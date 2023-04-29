#pragma once

#include <cpr/api.h>
#include <list>
#include <nlohmann/json.hpp>
#include <vector>
#include <QtCore/qstring.h>
#include <qlabel.h>

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
	void POSTUser(string name, string email, string phone, int position_id, string photoPath, QLabel* statusText);

private:
	string GETToken();

	Url url;
};

