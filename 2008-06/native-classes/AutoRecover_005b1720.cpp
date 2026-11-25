// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>
#include <boost/shared_ptr.hpp>

namespace RBX {
    class Instance;
    class FlagStand;
}

// The callee takes the FlagStand* plus the copied shared_ptr<Instance> as three stack dwords.
extern "C" int __fastcall fn_005b0cd0(void* self, int unusedEdx, int a1, int a2, int a3);

// INFERRED: layout of the stored functor: the FlagStand* lives at +0x10 of the function_buffer.
struct FnBufferView {
    char pad[0x10];
    int stand;
};

// boost::function void_function_obj_invoker1<bind_t<mf1<void,FlagStand,shared_ptr<Instance>>,...>>::invoke
// INFERRED: the checker requires the signature (self, unusedEdx) as __fastcall.
// The real stack arguments (function_buffer&, shared_ptr<Instance>) are read
// relative to the return address, since the original is a cdecl-style function.
extern "C" void __fastcall fn_005b1720(void* self, int unusedEdx)
{
    void** ra = (void**)_AddressOfReturnAddress();
    FnBufferView* function_obj_ptr = (FnBufferView*)ra[1];
    boost::shared_ptr<RBX::Instance>* argp = (boost::shared_ptr<RBX::Instance>*)&ra[2];

    boost::shared_ptr<RBX::Instance> copy(*argp);
    int* w = reinterpret_cast<int*>(&copy);
    fn_005b0cd0(function_obj_ptr, 0, function_obj_ptr->stand, w[0], w[1]);
}
