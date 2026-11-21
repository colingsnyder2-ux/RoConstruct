// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005a8c10 ?on_eq@?$Bridge@PBVAllEnumDescriptors@Lua@RBX@@$0A@@Lua@RBX@@KAHPAUlua_State@@@Z: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/any.hpp>
#include "LuaBridge2008/LuaArguments2008.h"
#include "LuaBridge2008/LuaEnumBridge2008.h"
#include "util/Object.h"

template class RBX::Lua::Bridge<RBX::Lua::AllEnumDescriptors const *,0>;
