// from server: 100% by auto
// roc 2009-12 006179f0  unit: seg_00610000  size: 502 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006179f0
//
// 006179f0  56                   push esi
// 006179f1  8b742408             mov esi, dword ptr [esp + 8]
// 006179f5  8b4668               mov eax, dword ptr [esi + 0x68]
// 006179f8  a801                 test al, 1
// 006179fa  750d                 jne 0x617a09
// 006179fc  6858959c00           push 0x9c9558
// 00617a01  56                   push esi
// 00617a02  e88987ffff           call 0x610190
// 00617a07  eb2e                 jmp 0x617a37
// 00617a09  a804                 test al, 4
// 00617a0b  741b                 je 0x617a28
// 00617a0d  6840959c00           push 0x9c9540
// 00617a12  56                   push esi
// 00617a13  e82888ffff           call 0x610240
// 00617a18  8b442418             mov eax, dword ptr [esp + 0x18]
// 00617a1c  50                   push eax
// 00617a1d  56                   push esi
// 00617a1e  e8cdf1ffff           call 0x616bf0
// 00617a23  83c410               add esp, 0x10
// 00617a26  5e                   pop esi
// 00617a27  c3                   ret 
// 00617a28  a802                 test al, 2
// 00617a2a  740e                 je 0x617a3a
// 00617a2c  6828959c00           push 0x9c9528
// 00617a31  56                   push esi
// 00617a32  e80988ffff           call 0x610240
// 00617a37  83c408               add esp, 8
// 00617a3a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00617a3e  53                   push ebx
// 00617a3f  33db                 xor ebx, ebx
// 00617a41  3bc3                 cmp eax, ebx
// 00617a43  7425                 je 0x617a6a
// 00617a45  f7400800100000       test dword ptr [eax + 8], 0x1000
// 00617a4c  741c                 je 0x617a6a
// 00617a4e  6810959c00           push 0x9c9510
// 00617a53  56                   push esi
// 00617a54  e8e787ffff           call 0x610240
// 00617a59  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00617a5d  51                   push ecx
// 00617a5e  56                   push esi
// 00617a5f  e88cf1ffff           call 0x616bf0
// 00617a64  83c410               add esp, 0x10
// 00617a67  5b                   pop ebx
// 00617a68  5e                   pop esi
// 00617a69  c3                   ret 
// 00617a6a  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00617a70  55                   push ebp
// 00617a71  57                   push edi
// 00617a72  52                   push edx
// 00617a73  56                   push esi
// 00617a74  e86792ffff           call 0x610ce0
// 00617a79  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00617a7d  8d4501               lea eax, [ebp + 1]
// 00617a80  50                   push eax
// 00617a81  56                   push esi
// 00617a82  e8f991ffff           call 0x610c80
// 00617a87  8bf8                 mov edi, eax
// 00617a89  55                   push ebp
// 00617a8a  57                   push edi
// 00617a8b  56                   push esi
// 00617a8c  89be88020000         mov dword ptr [esi + 0x288], edi
// 00617a92  e8f92fffff           call 0x60aa90
// 00617a97  55                   push ebp
// 00617a98  57                   push edi
// 00617a99  56                   push esi
// 00617a9a  e8d1bbfeff           call 0x603670
// 00617a9f  53                   push ebx
// 00617aa0  56                   push esi
// 00617aa1  e84af1ffff           call 0x616bf0
// 00617aa6  83c430               add esp, 0x30
// 00617aa9  85c0                 test eax, eax
// 00617aab  741b                 je 0x617ac8
// 00617aad  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00617ab3  51                   push ecx
// 00617ab4  56                   push esi
// 00617ab5  e82692ffff           call 0x610ce0
// 00617aba  83c408               add esp, 8
// 00617abd  5f                   pop edi
// 00617abe  5d                   pop ebp
// 00617abf  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00617ac5  5b                   pop ebx
// 00617ac6  5e                   pop esi
// 00617ac7  c3                   ret 
// 00617ac8  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00617ace  881c2a               mov byte ptr [edx + ebp], bl
// 00617ad1  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00617ad7  8bf8                 mov edi, eax
// 00617ad9  381f                 cmp byte ptr [edi], bl
// 00617adb  7408                 je 0x617ae5
// 00617add  8d4900               lea ecx, [ecx]
// 00617ae0  47                   inc edi
// 00617ae1  381f                 cmp byte ptr [edi], bl
// 00617ae3  75fb                 jne 0x617ae0
// 00617ae5  47                   inc edi
// 00617ae6  8d4c28ff             lea ecx, [eax + ebp - 1]
// 00617aea  3bf9                 cmp edi, ecx
// 00617aec  7220                 jb 0x617b0e
// 00617aee  50                   push eax
// 00617aef  56                   push esi
// 00617af0  e8eb91ffff           call 0x610ce0
// 00617af5  68f8949c00           push 0x9c94f8
// 00617afa  56                   push esi
// 00617afb  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00617b01  e83a87ffff           call 0x610240
// 00617b06  83c410               add esp, 0x10
// 00617b09  5f                   pop edi
// 00617b0a  5d                   pop ebp
// 00617b0b  5b                   pop ebx
// 00617b0c  5e                   pop esi
// 00617b0d  c3                   ret 
// 00617b0e  8a07                 mov al, byte ptr [edi]
// 00617b10  47                   inc edi
// 00617b11  84c0                 test al, al
// 00617b13  7410                 je 0x617b25
// 00617b15  68c8949c00           push 0x9c94c8
// 00617b1a  56                   push esi
// 00617b1b  e82087ffff           call 0x610240
// 00617b20  83c408               add esp, 8
// 00617b23  32c0                 xor al, al
// 00617b25  2bbe88020000         sub edi, dword ptr [esi + 0x288]
// 00617b2b  8d542414             lea edx, [esp + 0x14]
// 00617b2f  52                   push edx
// 00617b30  57                   push edi
// 00617b31  0fb6d8               movzx ebx, al
// 00617b34  55                   push ebp
// 00617b35  53                   push ebx
// 00617b36  56                   push esi
// 00617b37  e804e0ffff           call 0x615b40
// 00617b3c  8b442428             mov eax, dword ptr [esp + 0x28]
// 00617b40  8bc8                 mov ecx, eax
// 00617b42  83c414               add esp, 0x14
// 00617b45  2bcf                 sub ecx, edi
// 00617b47  3bf8                 cmp edi, eax
// 00617b49  7771                 ja 0x617bbc
// 00617b4b  83f904               cmp ecx, 4
// 00617b4e  726c                 jb 0x617bbc
// 00617b50  8bae88020000         mov ebp, dword ptr [esi + 0x288]
// 00617b56  0fb6042f             movzx eax, byte ptr [edi + ebp]
// 00617b5a  8d142f               lea edx, [edi + ebp]
// 00617b5d  0fb67a01             movzx edi, byte ptr [edx + 1]
// 00617b61  c1e008               shl eax, 8
// 00617b64  0bc7                 or eax, edi
// 00617b66  0fb67a02             movzx edi, byte ptr [edx + 2]
// 00617b6a  c1e008               shl eax, 8
// 00617b6d  0bc7                 or eax, edi
// 00617b6f  0fb67a03             movzx edi, byte ptr [edx + 3]
// 00617b73  c1e008               shl eax, 8
// 00617b76  0bc7                 or eax, edi
// 00617b78  3bc1                 cmp eax, ecx
// 00617b7a  7330                 jae 0x617bac
// 00617b7c  8bc8                 mov ecx, eax
// 00617b7e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00617b82  51                   push ecx
// 00617b83  52                   push edx
// 00617b84  53                   push ebx
// 00617b85  55                   push ebp
// 00617b86  50                   push eax
// 00617b87  56                   push esi
// 00617b88  e843b1feff           call 0x602cd0
// 00617b8d  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00617b93  51                   push ecx
// 00617b94  56                   push esi
// 00617b95  e84691ffff           call 0x610ce0
// 00617b9a  83c420               add esp, 0x20
// 00617b9d  5f                   pop edi
// 00617b9e  5d                   pop ebp
// 00617b9f  5b                   pop ebx
// 00617ba0  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00617baa  5e                   pop esi
// 00617bab  c3                   ret 
// 00617bac  76d0                 jbe 0x617b7e
// 00617bae  55                   push ebp
// 00617baf  56                   push esi
// 00617bb0  e82b91ffff           call 0x610ce0
// 00617bb5  68a4949c00           push 0x9c94a4
// 00617bba  eb12                 jmp 0x617bce
// 00617bbc  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00617bc2  52                   push edx
// 00617bc3  56                   push esi
// 00617bc4  e81791ffff           call 0x610ce0
// 00617bc9  6878949c00           push 0x9c9478
// 00617bce  56                   push esi
// 00617bcf  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00617bd9  e86286ffff           call 0x610240
// 00617bde  83c410               add esp, 0x10
// 00617be1  5f                   pop edi
// 00617be2  5d                   pop ebp
// 00617be3  5b                   pop ebx
// 00617be4  5e                   pop esi
// 00617be5  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
