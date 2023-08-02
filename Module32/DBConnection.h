#pragma once
#include "DBConnectionInterface.h"
#include <gmock/gmock.h>
class DBConnection :
    public DBConnectionInterface
{
public:
    DBConnection() {}
    virtual ~DBConnection() {}
    virtual bool Open(const std::string& port, const std::string& login, const std::string& password, const std::string& dbname) override;
    virtual bool Close()override;
    virtual bool ExecQuery(const std::string& query) override;
    std::string _query;
    std::string _port;
    std::string _login;
    std::string _password;
    std::string _dbname;
};


class SomeTestSuite : public ::testing::Test
{
protected:
    void SetUp()
    {
        somedb  = new DBConnection();
    }

    void TearDown()
    {
        delete somedb;
    }

protected:
    DBConnection* somedb;
};

class MockDatabse : public DBConnectionInterface
{
public:
    MOCK_METHOD(bool, Open, (const std::string& _host, const std::string& _login, const std::string& _password, const std::string& _dbname), (override));
    MOCK_METHOD(bool, Close, (), (override));
    MOCK_METHOD(bool, ExecQuery, (const std::string& query), (override));
};

TEST_F(SomeTestSuite, testcase1) 
{
        DBConnection db;
        std::string _host("localhost");
        std::string _login("root");
        std::string _password("poison");
        std::string _dbname("testdb");
        std::string _query("INSERT INTO users(id, name, login, password) values(default, 'Daria', 'Daria', '123')");

        MockDatabse mockdb;

        EXPECT_CALL(mockdb,Open(_host,_login,_password,_dbname)).WillOnce(::testing::Return(true));
        EXPECT_CALL(mockdb,Close).WillOnce(::testing::Return(true));
        EXPECT_CALL(mockdb,ExecQuery(_query)).WillRepeatedly(::testing::Return(true));

}
