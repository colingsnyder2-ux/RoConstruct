// from server: 100% by auto
// roc 2009-12 008239b0  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 355 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008239b0
//
// 008239b0  8b0db4aeb900         mov ecx, dword ptr [0xb9aeb4]
// 008239b6  56                   push esi
// 008239b7  57                   push edi
// 008239b8  85c9                 test ecx, ecx
// 008239ba  0f85bd000000         jne 0x823a7d
// 008239c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008239c4  83c008               add eax, 8
// 008239c7  8bf0                 mov esi, eax
// 008239c9  81e603000080         and esi, 0x80000003
// 008239cf  7905                 jns 0x8239d6
// 008239d1  4e                   dec esi
// 008239d2  83cefc               or esi, 0xfffffffc
// 008239d5  46                   inc esi
// 008239d6  8b3d085cb600         mov edi, dword ptr [0xb65c08]
// 008239dc  f7de                 neg esi
// 008239de  1bf6                 sbb esi, esi
// 008239e0  99                   cdq 
// 008239e1  83e203               and edx, 3
// 008239e4  03c2                 add eax, edx
// 008239e6  f7de                 neg esi
// 008239e8  c1f802               sar eax, 2
// 008239eb  03f0                 add esi, eax
// 008239ed  03f6                 add esi, esi
// 008239ef  03f6                 add esi, esi
// 008239f1  0faffe               imul edi, esi
// 008239f4  6870aeb900           push 0xb9ae70
// 008239f9  83c710               add edi, 0x10
// 008239fc  ff150cb29800         call dword ptr [0x98b20c]
// 00823a02  833d78aeb90000       cmp dword ptr [0xb9ae78], 0
// 00823a09  7416                 je 0x823a21
// 00823a0b  e820b0ffff           call 0x81ea30
// 00823a10  a16caeb900           mov eax, dword ptr [0xb9ae6c]
// 00823a15  57                   push edi
// 00823a16  6a00                 push 0
// 00823a18  50                   push eax
// 00823a19  ff1508b39800         call dword ptr [0x98b308]
// 00823a1f  eb09                 jmp 0x823a2a
// 00823a21  57                   push edi
// 00823a22  e81b01fdff           call 0x7f3b42
// 00823a27  83c404               add esp, 4
// 00823a2a  85c0                 test eax, eax
// 00823a2c  0f84dc000000         je 0x823b0e
// 00823a32  33c9                 xor ecx, ecx
// 00823a34  894804               mov dword ptr [eax + 4], ecx
// 00823a37  894808               mov dword ptr [eax + 8], ecx
// 00823a3a  89480c               mov dword ptr [eax + 0xc], ecx
// 00823a3d  8908                 mov dword ptr [eax], ecx
// 00823a3f  8bf8                 mov edi, eax
// 00823a41  a3b4aeb900           mov dword ptr [0xb9aeb4], eax
// 00823a46  83c010               add eax, 0x10
// 00823a49  894704               mov dword ptr [edi + 4], eax
// 00823a4c  33d2                 xor edx, edx
// 00823a4e  390d085cb600         cmp dword ptr [0xb65c08], ecx
// 00823a54  7e19                 jle 0x823a6f
// 00823a56  8bc8                 mov ecx, eax
// 00823a58  03c6                 add eax, esi
// 00823a5a  42                   inc edx
// 00823a5b  8939                 mov dword ptr [ecx], edi
// 00823a5d  894104               mov dword ptr [ecx + 4], eax
// 00823a60  3b15085cb600         cmp edx, dword ptr [0xb65c08]
// 00823a66  7cee                 jl 0x823a56
// 00823a68  c7410400000000       mov dword ptr [ecx + 4], 0
// 00823a6f  8b0db4aeb900         mov ecx, dword ptr [0xb9aeb4]
// 00823a75  85c9                 test ecx, ecx
// 00823a77  0f8491000000         je 0x823b0e
// 00823a7d  83790400             cmp dword ptr [ecx + 4], 0
// 00823a81  0f8487000000         je 0x823b0e
// 00823a87  8b4104               mov eax, dword ptr [ecx + 4]
// 00823a8a  ff01                 inc dword ptr [ecx]
// 00823a8c  ff05a8aeb900         inc dword ptr [0xb9aea8]
// 00823a92  8b0db4aeb900         mov ecx, dword ptr [0xb9aeb4]
// 00823a98  8b4904               mov ecx, dword ptr [ecx + 4]
// 00823a9b  8b5104               mov edx, dword ptr [ecx + 4]
// 00823a9e  c7410400000000       mov dword ptr [ecx + 4], 0
// 00823aa5  8b0db4aeb900         mov ecx, dword ptr [0xb9aeb4]
// 00823aab  83c008               add eax, 8
// 00823aae  895104               mov dword ptr [ecx + 4], edx
// 00823ab1  85d2                 test edx, edx
// 00823ab3  755b                 jne 0x823b10
// 00823ab5  8b15b4aeb900         mov edx, dword ptr [0xb9aeb4]
// 00823abb  837a0800             cmp dword ptr [edx + 8], 0
// 00823abf  8d4a08               lea ecx, [edx + 8]
// 00823ac2  8bf2                 mov esi, edx
// 00823ac4  7404                 je 0x823aca
// 00823ac6  8b11                 mov edx, dword ptr [ecx]
// 00823ac8  eb03                 jmp 0x823acd
// 00823aca  8b520c               mov edx, dword ptr [edx + 0xc]
// 00823acd  8915b4aeb900         mov dword ptr [0xb9aeb4], edx
// 00823ad3  85d2                 test edx, edx
// 00823ad5  7405                 je 0x823adc
// 00823ad7  8b39                 mov edi, dword ptr [ecx]
// 00823ad9  897a08               mov dword ptr [edx + 8], edi
// 00823adc  8b15b8aeb900         mov edx, dword ptr [0xb9aeb8]
// 00823ae2  89560c               mov dword ptr [esi + 0xc], edx
// 00823ae5  8b15b8aeb900         mov edx, dword ptr [0xb9aeb8]
// 00823aeb  85d2                 test edx, edx
// 00823aed  7405                 je 0x823af4
// 00823aef  8b5208               mov edx, dword ptr [edx + 8]
// 00823af2  eb02                 jmp 0x823af6
// 00823af4  33d2                 xor edx, edx
// 00823af6  8911                 mov dword ptr [ecx], edx
// 00823af8  8b0db8aeb900         mov ecx, dword ptr [0xb9aeb8]
// 00823afe  85c9                 test ecx, ecx
// 00823b00  7403                 je 0x823b05
// 00823b02  897108               mov dword ptr [ecx + 8], esi
// 00823b05  5f                   pop edi
// 00823b06  8935b8aeb900         mov dword ptr [0xb9aeb8], esi
// 00823b0c  5e                   pop esi
// 00823b0d  c3                   ret 
// 00823b0e  33c0                 xor eax, eax
// 00823b10  5f                   pop edi
// 00823b11  5e                   pop esi
// 00823b12  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?AllocData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
