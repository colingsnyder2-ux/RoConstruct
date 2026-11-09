// from server: 100% by auto
// roc 2007-08 00489b60  unit: RBX::Network::VPlayer::?$Notifier  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00489b60
//
// 00489b60  83ec08               sub esp, 8
// 00489b63  53                   push ebx
// 00489b64  55                   push ebp
// 00489b65  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 00489b6b  56                   push esi
// 00489b6c  8bf1                 mov esi, ecx
// 00489b6e  57                   push edi
// 00489b6f  8b7e08               mov edi, dword ptr [esi + 8]
// 00489b72  397e04               cmp dword ptr [esi + 4], edi
// 00489b75  7602                 jbe 0x489b79
// 00489b77  ffd5                 call ebp
// 00489b79  8b5e04               mov ebx, dword ptr [esi + 4]
// 00489b7c  3b5e08               cmp ebx, dword ptr [esi + 8]
// 00489b7f  7602                 jbe 0x489b83
// 00489b81  ffd5                 call ebp
// 00489b83  57                   push edi
// 00489b84  56                   push esi
// 00489b85  53                   push ebx
// 00489b86  56                   push esi
// 00489b87  8d442420             lea eax, [esp + 0x20]
// 00489b8b  50                   push eax
// 00489b8c  8bce                 mov ecx, esi
// 00489b8e  e8ddbbfbff           call 0x445770
// 00489b93  5f                   pop edi
// 00489b94  5e                   pop esi
// 00489b95  5d                   pop ebp
// 00489b96  5b                   pop ebx
// 00489b97  83c408               add esp, 8
// 00489b9a  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
