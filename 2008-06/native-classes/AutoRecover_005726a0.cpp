// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: v8tree/Service.h lacks the protected onDescendentAdded override. The macro below injects the
// declaration at the clearServices line (protected section) until the header owner adds it.
// Evidence: sibling AppUnit570_2008ServiceProvider.cpp batch 32 measured this body identical.
#define clearServices clearServices(void); void onDescendentAdded(Instance* instance); void clearServices_unused
#include "v8tree/Service.h"
#undef clearServices

namespace RBX
{
	void ServiceProvider::onDescendentAdded(Instance* instance)
	{
		Instance::onDescendentAdded(instance);
		instance->onServiceProvider(NULL, this);
	}
}
