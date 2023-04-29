#include "RESTClient.h"


RESTClient::RESTClient(string serverUrl) : url(serverUrl)
{
	GETPositions();
}

RESTClient::RESTClient(const RESTClient& restClient) : url(restClient.url)
{
	
}

vector<QString>* RESTClient::GETUsers(unsigned int page, unsigned int countOnPage)
{
	auto users = new vector<QString>();

	Response response = Get(Url{ url + "/users?page=" + to_string(page) +  "&count=" + to_string(countOnPage)});

	if (response.status_code != 200) return users;

	json jsonResponse = json::parse(response.text);
	json object = jsonResponse["users"];

	for (auto it = object.begin(); it != object.end(); ++it)
	{
		string photo = it->find("photo").value();
		string name = it->find("name").value();
		string position = it->find("position").value();
		string email = it->find("email").value();
		string phone = it->find("phone").value();
		string id = to_string(it->find("id").value()).c_str();
		users->push_back(photo.c_str());
		users->push_back(name.c_str());
		users->push_back(position.c_str());
		users->push_back(email.c_str());
		users->push_back(phone.c_str());
		users->push_back(id.c_str());
	}

	return users; 
}

vector<string>* RESTClient::GETPositions()
{
	auto *positions = new vector<string>();

	Response response = Get(Url{ url + "/positions"});

	if (response.status_code != 200) return positions;

	json jsonResponse =	json::parse(response.text);
	json object = jsonResponse["positions"];

	for (auto it = object.begin(); it != object.end(); ++it)
	{
		positions->push_back(to_string(it->find("id").value()));
		positions->push_back(it->find("name").value());
	}

	return positions;
}

void RESTClient::POSTUser(string name, string email, string phone, int position_id, string photoPath, QLabel* statusText)
{
	Response tokenResponse = Get(Url{ url + "/token" });

	if (tokenResponse.status_code != 200)
	{
		statusText->setText(tokenResponse.text.c_str());
		return;
	}

	json jsonResponse = json::parse(tokenResponse.text);
	string token = jsonResponse["token"];

	Response response = Post(Url{ url + "/users" },
		Header{ {"Token", token} },
		Multipart{ {{"name", name}, {"email", email}, {"phone", phone}, {"position_id", position_id}, {"photo", File{photoPath}}} }
	);

	if (response.status_code == 200 || response.status_code == 201)
	{
		statusText->setText("New user successfully registered");
	}
	else if (response.status_code == 0)
	{
		statusText->setText("No response from server");
	}
	else
	{
		statusText->setText("Registration failed");
	}

}

