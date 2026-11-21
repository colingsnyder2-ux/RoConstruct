// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native Reflection::Value / SignatureDescriptor default constructors (inactive). reflection/type.h declares
// both without a body. They belong to the reflection type.cpp object 00594a50..00594c05 (Type::singleton<void>
// 00594a50, Value() 00594ac0, list<Item> ctor 00594ae0, SignatureDescriptor::addArgument 00594b40, which is in
// ReflectionDescriptors.cpp: flags line copied from there).
#include "reflection/type.h"

namespace RBX
{
	namespace Reflection
	{
		// 00594ac0 ??0Value@Reflection@RBX@@QAE@XZ (registry identity-closure; called by every BoundFuncDesc ctor
		// for its default values, e.g. 00559d03, 005c50a3). _type = &Type::singleton<void>() 00594a50, empty any.
		Value::Value()
			: _type(&Type::singleton<void>())
		{
		}

		// 00594bf0 ??0SignatureDescriptor@Reflection@RBX@@QAE@XZ (registry; callers SignalDescriptor 0056baee and
		// FunctionDescriptor 005957d4): resultType = &Type::singleton<void>(), then the arguments list ctor 00594ae0.
		SignatureDescriptor::SignatureDescriptor()
			: resultType(&Type::singleton<void>())
		{
		}
	}
}
