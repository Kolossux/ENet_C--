#include "Server.h"
#include "../NetEvent/NetEventWrapper.h"
#include "../Client/Client.h"

Server::Server() : Network()
{
	hostData = HostData(32, 2, Bandwidth(0, 0));
	type = NT_SERVER;
	isRunning = false;
}

void Server::Connect(const char* _ip, const int _port)
{
	Network::Connect(_ip, _port);

	ShowAddress("Server", address);
	isRunning = true;
	Run();

	enet_host_destroy(host);
}

void Server::Run()
{
	while (isRunning)
	{
		while (enet_host_service(host, netEvent, latency) > 0)
		{
			switch (netEvent->type)
			{
			case ENET_EVENT_TYPE_CONNECT:
				RegisterClient(netEvent->peer);
				break;
			case ENET_EVENT_TYPE_DISCONNECT:
			{
				ShowAddress("A new client disconnected with :", netEvent->peer->address);
			}
			break;
			case ENET_EVENT_TYPE_RECEIVE:
				if (netEvent->packet)
				{
					Display("New message from: ", false, YELLOW);
					ShowAddress("Client ", netEvent->peer->address, false);
					Display(": " + string((char*)netEvent->packet->data));
					//Display(": " + reinterpret_cast<Client*>(netEvent->packet->data)->GetName());
				}
				break;
			case ENET_EVENT_TYPE_NONE:
				Display("None.");
				break;
			default:
				break;
			}
		}
	}

}

void Server::RegisterClient(ENetPeer* _client)
{
	registeredClients.push_back(_client);
    Display("Client Registered : " + to_string(registeredClients.size()),true, YELLOW);
}