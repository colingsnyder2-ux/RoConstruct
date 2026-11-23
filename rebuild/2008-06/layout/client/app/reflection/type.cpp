#include "reflection/type.h"

namespace RBX
{
	namespace Reflection
	{
		Value::Value()
			: _type(&Type::singleton<void>())
		{
		}

		SignatureDescriptor::SignatureDescriptor()
			: resultType(&Type::singleton<void>())
		{
		}
	}
}
