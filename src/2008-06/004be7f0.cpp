// from server: 100% by auto
// roc 2008-06 004be7f0  unit: ProfiledRakPeer  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004be7f0
//
// 004be7f0  8b442404             mov eax, dword ptr [esp + 4]
// 004be7f4  83ec20               sub esp, 0x20
// 004be7f7  56                   push esi
// 004be7f8  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 004be7fc  57                   push edi
// 004be7fd  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 004be801  57                   push edi
// 004be802  56                   push esi
// 004be803  50                   push eax
// 004be804  e897f9ffff           call 0x4be1a0
// 004be809  83c40c               add esp, 0xc
// 004be80c  33c0                 xor eax, eax
// 004be80e  8bff                 mov edi, edi
// 004be810  833c8700             cmp dword ptr [edi + eax*4], 0
// 004be814  7513                 jne 0x4be829
// 004be816  40                   inc eax
// 004be817  83f808               cmp eax, 8
// 004be81a  72f4                 jb 0x4be810
// 004be81c  b908000000           mov ecx, 8
// 004be821  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004be823  5f                   pop edi
// 004be824  5e                   pop esi
// 004be825  83c420               add esp, 0x20
// 004be828  c3                   ret 
// 004be829  8d4c2408             lea ecx, [esp + 8]
// 004be82d  51                   push ecx
// 004be82e  57                   push edi
// 004be82f  56                   push esi
// 004be830  e86bf9ffff           call 0x4be1a0
// 004be835  83c40c               add esp, 0xc
// 004be838  33c0                 xor eax, eax
// 004be83a  8d9b00000000         lea ebx, [ebx]
// 004be840  837c840800           cmp dword ptr [esp + eax*4 + 8], 0
// 004be845  750c                 jne 0x4be853
// 004be847  40                   inc eax
// 004be848  83f808               cmp eax, 8
// 004be84b  72f3                 jb 0x4be840
// 004be84d  5f                   pop edi
// 004be84e  5e                   pop esi
// 004be84f  83c420               add esp, 0x20
// 004be852  c3                   ret 
// 004be853  57                   push edi
// 004be854  8d54240c             lea edx, [esp + 0xc]
// 004be858  52                   push edx
// 004be859  57                   push edi
// 004be85a  e841f9ffff           call 0x4be1a0
// 004be85f  83c40c               add esp, 0xc
// 004be862  33c0                 xor eax, eax
// 004be864  833c8700             cmp dword ptr [edi + eax*4], 0
// 004be868  7517                 jne 0x4be881
// 004be86a  40                   inc eax
// 004be86b  83f808               cmp eax, 8
// 004be86e  72f4                 jb 0x4be864
// 004be870  8d742408             lea esi, [esp + 8]
// 004be874  b908000000           mov ecx, 8
// 004be879  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004be87b  5f                   pop edi
// 004be87c  5e                   pop esi
// 004be87d  83c420               add esp, 0x20
// 004be880  c3                   ret 
// 004be881  8d442408             lea eax, [esp + 8]
// 004be885  50                   push eax
// 004be886  8bc8                 mov ecx, eax
// 004be888  57                   push edi
// 004be889  51                   push ecx
// 004be88a  e811f9ffff           call 0x4be1a0
// 004be88f  83c40c               add esp, 0xc
// 004be892  33c0                 xor eax, eax
// 004be894  837c840800           cmp dword ptr [esp + eax*4 + 8], 0
// 004be899  75b8                 jne 0x4be853
// 004be89b  40                   inc eax
// 004be89c  83f808               cmp eax, 8
// 004be89f  72f3                 jb 0x4be894
// 004be8a1  5f                   pop edi
// 004be8a2  5e                   pop esi
// 004be8a3  83c420               add esp, 0x20
// 004be8a6  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$GCD@$$BY07I@big@@YAXAAY07I00@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
