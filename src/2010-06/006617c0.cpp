// from server: 100% by auto
// roc 2010-06 006617c0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006617c0
//
// 006617c0  6aff                 push -1
// 006617c2  68b8d19b00           push 0x9bd1b8
// 006617c7  64a100000000         mov eax, dword ptr fs:[0]
// 006617cd  50                   push eax
// 006617ce  64892500000000       mov dword ptr fs:[0], esp
// 006617d5  83ec0c               sub esp, 0xc
// 006617d8  56                   push esi
// 006617d9  8bf1                 mov esi, ecx
// 006617db  89742404             mov dword ptr [esp + 4], esi
// 006617df  8b4618               mov eax, dword ptr [esi + 0x18]
// 006617e2  8b0e                 mov ecx, dword ptr [esi]
// 006617e4  8b10                 mov edx, dword ptr [eax]
// 006617e6  50                   push eax
// 006617e7  51                   push ecx
// 006617e8  52                   push edx
// 006617e9  51                   push ecx
// 006617ea  8d442418             lea eax, [esp + 0x18]
// 006617ee  50                   push eax
// 006617ef  8bce                 mov ecx, esi
// 006617f1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006617f9  e8d2f9ffff           call 0x6611d0
// 006617fe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00661801  51                   push ecx
// 00661802  e893611400           call 0x7a799a
// 00661807  8b16                 mov edx, dword ptr [esi]
// 00661809  52                   push edx
// 0066180a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00661811  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00661818  e87d611400           call 0x7a799a
// 0066181d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00661821  83c408               add esp, 8
// 00661824  5e                   pop esi
// 00661825  64890d00000000       mov dword ptr fs:[0], ecx
// 0066182c  83c418               add esp, 0x18
// 0066182f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
