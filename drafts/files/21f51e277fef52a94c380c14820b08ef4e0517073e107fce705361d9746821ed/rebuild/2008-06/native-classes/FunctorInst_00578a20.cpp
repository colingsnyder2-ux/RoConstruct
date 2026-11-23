// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 00578a20: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
// INFERRED: std::allocator<boost::function_base> (boost default) over the byte-identical [('ctor', 'functionN', 'void')]
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
typedef boost::_bi::bind_t<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > (*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list1<boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > F;
// 00578a20: the stored vtable 00830038 holds manage 00577aa0 and void_function_obj_invoker0<F, void>::invoke 00577630, so
// this is boost::function0<void> built from the string-returning bind (the result is discarded).
template boost::function0<void, std::allocator<boost::function_base> >::function0(F, boost::enable_if_c<(boost::type_traits::ice_not<(boost::is_integral<F>::value)>::value), int>::type);
