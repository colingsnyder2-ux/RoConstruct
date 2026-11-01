// from server: 100% by auto
// roc 2007-03 0050e470  unit: seg_00500000  size: 230 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e470
//
// 0050e470  8b442404             mov eax, dword ptr [esp + 4]
// 0050e474  8a5008               mov dl, byte ptr [eax + 8]
// 0050e477  f6c202               test dl, 2
// 0050e47a  0f84d5000000         je 0x50e555
// 0050e480  8b08                 mov ecx, dword ptr [eax]
// 0050e482  8a4009               mov al, byte ptr [eax + 9]
// 0050e485  3c08                 cmp al, 8
// 0050e487  56                   push esi
// 0050e488  755a                 jne 0x50e4e4
// 0050e48a  80fa02               cmp dl, 2
// 0050e48d  7525                 jne 0x50e4b4
// 0050e48f  85c9                 test ecx, ecx
// 0050e491  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0050e495  0f86b9000000         jbe 0x50e554
// 0050e49b  8bf1                 mov esi, ecx
// 0050e49d  8d4900               lea ecx, [ecx]
// 0050e4a0  8a08                 mov cl, byte ptr [eax]
// 0050e4a2  8a5002               mov dl, byte ptr [eax + 2]
// 0050e4a5  8810                 mov byte ptr [eax], dl
// 0050e4a7  884802               mov byte ptr [eax + 2], cl
// 0050e4aa  83c003               add eax, 3
// 0050e4ad  83ee01               sub esi, 1
// 0050e4b0  75ee                 jne 0x50e4a0
// 0050e4b2  5e                   pop esi
// 0050e4b3  c3                   ret 
// 0050e4b4  80fa06               cmp dl, 6
// 0050e4b7  0f8597000000         jne 0x50e554
// 0050e4bd  85c9                 test ecx, ecx
// 0050e4bf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0050e4c3  0f868b000000         jbe 0x50e554
// 0050e4c9  8bf1                 mov esi, ecx
// 0050e4cb  eb03                 jmp 0x50e4d0
// 0050e4cd  8d4900               lea ecx, [ecx]
// 0050e4d0  8a08                 mov cl, byte ptr [eax]
// 0050e4d2  8a5002               mov dl, byte ptr [eax + 2]
// 0050e4d5  8810                 mov byte ptr [eax], dl
// 0050e4d7  884802               mov byte ptr [eax + 2], cl
// 0050e4da  83c004               add eax, 4
// 0050e4dd  83ee01               sub esi, 1
// 0050e4e0  75ee                 jne 0x50e4d0
// 0050e4e2  5e                   pop esi
// 0050e4e3  c3                   ret 
// 0050e4e4  3c10                 cmp al, 0x10
// 0050e4e6  756c                 jne 0x50e554
// 0050e4e8  80fa02               cmp dl, 2
// 0050e4eb  7535                 jne 0x50e522
// 0050e4ed  85c9                 test ecx, ecx
// 0050e4ef  7663                 jbe 0x50e554
// 0050e4f1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0050e4f5  83c001               add eax, 1
// 0050e4f8  8bf1                 mov esi, ecx
// 0050e4fa  8d9b00000000         lea ebx, [ebx]
// 0050e500  0fb65003             movzx edx, byte ptr [eax + 3]
// 0050e504  8a48ff               mov cl, byte ptr [eax - 1]
// 0050e507  8850ff               mov byte ptr [eax - 1], dl
// 0050e50a  0fb65004             movzx edx, byte ptr [eax + 4]
// 0050e50e  884803               mov byte ptr [eax + 3], cl
// 0050e511  8a08                 mov cl, byte ptr [eax]
// 0050e513  8810                 mov byte ptr [eax], dl
// 0050e515  884804               mov byte ptr [eax + 4], cl
// 0050e518  83c006               add eax, 6
// 0050e51b  83ee01               sub esi, 1
// 0050e51e  75e0                 jne 0x50e500
// 0050e520  5e                   pop esi
// 0050e521  c3                   ret 
// 0050e522  80fa06               cmp dl, 6
// 0050e525  752d                 jne 0x50e554
// 0050e527  85c9                 test ecx, ecx
// 0050e529  7629                 jbe 0x50e554
// 0050e52b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0050e52f  83c001               add eax, 1
// 0050e532  8bf1                 mov esi, ecx
// 0050e534  0fb65003             movzx edx, byte ptr [eax + 3]
// 0050e538  8a48ff               mov cl, byte ptr [eax - 1]
// 0050e53b  8850ff               mov byte ptr [eax - 1], dl
// 0050e53e  0fb65004             movzx edx, byte ptr [eax + 4]
// 0050e542  884803               mov byte ptr [eax + 3], cl
// 0050e545  8a08                 mov cl, byte ptr [eax]
// 0050e547  8810                 mov byte ptr [eax], dl
// 0050e549  884804               mov byte ptr [eax + 4], cl
// 0050e54c  83c008               add eax, 8
// 0050e54f  83ee01               sub esi, 1
// 0050e552  75e0                 jne 0x50e534
// 0050e554  5e                   pop esi
// 0050e555  c3                   ret 
// library libpng-1.2.7/pngtrans.c (function _png_do_bgr)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngtrans.c
