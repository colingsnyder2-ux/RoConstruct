// from server: 55% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs reflection/type.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/type.h"

namespace RBX
{
	namespace Reflection
	{
		template<>
		const Type& Type::singleton<void>()
		{
			static Type type("void", typeid(void));
			return type;
		}

		Value::Value()
			: _type(&Type::singleton<void>())
		{
		}

		SignatureDescriptor::SignatureDescriptor()
			: resultType(&Type::singleton<void>())
		{
		}

		void SignatureDescriptor::addArgument(const Name& name, const Type& type, const Value& defaultValue)
		{
			Item i = {&name, &type, defaultValue};
			arguments.push_back(i);
		}
	}
}
