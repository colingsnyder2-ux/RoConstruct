// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native ServiceProvider::find<Class>(const Instance* context) (static), out of line. v8tree/Service.h declares
// the template without a body: callers reference one definition per service class, as in the exe (Teams 0049ab50,
// ScriptContext 00586910, ControllerService 005a32e0). Body (0049ab50): walk the parent chain from `context`
// (Instance::parent +0x104), dynamic_cast each Instance to ServiceProvider, and tail-call the member find<Class>().
#include "v8tree/Service.h"
#include "v8datamodel/Teams.h"
#include "script/ScriptContext.h"
#include "v8datamodel/UserController.h"
#include "util/ContentProvider.h"
#include "v8datamodel/GeometryService.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/Visit.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/PhysicsService.h"

namespace RBX
{
	template<class Class>
	Class* ServiceProvider::find(const Instance* context)
	{
		for (const Instance* instance = context; instance != NULL; instance = instance->getParent())
		{
			const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(instance);
			if (provider != NULL)
				return provider->find<Class>();
		}
		return NULL;
	}

	// The static create<Class>(const Instance*) has the same walk and tail-calls the member create<Class>() (00465210).
	template<class Class>
	Class* ServiceProvider::create(const Instance* context)
	{
		for (const Instance* instance = context; instance != NULL; instance = instance->getParent())
		{
			const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(instance);
			if (provider != NULL)
				return provider->create<Class>();
		}
		return NULL;
	}

	template Teams* ServiceProvider::find<Teams>(const Instance*);                       // 0049ab50
	template ScriptContext* ServiceProvider::find<ScriptContext>(const Instance*);        // 00586910
	template ControllerService* ServiceProvider::find<ControllerService>(const Instance*); // 005a32e0
	template ContentProvider* ServiceProvider::find<ContentProvider>(const Instance*);
	template GeometryService* ServiceProvider::find<GeometryService>(const Instance*);
	template RunService* ServiceProvider::find<RunService>(const Instance*);
	template Visit* ServiceProvider::find<Visit>(const Instance*);

	template ContentProvider* ServiceProvider::create<ContentProvider>(const Instance*);       // 00465210
	template ControllerService* ServiceProvider::create<ControllerService>(const Instance*);
	template FlagStandService* ServiceProvider::create<FlagStandService>(const Instance*);
	template PhysicsService* ServiceProvider::create<PhysicsService>(const Instance*);
}
