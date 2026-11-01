// from server: 100% by auto
// roc 2007-03 00721c40  unit: seg_00720000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00721c40
//
// 00721c40  8b01                 mov eax, dword ptr [ecx]
// 00721c42  8b4904               mov ecx, dword ptr [ecx + 4]
// 00721c45  50                   push eax
// 00721c46  e8558f0100           call 0x73aba0
// 00721c4b  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ??1CXTPContextBkModeHandler@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
