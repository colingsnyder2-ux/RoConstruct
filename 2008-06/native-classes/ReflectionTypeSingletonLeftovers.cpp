// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 2008-06 native Reflection::Type::singleton<T> specializations that no other native unit defines (inactive).
// Each body is the same shape as AppUnit564_2008Type.cpp: a function-local static Type(name, typeid(T)) built through
// the header-inline Type(const char*, const type_info&) 0056bd90, registered for destruction with atexit 006a17af.
// The name string and the type descriptor are read from the two pushes of each original body; the registry names
// every address (decorated ??$singleton@...@Type@Reflection@RBX@@SAABV012@XZ).
#include "reflection/type.h"
#include "reflection/property.h"
#include "luafunction-threadref/script/ThreadRef.h"
#include <G3D/CoordinateFrame.h>

namespace RBX
{
	namespace Reflection
	{
		// 0056be70: "Property" 0082f638, type descriptor 00943aa0 (.PBVPropertyDescriptor@Reflection@RBX@@),
		// static 00974b04 guarded by bit 0 of 00974b14, atexit 007fd1b0.
		template<>
		const Type& Type::singleton<const PropertyDescriptor*>()
		{
			static Type type("Property", typeid(const PropertyDescriptor*));
			return type;
		}

		// 00593d20: "Function" 00832268, type descriptor 0092c2d0 (.?AVFunctionRef@Lua@RBX@@), atexit 007fda70.
		template<>
		const Type& Type::singleton<Lua::FunctionRef>()
		{
			static Type type("Function", typeid(Lua::FunctionRef));
			return type;
		}

		// 00594a50: "void" 008322c0, type descriptor 00929614 (.X), static 00975c74 (guard 00975c84), atexit 007fdac0.
		template<>
		const Type& Type::singleton<void>()
		{
			static Type type("void", typeid(void));
			return type;
		}

		// 00599a00: "CoordinateFrame" 00832b2c, type descriptor 00946380 (.?AVCoordinateFrame@G3D@@), atexit 007fdbb0.
		template<>
		const Type& Type::singleton<G3D::CoordinateFrame>()
		{
			static Type type("CoordinateFrame", typeid(G3D::CoordinateFrame));
			return type;
		}
	}
}
