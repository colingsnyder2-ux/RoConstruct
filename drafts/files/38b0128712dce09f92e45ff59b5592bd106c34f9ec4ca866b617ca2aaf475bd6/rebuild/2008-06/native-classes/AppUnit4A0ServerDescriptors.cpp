// 2008-06 native rows of the Network::Server unit (Network/Server.cpp, 004a1570..) inside the application range
// 004a0000..004a4000 (inactive). Verified by tests/record_native_app_unit4a0.py. All headers are read-only here
// (Server: native-headers/Network/Server2008.h, network-client-server owner; Replicator: Network/Replicator2008.h,
// network-replicator owner; descriptors: reflection/reflection.h, core owner).
//
// Rows:
//   * isReplicator(shared_ptr<Instance>) 004a17f0 (evidence name; dynamic_cast to Replicator, type descriptor
//     00938db4) and the std::_Count_if instance 004a1af0 on the children vector with it (pushed by getClientCount
//     004a227f / 004a2286);
//   * the "Port" property descriptor PropDescriptor<Server, int> (vtable 00823898; static initializer 007f1cf0 passes
//     "Port" 00823c0c, "Data" 00822490, the getter 004a1560 with adjustor 0, no setter and flags 5): its constructor
//     004a3f80, getset(get, int) 004a2030 and the GetImpl<int (Server::*)() const> setValue 004a1b70 (vtable
//     008234d0 slot 3; identical-code folded with the Mouse GetImpl setters, which call it at this address).
// Pending (NATIVE_APPUNIT4A0_PENDING; built only against a generated Server2008.h copy under rebuild/2008-06/out/, never
// counted): Server::stop(int) 004a1880 and Server::getClientCount() 004a2250, which Server2008.h does not declare.
#include "Network/Server2008.h"
#include "Network/Replicator2008.h"
#include <algorithm>

// Evidence name ?isReplicator@@YA_NV?$shared_ptr@VInstance@RBX@@@boost@@@Z (the donor declares it static; the
// mangling is the same, and external linkage keeps it emitted in the main build, where getClientCount is pending).
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

#ifdef NATIVE_APPUNIT4A0_PENDING
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
#endif
