// from server: 100% by auto
// roc 2010-06 005330d0  unit: RBX::PART::VWedge::?$FactoryProduct::Creator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005330d0
//
// 005330d0  6aff                 push -1
// 005330d2  68b8d19b00           push 0x9bd1b8
// 005330d7  64a100000000         mov eax, dword ptr fs:[0]
// 005330dd  50                   push eax
// 005330de  64892500000000       mov dword ptr fs:[0], esp
// 005330e5  83ec0c               sub esp, 0xc
// 005330e8  56                   push esi
// 005330e9  8bf1                 mov esi, ecx
// 005330eb  89742404             mov dword ptr [esp + 4], esi
// 005330ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 005330f2  8b0e                 mov ecx, dword ptr [esi]
// 005330f4  8b10                 mov edx, dword ptr [eax]
// 005330f6  50                   push eax
// 005330f7  51                   push ecx
// 005330f8  52                   push edx
// 005330f9  51                   push ecx
// 005330fa  8d442418             lea eax, [esp + 0x18]
// 005330fe  50                   push eax
// 005330ff  8bce                 mov ecx, esi
// 00533101  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00533109  e882ebffff           call 0x531c90
// 0053310e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00533111  51                   push ecx
// 00533112  e883482700           call 0x7a799a
// 00533117  8b16                 mov edx, dword ptr [esi]
// 00533119  52                   push edx
// 0053311a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00533121  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00533128  e86d482700           call 0x7a799a
// 0053312d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00533131  83c408               add esp, 8
// 00533134  5e                   pop esi
// 00533135  64890d00000000       mov dword ptr fs:[0], ecx
// 0053313c  83c418               add esp, 0x18
// 0053313f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
