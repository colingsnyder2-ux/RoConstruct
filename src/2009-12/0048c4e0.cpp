// from server: 100% by auto
// roc 2009-12 0048c4e0  unit: G3D::Shader  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048c4e0
//
// 0048c4e0  83ec08               sub esp, 8
// 0048c4e3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048c4e7  53                   push ebx
// 0048c4e8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0048c4ec  56                   push esi
// 0048c4ed  8b742418             mov esi, dword ptr [esp + 0x18]
// 0048c4f1  57                   push edi
// 0048c4f2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048c4f6  32c0                 xor al, al
// 0048c4f8  88442410             mov byte ptr [esp + 0x10], al
// 0048c4fc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0048c500  8844240c             mov byte ptr [esp + 0xc], al
// 0048c504  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0048c508  50                   push eax
// 0048c509  51                   push ecx
// 0048c50a  52                   push edx
// 0048c50b  57                   push edi
// 0048c50c  56                   push esi
// 0048c50d  53                   push ebx
// 0048c50e  e8adf7ffff           call 0x48bcc0
// 0048c513  2bf3                 sub esi, ebx
// 0048c515  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048c51a  f7ee                 imul esi
// 0048c51c  c1fa02               sar edx, 2
// 0048c51f  8bc2                 mov eax, edx
// 0048c521  c1e81f               shr eax, 0x1f
// 0048c524  03c2                 add eax, edx
// 0048c526  8d0440               lea eax, [eax + eax*2]
// 0048c529  03c0                 add eax, eax
// 0048c52b  03c0                 add eax, eax
// 0048c52d  03c0                 add eax, eax
// 0048c52f  83c418               add esp, 0x18
// 0048c532  8bc8                 mov ecx, eax
// 0048c534  8bc7                 mov eax, edi
// 0048c536  5f                   pop edi
// 0048c537  5e                   pop esi
// 0048c538  2bc1                 sub eax, ecx
// 0048c53a  5b                   pop ebx
// 0048c53b  83c408               add esp, 8
// 0048c53e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
