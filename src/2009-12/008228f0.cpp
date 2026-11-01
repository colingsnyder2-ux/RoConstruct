// from server: 100% by auto
// roc 2009-12 008228f0  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 248 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008228f0
//
// 008228f0  8b442404             mov eax, dword ptr [esp + 4]
// 008228f4  85c0                 test eax, eax
// 008228f6  0f84eb000000         je 0x8229e7
// 008228fc  8d48f8               lea ecx, [eax - 8]
// 008228ff  8b01                 mov eax, dword ptr [ecx]
// 00822901  8b5004               mov edx, dword ptr [eax + 4]
// 00822904  895104               mov dword ptr [ecx + 4], edx
// 00822907  894804               mov dword ptr [eax + 4], ecx
// 0082290a  8b01                 mov eax, dword ptr [ecx]
// 0082290c  ff08                 dec dword ptr [eax]
// 0082290e  ff0da8aeb900         dec dword ptr [0xb9aea8]
// 00822914  83790400             cmp dword ptr [ecx + 4], 0
// 00822918  7565                 jne 0x82297f
// 0082291a  8b01                 mov eax, dword ptr [ecx]
// 0082291c  8b5008               mov edx, dword ptr [eax + 8]
// 0082291f  56                   push esi
// 00822920  85d2                 test edx, edx
// 00822922  7406                 je 0x82292a
// 00822924  8b700c               mov esi, dword ptr [eax + 0xc]
// 00822927  89720c               mov dword ptr [edx + 0xc], esi
// 0082292a  8b500c               mov edx, dword ptr [eax + 0xc]
// 0082292d  85d2                 test edx, edx
// 0082292f  7406                 je 0x822937
// 00822931  8b7008               mov esi, dword ptr [eax + 8]
// 00822934  897208               mov dword ptr [edx + 8], esi
// 00822937  5e                   pop esi
// 00822938  3905b8aeb900         cmp dword ptr [0xb9aeb8], eax
// 0082293e  7510                 jne 0x822950
// 00822940  8b5008               mov edx, dword ptr [eax + 8]
// 00822943  85d2                 test edx, edx
// 00822945  7503                 jne 0x82294a
// 00822947  8b500c               mov edx, dword ptr [eax + 0xc]
// 0082294a  8915b8aeb900         mov dword ptr [0xb9aeb8], edx
// 00822950  8b15b4aeb900         mov edx, dword ptr [0xb9aeb4]
// 00822956  89500c               mov dword ptr [eax + 0xc], edx
// 00822959  8b15b4aeb900         mov edx, dword ptr [0xb9aeb4]
// 0082295f  85d2                 test edx, edx
// 00822961  7405                 je 0x822968
// 00822963  8b5208               mov edx, dword ptr [edx + 8]
// 00822966  eb02                 jmp 0x82296a
// 00822968  33d2                 xor edx, edx
// 0082296a  895008               mov dword ptr [eax + 8], edx
// 0082296d  8b15b4aeb900         mov edx, dword ptr [0xb9aeb4]
// 00822973  85d2                 test edx, edx
// 00822975  7403                 je 0x82297a
// 00822977  894208               mov dword ptr [edx + 8], eax
// 0082297a  a3b4aeb900           mov dword ptr [0xb9aeb4], eax
// 0082297f  8b09                 mov ecx, dword ptr [ecx]
// 00822981  833900               cmp dword ptr [ecx], 0
// 00822984  7561                 jne 0x8229e7
// 00822986  833dacaeb90000       cmp dword ptr [0xb9aeac], 0
// 0082298d  7458                 je 0x8229e7
// 0082298f  8b4108               mov eax, dword ptr [ecx + 8]
// 00822992  8bd0                 mov edx, eax
// 00822994  85c0                 test eax, eax
// 00822996  7503                 jne 0x82299b
// 00822998  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0082299b  390db4aeb900         cmp dword ptr [0xb9aeb4], ecx
// 008229a1  750d                 jne 0x8229b0
// 008229a3  85d2                 test edx, edx
// 008229a5  7409                 je 0x8229b0
// 008229a7  833db0aeb90000       cmp dword ptr [0xb9aeb0], 0
// 008229ae  7437                 je 0x8229e7
// 008229b0  85c0                 test eax, eax
// 008229b2  7406                 je 0x8229ba
// 008229b4  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008229b7  89500c               mov dword ptr [eax + 0xc], edx
// 008229ba  8b410c               mov eax, dword ptr [ecx + 0xc]
// 008229bd  85c0                 test eax, eax
// 008229bf  7406                 je 0x8229c7
// 008229c1  8b5108               mov edx, dword ptr [ecx + 8]
// 008229c4  895008               mov dword ptr [eax + 8], edx
// 008229c7  390db4aeb900         cmp dword ptr [0xb9aeb4], ecx
// 008229cd  750f                 jne 0x8229de
// 008229cf  8b4108               mov eax, dword ptr [ecx + 8]
// 008229d2  85c0                 test eax, eax
// 008229d4  7503                 jne 0x8229d9
// 008229d6  8b410c               mov eax, dword ptr [ecx + 0xc]
// 008229d9  a3b4aeb900           mov dword ptr [0xb9aeb4], eax
// 008229de  894c2404             mov dword ptr [esp + 4], ecx
// 008229e2  e979bfffff           jmp 0x81e960
// 008229e7  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?FreeData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
