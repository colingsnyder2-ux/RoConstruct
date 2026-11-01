// from server: 100% by auto
// roc 2007-03 005c2d90  unit: seg_005c0000  size: 376 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2d90
//
// 005c2d90  53                   push ebx
// 005c2d91  55                   push ebp
// 005c2d92  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 005c2d96  8bd8                 mov ebx, eax
// 005c2d98  8b4504               mov eax, dword ptr [ebp + 4]
// 005c2d9b  83780806             cmp dword ptr [eax + 8], 6
// 005c2d9f  56                   push esi
// 005c2da0  57                   push edi
// 005c2da1  0f8598000000         jne 0x5c2e3f
// 005c2da7  8b4504               mov eax, dword ptr [ebp + 4]
// 005c2daa  8b08                 mov ecx, dword ptr [eax]
// 005c2dac  80790600             cmp byte ptr [ecx + 6], 0
// 005c2db0  0f8589000000         jne 0x5c2e3f
// 005c2db6  83780806             cmp dword ptr [eax + 8], 6
// 005c2dba  8b7910               mov edi, dword ptr [ecx + 0x10]
// 005c2dbd  7522                 jne 0x5c2de1
// 005c2dbf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005c2dc3  3b6914               cmp ebp, dword ptr [ecx + 0x14]
// 005c2dc6  7506                 jne 0x5c2dce
// 005c2dc8  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005c2dcb  894d0c               mov dword ptr [ebp + 0xc], ecx
// 005c2dce  8b10                 mov edx, dword ptr [eax]
// 005c2dd0  8b4210               mov eax, dword ptr [edx + 0x10]
// 005c2dd3  8b750c               mov esi, dword ptr [ebp + 0xc]
// 005c2dd6  2b700c               sub esi, dword ptr [eax + 0xc]
// 005c2dd9  c1fe02               sar esi, 2
// 005c2ddc  83ee01               sub esi, 1
// 005c2ddf  eb03                 jmp 0x5c2de4
// 005c2de1  83ceff               or esi, 0xffffffff
// 005c2de4  56                   push esi
// 005c2de5  8d4b01               lea ecx, [ebx + 1]
// 005c2de8  51                   push ecx
// 005c2de9  57                   push edi
// 005c2dea  e8619e0300           call 0x5fcc50
// 005c2def  8b542428             mov edx, dword ptr [esp + 0x28]
// 005c2df3  83c40c               add esp, 0xc
// 005c2df6  85c0                 test eax, eax
// 005c2df8  8902                 mov dword ptr [edx], eax
// 005c2dfa  754a                 jne 0x5c2e46
// 005c2dfc  53                   push ebx
// 005c2dfd  56                   push esi
// 005c2dfe  57                   push edi
// 005c2dff  e8ccfaffff           call 0x5c28d0
// 005c2e04  8bc8                 mov ecx, eax
// 005c2e06  83e13f               and ecx, 0x3f
// 005c2e09  83c40c               add esp, 0xc
// 005c2e0c  83f90b               cmp ecx, 0xb
// 005c2e0f  772e                 ja 0x5c2e3f
// 005c2e11  0fb689fc2e5c00       movzx ecx, byte ptr [ecx + 0x5c2efc]
// 005c2e18  ff248de42e5c00       jmp dword ptr [ecx*4 + 0x5c2ee4]
// 005c2e1f  8bc8                 mov ecx, eax
// 005c2e21  c1e806               shr eax, 6
// 005c2e24  c1e917               shr ecx, 0x17
// 005c2e27  25ff000000           and eax, 0xff
// 005c2e2c  3bc8                 cmp ecx, eax
// 005c2e2e  7d0f                 jge 0x5c2e3f
// 005c2e30  8b5504               mov edx, dword ptr [ebp + 4]
// 005c2e33  837a0806             cmp dword ptr [edx + 8], 6
// 005c2e37  8bd9                 mov ebx, ecx
// 005c2e39  0f8468ffffff         je 0x5c2da7
// 005c2e3f  5f                   pop edi
// 005c2e40  5e                   pop esi
// 005c2e41  5d                   pop ebp
// 005c2e42  33c0                 xor eax, eax
// 005c2e44  5b                   pop ebx
// 005c2e45  c3                   ret 
// 005c2e46  5f                   pop edi
// 005c2e47  5e                   pop esi
// 005c2e48  5d                   pop ebp
// 005c2e49  b8649a7b00           mov eax, 0x7b9a64
// 005c2e4e  5b                   pop ebx
// 005c2e4f  c3                   ret 
// 005c2e50  8b4f08               mov ecx, dword ptr [edi + 8]
// 005c2e53  c1e80e               shr eax, 0xe
// 005c2e56  c1e004               shl eax, 4
// 005c2e59  8b1408               mov edx, dword ptr [eax + ecx]
// 005c2e5c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005c2e60  5f                   pop edi
// 005c2e61  5e                   pop esi
// 005c2e62  83c210               add edx, 0x10
// 005c2e65  5d                   pop ebp
// 005c2e66  8910                 mov dword ptr [eax], edx
// 005c2e68  b85c9a7b00           mov eax, 0x7b9a5c
// 005c2e6d  5b                   pop ebx
// 005c2e6e  c3                   ret 
// 005c2e6f  c1e80e               shr eax, 0xe
// 005c2e72  25ff010000           and eax, 0x1ff
// 005c2e77  8bcf                 mov ecx, edi
// 005c2e79  e8e2feffff           call 0x5c2d60
// 005c2e7e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005c2e82  5f                   pop edi
// 005c2e83  5e                   pop esi
// 005c2e84  5d                   pop ebp
// 005c2e85  8901                 mov dword ptr [ecx], eax
// 005c2e87  b8549a7b00           mov eax, 0x7b9a54
// 005c2e8c  5b                   pop ebx
// 005c2e8d  c3                   ret 
// 005c2e8e  8b7f1c               mov edi, dword ptr [edi + 0x1c]
// 005c2e91  85ff                 test edi, edi
// 005c2e93  7419                 je 0x5c2eae
// 005c2e95  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005c2e99  c1e817               shr eax, 0x17
// 005c2e9c  8b0487               mov eax, dword ptr [edi + eax*4]
// 005c2e9f  5f                   pop edi
// 005c2ea0  5e                   pop esi
// 005c2ea1  83c010               add eax, 0x10
// 005c2ea4  5d                   pop ebp
// 005c2ea5  8902                 mov dword ptr [edx], eax
// 005c2ea7  b84c9a7b00           mov eax, 0x7b9a4c
// 005c2eac  5b                   pop ebx
// 005c2ead  c3                   ret 
// 005c2eae  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005c2eb2  5f                   pop edi
// 005c2eb3  5e                   pop esi
// 005c2eb4  b89cc57900           mov eax, 0x79c59c
// 005c2eb9  5d                   pop ebp
// 005c2eba  8902                 mov dword ptr [edx], eax
// 005c2ebc  b84c9a7b00           mov eax, 0x7b9a4c
// 005c2ec1  5b                   pop ebx
// 005c2ec2  c3                   ret 
// 005c2ec3  c1e80e               shr eax, 0xe
// 005c2ec6  25ff010000           and eax, 0x1ff
// 005c2ecb  8bcf                 mov ecx, edi
// 005c2ecd  e88efeffff           call 0x5c2d60
// 005c2ed2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005c2ed6  5f                   pop edi
// 005c2ed7  5e                   pop esi
// 005c2ed8  5d                   pop ebp
// 005c2ed9  8901                 mov dword ptr [ecx], eax
// 005c2edb  b8b8917b00           mov eax, 0x7b91b8
// 005c2ee0  5b                   pop ebx
// 005c2ee1  c3                   ret 
// 005c2ee2  8bff                 mov edi, edi
// 005c2ee4  1f                   pop ds
// 005c2ee5  2e5c                 pop esp
// 005c2ee7  008e2e5c0050         add byte ptr [esi + 0x50005c2e], cl
// 005c2eed  2e5c                 pop esp
// 005c2eef  006f2e               add byte ptr [edi + 0x2e], ch
// 005c2ef2  5c                   pop esp
// 005c2ef3  00c3                 add bl, al
// 005c2ef5  2e5c                 pop esp
// 005c2ef7  003f                 add byte ptr [edi], bh
// 005c2ef9  2e5c                 pop esp
// 005c2efb  0000                 add byte ptr [eax], al
// 005c2efd  0505050102           add eax, 0x2010505
// 005c2f02  030505050504         add eax, dword ptr [0x4050505]
// library lua-5.1.1/ldebug.c (function _getobjname)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
