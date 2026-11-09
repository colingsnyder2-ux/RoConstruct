// from server: 100% by auto
// roc 2009-06 004b64c0  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b64c0
//
// 004b64c0  53                   push ebx
// 004b64c1  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 004b64c7  56                   push esi
// 004b64c8  8bf1                 mov esi, ecx
// 004b64ca  57                   push edi
// 004b64cb  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004b64ce  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004b64d1  7602                 jbe 0x4b64d5
// 004b64d3  ffd3                 call ebx
// 004b64d5  8b36                 mov esi, dword ptr [esi]
// 004b64d7  85f6                 test esi, esi
// 004b64d9  750f                 jne 0x4b64ea
// 004b64db  ffd3                 call ebx
// 004b64dd  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004b64e0  7202                 jb 0x4b64e4
// 004b64e2  ffd3                 call ebx
// 004b64e4  8bc7                 mov eax, edi
// 004b64e6  5f                   pop edi
// 004b64e7  5e                   pop esi
// 004b64e8  5b                   pop ebx
// 004b64e9  c3                   ret 
// 004b64ea  8b36                 mov esi, dword ptr [esi]
// 004b64ec  ebef                 jmp 0x4b64dd
// standard library vector<ptr> (function ?front@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
