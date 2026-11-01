// from server: 100% by auto
// roc 2009-12 004aad90  unit: Ogre::RbxSceneUpdater  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aad90
//
// 004aad90  53                   push ebx
// 004aad91  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004aad95  55                   push ebp
// 004aad96  56                   push esi
// 004aad97  8b742410             mov esi, dword ptr [esp + 0x10]
// 004aad9b  57                   push edi
// 004aad9c  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004aada0  8bc7                 mov eax, edi
// 004aada2  2bc6                 sub eax, esi
// 004aada4  c1f803               sar eax, 3
// 004aada7  8d2cc3               lea ebp, [ebx + eax*8]
// 004aadaa  3bf7                 cmp esi, edi
// 004aadac  7412                 je 0x4aadc0
// 004aadae  2bde                 sub ebx, esi
// 004aadb0  56                   push esi
// 004aadb1  8d0c33               lea ecx, [ebx + esi]
// 004aadb4  e8c70c0d00           call 0x57ba80
// 004aadb9  83c608               add esi, 8
// 004aadbc  3bf7                 cmp esi, edi
// 004aadbe  75f0                 jne 0x4aadb0
// 004aadc0  5f                   pop edi
// 004aadc1  5e                   pop esi
// 004aadc2  8bc5                 mov eax, ebp
// 004aadc4  5d                   pop ebp
// 004aadc5  5b                   pop ebx
// 004aadc6  c3                   ret 
// library wildmagic-2-core/Containment\WmlContMinEllipseCR2.cpp (function ??$_Copy_opt@PAV?$Vector2@M@Wml@@PAV12@@std@@YAPAV?$Vector2@M@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContMinEllipseCR2.cpp
