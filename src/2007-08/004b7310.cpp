// from server: 100% by EspClaude
// from server: 83% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: rbxgs-raknet roc_espclaude_e43e4749ff827824.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 RakNet: RakPeerInterface without SetPerConnectionOutgoingBandwidthLimit (exe vtable has 68 slots, GetRPCString @0x10c)
#define _DLL

#ifndef __RAK_PEER_INTERFACE_H
#define __RAK_PEER_INTERFACE_H

#include "PacketPriority.h"
#include "RakNetTypes.h"
#include "Export.h"

// Forward declarations
namespace RakNet
{
	class BitStream;
}
class PluginInterface;
struct RPCMap;
struct RakNetStatistics;
class RouterInterface;
class NetworkIDManager;
class RAK_DLL_EXPORT RakPeerInterface
{
public:
	virtual ~RakPeerInterface()	{}

	// --------------------------------------------------------------------------------------------Major Low Level Functions - Functions needed by most users--------------------------------------------------------------------------------------------
	virtual bool Startup( unsigned short maxConnections, int _threadSleepTimer, SocketDescriptor *socketDescriptors, unsigned socketDescriptorCount )=0;
	virtual void InitializeSecurity(const char *pubKeyE, const char *pubKeyN, const char *privKeyP, const char *privKeyQ )=0;
	virtual void DisableSecurity( void )=0;
	virtual void SetMaximumIncomingConnections( unsigned short numberAllowed )=0;
	virtual unsigned short GetMaximumIncomingConnections( void ) const=0;
	virtual unsigned short NumberOfConnections(void) const=0;
	virtual void SetIncomingPassword( const char* passwordData, int passwordDataLength )=0;
	virtual void GetIncomingPassword( char* passwordData, int *passwordDataLength  )=0;
	virtual bool Connect( const char* host, unsigned short remotePort, const char *passwordData, int passwordDataLength, unsigned connectionSocketIndex=0 )=0;
	virtual void Shutdown( unsigned int blockDuration, unsigned char orderingChannel=0 )=0;
	virtual bool IsActive( void ) const=0;
	virtual bool GetConnectionList( SystemAddress *remoteSystems, unsigned short *numberOfSystems ) const=0;
	virtual bool Send( const char *data, const int length, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast )=0;
	virtual bool Send( const RakNet::BitStream * bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast )=0;
	virtual Packet* Receive( void )=0;
	virtual void DeallocatePacket( Packet *packet )=0;
	// TODO - rename for RakNet 3.0
	virtual unsigned short GetMaximumNumberOfPeers( void ) const=0;

	// --------------------------------------------------------------------------------------------Remote Procedure Call Functions - Functions to initialize and perform RPC--------------------------------------------------------------------------------------------
	virtual void RegisterAsRemoteProcedureCall( const char* uniqueID, void ( *functionPointer ) ( RPCParameters *rpcParms ) )=0;
	virtual void RegisterClassMemberRPC( const char* uniqueID, void *functionPointer )=0;
	virtual void UnregisterAsRemoteProcedureCall( const char* uniqueID )=0;
	virtual void SetNetworkIDManager( NetworkIDManager *manager )=0;
	virtual NetworkIDManager *GetNetworkIDManager(void) const=0;
	virtual bool RPC( const char* uniqueID, const char *data, unsigned int bitLength, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, RakNetTime *includedTimestamp, NetworkID networkID, RakNet::BitStream *replyFromTarget )=0;
	virtual bool RPC( const char* uniqueID, const RakNet::BitStream *bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, RakNetTime *includedTimestamp, NetworkID networkID, RakNet::BitStream *replyFromTarget )=0;

	// -------------------------------------------------------------------------------------------- Connection Management Functions--------------------------------------------------------------------------------------------
	virtual void CloseConnection( const SystemAddress target, bool sendDisconnectionNotification, unsigned char orderingChannel=0 )=0;
	virtual bool IsConnected(const SystemAddress systemAddress)=0;
	virtual int GetIndexFromSystemAddress( const SystemAddress systemAddress )=0;
	virtual SystemAddress GetSystemAddressFromIndex( int index )=0;
	virtual void AddToBanList( const char *IP, RakNetTime milliseconds=0 )=0;
	virtual void RemoveFromBanList( const char *IP )=0;
	virtual void ClearBanList( void )=0;
	virtual bool IsBanned( const char *IP )=0;

	// --------------------------------------------------------------------------------------------Pinging Functions - Functions dealing with the automatic ping mechanism--------------------------------------------------------------------------------------------
	virtual void Ping( const SystemAddress target )=0;
	virtual void Ping( const char* host, unsigned short remotePort, bool onlyReplyOnAcceptingConnections, unsigned connectionSocketIndex=0 )=0;
	virtual int GetAveragePing( const SystemAddress systemAddress )=0;
	virtual int GetLastPing( const SystemAddress systemAddress ) const=0;
	virtual int GetLowestPing( const SystemAddress systemAddress ) const=0;
	virtual void SetOccasionalPing( bool doPing )=0;

	// --------------------------------------------------------------------------------------------Static Data Functions - Functions dealing with API defined synchronized memory--------------------------------------------------------------------------------------------
	virtual void SetOfflinePingResponse( const char *data, const unsigned int length )=0;

	//--------------------------------------------------------------------------------------------Network Functions - Functions dealing with the network in general--------------------------------------------------------------------------------------------
	virtual SystemAddress GetInternalID( const SystemAddress systemAddress=UNASSIGNED_SYSTEM_ADDRESS ) const=0;
	virtual SystemAddress GetExternalID( const SystemAddress target ) const=0;
	virtual void SetTimeoutTime( RakNetTime timeMS, const SystemAddress target )=0;
	virtual bool SetMTUSize( int size )=0;
	virtual int GetMTUSize( const SystemAddress target ) const=0;
	virtual unsigned GetNumberOfAddresses( void )=0;
	virtual const char* GetLocalIP( unsigned int index )=0;
	virtual void AllowConnectionResponseIPMigration( bool allow )=0;
	virtual void AdvertiseSystem( const char *host, unsigned short remotePort, const char *data, int dataLength, unsigned connectionSocketIndex=0 )=0;
	virtual void SetSplitMessageProgressInterval(int interval)=0;
	virtual void SetUnreliableTimeout(RakNetTime timeoutMS)=0;
	virtual void SendTTL1( const char* host, unsigned short remotePort, unsigned connectionSocketIndex=0 )=0;

	// --------------------------------------------------------------------------------------------Compression Functions - Functions related to the compression layer--------------------------------------------------------------------------------------------
	virtual void SetCompileFrequencyTable( bool doCompile )=0;
	virtual bool GetOutgoingFrequencyTable( unsigned int outputFrequencyTable[ 256 ] )=0;
	virtual bool GenerateCompressionLayer( unsigned int inputFrequencyTable[ 256 ], bool inputLayer )=0;
	virtual bool DeleteCompressionLayer( bool inputLayer )=0;
	virtual float GetCompressionRatio( void ) const=0;
	virtual float GetDecompressionRatio( void ) const=0;

	// -------------------------------------------------------------------------------------------- Plugin Functions--------------------------------------------------------------------------------------------
	virtual void AttachPlugin( PluginInterface *plugin )=0;
	virtual void DetachPlugin( PluginInterface *messageHandler )=0;

	// --------------------------------------------------------------------------------------------Miscellaneous Functions--------------------------------------------------------------------------------------------
	virtual void PushBackPacket( Packet *packet, bool pushAtHead )=0;
	// \param[in] routerInterface The router to use to route messages to systems not directly connected to this system.
	virtual void SetRouterInterface( RouterInterface *routerInterface )=0;
	// \param[in] routerInterface The router to use to route messages to systems not directly connected to this system.
	virtual void RemoveRouterInterface( RouterInterface *routerInterface )=0;
	virtual Packet* AllocatePacket(unsigned dataSize)=0;

	// --------------------------------------------------------------------------------------------Network Simulator Functions--------------------------------------------------------------------------------------------
	virtual void ApplyNetworkSimulator( double maxSendBPS, unsigned short minExtraPing, unsigned short extraPingVariance)=0;
	virtual bool IsNetworkSimulatorActive( void )=0;

	// --------------------------------------------------------------------------------------------Statistical Functions - Functions dealing with API performance--------------------------------------------------------------------------------------------
	virtual RakNetStatistics * const GetStatistics( const SystemAddress systemAddress )=0;

	// --------------------------------------------------------------------------------------------EVERYTHING AFTER THIS COMMENT IS FOR INTERNAL USE ONLY--------------------------------------------------------------------------------------------
	virtual char *GetRPCString( const char *data, const unsigned int bitSize, const SystemAddress systemAddress)=0;


};

#endif

#include "PacketLogger.cpp"
