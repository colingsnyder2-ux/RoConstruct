// from server: 100% by auto
// roc 2010-06 007d2a90  unit: CXTPReportControl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d2a90
//
// 007d2a90  51                   push ecx
// 007d2a91  833d9c55c20000       cmp dword ptr [0xc2559c], 0
// 007d2a98  755a                 jne 0x7d2af4
// 007d2a9a  56                   push esi
// 007d2a9b  6a00                 push 0
// 007d2a9d  6a00                 push 0
// 007d2a9f  6a00                 push 0
// 007d2aa1  ff1518a39e00         call dword ptr [0x9ea318]
// 007d2aa7  687439a000           push 0xa03974
// 007d2aac  a39c55c200           mov dword ptr [0xc2559c], eax
// 007d2ab1  8bf0                 mov esi, eax
// 007d2ab3  c744240802000000     mov dword ptr [esp + 8], 2
// 007d2abb  ff158ca39e00         call dword ptr [0x9ea38c]
// 007d2ac1  85c0                 test eax, eax
// 007d2ac3  7424                 je 0x7d2ae9
// 007d2ac5  686039a000           push 0xa03960
// 007d2aca  50                   push eax
// 007d2acb  ff1590a39e00         call dword ptr [0x9ea390]
// 007d2ad1  85c0                 test eax, eax
// 007d2ad3  7414                 je 0x7d2ae9
// 007d2ad5  6a04                 push 4
// 007d2ad7  8d4c2408             lea ecx, [esp + 8]
// 007d2adb  51                   push ecx
// 007d2adc  6a00                 push 0
// 007d2ade  56                   push esi
// 007d2adf  ffd0                 call eax
// 007d2ae1  a3a455c200           mov dword ptr [0xc255a4], eax
// 007d2ae6  5e                   pop esi
// 007d2ae7  59                   pop ecx
// 007d2ae8  c3                   ret 
// 007d2ae9  b801000000           mov eax, 1
// 007d2aee  a3a455c200           mov dword ptr [0xc255a4], eax
// 007d2af3  5e                   pop esi
// 007d2af4  59                   pop ecx
// 007d2af5  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?CreateHeapIfNeed@?$CXTPHeapAllocatorT@UCXTPReportDataAllocatorData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
