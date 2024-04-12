#pragma once
#include "../../Macro/Macro.h"
#include "../Peer/PeerWrapper.h"
#include "../Packet/PacketWrapper.h"

class PacketWrapper;

class NetEventWrapper : public ENetEvent
{
	PeerWrapper* peerWrapper;
	PacketWrapper* packetWrapper;

public:
	inline PeerWrapper* GetPeerWrapper()const { return peerWrapper; }
	inline ENetPeer* GetPeer()const { return peerWrapper->GetPeer(); }
	inline void SetPeerWrapper(PeerWrapper* _peer) { peerWrapper = _peer; }
	inline void SetPeer(ENetPeer* _peer) { peerWrapper->SetPeer(_peer); }

	inline PacketWrapper* GetPacketWrapper()const { return packetWrapper; }
	inline ENetPacket* GetPacket()const { return packetWrapper->GetPacket(); }
	inline void SetPacketWrapper(PacketWrapper* _packet) { packetWrapper = _packet; }
	inline void SetPacket(ENetPacket* _packet) { packetWrapper->SetPacket(_packet); }
};

