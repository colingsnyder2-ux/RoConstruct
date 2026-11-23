// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is the stock boost 1.34 signal2<void,float,float>::operator().
// Explicit instantiation emits it. The disassembly shows the usual call_notification,
// slot_call_iterator begin/end construction and combiner (last_value<void>) call.
#include <functional>
#include <memory>
#include <boost/function.hpp>
#include <boost/signal.hpp>

typedef boost::function<void (float, float), std::allocator<void> > RbxFloat2Slot;

template class boost::signal2<void, float, float, boost::last_value<void>, int,
                              std::less<int>, RbxFloat2Slot>;
