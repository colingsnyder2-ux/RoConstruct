// from server: 100% by auto
// roc 2009-06 004de320  unit: RBX::Network::IdSerializer  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004de320
//
// 004de320  83ec08               sub esp, 8
// 004de323  8b542414             mov edx, dword ptr [esp + 0x14]
// 004de327  53                   push ebx
// 004de328  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004de32c  56                   push esi
// 004de32d  8b742418             mov esi, dword ptr [esp + 0x18]
// 004de331  57                   push edi
// 004de332  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004de336  32c0                 xor al, al
// 004de338  88442410             mov byte ptr [esp + 0x10], al
// 004de33c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004de340  8844240c             mov byte ptr [esp + 0xc], al
// 004de344  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004de348  50                   push eax
// 004de349  51                   push ecx
// 004de34a  52                   push edx
// 004de34b  57                   push edi
// 004de34c  56                   push esi
// 004de34d  53                   push ebx
// 004de34e  e87dfbffff           call 0x4dded0
// 004de353  2bf3                 sub esi, ebx
// 004de355  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004de35a  f7ee                 imul esi
// 004de35c  d1fa                 sar edx, 1
// 004de35e  8bc2                 mov eax, edx
// 004de360  c1e81f               shr eax, 0x1f
// 004de363  03c2                 add eax, edx
// 004de365  8d0440               lea eax, [eax + eax*2]
// 004de368  03c0                 add eax, eax
// 004de36a  03c0                 add eax, eax
// 004de36c  83c418               add esp, 0x18
// 004de36f  8bc8                 mov ecx, eax
// 004de371  8bc7                 mov eax, edi
// 004de373  5f                   pop edi
// 004de374  5e                   pop esi
// 004de375  2bc1                 sub eax, ecx
// 004de377  5b                   pop ebx
// 004de378  83c408               add esp, 8
// 004de37b  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
