// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00577670 ?invoke@?$void_function_obj_invoker0@V?$bind_t@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@P: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
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

template class boost::detail::function::void_function_obj_invoker0<boost::_bi::bind_t<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > (__cdecl*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list1<boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >,void>;
