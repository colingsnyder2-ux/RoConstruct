// from server: 100% by auto
// roc 2009-12 008c1dd0  unit: CXTPImageEditorDlg::CDlgToolBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1dd0
//
// 008c1dd0  56                   push esi
// 008c1dd1  8bf1                 mov esi, ecx
// 008c1dd3  c786c000000000000000 mov dword ptr [esi + 0xc0], 0
// 008c1ddd  ff1520cc9800         call dword ptr [0x98cc20]
// 008c1de3  8bce                 mov ecx, esi
// 008c1de5  e84620f3ff           call 0x7f3e30
// 008c1dea  5e                   pop esi
// 008c1deb  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnLButtonUp@CXTPImageEditorPicture@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
