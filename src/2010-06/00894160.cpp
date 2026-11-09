// from server: 100% by auto
// roc 2010-06 00894160  unit: CXTPRichRender::XTextHost  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00894160
//
// 00894160  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00894164  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00894168  50                   push eax
// 00894169  ff158cce9e00         call dword ptr [0x9ece8c]
// 0089416f  33c0                 xor eax, eax
// 00894171  c21000               ret 0x10
// library xtp-13.2.1-shared-mfc/Source\Common\XTPOffice2007Image.cpp (function ?EnumResNameProc@CXTPOffice2007Images@@CGHPAUHINSTANCE__@@PBDPADJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPOffice2007Image.cpp
