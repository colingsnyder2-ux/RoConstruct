// from server: 100% by auto
// roc 2009-12 008c1f50  unit: CXTPImageEditorDlg::CDlgToolBar  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1f50
//
// 008c1f50  8b442404             mov eax, dword ptr [esp + 4]
// 008c1f54  894158               mov dword ptr [ecx + 0x58], eax
// 008c1f57  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008c1f5a  85c9                 test ecx, ecx
// 008c1f5c  740b                 je 0x8c1f69
// 008c1f5e  6a00                 push 0
// 008c1f60  6a00                 push 0
// 008c1f62  51                   push ecx
// 008c1f63  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008c1f69  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?SetSelected@CXTPImageEditorPicker@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
