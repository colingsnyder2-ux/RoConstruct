// from server: 100% by auto
// roc 2009-06 004130c0  unit: boost::gregorian::Ubad_month::U?$error_info_injector::?$clone_impl  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004130c0
//
// 004130c0  57                   push edi
// 004130c1  8bf9                 mov edi, ecx
// 004130c3  8bc7                 mov eax, edi
// 004130c5  f00fba281f           lock bts dword ptr [eax], 0x1f
// 004130ca  7206                 jb 0x4130d2
// 004130cc  b001                 mov al, 1
// 004130ce  5f                   pop edi
// 004130cf  c20400               ret 4
// 004130d2  56                   push esi
// 004130d3  8b37                 mov esi, dword ptr [edi]
// 004130d5  85f6                 test esi, esi
// 004130d7  7905                 jns 0x4130de
// 004130d9  8d4601               lea eax, [esi + 1]
// 004130dc  eb07                 jmp 0x4130e5
// 004130de  8bc6                 mov eax, esi
// 004130e0  0d00000080           or eax, 0x80000000
// 004130e5  8bc8                 mov ecx, eax
// 004130e7  8bd7                 mov edx, edi
// 004130e9  8bc6                 mov eax, esi
// 004130eb  f00fb10a             lock cmpxchg dword ptr [edx], ecx
// 004130ef  3bc6                 cmp eax, esi
// 004130f1  7404                 je 0x4130f7
// 004130f3  8bf0                 mov esi, eax
// 004130f5  ebde                 jmp 0x4130d5
// 004130f7  53                   push ebx
// 004130f8  55                   push ebp
// 004130f9  85f6                 test esi, esi
// 004130fb  0f898f000000         jns 0x413190
// 00413101  8bcf                 mov ecx, edi
// 00413103  e858dcffff           call 0x410d60
// 00413108  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041310c  55                   push ebp
// 0041310d  8bd8                 mov ebx, eax
// 0041310f  e82cffffff           call 0x413040
// 00413114  83c404               add esp, 4
// 00413117  50                   push eax
// 00413118  53                   push ebx
// 00413119  ff1550e38900         call dword ptr [0x89e350]
// 0041311f  85c0                 test eax, eax
// 00413121  755d                 jne 0x413180
// 00413123  eb0b                 jmp 0x413130
// 00413125  8da42400000000       lea esp, [esp]
// 0041312c  8d642400             lea esp, [esp]
// 00413130  81e6ffffff3f         and esi, 0x3fffffff
// 00413136  81ce00000040         or esi, 0x40000000
// 0041313c  8d642400             lea esp, [esp]
// 00413140  85f6                 test esi, esi
// 00413142  7904                 jns 0x413148
// 00413144  8bc6                 mov eax, esi
// 00413146  eb08                 jmp 0x413150
// 00413148  8d46ff               lea eax, [esi - 1]
// 0041314b  0d00000080           or eax, 0x80000000
// 00413150  25ffffffbf           and eax, 0xbfffffff
// 00413155  8bc8                 mov ecx, eax
// 00413157  8bd7                 mov edx, edi
// 00413159  8bc6                 mov eax, esi
// 0041315b  f00fb10a             lock cmpxchg dword ptr [edx], ecx
// 0041315f  3bc6                 cmp eax, esi
// 00413161  7404                 je 0x413167
// 00413163  8bf0                 mov esi, eax
// 00413165  ebd9                 jmp 0x413140
// 00413167  85f6                 test esi, esi
// 00413169  7925                 jns 0x413190
// 0041316b  55                   push ebp
// 0041316c  e8cffeffff           call 0x413040
// 00413171  83c404               add esp, 4
// 00413174  50                   push eax
// 00413175  53                   push ebx
// 00413176  ff1550e38900         call dword ptr [0x89e350]
// 0041317c  85c0                 test eax, eax
// 0041317e  74b0                 je 0x413130
// 00413180  83c8ff               or eax, 0xffffffff
// 00413183  f00fc107             lock xadd dword ptr [edi], eax
// 00413187  5d                   pop ebp
// 00413188  5b                   pop ebx
// 00413189  5e                   pop esi
// 0041318a  32c0                 xor al, al
// 0041318c  5f                   pop edi
// 0041318d  c20400               ret 4
// 00413190  5d                   pop ebp
// 00413191  5b                   pop ebx
// 00413192  5e                   pop esi
// 00413193  b001                 mov al, 1
// 00413195  5f                   pop edi
// 00413196  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?timed_lock@basic_timed_mutex@detail@boost@@QAE_NABVptime@posix_time@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
