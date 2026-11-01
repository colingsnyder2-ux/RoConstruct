// from server: 100% by auto
// roc 2007-03 00641fb0  unit: seg_00640000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00641fb0
//
// 00641fb0  33c0                 xor eax, eax
// 00641fb2  56                   push esi
// 00641fb3  8bf1                 mov esi, ecx
// 00641fb5  894604               mov dword ptr [esi + 4], eax
// 00641fb8  894608               mov dword ptr [esi + 8], eax
// 00641fbb  89460c               mov dword ptr [esi + 0xc], eax
// 00641fbe  894610               mov dword ptr [esi + 0x10], eax
// 00641fc1  8d4614               lea eax, [esi + 0x14]
// 00641fc4  50                   push eax
// 00641fc5  c706d0547c00         mov dword ptr [esi], 0x7c54d0
// 00641fcb  ff1514ef7700         call dword ptr [0x77ef14]
// 00641fd1  8bc6                 mov eax, esi
// 00641fd3  5e                   pop esi
// 00641fd4  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ??0XTP_REPORTRECORDITEM_ARGS@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
