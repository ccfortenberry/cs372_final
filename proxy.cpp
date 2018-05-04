/*
	proxy.cpp
	Curtis Fortenberry
	last rev.: 3 May 2018
	Clean proxy design pattern example
*/
#include "proxy.hpp"
#include <iostream>
using std::cout;
using std::endl;

void Server::doService(const serviceType & service) {
	cout << service << " has been provided by " << service << " server!" << endl;
}

ProxyServer::ProxyServer(const serviceType & service) : _server(new Server()), _service(service) {
	cout << _service << " server created!" << endl;
}

ProxyServer::~ProxyServer() noexcept {
	delete _server;
}
	
void ProxyServer::doService(const serviceType & service) {
	if (service == _service) _server->doService(service);
	else cout << _service << " ERROR: Unable to perform: " << service << endl;
}