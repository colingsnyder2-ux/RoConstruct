// from server: 100% by auto
// roc 2010-06 00875540  unit: CXTPImageEditorPicker  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00875540
//
// 00875540  8b81580a0000         mov eax, dword ptr [ecx + 0xa58]
// 00875546  83f802               cmp eax, 2
// 00875549  7506                 jne 0x875551
// 0087554b  8b815c0a0000         mov eax, dword ptr [ecx + 0xa5c]
// 00875551  89815c0a0000         mov dword ptr [ecx + 0xa5c], eax
// 00875557  8b442404             mov eax, dword ptr [esp + 4]
// 0087555b  0551dcffff           add eax, 0xffffdc51
// 00875560  8981580a0000         mov dword ptr [ecx + 0xa58], eax
// 00875566  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnButtonTool@CXTPImageEditorDlg@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
