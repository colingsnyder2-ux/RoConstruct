// roc 2012-06 009b4240  unit: CXTPReportControl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b4240
//
// 009b4240  56                   push esi
// 009b4241  8bf1                 mov esi, ecx
// 009b4243  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 009b4246  85c9                 test ecx, ecx
// 009b4248  740e                 je 0x9b4258
// 009b424a  8b01                 mov eax, dword ptr [ecx]
// 009b424c  8b5068               mov edx, dword ptr [eax + 0x68]
// 009b424f  ffd2                 call edx
// 009b4251  c7462c00000000       mov dword ptr [esi + 0x2c], 0
// 009b4258  5e                   pop esi
// 009b4259  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00000a@CXTPReportColumn@ns_ROCX00000a@@QAEXXZ)

namespace ns_ROCX00000a {
struct CXTPReportColumn
{
    void fn_ROCX00000a();
};

void CXTPReportColumn::fn_ROCX00000a()
{
    if (*(void**)((char*)this + 0x2c) != 0)
    {
        void* p = *(void**)((char*)this + 0x2c);
        (*(void (__thiscall**)(void*))(*(int*)p + 0x68))(p);
        *(int*)((char*)this + 0x2c) = 0;
    }
}
}
