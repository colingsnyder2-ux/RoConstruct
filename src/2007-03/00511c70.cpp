// from server: 100% by auto
// roc 2007-03 00511c70  unit: seg_00510000  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00511c70
//
// 00511c70  8b442404             mov eax, dword ptr [esp + 4]
// 00511c74  8a4808               mov cl, byte ptr [eax + 8]
// 00511c77  f6c102               test cl, 2
// 00511c7a  0f84b8000000         je 0x511d38
// 00511c80  8b10                 mov edx, dword ptr [eax]
// 00511c82  8a4009               mov al, byte ptr [eax + 9]
// 00511c85  3c08                 cmp al, 8
// 00511c87  57                   push edi
// 00511c88  753a                 jne 0x511cc4
// 00511c8a  80f902               cmp cl, 2
// 00511c8d  7507                 jne 0x511c96
// 00511c8f  bf03000000           mov edi, 3
// 00511c94  eb0e                 jmp 0x511ca4
// 00511c96  80f906               cmp cl, 6
// 00511c99  0f8598000000         jne 0x511d37
// 00511c9f  bf04000000           mov edi, 4
// 00511ca4  85d2                 test edx, edx
// 00511ca6  0f868b000000         jbe 0x511d37
// 00511cac  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00511cb0  83c002               add eax, 2
// 00511cb3  8a48ff               mov cl, byte ptr [eax - 1]
// 00511cb6  0048fe               add byte ptr [eax - 2], cl
// 00511cb9  0008                 add byte ptr [eax], cl
// 00511cbb  03c7                 add eax, edi
// 00511cbd  83ea01               sub edx, 1
// 00511cc0  75f1                 jne 0x511cb3
// 00511cc2  5f                   pop edi
// 00511cc3  c3                   ret 
// 00511cc4  3c10                 cmp al, 0x10
// 00511cc6  756f                 jne 0x511d37
// 00511cc8  80f902               cmp cl, 2
// 00511ccb  7507                 jne 0x511cd4
// 00511ccd  bf06000000           mov edi, 6
// 00511cd2  eb0a                 jmp 0x511cde
// 00511cd4  80f906               cmp cl, 6
// 00511cd7  755e                 jne 0x511d37
// 00511cd9  bf08000000           mov edi, 8
// 00511cde  85d2                 test edx, edx
// 00511ce0  7655                 jbe 0x511d37
// 00511ce2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00511ce6  53                   push ebx
// 00511ce7  56                   push esi
// 00511ce8  83c001               add eax, 1
// 00511ceb  8bf2                 mov esi, edx
// 00511ced  8d4900               lea ecx, [ecx]
// 00511cf0  33db                 xor ebx, ebx
// 00511cf2  8a7803               mov bh, byte ptr [eax + 3]
// 00511cf5  33c9                 xor ecx, ecx
// 00511cf7  8a6801               mov ch, byte ptr [eax + 1]
// 00511cfa  33d2                 xor edx, edx
// 00511cfc  8a70ff               mov dh, byte ptr [eax - 1]
// 00511cff  8a5804               mov bl, byte ptr [eax + 4]
// 00511d02  8a4802               mov cl, byte ptr [eax + 2]
// 00511d05  8a10                 mov dl, byte ptr [eax]
// 00511d07  03d9                 add ebx, ecx
// 00511d09  81e3ffff0000         and ebx, 0xffff
// 00511d0f  03d1                 add edx, ecx
// 00511d11  81e2ffff0000         and edx, 0xffff
// 00511d17  8bcb                 mov ecx, ebx
// 00511d19  8bda                 mov ebx, edx
// 00511d1b  8810                 mov byte ptr [eax], dl
// 00511d1d  8bd1                 mov edx, ecx
// 00511d1f  c1eb08               shr ebx, 8
// 00511d22  c1ea08               shr edx, 8
// 00511d25  8858ff               mov byte ptr [eax - 1], bl
// 00511d28  885003               mov byte ptr [eax + 3], dl
// 00511d2b  884804               mov byte ptr [eax + 4], cl
// 00511d2e  03c7                 add eax, edi
// 00511d30  83ee01               sub esi, 1
// 00511d33  75bb                 jne 0x511cf0
// 00511d35  5e                   pop esi
// 00511d36  5b                   pop ebx
// 00511d37  5f                   pop edi
// 00511d38  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_read_intrapixel)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
