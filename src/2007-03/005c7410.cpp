// from server: 100% by auto
// roc 2007-03 005c7410  unit: seg_005c0000  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c7410
//
// 005c7410  83ec64               sub esp, 0x64
// 005c7413  56                   push esi
// 005c7414  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005c7418  57                   push edi
// 005c7419  6a01                 push 1
// 005c741b  56                   push esi
// 005c741c  e86f1bffff           call 0x5b8f90
// 005c7421  8bf8                 mov edi, eax
// 005c7423  83c408               add esp, 8
// 005c7426  85ff                 test edi, edi
// 005c7428  7510                 jne 0x5c743a
// 005c742a  6874a57b00           push 0x7ba574
// 005c742f  6a01                 push 1
// 005c7431  56                   push esi
// 005c7432  e8b92fffff           call 0x5ba3f0
// 005c7437  83c40c               add esp, 0xc
// 005c743a  3bf7                 cmp esi, edi
// 005c743c  751b                 jne 0x5c7459
// 005c743e  6a07                 push 7
// 005c7440  6858a17b00           push 0x7ba158
// 005c7445  56                   push esi
// 005c7446  e8351cffff           call 0x5b9080
// 005c744b  83c40c               add esp, 0xc
// 005c744e  5f                   pop edi
// 005c744f  b801000000           mov eax, 1
// 005c7454  5e                   pop esi
// 005c7455  83c464               add esp, 0x64
// 005c7458  c3                   ret 
// 005c7459  57                   push edi
// 005c745a  e85124ffff           call 0x5b98b0
// 005c745f  83c404               add esp, 4
// 005c7462  83e800               sub eax, 0
// 005c7465  7420                 je 0x5c7487
// 005c7467  83e801               sub eax, 1
// 005c746a  7457                 je 0x5c74c3
// 005c746c  6a04                 push 4
// 005c746e  68b4a57b00           push 0x7ba5b4
// 005c7473  56                   push esi
// 005c7474  e8071cffff           call 0x5b9080
// 005c7479  83c40c               add esp, 0xc
// 005c747c  5f                   pop edi
// 005c747d  b801000000           mov eax, 1
// 005c7482  5e                   pop esi
// 005c7483  83c464               add esp, 0x64
// 005c7486  c3                   ret 
// 005c7487  8d442408             lea eax, [esp + 8]
// 005c748b  50                   push eax
// 005c748c  6a00                 push 0
// 005c748e  57                   push edi
// 005c748f  e82cb2ffff           call 0x5c26c0
// 005c7494  83c40c               add esp, 0xc
// 005c7497  85c0                 test eax, eax
// 005c7499  7e1b                 jle 0x5c74b6
// 005c749b  6a06                 push 6
// 005c749d  68aca57b00           push 0x7ba5ac
// 005c74a2  56                   push esi
// 005c74a3  e8d81bffff           call 0x5b9080
// 005c74a8  83c40c               add esp, 0xc
// 005c74ab  5f                   pop edi
// 005c74ac  b801000000           mov eax, 1
// 005c74b1  5e                   pop esi
// 005c74b2  83c464               add esp, 0x64
// 005c74b5  c3                   ret 
// 005c74b6  57                   push edi
// 005c74b7  e89415ffff           call 0x5b8a50
// 005c74bc  83c404               add esp, 4
// 005c74bf  85c0                 test eax, eax
// 005c74c1  74a9                 je 0x5c746c
// 005c74c3  6a09                 push 9
// 005c74c5  68a0a57b00           push 0x7ba5a0
// 005c74ca  56                   push esi
// 005c74cb  e8b01bffff           call 0x5b9080
// 005c74d0  83c40c               add esp, 0xc
// 005c74d3  5f                   pop edi
// 005c74d4  b801000000           mov eax, 1
// 005c74d9  5e                   pop esi
// 005c74da  83c464               add esp, 0x64
// 005c74dd  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_costatus)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
