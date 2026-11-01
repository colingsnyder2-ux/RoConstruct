// from server: 100% by auto
// roc 2007-03 0050e820  unit: seg_00500000  size: 318 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e820
//
// 0050e820  8b542404             mov edx, dword ptr [esp + 4]
// 0050e824  8a4209               mov al, byte ptr [edx + 9]
// 0050e827  3c08                 cmp al, 8
// 0050e829  0f832e010000         jae 0x50e95d
// 0050e82f  53                   push ebx
// 0050e830  55                   push ebp
// 0050e831  0fb6c0               movzx eax, al
// 0050e834  83e801               sub eax, 1
// 0050e837  56                   push esi
// 0050e838  57                   push edi
// 0050e839  8b3a                 mov edi, dword ptr [edx]
// 0050e83b  0f84b4000000         je 0x50e8f5
// 0050e841  83e801               sub eax, 1
// 0050e844  7466                 je 0x50e8ac
// 0050e846  83e802               sub eax, 2
// 0050e849  0f85ef000000         jne 0x50e93e
// 0050e84f  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050e853  8d4fff               lea ecx, [edi - 1]
// 0050e856  8bf1                 mov esi, ecx
// 0050e858  d1ee                 shr esi, 1
// 0050e85a  03f0                 add esi, eax
// 0050e85c  8d6c07ff             lea ebp, [edi + eax - 1]
// 0050e860  83e101               and ecx, 1
// 0050e863  b801000000           mov eax, 1
// 0050e868  2bc1                 sub eax, ecx
// 0050e86a  03c0                 add eax, eax
// 0050e86c  03c0                 add eax, eax
// 0050e86e  85ff                 test edi, edi
// 0050e870  0f86c8000000         jbe 0x50e93e
// 0050e876  897c2414             mov dword ptr [esp + 0x14], edi
// 0050e87a  8d9b00000000         lea ebx, [ebx]
// 0050e880  8a1e                 mov bl, byte ptr [esi]
// 0050e882  8ac8                 mov cl, al
// 0050e884  d2eb                 shr bl, cl
// 0050e886  80e30f               and bl, 0xf
// 0050e889  83f804               cmp eax, 4
// 0050e88c  885d00               mov byte ptr [ebp], bl
// 0050e88f  7507                 jne 0x50e898
// 0050e891  33c0                 xor eax, eax
// 0050e893  83ee01               sub esi, 1
// 0050e896  eb05                 jmp 0x50e89d
// 0050e898  b804000000           mov eax, 4
// 0050e89d  83ed01               sub ebp, 1
// 0050e8a0  836c241401           sub dword ptr [esp + 0x14], 1
// 0050e8a5  75d9                 jne 0x50e880
// 0050e8a7  e992000000           jmp 0x50e93e
// 0050e8ac  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050e8b0  8d4fff               lea ecx, [edi - 1]
// 0050e8b3  8bf1                 mov esi, ecx
// 0050e8b5  c1ee02               shr esi, 2
// 0050e8b8  03f0                 add esi, eax
// 0050e8ba  8d6c07ff             lea ebp, [edi + eax - 1]
// 0050e8be  83e103               and ecx, 3
// 0050e8c1  b803000000           mov eax, 3
// 0050e8c6  2bc1                 sub eax, ecx
// 0050e8c8  03c0                 add eax, eax
// 0050e8ca  85ff                 test edi, edi
// 0050e8cc  7670                 jbe 0x50e93e
// 0050e8ce  8bd7                 mov edx, edi
// 0050e8d0  8a1e                 mov bl, byte ptr [esi]
// 0050e8d2  8ac8                 mov cl, al
// 0050e8d4  d2eb                 shr bl, cl
// 0050e8d6  80e303               and bl, 3
// 0050e8d9  83f806               cmp eax, 6
// 0050e8dc  885d00               mov byte ptr [ebp], bl
// 0050e8df  7507                 jne 0x50e8e8
// 0050e8e1  33c0                 xor eax, eax
// 0050e8e3  83ee01               sub esi, 1
// 0050e8e6  eb03                 jmp 0x50e8eb
// 0050e8e8  83c002               add eax, 2
// 0050e8eb  83ed01               sub ebp, 1
// 0050e8ee  83ea01               sub edx, 1
// 0050e8f1  75dd                 jne 0x50e8d0
// 0050e8f3  eb45                 jmp 0x50e93a
// 0050e8f5  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050e8f9  8d4fff               lea ecx, [edi - 1]
// 0050e8fc  8bf1                 mov esi, ecx
// 0050e8fe  c1ee03               shr esi, 3
// 0050e901  03f0                 add esi, eax
// 0050e903  8d6c07ff             lea ebp, [edi + eax - 1]
// 0050e907  83e107               and ecx, 7
// 0050e90a  b807000000           mov eax, 7
// 0050e90f  2bc1                 sub eax, ecx
// 0050e911  85ff                 test edi, edi
// 0050e913  7629                 jbe 0x50e93e
// 0050e915  8bd7                 mov edx, edi
// 0050e917  8a1e                 mov bl, byte ptr [esi]
// 0050e919  8ac8                 mov cl, al
// 0050e91b  d2eb                 shr bl, cl
// 0050e91d  80e301               and bl, 1
// 0050e920  83f807               cmp eax, 7
// 0050e923  885d00               mov byte ptr [ebp], bl
// 0050e926  7507                 jne 0x50e92f
// 0050e928  33c0                 xor eax, eax
// 0050e92a  83ee01               sub esi, 1
// 0050e92d  eb03                 jmp 0x50e932
// 0050e92f  83c001               add eax, 1
// 0050e932  83ed01               sub ebp, 1
// 0050e935  83ea01               sub edx, 1
// 0050e938  75dd                 jne 0x50e917
// 0050e93a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0050e93e  8a420a               mov al, byte ptr [edx + 0xa]
// 0050e941  8ac8                 mov cl, al
// 0050e943  02c9                 add cl, cl
// 0050e945  02c9                 add cl, cl
// 0050e947  0fb6c0               movzx eax, al
// 0050e94a  02c9                 add cl, cl
// 0050e94c  0fafc7               imul eax, edi
// 0050e94f  5f                   pop edi
// 0050e950  5e                   pop esi
// 0050e951  5d                   pop ebp
// 0050e952  c6420908             mov byte ptr [edx + 9], 8
// 0050e956  884a0b               mov byte ptr [edx + 0xb], cl
// 0050e959  894204               mov dword ptr [edx + 4], eax
// 0050e95c  5b                   pop ebx
// 0050e95d  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_unpack)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
