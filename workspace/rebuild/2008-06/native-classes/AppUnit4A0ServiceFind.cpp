// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /Irebuild/2008-06/native-headers/boost-noinline-shared-destructor /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "Network/Server2008.h"

namespace RBX
{
	template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template size_t ServiceProvider::doGetClassIndex<Network::Server>();
	template void ServiceProvider::callDoGetClassIndex<Network::Server>();
}
