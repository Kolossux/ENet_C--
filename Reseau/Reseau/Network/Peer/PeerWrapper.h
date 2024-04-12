#pragma once
#include "../../Macro/Macro.h"

class Client;

class PeerWrapper
{
public:
	string clientName;
	Client* client;
	ENetPeer* peer;
public:
	PeerWrapper();
	PeerWrapper(Client* _client);
public:
	inline void SetClientName(const string& _str) {  clientName = _str; }
	inline const string& GetClientName()const { return clientName; }
	inline void SetPeer(ENetPeer* _peer) {  peer = _peer; }
	inline ENetPeer* GetPeer()const { return peer; }
	inline Client* GetClient()const { return client; }
};

