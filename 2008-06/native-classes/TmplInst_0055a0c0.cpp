// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0055a0c0 ??0?$BoundFuncDesc@VRunService@RBX@@$$A6AXXZ$0A@@Reflection@RBX@@QAE@P8RunService@2@AEXXZPBDW4Security@Functio: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
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
#include "reflection/reflection.h"
#include "util/RunStateOwner.h"
#include "reflection/function.h"
#include "util/Object.h"

template class RBX::Reflection::BoundFuncDesc<RBX::RunService,void __cdecl(void),0>;
