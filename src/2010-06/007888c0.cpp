// from server: 100% by auto
// roc 2010-06 007888c0  unit: RBX::HUMAN::GettingUp  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007888c0
//
// 007888c0  83ec08               sub esp, 8
// 007888c3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007888c7  53                   push ebx
// 007888c8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007888cc  56                   push esi
// 007888cd  8b742418             mov esi, dword ptr [esp + 0x18]
// 007888d1  57                   push edi
// 007888d2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007888d6  32c0                 xor al, al
// 007888d8  88442410             mov byte ptr [esp + 0x10], al
// 007888dc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007888e0  8844240c             mov byte ptr [esp + 0xc], al
// 007888e4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007888e8  50                   push eax
// 007888e9  51                   push ecx
// 007888ea  52                   push edx
// 007888eb  57                   push edi
// 007888ec  56                   push esi
// 007888ed  53                   push ebx
// 007888ee  e85df7ffff           call 0x788050
// 007888f3  2bf3                 sub esi, ebx
// 007888f5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007888fa  f7ee                 imul esi
// 007888fc  c1fa03               sar edx, 3
// 007888ff  8bc2                 mov eax, edx
// 00788901  c1e81f               shr eax, 0x1f
// 00788904  03c2                 add eax, edx
// 00788906  8d0440               lea eax, [eax + eax*2]
// 00788909  c1e004               shl eax, 4
// 0078890c  83c418               add esp, 0x18
// 0078890f  8bc8                 mov ecx, eax
// 00788911  8bc7                 mov eax, edi
// 00788913  5f                   pop edi
// 00788914  5e                   pop esi
// 00788915  2bc1                 sub eax, ecx
// 00788917  5b                   pop ebx
// 00788918  83c408               add esp, 8
// 0078891b  c3                   ret 
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ??$_Copy_backward_opt@PAUPMWorkingData@ProgressiveMesh@Ogre@@PAU123@@std@@YAPAUPMWorkingData@ProgressiveMesh@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
