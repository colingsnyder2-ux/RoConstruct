// from server: 100% by auto
// roc 2009-12 00412ba0  unit: boost::gregorian::Ubad_month::U?$error_info_injector::?$clone_impl  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00412ba0
//
// 00412ba0  57                   push edi
// 00412ba1  8bf9                 mov edi, ecx
// 00412ba3  8bc7                 mov eax, edi
// 00412ba5  f00fba281f           lock bts dword ptr [eax], 0x1f
// 00412baa  7206                 jb 0x412bb2
// 00412bac  b001                 mov al, 1
// 00412bae  5f                   pop edi
// 00412baf  c20400               ret 4
// 00412bb2  56                   push esi
// 00412bb3  8b37                 mov esi, dword ptr [edi]
// 00412bb5  85f6                 test esi, esi
// 00412bb7  7905                 jns 0x412bbe
// 00412bb9  8d4601               lea eax, [esi + 1]
// 00412bbc  eb07                 jmp 0x412bc5
// 00412bbe  8bc6                 mov eax, esi
// 00412bc0  0d00000080           or eax, 0x80000000
// 00412bc5  8bc8                 mov ecx, eax
// 00412bc7  8bd7                 mov edx, edi
// 00412bc9  8bc6                 mov eax, esi
// 00412bcb  f00fb10a             lock cmpxchg dword ptr [edx], ecx
// 00412bcf  3bc6                 cmp eax, esi
// 00412bd1  7404                 je 0x412bd7
// 00412bd3  8bf0                 mov esi, eax
// 00412bd5  ebde                 jmp 0x412bb5
// 00412bd7  53                   push ebx
// 00412bd8  55                   push ebp
// 00412bd9  85f6                 test esi, esi
// 00412bdb  0f898f000000         jns 0x412c70
// 00412be1  8bcf                 mov ecx, edi
// 00412be3  e8f8ddffff           call 0x4109e0
// 00412be8  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00412bec  55                   push ebp
// 00412bed  8bd8                 mov ebx, eax
// 00412bef  e82cffffff           call 0x412b20
// 00412bf4  83c404               add esp, 4
// 00412bf7  50                   push eax
// 00412bf8  53                   push ebx
// 00412bf9  ff1558b29800         call dword ptr [0x98b258]
// 00412bff  85c0                 test eax, eax
// 00412c01  755d                 jne 0x412c60
// 00412c03  eb0b                 jmp 0x412c10
// 00412c05  8da42400000000       lea esp, [esp]
// 00412c0c  8d642400             lea esp, [esp]
// 00412c10  81e6ffffff3f         and esi, 0x3fffffff
// 00412c16  81ce00000040         or esi, 0x40000000
// 00412c1c  8d642400             lea esp, [esp]
// 00412c20  85f6                 test esi, esi
// 00412c22  7904                 jns 0x412c28
// 00412c24  8bc6                 mov eax, esi
// 00412c26  eb08                 jmp 0x412c30
// 00412c28  8d46ff               lea eax, [esi - 1]
// 00412c2b  0d00000080           or eax, 0x80000000
// 00412c30  25ffffffbf           and eax, 0xbfffffff
// 00412c35  8bc8                 mov ecx, eax
// 00412c37  8bd7                 mov edx, edi
// 00412c39  8bc6                 mov eax, esi
// 00412c3b  f00fb10a             lock cmpxchg dword ptr [edx], ecx
// 00412c3f  3bc6                 cmp eax, esi
// 00412c41  7404                 je 0x412c47
// 00412c43  8bf0                 mov esi, eax
// 00412c45  ebd9                 jmp 0x412c20
// 00412c47  85f6                 test esi, esi
// 00412c49  7925                 jns 0x412c70
// 00412c4b  55                   push ebp
// 00412c4c  e8cffeffff           call 0x412b20
// 00412c51  83c404               add esp, 4
// 00412c54  50                   push eax
// 00412c55  53                   push ebx
// 00412c56  ff1558b29800         call dword ptr [0x98b258]
// 00412c5c  85c0                 test eax, eax
// 00412c5e  74b0                 je 0x412c10
// 00412c60  83c8ff               or eax, 0xffffffff
// 00412c63  f00fc107             lock xadd dword ptr [edi], eax
// 00412c67  5d                   pop ebp
// 00412c68  5b                   pop ebx
// 00412c69  5e                   pop esi
// 00412c6a  32c0                 xor al, al
// 00412c6c  5f                   pop edi
// 00412c6d  c20400               ret 4
// 00412c70  5d                   pop ebp
// 00412c71  5b                   pop ebx
// 00412c72  5e                   pop esi
// 00412c73  b001                 mov al, 1
// 00412c75  5f                   pop edi
// 00412c76  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?timed_lock@basic_timed_mutex@detail@boost@@QAE_NABVptime@posix_time@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
