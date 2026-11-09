// from server: 100% by auto
// roc 2010-06 007e31d0  unit: CXTPReportSelectedRows  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e31d0
//
// 007e31d0  b8dc000000           mov eax, 0xdc
// 007e31d5  39442404             cmp dword ptr [esp + 4], eax
// 007e31d9  7e04                 jle 0x7e31df
// 007e31db  89442404             mov dword ptr [esp + 4], eax
// 007e31df  db442404             fild dword ptr [esp + 4]
// 007e31e3  dc35e8a6a500         fdiv qword ptr [0xa5a6e8]
// 007e31e9  dc2d907aa100         fsubr qword ptr [0xa17a90]
// 007e31ef  da4c2408             fimul dword ptr [esp + 8]
// 007e31f3  d95c2404             fstp dword ptr [esp + 4]
// 007e31f7  d9442404             fld dword ptr [esp + 4]
// 007e31fb  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?ColorWidth@CXTPColorManager@@AAEMHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
