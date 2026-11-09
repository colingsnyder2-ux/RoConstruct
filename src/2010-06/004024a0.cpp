// from server: 100% by auto
// roc 2010-06 004024a0  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004024a0
//
// 004024a0  6aff                 push -1
// 004024a2  68b8d19b00           push 0x9bd1b8
// 004024a7  64a100000000         mov eax, dword ptr fs:[0]
// 004024ad  50                   push eax
// 004024ae  64892500000000       mov dword ptr fs:[0], esp
// 004024b5  83ec0c               sub esp, 0xc
// 004024b8  56                   push esi
// 004024b9  8bf1                 mov esi, ecx
// 004024bb  89742404             mov dword ptr [esp + 4], esi
// 004024bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004024c2  8b0e                 mov ecx, dword ptr [esi]
// 004024c4  8b10                 mov edx, dword ptr [eax]
// 004024c6  50                   push eax
// 004024c7  51                   push ecx
// 004024c8  52                   push edx
// 004024c9  51                   push ecx
// 004024ca  8d442418             lea eax, [esp + 0x18]
// 004024ce  50                   push eax
// 004024cf  8bce                 mov ecx, esi
// 004024d1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004024d9  e852370300           call 0x435c30
// 004024de  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004024e1  51                   push ecx
// 004024e2  e8b3543a00           call 0x7a799a
// 004024e7  8b16                 mov edx, dword ptr [esi]
// 004024e9  52                   push edx
// 004024ea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004024f1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004024f8  e89d543a00           call 0x7a799a
// 004024fd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00402501  83c408               add esp, 8
// 00402504  5e                   pop esi
// 00402505  64890d00000000       mov dword ptr fs:[0], ecx
// 0040250c  83c418               add esp, 0x18
// 0040250f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
