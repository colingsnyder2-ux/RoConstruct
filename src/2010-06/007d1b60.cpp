// from server: 100% by auto
// roc 2010-06 007d1b60  unit: CXTPReportControl  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d1b60
//
// 007d1b60  8b01                 mov eax, dword ptr [ecx]
// 007d1b62  8b9064010000         mov edx, dword ptr [eax + 0x164]
// 007d1b68  ffd2                 call edx
// 007d1b6a  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnEnable@CXTPReportControl@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
