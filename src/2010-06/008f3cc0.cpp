// from server: 100% by auto
// roc 2010-06 008f3cc0  unit: Ogre::UTVertex3DTex::?$SpecializedMeshGen  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f3cc0
//
// 008f3cc0  83ec08               sub esp, 8
// 008f3cc3  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f3cc7  53                   push ebx
// 008f3cc8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008f3ccc  56                   push esi
// 008f3ccd  8b742418             mov esi, dword ptr [esp + 0x18]
// 008f3cd1  57                   push edi
// 008f3cd2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008f3cd6  32c0                 xor al, al
// 008f3cd8  88442410             mov byte ptr [esp + 0x10], al
// 008f3cdc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f3ce0  8844240c             mov byte ptr [esp + 0xc], al
// 008f3ce4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008f3ce8  50                   push eax
// 008f3ce9  51                   push ecx
// 008f3cea  52                   push edx
// 008f3ceb  57                   push edi
// 008f3cec  56                   push esi
// 008f3ced  53                   push ebx
// 008f3cee  e8ddfeffff           call 0x8f3bd0
// 008f3cf3  2bf3                 sub esi, ebx
// 008f3cf5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008f3cfa  f7ee                 imul esi
// 008f3cfc  c1fa03               sar edx, 3
// 008f3cff  8bc2                 mov eax, edx
// 008f3d01  c1e81f               shr eax, 0x1f
// 008f3d04  03c2                 add eax, edx
// 008f3d06  8d0440               lea eax, [eax + eax*2]
// 008f3d09  c1e004               shl eax, 4
// 008f3d0c  83c418               add esp, 0x18
// 008f3d0f  8bc8                 mov ecx, eax
// 008f3d11  8bc7                 mov eax, edi
// 008f3d13  5f                   pop edi
// 008f3d14  5e                   pop esi
// 008f3d15  2bc1                 sub eax, ecx
// 008f3d17  5b                   pop ebx
// 008f3d18  83c408               add esp, 8
// 008f3d1b  c3                   ret 
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ??$_Copy_backward_opt@PAUPMWorkingData@ProgressiveMesh@Ogre@@PAU123@@std@@YAPAUPMWorkingData@ProgressiveMesh@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
