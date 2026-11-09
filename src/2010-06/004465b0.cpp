// from server: 100% by auto
// roc 2010-06 004465b0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004465b0
//
// 004465b0  83ec08               sub esp, 8
// 004465b3  53                   push ebx
// 004465b4  55                   push ebp
// 004465b5  56                   push esi
// 004465b6  8bf1                 mov esi, ecx
// 004465b8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004465bb  57                   push edi
// 004465bc  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004465bf  7606                 jbe 0x4465c7
// 004465c1  ff150ca99e00         call dword ptr [0x9ea90c]
// 004465c7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004465ca  8b2e                 mov ebp, dword ptr [esi]
// 004465cc  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004465cf  7606                 jbe 0x4465d7
// 004465d1  ff150ca99e00         call dword ptr [0x9ea90c]
// 004465d7  8b06                 mov eax, dword ptr [esi]
// 004465d9  53                   push ebx
// 004465da  55                   push ebp
// 004465db  57                   push edi
// 004465dc  50                   push eax
// 004465dd  8d442420             lea eax, [esp + 0x20]
// 004465e1  50                   push eax
// 004465e2  8bce                 mov ecx, esi
// 004465e4  e857fdffff           call 0x446340
// 004465e9  5f                   pop edi
// 004465ea  5e                   pop esi
// 004465eb  5d                   pop ebp
// 004465ec  5b                   pop ebx
// 004465ed  83c408               add esp, 8
// 004465f0  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
