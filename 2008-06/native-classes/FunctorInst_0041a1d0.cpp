// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 0041a1d0: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
// INFERRED: std::allocator<boost::function_base> (boost default) over the byte-identical [('manager', '', 'void')]
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "AppLeaves2008/DHTMLWindow2008.h"
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,DHTMLWindow,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::list2<boost::_bi::value<boost::shared_ptr<DHTMLWindow> >,boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > F;
template struct boost::detail::function::functor_manager<F, std::allocator<boost::function_base> >;
