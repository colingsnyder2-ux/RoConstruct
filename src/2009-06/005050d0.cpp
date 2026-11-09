// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
typedef unsigned int RakNetTime;
enum { ID_RPC = 0xb, ID_TIMESTAMP = 0x19 };
struct SystemAddress
{
	unsigned int binaryAddress;
	unsigned short port;
};
struct Packet
{
	int systemIndex;
	SystemAddress systemAddress;
	char pad[0x1c-0xc];
	unsigned int length;
	unsigned int bitSize;
	unsigned char* data;
};
class RakPeer
{
public:
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
	virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
	virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual Packet* Receive( void );
	virtual void DeallocatePacket( Packet *packet );
	Packet* ReceiveIgnoreRPC( void );
	bool HandleRPCPacket( const char *data, int length, SystemAddress systemAddress );
};
Packet* RakPeer::Receive( void )
{
	Packet *packet = ReceiveIgnoreRPC();
	while (packet && (packet->data[ 0 ] == ID_RPC || (packet->length>sizeof(unsigned char)+sizeof(RakNetTime) && packet->data[0]==ID_TIMESTAMP && packet->data[sizeof(unsigned char)+sizeof(RakNetTime)]==ID_RPC)))
	{
		HandleRPCPacket( ( char* ) packet->data, packet->length, packet->systemAddress );
		DeallocatePacket( packet );

		packet = ReceiveIgnoreRPC();
	}

    return packet;
}
