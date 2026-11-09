// from server: 100% by auto
// roc 2009-12 004014d0  unit: std::bad_alloc  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004014d0
//
// 004014d0  83ec44               sub esp, 0x44
// 004014d3  56                   push esi
// 004014d4  57                   push edi
// 004014d5  b90c000000           mov ecx, 0xc
// 004014da  bea4f49900           mov esi, 0x99f4a4
// 004014df  8d7c2408             lea edi, [esp + 8]
// 004014e3  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004014e5  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 004014e9  8d442438             lea eax, [esp + 0x38]
// 004014ed  50                   push eax
// 004014ee  51                   push ecx
// 004014ef  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 004014f0  e83bfdffff           call 0x401230
// 004014f5  83c408               add esp, 8
// 004014f8  8d542440             lea edx, [esp + 0x40]
// 004014fc  52                   push edx
// 004014fd  ff1544b29800         call dword ptr [0x98b244]
// 00401503  50                   push eax
// 00401504  e8a7fdffff           call 0x4012b0
// 00401509  83c408               add esp, 8
// 0040150c  8d442408             lea eax, [esp + 8]
// 00401510  50                   push eax
// 00401511  6a00                 push 0
// 00401513  6a00                 push 0
// 00401515  ff1548b29800         call dword ptr [0x98b248]
// 0040151b  5f                   pop edi
// 0040151c  5e                   pop esi
// 0040151d  83c444               add esp, 0x44
// 00401520  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?create_once_mutex@detail@boost@@YAPAXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
