// from server: 100% by auto
// roc 2009-06 0041a7b0  unit: CInstanceRecord::CNameItem  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041a7b0
//
// 0041a7b0  8b542404             mov edx, dword ptr [esp + 4]
// 0041a7b4  8b4144               mov eax, dword ptr [ecx + 0x44]
// 0041a7b7  895144               mov dword ptr [ecx + 0x44], edx
// 0041a7ba  c20400               ret 4
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditPaintManager.cpp (function ?SetLineSelCursor@CXTPSyntaxEditPaintManager@@QAEPAUHICON__@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditPaintManager.cpp
