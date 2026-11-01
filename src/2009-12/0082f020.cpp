// from server: 100% by auto
// roc 2009-12 0082f020  unit: CXTPReportSelectedRows  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082f020
//
// 0082f020  b8dc000000           mov eax, 0xdc
// 0082f025  39442404             cmp dword ptr [esp + 4], eax
// 0082f029  7e04                 jle 0x82f02f
// 0082f02b  89442404             mov dword ptr [esp + 4], eax
// 0082f02f  db442404             fild dword ptr [esp + 4]
// 0082f033  dc3500649f00         fdiv qword ptr [0x9f6400]
// 0082f039  dc2db0399b00         fsubr qword ptr [0x9b39b0]
// 0082f03f  da4c2408             fimul dword ptr [esp + 8]
// 0082f043  d95c2404             fstp dword ptr [esp + 4]
// 0082f047  d9442404             fld dword ptr [esp + 4]
// 0082f04b  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?ColorWidth@CXTPColorManager@@AAEMHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
