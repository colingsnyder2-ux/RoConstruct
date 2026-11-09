// from server: 100% by auto
// roc 2010-06 007e3510  unit: CXTPReportSelectedRows  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e3510
//
// 007e3510  8b442408             mov eax, dword ptr [esp + 8]
// 007e3514  8b542404             mov edx, dword ptr [esp + 4]
// 007e3518  89849168020000       mov dword ptr [ecx + edx*4 + 0x268], eax
// 007e351f  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?SetColor@CXTPColorManager@@QAEXHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
