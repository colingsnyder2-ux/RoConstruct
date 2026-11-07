// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/content-cache-inline /I{headers}/boost-function-pod-vtable
// >>> native-status (generated) -- do not edit >>>
// ContentProviderWorkerBinding | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 0041b92a | roc native-status --write
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
