// from server: 100% by auto
// roc 2008-06 004d8ae0  unit: RBX::ViewBase  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d8ae0
//
// 004d8ae0  6aff                 push -1
// 004d8ae2  6828d97b00           push 0x7bd928
// 004d8ae7  64a100000000         mov eax, dword ptr fs:[0]
// 004d8aed  50                   push eax
// 004d8aee  64892500000000       mov dword ptr fs:[0], esp
// 004d8af5  83ec0c               sub esp, 0xc
// 004d8af8  56                   push esi
// 004d8af9  8bf1                 mov esi, ecx
// 004d8afb  89742404             mov dword ptr [esp + 4], esi
// 004d8aff  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d8b02  8b0e                 mov ecx, dword ptr [esi]
// 004d8b04  8b10                 mov edx, dword ptr [eax]
// 004d8b06  50                   push eax
// 004d8b07  51                   push ecx
// 004d8b08  52                   push edx
// 004d8b09  51                   push ecx
// 004d8b0a  8d442418             lea eax, [esp + 0x18]
// 004d8b0e  50                   push eax
// 004d8b0f  8bce                 mov ecx, esi
// 004d8b11  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004d8b19  e822fdffff           call 0x4d8840
// 004d8b1e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004d8b21  51                   push ecx
// 004d8b22  e8537b1c00           call 0x6a067a
// 004d8b27  8b16                 mov edx, dword ptr [esi]
// 004d8b29  52                   push edx
// 004d8b2a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004d8b31  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004d8b38  e83d7b1c00           call 0x6a067a
// 004d8b3d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004d8b41  83c408               add esp, 8
// 004d8b44  5e                   pop esi
// 004d8b45  64890d00000000       mov dword ptr fs:[0], ecx
// 004d8b4c  83c418               add esp, 0x18
// 004d8b4f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
