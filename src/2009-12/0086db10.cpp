// from server: 100% by auto
// roc 2009-12 0086db10  unit: CXTPReportColumns  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086db10
//
// 0086db10  56                   push esi
// 0086db11  8bf1                 mov esi, ecx
// 0086db13  e82a890b00           call 0x926442
// 0086db18  8b442408             mov eax, dword ptr [esp + 8]
// 0086db1c  8d4e24               lea ecx, [esi + 0x24]
// 0086db1f  c706bc04a000         mov dword ptr [esi], 0xa004bc
// 0086db25  894620               mov dword ptr [esi + 0x20], eax
// 0086db28  e843fbffff           call 0x86d670
// 0086db2d  8bc6                 mov eax, esi
// 0086db2f  5e                   pop esi
// 0086db30  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPDatePickerDaysCollection.cpp (function ??0CXTPDatePickerDaysCollection@@QAE@PAVCXTPDatePickerControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPDatePickerDaysCollection.cpp
