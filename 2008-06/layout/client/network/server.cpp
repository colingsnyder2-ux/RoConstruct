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

static RBX::Reflection::PropDescriptor<RBX::Network::Server, int> prop_Port("Port", "Data", &RBX::Network::Server::getPort, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);

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

namespace RBX {
namespace Network {

bool __cdecl Server::serverIsPresent(const Instance* context, bool)
{
	const ServiceProvider* sp = ServiceProvider::findServiceProvider(context);
	return (sp ? sp->find<Selection>() : 0) != 0;
}

}
}
