// from server: 100% by auto
// roc 2009-12 004a1e80  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a1e80
//
// 004a1e80  83ec08               sub esp, 8
// 004a1e83  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a1e87  53                   push ebx
// 004a1e88  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004a1e8c  56                   push esi
// 004a1e8d  8b742418             mov esi, dword ptr [esp + 0x18]
// 004a1e91  57                   push edi
// 004a1e92  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004a1e96  32c0                 xor al, al
// 004a1e98  88442410             mov byte ptr [esp + 0x10], al
// 004a1e9c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a1ea0  8844240c             mov byte ptr [esp + 0xc], al
// 004a1ea4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004a1ea8  50                   push eax
// 004a1ea9  51                   push ecx
// 004a1eaa  52                   push edx
// 004a1eab  57                   push edi
// 004a1eac  56                   push esi
// 004a1ead  53                   push ebx
// 004a1eae  e84dfeffff           call 0x4a1d00
// 004a1eb3  2bf3                 sub esi, ebx
// 004a1eb5  83c418               add esp, 0x18
// 004a1eb8  c1fe05               sar esi, 5
// 004a1ebb  c1e605               shl esi, 5
// 004a1ebe  8bc7                 mov eax, edi
// 004a1ec0  5f                   pop edi
// 004a1ec1  2bc6                 sub eax, esi
// 004a1ec3  5e                   pop esi
// 004a1ec4  5b                   pop ebx
// 004a1ec5  83c408               add esp, 8
// 004a1ec8  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Copy_backward_opt@PAVFace@?$ConvexClipper@M@Wml@@PAV123@@std@@YAPAVFace@?$ConvexClipper@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
