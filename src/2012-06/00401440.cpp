// from server: 100% by auto
// roc 2012-06 00401440  unit: std::bad_alloc  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00401440
//
// 00401440  83ec44               sub esp, 0x44
// 00401443  56                   push esi
// 00401444  57                   push edi
// 00401445  b90c000000           mov ecx, 0xc
// 0040144a  bec02eb400           mov esi, 0xb42ec0
// 0040144f  8d7c2408             lea edi, [esp + 8]
// 00401453  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00401455  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00401459  8d442438             lea eax, [esp + 0x38]
// 0040145d  50                   push eax
// 0040145e  51                   push ecx
// 0040145f  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 00401460  e85bfdffff           call 0x4011c0
// 00401465  83c408               add esp, 8
// 00401468  8d542440             lea edx, [esp + 0x40]
// 0040146c  52                   push edx
// 0040146d  ff15d021b200         call dword ptr [0xb221d0]
// 00401473  50                   push eax
// 00401474  e8c7fdffff           call 0x401240
// 00401479  83c408               add esp, 8
// 0040147c  8d442408             lea eax, [esp + 8]
// 00401480  50                   push eax
// 00401481  6a00                 push 0
// 00401483  6a00                 push 0
// 00401485  ff15d421b200         call dword ptr [0xb221d4]
// 0040148b  5f                   pop edi
// 0040148c  5e                   pop esi
// 0040148d  83c444               add esp, 0x44
// 00401490  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?create_once_mutex@detail@boost@@YAPAXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
