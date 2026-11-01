// from server: 100% by auto
// roc 2009-12 00823300  unit: CXTPReportControl  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823300
//
// 00823300  83ec24               sub esp, 0x24
// 00823303  56                   push esi
// 00823304  8bf1                 mov esi, ecx
// 00823306  8b4620               mov eax, dword ptr [esi + 0x20]
// 00823309  50                   push eax
// 0082330a  ff1584cc9800         call dword ptr [0x98cc84]
// 00823310  85c0                 test eax, eax
// 00823312  7507                 jne 0x82331b
// 00823314  5e                   pop esi
// 00823315  83c424               add esp, 0x24
// 00823318  c21800               ret 0x18
// 0082331b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0082331f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00823323  8b542434             mov edx, dword ptr [esp + 0x34]
// 00823327  894c2414             mov dword ptr [esp + 0x14], ecx
// 0082332b  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0082332f  89442410             mov dword ptr [esp + 0x10], eax
// 00823333  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00823337  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0082333b  33c9                 xor ecx, ecx
// 0082333d  89542418             mov dword ptr [esp + 0x18], edx
// 00823341  894c2420             mov dword ptr [esp + 0x20], ecx
// 00823345  894c2424             mov dword ptr [esp + 0x24], ecx
// 00823349  3bc1                 cmp eax, ecx
// 0082334b  740d                 je 0x82335a
// 0082334d  8b10                 mov edx, dword ptr [eax]
// 0082334f  8b4004               mov eax, dword ptr [eax + 4]
// 00823352  89542420             mov dword ptr [esp + 0x20], edx
// 00823356  89442424             mov dword ptr [esp + 0x24], eax
// 0082335a  8b542438             mov edx, dword ptr [esp + 0x38]
// 0082335e  8d4c2404             lea ecx, [esp + 4]
// 00823362  51                   push ecx
// 00823363  52                   push edx
// 00823364  8bce                 mov ecx, esi
// 00823366  e805ffffff           call 0x823270
// 0082336b  5e                   pop esi
// 0082336c  83c424               add esp, 0x24
// 0082336f  c21800               ret 0x18
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?SendMessageToParent@CXTPReportControl@@QBEJPAVCXTPReportRow@@PAVCXTPReportRecordItem@@PAVCXTPReportColumn@@IPAVCPoint@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
