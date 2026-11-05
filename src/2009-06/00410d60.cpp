// from server: 100% by auto
// roc 2009-06 00410d60  unit: CChatPrompt  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00410d60
//
// 00410d60  8b4104               mov eax, dword ptr [ecx + 4]
// 00410d63  83ec10               sub esp, 0x10
// 00410d66  56                   push esi
// 00410d67  8d7104               lea esi, [ecx + 4]
// 00410d6a  85c0                 test eax, eax
// 00410d6c  7546                 jne 0x410db4
// 00410d6e  50                   push eax
// 00410d6f  50                   push eax
// 00410d70  50                   push eax
// 00410d71  50                   push eax
// 00410d72  ff1504e28900         call dword ptr [0x89e204]
// 00410d78  8bc8                 mov ecx, eax
// 00410d7a  85c9                 test ecx, ecx
// 00410d7c  7518                 jne 0x410d96
// 00410d7e  8d4c2404             lea ecx, [esp + 4]
// 00410d82  e869482f00           call 0x7055f0
// 00410d87  68e8af9700           push 0x97afe8
// 00410d8c  8d442408             lea eax, [esp + 8]
// 00410d90  50                   push eax
// 00410d91  e8b48c3000           call 0x719a4a
// 00410d96  8bd1                 mov edx, ecx
// 00410d98  33c0                 xor eax, eax
// 00410d9a  f00fb116             lock cmpxchg dword ptr [esi], edx
// 00410d9e  8bf0                 mov esi, eax
// 00410da0  85f6                 test esi, esi
// 00410da2  740e                 je 0x410db2
// 00410da4  51                   push ecx
// 00410da5  ff1588e38900         call dword ptr [0x89e388]
// 00410dab  8bc6                 mov eax, esi
// 00410dad  5e                   pop esi
// 00410dae  83c410               add esp, 0x10
// 00410db1  c3                   ret 
// 00410db2  8bc1                 mov eax, ecx
// 00410db4  5e                   pop esi
// 00410db5  83c410               add esp, 0x10
// 00410db8  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?get_event@basic_timed_mutex@detail@boost@@AAEPAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
