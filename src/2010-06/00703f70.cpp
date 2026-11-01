// from server: 100% by auto
// roc 2010-06 00703f70  unit: RBX::Animator  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00703f70
//
// 00703f70  83ec08               sub esp, 8
// 00703f73  8b542414             mov edx, dword ptr [esp + 0x14]
// 00703f77  53                   push ebx
// 00703f78  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00703f7c  56                   push esi
// 00703f7d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00703f81  57                   push edi
// 00703f82  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00703f86  32c0                 xor al, al
// 00703f88  88442410             mov byte ptr [esp + 0x10], al
// 00703f8c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00703f90  8844240c             mov byte ptr [esp + 0xc], al
// 00703f94  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00703f98  50                   push eax
// 00703f99  51                   push ecx
// 00703f9a  52                   push edx
// 00703f9b  57                   push edi
// 00703f9c  56                   push esi
// 00703f9d  53                   push ebx
// 00703f9e  e8fdfcffff           call 0x703ca0
// 00703fa3  2bf3                 sub esi, ebx
// 00703fa5  b8398ee338           mov eax, 0x38e38e39
// 00703faa  f7ee                 imul esi
// 00703fac  c1fa03               sar edx, 3
// 00703faf  8bc2                 mov eax, edx
// 00703fb1  c1e81f               shr eax, 0x1f
// 00703fb4  03c2                 add eax, edx
// 00703fb6  8d04c0               lea eax, [eax + eax*8]
// 00703fb9  03c0                 add eax, eax
// 00703fbb  03c0                 add eax, eax
// 00703fbd  83c418               add esp, 0x18
// 00703fc0  8bc8                 mov ecx, eax
// 00703fc2  8bc7                 mov eax, edi
// 00703fc4  5f                   pop edi
// 00703fc5  5e                   pop esi
// 00703fc6  2bc1                 sub eax, ecx
// 00703fc8  5b                   pop ebx
// 00703fc9  83c408               add esp, 8
// 00703fcc  c3                   ret 
// library ogre-1.7.0/OgreSubMesh.cpp (function ??$_Copy_backward_opt@PAUCluster@Ogre@@PAU12@@std@@YAPAUCluster@Ogre@@PAU12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreSubMesh.cpp
