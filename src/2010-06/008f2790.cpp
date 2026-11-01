// from server: 100% by auto
// roc 2010-06 008f2790  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f2790
//
// 008f2790  83ec08               sub esp, 8
// 008f2793  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f2797  53                   push ebx
// 008f2798  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008f279c  56                   push esi
// 008f279d  8b742418             mov esi, dword ptr [esp + 0x18]
// 008f27a1  57                   push edi
// 008f27a2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008f27a6  32c0                 xor al, al
// 008f27a8  88442410             mov byte ptr [esp + 0x10], al
// 008f27ac  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f27b0  8844240c             mov byte ptr [esp + 0xc], al
// 008f27b4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008f27b8  50                   push eax
// 008f27b9  51                   push ecx
// 008f27ba  52                   push edx
// 008f27bb  57                   push edi
// 008f27bc  56                   push esi
// 008f27bd  53                   push ebx
// 008f27be  e8fdfeffff           call 0x8f26c0
// 008f27c3  2bf3                 sub esi, ebx
// 008f27c5  b8398ee338           mov eax, 0x38e38e39
// 008f27ca  f7ee                 imul esi
// 008f27cc  c1fa03               sar edx, 3
// 008f27cf  8bc2                 mov eax, edx
// 008f27d1  c1e81f               shr eax, 0x1f
// 008f27d4  03c2                 add eax, edx
// 008f27d6  8d04c0               lea eax, [eax + eax*8]
// 008f27d9  03c0                 add eax, eax
// 008f27db  03c0                 add eax, eax
// 008f27dd  83c418               add esp, 0x18
// 008f27e0  8bc8                 mov ecx, eax
// 008f27e2  8bc7                 mov eax, edi
// 008f27e4  5f                   pop edi
// 008f27e5  5e                   pop esi
// 008f27e6  2bc1                 sub eax, ecx
// 008f27e8  5b                   pop ebx
// 008f27e9  83c408               add esp, 8
// 008f27ec  c3                   ret 
// library ogre-1.7.0/OgreSubMesh.cpp (function ??$_Copy_backward_opt@PAUCluster@Ogre@@PAU12@@std@@YAPAUCluster@Ogre@@PAU12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreSubMesh.cpp
