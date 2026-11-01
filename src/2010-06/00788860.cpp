// from server: 100% by auto
// roc 2010-06 00788860  unit: RBX::HUMAN::GettingUp  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00788860
//
// 00788860  83ec08               sub esp, 8
// 00788863  8b542414             mov edx, dword ptr [esp + 0x14]
// 00788867  53                   push ebx
// 00788868  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0078886c  56                   push esi
// 0078886d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00788871  57                   push edi
// 00788872  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00788876  32c0                 xor al, al
// 00788878  88442410             mov byte ptr [esp + 0x10], al
// 0078887c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00788880  8844240c             mov byte ptr [esp + 0xc], al
// 00788884  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00788888  50                   push eax
// 00788889  51                   push ecx
// 0078888a  52                   push edx
// 0078888b  57                   push edi
// 0078888c  56                   push esi
// 0078888d  53                   push ebx
// 0078888e  e84df7ffff           call 0x787fe0
// 00788893  2bf3                 sub esi, ebx
// 00788895  b867666666           mov eax, 0x66666667
// 0078889a  f7ee                 imul esi
// 0078889c  c1fa04               sar edx, 4
// 0078889f  8bc2                 mov eax, edx
// 007888a1  c1e81f               shr eax, 0x1f
// 007888a4  03c2                 add eax, edx
// 007888a6  8d0480               lea eax, [eax + eax*4]
// 007888a9  03c0                 add eax, eax
// 007888ab  03c0                 add eax, eax
// 007888ad  03c0                 add eax, eax
// 007888af  83c418               add esp, 0x18
// 007888b2  8bc8                 mov ecx, eax
// 007888b4  8bc7                 mov eax, edi
// 007888b6  5f                   pop edi
// 007888b7  5e                   pop esi
// 007888b8  2bc1                 sub eax, ecx
// 007888ba  5b                   pop ebx
// 007888bb  83c408               add esp, 8
// 007888be  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Copy_backward_opt@PAUEdgeGroup@EdgeData@Ogre@@PAU123@@std@@YAPAUEdgeGroup@EdgeData@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
