// from server: 100% by auto
// roc 2010-06 00413bd0  unit: CopyVerb  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413bd0
//
// 00413bd0  56                   push esi
// 00413bd1  8bf1                 mov esi, ecx
// 00413bd3  8b06                 mov eax, dword ptr [esi]
// 00413bd5  57                   push edi
// 00413bd6  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 00413bdc  85c0                 test eax, eax
// 00413bde  7508                 jne 0x413be8
// 00413be0  ffd7                 call edi
// 00413be2  8b06                 mov eax, dword ptr [esi]
// 00413be4  85c0                 test eax, eax
// 00413be6  7404                 je 0x413bec
// 00413be8  8b00                 mov eax, dword ptr [eax]
// 00413bea  eb02                 jmp 0x413bee
// 00413bec  33c0                 xor eax, eax
// 00413bee  8b4e04               mov ecx, dword ptr [esi + 4]
// 00413bf1  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 00413bf4  7208                 jb 0x413bfe
// 00413bf6  ffd7                 call edi
// 00413bf8  8b4604               mov eax, dword ptr [esi + 4]
// 00413bfb  5f                   pop edi
// 00413bfc  5e                   pop esi
// 00413bfd  c3                   ret 
// 00413bfe  5f                   pop edi
// 00413bff  8bc1                 mov eax, ecx
// 00413c01  5e                   pop esi
// 00413c02  c3                   ret 
// standard library vector<ptr> (function ??D?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
