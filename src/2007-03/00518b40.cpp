// from server: 100% by auto
// roc 2007-03 00518b40  unit: seg_00510000  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518b40
//
// 00518b40  8b442404             mov eax, dword ptr [esp + 4]
// 00518b44  8a4808               mov cl, byte ptr [eax + 8]
// 00518b47  f6c102               test cl, 2
// 00518b4a  0f84b8000000         je 0x518c08
// 00518b50  8b10                 mov edx, dword ptr [eax]
// 00518b52  8a4009               mov al, byte ptr [eax + 9]
// 00518b55  3c08                 cmp al, 8
// 00518b57  57                   push edi
// 00518b58  753a                 jne 0x518b94
// 00518b5a  80f902               cmp cl, 2
// 00518b5d  7507                 jne 0x518b66
// 00518b5f  bf03000000           mov edi, 3
// 00518b64  eb0e                 jmp 0x518b74
// 00518b66  80f906               cmp cl, 6
// 00518b69  0f8598000000         jne 0x518c07
// 00518b6f  bf04000000           mov edi, 4
// 00518b74  85d2                 test edx, edx
// 00518b76  0f868b000000         jbe 0x518c07
// 00518b7c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00518b80  83c002               add eax, 2
// 00518b83  8a48ff               mov cl, byte ptr [eax - 1]
// 00518b86  2848fe               sub byte ptr [eax - 2], cl
// 00518b89  2808                 sub byte ptr [eax], cl
// 00518b8b  03c7                 add eax, edi
// 00518b8d  83ea01               sub edx, 1
// 00518b90  75f1                 jne 0x518b83
// 00518b92  5f                   pop edi
// 00518b93  c3                   ret 
// 00518b94  3c10                 cmp al, 0x10
// 00518b96  756f                 jne 0x518c07
// 00518b98  80f902               cmp cl, 2
// 00518b9b  7507                 jne 0x518ba4
// 00518b9d  bf06000000           mov edi, 6
// 00518ba2  eb0a                 jmp 0x518bae
// 00518ba4  80f906               cmp cl, 6
// 00518ba7  755e                 jne 0x518c07
// 00518ba9  bf08000000           mov edi, 8
// 00518bae  85d2                 test edx, edx
// 00518bb0  7655                 jbe 0x518c07
// 00518bb2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00518bb6  53                   push ebx
// 00518bb7  56                   push esi
// 00518bb8  83c001               add eax, 1
// 00518bbb  8bf2                 mov esi, edx
// 00518bbd  8d4900               lea ecx, [ecx]
// 00518bc0  33db                 xor ebx, ebx
// 00518bc2  8a7803               mov bh, byte ptr [eax + 3]
// 00518bc5  33c9                 xor ecx, ecx
// 00518bc7  8a6801               mov ch, byte ptr [eax + 1]
// 00518bca  33d2                 xor edx, edx
// 00518bcc  8a70ff               mov dh, byte ptr [eax - 1]
// 00518bcf  8a5804               mov bl, byte ptr [eax + 4]
// 00518bd2  8a4802               mov cl, byte ptr [eax + 2]
// 00518bd5  8a10                 mov dl, byte ptr [eax]
// 00518bd7  2bd9                 sub ebx, ecx
// 00518bd9  81e3ffff0000         and ebx, 0xffff
// 00518bdf  2bd1                 sub edx, ecx
// 00518be1  81e2ffff0000         and edx, 0xffff
// 00518be7  8bcb                 mov ecx, ebx
// 00518be9  8bda                 mov ebx, edx
// 00518beb  8810                 mov byte ptr [eax], dl
// 00518bed  8bd1                 mov edx, ecx
// 00518bef  c1eb08               shr ebx, 8
// 00518bf2  c1ea08               shr edx, 8
// 00518bf5  8858ff               mov byte ptr [eax - 1], bl
// 00518bf8  885003               mov byte ptr [eax + 3], dl
// 00518bfb  884804               mov byte ptr [eax + 4], cl
// 00518bfe  03c7                 add eax, edi
// 00518c00  83ee01               sub esi, 1
// 00518c03  75bb                 jne 0x518bc0
// 00518c05  5e                   pop esi
// 00518c06  5b                   pop ebx
// 00518c07  5f                   pop edi
// 00518c08  c3                   ret 
// library libpng-1.2.7/pngwtran.c (function _png_do_write_intrapixel)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwtran.c
