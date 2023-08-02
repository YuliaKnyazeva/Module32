#pragma 
#include <iostream>
#include <mysql.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class DBConnectionInterface
{
public:
	DBConnectionInterface() {};
	virtual ~DBConnectionInterface() {};
	virtual bool Open(const std::string& _host, const std::string& _login, const std::string& _password, const std::string& _dbname) = 0;
	virtual bool Close() = 0;
	virtual bool ExecQuery(const std::string& query)= 0;
protected:
	MYSQL _mysql{ nullptr };
	std::string _query;
	std::string _host;
	std::string _login;
	std::string _password;
	std::string _dbname;
};





