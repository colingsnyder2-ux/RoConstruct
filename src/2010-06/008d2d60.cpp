// from server: 100% by auto
// roc 2010-06 008d2d60  unit: Ogre::VisualEngine  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d2d60
//
// 008d2d60  53                   push ebx
// 008d2d61  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 008d2d67  56                   push esi
// 008d2d68  8b31                 mov esi, dword ptr [ecx]
// 008d2d6a  57                   push edi
// 008d2d6b  8b7914               mov edi, dword ptr [ecx + 0x14]
// 008d2d6e  85f6                 test esi, esi
// 008d2d70  7502                 jne 0x8d2d74
// 008d2d72  ffd3                 call ebx
// 008d2d74  8b7f04               mov edi, dword ptr [edi + 4]
// 008d2d77  85f6                 test esi, esi
// 008d2d79  7404                 je 0x8d2d7f
// 008d2d7b  8b06                 mov eax, dword ptr [esi]
// 008d2d7d  eb02                 jmp 0x8d2d81
// 008d2d7f  33c0                 xor eax, eax
// 008d2d81  3b7814               cmp edi, dword ptr [eax + 0x14]
// 008d2d84  7502                 jne 0x8d2d88
// 008d2d86  ffd3                 call ebx
// 008d2d88  85f6                 test esi, esi
// 008d2d8a  7510                 jne 0x8d2d9c
// 008d2d8c  ffd3                 call ebx
// 008d2d8e  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 008d2d91  7502                 jne 0x8d2d95
// 008d2d93  ffd3                 call ebx
// 008d2d95  8d4708               lea eax, [edi + 8]
// 008d2d98  5f                   pop edi
// 008d2d99  5e                   pop esi
// 008d2d9a  5b                   pop ebx
// 008d2d9b  c3                   ret 
// 008d2d9c  8b36                 mov esi, dword ptr [esi]
// 008d2d9e  ebee                 jmp 0x8d2d8e
// standard library list<ptr> (function ?back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
