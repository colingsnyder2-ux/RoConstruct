// from server: 100% by auto
// roc 2010-06 008d27d0  unit: Ogre::VisualEngine  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d27d0
//
// 008d27d0  83ec08               sub esp, 8
// 008d27d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d27d7  53                   push ebx
// 008d27d8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008d27dc  56                   push esi
// 008d27dd  8b742418             mov esi, dword ptr [esp + 0x18]
// 008d27e1  57                   push edi
// 008d27e2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008d27e6  32c0                 xor al, al
// 008d27e8  88442410             mov byte ptr [esp + 0x10], al
// 008d27ec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d27f0  8844240c             mov byte ptr [esp + 0xc], al
// 008d27f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008d27f8  50                   push eax
// 008d27f9  51                   push ecx
// 008d27fa  52                   push edx
// 008d27fb  57                   push edi
// 008d27fc  56                   push esi
// 008d27fd  53                   push ebx
// 008d27fe  e8adf7ffff           call 0x8d1fb0
// 008d2803  2bf3                 sub esi, ebx
// 008d2805  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d280a  f7ee                 imul esi
// 008d280c  c1fa02               sar edx, 2
// 008d280f  8bc2                 mov eax, edx
// 008d2811  c1e81f               shr eax, 0x1f
// 008d2814  03c2                 add eax, edx
// 008d2816  8d0440               lea eax, [eax + eax*2]
// 008d2819  03c0                 add eax, eax
// 008d281b  03c0                 add eax, eax
// 008d281d  03c0                 add eax, eax
// 008d281f  83c418               add esp, 0x18
// 008d2822  8bc8                 mov ecx, eax
// 008d2824  8bc7                 mov eax, edi
// 008d2826  5f                   pop edi
// 008d2827  5e                   pop esi
// 008d2828  2bc1                 sub eax, ecx
// 008d282a  5b                   pop ebx
// 008d282b  83c408               add esp, 8
// 008d282e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
