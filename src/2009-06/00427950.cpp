// from server: 100% by EspClaude
// roc 2009-06 00427950  unit: CWrapperView  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427950
//
// 00427950  8b442404             mov eax, dword ptr [esp + 4]
// 00427954  53                   push ebx
// 00427955  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00427959  55                   push ebp
// 0042795a  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0042795e  56                   push esi
// 0042795f  57                   push edi
// 00427960  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00427964  57                   push edi
// 00427965  53                   push ebx
// 00427966  55                   push ebp
// 00427967  50                   push eax
// 00427968  8bf1                 mov esi, ecx
// 0042796a  e8a1142f00           call 0x718e10
// 0042796f  85c0                 test eax, eax
// 00427971  740c                 je 0x42797f
// 00427973  5f                   pop edi
// 00427974  5e                   pop esi
// 00427975  5d                   pop ebp
// 00427976  b801000000           mov eax, 1
// 0042797b  5b                   pop ebx
// 0042797c  c21000               ret 0x10
// 0042797f  8b5658               mov edx, dword ptr [esi + 0x58]
// 00427982  8b442414             mov eax, dword ptr [esp + 0x14]
// 00427986  8b5214               mov edx, dword ptr [edx + 0x14]
// 00427989  57                   push edi
// 0042798a  53                   push ebx
// 0042798b  8d4e58               lea ecx, [esi + 0x58]
// 0042798e  55                   push ebp
// 0042798f  50                   push eax
// 00427990  ffd2                 call edx
// 00427992  5f                   pop edi
// 00427993  5e                   pop esi
// 00427994  5d                   pop ebp
// 00427995  5b                   pop ebx
// 00427996  c21000               ret 0x10
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
