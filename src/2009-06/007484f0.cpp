// from server: 100% by auto
// roc 2009-06 007484f0  unit: CXTPReportControl  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007484f0
//
// 007484f0  83ec24               sub esp, 0x24
// 007484f3  56                   push esi
// 007484f4  8bf1                 mov esi, ecx
// 007484f6  8b4620               mov eax, dword ptr [esi + 0x20]
// 007484f9  50                   push eax
// 007484fa  ff15e0ed8900         call dword ptr [0x89ede0]
// 00748500  85c0                 test eax, eax
// 00748502  7507                 jne 0x74850b
// 00748504  5e                   pop esi
// 00748505  83c424               add esp, 0x24
// 00748508  c21800               ret 0x18
// 0074850b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0074850f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00748513  8b542434             mov edx, dword ptr [esp + 0x34]
// 00748517  894c2414             mov dword ptr [esp + 0x14], ecx
// 0074851b  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0074851f  89442410             mov dword ptr [esp + 0x10], eax
// 00748523  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00748527  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0074852b  33c9                 xor ecx, ecx
// 0074852d  89542418             mov dword ptr [esp + 0x18], edx
// 00748531  894c2420             mov dword ptr [esp + 0x20], ecx
// 00748535  894c2424             mov dword ptr [esp + 0x24], ecx
// 00748539  3bc1                 cmp eax, ecx
// 0074853b  740d                 je 0x74854a
// 0074853d  8b10                 mov edx, dword ptr [eax]
// 0074853f  8b4004               mov eax, dword ptr [eax + 4]
// 00748542  89542420             mov dword ptr [esp + 0x20], edx
// 00748546  89442424             mov dword ptr [esp + 0x24], eax
// 0074854a  8b542438             mov edx, dword ptr [esp + 0x38]
// 0074854e  8d4c2404             lea ecx, [esp + 4]
// 00748552  51                   push ecx
// 00748553  52                   push edx
// 00748554  8bce                 mov ecx, esi
// 00748556  e805ffffff           call 0x748460
// 0074855b  5e                   pop esi
// 0074855c  83c424               add esp, 0x24
// 0074855f  c21800               ret 0x18
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?SendMessageToParent@CXTPReportControl@@QBEJPAVCXTPReportRow@@PAVCXTPReportRecordItem@@PAVCXTPReportColumn@@IPAVCPoint@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
