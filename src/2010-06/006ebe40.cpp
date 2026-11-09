// from server: 100% by auto
// roc 2010-06 006ebe40  unit: RBX::VBadgeService::?$BoundYieldFuncDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006ebe40
//
// 006ebe40  6aff                 push -1
// 006ebe42  68b8d19b00           push 0x9bd1b8
// 006ebe47  64a100000000         mov eax, dword ptr fs:[0]
// 006ebe4d  50                   push eax
// 006ebe4e  64892500000000       mov dword ptr fs:[0], esp
// 006ebe55  83ec0c               sub esp, 0xc
// 006ebe58  56                   push esi
// 006ebe59  8bf1                 mov esi, ecx
// 006ebe5b  89742404             mov dword ptr [esp + 4], esi
// 006ebe5f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ebe62  8b0e                 mov ecx, dword ptr [esi]
// 006ebe64  8b10                 mov edx, dword ptr [eax]
// 006ebe66  50                   push eax
// 006ebe67  51                   push ecx
// 006ebe68  52                   push edx
// 006ebe69  51                   push ecx
// 006ebe6a  8d442418             lea eax, [esp + 0x18]
// 006ebe6e  50                   push eax
// 006ebe6f  8bce                 mov ecx, esi
// 006ebe71  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006ebe79  e842fdffff           call 0x6ebbc0
// 006ebe7e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006ebe81  51                   push ecx
// 006ebe82  e813bb0b00           call 0x7a799a
// 006ebe87  8b16                 mov edx, dword ptr [esi]
// 006ebe89  52                   push edx
// 006ebe8a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006ebe91  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006ebe98  e8fdba0b00           call 0x7a799a
// 006ebe9d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006ebea1  83c408               add esp, 8
// 006ebea4  5e                   pop esi
// 006ebea5  64890d00000000       mov dword ptr fs:[0], ecx
// 006ebeac  83c418               add esp, 0x18
// 006ebeaf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
