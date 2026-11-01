// from server: 100% by auto
// roc 2010-06 00445a90  unit: VCRenderSettingsItem::?$FactoryProduct  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00445a90
//
// 00445a90  8b542408             mov edx, dword ptr [esp + 8]
// 00445a94  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00445a98  8bc2                 mov eax, edx
// 00445a9a  2bc1                 sub eax, ecx
// 00445a9c  56                   push esi
// 00445a9d  8b742410             mov esi, dword ptr [esp + 0x10]
// 00445aa1  c1f802               sar eax, 2
// 00445aa4  8d0486               lea eax, [esi + eax*4]
// 00445aa7  3bca                 cmp ecx, edx
// 00445aa9  7412                 je 0x445abd
// 00445aab  2bf1                 sub esi, ecx
// 00445aad  57                   push edi
// 00445aae  8bff                 mov edi, edi
// 00445ab0  8b39                 mov edi, dword ptr [ecx]
// 00445ab2  893c0e               mov dword ptr [esi + ecx], edi
// 00445ab5  83c104               add ecx, 4
// 00445ab8  3bca                 cmp ecx, edx
// 00445aba  75f4                 jne 0x445ab0
// 00445abc  5f                   pop edi
// 00445abd  5e                   pop esi
// 00445abe  c3                   ret 
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ??$_Copy_opt@PAW4PixelFormat@Ogre@@PAW412@@std@@YAPAW4PixelFormat@Ogre@@PAW412@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
