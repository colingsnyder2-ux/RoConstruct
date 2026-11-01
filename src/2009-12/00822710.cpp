// from server: 100% by auto
// roc 2009-12 00822710  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 248 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00822710
//
// 00822710  8b442404             mov eax, dword ptr [esp + 4]
// 00822714  85c0                 test eax, eax
// 00822716  0f84eb000000         je 0x822807
// 0082271c  8d48f8               lea ecx, [eax - 8]
// 0082271f  8b01                 mov eax, dword ptr [ecx]
// 00822721  8b5004               mov edx, dword ptr [eax + 4]
// 00822724  895104               mov dword ptr [ecx + 4], edx
// 00822727  894804               mov dword ptr [eax + 4], ecx
// 0082272a  8b01                 mov eax, dword ptr [ecx]
// 0082272c  ff08                 dec dword ptr [eax]
// 0082272e  ff0d90aeb900         dec dword ptr [0xb9ae90]
// 00822734  83790400             cmp dword ptr [ecx + 4], 0
// 00822738  7565                 jne 0x82279f
// 0082273a  8b01                 mov eax, dword ptr [ecx]
// 0082273c  8b5008               mov edx, dword ptr [eax + 8]
// 0082273f  56                   push esi
// 00822740  85d2                 test edx, edx
// 00822742  7406                 je 0x82274a
// 00822744  8b700c               mov esi, dword ptr [eax + 0xc]
// 00822747  89720c               mov dword ptr [edx + 0xc], esi
// 0082274a  8b500c               mov edx, dword ptr [eax + 0xc]
// 0082274d  85d2                 test edx, edx
// 0082274f  7406                 je 0x822757
// 00822751  8b7008               mov esi, dword ptr [eax + 8]
// 00822754  897208               mov dword ptr [edx + 8], esi
// 00822757  5e                   pop esi
// 00822758  3905a0aeb900         cmp dword ptr [0xb9aea0], eax
// 0082275e  7510                 jne 0x822770
// 00822760  8b5008               mov edx, dword ptr [eax + 8]
// 00822763  85d2                 test edx, edx
// 00822765  7503                 jne 0x82276a
// 00822767  8b500c               mov edx, dword ptr [eax + 0xc]
// 0082276a  8915a0aeb900         mov dword ptr [0xb9aea0], edx
// 00822770  8b159caeb900         mov edx, dword ptr [0xb9ae9c]
// 00822776  89500c               mov dword ptr [eax + 0xc], edx
// 00822779  8b159caeb900         mov edx, dword ptr [0xb9ae9c]
// 0082277f  85d2                 test edx, edx
// 00822781  7405                 je 0x822788
// 00822783  8b5208               mov edx, dword ptr [edx + 8]
// 00822786  eb02                 jmp 0x82278a
// 00822788  33d2                 xor edx, edx
// 0082278a  895008               mov dword ptr [eax + 8], edx
// 0082278d  8b159caeb900         mov edx, dword ptr [0xb9ae9c]
// 00822793  85d2                 test edx, edx
// 00822795  7403                 je 0x82279a
// 00822797  894208               mov dword ptr [edx + 8], eax
// 0082279a  a39caeb900           mov dword ptr [0xb9ae9c], eax
// 0082279f  8b09                 mov ecx, dword ptr [ecx]
// 008227a1  833900               cmp dword ptr [ecx], 0
// 008227a4  7561                 jne 0x822807
// 008227a6  833d94aeb90000       cmp dword ptr [0xb9ae94], 0
// 008227ad  7458                 je 0x822807
// 008227af  8b4108               mov eax, dword ptr [ecx + 8]
// 008227b2  8bd0                 mov edx, eax
// 008227b4  85c0                 test eax, eax
// 008227b6  7503                 jne 0x8227bb
// 008227b8  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008227bb  390d9caeb900         cmp dword ptr [0xb9ae9c], ecx
// 008227c1  750d                 jne 0x8227d0
// 008227c3  85d2                 test edx, edx
// 008227c5  7409                 je 0x8227d0
// 008227c7  833d98aeb90000       cmp dword ptr [0xb9ae98], 0
// 008227ce  7437                 je 0x822807
// 008227d0  85c0                 test eax, eax
// 008227d2  7406                 je 0x8227da
// 008227d4  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008227d7  89500c               mov dword ptr [eax + 0xc], edx
// 008227da  8b410c               mov eax, dword ptr [ecx + 0xc]
// 008227dd  85c0                 test eax, eax
// 008227df  7406                 je 0x8227e7
// 008227e1  8b5108               mov edx, dword ptr [ecx + 8]
// 008227e4  895008               mov dword ptr [eax + 8], edx
// 008227e7  390d9caeb900         cmp dword ptr [0xb9ae9c], ecx
// 008227ed  750f                 jne 0x8227fe
// 008227ef  8b4108               mov eax, dword ptr [ecx + 8]
// 008227f2  85c0                 test eax, eax
// 008227f4  7503                 jne 0x8227f9
// 008227f6  8b410c               mov eax, dword ptr [ecx + 0xc]
// 008227f9  a39caeb900           mov dword ptr [0xb9ae9c], eax
// 008227fe  894c2404             mov dword ptr [esp + 4], ecx
// 00822802  e959c1ffff           jmp 0x81e960
// 00822807  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?FreeData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
