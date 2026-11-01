// from server: 100% by auto
// roc 2009-12 0081a580  unit: CInstanceRecord::CNameItem  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081a580
//
// 0081a580  83ec28               sub esp, 0x28
// 0081a583  33c0                 xor eax, eax
// 0081a585  89442424             mov dword ptr [esp + 0x24], eax
// 0081a589  8944240c             mov dword ptr [esp + 0xc], eax
// 0081a58d  89442410             mov dword ptr [esp + 0x10], eax
// 0081a591  89442414             mov dword ptr [esp + 0x14], eax
// 0081a595  890424               mov dword ptr [esp], eax
// 0081a598  89442404             mov dword ptr [esp + 4], eax
// 0081a59c  89442408             mov dword ptr [esp + 8], eax
// 0081a5a0  89442418             mov dword ptr [esp + 0x18], eax
// 0081a5a4  8944241c             mov dword ptr [esp + 0x1c], eax
// 0081a5a8  89442420             mov dword ptr [esp + 0x20], eax
// 0081a5ac  89442424             mov dword ptr [esp + 0x24], eax
// 0081a5b0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0081a5b4  8b500c               mov edx, dword ptr [eax + 0xc]
// 0081a5b7  894c2410             mov dword ptr [esp + 0x10], ecx
// 0081a5bb  8b4808               mov ecx, dword ptr [eax + 8]
// 0081a5be  894c240c             mov dword ptr [esp + 0xc], ecx
// 0081a5c2  8d0c24               lea ecx, [esp]
// 0081a5c5  51                   push ecx
// 0081a5c6  8b4804               mov ecx, dword ptr [eax + 4]
// 0081a5c9  6ac2                 push -0x3e
// 0081a5cb  8954241c             mov dword ptr [esp + 0x1c], edx
// 0081a5cf  e89c8c0000           call 0x823270
// 0081a5d4  33c0                 xor eax, eax
// 0081a5d6  39442424             cmp dword ptr [esp + 0x24], eax
// 0081a5da  0f94c0               sete al
// 0081a5dd  83c428               add esp, 0x28
// 0081a5e0  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?OnRequestEdit@CXTPReportRecordItem@@MAEHPAUXTP_REPORTRECORDITEM_ARGS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
