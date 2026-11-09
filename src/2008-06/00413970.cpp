// from server: 100% by auto
// roc 2008-06 00413970  unit: CopyVerb  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00413970
//
// 00413970  56                   push esi
// 00413971  8bf1                 mov esi, ecx
// 00413973  8b06                 mov eax, dword ptr [esi]
// 00413975  57                   push edi
// 00413976  8b3d90288000         mov edi, dword ptr [0x802890]
// 0041397c  85c0                 test eax, eax
// 0041397e  7508                 jne 0x413988
// 00413980  ffd7                 call edi
// 00413982  8b06                 mov eax, dword ptr [esi]
// 00413984  85c0                 test eax, eax
// 00413986  7404                 je 0x41398c
// 00413988  8b00                 mov eax, dword ptr [eax]
// 0041398a  eb02                 jmp 0x41398e
// 0041398c  33c0                 xor eax, eax
// 0041398e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00413991  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 00413994  7208                 jb 0x41399e
// 00413996  ffd7                 call edi
// 00413998  8b4604               mov eax, dword ptr [esi + 4]
// 0041399b  5f                   pop edi
// 0041399c  5e                   pop esi
// 0041399d  c3                   ret 
// 0041399e  5f                   pop edi
// 0041399f  8bc1                 mov eax, ecx
// 004139a1  5e                   pop esi
// 004139a2  c3                   ret 
// standard library vector<ptr> (function ??D?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
