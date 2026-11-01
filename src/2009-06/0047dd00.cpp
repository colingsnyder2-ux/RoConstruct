// from server: 100% by auto
// roc 2009-06 0047dd00  unit: Ogre::RbxPart  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047dd00
//
// 0047dd00  53                   push ebx
// 0047dd01  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0047dd05  55                   push ebp
// 0047dd06  56                   push esi
// 0047dd07  8b742414             mov esi, dword ptr [esp + 0x14]
// 0047dd0b  57                   push edi
// 0047dd0c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0047dd10  8bc6                 mov eax, esi
// 0047dd12  2bc7                 sub eax, edi
// 0047dd14  c1f803               sar eax, 3
// 0047dd17  03c0                 add eax, eax
// 0047dd19  03c0                 add eax, eax
// 0047dd1b  03c0                 add eax, eax
// 0047dd1d  8beb                 mov ebp, ebx
// 0047dd1f  2be8                 sub ebp, eax
// 0047dd21  3bfe                 cmp edi, esi
// 0047dd23  7412                 je 0x47dd37
// 0047dd25  2bde                 sub ebx, esi
// 0047dd27  83ee08               sub esi, 8
// 0047dd2a  56                   push esi
// 0047dd2b  8d0c33               lea ecx, [ebx + esi]
// 0047dd2e  e85d2f1900           call 0x610c90
// 0047dd33  3bf7                 cmp esi, edi
// 0047dd35  75f0                 jne 0x47dd27
// 0047dd37  5f                   pop edi
// 0047dd38  5e                   pop esi
// 0047dd39  8bc5                 mov eax, ebp
// 0047dd3b  5d                   pop ebp
// 0047dd3c  5b                   pop ebx
// 0047dd3d  c3                   ret 
// library wildmagic-2-core/Containment\WmlContMinEllipseCR2.cpp (function ??$_Copy_backward_opt@PAV?$Vector2@M@Wml@@PAV12@@std@@YAPAV?$Vector2@M@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContMinEllipseCR2.cpp
