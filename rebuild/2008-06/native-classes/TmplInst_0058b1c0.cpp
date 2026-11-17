// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0058b1c0 ?clone@?$holder@V?$vector@VValue@Reflection@RBX@@V?$allocator@VValue@Reflection@RBX@@@std@@@std@@@any@boost@@U: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
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
#include "reflection/type.h"
#include "util/Object.h"

template class boost::any::holder<std::vector<RBX::Reflection::Value,std::allocator<RBX::Reflection::Value> > >;
