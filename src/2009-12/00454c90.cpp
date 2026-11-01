// from server: 100% by auto
// roc 2009-12 00454c90  unit: CRobloxDoc  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00454c90
//
// 00454c90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00454c94  8b01                 mov eax, dword ptr [ecx]
// 00454c96  8b10                 mov edx, dword ptr [eax]
// 00454c98  c744240401000000     mov dword ptr [esp + 4], 1
// 00454ca0  ffe2                 jmp edx
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditView.cpp (function ?OnUpdateEditSelectAll@CXTPSyntaxEditView@@IAEXPAVCCmdUI@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditView.cpp
