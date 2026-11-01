// from server: 100% by auto
// roc 2009-12 0082f3a0  unit: CXTPReportSelectedRows  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082f3a0
//
// 0082f3a0  8b442404             mov eax, dword ptr [esp + 4]
// 0082f3a4  c1e808               shr eax, 8
// 0082f3a7  0fb6c8               movzx ecx, al
// 0082f3aa  894c2404             mov dword ptr [esp + 4], ecx
// 0082f3ae  db442404             fild dword ptr [esp + 4]
// 0082f3b2  dc0d10649f00         fmul qword ptr [0x9f6410]
// 0082f3b8  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetGDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
