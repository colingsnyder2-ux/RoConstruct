// from server: 100% by auto
// roc 2010-06 0047d7c0  unit: VCContent::?$CComObject  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047d7c0
//
// 0047d7c0  6aff                 push -1
// 0047d7c2  68b8d19b00           push 0x9bd1b8
// 0047d7c7  64a100000000         mov eax, dword ptr fs:[0]
// 0047d7cd  50                   push eax
// 0047d7ce  64892500000000       mov dword ptr fs:[0], esp
// 0047d7d5  83ec0c               sub esp, 0xc
// 0047d7d8  56                   push esi
// 0047d7d9  8bf1                 mov esi, ecx
// 0047d7db  89742404             mov dword ptr [esp + 4], esi
// 0047d7df  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047d7e2  8b0e                 mov ecx, dword ptr [esi]
// 0047d7e4  8b10                 mov edx, dword ptr [eax]
// 0047d7e6  50                   push eax
// 0047d7e7  51                   push ecx
// 0047d7e8  52                   push edx
// 0047d7e9  51                   push ecx
// 0047d7ea  8d442418             lea eax, [esp + 0x18]
// 0047d7ee  50                   push eax
// 0047d7ef  8bce                 mov ecx, esi
// 0047d7f1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0047d7f9  e8e2feffff           call 0x47d6e0
// 0047d7fe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0047d801  51                   push ecx
// 0047d802  e893a13200           call 0x7a799a
// 0047d807  8b16                 mov edx, dword ptr [esi]
// 0047d809  52                   push edx
// 0047d80a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0047d811  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0047d818  e87da13200           call 0x7a799a
// 0047d81d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0047d821  83c408               add esp, 8
// 0047d824  5e                   pop esi
// 0047d825  64890d00000000       mov dword ptr fs:[0], ecx
// 0047d82c  83c418               add esp, 0x18
// 0047d82f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
