// from server: 100% by auto
// roc 2008-06 00409d50  unit: RBX::VInstance::?$NonFactoryProduct  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00409d50
//
// 00409d50  6aff                 push -1
// 00409d52  6859cd7b00           push 0x7bcd59
// 00409d57  64a100000000         mov eax, dword ptr fs:[0]
// 00409d5d  50                   push eax
// 00409d5e  64892500000000       mov dword ptr fs:[0], esp
// 00409d65  51                   push ecx
// 00409d66  56                   push esi
// 00409d67  8bf1                 mov esi, ecx
// 00409d69  89742404             mov dword ptr [esp + 4], esi
// 00409d6d  ff1598288000         call dword ptr [0x802898]
// 00409d73  8b442418             mov eax, dword ptr [esp + 0x18]
// 00409d77  50                   push eax
// 00409d78  8d4e0c               lea ecx, [esi + 0xc]
// 00409d7b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00409d83  c706f8b78000         mov dword ptr [esi], 0x80b7f8
// 00409d89  ff155c248000         call dword ptr [0x80245c]
// 00409d8f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00409d93  8bc6                 mov eax, esi
// 00409d95  5e                   pop esi
// 00409d96  64890d00000000       mov dword ptr fs:[0], ecx
// 00409d9d  83c410               add esp, 0x10
// 00409da0  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
