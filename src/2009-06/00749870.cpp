// from server: 100% by auto
// roc 2009-06 00749870  unit: CXTPReportControl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00749870
//
// 00749870  83ec1c               sub esp, 0x1c
// 00749873  8b542424             mov edx, dword ptr [esp + 0x24]
// 00749877  33c0                 xor eax, eax
// 00749879  56                   push esi
// 0074987a  8b742424             mov esi, dword ptr [esp + 0x24]
// 0074987e  89442414             mov dword ptr [esp + 0x14], eax
// 00749882  89442410             mov dword ptr [esp + 0x10], eax
// 00749886  89442418             mov dword ptr [esp + 0x18], eax
// 0074988a  8944241c             mov dword ptr [esp + 0x1c], eax
// 0074988e  89442404             mov dword ptr [esp + 4], eax
// 00749892  89442408             mov dword ptr [esp + 8], eax
// 00749896  8944240c             mov dword ptr [esp + 0xc], eax
// 0074989a  8b06                 mov eax, dword ptr [esi]
// 0074989c  89542414             mov dword ptr [esp + 0x14], edx
// 007498a0  8d542404             lea edx, [esp + 4]
// 007498a4  89442410             mov dword ptr [esp + 0x10], eax
// 007498a8  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007498ac  52                   push edx
// 007498ad  6abb                 push -0x45
// 007498af  89442420             mov dword ptr [esp + 0x20], eax
// 007498b3  c744242400000000     mov dword ptr [esp + 0x24], 0
// 007498bb  e8a0ebffff           call 0x748460
// 007498c0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007498c4  8906                 mov dword ptr [esi], eax
// 007498c6  33c0                 xor eax, eax
// 007498c8  3944241c             cmp dword ptr [esp + 0x1c], eax
// 007498cc  5e                   pop esi
// 007498cd  0f94c0               sete al
// 007498d0  83c41c               add esp, 0x1c
// 007498d3  c20c00               ret 0xc
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnPreviewKeyDown@CXTPReportControl@@MAEHAAIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
