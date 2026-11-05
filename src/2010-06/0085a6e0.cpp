// from server: 100% by auto
// roc 2010-06 0085a6e0  unit: CXTPReportTip  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085a6e0
//
// 0085a6e0  8b442404             mov eax, dword ptr [esp + 4]
// 0085a6e4  56                   push esi
// 0085a6e5  33f6                 xor esi, esi
// 0085a6e7  2bc6                 sub eax, esi
// 0085a6e9  7421                 je 0x85a70c
// 0085a6eb  ba01000000           mov edx, 1
// 0085a6f0  2bc2                 sub eax, edx
// 0085a6f2  740e                 je 0x85a702
// 0085a6f4  2bc2                 sub eax, edx
// 0085a6f6  751a                 jne 0x85a712
// 0085a6f8  897124               mov dword ptr [ecx + 0x24], esi
// 0085a6fb  895128               mov dword ptr [ecx + 0x28], edx
// 0085a6fe  5e                   pop esi
// 0085a6ff  c20400               ret 4
// 0085a702  897128               mov dword ptr [ecx + 0x28], esi
// 0085a705  895124               mov dword ptr [ecx + 0x24], edx
// 0085a708  5e                   pop esi
// 0085a709  c20400               ret 4
// 0085a70c  897128               mov dword ptr [ecx + 0x28], esi
// 0085a70f  897124               mov dword ptr [ecx + 0x24], esi
// 0085a712  5e                   pop esi
// 0085a713  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportNavigator.cpp (function ?SetMovePosition@CXTPReportNavigator@@IAEXW4XTPReportRowType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportNavigator.cpp
