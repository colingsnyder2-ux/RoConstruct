// from server: 100% by auto
// roc 2009-12 0079bf00  unit: seg_00790000  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079bf00
//
// 0079bf00  55                   push ebp
// 0079bf01  56                   push esi
// 0079bf02  57                   push edi
// 0079bf03  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0079bf07  6a05                 push 5
// 0079bf09  6a01                 push 1
// 0079bf0b  57                   push edi
// 0079bf0c  e8dfe7feff           call 0x78a6f0
// 0079bf11  6a01                 push 1
// 0079bf13  57                   push edi
// 0079bf14  e8f7ccfeff           call 0x788c10
// 0079bf19  8be8                 mov ebp, eax
// 0079bf1b  55                   push ebp
// 0079bf1c  6a02                 push 2
// 0079bf1e  57                   push edi
// 0079bf1f  e8fce9feff           call 0x78a920
// 0079bf24  8bf0                 mov esi, eax
// 0079bf26  83c420               add esp, 0x20
// 0079bf29  83fe01               cmp esi, 1
// 0079bf2c  7c4f                 jl 0x79bf7d
// 0079bf2e  3bf5                 cmp esi, ebp
// 0079bf30  7f4b                 jg 0x79bf7d
// 0079bf32  56                   push esi
// 0079bf33  6a01                 push 1
// 0079bf35  57                   push edi
// 0079bf36  e855d1feff           call 0x789090
// 0079bf3b  83c40c               add esp, 0xc
// 0079bf3e  3bf5                 cmp esi, ebp
// 0079bf40  7d20                 jge 0x79bf62
// 0079bf42  53                   push ebx
// 0079bf43  8d5e01               lea ebx, [esi + 1]
// 0079bf46  53                   push ebx
// 0079bf47  6a01                 push 1
// 0079bf49  57                   push edi
// 0079bf4a  e841d1feff           call 0x789090
// 0079bf4f  56                   push esi
// 0079bf50  6a01                 push 1
// 0079bf52  57                   push edi
// 0079bf53  e8b8d3feff           call 0x789310
// 0079bf58  8bf3                 mov esi, ebx
// 0079bf5a  83c418               add esp, 0x18
// 0079bf5d  3bf5                 cmp esi, ebp
// 0079bf5f  7ce2                 jl 0x79bf43
// 0079bf61  5b                   pop ebx
// 0079bf62  57                   push edi
// 0079bf63  e8d8cdfeff           call 0x788d40
// 0079bf68  55                   push ebp
// 0079bf69  6a01                 push 1
// 0079bf6b  57                   push edi
// 0079bf6c  e89fd3feff           call 0x789310
// 0079bf71  83c410               add esp, 0x10
// 0079bf74  5f                   pop edi
// 0079bf75  5e                   pop esi
// 0079bf76  b801000000           mov eax, 1
// 0079bf7b  5d                   pop ebp
// 0079bf7c  c3                   ret 
// 0079bf7d  5f                   pop edi
// 0079bf7e  5e                   pop esi
// 0079bf7f  33c0                 xor eax, eax
// 0079bf81  5d                   pop ebp
// 0079bf82  c3                   ret 
// library lua-5.1.3/ltablib.c (function _tremove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ltablib.c
