// =============================================================================
// NetworkIDManager.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/raknet30/source/NetworkIDManager.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "NetworkIDManager.h"
#include "NetworkIDObject.h"
#include "RakAssert.h"
#include <string.h> // For memset

bool NetworkIDNode::operator==( const NetworkIDNode& right ) const
{
	if ( networkID == right.networkID )
		return !0;

	return 0;
}

bool NetworkIDNode::operator > ( const NetworkIDNode& right ) const
{
	if ( networkID > right.networkID )
		return !0;

	return 0;
}

bool NetworkIDNode::operator < ( const NetworkIDNode& right ) const
{
	if ( networkID < right.networkID )
		return !0;

	return 0;
}

NetworkIDNode::NetworkIDNode()
{
	object = 0;
}

NetworkIDNode::NetworkIDNode( NetworkID _networkID, NetworkIDObject *_object )
{
	networkID = _networkID;
	object = _object;
}

//-------------------------------------------------------------------------------------
void* NetworkIDManager::GET_BASE_OBJECT_FROM_ID( NetworkID x )
{
	if ( x == UNASSIGNED_NETWORK_ID )
		return 0;

#ifdef NETWORK_ID_USE_HASH
	// You can't use this technique in peer to peer mode.  Undefine NETWORK_ID_USE_HASH in NetworkIDManager.h
	assert(NetworkID::peerToPeerMode==false);
	return IDArray[x.localSystemAddress];
#else

	NetworkIDNode *n = IDTree.GetPointerToNode( NetworkIDNode( ( x ), 0 ) );

	if ( n )
	{
		return n->object;
	}

	return 0;

#endif

}
//-------------------------------------------------------------------------------------
void* NetworkIDManager::GET_OBJECT_FROM_ID( NetworkID x )
{
#ifdef NETWORK_ID_USE_HASH
	if (x.localSystemAddress==65535)
		return 0;

	// You can't use this technique in peer to peer mode.  Undefine NETWORK_ID_USE_HASH in NetworkIDManager.h
	assert(NetworkID::peerToPeerMode==false);
	if (IDArray[x.localSystemAddress])
	{
		if (IDArray[x.localSystemAddress]->GetParent())
		{
			return IDArray[x.localSystemAddress]->GetParent();
		}
		else
		{
#ifdef _DEBUG
			// If this assert hit then this object requires a call to SetParent and it never got one.
			assert(IDArray[x.localSystemAddress]->RequiresSetParent()==false);
#endif
			return IDArray[x.localSystemAddress];
		}
	}
#else
	NetworkIDObject *object = (NetworkIDObject *) GET_BASE_OBJECT_FROM_ID( x );
	if (object)
	{
		if (object->GetParent())
		{
			return object->GetParent();
		}
		else
		{
#ifdef _DEBUG
			// If this assert hit then this object requires a call to SetParent and it never got one.
			assert(object->RequiresSetParent()==false);
#endif
			return object;
		}
	}
#endif

	return 0;
}
//-------------------------------------------------------------------------------------
NetworkIDManager::NetworkIDManager(void)
{
	calledSetIsNetworkIDAuthority=false;
	sharedNetworkID=0;

#ifdef NETWORK_ID_USE_HASH
	// Last element is reserved for UNASSIGNED_NETWORK_ID
	IDArray = new NetworkIDObject*[65534];
	memset(IDArray,0,sizeof(NetworkIDObject*)*65534);
	// You can't use this technique in peer to peer mode.  Undefine NETWORK_ID_USE_HASH in NetworkIDManager.h
	assert(NetworkID::peerToPeerMode==false);
#endif
}
//-------------------------------------------------------------------------------------
NetworkIDManager::~NetworkIDManager(void)
{
#ifndef NETWORK_ID_USE_HASH
	delete [] IDArray;
#endif
}
//-------------------------------------------------------------------------------------

void NetworkIDManager::SetIsNetworkIDAuthority(bool isAuthority)
{
	isNetworkIDAuthority=isAuthority;
	calledSetIsNetworkIDAuthority=true;
}

//-------------------------------------------------------------------------------------

bool NetworkIDManager::IsNetworkIDAuthority(void) const
{
	RakAssert(calledSetIsNetworkIDAuthority);
	return isNetworkIDAuthority;
}

//-------------------------------------------------------------------------------------

unsigned short NetworkIDManager::GetSharedNetworkID( void )
{
	RakAssert(calledSetIsNetworkIDAuthority);
	return sharedNetworkID;
}

//-------------------------------------------------------------------------------------

void NetworkIDManager::SetSharedNetworkID( unsigned short i )
{
	RakAssert(calledSetIsNetworkIDAuthority);
	sharedNetworkID = i;
}

//-------------------------------------------------------------------------------------
void NetworkIDManager::SetExternalSystemAddress(SystemAddress systemAddress)
{
	RakAssert(calledSetIsNetworkIDAuthority);
	RakAssert(systemAddress!=UNASSIGNED_SYSTEM_ADDRESS);
	externalSystemAddress=systemAddress;
}
//-------------------------------------------------------------------------------------
SystemAddress NetworkIDManager::GetExternalSystemAddress(void)
{
	RakAssert(calledSetIsNetworkIDAuthority);
	return externalSystemAddress;
}
