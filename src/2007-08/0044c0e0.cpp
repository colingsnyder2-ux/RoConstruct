// from server: 100% by auto
// roc 2007-08 0044c0e0  unit: CRobloxControlColorSelector  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044c0e0
//
// 0044c0e0  83ec08               sub esp, 8
// 0044c0e3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044c0e7  53                   push ebx
// 0044c0e8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0044c0ec  56                   push esi
// 0044c0ed  8b742418             mov esi, dword ptr [esp + 0x18]
// 0044c0f1  57                   push edi
// 0044c0f2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0044c0f6  32c0                 xor al, al
// 0044c0f8  88442410             mov byte ptr [esp + 0x10], al
// 0044c0fc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044c100  8844240c             mov byte ptr [esp + 0xc], al
// 0044c104  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044c108  50                   push eax
// 0044c109  51                   push ecx
// 0044c10a  52                   push edx
// 0044c10b  57                   push edi
// 0044c10c  56                   push esi
// 0044c10d  53                   push ebx
// 0044c10e  e8ddf9ffff           call 0x44baf0
// 0044c113  2bf3                 sub esi, ebx
// 0044c115  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044c11a  f7ee                 imul esi
// 0044c11c  d1fa                 sar edx, 1
// 0044c11e  8bc2                 mov eax, edx
// 0044c120  c1e81f               shr eax, 0x1f
// 0044c123  03c2                 add eax, edx
// 0044c125  8d0440               lea eax, [eax + eax*2]
// 0044c128  03c0                 add eax, eax
// 0044c12a  03c0                 add eax, eax
// 0044c12c  83c418               add esp, 0x18
// 0044c12f  8bc8                 mov ecx, eax
// 0044c131  8bc7                 mov eax, edi
// 0044c133  5f                   pop edi
// 0044c134  5e                   pop esi
// 0044c135  2bc1                 sub eax, ecx
// 0044c137  5b                   pop ebx
// 0044c138  83c408               add esp, 8
// 0044c13b  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
