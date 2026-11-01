// from server: 100% by auto
// roc 2009-12 008ba620  unit: XTPDockingPanePaintThemes::CXTPDockingPaneVisualStudio2005SecondTheme  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ba620
//
// 008ba620  8b442404             mov eax, dword ptr [esp + 4]
// 008ba624  50                   push eax
// 008ba625  e806ffffff           call 0x8ba530
// 008ba62a  83c404               add esp, 4
// 008ba62d  85c0                 test eax, eax
// 008ba62f  7508                 jne 0x8ba639
// 008ba631  b801000000           mov eax, 1
// 008ba636  c20400               ret 4
// 008ba639  8bc8                 mov ecx, eax
// 008ba63b  e8f0d0e9ff           call 0x757730
// 008ba640  83e001               and eax, 1
// 008ba643  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?IsCaptionEnabled@CXTPDockingPanePaintManager@@QAEHPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
