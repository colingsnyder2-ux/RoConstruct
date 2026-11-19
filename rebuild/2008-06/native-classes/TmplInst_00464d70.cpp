// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00464d70 ?execute@EventData@?$MarshaledListener@VRunService@RBX@@W4RunState@2@V12@W432@@RBX@@UAEXXZ: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
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
#include "util/MarshaledListener.h"
#include "util/RunStateOwner.h"
#include "util/Object.h"

template class RBX::MarshaledListener<RBX::RunService,RBX::RunState,RBX::RunService,RBX::RunState>::EventData;
