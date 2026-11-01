// from server: 100% by auto
// roc 2009-06 00445810  unit: CRobloxApp  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445810
//
// 00445810  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00445814  8b01                 mov eax, dword ptr [ecx]
// 00445816  8b10                 mov edx, dword ptr [eax]
// 00445818  c744240401000000     mov dword ptr [esp + 4], 1
// 00445820  ffe2                 jmp edx
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditView.cpp (function ?OnUpdateEditSelectAll@CXTPSyntaxEditView@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditView.cpp
