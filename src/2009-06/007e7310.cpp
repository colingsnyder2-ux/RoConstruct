// from server: 100% by auto
// roc 2009-06 007e7310  unit: CXTPImageEditorDlg::CDlgToolBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e7310
//
// 007e7310  56                   push esi
// 007e7311  8bf1                 mov esi, ecx
// 007e7313  c786c000000000000000 mov dword ptr [esi + 0xc0], 0
// 007e731d  ff1544ee8900         call dword ptr [0x89ee44]
// 007e7323  8bce                 mov ecx, esi
// 007e7325  e8de1cf3ff           call 0x719008
// 007e732a  5e                   pop esi
// 007e732b  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnLButtonUp@CXTPImageEditorPicture@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
