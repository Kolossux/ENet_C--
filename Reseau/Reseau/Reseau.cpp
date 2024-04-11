#include <iostream>
#include "Macro/Macro.h"
#include "Network/Server/Server.h"
#include "Network/Client/Client.h"

using namespace std;

void HostServer();
void HostClient();
void SelectHost();

void SelectHost()
{
	const int _callbackMaxCount = 2;
	int _choices;

	do
	{
		system("cls");
		Display("1- Server", true, YELLOW);
		Display("2- Client", true, PURPLE);
		cin >> _choices;
	} while (_choices < 1 || _choices > _callbackMaxCount);

	const function<void()> _callback[] = {
		 []() {HostServer(); },
		 []() {HostClient(); }
	};

	try {

	_callback[_choices - 1]();
	}
	catch (const string& _error)
	{
		Display(_error, true, RED);
	}
}

void HostServer()
{
	Server* _server = new Server();
	_server->Start("127.0.0.1", 7777);
	delete _server;
}

void HostClient()
{
	Client* _client = new Client();
	_client->Start("127.0.0.1", 7777);
	delete _client;
}

int main()
{
	//TEST 

	//if (enet_initialize() != 0)
	//{
	//	cerr << "An error has occured while init Enet." << endl;
	//	return EXIT_FAILURE;
	//}
	//atexit(enet_deinitialize);
	//SelectHost();
	//
	//// === Server === \\
	//
	//ENetAddress _serverAdress;
	//_serverAdress.host = ENET_HOST_ANY;
	//_serverAdress.port = 1234;
	//ShowAddress("Server", _serverAdress);
	//
	//ENetHost* _server = enet_host_create(&_serverAdress,   // address
	//	32,              // nombre de client
	//	2,               // nombre de canaux
	//	0, 0);           // bande passante
	//
	//if (!_server)
	//{
	//	Display("An error has occured during the server creation. ", true, RED);
	//	return EXIT_FAILURE;
	//}
	//Display("Server Created !", true, GREEN);
	//
	//enet_host_destroy(_server);
	//
	//
	// === Client === \\ 
	//
	//ENetHost* _client = enet_host_create(nullptr,        // address
	//	1,              // nombre de client
	//	2,              // nombre de canaux
	//	0, 0);          // bande passante
	//
	//if (!_client)
	//{
	//	Display("An error has occured during the client creation. ", true, RED);
	//	return EXIT_FAILURE;
	//}
	//Display("Client Created !", true, GREEN);
	//enet_host_destroy(_client);

	SelectHost();
}


