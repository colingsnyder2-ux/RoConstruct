// from server: 100% by auto
// roc 2009-06 004015a0  unit: std::bad_alloc  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004015a0
//
// 004015a0  83ec44               sub esp, 0x44
// 004015a3  56                   push esi
// 004015a4  57                   push edi
// 004015a5  b90c000000           mov ecx, 0xc
// 004015aa  be64c98a00           mov esi, 0x8ac964
// 004015af  8d7c2408             lea edi, [esp + 8]
// 004015b3  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004015b5  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 004015b9  8d442438             lea eax, [esp + 0x38]
// 004015bd  50                   push eax
// 004015be  51                   push ecx
// 004015bf  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 004015c0  e87bfcffff           call 0x401240
// 004015c5  83c408               add esp, 8
// 004015c8  8d542440             lea edx, [esp + 0x40]
// 004015cc  52                   push edx
// 004015cd  ff153ce38900         call dword ptr [0x89e33c]
// 004015d3  50                   push eax
// 004015d4  e8e7fcffff           call 0x4012c0
// 004015d9  83c408               add esp, 8
// 004015dc  8d442408             lea eax, [esp + 8]
// 004015e0  50                   push eax
// 004015e1  6a00                 push 0
// 004015e3  6a00                 push 0
// 004015e5  ff1540e38900         call dword ptr [0x89e340]
// 004015eb  5f                   pop edi
// 004015ec  5e                   pop esi
// 004015ed  83c444               add esp, 0x44
// 004015f0  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?create_once_mutex@detail@boost@@YAPAXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
