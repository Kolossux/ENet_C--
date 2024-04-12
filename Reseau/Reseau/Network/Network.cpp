#include "Network.h"
#include "NetEvent/NetEventWrapper.h"

Network::Network()
{
	hostData = HostData();
	address = ENetAddress();
	host = nullptr;
	type = NT_NONE;
	netEvent = new NetEventWrapper();
	latency = 1000;
}

void Network::Connect(const char* _ip, const int _port)
{

	if (enet_address_set_host(&address, _ip) < 0)
	{
		throw(string("An error has occured while setting up the adress."));
	}
	address.port = _port;

	if (type == NT_CLIENT)
		host = enet_host_create(nullptr,							      // address
			hostData.maxClientCount,								  // nombre de client
			hostData.channelCount,								  // nombre de canaux
			hostData.bandwidth.incoming,						      // bande passante entrante
			hostData.bandwidth.outgoing);							  // bande passante sortante
	else
		host = enet_host_create(&address,							      // address
			hostData.maxClientCount,								  // nombre de client
			hostData.channelCount,								  // nombre de canaux
			hostData.bandwidth.incoming,						      // bande passante entrante
			hostData.bandwidth.outgoing);							  // bande passante sortante

	if (!host)
		throw(string("An error has occured while setting up the adress."));
}

void Network::Start(const char* _ip, const int _port)
{
	if (enet_initialize() != 0)
	{
		throw(string("An error has occured while init Enet."));
	}

	//atexit(enet_deinitialize);

	Display("Succes Enet initialization !", true, GREEN);
	Connect(_ip, _port);
}
