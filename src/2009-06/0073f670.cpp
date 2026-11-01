// from server: 100% by auto
// roc 2009-06 0073f670  unit: CInstanceRecord::CNameItem  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073f670
//
// 0073f670  83ec28               sub esp, 0x28
// 0073f673  33c0                 xor eax, eax
// 0073f675  89442424             mov dword ptr [esp + 0x24], eax
// 0073f679  8944240c             mov dword ptr [esp + 0xc], eax
// 0073f67d  89442410             mov dword ptr [esp + 0x10], eax
// 0073f681  89442414             mov dword ptr [esp + 0x14], eax
// 0073f685  890424               mov dword ptr [esp], eax
// 0073f688  89442404             mov dword ptr [esp + 4], eax
// 0073f68c  89442408             mov dword ptr [esp + 8], eax
// 0073f690  89442418             mov dword ptr [esp + 0x18], eax
// 0073f694  8944241c             mov dword ptr [esp + 0x1c], eax
// 0073f698  89442420             mov dword ptr [esp + 0x20], eax
// 0073f69c  89442424             mov dword ptr [esp + 0x24], eax
// 0073f6a0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0073f6a4  8b500c               mov edx, dword ptr [eax + 0xc]
// 0073f6a7  894c2410             mov dword ptr [esp + 0x10], ecx
// 0073f6ab  8b4808               mov ecx, dword ptr [eax + 8]
// 0073f6ae  894c240c             mov dword ptr [esp + 0xc], ecx
// 0073f6b2  8d0c24               lea ecx, [esp]
// 0073f6b5  51                   push ecx
// 0073f6b6  8b4804               mov ecx, dword ptr [eax + 4]
// 0073f6b9  6ac2                 push -0x3e
// 0073f6bb  8954241c             mov dword ptr [esp + 0x1c], edx
// 0073f6bf  e89c8d0000           call 0x748460
// 0073f6c4  33c0                 xor eax, eax
// 0073f6c6  39442424             cmp dword ptr [esp + 0x24], eax
// 0073f6ca  0f94c0               sete al
// 0073f6cd  83c428               add esp, 0x28
// 0073f6d0  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?OnRequestEdit@CXTPReportRecordItem@@MAEHPAUXTP_REPORTRECORDITEM_ARGS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
