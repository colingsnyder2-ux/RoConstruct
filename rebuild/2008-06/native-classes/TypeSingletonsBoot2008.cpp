// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native (inactive): Type::singleton<T> instances the donor-free boot reaches.
//  - Surface 005eccf0 (exact): function-local static Type("Surface", typeid(Surface), "Complex"), atexit 006a17af.
//  - Tuple and PartInstance::FormFactor have NO Type::singleton in the 2008 exe: the exe registers FormFactor through
//    EnumPropDescriptor and ChangeHistoryService::GetCanUndo through a different result signature, while the native headers
//    still instantiate TypedPropertyDescriptor<FormFactor> / BoundFuncDesc<..., Tuple()> (queued header fix,
//    work/donorfree-route/QUEUED_FIXES.md). Stand-ins below only let the donor-free link run; delete them with that fix.
#include "reflection/reflection.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surface.h"

namespace RBX
{
	namespace Reflection
	{
		template<>
		const Type& Type::singleton<Surface>()
		{
			static Type type("Surface", typeid(Surface), "Complex");
			return type;
		}

		// INFERRED: stand-in, no exe counterpart.
		template<>
		const Type& Type::singleton<Tuple>()
		{
			static Type type("Tuple", typeid(Tuple), "Complex");
			return type;
		}

		// INFERRED: stand-in, no exe counterpart.
		template<>
		const Type& Type::singleton<PartInstance::FormFactor>()
		{
			static Type type("FormFactor", typeid(PartInstance::FormFactor), "Enum");
			return type;
		}
	}
}
