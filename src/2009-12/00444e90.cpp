// from server: 100% by auto
// roc 2009-12 00444e90  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00444e90
//
// 00444e90  56                   push esi
// 00444e91  6a04                 push 4
// 00444e93  8bf1                 mov esi, ecx
// 00444e95  e8c6e93a00           call 0x7f3860
// 00444e9a  83c404               add esp, 4
// 00444e9d  85c0                 test eax, eax
// 00444e9f  740a                 je 0x444eab
// 00444ea1  8930                 mov dword ptr [eax], esi
// 00444ea3  8906                 mov dword ptr [esi], eax
// 00444ea5  8bc6                 mov eax, esi
// 00444ea7  5e                   pop esi
// 00444ea8  c20400               ret 4
// 00444eab  33c0                 xor eax, eax
// 00444ead  8906                 mov dword ptr [esi], eax
// 00444eaf  8bc6                 mov eax, esi
// 00444eb1  5e                   pop esi
// 00444eb2  c20400               ret 4
// standard library vector<ptr> (function ??0?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@V?$allocator@PAUT@@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
