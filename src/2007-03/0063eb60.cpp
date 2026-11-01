// from server: 100% by auto
// roc 2007-03 0063eb60  unit: seg_00630000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0063eb60
//
// 0063eb60  83ec10               sub esp, 0x10
// 0063eb63  56                   push esi
// 0063eb64  8bf1                 mov esi, ecx
// 0063eb66  85f6                 test esi, esi
// 0063eb68  7441                 je 0x63ebab
// 0063eb6a  837e2000             cmp dword ptr [esi + 0x20], 0
// 0063eb6e  743b                 je 0x63ebab
// 0063eb70  8b06                 mov eax, dword ptr [esi]
// 0063eb72  8b9060010000         mov edx, dword ptr [eax + 0x160]
// 0063eb78  ffd2                 call edx
// 0063eb7a  85c0                 test eax, eax
// 0063eb7c  742d                 je 0x63ebab
// 0063eb7e  8b4620               mov eax, dword ptr [esi + 0x20]
// 0063eb81  50                   push eax
// 0063eb82  ff158ced7700         call dword ptr [0x77ed8c]
// 0063eb88  85c0                 test eax, eax
// 0063eb8a  741f                 je 0x63ebab
// 0063eb8c  56                   push esi
// 0063eb8d  8d4c2408             lea ecx, [esp + 8]
// 0063eb91  e83acc0200           call 0x66b7d0
// 0063eb96  50                   push eax
// 0063eb97  ff1554ed7700         call dword ptr [0x77ed54]
// 0063eb9d  85c0                 test eax, eax
// 0063eb9f  750a                 jne 0x63ebab
// 0063eba1  b801000000           mov eax, 1
// 0063eba6  5e                   pop esi
// 0063eba7  83c410               add esp, 0x10
// 0063ebaa  c3                   ret 
// 0063ebab  33c0                 xor eax, eax
// 0063ebad  5e                   pop esi
// 0063ebae  83c410               add esp, 0x10
// 0063ebb1  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPToolBar.cpp (function ?IsWindowVisible@CXTPToolBar@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPToolBar.cpp
