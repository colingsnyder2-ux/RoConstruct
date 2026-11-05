// from server: 100% by auto
// roc 2009-06 004b8f40  unit: RBX::Network::Player  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b8f40
//
// 004b8f40  83ec08               sub esp, 8
// 004b8f43  53                   push ebx
// 004b8f44  55                   push ebp
// 004b8f45  56                   push esi
// 004b8f46  8bf1                 mov esi, ecx
// 004b8f48  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004b8f4b  57                   push edi
// 004b8f4c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004b8f4f  7606                 jbe 0x4b8f57
// 004b8f51  ff15ace98900         call dword ptr [0x89e9ac]
// 004b8f57  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004b8f5a  8b2e                 mov ebp, dword ptr [esi]
// 004b8f5c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004b8f5f  7606                 jbe 0x4b8f67
// 004b8f61  ff15ace98900         call dword ptr [0x89e9ac]
// 004b8f67  8b06                 mov eax, dword ptr [esi]
// 004b8f69  53                   push ebx
// 004b8f6a  55                   push ebp
// 004b8f6b  57                   push edi
// 004b8f6c  50                   push eax
// 004b8f6d  8d442420             lea eax, [esp + 0x20]
// 004b8f71  50                   push eax
// 004b8f72  8bce                 mov ecx, esi
// 004b8f74  e8a77bf8ff           call 0x440b20
// 004b8f79  5f                   pop edi
// 004b8f7a  5e                   pop esi
// 004b8f7b  5d                   pop ebp
// 004b8f7c  5b                   pop ebx
// 004b8f7d  83c408               add esp, 8
// 004b8f80  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
