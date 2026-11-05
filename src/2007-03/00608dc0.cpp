// from server: 100% by auto
// roc 2007-03 00608dc0  unit: seg_00600000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00608dc0
//
// 00608dc0  53                   push ebx
// 00608dc1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00608dc5  55                   push ebp
// 00608dc6  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00608dca  56                   push esi
// 00608dcb  8b742410             mov esi, dword ptr [esp + 0x10]
// 00608dcf  57                   push edi
// 00608dd0  8bfb                 mov edi, ebx
// 00608dd2  2bfe                 sub edi, esi
// 00608dd4  c1ff04               sar edi, 4
// 00608dd7  c1e704               shl edi, 4
// 00608dda  03fd                 add edi, ebp
// 00608ddc  3bf3                 cmp esi, ebx
// 00608dde  7412                 je 0x608df2
// 00608de0  2bee                 sub ebp, esi
// 00608de2  56                   push esi
// 00608de3  8d0c2e               lea ecx, [esi + ebp]
// 00608de6  e8b5fbffff           call 0x6089a0
// 00608deb  83c610               add esi, 0x10
// 00608dee  3bf3                 cmp esi, ebx
// 00608df0  75f0                 jne 0x608de2
// 00608df2  8bc7                 mov eax, edi
// 00608df4  5f                   pop edi
// 00608df5  5e                   pop esi
// 00608df6  5d                   pop ebp
// 00608df7  5b                   pop ebx
// 00608df8  c3                   ret 
// library wildmagic-2-core/Containment\WmlContMinEllipseCR2.cpp (function ??$_Copy_opt@PAV?$Vector2@N@Wml@@PAV12@@std@@YAPAV?$Vector2@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContMinEllipseCR2.cpp
