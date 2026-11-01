// from server: 100% by auto
// roc 2009-12 008c28c0  unit: CXTPImageEditorDlg  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c28c0
//
// 008c28c0  53                   push ebx
// 008c28c1  8bc1                 mov eax, ecx
// 008c28c3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008c28c7  8b11                 mov edx, dword ptr [ecx]
// 008c28c9  33db                 xor ebx, ebx
// 008c28cb  3998c4090000         cmp dword ptr [eax + 0x9c4], ebx
// 008c28d1  8b02                 mov eax, dword ptr [edx]
// 008c28d3  0f95c3               setne bl
// 008c28d6  53                   push ebx
// 008c28d7  ffd0                 call eax
// 008c28d9  5b                   pop ebx
// 008c28da  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnUpdateButtonRedo@CXTPImageEditorDlg@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
