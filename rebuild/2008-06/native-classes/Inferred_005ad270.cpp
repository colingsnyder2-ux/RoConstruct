// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::Reflection::Value::sub_005ad270 (placeholder name for 005ad270 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "reflection/type.h"

RBX::Reflection::Value& RBX::Reflection::Value::sub_005ad270(const std::vector<RBX::Reflection::Value>& v)
{
    _type = &RBX::Reflection::Type::singleton<std::vector<RBX::Reflection::Value> >();
    value = v;
    return *this;
}
