// from server: 100% by auto
// roc 2008-06 00625540  unit: lua_exception  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00625540
//
// 00625540  55                   push ebp
// 00625541  56                   push esi
// 00625542  57                   push edi
// 00625543  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00625547  6a05                 push 5
// 00625549  6a01                 push 1
// 0062554b  57                   push edi
// 0062554c  e8efc0feff           call 0x611640
// 00625551  6a01                 push 1
// 00625553  57                   push edi
// 00625554  e827cbfeff           call 0x612080
// 00625559  8be8                 mov ebp, eax
// 0062555b  55                   push ebp
// 0062555c  6a02                 push 2
// 0062555e  57                   push edi
// 0062555f  e80cc3feff           call 0x611870
// 00625564  83c420               add esp, 0x20
// 00625567  8bf0                 mov esi, eax
// 00625569  85ed                 test ebp, ebp
// 0062556b  7506                 jne 0x625573
// 0062556d  5f                   pop edi
// 0062556e  5e                   pop esi
// 0062556f  33c0                 xor eax, eax
// 00625571  5d                   pop ebp
// 00625572  c3                   ret 
// 00625573  56                   push esi
// 00625574  6a01                 push 1
// 00625576  57                   push edi
// 00625577  e8b4cffeff           call 0x612530
// 0062557c  83c40c               add esp, 0xc
// 0062557f  3bf5                 cmp esi, ebp
// 00625581  7d20                 jge 0x6255a3
// 00625583  53                   push ebx
// 00625584  8d5e01               lea ebx, [esi + 1]
// 00625587  53                   push ebx
// 00625588  6a01                 push 1
// 0062558a  57                   push edi
// 0062558b  e8a0cffeff           call 0x612530
// 00625590  56                   push esi
// 00625591  6a01                 push 1
// 00625593  57                   push edi
// 00625594  e8e7d1feff           call 0x612780
// 00625599  8bf3                 mov esi, ebx
// 0062559b  83c418               add esp, 0x18
// 0062559e  3bf5                 cmp esi, ebp
// 006255a0  7ce2                 jl 0x625584
// 006255a2  5b                   pop ebx
// 006255a3  57                   push edi
// 006255a4  e837ccfeff           call 0x6121e0
// 006255a9  55                   push ebp
// 006255aa  6a01                 push 1
// 006255ac  57                   push edi
// 006255ad  e8ced1feff           call 0x612780
// 006255b2  83c410               add esp, 0x10
// 006255b5  5f                   pop edi
// 006255b6  5e                   pop esi
// 006255b7  b801000000           mov eax, 1
// 006255bc  5d                   pop ebp
// 006255bd  c3                   ret 
// library lua-5.1.2/ltablib.c (function _tremove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ltablib.c
