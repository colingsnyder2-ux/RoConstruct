// from server: 100% by auto
// roc 2009-12 006f7310  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f7310
//
// 006f7310  6aff                 push -1
// 006f7312  68888f9400           push 0x948f88
// 006f7317  64a100000000         mov eax, dword ptr fs:[0]
// 006f731d  50                   push eax
// 006f731e  64892500000000       mov dword ptr fs:[0], esp
// 006f7325  83ec0c               sub esp, 0xc
// 006f7328  56                   push esi
// 006f7329  8bf1                 mov esi, ecx
// 006f732b  89742404             mov dword ptr [esp + 4], esi
// 006f732f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f7332  8b0e                 mov ecx, dword ptr [esi]
// 006f7334  8b10                 mov edx, dword ptr [eax]
// 006f7336  50                   push eax
// 006f7337  51                   push ecx
// 006f7338  52                   push edx
// 006f7339  51                   push ecx
// 006f733a  8d442418             lea eax, [esp + 0x18]
// 006f733e  50                   push eax
// 006f733f  8bce                 mov ecx, esi
// 006f7341  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006f7349  e8d2f9ffff           call 0x6f6d20
// 006f734e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f7351  51                   push ecx
// 006f7352  e803c50f00           call 0x7f385a
// 006f7357  8b16                 mov edx, dword ptr [esi]
// 006f7359  52                   push edx
// 006f735a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006f7361  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006f7368  e8edc40f00           call 0x7f385a
// 006f736d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006f7371  83c408               add esp, 8
// 006f7374  5e                   pop esi
// 006f7375  64890d00000000       mov dword ptr fs:[0], ecx
// 006f737c  83c418               add esp, 0x18
// 006f737f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
