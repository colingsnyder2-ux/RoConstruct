// from server: 100% by auto
// roc 2010-06 00870320  unit: ATL::CRegObject  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00870320
//
// 00870320  8b442408             mov eax, dword ptr [esp + 8]
// 00870324  56                   push esi
// 00870325  8b742408             mov esi, dword ptr [esp + 8]
// 00870329  8b0e                 mov ecx, dword ptr [esi]
// 0087032b  3bc1                 cmp eax, ecx
// 0087032d  7d04                 jge 0x870333
// 0087032f  2bc1                 sub eax, ecx
// 00870331  eb0d                 jmp 0x870340
// 00870333  8b4e08               mov ecx, dword ptr [esi + 8]
// 00870336  3bc1                 cmp eax, ecx
// 00870338  7e04                 jle 0x87033e
// 0087033a  2bc1                 sub eax, ecx
// 0087033c  eb02                 jmp 0x870340
// 0087033e  33c0                 xor eax, eax
// 00870340  8b5604               mov edx, dword ptr [esi + 4]
// 00870343  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00870347  3bca                 cmp ecx, edx
// 00870349  7c07                 jl 0x870352
// 0087034b  8b560c               mov edx, dword ptr [esi + 0xc]
// 0087034e  3bca                 cmp ecx, edx
// 00870350  7e0d                 jle 0x87035f
// 00870352  2bca                 sub ecx, edx
// 00870354  51                   push ecx
// 00870355  50                   push eax
// 00870356  56                   push esi
// 00870357  ff1540bc9e00         call dword ptr [0x9ebc40]
// 0087035d  5e                   pop esi
// 0087035e  c3                   ret 
// 0087035f  33c9                 xor ecx, ecx
// 00870361  51                   push ecx
// 00870362  50                   push eax
// 00870363  56                   push esi
// 00870364  ff1540bc9e00         call dword ptr [0x9ebc40]
// 0087036a  5e                   pop esi
// 0087036b  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPDockContext.cpp (function ?AdjustRectangle@CXTPDockContext@@CAXAAVCRect@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockContext.cpp
