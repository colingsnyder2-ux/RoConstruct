// from server: 100% by auto
// roc 2010-06 008d56e0  unit: Ogre::VertexStreamer  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d56e0
//
// 008d56e0  83ec08               sub esp, 8
// 008d56e3  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d56e7  53                   push ebx
// 008d56e8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008d56ec  56                   push esi
// 008d56ed  8b742418             mov esi, dword ptr [esp + 0x18]
// 008d56f1  57                   push edi
// 008d56f2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008d56f6  32c0                 xor al, al
// 008d56f8  88442410             mov byte ptr [esp + 0x10], al
// 008d56fc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d5700  8844240c             mov byte ptr [esp + 0xc], al
// 008d5704  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008d5708  50                   push eax
// 008d5709  51                   push ecx
// 008d570a  52                   push edx
// 008d570b  57                   push edi
// 008d570c  56                   push esi
// 008d570d  53                   push ebx
// 008d570e  e8cdfcffff           call 0x8d53e0
// 008d5713  2bf3                 sub esi, ebx
// 008d5715  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d571a  f7ee                 imul esi
// 008d571c  c1fa02               sar edx, 2
// 008d571f  8bc2                 mov eax, edx
// 008d5721  c1e81f               shr eax, 0x1f
// 008d5724  03c2                 add eax, edx
// 008d5726  8d0440               lea eax, [eax + eax*2]
// 008d5729  03c0                 add eax, eax
// 008d572b  03c0                 add eax, eax
// 008d572d  03c0                 add eax, eax
// 008d572f  83c418               add esp, 0x18
// 008d5732  8bc8                 mov ecx, eax
// 008d5734  8bc7                 mov eax, edi
// 008d5736  5f                   pop edi
// 008d5737  5e                   pop esi
// 008d5738  2bc1                 sub eax, ecx
// 008d573a  5b                   pop ebx
// 008d573b  83c408               add esp, 8
// 008d573e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
