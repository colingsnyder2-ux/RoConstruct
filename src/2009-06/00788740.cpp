// from server: 100% by auto
// roc 2009-06 00788740  unit: CXTPToolTipContextToolTip  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00788740
//
// 00788740  56                   push esi
// 00788741  6a40                 push 0x40
// 00788743  8bf1                 mov esi, ecx
// 00788745  6a00                 push 0
// 00788747  56                   push esi
// 00788748  c7463c00000000       mov dword ptr [esi + 0x3c], 0
// 0078874f  e82015f9ff           call 0x719c74
// 00788754  83c40c               add esp, 0xc
// 00788757  8bc6                 mov eax, esi
// 00788759  5e                   pop esi
// 0078875a  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPGlobal.cpp (function ??0CXTPLogFont@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPGlobal.cpp
