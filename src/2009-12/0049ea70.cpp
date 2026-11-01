// from server: 100% by auto
// roc 2009-12 0049ea70  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0049ea70
//
// 0049ea70  83ec08               sub esp, 8
// 0049ea73  8b542414             mov edx, dword ptr [esp + 0x14]
// 0049ea77  53                   push ebx
// 0049ea78  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0049ea7c  56                   push esi
// 0049ea7d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0049ea81  57                   push edi
// 0049ea82  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0049ea86  32c0                 xor al, al
// 0049ea88  88442410             mov byte ptr [esp + 0x10], al
// 0049ea8c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0049ea90  8844240c             mov byte ptr [esp + 0xc], al
// 0049ea94  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0049ea98  50                   push eax
// 0049ea99  51                   push ecx
// 0049ea9a  52                   push edx
// 0049ea9b  57                   push edi
// 0049ea9c  56                   push esi
// 0049ea9d  53                   push ebx
// 0049ea9e  e8fdfeffff           call 0x49e9a0
// 0049eaa3  2bf3                 sub esi, ebx
// 0049eaa5  b8398ee338           mov eax, 0x38e38e39
// 0049eaaa  f7ee                 imul esi
// 0049eaac  c1fa03               sar edx, 3
// 0049eaaf  8bc2                 mov eax, edx
// 0049eab1  c1e81f               shr eax, 0x1f
// 0049eab4  03c2                 add eax, edx
// 0049eab6  8d04c0               lea eax, [eax + eax*8]
// 0049eab9  03c0                 add eax, eax
// 0049eabb  03c0                 add eax, eax
// 0049eabd  83c418               add esp, 0x18
// 0049eac0  8bc8                 mov ecx, eax
// 0049eac2  8bc7                 mov eax, edi
// 0049eac4  5f                   pop edi
// 0049eac5  5e                   pop esi
// 0049eac6  2bc1                 sub eax, ecx
// 0049eac8  5b                   pop ebx
// 0049eac9  83c408               add esp, 8
// 0049eacc  c3                   ret 
// library ogre-1.6.4/OgreBillboardChain.cpp (function ??$_Copy_backward_opt@PAVElement@BillboardChain@Ogre@@PAV123@@std@@YAPAVElement@BillboardChain@Ogre@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboardChain.cpp
