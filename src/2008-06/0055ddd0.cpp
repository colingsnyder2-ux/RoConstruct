// from server: 100% by auto
// roc 2008-06 0055ddd0  unit: RBX::VInstance::?$NonFactoryProduct  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055ddd0
//
// 0055ddd0  53                   push ebx
// 0055ddd1  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0055ddd7  56                   push esi
// 0055ddd8  8b31                 mov esi, dword ptr [ecx]
// 0055ddda  57                   push edi
// 0055dddb  8b7914               mov edi, dword ptr [ecx + 0x14]
// 0055ddde  85f6                 test esi, esi
// 0055dde0  7502                 jne 0x55dde4
// 0055dde2  ffd3                 call ebx
// 0055dde4  8b7f04               mov edi, dword ptr [edi + 4]
// 0055dde7  85f6                 test esi, esi
// 0055dde9  7404                 je 0x55ddef
// 0055ddeb  8b06                 mov eax, dword ptr [esi]
// 0055dded  eb02                 jmp 0x55ddf1
// 0055ddef  33c0                 xor eax, eax
// 0055ddf1  3b7814               cmp edi, dword ptr [eax + 0x14]
// 0055ddf4  7502                 jne 0x55ddf8
// 0055ddf6  ffd3                 call ebx
// 0055ddf8  85f6                 test esi, esi
// 0055ddfa  7510                 jne 0x55de0c
// 0055ddfc  ffd3                 call ebx
// 0055ddfe  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 0055de01  7502                 jne 0x55de05
// 0055de03  ffd3                 call ebx
// 0055de05  8d4708               lea eax, [edi + 8]
// 0055de08  5f                   pop edi
// 0055de09  5e                   pop esi
// 0055de0a  5b                   pop ebx
// 0055de0b  c3                   ret 
// 0055de0c  8b36                 mov esi, dword ptr [esi]
// 0055de0e  ebee                 jmp 0x55ddfe
// standard library list<ptr> (function ?back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
