// from server: 100% by auto
// roc 2010-06 007886d0  unit: RBX::HUMAN::GettingUp  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007886d0
//
// 007886d0  83ec08               sub esp, 8
// 007886d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007886d7  53                   push ebx
// 007886d8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007886dc  56                   push esi
// 007886dd  8b742418             mov esi, dword ptr [esp + 0x18]
// 007886e1  57                   push edi
// 007886e2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007886e6  32c0                 xor al, al
// 007886e8  88442410             mov byte ptr [esp + 0x10], al
// 007886ec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007886f0  8844240c             mov byte ptr [esp + 0xc], al
// 007886f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007886f8  50                   push eax
// 007886f9  51                   push ecx
// 007886fa  52                   push edx
// 007886fb  57                   push edi
// 007886fc  56                   push esi
// 007886fd  53                   push ebx
// 007886fe  e87df8ffff           call 0x787f80
// 00788703  2bf3                 sub esi, ebx
// 00788705  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0078870a  f7ee                 imul esi
// 0078870c  c1fa03               sar edx, 3
// 0078870f  8bc2                 mov eax, edx
// 00788711  c1e81f               shr eax, 0x1f
// 00788714  03c2                 add eax, edx
// 00788716  8d0440               lea eax, [eax + eax*2]
// 00788719  83c418               add esp, 0x18
// 0078871c  c1e004               shl eax, 4
// 0078871f  03c7                 add eax, edi
// 00788721  5f                   pop edi
// 00788722  5e                   pop esi
// 00788723  5b                   pop ebx
// 00788724  83c408               add esp, 8
// 00788727  c3                   ret 
// library ogre-1.7.0/OgreSkeleton.cpp (function ??$_Copy_opt@PAULinkedSkeletonAnimationSource@Ogre@@PAU12@@std@@YAPAULinkedSkeletonAnimationSource@Ogre@@PAU12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreSkeleton.cpp
