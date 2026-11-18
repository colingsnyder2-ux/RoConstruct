// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 00596bd0: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
typedef boost::detail::tss_adapter<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > F;
template boost::thread_specific_ptr<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >::thread_specific_ptr();
