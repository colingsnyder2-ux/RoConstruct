// from server: 100% by auto
// roc 2010-06 00876150  unit: CXTPImageEditorDlg::CDlgToolBar  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00876150
//
// 00876150  8b442404             mov eax, dword ptr [esp + 4]
// 00876154  894154               mov dword ptr [ecx + 0x54], eax
// 00876157  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0087615a  85c9                 test ecx, ecx
// 0087615c  740b                 je 0x876169
// 0087615e  6a00                 push 0
// 00876160  6a00                 push 0
// 00876162  51                   push ecx
// 00876163  ff1578ba9e00         call dword ptr [0x9eba78]
// 00876169  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?SetColor@CXTPImageEditorPicker@@QAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
