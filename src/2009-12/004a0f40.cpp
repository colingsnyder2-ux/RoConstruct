// from server: 100% by auto
// roc 2009-12 004a0f40  unit: Ogre::UTVertexTangent3DTexColorIndexSurfaceTex::?$SpecializedMeshGen  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a0f40
//
// 004a0f40  83ec08               sub esp, 8
// 004a0f43  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a0f47  53                   push ebx
// 004a0f48  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004a0f4c  56                   push esi
// 004a0f4d  8b742418             mov esi, dword ptr [esp + 0x18]
// 004a0f51  57                   push edi
// 004a0f52  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004a0f56  32c0                 xor al, al
// 004a0f58  88442410             mov byte ptr [esp + 0x10], al
// 004a0f5c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a0f60  8844240c             mov byte ptr [esp + 0xc], al
// 004a0f64  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004a0f68  50                   push eax
// 004a0f69  51                   push ecx
// 004a0f6a  52                   push edx
// 004a0f6b  57                   push edi
// 004a0f6c  56                   push esi
// 004a0f6d  53                   push ebx
// 004a0f6e  e89dfeffff           call 0x4a0e10
// 004a0f73  2bf3                 sub esi, ebx
// 004a0f75  b8398ee338           mov eax, 0x38e38e39
// 004a0f7a  f7ee                 imul esi
// 004a0f7c  c1fa04               sar edx, 4
// 004a0f7f  8bc2                 mov eax, edx
// 004a0f81  c1e81f               shr eax, 0x1f
// 004a0f84  03c2                 add eax, edx
// 004a0f86  8d04c0               lea eax, [eax + eax*8]
// 004a0f89  03c0                 add eax, eax
// 004a0f8b  03c0                 add eax, eax
// 004a0f8d  03c0                 add eax, eax
// 004a0f8f  83c418               add esp, 0x18
// 004a0f92  8bc8                 mov ecx, eax
// 004a0f94  8bc7                 mov eax, edi
// 004a0f96  5f                   pop edi
// 004a0f97  5e                   pop esi
// 004a0f98  2bc1                 sub eax, ecx
// 004a0f9a  5b                   pop ebx
// 004a0f9b  83c408               add esp, 8
// 004a0f9e  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Copy_backward_opt@PAVFace@?$ConvexClipper@N@Wml@@PAV123@@std@@YAPAVFace@?$ConvexClipper@N@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
