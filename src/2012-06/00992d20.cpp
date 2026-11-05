// roc 2012-06 00992d20  unit: CXTPCommandBar  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00992d20
//
// 00992d20  e8cbffffff           call 0x992cf0
// 00992d25  85c0                 test eax, eax
// 00992d27  7404                 je 0x992d2d
// 00992d29  8b405c               mov eax, dword ptr [eax + 0x5c]
// 00992d2c  c3                   ret 
// 00992d2d  33c0                 xor eax, eax
// 00992d2f  c3                   ret 
// copied from an identical function in another client (function ?sub_006439b0@ns_ROCX000002@@YAHXZ)

namespace ns_ROCX000002 {
extern "C" void* sub_00643980();

int sub_006439b0()
{
    char* p = (char*)sub_00643980();
    if (p)
        return *(int*)(p + 0x5c);
    return 0;
}
}
