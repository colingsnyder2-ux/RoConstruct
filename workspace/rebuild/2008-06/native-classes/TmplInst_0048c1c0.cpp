// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0048c1c0 ??R?$bind_t@XP6AXV?$shared_ptr@X@boost@@0@ZV?$list2@V?$value@V?$shared_ptr@X@boost@@@_bi@boost@@V123@@_bi@2@@_: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
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

template class boost::_bi::bind_t<void,void (__cdecl*)(boost::shared_ptr<void>,boost::shared_ptr<void>),boost::_bi::list2<boost::_bi::value<boost::shared_ptr<void> >,boost::_bi::value<boost::shared_ptr<void> > > >;
