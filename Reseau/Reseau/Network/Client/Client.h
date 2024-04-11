#pragma once
#include "../../Macro/Macro.h"
#include "../Network.h"


class Client : public Network
{
	bool isConnected;
	string name;
	ENetPeer* peer;

public:
	inline const string& GetName()const
	{
		return name;
	}
public:
	Client();
private:
	void Connect(const char* _ip, const int _port) override;
	void Register();
	void SendPacket(const void* _element, const size_t& _size);
	virtual void Run() override;
};

