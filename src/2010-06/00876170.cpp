// from server: 100% by auto
// roc 2010-06 00876170  unit: CXTPImageEditorDlg::CDlgToolBar  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00876170
//
// 00876170  8b442404             mov eax, dword ptr [esp + 4]
// 00876174  894158               mov dword ptr [ecx + 0x58], eax
// 00876177  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0087617a  85c9                 test ecx, ecx
// 0087617c  740b                 je 0x876189
// 0087617e  6a00                 push 0
// 00876180  6a00                 push 0
// 00876182  51                   push ecx
// 00876183  ff1578ba9e00         call dword ptr [0x9eba78]
// 00876189  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?SetSelected@CXTPImageEditorPicker@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
