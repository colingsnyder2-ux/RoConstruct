// from server: 100% by auto
// roc 2009-12 008da940  unit: CXTColorPageStandard  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008da940
//
// 008da940  8b442404             mov eax, dword ptr [esp + 4]
// 008da944  81c188000000         add ecx, 0x88
// 008da94a  51                   push ecx
// 008da94b  6a67                 push 0x67
// 008da94d  50                   push eax
// 008da94e  e85b98f1ff           call 0x7f41ae
// 008da953  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageStandard.cpp (function ?DoDataExchange@CXTPColorPageStandard@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageStandard.cpp
