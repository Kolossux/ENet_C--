#pragma once
#include "../../Macro/Macro.h"
#include "../Network.h"


class Server : public Network
{
	bool isRunning;

public:
	Server();
private:
	void Connect(const char* _ip, const int _port) override;
	void Run();
	void RegisterClient(ENetPeer* _client);
};

