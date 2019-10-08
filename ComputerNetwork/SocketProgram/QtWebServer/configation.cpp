#include "configation.h"

Configation::Configation()
{

}
Configation::~Configation(){

}

const int Configation::DEFAULT_SERVER_PORT=23456;
const int Configation::DEFAULT_CLIENT_PORT=8080;
const string Configation::DEFAULT_SERVER_ADDR_STR="0.0.0.0";
const int Configation::MAX_CONNECTION_NUM=100;
const int Configation::BUF_LENGTH=1024;
const string Configation::OK_STATUS_STR="200 OK";
const string Configation::ERROR_METHOD_STR="501 Not Implemented";
const string Configation::DENY_STR="403 Forbidden";
const string Configation::NOT_FOUND_STR="404 Not Found";
const string Configation::DEFAULT_HTTP_VERSION_STR="HTTP/1.1 ";
const string Configation::SERVER_STR="Server: csr_http1.1";
