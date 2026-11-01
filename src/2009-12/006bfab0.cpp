// from server: 100% by auto
// roc 2009-12 006bfab0  unit: RBX::VInstance::?$NonFactoryProduct  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bfab0
//
// 006bfab0  53                   push ebx
// 006bfab1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 006bfab5  55                   push ebp
// 006bfab6  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 006bfaba  56                   push esi
// 006bfabb  8b742410             mov esi, dword ptr [esp + 0x10]
// 006bfabf  57                   push edi
// 006bfac0  8bfb                 mov edi, ebx
// 006bfac2  2bfe                 sub edi, esi
// 006bfac4  c1ff05               sar edi, 5
// 006bfac7  c1e705               shl edi, 5
// 006bfaca  03fd                 add edi, ebp
// 006bfacc  3bf3                 cmp esi, ebx
// 006bface  7412                 je 0x6bfae2
// 006bfad0  2bee                 sub ebp, esi
// 006bfad2  56                   push esi
// 006bfad3  8d0c2e               lea ecx, [esi + ebp]
// 006bfad6  e825400400           call 0x703b00
// 006bfadb  83c620               add esi, 0x20
// 006bfade  3bf3                 cmp esi, ebx
// 006bfae0  75f0                 jne 0x6bfad2
// 006bfae2  8bc7                 mov eax, edi
// 006bfae4  5f                   pop edi
// 006bfae5  5e                   pop esi
// 006bfae6  5d                   pop ebp
// 006bfae7  5b                   pop ebx
// 006bfae8  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ??$_Copy_opt@PAV?$Plane3@N@Wml@@PAV12@@std@@YAPAV?$Plane3@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
