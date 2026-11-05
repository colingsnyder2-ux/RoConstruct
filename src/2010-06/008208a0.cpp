// from server: 100% by auto
// roc 2010-06 008208a0  unit: CXTPReportColumns  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008208a0
//
// 008208a0  56                   push esi
// 008208a1  8bf1                 mov esi, ecx
// 008208a3  e8d6c41500           call 0x97cd7e
// 008208a8  8b442408             mov eax, dword ptr [esp + 8]
// 008208ac  8d4e24               lea ecx, [esi + 0x24]
// 008208af  c7063c43a600         mov dword ptr [esi], 0xa6433c
// 008208b5  894620               mov dword ptr [esi + 0x20], eax
// 008208b8  e843fbffff           call 0x820400
// 008208bd  8bc6                 mov eax, esi
// 008208bf  5e                   pop esi
// 008208c0  c20400               ret 4
// library xtp-13.2.1/Source\Calendar\XTPDatePickerDaysCollection.cpp (function ??0CXTPDatePickerDaysCollection@@QAE@PAVCXTPDatePickerControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPDatePickerDaysCollection.cpp
