// from server: 100% by auto
// roc 2009-12 0082f3c0  unit: CXTPReportSelectedRows  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082f3c0
//
// 0082f3c0  8b442404             mov eax, dword ptr [esp + 4]
// 0082f3c4  c1e810               shr eax, 0x10
// 0082f3c7  0fb6c8               movzx ecx, al
// 0082f3ca  894c2404             mov dword ptr [esp + 4], ecx
// 0082f3ce  db442404             fild dword ptr [esp + 4]
// 0082f3d2  dc0d18649f00         fmul qword ptr [0x9f6418]
// 0082f3d8  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetBDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
