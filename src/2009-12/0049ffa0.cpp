// from server: 100% by auto
// roc 2009-12 0049ffa0  unit: Ogre::UTVertex3DTex::?$SpecializedMeshGen  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0049ffa0
//
// 0049ffa0  83ec08               sub esp, 8
// 0049ffa3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0049ffa7  53                   push ebx
// 0049ffa8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0049ffac  56                   push esi
// 0049ffad  8b742418             mov esi, dword ptr [esp + 0x18]
// 0049ffb1  57                   push edi
// 0049ffb2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0049ffb6  32c0                 xor al, al
// 0049ffb8  88442410             mov byte ptr [esp + 0x10], al
// 0049ffbc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0049ffc0  8844240c             mov byte ptr [esp + 0xc], al
// 0049ffc4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0049ffc8  50                   push eax
// 0049ffc9  51                   push ecx
// 0049ffca  52                   push edx
// 0049ffcb  57                   push edi
// 0049ffcc  56                   push esi
// 0049ffcd  53                   push ebx
// 0049ffce  e8ddfeffff           call 0x49feb0
// 0049ffd3  2bf3                 sub esi, ebx
// 0049ffd5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0049ffda  f7ee                 imul esi
// 0049ffdc  c1fa03               sar edx, 3
// 0049ffdf  8bc2                 mov eax, edx
// 0049ffe1  c1e81f               shr eax, 0x1f
// 0049ffe4  03c2                 add eax, edx
// 0049ffe6  8d0440               lea eax, [eax + eax*2]
// 0049ffe9  c1e004               shl eax, 4
// 0049ffec  83c418               add esp, 0x18
// 0049ffef  8bc8                 mov ecx, eax
// 0049fff1  8bc7                 mov eax, edi
// 0049fff3  5f                   pop edi
// 0049fff4  5e                   pop esi
// 0049fff5  2bc1                 sub eax, ecx
// 0049fff7  5b                   pop ebx
// 0049fff8  83c408               add esp, 8
// 0049fffb  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Copy_backward_opt@PAVFace@?$ConvexClipper@N@Wml@@PAV123@@std@@YAPAVFace@?$ConvexClipper@N@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
