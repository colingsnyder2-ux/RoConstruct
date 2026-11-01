// from server: 100% by auto
// roc 2009-12 008a6590  unit: CXTPReportTip  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a6590
//
// 008a6590  8b442404             mov eax, dword ptr [esp + 4]
// 008a6594  56                   push esi
// 008a6595  33f6                 xor esi, esi
// 008a6597  2bc6                 sub eax, esi
// 008a6599  7421                 je 0x8a65bc
// 008a659b  ba01000000           mov edx, 1
// 008a65a0  2bc2                 sub eax, edx
// 008a65a2  740e                 je 0x8a65b2
// 008a65a4  2bc2                 sub eax, edx
// 008a65a6  751a                 jne 0x8a65c2
// 008a65a8  897124               mov dword ptr [ecx + 0x24], esi
// 008a65ab  895128               mov dword ptr [ecx + 0x28], edx
// 008a65ae  5e                   pop esi
// 008a65af  c20400               ret 4
// 008a65b2  897128               mov dword ptr [ecx + 0x28], esi
// 008a65b5  895124               mov dword ptr [ecx + 0x24], edx
// 008a65b8  5e                   pop esi
// 008a65b9  c20400               ret 4
// 008a65bc  897128               mov dword ptr [ecx + 0x28], esi
// 008a65bf  897124               mov dword ptr [ecx + 0x24], esi
// 008a65c2  5e                   pop esi
// 008a65c3  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportNavigator.cpp (function ?SetMovePosition@CXTPReportNavigator@@IAEXW4XTPReportRowType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportNavigator.cpp
