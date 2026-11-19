// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../../../tools/rbxgs/Client/App/include/script/ThreadRef.h"

namespace RBX {
namespace Lua {
FunctionRef::FunctionRef()
    : ThreadRef()
{
    functionId = 0;
}
}
}
