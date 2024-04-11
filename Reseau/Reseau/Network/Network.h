#pragma once
#include "../Macro/Macro.h"
enum NetworkType
{
	NT_NONE,
	NT_SERVER,
	NT_CLIENT,

	NT_COUNT
};

class Network
{
protected:
	struct Bandwidth
	{
	public:
		enet_uint32 incoming;
		enet_uint32 outgoing;

		Bandwidth()
		{
			incoming = 0;
			outgoing = 0;
		}

		Bandwidth(enet_uint32 _incoming, enet_uint32 _outgoing)
		{
			incoming = _incoming;
			outgoing = _outgoing;
		}

	};

	struct HostData
	{
	public:
		size_t maxClientCount;
		size_t channelCount;
		Bandwidth bandwidth;

		HostData()
		{
			maxClientCount = 0;
			channelCount = 0;
		}

		HostData(size_t _maxClientCount, size_t _channelCount, Bandwidth _bandWidth)
		{
			maxClientCount = _maxClientCount;
			channelCount = _channelCount;
			bandwidth = _bandWidth;
		}
	};

	NetworkType type;
	HostData hostData;
	ENetAddress address;
	ENetHost* host;
	enet_uint32 latency;
	ENetEvent netEvent;
public:
	Network();
public:
	virtual void Connect(const char* _ip, const int _port);
public:
	void Start(const char* _ip, const int _port);
	virtual void Run() = 0;
};