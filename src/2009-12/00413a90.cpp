// from server: 100% by auto
// roc 2009-12 00413a90  unit: CopyVerb  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00413a90
//
// 00413a90  56                   push esi
// 00413a91  8bf1                 mov esi, ecx
// 00413a93  8b06                 mov eax, dword ptr [esi]
// 00413a95  57                   push edi
// 00413a96  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 00413a9c  85c0                 test eax, eax
// 00413a9e  7508                 jne 0x413aa8
// 00413aa0  ffd7                 call edi
// 00413aa2  8b06                 mov eax, dword ptr [esi]
// 00413aa4  85c0                 test eax, eax
// 00413aa6  7404                 je 0x413aac
// 00413aa8  8b00                 mov eax, dword ptr [eax]
// 00413aaa  eb02                 jmp 0x413aae
// 00413aac  33c0                 xor eax, eax
// 00413aae  8b4e04               mov ecx, dword ptr [esi + 4]
// 00413ab1  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 00413ab4  7208                 jb 0x413abe
// 00413ab6  ffd7                 call edi
// 00413ab8  8b4604               mov eax, dword ptr [esi + 4]
// 00413abb  5f                   pop edi
// 00413abc  5e                   pop esi
// 00413abd  c3                   ret 
// 00413abe  5f                   pop edi
// 00413abf  8bc1                 mov eax, ecx
// 00413ac1  5e                   pop esi
// 00413ac2  c3                   ret 
// standard library vector<ptr> (function ??D?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
