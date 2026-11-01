// from server: 100% by auto
// roc 2009-12 00662520  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00662520
//
// 00662520  6aff                 push -1
// 00662522  68888f9400           push 0x948f88
// 00662527  64a100000000         mov eax, dword ptr fs:[0]
// 0066252d  50                   push eax
// 0066252e  64892500000000       mov dword ptr fs:[0], esp
// 00662535  83ec0c               sub esp, 0xc
// 00662538  56                   push esi
// 00662539  8bf1                 mov esi, ecx
// 0066253b  89742404             mov dword ptr [esp + 4], esi
// 0066253f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00662542  8b0e                 mov ecx, dword ptr [esi]
// 00662544  8b10                 mov edx, dword ptr [eax]
// 00662546  50                   push eax
// 00662547  51                   push ecx
// 00662548  52                   push edx
// 00662549  51                   push ecx
// 0066254a  8d442418             lea eax, [esp + 0x18]
// 0066254e  50                   push eax
// 0066254f  8bce                 mov ecx, esi
// 00662551  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00662559  e812faffff           call 0x661f70
// 0066255e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00662561  51                   push ecx
// 00662562  e8f3121900           call 0x7f385a
// 00662567  8b16                 mov edx, dword ptr [esi]
// 00662569  52                   push edx
// 0066256a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00662571  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00662578  e8dd121900           call 0x7f385a
// 0066257d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00662581  83c408               add esp, 8
// 00662584  5e                   pop esi
// 00662585  64890d00000000       mov dword ptr fs:[0], ecx
// 0066258c  83c418               add esp, 0x18
// 0066258f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
