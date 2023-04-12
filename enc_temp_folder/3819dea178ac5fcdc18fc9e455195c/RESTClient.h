#pragma once

#include <cpr/api.h>
#include <list>

using namespace std;
using namespace cpr;

class RESTClient
{
public:
	RESTClient(string serverUrl);

	list<list<string>> GETUsers();
	void GETPositions();
	bool POSTUser(string&token, string&name, string&email, string&phone, string&photoPath);

private:
	wstring GETToken();

	Url serverUrl{"https://frontend-test-assignment-api.abz.agency/api/v1"};
};

