// from server: 100% by auto
// roc 2010-06 00875ff0  unit: CXTPImageEditorDlg::CDlgToolBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00875ff0
//
// 00875ff0  56                   push esi
// 00875ff1  8bf1                 mov esi, ecx
// 00875ff3  c786c000000000000000 mov dword ptr [esi + 0xc0], 0
// 00875ffd  ff158cbc9e00         call dword ptr [0x9ebc8c]
// 00876003  8bce                 mov ecx, esi
// 00876005  e8661ff3ff           call 0x7a7f70
// 0087600a  5e                   pop esi
// 0087600b  c20c00               ret 0xc
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnLButtonUp@CXTPImageEditorPicture@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
