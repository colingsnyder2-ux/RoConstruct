// from server: 100% by auto
// roc 2008-06 004a7340  unit: RBX::VHint::?$FactoryProduct::Creator  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a7340
//
// 004a7340  83ec08               sub esp, 8
// 004a7343  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a7347  53                   push ebx
// 004a7348  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004a734c  56                   push esi
// 004a734d  8b742418             mov esi, dword ptr [esp + 0x18]
// 004a7351  57                   push edi
// 004a7352  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004a7356  32c0                 xor al, al
// 004a7358  88442410             mov byte ptr [esp + 0x10], al
// 004a735c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a7360  8844240c             mov byte ptr [esp + 0xc], al
// 004a7364  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004a7368  50                   push eax
// 004a7369  51                   push ecx
// 004a736a  52                   push edx
// 004a736b  57                   push edi
// 004a736c  56                   push esi
// 004a736d  53                   push ebx
// 004a736e  e86dfbffff           call 0x4a6ee0
// 004a7373  2bf3                 sub esi, ebx
// 004a7375  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a737a  f7ee                 imul esi
// 004a737c  d1fa                 sar edx, 1
// 004a737e  8bc2                 mov eax, edx
// 004a7380  c1e81f               shr eax, 0x1f
// 004a7383  03c2                 add eax, edx
// 004a7385  8d0440               lea eax, [eax + eax*2]
// 004a7388  03c0                 add eax, eax
// 004a738a  03c0                 add eax, eax
// 004a738c  83c418               add esp, 0x18
// 004a738f  8bc8                 mov ecx, eax
// 004a7391  8bc7                 mov eax, edi
// 004a7393  5f                   pop edi
// 004a7394  5e                   pop esi
// 004a7395  2bc1                 sub eax, ecx
// 004a7397  5b                   pop ebx
// 004a7398  83c408               add esp, 8
// 004a739b  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
