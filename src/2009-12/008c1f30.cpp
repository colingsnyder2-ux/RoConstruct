// from server: 100% by auto
// roc 2009-12 008c1f30  unit: CXTPImageEditorDlg::CDlgToolBar  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1f30
//
// 008c1f30  8b442404             mov eax, dword ptr [esp + 4]
// 008c1f34  894154               mov dword ptr [ecx + 0x54], eax
// 008c1f37  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008c1f3a  85c9                 test ecx, ecx
// 008c1f3c  740b                 je 0x8c1f49
// 008c1f3e  6a00                 push 0
// 008c1f40  6a00                 push 0
// 008c1f42  51                   push ecx
// 008c1f43  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008c1f49  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?SetColor@CXTPImageEditorPicker@@QAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
