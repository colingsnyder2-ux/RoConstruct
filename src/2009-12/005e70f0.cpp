// from server: 100% by auto
// roc 2009-12 005e70f0  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005e70f0
//
// 005e70f0  6aff                 push -1
// 005e70f2  68888f9400           push 0x948f88
// 005e70f7  64a100000000         mov eax, dword ptr fs:[0]
// 005e70fd  50                   push eax
// 005e70fe  64892500000000       mov dword ptr fs:[0], esp
// 005e7105  83ec0c               sub esp, 0xc
// 005e7108  56                   push esi
// 005e7109  8bf1                 mov esi, ecx
// 005e710b  89742404             mov dword ptr [esp + 4], esi
// 005e710f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005e7112  8b0e                 mov ecx, dword ptr [esi]
// 005e7114  8b10                 mov edx, dword ptr [eax]
// 005e7116  50                   push eax
// 005e7117  51                   push ecx
// 005e7118  52                   push edx
// 005e7119  51                   push ecx
// 005e711a  8d442418             lea eax, [esp + 0x18]
// 005e711e  50                   push eax
// 005e711f  8bce                 mov ecx, esi
// 005e7121  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005e7129  e802fdffff           call 0x5e6e30
// 005e712e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005e7131  51                   push ecx
// 005e7132  e823c72000           call 0x7f385a
// 005e7137  8b16                 mov edx, dword ptr [esi]
// 005e7139  52                   push edx
// 005e713a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005e7141  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005e7148  e80dc72000           call 0x7f385a
// 005e714d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005e7151  83c408               add esp, 8
// 005e7154  5e                   pop esi
// 005e7155  64890d00000000       mov dword ptr fs:[0], ecx
// 005e715c  83c418               add esp, 0x18
// 005e715f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
