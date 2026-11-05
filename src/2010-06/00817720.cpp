// from server: 100% by auto
// roc 2010-06 00817720  unit: CXTPToolTipContextToolTip  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00817720
//
// 00817720  56                   push esi
// 00817721  6a40                 push 0x40
// 00817723  8bf1                 mov esi, ecx
// 00817725  6a00                 push 0
// 00817727  56                   push esi
// 00817728  c7463c00000000       mov dword ptr [esi + 0x3c], 0
// 0081772f  e8b014f9ff           call 0x7a8be4
// 00817734  83c40c               add esp, 0xc
// 00817737  8bc6                 mov eax, esi
// 00817739  5e                   pop esi
// 0081773a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTGlobal.cpp (function ??0CXTLogFont@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTGlobal.cpp
