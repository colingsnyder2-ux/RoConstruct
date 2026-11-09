// from server: 100% by auto
// roc 2008-06 00594ae0  unit: RBX::Lua::ThreadRef::VNode::?$sp_counted_impl_p  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00594ae0
//
// 00594ae0  6aff                 push -1
// 00594ae2  68e8727d00           push 0x7d72e8
// 00594ae7  64a100000000         mov eax, dword ptr fs:[0]
// 00594aed  50                   push eax
// 00594aee  64892500000000       mov dword ptr fs:[0], esp
// 00594af5  51                   push ecx
// 00594af6  56                   push esi
// 00594af7  8bf1                 mov esi, ecx
// 00594af9  6a04                 push 4
// 00594afb  89742408             mov dword ptr [esp + 8], esi
// 00594aff  e81cbe1000           call 0x6a0920
// 00594b04  83c404               add esp, 4
// 00594b07  85c0                 test eax, eax
// 00594b09  7404                 je 0x594b0f
// 00594b0b  8930                 mov dword ptr [eax], esi
// 00594b0d  eb02                 jmp 0x594b11
// 00594b0f  33c0                 xor eax, eax
// 00594b11  8906                 mov dword ptr [esi], eax
// 00594b13  8bce                 mov ecx, esi
// 00594b15  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00594b1d  e8de5ce8ff           call 0x41a800
// 00594b22  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00594b26  894614               mov dword ptr [esi + 0x14], eax
// 00594b29  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00594b30  8bc6                 mov eax, esi
// 00594b32  5e                   pop esi
// 00594b33  64890d00000000       mov dword ptr fs:[0], ecx
// 00594b3a  83c410               add esp, 0x10
// 00594b3d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
