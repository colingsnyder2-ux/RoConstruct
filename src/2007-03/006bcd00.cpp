// from server: 100% by auto
// roc 2007-03 006bcd00  unit: seg_006b0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bcd00
//
// 006bcd00  56                   push esi
// 006bcd01  8bf1                 mov esi, ecx
// 006bcd03  e8c6dd0700           call 0x73aace
// 006bcd08  8b442408             mov eax, dword ptr [esp + 8]
// 006bcd0c  8d4e24               lea ecx, [esi + 0x24]
// 006bcd0f  c7064c507d00         mov dword ptr [esi], 0x7d504c
// 006bcd15  894620               mov dword ptr [esi + 0x20], eax
// 006bcd18  e823fcffff           call 0x6bc940
// 006bcd1d  8bc6                 mov eax, esi
// 006bcd1f  5e                   pop esi
// 006bcd20  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPDatePickerDaysCollection.cpp (function ??0CXTPDatePickerDaysCollection@@QAE@PAVCXTPDatePickerControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPDatePickerDaysCollection.cpp
