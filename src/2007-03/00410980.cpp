// from server: 100% by auto
// roc 2007-03 00410980  unit: seg_00410000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00410980
//
// 00410980  83ec08               sub esp, 8
// 00410983  8b542414             mov edx, dword ptr [esp + 0x14]
// 00410987  53                   push ebx
// 00410988  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0041098c  56                   push esi
// 0041098d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00410991  57                   push edi
// 00410992  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00410996  32c0                 xor al, al
// 00410998  88442410             mov byte ptr [esp + 0x10], al
// 0041099c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004109a0  8844240c             mov byte ptr [esp + 0xc], al
// 004109a4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004109a8  50                   push eax
// 004109a9  51                   push ecx
// 004109aa  52                   push edx
// 004109ab  57                   push edi
// 004109ac  56                   push esi
// 004109ad  53                   push ebx
// 004109ae  e86dfaffff           call 0x410420
// 004109b3  2bf3                 sub esi, ebx
// 004109b5  b8398ee338           mov eax, 0x38e38e39
// 004109ba  f7ee                 imul esi
// 004109bc  c1fa03               sar edx, 3
// 004109bf  83c418               add esp, 0x18
// 004109c2  8bc2                 mov eax, edx
// 004109c4  c1e81f               shr eax, 0x1f
// 004109c7  03c2                 add eax, edx
// 004109c9  8d04c0               lea eax, [eax + eax*8]
// 004109cc  8d0487               lea eax, [edi + eax*4]
// 004109cf  5f                   pop edi
// 004109d0  5e                   pop esi
// 004109d1  5b                   pop ebx
// 004109d2  83c408               add esp, 8
// 004109d5  c3                   ret 
// library ogre-1.6.4/OgreBillboardChain.cpp (function ??$_Copy_opt@PAVElement@BillboardChain@Ogre@@PAV123@@std@@YAPAVElement@BillboardChain@Ogre@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreBillboardChain.cpp
