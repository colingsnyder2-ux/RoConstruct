// from server: 100% by auto
// roc 2010-06 008fe670  unit: Ogre::RbxSceneUpdater  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fe670
//
// 008fe670  53                   push ebx
// 008fe671  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008fe675  55                   push ebp
// 008fe676  56                   push esi
// 008fe677  8b742410             mov esi, dword ptr [esp + 0x10]
// 008fe67b  57                   push edi
// 008fe67c  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 008fe680  8bc7                 mov eax, edi
// 008fe682  2bc6                 sub eax, esi
// 008fe684  c1f803               sar eax, 3
// 008fe687  8d2cc3               lea ebp, [ebx + eax*8]
// 008fe68a  3bf7                 cmp esi, edi
// 008fe68c  7412                 je 0x8fe6a0
// 008fe68e  2bde                 sub ebx, esi
// 008fe690  56                   push esi
// 008fe691  8d0c33               lea ecx, [ebx + esi]
// 008fe694  e8b726e2ff           call 0x720d50
// 008fe699  83c608               add esi, 8
// 008fe69c  3bf7                 cmp esi, edi
// 008fe69e  75f0                 jne 0x8fe690
// 008fe6a0  5f                   pop edi
// 008fe6a1  5e                   pop esi
// 008fe6a2  8bc5                 mov eax, ebp
// 008fe6a4  5d                   pop ebp
// 008fe6a5  5b                   pop ebx
// 008fe6a6  c3                   ret 
// library wildmagic-2-core/Containment\WmlContMinEllipseCR2.cpp (function ??$_Copy_opt@PAV?$Vector2@M@Wml@@PAV12@@std@@YAPAV?$Vector2@M@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContMinEllipseCR2.cpp
