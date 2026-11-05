// from server: 100% by auto
// roc 2011-06 007f8580  unit: RBX::CircleRadialNormal  size: 225 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007f8580
//
// 007f8580  8b01                 mov eax, dword ptr [ecx]
// 007f8582  8b5104               mov edx, dword ptr [ecx + 4]
// 007f8585  83ec08               sub esp, 8
// 007f8588  85c0                 test eax, eax
// 007f858a  7508                 jne 0x7f8594
// 007f858c  81fa00000080         cmp edx, 0x80000000
// 007f8592  741e                 je 0x7f85b2
// 007f8594  83f8ff               cmp eax, -1
// 007f8597  7508                 jne 0x7f85a1
// 007f8599  81faffffff7f         cmp edx, 0x7fffffff
// 007f859f  7411                 je 0x7f85b2
// 007f85a1  83f8fe               cmp eax, -2
// 007f85a4  0f8581000000         jne 0x7f862b
// 007f85aa  81faffffff7f         cmp edx, 0x7fffffff
// 007f85b0  7579                 jne 0x7f862b
// 007f85b2  83f8fe               cmp eax, -2
// 007f85b5  7520                 jne 0x7f85d7
// 007f85b7  81faffffff7f         cmp edx, 0x7fffffff
// 007f85bd  7518                 jne 0x7f85d7
// 007f85bf  56                   push esi
// 007f85c0  8b742410             mov esi, dword ptr [esp + 0x10]
// 007f85c4  33c0                 xor eax, eax
// 007f85c6  50                   push eax
// 007f85c7  8bce                 mov ecx, esi
// 007f85c9  e8727bc1ff           call 0x410140
// 007f85ce  8bc6                 mov eax, esi
// 007f85d0  5e                   pop esi
// 007f85d1  83c408               add esp, 8
// 007f85d4  c20400               ret 4
// 007f85d7  85c0                 test eax, eax
// 007f85d9  7523                 jne 0x7f85fe
// 007f85db  81fa00000080         cmp edx, 0x80000000
// 007f85e1  751b                 jne 0x7f85fe
// 007f85e3  56                   push esi
// 007f85e4  8b742410             mov esi, dword ptr [esp + 0x10]
// 007f85e8  b801000000           mov eax, 1
// 007f85ed  50                   push eax
// 007f85ee  8bce                 mov ecx, esi
// 007f85f0  e84b7bc1ff           call 0x410140
// 007f85f5  8bc6                 mov eax, esi
// 007f85f7  5e                   pop esi
// 007f85f8  83c408               add esp, 8
// 007f85fb  c20400               ret 4
// 007f85fe  83f8ff               cmp eax, -1
// 007f8601  750d                 jne 0x7f8610
// 007f8603  b802000000           mov eax, 2
// 007f8608  81faffffff7f         cmp edx, 0x7fffffff
// 007f860e  7405                 je 0x7f8615
// 007f8610  b805000000           mov eax, 5
// 007f8615  56                   push esi
// 007f8616  8b742410             mov esi, dword ptr [esp + 0x10]
// 007f861a  50                   push eax
// 007f861b  8bce                 mov ecx, esi
// 007f861d  e81e7bc1ff           call 0x410140
// 007f8622  8bc6                 mov eax, esi
// 007f8624  5e                   pop esi
// 007f8625  83c408               add esp, 8
// 007f8628  c20400               ret 4
// 007f862b  6a14                 push 0x14
// 007f862d  680060d71d           push 0x1dd76000
// 007f8632  8bca                 mov ecx, edx
// 007f8634  51                   push ecx
// 007f8635  50                   push eax
// 007f8636  e8a52d0100           call 0x80b3e0
// 007f863b  50                   push eax
// 007f863c  8d442404             lea eax, [esp + 4]
// 007f8640  50                   push eax
// 007f8641  e80afeffff           call 0x7f8450
// 007f8646  8d4c2408             lea ecx, [esp + 8]
// 007f864a  51                   push ecx
// 007f864b  e8601dc1ff           call 0x40a3b0
// 007f8650  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007f8654  8901                 mov dword ptr [ecx], eax
// 007f8656  83c40c               add esp, 0xc
// 007f8659  8bc1                 mov eax, ecx
// 007f865b  83c408               add esp, 8
// 007f865e  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?date@?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@QBE?AV0gregorian@3@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
