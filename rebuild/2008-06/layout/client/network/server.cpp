// =============================================================================
// server.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/server.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "Network/Server2008.h"
#include "Network/Replicator2008.h"
#include <algorithm>

bool isReplicator(boost::shared_ptr<RBX::Instance> instance)
{
	return dynamic_cast<RBX::Network::Replicator*>(instance.get()) != NULL;
}

typedef bool (*InstancePredicate)(boost::shared_ptr<RBX::Instance>);
template std::ptrdiff_t std::_Count_if<const boost::shared_ptr<RBX::Instance>*, InstancePredicate>(
	const boost::shared_ptr<RBX::Instance>*, const boost::shared_ptr<RBX::Instance>*, InstancePredicate);

typedef int (RBX::Network::Server::*ServerIntGetter)() const;
template RBX::Reflection::PropDescriptor<RBX::Network::Server, int>::PropDescriptor(
	const char*, const char*, ServerIntGetter, int, RBX::Reflection::PropertyDescriptor::Functionality);

static RBX::Reflection::PropDescriptor<RBX::Network::Server, int> prop_Port(
	"Port",
	"Data",
	&RBX::Network::Server::getPort,
	NULL,
	RBX::Reflection::PropertyDescriptor::STANDARD);

namespace RBX
{
	namespace Network
	{
		void Server::stop(int blockDuration)
		{
			if (rakPeer->IsActive())
				rakPeer->Shutdown(blockDuration, 0);
			removeAllChildren();
		}

		int Server::getClientCount()
		{
			if (children)
				return std::count_if(children->begin(), children->end(), isReplicator);
			return 0;
		}
	}
}

#include "Network/ClientProxy2008.h"
#include "v8datamodel/Selection.h"
#include "util/Name.h"

namespace RBX
{
namespace Network
{

bool __cdecl Server::serverIsPresent(const Instance* context, bool)
{
	const ServiceProvider* sp = ServiceProvider::findServiceProvider(context);
	return (sp ? sp->find<Selection>() : 0) != 0;
}

}
}
