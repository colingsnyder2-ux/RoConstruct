// from server: 100% by auto
// roc 2010-06 0041f3e0  unit: CSelectionTreeCtrl  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041f3e0
//
// 0041f3e0  6aff                 push -1
// 0041f3e2  68b8d19b00           push 0x9bd1b8
// 0041f3e7  64a100000000         mov eax, dword ptr fs:[0]
// 0041f3ed  50                   push eax
// 0041f3ee  64892500000000       mov dword ptr fs:[0], esp
// 0041f3f5  83ec0c               sub esp, 0xc
// 0041f3f8  56                   push esi
// 0041f3f9  8bf1                 mov esi, ecx
// 0041f3fb  89742404             mov dword ptr [esp + 4], esi
// 0041f3ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041f402  8b0e                 mov ecx, dword ptr [esi]
// 0041f404  8b10                 mov edx, dword ptr [eax]
// 0041f406  50                   push eax
// 0041f407  51                   push ecx
// 0041f408  52                   push edx
// 0041f409  51                   push ecx
// 0041f40a  8d442418             lea eax, [esp + 0x18]
// 0041f40e  50                   push eax
// 0041f40f  8bce                 mov ecx, esi
// 0041f411  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0041f419  e862feffff           call 0x41f280
// 0041f41e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0041f421  51                   push ecx
// 0041f422  e873853800           call 0x7a799a
// 0041f427  8b16                 mov edx, dword ptr [esi]
// 0041f429  52                   push edx
// 0041f42a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0041f431  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0041f438  e85d853800           call 0x7a799a
// 0041f43d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041f441  83c408               add esp, 8
// 0041f444  5e                   pop esi
// 0041f445  64890d00000000       mov dword ptr fs:[0], ecx
// 0041f44c  83c418               add esp, 0x18
// 0041f44f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
