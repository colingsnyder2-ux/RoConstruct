// from server: 100% by auto
// roc 2007-03 006d4b40  unit: seg_006d0000  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d4b40
//
// 006d4b40  8b442408             mov eax, dword ptr [esp + 8]
// 006d4b44  56                   push esi
// 006d4b45  8b742408             mov esi, dword ptr [esp + 8]
// 006d4b49  8b0e                 mov ecx, dword ptr [esi]
// 006d4b4b  3bc1                 cmp eax, ecx
// 006d4b4d  7d04                 jge 0x6d4b53
// 006d4b4f  2bc1                 sub eax, ecx
// 006d4b51  eb0d                 jmp 0x6d4b60
// 006d4b53  8b4e08               mov ecx, dword ptr [esi + 8]
// 006d4b56  3bc1                 cmp eax, ecx
// 006d4b58  7e04                 jle 0x6d4b5e
// 006d4b5a  2bc1                 sub eax, ecx
// 006d4b5c  eb02                 jmp 0x6d4b60
// 006d4b5e  33c0                 xor eax, eax
// 006d4b60  8b5604               mov edx, dword ptr [esi + 4]
// 006d4b63  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006d4b67  3bca                 cmp ecx, edx
// 006d4b69  7c07                 jl 0x6d4b72
// 006d4b6b  8b560c               mov edx, dword ptr [esi + 0xc]
// 006d4b6e  3bca                 cmp ecx, edx
// 006d4b70  7e0d                 jle 0x6d4b7f
// 006d4b72  2bca                 sub ecx, edx
// 006d4b74  51                   push ecx
// 006d4b75  50                   push eax
// 006d4b76  56                   push esi
// 006d4b77  ff1558ed7700         call dword ptr [0x77ed58]
// 006d4b7d  5e                   pop esi
// 006d4b7e  c3                   ret 
// 006d4b7f  33c9                 xor ecx, ecx
// 006d4b81  51                   push ecx
// 006d4b82  50                   push eax
// 006d4b83  56                   push esi
// 006d4b84  ff1558ed7700         call dword ptr [0x77ed58]
// 006d4b8a  5e                   pop esi
// 006d4b8b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockContext.cpp (function ?AdjustRectangle@CXTPDockContext@@CAXAAVCRect@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockContext.cpp
