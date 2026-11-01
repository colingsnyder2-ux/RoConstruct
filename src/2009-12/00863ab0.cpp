// from server: 100% by auto
// roc 2009-12 00863ab0  unit: CXTPToolTipContextToolTip  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00863ab0
//
// 00863ab0  8b442404             mov eax, dword ptr [esp + 4]
// 00863ab4  50                   push eax
// 00863ab5  e8866dfeff           call 0x84a840
// 00863aba  83c404               add esp, 4
// 00863abd  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\appui2.cpp (function ??2CObject@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui2.cpp
