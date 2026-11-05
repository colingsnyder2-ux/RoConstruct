// from server: 100% by auto
// roc 2009-06 00413f70  unit: CopyVerb  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413f70
//
// 00413f70  56                   push esi
// 00413f71  8bf1                 mov esi, ecx
// 00413f73  8b06                 mov eax, dword ptr [esi]
// 00413f75  57                   push edi
// 00413f76  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 00413f7c  85c0                 test eax, eax
// 00413f7e  7508                 jne 0x413f88
// 00413f80  ffd7                 call edi
// 00413f82  8b06                 mov eax, dword ptr [esi]
// 00413f84  85c0                 test eax, eax
// 00413f86  7404                 je 0x413f8c
// 00413f88  8b00                 mov eax, dword ptr [eax]
// 00413f8a  eb02                 jmp 0x413f8e
// 00413f8c  33c0                 xor eax, eax
// 00413f8e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00413f91  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 00413f94  7208                 jb 0x413f9e
// 00413f96  ffd7                 call edi
// 00413f98  8b4604               mov eax, dword ptr [esi + 4]
// 00413f9b  5f                   pop edi
// 00413f9c  5e                   pop esi
// 00413f9d  c3                   ret 
// 00413f9e  5f                   pop edi
// 00413f9f  8bc1                 mov eax, ecx
// 00413fa1  5e                   pop esi
// 00413fa2  c3                   ret 
// standard library vector<ptr> (function ??D?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
