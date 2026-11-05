// from server: 100% by auto
// roc 2011-06 00410900  unit: RBX::Reflection::Metadata::VCallbacks::?$FactoryProduct  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00410900
//
// 00410900  57                   push edi
// 00410901  8bf9                 mov edi, ecx
// 00410903  8bc7                 mov eax, edi
// 00410905  f00fba281f           lock bts dword ptr [eax], 0x1f
// 0041090a  7206                 jb 0x410912
// 0041090c  b001                 mov al, 1
// 0041090e  5f                   pop edi
// 0041090f  c20400               ret 4
// 00410912  56                   push esi
// 00410913  8b37                 mov esi, dword ptr [edi]
// 00410915  85f6                 test esi, esi
// 00410917  7905                 jns 0x41091e
// 00410919  8d4601               lea eax, [esi + 1]
// 0041091c  eb07                 jmp 0x410925
// 0041091e  8bc6                 mov eax, esi
// 00410920  0d00000080           or eax, 0x80000000
// 00410925  8bc8                 mov ecx, eax
// 00410927  8bd7                 mov edx, edi
// 00410929  8bc6                 mov eax, esi
// 0041092b  f00fb10a             lock cmpxchg dword ptr [edx], ecx
// 0041092f  3bc6                 cmp eax, esi
// 00410931  7404                 je 0x410937
// 00410933  8bf0                 mov esi, eax
// 00410935  ebde                 jmp 0x410915
// 00410937  53                   push ebx
// 00410938  55                   push ebp
// 00410939  85f6                 test esi, esi
// 0041093b  0f898f000000         jns 0x4109d0
// 00410941  8bcf                 mov ecx, edi
// 00410943  e86899ffff           call 0x40a2b0
// 00410948  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041094c  55                   push ebp
// 0041094d  8bd8                 mov ebx, eax
// 0041094f  e82cffffff           call 0x410880
// 00410954  83c404               add esp, 4
// 00410957  50                   push eax
// 00410958  53                   push ebx
// 00410959  ff15a803a400         call dword ptr [0xa403a8]
// 0041095f  85c0                 test eax, eax
// 00410961  755d                 jne 0x4109c0
// 00410963  eb0b                 jmp 0x410970
// 00410965  8da42400000000       lea esp, [esp]
// 0041096c  8d642400             lea esp, [esp]
// 00410970  81e6ffffff3f         and esi, 0x3fffffff
// 00410976  81ce00000040         or esi, 0x40000000
// 0041097c  8d642400             lea esp, [esp]
// 00410980  85f6                 test esi, esi
// 00410982  7904                 jns 0x410988
// 00410984  8bc6                 mov eax, esi
// 00410986  eb08                 jmp 0x410990
// 00410988  8d46ff               lea eax, [esi - 1]
// 0041098b  0d00000080           or eax, 0x80000000
// 00410990  25ffffffbf           and eax, 0xbfffffff
// 00410995  8bc8                 mov ecx, eax
// 00410997  8bd7                 mov edx, edi
// 00410999  8bc6                 mov eax, esi
// 0041099b  f00fb10a             lock cmpxchg dword ptr [edx], ecx
// 0041099f  3bc6                 cmp eax, esi
// 004109a1  7404                 je 0x4109a7
// 004109a3  8bf0                 mov esi, eax
// 004109a5  ebd9                 jmp 0x410980
// 004109a7  85f6                 test esi, esi
// 004109a9  7925                 jns 0x4109d0
// 004109ab  55                   push ebp
// 004109ac  e8cffeffff           call 0x410880
// 004109b1  83c404               add esp, 4
// 004109b4  50                   push eax
// 004109b5  53                   push ebx
// 004109b6  ff15a803a400         call dword ptr [0xa403a8]
// 004109bc  85c0                 test eax, eax
// 004109be  74b0                 je 0x410970
// 004109c0  83c8ff               or eax, 0xffffffff
// 004109c3  f00fc107             lock xadd dword ptr [edi], eax
// 004109c7  5d                   pop ebp
// 004109c8  5b                   pop ebx
// 004109c9  5e                   pop esi
// 004109ca  32c0                 xor al, al
// 004109cc  5f                   pop edi
// 004109cd  c20400               ret 4
// 004109d0  5d                   pop ebp
// 004109d1  5b                   pop ebx
// 004109d2  5e                   pop esi
// 004109d3  b001                 mov al, 1
// 004109d5  5f                   pop edi
// 004109d6  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?timed_lock@basic_timed_mutex@detail@boost@@QAE_NABVptime@posix_time@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
