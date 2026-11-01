// from server: 100% by auto
// roc 2009-06 00754520  unit: CXTPReportSelectedRows  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00754520
//
// 00754520  0fb6442404           movzx eax, byte ptr [esp + 4]
// 00754525  89442404             mov dword ptr [esp + 4], eax
// 00754529  db442404             fild dword ptr [esp + 4]
// 0075452d  dc0d605f8f00         fmul qword ptr [0x8f5f60]
// 00754533  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetRDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
