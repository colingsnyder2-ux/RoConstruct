// from server: 100% by auto
// roc 2010-06 0088eaf0  unit: CXTColorPageStandard  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088eaf0
//
// 0088eaf0  8b442404             mov eax, dword ptr [esp + 4]
// 0088eaf4  81c188000000         add ecx, 0x88
// 0088eafa  51                   push ecx
// 0088eafb  6a67                 push 0x67
// 0088eafd  50                   push eax
// 0088eafe  e8eb97f1ff           call 0x7a82ee
// 0088eb03  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?DoDataExchange@CXTColorPageStandard@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
