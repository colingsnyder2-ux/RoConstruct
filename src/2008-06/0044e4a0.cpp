// from server: 100% by auto
// roc 2008-06 0044e4a0  unit: CRobloxControlColorSelector  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044e4a0
//
// 0044e4a0  83ec08               sub esp, 8
// 0044e4a3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044e4a7  53                   push ebx
// 0044e4a8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0044e4ac  56                   push esi
// 0044e4ad  8b742418             mov esi, dword ptr [esp + 0x18]
// 0044e4b1  57                   push edi
// 0044e4b2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0044e4b6  32c0                 xor al, al
// 0044e4b8  88442410             mov byte ptr [esp + 0x10], al
// 0044e4bc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044e4c0  8844240c             mov byte ptr [esp + 0xc], al
// 0044e4c4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044e4c8  50                   push eax
// 0044e4c9  51                   push ecx
// 0044e4ca  52                   push edx
// 0044e4cb  57                   push edi
// 0044e4cc  56                   push esi
// 0044e4cd  53                   push ebx
// 0044e4ce  e80dfaffff           call 0x44dee0
// 0044e4d3  2bf3                 sub esi, ebx
// 0044e4d5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044e4da  f7ee                 imul esi
// 0044e4dc  d1fa                 sar edx, 1
// 0044e4de  8bc2                 mov eax, edx
// 0044e4e0  c1e81f               shr eax, 0x1f
// 0044e4e3  03c2                 add eax, edx
// 0044e4e5  8d0440               lea eax, [eax + eax*2]
// 0044e4e8  03c0                 add eax, eax
// 0044e4ea  03c0                 add eax, eax
// 0044e4ec  83c418               add esp, 0x18
// 0044e4ef  8bc8                 mov ecx, eax
// 0044e4f1  8bc7                 mov eax, edi
// 0044e4f3  5f                   pop edi
// 0044e4f4  5e                   pop esi
// 0044e4f5  2bc1                 sub eax, ecx
// 0044e4f7  5b                   pop ebx
// 0044e4f8  83c408               add esp, 8
// 0044e4fb  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
