// from server: 100% by auto
// roc 2009-06 00432e40  unit: IIHAAH::?$CMap  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00432e40
//
// 00432e40  56                   push esi
// 00432e41  8bf1                 mov esi, ecx
// 00432e43  8b4610               mov eax, dword ptr [esi + 0x10]
// 00432e46  85c0                 test eax, eax
// 00432e48  7409                 je 0x432e53
// 00432e4a  50                   push eax
// 00432e4b  e8e25b2e00           call 0x718a32
// 00432e50  83c404               add esp, 4
// 00432e53  8b4604               mov eax, dword ptr [esi + 4]
// 00432e56  50                   push eax
// 00432e57  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00432e5e  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00432e65  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00432e6c  e8c15b2e00           call 0x718a32
// 00432e71  83c404               add esp, 4
// 00432e74  5e                   pop esi
// 00432e75  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??1?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
