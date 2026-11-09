// from server: 100% by auto
// roc 2010-06 007e3550  unit: CXTPReportSelectedRows  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e3550
//
// 007e3550  8b442404             mov eax, dword ptr [esp + 4]
// 007e3554  c1e808               shr eax, 8
// 007e3557  0fb6c8               movzx ecx, al
// 007e355a  894c2404             mov dword ptr [esp + 4], ecx
// 007e355e  db442404             fild dword ptr [esp + 4]
// 007e3562  dc0df8a6a500         fmul qword ptr [0xa5a6f8]
// 007e3568  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?GetGDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
