// from server: 100% by auto
// roc 2012-06 004515d0  unit: boost::posix_time::Vptime::?$time_facet  size: 225 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004515d0
//
// 004515d0  8b01                 mov eax, dword ptr [ecx]
// 004515d2  8b5104               mov edx, dword ptr [ecx + 4]
// 004515d5  83ec08               sub esp, 8
// 004515d8  85c0                 test eax, eax
// 004515da  7508                 jne 0x4515e4
// 004515dc  81fa00000080         cmp edx, 0x80000000
// 004515e2  741e                 je 0x451602
// 004515e4  83f8ff               cmp eax, -1
// 004515e7  7508                 jne 0x4515f1
// 004515e9  81faffffff7f         cmp edx, 0x7fffffff
// 004515ef  7411                 je 0x451602
// 004515f1  83f8fe               cmp eax, -2
// 004515f4  0f8581000000         jne 0x45167b
// 004515fa  81faffffff7f         cmp edx, 0x7fffffff
// 00451600  7579                 jne 0x45167b
// 00451602  83f8fe               cmp eax, -2
// 00451605  7520                 jne 0x451627
// 00451607  81faffffff7f         cmp edx, 0x7fffffff
// 0045160d  7518                 jne 0x451627
// 0045160f  56                   push esi
// 00451610  8b742410             mov esi, dword ptr [esp + 0x10]
// 00451614  33c0                 xor eax, eax
// 00451616  50                   push eax
// 00451617  8bce                 mov ecx, esi
// 00451619  e8420dfcff           call 0x412360
// 0045161e  8bc6                 mov eax, esi
// 00451620  5e                   pop esi
// 00451621  83c408               add esp, 8
// 00451624  c20400               ret 4
// 00451627  85c0                 test eax, eax
// 00451629  7523                 jne 0x45164e
// 0045162b  81fa00000080         cmp edx, 0x80000000
// 00451631  751b                 jne 0x45164e
// 00451633  56                   push esi
// 00451634  8b742410             mov esi, dword ptr [esp + 0x10]
// 00451638  b801000000           mov eax, 1
// 0045163d  50                   push eax
// 0045163e  8bce                 mov ecx, esi
// 00451640  e81b0dfcff           call 0x412360
// 00451645  8bc6                 mov eax, esi
// 00451647  5e                   pop esi
// 00451648  83c408               add esp, 8
// 0045164b  c20400               ret 4
// 0045164e  83f8ff               cmp eax, -1
// 00451651  750d                 jne 0x451660
// 00451653  b802000000           mov eax, 2
// 00451658  81faffffff7f         cmp edx, 0x7fffffff
// 0045165e  7405                 je 0x451665
// 00451660  b805000000           mov eax, 5
// 00451665  56                   push esi
// 00451666  8b742410             mov esi, dword ptr [esp + 0x10]
// 0045166a  50                   push eax
// 0045166b  8bce                 mov ecx, esi
// 0045166d  e8ee0cfcff           call 0x412360
// 00451672  8bc6                 mov eax, esi
// 00451674  5e                   pop esi
// 00451675  83c408               add esp, 8
// 00451678  c20400               ret 4
// 0045167b  6a14                 push 0x14
// 0045167d  680060d71d           push 0x1dd76000
// 00451682  8bca                 mov ecx, edx
// 00451684  51                   push ecx
// 00451685  50                   push eax
// 00451686  e8d51d5300           call 0x983460
// 0045168b  50                   push eax
// 0045168c  8d442404             lea eax, [esp + 4]
// 00451690  50                   push eax
// 00451691  e8baf8ffff           call 0x450f50
// 00451696  8d4c2408             lea ecx, [esp + 8]
// 0045169a  51                   push ecx
// 0045169b  e820a4fbff           call 0x40bac0
// 004516a0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004516a4  8901                 mov dword ptr [ecx], eax
// 004516a6  83c40c               add esp, 0xc
// 004516a9  8bc1                 mov eax, ecx
// 004516ab  83c408               add esp, 8
// 004516ae  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?date@?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@QBE?AV0gregorian@3@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
