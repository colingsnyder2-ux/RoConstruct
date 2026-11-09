// from server: 100% by auto
// roc 2012-06 00413360  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00413360
//
// 00413360  57                   push edi
// 00413361  8bf9                 mov edi, ecx
// 00413363  8bc7                 mov eax, edi
// 00413365  f00fba281f           lock bts dword ptr [eax], 0x1f
// 0041336a  7206                 jb 0x413372
// 0041336c  b001                 mov al, 1
// 0041336e  5f                   pop edi
// 0041336f  c20400               ret 4
// 00413372  56                   push esi
// 00413373  8b37                 mov esi, dword ptr [edi]
// 00413375  85f6                 test esi, esi
// 00413377  7905                 jns 0x41337e
// 00413379  8d4601               lea eax, [esi + 1]
// 0041337c  eb07                 jmp 0x413385
// 0041337e  8bc6                 mov eax, esi
// 00413380  0d00000080           or eax, 0x80000000
// 00413385  8bc8                 mov ecx, eax
// 00413387  8bd7                 mov edx, edi
// 00413389  8bc6                 mov eax, esi
// 0041338b  f00fb10a             lock cmpxchg dword ptr [edx], ecx
// 0041338f  3bc6                 cmp eax, esi
// 00413391  7404                 je 0x413397
// 00413393  8bf0                 mov esi, eax
// 00413395  ebde                 jmp 0x413375
// 00413397  53                   push ebx
// 00413398  55                   push ebp
// 00413399  85f6                 test esi, esi
// 0041339b  0f898f000000         jns 0x413430
// 004133a1  8bcf                 mov ecx, edi
// 004133a3  e81886ffff           call 0x40b9c0
// 004133a8  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004133ac  55                   push ebp
// 004133ad  8bd8                 mov ebx, eax
// 004133af  e82cffffff           call 0x4132e0
// 004133b4  83c404               add esp, 4
// 004133b7  50                   push eax
// 004133b8  53                   push ebx
// 004133b9  ff15e421b200         call dword ptr [0xb221e4]
// 004133bf  85c0                 test eax, eax
// 004133c1  755d                 jne 0x413420
// 004133c3  eb0b                 jmp 0x4133d0
// 004133c5  8da42400000000       lea esp, [esp]
// 004133cc  8d642400             lea esp, [esp]
// 004133d0  81e6ffffff3f         and esi, 0x3fffffff
// 004133d6  81ce00000040         or esi, 0x40000000
// 004133dc  8d642400             lea esp, [esp]
// 004133e0  85f6                 test esi, esi
// 004133e2  7904                 jns 0x4133e8
// 004133e4  8bc6                 mov eax, esi
// 004133e6  eb08                 jmp 0x4133f0
// 004133e8  8d46ff               lea eax, [esi - 1]
// 004133eb  0d00000080           or eax, 0x80000000
// 004133f0  25ffffffbf           and eax, 0xbfffffff
// 004133f5  8bc8                 mov ecx, eax
// 004133f7  8bd7                 mov edx, edi
// 004133f9  8bc6                 mov eax, esi
// 004133fb  f00fb10a             lock cmpxchg dword ptr [edx], ecx
// 004133ff  3bc6                 cmp eax, esi
// 00413401  7404                 je 0x413407
// 00413403  8bf0                 mov esi, eax
// 00413405  ebd9                 jmp 0x4133e0
// 00413407  85f6                 test esi, esi
// 00413409  7925                 jns 0x413430
// 0041340b  55                   push ebp
// 0041340c  e8cffeffff           call 0x4132e0
// 00413411  83c404               add esp, 4
// 00413414  50                   push eax
// 00413415  53                   push ebx
// 00413416  ff15e421b200         call dword ptr [0xb221e4]
// 0041341c  85c0                 test eax, eax
// 0041341e  74b0                 je 0x4133d0
// 00413420  83c8ff               or eax, 0xffffffff
// 00413423  f00fc107             lock xadd dword ptr [edi], eax
// 00413427  5d                   pop ebp
// 00413428  5b                   pop ebx
// 00413429  5e                   pop esi
// 0041342a  32c0                 xor al, al
// 0041342c  5f                   pop edi
// 0041342d  c20400               ret 4
// 00413430  5d                   pop ebp
// 00413431  5b                   pop ebx
// 00413432  5e                   pop esi
// 00413433  b001                 mov al, 1
// 00413435  5f                   pop edi
// 00413436  c20400               ret 4
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?timed_lock@basic_timed_mutex@detail@boost@@QAE_NABVptime@posix_time@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
