// from server: 100% by auto
// roc 2010-06 007d86d0  unit: CXTPReportControl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d86d0
//
// 007d86d0  83ec1c               sub esp, 0x1c
// 007d86d3  8b542424             mov edx, dword ptr [esp + 0x24]
// 007d86d7  33c0                 xor eax, eax
// 007d86d9  56                   push esi
// 007d86da  8b742424             mov esi, dword ptr [esp + 0x24]
// 007d86de  89442414             mov dword ptr [esp + 0x14], eax
// 007d86e2  89442410             mov dword ptr [esp + 0x10], eax
// 007d86e6  89442418             mov dword ptr [esp + 0x18], eax
// 007d86ea  8944241c             mov dword ptr [esp + 0x1c], eax
// 007d86ee  89442404             mov dword ptr [esp + 4], eax
// 007d86f2  89442408             mov dword ptr [esp + 8], eax
// 007d86f6  8944240c             mov dword ptr [esp + 0xc], eax
// 007d86fa  8b06                 mov eax, dword ptr [esi]
// 007d86fc  89542414             mov dword ptr [esp + 0x14], edx
// 007d8700  8d542404             lea edx, [esp + 4]
// 007d8704  89442410             mov dword ptr [esp + 0x10], eax
// 007d8708  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007d870c  52                   push edx
// 007d870d  6abb                 push -0x45
// 007d870f  89442420             mov dword ptr [esp + 0x20], eax
// 007d8713  c744242400000000     mov dword ptr [esp + 0x24], 0
// 007d871b  e8b0ebffff           call 0x7d72d0
// 007d8720  8b442410             mov eax, dword ptr [esp + 0x10]
// 007d8724  8906                 mov dword ptr [esi], eax
// 007d8726  33c0                 xor eax, eax
// 007d8728  3944241c             cmp dword ptr [esp + 0x1c], eax
// 007d872c  5e                   pop esi
// 007d872d  0f94c0               sete al
// 007d8730  83c41c               add esp, 0x1c
// 007d8733  c20c00               ret 0xc
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnPreviewKeyDown@CXTPReportControl@@MAEHAAIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
