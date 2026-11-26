// from server: 100% by Xemicl
// roc 2012-06 0042ab20  unit: CSelectionTreeCtrl  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042ab20
//
// 0042ab20  53                   push ebx
// 0042ab21  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0042ab25  55                   push ebp
// 0042ab26  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0042ab2a  56                   push esi
// 0042ab2b  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0042ab2f  57                   push edi
// 0042ab30  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0042ab34  56                   push esi
// 0042ab35  57                   push edi
// 0042ab36  53                   push ebx
// 0042ab37  55                   push ebp
// 0042ab38  e8a57d5500           call 0x9828e2
// 0042ab3d  85c0                 test eax, eax
// 0042ab3f  740c                 je 0x42ab4d
// 0042ab41  5f                   pop edi
// 0042ab42  5e                   pop esi
// 0042ab43  5d                   pop ebp
// 0042ab44  b801000000           mov eax, 1
// 0042ab49  5b                   pop ebx
// 0042ab4a  c21000               ret 0x10
// 0042ab4d  8b0da063e100         mov ecx, dword ptr [0xe163a0]
// 0042ab53  85c9                 test ecx, ecx
// 0042ab55  7509                 jne 0x42ab60
// 0042ab57  5f                   pop edi
// 0042ab58  5e                   pop esi
// 0042ab59  5d                   pop ebp
// 0042ab5a  33c0                 xor eax, eax
// 0042ab5c  5b                   pop ebx
// 0042ab5d  c21000               ret 0x10
// 0042ab60  8b01                 mov eax, dword ptr [ecx]
// 0042ab62  8b5014               mov edx, dword ptr [eax + 0x14]
// 0042ab65  56                   push esi
// 0042ab66  57                   push edi
// 0042ab67  53                   push ebx
// 0042ab68  55                   push ebp
// 0042ab69  ffd2                 call edx
// 0042ab6b  5f                   pop edi
// 0042ab6c  5e                   pop esi
// 0042ab6d  5d                   pop ebp
// 0042ab6e  5b                   pop ebx
// 0042ab6f  c21000               ret 0x10
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