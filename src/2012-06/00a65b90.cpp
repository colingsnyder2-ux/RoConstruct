// roc 2012-06 00a65b90  unit: CXTPOffice2007Image  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a65b90
//
// 00a65b90  83ec08               sub esp, 8
// 00a65b93  8d0424               lea eax, [esp]
// 00a65b96  50                   push eax
// 00a65b97  e804ffffff           call 0xa65aa0
// 00a65b9c  8b00                 mov eax, dword ptr [eax]
// 00a65b9e  83c408               add esp, 8
// 00a65ba1  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00004d@ns_ROCX00004d@@YAHXZ)

namespace ns_ROCX00004d {
extern int* __stdcall fn_ROCX00004d(void*);

int fn_ROCX00004d()
{
    int buffer[2];
    return *fn_ROCX00004d(buffer);
}
}
