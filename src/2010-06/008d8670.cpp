// from server: 100% by auto
// roc 2010-06 008d8670  unit: Ogre::RbxTextureCompositorSceneManager  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d8670
//
// 008d8670  83ec08               sub esp, 8
// 008d8673  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d8677  53                   push ebx
// 008d8678  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008d867c  56                   push esi
// 008d867d  8b742418             mov esi, dword ptr [esp + 0x18]
// 008d8681  57                   push edi
// 008d8682  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008d8686  32c0                 xor al, al
// 008d8688  88442410             mov byte ptr [esp + 0x10], al
// 008d868c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d8690  8844240c             mov byte ptr [esp + 0xc], al
// 008d8694  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008d8698  50                   push eax
// 008d8699  51                   push ecx
// 008d869a  52                   push edx
// 008d869b  57                   push edi
// 008d869c  56                   push esi
// 008d869d  53                   push ebx
// 008d869e  e85dedffff           call 0x8d7400
// 008d86a3  2bf3                 sub esi, ebx
// 008d86a5  b8398ee338           mov eax, 0x38e38e39
// 008d86aa  f7ee                 imul esi
// 008d86ac  c1fa04               sar edx, 4
// 008d86af  83c418               add esp, 0x18
// 008d86b2  8bc2                 mov eax, edx
// 008d86b4  c1e81f               shr eax, 0x1f
// 008d86b7  03c2                 add eax, edx
// 008d86b9  8d04c0               lea eax, [eax + eax*8]
// 008d86bc  8d04c7               lea eax, [edi + eax*8]
// 008d86bf  5f                   pop edi
// 008d86c0  5e                   pop esi
// 008d86c1  5b                   pop ebx
// 008d86c2  83c408               add esp, 8
// 008d86c5  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Copy_opt@PAVFace@?$ConvexClipper@N@Wml@@PAV123@@std@@YAPAVFace@?$ConvexClipper@N@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
