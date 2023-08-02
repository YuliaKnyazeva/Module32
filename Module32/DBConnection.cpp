#include "DBConnection.h"

bool DBConnection::Open(const std::string& port, const std::string& login, const std::string& password, const std::string& dbname)
{
	mysql_init(&_mysql);
	if (&_mysql == nullptr) {
		return false;
	}
	if (!mysql_real_connect(&_mysql, port.c_str(), login.c_str(), password.c_str(), dbname.c_str(), NULL, NULL, 0)) {
		return false;
	}
	else {
		return true;
	}
}

bool DBConnection::Close()
{
	mysql_close(&_mysql);
	return true;
}

bool DBConnection::ExecQuery(const std::string& query)
{
	try {
		mysql_query(&_mysql, query.c_str());
	}
	catch (char error) {
		return false;
	}
	return true;
}
