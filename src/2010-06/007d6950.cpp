// from server: 100% by auto
// roc 2010-06 007d6950  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 248 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d6950
//
// 007d6950  8b442404             mov eax, dword ptr [esp + 4]
// 007d6954  85c0                 test eax, eax
// 007d6956  0f84eb000000         je 0x7d6a47
// 007d695c  8d48f8               lea ecx, [eax - 8]
// 007d695f  8b01                 mov eax, dword ptr [ecx]
// 007d6961  8b5004               mov edx, dword ptr [eax + 4]
// 007d6964  895104               mov dword ptr [ecx + 4], edx
// 007d6967  894804               mov dword ptr [eax + 4], ecx
// 007d696a  8b01                 mov eax, dword ptr [ecx]
// 007d696c  ff08                 dec dword ptr [eax]
// 007d696e  ff0dd855c200         dec dword ptr [0xc255d8]
// 007d6974  83790400             cmp dword ptr [ecx + 4], 0
// 007d6978  7565                 jne 0x7d69df
// 007d697a  8b01                 mov eax, dword ptr [ecx]
// 007d697c  8b5008               mov edx, dword ptr [eax + 8]
// 007d697f  56                   push esi
// 007d6980  85d2                 test edx, edx
// 007d6982  7406                 je 0x7d698a
// 007d6984  8b700c               mov esi, dword ptr [eax + 0xc]
// 007d6987  89720c               mov dword ptr [edx + 0xc], esi
// 007d698a  8b500c               mov edx, dword ptr [eax + 0xc]
// 007d698d  85d2                 test edx, edx
// 007d698f  7406                 je 0x7d6997
// 007d6991  8b7008               mov esi, dword ptr [eax + 8]
// 007d6994  897208               mov dword ptr [edx + 8], esi
// 007d6997  5e                   pop esi
// 007d6998  3905e855c200         cmp dword ptr [0xc255e8], eax
// 007d699e  7510                 jne 0x7d69b0
// 007d69a0  8b5008               mov edx, dword ptr [eax + 8]
// 007d69a3  85d2                 test edx, edx
// 007d69a5  7503                 jne 0x7d69aa
// 007d69a7  8b500c               mov edx, dword ptr [eax + 0xc]
// 007d69aa  8915e855c200         mov dword ptr [0xc255e8], edx
// 007d69b0  8b15e455c200         mov edx, dword ptr [0xc255e4]
// 007d69b6  89500c               mov dword ptr [eax + 0xc], edx
// 007d69b9  8b15e455c200         mov edx, dword ptr [0xc255e4]
// 007d69bf  85d2                 test edx, edx
// 007d69c1  7405                 je 0x7d69c8
// 007d69c3  8b5208               mov edx, dword ptr [edx + 8]
// 007d69c6  eb02                 jmp 0x7d69ca
// 007d69c8  33d2                 xor edx, edx
// 007d69ca  895008               mov dword ptr [eax + 8], edx
// 007d69cd  8b15e455c200         mov edx, dword ptr [0xc255e4]
// 007d69d3  85d2                 test edx, edx
// 007d69d5  7403                 je 0x7d69da
// 007d69d7  894208               mov dword ptr [edx + 8], eax
// 007d69da  a3e455c200           mov dword ptr [0xc255e4], eax
// 007d69df  8b09                 mov ecx, dword ptr [ecx]
// 007d69e1  833900               cmp dword ptr [ecx], 0
// 007d69e4  7561                 jne 0x7d6a47
// 007d69e6  833ddc55c20000       cmp dword ptr [0xc255dc], 0
// 007d69ed  7458                 je 0x7d6a47
// 007d69ef  8b4108               mov eax, dword ptr [ecx + 8]
// 007d69f2  8bd0                 mov edx, eax
// 007d69f4  85c0                 test eax, eax
// 007d69f6  7503                 jne 0x7d69fb
// 007d69f8  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007d69fb  390de455c200         cmp dword ptr [0xc255e4], ecx
// 007d6a01  750d                 jne 0x7d6a10
// 007d6a03  85d2                 test edx, edx
// 007d6a05  7409                 je 0x7d6a10
// 007d6a07  833de055c20000       cmp dword ptr [0xc255e0], 0
// 007d6a0e  7437                 je 0x7d6a47
// 007d6a10  85c0                 test eax, eax
// 007d6a12  7406                 je 0x7d6a1a
// 007d6a14  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007d6a17  89500c               mov dword ptr [eax + 0xc], edx
// 007d6a1a  8b410c               mov eax, dword ptr [ecx + 0xc]
// 007d6a1d  85c0                 test eax, eax
// 007d6a1f  7406                 je 0x7d6a27
// 007d6a21  8b5108               mov edx, dword ptr [ecx + 8]
// 007d6a24  895008               mov dword ptr [eax + 8], edx
// 007d6a27  390de455c200         cmp dword ptr [0xc255e4], ecx
// 007d6a2d  750f                 jne 0x7d6a3e
// 007d6a2f  8b4108               mov eax, dword ptr [ecx + 8]
// 007d6a32  85c0                 test eax, eax
// 007d6a34  7503                 jne 0x7d6a39
// 007d6a36  8b410c               mov eax, dword ptr [ecx + 0xc]
// 007d6a39  a3e455c200           mov dword ptr [0xc255e4], eax
// 007d6a3e  894c2404             mov dword ptr [esp + 4], ecx
// 007d6a42  e979bfffff           jmp 0x7d29c0
// 007d6a47  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?FreeData@?$CXTPBatchAllocManagerT@VCXTPReportRowAllocator@@UCXTPReportRow_BatchData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
