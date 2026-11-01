// from server: 100% by auto
// roc 2007-08 0061e2e0  unit: RBX::ScoreHud  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061e2e0
//
// 0061e2e0  53                   push ebx
// 0061e2e1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0061e2e5  55                   push ebp
// 0061e2e6  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0061e2ea  56                   push esi
// 0061e2eb  8b742410             mov esi, dword ptr [esp + 0x10]
// 0061e2ef  57                   push edi
// 0061e2f0  8bfb                 mov edi, ebx
// 0061e2f2  2bfe                 sub edi, esi
// 0061e2f4  c1ff04               sar edi, 4
// 0061e2f7  c1e704               shl edi, 4
// 0061e2fa  03fd                 add edi, ebp
// 0061e2fc  3bf3                 cmp esi, ebx
// 0061e2fe  7412                 je 0x61e312
// 0061e300  2bee                 sub ebp, esi
// 0061e302  56                   push esi
// 0061e303  8d0c2e               lea ecx, [esi + ebp]
// 0061e306  e835bae6ff           call 0x489d40
// 0061e30b  83c610               add esi, 0x10
// 0061e30e  3bf3                 cmp esi, ebx
// 0061e310  75f0                 jne 0x61e302
// 0061e312  8bc7                 mov eax, edi
// 0061e314  5f                   pop edi
// 0061e315  5e                   pop esi
// 0061e316  5d                   pop ebp
// 0061e317  5b                   pop ebx
// 0061e318  c3                   ret 
// library wildmagic-2-core/Containment\WmlContMinEllipseCR2.cpp (function ??$_Copy_opt@PAV?$Vector2@N@Wml@@PAV12@@std@@YAPAV?$Vector2@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContMinEllipseCR2.cpp
