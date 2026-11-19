// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0041a1d0 ?manager@?$functor_manager@V?$bind_t@XV?$mf1@XVDHTMLWindow@@V?$basic_string@DU?$char_traits@D@std@@V?$allocato: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
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
#include "AppLeaves2008/DHTMLWindow2008.h"
#include "util/Object.h"

template class boost::detail::function::functor_manager<boost::_bi::bind_t<void,boost::_mfi::mf1<void,DHTMLWindow,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::list2<boost::_bi::value<boost::shared_ptr<DHTMLWindow> >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >,std::allocator<boost::function_base> >;
