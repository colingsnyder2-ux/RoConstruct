// from server: 100% by auto
// roc 2010-06 00611860  unit: RBX::VScriptContext::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00611860
//
// 00611860  6aff                 push -1
// 00611862  68b8d19b00           push 0x9bd1b8
// 00611867  64a100000000         mov eax, dword ptr fs:[0]
// 0061186d  50                   push eax
// 0061186e  64892500000000       mov dword ptr fs:[0], esp
// 00611875  83ec0c               sub esp, 0xc
// 00611878  56                   push esi
// 00611879  8bf1                 mov esi, ecx
// 0061187b  89742404             mov dword ptr [esp + 4], esi
// 0061187f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00611882  8b0e                 mov ecx, dword ptr [esi]
// 00611884  8b10                 mov edx, dword ptr [eax]
// 00611886  50                   push eax
// 00611887  51                   push ecx
// 00611888  52                   push edx
// 00611889  51                   push ecx
// 0061188a  8d442418             lea eax, [esp + 0x18]
// 0061188e  50                   push eax
// 0061188f  8bce                 mov ecx, esi
// 00611891  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00611899  e832feffff           call 0x6116d0
// 0061189e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006118a1  51                   push ecx
// 006118a2  e8f3601900           call 0x7a799a
// 006118a7  8b16                 mov edx, dword ptr [esi]
// 006118a9  52                   push edx
// 006118aa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006118b1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006118b8  e8dd601900           call 0x7a799a
// 006118bd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006118c1  83c408               add esp, 8
// 006118c4  5e                   pop esi
// 006118c5  64890d00000000       mov dword ptr fs:[0], ecx
// 006118cc  83c418               add esp, 0x18
// 006118cf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
