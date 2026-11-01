// from server: 100% by auto
// roc 2009-12 008f3e60  unit: CXTMemDC  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f3e60
//
// 008f3e60  8b01                 mov eax, dword ptr [ecx]
// 008f3e62  8b4904               mov ecx, dword ptr [ecx + 4]
// 008f3e65  50                   push eax
// 008f3e66  e825260300           call 0x926490
// 008f3e6b  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ??1CXTPContextBkModeHandler@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
