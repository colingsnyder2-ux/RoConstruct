// from server: 100% by auto
// roc 2010-06 00455dc0  unit: CRobloxDoc  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00455dc0
//
// 00455dc0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00455dc4  8b01                 mov eax, dword ptr [ecx]
// 00455dc6  8b10                 mov edx, dword ptr [eax]
// 00455dc8  c744240401000000     mov dword ptr [esp + 4], 1
// 00455dd0  ffe2                 jmp edx
// library xtp-13.2.1/Source\SyntaxEdit\XTPSyntaxEditView.cpp (function ?OnUpdateEditSelectAll@CXTPSyntaxEditView@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SyntaxEdit/XTPSyntaxEditView.cpp
