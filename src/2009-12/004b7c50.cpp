// from server: 100% by auto
// roc 2009-12 004b7c50  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b7c50
//
// 004b7c50  83ec08               sub esp, 8
// 004b7c53  8b542414             mov edx, dword ptr [esp + 0x14]
// 004b7c57  53                   push ebx
// 004b7c58  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004b7c5c  56                   push esi
// 004b7c5d  8b742418             mov esi, dword ptr [esp + 0x18]
// 004b7c61  57                   push edi
// 004b7c62  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b7c66  32c0                 xor al, al
// 004b7c68  88442410             mov byte ptr [esp + 0x10], al
// 004b7c6c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b7c70  8844240c             mov byte ptr [esp + 0xc], al
// 004b7c74  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004b7c78  50                   push eax
// 004b7c79  51                   push ecx
// 004b7c7a  52                   push edx
// 004b7c7b  57                   push edi
// 004b7c7c  56                   push esi
// 004b7c7d  53                   push ebx
// 004b7c7e  e81dfeffff           call 0x4b7aa0
// 004b7c83  2bf3                 sub esi, ebx
// 004b7c85  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004b7c8a  f7ee                 imul esi
// 004b7c8c  c1fa04               sar edx, 4
// 004b7c8f  8bc2                 mov eax, edx
// 004b7c91  c1e81f               shr eax, 0x1f
// 004b7c94  03c2                 add eax, edx
// 004b7c96  8d0440               lea eax, [eax + eax*2]
// 004b7c99  c1e005               shl eax, 5
// 004b7c9c  83c418               add esp, 0x18
// 004b7c9f  8bc8                 mov ecx, eax
// 004b7ca1  8bc7                 mov eax, edi
// 004b7ca3  5f                   pop edi
// 004b7ca4  5e                   pop esi
// 004b7ca5  2bc1                 sub eax, ecx
// 004b7ca7  5b                   pop ebx
// 004b7ca8  83c408               add esp, 8
// 004b7cab  c3                   ret 
// library wildmagic-2-core/Intersection\WmlIntrTet3Tet3.cpp (function ??$_Copy_backward_opt@PAV?$Tetrahedron3@N@Wml@@PAV12@@std@@YAPAV?$Tetrahedron3@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Intersection/WmlIntrTet3Tet3.cpp
