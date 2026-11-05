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
