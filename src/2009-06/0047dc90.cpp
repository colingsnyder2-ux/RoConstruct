// from server: 100% by auto
// roc 2009-06 0047dc90  unit: Ogre::RbxPart  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047dc90
//
// 0047dc90  53                   push ebx
// 0047dc91  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0047dc95  55                   push ebp
// 0047dc96  56                   push esi
// 0047dc97  8b742410             mov esi, dword ptr [esp + 0x10]
// 0047dc9b  57                   push edi
// 0047dc9c  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0047dca0  8bc7                 mov eax, edi
// 0047dca2  2bc6                 sub eax, esi
// 0047dca4  c1f803               sar eax, 3
// 0047dca7  8d2cc3               lea ebp, [ebx + eax*8]
// 0047dcaa  3bf7                 cmp esi, edi
// 0047dcac  7412                 je 0x47dcc0
// 0047dcae  2bde                 sub ebx, esi
// 0047dcb0  56                   push esi
// 0047dcb1  8d0c33               lea ecx, [ebx + esi]
// 0047dcb4  e8d72f1900           call 0x610c90
// 0047dcb9  83c608               add esi, 8
// 0047dcbc  3bf7                 cmp esi, edi
// 0047dcbe  75f0                 jne 0x47dcb0
// 0047dcc0  5f                   pop edi
// 0047dcc1  5e                   pop esi
// 0047dcc2  8bc5                 mov eax, ebp
// 0047dcc4  5d                   pop ebp
// 0047dcc5  5b                   pop ebx
// 0047dcc6  c3                   ret 
// library wildmagic-2-core/Containment\WmlContMinEllipseCR2.cpp (function ??$_Copy_opt@PAV?$Vector2@M@Wml@@PAV12@@std@@YAPAV?$Vector2@M@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContMinEllipseCR2.cpp
