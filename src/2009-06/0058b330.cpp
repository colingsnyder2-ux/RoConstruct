// from server: 100% by auto
// roc 2009-06 0058b330  unit: seg_00580000  size: 678 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058b330
//
// 0058b330  83ec28               sub esp, 0x28
// 0058b333  837c243c04           cmp dword ptr [esp + 0x3c], 4
// 0058b338  56                   push esi
// 0058b339  8b742430             mov esi, dword ptr [esp + 0x30]
// 0058b33d  c644241870           mov byte ptr [esp + 0x18], 0x70
// 0058b342  c644241943           mov byte ptr [esp + 0x19], 0x43
// 0058b347  c644241a41           mov byte ptr [esp + 0x1a], 0x41
// 0058b34c  c644241b4c           mov byte ptr [esp + 0x1b], 0x4c
// 0058b351  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0058b356  7c0e                 jl 0x58b366
// 0058b358  6810ed8c00           push 0x8ced10
// 0058b35d  56                   push esi
// 0058b35e  e8ad2e0000           call 0x58e210
// 0058b363  83c408               add esp, 8
// 0058b366  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0058b36a  53                   push ebx
// 0058b36b  55                   push ebp
// 0058b36c  57                   push edi
// 0058b36d  8d442410             lea eax, [esp + 0x10]
// 0058b371  50                   push eax
// 0058b372  51                   push ecx
// 0058b373  56                   push esi
// 0058b374  e8a7fbffff           call 0x58af20
// 0058b379  8be8                 mov ebp, eax
// 0058b37b  8b442460             mov eax, dword ptr [esp + 0x60]
// 0058b37f  83c40c               add esp, 0xc
// 0058b382  45                   inc ebp
// 0058b383  896c2418             mov dword ptr [esp + 0x18], ebp
// 0058b387  8d4801               lea ecx, [eax + 1]
// 0058b38a  8d9b00000000         lea ebx, [ebx]
// 0058b390  8a10                 mov dl, byte ptr [eax]
// 0058b392  40                   inc eax
// 0058b393  84d2                 test dl, dl
// 0058b395  75f9                 jne 0x58b390
// 0058b397  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 0058b39b  2bc1                 sub eax, ecx
// 0058b39d  33d2                 xor edx, edx
// 0058b39f  85db                 test ebx, ebx
// 0058b3a1  0f95c2               setne dl
// 0058b3a4  8d0c9d00000000       lea ecx, [ebx*4]
// 0058b3ab  51                   push ecx
// 0058b3ac  56                   push esi
// 0058b3ad  03d0                 add edx, eax
// 0058b3af  8bfa                 mov edi, edx
// 0058b3b1  8d442f0a             lea eax, [edi + ebp + 0xa]
// 0058b3b5  897c2424             mov dword ptr [esp + 0x24], edi
// 0058b3b9  89442444             mov dword ptr [esp + 0x44], eax
// 0058b3bd  e88e380000           call 0x58ec50
// 0058b3c2  83c408               add esp, 8
// 0058b3c5  33c9                 xor ecx, ecx
// 0058b3c7  89442450             mov dword ptr [esp + 0x50], eax
// 0058b3cb  85db                 test ebx, ebx
// 0058b3cd  7e50                 jle 0x58b41f
// 0058b3cf  8b542458             mov edx, dword ptr [esp + 0x58]
// 0058b3d3  2bd0                 sub edx, eax
// 0058b3d5  8bf8                 mov edi, eax
// 0058b3d7  89542414             mov dword ptr [esp + 0x14], edx
// 0058b3db  eb07                 jmp 0x58b3e4
// 0058b3dd  8d4900               lea ecx, [ecx]
// 0058b3e0  8b542414             mov edx, dword ptr [esp + 0x14]
// 0058b3e4  8b043a               mov eax, dword ptr [edx + edi]
// 0058b3e7  8d6801               lea ebp, [eax + 1]
// 0058b3ea  8d9b00000000         lea ebx, [ebx]
// 0058b3f0  8a10                 mov dl, byte ptr [eax]
// 0058b3f2  40                   inc eax
// 0058b3f3  84d2                 test dl, dl
// 0058b3f5  75f9                 jne 0x58b3f0
// 0058b3f7  2bc5                 sub eax, ebp
// 0058b3f9  8be8                 mov ebp, eax
// 0058b3fb  33d2                 xor edx, edx
// 0058b3fd  8d43ff               lea eax, [ebx - 1]
// 0058b400  3bc8                 cmp ecx, eax
// 0058b402  0f95c2               setne dl
// 0058b405  41                   inc ecx
// 0058b406  83c704               add edi, 4
// 0058b409  8d042a               lea eax, [edx + ebp]
// 0058b40c  0144243c             add dword ptr [esp + 0x3c], eax
// 0058b410  3bcb                 cmp ecx, ebx
// 0058b412  8947fc               mov dword ptr [edi - 4], eax
// 0058b415  7cc9                 jl 0x58b3e0
// 0058b417  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0058b41b  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0058b41f  85f6                 test esi, esi
// 0058b421  747b                 je 0x58b49e
// 0058b423  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0058b427  8bc8                 mov ecx, eax
// 0058b429  c1e918               shr ecx, 0x18
// 0058b42c  884c241c             mov byte ptr [esp + 0x1c], cl
// 0058b430  8bd0                 mov edx, eax
// 0058b432  8bc8                 mov ecx, eax
// 0058b434  c1ea10               shr edx, 0x10
// 0058b437  8844241f             mov byte ptr [esp + 0x1f], al
// 0058b43b  6a08                 push 8
// 0058b43d  8d442420             lea eax, [esp + 0x20]
// 0058b441  88542421             mov byte ptr [esp + 0x21], dl
// 0058b445  8b542428             mov edx, dword ptr [esp + 0x28]
// 0058b449  50                   push eax
// 0058b44a  c1e908               shr ecx, 8
// 0058b44d  56                   push esi
// 0058b44e  884c242a             mov byte ptr [esp + 0x2a], cl
// 0058b452  8954242c             mov dword ptr [esp + 0x2c], edx
// 0058b456  e88561ffff           call 0x5815e0
// 0058b45b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0058b45f  56                   push esi
// 0058b460  898e1c010000         mov dword ptr [esi + 0x11c], ecx
// 0058b466  e83564ffff           call 0x5818a0
// 0058b46b  6a04                 push 4
// 0058b46d  8d542438             lea edx, [esp + 0x38]
// 0058b471  52                   push edx
// 0058b472  56                   push esi
// 0058b473  e84864ffff           call 0x5818c0
// 0058b478  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0058b47c  83c41c               add esp, 0x1c
// 0058b47f  85c0                 test eax, eax
// 0058b481  741b                 je 0x58b49e
// 0058b483  85ed                 test ebp, ebp
// 0058b485  7617                 jbe 0x58b49e
// 0058b487  55                   push ebp
// 0058b488  50                   push eax
// 0058b489  56                   push esi
// 0058b48a  e85161ffff           call 0x5815e0
// 0058b48f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058b493  55                   push ebp
// 0058b494  50                   push eax
// 0058b495  56                   push esi
// 0058b496  e82564ffff           call 0x5818c0
// 0058b49b  83c418               add esp, 0x18
// 0058b49e  8b442444             mov eax, dword ptr [esp + 0x44]
// 0058b4a2  8bc8                 mov ecx, eax
// 0058b4a4  c1f918               sar ecx, 0x18
// 0058b4a7  884c242c             mov byte ptr [esp + 0x2c], cl
// 0058b4ab  8bd0                 mov edx, eax
// 0058b4ad  c1fa10               sar edx, 0x10
// 0058b4b0  8bc8                 mov ecx, eax
// 0058b4b2  8854242d             mov byte ptr [esp + 0x2d], dl
// 0058b4b6  8844242f             mov byte ptr [esp + 0x2f], al
// 0058b4ba  8b442448             mov eax, dword ptr [esp + 0x48]
// 0058b4be  c1f908               sar ecx, 8
// 0058b4c1  8bd0                 mov edx, eax
// 0058b4c3  c1fa18               sar edx, 0x18
// 0058b4c6  884c242e             mov byte ptr [esp + 0x2e], cl
// 0058b4ca  88542430             mov byte ptr [esp + 0x30], dl
// 0058b4ce  8bc8                 mov ecx, eax
// 0058b4d0  8bd0                 mov edx, eax
// 0058b4d2  c1f910               sar ecx, 0x10
// 0058b4d5  c1fa08               sar edx, 8
// 0058b4d8  88442433             mov byte ptr [esp + 0x33], al
// 0058b4dc  8a44244c             mov al, byte ptr [esp + 0x4c]
// 0058b4e0  884c2431             mov byte ptr [esp + 0x31], cl
// 0058b4e4  88542432             mov byte ptr [esp + 0x32], dl
// 0058b4e8  88442434             mov byte ptr [esp + 0x34], al
// 0058b4ec  885c2435             mov byte ptr [esp + 0x35], bl
// 0058b4f0  85f6                 test esi, esi
// 0058b4f2  743c                 je 0x58b530
// 0058b4f4  6a0a                 push 0xa
// 0058b4f6  8d4c2430             lea ecx, [esp + 0x30]
// 0058b4fa  51                   push ecx
// 0058b4fb  56                   push esi
// 0058b4fc  e8df60ffff           call 0x5815e0
// 0058b501  6a0a                 push 0xa
// 0058b503  8d54243c             lea edx, [esp + 0x3c]
// 0058b507  52                   push edx
// 0058b508  56                   push esi
// 0058b509  e8b263ffff           call 0x5818c0
// 0058b50e  8b6c246c             mov ebp, dword ptr [esp + 0x6c]
// 0058b512  83c418               add esp, 0x18
// 0058b515  85ed                 test ebp, ebp
// 0058b517  7417                 je 0x58b530
// 0058b519  85ff                 test edi, edi
// 0058b51b  7613                 jbe 0x58b530
// 0058b51d  57                   push edi
// 0058b51e  55                   push ebp
// 0058b51f  56                   push esi
// 0058b520  e8bb60ffff           call 0x5815e0
// 0058b525  57                   push edi
// 0058b526  55                   push ebp
// 0058b527  56                   push esi
// 0058b528  e89363ffff           call 0x5818c0
// 0058b52d  83c418               add esp, 0x18
// 0058b530  8b442410             mov eax, dword ptr [esp + 0x10]
// 0058b534  50                   push eax
// 0058b535  56                   push esi
// 0058b536  e875370000           call 0x58ecb0
// 0058b53b  83c408               add esp, 8
// 0058b53e  85db                 test ebx, ebx
// 0058b540  7e45                 jle 0x58b587
// 0058b542  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 0058b546  8b442450             mov eax, dword ptr [esp + 0x50]
// 0058b54a  2bc5                 sub eax, ebp
// 0058b54c  8944243c             mov dword ptr [esp + 0x3c], eax
// 0058b550  895c244c             mov dword ptr [esp + 0x4c], ebx
// 0058b554  8b1c28               mov ebx, dword ptr [eax + ebp]
// 0058b557  8b7d00               mov edi, dword ptr [ebp]
// 0058b55a  85f6                 test esi, esi
// 0058b55c  741f                 je 0x58b57d
// 0058b55e  85ff                 test edi, edi
// 0058b560  741b                 je 0x58b57d
// 0058b562  85db                 test ebx, ebx
// 0058b564  7617                 jbe 0x58b57d
// 0058b566  53                   push ebx
// 0058b567  57                   push edi
// 0058b568  56                   push esi
// 0058b569  e87260ffff           call 0x5815e0
// 0058b56e  53                   push ebx
// 0058b56f  57                   push edi
// 0058b570  56                   push esi
// 0058b571  e84a63ffff           call 0x5818c0
// 0058b576  8b442454             mov eax, dword ptr [esp + 0x54]
// 0058b57a  83c418               add esp, 0x18
// 0058b57d  83c504               add ebp, 4
// 0058b580  836c244c01           sub dword ptr [esp + 0x4c], 1
// 0058b585  75cd                 jne 0x58b554
// 0058b587  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0058b58b  51                   push ecx
// 0058b58c  56                   push esi
// 0058b58d  e81e370000           call 0x58ecb0
// 0058b592  83c408               add esp, 8
// 0058b595  5f                   pop edi
// 0058b596  5d                   pop ebp
// 0058b597  5b                   pop ebx
// 0058b598  85f6                 test esi, esi
// 0058b59a  7435                 je 0x58b5d1
// 0058b59c  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0058b5a2  8bd0                 mov edx, eax
// 0058b5a4  c1ea18               shr edx, 0x18
// 0058b5a7  88542440             mov byte ptr [esp + 0x40], dl
// 0058b5ab  8bc8                 mov ecx, eax
// 0058b5ad  8bd0                 mov edx, eax
// 0058b5af  88442443             mov byte ptr [esp + 0x43], al
// 0058b5b3  6a04                 push 4
// 0058b5b5  8d442444             lea eax, [esp + 0x44]
// 0058b5b9  50                   push eax
// 0058b5ba  c1e910               shr ecx, 0x10
// 0058b5bd  c1ea08               shr edx, 8
// 0058b5c0  56                   push esi
// 0058b5c1  884c244d             mov byte ptr [esp + 0x4d], cl
// 0058b5c5  8854244e             mov byte ptr [esp + 0x4e], dl
// 0058b5c9  e81260ffff           call 0x5815e0
// 0058b5ce  83c40c               add esp, 0xc
// 0058b5d1  5e                   pop esi
// 0058b5d2  83c428               add esp, 0x28
// 0058b5d5  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
