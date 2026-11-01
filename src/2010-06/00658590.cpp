// from server: 100% by auto
// roc 2010-06 00658590  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00658590
//
// 00658590  83ec08               sub esp, 8
// 00658593  8b542414             mov edx, dword ptr [esp + 0x14]
// 00658597  53                   push ebx
// 00658598  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0065859c  56                   push esi
// 0065859d  8b742418             mov esi, dword ptr [esp + 0x18]
// 006585a1  57                   push edi
// 006585a2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006585a6  32c0                 xor al, al
// 006585a8  88442410             mov byte ptr [esp + 0x10], al
// 006585ac  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006585b0  8844240c             mov byte ptr [esp + 0xc], al
// 006585b4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006585b8  50                   push eax
// 006585b9  51                   push ecx
// 006585ba  52                   push edx
// 006585bb  57                   push edi
// 006585bc  56                   push esi
// 006585bd  53                   push ebx
// 006585be  e8ddfbffff           call 0x6581a0
// 006585c3  2bf3                 sub esi, ebx
// 006585c5  b893244992           mov eax, 0x92492493
// 006585ca  f7ee                 imul esi
// 006585cc  03d6                 add edx, esi
// 006585ce  c1fa04               sar edx, 4
// 006585d1  8bc2                 mov eax, edx
// 006585d3  c1e81f               shr eax, 0x1f
// 006585d6  03c2                 add eax, edx
// 006585d8  8d0cc500000000       lea ecx, [eax*8]
// 006585df  83c418               add esp, 0x18
// 006585e2  2bc8                 sub ecx, eax
// 006585e4  8bc7                 mov eax, edi
// 006585e6  03c9                 add ecx, ecx
// 006585e8  5f                   pop edi
// 006585e9  03c9                 add ecx, ecx
// 006585eb  5e                   pop esi
// 006585ec  2bc1                 sub eax, ecx
// 006585ee  5b                   pop ebx
// 006585ef  83c408               add esp, 8
// 006585f2  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Copy_backward_opt@PAUCommonVertex@EdgeListBuilder@Ogre@@PAU123@@std@@YAPAUCommonVertex@EdgeListBuilder@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
