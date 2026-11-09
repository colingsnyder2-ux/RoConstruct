// from server: 100% by auto
// roc 2009-12 006bd9a0  unit: CPropGrid::UpdateItemsJob  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bd9a0
//
// 006bd9a0  56                   push esi
// 006bd9a1  8bf1                 mov esi, ecx
// 006bd9a3  8b06                 mov eax, dword ptr [esi]
// 006bd9a5  57                   push edi
// 006bd9a6  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 006bd9ac  85c0                 test eax, eax
// 006bd9ae  7508                 jne 0x6bd9b8
// 006bd9b0  ffd7                 call edi
// 006bd9b2  8b06                 mov eax, dword ptr [esi]
// 006bd9b4  85c0                 test eax, eax
// 006bd9b6  7404                 je 0x6bd9bc
// 006bd9b8  8b00                 mov eax, dword ptr [eax]
// 006bd9ba  eb02                 jmp 0x6bd9be
// 006bd9bc  33c0                 xor eax, eax
// 006bd9be  8b4e04               mov ecx, dword ptr [esi + 4]
// 006bd9c1  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 006bd9c4  7502                 jne 0x6bd9c8
// 006bd9c6  ffd7                 call edi
// 006bd9c8  8b4604               mov eax, dword ptr [esi + 4]
// 006bd9cb  5f                   pop edi
// 006bd9cc  83c008               add eax, 8
// 006bd9cf  5e                   pop esi
// 006bd9d0  c3                   ret 
// standard library list<ptr> (function ??D?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
