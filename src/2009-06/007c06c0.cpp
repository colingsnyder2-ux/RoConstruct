// from server: 100% by auto
// roc 2009-06 007c06c0  unit: CXTPReportPaintManager  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c06c0
//
// 007c06c0  8b4178               mov eax, dword ptr [ecx + 0x78]
// 007c06c3  83f8ff               cmp eax, -1
// 007c06c6  7503                 jne 0x7c06cb
// 007c06c8  8b4174               mov eax, dword ptr [ecx + 0x74]
// 007c06cb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007c06cf  50                   push eax
// 007c06d0  8d44240c             lea eax, [esp + 0xc]
// 007c06d4  50                   push eax
// 007c06d5  e8f690f5ff           call 0x7197d0
// 007c06da  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillHeaderControl@CXTPReportPaintManager@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
