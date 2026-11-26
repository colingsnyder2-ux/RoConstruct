// from server: 100% by Xemicl
// roc 2012-06 00435570  unit: CWrapperView  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00435570
//
// 00435570  8b442404             mov eax, dword ptr [esp + 4]
// 00435574  53                   push ebx
// 00435575  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00435579  55                   push ebp
// 0043557a  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0043557e  56                   push esi
// 0043557f  57                   push edi
// 00435580  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00435584  57                   push edi
// 00435585  53                   push ebx
// 00435586  55                   push ebp
// 00435587  50                   push eax
// 00435588  8bf1                 mov esi, ecx
// 0043558a  e85dcf5400           call 0x9824ec
// 0043558f  85c0                 test eax, eax
// 00435591  740c                 je 0x43559f
// 00435593  5f                   pop edi
// 00435594  5e                   pop esi
// 00435595  5d                   pop ebp
// 00435596  b801000000           mov eax, 1
// 0043559b  5b                   pop ebx
// 0043559c  c21000               ret 0x10
// 0043559f  8b5658               mov edx, dword ptr [esi + 0x58]
// 004355a2  8b442414             mov eax, dword ptr [esp + 0x14]
// 004355a6  8b5214               mov edx, dword ptr [edx + 0x14]
// 004355a9  57                   push edi
// 004355aa  53                   push ebx
// 004355ab  8d4e58               lea ecx, [esi + 0x58]
// 004355ae  55                   push ebp
// 004355af  50                   push eax
// 004355b0  ffd2                 call edx
// 004355b2  5f                   pop edi
// 004355b3  5e                   pop esi
// 004355b4  5d                   pop ebp
// 004355b5  5b                   pop ebx
// 004355b6  c21000               ret 0x10
// copied from an identical function in another client (function ?Dispatch@CWrapperView@ns_ROCX0000e7@@QAEHHHHH@Z)

namespace ns_ROCX0000e7 {
typedef int (__thiscall *DispatchFn)(void *, int, int, int, int);

struct CWrapperView {
    char padding[0x58];
    struct {
        DispatchFn *vtable;
    } target;

    int BaseDispatch(int, int, int, int);
    int Dispatch(int, int, int, int);
};

int CWrapperView::Dispatch(int a, int b, int c, int d) {
    if (BaseDispatch(a, b, c, d))
        return 1;
    return target.vtable[5](&target, a, b, c, d);
}
}