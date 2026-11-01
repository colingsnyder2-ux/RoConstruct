// from server: 100% by auto
// roc 2009-12 008c1330  unit: CXTPImageEditorPicker  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1330
//
// 008c1330  8b81580a0000         mov eax, dword ptr [ecx + 0xa58]
// 008c1336  83f802               cmp eax, 2
// 008c1339  7506                 jne 0x8c1341
// 008c133b  8b815c0a0000         mov eax, dword ptr [ecx + 0xa5c]
// 008c1341  89815c0a0000         mov dword ptr [ecx + 0xa5c], eax
// 008c1347  8b442404             mov eax, dword ptr [esp + 4]
// 008c134b  0551dcffff           add eax, 0xffffdc51
// 008c1350  8981580a0000         mov dword ptr [ecx + 0xa58], eax
// 008c1356  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnButtonTool@CXTPImageEditorDlg@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
