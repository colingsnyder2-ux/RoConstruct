// from server: 100% by auto
// roc 2011-06 008b6f30  unit: CXTPReportInplaceList  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b6f30
//
// 008b6f30  8b442404             mov eax, dword ptr [esp + 4]
// 008b6f34  56                   push esi
// 008b6f35  33f6                 xor esi, esi
// 008b6f37  2bc6                 sub eax, esi
// 008b6f39  7421                 je 0x8b6f5c
// 008b6f3b  ba01000000           mov edx, 1
// 008b6f40  2bc2                 sub eax, edx
// 008b6f42  740e                 je 0x8b6f52
// 008b6f44  2bc2                 sub eax, edx
// 008b6f46  751a                 jne 0x8b6f62
// 008b6f48  897124               mov dword ptr [ecx + 0x24], esi
// 008b6f4b  895128               mov dword ptr [ecx + 0x28], edx
// 008b6f4e  5e                   pop esi
// 008b6f4f  c20400               ret 4
// 008b6f52  897128               mov dword ptr [ecx + 0x28], esi
// 008b6f55  895124               mov dword ptr [ecx + 0x24], edx
// 008b6f58  5e                   pop esi
// 008b6f59  c20400               ret 4
// 008b6f5c  897128               mov dword ptr [ecx + 0x28], esi
// 008b6f5f  897124               mov dword ptr [ecx + 0x24], esi
// 008b6f62  5e                   pop esi
// 008b6f63  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportNavigator.cpp (function ?SetMovePosition@CXTPReportNavigator@@IAEXW4XTPReportRowType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportNavigator.cpp
