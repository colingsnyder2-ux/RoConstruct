// from server: 100% by auto
// roc 2009-12 004fc410  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004fc410
//
// 004fc410  83ec08               sub esp, 8
// 004fc413  53                   push ebx
// 004fc414  55                   push ebp
// 004fc415  56                   push esi
// 004fc416  8bf1                 mov esi, ecx
// 004fc418  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004fc41b  57                   push edi
// 004fc41c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004fc41f  7606                 jbe 0x4fc427
// 004fc421  ff1560b79800         call dword ptr [0x98b760]
// 004fc427  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004fc42a  8b2e                 mov ebp, dword ptr [esi]
// 004fc42c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004fc42f  7606                 jbe 0x4fc437
// 004fc431  ff1560b79800         call dword ptr [0x98b760]
// 004fc437  8b06                 mov eax, dword ptr [esi]
// 004fc439  53                   push ebx
// 004fc43a  55                   push ebp
// 004fc43b  57                   push edi
// 004fc43c  50                   push eax
// 004fc43d  8d442420             lea eax, [esp + 0x20]
// 004fc441  50                   push eax
// 004fc442  8bce                 mov ecx, esi
// 004fc444  e8478df4ff           call 0x445190
// 004fc449  5f                   pop edi
// 004fc44a  5e                   pop esi
// 004fc44b  5d                   pop ebp
// 004fc44c  5b                   pop ebx
// 004fc44d  83c408               add esp, 8
// 004fc450  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
