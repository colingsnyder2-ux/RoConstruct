// from server: 100% by auto
// roc 2007-03 0063ce00  unit: seg_00630000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0063ce00
//
// 0063ce00  8b4104               mov eax, dword ptr [ecx + 4]
// 0063ce03  8b09                 mov ecx, dword ptr [ecx]
// 0063ce05  8988ec000000         mov dword ptr [eax + 0xec], ecx
// 0063ce0b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??1CXTPPushRoutingFrame@CXTPToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
