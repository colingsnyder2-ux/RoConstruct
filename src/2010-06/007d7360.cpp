// from server: 100% by auto
// roc 2010-06 007d7360  unit: CXTPReportControl  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d7360
//
// 007d7360  83ec24               sub esp, 0x24
// 007d7363  56                   push esi
// 007d7364  8bf1                 mov esi, ecx
// 007d7366  8b4620               mov eax, dword ptr [esi + 0x20]
// 007d7369  50                   push eax
// 007d736a  ff1528bc9e00         call dword ptr [0x9ebc28]
// 007d7370  85c0                 test eax, eax
// 007d7372  7507                 jne 0x7d737b
// 007d7374  5e                   pop esi
// 007d7375  83c424               add esp, 0x24
// 007d7378  c21800               ret 0x18
// 007d737b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007d737f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007d7383  8b542434             mov edx, dword ptr [esp + 0x34]
// 007d7387  894c2414             mov dword ptr [esp + 0x14], ecx
// 007d738b  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007d738f  89442410             mov dword ptr [esp + 0x10], eax
// 007d7393  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 007d7397  894c241c             mov dword ptr [esp + 0x1c], ecx
// 007d739b  33c9                 xor ecx, ecx
// 007d739d  89542418             mov dword ptr [esp + 0x18], edx
// 007d73a1  894c2420             mov dword ptr [esp + 0x20], ecx
// 007d73a5  894c2424             mov dword ptr [esp + 0x24], ecx
// 007d73a9  3bc1                 cmp eax, ecx
// 007d73ab  740d                 je 0x7d73ba
// 007d73ad  8b10                 mov edx, dword ptr [eax]
// 007d73af  8b4004               mov eax, dword ptr [eax + 4]
// 007d73b2  89542420             mov dword ptr [esp + 0x20], edx
// 007d73b6  89442424             mov dword ptr [esp + 0x24], eax
// 007d73ba  8b542438             mov edx, dword ptr [esp + 0x38]
// 007d73be  8d4c2404             lea ecx, [esp + 4]
// 007d73c2  51                   push ecx
// 007d73c3  52                   push edx
// 007d73c4  8bce                 mov ecx, esi
// 007d73c6  e805ffffff           call 0x7d72d0
// 007d73cb  5e                   pop esi
// 007d73cc  83c424               add esp, 0x24
// 007d73cf  c21800               ret 0x18
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?SendMessageToParent@CXTPReportControl@@QBEJPAVCXTPReportRow@@PAVCXTPReportRecordItem@@PAVCXTPReportColumn@@IPAVCPoint@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
