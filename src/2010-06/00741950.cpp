// from server: 100% by auto
// roc 2010-06 00741950  unit: RBX::VHttp::?$sp_counted_impl_p  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00741950
//
// 00741950  83ec08               sub esp, 8
// 00741953  8b542414             mov edx, dword ptr [esp + 0x14]
// 00741957  53                   push ebx
// 00741958  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0074195c  56                   push esi
// 0074195d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00741961  57                   push edi
// 00741962  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00741966  32c0                 xor al, al
// 00741968  88442410             mov byte ptr [esp + 0x10], al
// 0074196c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00741970  8844240c             mov byte ptr [esp + 0xc], al
// 00741974  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00741978  50                   push eax
// 00741979  51                   push ecx
// 0074197a  52                   push edx
// 0074197b  57                   push edi
// 0074197c  56                   push esi
// 0074197d  53                   push ebx
// 0074197e  e8cdf9ffff           call 0x741350
// 00741983  2bf3                 sub esi, ebx
// 00741985  b867666666           mov eax, 0x66666667
// 0074198a  f7ee                 imul esi
// 0074198c  c1fa04               sar edx, 4
// 0074198f  8bc2                 mov eax, edx
// 00741991  c1e81f               shr eax, 0x1f
// 00741994  03c2                 add eax, edx
// 00741996  8d0480               lea eax, [eax + eax*4]
// 00741999  03c0                 add eax, eax
// 0074199b  03c0                 add eax, eax
// 0074199d  03c0                 add eax, eax
// 0074199f  83c418               add esp, 0x18
// 007419a2  8bc8                 mov ecx, eax
// 007419a4  8bc7                 mov eax, edi
// 007419a6  5f                   pop edi
// 007419a7  5e                   pop esi
// 007419a8  2bc1                 sub eax, ecx
// 007419aa  5b                   pop ebx
// 007419ab  83c408               add esp, 8
// 007419ae  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Copy_backward_opt@PAUEdgeGroup@EdgeData@Ogre@@PAU123@@std@@YAPAUEdgeGroup@EdgeData@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
