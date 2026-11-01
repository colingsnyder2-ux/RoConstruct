// from server: 100% by auto
// roc 2010-06 00454fd0  unit: CRobloxControlColorSelector  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00454fd0
//
// 00454fd0  83ec08               sub esp, 8
// 00454fd3  8b542414             mov edx, dword ptr [esp + 0x14]
// 00454fd7  53                   push ebx
// 00454fd8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00454fdc  56                   push esi
// 00454fdd  8b742418             mov esi, dword ptr [esp + 0x18]
// 00454fe1  57                   push edi
// 00454fe2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00454fe6  32c0                 xor al, al
// 00454fe8  88442410             mov byte ptr [esp + 0x10], al
// 00454fec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00454ff0  8844240c             mov byte ptr [esp + 0xc], al
// 00454ff4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00454ff8  50                   push eax
// 00454ff9  51                   push ecx
// 00454ffa  52                   push edx
// 00454ffb  57                   push edi
// 00454ffc  56                   push esi
// 00454ffd  53                   push ebx
// 00454ffe  e8adf8ffff           call 0x4548b0
// 00455003  2bf3                 sub esi, ebx
// 00455005  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0045500a  f7ee                 imul esi
// 0045500c  d1fa                 sar edx, 1
// 0045500e  8bc2                 mov eax, edx
// 00455010  c1e81f               shr eax, 0x1f
// 00455013  03c2                 add eax, edx
// 00455015  8d0440               lea eax, [eax + eax*2]
// 00455018  03c0                 add eax, eax
// 0045501a  03c0                 add eax, eax
// 0045501c  83c418               add esp, 0x18
// 0045501f  8bc8                 mov ecx, eax
// 00455021  8bc7                 mov eax, edi
// 00455023  5f                   pop edi
// 00455024  5e                   pop esi
// 00455025  2bc1                 sub eax, ecx
// 00455027  5b                   pop ebx
// 00455028  83c408               add esp, 8
// 0045502b  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
