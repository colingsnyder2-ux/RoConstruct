// from server: 100% by auto
// roc 2009-12 00486850  unit: Ogre::GfxClustererPart  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00486850
//
// 00486850  83ec08               sub esp, 8
// 00486853  8b542414             mov edx, dword ptr [esp + 0x14]
// 00486857  53                   push ebx
// 00486858  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0048685c  56                   push esi
// 0048685d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00486861  57                   push edi
// 00486862  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00486866  32c0                 xor al, al
// 00486868  88442410             mov byte ptr [esp + 0x10], al
// 0048686c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00486870  8844240c             mov byte ptr [esp + 0xc], al
// 00486874  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00486878  50                   push eax
// 00486879  51                   push ecx
// 0048687a  52                   push edx
// 0048687b  57                   push edi
// 0048687c  56                   push esi
// 0048687d  53                   push ebx
// 0048687e  e89de8ffff           call 0x485120
// 00486883  2bf3                 sub esi, ebx
// 00486885  83c418               add esp, 0x18
// 00486888  c1fe05               sar esi, 5
// 0048688b  c1e605               shl esi, 5
// 0048688e  8bc7                 mov eax, edi
// 00486890  5f                   pop edi
// 00486891  2bc6                 sub eax, esi
// 00486893  5e                   pop esi
// 00486894  5b                   pop ebx
// 00486895  83c408               add esp, 8
// 00486898  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Copy_backward_opt@PAVFace@?$ConvexClipper@M@Wml@@PAV123@@std@@YAPAVFace@?$ConvexClipper@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
