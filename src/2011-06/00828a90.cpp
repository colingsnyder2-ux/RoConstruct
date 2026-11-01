// from server: 100% by auto
// roc 2011-06 00828a90  unit: CXTPToolBar  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00828a90
//
// 00828a90  83ec10               sub esp, 0x10
// 00828a93  56                   push esi
// 00828a94  8bf1                 mov esi, ecx
// 00828a96  85f6                 test esi, esi
// 00828a98  7441                 je 0x828adb
// 00828a9a  837e2000             cmp dword ptr [esi + 0x20], 0
// 00828a9e  743b                 je 0x828adb
// 00828aa0  8b06                 mov eax, dword ptr [esi]
// 00828aa2  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 00828aa8  ffd2                 call edx
// 00828aaa  85c0                 test eax, eax
// 00828aac  742d                 je 0x828adb
// 00828aae  8b4620               mov eax, dword ptr [esi + 0x20]
// 00828ab1  50                   push eax
// 00828ab2  ff15201ca400         call dword ptr [0xa41c20]
// 00828ab8  85c0                 test eax, eax
// 00828aba  741f                 je 0x828adb
// 00828abc  56                   push esi
// 00828abd  8d4c2408             lea ecx, [esp + 8]
// 00828ac1  e86a420300           call 0x85cd30
// 00828ac6  50                   push eax
// 00828ac7  ff15641ca400         call dword ptr [0xa41c64]
// 00828acd  85c0                 test eax, eax
// 00828acf  750a                 jne 0x828adb
// 00828ad1  b801000000           mov eax, 1
// 00828ad6  5e                   pop esi
// 00828ad7  83c410               add esp, 0x10
// 00828ada  c3                   ret 
// 00828adb  33c0                 xor eax, eax
// 00828add  5e                   pop esi
// 00828ade  83c410               add esp, 0x10
// 00828ae1  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPToolBar.cpp (function ?IsWindowVisible@CXTPToolBar@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPToolBar.cpp
