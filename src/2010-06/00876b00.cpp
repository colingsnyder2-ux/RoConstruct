// from server: 100% by auto
// roc 2010-06 00876b00  unit: CXTPImageEditorDlg  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00876b00
//
// 00876b00  53                   push ebx
// 00876b01  8bc1                 mov eax, ecx
// 00876b03  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00876b07  8b11                 mov edx, dword ptr [ecx]
// 00876b09  33db                 xor ebx, ebx
// 00876b0b  3998c4090000         cmp dword ptr [eax + 0x9c4], ebx
// 00876b11  8b02                 mov eax, dword ptr [edx]
// 00876b13  0f95c3               setne bl
// 00876b16  53                   push ebx
// 00876b17  ffd0                 call eax
// 00876b19  5b                   pop ebx
// 00876b1a  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnUpdateButtonRedo@CXTPImageEditorDlg@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
