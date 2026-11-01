// from server: 100% by auto
// roc 2007-03 006ecde0  unit: seg_006e0000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006ecde0
//
// 006ecde0  8b442404             mov eax, dword ptr [esp + 4]
// 006ecde4  81c188000000         add ecx, 0x88
// 006ecdea  51                   push ecx
// 006ecdeb  6a67                 push 0x67
// 006ecded  50                   push eax
// 006ecdee  e8f7e10400           call 0x73afea
// 006ecdf3  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageStandard.cpp (function ?DoDataExchange@CXTPColorPageStandard@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageStandard.cpp
