// from server: 100% by auto
// roc 2007-03 005ba3f0  unit: seg_005b0000  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba3f0
//
// 005ba3f0  83ec64               sub esp, 0x64
// 005ba3f3  53                   push ebx
// 005ba3f4  8b5c246c             mov ebx, dword ptr [esp + 0x6c]
// 005ba3f8  8d442404             lea eax, [esp + 4]
// 005ba3fc  50                   push eax
// 005ba3fd  6a00                 push 0
// 005ba3ff  53                   push ebx
// 005ba400  e8bb820000           call 0x5c26c0
// 005ba405  83c40c               add esp, 0xc
// 005ba408  85c0                 test eax, eax
// 005ba40a  751d                 jne 0x5ba429
// 005ba40c  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 005ba410  8b542470             mov edx, dword ptr [esp + 0x70]
// 005ba414  51                   push ecx
// 005ba415  52                   push edx
// 005ba416  68c4917b00           push 0x7b91c4
// 005ba41b  53                   push ebx
// 005ba41c  e82ff7ffff           call 0x5b9b50
// 005ba421  83c410               add esp, 0x10
// 005ba424  5b                   pop ebx
// 005ba425  83c464               add esp, 0x64
// 005ba428  c3                   ret 
// 005ba429  56                   push esi
// 005ba42a  57                   push edi
// 005ba42b  8d44240c             lea eax, [esp + 0xc]
// 005ba42f  50                   push eax
// 005ba430  68c0917b00           push 0x7b91c0
// 005ba435  53                   push ebx
// 005ba436  e8f58d0000           call 0x5c3230
// 005ba43b  8b742420             mov esi, dword ptr [esp + 0x20]
// 005ba43f  83c40c               add esp, 0xc
// 005ba442  bfb8917b00           mov edi, 0x7b91b8
// 005ba447  b907000000           mov ecx, 7
// 005ba44c  33d2                 xor edx, edx
// 005ba44e  f3a6                 repe cmpsb byte ptr [esi], byte ptr es:[edi]
// 005ba450  5f                   pop edi
// 005ba451  5e                   pop esi
// 005ba452  7524                 jne 0x5ba478
// 005ba454  836c247001           sub dword ptr [esp + 0x70], 1
// 005ba459  751d                 jne 0x5ba478
// 005ba45b  8b442474             mov eax, dword ptr [esp + 0x74]
// 005ba45f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005ba463  50                   push eax
// 005ba464  51                   push ecx
// 005ba465  6898917b00           push 0x7b9198
// 005ba46a  53                   push ebx
// 005ba46b  e8e0f6ffff           call 0x5b9b50
// 005ba470  83c410               add esp, 0x10
// 005ba473  5b                   pop ebx
// 005ba474  83c464               add esp, 0x64
// 005ba477  c3                   ret 
// 005ba478  8b442408             mov eax, dword ptr [esp + 8]
// 005ba47c  85c0                 test eax, eax
// 005ba47e  7509                 jne 0x5ba489
// 005ba480  b89cc57900           mov eax, 0x79c59c
// 005ba485  89442408             mov dword ptr [esp + 8], eax
// 005ba489  8b542474             mov edx, dword ptr [esp + 0x74]
// 005ba48d  52                   push edx
// 005ba48e  50                   push eax
// 005ba48f  8b442478             mov eax, dword ptr [esp + 0x78]
// 005ba493  50                   push eax
// 005ba494  6878917b00           push 0x7b9178
// 005ba499  53                   push ebx
// 005ba49a  e8b1f6ffff           call 0x5b9b50
// 005ba49f  83c414               add esp, 0x14
// 005ba4a2  5b                   pop ebx
// 005ba4a3  83c464               add esp, 0x64
// 005ba4a6  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_argerror)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
