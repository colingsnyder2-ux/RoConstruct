// from server: 100% by auto
// roc 2008-06 004d5a00  unit: CSHA1  size: 353 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d5a00
//
// 004d5a00  83ec14               sub esp, 0x14
// 004d5a03  53                   push ebx
// 004d5a04  55                   push ebp
// 004d5a05  894c240c             mov dword ptr [esp + 0xc], ecx
// 004d5a09  56                   push esi
// 004d5a0a  b871d90000           mov eax, 0xd971
// 004d5a0f  b96dce0000           mov ecx, 0xce6d
// 004d5a14  babf580000           mov edx, 0x58bf
// 004d5a19  57                   push edi
// 004d5a1a  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004d5a22  6689442418           mov word ptr [esp + 0x18], ax
// 004d5a27  66894c241a           mov word ptr [esp + 0x1a], cx
// 004d5a2c  668954241c           mov word ptr [esp + 0x1c], dx
// 004d5a31  e8eae6ffff           call 0x4d4120
// 004d5a36  88442412             mov byte ptr [esp + 0x12], al
// 004d5a3a  8a44242c             mov al, byte ptr [esp + 0x2c]
// 004d5a3e  0405                 add al, 5
// 004d5a40  240f                 and al, 0xf
// 004d5a42  b30f                 mov bl, 0xf
// 004d5a44  2ad8                 sub bl, al
// 004d5a46  e8d5e6ffff           call 0x4d4120
// 004d5a4b  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004d5a4f  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 004d5a53  8b542434             mov edx, dword ptr [esp + 0x34]
// 004d5a57  c0e004               shl al, 4
// 004d5a5a  0ac3                 or al, bl
// 004d5a5c  0fb6f3               movzx esi, bl
// 004d5a5f  88442413             mov byte ptr [esp + 0x13], al
// 004d5a63  8b442428             mov eax, dword ptr [esp + 0x28]
// 004d5a67  8d4c3e06             lea ecx, [esi + edi + 6]
// 004d5a6b  57                   push edi
// 004d5a6c  890a                 mov dword ptr [edx], ecx
// 004d5a6e  50                   push eax
// 004d5a6f  3bc5                 cmp eax, ebp
// 004d5a71  750d                 jne 0x4d5a80
// 004d5a73  8d442e06             lea eax, [esi + ebp + 6]
// 004d5a77  50                   push eax
// 004d5a78  ff15cc278000         call dword ptr [0x8027cc]
// 004d5a7e  eb0a                 jmp 0x4d5a8a
// 004d5a80  8d4c2e06             lea ecx, [esi + ebp + 6]
// 004d5a84  51                   push ecx
// 004d5a85  e856bd1c00           call 0x6a17e0
// 004d5a8a  8a54241e             mov dl, byte ptr [esp + 0x1e]
// 004d5a8e  8a44241f             mov al, byte ptr [esp + 0x1f]
// 004d5a92  83c40c               add esp, 0xc
// 004d5a95  33db                 xor ebx, ebx
// 004d5a97  885504               mov byte ptr [ebp + 4], dl
// 004d5a9a  884505               mov byte ptr [ebp + 5], al
// 004d5a9d  85f6                 test esi, esi
// 004d5a9f  760e                 jbe 0x4d5aaf
// 004d5aa1  e87ae6ffff           call 0x4d4120
// 004d5aa6  88442b06             mov byte ptr [ebx + ebp + 6], al
// 004d5aaa  43                   inc ebx
// 004d5aab  3bde                 cmp ebx, esi
// 004d5aad  72f2                 jb 0x4d5aa1
// 004d5aaf  8d4c3e02             lea ecx, [esi + edi + 2]
// 004d5ab3  51                   push ecx
// 004d5ab4  8d4504               lea eax, [ebp + 4]
// 004d5ab7  50                   push eax
// 004d5ab8  8d4c2420             lea ecx, [esp + 0x20]
// 004d5abc  e83f140000           call 0x4d6f00
// 004d5ac1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004d5ac5  8b542420             mov edx, dword ptr [esp + 0x20]
// 004d5ac9  55                   push ebp
// 004d5aca  6a10                 push 0x10
// 004d5acc  55                   push ebp
// 004d5acd  8d8140020000         lea eax, [ecx + 0x240]
// 004d5ad3  51                   push ecx
// 004d5ad4  50                   push eax
// 004d5ad5  895500               mov dword ptr [ebp], edx
// 004d5ad8  e8930d0000           call 0x4d6870
// 004d5add  8b442448             mov eax, dword ptr [esp + 0x48]
// 004d5ae1  8b38                 mov edi, dword ptr [eax]
// 004d5ae3  83ef10               sub edi, 0x10
// 004d5ae6  83c414               add esp, 0x14
// 004d5ae9  33f6                 xor esi, esi
// 004d5aeb  83ff10               cmp edi, 0x10
// 004d5aee  7267                 jb 0x4d5b57
// 004d5af0  8d1c2f               lea ebx, [edi + ebp]
// 004d5af3  895c242c             mov dword ptr [esp + 0x2c], ebx
// 004d5af7  8bd6                 mov edx, esi
// 004d5af9  33c9                 xor ecx, ecx
// 004d5afb  8bc3                 mov eax, ebx
// 004d5afd  2bd7                 sub edx, edi
// 004d5aff  8d742e02             lea esi, [esi + ebp + 2]
// 004d5b03  0fb61c02             movzx ebx, byte ptr [edx + eax]
// 004d5b07  3018                 xor byte ptr [eax], bl
// 004d5b09  0fb65c0eff           movzx ebx, byte ptr [esi + ecx - 1]
// 004d5b0e  305801               xor byte ptr [eax + 1], bl
// 004d5b11  0fb61c0e             movzx ebx, byte ptr [esi + ecx]
// 004d5b15  305802               xor byte ptr [eax + 2], bl
// 004d5b18  0fb65c0e01           movzx ebx, byte ptr [esi + ecx + 1]
// 004d5b1d  305803               xor byte ptr [eax + 3], bl
// 004d5b20  83c104               add ecx, 4
// 004d5b23  83c004               add eax, 4
// 004d5b26  83f910               cmp ecx, 0x10
// 004d5b29  72d8                 jb 0x4d5b03
// 004d5b2b  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 004d5b2f  8b442414             mov eax, dword ptr [esp + 0x14]
// 004d5b33  53                   push ebx
// 004d5b34  6a10                 push 0x10
// 004d5b36  53                   push ebx
// 004d5b37  50                   push eax
// 004d5b38  0540020000           add eax, 0x240
// 004d5b3d  50                   push eax
// 004d5b3e  e82d0d0000           call 0x4d6870
// 004d5b43  8bf7                 mov esi, edi
// 004d5b45  83ef10               sub edi, 0x10
// 004d5b48  83eb10               sub ebx, 0x10
// 004d5b4b  83c414               add esp, 0x14
// 004d5b4e  895c242c             mov dword ptr [esp + 0x2c], ebx
// 004d5b52  83ff10               cmp edi, 0x10
// 004d5b55  73a0                 jae 0x4d5af7
// 004d5b57  5f                   pop edi
// 004d5b58  5e                   pop esi
// 004d5b59  5d                   pop ebp
// 004d5b5a  5b                   pop ebx
// 004d5b5b  83c414               add esp, 0x14
// 004d5b5e  c21000               ret 0x10
// library openrbx-raknet/DataBlockEncryptor.cpp (function ?Encrypt@DataBlockEncryptor@@QAEXPAEH0PAH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet DataBlockEncryptor.cpp
