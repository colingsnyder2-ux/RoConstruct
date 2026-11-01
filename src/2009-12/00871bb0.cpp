// from server: 100% by auto
// roc 2009-12 00871bb0  unit: CXTPRibbonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00871bb0
//
// 00871bb0  56                   push esi
// 00871bb1  8bf1                 mov esi, ecx
// 00871bb3  e828290600           call 0x8d44e0
// 00871bb8  6a00                 push 0
// 00871bba  6a04                 push 4
// 00871bbc  6a02                 push 2
// 00871bbe  6a02                 push 2
// 00871bc0  8d4604               lea eax, [esi + 4]
// 00871bc3  50                   push eax
// 00871bc4  c706c40fa000         mov dword ptr [esi], 0xa00fc4
// 00871bca  ff1538ca9800         call dword ptr [0x98ca38]
// 00871bd0  8bc6                 mov eax, esi
// 00871bd2  5e                   pop esi
// 00871bd3  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ??0CAppearanceSetFlat@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
