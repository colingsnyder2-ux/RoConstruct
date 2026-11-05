// from server: 100% by auto
// roc 2010-06 00876ae0  unit: CXTPImageEditorDlg  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00876ae0
//
// 00876ae0  53                   push ebx
// 00876ae1  8bc1                 mov eax, ecx
// 00876ae3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00876ae7  8b11                 mov edx, dword ptr [ecx]
// 00876ae9  33db                 xor ebx, ebx
// 00876aeb  3998a8090000         cmp dword ptr [eax + 0x9a8], ebx
// 00876af1  8b02                 mov eax, dword ptr [edx]
// 00876af3  0f95c3               setne bl
// 00876af6  53                   push ebx
// 00876af7  ffd0                 call eax
// 00876af9  5b                   pop ebx
// 00876afa  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnUpdateButtonUndo@CXTPImageEditorDlg@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
