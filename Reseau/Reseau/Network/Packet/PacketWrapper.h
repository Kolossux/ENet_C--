#pragma once
#include "../../Macro/Macro.h"

class PacketWrapper
{
	ENetPacket* packet;
	string name;
public:
	PacketWrapper() = default;
public:
	inline ENetPacket* GetPacket()const { return packet; }
	inline void SetPacket(ENetPacket* _packet) { packet = _packet; }
	inline const string& GetName()const { return name; }
	inline void SetName(const string& _name) { name = _name; }
};

