// from server: 100% by auto
// roc 2010-06 00856f40  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00856f40
//
// 00856f40  56                   push esi
// 00856f41  57                   push edi
// 00856f42  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00856f46  8bf1                 mov esi, ecx
// 00856f48  8b06                 mov eax, dword ptr [esi]
// 00856f4a  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 00856f50  57                   push edi
// 00856f51  ffd2                 call edx
// 00856f53  85c0                 test eax, eax
// 00856f55  7d0a                 jge 0x856f61
// 00856f57  8b06                 mov eax, dword ptr [esi]
// 00856f59  8b5078               mov edx, dword ptr [eax + 0x78]
// 00856f5c  57                   push edi
// 00856f5d  8bce                 mov ecx, esi
// 00856f5f  ffd2                 call edx
// 00856f61  5f                   pop edi
// 00856f62  5e                   pop esi
// 00856f63  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPCalendarEventLabel.cpp (function ?AddIfNeed@?$CXTPArrayT@IIJ@@UAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPCalendarEventLabel.cpp
