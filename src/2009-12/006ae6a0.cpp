// from server: 100% by auto
// roc 2009-12 006ae6a0  unit: RBX::Accoutrement  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ae6a0
//
// 006ae6a0  6aff                 push -1
// 006ae6a2  68888f9400           push 0x948f88
// 006ae6a7  64a100000000         mov eax, dword ptr fs:[0]
// 006ae6ad  50                   push eax
// 006ae6ae  64892500000000       mov dword ptr fs:[0], esp
// 006ae6b5  83ec0c               sub esp, 0xc
// 006ae6b8  56                   push esi
// 006ae6b9  8bf1                 mov esi, ecx
// 006ae6bb  89742404             mov dword ptr [esp + 4], esi
// 006ae6bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ae6c2  8b0e                 mov ecx, dword ptr [esi]
// 006ae6c4  8b10                 mov edx, dword ptr [eax]
// 006ae6c6  50                   push eax
// 006ae6c7  51                   push ecx
// 006ae6c8  52                   push edx
// 006ae6c9  51                   push ecx
// 006ae6ca  8d442418             lea eax, [esp + 0x18]
// 006ae6ce  50                   push eax
// 006ae6cf  8bce                 mov ecx, esi
// 006ae6d1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006ae6d9  e832fbffff           call 0x6ae210
// 006ae6de  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006ae6e1  51                   push ecx
// 006ae6e2  e873511400           call 0x7f385a
// 006ae6e7  8b16                 mov edx, dword ptr [esi]
// 006ae6e9  52                   push edx
// 006ae6ea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006ae6f1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006ae6f8  e85d511400           call 0x7f385a
// 006ae6fd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006ae701  83c408               add esp, 8
// 006ae704  5e                   pop esi
// 006ae705  64890d00000000       mov dword ptr fs:[0], ecx
// 006ae70c  83c418               add esp, 0x18
// 006ae70f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
