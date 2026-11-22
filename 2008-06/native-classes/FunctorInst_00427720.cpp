// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 00427720: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
// INFERRED: std::allocator<boost::function_base> (boost default) over the byte-identical [('ctor', 'functionN', 'void')]
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "util/boost.hpp"
typedef boost::_bi::bind_t<RBX::worker_thread::work_result,RBX::worker_thread::work_result (*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >),boost::_bi::list1<boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > F;
template boost::function0<RBX::worker_thread::work_result, std::allocator<boost::function_base> >::function0(F, boost::enable_if_c<(boost::type_traits::ice_not<(boost::is_integral<F>::value)>::value), int>::type);

// 005c4b20 (batch 32): the same function0<work_result>(F, int) constructor for Visit::setPing 005c4bb0's
// boost::bind(&Visit::ping, url, interval) (AppUnit5BC_2008Visit.cpp; registry decorated name, `ret 0x28` = 0x24-byte
// bind_t by value + int). Like 00427720, it keeps the original EH frame for the by-value std::string only as this
// plain explicit instantiation; it moves here from the throw() member specialization of BoostFunctionBindCtors2008.cpp.
typedef boost::_bi::bind_t<RBX::worker_thread::work_result,RBX::worker_thread::work_result (*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int),boost::_bi::list2<boost::_bi::value<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,boost::_bi::value<int> > > PingF;
template boost::function0<RBX::worker_thread::work_result, std::allocator<boost::function_base> >::function0(PingF, boost::enable_if_c<(boost::type_traits::ice_not<(boost::is_integral<PingF>::value)>::value), int>::type);
