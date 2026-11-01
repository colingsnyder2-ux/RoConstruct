// from server: 100% by auto
// roc 2009-12 00534350  unit: RBX::Network::IdSerializer  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00534350
//
// 00534350  83ec08               sub esp, 8
// 00534353  8b542414             mov edx, dword ptr [esp + 0x14]
// 00534357  53                   push ebx
// 00534358  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0053435c  56                   push esi
// 0053435d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00534361  57                   push edi
// 00534362  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00534366  32c0                 xor al, al
// 00534368  88442410             mov byte ptr [esp + 0x10], al
// 0053436c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00534370  8844240c             mov byte ptr [esp + 0xc], al
// 00534374  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00534378  50                   push eax
// 00534379  51                   push ecx
// 0053437a  52                   push edx
// 0053437b  57                   push edi
// 0053437c  56                   push esi
// 0053437d  53                   push ebx
// 0053437e  e88dfbffff           call 0x533f10
// 00534383  2bf3                 sub esi, ebx
// 00534385  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053438a  f7ee                 imul esi
// 0053438c  d1fa                 sar edx, 1
// 0053438e  8bc2                 mov eax, edx
// 00534390  c1e81f               shr eax, 0x1f
// 00534393  03c2                 add eax, edx
// 00534395  8d0440               lea eax, [eax + eax*2]
// 00534398  03c0                 add eax, eax
// 0053439a  03c0                 add eax, eax
// 0053439c  83c418               add esp, 0x18
// 0053439f  8bc8                 mov ecx, eax
// 005343a1  8bc7                 mov eax, edi
// 005343a3  5f                   pop edi
// 005343a4  5e                   pop esi
// 005343a5  2bc1                 sub eax, ecx
// 005343a7  5b                   pop ebx
// 005343a8  83c408               add esp, 8
// 005343ab  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
