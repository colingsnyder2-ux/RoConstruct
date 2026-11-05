// from server: 100% by auto
// roc 2009-06 005dbb50  unit: RBX::VInstance::?$NonFactoryProduct  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005dbb50
//
// 005dbb50  53                   push ebx
// 005dbb51  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005dbb55  55                   push ebp
// 005dbb56  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005dbb5a  56                   push esi
// 005dbb5b  8b742410             mov esi, dword ptr [esp + 0x10]
// 005dbb5f  57                   push edi
// 005dbb60  8bfb                 mov edi, ebx
// 005dbb62  2bfe                 sub edi, esi
// 005dbb64  c1ff05               sar edi, 5
// 005dbb67  c1e705               shl edi, 5
// 005dbb6a  03fd                 add edi, ebp
// 005dbb6c  3bf3                 cmp esi, ebx
// 005dbb6e  7412                 je 0x5dbb82
// 005dbb70  2bee                 sub ebp, esi
// 005dbb72  56                   push esi
// 005dbb73  8d0c2e               lea ecx, [esi + ebp]
// 005dbb76  e835f1ffff           call 0x5dacb0
// 005dbb7b  83c620               add esi, 0x20
// 005dbb7e  3bf3                 cmp esi, ebx
// 005dbb80  75f0                 jne 0x5dbb72
// 005dbb82  8bc7                 mov eax, edi
// 005dbb84  5f                   pop edi
// 005dbb85  5e                   pop esi
// 005dbb86  5d                   pop ebp
// 005dbb87  5b                   pop ebx
// 005dbb88  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ??$_Copy_opt@PAV?$Plane3@N@Wml@@PAV12@@std@@YAPAV?$Plane3@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
