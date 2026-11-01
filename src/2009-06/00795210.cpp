// from server: 100% by auto
// roc 2009-06 00795210  unit: CXTPRibbonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00795210
//
// 00795210  56                   push esi
// 00795211  8bf1                 mov esi, ecx
// 00795213  e828470600           call 0x7f9940
// 00795218  6a00                 push 0
// 0079521a  6a04                 push 4
// 0079521c  6a02                 push 2
// 0079521e  6a02                 push 2
// 00795220  8d4604               lea eax, [esi + 4]
// 00795223  50                   push eax
// 00795224  c706e4039000         mov dword ptr [esi], 0x9003e4
// 0079522a  ff15a4ed8900         call dword ptr [0x89eda4]
// 00795230  8bc6                 mov eax, esi
// 00795232  5e                   pop esi
// 00795233  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ??0CAppearanceSetFlat@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
