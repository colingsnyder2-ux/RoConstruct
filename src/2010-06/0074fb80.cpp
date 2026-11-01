// from server: 100% by auto
// roc 2010-06 0074fb80  unit: RBX::Humanoid  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0074fb80
//
// 0074fb80  83ec08               sub esp, 8
// 0074fb83  8b542414             mov edx, dword ptr [esp + 0x14]
// 0074fb87  53                   push ebx
// 0074fb88  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0074fb8c  56                   push esi
// 0074fb8d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0074fb91  57                   push edi
// 0074fb92  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0074fb96  32c0                 xor al, al
// 0074fb98  88442410             mov byte ptr [esp + 0x10], al
// 0074fb9c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0074fba0  8844240c             mov byte ptr [esp + 0xc], al
// 0074fba4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074fba8  50                   push eax
// 0074fba9  51                   push ecx
// 0074fbaa  52                   push edx
// 0074fbab  57                   push edi
// 0074fbac  56                   push esi
// 0074fbad  53                   push ebx
// 0074fbae  e83dfeffff           call 0x74f9f0
// 0074fbb3  2bf3                 sub esi, ebx
// 0074fbb5  b893244992           mov eax, 0x92492493
// 0074fbba  f7ee                 imul esi
// 0074fbbc  03d6                 add edx, esi
// 0074fbbe  c1fa04               sar edx, 4
// 0074fbc1  8bc2                 mov eax, edx
// 0074fbc3  c1e81f               shr eax, 0x1f
// 0074fbc6  03c2                 add eax, edx
// 0074fbc8  8d0cc500000000       lea ecx, [eax*8]
// 0074fbcf  83c418               add esp, 0x18
// 0074fbd2  2bc8                 sub ecx, eax
// 0074fbd4  8bc7                 mov eax, edi
// 0074fbd6  03c9                 add ecx, ecx
// 0074fbd8  5f                   pop edi
// 0074fbd9  03c9                 add ecx, ecx
// 0074fbdb  5e                   pop esi
// 0074fbdc  2bc1                 sub eax, ecx
// 0074fbde  5b                   pop ebx
// 0074fbdf  83c408               add esp, 8
// 0074fbe2  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Copy_backward_opt@PAUCommonVertex@EdgeListBuilder@Ogre@@PAU123@@std@@YAPAUCommonVertex@EdgeListBuilder@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
