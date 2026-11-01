// from server: 100% by auto
// roc 2009-12 008d0950  unit: CXTSplitterWnd  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0950
//
// 008d0950  56                   push esi
// 008d0951  8bf1                 mov esi, ecx
// 008d0953  e8883b0000           call 0x8d44e0
// 008d0958  6a00                 push 0
// 008d095a  6a06                 push 6
// 008d095c  6a03                 push 3
// 008d095e  6a02                 push 2
// 008d0960  8d4604               lea eax, [esi + 4]
// 008d0963  50                   push eax
// 008d0964  c70694a8a000         mov dword ptr [esi], 0xa0a894
// 008d096a  ff1538ca9800         call dword ptr [0x98ca38]
// 008d0970  8bc6                 mov eax, esi
// 008d0972  5e                   pop esi
// 008d0973  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
