// from server: 100% by auto
// roc 2010-06 005eb550  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005eb550
//
// 005eb550  6aff                 push -1
// 005eb552  68b8d19b00           push 0x9bd1b8
// 005eb557  64a100000000         mov eax, dword ptr fs:[0]
// 005eb55d  50                   push eax
// 005eb55e  64892500000000       mov dword ptr fs:[0], esp
// 005eb565  83ec0c               sub esp, 0xc
// 005eb568  56                   push esi
// 005eb569  8bf1                 mov esi, ecx
// 005eb56b  89742404             mov dword ptr [esp + 4], esi
// 005eb56f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005eb572  8b0e                 mov ecx, dword ptr [esi]
// 005eb574  8b10                 mov edx, dword ptr [eax]
// 005eb576  50                   push eax
// 005eb577  51                   push ecx
// 005eb578  52                   push edx
// 005eb579  51                   push ecx
// 005eb57a  8d442418             lea eax, [esp + 0x18]
// 005eb57e  50                   push eax
// 005eb57f  8bce                 mov ecx, esi
// 005eb581  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005eb589  e8b2fcffff           call 0x5eb240
// 005eb58e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005eb591  51                   push ecx
// 005eb592  e803c41b00           call 0x7a799a
// 005eb597  8b16                 mov edx, dword ptr [esi]
// 005eb599  52                   push edx
// 005eb59a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005eb5a1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005eb5a8  e8edc31b00           call 0x7a799a
// 005eb5ad  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005eb5b1  83c408               add esp, 8
// 005eb5b4  5e                   pop esi
// 005eb5b5  64890d00000000       mov dword ptr fs:[0], ecx
// 005eb5bc  83c418               add esp, 0x18
// 005eb5bf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
