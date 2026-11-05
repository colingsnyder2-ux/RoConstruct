// from server: 100% by auto
// roc 2010-06 007f8560  unit: CXTPPopupToolBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f8560
//
// 007f8560  56                   push esi
// 007f8561  8b742408             mov esi, dword ptr [esp + 8]
// 007f8565  6a00                 push 0
// 007f8567  6a00                 push 0
// 007f8569  56                   push esi
// 007f856a  e801e2ffff           call 0x7f6770
// 007f856f  8bc6                 mov eax, esi
// 007f8571  5e                   pop esi
// 007f8572  c20c00               ret 0xc
// library xtp-13.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?CalcDynamicLayout@CXTPPopupToolBar@@MAE?AVCSize@@HK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPopupBar.cpp
