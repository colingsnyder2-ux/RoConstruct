// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 004ac340 ??$callDoDeclare@$0A@@Name@RBX@@CAXXZ: explicit template instantiation (generic_templates.py, function form, byte-proved standalone)
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
#include "util/Name.h"
#include "util/Object.h"

template void RBX::Name::callDoDeclare<0>();
