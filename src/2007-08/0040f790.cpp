// from server: 100% by auto
// roc 2007-08 0040f790  unit: CopyVerb  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040f790
//
// 0040f790  83ec08               sub esp, 8
// 0040f793  8b542414             mov edx, dword ptr [esp + 0x14]
// 0040f797  53                   push ebx
// 0040f798  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0040f79c  56                   push esi
// 0040f79d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0040f7a1  57                   push edi
// 0040f7a2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0040f7a6  32c0                 xor al, al
// 0040f7a8  88442410             mov byte ptr [esp + 0x10], al
// 0040f7ac  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040f7b0  8844240c             mov byte ptr [esp + 0xc], al
// 0040f7b4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040f7b8  50                   push eax
// 0040f7b9  51                   push ecx
// 0040f7ba  52                   push edx
// 0040f7bb  57                   push edi
// 0040f7bc  56                   push esi
// 0040f7bd  53                   push ebx
// 0040f7be  e8ddfdffff           call 0x40f5a0
// 0040f7c3  2bf3                 sub esi, ebx
// 0040f7c5  b8398ee338           mov eax, 0x38e38e39
// 0040f7ca  f7ee                 imul esi
// 0040f7cc  c1fa03               sar edx, 3
// 0040f7cf  8bc2                 mov eax, edx
// 0040f7d1  c1e81f               shr eax, 0x1f
// 0040f7d4  03c2                 add eax, edx
// 0040f7d6  8d04c0               lea eax, [eax + eax*8]
// 0040f7d9  03c0                 add eax, eax
// 0040f7db  03c0                 add eax, eax
// 0040f7dd  83c418               add esp, 0x18
// 0040f7e0  8bc8                 mov ecx, eax
// 0040f7e2  8bc7                 mov eax, edi
// 0040f7e4  5f                   pop edi
// 0040f7e5  5e                   pop esi
// 0040f7e6  2bc1                 sub eax, ecx
// 0040f7e8  5b                   pop ebx
// 0040f7e9  83c408               add esp, 8
// 0040f7ec  c3                   ret 
// library ogre-1.7.0/OgreSubMesh.cpp (function ??$_Copy_backward_opt@PAUCluster@Ogre@@PAU12@@std@@YAPAUCluster@Ogre@@PAU12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreSubMesh.cpp
