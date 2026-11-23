// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: v8tree/Service.h does not declare ServiceProvider::onChildRemoving (the previous attempt failed with C2509).
// The macro below injects the protected declaration just before clearServices in the class body,
// since the header cannot be edited. The override is implicitly virtual through Instance.
#define clearServices onChildRemoving(Instance*); void clearServices
#include "v8tree/Service.h"
#undef clearServices

namespace RBX
{
	// 00572b40: look up the child's class name (DescribedBase +0x10, vtable slot 1) in serviceMap
	// (+0x1a8). If found, raise the notifier at +0x170 with an in-place shared_from of the child.
	// INFERRED: the raise at +0x170 is the ServiceRemoving notifier. The disassembly names the folded
	// ServiceAdded raise because both instantiations are identical.
	// INFERRED: ServiceRemoving has an Instance* constructor, as noted in the sibling source.
	void ServiceProvider::onChildRemoving(Instance* instance)
	{
		std::map<const Name*, boost::shared_ptr<Instance> >::iterator it = serviceMap.find(&instance->getClassName());
		if (it != serviceMap.end())
			Notifier<ServiceProvider, ServiceRemoving>::raise(ServiceRemoving(instance));
	}
}
