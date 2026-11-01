// from server: 100% by auto
// roc 2009-12 00863740  unit: CXTPToolTipContextToolTip  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00863740
//
// 00863740  56                   push esi
// 00863741  6a40                 push 0x40
// 00863743  8bf1                 mov esi, ecx
// 00863745  6a00                 push 0
// 00863747  56                   push esi
// 00863748  c7463c00000000       mov dword ptr [esi + 0x3c], 0
// 0086374f  e85013f9ff           call 0x7f4aa4
// 00863754  83c40c               add esp, 0xc
// 00863757  8bc6                 mov eax, esi
// 00863759  5e                   pop esi
// 0086375a  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPGlobal.cpp (function ??0CXTPLogFont@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPGlobal.cpp
