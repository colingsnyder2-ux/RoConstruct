// from server: 100% by auto
// roc 2009-06 0051d6a0  unit: RBX::VBlockMesh::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0051d6a0
//
// 0051d6a0  6aff                 push -1
// 0051d6a2  68485e8500           push 0x855e48
// 0051d6a7  64a100000000         mov eax, dword ptr fs:[0]
// 0051d6ad  50                   push eax
// 0051d6ae  64892500000000       mov dword ptr fs:[0], esp
// 0051d6b5  83ec0c               sub esp, 0xc
// 0051d6b8  56                   push esi
// 0051d6b9  8bf1                 mov esi, ecx
// 0051d6bb  89742404             mov dword ptr [esp + 4], esi
// 0051d6bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051d6c2  8b0e                 mov ecx, dword ptr [esi]
// 0051d6c4  8b10                 mov edx, dword ptr [eax]
// 0051d6c6  50                   push eax
// 0051d6c7  51                   push ecx
// 0051d6c8  52                   push edx
// 0051d6c9  51                   push ecx
// 0051d6ca  8d442418             lea eax, [esp + 0x18]
// 0051d6ce  50                   push eax
// 0051d6cf  8bce                 mov ecx, esi
// 0051d6d1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0051d6d9  e872efffff           call 0x51c650
// 0051d6de  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0051d6e1  51                   push ecx
// 0051d6e2  e84bb31f00           call 0x718a32
// 0051d6e7  8b16                 mov edx, dword ptr [esi]
// 0051d6e9  52                   push edx
// 0051d6ea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0051d6f1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0051d6f8  e835b31f00           call 0x718a32
// 0051d6fd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0051d701  83c408               add esp, 8
// 0051d704  5e                   pop esi
// 0051d705  64890d00000000       mov dword ptr fs:[0], ecx
// 0051d70c  83c418               add esp, 0x18
// 0051d70f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
