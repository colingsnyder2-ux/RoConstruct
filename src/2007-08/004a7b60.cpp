// from server: 100% by auto
// roc 2007-08 004a7b60  unit: RBX::Network::Replicator::ChangePropertyItem  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a7b60
//
// 004a7b60  53                   push ebx
// 004a7b61  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004a7b65  55                   push ebp
// 004a7b66  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004a7b6a  56                   push esi
// 004a7b6b  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a7b6f  57                   push edi
// 004a7b70  8bfb                 mov edi, ebx
// 004a7b72  2bfe                 sub edi, esi
// 004a7b74  c1ff04               sar edi, 4
// 004a7b77  c1e704               shl edi, 4
// 004a7b7a  03fd                 add edi, ebp
// 004a7b7c  3bf3                 cmp esi, ebx
// 004a7b7e  7412                 je 0x4a7b92
// 004a7b80  2bee                 sub ebp, esi
// 004a7b82  56                   push esi
// 004a7b83  8d0c2e               lea ecx, [esi + ebp]
// 004a7b86  e865092800           call 0x7284f0
// 004a7b8b  83c610               add esi, 0x10
// 004a7b8e  3bf3                 cmp esi, ebx
// 004a7b90  75f0                 jne 0x4a7b82
// 004a7b92  8bc7                 mov eax, edi
// 004a7b94  5f                   pop edi
// 004a7b95  5e                   pop esi
// 004a7b96  5d                   pop ebp
// 004a7b97  5b                   pop ebx
// 004a7b98  c3                   ret 
// library wildmagic-2-core/Containment\WmlContMinEllipseCR2.cpp (function ??$_Copy_opt@PAV?$Vector2@N@Wml@@PAV12@@std@@YAPAV?$Vector2@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContMinEllipseCR2.cpp
