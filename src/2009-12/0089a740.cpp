// from server: 100% by auto
// roc 2009-12 0089a740  unit: CXTPReportPaintManager  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089a740
//
// 0089a740  8b442414             mov eax, dword ptr [esp + 0x14]
// 0089a744  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089a748  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0089a74c  50                   push eax
// 0089a74d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0089a751  6a01                 push 1
// 0089a753  51                   push ecx
// 0089a754  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089a758  52                   push edx
// 0089a759  50                   push eax
// 0089a75a  e837bd0800           call 0x926496
// 0089a75f  c21400               ret 0x14
// library xtp-15.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?DrawHorizontalLine@CXTPReportPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPaintManager.cpp
