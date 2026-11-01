// from server: 100% by auto
// roc 2009-12 0079bc40  unit: seg_00790000  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079bc40
//
// 0079bc40  53                   push ebx
// 0079bc41  56                   push esi
// 0079bc42  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0079bc46  57                   push edi
// 0079bc47  6a05                 push 5
// 0079bc49  6a01                 push 1
// 0079bc4b  56                   push esi
// 0079bc4c  e89feafeff           call 0x78a6f0
// 0079bc51  6a01                 push 1
// 0079bc53  56                   push esi
// 0079bc54  e8b7cffeff           call 0x788c10
// 0079bc59  6a06                 push 6
// 0079bc5b  6a02                 push 2
// 0079bc5d  56                   push esi
// 0079bc5e  8bd8                 mov ebx, eax
// 0079bc60  e88beafeff           call 0x78a6f0
// 0079bc65  bf01000000           mov edi, 1
// 0079bc6a  83c420               add esp, 0x20
// 0079bc6d  3bdf                 cmp ebx, edi
// 0079bc6f  7c41                 jl 0x79bcb2
// 0079bc71  6a02                 push 2
// 0079bc73  56                   push esi
// 0079bc74  e8e7ccfeff           call 0x788960
// 0079bc79  57                   push edi
// 0079bc7a  56                   push esi
// 0079bc7b  e800d1feff           call 0x788d80
// 0079bc80  57                   push edi
// 0079bc81  6a01                 push 1
// 0079bc83  56                   push esi
// 0079bc84  e807d4feff           call 0x789090
// 0079bc89  6a01                 push 1
// 0079bc8b  6a02                 push 2
// 0079bc8d  56                   push esi
// 0079bc8e  e82dd8feff           call 0x7894c0
// 0079bc93  6aff                 push -1
// 0079bc95  56                   push esi
// 0079bc96  e8f5ccfeff           call 0x788990
// 0079bc9b  83c430               add esp, 0x30
// 0079bc9e  85c0                 test eax, eax
// 0079bca0  7516                 jne 0x79bcb8
// 0079bca2  6afe                 push -2
// 0079bca4  56                   push esi
// 0079bca5  e806cbfeff           call 0x7887b0
// 0079bcaa  47                   inc edi
// 0079bcab  83c408               add esp, 8
// 0079bcae  3bfb                 cmp edi, ebx
// 0079bcb0  7ebf                 jle 0x79bc71
// 0079bcb2  5f                   pop edi
// 0079bcb3  5e                   pop esi
// 0079bcb4  33c0                 xor eax, eax
// 0079bcb6  5b                   pop ebx
// 0079bcb7  c3                   ret 
// 0079bcb8  5f                   pop edi
// 0079bcb9  5e                   pop esi
// 0079bcba  b801000000           mov eax, 1
// 0079bcbf  5b                   pop ebx
// 0079bcc0  c3                   ret 
// library lua-5.1/ltablib.c (function _foreachi)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltablib.c
