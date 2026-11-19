// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::Reflection::Value::sub_00443590 (placeholder name for 00443590 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "reflection/type.h"

RBX::Reflection::Value& RBX::Reflection::Value::sub_00443590(const std::string& v)
{
    _type = &Type::singleton<std::string>();
    value = v;
    return *this;
}
