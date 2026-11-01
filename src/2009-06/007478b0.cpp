// from server: 100% by auto
// roc 2009-06 007478b0  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 248 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007478b0
//
// 007478b0  8b442404             mov eax, dword ptr [esp + 4]
// 007478b4  85c0                 test eax, eax
// 007478b6  0f84eb000000         je 0x7479a7
// 007478bc  8d48f8               lea ecx, [eax - 8]
// 007478bf  8b01                 mov eax, dword ptr [ecx]
// 007478c1  8b5004               mov edx, dword ptr [eax + 4]
// 007478c4  895104               mov dword ptr [ecx + 4], edx
// 007478c7  894804               mov dword ptr [eax + 4], ecx
// 007478ca  8b01                 mov eax, dword ptr [ecx]
// 007478cc  ff08                 dec dword ptr [eax]
// 007478ce  ff0d341aa500         dec dword ptr [0xa51a34]
// 007478d4  83790400             cmp dword ptr [ecx + 4], 0
// 007478d8  7565                 jne 0x74793f
// 007478da  8b01                 mov eax, dword ptr [ecx]
// 007478dc  8b5008               mov edx, dword ptr [eax + 8]
// 007478df  56                   push esi
// 007478e0  85d2                 test edx, edx
// 007478e2  7406                 je 0x7478ea
// 007478e4  8b700c               mov esi, dword ptr [eax + 0xc]
// 007478e7  89720c               mov dword ptr [edx + 0xc], esi
// 007478ea  8b500c               mov edx, dword ptr [eax + 0xc]
// 007478ed  85d2                 test edx, edx
// 007478ef  7406                 je 0x7478f7
// 007478f1  8b7008               mov esi, dword ptr [eax + 8]
// 007478f4  897208               mov dword ptr [edx + 8], esi
// 007478f7  5e                   pop esi
// 007478f8  3905441aa500         cmp dword ptr [0xa51a44], eax
// 007478fe  7510                 jne 0x747910
// 00747900  8b5008               mov edx, dword ptr [eax + 8]
// 00747903  85d2                 test edx, edx
// 00747905  7503                 jne 0x74790a
// 00747907  8b500c               mov edx, dword ptr [eax + 0xc]
// 0074790a  8915441aa500         mov dword ptr [0xa51a44], edx
// 00747910  8b15401aa500         mov edx, dword ptr [0xa51a40]
// 00747916  89500c               mov dword ptr [eax + 0xc], edx
// 00747919  8b15401aa500         mov edx, dword ptr [0xa51a40]
// 0074791f  85d2                 test edx, edx
// 00747921  7405                 je 0x747928
// 00747923  8b5208               mov edx, dword ptr [edx + 8]
// 00747926  eb02                 jmp 0x74792a
// 00747928  33d2                 xor edx, edx
// 0074792a  895008               mov dword ptr [eax + 8], edx
// 0074792d  8b15401aa500         mov edx, dword ptr [0xa51a40]
// 00747933  85d2                 test edx, edx
// 00747935  7403                 je 0x74793a
// 00747937  894208               mov dword ptr [edx + 8], eax
// 0074793a  a3401aa500           mov dword ptr [0xa51a40], eax
// 0074793f  8b09                 mov ecx, dword ptr [ecx]
// 00747941  833900               cmp dword ptr [ecx], 0
// 00747944  7561                 jne 0x7479a7
// 00747946  833d381aa50000       cmp dword ptr [0xa51a38], 0
// 0074794d  7458                 je 0x7479a7
// 0074794f  8b4108               mov eax, dword ptr [ecx + 8]
// 00747952  8bd0                 mov edx, eax
// 00747954  85c0                 test eax, eax
// 00747956  7503                 jne 0x74795b
// 00747958  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0074795b  390d401aa500         cmp dword ptr [0xa51a40], ecx
// 00747961  750d                 jne 0x747970
// 00747963  85d2                 test edx, edx
// 00747965  7409                 je 0x747970
// 00747967  833d3c1aa50000       cmp dword ptr [0xa51a3c], 0
// 0074796e  7437                 je 0x7479a7
// 00747970  85c0                 test eax, eax
// 00747972  7406                 je 0x74797a
// 00747974  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00747977  89500c               mov dword ptr [eax + 0xc], edx
// 0074797a  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0074797d  85c0                 test eax, eax
// 0074797f  7406                 je 0x747987
// 00747981  8b5108               mov edx, dword ptr [ecx + 8]
// 00747984  895008               mov dword ptr [eax + 8], edx
// 00747987  390d401aa500         cmp dword ptr [0xa51a40], ecx
// 0074798d  750f                 jne 0x74799e
// 0074798f  8b4108               mov eax, dword ptr [ecx + 8]
// 00747992  85c0                 test eax, eax
// 00747994  7503                 jne 0x747999
// 00747996  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00747999  a3401aa500           mov dword ptr [0xa51a40], eax
// 0074799e  894c2404             mov dword ptr [esp + 4], ecx
// 007479a2  e9f9c0ffff           jmp 0x743aa0
// 007479a7  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?FreeData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
