// from server: 100% by auto
// roc 2011-06 008b8200  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b8200
//
// 008b8200  56                   push esi
// 008b8201  57                   push edi
// 008b8202  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008b8206  8bf1                 mov esi, ecx
// 008b8208  8b06                 mov eax, dword ptr [esi]
// 008b820a  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 008b8210  57                   push edi
// 008b8211  ffd2                 call edx
// 008b8213  85c0                 test eax, eax
// 008b8215  7d0a                 jge 0x8b8221
// 008b8217  8b06                 mov eax, dword ptr [esi]
// 008b8219  8b5078               mov edx, dword ptr [eax + 0x78]
// 008b821c  57                   push edi
// 008b821d  8bce                 mov ecx, esi
// 008b821f  ffd2                 call edx
// 008b8221  5f                   pop edi
// 008b8222  5e                   pop esi
// 008b8223  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarEventLabel.cpp (function ?AddIfNeed@?$CXTPArrayT@IIJ@@UAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarEventLabel.cpp
