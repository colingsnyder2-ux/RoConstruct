// from server: 100% by auto
// roc 2007-03 00654a70  unit: seg_00650000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00654a70
//
// 00654a70  8b442404             mov eax, dword ptr [esp + 4]
// 00654a74  c1e810               shr eax, 0x10
// 00654a77  0fb6c8               movzx ecx, al
// 00654a7a  894c2404             mov dword ptr [esp + 4], ecx
// 00654a7e  db442404             fild dword ptr [esp + 4]
// 00654a82  dc0d60777c00         fmul qword ptr [0x7c7760]
// 00654a88  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetBDelta@CXTPColorManager@@AAENK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
