// from server: 100% by auto
// roc 2009-12 0082f380  unit: CXTPReportSelectedRows  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082f380
//
// 0082f380  0fb6442404           movzx eax, byte ptr [esp + 4]
// 0082f385  89442404             mov dword ptr [esp + 4], eax
// 0082f389  db442404             fild dword ptr [esp + 4]
// 0082f38d  dc0d08649f00         fmul qword ptr [0x9f6408]
// 0082f393  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetRDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
