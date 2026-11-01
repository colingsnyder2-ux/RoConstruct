// from server: 100% by auto
// roc 2007-08 004a8c30  unit: RBX::Network::VClient::?$FactoryProduct  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a8c30
//
// 004a8c30  53                   push ebx
// 004a8c31  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004a8c35  55                   push ebp
// 004a8c36  56                   push esi
// 004a8c37  8b742414             mov esi, dword ptr [esp + 0x14]
// 004a8c3b  57                   push edi
// 004a8c3c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004a8c40  8bc6                 mov eax, esi
// 004a8c42  2bc7                 sub eax, edi
// 004a8c44  c1f804               sar eax, 4
// 004a8c47  c1e004               shl eax, 4
// 004a8c4a  8beb                 mov ebp, ebx
// 004a8c4c  2be8                 sub ebp, eax
// 004a8c4e  3bfe                 cmp edi, esi
// 004a8c50  7412                 je 0x4a8c64
// 004a8c52  2bde                 sub ebx, esi
// 004a8c54  83ee10               sub esi, 0x10
// 004a8c57  56                   push esi
// 004a8c58  8d0c33               lea ecx, [ebx + esi]
// 004a8c5b  e890f82700           call 0x7284f0
// 004a8c60  3bf7                 cmp esi, edi
// 004a8c62  75f0                 jne 0x4a8c54
// 004a8c64  5f                   pop edi
// 004a8c65  5e                   pop esi
// 004a8c66  8bc5                 mov eax, ebp
// 004a8c68  5d                   pop ebp
// 004a8c69  5b                   pop ebx
// 004a8c6a  c3                   ret 
// library ogre-1.7.0/OgreScriptLexer.cpp (function ??$_Copy_backward_opt@PAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@PAV12@@std@@YAPAV?$SharedPtr@UScriptToken@Ogre@@@Ogre@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptLexer.cpp
