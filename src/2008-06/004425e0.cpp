// from server: 100% by auto
// roc 2008-06 004425e0  unit: CSelectionPropGrid  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004425e0
//
// 004425e0  6aff                 push -1
// 004425e2  6828d97b00           push 0x7bd928
// 004425e7  64a100000000         mov eax, dword ptr fs:[0]
// 004425ed  50                   push eax
// 004425ee  64892500000000       mov dword ptr fs:[0], esp
// 004425f5  83ec0c               sub esp, 0xc
// 004425f8  56                   push esi
// 004425f9  8bf1                 mov esi, ecx
// 004425fb  89742404             mov dword ptr [esp + 4], esi
// 004425ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 00442602  8b0e                 mov ecx, dword ptr [esi]
// 00442604  8b10                 mov edx, dword ptr [eax]
// 00442606  50                   push eax
// 00442607  51                   push ecx
// 00442608  52                   push edx
// 00442609  51                   push ecx
// 0044260a  8d442418             lea eax, [esp + 0x18]
// 0044260e  50                   push eax
// 0044260f  8bce                 mov ecx, esi
// 00442611  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00442619  e852fcffff           call 0x442270
// 0044261e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00442621  51                   push ecx
// 00442622  e853e02500           call 0x6a067a
// 00442627  8b16                 mov edx, dword ptr [esi]
// 00442629  52                   push edx
// 0044262a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00442631  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00442638  e83de02500           call 0x6a067a
// 0044263d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00442641  83c408               add esp, 8
// 00442644  5e                   pop esi
// 00442645  64890d00000000       mov dword ptr fs:[0], ecx
// 0044264c  83c418               add esp, 0x18
// 0044264f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
