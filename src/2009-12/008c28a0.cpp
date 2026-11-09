// from server: 100% by auto
// roc 2009-12 008c28a0  unit: CXTPImageEditorDlg  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c28a0
//
// 008c28a0  53                   push ebx
// 008c28a1  8bc1                 mov eax, ecx
// 008c28a3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008c28a7  8b11                 mov edx, dword ptr [ecx]
// 008c28a9  33db                 xor ebx, ebx
// 008c28ab  3998a8090000         cmp dword ptr [eax + 0x9a8], ebx
// 008c28b1  8b02                 mov eax, dword ptr [edx]
// 008c28b3  0f95c3               setne bl
// 008c28b6  53                   push ebx
// 008c28b7  ffd0                 call eax
// 008c28b9  5b                   pop ebx
// 008c28ba  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnUpdateButtonUndo@CXTPImageEditorDlg@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
