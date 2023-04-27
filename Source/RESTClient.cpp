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



//Response response = Post(Url{ "https://server.server/api/v1/users" },
//	Header{ {"Token", "eyJpdiI6IndEeVNyRDJuOEdjQ1V5RWZUTU9MQXc9PSIsInZhbHVlIjoiNVR3TkdhM3I4NElZNlZFQnpwVlQyRTkzQzEwVGc5SEsreFNtb1VPcVNPZERUZVpZZG5SY25aZmpQM2tWWUo0MGdFTnYycnhQVlpqemR6MEpzYVwveVwvQT09IiwibWFjIjoiOWZlM2FjYjdiZjBlNWY3NDY3N2UxMTBhODY3YjEyNDgyYjM5M2JlYzViYjgzNmM3NGZhMmM0MTZkMzZlOWRmMiJ9"} },
//	Multipart{ {{"name", "Oleg"}, {"email", "awgwagaw@gawb.awg"}, {"phone", "+380003002020"}, {"position_id", 1}, {"photo", File{"C:/skins/stump-3.jpg"}}} }
//);
//
//
//string awd = response.text;
//long fgaw = response.status_code;