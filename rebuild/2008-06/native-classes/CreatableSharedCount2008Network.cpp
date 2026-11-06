// boost::detail::shared_count::shared_count<T*, RBX::Creatable<RBX::Instance>::Deleter>(T*, Deleter) instances (2008-06,
// inactive). Each original is a 131-byte COMDAT (pinned extent: ret 8 at +0x6b, then the catch(...) funclet that
// calls the deleter and rethrows) storing the sp_counted_impl_pd<T*, Deleter> vtable named by its RTTI; the
// expected address and T of every instance are listed in tests/record_native_creatable_shared_count.py.
// Separate unit: T = RBX::Network::Client / Server come from the native Network/Client2008.h / Server2008.h
// (record_native_network_client_server2008.py), which need the RakNet raknet30/Source headers ahead of windows.h;
// nothing is declared here.
#include "Network/Client2008.h"
#include "Network/Server2008.h"

typedef RBX::Creatable<RBX::Instance>::Deleter CreatableInstanceDeleter;

template boost::detail::shared_count::shared_count(RBX::Network::Client*, CreatableInstanceDeleter); // 0049a0a0
template boost::detail::shared_count::shared_count(RBX::Network::Server*, CreatableInstanceDeleter); // 0049a310
