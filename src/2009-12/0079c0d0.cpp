// from server: 100% by auto
// roc 2009-12 0079c0d0  unit: seg_00790000  size: 1011 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079c0d0
//
// 0079c0d0  51                   push ecx
// 0079c0d1  53                   push ebx
// 0079c0d2  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0079c0d6  55                   push ebp
// 0079c0d7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0079c0db  3beb                 cmp ebp, ebx
// 0079c0dd  0f8ddc030000         jge 0x79c4bf
// 0079c0e3  56                   push esi
// 0079c0e4  8b742414             mov esi, dword ptr [esp + 0x14]
// 0079c0e8  57                   push edi
// 0079c0e9  eb0d                 jmp 0x79c0f8
// 0079c0eb  eb03                 jmp 0x79c0f0
// 0079c0ed  8d4900               lea ecx, [ecx]
// 0079c0f0  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0079c0f4  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0079c0f8  55                   push ebp
// 0079c0f9  6a01                 push 1
// 0079c0fb  56                   push esi
// 0079c0fc  e88fcffeff           call 0x789090
// 0079c101  53                   push ebx
// 0079c102  6a01                 push 1
// 0079c104  56                   push esi
// 0079c105  e886cffeff           call 0x789090
// 0079c10a  6a02                 push 2
// 0079c10c  56                   push esi
// 0079c10d  e87ec8feff           call 0x788990
// 0079c112  83c420               add esp, 0x20
// 0079c115  85c0                 test eax, eax
// 0079c117  743b                 je 0x79c154
// 0079c119  6a02                 push 2
// 0079c11b  56                   push esi
// 0079c11c  e83fc8feff           call 0x788960
// 0079c121  6afe                 push -2
// 0079c123  56                   push esi
// 0079c124  e837c8feff           call 0x788960
// 0079c129  6afc                 push -4
// 0079c12b  56                   push esi
// 0079c12c  e82fc8feff           call 0x788960
// 0079c131  6a01                 push 1
// 0079c133  6a02                 push 2
// 0079c135  56                   push esi
// 0079c136  e885d3feff           call 0x7894c0
// 0079c13b  6aff                 push -1
// 0079c13d  56                   push esi
// 0079c13e  e82dcafeff           call 0x788b70
// 0079c143  6afe                 push -2
// 0079c145  56                   push esi
// 0079c146  8bf8                 mov edi, eax
// 0079c148  e863c6feff           call 0x7887b0
// 0079c14d  83c434               add esp, 0x34
// 0079c150  8bc7                 mov eax, edi
// 0079c152  eb0d                 jmp 0x79c161
// 0079c154  6afe                 push -2
// 0079c156  6aff                 push -1
// 0079c158  56                   push esi
// 0079c159  e852c9feff           call 0x788ab0
// 0079c15e  83c40c               add esp, 0xc
// 0079c161  85c0                 test eax, eax
// 0079c163  7417                 je 0x79c17c
// 0079c165  55                   push ebp
// 0079c166  6a01                 push 1
// 0079c168  56                   push esi
// 0079c169  e8a2d1feff           call 0x789310
// 0079c16e  53                   push ebx
// 0079c16f  6a01                 push 1
// 0079c171  56                   push esi
// 0079c172  e899d1feff           call 0x789310
// 0079c177  83c418               add esp, 0x18
// 0079c17a  eb0b                 jmp 0x79c187
// 0079c17c  6afd                 push -3
// 0079c17e  56                   push esi
// 0079c17f  e82cc6feff           call 0x7887b0
// 0079c184  83c408               add esp, 8
// 0079c187  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0079c18b  8beb                 mov ebp, ebx
// 0079c18d  2be8                 sub ebp, eax
// 0079c18f  83fd01               cmp ebp, 1
// 0079c192  0f8425030000         je 0x79c4bd
// 0079c198  03c3                 add eax, ebx
// 0079c19a  99                   cdq 
// 0079c19b  2bc2                 sub eax, edx
// 0079c19d  8bf8                 mov edi, eax
// 0079c19f  d1ff                 sar edi, 1
// 0079c1a1  57                   push edi
// 0079c1a2  6a01                 push 1
// 0079c1a4  56                   push esi
// 0079c1a5  e8e6cefeff           call 0x789090
// 0079c1aa  8b442428             mov eax, dword ptr [esp + 0x28]
// 0079c1ae  50                   push eax
// 0079c1af  6a01                 push 1
// 0079c1b1  56                   push esi
// 0079c1b2  e8d9cefeff           call 0x789090
// 0079c1b7  6a02                 push 2
// 0079c1b9  56                   push esi
// 0079c1ba  e8d1c7feff           call 0x788990
// 0079c1bf  83c420               add esp, 0x20
// 0079c1c2  85c0                 test eax, eax
// 0079c1c4  743f                 je 0x79c205
// 0079c1c6  6a02                 push 2
// 0079c1c8  56                   push esi
// 0079c1c9  e892c7feff           call 0x788960
// 0079c1ce  6afd                 push -3
// 0079c1d0  56                   push esi
// 0079c1d1  e88ac7feff           call 0x788960
// 0079c1d6  6afd                 push -3
// 0079c1d8  56                   push esi
// 0079c1d9  e882c7feff           call 0x788960
// 0079c1de  6a01                 push 1
// 0079c1e0  6a02                 push 2
// 0079c1e2  56                   push esi
// 0079c1e3  e8d8d2feff           call 0x7894c0
// 0079c1e8  6aff                 push -1
// 0079c1ea  56                   push esi
// 0079c1eb  e880c9feff           call 0x788b70
// 0079c1f0  6afe                 push -2
// 0079c1f2  56                   push esi
// 0079c1f3  8bd8                 mov ebx, eax
// 0079c1f5  e8b6c5feff           call 0x7887b0
// 0079c1fa  8bc3                 mov eax, ebx
// 0079c1fc  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 0079c200  83c434               add esp, 0x34
// 0079c203  eb0d                 jmp 0x79c212
// 0079c205  6aff                 push -1
// 0079c207  6afe                 push -2
// 0079c209  56                   push esi
// 0079c20a  e8a1c8feff           call 0x788ab0
// 0079c20f  83c40c               add esp, 0xc
// 0079c212  85c0                 test eax, eax
// 0079c214  741e                 je 0x79c234
// 0079c216  57                   push edi
// 0079c217  6a01                 push 1
// 0079c219  56                   push esi
// 0079c21a  e8f1d0feff           call 0x789310
// 0079c21f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0079c223  51                   push ecx
// 0079c224  6a01                 push 1
// 0079c226  56                   push esi
// 0079c227  e8e4d0feff           call 0x789310
// 0079c22c  83c418               add esp, 0x18
// 0079c22f  e992000000           jmp 0x79c2c6
// 0079c234  6afe                 push -2
// 0079c236  56                   push esi
// 0079c237  e874c5feff           call 0x7887b0
// 0079c23c  53                   push ebx
// 0079c23d  6a01                 push 1
// 0079c23f  56                   push esi
// 0079c240  e84bcefeff           call 0x789090
// 0079c245  6a02                 push 2
// 0079c247  56                   push esi
// 0079c248  e843c7feff           call 0x788990
// 0079c24d  83c41c               add esp, 0x1c
// 0079c250  85c0                 test eax, eax
// 0079c252  743f                 je 0x79c293
// 0079c254  6a02                 push 2
// 0079c256  56                   push esi
// 0079c257  e804c7feff           call 0x788960
// 0079c25c  6afe                 push -2
// 0079c25e  56                   push esi
// 0079c25f  e8fcc6feff           call 0x788960
// 0079c264  6afc                 push -4
// 0079c266  56                   push esi
// 0079c267  e8f4c6feff           call 0x788960
// 0079c26c  6a01                 push 1
// 0079c26e  6a02                 push 2
// 0079c270  56                   push esi
// 0079c271  e84ad2feff           call 0x7894c0
// 0079c276  6aff                 push -1
// 0079c278  56                   push esi
// 0079c279  e8f2c8feff           call 0x788b70
// 0079c27e  6afe                 push -2
// 0079c280  56                   push esi
// 0079c281  8bd8                 mov ebx, eax
// 0079c283  e828c5feff           call 0x7887b0
// 0079c288  8bc3                 mov eax, ebx
// 0079c28a  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 0079c28e  83c434               add esp, 0x34
// 0079c291  eb0d                 jmp 0x79c2a0
// 0079c293  6afe                 push -2
// 0079c295  6aff                 push -1
// 0079c297  56                   push esi
// 0079c298  e813c8feff           call 0x788ab0
// 0079c29d  83c40c               add esp, 0xc
// 0079c2a0  85c0                 test eax, eax
// 0079c2a2  7417                 je 0x79c2bb
// 0079c2a4  57                   push edi
// 0079c2a5  6a01                 push 1
// 0079c2a7  56                   push esi
// 0079c2a8  e863d0feff           call 0x789310
// 0079c2ad  53                   push ebx
// 0079c2ae  6a01                 push 1
// 0079c2b0  56                   push esi
// 0079c2b1  e85ad0feff           call 0x789310
// 0079c2b6  83c418               add esp, 0x18
// 0079c2b9  eb0b                 jmp 0x79c2c6
// 0079c2bb  6afd                 push -3
// 0079c2bd  56                   push esi
// 0079c2be  e8edc4feff           call 0x7887b0
// 0079c2c3  83c408               add esp, 8
// 0079c2c6  83fd02               cmp ebp, 2
// 0079c2c9  0f84ee010000         je 0x79c4bd
// 0079c2cf  57                   push edi
// 0079c2d0  6a01                 push 1
// 0079c2d2  56                   push esi
// 0079c2d3  e8b8cdfeff           call 0x789090
// 0079c2d8  6aff                 push -1
// 0079c2da  56                   push esi
// 0079c2db  e880c6feff           call 0x788960
// 0079c2e0  8d6bff               lea ebp, [ebx - 1]
// 0079c2e3  55                   push ebp
// 0079c2e4  6a01                 push 1
// 0079c2e6  56                   push esi
// 0079c2e7  896c2430             mov dword ptr [esp + 0x30], ebp
// 0079c2eb  e8a0cdfeff           call 0x789090
// 0079c2f0  57                   push edi
// 0079c2f1  6a01                 push 1
// 0079c2f3  56                   push esi
// 0079c2f4  e817d0feff           call 0x789310
// 0079c2f9  55                   push ebp
// 0079c2fa  6a01                 push 1
// 0079c2fc  56                   push esi
// 0079c2fd  e80ed0feff           call 0x789310
// 0079c302  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 0079c306  83c438               add esp, 0x38
// 0079c309  8da42400000000       lea esp, [esp]
// 0079c310  43                   inc ebx
// 0079c311  53                   push ebx
// 0079c312  6a01                 push 1
// 0079c314  56                   push esi
// 0079c315  e876cdfeff           call 0x789090
// 0079c31a  6a02                 push 2
// 0079c31c  56                   push esi
// 0079c31d  e86ec6feff           call 0x788990
// 0079c322  83c414               add esp, 0x14
// 0079c325  85c0                 test eax, eax
// 0079c327  743b                 je 0x79c364
// 0079c329  6a02                 push 2
// 0079c32b  56                   push esi
// 0079c32c  e82fc6feff           call 0x788960
// 0079c331  6afe                 push -2
// 0079c333  56                   push esi
// 0079c334  e827c6feff           call 0x788960
// 0079c339  6afc                 push -4
// 0079c33b  56                   push esi
// 0079c33c  e81fc6feff           call 0x788960
// 0079c341  6a01                 push 1
// 0079c343  6a02                 push 2
// 0079c345  56                   push esi
// 0079c346  e875d1feff           call 0x7894c0
// 0079c34b  6aff                 push -1
// 0079c34d  56                   push esi
// 0079c34e  e81dc8feff           call 0x788b70
// 0079c353  6afe                 push -2
// 0079c355  56                   push esi
// 0079c356  8bf8                 mov edi, eax
// 0079c358  e853c4feff           call 0x7887b0
// 0079c35d  83c434               add esp, 0x34
// 0079c360  8bc7                 mov eax, edi
// 0079c362  eb0d                 jmp 0x79c371
// 0079c364  6afe                 push -2
// 0079c366  6aff                 push -1
// 0079c368  56                   push esi
// 0079c369  e842c7feff           call 0x788ab0
// 0079c36e  83c40c               add esp, 0xc
// 0079c371  85c0                 test eax, eax
// 0079c373  742b                 je 0x79c3a0
// 0079c375  3b5c2420             cmp ebx, dword ptr [esp + 0x20]
// 0079c379  7e0e                 jle 0x79c389
// 0079c37b  687cad9e00           push 0x9ead7c
// 0079c380  56                   push esi
// 0079c381  e86ad9feff           call 0x789cf0
// 0079c386  83c408               add esp, 8
// 0079c389  6afe                 push -2
// 0079c38b  56                   push esi
// 0079c38c  e81fc4feff           call 0x7887b0
// 0079c391  83c408               add esp, 8
// 0079c394  e977ffffff           jmp 0x79c310
// 0079c399  8da42400000000       lea esp, [esp]
// 0079c3a0  4d                   dec ebp
// 0079c3a1  55                   push ebp
// 0079c3a2  6a01                 push 1
// 0079c3a4  56                   push esi
// 0079c3a5  e8e6ccfeff           call 0x789090
// 0079c3aa  6a02                 push 2
// 0079c3ac  56                   push esi
// 0079c3ad  e8dec5feff           call 0x788990
// 0079c3b2  83c414               add esp, 0x14
// 0079c3b5  85c0                 test eax, eax
// 0079c3b7  743b                 je 0x79c3f4
// 0079c3b9  6a02                 push 2
// 0079c3bb  56                   push esi
// 0079c3bc  e89fc5feff           call 0x788960
// 0079c3c1  6afc                 push -4
// 0079c3c3  56                   push esi
// 0079c3c4  e897c5feff           call 0x788960
// 0079c3c9  6afd                 push -3
// 0079c3cb  56                   push esi
// 0079c3cc  e88fc5feff           call 0x788960
// 0079c3d1  6a01                 push 1
// 0079c3d3  6a02                 push 2
// 0079c3d5  56                   push esi
// 0079c3d6  e8e5d0feff           call 0x7894c0
// 0079c3db  6aff                 push -1
// 0079c3dd  56                   push esi
// 0079c3de  e88dc7feff           call 0x788b70
// 0079c3e3  6afe                 push -2
// 0079c3e5  56                   push esi
// 0079c3e6  8bf8                 mov edi, eax
// 0079c3e8  e8c3c3feff           call 0x7887b0
// 0079c3ed  83c434               add esp, 0x34
// 0079c3f0  8bc7                 mov eax, edi
// 0079c3f2  eb0d                 jmp 0x79c401
// 0079c3f4  6aff                 push -1
// 0079c3f6  6afd                 push -3
// 0079c3f8  56                   push esi
// 0079c3f9  e8b2c6feff           call 0x788ab0
// 0079c3fe  83c40c               add esp, 0xc
// 0079c401  85c0                 test eax, eax
// 0079c403  7424                 je 0x79c429
// 0079c405  3b6c241c             cmp ebp, dword ptr [esp + 0x1c]
// 0079c409  7d0e                 jge 0x79c419
// 0079c40b  687cad9e00           push 0x9ead7c
// 0079c410  56                   push esi
// 0079c411  e8dad8feff           call 0x789cf0
// 0079c416  83c408               add esp, 8
// 0079c419  6afe                 push -2
// 0079c41b  56                   push esi
// 0079c41c  e88fc3feff           call 0x7887b0
// 0079c421  83c408               add esp, 8
// 0079c424  e977ffffff           jmp 0x79c3a0
// 0079c429  3beb                 cmp ebp, ebx
// 0079c42b  7c1a                 jl 0x79c447
// 0079c42d  53                   push ebx
// 0079c42e  6a01                 push 1
// 0079c430  56                   push esi
// 0079c431  e8dacefeff           call 0x789310
// 0079c436  55                   push ebp
// 0079c437  6a01                 push 1
// 0079c439  56                   push esi
// 0079c43a  e8d1cefeff           call 0x789310
// 0079c43f  83c418               add esp, 0x18
// 0079c442  e9c9feffff           jmp 0x79c310
// 0079c447  6afc                 push -4
// 0079c449  56                   push esi
// 0079c44a  e861c3feff           call 0x7887b0
// 0079c44f  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0079c453  57                   push edi
// 0079c454  6a01                 push 1
// 0079c456  56                   push esi
// 0079c457  e834ccfeff           call 0x789090
// 0079c45c  53                   push ebx
// 0079c45d  6a01                 push 1
// 0079c45f  56                   push esi
// 0079c460  e82bccfeff           call 0x789090
// 0079c465  57                   push edi
// 0079c466  6a01                 push 1
// 0079c468  56                   push esi
// 0079c469  e8a2cefeff           call 0x789310
// 0079c46e  53                   push ebx
// 0079c46f  6a01                 push 1
// 0079c471  56                   push esi
// 0079c472  e899cefeff           call 0x789310
// 0079c477  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 0079c47b  8b7c2454             mov edi, dword ptr [esp + 0x54]
// 0079c47f  8bd5                 mov edx, ebp
// 0079c481  8bc3                 mov eax, ebx
// 0079c483  2bd3                 sub edx, ebx
// 0079c485  2bc7                 sub eax, edi
// 0079c487  83c438               add esp, 0x38
// 0079c48a  3bc2                 cmp eax, edx
// 0079c48c  7d0e                 jge 0x79c49c
// 0079c48e  4b                   dec ebx
// 0079c48f  8d4b02               lea ecx, [ebx + 2]
// 0079c492  8bc7                 mov eax, edi
// 0079c494  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0079c498  8bf9                 mov edi, ecx
// 0079c49a  eb0e                 jmp 0x79c4aa
// 0079c49c  8d4301               lea eax, [ebx + 1]
// 0079c49f  8d50fe               lea edx, [eax - 2]
// 0079c4a2  8bdd                 mov ebx, ebp
// 0079c4a4  89542420             mov dword ptr [esp + 0x20], edx
// 0079c4a8  8bea                 mov ebp, edx
// 0079c4aa  53                   push ebx
// 0079c4ab  50                   push eax
// 0079c4ac  56                   push esi
// 0079c4ad  e81efcffff           call 0x79c0d0
// 0079c4b2  83c40c               add esp, 0xc
// 0079c4b5  3bfd                 cmp edi, ebp
// 0079c4b7  0f8c33fcffff         jl 0x79c0f0
// 0079c4bd  5f                   pop edi
// 0079c4be  5e                   pop esi
// 0079c4bf  5d                   pop ebp
// 0079c4c0  5b                   pop ebx
// 0079c4c1  59                   pop ecx
// 0079c4c2  c3                   ret 
// library lua-5.1/ltablib.c (function _auxsort)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltablib.c
