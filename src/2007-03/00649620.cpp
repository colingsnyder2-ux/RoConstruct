// from server: 100% by auto
// roc 2007-03 00649620  unit: seg_00640000  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00649620
//
// 00649620  83ec1c               sub esp, 0x1c
// 00649623  8b542424             mov edx, dword ptr [esp + 0x24]
// 00649627  33c0                 xor eax, eax
// 00649629  56                   push esi
// 0064962a  8b742424             mov esi, dword ptr [esp + 0x24]
// 0064962e  89442414             mov dword ptr [esp + 0x14], eax
// 00649632  89442410             mov dword ptr [esp + 0x10], eax
// 00649636  89442418             mov dword ptr [esp + 0x18], eax
// 0064963a  8944241c             mov dword ptr [esp + 0x1c], eax
// 0064963e  89442404             mov dword ptr [esp + 4], eax
// 00649642  89442408             mov dword ptr [esp + 8], eax
// 00649646  8944240c             mov dword ptr [esp + 0xc], eax
// 0064964a  8b06                 mov eax, dword ptr [esi]
// 0064964c  89542414             mov dword ptr [esp + 0x14], edx
// 00649650  8d542404             lea edx, [esp + 4]
// 00649654  89442410             mov dword ptr [esp + 0x10], eax
// 00649658  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0064965c  52                   push edx
// 0064965d  6abb                 push -0x45
// 0064965f  89442420             mov dword ptr [esp + 0x20], eax
// 00649663  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0064966b  e840f6ffff           call 0x648cb0
// 00649670  8b442410             mov eax, dword ptr [esp + 0x10]
// 00649674  8906                 mov dword ptr [esi], eax
// 00649676  33c0                 xor eax, eax
// 00649678  3944241c             cmp dword ptr [esp + 0x1c], eax
// 0064967c  5e                   pop esi
// 0064967d  0f94c0               sete al
// 00649680  83c41c               add esp, 0x1c
// 00649683  c20c00               ret 0xc
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnPreviewKeyDown@CXTPReportControl@@MAEHAAIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
