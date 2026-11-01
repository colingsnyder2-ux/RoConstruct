// from server: 100% by auto
// roc 2009-06 007696d0  unit: CXTPPopupToolBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007696d0
//
// 007696d0  56                   push esi
// 007696d1  8b742408             mov esi, dword ptr [esp + 8]
// 007696d5  6a00                 push 0
// 007696d7  6a00                 push 0
// 007696d9  56                   push esi
// 007696da  e801e2ffff           call 0x7678e0
// 007696df  8bc6                 mov eax, esi
// 007696e1  5e                   pop esi
// 007696e2  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?CalcDynamicLayout@CXTPPopupToolBar@@MAE?AVCSize@@HK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
