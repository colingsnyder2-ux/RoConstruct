// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005a8ec0 (placeholder name for 005a8ec0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <lua.h>
#include "v8tree/Instance.h"
#include "LuaBridge2008/LuaBridge2008.h"

namespace RBX {
namespace Lua {

int sub_005a8ec0(const boost::shared_ptr<RBX::Reflection::DescribedBase>& object, lua_State* L)
{
    if (RBX::Instance* instance = dynamic_cast<RBX::Instance*>(object.get()))
    {
        lua_pushstring(L, instance->getName().c_str());
        return 1;
    }
    lua_pushstring(L, object->getDescriptor().name.toString().c_str());
    return 1;
}

}
}
