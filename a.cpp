/*
	a.cpp
	Curtis Fortenberry
	last rev.: 3 May 2018
	A clean proxy design pattern example
*/

#include "proxy.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	cout << "Initializing servers..." << endl;
	
	ProxyServer DHCPServer("DHCP");
	ProxyServer DNSServer("DNS");
	
	DHCPServer.doService("DHCP");
	DNSServer.doService("DNS");
	
	DHCPServer.doService("DNS");
	DNSServer.doService("DHCP");
	
	cout << "EOS" << endl;
}