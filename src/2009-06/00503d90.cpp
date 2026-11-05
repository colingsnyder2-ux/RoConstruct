// from server: 100% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet roc_espclaude_74415e90d6e51da3.cpp

// Candidate translation unit (score above; library headers required).
#include "DS_List.h"
#include "DS_Queue.h"
#include "SingleProducerConsumer.h"
typedef unsigned int RakNetTime;
enum { ID_RPC_REPLY = 0xc, ID_TIMESTAMP = 0x19 };
struct SystemAddress
{
	unsigned int binaryAddress;
	unsigned short port;
	bool operator==( const SystemAddress& right ) const;
	bool operator!=( const SystemAddress& right ) const;
};
struct Packet
{
	unsigned short systemIndex;
	SystemAddress systemAddress;
	char exePad[0x10];
	unsigned int length;
	unsigned int bitSize;
	unsigned char* data;
	bool deleteData;
};
namespace RakNet { class BitStream { public: void Write( const char* input, const unsigned int numberOfBytes ); }; }
class RakPeer;
enum PluginReceiveResult { RR_STOP_PROCESSING_AND_DEALLOCATE=0, RR_CONTINUE_PROCESSING, RR_STOP_PROCESSING };
class PluginInterface
{
public:
	virtual ~PluginInterface();
	virtual void OnAttach(RakPeer *peer);
	virtual void OnDetach(RakPeer *peer);
	virtual void OnInitialize(RakPeer *peer);
	virtual void Update(RakPeer *peer);
	virtual PluginReceiveResult OnReceive(RakPeer *peer, Packet *packet);
};
class RakPeer
{
public:
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
	virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
	virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13();
	virtual bool IsActive( void ) const;
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual Packet* Receive( void );
	virtual void DeallocatePacket( Packet *packet );
	Packet* ReceiveIgnoreRPC( void );
	void ShiftIncomingTimestamp( unsigned char *data, SystemAddress systemAddress ) const;
	void HandleRPCReplyPacket( const char *data, int length, SystemAddress systemAddress );

	char pad0[0x5bc-4];
	DataStructures::List<PluginInterface*> messageHandlerList;
	char pad1[0xa64-0x5c8];
	RakNet::BitStream *replyFromTargetBS;
	SystemAddress replyFromTargetPlayer;
	bool replyFromTargetBroadcast;
	char pad2[7];
	bool blockOnRPCReply;
	char pad3[0xb58-0xa79];
	DataStructures::SingleProducerConsumer<Packet*> packetSingleProducerConsumer;
	DataStructures::Queue<Packet*> packetPool;
};
inline void RakPeer::HandleRPCReplyPacket( const char *data, int length, SystemAddress systemAddress )
{
	if (blockOnRPCReply)
	{
		if ((systemAddress==replyFromTargetPlayer && replyFromTargetBroadcast==false) ||
			(systemAddress!=replyFromTargetPlayer && replyFromTargetBroadcast==true))
		{
			replyFromTargetBS->Write(data+1, length-1);
			blockOnRPCReply=false;
		}
	}
}
Packet* RakPeer::ReceiveIgnoreRPC( void )
{
	if ( !( IsActive() ) )
		return 0;

	Packet *packet;
	Packet **threadPacket;
	PluginReceiveResult pluginResult;

	int offset;
	unsigned int i;

	for (i=0; i < messageHandlerList.Size(); i++)
	{
		messageHandlerList[i]->Update(this);
	}

	do 
	{
#ifdef _RAKNET_THREADSAFE
		rakPeerMutexes[transferToPacketQueue_Mutex].Lock();
#endif
		// Take all the messages off the queue so if the user pushes them back they are really pushed back, and not just at the end of the immediate write
		threadPacket=packetSingleProducerConsumer.ReadLock();
		while (threadPacket)
		{
			packet=*threadPacket;
			packetSingleProducerConsumer.ReadUnlock();
			threadPacket=packetSingleProducerConsumer.ReadLock();
			packetPool.Push(packet);
		}
#ifdef _RAKNET_THREADSAFE
		rakPeerMutexes[transferToPacketQueue_Mutex].Unlock();
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4127 ) // warning C4127: conditional expression is constant
#endif

#ifdef _RAKNET_THREADSAFE
		rakPeerMutexes[packetPool_Mutex].Lock();
#endif
		if (packetPool.Size()==0)
		{
#ifdef _RAKNET_THREADSAFE
			rakPeerMutexes[packetPool_Mutex].Unlock();
#endif
			return 0;
		}

		packet = packetPool.Pop();
#ifdef _RAKNET_THREADSAFE
		rakPeerMutexes[packetPool_Mutex].Unlock();
#endif
		if ( ( packet->length >= sizeof(unsigned char) + sizeof( RakNetTime ) ) &&
			( (unsigned char) packet->data[ 0 ] == ID_TIMESTAMP ) )
		{
			offset = sizeof(unsigned char);
			ShiftIncomingTimestamp( packet->data + offset, packet->systemAddress );
		}
		if ( (unsigned char) packet->data[ 0 ] == ID_RPC_REPLY )
		{
			HandleRPCReplyPacket( ( char* ) packet->data, packet->length, packet->systemAddress );
			DeallocatePacket( packet );
			packet=0; // Will do the loop again and get another packet
		}
		else
		{
			for (i=0; i < messageHandlerList.Size(); i++)
			{
				pluginResult=messageHandlerList[i]->OnReceive(this, packet);
				if (pluginResult==RR_STOP_PROCESSING_AND_DEALLOCATE)
				{
					DeallocatePacket( packet );
					packet=0; // Will do the loop again and get another packet
					break; // break out of the enclosing for
				}
				else if (pluginResult==RR_STOP_PROCESSING)
				{
					packet=0;
					break;
				}
			}
		}

	} while(packet==0);

#ifdef _DEBUG
	assert( packet->data );
#endif

	return packet;
}
