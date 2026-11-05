// roc 2009-12 0085bfd0  unit: CXTPStatusBarPane  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085bfd0
//
// 0085bfd0  53                   push ebx
// 0085bfd1  55                   push ebp
// 0085bfd2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0085bfd6  56                   push esi
// 0085bfd7  55                   push ebp
// 0085bfd8  8bd9                 mov ebx, ecx
// 0085bfda  e821f3ffff           call 0x85b300
// 0085bfdf  8bf0                 mov esi, eax
// 0085bfe1  85f6                 test esi, esi
// 0085bfe3  7439                 je 0x85c01e
// 0085bfe5  8b4628               mov eax, dword ptr [esi + 0x28]
// 0085bfe8  57                   push edi
// 0085bfe9  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0085bfed  3bc7                 cmp eax, edi
// 0085bfef  742c                 je 0x85c01d
// 0085bff1  33c7                 xor eax, edi
// 0085bff3  a900000008           test eax, 0x8000000
// 0085bff8  740e                 je 0x85c008
// 0085bffa  6a00                 push 0
// 0085bffc  6a01                 push 1
// 0085bffe  8bcb                 mov ecx, ebx
// 0085c000  897e28               mov dword ptr [esi + 0x28], edi
// 0085c003  e898fdffff           call 0x85bda0
// 0085c008  834e2c01             or dword ptr [esi + 0x2c], 1
// 0085c00c  897e28               mov dword ptr [esi + 0x28], edi
// 0085c00f  6a01                 push 1
// 0085c011  83c630               add esi, 0x30
// 0085c014  56                   push esi
// 0085c015  55                   push ebp
// 0085c016  8bcb                 mov ecx, ebx
// 0085c018  e8e3f3ffff           call 0x85b400
// 0085c01d  5f                   pop edi
// 0085c01e  5e                   pop esi
// 0085c01f  5d                   pop ebp
// 0085c020  5b                   pop ebx
// 0085c021  c20800               ret 8
// copied from an identical function in another client (function ?f@CXTPStatusBar@ns_ROCX00001a@ns_ROCX00008e@@QAEXHH@Z)

namespace ns_ROCX00001a {
namespace ns_ROCX000006 {
struct CXTPCustomizeSheet {
    char pad[0xb8];
    void* field_b8;
    void func(void*);
};

void CXTPCustomizeSheet::func(void* arg)
{
    void* p = arg;
    void (__thiscall**vt)(void*, int) = *(void (__thiscall***)(void*, int))p;
    vt[1](p, 0);
    void* q = *(void**)((char*)this->field_b8 + 0x58);
    if (q) {
        void (__thiscall**vt2)(void*, int) = *(void (__thiscall***)(void*, int))p;
        vt2[1](p, *(int*)((char*)q + 0x98));
        void (__thiscall**vt3)(void*, int) = *(void (__thiscall***)(void*, int))p;
        int flag = (*(int*)((char*)q + 0x80) != 0);
        vt3[0](p, flag);
    }
}
}
}
