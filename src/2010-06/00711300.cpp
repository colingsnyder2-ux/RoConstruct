// from server: 100% by auto
// roc 2010-06 00711300  unit: RBX::BallBallContact  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00711300
//
// 00711300  33c0                 xor eax, eax
// 00711302  394134               cmp dword ptr [ecx + 0x34], eax
// 00711305  0f95c0               setne al
// 00711308  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?IsVirtualMode@CXTPReportRecords@@IBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
