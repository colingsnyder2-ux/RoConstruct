// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/reflection/type.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/type.h"

namespace RBX {
namespace Reflection {

// FUNCTION: WEBSERVICE 0x100711b0
template <>
const Type& Type::singleton<void>()
{
	static Type type("void", typeid(void));

	return type;
}

// FUNCTION: WEBSERVICE 0x10071220
Value::Value() : _type(&Type::singleton<void>())
{
}

// FUNCTION: WEBSERVICE 0x10071260
void SignatureDescriptor::addArgument(const Name& name, const Type& type, const Value& defaultValue)
{
	Item i = {&name, &type, defaultValue};

	arguments.push_back(i);
}

// FUNCTION: WEBSERVICE 0x10071310
SignatureDescriptor::SignatureDescriptor() : resultType(&Type::singleton<void>())
{
}

} // namespace Reflection
} // namespace RBX
