// from server: 100% by auto
// roc 2009-12 006be500  unit: RBX::VInstance::?$NonFactoryProduct  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006be500
//
// 006be500  53                   push ebx
// 006be501  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 006be507  56                   push esi
// 006be508  8b31                 mov esi, dword ptr [ecx]
// 006be50a  57                   push edi
// 006be50b  8b7914               mov edi, dword ptr [ecx + 0x14]
// 006be50e  85f6                 test esi, esi
// 006be510  7502                 jne 0x6be514
// 006be512  ffd3                 call ebx
// 006be514  8b7f04               mov edi, dword ptr [edi + 4]
// 006be517  85f6                 test esi, esi
// 006be519  7404                 je 0x6be51f
// 006be51b  8b06                 mov eax, dword ptr [esi]
// 006be51d  eb02                 jmp 0x6be521
// 006be51f  33c0                 xor eax, eax
// 006be521  3b7814               cmp edi, dword ptr [eax + 0x14]
// 006be524  7502                 jne 0x6be528
// 006be526  ffd3                 call ebx
// 006be528  85f6                 test esi, esi
// 006be52a  7510                 jne 0x6be53c
// 006be52c  ffd3                 call ebx
// 006be52e  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 006be531  7502                 jne 0x6be535
// 006be533  ffd3                 call ebx
// 006be535  8d4708               lea eax, [edi + 8]
// 006be538  5f                   pop edi
// 006be539  5e                   pop esi
// 006be53a  5b                   pop ebx
// 006be53b  c3                   ret 
// 006be53c  8b36                 mov esi, dword ptr [esi]
// 006be53e  ebee                 jmp 0x6be52e
// standard library list<ptr> (function ?back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
