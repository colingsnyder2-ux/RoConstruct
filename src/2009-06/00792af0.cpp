// from server: 100% by auto
// roc 2009-06 00792af0  unit: CXTPReportColumns  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00792af0
//
// 00792af0  56                   push esi
// 00792af1  8bf1                 mov esi, ecx
// 00792af3  e832940b00           call 0x84bf2a
// 00792af8  8b442408             mov eax, dword ptr [esp + 8]
// 00792afc  8d4e24               lea ecx, [esi + 0x24]
// 00792aff  c70634009000         mov dword ptr [esi], 0x900034
// 00792b05  894620               mov dword ptr [esi + 0x20], eax
// 00792b08  e843fbffff           call 0x792650
// 00792b0d  8bc6                 mov eax, esi
// 00792b0f  5e                   pop esi
// 00792b10  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPDatePickerDaysCollection.cpp (function ??0CXTPDatePickerDaysCollection@@QAE@PAVCXTPDatePickerControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPDatePickerDaysCollection.cpp
