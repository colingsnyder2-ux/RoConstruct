// from server: 100% by auto
// roc 2008-06 004247c0  unit: CSelectionTreeCtrl  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004247c0
//
// 004247c0  6aff                 push -1
// 004247c2  6828d97b00           push 0x7bd928
// 004247c7  64a100000000         mov eax, dword ptr fs:[0]
// 004247cd  50                   push eax
// 004247ce  64892500000000       mov dword ptr fs:[0], esp
// 004247d5  83ec0c               sub esp, 0xc
// 004247d8  56                   push esi
// 004247d9  8bf1                 mov esi, ecx
// 004247db  89742404             mov dword ptr [esp + 4], esi
// 004247df  8b4618               mov eax, dword ptr [esi + 0x18]
// 004247e2  8b0e                 mov ecx, dword ptr [esi]
// 004247e4  8b10                 mov edx, dword ptr [eax]
// 004247e6  50                   push eax
// 004247e7  51                   push ecx
// 004247e8  52                   push edx
// 004247e9  51                   push ecx
// 004247ea  8d442418             lea eax, [esp + 0x18]
// 004247ee  50                   push eax
// 004247ef  8bce                 mov ecx, esi
// 004247f1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004247f9  e832fcffff           call 0x424430
// 004247fe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00424801  51                   push ecx
// 00424802  e873be2700           call 0x6a067a
// 00424807  8b16                 mov edx, dword ptr [esi]
// 00424809  52                   push edx
// 0042480a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00424811  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00424818  e85dbe2700           call 0x6a067a
// 0042481d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00424821  83c408               add esp, 8
// 00424824  5e                   pop esi
// 00424825  64890d00000000       mov dword ptr fs:[0], ecx
// 0042482c  83c418               add esp, 0x18
// 0042482f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
