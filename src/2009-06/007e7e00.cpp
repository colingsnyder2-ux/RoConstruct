// from server: 100% by auto
// roc 2009-06 007e7e00  unit: CXTPImageEditorDlg  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e7e00
//
// 007e7e00  53                   push ebx
// 007e7e01  8bc1                 mov eax, ecx
// 007e7e03  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e7e07  8b11                 mov edx, dword ptr [ecx]
// 007e7e09  33db                 xor ebx, ebx
// 007e7e0b  3998a8090000         cmp dword ptr [eax + 0x9a8], ebx
// 007e7e11  8b02                 mov eax, dword ptr [edx]
// 007e7e13  0f95c3               setne bl
// 007e7e16  53                   push ebx
// 007e7e17  ffd0                 call eax
// 007e7e19  5b                   pop ebx
// 007e7e1a  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnUpdateButtonUndo@CXTPImageEditorDlg@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
