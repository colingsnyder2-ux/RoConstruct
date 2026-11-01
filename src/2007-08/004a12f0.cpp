// from server: 100% by auto
// roc 2007-08 004a12f0  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a12f0
//
// 004a12f0  83ec08               sub esp, 8
// 004a12f3  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a12f7  53                   push ebx
// 004a12f8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004a12fc  56                   push esi
// 004a12fd  8b742418             mov esi, dword ptr [esp + 0x18]
// 004a1301  57                   push edi
// 004a1302  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004a1306  32c0                 xor al, al
// 004a1308  88442410             mov byte ptr [esp + 0x10], al
// 004a130c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a1310  8844240c             mov byte ptr [esp + 0xc], al
// 004a1314  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004a1318  50                   push eax
// 004a1319  51                   push ecx
// 004a131a  52                   push edx
// 004a131b  57                   push edi
// 004a131c  56                   push esi
// 004a131d  53                   push ebx
// 004a131e  e8bdfcffff           call 0x4a0fe0
// 004a1323  2bf3                 sub esi, ebx
// 004a1325  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a132a  f7ee                 imul esi
// 004a132c  d1fa                 sar edx, 1
// 004a132e  8bc2                 mov eax, edx
// 004a1330  c1e81f               shr eax, 0x1f
// 004a1333  03c2                 add eax, edx
// 004a1335  8d0440               lea eax, [eax + eax*2]
// 004a1338  03c0                 add eax, eax
// 004a133a  03c0                 add eax, eax
// 004a133c  83c418               add esp, 0x18
// 004a133f  8bc8                 mov ecx, eax
// 004a1341  8bc7                 mov eax, edi
// 004a1343  5f                   pop edi
// 004a1344  5e                   pop esi
// 004a1345  2bc1                 sub eax, ecx
// 004a1347  5b                   pop ebx
// 004a1348  83c408               add esp, 8
// 004a134b  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Copy_backward_opt@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@@std@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
