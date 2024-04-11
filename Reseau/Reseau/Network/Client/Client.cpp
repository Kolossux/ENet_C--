#include "Client.h"
#include "../../Resources/ChatBox.h"

Client::Client() : Network()
{
	hostData = HostData(1, 1, Bandwidth(0, 0));
	type = NT_CLIENT;
	isConnected = false;
	peer = nullptr;
	latency = 100;
}

void Client::Connect(const char* _ip, const int _port)
{
	Network::Connect(_ip, _port);

	ShowAddress("Client ", address);

	if (!(peer = enet_host_connect(host, &address, 1, 0)))
		throw string("Peer connectionFailed");

	const bool _request = enet_host_service(host, &netEvent, latency) >= 0;
	const bool _isConnectedEvent = netEvent.type == ENET_EVENT_TYPE_CONNECT;

	if (!_request || !_isConnectedEvent)
	{
		enet_peer_reset(peer);
		throw string("connection to server failed");
	}

	Register();
	Run();

}

void Client::Register()
{
	isConnected = true;
	Display("Enter your name: ", false);
	cin >> name;
	system("cls");

	ENetPacket* _packet = enet_packet_create(name.c_str(), strlen(name.c_str()) + 1, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, _packet);
}

void Client::SendPacket(const void* _element, const size_t& _size)
{
	ENetPacket* _packet = enet_packet_create(_element, _size + 1, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, _packet);
}

void Client::Run()
{
	while (isConnected)
	{
		if (_kbhit())
		{
			if (_getch() == 9)
			{
				string _message;
				ChatBox::GetInstance().Open(_message);
				SendPacket(_message.c_str(), _message.size());
			}
		}

		else
		{

			while (enet_host_service(host, &netEvent, latency /*Latence en ms avant d'abandonner*/) > 0)
			{
				switch (netEvent.type)
				{
				case ENET_EVENT_TYPE_CONNECT:
					ShowAddress("I just connected with: ", netEvent.peer->address);
					break;
				case ENET_EVENT_TYPE_DISCONNECT:
					ShowAddress("I just disconnected with: ", netEvent.peer->address);
					break;
				default:
					break;
				}
			}
		}

	}
}
