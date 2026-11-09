// from server: 100% by auto
// roc 2010-06 00901ed0  unit: Ogre::UFileInfo::V?$vector::?$SharedPtr  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00901ed0
//
// 00901ed0  83ec08               sub esp, 8
// 00901ed3  8b542414             mov edx, dword ptr [esp + 0x14]
// 00901ed7  53                   push ebx
// 00901ed8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00901edc  56                   push esi
// 00901edd  8b742418             mov esi, dword ptr [esp + 0x18]
// 00901ee1  57                   push edi
// 00901ee2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00901ee6  32c0                 xor al, al
// 00901ee8  88442410             mov byte ptr [esp + 0x10], al
// 00901eec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00901ef0  8844240c             mov byte ptr [esp + 0xc], al
// 00901ef4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00901ef8  50                   push eax
// 00901ef9  51                   push ecx
// 00901efa  52                   push edx
// 00901efb  57                   push edi
// 00901efc  56                   push esi
// 00901efd  53                   push ebx
// 00901efe  e8cdfdffff           call 0x901cd0
// 00901f03  2bf3                 sub esi, ebx
// 00901f05  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00901f0a  f7ee                 imul esi
// 00901f0c  c1fa04               sar edx, 4
// 00901f0f  8bc2                 mov eax, edx
// 00901f11  c1e81f               shr eax, 0x1f
// 00901f14  03c2                 add eax, edx
// 00901f16  8d0440               lea eax, [eax + eax*2]
// 00901f19  c1e005               shl eax, 5
// 00901f1c  83c418               add esp, 0x18
// 00901f1f  8bc8                 mov ecx, eax
// 00901f21  8bc7                 mov eax, edi
// 00901f23  5f                   pop edi
// 00901f24  5e                   pop esi
// 00901f25  2bc1                 sub eax, ecx
// 00901f27  5b                   pop ebx
// 00901f28  83c408               add esp, 8
// 00901f2b  c3                   ret 
// library wildmagic-2-core/Intersection\WmlIntrTet3Tet3.cpp (function ??$_Copy_backward_opt@PAV?$Tetrahedron3@N@Wml@@PAV12@@std@@YAPAV?$Tetrahedron3@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Intersection/WmlIntrTet3Tet3.cpp
