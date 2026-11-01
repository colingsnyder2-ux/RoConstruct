// from server: 100% by auto
// roc 2011-06 008ac780  unit: CXTPReportPaintManager  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ac780
//
// 008ac780  8b4178               mov eax, dword ptr [ecx + 0x78]
// 008ac783  83f8ff               cmp eax, -1
// 008ac786  7503                 jne 0x8ac78b
// 008ac788  8b4174               mov eax, dword ptr [ecx + 0x74]
// 008ac78b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008ac78f  50                   push eax
// 008ac790  8d44240c             lea eax, [esp + 0xc]
// 008ac794  50                   push eax
// 008ac795  e886e6f5ff           call 0x80ae20
// 008ac79a  c21400               ret 0x14
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillHeaderControl@CXTPReportPaintManager@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
