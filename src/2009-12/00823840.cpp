// from server: 100% by auto
// roc 2009-12 00823840  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 355 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823840
//
// 00823840  8b0d9caeb900         mov ecx, dword ptr [0xb9ae9c]
// 00823846  56                   push esi
// 00823847  57                   push edi
// 00823848  85c9                 test ecx, ecx
// 0082384a  0f85bd000000         jne 0x82390d
// 00823850  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00823854  83c008               add eax, 8
// 00823857  8bf0                 mov esi, eax
// 00823859  81e603000080         and esi, 0x80000003
// 0082385f  7905                 jns 0x823866
// 00823861  4e                   dec esi
// 00823862  83cefc               or esi, 0xfffffffc
// 00823865  46                   inc esi
// 00823866  8b3d045cb600         mov edi, dword ptr [0xb65c04]
// 0082386c  f7de                 neg esi
// 0082386e  1bf6                 sbb esi, esi
// 00823870  99                   cdq 
// 00823871  83e203               and edx, 3
// 00823874  03c2                 add eax, edx
// 00823876  f7de                 neg esi
// 00823878  c1f802               sar eax, 2
// 0082387b  03f0                 add esi, eax
// 0082387d  03f6                 add esi, esi
// 0082387f  03f6                 add esi, esi
// 00823881  0faffe               imul edi, esi
// 00823884  6870aeb900           push 0xb9ae70
// 00823889  83c710               add edi, 0x10
// 0082388c  ff150cb29800         call dword ptr [0x98b20c]
// 00823892  833d78aeb90000       cmp dword ptr [0xb9ae78], 0
// 00823899  7416                 je 0x8238b1
// 0082389b  e890b1ffff           call 0x81ea30
// 008238a0  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 008238a5  57                   push edi
// 008238a6  6a00                 push 0
// 008238a8  50                   push eax
// 008238a9  ff1508b39800         call dword ptr [0x98b308]
// 008238af  eb09                 jmp 0x8238ba
// 008238b1  57                   push edi
// 008238b2  e88b02fdff           call 0x7f3b42
// 008238b7  83c404               add esp, 4
// 008238ba  85c0                 test eax, eax
// 008238bc  0f84dc000000         je 0x82399e
// 008238c2  33c9                 xor ecx, ecx
// 008238c4  894804               mov dword ptr [eax + 4], ecx
// 008238c7  894808               mov dword ptr [eax + 8], ecx
// 008238ca  89480c               mov dword ptr [eax + 0xc], ecx
// 008238cd  8908                 mov dword ptr [eax], ecx
// 008238cf  8bf8                 mov edi, eax
// 008238d1  a39caeb900           mov dword ptr [0xb9ae9c], eax
// 008238d6  83c010               add eax, 0x10
// 008238d9  894704               mov dword ptr [edi + 4], eax
// 008238dc  33d2                 xor edx, edx
// 008238de  390d045cb600         cmp dword ptr [0xb65c04], ecx
// 008238e4  7e19                 jle 0x8238ff
// 008238e6  8bc8                 mov ecx, eax
// 008238e8  03c6                 add eax, esi
// 008238ea  42                   inc edx
// 008238eb  8939                 mov dword ptr [ecx], edi
// 008238ed  894104               mov dword ptr [ecx + 4], eax
// 008238f0  3b15045cb600         cmp edx, dword ptr [0xb65c04]
// 008238f6  7cee                 jl 0x8238e6
// 008238f8  c7410400000000       mov dword ptr [ecx + 4], 0
// 008238ff  8b0d9caeb900         mov ecx, dword ptr [0xb9ae9c]
// 00823905  85c9                 test ecx, ecx
// 00823907  0f8491000000         je 0x82399e
// 0082390d  83790400             cmp dword ptr [ecx + 4], 0
// 00823911  0f8487000000         je 0x82399e
// 00823917  8b4104               mov eax, dword ptr [ecx + 4]
// 0082391a  ff01                 inc dword ptr [ecx]
// 0082391c  ff0590aeb900         inc dword ptr [0xb9ae90]
// 00823922  8b0d9caeb900         mov ecx, dword ptr [0xb9ae9c]
// 00823928  8b4904               mov ecx, dword ptr [ecx + 4]
// 0082392b  8b5104               mov edx, dword ptr [ecx + 4]
// 0082392e  c7410400000000       mov dword ptr [ecx + 4], 0
// 00823935  8b0d9caeb900         mov ecx, dword ptr [0xb9ae9c]
// 0082393b  83c008               add eax, 8
// 0082393e  895104               mov dword ptr [ecx + 4], edx
// 00823941  85d2                 test edx, edx
// 00823943  755b                 jne 0x8239a0
// 00823945  8b159caeb900         mov edx, dword ptr [0xb9ae9c]
// 0082394b  837a0800             cmp dword ptr [edx + 8], 0
// 0082394f  8d4a08               lea ecx, [edx + 8]
// 00823952  8bf2                 mov esi, edx
// 00823954  7404                 je 0x82395a
// 00823956  8b11                 mov edx, dword ptr [ecx]
// 00823958  eb03                 jmp 0x82395d
// 0082395a  8b520c               mov edx, dword ptr [edx + 0xc]
// 0082395d  89159caeb900         mov dword ptr [0xb9ae9c], edx
// 00823963  85d2                 test edx, edx
// 00823965  7405                 je 0x82396c
// 00823967  8b39                 mov edi, dword ptr [ecx]
// 00823969  897a08               mov dword ptr [edx + 8], edi
// 0082396c  8b15a0aeb900         mov edx, dword ptr [0xb9aea0]
// 00823972  89560c               mov dword ptr [esi + 0xc], edx
// 00823975  8b15a0aeb900         mov edx, dword ptr [0xb9aea0]
// 0082397b  85d2                 test edx, edx
// 0082397d  7405                 je 0x823984
// 0082397f  8b5208               mov edx, dword ptr [edx + 8]
// 00823982  eb02                 jmp 0x823986
// 00823984  33d2                 xor edx, edx
// 00823986  8911                 mov dword ptr [ecx], edx
// 00823988  8b0da0aeb900         mov ecx, dword ptr [0xb9aea0]
// 0082398e  85c9                 test ecx, ecx
// 00823990  7403                 je 0x823995
// 00823992  897108               mov dword ptr [ecx + 8], esi
// 00823995  5f                   pop edi
// 00823996  8935a0aeb900         mov dword ptr [0xb9aea0], esi
// 0082399c  5e                   pop esi
// 0082399d  c3                   ret 
// 0082399e  33c0                 xor eax, eax
// 008239a0  5f                   pop edi
// 008239a1  5e                   pop esi
// 008239a2  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?AllocData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
