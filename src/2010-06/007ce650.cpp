// from server: 100% by auto
// roc 2010-06 007ce650  unit: CInstanceRecord::CNameItem  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ce650
//
// 007ce650  83ec28               sub esp, 0x28
// 007ce653  33c0                 xor eax, eax
// 007ce655  89442424             mov dword ptr [esp + 0x24], eax
// 007ce659  8944240c             mov dword ptr [esp + 0xc], eax
// 007ce65d  89442410             mov dword ptr [esp + 0x10], eax
// 007ce661  89442414             mov dword ptr [esp + 0x14], eax
// 007ce665  890424               mov dword ptr [esp], eax
// 007ce668  89442404             mov dword ptr [esp + 4], eax
// 007ce66c  89442408             mov dword ptr [esp + 8], eax
// 007ce670  89442418             mov dword ptr [esp + 0x18], eax
// 007ce674  8944241c             mov dword ptr [esp + 0x1c], eax
// 007ce678  89442420             mov dword ptr [esp + 0x20], eax
// 007ce67c  89442424             mov dword ptr [esp + 0x24], eax
// 007ce680  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007ce684  8b500c               mov edx, dword ptr [eax + 0xc]
// 007ce687  894c2410             mov dword ptr [esp + 0x10], ecx
// 007ce68b  8b4808               mov ecx, dword ptr [eax + 8]
// 007ce68e  894c240c             mov dword ptr [esp + 0xc], ecx
// 007ce692  8d0c24               lea ecx, [esp]
// 007ce695  51                   push ecx
// 007ce696  8b4804               mov ecx, dword ptr [eax + 4]
// 007ce699  6ac2                 push -0x3e
// 007ce69b  8954241c             mov dword ptr [esp + 0x1c], edx
// 007ce69f  e82c8c0000           call 0x7d72d0
// 007ce6a4  33c0                 xor eax, eax
// 007ce6a6  39442424             cmp dword ptr [esp + 0x24], eax
// 007ce6aa  0f94c0               sete al
// 007ce6ad  83c428               add esp, 0x28
// 007ce6b0  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?OnRequestEdit@CXTPReportRecordItem@@MAEHPAUXTP_REPORTRECORDITEM_ARGS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecordItem.cpp
