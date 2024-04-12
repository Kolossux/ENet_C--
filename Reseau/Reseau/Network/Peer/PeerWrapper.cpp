#include "PeerWrapper.h"
#include "../Client/Client.h"

PeerWrapper::PeerWrapper()
{
	clientName = "default";
	peer = nullptr;
}

PeerWrapper::PeerWrapper(Client* _client)
{
	clientName = "default";
	client = _client;
	peer = nullptr;
}
