// from server: 100% by auto
// roc 2009-12 008bc150  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008bc150
//
// 008bc150  8b442408             mov eax, dword ptr [esp + 8]
// 008bc154  56                   push esi
// 008bc155  8b742408             mov esi, dword ptr [esp + 8]
// 008bc159  8b0e                 mov ecx, dword ptr [esi]
// 008bc15b  3bc1                 cmp eax, ecx
// 008bc15d  7d04                 jge 0x8bc163
// 008bc15f  2bc1                 sub eax, ecx
// 008bc161  eb0d                 jmp 0x8bc170
// 008bc163  8b4e08               mov ecx, dword ptr [esi + 8]
// 008bc166  3bc1                 cmp eax, ecx
// 008bc168  7e04                 jle 0x8bc16e
// 008bc16a  2bc1                 sub eax, ecx
// 008bc16c  eb02                 jmp 0x8bc170
// 008bc16e  33c0                 xor eax, eax
// 008bc170  8b5604               mov edx, dword ptr [esi + 4]
// 008bc173  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008bc177  3bca                 cmp ecx, edx
// 008bc179  7c07                 jl 0x8bc182
// 008bc17b  8b560c               mov edx, dword ptr [esi + 0xc]
// 008bc17e  3bca                 cmp ecx, edx
// 008bc180  7e0d                 jle 0x8bc18f
// 008bc182  2bca                 sub ecx, edx
// 008bc184  51                   push ecx
// 008bc185  50                   push eax
// 008bc186  56                   push esi
// 008bc187  ff156ccc9800         call dword ptr [0x98cc6c]
// 008bc18d  5e                   pop esi
// 008bc18e  c3                   ret 
// 008bc18f  33c9                 xor ecx, ecx
// 008bc191  51                   push ecx
// 008bc192  50                   push eax
// 008bc193  56                   push esi
// 008bc194  ff156ccc9800         call dword ptr [0x98cc6c]
// 008bc19a  5e                   pop esi
// 008bc19b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockContext.cpp (function ?AdjustRectangle@CXTPDockContext@@CAXAAVCRect@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockContext.cpp
