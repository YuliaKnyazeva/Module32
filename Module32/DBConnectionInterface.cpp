#include "DBConnectionInterface.h"

bool DBConnectionInterface::Open(const std::string& _host, const std::string& _login, const std::string& _password, const std::string& _dbname)
{
	mysql_init(&_mysql);
	if (&_mysql == nullptr) {
		return false;
	}
	if (!mysql_real_connect(&_mysql, _host.c_str(), _login.c_str(), _password.c_str(), _dbname.c_str(), NULL, NULL, 0)) {
		return false;
	}
	else {
		return true;
	}
}
bool DBConnectionInterface::Close()
{
	mysql_close(&_mysql);
	return true;
}
bool DBConnectionInterface::ExecQuery(const std::string& query)
{
	try {
		mysql_query(&_mysql, query.c_str());

	}
	catch (char error) {
	return false;
	}
	return true;
}
