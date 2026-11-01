// from server: 100% by auto
// roc 2007-03 006c0030  unit: seg_006c0000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c0030
//
// 006c0030  56                   push esi
// 006c0031  8bf1                 mov esi, ecx
// 006c0033  e836eaf5ff           call 0x61ea6e
// 006c0038  8b442408             mov eax, dword ptr [esp + 8]
// 006c003c  894654               mov dword ptr [esi + 0x54], eax
// 006c003f  33c0                 xor eax, eax
// 006c0041  c70694567d00         mov dword ptr [esi], 0x7d5694
// 006c0047  89465c               mov dword ptr [esi + 0x5c], eax
// 006c004a  c7465824407c00       mov dword ptr [esi + 0x58], 0x7c4024
// 006c0051  894660               mov dword ptr [esi + 0x60], eax
// 006c0054  8bc6                 mov eax, esi
// 006c0056  5e                   pop esi
// 006c0057  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ??0CXTPReportHeaderDropWnd@@QAE@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportDragDrop.cpp
