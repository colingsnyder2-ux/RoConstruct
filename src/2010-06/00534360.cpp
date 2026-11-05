// from server: 100% by auto
// roc 2010-06 00534360  unit: RBX::PART::VWedge::?$FactoryProduct::Creator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00534360
//
// 00534360  6aff                 push -1
// 00534362  68b8d19b00           push 0x9bd1b8
// 00534367  64a100000000         mov eax, dword ptr fs:[0]
// 0053436d  50                   push eax
// 0053436e  64892500000000       mov dword ptr fs:[0], esp
// 00534375  83ec0c               sub esp, 0xc
// 00534378  56                   push esi
// 00534379  8bf1                 mov esi, ecx
// 0053437b  89742404             mov dword ptr [esp + 4], esi
// 0053437f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00534382  8b0e                 mov ecx, dword ptr [esi]
// 00534384  8b10                 mov edx, dword ptr [eax]
// 00534386  50                   push eax
// 00534387  51                   push ecx
// 00534388  52                   push edx
// 00534389  51                   push ecx
// 0053438a  8d442418             lea eax, [esp + 0x18]
// 0053438e  50                   push eax
// 0053438f  8bce                 mov ecx, esi
// 00534391  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00534399  e8f2e1ffff           call 0x532590
// 0053439e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005343a1  51                   push ecx
// 005343a2  e8f3352700           call 0x7a799a
// 005343a7  8b16                 mov edx, dword ptr [esi]
// 005343a9  52                   push edx
// 005343aa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005343b1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005343b8  e8dd352700           call 0x7a799a
// 005343bd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005343c1  83c408               add esp, 8
// 005343c4  5e                   pop esi
// 005343c5  64890d00000000       mov dword ptr fs:[0], ecx
// 005343cc  83c418               add esp, 0x18
// 005343cf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
