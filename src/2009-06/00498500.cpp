// from server: 100% by auto
// roc 2009-06 00498500  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498500
//
// 00498500  83ec08               sub esp, 8
// 00498503  8b542414             mov edx, dword ptr [esp + 0x14]
// 00498507  53                   push ebx
// 00498508  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0049850c  56                   push esi
// 0049850d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00498511  57                   push edi
// 00498512  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00498516  32c0                 xor al, al
// 00498518  88442410             mov byte ptr [esp + 0x10], al
// 0049851c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00498520  8844240c             mov byte ptr [esp + 0xc], al
// 00498524  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00498528  50                   push eax
// 00498529  51                   push ecx
// 0049852a  52                   push edx
// 0049852b  57                   push edi
// 0049852c  56                   push esi
// 0049852d  53                   push ebx
// 0049852e  e81dfeffff           call 0x498350
// 00498533  2bf3                 sub esi, ebx
// 00498535  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0049853a  f7ee                 imul esi
// 0049853c  c1fa04               sar edx, 4
// 0049853f  8bc2                 mov eax, edx
// 00498541  c1e81f               shr eax, 0x1f
// 00498544  03c2                 add eax, edx
// 00498546  8d0440               lea eax, [eax + eax*2]
// 00498549  c1e005               shl eax, 5
// 0049854c  83c418               add esp, 0x18
// 0049854f  8bc8                 mov ecx, eax
// 00498551  8bc7                 mov eax, edi
// 00498553  5f                   pop edi
// 00498554  5e                   pop esi
// 00498555  2bc1                 sub eax, ecx
// 00498557  5b                   pop ebx
// 00498558  83c408               add esp, 8
// 0049855b  c3                   ret 
// library wildmagic-2-core/Intersection\WmlIntrTet3Tet3.cpp (function ??$_Copy_backward_opt@PAV?$Tetrahedron3@N@Wml@@PAV12@@std@@YAPAV?$Tetrahedron3@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Intersection/WmlIntrTet3Tet3.cpp
