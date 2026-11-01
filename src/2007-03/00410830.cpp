// from server: 100% by auto
// roc 2007-03 00410830  unit: seg_00410000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00410830
//
// 00410830  83ec08               sub esp, 8
// 00410833  8b542414             mov edx, dword ptr [esp + 0x14]
// 00410837  53                   push ebx
// 00410838  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0041083c  56                   push esi
// 0041083d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00410841  57                   push edi
// 00410842  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00410846  32c0                 xor al, al
// 00410848  88442410             mov byte ptr [esp + 0x10], al
// 0041084c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00410850  8844240c             mov byte ptr [esp + 0xc], al
// 00410854  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00410858  50                   push eax
// 00410859  51                   push ecx
// 0041085a  52                   push edx
// 0041085b  57                   push edi
// 0041085c  56                   push esi
// 0041085d  53                   push ebx
// 0041085e  e86dfcffff           call 0x4104d0
// 00410863  2bf3                 sub esi, ebx
// 00410865  b8398ee338           mov eax, 0x38e38e39
// 0041086a  f7ee                 imul esi
// 0041086c  c1fa03               sar edx, 3
// 0041086f  8bc2                 mov eax, edx
// 00410871  c1e81f               shr eax, 0x1f
// 00410874  03c2                 add eax, edx
// 00410876  8d04c0               lea eax, [eax + eax*8]
// 00410879  03c0                 add eax, eax
// 0041087b  03c0                 add eax, eax
// 0041087d  83c418               add esp, 0x18
// 00410880  8bc8                 mov ecx, eax
// 00410882  8bc7                 mov eax, edi
// 00410884  5f                   pop edi
// 00410885  5e                   pop esi
// 00410886  2bc1                 sub eax, ecx
// 00410888  5b                   pop ebx
// 00410889  83c408               add esp, 8
// 0041088c  c3                   ret 
// library ogre-1.6.4/OgreBillboardChain.cpp (function ??$_Copy_backward_opt@PAVElement@BillboardChain@Ogre@@PAV123@@std@@YAPAVElement@BillboardChain@Ogre@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboardChain.cpp
