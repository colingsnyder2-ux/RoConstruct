// from server: 100% by auto
// roc 2009-12 00434880  unit: IIHAAH::?$CMap  size: 884 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00434880
//
// 00434880  83ec14               sub esp, 0x14
// 00434883  53                   push ebx
// 00434884  55                   push ebp
// 00434885  56                   push esi
// 00434886  8bf1                 mov esi, ecx
// 00434888  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0043488c  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0043488f  f7d0                 not eax
// 00434891  57                   push edi
// 00434892  89742414             mov dword ptr [esp + 0x14], esi
// 00434896  a801                 test al, 1
// 00434898  0f847d010000         je 0x434a1b
// 0043489e  8b560c               mov edx, dword ptr [esi + 0xc]
// 004348a1  52                   push edx
// 004348a2  e84dfb3b00           call 0x7f43f4
// 004348a7  837e0c00             cmp dword ptr [esi + 0xc], 0
// 004348ab  0f8439030000         je 0x434bea
// 004348b1  33c0                 xor eax, eax
// 004348b3  8944241c             mov dword ptr [esp + 0x1c], eax
// 004348b7  394608               cmp dword ptr [esi + 8], eax
// 004348ba  0f862a030000         jbe 0x434bea
// 004348c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004348c3  8b2c81               mov ebp, dword ptr [ecx + eax*4]
// 004348c6  896c2410             mov dword ptr [esp + 0x10], ebp
// 004348ca  85ed                 test ebp, ebp
// 004348cc  0f8422010000         je 0x4349f4
// 004348d2  eb04                 jmp 0x4348d8
// 004348d4  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 004348d8  8d5504               lea edx, [ebp + 4]
// 004348db  89542418             mov dword ptr [esp + 0x18], edx
// 004348df  85ed                 test ebp, ebp
// 004348e1  0f8426010000         je 0x434a0d
// 004348e7  8b442428             mov eax, dword ptr [esp + 0x28]
// 004348eb  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004348ee  f7d1                 not ecx
// 004348f0  bf01000000           mov edi, 1
// 004348f5  f6c101               test cl, 1
// 004348f8  7436                 je 0x434930
// 004348fa  8d9b00000000         lea ebx, [ebx]
// 00434900  8bdf                 mov ebx, edi
// 00434902  81ffffffff1f         cmp edi, 0x1fffffff
// 00434908  7205                 jb 0x43490f
// 0043490a  bbffffff1f           mov ebx, 0x1fffffff
// 0043490f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434913  8d349d00000000       lea esi, [ebx*4]
// 0043491a  56                   push esi
// 0043491b  55                   push ebp
// 0043491c  e8bbfa3b00           call 0x7f43dc
// 00434921  2bfb                 sub edi, ebx
// 00434923  03ee                 add ebp, esi
// 00434925  85ff                 test edi, edi
// 00434927  77d7                 ja 0x434900
// 00434929  eb36                 jmp 0x434961
// 0043492b  eb03                 jmp 0x434930
// 0043492d  8d4900               lea ecx, [ecx]
// 00434930  8bdf                 mov ebx, edi
// 00434932  81ffffffff1f         cmp edi, 0x1fffffff
// 00434938  7205                 jb 0x43493f
// 0043493a  bbffffff1f           mov ebx, 0x1fffffff
// 0043493f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434943  8d349d00000000       lea esi, [ebx*4]
// 0043494a  56                   push esi
// 0043494b  55                   push ebp
// 0043494c  e885fa3b00           call 0x7f43d6
// 00434951  3bc6                 cmp eax, esi
// 00434953  0f85b9000000         jne 0x434a12
// 00434959  2bfb                 sub edi, ebx
// 0043495b  03ee                 add ebp, esi
// 0043495d  85ff                 test edi, edi
// 0043495f  77cf                 ja 0x434930
// 00434961  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00434965  85ed                 test ebp, ebp
// 00434967  0f84a0000000         je 0x434a0d
// 0043496d  8b542428             mov edx, dword ptr [esp + 0x28]
// 00434971  8b4218               mov eax, dword ptr [edx + 0x18]
// 00434974  f7d0                 not eax
// 00434976  bf01000000           mov edi, 1
// 0043497b  a801                 test al, 1
// 0043497d  7431                 je 0x4349b0
// 0043497f  90                   nop 
// 00434980  8bdf                 mov ebx, edi
// 00434982  81ffffffff1f         cmp edi, 0x1fffffff
// 00434988  7205                 jb 0x43498f
// 0043498a  bbffffff1f           mov ebx, 0x1fffffff
// 0043498f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434993  8d349d00000000       lea esi, [ebx*4]
// 0043499a  56                   push esi
// 0043499b  55                   push ebp
// 0043499c  e83bfa3b00           call 0x7f43dc
// 004349a1  2bfb                 sub edi, ebx
// 004349a3  03ee                 add ebp, esi
// 004349a5  85ff                 test edi, edi
// 004349a7  77d7                 ja 0x434980
// 004349a9  eb32                 jmp 0x4349dd
// 004349ab  eb03                 jmp 0x4349b0
// 004349ad  8d4900               lea ecx, [ecx]
// 004349b0  8bdf                 mov ebx, edi
// 004349b2  81ffffffff1f         cmp edi, 0x1fffffff
// 004349b8  7205                 jb 0x4349bf
// 004349ba  bbffffff1f           mov ebx, 0x1fffffff
// 004349bf  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004349c3  8d349d00000000       lea esi, [ebx*4]
// 004349ca  56                   push esi
// 004349cb  55                   push ebp
// 004349cc  e805fa3b00           call 0x7f43d6
// 004349d1  3bc6                 cmp eax, esi
// 004349d3  753d                 jne 0x434a12
// 004349d5  2bfb                 sub edi, ebx
// 004349d7  03ee                 add ebp, esi
// 004349d9  85ff                 test edi, edi
// 004349db  77d3                 ja 0x4349b0
// 004349dd  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004349e1  8b4108               mov eax, dword ptr [ecx + 8]
// 004349e4  89442410             mov dword ptr [esp + 0x10], eax
// 004349e8  85c0                 test eax, eax
// 004349ea  0f85e4feffff         jne 0x4348d4
// 004349f0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004349f4  8b542414             mov edx, dword ptr [esp + 0x14]
// 004349f8  40                   inc eax
// 004349f9  8944241c             mov dword ptr [esp + 0x1c], eax
// 004349fd  3b4208               cmp eax, dword ptr [edx + 8]
// 00434a00  0f83e4010000         jae 0x434bea
// 00434a06  8bf2                 mov esi, edx
// 00434a08  e9b3feffff           jmp 0x4348c0
// 00434a0d  e8faf03b00           call 0x7f3b0c
// 00434a12  6a00                 push 0
// 00434a14  6a03                 push 3
// 00434a16  e8b5f93b00           call 0x7f43d0
// 00434a1b  e8cef93b00           call 0x7f43ee
// 00434a20  89442410             mov dword ptr [esp + 0x10], eax
// 00434a24  85c0                 test eax, eax
// 00434a26  0f84be010000         je 0x434bea
// 00434a2c  8d642400             lea esp, [esp]
// 00434a30  8b442428             mov eax, dword ptr [esp + 0x28]
// 00434a34  8b4818               mov ecx, dword ptr [eax + 0x18]
// 00434a37  bd01000000           mov ebp, 1
// 00434a3c  296c2410             sub dword ptr [esp + 0x10], ebp
// 00434a40  f7d1                 not ecx
// 00434a42  8d5c241c             lea ebx, [esp + 0x1c]
// 00434a46  f6c101               test cl, 1
// 00434a49  7435                 je 0x434a80
// 00434a4b  8bfd                 mov edi, ebp
// 00434a4d  8d4900               lea ecx, [ecx]
// 00434a50  8bef                 mov ebp, edi
// 00434a52  81ffffffff1f         cmp edi, 0x1fffffff
// 00434a58  7205                 jb 0x434a5f
// 00434a5a  bdffffff1f           mov ebp, 0x1fffffff
// 00434a5f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434a63  8d34ad00000000       lea esi, [ebp*4]
// 00434a6a  56                   push esi
// 00434a6b  53                   push ebx
// 00434a6c  e86bf93b00           call 0x7f43dc
// 00434a71  2bfd                 sub edi, ebp
// 00434a73  03de                 add ebx, esi
// 00434a75  85ff                 test edi, edi
// 00434a77  77d7                 ja 0x434a50
// 00434a79  eb36                 jmp 0x434ab1
// 00434a7b  eb03                 jmp 0x434a80
// 00434a7d  8d4900               lea ecx, [ecx]
// 00434a80  8bfd                 mov edi, ebp
// 00434a82  81fdffffff1f         cmp ebp, 0x1fffffff
// 00434a88  7205                 jb 0x434a8f
// 00434a8a  bfffffff1f           mov edi, 0x1fffffff
// 00434a8f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434a93  8d34bd00000000       lea esi, [edi*4]
// 00434a9a  56                   push esi
// 00434a9b  53                   push ebx
// 00434a9c  e835f93b00           call 0x7f43d6
// 00434aa1  3bc6                 cmp eax, esi
// 00434aa3  0f8569ffffff         jne 0x434a12
// 00434aa9  2bef                 sub ebp, edi
// 00434aab  03de                 add ebx, esi
// 00434aad  85ed                 test ebp, ebp
// 00434aaf  77cf                 ja 0x434a80
// 00434ab1  8b542428             mov edx, dword ptr [esp + 0x28]
// 00434ab5  8b4218               mov eax, dword ptr [edx + 0x18]
// 00434ab8  f7d0                 not eax
// 00434aba  8d5c2418             lea ebx, [esp + 0x18]
// 00434abe  a801                 test al, 1
// 00434ac0  7439                 je 0x434afb
// 00434ac2  bf01000000           mov edi, 1
// 00434ac7  eb07                 jmp 0x434ad0
// 00434ac9  8da42400000000       lea esp, [esp]
// 00434ad0  8bef                 mov ebp, edi
// 00434ad2  81ffffffff1f         cmp edi, 0x1fffffff
// 00434ad8  7205                 jb 0x434adf
// 00434ada  bdffffff1f           mov ebp, 0x1fffffff
// 00434adf  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434ae3  8d34ad00000000       lea esi, [ebp*4]
// 00434aea  56                   push esi
// 00434aeb  53                   push ebx
// 00434aec  e8ebf83b00           call 0x7f43dc
// 00434af1  2bfd                 sub edi, ebp
// 00434af3  03de                 add ebx, esi
// 00434af5  85ff                 test edi, edi
// 00434af7  77d7                 ja 0x434ad0
// 00434af9  eb36                 jmp 0x434b31
// 00434afb  bd01000000           mov ebp, 1
// 00434b00  8bfd                 mov edi, ebp
// 00434b02  81fdffffff1f         cmp ebp, 0x1fffffff
// 00434b08  7205                 jb 0x434b0f
// 00434b0a  bfffffff1f           mov edi, 0x1fffffff
// 00434b0f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00434b13  8d34bd00000000       lea esi, [edi*4]
// 00434b1a  56                   push esi
// 00434b1b  53                   push ebx
// 00434b1c  e8b5f83b00           call 0x7f43d6
// 00434b21  3bc6                 cmp eax, esi
// 00434b23  0f85e9feffff         jne 0x434a12
// 00434b29  2bef                 sub ebp, edi
// 00434b2b  03de                 add ebx, esi
// 00434b2d  85ed                 test ebp, ebp
// 00434b2f  77cf                 ja 0x434b00
// 00434b31  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00434b35  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00434b39  8b6f08               mov ebp, dword ptr [edi + 8]
// 00434b3c  8bf3                 mov esi, ebx
// 00434b3e  c1ee04               shr esi, 4
// 00434b41  33d2                 xor edx, edx
// 00434b43  8bc6                 mov eax, esi
// 00434b45  f7f5                 div ebp
// 00434b47  8b4f04               mov ecx, dword ptr [edi + 4]
// 00434b4a  89542420             mov dword ptr [esp + 0x20], edx
// 00434b4e  85c9                 test ecx, ecx
// 00434b50  7422                 je 0x434b74
// 00434b52  8b0491               mov eax, dword ptr [ecx + edx*4]
// 00434b55  85c0                 test eax, eax
// 00434b57  7417                 je 0x434b70
// 00434b59  8da42400000000       lea esp, [esp]
// 00434b60  39700c               cmp dword ptr [eax + 0xc], esi
// 00434b63  7504                 jne 0x434b69
// 00434b65  3918                 cmp dword ptr [eax], ebx
// 00434b67  746f                 je 0x434bd8
// 00434b69  8b4008               mov eax, dword ptr [eax + 8]
// 00434b6c  85c0                 test eax, eax
// 00434b6e  75f0                 jne 0x434b60
// 00434b70  85c9                 test ecx, ecx
// 00434b72  753c                 jne 0x434bb0
// 00434b74  33c9                 xor ecx, ecx
// 00434b76  8bc5                 mov eax, ebp
// 00434b78  ba04000000           mov edx, 4
// 00434b7d  f7e2                 mul edx
// 00434b7f  0f90c1               seto cl
// 00434b82  f7d9                 neg ecx
// 00434b84  0bc8                 or ecx, eax
// 00434b86  51                   push ecx
// 00434b87  e8b6ef3b00           call 0x7f3b42
// 00434b8c  83c404               add esp, 4
// 00434b8f  894704               mov dword ptr [edi + 4], eax
// 00434b92  85c0                 test eax, eax
// 00434b94  0f8473feffff         je 0x434a0d
// 00434b9a  8d0cad00000000       lea ecx, [ebp*4]
// 00434ba1  51                   push ecx
// 00434ba2  6a00                 push 0
// 00434ba4  50                   push eax
// 00434ba5  e8fafe3b00           call 0x7f4aa4
// 00434baa  83c40c               add esp, 0xc
// 00434bad  896f08               mov dword ptr [edi + 8], ebp
// 00434bb0  837f0400             cmp dword ptr [edi + 4], 0
// 00434bb4  0f8453feffff         je 0x434a0d
// 00434bba  53                   push ebx
// 00434bbb  8bcf                 mov ecx, edi
// 00434bbd  e8ee7d3d00           call 0x80c9b0
// 00434bc2  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00434bc6  89700c               mov dword ptr [eax + 0xc], esi
// 00434bc9  8b5704               mov edx, dword ptr [edi + 4]
// 00434bcc  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00434bcf  895008               mov dword ptr [eax + 8], edx
// 00434bd2  8b5704               mov edx, dword ptr [edi + 4]
// 00434bd5  89048a               mov dword ptr [edx + ecx*4], eax
// 00434bd8  837c241000           cmp dword ptr [esp + 0x10], 0
// 00434bdd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00434be1  894804               mov dword ptr [eax + 4], ecx
// 00434be4  0f8546feffff         jne 0x434a30
// 00434bea  5f                   pop edi
// 00434beb  5e                   pop esi
// 00434bec  5d                   pop ebp
// 00434bed  5b                   pop ebx
// 00434bee  83c414               add esp, 0x14
// 00434bf1  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarTheme.cpp (function ?Serialize@?$CMap@IIIAAI@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarTheme.cpp
