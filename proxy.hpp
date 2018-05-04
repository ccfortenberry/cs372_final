/*
	proxy.hpp
	Curtis Fortenberry
	last rev.: 3 May 2018
	Clean proxy design pattern example
*/
#ifndef PROXY_HPP_INCLUDED
#define PROXY_HPP_INCLUDED

#include <string>
using serviceType = std::string;

class ServerInterface {
public:
	virtual void doService(const serviceType &) = 0;
};

class Server : public ServerInterface {
public:
	void doService(const serviceType &) override;
};

class ProxyServer : public ServerInterface {
private:
	ServerInterface * _server;
	serviceType _service;
	
public:
	ProxyServer(const serviceType &);
	~ProxyServer() noexcept;
	
	void doService(const serviceType &) override;
};

#endif //PROXY_HPP_INCLUDED