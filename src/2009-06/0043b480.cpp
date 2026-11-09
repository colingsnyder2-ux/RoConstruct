// from server: 100% by EspClaude
// roc 2009-06 0043b480  unit: CSelectionPropGrid  size: 1321 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043b480
//
// 0043b480  64a100000000         mov eax, dword ptr fs:[0]
// 0043b486  6aff                 push -1
// 0043b488  6858ff8400           push 0x84ff58
// 0043b48d  50                   push eax
// 0043b48e  64892500000000       mov dword ptr fs:[0], esp
// 0043b495  8b442410             mov eax, dword ptr [esp + 0x10]
// 0043b499  53                   push ebx
// 0043b49a  55                   push ebp
// 0043b49b  56                   push esi
// 0043b49c  8b742420             mov esi, dword ptr [esp + 0x20]
// 0043b4a0  57                   push edi
// 0043b4a1  8bf9                 mov edi, ecx
// 0043b4a3  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0043b4a6  50                   push eax
// 0043b4a7  e8d4d41b00           call 0x5f8980
// 0043b4ac  84c0                 test al, al
// 0043b4ae  0f85e0040000         jne 0x43b994
// 0043b4b4  bb01000000           mov ebx, 1
// 0043b4b9  845e10               test byte ptr [esi + 0x10], bl
// 0043b4bc  0f84d2040000         je 0x43b994
// 0043b4c2  6a00                 push 0
// 0043b4c4  6838c29d00           push 0x9dc238
// 0043b4c9  6874c29d00           push 0x9dc274
// 0043b4ce  6a00                 push 0
// 0043b4d0  56                   push esi
// 0043b4d1  e8a4e72d00           call 0x719c7a
// 0043b4d6  8be8                 mov ebp, eax
// 0043b4d8  83c414               add esp, 0x14
// 0043b4db  85ed                 test ebp, ebp
// 0043b4dd  744f                 je 0x43b52e
// 0043b4df  6844010000           push 0x144
// 0043b4e4  e84fd52d00           call 0x718a38
// 0043b4e9  83c404               add esp, 4
// 0043b4ec  89442420             mov dword ptr [esp + 0x20], eax
// 0043b4f0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0043b4f8  85c0                 test eax, eax
// 0043b4fa  740b                 je 0x43b507
// 0043b4fc  57                   push edi
// 0043b4fd  55                   push ebp
// 0043b4fe  8bc8                 mov ecx, eax
// 0043b500  e83bc7ffff           call 0x437c40
// 0043b505  eb02                 jmp 0x43b509
// 0043b507  33c0                 xor eax, eax
// 0043b509  50                   push eax
// 0043b50a  8bcf                 mov ecx, edi
// 0043b50c  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b514  e8678affff           call 0x433f80
// 0043b519  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b51d  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b524  5f                   pop edi
// 0043b525  5e                   pop esi
// 0043b526  5d                   pop ebp
// 0043b527  5b                   pop ebx
// 0043b528  83c40c               add esp, 0xc
// 0043b52b  c20800               ret 8
// 0043b52e  6a00                 push 0
// 0043b530  684c269e00           push 0x9e264c
// 0043b535  6874c29d00           push 0x9dc274
// 0043b53a  6a00                 push 0
// 0043b53c  56                   push esi
// 0043b53d  e838e72d00           call 0x719c7a
// 0043b542  8be8                 mov ebp, eax
// 0043b544  83c414               add esp, 0x14
// 0043b547  85ed                 test ebp, ebp
// 0043b549  744b                 je 0x43b596
// 0043b54b  6830010000           push 0x130
// 0043b550  e8e3d42d00           call 0x718a38
// 0043b555  83c404               add esp, 4
// 0043b558  89442420             mov dword ptr [esp + 0x20], eax
// 0043b55c  895c2418             mov dword ptr [esp + 0x18], ebx
// 0043b560  85c0                 test eax, eax
// 0043b562  740b                 je 0x43b56f
// 0043b564  57                   push edi
// 0043b565  55                   push ebp
// 0043b566  8bc8                 mov ecx, eax
// 0043b568  e8b394ffff           call 0x434a20
// 0043b56d  eb02                 jmp 0x43b571
// 0043b56f  33c0                 xor eax, eax
// 0043b571  50                   push eax
// 0043b572  8bcf                 mov ecx, edi
// 0043b574  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b57c  e82f8bffff           call 0x4340b0
// 0043b581  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b585  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b58c  5f                   pop edi
// 0043b58d  5e                   pop esi
// 0043b58e  5d                   pop ebp
// 0043b58f  5b                   pop ebx
// 0043b590  83c40c               add esp, 0xc
// 0043b593  c20800               ret 8
// 0043b596  6a00                 push 0
// 0043b598  6810269e00           push 0x9e2610
// 0043b59d  6874c29d00           push 0x9dc274
// 0043b5a2  6a00                 push 0
// 0043b5a4  56                   push esi
// 0043b5a5  e8d0e62d00           call 0x719c7a
// 0043b5aa  8bd8                 mov ebx, eax
// 0043b5ac  83c414               add esp, 0x14
// 0043b5af  85db                 test ebx, ebx
// 0043b5b1  744f                 je 0x43b602
// 0043b5b3  6830010000           push 0x130
// 0043b5b8  e87bd42d00           call 0x718a38
// 0043b5bd  83c404               add esp, 4
// 0043b5c0  89442420             mov dword ptr [esp + 0x20], eax
// 0043b5c4  c744241802000000     mov dword ptr [esp + 0x18], 2
// 0043b5cc  85c0                 test eax, eax
// 0043b5ce  740b                 je 0x43b5db
// 0043b5d0  57                   push edi
// 0043b5d1  53                   push ebx
// 0043b5d2  8bc8                 mov ecx, eax
// 0043b5d4  e8f797ffff           call 0x434dd0
// 0043b5d9  eb02                 jmp 0x43b5dd
// 0043b5db  33c0                 xor eax, eax
// 0043b5dd  50                   push eax
// 0043b5de  8bcf                 mov ecx, edi
// 0043b5e0  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b5e8  e8c38affff           call 0x4340b0
// 0043b5ed  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b5f1  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b5f8  5f                   pop edi
// 0043b5f9  5e                   pop esi
// 0043b5fa  5d                   pop ebp
// 0043b5fb  5b                   pop ebx
// 0043b5fc  83c40c               add esp, 0xc
// 0043b5ff  c20800               ret 8
// 0043b602  6a00                 push 0
// 0043b604  68c8259e00           push 0x9e25c8
// 0043b609  6874c29d00           push 0x9dc274
// 0043b60e  6a00                 push 0
// 0043b610  56                   push esi
// 0043b611  e864e62d00           call 0x719c7a
// 0043b616  8bd8                 mov ebx, eax
// 0043b618  83c414               add esp, 0x14
// 0043b61b  85db                 test ebx, ebx
// 0043b61d  744f                 je 0x43b66e
// 0043b61f  683c010000           push 0x13c
// 0043b624  e80fd42d00           call 0x718a38
// 0043b629  83c404               add esp, 4
// 0043b62c  89442420             mov dword ptr [esp + 0x20], eax
// 0043b630  c744241803000000     mov dword ptr [esp + 0x18], 3
// 0043b638  85c0                 test eax, eax
// 0043b63a  740b                 je 0x43b647
// 0043b63c  57                   push edi
// 0043b63d  53                   push ebx
// 0043b63e  8bc8                 mov ecx, eax
// 0043b640  e80b9bffff           call 0x435150
// 0043b645  eb02                 jmp 0x43b649
// 0043b647  33c0                 xor eax, eax
// 0043b649  50                   push eax
// 0043b64a  8bcf                 mov ecx, edi
// 0043b64c  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b654  e8878bffff           call 0x4341e0
// 0043b659  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b65d  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b664  5f                   pop edi
// 0043b665  5e                   pop esi
// 0043b666  5d                   pop ebp
// 0043b667  5b                   pop ebx
// 0043b668  83c40c               add esp, 0xc
// 0043b66b  c20800               ret 8
// 0043b66e  6a00                 push 0
// 0043b670  6878259e00           push 0x9e2578
// 0043b675  6874c29d00           push 0x9dc274
// 0043b67a  6a00                 push 0
// 0043b67c  56                   push esi
// 0043b67d  e8f8e52d00           call 0x719c7a
// 0043b682  8bd8                 mov ebx, eax
// 0043b684  83c414               add esp, 0x14
// 0043b687  85db                 test ebx, ebx
// 0043b689  744f                 je 0x43b6da
// 0043b68b  683c010000           push 0x13c
// 0043b690  e8a3d32d00           call 0x718a38
// 0043b695  83c404               add esp, 4
// 0043b698  89442420             mov dword ptr [esp + 0x20], eax
// 0043b69c  c744241804000000     mov dword ptr [esp + 0x18], 4
// 0043b6a4  85c0                 test eax, eax
// 0043b6a6  740b                 je 0x43b6b3
// 0043b6a8  57                   push edi
// 0043b6a9  53                   push ebx
// 0043b6aa  8bc8                 mov ecx, eax
// 0043b6ac  e84fc7ffff           call 0x437e00
// 0043b6b1  eb02                 jmp 0x43b6b5
// 0043b6b3  33c0                 xor eax, eax
// 0043b6b5  50                   push eax
// 0043b6b6  8bcf                 mov ecx, edi
// 0043b6b8  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b6c0  e81b8bffff           call 0x4341e0
// 0043b6c5  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b6c9  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b6d0  5f                   pop edi
// 0043b6d1  5e                   pop esi
// 0043b6d2  5d                   pop ebp
// 0043b6d3  5b                   pop ebx
// 0043b6d4  83c40c               add esp, 0xc
// 0043b6d7  c20800               ret 8
// 0043b6da  6a00                 push 0
// 0043b6dc  6830259e00           push 0x9e2530
// 0043b6e1  6874c29d00           push 0x9dc274
// 0043b6e6  6a00                 push 0
// 0043b6e8  56                   push esi
// 0043b6e9  e88ce52d00           call 0x719c7a
// 0043b6ee  8bd8                 mov ebx, eax
// 0043b6f0  83c414               add esp, 0x14
// 0043b6f3  85db                 test ebx, ebx
// 0043b6f5  744f                 je 0x43b746
// 0043b6f7  683c010000           push 0x13c
// 0043b6fc  e837d32d00           call 0x718a38
// 0043b701  83c404               add esp, 4
// 0043b704  89442420             mov dword ptr [esp + 0x20], eax
// 0043b708  c744241805000000     mov dword ptr [esp + 0x18], 5
// 0043b710  85c0                 test eax, eax
// 0043b712  740b                 je 0x43b71f
// 0043b714  57                   push edi
// 0043b715  53                   push ebx
// 0043b716  8bc8                 mov ecx, eax
// 0043b718  e8d3c7ffff           call 0x437ef0
// 0043b71d  eb02                 jmp 0x43b721
// 0043b71f  33c0                 xor eax, eax
// 0043b721  50                   push eax
// 0043b722  8bcf                 mov ecx, edi
// 0043b724  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b72c  e87f89ffff           call 0x4340b0
// 0043b731  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b735  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b73c  5f                   pop edi
// 0043b73d  5e                   pop esi
// 0043b73e  5d                   pop ebp
// 0043b73f  5b                   pop ebx
// 0043b740  83c40c               add esp, 0xc
// 0043b743  c20800               ret 8
// 0043b746  6a00                 push 0
// 0043b748  68fc249e00           push 0x9e24fc
// 0043b74d  6874c29d00           push 0x9dc274
// 0043b752  6a00                 push 0
// 0043b754  56                   push esi
// 0043b755  e820e52d00           call 0x719c7a
// 0043b75a  8bd8                 mov ebx, eax
// 0043b75c  83c414               add esp, 0x14
// 0043b75f  85db                 test ebx, ebx
// 0043b761  744f                 je 0x43b7b2
// 0043b763  6838010000           push 0x138
// 0043b768  e8cbd22d00           call 0x718a38
// 0043b76d  83c404               add esp, 4
// 0043b770  89442420             mov dword ptr [esp + 0x20], eax
// 0043b774  c744241806000000     mov dword ptr [esp + 0x18], 6
// 0043b77c  85c0                 test eax, eax
// 0043b77e  740b                 je 0x43b78b
// 0043b780  57                   push edi
// 0043b781  53                   push ebx
// 0043b782  8bc8                 mov ecx, eax
// 0043b784  e8e7d3ffff           call 0x438b70
// 0043b789  eb02                 jmp 0x43b78d
// 0043b78b  33c0                 xor eax, eax
// 0043b78d  50                   push eax
// 0043b78e  8bcf                 mov ecx, edi
// 0043b790  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b798  e8738bffff           call 0x434310
// 0043b79d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b7a1  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b7a8  5f                   pop edi
// 0043b7a9  5e                   pop esi
// 0043b7aa  5d                   pop ebp
// 0043b7ab  5b                   pop ebx
// 0043b7ac  83c40c               add esp, 0xc
// 0043b7af  c20800               ret 8
// 0043b7b2  6a00                 push 0
// 0043b7b4  68c8249e00           push 0x9e24c8
// 0043b7b9  6874c29d00           push 0x9dc274
// 0043b7be  6a00                 push 0
// 0043b7c0  56                   push esi
// 0043b7c1  e8b4e42d00           call 0x719c7a
// 0043b7c6  8bd8                 mov ebx, eax
// 0043b7c8  83c414               add esp, 0x14
// 0043b7cb  85db                 test ebx, ebx
// 0043b7cd  744f                 je 0x43b81e
// 0043b7cf  6834010000           push 0x134
// 0043b7d4  e85fd22d00           call 0x718a38
// 0043b7d9  83c404               add esp, 4
// 0043b7dc  89442420             mov dword ptr [esp + 0x20], eax
// 0043b7e0  c744241807000000     mov dword ptr [esp + 0x18], 7
// 0043b7e8  85c0                 test eax, eax
// 0043b7ea  740b                 je 0x43b7f7
// 0043b7ec  57                   push edi
// 0043b7ed  53                   push ebx
// 0043b7ee  8bc8                 mov ecx, eax
// 0043b7f0  e85bcbffff           call 0x438350
// 0043b7f5  eb02                 jmp 0x43b7f9
// 0043b7f7  33c0                 xor eax, eax
// 0043b7f9  50                   push eax
// 0043b7fa  8bcf                 mov ecx, edi
// 0043b7fc  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b804  e8a788ffff           call 0x4340b0
// 0043b809  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b80d  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b814  5f                   pop edi
// 0043b815  5e                   pop esi
// 0043b816  5d                   pop ebp
// 0043b817  5b                   pop ebx
// 0043b818  83c40c               add esp, 0xc
// 0043b81b  c20800               ret 8
// 0043b81e  81feecb2a400         cmp esi, 0xa4b2ec
// 0043b824  754f                 jne 0x43b875
// 0043b826  6830010000           push 0x130
// 0043b82b  e808d22d00           call 0x718a38
// 0043b830  83c404               add esp, 4
// 0043b833  89442420             mov dword ptr [esp + 0x20], eax
// 0043b837  c744241808000000     mov dword ptr [esp + 0x18], 8
// 0043b83f  85c0                 test eax, eax
// 0043b841  740b                 je 0x43b84e
// 0043b843  57                   push edi
// 0043b844  56                   push esi
// 0043b845  8bc8                 mov ecx, eax
// 0043b847  e8d4ceffff           call 0x438720
// 0043b84c  eb02                 jmp 0x43b850
// 0043b84e  33c0                 xor eax, eax
// 0043b850  50                   push eax
// 0043b851  8bcf                 mov ecx, edi
// 0043b853  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b85b  e85088ffff           call 0x4340b0
// 0043b860  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b864  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b86b  5f                   pop edi
// 0043b86c  5e                   pop esi
// 0043b86d  5d                   pop ebp
// 0043b86e  5b                   pop ebx
// 0043b86f  83c40c               add esp, 0xc
// 0043b872  c20800               ret 8
// 0043b875  6a00                 push 0
// 0043b877  6880249e00           push 0x9e2480
// 0043b87c  6874c29d00           push 0x9dc274
// 0043b881  6a00                 push 0
// 0043b883  56                   push esi
// 0043b884  e8f1e32d00           call 0x719c7a
// 0043b889  8bd8                 mov ebx, eax
// 0043b88b  83c414               add esp, 0x14
// 0043b88e  85db                 test ebx, ebx
// 0043b890  744f                 je 0x43b8e1
// 0043b892  6830010000           push 0x130
// 0043b897  e89cd12d00           call 0x718a38
// 0043b89c  83c404               add esp, 4
// 0043b89f  89442420             mov dword ptr [esp + 0x20], eax
// 0043b8a3  c744241809000000     mov dword ptr [esp + 0x18], 9
// 0043b8ab  85c0                 test eax, eax
// 0043b8ad  740b                 je 0x43b8ba
// 0043b8af  57                   push edi
// 0043b8b0  53                   push ebx
// 0043b8b1  8bc8                 mov ecx, eax
// 0043b8b3  e848fbffff           call 0x43b400
// 0043b8b8  eb02                 jmp 0x43b8bc
// 0043b8ba  33c0                 xor eax, eax
// 0043b8bc  50                   push eax
// 0043b8bd  8bcf                 mov ecx, edi
// 0043b8bf  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b8c7  e8e487ffff           call 0x4340b0
// 0043b8cc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b8d0  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b8d7  5f                   pop edi
// 0043b8d8  5e                   pop esi
// 0043b8d9  5d                   pop ebp
// 0043b8da  5b                   pop ebx
// 0043b8db  83c40c               add esp, 0xc
// 0043b8de  c20800               ret 8
// 0043b8e1  6a00                 push 0
// 0043b8e3  6828249e00           push 0x9e2428
// 0043b8e8  6874c29d00           push 0x9dc274
// 0043b8ed  6a00                 push 0
// 0043b8ef  56                   push esi
// 0043b8f0  e885e32d00           call 0x719c7a
// 0043b8f5  8bd8                 mov ebx, eax
// 0043b8f7  83c414               add esp, 0x14
// 0043b8fa  85db                 test ebx, ebx
// 0043b8fc  744f                 je 0x43b94d
// 0043b8fe  6830010000           push 0x130
// 0043b903  e830d12d00           call 0x718a38
// 0043b908  83c404               add esp, 4
// 0043b90b  89442420             mov dword ptr [esp + 0x20], eax
// 0043b90f  c74424180a000000     mov dword ptr [esp + 0x18], 0xa
// 0043b917  85c0                 test eax, eax
// 0043b919  740b                 je 0x43b926
// 0043b91b  57                   push edi
// 0043b91c  53                   push ebx
// 0043b91d  8bc8                 mov ecx, eax
// 0043b91f  e85cfaffff           call 0x43b380
// 0043b924  eb02                 jmp 0x43b928
// 0043b926  33c0                 xor eax, eax
// 0043b928  50                   push eax
// 0043b929  8bcf                 mov ecx, edi
// 0043b92b  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b933  e87887ffff           call 0x4340b0
// 0043b938  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b93c  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b943  5f                   pop edi
// 0043b944  5e                   pop esi
// 0043b945  5d                   pop ebp
// 0043b946  5b                   pop ebx
// 0043b947  83c40c               add esp, 0xc
// 0043b94a  c20800               ret 8
// 0043b94d  8b16                 mov edx, dword ptr [esi]
// 0043b94f  8b4218               mov eax, dword ptr [edx + 0x18]
// 0043b952  8bce                 mov ecx, esi
// 0043b954  ffd0                 call eax
// 0043b956  84c0                 test al, al
// 0043b958  743a                 je 0x43b994
// 0043b95a  6830010000           push 0x130
// 0043b95f  e8d4d02d00           call 0x718a38
// 0043b964  83c404               add esp, 4
// 0043b967  89442420             mov dword ptr [esp + 0x20], eax
// 0043b96b  c74424180b000000     mov dword ptr [esp + 0x18], 0xb
// 0043b973  85c0                 test eax, eax
// 0043b975  740b                 je 0x43b982
// 0043b977  57                   push edi
// 0043b978  56                   push esi
// 0043b979  8bc8                 mov ecx, eax
// 0043b97b  e840a0ffff           call 0x4359c0
// 0043b980  eb02                 jmp 0x43b984
// 0043b982  33c0                 xor eax, eax
// 0043b984  50                   push eax
// 0043b985  8bcf                 mov ecx, edi
// 0043b987  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043b98f  e81c87ffff           call 0x4340b0
// 0043b994  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043b998  5f                   pop edi
// 0043b999  5e                   pop esi
// 0043b99a  5d                   pop ebp
// 0043b99b  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b9a2  5b                   pop ebx
// 0043b9a3  83c40c               add esp, 0xc
// 0043b9a6  c20800               ret 8
// copied from an identical function in another client (function ?f@Grid@@QAEXPAXPAUProperty@@@Z)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern "C" void* __cdecl runtime_cast(void*, int, const void*, const void*, int);

extern char descriptorBase;
extern char descriptor0;
extern char descriptor1;
extern char descriptor2;
extern char descriptor3;
extern char descriptor4;
extern char descriptor5;
extern char descriptor6;
extern char descriptor7;
extern char descriptor9;
extern char descriptor10;

struct Grid;
struct Owner {
    bool check(void*);
};

struct Property {
    typedef bool (__thiscall *Query)(Property*);
    void** table;
    char padding[8];
    Owner* owner;
    unsigned char flags;
};
extern Property specialProperty;

struct Editor0 {
    char storage[0x144];
    Editor0(void*, Grid*);
};
struct Editor1 {
    char storage[0x130];
    Editor1(void*, Grid*);
};
struct Editor2 {
    char storage[0x130];
    Editor2(void*, Grid*);
};
struct Editor3 {
    char storage[0x13c];
    Editor3(void*, Grid*);
};
struct Editor4 {
    char storage[0x13c];
    Editor4(void*, Grid*);
};
struct Editor5 {
    char storage[0x13c];
    Editor5(void*, Grid*);
};
struct Editor6 {
    char storage[0x138];
    Editor6(void*, Grid*);
};
struct Editor7 {
    char storage[0x134];
    Editor7(void*, Grid*);
};
struct Editor8 {
    char storage[0x130];
    Editor8(void*, Grid*);
};
struct Editor9 {
    char storage[0x130];
    Editor9(void*, Grid*);
};
struct Editor10 {
    char storage[0x130];
    Editor10(void*, Grid*);
};
struct Editor11 {
    char storage[0x130];
    Editor11(void*, Grid*);
};

struct Grid {
    void add0(Editor0*);
    void add3(Editor3*);
    void add3(Editor4*);
    void add6(Editor6*);
    void addOther(Editor1*);
    void addOther(Editor2*);
    void addOther(Editor5*);
    void addOther(Editor7*);
    void addOther(Editor8*);
    void addOther(Editor9*);
    void addOther(Editor10*);
    void addOther(Editor11*);
    void f(void*, Property*);
};

void Grid::f(void* object, Property* property)
{
    if (property->owner->check(object))
        return;
    if (!(property->flags & 1))
        return;

    void* typed = runtime_cast(property, 0, &descriptorBase, &descriptor0, 0);
    if (typed) {
        add0(new Editor0(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor1, 0);
    if (typed) {
        addOther(new Editor1(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor2, 0);
    if (typed) {
        addOther(new Editor2(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor3, 0);
    if (typed) {
        add3(new Editor3(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor4, 0);
    if (typed) {
        add3(new Editor4(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor5, 0);
    if (typed) {
        addOther(new Editor5(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor6, 0);
    if (typed) {
        add6(new Editor6(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor7, 0);
    if (typed) {
        addOther(new Editor7(typed, this));
        return;
    }

    if (property == &specialProperty) {
        addOther(new Editor8(property, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor9, 0);
    if (typed) {
        addOther(new Editor9(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor10, 0);
    if (typed) {
        addOther(new Editor10(typed, this));
        return;
    }

    if (((Property::Query)property->table[6])(property))
        addOther(new Editor11(property, this));
}