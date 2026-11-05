// from server: 100% by auto
// roc 2011-06 004014b0  unit: std::logic_error  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004014b0
//
// 004014b0  83ec44               sub esp, 0x44
// 004014b3  56                   push esi
// 004014b4  57                   push edi
// 004014b5  b90c000000           mov ecx, 0xc
// 004014ba  bee0b5a500           mov esi, 0xa5b5e0
// 004014bf  8d7c2408             lea edi, [esp + 8]
// 004014c3  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004014c5  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 004014c9  8d442438             lea eax, [esp + 0x38]
// 004014cd  50                   push eax
// 004014ce  51                   push ecx
// 004014cf  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 004014d0  e8fbfcffff           call 0x4011d0
// 004014d5  83c408               add esp, 8
// 004014d8  8d542440             lea edx, [esp + 0x40]
// 004014dc  52                   push edx
// 004014dd  ff159403a400         call dword ptr [0xa40394]
// 004014e3  50                   push eax
// 004014e4  e867fdffff           call 0x401250
// 004014e9  83c408               add esp, 8
// 004014ec  8d442408             lea eax, [esp + 8]
// 004014f0  50                   push eax
// 004014f1  6a00                 push 0
// 004014f3  6a00                 push 0
// 004014f5  ff159803a400         call dword ptr [0xa40398]
// 004014fb  5f                   pop edi
// 004014fc  5e                   pop esi
// 004014fd  83c444               add esp, 0x44
// 00401500  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?create_once_mutex@detail@boost@@YAPAXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
