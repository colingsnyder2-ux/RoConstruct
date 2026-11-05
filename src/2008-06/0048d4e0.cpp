// from server: 100% by auto
// roc 2008-06 0048d4e0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048d4e0
//
// 0048d4e0  83ec08               sub esp, 8
// 0048d4e3  53                   push ebx
// 0048d4e4  55                   push ebp
// 0048d4e5  56                   push esi
// 0048d4e6  8bf1                 mov esi, ecx
// 0048d4e8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0048d4eb  57                   push edi
// 0048d4ec  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0048d4ef  7606                 jbe 0x48d4f7
// 0048d4f1  ff1590288000         call dword ptr [0x802890]
// 0048d4f7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0048d4fa  8b2e                 mov ebp, dword ptr [esi]
// 0048d4fc  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0048d4ff  7606                 jbe 0x48d507
// 0048d501  ff1590288000         call dword ptr [0x802890]
// 0048d507  8b06                 mov eax, dword ptr [esi]
// 0048d509  53                   push ebx
// 0048d50a  55                   push ebp
// 0048d50b  57                   push edi
// 0048d50c  50                   push eax
// 0048d50d  8d442420             lea eax, [esp + 0x20]
// 0048d511  50                   push eax
// 0048d512  8bce                 mov ecx, esi
// 0048d514  e8078bfbff           call 0x446020
// 0048d519  5f                   pop edi
// 0048d51a  5e                   pop esi
// 0048d51b  5d                   pop ebp
// 0048d51c  5b                   pop ebx
// 0048d51d  83c408               add esp, 8
// 0048d520  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
