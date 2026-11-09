// from server: 100% by auto
// roc 2010-06 0041f4c0  unit: CSelectionTreeCtrl  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041f4c0
//
// 0041f4c0  83ec08               sub esp, 8
// 0041f4c3  53                   push ebx
// 0041f4c4  55                   push ebp
// 0041f4c5  56                   push esi
// 0041f4c6  8bf1                 mov esi, ecx
// 0041f4c8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0041f4cb  57                   push edi
// 0041f4cc  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0041f4cf  7606                 jbe 0x41f4d7
// 0041f4d1  ff150ca99e00         call dword ptr [0x9ea90c]
// 0041f4d7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0041f4da  8b2e                 mov ebp, dword ptr [esi]
// 0041f4dc  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0041f4df  7606                 jbe 0x41f4e7
// 0041f4e1  ff150ca99e00         call dword ptr [0x9ea90c]
// 0041f4e7  8b06                 mov eax, dword ptr [esi]
// 0041f4e9  53                   push ebx
// 0041f4ea  55                   push ebp
// 0041f4eb  57                   push edi
// 0041f4ec  50                   push eax
// 0041f4ed  8d442420             lea eax, [esp + 0x20]
// 0041f4f1  50                   push eax
// 0041f4f2  8bce                 mov ecx, esi
// 0041f4f4  e8a7491e00           call 0x603ea0
// 0041f4f9  5f                   pop edi
// 0041f4fa  5e                   pop esi
// 0041f4fb  5d                   pop ebp
// 0041f4fc  5b                   pop ebx
// 0041f4fd  83c408               add esp, 8
// 0041f500  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
