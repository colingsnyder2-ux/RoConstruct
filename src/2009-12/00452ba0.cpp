// from server: 100% by auto
// roc 2009-12 00452ba0  unit: CRobloxControlColorSelector  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00452ba0
//
// 00452ba0  83ec08               sub esp, 8
// 00452ba3  8b542414             mov edx, dword ptr [esp + 0x14]
// 00452ba7  53                   push ebx
// 00452ba8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00452bac  56                   push esi
// 00452bad  8b742418             mov esi, dword ptr [esp + 0x18]
// 00452bb1  57                   push edi
// 00452bb2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00452bb6  32c0                 xor al, al
// 00452bb8  88442410             mov byte ptr [esp + 0x10], al
// 00452bbc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00452bc0  8844240c             mov byte ptr [esp + 0xc], al
// 00452bc4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00452bc8  50                   push eax
// 00452bc9  51                   push ecx
// 00452bca  52                   push edx
// 00452bcb  57                   push edi
// 00452bcc  56                   push esi
// 00452bcd  53                   push ebx
// 00452bce  e85dfaffff           call 0x452630
// 00452bd3  2bf3                 sub esi, ebx
// 00452bd5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00452bda  f7ee                 imul esi
// 00452bdc  d1fa                 sar edx, 1
// 00452bde  8bc2                 mov eax, edx
// 00452be0  c1e81f               shr eax, 0x1f
// 00452be3  03c2                 add eax, edx
// 00452be5  8d0440               lea eax, [eax + eax*2]
// 00452be8  03c0                 add eax, eax
// 00452bea  03c0                 add eax, eax
// 00452bec  83c418               add esp, 0x18
// 00452bef  8bc8                 mov ecx, eax
// 00452bf1  8bc7                 mov eax, edi
// 00452bf3  5f                   pop edi
// 00452bf4  5e                   pop esi
// 00452bf5  2bc1                 sub eax, ecx
// 00452bf7  5b                   pop ebx
// 00452bf8  83c408               add esp, 8
// 00452bfb  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
