// roc 2012-06 009addc0  unit: CXTPReportGroupRow_Batch  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009addc0
//
// 009addc0  51                   push ecx
// 009addc1  8b01                 mov eax, dword ptr [ecx]
// 009addc3  8b90fc000000         mov edx, dword ptr [eax + 0xfc]
// 009addc9  56                   push esi
// 009addca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 009addce  56                   push esi
// 009addcf  c744240800000000     mov dword ptr [esp + 8], 0
// 009addd7  ffd2                 call edx
// 009addd9  8bc6                 mov eax, esi
// 009adddb  5e                   pop esi
// 009adddc  59                   pop ecx
// 009adddd  c20400               ret 4
// copied from an identical function in another client (function ?Method@CXTPReportGroupRow_Batch@ns_ROCX000003@@QAEHH@Z)

namespace ns_ROCX000003 {
struct CXTPReportGroupRow_Batch
{
    int Method(int);
};

int CXTPReportGroupRow_Batch::Method(int arg)
{
    volatile int pad = 0;
    (*(void (__thiscall **)(CXTPReportGroupRow_Batch *, int))(*(int *)this + 0xfc))(this, arg);
    return arg;
}
}
