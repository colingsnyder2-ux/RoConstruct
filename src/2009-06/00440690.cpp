// from server: 100% by auto
// roc 2009-06 00440690  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00440690
//
// 00440690  56                   push esi
// 00440691  6a04                 push 4
// 00440693  8bf1                 mov esi, ecx
// 00440695  e89e832d00           call 0x718a38
// 0044069a  83c404               add esp, 4
// 0044069d  85c0                 test eax, eax
// 0044069f  740a                 je 0x4406ab
// 004406a1  8930                 mov dword ptr [eax], esi
// 004406a3  8906                 mov dword ptr [esi], eax
// 004406a5  8bc6                 mov eax, esi
// 004406a7  5e                   pop esi
// 004406a8  c20400               ret 4
// 004406ab  33c0                 xor eax, eax
// 004406ad  8906                 mov dword ptr [esi], eax
// 004406af  8bc6                 mov eax, esi
// 004406b1  5e                   pop esi
// 004406b2  c20400               ret 4
// standard library vector<ptr> (function ??0?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@V?$allocator@PAUT@@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
