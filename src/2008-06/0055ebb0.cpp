// from server: 100% by auto
// roc 2008-06 0055ebb0  unit: RBX::MD5HasherImpl  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055ebb0
//
// 0055ebb0  53                   push ebx
// 0055ebb1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0055ebb5  55                   push ebp
// 0055ebb6  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0055ebba  56                   push esi
// 0055ebbb  8b742410             mov esi, dword ptr [esp + 0x10]
// 0055ebbf  57                   push edi
// 0055ebc0  8bfb                 mov edi, ebx
// 0055ebc2  2bfe                 sub edi, esi
// 0055ebc4  c1ff05               sar edi, 5
// 0055ebc7  c1e705               shl edi, 5
// 0055ebca  03fd                 add edi, ebp
// 0055ebcc  3bf3                 cmp esi, ebx
// 0055ebce  7412                 je 0x55ebe2
// 0055ebd0  2bee                 sub ebp, esi
// 0055ebd2  56                   push esi
// 0055ebd3  8d0c2e               lea ecx, [esi + ebp]
// 0055ebd6  e8b563ffff           call 0x554f90
// 0055ebdb  83c620               add esi, 0x20
// 0055ebde  3bf3                 cmp esi, ebx
// 0055ebe0  75f0                 jne 0x55ebd2
// 0055ebe2  8bc7                 mov eax, edi
// 0055ebe4  5f                   pop edi
// 0055ebe5  5e                   pop esi
// 0055ebe6  5d                   pop ebp
// 0055ebe7  5b                   pop ebx
// 0055ebe8  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ??$_Copy_opt@PAV?$Plane3@N@Wml@@PAV12@@std@@YAPAV?$Plane3@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
