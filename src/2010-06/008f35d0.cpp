// from server: 100% by auto
// roc 2010-06 008f35d0  unit: Ogre::UTVertexSurfaceTexTangent::?$SpecializedMeshGen  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f35d0
//
// 008f35d0  83ec08               sub esp, 8
// 008f35d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f35d7  53                   push ebx
// 008f35d8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008f35dc  56                   push esi
// 008f35dd  8b742418             mov esi, dword ptr [esp + 0x18]
// 008f35e1  57                   push edi
// 008f35e2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008f35e6  32c0                 xor al, al
// 008f35e8  88442410             mov byte ptr [esp + 0x10], al
// 008f35ec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f35f0  8844240c             mov byte ptr [esp + 0xc], al
// 008f35f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008f35f8  50                   push eax
// 008f35f9  51                   push ecx
// 008f35fa  52                   push edx
// 008f35fb  57                   push edi
// 008f35fc  56                   push esi
// 008f35fd  53                   push ebx
// 008f35fe  e8bdfeffff           call 0x8f34c0
// 008f3603  2bf3                 sub esi, ebx
// 008f3605  b893244992           mov eax, 0x92492493
// 008f360a  f7ee                 imul esi
// 008f360c  03d6                 add edx, esi
// 008f360e  c1fa05               sar edx, 5
// 008f3611  8bc2                 mov eax, edx
// 008f3613  c1e81f               shr eax, 0x1f
// 008f3616  03c2                 add eax, edx
// 008f3618  8d0cc500000000       lea ecx, [eax*8]
// 008f361f  2bc8                 sub ecx, eax
// 008f3621  83c418               add esp, 0x18
// 008f3624  03c9                 add ecx, ecx
// 008f3626  8bc7                 mov eax, edi
// 008f3628  03c9                 add ecx, ecx
// 008f362a  5f                   pop edi
// 008f362b  03c9                 add ecx, ecx
// 008f362d  5e                   pop esi
// 008f362e  2bc1                 sub eax, ecx
// 008f3630  5b                   pop ebx
// 008f3631  83c408               add esp, 8
// 008f3634  c3                   ret 
// library ogre-1.7.0/OgreMaterialSerializer.cpp (function ??$_Copy_backward_opt@PAU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@PAU12@@std@@YAPAU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@0@PAU10@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMaterialSerializer.cpp
