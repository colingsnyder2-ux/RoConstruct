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
