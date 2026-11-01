// from server: 100% by auto
// roc 2009-06 007c64b0  unit: CXTPReportInplaceControl  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c64b0
//
// 007c64b0  53                   push ebx
// 007c64b1  56                   push esi
// 007c64b2  57                   push edi
// 007c64b3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007c64b7  33db                 xor ebx, ebx
// 007c64b9  8bf1                 mov esi, ecx
// 007c64bb  3bfb                 cmp edi, ebx
// 007c64bd  7449                 je 0x7c6508
// 007c64bf  8bcf                 mov ecx, edi
// 007c64c1  e84a93f7ff           call 0x73f810
// 007c64c6  8bce                 mov ecx, esi
// 007c64c8  e8c38cf7ff           call 0x73f190
// 007c64cd  8b4710               mov eax, dword ptr [edi + 0x10]
// 007c64d0  894610               mov dword ptr [esi + 0x10], eax
// 007c64d3  8b4f04               mov ecx, dword ptr [edi + 4]
// 007c64d6  894e04               mov dword ptr [esi + 4], ecx
// 007c64d9  8b5708               mov edx, dword ptr [edi + 8]
// 007c64dc  895608               mov dword ptr [esi + 8], edx
// 007c64df  8b470c               mov eax, dword ptr [edi + 0xc]
// 007c64e2  89460c               mov dword ptr [esi + 0xc], eax
// 007c64e5  8b5714               mov edx, dword ptr [edi + 0x14]
// 007c64e8  8d4714               lea eax, [edi + 0x14]
// 007c64eb  8d4e14               lea ecx, [esi + 0x14]
// 007c64ee  8911                 mov dword ptr [ecx], edx
// 007c64f0  8b5004               mov edx, dword ptr [eax + 4]
// 007c64f3  895104               mov dword ptr [ecx + 4], edx
// 007c64f6  8b5008               mov edx, dword ptr [eax + 8]
// 007c64f9  5f                   pop edi
// 007c64fa  895108               mov dword ptr [ecx + 8], edx
// 007c64fd  8b400c               mov eax, dword ptr [eax + 0xc]
// 007c6500  5e                   pop esi
// 007c6501  89410c               mov dword ptr [ecx + 0xc], eax
// 007c6504  5b                   pop ebx
// 007c6505  c20400               ret 4
// 007c6508  e8838cf7ff           call 0x73f190
// 007c650d  5f                   pop edi
// 007c650e  895e10               mov dword ptr [esi + 0x10], ebx
// 007c6511  895e04               mov dword ptr [esi + 4], ebx
// 007c6514  895e08               mov dword ptr [esi + 8], ebx
// 007c6517  895e0c               mov dword ptr [esi + 0xc], ebx
// 007c651a  5e                   pop esi
// 007c651b  5b                   pop ebx
// 007c651c  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?SetItemArgs@CXTPReportInplaceControl@@MAEXPAUXTP_REPORTRECORDITEM_ARGS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
