// from server: 100% by auto
// roc 2007-03 006d3030  unit: seg_006d0000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d3030
//
// 006d3030  8b442404             mov eax, dword ptr [esp + 4]
// 006d3034  50                   push eax
// 006d3035  e816ffffff           call 0x6d2f50
// 006d303a  83c404               add esp, 4
// 006d303d  85c0                 test eax, eax
// 006d303f  7508                 jne 0x6d3049
// 006d3041  b801000000           mov eax, 1
// 006d3046  c20400               ret 4
// 006d3049  8bc8                 mov ecx, eax
// 006d304b  e8805cfaff           call 0x678cd0
// 006d3050  83e001               and eax, 1
// 006d3053  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?IsCaptionEnabled@CXTPDockingPanePaintManager@@QAEHPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
