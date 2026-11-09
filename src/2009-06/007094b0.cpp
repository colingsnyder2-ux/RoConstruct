// from server: 100% by auto
// roc 2009-06 007094b0  unit: boost::detail::thread_data_base  size: 225 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007094b0
//
// 007094b0  8b01                 mov eax, dword ptr [ecx]
// 007094b2  8b5104               mov edx, dword ptr [ecx + 4]
// 007094b5  83ec08               sub esp, 8
// 007094b8  85c0                 test eax, eax
// 007094ba  7508                 jne 0x7094c4
// 007094bc  81fa00000080         cmp edx, 0x80000000
// 007094c2  741e                 je 0x7094e2
// 007094c4  83f8ff               cmp eax, -1
// 007094c7  7508                 jne 0x7094d1
// 007094c9  81faffffff7f         cmp edx, 0x7fffffff
// 007094cf  7411                 je 0x7094e2
// 007094d1  83f8fe               cmp eax, -2
// 007094d4  0f8581000000         jne 0x70955b
// 007094da  81faffffff7f         cmp edx, 0x7fffffff
// 007094e0  7579                 jne 0x70955b
// 007094e2  83f8fe               cmp eax, -2
// 007094e5  7520                 jne 0x709507
// 007094e7  81faffffff7f         cmp edx, 0x7fffffff
// 007094ed  7518                 jne 0x709507
// 007094ef  56                   push esi
// 007094f0  8b742410             mov esi, dword ptr [esp + 0x10]
// 007094f4  33c0                 xor eax, eax
// 007094f6  50                   push eax
// 007094f7  8bce                 mov ecx, esi
// 007094f9  e83299d0ff           call 0x412e30
// 007094fe  8bc6                 mov eax, esi
// 00709500  5e                   pop esi
// 00709501  83c408               add esp, 8
// 00709504  c20400               ret 4
// 00709507  85c0                 test eax, eax
// 00709509  7523                 jne 0x70952e
// 0070950b  81fa00000080         cmp edx, 0x80000000
// 00709511  751b                 jne 0x70952e
// 00709513  56                   push esi
// 00709514  8b742410             mov esi, dword ptr [esp + 0x10]
// 00709518  b801000000           mov eax, 1
// 0070951d  50                   push eax
// 0070951e  8bce                 mov ecx, esi
// 00709520  e80b99d0ff           call 0x412e30
// 00709525  8bc6                 mov eax, esi
// 00709527  5e                   pop esi
// 00709528  83c408               add esp, 8
// 0070952b  c20400               ret 4
// 0070952e  83f8ff               cmp eax, -1
// 00709531  750d                 jne 0x709540
// 00709533  b802000000           mov eax, 2
// 00709538  81faffffff7f         cmp edx, 0x7fffffff
// 0070953e  7405                 je 0x709545
// 00709540  b805000000           mov eax, 5
// 00709545  56                   push esi
// 00709546  8b742410             mov esi, dword ptr [esp + 0x10]
// 0070954a  50                   push eax
// 0070954b  8bce                 mov ecx, esi
// 0070954d  e8de98d0ff           call 0x412e30
// 00709552  8bc6                 mov eax, esi
// 00709554  5e                   pop esi
// 00709555  83c408               add esp, 8
// 00709558  c20400               ret 4
// 0070955b  6a14                 push 0x14
// 0070955d  680060d71d           push 0x1dd76000
// 00709562  8bca                 mov ecx, edx
// 00709564  51                   push ecx
// 00709565  50                   push eax
// 00709566  e805080100           call 0x719d70
// 0070956b  50                   push eax
// 0070956c  8d442404             lea eax, [esp + 4]
// 00709570  50                   push eax
// 00709571  e80afeffff           call 0x709380
// 00709576  8d4c2408             lea ecx, [esp + 8]
// 0070957a  51                   push ecx
// 0070957b  e8207ad0ff           call 0x410fa0
// 00709580  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00709584  8901                 mov dword ptr [ecx], eax
// 00709586  83c40c               add esp, 0xc
// 00709589  8bc1                 mov eax, ecx
// 0070958b  83c408               add esp, 8
// 0070958e  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?date@?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@QBE?AV0gregorian@3@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
