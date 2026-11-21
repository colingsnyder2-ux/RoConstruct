// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 2008-06 boost::function0<void> invoker for bind(string(*)(string), string) (inactive)
#include <string>
#include <boost/bind.hpp>
#include <boost/function.hpp>

typedef boost::_bi::bind_t<std::string, std::string (__cdecl *)(std::string),
	boost::_bi::list1<boost::_bi::value<std::string> > > StringBind;

template void boost::function0<void, std::allocator<void> >::assign_to<StringBind>(const StringBind&);
