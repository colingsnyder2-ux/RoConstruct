// from server: 100% by auto
// roc 2007-03 00685ce0  unit: seg_00680000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685ce0
//
// 00685ce0  56                   push esi
// 00685ce1  6894000000           push 0x94
// 00685ce6  8bf1                 mov esi, ecx
// 00685ce8  6a00                 push 0
// 00685cea  56                   push esi
// 00685ceb  e82c93f9ff           call 0x61f01c
// 00685cf0  83c40c               add esp, 0xc
// 00685cf3  56                   push esi
// 00685cf4  c70694000000         mov dword ptr [esi], 0x94
// 00685cfa  ff15dcd17700         call dword ptr [0x77d1dc]
// 00685d00  8bc6                 mov eax, esi
// 00685d02  5e                   pop esi
// 00685d03  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ??0CXTPSystemVersion@@AAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
