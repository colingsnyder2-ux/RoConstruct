// from server: 100% by auto
// roc 2007-03 006546e0  unit: seg_00650000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006546e0
//
// 006546e0  b8dc000000           mov eax, 0xdc
// 006546e5  39442404             cmp dword ptr [esp + 4], eax
// 006546e9  7e04                 jle 0x6546ef
// 006546eb  89442404             mov dword ptr [esp + 4], eax
// 006546ef  db442404             fild dword ptr [esp + 4]
// 006546f3  dc3548777c00         fdiv qword ptr [0x7c7748]
// 006546f9  dc2d18507900         fsubr qword ptr [0x795018]
// 006546ff  da4c2408             fimul dword ptr [esp + 8]
// 00654703  d95c2404             fstp dword ptr [esp + 4]
// 00654707  d9442404             fld dword ptr [esp + 4]
// 0065470b  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?ColorWidth@CXTPColorManager@@AAEMHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
