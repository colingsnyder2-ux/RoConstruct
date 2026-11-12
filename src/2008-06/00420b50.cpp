// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/reflection/type.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/type.h"

namespace RBX {
namespace Reflection {

// FUNCTION: WEBSERVICE 0x100711b0
// FUNCTION: ROBLOX 0x005a57f0
template <>
const Type& Type::singleton<void>()
{
	static Type type("void", typeid(void));

	return type;
}

// FUNCTION: WEBSERVICE 0x10071220
// FUNCTION: ROBLOX 0x005a5860
Value::Value() : _type(&Type::singleton<void>())
{
}

// FUNCTION: WEBSERVICE 0x10071260
// FUNCTION: ROBLOX 0x005a58a0
void SignatureDescriptor::addArgument(const Name& name, const Type& type, const Value& defaultValue)
{
	Item i = {&name, &type, defaultValue};

	arguments.push_back(i);
}

// FUNCTION: WEBSERVICE 0x10071310
// FUNCTION: ROBLOX 0x005a5950
SignatureDescriptor::SignatureDescriptor() : resultType(&Type::singleton<void>())
{
}

} // namespace Reflection
} // namespace RBX
