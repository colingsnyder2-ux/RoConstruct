// from server: 100% by auto
// roc 2007-03 005b9fd0  unit: seg_005b0000  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9fd0
//
// 005b9fd0  53                   push ebx
// 005b9fd1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005b9fd5  8d830f270000         lea eax, [ebx + 0x270f]
// 005b9fdb  3d0f270000           cmp eax, 0x270f
// 005b9fe0  56                   push esi
// 005b9fe1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005b9fe5  770d                 ja 0x5b9ff4
// 005b9fe7  56                   push esi
// 005b9fe8  e863eaffff           call 0x5b8a50
// 005b9fed  83c404               add esp, 4
// 005b9ff0  8d5c0301             lea ebx, [ebx + eax + 1]
// 005b9ff4  6aff                 push -1
// 005b9ff6  56                   push esi
// 005b9ff7  e844ecffff           call 0x5b8c40
// 005b9ffc  83c408               add esp, 8
// 005b9fff  85c0                 test eax, eax
// 005ba001  7511                 jne 0x5ba014
// 005ba003  6afe                 push -2
// 005ba005  56                   push esi
// 005ba006  e855eaffff           call 0x5b8a60
// 005ba00b  83c408               add esp, 8
// 005ba00e  5e                   pop esi
// 005ba00f  83c8ff               or eax, 0xffffffff
// 005ba012  5b                   pop ebx
// 005ba013  c3                   ret 
// 005ba014  57                   push edi
// 005ba015  6a00                 push 0
// 005ba017  53                   push ebx
// 005ba018  56                   push esi
// 005ba019  e852f3ffff           call 0x5b9370
// 005ba01e  6aff                 push -1
// 005ba020  56                   push esi
// 005ba021  e8baedffff           call 0x5b8de0
// 005ba026  6afe                 push -2
// 005ba028  56                   push esi
// 005ba029  8bf8                 mov edi, eax
// 005ba02b  e830eaffff           call 0x5b8a60
// 005ba030  83c41c               add esp, 0x1c
// 005ba033  85ff                 test edi, edi
// 005ba035  7425                 je 0x5ba05c
// 005ba037  57                   push edi
// 005ba038  53                   push ebx
// 005ba039  56                   push esi
// 005ba03a  e831f3ffff           call 0x5b9370
// 005ba03f  6a00                 push 0
// 005ba041  53                   push ebx
// 005ba042  56                   push esi
// 005ba043  e878f5ffff           call 0x5b95c0
// 005ba048  83c418               add esp, 0x18
// 005ba04b  57                   push edi
// 005ba04c  53                   push ebx
// 005ba04d  56                   push esi
// 005ba04e  e86df5ffff           call 0x5b95c0
// 005ba053  83c40c               add esp, 0xc
// 005ba056  8bc7                 mov eax, edi
// 005ba058  5f                   pop edi
// 005ba059  5e                   pop esi
// 005ba05a  5b                   pop ebx
// 005ba05b  c3                   ret 
// 005ba05c  53                   push ebx
// 005ba05d  56                   push esi
// 005ba05e  e85deeffff           call 0x5b8ec0
// 005ba063  8bf8                 mov edi, eax
// 005ba065  83c408               add esp, 8
// 005ba068  83c701               add edi, 1
// 005ba06b  57                   push edi
// 005ba06c  53                   push ebx
// 005ba06d  56                   push esi
// 005ba06e  e84df5ffff           call 0x5b95c0
// 005ba073  83c40c               add esp, 0xc
// 005ba076  8bc7                 mov eax, edi
// 005ba078  5f                   pop edi
// 005ba079  5e                   pop esi
// 005ba07a  5b                   pop ebx
// 005ba07b  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_ref)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
