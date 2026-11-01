// from server: 100% by auto
// roc 2009-06 006b0da0  unit: RBX::BallBallContact  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b0da0
//
// 006b0da0  33c0                 xor eax, eax
// 006b0da2  394134               cmp dword ptr [ecx + 0x34], eax
// 006b0da5  0f95c0               setne al
// 006b0da8  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?IsVirtualMode@CXTPReportRecords@@IBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
