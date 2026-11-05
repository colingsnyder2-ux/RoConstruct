// from server: 100% by auto
// roc 2010-06 0086e780  unit: XTPDockingPanePaintThemes::CXTPDockingPaneVisualStudio2005SecondTheme  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0086e780
//
// 0086e780  8b442404             mov eax, dword ptr [esp + 4]
// 0086e784  50                   push eax
// 0086e785  e806ffffff           call 0x86e690
// 0086e78a  83c404               add esp, 4
// 0086e78d  85c0                 test eax, eax
// 0086e78f  7508                 jne 0x86e799
// 0086e791  b801000000           mov eax, 1
// 0086e796  c20400               ret 4
// 0086e799  8bc8                 mov ecx, eax
// 0086e79b  e850fbe6ff           call 0x6de2f0
// 0086e7a0  83e001               and eax, 1
// 0086e7a3  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?IsCaptionEnabled@CXTPDockingPanePaintManager@@QAEHPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
