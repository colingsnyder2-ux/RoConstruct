// from server: 100% by auto
// roc 2009-06 0044c580  unit: CRobloxControlColorSelector  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044c580
//
// 0044c580  83ec08               sub esp, 8
// 0044c583  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044c587  53                   push ebx
// 0044c588  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0044c58c  56                   push esi
// 0044c58d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0044c591  57                   push edi
// 0044c592  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0044c596  32c0                 xor al, al
// 0044c598  88442410             mov byte ptr [esp + 0x10], al
// 0044c59c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044c5a0  8844240c             mov byte ptr [esp + 0xc], al
// 0044c5a4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044c5a8  50                   push eax
// 0044c5a9  51                   push ecx
// 0044c5aa  52                   push edx
// 0044c5ab  57                   push edi
// 0044c5ac  56                   push esi
// 0044c5ad  53                   push ebx
// 0044c5ae  e85dfaffff           call 0x44c010
// 0044c5b3  2bf3                 sub esi, ebx
// 0044c5b5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044c5ba  f7ee                 imul esi
// 0044c5bc  d1fa                 sar edx, 1
// 0044c5be  8bc2                 mov eax, edx
// 0044c5c0  c1e81f               shr eax, 0x1f
// 0044c5c3  03c2                 add eax, edx
// 0044c5c5  8d0440               lea eax, [eax + eax*2]
// 0044c5c8  03c0                 add eax, eax
// 0044c5ca  03c0                 add eax, eax
// 0044c5cc  83c418               add esp, 0x18
// 0044c5cf  8bc8                 mov ecx, eax
// 0044c5d1  8bc7                 mov eax, edi
// 0044c5d3  5f                   pop edi
// 0044c5d4  5e                   pop esi
// 0044c5d5  2bc1                 sub eax, ecx
// 0044c5d7  5b                   pop ebx
// 0044c5d8  83c408               add esp, 8
// 0044c5db  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
