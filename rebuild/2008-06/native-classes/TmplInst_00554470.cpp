// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00554470 ??4?$function1@XPAXV?$allocator@Vfunction_base@boost@@@std@@@boost@@QAEAAV01@ABV01@@Z: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
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
#include "util/Object.h"

template class boost::function1<void,void *,std::allocator<boost::function_base> >;
