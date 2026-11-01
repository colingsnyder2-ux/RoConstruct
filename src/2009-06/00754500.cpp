// from server: 100% by auto
// roc 2009-06 00754500  unit: CXTPReportSelectedRows  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00754500
//
// 00754500  8b442408             mov eax, dword ptr [esp + 8]
// 00754504  8b542404             mov edx, dword ptr [esp + 4]
// 00754508  89849168020000       mov dword ptr [ecx + edx*4 + 0x268], eax
// 0075450f  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?SetColor@CXTPColorManager@@QAEXHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
