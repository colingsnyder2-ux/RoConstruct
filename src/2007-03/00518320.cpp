// from server: 100% by auto
// roc 2007-03 00518320  unit: seg_00510000  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518320
//
// 00518320  83ec14               sub esp, 0x14
// 00518323  a1b4f58a00           mov eax, dword ptr [0x8af5b4]
// 00518328  33c4                 xor eax, esp
// 0051832a  89442410             mov dword ptr [esp + 0x10], eax
// 0051832e  55                   push ebp
// 0051832f  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00518333  8b556c               mov edx, dword ptr [ebp + 0x6c]
// 00518336  f7c200000c00         test edx, 0xc0000
// 0051833c  56                   push esi
// 0051833d  8b742424             mov esi, dword ptr [esp + 0x24]
// 00518341  746d                 je 0x5183b0
// 00518343  803e23               cmp byte ptr [esi], 0x23
// 00518346  7552                 jne 0x51839a
// 00518348  b801000000           mov eax, 1
// 0051834d  b120                 mov cl, 0x20
// 0051834f  90                   nop 
// 00518350  380c06               cmp byte ptr [esi + eax], cl
// 00518353  7413                 je 0x518368
// 00518355  384c0601             cmp byte ptr [esi + eax + 1], cl
// 00518359  740a                 je 0x518365
// 0051835b  83c002               add eax, 2
// 0051835e  83f80f               cmp eax, 0xf
// 00518361  7ced                 jl 0x518350
// 00518363  eb03                 jmp 0x518368
// 00518365  83c001               add eax, 1
// 00518368  f7c200000800         test edx, 0x80000
// 0051836e  7426                 je 0x518396
// 00518370  57                   push edi
// 00518371  8d78ff               lea edi, [eax - 1]
// 00518374  33c9                 xor ecx, ecx
// 00518376  85ff                 test edi, edi
// 00518378  7e14                 jle 0x51838e
// 0051837a  8d4601               lea eax, [esi + 1]
// 0051837d  57                   push edi
// 0051837e  50                   push eax
// 0051837f  8d442414             lea eax, [esp + 0x14]
// 00518383  50                   push eax
// 00518384  e8596e1000           call 0x61f1e2
// 00518389  83c40c               add esp, 0xc
// 0051838c  8bcf                 mov ecx, edi
// 0051838e  c6440c0c00           mov byte ptr [esp + ecx + 0xc], 0
// 00518393  5f                   pop edi
// 00518394  eb16                 jmp 0x5183ac
// 00518396  03f0                 add esi, eax
// 00518398  eb16                 jmp 0x5183b0
// 0051839a  f7c200000800         test edx, 0x80000
// 005183a0  740e                 je 0x5183b0
// 005183a2  c644240830           mov byte ptr [esp + 8], 0x30
// 005183a7  c644240900           mov byte ptr [esp + 9], 0
// 005183ac  8d742408             lea esi, [esp + 8]
// 005183b0  8b4540               mov eax, dword ptr [ebp + 0x40]
// 005183b3  85c0                 test eax, eax
// 005183b5  7407                 je 0x5183be
// 005183b7  56                   push esi
// 005183b8  55                   push ebp
// 005183b9  ffd0                 call eax
// 005183bb  83c408               add esp, 8
// 005183be  56                   push esi
// 005183bf  55                   push ebp
// 005183c0  e8abfcffff           call 0x518070
// 005183c5  5e                   pop esi
// 005183c6  5d                   pop ebp
// library libpng-1.2.7/pngerror.c (function _png_error)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS /MD
// roc-lib: libpng-1.2.7 pngerror.c
