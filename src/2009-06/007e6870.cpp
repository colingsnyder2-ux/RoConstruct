// from server: 100% by auto
// roc 2009-06 007e6870  unit: CXTPImageEditorPicker  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e6870
//
// 007e6870  8b81580a0000         mov eax, dword ptr [ecx + 0xa58]
// 007e6876  83f802               cmp eax, 2
// 007e6879  7506                 jne 0x7e6881
// 007e687b  8b815c0a0000         mov eax, dword ptr [ecx + 0xa5c]
// 007e6881  89815c0a0000         mov dword ptr [ecx + 0xa5c], eax
// 007e6887  8b442404             mov eax, dword ptr [esp + 4]
// 007e688b  0551dcffff           add eax, 0xffffdc51
// 007e6890  8981580a0000         mov dword ptr [ecx + 0xa58], eax
// 007e6896  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnButtonTool@CXTPImageEditorDlg@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
