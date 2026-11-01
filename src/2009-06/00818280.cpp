// from server: 100% by auto
// roc 2009-06 00818280  unit: CXTPDockingPaneAutoHidePanel  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00818280
//
// 00818280  83794400             cmp dword ptr [ecx + 0x44], 0
// 00818284  7503                 jne 0x818289
// 00818286  33c0                 xor eax, eax
// 00818288  c3                   ret 
// 00818289  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 0081828c  85c0                 test eax, eax
// 0081828e  7505                 jne 0x818295
// 00818290  e94f0af0ff           jmp 0x718ce4
// 00818295  8b4008               mov eax, dword ptr [eax + 8]
// 00818298  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?GetFirstPane@CXTPDockingPaneBaseContainer@@QBEPAVCXTPDockingPaneBase@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
