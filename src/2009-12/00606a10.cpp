// from server: 100% by auto
// roc 2009-12 00606a10  unit: seg_00600000  size: 381 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00606a10
//
// 00606a10  55                   push ebp
// 00606a11  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00606a15  8a4d09               mov cl, byte ptr [ebp + 9]
// 00606a18  56                   push esi
// 00606a19  8b7500               mov esi, dword ptr [ebp]
// 00606a1c  80f908               cmp cl, 8
// 00606a1f  0f8265010000         jb 0x606b8a
// 00606a25  8a4508               mov al, byte ptr [ebp + 8]
// 00606a28  b202                 mov dl, 2
// 00606a2a  84c2                 test dl, al
// 00606a2c  0f8558010000         jne 0x606b8a
// 00606a32  53                   push ebx
// 00606a33  57                   push edi
// 00606a34  84c0                 test al, al
// 00606a36  0f8589000000         jne 0x606ac5
// 00606a3c  80f908               cmp cl, 8
// 00606a3f  7532                 jne 0x606a73
// 00606a41  8b442418             mov eax, dword ptr [esp + 0x18]
// 00606a45  8d4c06ff             lea ecx, [esi + eax - 1]
// 00606a49  8d0471               lea eax, [ecx + esi*2]
// 00606a4c  85f6                 test esi, esi
// 00606a4e  0f8604010000         jbe 0x606b58
// 00606a54  8bfe                 mov edi, esi
// 00606a56  0fb619               movzx ebx, byte ptr [ecx]
// 00606a59  8818                 mov byte ptr [eax], bl
// 00606a5b  0fb619               movzx ebx, byte ptr [ecx]
// 00606a5e  48                   dec eax
// 00606a5f  8818                 mov byte ptr [eax], bl
// 00606a61  0fb619               movzx ebx, byte ptr [ecx]
// 00606a64  48                   dec eax
// 00606a65  8818                 mov byte ptr [eax], bl
// 00606a67  48                   dec eax
// 00606a68  49                   dec ecx
// 00606a69  83ef01               sub edi, 1
// 00606a6c  75e8                 jne 0x606a56
// 00606a6e  e9e5000000           jmp 0x606b58
// 00606a73  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00606a77  8d4c71ff             lea ecx, [ecx + esi*2 - 1]
// 00606a7b  8d04b1               lea eax, [ecx + esi*4]
// 00606a7e  85f6                 test esi, esi
// 00606a80  0f86d2000000         jbe 0x606b58
// 00606a86  8bfe                 mov edi, esi
// 00606a88  eb06                 jmp 0x606a90
// 00606a8a  8d9b00000000         lea ebx, [ebx]
// 00606a90  0fb619               movzx ebx, byte ptr [ecx]
// 00606a93  8818                 mov byte ptr [eax], bl
// 00606a95  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606a99  8858ff               mov byte ptr [eax - 1], bl
// 00606a9c  0fb619               movzx ebx, byte ptr [ecx]
// 00606a9f  48                   dec eax
// 00606aa0  8858ff               mov byte ptr [eax - 1], bl
// 00606aa3  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606aa7  48                   dec eax
// 00606aa8  48                   dec eax
// 00606aa9  8818                 mov byte ptr [eax], bl
// 00606aab  0fb619               movzx ebx, byte ptr [ecx]
// 00606aae  48                   dec eax
// 00606aaf  8818                 mov byte ptr [eax], bl
// 00606ab1  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606ab5  49                   dec ecx
// 00606ab6  48                   dec eax
// 00606ab7  8818                 mov byte ptr [eax], bl
// 00606ab9  48                   dec eax
// 00606aba  49                   dec ecx
// 00606abb  83ef01               sub edi, 1
// 00606abe  75d0                 jne 0x606a90
// 00606ac0  e993000000           jmp 0x606b58
// 00606ac5  3c04                 cmp al, 4
// 00606ac7  0f858b000000         jne 0x606b58
// 00606acd  80f908               cmp cl, 8
// 00606ad0  7533                 jne 0x606b05
// 00606ad2  8b442418             mov eax, dword ptr [esp + 0x18]
// 00606ad6  8d4c70ff             lea ecx, [eax + esi*2 - 1]
// 00606ada  8d0471               lea eax, [ecx + esi*2]
// 00606add  85f6                 test esi, esi
// 00606adf  7677                 jbe 0x606b58
// 00606ae1  8bfe                 mov edi, esi
// 00606ae3  0fb619               movzx ebx, byte ptr [ecx]
// 00606ae6  8818                 mov byte ptr [eax], bl
// 00606ae8  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606aec  49                   dec ecx
// 00606aed  48                   dec eax
// 00606aee  8818                 mov byte ptr [eax], bl
// 00606af0  0fb619               movzx ebx, byte ptr [ecx]
// 00606af3  48                   dec eax
// 00606af4  8818                 mov byte ptr [eax], bl
// 00606af6  0fb619               movzx ebx, byte ptr [ecx]
// 00606af9  48                   dec eax
// 00606afa  8818                 mov byte ptr [eax], bl
// 00606afc  48                   dec eax
// 00606afd  49                   dec ecx
// 00606afe  83ef01               sub edi, 1
// 00606b01  75e0                 jne 0x606ae3
// 00606b03  eb53                 jmp 0x606b58
// 00606b05  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00606b09  8d4cb1ff             lea ecx, [ecx + esi*4 - 1]
// 00606b0d  8d04b1               lea eax, [ecx + esi*4]
// 00606b10  85f6                 test esi, esi
// 00606b12  7644                 jbe 0x606b58
// 00606b14  8bfe                 mov edi, esi
// 00606b16  0fb619               movzx ebx, byte ptr [ecx]
// 00606b19  8818                 mov byte ptr [eax], bl
// 00606b1b  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606b1f  8858ff               mov byte ptr [eax - 1], bl
// 00606b22  48                   dec eax
// 00606b23  49                   dec ecx
// 00606b24  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606b28  8858ff               mov byte ptr [eax - 1], bl
// 00606b2b  0fb659fe             movzx ebx, byte ptr [ecx - 2]
// 00606b2f  49                   dec ecx
// 00606b30  48                   dec eax
// 00606b31  8858ff               mov byte ptr [eax - 1], bl
// 00606b34  0fb619               movzx ebx, byte ptr [ecx]
// 00606b37  48                   dec eax
// 00606b38  8858ff               mov byte ptr [eax - 1], bl
// 00606b3b  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606b3f  48                   dec eax
// 00606b40  48                   dec eax
// 00606b41  8818                 mov byte ptr [eax], bl
// 00606b43  0fb619               movzx ebx, byte ptr [ecx]
// 00606b46  48                   dec eax
// 00606b47  8818                 mov byte ptr [eax], bl
// 00606b49  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 00606b4d  49                   dec ecx
// 00606b4e  48                   dec eax
// 00606b4f  8818                 mov byte ptr [eax], bl
// 00606b51  48                   dec eax
// 00606b52  49                   dec ecx
// 00606b53  83ef01               sub edi, 1
// 00606b56  75be                 jne 0x606b16
// 00606b58  00550a               add byte ptr [ebp + 0xa], dl
// 00606b5b  8a4509               mov al, byte ptr [ebp + 9]
// 00606b5e  8a4d0a               mov cl, byte ptr [ebp + 0xa]
// 00606b61  085508               or byte ptr [ebp + 8], dl
// 00606b64  f6e9                 imul cl
// 00606b66  5f                   pop edi
// 00606b67  88450b               mov byte ptr [ebp + 0xb], al
// 00606b6a  3c08                 cmp al, 8
// 00606b6c  5b                   pop ebx
// 00606b6d  0fb6c0               movzx eax, al
// 00606b70  720c                 jb 0x606b7e
// 00606b72  c1e803               shr eax, 3
// 00606b75  0fafc6               imul eax, esi
// 00606b78  5e                   pop esi
// 00606b79  894504               mov dword ptr [ebp + 4], eax
// 00606b7c  5d                   pop ebp
// 00606b7d  c3                   ret 
// 00606b7e  0fafc6               imul eax, esi
// 00606b81  83c007               add eax, 7
// 00606b84  c1e803               shr eax, 3
// 00606b87  894504               mov dword ptr [ebp + 4], eax
// 00606b8a  5e                   pop esi
// 00606b8b  5d                   pop ebp
// 00606b8c  c3                   ret 
// library libpng-1.2.6/pngrtran.c (function _png_do_gray_to_rgb)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngrtran.c
