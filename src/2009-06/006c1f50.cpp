// from server: 100% by auto
// roc 2009-06 006c1f50  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c1f50
//
// 006c1f50  83ec08               sub esp, 8
// 006c1f53  8b542414             mov edx, dword ptr [esp + 0x14]
// 006c1f57  53                   push ebx
// 006c1f58  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006c1f5c  56                   push esi
// 006c1f5d  8b742418             mov esi, dword ptr [esp + 0x18]
// 006c1f61  57                   push edi
// 006c1f62  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006c1f66  32c0                 xor al, al
// 006c1f68  88442410             mov byte ptr [esp + 0x10], al
// 006c1f6c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006c1f70  8844240c             mov byte ptr [esp + 0xc], al
// 006c1f74  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006c1f78  50                   push eax
// 006c1f79  51                   push ecx
// 006c1f7a  52                   push edx
// 006c1f7b  57                   push edi
// 006c1f7c  56                   push esi
// 006c1f7d  53                   push ebx
// 006c1f7e  e8edfcffff           call 0x6c1c70
// 006c1f83  2bf3                 sub esi, ebx
// 006c1f85  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006c1f8a  f7ee                 imul esi
// 006c1f8c  c1fa02               sar edx, 2
// 006c1f8f  83c418               add esp, 0x18
// 006c1f92  8bc2                 mov eax, edx
// 006c1f94  c1e81f               shr eax, 0x1f
// 006c1f97  03c2                 add eax, edx
// 006c1f99  8d0440               lea eax, [eax + eax*2]
// 006c1f9c  8d04c7               lea eax, [edi + eax*8]
// 006c1f9f  5f                   pop edi
// 006c1fa0  5e                   pop esi
// 006c1fa1  5b                   pop ebx
// 006c1fa2  83c408               add esp, 8
// 006c1fa5  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
