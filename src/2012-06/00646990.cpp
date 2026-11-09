// from server: 100% by auto
// roc 2012-06 00646990  unit: seg_00640000  size: 549 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00646990
//
// 00646990  57                   push edi
// 00646991  8b7c2408             mov edi, dword ptr [esp + 8]
// 00646995  85ff                 test edi, edi
// 00646997  0f8416020000         je 0x646bb3
// 0064699d  56                   push esi
// 0064699e  8b742410             mov esi, dword ptr [esp + 0x10]
// 006469a2  85f6                 test esi, esi
// 006469a4  0f8408020000         je 0x646bb2
// 006469aa  53                   push ebx
// 006469ab  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 006469af  55                   push ebp
// 006469b0  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 006469b4  85ed                 test ebp, ebp
// 006469b6  7404                 je 0x6469bc
// 006469b8  85db                 test ebx, ebx
// 006469ba  750e                 jne 0x6469ca
// 006469bc  68f461b800           push 0xb861f4
// 006469c1  57                   push edi
// 006469c2  e8e9770000           call 0x64e1b0
// 006469c7  83c408               add esp, 8
// 006469ca  3baf64020000         cmp ebp, dword ptr [edi + 0x264]
// 006469d0  7708                 ja 0x6469da
// 006469d2  3b9f68020000         cmp ebx, dword ptr [edi + 0x268]
// 006469d8  760e                 jbe 0x6469e8
// 006469da  68cc61b800           push 0xb861cc
// 006469df  57                   push edi
// 006469e0  e8cb770000           call 0x64e1b0
// 006469e5  83c408               add esp, 8
// 006469e8  81fdffffff7f         cmp ebp, 0x7fffffff
// 006469ee  7708                 ja 0x6469f8
// 006469f0  81fbffffff7f         cmp ebx, 0x7fffffff
// 006469f6  760e                 jbe 0x646a06
// 006469f8  68b061b800           push 0xb861b0
// 006469fd  57                   push edi
// 006469fe  e8ad770000           call 0x64e1b0
// 00646a03  83c408               add esp, 8
// 00646a06  81fd7effff1f         cmp ebp, 0x1fffff7e
// 00646a0c  760e                 jbe 0x646a1c
// 00646a0e  688061b800           push 0xb86180
// 00646a13  57                   push edi
// 00646a14  e847780000           call 0x64e260
// 00646a19  83c408               add esp, 8
// 00646a1c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00646a20  83f801               cmp eax, 1
// 00646a23  7422                 je 0x646a47
// 00646a25  83f802               cmp eax, 2
// 00646a28  741d                 je 0x646a47
// 00646a2a  83f804               cmp eax, 4
// 00646a2d  7418                 je 0x646a47
// 00646a2f  83f808               cmp eax, 8
// 00646a32  7413                 je 0x646a47
// 00646a34  83f810               cmp eax, 0x10
// 00646a37  740e                 je 0x646a47
// 00646a39  686461b800           push 0xb86164
// 00646a3e  57                   push edi
// 00646a3f  e86c770000           call 0x64e1b0
// 00646a44  83c408               add esp, 8
// 00646a47  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00646a4b  85db                 test ebx, ebx
// 00646a4d  7c0f                 jl 0x646a5e
// 00646a4f  83fb01               cmp ebx, 1
// 00646a52  740a                 je 0x646a5e
// 00646a54  83fb05               cmp ebx, 5
// 00646a57  7405                 je 0x646a5e
// 00646a59  83fb06               cmp ebx, 6
// 00646a5c  7e0e                 jle 0x646a6c
// 00646a5e  684861b800           push 0xb86148
// 00646a63  57                   push edi
// 00646a64  e847770000           call 0x64e1b0
// 00646a69  83c408               add esp, 8
// 00646a6c  83fb03               cmp ebx, 3
// 00646a6f  7509                 jne 0x646a7a
// 00646a71  837c242408           cmp dword ptr [esp + 0x24], 8
// 00646a76  7f18                 jg 0x646a90
// 00646a78  eb24                 jmp 0x646a9e
// 00646a7a  83fb02               cmp ebx, 2
// 00646a7d  740a                 je 0x646a89
// 00646a7f  83fb04               cmp ebx, 4
// 00646a82  7405                 je 0x646a89
// 00646a84  83fb06               cmp ebx, 6
// 00646a87  7515                 jne 0x646a9e
// 00646a89  837c242408           cmp dword ptr [esp + 0x24], 8
// 00646a8e  7d0e                 jge 0x646a9e
// 00646a90  681461b800           push 0xb86114
// 00646a95  57                   push edi
// 00646a96  e815770000           call 0x64e1b0
// 00646a9b  83c408               add esp, 8
// 00646a9e  837c242c02           cmp dword ptr [esp + 0x2c], 2
// 00646aa3  7c0e                 jl 0x646ab3
// 00646aa5  68f060b800           push 0xb860f0
// 00646aaa  57                   push edi
// 00646aab  e800770000           call 0x64e1b0
// 00646ab0  83c408               add esp, 8
// 00646ab3  837c243000           cmp dword ptr [esp + 0x30], 0
// 00646ab8  740e                 je 0x646ac8
// 00646aba  68cc60b800           push 0xb860cc
// 00646abf  57                   push edi
// 00646ac0  e8eb760000           call 0x64e1b0
// 00646ac5  83c408               add esp, 8
// 00646ac8  bd00100000           mov ebp, 0x1000
// 00646acd  856f68               test dword ptr [edi + 0x68], ebp
// 00646ad0  7417                 je 0x646ae9
// 00646ad2  83bf3002000000       cmp dword ptr [edi + 0x230], 0
// 00646ad9  740e                 je 0x646ae9
// 00646adb  68105eb800           push 0xb85e10
// 00646ae0  57                   push edi
// 00646ae1  e87a770000           call 0x64e260
// 00646ae6  83c408               add esp, 8
// 00646ae9  8b442434             mov eax, dword ptr [esp + 0x34]
// 00646aed  85c0                 test eax, eax
// 00646aef  743e                 je 0x646b2f
// 00646af1  f6873002000004       test byte ptr [edi + 0x230], 4
// 00646af8  7414                 je 0x646b0e
// 00646afa  83f840               cmp eax, 0x40
// 00646afd  750f                 jne 0x646b0e
// 00646aff  856f68               test dword ptr [edi + 0x68], ebp
// 00646b02  750a                 jne 0x646b0e
// 00646b04  83fb02               cmp ebx, 2
// 00646b07  7413                 je 0x646b1c
// 00646b09  83fb06               cmp ebx, 6
// 00646b0c  740e                 je 0x646b1c
// 00646b0e  68ac60b800           push 0xb860ac
// 00646b13  57                   push edi
// 00646b14  e897760000           call 0x64e1b0
// 00646b19  83c408               add esp, 8
// 00646b1c  856f68               test dword ptr [edi + 0x68], ebp
// 00646b1f  740e                 je 0x646b2f
// 00646b21  688c60b800           push 0xb8608c
// 00646b26  57                   push edi
// 00646b27  e834770000           call 0x64e260
// 00646b2c  83c408               add esp, 8
// 00646b2f  8b442420             mov eax, dword ptr [esp + 0x20]
// 00646b33  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00646b37  8a542424             mov dl, byte ptr [esp + 0x24]
// 00646b3b  894604               mov dword ptr [esi + 4], eax
// 00646b3e  8a442430             mov al, byte ptr [esp + 0x30]
// 00646b42  88461a               mov byte ptr [esi + 0x1a], al
// 00646b45  8a442434             mov al, byte ptr [esp + 0x34]
// 00646b49  88461b               mov byte ptr [esi + 0x1b], al
// 00646b4c  8a44242c             mov al, byte ptr [esp + 0x2c]
// 00646b50  890e                 mov dword ptr [esi], ecx
// 00646b52  885618               mov byte ptr [esi + 0x18], dl
// 00646b55  885e19               mov byte ptr [esi + 0x19], bl
// 00646b58  88461c               mov byte ptr [esi + 0x1c], al
// 00646b5b  80fb03               cmp bl, 3
// 00646b5e  740b                 je 0x646b6b
// 00646b60  f6c302               test bl, 2
// 00646b63  7406                 je 0x646b6b
// 00646b65  c6461d03             mov byte ptr [esi + 0x1d], 3
// 00646b69  eb04                 jmp 0x646b6f
// 00646b6b  c6461d01             mov byte ptr [esi + 0x1d], 1
// 00646b6f  5d                   pop ebp
// 00646b70  f6c304               test bl, 4
// 00646b73  5b                   pop ebx
// 00646b74  7403                 je 0x646b79
// 00646b76  fe461d               inc byte ptr [esi + 0x1d]
// 00646b79  8a461d               mov al, byte ptr [esi + 0x1d]
// 00646b7c  f6ea                 imul dl
// 00646b7e  88461e               mov byte ptr [esi + 0x1e], al
// 00646b81  81f97effff1f         cmp ecx, 0x1fffff7e
// 00646b87  760a                 jbe 0x646b93
// 00646b89  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00646b90  5e                   pop esi
// 00646b91  5f                   pop edi
// 00646b92  c3                   ret 
// 00646b93  3c08                 cmp al, 8
// 00646b95  0fb6c0               movzx eax, al
// 00646b98  720c                 jb 0x646ba6
// 00646b9a  c1e803               shr eax, 3
// 00646b9d  0fafc1               imul eax, ecx
// 00646ba0  89460c               mov dword ptr [esi + 0xc], eax
// 00646ba3  5e                   pop esi
// 00646ba4  5f                   pop edi
// 00646ba5  c3                   ret 
// 00646ba6  0fafc1               imul eax, ecx
// 00646ba9  83c007               add eax, 7
// 00646bac  c1e803               shr eax, 3
// 00646baf  89460c               mov dword ptr [esi + 0xc], eax
// 00646bb2  5e                   pop esi
// 00646bb3  5f                   pop edi
// 00646bb4  c3                   ret 
// library libpng-1.2.10/pngset.c (function _png_set_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngset.c
