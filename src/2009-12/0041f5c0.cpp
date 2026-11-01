// from server: 100% by auto
// roc 2009-12 0041f5c0  unit: CSelectionTreeCtrl  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041f5c0
//
// 0041f5c0  6aff                 push -1
// 0041f5c2  68888f9400           push 0x948f88
// 0041f5c7  64a100000000         mov eax, dword ptr fs:[0]
// 0041f5cd  50                   push eax
// 0041f5ce  64892500000000       mov dword ptr fs:[0], esp
// 0041f5d5  83ec0c               sub esp, 0xc
// 0041f5d8  56                   push esi
// 0041f5d9  8bf1                 mov esi, ecx
// 0041f5db  89742404             mov dword ptr [esp + 4], esi
// 0041f5df  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f5e2  8b0e                 mov ecx, dword ptr [esi]
// 0041f5e4  8b10                 mov edx, dword ptr [eax]
// 0041f5e6  50                   push eax
// 0041f5e7  51                   push ecx
// 0041f5e8  52                   push edx
// 0041f5e9  51                   push ecx
// 0041f5ea  8d442418             lea eax, [esp + 0x18]
// 0041f5ee  50                   push eax
// 0041f5ef  8bce                 mov ecx, esi
// 0041f5f1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0041f5f9  e862feffff           call 0x41f460
// 0041f5fe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0041f601  51                   push ecx
// 0041f602  e853423d00           call 0x7f385a
// 0041f607  8b16                 mov edx, dword ptr [esi]
// 0041f609  52                   push edx
// 0041f60a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0041f611  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0041f618  e83d423d00           call 0x7f385a
// 0041f61d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041f621  83c408               add esp, 8
// 0041f624  5e                   pop esi
// 0041f625  64890d00000000       mov dword ptr fs:[0], ecx
// 0041f62c  83c418               add esp, 0x18
// 0041f62f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
