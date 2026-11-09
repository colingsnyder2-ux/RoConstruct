// from server: 100% by auto
// roc 2010-06 007e3570  unit: CXTPReportSelectedRows  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e3570
//
// 007e3570  8b442404             mov eax, dword ptr [esp + 4]
// 007e3574  c1e810               shr eax, 0x10
// 007e3577  0fb6c8               movzx ecx, al
// 007e357a  894c2404             mov dword ptr [esp + 4], ecx
// 007e357e  db442404             fild dword ptr [esp + 4]
// 007e3582  dc0d00a7a500         fmul qword ptr [0xa5a700]
// 007e3588  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?GetBDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
