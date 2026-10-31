// from server: 100% by EspClaude
// roc 2009-06 0041d120  unit: CSelectionTreeCtrl  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041d120
//
// 0041d120  53                   push ebx
// 0041d121  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0041d125  55                   push ebp
// 0041d126  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0041d12a  56                   push esi
// 0041d12b  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0041d12f  57                   push edi
// 0041d130  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0041d134  56                   push esi
// 0041d135  57                   push edi
// 0041d136  53                   push ebx
// 0041d137  55                   push ebp
// 0041d138  e8ffc02f00           call 0x71923c
// 0041d13d  85c0                 test eax, eax
// 0041d13f  740c                 je 0x41d14d
// 0041d141  5f                   pop edi
// 0041d142  5e                   pop esi
// 0041d143  5d                   pop ebp
// 0041d144  b801000000           mov eax, 1
// 0041d149  5b                   pop ebx
// 0041d14a  c21000               ret 0x10
// 0041d14d  8b0de096a300         mov ecx, dword ptr [0xa396e0]
// 0041d153  85c9                 test ecx, ecx
// 0041d155  7509                 jne 0x41d160
// 0041d157  5f                   pop edi
// 0041d158  5e                   pop esi
// 0041d159  5d                   pop ebp
// 0041d15a  33c0                 xor eax, eax
// 0041d15c  5b                   pop ebx
// 0041d15d  c21000               ret 0x10
// 0041d160  8b01                 mov eax, dword ptr [ecx]
// 0041d162  8b5014               mov edx, dword ptr [eax + 0x14]
// 0041d165  56                   push esi
// 0041d166  57                   push edi
// 0041d167  53                   push ebx
// 0041d168  55                   push ebp
// 0041d169  ffd2                 call edx
// 0041d16b  5f                   pop edi
// 0041d16c  5e                   pop esi
// 0041d16d  5d                   pop ebp
// 0041d16e  5b                   pop ebx
// 0041d16f  c21000               ret 0x10
// copied from an identical function in another client (function ?fn_ROCX000077_00422960@ns_ROCX000077@@YGHHHHH@Z)

namespace ns_ROCX000077 {
struct CSelectionTreeCtrl;

extern "C" int __stdcall fn_ROCX000077_006a0e9c(int, int, int, int);

struct Inner
{
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual int vfunc5(int, int, int, int);
};

extern Inner* g_96c238;

int __stdcall fn_ROCX000077_00422960(int a, int b, int c, int d)
{
    if (fn_ROCX000077_006a0e9c(a, b, c, d))
        return 1;
    if (g_96c238 == 0)
        return 0;
    return g_96c238->vfunc5(a, b, c, d);
}
}
