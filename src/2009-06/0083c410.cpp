// from server: 99% by EspClaude
// from server: 100% by colin
// roc 2008-06 00687860  unit: Ogre::RbxSubEntity  size: 6738 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00687860
//
// 00687860  6aff                 push -1
// 00687862  64a100000000         mov eax, dword ptr fs:[0]
// 00687868  68fbdf7d00           push 0x7ddffb
// 0068786d  50                   push eax
// 0068786e  64892500000000       mov dword ptr fs:[0], esp
// 00687875  81ec30090000         sub esp, 0x930
// 0068787b  53                   push ebx
// 0068787c  55                   push ebp
// 0068787d  56                   push esi
// 0068787e  8bb42454090000       mov esi, dword ptr [esp + 0x954]
// 00687885  33db                 xor ebx, ebx
// 00687887  57                   push edi
// 00687888  8be9                 mov ebp, ecx
// 0068788a  3bf3                 cmp esi, ebx
// 0068788c  751b                 jne 0x6878a9
// 0068788e  8b8c2450090000       mov ecx, dword ptr [esp + 0x950]
// 00687895  8b01                 mov eax, dword ptr [ecx]
// 00687897  8b942454090000       mov edx, dword ptr [esp + 0x954]
// 0068789e  8b80dc000000         mov eax, dword ptr [eax + 0xdc]
// 006878a4  52                   push edx
// 006878a5  ffd0                 call eax
// 006878a7  8bf0                 mov esi, eax
// 006878a9  d9ee                 fldz 
// 006878ab  8b8c2464090000       mov ecx, dword ptr [esp + 0x964]
// 006878b2  81f9f0000000         cmp ecx, 0xf0
// 006878b8  d9542420             fst dword ptr [esp + 0x20]
// 006878bc  d954242c             fst dword ptr [esp + 0x2c]
// 006878c0  7c14                 jl 0x6878d6
// 006878c2  c7842464090000ef000000 mov dword ptr [esp + 0x964], 0xef
// 006878cd  8b8c2464090000       mov ecx, dword ptr [esp + 0x964]
// 006878d4  eb09                 jmp 0x6878df
// 006878d6  83f902               cmp ecx, 2
// 006878d9  0f8cb4190000         jl 0x689293
// 006878df  8bbc2468090000       mov edi, dword ptr [esp + 0x968]
// 006878e6  83ff01               cmp edi, 1
// 006878e9  0f8ca4190000         jl 0x689293
// 006878ef  d9842460090000       fld dword ptr [esp + 0x960]
// 006878f6  d8d1                 fcom st(1)
// 006878f8  dfe0                 fnstsw ax
// 006878fa  f6c441               test ah, 0x41
// 006878fd  0f8b88190000         jnp 0x68928b
// 00687903  d984245c090000       fld dword ptr [esp + 0x95c]
// 0068790a  d8d2                 fcom st(2)
// 0068790c  dfe0                 fnstsw ax
// 0068790e  f6c405               test ah, 5
// 00687911  0f8b78190000         jnp 0x68928f
// 00687917  d8d1                 fcom st(1)
// 00687919  dfe0                 fnstsw ax
// 0068791b  f6c441               test ah, 0x41
// 0068791e  0f846b190000         je 0x68928f
// 00687924  d90580e98400         fld dword ptr [0x84e980]
// 0068792a  d9842470090000       fld dword ptr [esp + 0x970]
// 00687931  d8d1                 fcom st(1)
// 00687933  dfe0                 fnstsw ax
// 00687935  ddd9                 fstp st(1)
// 00687937  f6c405               test ah, 5
// 0068793a  7a12                 jp 0x68794e
// 0068793c  dddb                 fstp st(3)
// 0068793e  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00687942  ddda                 fstp st(2)
// 00687944  d9057ce98400         fld dword ptr [0x84e97c]
// 0068794a  d9c0                 fld st(0)
// 0068794c  eb62                 jmp 0x6879b0
// 0068794e  d9057ce98400         fld dword ptr [0x84e97c]
// 00687954  d8d1                 fcom st(1)
// 00687956  dfe0                 fnstsw ax
// 00687958  f6c405               test ah, 5
// 0068795b  7a12                 jp 0x68796f
// 0068795d  dddc                 fstp st(4)
// 0068795f  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00687963  ddd8                 fstp st(0)
// 00687965  d9c2                 fld st(2)
// 00687967  d9c9                 fxch st(1)
// 00687969  d9cb                 fxch st(3)
// 0068796b  d9c9                 fxch st(1)
// 0068796d  eb41                 jmp 0x6879b0
// 0068796f  d9cc                 fxch st(4)
// 00687971  d8d9                 fcomp st(1)
// 00687973  dfe0                 fnstsw ax
// 00687975  f6c441               test ah, 0x41
// 00687978  7512                 jne 0x68798c
// 0068797a  d984246c090000       fld dword ptr [esp + 0x96c]
// 00687981  d8c1                 fadd st(1)
// 00687983  d99c246c090000       fstp dword ptr [esp + 0x96c]
// 0068798a  d9e0                 fchs 
// 0068798c  d9c3                 fld st(3)
// 0068798e  dde9                 fucomp st(1)
// 00687990  dfe0                 fnstsw ax
// 00687992  f6c444               test ah, 0x44
// 00687995  7a0c                 jp 0x6879a3
// 00687997  d9c9                 fxch st(1)
// 00687999  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0068799d  d9cb                 fxch st(3)
// 0068799f  d9c9                 fxch st(1)
// 006879a1  eb0d                 jmp 0x6879b0
// 006879a3  8d5101               lea edx, [ecx + 1]
// 006879a6  d9c9                 fxch st(1)
// 006879a8  d9cb                 fxch st(3)
// 006879aa  8954241c             mov dword ptr [esp + 0x1c], edx
// 006879ae  d9c9                 fxch st(1)
// 006879b0  8b15e8468000         mov edx, dword ptr [0x8046e8]
// 006879b6  d9c2                 fld st(2)
// 006879b8  dee4                 fsubrp st(4)
// 006879ba  33c0                 xor eax, eax
// 006879bc  3bcb                 cmp ecx, ebx
// 006879be  d9cb                 fxch st(3)
// 006879c0  89442414             mov dword ptr [esp + 0x14], eax
// 006879c4  d95c2430             fstp dword ptr [esp + 0x30]
// 006879c8  d902                 fld dword ptr [edx]
// 006879ca  d88c246c090000       fmul dword ptr [esp + 0x96c]
// 006879d1  d90578e98400         fld dword ptr [0x84e978]
// 006879d7  dcc9                 fmul st(1), st(0)
// 006879d9  7c36                 jl 0x687a11
// 006879db  d902                 fld dword ptr [edx]
// 006879dd  d8cd                 fmul st(5)
// 006879df  dec9                 fmulp st(1)
// 006879e1  db842464090000       fild dword ptr [esp + 0x964]
// 006879e8  d9c1                 fld st(1)
// 006879ea  40                   inc eax
// 006879eb  3bc1                 cmp eax, ecx
// 006879ed  da4c2414             fimul dword ptr [esp + 0x14]
// 006879f1  89442414             mov dword ptr [esp + 0x14], eax
// 006879f5  d8f1                 fdiv st(1)
// 006879f7  d8c3                 fadd st(3)
// 006879f9  d9c0                 fld st(0)
// 006879fb  d9fe                 fsin 
// 006879fd  d99c847c050000       fstp dword ptr [esp + eax*4 + 0x57c]
// 00687a04  d9ff                 fcos 
// 00687a06  d99c84bc010000       fstp dword ptr [esp + eax*4 + 0x1bc]
// 00687a0d  7ed9                 jle 0x6879e8
// 00687a0f  ddd9                 fstp st(1)
// 00687a11  ddd8                 fstp st(0)
// 00687a13  ddd8                 fstp st(0)
// 00687a15  d9c0                 fld st(0)
// 00687a17  ddeb                 fucomp st(3)
// 00687a19  dfe0                 fnstsw ax
// 00687a1b  f6c444               test ah, 0x44
// 00687a1e  7a1c                 jp 0x687a3c
// 00687a20  d9842480050000       fld dword ptr [esp + 0x580]
// 00687a27  d99c8c80050000       fstp dword ptr [esp + ecx*4 + 0x580]
// 00687a2e  d98424c0010000       fld dword ptr [esp + 0x1c0]
// 00687a35  d99c8cc0010000       fstp dword ptr [esp + ecx*4 + 0x1c0]
// 00687a3c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00687a3f  83f803               cmp eax, 3
// 00687a42  0f8739180000         ja 0x689281
// 00687a48  ff2485b4926800       jmp dword ptr [eax*4 + 0x6892b4]
// 00687a4f  ddda                 fstp st(2)
// 00687a51  ddd9                 fstp st(1)
// 00687a53  d9ee                 fldz 
// 00687a55  d89c245c090000       fcomp dword ptr [esp + 0x95c]
// 00687a5c  dfe0                 fnstsw ax
// 00687a5e  f6c444               test ah, 0x44
// 00687a61  0f8abd020000         jp 0x687d24
// 00687a67  8d47ff               lea eax, [edi - 1]
// 00687a6a  ddd8                 fstp st(0)
// 00687a6c  6816b78000           push 0x80b716
// 00687a71  8d8c24e4000000       lea ecx, [esp + 0xe4]
// 00687a78  89442450             mov dword ptr [esp + 0x50], eax
// 00687a7c  8944242c             mov dword ptr [esp + 0x2c], eax
// 00687a80  ff1558248000         call dword ptr [0x802458]
// 00687a86  8b06                 mov eax, dword ptr [esi]
// 00687a88  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00687a8e  6a06                 push 6
// 00687a90  8d8c24e4000000       lea ecx, [esp + 0xe4]
// 00687a97  51                   push ecx
// 00687a98  8bce                 mov ecx, esi
// 00687a9a  899c2450090000       mov dword ptr [esp + 0x950], ebx
// 00687aa1  ffd2                 call edx
// 00687aa3  8d8c24e0000000       lea ecx, [esp + 0xe0]
// 00687aaa  c7842448090000ffffffff mov dword ptr [esp + 0x948], 0xffffffff
// 00687ab5  ff1568248000         call dword ptr [0x802468]
// 00687abb  d9ee                 fldz 
// 00687abd  d85d10               fcomp dword ptr [ebp + 0x10]
// 00687ac0  8d4d10               lea ecx, [ebp + 0x10]
// 00687ac3  dfe0                 fnstsw ax
// 00687ac5  f6c441               test ah, 0x41
// 00687ac8  7a0d                 jp 0x687ad7
// 00687aca  8b06                 mov eax, dword ptr [esi]
// 00687acc  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00687ad2  51                   push ecx
// 00687ad3  8bce                 mov ecx, esi
// 00687ad5  ffd2                 call edx
// 00687ad7  d94528               fld dword ptr [ebp + 0x28]
// 00687ada  8b06                 mov eax, dword ptr [esi]
// 00687adc  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 00687ae2  83ec0c               sub esp, 0xc
// 00687ae5  d95c2408             fstp dword ptr [esp + 8]
// 00687ae9  8bce                 mov ecx, esi
// 00687aeb  d94524               fld dword ptr [ebp + 0x24]
// 00687aee  d95c2404             fstp dword ptr [esp + 4]
// 00687af2  d94520               fld dword ptr [ebp + 0x20]
// 00687af5  d91c24               fstp dword ptr [esp]
// 00687af8  ffd2                 call edx
// 00687afa  8b06                 mov eax, dword ptr [esi]
// 00687afc  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00687b02  53                   push ebx
// 00687b03  8bce                 mov ecx, esi
// 00687b05  ffd2                 call edx
// 00687b07  bf01000000           mov edi, 1
// 00687b0c  397d00               cmp dword ptr [ebp], edi
// 00687b0f  772b                 ja 0x687b3c
// 00687b11  8b06                 mov eax, dword ptr [esi]
// 00687b13  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 00687b19  83ec0c               sub esp, 0xc
// 00687b1c  8bce                 mov ecx, esi
// 00687b1e  395d08               cmp dword ptr [ebp + 8], ebx
// 00687b21  7504                 jne 0x687b27
// 00687b23  d9e8                 fld1 
// 00687b25  eb06                 jmp 0x687b2d
// 00687b27  d905b8c38100         fld dword ptr [0x81c3b8]
// 00687b2d  d95c2408             fstp dword ptr [esp + 8]
// 00687b31  d9ee                 fldz 
// 00687b33  d9542404             fst dword ptr [esp + 4]
// 00687b37  d91c24               fstp dword ptr [esp]
// 00687b3a  ffd2                 call edx
// 00687b3c  807d0400             cmp byte ptr [ebp + 4], 0
// 00687b40  741c                 je 0x687b5e
// 00687b42  8b06                 mov eax, dword ptr [esi]
// 00687b44  d905ac9b8100         fld dword ptr [0x819bac]
// 00687b4a  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 00687b50  83ec08               sub esp, 8
// 00687b53  d9542404             fst dword ptr [esp + 4]
// 00687b57  8bce                 mov ecx, esi
// 00687b59  d91c24               fstp dword ptr [esp]
// 00687b5c  ffd2                 call edx
// 00687b5e  807d0400             cmp byte ptr [ebp + 4], 0
// 00687b62  db44244c             fild dword ptr [esp + 0x4c]
// 00687b66  dab42468090000       fidiv dword ptr [esp + 0x968]
// 00687b6d  d84c2430             fmul dword ptr [esp + 0x30]
// 00687b71  d9842460090000       fld dword ptr [esp + 0x960]
// 00687b78  d9c0                 fld st(0)
// 00687b7a  dee2                 fsubrp st(2)
// 00687b7c  d9c9                 fxch st(1)
// 00687b7e  d9542418             fst dword ptr [esp + 0x18]
// 00687b82  7412                 je 0x687b96
// 00687b84  d9c0                 fld st(0)
// 00687b86  def2                 fdivrp st(2)
// 00687b88  d9c9                 fxch st(1)
// 00687b8a  d80dac9b8100         fmul dword ptr [0x819bac]
// 00687b90  d95c2420             fstp dword ptr [esp + 0x20]
// 00687b94  eb02                 jmp 0x687b98
// 00687b96  ddd9                 fstp st(1)
// 00687b98  395d08               cmp dword ptr [ebp + 8], ebx
// 00687b9b  0f85c7000000         jne 0x687c68
// 00687ba1  8b9c2464090000       mov ebx, dword ptr [esp + 0x964]
// 00687ba8  85db                 test ebx, ebx
// 00687baa  7d1e                 jge 0x687bca
// 00687bac  8b06                 mov eax, dword ptr [esi]
// 00687bae  ddd8                 fstp st(0)
// 00687bb0  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 00687bb6  8bce                 mov ecx, esi
// 00687bb8  ffd2                 call edx
// 00687bba  d9842460090000       fld dword ptr [esp + 0x960]
// 00687bc1  e962010000           jmp 0x687d28
// 00687bc6  d9442418             fld dword ptr [esp + 0x18]
// 00687bca  d94528               fld dword ptr [ebp + 0x28]
// 00687bcd  8b06                 mov eax, dword ptr [esi]
// 00687bcf  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 00687bd5  83ec0c               sub esp, 0xc
// 00687bd8  d95c2408             fstp dword ptr [esp + 8]
// 00687bdc  8bce                 mov ecx, esi
// 00687bde  d9849ccc010000       fld dword ptr [esp + ebx*4 + 0x1cc]
// 00687be5  d8c9                 fmul st(1)
// 00687be7  d84524               fadd dword ptr [ebp + 0x24]
// 00687bea  d95c2404             fstp dword ptr [esp + 4]
// 00687bee  d88c9c8c050000       fmul dword ptr [esp + ebx*4 + 0x58c]
// 00687bf5  d84520               fadd dword ptr [ebp + 0x20]
// 00687bf8  d91c24               fstp dword ptr [esp]
// 00687bfb  ffd2                 call edx
// 00687bfd  8b06                 mov eax, dword ptr [esi]
// 00687bff  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00687c05  57                   push edi
// 00687c06  8bce                 mov ecx, esi
// 00687c08  ffd2                 call edx
// 00687c0a  47                   inc edi
// 00687c0b  807d0400             cmp byte ptr [ebp + 4], 0
// 00687c0f  7436                 je 0x687c47
// 00687c11  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 00687c18  8b06                 mov eax, dword ptr [esi]
// 00687c1a  d9442420             fld dword ptr [esp + 0x20]
// 00687c1e  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 00687c24  dcc9                 fmul st(1), st(0)
// 00687c26  83ec08               sub esp, 8
// 00687c29  d905ac9b8100         fld dword ptr [0x819bac]
// 00687c2f  8bce                 mov ecx, esi
// 00687c31  dcc2                 fadd st(2), st(0)
// 00687c33  d9ca                 fxch st(2)
// 00687c35  d95c2404             fstp dword ptr [esp + 4]
// 00687c39  d88c9c88050000       fmul dword ptr [esp + ebx*4 + 0x588]
// 00687c40  dec1                 faddp st(1)
// 00687c42  d91c24               fstp dword ptr [esp]
// 00687c45  ffd2                 call edx
// 00687c47  83eb01               sub ebx, 1
// 00687c4a  0f8976ffffff         jns 0x687bc6
// 00687c50  8b06                 mov eax, dword ptr [esi]
// 00687c52  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 00687c58  8bce                 mov ecx, esi
// 00687c5a  ffd2                 call edx
// 00687c5c  d9842460090000       fld dword ptr [esp + 0x960]
// 00687c63  e9c0000000           jmp 0x687d28
// 00687c68  33db                 xor ebx, ebx
// 00687c6a  399c2464090000       cmp dword ptr [esp + 0x964], ebx
// 00687c71  0f8c35ffffff         jl 0x687bac
// 00687c77  eb0b                 jmp 0x687c84
// 00687c79  8da42400000000       lea esp, [esp]
// 00687c80  d9442418             fld dword ptr [esp + 0x18]
// 00687c84  d94528               fld dword ptr [ebp + 0x28]
// 00687c87  8b06                 mov eax, dword ptr [esi]
// 00687c89  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 00687c8f  83ec0c               sub esp, 0xc
// 00687c92  d95c2408             fstp dword ptr [esp + 8]
// 00687c96  8bce                 mov ecx, esi
// 00687c98  d9849ccc010000       fld dword ptr [esp + ebx*4 + 0x1cc]
// 00687c9f  d8c9                 fmul st(1)
// 00687ca1  d84524               fadd dword ptr [ebp + 0x24]
// 00687ca4  d95c2404             fstp dword ptr [esp + 4]
// 00687ca8  d88c9c8c050000       fmul dword ptr [esp + ebx*4 + 0x58c]
// 00687caf  d84520               fadd dword ptr [ebp + 0x20]
// 00687cb2  d91c24               fstp dword ptr [esp]
// 00687cb5  ffd2                 call edx
// 00687cb7  8b06                 mov eax, dword ptr [esi]
// 00687cb9  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00687cbf  57                   push edi
// 00687cc0  8bce                 mov ecx, esi
// 00687cc2  ffd2                 call edx
// 00687cc4  47                   inc edi
// 00687cc5  807d0400             cmp byte ptr [ebp + 4], 0
// 00687cc9  7436                 je 0x687d01
// 00687ccb  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 00687cd2  8b06                 mov eax, dword ptr [esi]
// 00687cd4  d9442420             fld dword ptr [esp + 0x20]
// 00687cd8  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 00687cde  dcc9                 fmul st(1), st(0)
// 00687ce0  83ec08               sub esp, 8
// 00687ce3  d905ac9b8100         fld dword ptr [0x819bac]
// 00687ce9  8bce                 mov ecx, esi
// 00687ceb  dcc2                 fadd st(2), st(0)
// 00687ced  d9ca                 fxch st(2)
// 00687cef  d95c2404             fstp dword ptr [esp + 4]
// 00687cf3  d88c9c88050000       fmul dword ptr [esp + ebx*4 + 0x588]
// 00687cfa  dec1                 faddp st(1)
// 00687cfc  d91c24               fstp dword ptr [esp]
// 00687cff  ffd2                 call edx
// 00687d01  43                   inc ebx
// 00687d02  3b9c2464090000       cmp ebx, dword ptr [esp + 0x964]
// 00687d09  0f8e71ffffff         jle 0x687c80
// 00687d0f  8b06                 mov eax, dword ptr [esi]
// 00687d11  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 00687d17  8bce                 mov ecx, esi
// 00687d19  ffd2                 call edx
// 00687d1b  d9842460090000       fld dword ptr [esp + 0x960]
// 00687d22  eb04                 jmp 0x687d28
// 00687d24  897c2428             mov dword ptr [esp + 0x28], edi
// 00687d28  33c0                 xor eax, eax
// 00687d2a  39442428             cmp dword ptr [esp + 0x28], eax
// 00687d2e  89442410             mov dword ptr [esp + 0x10], eax
// 00687d32  0f8e4d150000         jle 0x689285
// 00687d38  db842468090000       fild dword ptr [esp + 0x968]
// 00687d3f  d9542424             fst dword ptr [esp + 0x24]
// 00687d43  d9442430             fld dword ptr [esp + 0x30]
// 00687d47  eb1a                 jmp 0x687d63
// 00687d49  8da42400000000       lea esp, [esp]
// 00687d50  d9442424             fld dword ptr [esp + 0x24]
// 00687d54  d9442430             fld dword ptr [esp + 0x30]
// 00687d58  d9842460090000       fld dword ptr [esp + 0x960]
// 00687d5f  d9ca                 fxch st(2)
// 00687d61  d9c9                 fxch st(1)
// 00687d63  db442410             fild dword ptr [esp + 0x10]
// 00687d67  40                   inc eax
// 00687d68  807d0400             cmp byte ptr [ebp + 4], 0
// 00687d6c  8944244c             mov dword ptr [esp + 0x4c], eax
// 00687d70  d8f2                 fdiv st(2)
// 00687d72  d8c9                 fmul st(1)
// 00687d74  d8eb                 fsubr st(3)
// 00687d76  d9542418             fst dword ptr [esp + 0x18]
// 00687d7a  db44244c             fild dword ptr [esp + 0x4c]
// 00687d7e  def3                 fdivrp st(3)
// 00687d80  d9ca                 fxch st(2)
// 00687d82  dec9                 fmulp st(1)
// 00687d84  d8ea                 fsubr st(2)
// 00687d86  d954241c             fst dword ptr [esp + 0x1c]
// 00687d8a  7420                 je 0x687dac
// 00687d8c  d9e8                 fld1 
// 00687d8e  def3                 fdivrp st(3)
// 00687d90  d9c2                 fld st(2)
// 00687d92  deca                 fmulp st(2)
// 00687d94  d905ac9b8100         fld dword ptr [0x819bac]
// 00687d9a  dcca                 fmul st(2), st(0)
// 00687d9c  d9ca                 fxch st(2)
// 00687d9e  d95c2420             fstp dword ptr [esp + 0x20]
// 00687da2  deca                 fmulp st(2)
// 00687da4  dec9                 fmulp st(1)
// 00687da6  d95c242c             fstp dword ptr [esp + 0x2c]
// 00687daa  eb06                 jmp 0x687db2
// 00687dac  ddda                 fstp st(2)
// 00687dae  ddd8                 fstp st(0)
// 00687db0  ddd8                 fstp st(0)
// 00687db2  8d4c2434             lea ecx, [esp + 0x34]
// 00687db6  e81516daff           call 0x4293d0
// 00687dbb  6816b78000           push 0x80b716
// 00687dc0  8d8c241c010000       lea ecx, [esp + 0x11c]
// 00687dc7  c784244c09000001000000 mov dword ptr [esp + 0x94c], 1
// 00687dd2  ff1558248000         call dword ptr [0x802458]
// 00687dd8  8b06                 mov eax, dword ptr [esi]
// 00687dda  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00687de0  6a04                 push 4
// 00687de2  8d8c241c010000       lea ecx, [esp + 0x11c]
// 00687de9  51                   push ecx
// 00687dea  8bce                 mov ecx, esi
// 00687dec  c684245009000002     mov byte ptr [esp + 0x950], 2
// 00687df4  ffd2                 call edx
// 00687df6  8d8c2418010000       lea ecx, [esp + 0x118]
// 00687dfd  c684244809000001     mov byte ptr [esp + 0x948], 1
// 00687e05  ff1568248000         call dword ptr [0x802468]
// 00687e0b  d9ee                 fldz 
// 00687e0d  d85d10               fcomp dword ptr [ebp + 0x10]
// 00687e10  8d4d10               lea ecx, [ebp + 0x10]
// 00687e13  33ff                 xor edi, edi
// 00687e15  dfe0                 fnstsw ax
// 00687e17  f6c441               test ah, 0x41
// 00687e1a  7a0d                 jp 0x687e29
// 00687e1c  8b06                 mov eax, dword ptr [esi]
// 00687e1e  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00687e24  51                   push ecx
// 00687e25  8bce                 mov ecx, esi
// 00687e27  ffd2                 call edx
// 00687e29  837d0001             cmp dword ptr [ebp], 1
// 00687e2d  772c                 ja 0x687e5b
// 00687e2f  8b06                 mov eax, dword ptr [esi]
// 00687e31  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 00687e37  83ec0c               sub esp, 0xc
// 00687e3a  837d0800             cmp dword ptr [ebp + 8], 0
// 00687e3e  8bce                 mov ecx, esi
// 00687e40  7504                 jne 0x687e46
// 00687e42  d9e8                 fld1 
// 00687e44  eb06                 jmp 0x687e4c
// 00687e46  d905b8c38100         fld dword ptr [0x81c3b8]
// 00687e4c  d95c2408             fstp dword ptr [esp + 8]
// 00687e50  d9ee                 fldz 
// 00687e52  d9542404             fst dword ptr [esp + 4]
// 00687e56  d91c24               fstp dword ptr [esp]
// 00687e59  ffd2                 call edx
// 00687e5b  33db                 xor ebx, ebx
// 00687e5d  399c2464090000       cmp dword ptr [esp + 0x964], ebx
// 00687e64  0f8ce7090000         jl 0x688851
// 00687e6a  8d9b00000000         lea ebx, [ebx]
// 00687e70  837d0800             cmp dword ptr [ebp + 8], 0
// 00687e74  0f85e2040000         jne 0x68835c
// 00687e7a  807d0400             cmp byte ptr [ebp + 4], 0
// 00687e7e  7436                 je 0x687eb6
// 00687e80  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 00687e87  8b06                 mov eax, dword ptr [esi]
// 00687e89  d9442420             fld dword ptr [esp + 0x20]
// 00687e8d  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 00687e93  dcc9                 fmul st(1), st(0)
// 00687e95  83ec08               sub esp, 8
// 00687e98  d905ac9b8100         fld dword ptr [0x819bac]
// 00687e9e  8bce                 mov ecx, esi
// 00687ea0  dcc2                 fadd st(2), st(0)
// 00687ea2  d9ca                 fxch st(2)
// 00687ea4  d95c2404             fstp dword ptr [esp + 4]
// 00687ea8  d88c9c88050000       fmul dword ptr [esp + ebx*4 + 0x588]
// 00687eaf  dec1                 faddp st(1)
// 00687eb1  d91c24               fstp dword ptr [esp]
// 00687eb4  ffd2                 call edx
// 00687eb6  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00687eba  2b4c2440             sub ecx, dword ptr [esp + 0x40]
// 00687ebe  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00687ec3  f7e9                 imul ecx
// 00687ec5  d1fa                 sar edx, 1
// 00687ec7  8bc2                 mov eax, edx
// 00687ec9  c1e81f               shr eax, 0x1f
// 00687ecc  03c2                 add eax, edx
// 00687ece  89442410             mov dword ptr [esp + 0x10], eax
// 00687ed2  83f802               cmp eax, 2
// 00687ed5  0f82d3010000         jb 0x6880ae
// 00687edb  2501000080           and eax, 0x80000001
// 00687ee0  7905                 jns 0x687ee7
// 00687ee2  48                   dec eax
// 00687ee3  83c8fe               or eax, 0xfffffffe
// 00687ee6  40                   inc eax
// 00687ee7  8b06                 mov eax, dword ptr [esi]
// 00687ee9  8d4c2434             lea ecx, [esp + 0x34]
// 00687eed  0f84e5000000         je 0x687fd8
// 00687ef3  05f4000000           add eax, 0xf4
// 00687ef8  89442414             mov dword ptr [esp + 0x14], eax
// 00687efc  8b442410             mov eax, dword ptr [esp + 0x10]
// 00687f00  48                   dec eax
// 00687f01  50                   push eax
// 00687f02  e879500000           call 0x68cf80
// 00687f07  8b542414             mov edx, dword ptr [esp + 0x14]
// 00687f0b  50                   push eax
// 00687f0c  8b02                 mov eax, dword ptr [edx]
// 00687f0e  8bce                 mov ecx, esi
// 00687f10  ffd0                 call eax
// 00687f12  8b16                 mov edx, dword ptr [esi]
// 00687f14  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00687f1a  57                   push edi
// 00687f1b  8bce                 mov ecx, esi
// 00687f1d  ffd0                 call eax
// 00687f1f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00687f23  8b06                 mov eax, dword ptr [esi]
// 00687f25  83c1fe               add ecx, -2
// 00687f28  05f4000000           add eax, 0xf4
// 00687f2d  51                   push ecx
// 00687f2e  8d4c2438             lea ecx, [esp + 0x38]
// 00687f32  47                   inc edi
// 00687f33  89442418             mov dword ptr [esp + 0x18], eax
// 00687f37  e844500000           call 0x68cf80
// 00687f3c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00687f40  50                   push eax
// 00687f41  8b02                 mov eax, dword ptr [edx]
// 00687f43  8bce                 mov ecx, esi
// 00687f45  ffd0                 call eax
// 00687f47  8b16                 mov edx, dword ptr [esi]
// 00687f49  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00687f4f  57                   push edi
// 00687f50  8bce                 mov ecx, esi
// 00687f52  ffd0                 call eax
// 00687f54  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 00687f5b  d9442418             fld dword ptr [esp + 0x18]
// 00687f5f  8b16                 mov edx, dword ptr [esi]
// 00687f61  dcc9                 fmul st(1), st(0)
// 00687f63  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00687f69  d9c9                 fxch st(1)
// 00687f6b  83ec0c               sub esp, 0xc
// 00687f6e  8bce                 mov ecx, esi
// 00687f70  d954241c             fst dword ptr [esp + 0x1c]
// 00687f74  47                   inc edi
// 00687f75  d9849c8c050000       fld dword ptr [esp + ebx*4 + 0x58c]
// 00687f7c  deca                 fmulp st(2)
// 00687f7e  d9c9                 fxch st(1)
// 00687f80  d9542420             fst dword ptr [esp + 0x20]
// 00687f84  d94528               fld dword ptr [ebp + 0x28]
// 00687f87  d95c2408             fstp dword ptr [esp + 8]
// 00687f8b  d94524               fld dword ptr [ebp + 0x24]
// 00687f8e  dec2                 faddp st(2)
// 00687f90  d9c9                 fxch st(1)
// 00687f92  d95c2404             fstp dword ptr [esp + 4]
// 00687f96  d84520               fadd dword ptr [ebp + 0x20]
// 00687f99  d91c24               fstp dword ptr [esp]
// 00687f9c  ffd0                 call eax
// 00687f9e  8b16                 mov edx, dword ptr [esi]
// 00687fa0  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00687fa6  57                   push edi
// 00687fa7  8bce                 mov ecx, esi
// 00687fa9  ffd0                 call eax
// 00687fab  d9442410             fld dword ptr [esp + 0x10]
// 00687faf  d9442414             fld dword ptr [esp + 0x14]
// 00687fb3  8d8c2498000000       lea ecx, [esp + 0x98]
// 00687fba  d99c2498000000       fstp dword ptr [esp + 0x98]
// 00687fc1  47                   inc edi
// 00687fc2  51                   push ecx
// 00687fc3  d99c24a0000000       fstp dword ptr [esp + 0xa0]
// 00687fca  d9ee                 fldz 
// 00687fcc  d99c24a4000000       fstp dword ptr [esp + 0xa4]
// 00687fd3  e9ff000000           jmp 0x6880d7
// 00687fd8  8b542410             mov edx, dword ptr [esp + 0x10]
// 00687fdc  83c2fe               add edx, -2
// 00687fdf  05f4000000           add eax, 0xf4
// 00687fe4  52                   push edx
// 00687fe5  89442418             mov dword ptr [esp + 0x18], eax
// 00687fe9  e8924f0000           call 0x68cf80
// 00687fee  50                   push eax
// 00687fef  8b442418             mov eax, dword ptr [esp + 0x18]
// 00687ff3  8b10                 mov edx, dword ptr [eax]
// 00687ff5  8bce                 mov ecx, esi
// 00687ff7  ffd2                 call edx
// 00687ff9  8b06                 mov eax, dword ptr [esi]
// 00687ffb  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00688001  57                   push edi
// 00688002  8bce                 mov ecx, esi
// 00688004  ffd2                 call edx
// 00688006  8b06                 mov eax, dword ptr [esi]
// 00688008  05f4000000           add eax, 0xf4
// 0068800d  89442414             mov dword ptr [esp + 0x14], eax
// 00688011  8b442410             mov eax, dword ptr [esp + 0x10]
// 00688015  48                   dec eax
// 00688016  50                   push eax
// 00688017  8d4c2438             lea ecx, [esp + 0x38]
// 0068801b  47                   inc edi
// 0068801c  e85f4f0000           call 0x68cf80
// 00688021  8b542414             mov edx, dword ptr [esp + 0x14]
// 00688025  50                   push eax
// 00688026  8b02                 mov eax, dword ptr [edx]
// 00688028  8bce                 mov ecx, esi
// 0068802a  ffd0                 call eax
// 0068802c  8b16                 mov edx, dword ptr [esi]
// 0068802e  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00688034  57                   push edi
// 00688035  8bce                 mov ecx, esi
// 00688037  ffd0                 call eax
// 00688039  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 00688040  d9442418             fld dword ptr [esp + 0x18]
// 00688044  8b16                 mov edx, dword ptr [esi]
// 00688046  dcc9                 fmul st(1), st(0)
// 00688048  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0068804e  d9c9                 fxch st(1)
// 00688050  83ec0c               sub esp, 0xc
// 00688053  8bce                 mov ecx, esi
// 00688055  d954241c             fst dword ptr [esp + 0x1c]
// 00688059  47                   inc edi
// 0068805a  d9849c8c050000       fld dword ptr [esp + ebx*4 + 0x58c]
// 00688061  deca                 fmulp st(2)
// 00688063  d9c9                 fxch st(1)
// 00688065  d9542420             fst dword ptr [esp + 0x20]
// 00688069  d94528               fld dword ptr [ebp + 0x28]
// 0068806c  d95c2408             fstp dword ptr [esp + 8]
// 00688070  d94524               fld dword ptr [ebp + 0x24]
// 00688073  dec2                 faddp st(2)
// 00688075  d9c9                 fxch st(1)
// 00688077  d95c2404             fstp dword ptr [esp + 4]
// 0068807b  d84520               fadd dword ptr [ebp + 0x20]
// 0068807e  d91c24               fstp dword ptr [esp]
// 00688081  ffd0                 call eax
// 00688083  8b16                 mov edx, dword ptr [esi]
// 00688085  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068808b  57                   push edi
// 0068808c  8bce                 mov ecx, esi
// 0068808e  ffd0                 call eax
// 00688090  d9442410             fld dword ptr [esp + 0x10]
// 00688094  d9442414             fld dword ptr [esp + 0x14]
// 00688098  8d4c245c             lea ecx, [esp + 0x5c]
// 0068809c  d95c245c             fstp dword ptr [esp + 0x5c]
// 006880a0  47                   inc edi
// 006880a1  51                   push ecx
// 006880a2  d95c2464             fstp dword ptr [esp + 0x64]
// 006880a6  d9ee                 fldz 
// 006880a8  d95c2468             fstp dword ptr [esp + 0x68]
// 006880ac  eb29                 jmp 0x6880d7
// 006880ae  d9849c80050000       fld dword ptr [esp + ebx*4 + 0x580]
// 006880b5  8d542468             lea edx, [esp + 0x68]
// 006880b9  d9442418             fld dword ptr [esp + 0x18]
// 006880bd  52                   push edx
// 006880be  dcc9                 fmul st(1), st(0)
// 006880c0  d88c9cc4010000       fmul dword ptr [esp + ebx*4 + 0x1c4]
// 006880c7  d9c9                 fxch st(1)
// 006880c9  d95c246c             fstp dword ptr [esp + 0x6c]
// 006880cd  d95c2470             fstp dword ptr [esp + 0x70]
// 006880d1  d9ee                 fldz 
// 006880d3  d95c2474             fstp dword ptr [esp + 0x74]
// 006880d7  8d4c2438             lea ecx, [esp + 0x38]
// 006880db  e87061e5ff           call 0x4de250
// 006880e0  807d0400             cmp byte ptr [ebp + 4], 0
// 006880e4  7436                 je 0x68811c
// 006880e6  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 006880ed  8b06                 mov eax, dword ptr [esi]
// 006880ef  d944242c             fld dword ptr [esp + 0x2c]
// 006880f3  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 006880f9  dcc9                 fmul st(1), st(0)
// 006880fb  83ec08               sub esp, 8
// 006880fe  d905ac9b8100         fld dword ptr [0x819bac]
// 00688104  8bce                 mov ecx, esi
// 00688106  dcc2                 fadd st(2), st(0)
// 00688108  d9ca                 fxch st(2)
// 0068810a  d95c2404             fstp dword ptr [esp + 4]
// 0068810e  d88c9c88050000       fmul dword ptr [esp + ebx*4 + 0x588]
// 00688115  dec1                 faddp st(1)
// 00688117  d91c24               fstp dword ptr [esp]
// 0068811a  ffd2                 call edx
// 0068811c  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00688120  2b4c2440             sub ecx, dword ptr [esp + 0x40]
// 00688124  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00688129  f7e9                 imul ecx
// 0068812b  d1fa                 sar edx, 1
// 0068812d  8bc2                 mov eax, edx
// 0068812f  c1e81f               shr eax, 0x1f
// 00688132  03c2                 add eax, edx
// 00688134  89442410             mov dword ptr [esp + 0x10], eax
// 00688138  83f802               cmp eax, 2
// 0068813b  0f82e2010000         jb 0x688323
// 00688141  2501000080           and eax, 0x80000001
// 00688146  7905                 jns 0x68814d
// 00688148  48                   dec eax
// 00688149  83c8fe               or eax, 0xfffffffe
// 0068814c  40                   inc eax
// 0068814d  8b06                 mov eax, dword ptr [esi]
// 0068814f  8d4c2434             lea ecx, [esp + 0x34]
// 00688153  0f84e5000000         je 0x68823e
// 00688159  05f4000000           add eax, 0xf4
// 0068815e  89442414             mov dword ptr [esp + 0x14], eax
// 00688162  8b442410             mov eax, dword ptr [esp + 0x10]
// 00688166  48                   dec eax
// 00688167  50                   push eax
// 00688168  e8134e0000           call 0x68cf80
// 0068816d  8b542414             mov edx, dword ptr [esp + 0x14]
// 00688171  50                   push eax
// 00688172  8b02                 mov eax, dword ptr [edx]
// 00688174  8bce                 mov ecx, esi
// 00688176  ffd0                 call eax
// 00688178  8b16                 mov edx, dword ptr [esi]
// 0068817a  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00688180  57                   push edi
// 00688181  8bce                 mov ecx, esi
// 00688183  ffd0                 call eax
// 00688185  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00688189  8b06                 mov eax, dword ptr [esi]
// 0068818b  83c1fe               add ecx, -2
// 0068818e  05f4000000           add eax, 0xf4
// 00688193  51                   push ecx
// 00688194  8d4c2438             lea ecx, [esp + 0x38]
// 00688198  47                   inc edi
// 00688199  89442418             mov dword ptr [esp + 0x18], eax
// 0068819d  e8de4d0000           call 0x68cf80
// 006881a2  8b542414             mov edx, dword ptr [esp + 0x14]
// 006881a6  50                   push eax
// 006881a7  8b02                 mov eax, dword ptr [edx]
// 006881a9  8bce                 mov ecx, esi
// 006881ab  ffd0                 call eax
// 006881ad  8b16                 mov edx, dword ptr [esi]
// 006881af  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 006881b5  57                   push edi
// 006881b6  8bce                 mov ecx, esi
// 006881b8  ffd0                 call eax
// 006881ba  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 006881c1  d944241c             fld dword ptr [esp + 0x1c]
// 006881c5  8b16                 mov edx, dword ptr [esi]
// 006881c7  dcc9                 fmul st(1), st(0)
// 006881c9  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 006881cf  d9c9                 fxch st(1)
// 006881d1  83ec0c               sub esp, 0xc
// 006881d4  8bce                 mov ecx, esi
// 006881d6  d9542420             fst dword ptr [esp + 0x20]
// 006881da  47                   inc edi
// 006881db  d9849c8c050000       fld dword ptr [esp + ebx*4 + 0x58c]
// 006881e2  deca                 fmulp st(2)
// 006881e4  d9c9                 fxch st(1)
// 006881e6  d954241c             fst dword ptr [esp + 0x1c]
// 006881ea  d94528               fld dword ptr [ebp + 0x28]
// 006881ed  d95c2408             fstp dword ptr [esp + 8]
// 006881f1  d94524               fld dword ptr [ebp + 0x24]
// 006881f4  dec2                 faddp st(2)
// 006881f6  d9c9                 fxch st(1)
// 006881f8  d95c2404             fstp dword ptr [esp + 4]
// 006881fc  d84520               fadd dword ptr [ebp + 0x20]
// 006881ff  d91c24               fstp dword ptr [esp]
// 00688202  ffd0                 call eax
// 00688204  8b16                 mov edx, dword ptr [esi]
// 00688206  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068820c  57                   push edi
// 0068820d  8bce                 mov ecx, esi
// 0068820f  ffd0                 call eax
// 00688211  d9442414             fld dword ptr [esp + 0x14]
// 00688215  d9442410             fld dword ptr [esp + 0x10]
// 00688219  8d8c24d4000000       lea ecx, [esp + 0xd4]
// 00688220  d99c24d4000000       fstp dword ptr [esp + 0xd4]
// 00688227  47                   inc edi
// 00688228  51                   push ecx
// 00688229  d99c24dc000000       fstp dword ptr [esp + 0xdc]
// 00688230  d9ee                 fldz 
// 00688232  d99c24e0000000       fstp dword ptr [esp + 0xe0]
// 00688239  e9fc050000           jmp 0x68883a
// 0068823e  8b542410             mov edx, dword ptr [esp + 0x10]
// 00688242  83c2fe               add edx, -2
// 00688245  05f4000000           add eax, 0xf4
// 0068824a  52                   push edx
// 0068824b  89442418             mov dword ptr [esp + 0x18], eax
// 0068824f  e82c4d0000           call 0x68cf80
// 00688254  50                   push eax
// 00688255  8b442418             mov eax, dword ptr [esp + 0x18]
// 00688259  8b10                 mov edx, dword ptr [eax]
// 0068825b  8bce                 mov ecx, esi
// 0068825d  ffd2                 call edx
// 0068825f  8b06                 mov eax, dword ptr [esi]
// 00688261  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00688267  57                   push edi
// 00688268  8bce                 mov ecx, esi
// 0068826a  ffd2                 call edx
// 0068826c  8b06                 mov eax, dword ptr [esi]
// 0068826e  05f4000000           add eax, 0xf4
// 00688273  89442414             mov dword ptr [esp + 0x14], eax
// 00688277  8b442410             mov eax, dword ptr [esp + 0x10]
// 0068827b  48                   dec eax
// 0068827c  50                   push eax
// 0068827d  8d4c2438             lea ecx, [esp + 0x38]
// 00688281  47                   inc edi
// 00688282  e8f94c0000           call 0x68cf80
// 00688287  8b542414             mov edx, dword ptr [esp + 0x14]
// 0068828b  50                   push eax
// 0068828c  8b02                 mov eax, dword ptr [edx]
// 0068828e  8bce                 mov ecx, esi
// 00688290  ffd0                 call eax
// 00688292  8b16                 mov edx, dword ptr [esi]
// 00688294  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068829a  57                   push edi
// 0068829b  8bce                 mov ecx, esi
// 0068829d  ffd0                 call eax
// 0068829f  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 006882a6  d944241c             fld dword ptr [esp + 0x1c]
// 006882aa  8b16                 mov edx, dword ptr [esi]
// 006882ac  dcc9                 fmul st(1), st(0)
// 006882ae  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 006882b4  d9c9                 fxch st(1)
// 006882b6  83ec0c               sub esp, 0xc
// 006882b9  8bce                 mov ecx, esi
// 006882bb  d9542420             fst dword ptr [esp + 0x20]
// 006882bf  47                   inc edi
// 006882c0  d9849c8c050000       fld dword ptr [esp + ebx*4 + 0x58c]
// 006882c7  deca                 fmulp st(2)
// 006882c9  d9c9                 fxch st(1)
// 006882cb  d954241c             fst dword ptr [esp + 0x1c]
// 006882cf  d94528               fld dword ptr [ebp + 0x28]
// 006882d2  d95c2408             fstp dword ptr [esp + 8]
// 006882d6  d94524               fld dword ptr [ebp + 0x24]
// 006882d9  dec2                 faddp st(2)
// 006882db  d9c9                 fxch st(1)
// 006882dd  d95c2404             fstp dword ptr [esp + 4]
// 006882e1  d84520               fadd dword ptr [ebp + 0x20]
// 006882e4  d91c24               fstp dword ptr [esp]
// 006882e7  ffd0                 call eax
// 006882e9  8b16                 mov edx, dword ptr [esi]
// 006882eb  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 006882f1  57                   push edi
// 006882f2  8bce                 mov ecx, esi
// 006882f4  ffd0                 call eax
// 006882f6  d9442414             fld dword ptr [esp + 0x14]
// 006882fa  d9442410             fld dword ptr [esp + 0x10]
// 006882fe  8d8c2480000000       lea ecx, [esp + 0x80]
// 00688305  d99c2480000000       fstp dword ptr [esp + 0x80]
// 0068830c  47                   inc edi
// 0068830d  51                   push ecx
// 0068830e  d99c2488000000       fstp dword ptr [esp + 0x88]
// 00688315  d9ee                 fldz 
// 00688317  d99c248c000000       fstp dword ptr [esp + 0x8c]
// 0068831e  e917050000           jmp 0x68883a
// 00688323  d9849c80050000       fld dword ptr [esp + ebx*4 + 0x580]
// 0068832a  8d9424b0000000       lea edx, [esp + 0xb0]
// 00688331  d944241c             fld dword ptr [esp + 0x1c]
// 00688335  dcc9                 fmul st(1), st(0)
// 00688337  d88c9cc0010000       fmul dword ptr [esp + ebx*4 + 0x1c0]
// 0068833e  d9c9                 fxch st(1)
// 00688340  d99c24b0000000       fstp dword ptr [esp + 0xb0]
// 00688347  d99c24b4000000       fstp dword ptr [esp + 0xb4]
// 0068834e  d9ee                 fldz 
// 00688350  d99c24b8000000       fstp dword ptr [esp + 0xb8]
// 00688357  e9dd040000           jmp 0x688839
// 0068835c  807d0400             cmp byte ptr [ebp + 4], 0
// 00688360  7436                 je 0x688398
// 00688362  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 00688369  8b06                 mov eax, dword ptr [esi]
// 0068836b  d944242c             fld dword ptr [esp + 0x2c]
// 0068836f  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 00688375  dcc9                 fmul st(1), st(0)
// 00688377  83ec08               sub esp, 8
// 0068837a  d905ac9b8100         fld dword ptr [0x819bac]
// 00688380  8bce                 mov ecx, esi
// 00688382  dcc2                 fadd st(2), st(0)
// 00688384  d9ca                 fxch st(2)
// 00688386  d95c2404             fstp dword ptr [esp + 4]
// 0068838a  d88c9c88050000       fmul dword ptr [esp + ebx*4 + 0x588]
// 00688391  dec1                 faddp st(1)
// 00688393  d91c24               fstp dword ptr [esp]
// 00688396  ffd2                 call edx
// 00688398  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0068839c  2b4c2440             sub ecx, dword ptr [esp + 0x40]
// 006883a0  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006883a5  f7e9                 imul ecx
// 006883a7  d1fa                 sar edx, 1
// 006883a9  8bc2                 mov eax, edx
// 006883ab  c1e81f               shr eax, 0x1f
// 006883ae  03c2                 add eax, edx
// 006883b0  89442410             mov dword ptr [esp + 0x10], eax
// 006883b4  83f802               cmp eax, 2
// 006883b7  0f82d3010000         jb 0x688590
// 006883bd  2501000080           and eax, 0x80000001
// 006883c2  7905                 jns 0x6883c9
// 006883c4  48                   dec eax
// 006883c5  83c8fe               or eax, 0xfffffffe
// 006883c8  40                   inc eax
// 006883c9  8b06                 mov eax, dword ptr [esi]
// 006883cb  8d4c2434             lea ecx, [esp + 0x34]
// 006883cf  0f84d9000000         je 0x6884ae
// 006883d5  05f4000000           add eax, 0xf4
// 006883da  89442414             mov dword ptr [esp + 0x14], eax
// 006883de  8b442410             mov eax, dword ptr [esp + 0x10]
// 006883e2  48                   dec eax
// 006883e3  50                   push eax
// 006883e4  e8974b0000           call 0x68cf80
// 006883e9  8b542414             mov edx, dword ptr [esp + 0x14]
// 006883ed  50                   push eax
// 006883ee  8b02                 mov eax, dword ptr [edx]
// 006883f0  8bce                 mov ecx, esi
// 006883f2  ffd0                 call eax
// 006883f4  8b16                 mov edx, dword ptr [esi]
// 006883f6  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 006883fc  57                   push edi
// 006883fd  8bce                 mov ecx, esi
// 006883ff  ffd0                 call eax
// 00688401  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00688405  8b06                 mov eax, dword ptr [esi]
// 00688407  83c1fe               add ecx, -2
// 0068840a  05f4000000           add eax, 0xf4
// 0068840f  51                   push ecx
// 00688410  8d4c2438             lea ecx, [esp + 0x38]
// 00688414  47                   inc edi
// 00688415  89442418             mov dword ptr [esp + 0x18], eax
// 00688419  e8624b0000           call 0x68cf80
// 0068841e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00688422  50                   push eax
// 00688423  8b02                 mov eax, dword ptr [edx]
// 00688425  8bce                 mov ecx, esi
// 00688427  ffd0                 call eax
// 00688429  8b16                 mov edx, dword ptr [esi]
// 0068842b  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00688431  57                   push edi
// 00688432  8bce                 mov ecx, esi
// 00688434  ffd0                 call eax
// 00688436  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 0068843d  d944241c             fld dword ptr [esp + 0x1c]
// 00688441  8b16                 mov edx, dword ptr [esi]
// 00688443  dcc9                 fmul st(1), st(0)
// 00688445  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0068844b  d9c9                 fxch st(1)
// 0068844d  83ec0c               sub esp, 0xc
// 00688450  8bce                 mov ecx, esi
// 00688452  d9542420             fst dword ptr [esp + 0x20]
// 00688456  47                   inc edi
// 00688457  d9849c8c050000       fld dword ptr [esp + ebx*4 + 0x58c]
// 0068845e  deca                 fmulp st(2)
// 00688460  d9c9                 fxch st(1)
// 00688462  d954241c             fst dword ptr [esp + 0x1c]
// 00688466  d94528               fld dword ptr [ebp + 0x28]
// 00688469  d95c2408             fstp dword ptr [esp + 8]
// 0068846d  d94524               fld dword ptr [ebp + 0x24]
// 00688470  dec2                 faddp st(2)
// 00688472  d9c9                 fxch st(1)
// 00688474  d95c2404             fstp dword ptr [esp + 4]
// 00688478  d84520               fadd dword ptr [ebp + 0x20]
// 0068847b  d91c24               fstp dword ptr [esp]
// 0068847e  ffd0                 call eax
// 00688480  8b16                 mov edx, dword ptr [esi]
// 00688482  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00688488  57                   push edi
// 00688489  8bce                 mov ecx, esi
// 0068848b  ffd0                 call eax
// 0068848d  d9442414             fld dword ptr [esp + 0x14]
// 00688491  d9442410             fld dword ptr [esp + 0x10]
// 00688495  8d4c2450             lea ecx, [esp + 0x50]
// 00688499  d95c2450             fstp dword ptr [esp + 0x50]
// 0068849d  47                   inc edi
// 0068849e  51                   push ecx
// 0068849f  d95c2458             fstp dword ptr [esp + 0x58]
// 006884a3  d9ee                 fldz 
// 006884a5  d95c245c             fstp dword ptr [esp + 0x5c]
// 006884a9  e90e010000           jmp 0x6885bc
// 006884ae  8b542410             mov edx, dword ptr [esp + 0x10]
// 006884b2  83c2fe               add edx, -2
// 006884b5  05f4000000           add eax, 0xf4
// 006884ba  52                   push edx
// 006884bb  89442418             mov dword ptr [esp + 0x18], eax
// 006884bf  e8bc4a0000           call 0x68cf80
// 006884c4  50                   push eax
// 006884c5  8b442418             mov eax, dword ptr [esp + 0x18]
// 006884c9  8b10                 mov edx, dword ptr [eax]
// 006884cb  8bce                 mov ecx, esi
// 006884cd  ffd2                 call edx
// 006884cf  8b06                 mov eax, dword ptr [esi]
// 006884d1  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 006884d7  57                   push edi
// 006884d8  8bce                 mov ecx, esi
// 006884da  ffd2                 call edx
// 006884dc  8b06                 mov eax, dword ptr [esi]
// 006884de  05f4000000           add eax, 0xf4
// 006884e3  89442414             mov dword ptr [esp + 0x14], eax
// 006884e7  8b442410             mov eax, dword ptr [esp + 0x10]
// 006884eb  48                   dec eax
// 006884ec  50                   push eax
// 006884ed  8d4c2438             lea ecx, [esp + 0x38]
// 006884f1  47                   inc edi
// 006884f2  e8894a0000           call 0x68cf80
// 006884f7  8b542414             mov edx, dword ptr [esp + 0x14]
// 006884fb  50                   push eax
// 006884fc  8b02                 mov eax, dword ptr [edx]
// 006884fe  8bce                 mov ecx, esi
// 00688500  ffd0                 call eax
// 00688502  8b16                 mov edx, dword ptr [esi]
// 00688504  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068850a  57                   push edi
// 0068850b  8bce                 mov ecx, esi
// 0068850d  ffd0                 call eax
// 0068850f  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 00688516  d944241c             fld dword ptr [esp + 0x1c]
// 0068851a  8b16                 mov edx, dword ptr [esi]
// 0068851c  dcc9                 fmul st(1), st(0)
// 0068851e  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00688524  d9c9                 fxch st(1)
// 00688526  83ec0c               sub esp, 0xc
// 00688529  8bce                 mov ecx, esi
// 0068852b  d9542420             fst dword ptr [esp + 0x20]
// 0068852f  47                   inc edi
// 00688530  d9849c8c050000       fld dword ptr [esp + ebx*4 + 0x58c]
// 00688537  deca                 fmulp st(2)
// 00688539  d9c9                 fxch st(1)
// 0068853b  d954241c             fst dword ptr [esp + 0x1c]
// 0068853f  d94528               fld dword ptr [ebp + 0x28]
// 00688542  d95c2408             fstp dword ptr [esp + 8]
// 00688546  d94524               fld dword ptr [ebp + 0x24]
// 00688549  dec2                 faddp st(2)
// 0068854b  d9c9                 fxch st(1)
// 0068854d  d95c2404             fstp dword ptr [esp + 4]
// 00688551  d84520               fadd dword ptr [ebp + 0x20]
// 00688554  d91c24               fstp dword ptr [esp]
// 00688557  ffd0                 call eax
// 00688559  8b16                 mov edx, dword ptr [esi]
// 0068855b  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00688561  57                   push edi
// 00688562  8bce                 mov ecx, esi
// 00688564  ffd0                 call eax
// 00688566  d9442414             fld dword ptr [esp + 0x14]
// 0068856a  d9442410             fld dword ptr [esp + 0x10]
// 0068856e  8d8c24c8000000       lea ecx, [esp + 0xc8]
// 00688575  d99c24c8000000       fstp dword ptr [esp + 0xc8]
// 0068857c  47                   inc edi
// 0068857d  51                   push ecx
// 0068857e  d99c24d0000000       fstp dword ptr [esp + 0xd0]
// 00688585  d9ee                 fldz 
// 00688587  d99c24d4000000       fstp dword ptr [esp + 0xd4]
// 0068858e  eb2c                 jmp 0x6885bc
// 00688590  d9849c80050000       fld dword ptr [esp + ebx*4 + 0x580]
// 00688597  8d542474             lea edx, [esp + 0x74]
// 0068859b  d944241c             fld dword ptr [esp + 0x1c]
// 0068859f  52                   push edx
// 006885a0  dcc9                 fmul st(1), st(0)
// 006885a2  d88c9cc4010000       fmul dword ptr [esp + ebx*4 + 0x1c4]
// 006885a9  d9c9                 fxch st(1)
// 006885ab  d95c2478             fstp dword ptr [esp + 0x78]
// 006885af  d95c247c             fstp dword ptr [esp + 0x7c]
// 006885b3  d9ee                 fldz 
// 006885b5  d99c2480000000       fstp dword ptr [esp + 0x80]
// 006885bc  8d4c2438             lea ecx, [esp + 0x38]
// 006885c0  e88b5ce5ff           call 0x4de250
// 006885c5  807d0400             cmp byte ptr [ebp + 4], 0
// 006885c9  7436                 je 0x688601
// 006885cb  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 006885d2  8b06                 mov eax, dword ptr [esi]
// 006885d4  d9442420             fld dword ptr [esp + 0x20]
// 006885d8  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 006885de  dcc9                 fmul st(1), st(0)
// 006885e0  83ec08               sub esp, 8
// 006885e3  d905ac9b8100         fld dword ptr [0x819bac]
// 006885e9  8bce                 mov ecx, esi
// 006885eb  dcc2                 fadd st(2), st(0)
// 006885ed  d9ca                 fxch st(2)
// 006885ef  d95c2404             fstp dword ptr [esp + 4]
// 006885f3  d88c9c88050000       fmul dword ptr [esp + ebx*4 + 0x588]
// 006885fa  dec1                 faddp st(1)
// 006885fc  d91c24               fstp dword ptr [esp]
// 006885ff  ffd2                 call edx
// 00688601  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00688605  2b4c2440             sub ecx, dword ptr [esp + 0x40]
// 00688609  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068860e  f7e9                 imul ecx
// 00688610  d1fa                 sar edx, 1
// 00688612  8bc2                 mov eax, edx
// 00688614  c1e81f               shr eax, 0x1f
// 00688617  03c2                 add eax, edx
// 00688619  89442410             mov dword ptr [esp + 0x10], eax
// 0068861d  83f802               cmp eax, 2
// 00688620  0f82df010000         jb 0x688805
// 00688626  2501000080           and eax, 0x80000001
// 0068862b  7905                 jns 0x688632
// 0068862d  48                   dec eax
// 0068862e  83c8fe               or eax, 0xfffffffe
// 00688631  40                   inc eax
// 00688632  8b06                 mov eax, dword ptr [esi]
// 00688634  8d4c2434             lea ecx, [esp + 0x34]
// 00688638  0f84e5000000         je 0x688723
// 0068863e  05f4000000           add eax, 0xf4
// 00688643  89442414             mov dword ptr [esp + 0x14], eax
// 00688647  8b442410             mov eax, dword ptr [esp + 0x10]
// 0068864b  48                   dec eax
// 0068864c  50                   push eax
// 0068864d  e82e490000           call 0x68cf80
// 00688652  8b542414             mov edx, dword ptr [esp + 0x14]
// 00688656  50                   push eax
// 00688657  8b02                 mov eax, dword ptr [edx]
// 00688659  8bce                 mov ecx, esi
// 0068865b  ffd0                 call eax
// 0068865d  8b16                 mov edx, dword ptr [esi]
// 0068865f  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00688665  57                   push edi
// 00688666  8bce                 mov ecx, esi
// 00688668  ffd0                 call eax
// 0068866a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0068866e  8b06                 mov eax, dword ptr [esi]
// 00688670  83c1fe               add ecx, -2
// 00688673  05f4000000           add eax, 0xf4
// 00688678  51                   push ecx
// 00688679  8d4c2438             lea ecx, [esp + 0x38]
// 0068867d  47                   inc edi
// 0068867e  89442418             mov dword ptr [esp + 0x18], eax
// 00688682  e8f9480000           call 0x68cf80
// 00688687  8b542414             mov edx, dword ptr [esp + 0x14]
// 0068868b  50                   push eax
// 0068868c  8b02                 mov eax, dword ptr [edx]
// 0068868e  8bce                 mov ecx, esi
// 00688690  ffd0                 call eax
// 00688692  8b16                 mov edx, dword ptr [esi]
// 00688694  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068869a  57                   push edi
// 0068869b  8bce                 mov ecx, esi
// 0068869d  ffd0                 call eax
// 0068869f  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 006886a6  d9442418             fld dword ptr [esp + 0x18]
// 006886aa  8b16                 mov edx, dword ptr [esi]
// 006886ac  dcc9                 fmul st(1), st(0)
// 006886ae  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 006886b4  d9c9                 fxch st(1)
// 006886b6  83ec0c               sub esp, 0xc
// 006886b9  8bce                 mov ecx, esi
// 006886bb  d954241c             fst dword ptr [esp + 0x1c]
// 006886bf  47                   inc edi
// 006886c0  d9849c8c050000       fld dword ptr [esp + ebx*4 + 0x58c]
// 006886c7  deca                 fmulp st(2)
// 006886c9  d9c9                 fxch st(1)
// 006886cb  d9542420             fst dword ptr [esp + 0x20]
// 006886cf  d94528               fld dword ptr [ebp + 0x28]
// 006886d2  d95c2408             fstp dword ptr [esp + 8]
// 006886d6  d94524               fld dword ptr [ebp + 0x24]
// 006886d9  dec2                 faddp st(2)
// 006886db  d9c9                 fxch st(1)
// 006886dd  d95c2404             fstp dword ptr [esp + 4]
// 006886e1  d84520               fadd dword ptr [ebp + 0x20]
// 006886e4  d91c24               fstp dword ptr [esp]
// 006886e7  ffd0                 call eax
// 006886e9  8b16                 mov edx, dword ptr [esi]
// 006886eb  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 006886f1  57                   push edi
// 006886f2  8bce                 mov ecx, esi
// 006886f4  ffd0                 call eax
// 006886f6  d9442410             fld dword ptr [esp + 0x10]
// 006886fa  d9442414             fld dword ptr [esp + 0x14]
// 006886fe  8d8c248c000000       lea ecx, [esp + 0x8c]
// 00688705  d99c248c000000       fstp dword ptr [esp + 0x8c]
// 0068870c  47                   inc edi
// 0068870d  51                   push ecx
// 0068870e  d99c2494000000       fstp dword ptr [esp + 0x94]
// 00688715  d9ee                 fldz 
// 00688717  d99c2498000000       fstp dword ptr [esp + 0x98]
// 0068871e  e917010000           jmp 0x68883a
// 00688723  8b542410             mov edx, dword ptr [esp + 0x10]
// 00688727  83c2fe               add edx, -2
// 0068872a  05f4000000           add eax, 0xf4
// 0068872f  52                   push edx
// 00688730  89442418             mov dword ptr [esp + 0x18], eax
// 00688734  e847480000           call 0x68cf80
// 00688739  50                   push eax
// 0068873a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0068873e  8b10                 mov edx, dword ptr [eax]
// 00688740  8bce                 mov ecx, esi
// 00688742  ffd2                 call edx
// 00688744  8b06                 mov eax, dword ptr [esi]
// 00688746  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 0068874c  57                   push edi
// 0068874d  8bce                 mov ecx, esi
// 0068874f  ffd2                 call edx
// 00688751  8b06                 mov eax, dword ptr [esi]
// 00688753  05f4000000           add eax, 0xf4
// 00688758  89442414             mov dword ptr [esp + 0x14], eax
// 0068875c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00688760  48                   dec eax
// 00688761  50                   push eax
// 00688762  8d4c2438             lea ecx, [esp + 0x38]
// 00688766  47                   inc edi
// 00688767  e814480000           call 0x68cf80
// 0068876c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00688770  50                   push eax
// 00688771  8b02                 mov eax, dword ptr [edx]
// 00688773  8bce                 mov ecx, esi
// 00688775  ffd0                 call eax
// 00688777  8b16                 mov edx, dword ptr [esi]
// 00688779  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068877f  57                   push edi
// 00688780  8bce                 mov ecx, esi
// 00688782  ffd0                 call eax
// 00688784  d9849cc0010000       fld dword ptr [esp + ebx*4 + 0x1c0]
// 0068878b  d9442418             fld dword ptr [esp + 0x18]
// 0068878f  8b16                 mov edx, dword ptr [esi]
// 00688791  dcc9                 fmul st(1), st(0)
// 00688793  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00688799  d9c9                 fxch st(1)
// 0068879b  83ec0c               sub esp, 0xc
// 0068879e  8bce                 mov ecx, esi
// 006887a0  d954241c             fst dword ptr [esp + 0x1c]
// 006887a4  47                   inc edi
// 006887a5  d9849c8c050000       fld dword ptr [esp + ebx*4 + 0x58c]
// 006887ac  deca                 fmulp st(2)
// 006887ae  d9c9                 fxch st(1)
// 006887b0  d9542420             fst dword ptr [esp + 0x20]
// 006887b4  d94528               fld dword ptr [ebp + 0x28]
// 006887b7  d95c2408             fstp dword ptr [esp + 8]
// 006887bb  d94524               fld dword ptr [ebp + 0x24]
// 006887be  dec2                 faddp st(2)
// 006887c0  d9c9                 fxch st(1)
// 006887c2  d95c2404             fstp dword ptr [esp + 4]
// 006887c6  d84520               fadd dword ptr [ebp + 0x20]
// 006887c9  d91c24               fstp dword ptr [esp]
// 006887cc  ffd0                 call eax
// 006887ce  8b16                 mov edx, dword ptr [esi]
// 006887d0  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 006887d6  57                   push edi
// 006887d7  8bce                 mov ecx, esi
// 006887d9  ffd0                 call eax
// 006887db  d9442410             fld dword ptr [esp + 0x10]
// 006887df  d9442414             fld dword ptr [esp + 0x14]
// 006887e3  8d8c24a4000000       lea ecx, [esp + 0xa4]
// 006887ea  d99c24a4000000       fstp dword ptr [esp + 0xa4]
// 006887f1  47                   inc edi
// 006887f2  51                   push ecx
// 006887f3  d99c24ac000000       fstp dword ptr [esp + 0xac]
// 006887fa  d9ee                 fldz 
// 006887fc  d99c24b0000000       fstp dword ptr [esp + 0xb0]
// 00688803  eb35                 jmp 0x68883a
// 00688805  d9849c80050000       fld dword ptr [esp + ebx*4 + 0x580]
// 0068880c  8d9424bc000000       lea edx, [esp + 0xbc]
// 00688813  d9442418             fld dword ptr [esp + 0x18]
// 00688817  dcc9                 fmul st(1), st(0)
// 00688819  d88c9cc0010000       fmul dword ptr [esp + ebx*4 + 0x1c0]
// 00688820  d9c9                 fxch st(1)
// 00688822  d99c24bc000000       fstp dword ptr [esp + 0xbc]
// 00688829  d99c24c0000000       fstp dword ptr [esp + 0xc0]
// 00688830  d9ee                 fldz 
// 00688832  d99c24c4000000       fstp dword ptr [esp + 0xc4]
// 00688839  52                   push edx
// 0068883a  8d4c2438             lea ecx, [esp + 0x38]
// 0068883e  e80d5ae5ff           call 0x4de250
// 00688843  43                   inc ebx
// 00688844  3b9c2464090000       cmp ebx, dword ptr [esp + 0x964]
// 0068884b  0f8e1ff6ffff         jle 0x687e70
// 00688851  8b06                 mov eax, dword ptr [esi]
// 00688853  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 00688859  8bce                 mov ecx, esi
// 0068885b  ffd2                 call edx
// 0068885d  8b442440             mov eax, dword ptr [esp + 0x40]
// 00688861  33ff                 xor edi, edi
// 00688863  c7842448090000ffffffff mov dword ptr [esp + 0x948], 0xffffffff
// 0068886e  3bc7                 cmp eax, edi
// 00688870  7409                 je 0x68887b
// 00688872  50                   push eax
// 00688873  e8027e0100           call 0x6a067a
// 00688878  83c404               add esp, 4
// 0068887b  8b442434             mov eax, dword ptr [esp + 0x34]
// 0068887f  50                   push eax
// 00688880  897c2444             mov dword ptr [esp + 0x44], edi
// 00688884  897c2448             mov dword ptr [esp + 0x48], edi
// 00688888  897c244c             mov dword ptr [esp + 0x4c], edi
// 0068888c  e8e97d0100           call 0x6a067a
// 00688891  8b442450             mov eax, dword ptr [esp + 0x50]
// 00688895  83c404               add esp, 4
// 00688898  3b442428             cmp eax, dword ptr [esp + 0x28]
// 0068889c  89442410             mov dword ptr [esp + 0x10], eax
// 006888a0  0f8caaf4ffff         jl 0x687d50
// 006888a6  8bc6                 mov eax, esi
// 006888a8  e9ea090000           jmp 0x689297
// 006888ad  ddd9                 fstp st(1)
// 006888af  6816b78000           push 0x80b716
// 006888b4  ddd9                 fstp st(1)
// 006888b6  8d8c248c010000       lea ecx, [esp + 0x18c]
// 006888bd  ddd8                 fstp st(0)
// 006888bf  ff1558248000         call dword ptr [0x802458]
// 006888c5  8b16                 mov edx, dword ptr [esi]
// 006888c7  8b92e0000000         mov edx, dword ptr [edx + 0xe0]
// 006888cd  6a01                 push 1
// 006888cf  8d84248c010000       lea eax, [esp + 0x18c]
// 006888d6  50                   push eax
// 006888d7  8bce                 mov ecx, esi
// 006888d9  c784245009000003000000 mov dword ptr [esp + 0x950], 3
// 006888e4  ffd2                 call edx
// 006888e6  8d8c2488010000       lea ecx, [esp + 0x188]
// 006888ed  c7842448090000ffffffff mov dword ptr [esp + 0x948], 0xffffffff
// 006888f8  ff1568248000         call dword ptr [0x802468]
// 006888fe  d9ee                 fldz 
// 00688900  d85510               fcom dword ptr [ebp + 0x10]
// 00688903  8d4d10               lea ecx, [ebp + 0x10]
// 00688906  33db                 xor ebx, ebx
// 00688908  dfe0                 fnstsw ax
// 0068890a  f6c441               test ah, 0x41
// 0068890d  7a11                 jp 0x688920
// 0068890f  8b06                 mov eax, dword ptr [esi]
// 00688911  ddd8                 fstp st(0)
// 00688913  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00688919  51                   push ecx
// 0068891a  8bce                 mov ecx, esi
// 0068891c  ffd2                 call edx
// 0068891e  d9ee                 fldz 
// 00688920  837d0001             cmp dword ptr [ebp], 1
// 00688924  7738                 ja 0x68895e
// 00688926  8b06                 mov eax, dword ptr [esi]
// 00688928  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 0068892e  83ec0c               sub esp, 0xc
// 00688931  8bce                 mov ecx, esi
// 00688933  395d08               cmp dword ptr [ebp + 8], ebx
// 00688936  7511                 jne 0x688949
// 00688938  d9e8                 fld1 
// 0068893a  d95c2408             fstp dword ptr [esp + 8]
// 0068893e  d9542404             fst dword ptr [esp + 4]
// 00688942  d91c24               fstp dword ptr [esp]
// 00688945  ffd2                 call edx
// 00688947  eb17                 jmp 0x688960
// 00688949  d905b8c38100         fld dword ptr [0x81c3b8]
// 0068894f  d95c2408             fstp dword ptr [esp + 8]
// 00688953  d9542404             fst dword ptr [esp + 4]
// 00688957  d91c24               fstp dword ptr [esp]
// 0068895a  ffd2                 call edx
// 0068895c  eb02                 jmp 0x688960
// 0068895e  ddd8                 fstp st(0)
// 00688960  395c241c             cmp dword ptr [esp + 0x1c], ebx
// 00688964  895c2414             mov dword ptr [esp + 0x14], ebx
// 00688968  0f8e02010000         jle 0x688a70
// 0068896e  8bff                 mov edi, edi
// 00688970  8b442414             mov eax, dword ptr [esp + 0x14]
// 00688974  d9848480050000       fld dword ptr [esp + eax*4 + 0x580]
// 0068897b  33ff                 xor edi, edi
// 0068897d  39bc2468090000       cmp dword ptr [esp + 0x968], edi
// 00688984  d95c242c             fstp dword ptr [esp + 0x2c]
// 00688988  d98484c0010000       fld dword ptr [esp + eax*4 + 0x1c0]
// 0068898f  897c2410             mov dword ptr [esp + 0x10], edi
// 00688993  d95c2428             fstp dword ptr [esp + 0x28]
// 00688997  0f8cc0000000         jl 0x688a5d
// 0068899d  db842468090000       fild dword ptr [esp + 0x968]
// 006889a4  d95c2424             fstp dword ptr [esp + 0x24]
// 006889a8  eb06                 jmp 0x6889b0
// 006889aa  8d9b00000000         lea ebx, [ebx]
// 006889b0  db442410             fild dword ptr [esp + 0x10]
// 006889b4  8b06                 mov eax, dword ptr [esi]
// 006889b6  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 006889bc  83ec0c               sub esp, 0xc
// 006889bf  d8742430             fdiv dword ptr [esp + 0x30]
// 006889c3  8bce                 mov ecx, esi
// 006889c5  d84c243c             fmul dword ptr [esp + 0x3c]
// 006889c9  d8ac246c090000       fsubr dword ptr [esp + 0x96c]
// 006889d0  d9542424             fst dword ptr [esp + 0x24]
// 006889d4  d94528               fld dword ptr [ebp + 0x28]
// 006889d7  d95c2408             fstp dword ptr [esp + 8]
// 006889db  d9442434             fld dword ptr [esp + 0x34]
// 006889df  d8c9                 fmul st(1)
// 006889e1  d84524               fadd dword ptr [ebp + 0x24]
// 006889e4  d95c2404             fstp dword ptr [esp + 4]
// 006889e8  d84c2438             fmul dword ptr [esp + 0x38]
// 006889ec  d84520               fadd dword ptr [ebp + 0x20]
// 006889ef  d91c24               fstp dword ptr [esp]
// 006889f2  ffd2                 call edx
// 006889f4  8b06                 mov eax, dword ptr [esi]
// 006889f6  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 006889fc  53                   push ebx
// 006889fd  8bce                 mov ecx, esi
// 006889ff  ffd2                 call edx
// 00688a01  43                   inc ebx
// 00688a02  807d0400             cmp byte ptr [ebp + 4], 0
// 00688a06  7443                 je 0x688a4b
// 00688a08  d9442418             fld dword ptr [esp + 0x18]
// 00688a0c  8b442414             mov eax, dword ptr [esp + 0x14]
// 00688a10  d8b42460090000       fdiv dword ptr [esp + 0x960]
// 00688a17  8b16                 mov edx, dword ptr [esi]
// 00688a19  83ec08               sub esp, 8
// 00688a1c  8bce                 mov ecx, esi
// 00688a1e  d905ac9b8100         fld dword ptr [0x819bac]
// 00688a24  dcc9                 fmul st(1), st(0)
// 00688a26  d98484c8010000       fld dword ptr [esp + eax*4 + 0x1c8]
// 00688a2d  d8ca                 fmul st(2)
// 00688a2f  d8c1                 fadd st(1)
// 00688a31  d95c2404             fstp dword ptr [esp + 4]
// 00688a35  d9848488050000       fld dword ptr [esp + eax*4 + 0x588]
// 00688a3c  8b820c010000         mov eax, dword ptr [edx + 0x10c]
// 00688a42  deca                 fmulp st(2)
// 00688a44  dec1                 faddp st(1)
// 00688a46  d91c24               fstp dword ptr [esp]
// 00688a49  ffd0                 call eax
// 00688a4b  47                   inc edi
// 00688a4c  3bbc2468090000       cmp edi, dword ptr [esp + 0x968]
// 00688a53  897c2410             mov dword ptr [esp + 0x10], edi
// 00688a57  0f8e53ffffff         jle 0x6889b0
// 00688a5d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00688a61  40                   inc eax
// 00688a62  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 00688a66  89442414             mov dword ptr [esp + 0x14], eax
// 00688a6a  0f8c00ffffff         jl 0x688970
// 00688a70  8b16                 mov edx, dword ptr [esi]
// 00688a72  8b8228010000         mov eax, dword ptr [edx + 0x128]
// 00688a78  8bce                 mov ecx, esi
// 00688a7a  ffd0                 call eax
// 00688a7c  8bc6                 mov eax, esi
// 00688a7e  e914080000           jmp 0x689297
// 00688a83  ddda                 fstp st(2)
// 00688a85  ddd9                 fstp st(1)
// 00688a87  d894245c090000       fcom dword ptr [esp + 0x95c]
// 00688a8e  dfe0                 fnstsw ax
// 00688a90  f6c444               test ah, 0x44
// 00688a93  0f8a6c010000         jp 0x688c05
// 00688a99  6816b78000           push 0x80b716
// 00688a9e  ddd8                 fstp st(0)
// 00688aa0  8d8c2454010000       lea ecx, [esp + 0x154]
// 00688aa7  ff1558248000         call dword ptr [0x802458]
// 00688aad  8b16                 mov edx, dword ptr [esi]
// 00688aaf  8b92e0000000         mov edx, dword ptr [edx + 0xe0]
// 00688ab5  6a03                 push 3
// 00688ab7  8d842454010000       lea eax, [esp + 0x154]
// 00688abe  50                   push eax
// 00688abf  8bce                 mov ecx, esi
// 00688ac1  c784245009000004000000 mov dword ptr [esp + 0x950], 4
// 00688acc  ffd2                 call edx
// 00688ace  8d8c2450010000       lea ecx, [esp + 0x150]
// 00688ad5  c7842448090000ffffffff mov dword ptr [esp + 0x948], 0xffffffff
// 00688ae0  ff1568248000         call dword ptr [0x802468]
// 00688ae6  d9ee                 fldz 
// 00688ae8  d85510               fcom dword ptr [ebp + 0x10]
// 00688aeb  8d4d10               lea ecx, [ebp + 0x10]
// 00688aee  33db                 xor ebx, ebx
// 00688af0  dfe0                 fnstsw ax
// 00688af2  f6c441               test ah, 0x41
// 00688af5  7a11                 jp 0x688b08
// 00688af7  8b06                 mov eax, dword ptr [esi]
// 00688af9  ddd8                 fstp st(0)
// 00688afb  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00688b01  51                   push ecx
// 00688b02  8bce                 mov ecx, esi
// 00688b04  ffd2                 call edx
// 00688b06  d9ee                 fldz 
// 00688b08  837d0001             cmp dword ptr [ebp], 1
// 00688b0c  7738                 ja 0x688b46
// 00688b0e  8b06                 mov eax, dword ptr [esi]
// 00688b10  8b90f8000000         mov edx, dword ptr [eax + 0xf8]
// 00688b16  83ec0c               sub esp, 0xc
// 00688b19  8bce                 mov ecx, esi
// 00688b1b  395d08               cmp dword ptr [ebp + 8], ebx
// 00688b1e  7511                 jne 0x688b31
// 00688b20  d9e8                 fld1 
// 00688b22  d95c2408             fstp dword ptr [esp + 8]
// 00688b26  d9542404             fst dword ptr [esp + 4]
// 00688b2a  d91c24               fstp dword ptr [esp]
// 00688b2d  ffd2                 call edx
// 00688b2f  eb17                 jmp 0x688b48
// 00688b31  d905b8c38100         fld dword ptr [0x81c3b8]
// 00688b37  d95c2408             fstp dword ptr [esp + 8]
// 00688b3b  d9542404             fst dword ptr [esp + 4]
// 00688b3f  d91c24               fstp dword ptr [esp]
// 00688b42  ffd2                 call edx
// 00688b44  eb02                 jmp 0x688b48
// 00688b46  ddd8                 fstp st(0)
// 00688b48  33ff                 xor edi, edi
// 00688b4a  399c2464090000       cmp dword ptr [esp + 0x964], ebx
// 00688b51  0f8c9b000000         jl 0x688bf2
// 00688b57  eb07                 jmp 0x688b60
// 00688b59  8da42400000000       lea esp, [esp]
// 00688b60  d94528               fld dword ptr [ebp + 0x28]
// 00688b63  8b06                 mov eax, dword ptr [esi]
// 00688b65  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 00688b6b  83ec0c               sub esp, 0xc
// 00688b6e  d95c2408             fstp dword ptr [esp + 8]
// 00688b72  8bce                 mov ecx, esi
// 00688b74  d984bccc010000       fld dword ptr [esp + edi*4 + 0x1cc]
// 00688b7b  d9842468090000       fld dword ptr [esp + 0x968]
// 00688b82  dcc9                 fmul st(1), st(0)
// 00688b84  d9c9                 fxch st(1)
// 00688b86  d84524               fadd dword ptr [ebp + 0x24]
// 00688b89  d95c2404             fstp dword ptr [esp + 4]
// 00688b8d  d88cbc8c050000       fmul dword ptr [esp + edi*4 + 0x58c]
// 00688b94  d84520               fadd dword ptr [ebp + 0x20]
// 00688b97  d91c24               fstp dword ptr [esp]
// 00688b9a  ffd2                 call edx
// 00688b9c  8b06                 mov eax, dword ptr [esi]
// 00688b9e  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00688ba4  53                   push ebx
// 00688ba5  8bce                 mov ecx, esi
// 00688ba7  ffd2                 call edx
// 00688ba9  43                   inc ebx
// 00688baa  807d0400             cmp byte ptr [ebp + 4], 0
// 00688bae  7434                 je 0x688be4
// 00688bb0  d984bcc0010000       fld dword ptr [esp + edi*4 + 0x1c0]
// 00688bb7  8b06                 mov eax, dword ptr [esi]
// 00688bb9  d9e8                 fld1 
// 00688bbb  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 00688bc1  dcc1                 fadd st(1), st(0)
// 00688bc3  83ec08               sub esp, 8
// 00688bc6  d905ac9b8100         fld dword ptr [0x819bac]
// 00688bcc  8bce                 mov ecx, esi
// 00688bce  dcca                 fmul st(2), st(0)
// 00688bd0  d9ca                 fxch st(2)
// 00688bd2  d95c2404             fstp dword ptr [esp + 4]
// 00688bd6  d884bc88050000       fadd dword ptr [esp + edi*4 + 0x588]
// 00688bdd  dec9                 fmulp st(1)
// 00688bdf  d91c24               fstp dword ptr [esp]
// 00688be2  ffd2                 call edx
// 00688be4  47                   inc edi
// 00688be5  3bbc2464090000       cmp edi, dword ptr [esp + 0x964]
// 00688bec  0f8e6effffff         jle 0x688b60
// 00688bf2  8b06                 mov eax, dword ptr [esi]
// 00688bf4  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 00688bfa  8bce                 mov ecx, esi
// 00688bfc  ffd2                 call edx
// 00688bfe  8bc6                 mov eax, esi
// 00688c00  e992060000           jmp 0x689297
// 00688c05  3bfb                 cmp edi, ebx
// 00688c07  895c2410             mov dword ptr [esp + 0x10], ebx
// 00688c0b  0f8c74010000         jl 0x688d85
// 00688c11  db842468090000       fild dword ptr [esp + 0x968]
// 00688c18  d95c2424             fstp dword ptr [esp + 0x24]
// 00688c1c  eb09                 jmp 0x688c27
// 00688c1e  8bff                 mov edi, edi
// 00688c20  d9842460090000       fld dword ptr [esp + 0x960]
// 00688c27  807d0400             cmp byte ptr [ebp + 4], 0
// 00688c2b  db442410             fild dword ptr [esp + 0x10]
// 00688c2f  d8742424             fdiv dword ptr [esp + 0x24]
// 00688c33  d84c2430             fmul dword ptr [esp + 0x30]
// 00688c37  d8e9                 fsubr st(1)
// 00688c39  d9542418             fst dword ptr [esp + 0x18]
// 00688c3d  740e                 je 0x688c4d
// 00688c3f  def1                 fdivrp st(1)
// 00688c41  d80dac9b8100         fmul dword ptr [0x819bac]
// 00688c47  d95c2420             fstp dword ptr [esp + 0x20]
// 00688c4b  eb04                 jmp 0x688c51
// 00688c4d  ddd8                 fstp st(0)
// 00688c4f  ddd8                 fstp st(0)
// 00688c51  6816b78000           push 0x80b716
// 00688c56  8d8c24a8010000       lea ecx, [esp + 0x1a8]
// 00688c5d  ff1558248000         call dword ptr [0x802458]
// 00688c63  8b06                 mov eax, dword ptr [esi]
// 00688c65  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00688c6b  6a03                 push 3
// 00688c6d  8d8c24a8010000       lea ecx, [esp + 0x1a8]
// 00688c74  51                   push ecx
// 00688c75  8bce                 mov ecx, esi
// 00688c77  c784245009000005000000 mov dword ptr [esp + 0x950], 5
// 00688c82  ffd2                 call edx
// 00688c84  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 00688c8b  c7842448090000ffffffff mov dword ptr [esp + 0x948], 0xffffffff
// 00688c96  ff1568248000         call dword ptr [0x802468]
// 00688c9c  d9ee                 fldz 
// 00688c9e  d85d10               fcomp dword ptr [ebp + 0x10]
// 00688ca1  8d4d10               lea ecx, [ebp + 0x10]
// 00688ca4  33db                 xor ebx, ebx
// 00688ca6  dfe0                 fnstsw ax
// 00688ca8  f6c441               test ah, 0x41
// 00688cab  7a0d                 jp 0x688cba
// 00688cad  8b06                 mov eax, dword ptr [esi]
// 00688caf  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00688cb5  51                   push ecx
// 00688cb6  8bce                 mov ecx, esi
// 00688cb8  ffd2                 call edx
// 00688cba  33ff                 xor edi, edi
// 00688cbc  39bc2464090000       cmp dword ptr [esp + 0x964], edi
// 00688cc3  0f8c98000000         jl 0x688d61
// 00688cc9  8da42400000000       lea esp, [esp]
// 00688cd0  d94528               fld dword ptr [ebp + 0x28]
// 00688cd3  8b06                 mov eax, dword ptr [esi]
// 00688cd5  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 00688cdb  83ec0c               sub esp, 0xc
// 00688cde  d95c2408             fstp dword ptr [esp + 8]
// 00688ce2  8bce                 mov ecx, esi
// 00688ce4  d984bccc010000       fld dword ptr [esp + edi*4 + 0x1cc]
// 00688ceb  d9442424             fld dword ptr [esp + 0x24]
// 00688cef  dcc9                 fmul st(1), st(0)
// 00688cf1  d9c9                 fxch st(1)
// 00688cf3  d84524               fadd dword ptr [ebp + 0x24]
// 00688cf6  d95c2404             fstp dword ptr [esp + 4]
// 00688cfa  d88cbc8c050000       fmul dword ptr [esp + edi*4 + 0x58c]
// 00688d01  d84520               fadd dword ptr [ebp + 0x20]
// 00688d04  d91c24               fstp dword ptr [esp]
// 00688d07  ffd2                 call edx
// 00688d09  8b06                 mov eax, dword ptr [esi]
// 00688d0b  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 00688d11  53                   push ebx
// 00688d12  8bce                 mov ecx, esi
// 00688d14  ffd2                 call edx
// 00688d16  43                   inc ebx
// 00688d17  807d0400             cmp byte ptr [ebp + 4], 0
// 00688d1b  7436                 je 0x688d53
// 00688d1d  d984bcc0010000       fld dword ptr [esp + edi*4 + 0x1c0]
// 00688d24  8b06                 mov eax, dword ptr [esi]
// 00688d26  d9442420             fld dword ptr [esp + 0x20]
// 00688d2a  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 00688d30  dcc9                 fmul st(1), st(0)
// 00688d32  83ec08               sub esp, 8
// 00688d35  d905ac9b8100         fld dword ptr [0x819bac]
// 00688d3b  8bce                 mov ecx, esi
// 00688d3d  dcc2                 fadd st(2), st(0)
// 00688d3f  d9ca                 fxch st(2)
// 00688d41  d95c2404             fstp dword ptr [esp + 4]
// 00688d45  d88cbc88050000       fmul dword ptr [esp + edi*4 + 0x588]
// 00688d4c  dec1                 faddp st(1)
// 00688d4e  d91c24               fstp dword ptr [esp]
// 00688d51  ffd2                 call edx
// 00688d53  47                   inc edi
// 00688d54  3bbc2464090000       cmp edi, dword ptr [esp + 0x964]
// 00688d5b  0f8e6fffffff         jle 0x688cd0
// 00688d61  8b06                 mov eax, dword ptr [esi]
// 00688d63  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 00688d69  8bce                 mov ecx, esi
// 00688d6b  ffd2                 call edx
// 00688d6d  8b442410             mov eax, dword ptr [esp + 0x10]
// 00688d71  40                   inc eax
// 00688d72  3b842468090000       cmp eax, dword ptr [esp + 0x968]
// 00688d79  89442410             mov dword ptr [esp + 0x10], eax
// 00688d7d  0f8e9dfeffff         jle 0x688c20
// 00688d83  eb02                 jmp 0x688d87
// 00688d85  ddd8                 fstp st(0)
// 00688d87  33db                 xor ebx, ebx
// 00688d89  395c241c             cmp dword ptr [esp + 0x1c], ebx
// 00688d8d  0f8ef4040000         jle 0x689287
// 00688d93  eb0b                 jmp 0x688da0
// 00688d95  8da42400000000       lea esp, [esp]
// 00688d9c  8d642400             lea esp, [esp]
// 00688da0  d9849c80050000       fld dword ptr [esp + ebx*4 + 0x580]
// 00688da7  6816b78000           push 0x80b716
// 00688dac  d95c2430             fstp dword ptr [esp + 0x30]
// 00688db0  8d8c2400010000       lea ecx, [esp + 0x100]
// 00688db7  d9849cc4010000       fld dword ptr [esp + ebx*4 + 0x1c4]
// 00688dbe  d95c242c             fstp dword ptr [esp + 0x2c]
// 00688dc2  ff1558248000         call dword ptr [0x802458]
// 00688dc8  8b06                 mov eax, dword ptr [esi]
// 00688dca  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00688dd0  6a03                 push 3
// 00688dd2  8d8c2400010000       lea ecx, [esp + 0x100]
// 00688dd9  51                   push ecx
// 00688dda  8bce                 mov ecx, esi
// 00688ddc  c784245009000006000000 mov dword ptr [esp + 0x950], 6
// 00688de7  ffd2                 call edx
// 00688de9  8d8c24fc000000       lea ecx, [esp + 0xfc]
// 00688df0  c7842448090000ffffffff mov dword ptr [esp + 0x948], 0xffffffff
// 00688dfb  ff1568248000         call dword ptr [0x802468]
// 00688e01  d9ee                 fldz 
// 00688e03  d85d10               fcomp dword ptr [ebp + 0x10]
// 00688e06  33ff                 xor edi, edi
// 00688e08  dfe0                 fnstsw ax
// 00688e0a  f6c441               test ah, 0x41
// 00688e0d  7a10                 jp 0x688e1f
// 00688e0f  8b16                 mov edx, dword ptr [esi]
// 00688e11  8d4510               lea eax, [ebp + 0x10]
// 00688e14  50                   push eax
// 00688e15  8b8218010000         mov eax, dword ptr [edx + 0x118]
// 00688e1b  8bce                 mov ecx, esi
// 00688e1d  ffd0                 call eax
// 00688e1f  83bc246809000000     cmp dword ptr [esp + 0x968], 0
// 00688e27  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00688e2f  0f8cb8000000         jl 0x688eed
// 00688e35  db842468090000       fild dword ptr [esp + 0x968]
// 00688e3c  d95c2424             fstp dword ptr [esp + 0x24]
// 00688e40  db442410             fild dword ptr [esp + 0x10]
// 00688e44  8b16                 mov edx, dword ptr [esi]
// 00688e46  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00688e4c  83ec0c               sub esp, 0xc
// 00688e4f  d8742430             fdiv dword ptr [esp + 0x30]
// 00688e53  8bce                 mov ecx, esi
// 00688e55  d84c243c             fmul dword ptr [esp + 0x3c]
// 00688e59  d8ac246c090000       fsubr dword ptr [esp + 0x96c]
// 00688e60  d9542424             fst dword ptr [esp + 0x24]
// 00688e64  d94528               fld dword ptr [ebp + 0x28]
// 00688e67  d95c2408             fstp dword ptr [esp + 8]
// 00688e6b  d9442434             fld dword ptr [esp + 0x34]
// 00688e6f  d8c9                 fmul st(1)
// 00688e71  d84524               fadd dword ptr [ebp + 0x24]
// 00688e74  d95c2404             fstp dword ptr [esp + 4]
// 00688e78  d84c2438             fmul dword ptr [esp + 0x38]
// 00688e7c  d84520               fadd dword ptr [ebp + 0x20]
// 00688e7f  d91c24               fstp dword ptr [esp]
// 00688e82  ffd0                 call eax
// 00688e84  8b16                 mov edx, dword ptr [esi]
// 00688e86  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 00688e8c  57                   push edi
// 00688e8d  8bce                 mov ecx, esi
// 00688e8f  ffd0                 call eax
// 00688e91  47                   inc edi
// 00688e92  807d0400             cmp byte ptr [ebp + 4], 0
// 00688e96  743f                 je 0x688ed7
// 00688e98  d9442418             fld dword ptr [esp + 0x18]
// 00688e9c  8b16                 mov edx, dword ptr [esi]
// 00688e9e  d8b42460090000       fdiv dword ptr [esp + 0x960]
// 00688ea5  8b820c010000         mov eax, dword ptr [edx + 0x10c]
// 00688eab  83ec08               sub esp, 8
// 00688eae  8bce                 mov ecx, esi
// 00688eb0  d905ac9b8100         fld dword ptr [0x819bac]
// 00688eb6  dcc9                 fmul st(1), st(0)
// 00688eb8  d9849cc8010000       fld dword ptr [esp + ebx*4 + 0x1c8]
// 00688ebf  d8ca                 fmul st(2)
// 00688ec1  d8c1                 fadd st(1)
// 00688ec3  d95c2404             fstp dword ptr [esp + 4]
// 00688ec7  d9849c88050000       fld dword ptr [esp + ebx*4 + 0x588]
// 00688ece  deca                 fmulp st(2)
// 00688ed0  dec1                 faddp st(1)
// 00688ed2  d91c24               fstp dword ptr [esp]
// 00688ed5  ffd0                 call eax
// 00688ed7  8b442410             mov eax, dword ptr [esp + 0x10]
// 00688edb  40                   inc eax
// 00688edc  3b842468090000       cmp eax, dword ptr [esp + 0x968]
// 00688ee3  89442410             mov dword ptr [esp + 0x10], eax
// 00688ee7  0f8e53ffffff         jle 0x688e40
// 00688eed  8b16                 mov edx, dword ptr [esi]
// 00688eef  8b8228010000         mov eax, dword ptr [edx + 0x128]
// 00688ef5  8bce                 mov ecx, esi
// 00688ef7  ffd0                 call eax
// 00688ef9  43                   inc ebx
// 00688efa  3b5c241c             cmp ebx, dword ptr [esp + 0x1c]
// 00688efe  0f8c9cfeffff         jl 0x688da0
// 00688f04  8bc6                 mov eax, esi
// 00688f06  e98c030000           jmp 0x689297
// 00688f0b  d8da                 fcomp st(2)
// 00688f0d  dfe0                 fnstsw ax
// 00688f0f  ddd9                 fstp st(1)
// 00688f11  f6c441               test ah, 0x41
// 00688f14  0f85cb010000         jne 0x6890e5
// 00688f1a  33db                 xor ebx, ebx
// 00688f1c  399c2464090000       cmp dword ptr [esp + 0x964], ebx
// 00688f23  0f8cbc010000         jl 0x6890e5
// 00688f29  ddd8                 fstp st(0)
// 00688f2b  d9849c80050000       fld dword ptr [esp + ebx*4 + 0x580]
// 00688f32  6816b78000           push 0x80b716
// 00688f37  d95c2430             fstp dword ptr [esp + 0x30]
// 00688f3b  8d8c2438010000       lea ecx, [esp + 0x138]
// 00688f42  d9849cc4010000       fld dword ptr [esp + ebx*4 + 0x1c4]
// 00688f49  d95c242c             fstp dword ptr [esp + 0x2c]
// 00688f4d  ff1558248000         call dword ptr [0x802458]
// 00688f53  8b16                 mov edx, dword ptr [esi]
// 00688f55  8b92e0000000         mov edx, dword ptr [edx + 0xe0]
// 00688f5b  6a03                 push 3
// 00688f5d  8d842438010000       lea eax, [esp + 0x138]
// 00688f64  50                   push eax
// 00688f65  8bce                 mov ecx, esi
// 00688f67  c784245009000007000000 mov dword ptr [esp + 0x950], 7
// 00688f72  ffd2                 call edx
// 00688f74  8d8c2434010000       lea ecx, [esp + 0x134]
// 00688f7b  c7842448090000ffffffff mov dword ptr [esp + 0x948], 0xffffffff
// 00688f86  ff1568248000         call dword ptr [0x802468]
// 00688f8c  d9ee                 fldz 
// 00688f8e  d85510               fcom dword ptr [ebp + 0x10]
// 00688f91  33ff                 xor edi, edi
// 00688f93  dfe0                 fnstsw ax
// 00688f95  f6c441               test ah, 0x41
// 00688f98  7a14                 jp 0x688fae
// 00688f9a  8b16                 mov edx, dword ptr [esi]
// 00688f9c  ddd8                 fstp st(0)
// 00688f9e  8d4510               lea eax, [ebp + 0x10]
// 00688fa1  50                   push eax
// 00688fa2  8b8218010000         mov eax, dword ptr [edx + 0x118]
// 00688fa8  8bce                 mov ecx, esi
// 00688faa  ffd0                 call eax
// 00688fac  d9ee                 fldz 
// 00688fae  837d0001             cmp dword ptr [ebp], 1
// 00688fb2  7739                 ja 0x688fed
// 00688fb4  8b16                 mov edx, dword ptr [esi]
// 00688fb6  8b82f8000000         mov eax, dword ptr [edx + 0xf8]
// 00688fbc  83ec0c               sub esp, 0xc
// 00688fbf  837d0800             cmp dword ptr [ebp + 8], 0
// 00688fc3  8bce                 mov ecx, esi
// 00688fc5  7511                 jne 0x688fd8
// 00688fc7  d9e8                 fld1 
// 00688fc9  d95c2408             fstp dword ptr [esp + 8]
// 00688fcd  d9542404             fst dword ptr [esp + 4]
// 00688fd1  d91c24               fstp dword ptr [esp]
// 00688fd4  ffd0                 call eax
// 00688fd6  eb17                 jmp 0x688fef
// 00688fd8  d905b8c38100         fld dword ptr [0x81c3b8]
// 00688fde  d95c2408             fstp dword ptr [esp + 8]
// 00688fe2  d9542404             fst dword ptr [esp + 4]
// 00688fe6  d91c24               fstp dword ptr [esp]
// 00688fe9  ffd0                 call eax
// 00688feb  eb02                 jmp 0x688fef
// 00688fed  ddd8                 fstp st(0)
// 00688fef  83bc246809000000     cmp dword ptr [esp + 0x968], 0
// 00688ff7  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00688fff  0f8cbc000000         jl 0x6890c1
// 00689005  db842468090000       fild dword ptr [esp + 0x968]
// 0068900c  d95c2424             fstp dword ptr [esp + 0x24]
// 00689010  db442410             fild dword ptr [esp + 0x10]
// 00689014  8b16                 mov edx, dword ptr [esi]
// 00689016  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0068901c  83ec0c               sub esp, 0xc
// 0068901f  d8742430             fdiv dword ptr [esp + 0x30]
// 00689023  8bce                 mov ecx, esi
// 00689025  d84c243c             fmul dword ptr [esp + 0x3c]
// 00689029  d8ac246c090000       fsubr dword ptr [esp + 0x96c]
// 00689030  d9542424             fst dword ptr [esp + 0x24]
// 00689034  d94528               fld dword ptr [ebp + 0x28]
// 00689037  d95c2408             fstp dword ptr [esp + 8]
// 0068903b  d9442434             fld dword ptr [esp + 0x34]
// 0068903f  d8c9                 fmul st(1)
// 00689041  d84524               fadd dword ptr [ebp + 0x24]
// 00689044  d95c2404             fstp dword ptr [esp + 4]
// 00689048  d84c2438             fmul dword ptr [esp + 0x38]
// 0068904c  d84520               fadd dword ptr [ebp + 0x20]
// 0068904f  d91c24               fstp dword ptr [esp]
// 00689052  ffd0                 call eax
// 00689054  8b16                 mov edx, dword ptr [esi]
// 00689056  8b821c010000         mov eax, dword ptr [edx + 0x11c]
// 0068905c  57                   push edi
// 0068905d  8bce                 mov ecx, esi
// 0068905f  ffd0                 call eax
// 00689061  47                   inc edi
// 00689062  807d0400             cmp byte ptr [ebp + 4], 0
// 00689066  7443                 je 0x6890ab
// 00689068  d9442418             fld dword ptr [esp + 0x18]
// 0068906c  8b16                 mov edx, dword ptr [esi]
// 0068906e  d8b42460090000       fdiv dword ptr [esp + 0x960]
// 00689075  8b820c010000         mov eax, dword ptr [edx + 0x10c]
// 0068907b  83ec08               sub esp, 8
// 0068907e  8bce                 mov ecx, esi
// 00689080  d905ac9b8100         fld dword ptr [0x819bac]
// 00689086  dcc9                 fmul st(1), st(0)
// 00689088  d9c9                 fxch st(1)
// 0068908a  d9542428             fst dword ptr [esp + 0x28]
// 0068908e  d9849cc8010000       fld dword ptr [esp + ebx*4 + 0x1c8]
// 00689095  d8c9                 fmul st(1)
// 00689097  d8c2                 fadd st(2)
// 00689099  d95c2404             fstp dword ptr [esp + 4]
// 0068909d  d88c9c88050000       fmul dword ptr [esp + ebx*4 + 0x588]
// 006890a4  dec1                 faddp st(1)
// 006890a6  d91c24               fstp dword ptr [esp]
// 006890a9  ffd0                 call eax
// 006890ab  8b442410             mov eax, dword ptr [esp + 0x10]
// 006890af  40                   inc eax
// 006890b0  3b842468090000       cmp eax, dword ptr [esp + 0x968]
// 006890b7  89442410             mov dword ptr [esp + 0x10], eax
// 006890bb  0f8e4fffffff         jle 0x689010
// 006890c1  8b16                 mov edx, dword ptr [esi]
// 006890c3  8b8228010000         mov eax, dword ptr [edx + 0x128]
// 006890c9  8bce                 mov ecx, esi
// 006890cb  ffd0                 call eax
// 006890cd  8b842464090000       mov eax, dword ptr [esp + 0x964]
// 006890d4  03d8                 add ebx, eax
// 006890d6  3bd8                 cmp ebx, eax
// 006890d8  0f8e4dfeffff         jle 0x688f2b
// 006890de  d9842460090000       fld dword ptr [esp + 0x960]
// 006890e5  83bc246809000000     cmp dword ptr [esp + 0x968], 0
// 006890ed  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006890f5  0f8c8a010000         jl 0x689285
// 006890fb  db842468090000       fild dword ptr [esp + 0x968]
// 00689102  d95c2424             fstp dword ptr [esp + 0x24]
// 00689106  807d0400             cmp byte ptr [ebp + 4], 0
// 0068910a  db442410             fild dword ptr [esp + 0x10]
// 0068910e  d8742424             fdiv dword ptr [esp + 0x24]
// 00689112  d84c2430             fmul dword ptr [esp + 0x30]
// 00689116  d8e9                 fsubr st(1)
// 00689118  d9542418             fst dword ptr [esp + 0x18]
// 0068911c  740e                 je 0x68912c
// 0068911e  def1                 fdivrp st(1)
// 00689120  d80dac9b8100         fmul dword ptr [0x819bac]
// 00689126  d95c2420             fstp dword ptr [esp + 0x20]
// 0068912a  eb04                 jmp 0x689130
// 0068912c  ddd8                 fstp st(0)
// 0068912e  ddd8                 fstp st(0)
// 00689130  6816b78000           push 0x80b716
// 00689135  8d8c2470010000       lea ecx, [esp + 0x170]
// 0068913c  ff1558248000         call dword ptr [0x802458]
// 00689142  8b16                 mov edx, dword ptr [esi]
// 00689144  8b92e0000000         mov edx, dword ptr [edx + 0xe0]
// 0068914a  6a03                 push 3
// 0068914c  8d842470010000       lea eax, [esp + 0x170]
// 00689153  50                   push eax
// 00689154  8bce                 mov ecx, esi
// 00689156  c784245009000008000000 mov dword ptr [esp + 0x950], 8
// 00689161  ffd2                 call edx
// 00689163  8d8c246c010000       lea ecx, [esp + 0x16c]
// 0068916a  c7842448090000ffffffff mov dword ptr [esp + 0x948], 0xffffffff
// 00689175  ff1568248000         call dword ptr [0x802468]
// 0068917b  d9ee                 fldz 
// 0068917d  d85d10               fcomp dword ptr [ebp + 0x10]
// 00689180  8d4d10               lea ecx, [ebp + 0x10]
// 00689183  33db                 xor ebx, ebx
// 00689185  dfe0                 fnstsw ax
// 00689187  f6c441               test ah, 0x41
// 0068918a  7a0d                 jp 0x689199
// 0068918c  8b06                 mov eax, dword ptr [esi]
// 0068918e  8b9018010000         mov edx, dword ptr [eax + 0x118]
// 00689194  51                   push ecx
// 00689195  8bce                 mov ecx, esi
// 00689197  ffd2                 call edx
// 00689199  33ff                 xor edi, edi
// 0068919b  39bc2464090000       cmp dword ptr [esp + 0x964], edi
// 006891a2  0f8c99000000         jl 0x689241
// 006891a8  eb06                 jmp 0x6891b0
// 006891aa  8d9b00000000         lea ebx, [ebx]
// 006891b0  d94528               fld dword ptr [ebp + 0x28]
// 006891b3  8b06                 mov eax, dword ptr [esi]
// 006891b5  8b90f0000000         mov edx, dword ptr [eax + 0xf0]
// 006891bb  83ec0c               sub esp, 0xc
// 006891be  d95c2408             fstp dword ptr [esp + 8]
// 006891c2  8bce                 mov ecx, esi
// 006891c4  d984bccc010000       fld dword ptr [esp + edi*4 + 0x1cc]
// 006891cb  d9442424             fld dword ptr [esp + 0x24]
// 006891cf  dcc9                 fmul st(1), st(0)
// 006891d1  d9c9                 fxch st(1)
// 006891d3  d84524               fadd dword ptr [ebp + 0x24]
// 006891d6  d95c2404             fstp dword ptr [esp + 4]
// 006891da  d88cbc8c050000       fmul dword ptr [esp + edi*4 + 0x58c]
// 006891e1  d84520               fadd dword ptr [ebp + 0x20]
// 006891e4  d91c24               fstp dword ptr [esp]
// 006891e7  ffd2                 call edx
// 006891e9  8b06                 mov eax, dword ptr [esi]
// 006891eb  8b901c010000         mov edx, dword ptr [eax + 0x11c]
// 006891f1  53                   push ebx
// 006891f2  8bce                 mov ecx, esi
// 006891f4  ffd2                 call edx
// 006891f6  43                   inc ebx
// 006891f7  807d0400             cmp byte ptr [ebp + 4], 0
// 006891fb  7436                 je 0x689233
// 006891fd  d984bcc0010000       fld dword ptr [esp + edi*4 + 0x1c0]
// 00689204  8b06                 mov eax, dword ptr [esi]
// 00689206  d9442420             fld dword ptr [esp + 0x20]
// 0068920a  8b900c010000         mov edx, dword ptr [eax + 0x10c]
// 00689210  dcc9                 fmul st(1), st(0)
// 00689212  83ec08               sub esp, 8
// 00689215  d905ac9b8100         fld dword ptr [0x819bac]
// 0068921b  8bce                 mov ecx, esi
// 0068921d  dcc2                 fadd st(2), st(0)
// 0068921f  d9ca                 fxch st(2)
// 00689221  d95c2404             fstp dword ptr [esp + 4]
// 00689225  d88cbc88050000       fmul dword ptr [esp + edi*4 + 0x588]
// 0068922c  dec1                 faddp st(1)
// 0068922e  d91c24               fstp dword ptr [esp]
// 00689231  ffd2                 call edx
// 00689233  47                   inc edi
// 00689234  3bbc2464090000       cmp edi, dword ptr [esp + 0x964]
// 0068923b  0f8e6fffffff         jle 0x6891b0
// 00689241  8b06                 mov eax, dword ptr [esi]
// 00689243  8b9028010000         mov edx, dword ptr [eax + 0x128]
// 00689249  8bce                 mov ecx, esi
// 0068924b  ffd2                 call edx
// 0068924d  d9842460090000       fld dword ptr [esp + 0x960]
// 00689254  d894245c090000       fcom dword ptr [esp + 0x95c]
// 0068925b  dfe0                 fnstsw ax
// 0068925d  f6c444               test ah, 0x44
// 00689260  7b23                 jnp 0x689285
// 00689262  8b442410             mov eax, dword ptr [esp + 0x10]
// 00689266  8b8c2468090000       mov ecx, dword ptr [esp + 0x968]
// 0068926d  03c1                 add eax, ecx
// 0068926f  3bc1                 cmp eax, ecx
// 00689271  89442410             mov dword ptr [esp + 0x10], eax
// 00689275  0f8e8bfeffff         jle 0x689106
// 0068927b  ddd8                 fstp st(0)
// 0068927d  8bc6                 mov eax, esi
// 0068927f  eb16                 jmp 0x689297
// 00689281  ddd9                 fstp st(1)
// 00689283  ddd9                 fstp st(1)
// 00689285  ddd8                 fstp st(0)
// 00689287  8bc6                 mov eax, esi
// 00689289  eb0c                 jmp 0x689297
// 0068928b  ddd9                 fstp st(1)
// 0068928d  eb04                 jmp 0x689293
// 0068928f  ddda                 fstp st(2)
// 00689291  ddd8                 fstp st(0)
// 00689293  ddd8                 fstp st(0)
// 00689295  33c0                 xor eax, eax
// 00689297  8b8c2440090000       mov ecx, dword ptr [esp + 0x940]
// 0068929e  5f                   pop edi
// 0068929f  5e                   pop esi
// 006892a0  5d                   pop ebp
// 006892a1  5b                   pop ebx
// 006892a2  64890d00000000       mov dword ptr fs:[0], ecx
// 006892a9  81c43c090000         add esp, 0x93c
// 006892af  c22400               ret 0x24

// from server: 99% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// Genuine Ogre 1.4.5 consumer interfaces, reduced to the virtual declarations
// used to establish primary vtable dispatch. Existing pointers only; no object
// of these interface views is constructed and no whole-owner size is claimed.
#include <string>
#include <vector>
#include <cmath>
#include <stddef.h>
namespace Ogre {
typedef float Real;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long ulong;
typedef std::string String;
class Light; class EdgeData; class AxisAlignedBox; class Vector2; class Vector4;
class SceneManager; class ManualObject; class Camera; class Node; class SceneNode;
class RenderQueue; class UserDefinedObject; class MovableObjectFactory; class Any;
class Matrix4; class Sphere; class ShadowRenderable; class HardwareIndexBufferSharedPtr;
class HardwareVertexBufferSharedPtr; class AnimableValue; class Entity;
class RenderQueueGroup; class Pass; class Renderable; class RenderablePass;
class Viewport; class RenderQueueInvocationSequence; class ShadowCaster;
template<class T> class SharedPtr;
template<class T> class VectorIterator;
typedef SharedPtr<AnimableValue> AnimableValuePtr;
typedef std::vector<String> StringVector;
typedef std::vector<Light*> LightList;
enum ShadowTechnique
    {
        SHADOWTYPE_NONE = 0x00,
		SHADOWDETAILTYPE_ADDITIVE = 0x01,
		SHADOWDETAILTYPE_MODULATIVE = 0x02,
		SHADOWDETAILTYPE_INTEGRATED = 0x04,
		SHADOWDETAILTYPE_STENCIL = 0x10,
		SHADOWDETAILTYPE_TEXTURE = 0x20,
        SHADOWTYPE_STENCIL_MODULATIVE = 0x12,
        SHADOWTYPE_STENCIL_ADDITIVE = 0x11,
        SHADOWTYPE_TEXTURE_MODULATIVE = 0x22,
        SHADOWTYPE_TEXTURE_ADDITIVE = 0x21,
		SHADOWTYPE_TEXTURE_ADDITIVE_INTEGRATED = 0x25,
		SHADOWTYPE_TEXTURE_MODULATIVE_INTEGRATED = 0x26
    };
class QueuedRenderableCollection {public:enum OrganisationMode
		{
			OM_PASS_GROUP = 1,
			OM_SORT_DESCENDING = 2,
			OM_SORT_ASCENDING = 6
		};};
class __declspec(dllimport) Math { public: static const Real PI; };
class __declspec(dllimport) Vector3 {
public: Real x,y,z;
inline Vector3() {}
inline Vector3(const Real fX,const Real fY,const Real fZ):x(fX),y(fY),z(fZ){}
inline Vector3(const Vector3& rkVector):x(rkVector.x),y(rkVector.y),z(rkVector.z){}
inline Vector3& operator=(const Vector3& rkVector){x=rkVector.x;y=rkVector.y;z=rkVector.z;return *this;}
};
class __declspec(dllimport) ColourValue {public:float r,g,b,a;};
class RenderOperation {public:enum OperationType {
            OT_POINT_LIST = 1,
            OT_LINE_LIST = 2,
            OT_LINE_STRIP = 3,
            OT_TRIANGLE_LIST = 4,
            OT_TRIANGLE_STRIP = 5,
            OT_TRIANGLE_FAN = 6
        };};
class __declspec(dllimport) ShadowCaster {public:
typedef std::vector<ShadowRenderable*> ShadowRenderableList;
typedef VectorIterator<ShadowRenderableList> ShadowRenderableListIterator;
virtual ~ShadowCaster();
virtual bool getCastShadows(void) const = 0;
virtual EdgeData* getEdgeList(void) = 0;
virtual bool hasEdgeList(void) = 0;
virtual const AxisAlignedBox& getWorldBoundingBox(bool derive = false) const = 0;
virtual const AxisAlignedBox& getLightCapBounds(void) const = 0;
virtual const AxisAlignedBox& getDarkCapBounds(const Light& light, Real dirLightExtrusionDist) const = 0;
virtual ShadowRenderableListIterator getShadowVolumeRenderableIterator(
            ShadowTechnique shadowTechnique, const Light* light, 
            HardwareIndexBufferSharedPtr* indexBuffer, 
            bool extrudeVertices, Real extrusionDistance, unsigned long flags = 0 ) = 0;
virtual Real getPointExtrusionDistance(const Light* l) const = 0;
virtual void updateEdgeListLightFacing(EdgeData* edgeData, 
            const Vector4& lightPos);
virtual void generateShadowVolume(EdgeData* edgeData, 
            const HardwareIndexBufferSharedPtr& indexBuffer, const Light* light,
            ShadowRenderableList& shadowRenderables, unsigned long flags);
virtual void extrudeBounds(AxisAlignedBox& box, const Vector4& lightPos, 
            Real extrudeDist) const;
};
class __declspec(dllimport) AnimableObject {public:
virtual const String& getAnimableDictionaryName(void) const;
virtual void initialiseAnimableDictionary(StringVector&) const;
virtual ~AnimableObject();
virtual AnimableValuePtr createAnimableValue(const String& valueName);
};
class __declspec(dllimport) MovableObject : public ShadowCaster,public AnimableObject {public:
class Listener;
virtual ~MovableObject();
virtual void _notifyCreator(MovableObjectFactory* fact);
virtual MovableObjectFactory*  _getCreator(void) const;
virtual void _notifyManager(SceneManager* man);
virtual SceneManager* _getManager(void) const;
virtual const String& getName(void) const;
virtual const String& getMovableType(void) const = 0;
virtual Node* getParentNode(void) const;
virtual SceneNode* getParentSceneNode(void) const;
virtual void _notifyAttached(Node* parent, bool isTagPoint = false);
virtual bool isAttached(void) const;
virtual bool isInScene(void) const;
virtual void _notifyMoved(void);
virtual void _notifyCurrentCamera(Camera* cam);
virtual const AxisAlignedBox& getBoundingBox(void) const = 0;
virtual Real getBoundingRadius(void) const = 0;
virtual const AxisAlignedBox& getWorldBoundingBox(bool derive = false) const;
virtual const Sphere& getWorldBoundingSphere(bool derive = false) const;
virtual void _updateRenderQueue(RenderQueue* queue) = 0;
virtual void setVisible(bool visible);
virtual bool getVisible(void) const;
virtual bool isVisible(void) const;
virtual void setRenderingDistance(Real dist);
virtual Real getRenderingDistance(void) const;
virtual void setUserObject(UserDefinedObject* obj);
virtual UserDefinedObject* getUserObject(void);
virtual void setUserAny(const Any& anything);
virtual const Any& getUserAny(void) const;
virtual void setRenderQueueGroup(uint8 queueID);
virtual uint8 getRenderQueueGroup(void) const;
virtual const Matrix4& _getParentNodeFullTransform(void) const;
virtual void setQueryFlags(uint32 flags);
virtual void addQueryFlags(uint32 flags);
virtual void removeQueryFlags(unsigned long flags);
virtual uint32 getQueryFlags(void) const;
virtual void setVisibilityFlags(uint32 flags);
virtual void addVisibilityFlags(uint32 flags);
virtual void removeVisibilityFlags(uint32 flags);
virtual uint32 getVisibilityFlags(void) const;
virtual void setListener(Listener* listener);
virtual Listener* getListener(void) const;
virtual const LightList& queryLights(void) const;
virtual uint32 getTypeFlags(void) const;
};
class __declspec(dllimport) SceneManager {public:
typedef std::vector<ShadowCaster*> ShadowCasterList;
enum PrefabType {PT_PLANE,PT_CUBE,PT_SPHERE};
virtual void initRenderQueue(void);
virtual void setViewport(Viewport *vp);
virtual void renderVisibleObjectsDefaultSequence(void);
virtual void renderVisibleObjectsCustomSequence(RenderQueueInvocationSequence* s);
virtual void prepareRenderQueue(void);
virtual void renderSingleObject(const Renderable* rend, const Pass* pass, 
			bool doLightIteration, const LightList* manualLightList = 0);
virtual void findLightsAffectingFrustum(const Camera* camera);
virtual void initShadowVolumeMaterials(void);
virtual void ensureShadowTexturesCreated();
virtual void destroyShadowTextures(void);
virtual void prepareShadowTextures(Camera* cam, Viewport* vp);
virtual void renderShadowVolumesToStencil(const Light* light, const Camera* cam);
virtual void setShadowVolumeStencilState(bool secondpass, bool zfail, bool twosided);
virtual const ShadowCasterList& findShadowCastersForLight(const Light* light, 
            const Camera* camera);
virtual void renderBasicQueueGroupObjects(RenderQueueGroup* pGroup, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderAdditiveStencilShadowedQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderModulativeStencilShadowedQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderTextureShadowCasterQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderTextureShadowReceiverQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderModulativeTextureShadowedQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderAdditiveTextureShadowedQueueGroupObjects(RenderQueueGroup* group, 
			QueuedRenderableCollection::OrganisationMode om);
virtual void renderObjects(const QueuedRenderableCollection& objs, 
			QueuedRenderableCollection::OrganisationMode om, 
            bool doLightIteration, const LightList* manualLightList = 0);
virtual void renderTransparentShadowCasterObjects(const QueuedRenderableCollection& objs, 
			QueuedRenderableCollection::OrganisationMode om, 
			bool doLightIteration, const LightList* manualLightList = 0);
virtual void updateRenderQueueSplitOptions(void);
virtual void updateRenderQueueGroupSplitOptions(RenderQueueGroup* group, 
			bool suppressShadows, bool suppressRenderState);
virtual ~SceneManager();
virtual const String& getTypeName(void) const = 0;
virtual Camera* createCamera(const String& name);
virtual Camera* getCamera(const String& name) const;
virtual bool hasCamera(const String& name) const;
virtual void destroyCamera(Camera *cam);
virtual void destroyCamera(const String& name);
virtual void destroyAllCameras(void);
virtual Light* createLight(const String& name);
virtual Light* getLight(const String& name) const;
virtual bool hasLight(const String& name) const;
virtual void destroyLight(const String& name);
virtual void destroyLight(Light* light);
virtual void destroyAllLights(void);
virtual void _notifyLightsDirty(void);
virtual const LightList& _getLightsAffectingFrustum(void) const;
virtual void _populateLightList(const Vector3& position, Real radius, LightList& destList);
virtual SceneNode* createSceneNode(void);
virtual SceneNode* createSceneNode(const String& name);
virtual void destroySceneNode(const String& name);
virtual SceneNode* getRootSceneNode(void) const;
virtual SceneNode* getSceneNode(const String& name) const;
virtual bool hasSceneNode(const String& name) const;
virtual Entity* createEntity(const String& entityName, const String& meshName);
virtual Entity* createEntity(const String& entityName, PrefabType ptype);
virtual Entity* getEntity(const String& name) const;
virtual bool hasEntity(const String& name) const;
virtual void destroyEntity(Entity* ent);
virtual void destroyEntity(const String& name);
virtual void destroyAllEntities(void);
virtual ManualObject* createManualObject(const String& name);
};
class __declspec(dllimport) ManualObject : public MovableObject {public:
class ManualObjectSection;
virtual ~ManualObject();
virtual void clear(void);
virtual void estimateVertexCount(size_t vcount);
virtual void estimateIndexCount(size_t icount);
virtual void begin(const String& materialName, 
			RenderOperation::OperationType opType = RenderOperation::OT_TRIANGLE_LIST);
virtual void setDynamic(bool dyn);
virtual bool getDynamic() const;
virtual void beginUpdate(size_t sectionIndex);
virtual void position(const Vector3& pos);
virtual void position(Real x, Real y, Real z);
virtual void normal(const Vector3& norm);
virtual void normal(Real x, Real y, Real z);
virtual void textureCoord(Real u);
virtual void textureCoord(Real u, Real v);
virtual void textureCoord(Real u, Real v, Real w);
virtual void textureCoord(const Vector2& uv);
virtual void textureCoord(const Vector3& uvw);
virtual void colour(const ColourValue& col);
virtual void colour(Real r, Real g, Real b, Real a = 1.0f);
virtual void index(uint16 idx);
virtual void triangle(uint16 i1, uint16 i2, uint16 i3);
virtual void quad(uint16 i1, uint16 i2, uint16 i3, uint16 i4);
virtual ManualObjectSection* end(void);
};
}
namespace Ogre {
// Existing receiver view: every field below is accessed by the native body.
class AdornQuadric {
public:
enum NormalStyle {Smooth=0,Flat=1,None=2};
enum Orientation {Outside=0,Inside=1};
enum DrawStyle {Point=0,Line=1,Fill=2,Silhouette=3};
NormalStyle normals;
bool textureCoords;
Orientation orientation;
DrawStyle drawStyle;
ColourValue colour;
Vector3 offset;
ManualObject* partialDisk(SceneManager*,const String&,ManualObject*,float,float,int,int,float,float);
};
ManualObject* AdornQuadric::partialDisk(SceneManager*manager,const String&name,ManualObject*object,float innerRadius,float outerRadius,int slices,int loops,float startAngle,float sweepAngle){
if(!object)object=manager->createManualObject(name);
int index=0;

    int i,j;
    float sinCache[240];
    float cosCache[240];
    double angle;
    float sintemp, costemp;
    float deltaRadius;
    float radiusLow, radiusHigh;
    float texLow = 0.0f, texHigh = 0.0f;
    float angleOffset;
    int slices2;
    int finish;

    if (slices >= 240) slices = 240-1;
    if (slices < 2 || loops < 1 || outerRadius <= 0.0f || innerRadius < 0.0f ||
	    innerRadius > outerRadius) {
	
	return 0;
    }

    if (sweepAngle < -360.0f) sweepAngle = 360.0f;
    if (sweepAngle > 360.0f) sweepAngle = 360.0f;
    if (sweepAngle < 0) {
	startAngle += sweepAngle;
	sweepAngle = -sweepAngle;
    }

    if (sweepAngle == 360.0f) {
	slices2 = slices;
    } else {
	slices2 = slices + 1;
    }

    
    deltaRadius = outerRadius - innerRadius;

    

    angleOffset = startAngle / 180.0f * Ogre::Math::PI;
    for (i = 0; i <= slices; i++) {
	angle = angleOffset + double((Ogre::Math::PI * sweepAngle) / 180.0f) * i / slices;
	sinCache[i] = sin(angle);
	cosCache[i] = cos(angle);
    }

    if (sweepAngle == 360.0f) {
	sinCache[slices] = sinCache[0];
	cosCache[slices] = cosCache[0];
    }

    

    switch (drawStyle) {
      case Fill:
	if (innerRadius == 0.0f) {
	    finish = loops - 1;
	    
	    object->begin("", Ogre::RenderOperation::OT_TRIANGLE_FAN);
index=0;
if(colour.r>=0.0f)object->colour(colour);
	    object->position(0.0f + offset.x, 0.0f + offset.y, 0.0f + offset.z);
object->index(index++);
switch(normals) {
      case Flat:
      case Smooth:
	if (orientation == Outside) {
	    object->normal(0.0f, 0.0f, 1.0);
	} else {
	    object->normal(0.0f, 0.0f, -1.0);
	}
	break;
      default:
      case None:
	break;
    }

if (textureCoords) {
		object->textureCoord(0.5f, 0.5f);
	    }
	    radiusLow = outerRadius -
		    deltaRadius * ((float) (loops-1) / loops);
	    if (textureCoords) {
		texLow = radiusLow / outerRadius / 2;
	    }

	    if (orientation == Outside) {
		for (i = slices; i >= 0; i--) {
		    object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
			object->textureCoord(texLow * sinCache[i] + 0.5f,
				texLow * cosCache[i] + 0.5f);
		    }
		}
	    } else {
		for (i = 0; i <= slices; i++) {
		    object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
			object->textureCoord(texLow * sinCache[i] + 0.5f,
				texLow * cosCache[i] + 0.5f);
		    }
		}
	    }
	    object->end();
	} else {
	    finish = loops;
	}
	for (j = 0; j < finish; j++) {
	    radiusLow = outerRadius - deltaRadius * ((float) j / loops);
	    radiusHigh = outerRadius - deltaRadius * ((float) (j + 1) / loops);
	    if (textureCoords) {
		texLow = radiusLow / outerRadius / 2;
		texHigh = radiusHigh / outerRadius / 2;
	    }

	    std::vector<Ogre::Vector3> positions;
object->begin("",Ogre::RenderOperation::OT_TRIANGLE_LIST);
index=0;
if(colour.r>=0.0f)object->colour(colour);
switch(normals) {
      case Flat:
      case Smooth:
	if (orientation == Outside) {
	    object->normal(0.0f, 0.0f, 1.0);
	} else {
	    object->normal(0.0f, 0.0f, -1.0);
	}
	break;
      default:
      case None:
	break;
    }

	    for (i = 0; i <= slices; i++) {
		if (orientation == Outside) {
		    if (textureCoords) {
			object->textureCoord(texLow * sinCache[i] + 0.5f,
				texLow * cosCache[i] + 0.5f);
		    }
		    {int count=positions.size();
if(positions.size()>=2){if(count%2){object->position(positions[count-1]);object->index(index++);
object->position(positions[count-2]);object->index(index++);
object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}else{object->position(positions[count-2]);object->index(index++);
object->position(positions[count-1]);object->index(index++);
object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}}
else{positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}};

		    if (textureCoords) {
			object->textureCoord(texHigh * sinCache[i] + 0.5f,
				texHigh * cosCache[i] + 0.5f);
		    }
		    {int count=positions.size();
if(positions.size()>=2){if(count%2){object->position(positions[count-1]);object->index(index++);
object->position(positions[count-2]);object->index(index++);
object->position(radiusHigh * sinCache[i] + offset.x, radiusHigh * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}else{object->position(positions[count-2]);object->index(index++);
object->position(positions[count-1]);object->index(index++);
object->position(radiusHigh * sinCache[i] + offset.x, radiusHigh * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}}
else{positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}};
		} else {
		    if (textureCoords) {
			object->textureCoord(texHigh * sinCache[i] + 0.5f,
				texHigh * cosCache[i] + 0.5f);
		    }
		    {int count=positions.size();
if(positions.size()>=2){if(count%2){object->position(positions[count-1]);object->index(index++);
object->position(positions[count-2]);object->index(index++);
object->position(radiusHigh * sinCache[i] + offset.x, radiusHigh * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}else{object->position(positions[count-2]);object->index(index++);
object->position(positions[count-1]);object->index(index++);
object->position(radiusHigh * sinCache[i] + offset.x, radiusHigh * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}}
else{positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}};

		    if (textureCoords) {
			object->textureCoord(texLow * sinCache[i] + 0.5f,
				texLow * cosCache[i] + 0.5f);
		    }
		    {int count=positions.size();
if(positions.size()>=2){if(count%2){object->position(positions[count-1]);object->index(index++);
object->position(positions[count-2]);object->index(index++);
object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}else{object->position(positions[count-2]);object->index(index++);
object->position(positions[count-1]);object->index(index++);
object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}}
else{positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}};
		}
	    }
	    object->end();
	}
	break;case Point:
	object->begin("",Ogre::RenderOperation::OT_POINT_LIST);
index=0;
if(colour.r>=0.0f)object->colour(colour);
switch(normals) {
      case Flat:
      case Smooth:
	if (orientation == Outside) {
	    object->normal(0.0f, 0.0f, 1.0);
	} else {
	    object->normal(0.0f, 0.0f, -1.0);
	}
	break;
      default:
      case None:
	break;
    }

	for (i = 0; i < slices2; i++) {
	    sintemp = sinCache[i];
	    costemp = cosCache[i];
	    for (j = 0; j <= loops; j++) {
		radiusLow = outerRadius - deltaRadius * ((float) j / loops);

		object->position(radiusLow * sintemp + offset.x, radiusLow * costemp + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
		    texLow = radiusLow / outerRadius / 2;

		    object->textureCoord(texLow * sinCache[i] + 0.5f,
			    texLow * cosCache[i] + 0.5f);
		}
	    }
	}
	object->end();
	break;
      case Line:
	if (innerRadius == outerRadius) {
	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r>=0.0f)object->colour(colour);
switch(normals) {
      case Flat:
      case Smooth:
	if (orientation == Outside) {
	    object->normal(0.0f, 0.0f, 1.0);
	} else {
	    object->normal(0.0f, 0.0f, -1.0);
	}
	break;
      default:
      case None:
	break;
    }


	    for (i = 0; i <= slices; i++) {
		object->position(innerRadius * sinCache[i] + offset.x, innerRadius * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
		    object->textureCoord(sinCache[i] / 2 + 0.5f,
			    cosCache[i] / 2 + 0.5f);
		}
	    }
	    object->end();
	    break;
	}
	for (j = 0; j <= loops; j++) {
	    radiusLow = outerRadius - deltaRadius * ((float) j / loops);
	    if (textureCoords) {
		texLow = radiusLow / outerRadius / 2;
	    }

	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r>=0.0f)object->colour(colour);

	    for (i = 0; i <= slices; i++) {
		object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
		    object->textureCoord(texLow * sinCache[i] + 0.5f,
			    texLow * cosCache[i] + 0.5f);
		}
	    }
	    object->end();
	}
	for (i=0; i < slices2; i++) {
	    sintemp = sinCache[i];
	    costemp = cosCache[i];
	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r>=0.0f)object->colour(colour);

	    for (j = 0; j <= loops; j++) {
		radiusLow = outerRadius - deltaRadius * ((float) j / loops);
		

		object->position(radiusLow * sintemp + offset.x, radiusLow * costemp + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
texLow = radiusLow / outerRadius / 2;
		    object->textureCoord(texLow * sinCache[i] + 0.5f,
			    texLow * cosCache[i] + 0.5f);
		}
	    }
	    object->end();
	}
	break;
      case Silhouette:
	if (sweepAngle < 360.0f) {
	    for (i = 0; i <= slices; i+= slices) {
		sintemp = sinCache[i];
		costemp = cosCache[i];
		object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r>=0.0f)object->colour(colour);
switch(normals) {
      case Flat:
      case Smooth:
	if (orientation == Outside) {
	    object->normal(0.0f, 0.0f, 1.0);
	} else {
	    object->normal(0.0f, 0.0f, -1.0);
	}
	break;
      default:
      case None:
	break;
    }

		for (j = 0; j <= loops; j++) {
		    radiusLow = outerRadius - deltaRadius * ((float) j / loops);

		    object->position(radiusLow * sintemp + offset.x, radiusLow * costemp + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
			texLow = radiusLow / outerRadius / 2;
			object->textureCoord(texLow * sinCache[i] + 0.5f,
				texLow * cosCache[i] + 0.5f);
		    }
		}
		object->end();
	    }
	}
	for (j = 0; j <= loops; j += loops) {
	    radiusLow = outerRadius - deltaRadius * ((float) j / loops);
	    if (textureCoords) {
		texLow = radiusLow / outerRadius / 2;
	    }

	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r>=0.0f)object->colour(colour);

	    for (i = 0; i <= slices; i++) {
		object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
		    object->textureCoord(texLow * sinCache[i] + 0.5f,
			    texLow * cosCache[i] + 0.5f);
		}
	    }
	    object->end();
	    if (innerRadius == outerRadius) break;
	}
	break;
      default:
	break;
    }

return object;
}
}

// Native used values and receiver member addresses; interface owner sizes are
// deliberately unspecified because this function only uses existing pointers.
typedef char disk_vector_size[sizeof(Ogre::Vector3)==12?1:-1];
typedef char disk_vector_x[offsetof(Ogre::Vector3,x)==0?1:-1];
typedef char disk_vector_y[offsetof(Ogre::Vector3,y)==4?1:-1];
typedef char disk_vector_z[offsetof(Ogre::Vector3,z)==8?1:-1];
typedef char disk_colour_size[sizeof(Ogre::ColourValue)==16?1:-1];
typedef char disk_colour_r[offsetof(Ogre::ColourValue,r)==0?1:-1];
typedef char disk_colour_g[offsetof(Ogre::ColourValue,g)==4?1:-1];
typedef char disk_colour_b[offsetof(Ogre::ColourValue,b)==8?1:-1];
typedef char disk_colour_a[offsetof(Ogre::ColourValue,a)==12?1:-1];
typedef char disk_receiver_normals[offsetof(Ogre::AdornQuadric,normals)==0?1:-1];
typedef char disk_receiver_texture[offsetof(Ogre::AdornQuadric,textureCoords)==4?1:-1];
typedef char disk_receiver_orientation[offsetof(Ogre::AdornQuadric,orientation)==8?1:-1];
typedef char disk_receiver_draw[offsetof(Ogre::AdornQuadric,drawStyle)==12?1:-1];
typedef char disk_receiver_colour[offsetof(Ogre::AdornQuadric,colour)==16?1:-1];
typedef char disk_receiver_offset[offsetof(Ogre::AdornQuadric,offset)==32?1:-1];
typedef char disk_cache_size[sizeof(std::vector<Ogre::Vector3>)==24?1:-1];
