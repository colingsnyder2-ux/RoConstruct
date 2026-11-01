// from server: 100% by auto
// roc 2009-12 00824660  unit: CXTPReportControl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00824660
//
// 00824660  83ec1c               sub esp, 0x1c
// 00824663  8b542424             mov edx, dword ptr [esp + 0x24]
// 00824667  33c0                 xor eax, eax
// 00824669  56                   push esi
// 0082466a  8b742424             mov esi, dword ptr [esp + 0x24]
// 0082466e  89442414             mov dword ptr [esp + 0x14], eax
// 00824672  89442410             mov dword ptr [esp + 0x10], eax
// 00824676  89442418             mov dword ptr [esp + 0x18], eax
// 0082467a  8944241c             mov dword ptr [esp + 0x1c], eax
// 0082467e  89442404             mov dword ptr [esp + 4], eax
// 00824682  89442408             mov dword ptr [esp + 8], eax
// 00824686  8944240c             mov dword ptr [esp + 0xc], eax
// 0082468a  8b06                 mov eax, dword ptr [esi]
// 0082468c  89542414             mov dword ptr [esp + 0x14], edx
// 00824690  8d542404             lea edx, [esp + 4]
// 00824694  89442410             mov dword ptr [esp + 0x10], eax
// 00824698  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0082469c  52                   push edx
// 0082469d  6abb                 push -0x45
// 0082469f  89442420             mov dword ptr [esp + 0x20], eax
// 008246a3  c744242400000000     mov dword ptr [esp + 0x24], 0
// 008246ab  e8c0ebffff           call 0x823270
// 008246b0  8b442410             mov eax, dword ptr [esp + 0x10]
// 008246b4  8906                 mov dword ptr [esi], eax
// 008246b6  33c0                 xor eax, eax
// 008246b8  3944241c             cmp dword ptr [esp + 0x1c], eax
// 008246bc  5e                   pop esi
// 008246bd  0f94c0               sete al
// 008246c0  83c41c               add esp, 0x1c
// 008246c3  c20c00               ret 0xc
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnPreviewKeyDown@CXTPReportControl@@MAEHAAIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
