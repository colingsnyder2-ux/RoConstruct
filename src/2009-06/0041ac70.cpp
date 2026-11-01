// from server: 100% by auto
// roc 2009-06 0041ac70  unit: rbx::signals::connection::slot  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041ac70
//
// 0041ac70  56                   push esi
// 0041ac71  33f6                 xor esi, esi
// 0041ac73  3935041aa500         cmp dword ptr [0xa51a04], esi
// 0041ac79  740d                 je 0x41ac88
// 0041ac7b  68041aa500           push 0xa51a04
// 0041ac80  ff15a4e18900         call dword ptr [0x89e1a4]
// 0041ac86  8bf0                 mov esi, eax
// 0041ac88  833d0c1aa50000       cmp dword ptr [0xa51a0c], 0
// 0041ac8f  7434                 je 0x41acc5
// 0041ac91  8b442408             mov eax, dword ptr [esp + 8]
// 0041ac95  8b0d001aa500         mov ecx, dword ptr [0xa51a00]
// 0041ac9b  50                   push eax
// 0041ac9c  6a00                 push 0
// 0041ac9e  51                   push ecx
// 0041ac9f  ff1528e28900         call dword ptr [0x89e228]
// 0041aca5  85f6                 test esi, esi
// 0041aca7  751a                 jne 0x41acc3
// 0041aca9  a1001aa500           mov eax, dword ptr [0xa51a00]
// 0041acae  85c0                 test eax, eax
// 0041acb0  7407                 je 0x41acb9
// 0041acb2  50                   push eax
// 0041acb3  ff1520e28900         call dword ptr [0x89e220]
// 0041acb9  c705001aa50000000000 mov dword ptr [0xa51a00], 0
// 0041acc3  5e                   pop esi
// 0041acc4  c3                   ret 
// 0041acc5  5e                   pop esi
// 0041acc6  e967dd2f00           jmp 0x718a32
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?Free_mem@?$CXTPHeapAllocatorT@UCXTPChartSeriesPointAllocatorData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
