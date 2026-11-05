// from server: 100% by auto
// roc 2007-08 00439d80  unit: RBX::VSoundId::?$XItem  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00439d80
//
// 00439d80  83ec08               sub esp, 8
// 00439d83  53                   push ebx
// 00439d84  55                   push ebp
// 00439d85  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 00439d8b  56                   push esi
// 00439d8c  8bf1                 mov esi, ecx
// 00439d8e  57                   push edi
// 00439d8f  8b7e08               mov edi, dword ptr [esi + 8]
// 00439d92  397e04               cmp dword ptr [esi + 4], edi
// 00439d95  7602                 jbe 0x439d99
// 00439d97  ffd5                 call ebp
// 00439d99  8b5e04               mov ebx, dword ptr [esi + 4]
// 00439d9c  3b5e08               cmp ebx, dword ptr [esi + 8]
// 00439d9f  7602                 jbe 0x439da3
// 00439da1  ffd5                 call ebp
// 00439da3  57                   push edi
// 00439da4  56                   push esi
// 00439da5  53                   push ebx
// 00439da6  56                   push esi
// 00439da7  8d442420             lea eax, [esp + 0x20]
// 00439dab  50                   push eax
// 00439dac  8bce                 mov ecx, esi
// 00439dae  e8ed3e1900           call 0x5cdca0
// 00439db3  5f                   pop edi
// 00439db4  5e                   pop esi
// 00439db5  5d                   pop ebp
// 00439db6  5b                   pop ebx
// 00439db7  83c408               add esp, 8
// 00439dba  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
