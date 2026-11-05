// from server: 100% by auto
// roc 2010-06 007e3530  unit: CXTPReportSelectedRows  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e3530
//
// 007e3530  0fb6442404           movzx eax, byte ptr [esp + 4]
// 007e3535  89442404             mov dword ptr [esp + 4], eax
// 007e3539  db442404             fild dword ptr [esp + 4]
// 007e353d  dc0df0a6a500         fmul qword ptr [0xa5a6f0]
// 007e3543  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?GetRDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
