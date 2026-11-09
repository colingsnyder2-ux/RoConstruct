// from server: 100% by auto
// roc 2008-06 006515a0  unit: RBX::ScoreHud  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006515a0
//
// 006515a0  83ec08               sub esp, 8
// 006515a3  56                   push esi
// 006515a4  8bf1                 mov esi, ecx
// 006515a6  8b4618               mov eax, dword ptr [esi + 0x18]
// 006515a9  8b0e                 mov ecx, dword ptr [esi]
// 006515ab  8b10                 mov edx, dword ptr [eax]
// 006515ad  50                   push eax
// 006515ae  51                   push ecx
// 006515af  52                   push edx
// 006515b0  51                   push ecx
// 006515b1  8d442414             lea eax, [esp + 0x14]
// 006515b5  50                   push eax
// 006515b6  8bce                 mov ecx, esi
// 006515b8  e8d399e1ff           call 0x46af90
// 006515bd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006515c0  51                   push ecx
// 006515c1  e8b4f00400           call 0x6a067a
// 006515c6  83c404               add esp, 4
// 006515c9  33c0                 xor eax, eax
// 006515cb  894618               mov dword ptr [esi + 0x18], eax
// 006515ce  89461c               mov dword ptr [esi + 0x1c], eax
// 006515d1  5e                   pop esi
// 006515d2  83c408               add esp, 8
// 006515d5  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
