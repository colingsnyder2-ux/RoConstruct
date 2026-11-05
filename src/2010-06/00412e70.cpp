// from server: 100% by auto
// roc 2010-06 00412e70  unit: boost::gregorian::Ubad_month::U?$error_info_injector::?$clone_impl  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00412e70
//
// 00412e70  57                   push edi
// 00412e71  8bf9                 mov edi, ecx
// 00412e73  8bc7                 mov eax, edi
// 00412e75  f00fba281f           lock bts dword ptr [eax], 0x1f
// 00412e7a  7206                 jb 0x412e82
// 00412e7c  b001                 mov al, 1
// 00412e7e  5f                   pop edi
// 00412e7f  c20400               ret 4
// 00412e82  56                   push esi
// 00412e83  8b37                 mov esi, dword ptr [edi]
// 00412e85  85f6                 test esi, esi
// 00412e87  7905                 jns 0x412e8e
// 00412e89  8d4601               lea eax, [esi + 1]
// 00412e8c  eb07                 jmp 0x412e95
// 00412e8e  8bc6                 mov eax, esi
// 00412e90  0d00000080           or eax, 0x80000000
// 00412e95  8bc8                 mov ecx, eax
// 00412e97  8bd7                 mov edx, edi
// 00412e99  8bc6                 mov eax, esi
// 00412e9b  f00fb10a             lock cmpxchg dword ptr [edx], ecx
// 00412e9f  3bc6                 cmp eax, esi
// 00412ea1  7404                 je 0x412ea7
// 00412ea3  8bf0                 mov esi, eax
// 00412ea5  ebde                 jmp 0x412e85
// 00412ea7  53                   push ebx
// 00412ea8  55                   push ebp
// 00412ea9  85f6                 test esi, esi
// 00412eab  0f898f000000         jns 0x412f40
// 00412eb1  8bcf                 mov ecx, edi
// 00412eb3  e8f8ddffff           call 0x410cb0
// 00412eb8  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00412ebc  55                   push ebp
// 00412ebd  8bd8                 mov ebx, eax
// 00412ebf  e82cffffff           call 0x412df0
// 00412ec4  83c404               add esp, 4
// 00412ec7  50                   push eax
// 00412ec8  53                   push ebx
// 00412ec9  ff15c8a39e00         call dword ptr [0x9ea3c8]
// 00412ecf  85c0                 test eax, eax
// 00412ed1  755d                 jne 0x412f30
// 00412ed3  eb0b                 jmp 0x412ee0
// 00412ed5  8da42400000000       lea esp, [esp]
// 00412edc  8d642400             lea esp, [esp]
// 00412ee0  81e6ffffff3f         and esi, 0x3fffffff
// 00412ee6  81ce00000040         or esi, 0x40000000
// 00412eec  8d642400             lea esp, [esp]
// 00412ef0  85f6                 test esi, esi
// 00412ef2  7904                 jns 0x412ef8
// 00412ef4  8bc6                 mov eax, esi
// 00412ef6  eb08                 jmp 0x412f00
// 00412ef8  8d46ff               lea eax, [esi - 1]
// 00412efb  0d00000080           or eax, 0x80000000
// 00412f00  25ffffffbf           and eax, 0xbfffffff
// 00412f05  8bc8                 mov ecx, eax
// 00412f07  8bd7                 mov edx, edi
// 00412f09  8bc6                 mov eax, esi
// 00412f0b  f00fb10a             lock cmpxchg dword ptr [edx], ecx
// 00412f0f  3bc6                 cmp eax, esi
// 00412f11  7404                 je 0x412f17
// 00412f13  8bf0                 mov esi, eax
// 00412f15  ebd9                 jmp 0x412ef0
// 00412f17  85f6                 test esi, esi
// 00412f19  7925                 jns 0x412f40
// 00412f1b  55                   push ebp
// 00412f1c  e8cffeffff           call 0x412df0
// 00412f21  83c404               add esp, 4
// 00412f24  50                   push eax
// 00412f25  53                   push ebx
// 00412f26  ff15c8a39e00         call dword ptr [0x9ea3c8]
// 00412f2c  85c0                 test eax, eax
// 00412f2e  74b0                 je 0x412ee0
// 00412f30  83c8ff               or eax, 0xffffffff
// 00412f33  f00fc107             lock xadd dword ptr [edi], eax
// 00412f37  5d                   pop ebp
// 00412f38  5b                   pop ebx
// 00412f39  5e                   pop esi
// 00412f3a  32c0                 xor al, al
// 00412f3c  5f                   pop edi
// 00412f3d  c20400               ret 4
// 00412f40  5d                   pop ebp
// 00412f41  5b                   pop ebx
// 00412f42  5e                   pop esi
// 00412f43  b001                 mov al, 1
// 00412f45  5f                   pop edi
// 00412f46  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?timed_lock@basic_timed_mutex@detail@boost@@QAE_NABVptime@posix_time@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
