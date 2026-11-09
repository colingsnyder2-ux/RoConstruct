// from server: 100% by auto
// roc 2009-06 006c1e10  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c1e10
//
// 006c1e10  83ec08               sub esp, 8
// 006c1e13  8b542414             mov edx, dword ptr [esp + 0x14]
// 006c1e17  53                   push ebx
// 006c1e18  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006c1e1c  56                   push esi
// 006c1e1d  8b742418             mov esi, dword ptr [esp + 0x18]
// 006c1e21  57                   push edi
// 006c1e22  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006c1e26  32c0                 xor al, al
// 006c1e28  88442410             mov byte ptr [esp + 0x10], al
// 006c1e2c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006c1e30  8844240c             mov byte ptr [esp + 0xc], al
// 006c1e34  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006c1e38  50                   push eax
// 006c1e39  51                   push ecx
// 006c1e3a  52                   push edx
// 006c1e3b  57                   push edi
// 006c1e3c  56                   push esi
// 006c1e3d  53                   push ebx
// 006c1e3e  e8bdfeffff           call 0x6c1d00
// 006c1e43  2bf3                 sub esi, ebx
// 006c1e45  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006c1e4a  f7ee                 imul esi
// 006c1e4c  c1fa02               sar edx, 2
// 006c1e4f  8bc2                 mov eax, edx
// 006c1e51  c1e81f               shr eax, 0x1f
// 006c1e54  03c2                 add eax, edx
// 006c1e56  8d0440               lea eax, [eax + eax*2]
// 006c1e59  03c0                 add eax, eax
// 006c1e5b  03c0                 add eax, eax
// 006c1e5d  03c0                 add eax, eax
// 006c1e5f  83c418               add esp, 0x18
// 006c1e62  8bc8                 mov ecx, eax
// 006c1e64  8bc7                 mov eax, edi
// 006c1e66  5f                   pop edi
// 006c1e67  5e                   pop esi
// 006c1e68  2bc1                 sub eax, ecx
// 006c1e6a  5b                   pop ebx
// 006c1e6b  83c408               add esp, 8
// 006c1e6e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
