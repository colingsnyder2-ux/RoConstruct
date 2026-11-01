// from server: 100% by auto
// roc 2009-06 007cc590  unit: CXTPReportHeaderDragWnd  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cc590
//
// 007cc590  56                   push esi
// 007cc591  8bf1                 mov esi, ecx
// 007cc593  e888cdf4ff           call 0x719320
// 007cc598  8b442408             mov eax, dword ptr [esp + 8]
// 007cc59c  894654               mov dword ptr [esi + 0x54], eax
// 007cc59f  33c0                 xor eax, eax
// 007cc5a1  c706545c9000         mov dword ptr [esi], 0x905c54
// 007cc5a7  89465c               mov dword ptr [esi + 0x5c], eax
// 007cc5aa  c746588c2b8f00       mov dword ptr [esi + 0x58], 0x8f2b8c
// 007cc5b1  894660               mov dword ptr [esi + 0x60], eax
// 007cc5b4  8bc6                 mov eax, esi
// 007cc5b6  5e                   pop esi
// 007cc5b7  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ??0CXTPReportHeaderDropWnd@@QAE@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportDragDrop.cpp
