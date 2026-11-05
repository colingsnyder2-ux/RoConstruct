// from server: 100% by auto
// roc 2010-06 0096a440  unit: Ogre::RbxSceneUpdater  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096a440
//
// 0096a440  83ec08               sub esp, 8
// 0096a443  8b542414             mov edx, dword ptr [esp + 0x14]
// 0096a447  53                   push ebx
// 0096a448  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0096a44c  56                   push esi
// 0096a44d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0096a451  57                   push edi
// 0096a452  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0096a456  32c0                 xor al, al
// 0096a458  88442410             mov byte ptr [esp + 0x10], al
// 0096a45c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0096a460  8844240c             mov byte ptr [esp + 0xc], al
// 0096a464  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0096a468  50                   push eax
// 0096a469  51                   push ecx
// 0096a46a  52                   push edx
// 0096a46b  57                   push edi
// 0096a46c  56                   push esi
// 0096a46d  53                   push ebx
// 0096a46e  e82de2ffff           call 0x9686a0
// 0096a473  2bf3                 sub esi, ebx
// 0096a475  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096a47a  f7ee                 imul esi
// 0096a47c  c1fa02               sar edx, 2
// 0096a47f  8bc2                 mov eax, edx
// 0096a481  c1e81f               shr eax, 0x1f
// 0096a484  03c2                 add eax, edx
// 0096a486  8d0440               lea eax, [eax + eax*2]
// 0096a489  03c0                 add eax, eax
// 0096a48b  03c0                 add eax, eax
// 0096a48d  03c0                 add eax, eax
// 0096a48f  83c418               add esp, 0x18
// 0096a492  8bc8                 mov ecx, eax
// 0096a494  8bc7                 mov eax, edi
// 0096a496  5f                   pop edi
// 0096a497  5e                   pop esi
// 0096a498  2bc1                 sub eax, ecx
// 0096a49a  5b                   pop ebx
// 0096a49b  83c408               add esp, 8
// 0096a49e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
