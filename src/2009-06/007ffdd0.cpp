// from server: 100% by auto
// roc 2009-06 007ffdd0  unit: CXTColorPageStandard  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ffdd0
//
// 007ffdd0  8b442404             mov eax, dword ptr [esp + 4]
// 007ffdd4  81c188000000         add ecx, 0x88
// 007ffdda  51                   push ecx
// 007ffddb  6a67                 push 0x67
// 007ffddd  50                   push eax
// 007ffdde  e8a395f1ff           call 0x719386
// 007ffde3  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageStandard.cpp (function ?DoDataExchange@CXTPColorPageStandard@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageStandard.cpp
