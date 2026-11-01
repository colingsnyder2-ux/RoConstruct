// from server: 100% by auto
// roc 2009-12 00444760  unit: VCRenderSettingsItem::?$FactoryProduct  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00444760
//
// 00444760  8b542408             mov edx, dword ptr [esp + 8]
// 00444764  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00444768  8bc2                 mov eax, edx
// 0044476a  2bc1                 sub eax, ecx
// 0044476c  56                   push esi
// 0044476d  8b742410             mov esi, dword ptr [esp + 0x10]
// 00444771  c1f802               sar eax, 2
// 00444774  8d0486               lea eax, [esi + eax*4]
// 00444777  3bca                 cmp ecx, edx
// 00444779  7412                 je 0x44478d
// 0044477b  2bf1                 sub esi, ecx
// 0044477d  57                   push edi
// 0044477e  8bff                 mov edi, edi
// 00444780  8b39                 mov edi, dword ptr [ecx]
// 00444782  893c0e               mov dword ptr [esi + ecx], edi
// 00444785  83c104               add ecx, 4
// 00444788  3bca                 cmp ecx, edx
// 0044478a  75f4                 jne 0x444780
// 0044478c  5f                   pop edi
// 0044478d  5e                   pop esi
// 0044478e  c3                   ret 
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ??$_Copy_opt@PAW4PixelFormat@Ogre@@PAW412@@std@@YAPAW4PixelFormat@Ogre@@PAW412@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
