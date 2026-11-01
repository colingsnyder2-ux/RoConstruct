// from server: 100% by auto
// roc 2009-06 007cb790  unit: CXTPReportTip  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cb790
//
// 007cb790  8b442404             mov eax, dword ptr [esp + 4]
// 007cb794  56                   push esi
// 007cb795  33f6                 xor esi, esi
// 007cb797  2bc6                 sub eax, esi
// 007cb799  7421                 je 0x7cb7bc
// 007cb79b  ba01000000           mov edx, 1
// 007cb7a0  2bc2                 sub eax, edx
// 007cb7a2  740e                 je 0x7cb7b2
// 007cb7a4  2bc2                 sub eax, edx
// 007cb7a6  751a                 jne 0x7cb7c2
// 007cb7a8  897124               mov dword ptr [ecx + 0x24], esi
// 007cb7ab  895128               mov dword ptr [ecx + 0x28], edx
// 007cb7ae  5e                   pop esi
// 007cb7af  c20400               ret 4
// 007cb7b2  897128               mov dword ptr [ecx + 0x28], esi
// 007cb7b5  895124               mov dword ptr [ecx + 0x24], edx
// 007cb7b8  5e                   pop esi
// 007cb7b9  c20400               ret 4
// 007cb7bc  897128               mov dword ptr [ecx + 0x28], esi
// 007cb7bf  897124               mov dword ptr [ecx + 0x24], esi
// 007cb7c2  5e                   pop esi
// 007cb7c3  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportNavigator.cpp (function ?SetMovePosition@CXTPReportNavigator@@IAEXW4XTPReportRowType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportNavigator.cpp
