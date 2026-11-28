// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 004a15f0 FactoryProduct<Network::Server, Network::Peer, sServer>::FactoryProduct(): Peer::Peer() 004b4640 then the
// FactoryProduct vtables. Registry name 'ScriptContext::ScriptContext' is an ICF fold label. It was a `return 0` stub:
// Server::Server read a null rakPeer (+0x140) when Insert Object probed NetworkServer.
#include "util/Object.h"
#include "Network/Server2008.h"
namespace RBX { template<typename Class, typename DerivedClass, const char* ClassName>
 FactoryProduct<Class, DerivedClass, ClassName>::FactoryProduct() {} }
template RBX::FactoryProduct<RBX::Network::Server, RBX::Network::Peer, RBX::Network::sServer>::FactoryProduct();
