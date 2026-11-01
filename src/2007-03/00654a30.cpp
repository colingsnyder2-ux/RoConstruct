// from server: 100% by auto
// roc 2007-03 00654a30  unit: seg_00650000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00654a30
//
// 00654a30  0fb6442404           movzx eax, byte ptr [esp + 4]
// 00654a35  89442404             mov dword ptr [esp + 4], eax
// 00654a39  db442404             fild dword ptr [esp + 4]
// 00654a3d  dc0d50777c00         fmul qword ptr [0x7c7750]
// 00654a43  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetRDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
