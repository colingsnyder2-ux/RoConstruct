// from server: 100% by auto
// roc 2011-06 004324b0  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004324b0
//
// 004324b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004324b4  8b542408             mov edx, dword ptr [esp + 8]
// 004324b8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004324bc  3bca                 cmp ecx, edx
// 004324be  7410                 je 0x4324d0
// 004324c0  56                   push esi
// 004324c1  8b31                 mov esi, dword ptr [ecx]
// 004324c3  8930                 mov dword ptr [eax], esi
// 004324c5  83c104               add ecx, 4
// 004324c8  83c004               add eax, 4
// 004324cb  3bca                 cmp ecx, edx
// 004324cd  75f2                 jne 0x4324c1
// 004324cf  5e                   pop esi
// 004324d0  c3                   ret 
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ??$_Copy_opt@PAW4PixelFormat@Ogre@@PAW412@Uforward_iterator_tag@std@@@std@@YAPAW4PixelFormat@Ogre@@PAW412@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
