// from server: 100% by auto
// roc 2010-06 0053f030  unit: RBX::Mesh  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053f030
//
// 0053f030  6aff                 push -1
// 0053f032  68b8d19b00           push 0x9bd1b8
// 0053f037  64a100000000         mov eax, dword ptr fs:[0]
// 0053f03d  50                   push eax
// 0053f03e  64892500000000       mov dword ptr fs:[0], esp
// 0053f045  83ec0c               sub esp, 0xc
// 0053f048  56                   push esi
// 0053f049  8bf1                 mov esi, ecx
// 0053f04b  89742404             mov dword ptr [esp + 4], esi
// 0053f04f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053f052  8b0e                 mov ecx, dword ptr [esi]
// 0053f054  8b10                 mov edx, dword ptr [eax]
// 0053f056  50                   push eax
// 0053f057  51                   push ecx
// 0053f058  52                   push edx
// 0053f059  51                   push ecx
// 0053f05a  8d442418             lea eax, [esp + 0x18]
// 0053f05e  50                   push eax
// 0053f05f  8bce                 mov ecx, esi
// 0053f061  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0053f069  e802fdffff           call 0x53ed70
// 0053f06e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0053f071  51                   push ecx
// 0053f072  e823892600           call 0x7a799a
// 0053f077  8b16                 mov edx, dword ptr [esi]
// 0053f079  52                   push edx
// 0053f07a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0053f081  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0053f088  e80d892600           call 0x7a799a
// 0053f08d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0053f091  83c408               add esp, 8
// 0053f094  5e                   pop esi
// 0053f095  64890d00000000       mov dword ptr fs:[0], ecx
// 0053f09c  83c418               add esp, 0x18
// 0053f09f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
