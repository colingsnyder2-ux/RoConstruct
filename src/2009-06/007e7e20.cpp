// from server: 100% by auto
// roc 2009-06 007e7e20  unit: CXTPImageEditorDlg  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e7e20
//
// 007e7e20  53                   push ebx
// 007e7e21  8bc1                 mov eax, ecx
// 007e7e23  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e7e27  8b11                 mov edx, dword ptr [ecx]
// 007e7e29  33db                 xor ebx, ebx
// 007e7e2b  3998c4090000         cmp dword ptr [eax + 0x9c4], ebx
// 007e7e31  8b02                 mov eax, dword ptr [edx]
// 007e7e33  0f95c3               setne bl
// 007e7e36  53                   push ebx
// 007e7e37  ffd0                 call eax
// 007e7e39  5b                   pop ebx
// 007e7e3a  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnUpdateButtonRedo@CXTPImageEditorDlg@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
