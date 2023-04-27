#pragma once

#include <cpr/api.h>
#include <list>
#include <nlohmann/json.hpp>
#include <vector>
#include <QtCore/qstring.h>

using namespace std;
using namespace cpr;
using json = nlohmann::json;

class RESTClient
{
public:
	RESTClient(string serverUrl);
	RESTClient(const RESTClient& restClient);

	vector<QString> *GETUsers(unsigned int page, unsigned int countOnPage);
	vector<string> *GETPositions();
	bool POSTUser(string&token, string&name, string&email, string&phone, string&photoPath);

private:
	string GETToken();

	Url url;
};

