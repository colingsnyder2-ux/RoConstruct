// from server: 100% by auto
// roc 2008-06 00553d80  unit: RBX::RenderBase::AggregateChunk  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00553d80
//
// 00553d80  6aff                 push -1
// 00553d82  6828d97b00           push 0x7bd928
// 00553d87  64a100000000         mov eax, dword ptr fs:[0]
// 00553d8d  50                   push eax
// 00553d8e  64892500000000       mov dword ptr fs:[0], esp
// 00553d95  83ec0c               sub esp, 0xc
// 00553d98  56                   push esi
// 00553d99  8bf1                 mov esi, ecx
// 00553d9b  89742404             mov dword ptr [esp + 4], esi
// 00553d9f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00553da2  8b0e                 mov ecx, dword ptr [esi]
// 00553da4  8b10                 mov edx, dword ptr [eax]
// 00553da6  50                   push eax
// 00553da7  51                   push ecx
// 00553da8  52                   push edx
// 00553da9  51                   push ecx
// 00553daa  8d442418             lea eax, [esp + 0x18]
// 00553dae  50                   push eax
// 00553daf  8bce                 mov ecx, esi
// 00553db1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00553db9  e8e2feffff           call 0x553ca0
// 00553dbe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00553dc1  51                   push ecx
// 00553dc2  e8b3c81400           call 0x6a067a
// 00553dc7  8b16                 mov edx, dword ptr [esi]
// 00553dc9  52                   push edx
// 00553dca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00553dd1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00553dd8  e89dc81400           call 0x6a067a
// 00553ddd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00553de1  83c408               add esp, 8
// 00553de4  5e                   pop esi
// 00553de5  64890d00000000       mov dword ptr fs:[0], ecx
// 00553dec  83c418               add esp, 0x18
// 00553def  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
