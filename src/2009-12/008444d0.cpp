// from server: 100% by auto
// roc 2009-12 008444d0  unit: CXTPPopupToolBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008444d0
//
// 008444d0  56                   push esi
// 008444d1  8b742408             mov esi, dword ptr [esp + 8]
// 008444d5  6a00                 push 0
// 008444d7  6a00                 push 0
// 008444d9  56                   push esi
// 008444da  e8e1e1ffff           call 0x8426c0
// 008444df  8bc6                 mov eax, esi
// 008444e1  5e                   pop esi
// 008444e2  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?CalcDynamicLayout@CXTPPopupToolBar@@MAE?AVCSize@@HK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
