// from server: 100% by auto
// roc 2009-06 00754560  unit: CXTPReportSelectedRows  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00754560
//
// 00754560  8b442404             mov eax, dword ptr [esp + 4]
// 00754564  c1e810               shr eax, 0x10
// 00754567  0fb6c8               movzx ecx, al
// 0075456a  894c2404             mov dword ptr [esp + 4], ecx
// 0075456e  db442404             fild dword ptr [esp + 4]
// 00754572  dc0d705f8f00         fmul qword ptr [0x8f5f70]
// 00754578  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetBDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
