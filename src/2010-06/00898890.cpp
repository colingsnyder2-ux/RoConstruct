// from server: 100% by auto
// roc 2010-06 00898890  unit: CXTCaptionButtonThemeFactory  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00898890
//
// 00898890  56                   push esi
// 00898891  8bf1                 mov esi, ecx
// 00898893  e838f70000           call 0x8a7fd0
// 00898898  c7064407a700         mov dword ptr [esi], 0xa70744
// 0089889e  c7461800000000       mov dword ptr [esi + 0x18], 0
// 008988a5  8bc6                 mov eax, esi
// 008988a7  5e                   pop esi
// 008988a8  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ??0CXTCaptionButtonTheme@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
