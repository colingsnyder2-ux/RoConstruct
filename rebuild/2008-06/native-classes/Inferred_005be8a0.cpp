// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_005be8a0 (placeholder name for 005be8a0 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "util/Name.h"
#include "util/Utilities.h"

namespace RBX {

std::string sub_005be8a0(const short* values)
{
    std::string result = StringConverter<int>::convertToString(static_cast<int>(values[0]));
    result += ", ";
    result += StringConverter<int>::convertToString(static_cast<int>(values[1]));
    return result;
}

}
