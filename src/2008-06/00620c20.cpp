// from server: 100% by auto
// roc 2008-06 00620c20  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00620c20
//
// 00620c20  83ec08               sub esp, 8
// 00620c23  8b542414             mov edx, dword ptr [esp + 0x14]
// 00620c27  53                   push ebx
// 00620c28  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00620c2c  56                   push esi
// 00620c2d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00620c31  57                   push edi
// 00620c32  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00620c36  32c0                 xor al, al
// 00620c38  88442410             mov byte ptr [esp + 0x10], al
// 00620c3c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00620c40  8844240c             mov byte ptr [esp + 0xc], al
// 00620c44  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00620c48  50                   push eax
// 00620c49  51                   push ecx
// 00620c4a  52                   push edx
// 00620c4b  57                   push edi
// 00620c4c  56                   push esi
// 00620c4d  53                   push ebx
// 00620c4e  e8bdfeffff           call 0x620b10
// 00620c53  2bf3                 sub esi, ebx
// 00620c55  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00620c5a  f7ee                 imul esi
// 00620c5c  c1fa02               sar edx, 2
// 00620c5f  8bc2                 mov eax, edx
// 00620c61  c1e81f               shr eax, 0x1f
// 00620c64  03c2                 add eax, edx
// 00620c66  8d0440               lea eax, [eax + eax*2]
// 00620c69  03c0                 add eax, eax
// 00620c6b  03c0                 add eax, eax
// 00620c6d  03c0                 add eax, eax
// 00620c6f  83c418               add esp, 0x18
// 00620c72  8bc8                 mov ecx, eax
// 00620c74  8bc7                 mov eax, edi
// 00620c76  5f                   pop edi
// 00620c77  5e                   pop esi
// 00620c78  2bc1                 sub eax, ecx
// 00620c7a  5b                   pop ebx
// 00620c7b  83c408               add esp, 8
// 00620c7e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
