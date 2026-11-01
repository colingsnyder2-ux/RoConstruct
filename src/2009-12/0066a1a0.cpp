// from server: 100% by auto
// roc 2009-12 0066a1a0  unit: RBX::VInstance::?$NonFactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0066a1a0
//
// 0066a1a0  6aff                 push -1
// 0066a1a2  6808459400           push 0x944508
// 0066a1a7  64a100000000         mov eax, dword ptr fs:[0]
// 0066a1ad  50                   push eax
// 0066a1ae  64892500000000       mov dword ptr fs:[0], esp
// 0066a1b5  83ec0c               sub esp, 0xc
// 0066a1b8  56                   push esi
// 0066a1b9  8bf1                 mov esi, ecx
// 0066a1bb  89742404             mov dword ptr [esp + 4], esi
// 0066a1bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066a1c2  8b0e                 mov ecx, dword ptr [esi]
// 0066a1c4  8b10                 mov edx, dword ptr [eax]
// 0066a1c6  50                   push eax
// 0066a1c7  51                   push ecx
// 0066a1c8  52                   push edx
// 0066a1c9  51                   push ecx
// 0066a1ca  8d442418             lea eax, [esp + 0x18]
// 0066a1ce  50                   push eax
// 0066a1cf  8bce                 mov ecx, esi
// 0066a1d1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0066a1d9  e8b21ce8ff           call 0x4ebe90
// 0066a1de  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0066a1e1  51                   push ecx
// 0066a1e2  e873961800           call 0x7f385a
// 0066a1e7  8b16                 mov edx, dword ptr [esi]
// 0066a1e9  52                   push edx
// 0066a1ea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0066a1f1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0066a1f8  e85d961800           call 0x7f385a
// 0066a1fd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0066a201  83c408               add esp, 8
// 0066a204  5e                   pop esi
// 0066a205  64890d00000000       mov dword ptr fs:[0], ecx
// 0066a20c  83c418               add esp, 0x18
// 0066a20f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
