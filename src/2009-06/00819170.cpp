// from server: 100% by auto
// roc 2009-06 00819170  unit: CXTMemDC  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00819170
//
// 00819170  8b01                 mov eax, dword ptr [ecx]
// 00819172  8b4904               mov ecx, dword ptr [ecx + 4]
// 00819175  50                   push eax
// 00819176  e88b2d0300           call 0x84bf06
// 0081917b  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ??1CXTPContextBkModeHandler@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
