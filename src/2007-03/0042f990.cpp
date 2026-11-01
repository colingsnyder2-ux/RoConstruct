// from server: 100% by auto
// roc 2007-03 0042f990  unit: seg_00420000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0042f990
//
// 0042f990  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042f994  8b01                 mov eax, dword ptr [ecx]
// 0042f996  8b10                 mov edx, dword ptr [eax]
// 0042f998  c744240401000000     mov dword ptr [esp + 4], 1
// 0042f9a0  ffe2                 jmp edx
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditView.cpp (function ?OnUpdateEditSelectAll@CXTPSyntaxEditView@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditView.cpp
