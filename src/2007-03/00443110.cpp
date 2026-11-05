// from server: 100% by auto
// roc 2007-03 00443110  unit: seg_00440000  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00443110
//
// 00443110  83ec08               sub esp, 8
// 00443113  8b542414             mov edx, dword ptr [esp + 0x14]
// 00443117  53                   push ebx
// 00443118  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0044311c  56                   push esi
// 0044311d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00443121  57                   push edi
// 00443122  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00443126  32c0                 xor al, al
// 00443128  88442410             mov byte ptr [esp + 0x10], al
// 0044312c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00443130  8844240c             mov byte ptr [esp + 0xc], al
// 00443134  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00443138  50                   push eax
// 00443139  51                   push ecx
// 0044313a  52                   push edx
// 0044313b  57                   push edi
// 0044313c  56                   push esi
// 0044313d  53                   push ebx
// 0044313e  e87dfeffff           call 0x442fc0
// 00443143  2bf3                 sub esi, ebx
// 00443145  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044314a  f7ee                 imul esi
// 0044314c  d1fa                 sar edx, 1
// 0044314e  8bc2                 mov eax, edx
// 00443150  c1e81f               shr eax, 0x1f
// 00443153  03c2                 add eax, edx
// 00443155  8d0440               lea eax, [eax + eax*2]
// 00443158  03c0                 add eax, eax
// 0044315a  03c0                 add eax, eax
// 0044315c  83c418               add esp, 0x18
// 0044315f  8bc8                 mov ecx, eax
// 00443161  8bc7                 mov eax, edi
// 00443163  5f                   pop edi
// 00443164  5e                   pop esi
// 00443165  2bc1                 sub eax, ecx
// 00443167  5b                   pop ebx
// 00443168  83c408               add esp, 8
// 0044316b  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
