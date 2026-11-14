// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/boost-function-pod-vtable
#include <memory>
#include <boost/function.hpp>

namespace {
typedef bool (*PlainBoolCall)();
typedef boost::function0<bool, std::allocator<boost::function_base> > BoolFunction;
}

template BoolFunction& BoolFunction::operator=<PlainBoolCall>(PlainBoolCall);
