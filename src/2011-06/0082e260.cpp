// from server: 100% by auto
// roc 2011-06 0082e260  unit: CXTPPrintingDialog  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082e260
//
// 0082e260  8b442404             mov eax, dword ptr [esp + 4]
// 0082e264  56                   push esi
// 0082e265  50                   push eax
// 0082e266  8bf1                 mov esi, ecx
// 0082e268  e855ccfdff           call 0x80aec2
// 0082e26d  8b16                 mov edx, dword ptr [esi]
// 0082e26f  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 0082e275  8bce                 mov ecx, esi
// 0082e277  ffd0                 call eax
// 0082e279  85c0                 test eax, eax
// 0082e27b  7403                 je 0x82e280
// 0082e27d  8b4020               mov eax, dword ptr [eax + 0x20]
// 0082e280  50                   push eax
// 0082e281  ff15ec1ba400         call dword ptr [0xa41bec]
// 0082e287  85c0                 test eax, eax
// 0082e289  7413                 je 0x82e29e
// 0082e28b  8b16                 mov edx, dword ptr [esi]
// 0082e28d  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 0082e293  8bce                 mov ecx, esi
// 0082e295  ffd0                 call eax
// 0082e297  8bc8                 mov ecx, eax
// 0082e299  e862c1fdff           call 0x80a400
// 0082e29e  5e                   pop esi
// 0082e29f  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\ReportControl\XTPReportView.cpp (function ?OnSetFocus@CXTPReportView@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/ReportControl/XTPReportView.cpp
