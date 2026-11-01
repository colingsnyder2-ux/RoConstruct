// from server: 100% by auto
// roc 2009-06 007dfb10  unit: XTPDockingPanePaintThemes::CXTPDockingPaneVisualStudio2005SecondTheme  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007dfb10
//
// 007dfb10  8b442404             mov eax, dword ptr [esp + 4]
// 007dfb14  50                   push eax
// 007dfb15  e806ffffff           call 0x7dfa20
// 007dfb1a  83c404               add esp, 4
// 007dfb1d  85c0                 test eax, eax
// 007dfb1f  7508                 jne 0x7dfb29
// 007dfb21  b801000000           mov eax, 1
// 007dfb26  c20400               ret 4
// 007dfb29  8bc8                 mov ecx, eax
// 007dfb2b  e8d01bfaff           call 0x781700
// 007dfb30  83e001               and eax, 1
// 007dfb33  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?IsCaptionEnabled@CXTPDockingPanePaintManager@@QAEHPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
