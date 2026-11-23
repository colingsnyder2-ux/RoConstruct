// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: v8tree/Service.h does not declare ServiceProvider::onChildAdded, so this
// defines the body as an extern "C" fastcall thunk (fn_ convention) instead of a member.
// INFERRED: protected raise()/onChildAdded access is opened with the define below.
#define protected public
#include "v8tree/Service.h"
#undef protected

namespace RBX
{
	// 0x00572ca0 ServiceProvider::onChildAdded(Instance*), slot 7
	extern "C" void __fastcall fn_00572ca0(ServiceProvider* self, int unusedEdx, Instance* child)
	{
		if (dynamic_cast<Service*>(child) != NULL)
		{
			const Name& nullName = Name::getNullName();
			if (&child->getClassName() != &nullName)
				self->serviceMap[&child->getClassName()] = shared_from(child);

			// INFERRED: ServiceAdded carries a shared_ptr<Instance> built in place from child.
			self->Notifier<ServiceProvider, ServiceAdded>::raise(ServiceAdded(shared_from(child)));
		}
	}
}
