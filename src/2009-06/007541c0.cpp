// from server: 100% by auto
// roc 2009-06 007541c0  unit: CXTPReportSelectedRows  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007541c0
//
// 007541c0  b8dc000000           mov eax, 0xdc
// 007541c5  39442404             cmp dword ptr [esp + 4], eax
// 007541c9  7e04                 jle 0x7541cf
// 007541cb  89442404             mov dword ptr [esp + 4], eax
// 007541cf  db442404             fild dword ptr [esp + 4]
// 007541d3  dc35585f8f00         fdiv qword ptr [0x8f5f58]
// 007541d9  dc2d28e88b00         fsubr qword ptr [0x8be828]
// 007541df  da4c2408             fimul dword ptr [esp + 8]
// 007541e3  d95c2404             fstp dword ptr [esp + 4]
// 007541e7  d9442404             fld dword ptr [esp + 4]
// 007541eb  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?ColorWidth@CXTPColorManager@@AAEMHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
