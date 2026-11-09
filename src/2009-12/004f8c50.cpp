// from server: 100% by auto
// roc 2009-12 004f8c50  unit: RBX::VBrickColor::?$holder  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004f8c50
//
// 004f8c50  53                   push ebx
// 004f8c51  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 004f8c57  56                   push esi
// 004f8c58  8bf1                 mov esi, ecx
// 004f8c5a  57                   push edi
// 004f8c5b  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004f8c5e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004f8c61  7602                 jbe 0x4f8c65
// 004f8c63  ffd3                 call ebx
// 004f8c65  8b36                 mov esi, dword ptr [esi]
// 004f8c67  85f6                 test esi, esi
// 004f8c69  750f                 jne 0x4f8c7a
// 004f8c6b  ffd3                 call ebx
// 004f8c6d  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004f8c70  7202                 jb 0x4f8c74
// 004f8c72  ffd3                 call ebx
// 004f8c74  8bc7                 mov eax, edi
// 004f8c76  5f                   pop edi
// 004f8c77  5e                   pop esi
// 004f8c78  5b                   pop ebx
// 004f8c79  c3                   ret 
// 004f8c7a  8b36                 mov esi, dword ptr [esi]
// 004f8c7c  ebef                 jmp 0x4f8c6d
// standard library vector<ptr> (function ?front@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
