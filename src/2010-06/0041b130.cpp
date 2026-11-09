// from server: 100% by auto
// roc 2010-06 0041b130  unit: rbx::signals::connection::slot  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041b130
//
// 0041b130  56                   push esi
// 0041b131  33f6                 xor esi, esi
// 0041b133  39359055c200         cmp dword ptr [0xc25590], esi
// 0041b139  740d                 je 0x41b148
// 0041b13b  689055c200           push 0xc25590
// 0041b140  ff157ca39e00         call dword ptr [0x9ea37c]
// 0041b146  8bf0                 mov esi, eax
// 0041b148  833d9855c20000       cmp dword ptr [0xc25598], 0
// 0041b14f  7434                 je 0x41b185
// 0041b151  8b442408             mov eax, dword ptr [esp + 8]
// 0041b155  8b0d8c55c200         mov ecx, dword ptr [0xc2558c]
// 0041b15b  50                   push eax
// 0041b15c  6a00                 push 0
// 0041b15e  51                   push ecx
// 0041b15f  ff150ca39e00         call dword ptr [0x9ea30c]
// 0041b165  85f6                 test esi, esi
// 0041b167  751a                 jne 0x41b183
// 0041b169  a18c55c200           mov eax, dword ptr [0xc2558c]
// 0041b16e  85c0                 test eax, eax
// 0041b170  7407                 je 0x41b179
// 0041b172  50                   push eax
// 0041b173  ff1514a39e00         call dword ptr [0x9ea314]
// 0041b179  c7058c55c20000000000 mov dword ptr [0xc2558c], 0
// 0041b183  5e                   pop esi
// 0041b184  c3                   ret 
// 0041b185  5e                   pop esi
// 0041b186  e90fc83800           jmp 0x7a799a
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?Free_mem@?$CXTPHeapAllocatorT@UCXTPReportRowAllocatorData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
