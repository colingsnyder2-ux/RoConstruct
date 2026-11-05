// from server: 100% by auto
// roc 2007-08 0040f430  unit: CutVerb  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040f430
//
// 0040f430  56                   push esi
// 0040f431  8bf1                 mov esi, ecx
// 0040f433  833e00               cmp dword ptr [esi], 0
// 0040f436  57                   push edi
// 0040f437  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 0040f43d  7502                 jne 0x40f441
// 0040f43f  ffd7                 call edi
// 0040f441  8b06                 mov eax, dword ptr [esi]
// 0040f443  8b4e04               mov ecx, dword ptr [esi + 4]
// 0040f446  3b4808               cmp ecx, dword ptr [eax + 8]
// 0040f449  7208                 jb 0x40f453
// 0040f44b  ffd7                 call edi
// 0040f44d  8b4604               mov eax, dword ptr [esi + 4]
// 0040f450  5f                   pop edi
// 0040f451  5e                   pop esi
// 0040f452  c3                   ret 
// 0040f453  5f                   pop edi
// 0040f454  8bc1                 mov eax, ecx
// 0040f456  5e                   pop esi
// 0040f457  c3                   ret 
// standard library vector<ptr> (function ??D?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
