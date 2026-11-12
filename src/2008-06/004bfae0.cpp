// from server: 100% by auto
// roc 2008-06 004bfae0  unit: ProfiledRakPeer  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bfae0
//
// 004bfae0  83ec08               sub esp, 8
// 004bfae3  53                   push ebx
// 004bfae4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004bfae8  55                   push ebp
// 004bfae9  8be9                 mov ebp, ecx
// 004bfaeb  85db                 test ebx, ebx
// 004bfaed  0f84e1000000         je 0x4bfbd4
// 004bfaf3  803b00               cmp byte ptr [ebx], 0
// 004bfaf6  0f84d8000000         je 0x4bfbd4
// 004bfafc  8bc3                 mov eax, ebx
// 004bfafe  8d5001               lea edx, [eax + 1]
// 004bfb01  8a08                 mov cl, byte ptr [eax]
// 004bfb03  40                   inc eax
// 004bfb04  84c9                 test cl, cl
// 004bfb06  75f9                 jne 0x4bfb01
// 004bfb08  2bc2                 sub eax, edx
// 004bfb0a  83f80f               cmp eax, 0xf
// 004bfb0d  0f87c1000000         ja 0x4bfbd4
// 004bfb13  56                   push esi
// 004bfb14  57                   push edi
// 004bfb15  8d8d84020000         lea ecx, [ebp + 0x284]
// 004bfb1b  33ff                 xor edi, edi
// 004bfb1d  33f6                 xor esi, esi
// 004bfb1f  897c2410             mov dword ptr [esp + 0x10], edi
// 004bfb23  894c2414             mov dword ptr [esp + 0x14], ecx
// 004bfb27  e864440100           call 0x4d3f90
// 004bfb2c  8b8da0020000         mov ecx, dword ptr [ebp + 0x2a0]
// 004bfb32  85c9                 test ecx, ecx
// 004bfb34  0f867a000000         jbe 0x4bfbb4
// 004bfb3a  8bbd9c020000         mov edi, dword ptr [ebp + 0x29c]
// 004bfb40  eb04                 jmp 0x4bfb46
// 004bfb42  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004bfb46  8b07                 mov eax, dword ptr [edi]
// 004bfb48  8b10                 mov edx, dword ptr [eax]
// 004bfb4a  8bc3                 mov eax, ebx
// 004bfb4c  8d642400             lea esp, [esp]
// 004bfb50  8a18                 mov bl, byte ptr [eax]
// 004bfb52  3a1a                 cmp bl, byte ptr [edx]
// 004bfb54  751a                 jne 0x4bfb70
// 004bfb56  84db                 test bl, bl
// 004bfb58  7412                 je 0x4bfb6c
// 004bfb5a  8a5801               mov bl, byte ptr [eax + 1]
// 004bfb5d  3a5a01               cmp bl, byte ptr [edx + 1]
// 004bfb60  750e                 jne 0x4bfb70
// 004bfb62  83c002               add eax, 2
// 004bfb65  83c202               add edx, 2
// 004bfb68  84db                 test bl, bl
// 004bfb6a  75e4                 jne 0x4bfb50
// 004bfb6c  33c0                 xor eax, eax
// 004bfb6e  eb05                 jmp 0x4bfb75
// 004bfb70  1bc0                 sbb eax, eax
// 004bfb72  83d8ff               sbb eax, -1
// 004bfb75  85c0                 test eax, eax
// 004bfb77  740a                 je 0x4bfb83
// 004bfb79  46                   inc esi
// 004bfb7a  83c704               add edi, 4
// 004bfb7d  3bf1                 cmp esi, ecx
// 004bfb7f  72c1                 jb 0x4bfb42
// 004bfb81  eb2d                 jmp 0x4bfbb0
// 004bfb83  8b859c020000         mov eax, dword ptr [ebp + 0x29c]
// 004bfb89  8b14b0               mov edx, dword ptr [eax + esi*4]
// 004bfb8c  8d8d9c020000         lea ecx, [ebp + 0x29c]
// 004bfb92  89542410             mov dword ptr [esp + 0x10], edx
// 004bfb96  8b95a0020000         mov edx, dword ptr [ebp + 0x2a0]
// 004bfb9c  8b5490fc             mov edx, dword ptr [eax + edx*4 - 4]
// 004bfba0  8914b0               mov dword ptr [eax + esi*4], edx
// 004bfba3  8b85a0020000         mov eax, dword ptr [ebp + 0x2a0]
// 004bfba9  48                   dec eax
// 004bfbaa  50                   push eax
// 004bfbab  e8e0ddffff           call 0x4bd990
// 004bfbb0  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004bfbb4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004bfbb8  e8e3430100           call 0x4d3fa0
// 004bfbbd  85ff                 test edi, edi
// 004bfbbf  7411                 je 0x4bfbd2
// 004bfbc1  8b0f                 mov ecx, dword ptr [edi]
// 004bfbc3  51                   push ecx
// 004bfbc4  e8b10a1e00           call 0x6a067a
// 004bfbc9  57                   push edi
// 004bfbca  e8ab0a1e00           call 0x6a067a
// 004bfbcf  83c408               add esp, 8
// 004bfbd2  5f                   pop edi
// 004bfbd3  5e                   pop esi
// 004bfbd4  5d                   pop ebp
// 004bfbd5  5b                   pop ebx
// 004bfbd6  83c408               add esp, 8
// 004bfbd9  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?RemoveFromBanList@RakPeer@@UAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
