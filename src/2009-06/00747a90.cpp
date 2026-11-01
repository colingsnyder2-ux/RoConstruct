// from server: 100% by auto
// roc 2009-06 00747a90  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 248 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00747a90
//
// 00747a90  8b442404             mov eax, dword ptr [esp + 4]
// 00747a94  85c0                 test eax, eax
// 00747a96  0f84eb000000         je 0x747b87
// 00747a9c  8d48f8               lea ecx, [eax - 8]
// 00747a9f  8b01                 mov eax, dword ptr [ecx]
// 00747aa1  8b5004               mov edx, dword ptr [eax + 4]
// 00747aa4  895104               mov dword ptr [ecx + 4], edx
// 00747aa7  894804               mov dword ptr [eax + 4], ecx
// 00747aaa  8b01                 mov eax, dword ptr [ecx]
// 00747aac  ff08                 dec dword ptr [eax]
// 00747aae  ff0d4c1aa500         dec dword ptr [0xa51a4c]
// 00747ab4  83790400             cmp dword ptr [ecx + 4], 0
// 00747ab8  7565                 jne 0x747b1f
// 00747aba  8b01                 mov eax, dword ptr [ecx]
// 00747abc  8b5008               mov edx, dword ptr [eax + 8]
// 00747abf  56                   push esi
// 00747ac0  85d2                 test edx, edx
// 00747ac2  7406                 je 0x747aca
// 00747ac4  8b700c               mov esi, dword ptr [eax + 0xc]
// 00747ac7  89720c               mov dword ptr [edx + 0xc], esi
// 00747aca  8b500c               mov edx, dword ptr [eax + 0xc]
// 00747acd  85d2                 test edx, edx
// 00747acf  7406                 je 0x747ad7
// 00747ad1  8b7008               mov esi, dword ptr [eax + 8]
// 00747ad4  897208               mov dword ptr [edx + 8], esi
// 00747ad7  5e                   pop esi
// 00747ad8  39055c1aa500         cmp dword ptr [0xa51a5c], eax
// 00747ade  7510                 jne 0x747af0
// 00747ae0  8b5008               mov edx, dword ptr [eax + 8]
// 00747ae3  85d2                 test edx, edx
// 00747ae5  7503                 jne 0x747aea
// 00747ae7  8b500c               mov edx, dword ptr [eax + 0xc]
// 00747aea  89155c1aa500         mov dword ptr [0xa51a5c], edx
// 00747af0  8b15581aa500         mov edx, dword ptr [0xa51a58]
// 00747af6  89500c               mov dword ptr [eax + 0xc], edx
// 00747af9  8b15581aa500         mov edx, dword ptr [0xa51a58]
// 00747aff  85d2                 test edx, edx
// 00747b01  7405                 je 0x747b08
// 00747b03  8b5208               mov edx, dword ptr [edx + 8]
// 00747b06  eb02                 jmp 0x747b0a
// 00747b08  33d2                 xor edx, edx
// 00747b0a  895008               mov dword ptr [eax + 8], edx
// 00747b0d  8b15581aa500         mov edx, dword ptr [0xa51a58]
// 00747b13  85d2                 test edx, edx
// 00747b15  7403                 je 0x747b1a
// 00747b17  894208               mov dword ptr [edx + 8], eax
// 00747b1a  a3581aa500           mov dword ptr [0xa51a58], eax
// 00747b1f  8b09                 mov ecx, dword ptr [ecx]
// 00747b21  833900               cmp dword ptr [ecx], 0
// 00747b24  7561                 jne 0x747b87
// 00747b26  833d501aa50000       cmp dword ptr [0xa51a50], 0
// 00747b2d  7458                 je 0x747b87
// 00747b2f  8b4108               mov eax, dword ptr [ecx + 8]
// 00747b32  8bd0                 mov edx, eax
// 00747b34  85c0                 test eax, eax
// 00747b36  7503                 jne 0x747b3b
// 00747b38  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00747b3b  390d581aa500         cmp dword ptr [0xa51a58], ecx
// 00747b41  750d                 jne 0x747b50
// 00747b43  85d2                 test edx, edx
// 00747b45  7409                 je 0x747b50
// 00747b47  833d541aa50000       cmp dword ptr [0xa51a54], 0
// 00747b4e  7437                 je 0x747b87
// 00747b50  85c0                 test eax, eax
// 00747b52  7406                 je 0x747b5a
// 00747b54  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00747b57  89500c               mov dword ptr [eax + 0xc], edx
// 00747b5a  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00747b5d  85c0                 test eax, eax
// 00747b5f  7406                 je 0x747b67
// 00747b61  8b5108               mov edx, dword ptr [ecx + 8]
// 00747b64  895008               mov dword ptr [eax + 8], edx
// 00747b67  390d581aa500         cmp dword ptr [0xa51a58], ecx
// 00747b6d  750f                 jne 0x747b7e
// 00747b6f  8b4108               mov eax, dword ptr [ecx + 8]
// 00747b72  85c0                 test eax, eax
// 00747b74  7503                 jne 0x747b79
// 00747b76  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00747b79  a3581aa500           mov dword ptr [0xa51a58], eax
// 00747b7e  894c2404             mov dword ptr [esp + 4], ecx
// 00747b82  e919bfffff           jmp 0x743aa0
// 00747b87  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?FreeData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
