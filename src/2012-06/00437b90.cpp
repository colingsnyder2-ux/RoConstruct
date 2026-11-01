// from server: 100% by auto
// roc 2012-06 00437b90  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00437b90
//
// 00437b90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00437b94  8b542408             mov edx, dword ptr [esp + 8]
// 00437b98  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00437b9c  3bca                 cmp ecx, edx
// 00437b9e  7410                 je 0x437bb0
// 00437ba0  56                   push esi
// 00437ba1  8b31                 mov esi, dword ptr [ecx]
// 00437ba3  8930                 mov dword ptr [eax], esi
// 00437ba5  83c104               add ecx, 4
// 00437ba8  83c004               add eax, 4
// 00437bab  3bca                 cmp ecx, edx
// 00437bad  75f2                 jne 0x437ba1
// 00437baf  5e                   pop esi
// 00437bb0  c3                   ret 
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ??$_Copy_opt@PAW4PixelFormat@Ogre@@PAW412@Uforward_iterator_tag@std@@@std@@YAPAW4PixelFormat@Ogre@@PAW412@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
