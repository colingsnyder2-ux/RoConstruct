// from server: 100% by auto
// roc 2007-08 0043a440  unit: IIHAAH::?$CMap  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043a440
//
// 0043a440  56                   push esi
// 0043a441  8bf1                 mov esi, ecx
// 0043a443  8b4608               mov eax, dword ptr [esi + 8]
// 0043a446  85c0                 test eax, eax
// 0043a448  7409                 je 0x43a453
// 0043a44a  50                   push eax
// 0043a44b  e812581f00           call 0x62fc62
// 0043a450  83c404               add esp, 4
// 0043a453  c7460800000000       mov dword ptr [esi + 8], 0
// 0043a45a  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0043a461  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0043a468  5e                   pop esi
// 0043a469  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??1?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
