// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/content-cache-inline /I{headers}/boost-function-pod-vtable
#include <functional>
#include "util/NativeContentProvider.h"

namespace boost {
template<> template<>
function0<RBX::worker_thread::work_result, std::allocator<boost::function_base> >::function0(ContentProviderBind target, int) throw()
    : function_base()
{
    this->assign_to(target);
}
}

typedef char CallbackAbi32[sizeof(RBX::RequestCallback)==32?1:-1];
typedef char Function0Abi32[sizeof(boost::function0<RBX::worker_thread::work_result>)==32?1:-1];
typedef char BindingAbi16[sizeof(ContentProviderBind)==16?1:-1];
typedef char FunctorOffset8[offsetof(boost::function_base,functor)==8?1:-1];

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::_mfi::mf0<enum RBX::worker_thread::work_result,RBX::ContentProvider>;
