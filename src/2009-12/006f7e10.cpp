// from server: 100% by auto
// roc 2009-12 006f7e10  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f7e10
//
// 006f7e10  6aff                 push -1
// 006f7e12  68888f9400           push 0x948f88
// 006f7e17  64a100000000         mov eax, dword ptr fs:[0]
// 006f7e1d  50                   push eax
// 006f7e1e  64892500000000       mov dword ptr fs:[0], esp
// 006f7e25  83ec0c               sub esp, 0xc
// 006f7e28  56                   push esi
// 006f7e29  8bf1                 mov esi, ecx
// 006f7e2b  89742404             mov dword ptr [esp + 4], esi
// 006f7e2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f7e32  8b0e                 mov ecx, dword ptr [esi]
// 006f7e34  8b10                 mov edx, dword ptr [eax]
// 006f7e36  50                   push eax
// 006f7e37  51                   push ecx
// 006f7e38  52                   push edx
// 006f7e39  51                   push ecx
// 006f7e3a  8d442418             lea eax, [esp + 0x18]
// 006f7e3e  50                   push eax
// 006f7e3f  8bce                 mov ecx, esi
// 006f7e41  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006f7e49  e8d2f6ffff           call 0x6f7520
// 006f7e4e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f7e51  51                   push ecx
// 006f7e52  e803ba0f00           call 0x7f385a
// 006f7e57  8b16                 mov edx, dword ptr [esi]
// 006f7e59  52                   push edx
// 006f7e5a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006f7e61  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006f7e68  e8edb90f00           call 0x7f385a
// 006f7e6d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006f7e71  83c408               add esp, 8
// 006f7e74  5e                   pop esi
// 006f7e75  64890d00000000       mov dword ptr fs:[0], ecx
// 006f7e7c  83c418               add esp, 0x18
// 006f7e7f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
