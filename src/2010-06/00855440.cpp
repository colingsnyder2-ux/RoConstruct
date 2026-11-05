// from server: 100% by auto
// roc 2010-06 00855440  unit: CXTPReportInplaceControl  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00855440
//
// 00855440  53                   push ebx
// 00855441  56                   push esi
// 00855442  57                   push edi
// 00855443  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00855447  33db                 xor ebx, ebx
// 00855449  8bf1                 mov esi, ecx
// 0085544b  3bfb                 cmp edi, ebx
// 0085544d  7449                 je 0x855498
// 0085544f  8bcf                 mov ecx, edi
// 00855451  e87a93f7ff           call 0x7ce7d0
// 00855456  8bce                 mov ecx, esi
// 00855458  e8138df7ff           call 0x7ce170
// 0085545d  8b4710               mov eax, dword ptr [edi + 0x10]
// 00855460  894610               mov dword ptr [esi + 0x10], eax
// 00855463  8b4f04               mov ecx, dword ptr [edi + 4]
// 00855466  894e04               mov dword ptr [esi + 4], ecx
// 00855469  8b5708               mov edx, dword ptr [edi + 8]
// 0085546c  895608               mov dword ptr [esi + 8], edx
// 0085546f  8b470c               mov eax, dword ptr [edi + 0xc]
// 00855472  89460c               mov dword ptr [esi + 0xc], eax
// 00855475  8b5714               mov edx, dword ptr [edi + 0x14]
// 00855478  8d4714               lea eax, [edi + 0x14]
// 0085547b  8d4e14               lea ecx, [esi + 0x14]
// 0085547e  8911                 mov dword ptr [ecx], edx
// 00855480  8b5004               mov edx, dword ptr [eax + 4]
// 00855483  895104               mov dword ptr [ecx + 4], edx
// 00855486  8b5008               mov edx, dword ptr [eax + 8]
// 00855489  5f                   pop edi
// 0085548a  895108               mov dword ptr [ecx + 8], edx
// 0085548d  8b400c               mov eax, dword ptr [eax + 0xc]
// 00855490  5e                   pop esi
// 00855491  89410c               mov dword ptr [ecx + 0xc], eax
// 00855494  5b                   pop ebx
// 00855495  c20400               ret 4
// 00855498  e8d38cf7ff           call 0x7ce170
// 0085549d  5f                   pop edi
// 0085549e  895e10               mov dword ptr [esi + 0x10], ebx
// 008554a1  895e04               mov dword ptr [esi + 4], ebx
// 008554a4  895e08               mov dword ptr [esi + 8], ebx
// 008554a7  895e0c               mov dword ptr [esi + 0xc], ebx
// 008554aa  5e                   pop esi
// 008554ab  5b                   pop ebx
// 008554ac  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?SetItemArgs@CXTPReportInplaceControl@@MAEXPAUXTP_REPORTRECORDITEM_ARGS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
