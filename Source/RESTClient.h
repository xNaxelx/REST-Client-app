#pragma once

#include <cpr/api.h>
#include <list>
#include <nlohmann/json.hpp>
#include <vector>

using namespace std;
using namespace cpr;
using json = nlohmann::json;

class RESTClient
{
public:
	RESTClient(string serverUrl);

	vector<string> *GETUsers();
	vector<string> *GETPositions();
	bool POSTUser(string&token, string&name, string&email, string&phone, string&photoPath);

private:
	string GETToken();

	Url url;
};

