// roc 2012-06 009e0ef0  unit: CXTPTabClientWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e0ef0
//
// 009e0ef0  56                   push esi
// 009e0ef1  8bf1                 mov esi, ecx
// 009e0ef3  e8ba880b00           call 0xa997b2
// 009e0ef8  8bce                 mov ecx, esi
// 009e0efa  e821bcffff           call 0x9dcb20
// 009e0eff  8b10                 mov edx, dword ptr [eax]
// 009e0f01  8bc8                 mov ecx, eax
// 009e0f03  8b426c               mov eax, dword ptr [edx + 0x6c]
// 009e0f06  ffd0                 call eax
// 009e0f08  6a01                 push 1
// 009e0f0a  8bce                 mov ecx, esi
// 009e0f0c  e8cff8ffff           call 0x9e07e0
// 009e0f11  5e                   pop esi
// 009e0f12  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000010@CXTPTabClientWnd@ns_ROCX000010@@QAEXXZ)

namespace ns_ROCX000010 {
struct CXTPTabClientWnd
{
    void sub_738580();
    void* sub_689740();
    void sub_68d750(int);
    void fn_ROCX000010();
};

void CXTPTabClientWnd::fn_ROCX000010()
{
    sub_738580();
    void* p = sub_689740();
    (*(void (__thiscall**)(void*))(*(int*)p + 0x6c))(p);
    sub_68d750(1);
}
}
