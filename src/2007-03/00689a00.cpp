// from server: 100% by auto
// roc 2007-03 00689a00  unit: seg_00680000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00689a00
//
// 00689a00  c701ecf07c00         mov dword ptr [ecx], 0x7cf0ec
// 00689a06  c74154dcf07c00       mov dword ptr [ecx + 0x54], 0x7cf0dc
// 00689a0d  e90e910700           jmp 0x702b20
// library xtp-15.2.1/Source\Controls\Deprecated\XTOutBarCtrl.cpp (function ??1CXTToolBox@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTOutBarCtrl.cpp
