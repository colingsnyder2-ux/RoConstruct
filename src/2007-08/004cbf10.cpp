// from server: 100% by auto
// roc 2007-08 004cbf10  unit: CSHA1  size: 431 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004cbf10
//
// 004cbf10  83ec18               sub esp, 0x18
// 004cbf13  55                   push ebp
// 004cbf14  57                   push edi
// 004cbf15  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004cbf19  85ff                 test edi, edi
// 004cbf1b  894c240c             mov dword ptr [esp + 0xc], ecx
// 004cbf1f  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004cbf27  66c744241471d9       mov word ptr [esp + 0x14], 0xd971
// 004cbf2e  66c74424166dce       mov word ptr [esp + 0x16], 0xce6d
// 004cbf35  66c7442418bf58       mov word ptr [esp + 0x18], 0x58bf
// 004cbf3c  0f8473010000         je 0x4cc0b5
// 004cbf42  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 004cbf46  83fd10               cmp ebp, 0x10
// 004cbf49  0f8c66010000         jl 0x4cc0b5
// 004cbf4f  8bc5                 mov eax, ebp
// 004cbf51  250f000080           and eax, 0x8000000f
// 004cbf56  7905                 jns 0x4cbf5d
// 004cbf58  48                   dec eax
// 004cbf59  83c8f0               or eax, 0xfffffff0
// 004cbf5c  40                   inc eax
// 004cbf5d  0f8552010000         jne 0x4cc0b5
// 004cbf63  8d45f0               lea eax, [ebp - 0x10]
// 004cbf66  83f810               cmp eax, 0x10
// 004cbf69  53                   push ebx
// 004cbf6a  56                   push esi
// 004cbf6b  0f8cb5000000         jl 0x4cc026
// 004cbf71  bd10000000           mov ebp, 0x10
// 004cbf76  2bef                 sub ebp, edi
// 004cbf78  c1e804               shr eax, 4
// 004cbf7b  8d7710               lea esi, [edi + 0x10]
// 004cbf7e  c744242cefffffff     mov dword ptr [esp + 0x2c], 0xffffffef
// 004cbf86  896c2418             mov dword ptr [esp + 0x18], ebp
// 004cbf8a  89442410             mov dword ptr [esp + 0x10], eax
// 004cbf8e  eb04                 jmp 0x4cbf94
// 004cbf90  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004cbf94  56                   push esi
// 004cbf95  6a10                 push 0x10
// 004cbf97  8d8120010000         lea eax, [ecx + 0x120]
// 004cbf9d  56                   push esi
// 004cbf9e  50                   push eax
// 004cbf9f  8d8140020000         lea eax, [ecx + 0x240]
// 004cbfa5  50                   push eax
// 004cbfa6  e865100000           call 0x4cd010
// 004cbfab  83c414               add esp, 0x14
// 004cbfae  33c9                 xor ecx, ecx
// 004cbfb0  03ee                 add ebp, esi
// 004cbfb2  8d442ff1             lea eax, [edi + ebp - 0xf]
// 004cbfb6  8b542430             mov edx, dword ptr [esp + 0x30]
// 004cbfba  3bea                 cmp ebp, edx
// 004cbfbc  7509                 jne 0x4cbfc7
// 004cbfbe  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 004cbfc2  8a1c03               mov bl, byte ptr [ebx + eax]
// 004cbfc5  eb04                 jmp 0x4cbfcb
// 004cbfc7  8a5c0e10             mov bl, byte ptr [esi + ecx + 0x10]
// 004cbfcb  3058ff               xor byte ptr [eax - 1], bl
// 004cbfce  3bea                 cmp ebp, edx
// 004cbfd0  7506                 jne 0x4cbfd8
// 004cbfd2  8a5c3901             mov bl, byte ptr [ecx + edi + 1]
// 004cbfd6  eb04                 jmp 0x4cbfdc
// 004cbfd8  8a5c0e11             mov bl, byte ptr [esi + ecx + 0x11]
// 004cbfdc  3018                 xor byte ptr [eax], bl
// 004cbfde  3bea                 cmp ebp, edx
// 004cbfe0  7506                 jne 0x4cbfe8
// 004cbfe2  8a5c3902             mov bl, byte ptr [ecx + edi + 2]
// 004cbfe6  eb04                 jmp 0x4cbfec
// 004cbfe8  8a5c0e12             mov bl, byte ptr [esi + ecx + 0x12]
// 004cbfec  305801               xor byte ptr [eax + 1], bl
// 004cbfef  3bea                 cmp ebp, edx
// 004cbff1  7506                 jne 0x4cbff9
// 004cbff3  8a543903             mov dl, byte ptr [ecx + edi + 3]
// 004cbff7  eb04                 jmp 0x4cbffd
// 004cbff9  8a540e13             mov dl, byte ptr [esi + ecx + 0x13]
// 004cbffd  305002               xor byte ptr [eax + 2], dl
// 004cc000  83c104               add ecx, 4
// 004cc003  83c004               add eax, 4
// 004cc006  83f910               cmp ecx, 0x10
// 004cc009  72ab                 jb 0x4cbfb6
// 004cc00b  836c242c10           sub dword ptr [esp + 0x2c], 0x10
// 004cc010  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004cc014  83c610               add esi, 0x10
// 004cc017  836c241001           sub dword ptr [esp + 0x10], 1
// 004cc01c  0f856effffff         jne 0x4cbf90
// 004cc022  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 004cc026  57                   push edi
// 004cc027  6a10                 push 0x10
// 004cc029  8d8120010000         lea eax, [ecx + 0x120]
// 004cc02f  57                   push edi
// 004cc030  50                   push eax
// 004cc031  81c140020000         add ecx, 0x240
// 004cc037  51                   push ecx
// 004cc038  e8d30f0000           call 0x4cd010
// 004cc03d  8a4705               mov al, byte ptr [edi + 5]
// 004cc040  8b1f                 mov ebx, dword ptr [edi]
// 004cc042  240f                 and al, 0xf
// 004cc044  0fb6f0               movzx esi, al
// 004cc047  2bee                 sub ebp, esi
// 004cc049  8d45fa               lea eax, [ebp - 6]
// 004cc04c  8b6c244c             mov ebp, dword ptr [esp + 0x4c]
// 004cc050  83c414               add esp, 0x14
// 004cc053  8d4c3002             lea ecx, [eax + esi + 2]
// 004cc057  51                   push ecx
// 004cc058  8d5704               lea edx, [edi + 4]
// 004cc05b  52                   push edx
// 004cc05c  8d4c2424             lea ecx, [esp + 0x24]
// 004cc060  894500               mov dword ptr [ebp], eax
// 004cc063  e8f8120000           call 0x4cd360
// 004cc068  3b5c2424             cmp ebx, dword ptr [esp + 0x24]
// 004cc06c  740c                 je 0x4cc07a
// 004cc06e  5e                   pop esi
// 004cc06f  5b                   pop ebx
// 004cc070  5f                   pop edi
// 004cc071  32c0                 xor al, al
// 004cc073  5d                   pop ebp
// 004cc074  83c418               add esp, 0x18
// 004cc077  c21000               ret 0x10
// 004cc07a  8b4d00               mov ecx, dword ptr [ebp]
// 004cc07d  8b442434             mov eax, dword ptr [esp + 0x34]
// 004cc081  3bf8                 cmp edi, eax
// 004cc083  51                   push ecx
// 004cc084  8d543e06             lea edx, [esi + edi + 6]
// 004cc088  52                   push edx
// 004cc089  50                   push eax
// 004cc08a  7515                 jne 0x4cc0a1
// 004cc08c  ff150ce97700         call dword ptr [0x77e90c]
// 004cc092  83c40c               add esp, 0xc
// 004cc095  5e                   pop esi
// 004cc096  5b                   pop ebx
// 004cc097  5f                   pop edi
// 004cc098  b001                 mov al, 1
// 004cc09a  5d                   pop ebp
// 004cc09b  83c418               add esp, 0x18
// 004cc09e  c21000               ret 0x10
// 004cc0a1  e8a64c1600           call 0x630d4c
// 004cc0a6  83c40c               add esp, 0xc
// 004cc0a9  5e                   pop esi
// 004cc0aa  5b                   pop ebx
// 004cc0ab  5f                   pop edi
// 004cc0ac  b001                 mov al, 1
// 004cc0ae  5d                   pop ebp
// 004cc0af  83c418               add esp, 0x18
// 004cc0b2  c21000               ret 0x10
// 004cc0b5  5f                   pop edi
// 004cc0b6  32c0                 xor al, al
// 004cc0b8  5d                   pop ebp
// 004cc0b9  83c418               add esp, 0x18
// 004cc0bc  c21000               ret 0x10
// library openrbx-raknet/DataBlockEncryptor.cpp (function ?Decrypt@DataBlockEncryptor@@QAE_NPAEH0PAH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DataBlockEncryptor.cpp
