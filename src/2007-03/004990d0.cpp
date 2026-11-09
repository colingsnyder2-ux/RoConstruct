// from server: 100% by auto
// roc 2007-03 004990d0  unit: seg_00490000  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004990d0
//
// 004990d0  83ec08               sub esp, 8
// 004990d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 004990d7  53                   push ebx
// 004990d8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004990dc  56                   push esi
// 004990dd  8b742418             mov esi, dword ptr [esp + 0x18]
// 004990e1  57                   push edi
// 004990e2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004990e6  32c0                 xor al, al
// 004990e8  88442410             mov byte ptr [esp + 0x10], al
// 004990ec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004990f0  8844240c             mov byte ptr [esp + 0xc], al
// 004990f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004990f8  50                   push eax
// 004990f9  51                   push ecx
// 004990fa  52                   push edx
// 004990fb  57                   push edi
// 004990fc  56                   push esi
// 004990fd  53                   push ebx
// 004990fe  e8adfdffff           call 0x498eb0
// 00499103  2bf3                 sub esi, ebx
// 00499105  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0049910a  f7ee                 imul esi
// 0049910c  d1fa                 sar edx, 1
// 0049910e  8bc2                 mov eax, edx
// 00499110  c1e81f               shr eax, 0x1f
// 00499113  03c2                 add eax, edx
// 00499115  8d0440               lea eax, [eax + eax*2]
// 00499118  03c0                 add eax, eax
// 0049911a  03c0                 add eax, eax
// 0049911c  83c418               add esp, 0x18
// 0049911f  8bc8                 mov ecx, eax
// 00499121  8bc7                 mov eax, edi
// 00499123  5f                   pop edi
// 00499124  5e                   pop esi
// 00499125  2bc1                 sub eax, ecx
// 00499127  5b                   pop ebx
// 00499128  83c408               add esp, 8
// 0049912b  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
