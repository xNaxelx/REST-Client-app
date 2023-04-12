#include "RESTClient.h"


RESTClient::RESTClient(string serverUrl)
{
	GETPositions();
}

//list<list<string>> RESTClient::GETUsers()
//{
//	return (list<list<string>>)NULL;
//}

void RESTClient::GETPositions()
{
	Response response = Post(Url{ "https://frontend-test-assignment-api.abz.agency/api/v1/users" },
		Header{{"Token", "eyJpdiI6IndEeVNyRDJuOEdjQ1V5RWZUTU9MQXc9PSIsInZhbHVlIjoiNVR3TkdhM3I4NElZNlZFQnpwVlQyRTkzQzEwVGc5SEsreFNtb1VPcVNPZERUZVpZZG5SY25aZmpQM2tWWUo0MGdFTnYycnhQVlpqemR6MEpzYVwveVwvQT09IiwibWFjIjoiOWZlM2FjYjdiZjBlNWY3NDY3N2UxMTBhODY3YjEyNDgyYjM5M2JlYzViYjgzNmM3NGZhMmM0MTZkMzZlOWRmMiJ9"}},
		Multipart{ {{"name", "Oleg"}, {"email", "awgwagaw@gawb.awg"}, {"phone", "+380003002020"}, {"position_id", 1}, {"photo", File{"C:/skins/stump-3.jpg"}}}}
		);


	string awd = response.text;
	long fgaw = response.status_code;

}