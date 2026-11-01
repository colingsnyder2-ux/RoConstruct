// from server: 100% by auto
// roc 2007-03 005fd190  unit: seg_005f0000  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd190
//
// 005fd190  53                   push ebx
// 005fd191  55                   push ebp
// 005fd192  56                   push esi
// 005fd193  8b742418             mov esi, dword ptr [esp + 0x18]
// 005fd197  57                   push edi
// 005fd198  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005fd19c  8b4720               mov eax, dword ptr [edi + 0x20]
// 005fd19f  3b442418             cmp eax, dword ptr [esp + 0x18]
// 005fd1a3  7406                 je 0x5fd1ab
// 005fd1a5  837e0c00             cmp dword ptr [esi + 0xc], 0
// 005fd1a9  7402                 je 0x5fd1ad
// 005fd1ab  33c0                 xor eax, eax
// 005fd1ad  e8befcffff           call 0x5fce70
// 005fd1b2  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd1b6  8b473c               mov eax, dword ptr [edi + 0x3c]
// 005fd1b9  89442414             mov dword ptr [esp + 0x14], eax
// 005fd1bd  7519                 jne 0x5fd1d8
// 005fd1bf  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fd1c2  8b06                 mov eax, dword ptr [esi]
// 005fd1c4  51                   push ecx
// 005fd1c5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fd1c8  6a04                 push 4
// 005fd1ca  8d54241c             lea edx, [esp + 0x1c]
// 005fd1ce  52                   push edx
// 005fd1cf  50                   push eax
// 005fd1d0  ffd1                 call ecx
// 005fd1d2  83c410               add esp, 0x10
// 005fd1d5  894610               mov dword ptr [esi + 0x10], eax
// 005fd1d8  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd1dc  8b5740               mov edx, dword ptr [edi + 0x40]
// 005fd1df  89542414             mov dword ptr [esp + 0x14], edx
// 005fd1e3  7519                 jne 0x5fd1fe
// 005fd1e5  8b4608               mov eax, dword ptr [esi + 8]
// 005fd1e8  8b16                 mov edx, dword ptr [esi]
// 005fd1ea  50                   push eax
// 005fd1eb  8b4604               mov eax, dword ptr [esi + 4]
// 005fd1ee  6a04                 push 4
// 005fd1f0  8d4c241c             lea ecx, [esp + 0x1c]
// 005fd1f4  51                   push ecx
// 005fd1f5  52                   push edx
// 005fd1f6  ffd0                 call eax
// 005fd1f8  83c410               add esp, 0x10
// 005fd1fb  894610               mov dword ptr [esi + 0x10], eax
// 005fd1fe  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd202  8a4f48               mov cl, byte ptr [edi + 0x48]
// 005fd205  884c2414             mov byte ptr [esp + 0x14], cl
// 005fd209  7519                 jne 0x5fd224
// 005fd20b  8b5608               mov edx, dword ptr [esi + 8]
// 005fd20e  8b0e                 mov ecx, dword ptr [esi]
// 005fd210  52                   push edx
// 005fd211  8b5604               mov edx, dword ptr [esi + 4]
// 005fd214  6a01                 push 1
// 005fd216  8d44241c             lea eax, [esp + 0x1c]
// 005fd21a  50                   push eax
// 005fd21b  51                   push ecx
// 005fd21c  ffd2                 call edx
// 005fd21e  83c410               add esp, 0x10
// 005fd221  894610               mov dword ptr [esi + 0x10], eax
// 005fd224  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd228  8a4749               mov al, byte ptr [edi + 0x49]
// 005fd22b  88442414             mov byte ptr [esp + 0x14], al
// 005fd22f  7519                 jne 0x5fd24a
// 005fd231  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fd234  8b06                 mov eax, dword ptr [esi]
// 005fd236  51                   push ecx
// 005fd237  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fd23a  6a01                 push 1
// 005fd23c  8d54241c             lea edx, [esp + 0x1c]
// 005fd240  52                   push edx
// 005fd241  50                   push eax
// 005fd242  ffd1                 call ecx
// 005fd244  83c410               add esp, 0x10
// 005fd247  894610               mov dword ptr [esi + 0x10], eax
// 005fd24a  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd24e  8a574a               mov dl, byte ptr [edi + 0x4a]
// 005fd251  88542414             mov byte ptr [esp + 0x14], dl
// 005fd255  7519                 jne 0x5fd270
// 005fd257  8b4608               mov eax, dword ptr [esi + 8]
// 005fd25a  8b16                 mov edx, dword ptr [esi]
// 005fd25c  50                   push eax
// 005fd25d  8b4604               mov eax, dword ptr [esi + 4]
// 005fd260  6a01                 push 1
// 005fd262  8d4c241c             lea ecx, [esp + 0x1c]
// 005fd266  51                   push ecx
// 005fd267  52                   push edx
// 005fd268  ffd0                 call eax
// 005fd26a  83c410               add esp, 0x10
// 005fd26d  894610               mov dword ptr [esi + 0x10], eax
// 005fd270  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd274  8a4f4b               mov cl, byte ptr [edi + 0x4b]
// 005fd277  884c2414             mov byte ptr [esp + 0x14], cl
// 005fd27b  7519                 jne 0x5fd296
// 005fd27d  8b5608               mov edx, dword ptr [esi + 8]
// 005fd280  8b0e                 mov ecx, dword ptr [esi]
// 005fd282  52                   push edx
// 005fd283  8b5604               mov edx, dword ptr [esi + 4]
// 005fd286  6a01                 push 1
// 005fd288  8d44241c             lea eax, [esp + 0x1c]
// 005fd28c  50                   push eax
// 005fd28d  51                   push ecx
// 005fd28e  ffd2                 call edx
// 005fd290  83c410               add esp, 0x10
// 005fd293  894610               mov dword ptr [esi + 0x10], eax
// 005fd296  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fd29a  8b5f2c               mov ebx, dword ptr [edi + 0x2c]
// 005fd29d  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 005fd2a0  895c2414             mov dword ptr [esp + 0x14], ebx
// 005fd2a4  7538                 jne 0x5fd2de
// 005fd2a6  8b4608               mov eax, dword ptr [esi + 8]
// 005fd2a9  8b16                 mov edx, dword ptr [esi]
// 005fd2ab  50                   push eax
// 005fd2ac  8b4604               mov eax, dword ptr [esi + 4]
// 005fd2af  6a04                 push 4
// 005fd2b1  8d4c241c             lea ecx, [esp + 0x1c]
// 005fd2b5  51                   push ecx
// 005fd2b6  52                   push edx
// 005fd2b7  ffd0                 call eax
// 005fd2b9  83c410               add esp, 0x10
// 005fd2bc  85c0                 test eax, eax
// 005fd2be  894610               mov dword ptr [esi + 0x10], eax
// 005fd2c1  751b                 jne 0x5fd2de
// 005fd2c3  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fd2c6  8b06                 mov eax, dword ptr [esi]
// 005fd2c8  51                   push ecx
// 005fd2c9  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fd2cc  8d149d00000000       lea edx, [ebx*4]
// 005fd2d3  52                   push edx
// 005fd2d4  55                   push ebp
// 005fd2d5  50                   push eax
// 005fd2d6  ffd1                 call ecx
// 005fd2d8  83c410               add esp, 0x10
// 005fd2db  894610               mov dword ptr [esi + 0x10], eax
// 005fd2de  57                   push edi
// 005fd2df  8bc6                 mov eax, esi
// 005fd2e1  e81afcffff           call 0x5fcf00
// 005fd2e6  57                   push edi
// 005fd2e7  8bc6                 mov eax, esi
// 005fd2e9  e852fdffff           call 0x5fd040
// 005fd2ee  83c408               add esp, 8
// 005fd2f1  5f                   pop edi
// 005fd2f2  5e                   pop esi
// 005fd2f3  5d                   pop ebp
// 005fd2f4  5b                   pop ebx
// 005fd2f5  c3                   ret 
// library lua-5.1.1/ldump.c (function _DumpFunction)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldump.c
