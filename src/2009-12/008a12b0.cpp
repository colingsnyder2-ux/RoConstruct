// from server: 100% by auto
// roc 2009-12 008a12b0  unit: CXTPReportInplaceControl  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a12b0
//
// 008a12b0  53                   push ebx
// 008a12b1  56                   push esi
// 008a12b2  57                   push edi
// 008a12b3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008a12b7  33db                 xor ebx, ebx
// 008a12b9  8bf1                 mov esi, ecx
// 008a12bb  3bfb                 cmp edi, ebx
// 008a12bd  7449                 je 0x8a1308
// 008a12bf  8bcf                 mov ecx, edi
// 008a12c1  e85a94f7ff           call 0x81a720
// 008a12c6  8bce                 mov ecx, esi
// 008a12c8  e8e38df7ff           call 0x81a0b0
// 008a12cd  8b4710               mov eax, dword ptr [edi + 0x10]
// 008a12d0  894610               mov dword ptr [esi + 0x10], eax
// 008a12d3  8b4f04               mov ecx, dword ptr [edi + 4]
// 008a12d6  894e04               mov dword ptr [esi + 4], ecx
// 008a12d9  8b5708               mov edx, dword ptr [edi + 8]
// 008a12dc  895608               mov dword ptr [esi + 8], edx
// 008a12df  8b470c               mov eax, dword ptr [edi + 0xc]
// 008a12e2  89460c               mov dword ptr [esi + 0xc], eax
// 008a12e5  8b5714               mov edx, dword ptr [edi + 0x14]
// 008a12e8  8d4714               lea eax, [edi + 0x14]
// 008a12eb  8d4e14               lea ecx, [esi + 0x14]
// 008a12ee  8911                 mov dword ptr [ecx], edx
// 008a12f0  8b5004               mov edx, dword ptr [eax + 4]
// 008a12f3  895104               mov dword ptr [ecx + 4], edx
// 008a12f6  8b5008               mov edx, dword ptr [eax + 8]
// 008a12f9  5f                   pop edi
// 008a12fa  895108               mov dword ptr [ecx + 8], edx
// 008a12fd  8b400c               mov eax, dword ptr [eax + 0xc]
// 008a1300  5e                   pop esi
// 008a1301  89410c               mov dword ptr [ecx + 0xc], eax
// 008a1304  5b                   pop ebx
// 008a1305  c20400               ret 4
// 008a1308  e8a38df7ff           call 0x81a0b0
// 008a130d  5f                   pop edi
// 008a130e  895e10               mov dword ptr [esi + 0x10], ebx
// 008a1311  895e04               mov dword ptr [esi + 4], ebx
// 008a1314  895e08               mov dword ptr [esi + 8], ebx
// 008a1317  895e0c               mov dword ptr [esi + 0xc], ebx
// 008a131a  5e                   pop esi
// 008a131b  5b                   pop ebx
// 008a131c  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?SetItemArgs@CXTPReportInplaceControl@@MAEXPAUXTP_REPORTRECORDITEM_ARGS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
