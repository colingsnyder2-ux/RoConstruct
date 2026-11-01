// from server: 100% by auto
// roc 2007-03 00641d50  unit: seg_00640000  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00641d50
//
// 00641d50  83ec28               sub esp, 0x28
// 00641d53  33c0                 xor eax, eax
// 00641d55  89442424             mov dword ptr [esp + 0x24], eax
// 00641d59  8944240c             mov dword ptr [esp + 0xc], eax
// 00641d5d  89442410             mov dword ptr [esp + 0x10], eax
// 00641d61  89442414             mov dword ptr [esp + 0x14], eax
// 00641d65  890424               mov dword ptr [esp], eax
// 00641d68  89442404             mov dword ptr [esp + 4], eax
// 00641d6c  89442408             mov dword ptr [esp + 8], eax
// 00641d70  89442418             mov dword ptr [esp + 0x18], eax
// 00641d74  8944241c             mov dword ptr [esp + 0x1c], eax
// 00641d78  89442420             mov dword ptr [esp + 0x20], eax
// 00641d7c  89442424             mov dword ptr [esp + 0x24], eax
// 00641d80  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00641d84  8b500c               mov edx, dword ptr [eax + 0xc]
// 00641d87  894c2410             mov dword ptr [esp + 0x10], ecx
// 00641d8b  8b4808               mov ecx, dword ptr [eax + 8]
// 00641d8e  894c240c             mov dword ptr [esp + 0xc], ecx
// 00641d92  8d0c24               lea ecx, [esp]
// 00641d95  51                   push ecx
// 00641d96  8b4804               mov ecx, dword ptr [eax + 4]
// 00641d99  6ac2                 push -0x3e
// 00641d9b  8954241c             mov dword ptr [esp + 0x1c], edx
// 00641d9f  e80c6f0000           call 0x648cb0
// 00641da4  33c0                 xor eax, eax
// 00641da6  39442424             cmp dword ptr [esp + 0x24], eax
// 00641daa  0f94c0               sete al
// 00641dad  83c428               add esp, 0x28
// 00641db0  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?OnRequestEdit@CXTPReportRecordItem@@MAEHPAUXTP_REPORTRECORDITEM_ARGS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
