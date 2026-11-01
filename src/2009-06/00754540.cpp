// from server: 100% by auto
// roc 2009-06 00754540  unit: CXTPReportSelectedRows  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00754540
//
// 00754540  8b442404             mov eax, dword ptr [esp + 4]
// 00754544  c1e808               shr eax, 8
// 00754547  0fb6c8               movzx ecx, al
// 0075454a  894c2404             mov dword ptr [esp + 4], ecx
// 0075454e  db442404             fild dword ptr [esp + 4]
// 00754552  dc0d685f8f00         fmul qword ptr [0x8f5f68]
// 00754558  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetGDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
