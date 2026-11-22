// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 0049a1e0: Creatable<Instance>::create<Network::Client>() (explicit template instantiation). The registry row
// carries the create<Hole> name, but the body allocates 0x150 bytes and calls Client::Client() 004a0990 (registry
// ??0Client@Network@RBX@@QAE@XZ), then shared_ptr<Client>(p, Deleter) 0049a130; the FactoryProduct<Client, Peer,
// sClient>::Creator::create 0049a260 (vtable 00822818, RTTI .?AVCreator@?$FactoryProduct@VClient@Network@RBX@@...)
// calls it. The real create<Hole> is 00580230 (Feature.h); its instantiation is kept below from the earlier revision
// of this unit (it brings the folded ~shared_ptr 00600660 that the registry names for Hole).
#include "Network/Client2008.h"
#include "v8datamodel/Feature.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Network::Client> RBX::Creatable<RBX::Instance>::create<RBX::Network::Client>();
// 00580230 (not 0049a1e0): create<Hole>, malloc 0x150, Hole() 0060c840.
template boost::shared_ptr<RBX::Hole> RBX::Creatable<RBX::Instance>::create<RBX::Hole>();
