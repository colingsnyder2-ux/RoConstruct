// from server: 100% by auto
// roc 2007-03 0044a9b0  unit: seg_00440000  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0044a9b0
//
// 0044a9b0  83ec08               sub esp, 8
// 0044a9b3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044a9b7  53                   push ebx
// 0044a9b8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0044a9bc  56                   push esi
// 0044a9bd  8b742418             mov esi, dword ptr [esp + 0x18]
// 0044a9c1  57                   push edi
// 0044a9c2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0044a9c6  32c0                 xor al, al
// 0044a9c8  88442410             mov byte ptr [esp + 0x10], al
// 0044a9cc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044a9d0  8844240c             mov byte ptr [esp + 0xc], al
// 0044a9d4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044a9d8  50                   push eax
// 0044a9d9  51                   push ecx
// 0044a9da  52                   push edx
// 0044a9db  57                   push edi
// 0044a9dc  56                   push esi
// 0044a9dd  53                   push ebx
// 0044a9de  e87df9ffff           call 0x44a360
// 0044a9e3  2bf3                 sub esi, ebx
// 0044a9e5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044a9ea  f7ee                 imul esi
// 0044a9ec  d1fa                 sar edx, 1
// 0044a9ee  8bc2                 mov eax, edx
// 0044a9f0  c1e81f               shr eax, 0x1f
// 0044a9f3  03c2                 add eax, edx
// 0044a9f5  8d0440               lea eax, [eax + eax*2]
// 0044a9f8  03c0                 add eax, eax
// 0044a9fa  03c0                 add eax, eax
// 0044a9fc  83c418               add esp, 0x18
// 0044a9ff  8bc8                 mov ecx, eax
// 0044aa01  8bc7                 mov eax, edi
// 0044aa03  5f                   pop edi
// 0044aa04  5e                   pop esi
// 0044aa05  2bc1                 sub eax, ecx
// 0044aa07  5b                   pop ebx
// 0044aa08  83c408               add esp, 8
// 0044aa0b  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
