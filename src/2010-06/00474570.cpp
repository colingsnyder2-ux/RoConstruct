// from server: 100% by auto
// roc 2010-06 00474570  unit: CRobloxScriptReviewPaneView  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00474570
//
// 00474570  6aff                 push -1
// 00474572  68b8d19b00           push 0x9bd1b8
// 00474577  64a100000000         mov eax, dword ptr fs:[0]
// 0047457d  50                   push eax
// 0047457e  64892500000000       mov dword ptr fs:[0], esp
// 00474585  83ec0c               sub esp, 0xc
// 00474588  56                   push esi
// 00474589  8bf1                 mov esi, ecx
// 0047458b  89742404             mov dword ptr [esp + 4], esi
// 0047458f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00474592  8b0e                 mov ecx, dword ptr [esi]
// 00474594  8b10                 mov edx, dword ptr [eax]
// 00474596  50                   push eax
// 00474597  51                   push ecx
// 00474598  52                   push edx
// 00474599  51                   push ecx
// 0047459a  8d442418             lea eax, [esp + 0x18]
// 0047459e  50                   push eax
// 0047459f  8bce                 mov ecx, esi
// 004745a1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004745a9  e842fbffff           call 0x4740f0
// 004745ae  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004745b1  51                   push ecx
// 004745b2  e8e3333300           call 0x7a799a
// 004745b7  8b16                 mov edx, dword ptr [esi]
// 004745b9  52                   push edx
// 004745ba  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004745c1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004745c8  e8cd333300           call 0x7a799a
// 004745cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004745d1  83c408               add esp, 8
// 004745d4  5e                   pop esi
// 004745d5  64890d00000000       mov dword ptr fs:[0], ecx
// 004745dc  83c418               add esp, 0x18
// 004745df  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
