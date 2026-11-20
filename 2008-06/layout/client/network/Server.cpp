// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source /FIwinsock2.h
// 004a40d0: real name from the identity registry; body byte-proved against the native headers (named lane)
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
