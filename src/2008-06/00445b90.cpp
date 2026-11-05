// from server: 100% by auto
// roc 2008-06 00445b90  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00445b90
//
// 00445b90  56                   push esi
// 00445b91  6a04                 push 4
// 00445b93  8bf1                 mov esi, ecx
// 00445b95  e886ad2500           call 0x6a0920
// 00445b9a  83c404               add esp, 4
// 00445b9d  85c0                 test eax, eax
// 00445b9f  740a                 je 0x445bab
// 00445ba1  8930                 mov dword ptr [eax], esi
// 00445ba3  8906                 mov dword ptr [esi], eax
// 00445ba5  8bc6                 mov eax, esi
// 00445ba7  5e                   pop esi
// 00445ba8  c20400               ret 4
// 00445bab  33c0                 xor eax, eax
// 00445bad  8906                 mov dword ptr [esi], eax
// 00445baf  8bc6                 mov eax, esi
// 00445bb1  5e                   pop esi
// 00445bb2  c20400               ret 4
// standard library vector<ptr> (function ??0?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@V?$allocator@PAUT@@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
