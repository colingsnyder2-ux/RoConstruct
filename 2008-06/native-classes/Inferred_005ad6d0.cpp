// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005ad6d0 (placeholder name for 005ad6d0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <vector>
#include <memory>
#include "util/Name.h"
#include "LuaBridge2008/LuaArguments2008.h"

namespace RBX {

void sub_005ad6d0(std::auto_ptr<std::vector<Reflection::Value> >& values, lua_State* L, unsigned int count)
{
    values.reset(new std::vector<Reflection::Value>(count));

    for (unsigned int i = 0; i < count; )
    {
        Reflection::Value& value = values->at(i);
        ++i;
        Lua::LuaArguments2008::get(L, i, value, true);
    }
}

}
