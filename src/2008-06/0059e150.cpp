// from server: 100% by EspClaude
// from server: 93% by coldek
// roc 2008-06 0059e150  unit: VCRenderSettings::?$EnumPropDescriptor  size: 590 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059e150
//
// 0059e150  81ec94000000         sub esp, 0x94
// 0059e156  83bc249c00000000     cmp dword ptr [esp + 0x9c], 0
// 0059e15e  56                   push esi
// 0059e15f  8bf1                 mov esi, ecx
// 0059e161  0f842b020000         je 0x59e392
// 0059e167  8b86c4020000         mov eax, dword ptr [esi + 0x2c4]
// 0059e16d  d94004               fld dword ptr [eax + 4]
// 0059e170  83c004               add eax, 4
// 0059e173  d95c2410             fstp dword ptr [esp + 0x10]
// 0059e177  53                   push ebx
// 0059e178  d94004               fld dword ptr [eax + 4]
// 0059e17b  8d9e28020000         lea ebx, [esi + 0x228]
// 0059e181  d95c2418             fstp dword ptr [esp + 0x18]
// 0059e185  57                   push edi
// 0059e186  d94008               fld dword ptr [eax + 8]
// 0059e189  8bcb                 mov ecx, ebx
// 0059e18b  d95c2420             fstp dword ptr [esp + 0x20]
// 0059e18f  e82ca10400           call 0x5e82c0
// 0059e194  8bf8                 mov edi, eax
// 0059e196  57                   push edi
// 0059e197  8d4c2444             lea ecx, [esp + 0x44]
// 0059e19b  e88050f7ff           call 0x513220
// 0059e1a0  d94724               fld dword ptr [edi + 0x24]
// 0059e1a3  8b8c24a4000000       mov ecx, dword ptr [esp + 0xa4]
// 0059e1aa  d95c2464             fstp dword ptr [esp + 0x64]
// 0059e1ae  83f903               cmp ecx, 3
// 0059e1b1  d94728               fld dword ptr [edi + 0x28]
// 0059e1b4  d95c2468             fstp dword ptr [esp + 0x68]
// 0059e1b8  d9472c               fld dword ptr [edi + 0x2c]
// 0059e1bb  d95c246c             fstp dword ptr [esp + 0x6c]
// 0059e1bf  d9ee                 fldz 
// 0059e1c1  d954240c             fst dword ptr [esp + 0xc]
// 0059e1c5  d9542410             fst dword ptr [esp + 0x10]
// 0059e1c9  d95c2414             fstp dword ptr [esp + 0x14]
// 0059e1cd  7d04                 jge 0x59e1d3
// 0059e1cf  d9e8                 fld1 
// 0059e1d1  eb06                 jmp 0x59e1d9
// 0059e1d3  d905b8c38100         fld dword ptr [0x81c3b8]
// 0059e1d9  83bedc01000001       cmp dword ptr [esi + 0x1dc], 1
// 0059e1e0  d95c2424             fstp dword ptr [esp + 0x24]
// 0059e1e4  db8424a8000000       fild dword ptr [esp + 0xa8]
// 0059e1eb  7525                 jne 0x59e212
// 0059e1ed  b856555555           mov eax, 0x55555556
// 0059e1f2  f7e9                 imul ecx
// 0059e1f4  8bc2                 mov eax, edx
// 0059e1f6  c1e81f               shr eax, 0x1f
// 0059e1f9  03c2                 add eax, edx
// 0059e1fb  8d0440               lea eax, [eax + eax*2]
// 0059e1fe  2bc8                 sub ecx, eax
// 0059e200  d95c8c0c             fstp dword ptr [esp + ecx*4 + 0xc]
// 0059e204  d9442414             fld dword ptr [esp + 0x14]
// 0059e208  d9442410             fld dword ptr [esp + 0x10]
// 0059e20c  d944240c             fld dword ptr [esp + 0xc]
// 0059e210  eb06                 jmp 0x59e218
// 0059e212  d9c0                 fld st(0)
// 0059e214  d9c1                 fld st(1)
// 0059e216  d9c9                 fxch st(1)
// 0059e218  8b86e0010000         mov eax, dword ptr [esi + 0x1e0]
// 0059e21e  d944241c             fld dword ptr [esp + 0x1c]
// 0059e222  83e801               sub eax, 1
// 0059e225  d9c0                 fld st(0)
// 0059e227  740f                 je 0x59e238
// 0059e229  83e801               sub eax, 1
// 0059e22c  7514                 jne 0x59e242
// 0059e22e  ddd8                 fstp st(0)
// 0059e230  d80dc0888200         fmul dword ptr [0x8288c0]
// 0059e236  eb0c                 jmp 0x59e244
// 0059e238  ddd8                 fstp st(0)
// 0059e23a  d80d606e8200         fmul dword ptr [0x826e60]
// 0059e240  eb02                 jmp 0x59e244
// 0059e242  ddd9                 fstp st(1)
// 0059e244  d9c9                 fxch st(1)
// 0059e246  8d4c2434             lea ecx, [esp + 0x34]
// 0059e24a  d8442418             fadd dword ptr [esp + 0x18]
// 0059e24e  51                   push ecx
// 0059e24f  8d542410             lea edx, [esp + 0x10]
// 0059e253  52                   push edx
// 0059e254  d95c243c             fstp dword ptr [esp + 0x3c]
// 0059e258  8bce                 mov ecx, esi
// 0059e25a  dec1                 faddp st(1)
// 0059e25c  d95c2440             fstp dword ptr [esp + 0x40]
// 0059e260  d8442428             fadd dword ptr [esp + 0x28]
// 0059e264  d95c2444             fstp dword ptr [esp + 0x44]
// 0059e268  e843bcffff           call 0x599eb0
// 0059e26d  d944240c             fld dword ptr [esp + 0xc]
// 0059e271  8d442428             lea eax, [esp + 0x28]
// 0059e275  d8642418             fsub dword ptr [esp + 0x18]
// 0059e279  50                   push eax
// 0059e27a  8d4c2410             lea ecx, [esp + 0x10]
// 0059e27e  51                   push ecx
// 0059e27f  d95c2430             fstp dword ptr [esp + 0x30]
// 0059e283  8d4c2448             lea ecx, [esp + 0x48]
// 0059e287  d9442418             fld dword ptr [esp + 0x18]
// 0059e28b  d8642424             fsub dword ptr [esp + 0x24]
// 0059e28f  d95c2434             fstp dword ptr [esp + 0x34]
// 0059e293  d944241c             fld dword ptr [esp + 0x1c]
// 0059e297  d8642428             fsub dword ptr [esp + 0x28]
// 0059e29b  d95c2438             fstp dword ptr [esp + 0x38]
// 0059e29f  e8dc82edff           call 0x476580
// 0059e2a4  d944240c             fld dword ptr [esp + 0xc]
// 0059e2a8  8d542440             lea edx, [esp + 0x40]
// 0059e2ac  d905ac9b8100         fld dword ptr [0x819bac]
// 0059e2b2  52                   push edx
// 0059e2b3  dcc9                 fmul st(1), st(0)
// 0059e2b5  8d4c2474             lea ecx, [esp + 0x74]
// 0059e2b9  d9442414             fld dword ptr [esp + 0x14]
// 0059e2bd  d8c9                 fmul st(1)
// 0059e2bf  d9442418             fld dword ptr [esp + 0x18]
// 0059e2c3  deca                 fmulp st(2)
// 0059e2c5  d9442428             fld dword ptr [esp + 0x28]
// 0059e2c9  dccb                 fmul st(3), st(0)
// 0059e2cb  dcc9                 fmul st(1), st(0)
// 0059e2cd  deca                 fmulp st(2)
// 0059e2cf  d9ca                 fxch st(2)
// 0059e2d1  d8442468             fadd dword ptr [esp + 0x68]
// 0059e2d5  d95c2410             fstp dword ptr [esp + 0x10]
// 0059e2d9  d944246c             fld dword ptr [esp + 0x6c]
// 0059e2dd  dec2                 faddp st(2)
// 0059e2df  d9c9                 fxch st(1)
// 0059e2e1  d95c2414             fstp dword ptr [esp + 0x14]
// 0059e2e5  d8442470             fadd dword ptr [esp + 0x70]
// 0059e2e9  d95c2418             fstp dword ptr [esp + 0x18]
// 0059e2ed  e82e4ff7ff           call 0x513220
// 0059e2f2  d944240c             fld dword ptr [esp + 0xc]
// 0059e2f6  8d442470             lea eax, [esp + 0x70]
// 0059e2fa  d99c2494000000       fstp dword ptr [esp + 0x94]
// 0059e301  50                   push eax
// 0059e302  d9442414             fld dword ptr [esp + 0x14]
// 0059e306  8bce                 mov ecx, esi
// 0059e308  d99c249c000000       fstp dword ptr [esp + 0x9c]
// 0059e30f  d9442418             fld dword ptr [esp + 0x18]
// 0059e313  d99c24a0000000       fstp dword ptr [esp + 0xa0]
// 0059e31a  e881f5ffff           call 0x59d8a0
// 0059e31f  8d4c2434             lea ecx, [esp + 0x34]
// 0059e323  51                   push ecx
// 0059e324  8d54242c             lea edx, [esp + 0x2c]
// 0059e328  52                   push edx
// 0059e329  8bce                 mov ecx, esi
// 0059e32b  e880bbffff           call 0x599eb0
// 0059e330  8d442428             lea eax, [esp + 0x28]
// 0059e334  50                   push eax
// 0059e335  8bce                 mov ecx, esi
// 0059e337  e854f8ffff           call 0x59db90
// 0059e33c  8bce                 mov ecx, esi
// 0059e33e  e8add1ffff           call 0x59b4f0
// 0059e343  8bcb                 mov ecx, ebx
// 0059e345  e8769f0400           call 0x5e82c0
// 0059e34a  d905b0b38200         fld dword ptr [0x82b3b0]
// 0059e350  83ec08               sub esp, 8
// 0059e353  d9542404             fst dword ptr [esp + 4]
// 0059e357  8d4c2478             lea ecx, [esp + 0x78]
// 0059e35b  d91c24               fstp dword ptr [esp]
// 0059e35e  51                   push ecx
// 0059e35f  50                   push eax
// 0059e360  e83bff0300           call 0x5de2a0
// 0059e365  83c410               add esp, 0x10
// 0059e368  5f                   pop edi
// 0059e369  5b                   pop ebx
// 0059e36a  84c0                 test al, al
// 0059e36c  740c                 je 0x59e37a
// 0059e36e  b001                 mov al, 1
// 0059e370  5e                   pop esi
// 0059e371  81c494000000         add esp, 0x94
// 0059e377  c20800               ret 8
// 0059e37a  8d542438             lea edx, [esp + 0x38]
// 0059e37e  52                   push edx
// 0059e37f  8bce                 mov ecx, esi
// 0059e381  e81af5ffff           call 0x59d8a0
// 0059e386  8d442410             lea eax, [esp + 0x10]
// 0059e38a  50                   push eax
// 0059e38b  8bce                 mov ecx, esi
// 0059e38d  e8fef7ffff           call 0x59db90
// 0059e392  32c0                 xor al, al
// 0059e394  5e                   pop esi
// 0059e395  81c494000000         add esp, 0x94
// 0059e39b  c20800               ret 8

// from server: 88% by colin
// roc 2008-06 0059e150  unit: VCRenderSettings::?$EnumPropDescriptor  size: 590 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059e150
//
// 0059e150  81ec94000000         sub esp, 0x94
// 0059e156  83bc249c00000000     cmp dword ptr [esp + 0x9c], 0
// 0059e15e  56                   push esi
// 0059e15f  8bf1                 mov esi, ecx
// 0059e161  0f842b020000         je 0x59e392
// 0059e167  8b86c4020000         mov eax, dword ptr [esi + 0x2c4]
// 0059e16d  d94004               fld dword ptr [eax + 4]
// 0059e170  83c004               add eax, 4
// 0059e173  d95c2410             fstp dword ptr [esp + 0x10]
// 0059e177  53                   push ebx
// 0059e178  d94004               fld dword ptr [eax + 4]
// 0059e17b  8d9e28020000         lea ebx, [esi + 0x228]
// 0059e181  d95c2418             fstp dword ptr [esp + 0x18]
// 0059e185  57                   push edi
// 0059e186  d94008               fld dword ptr [eax + 8]
// 0059e189  8bcb                 mov ecx, ebx
// 0059e18b  d95c2420             fstp dword ptr [esp + 0x20]
// 0059e18f  e82ca10400           call 0x5e82c0
// 0059e194  8bf8                 mov edi, eax
// 0059e196  57                   push edi
// 0059e197  8d4c2444             lea ecx, [esp + 0x44]
// 0059e19b  e88050f7ff           call 0x513220
// 0059e1a0  d94724               fld dword ptr [edi + 0x24]
// 0059e1a3  8b8c24a4000000       mov ecx, dword ptr [esp + 0xa4]
// 0059e1aa  d95c2464             fstp dword ptr [esp + 0x64]
// 0059e1ae  83f903               cmp ecx, 3
// 0059e1b1  d94728               fld dword ptr [edi + 0x28]
// 0059e1b4  d95c2468             fstp dword ptr [esp + 0x68]
// 0059e1b8  d9472c               fld dword ptr [edi + 0x2c]
// 0059e1bb  d95c246c             fstp dword ptr [esp + 0x6c]
// 0059e1bf  d9ee                 fldz 
// 0059e1c1  d954240c             fst dword ptr [esp + 0xc]
// 0059e1c5  d9542410             fst dword ptr [esp + 0x10]
// 0059e1c9  d95c2414             fstp dword ptr [esp + 0x14]
// 0059e1cd  7d04                 jge 0x59e1d3
// 0059e1cf  d9e8                 fld1 
// 0059e1d1  eb06                 jmp 0x59e1d9
// 0059e1d3  d905b8c38100         fld dword ptr [0x81c3b8]
// 0059e1d9  83bedc01000001       cmp dword ptr [esi + 0x1dc], 1
// 0059e1e0  d95c2424             fstp dword ptr [esp + 0x24]
// 0059e1e4  db8424a8000000       fild dword ptr [esp + 0xa8]
// 0059e1eb  7525                 jne 0x59e212
// 0059e1ed  b856555555           mov eax, 0x55555556
// 0059e1f2  f7e9                 imul ecx
// 0059e1f4  8bc2                 mov eax, edx
// 0059e1f6  c1e81f               shr eax, 0x1f
// 0059e1f9  03c2                 add eax, edx
// 0059e1fb  8d0440               lea eax, [eax + eax*2]
// 0059e1fe  2bc8                 sub ecx, eax
// 0059e200  d95c8c0c             fstp dword ptr [esp + ecx*4 + 0xc]
// 0059e204  d9442414             fld dword ptr [esp + 0x14]
// 0059e208  d9442410             fld dword ptr [esp + 0x10]
// 0059e20c  d944240c             fld dword ptr [esp + 0xc]
// 0059e210  eb06                 jmp 0x59e218
// 0059e212  d9c0                 fld st(0)
// 0059e214  d9c1                 fld st(1)
// 0059e216  d9c9                 fxch st(1)
// 0059e218  8b86e0010000         mov eax, dword ptr [esi + 0x1e0]
// 0059e21e  d944241c             fld dword ptr [esp + 0x1c]
// 0059e222  83e801               sub eax, 1
// 0059e225  d9c0                 fld st(0)
// 0059e227  740f                 je 0x59e238
// 0059e229  83e801               sub eax, 1
// 0059e22c  7514                 jne 0x59e242
// 0059e22e  ddd8                 fstp st(0)
// 0059e230  d80dc0888200         fmul dword ptr [0x8288c0]
// 0059e236  eb0c                 jmp 0x59e244
// 0059e238  ddd8                 fstp st(0)
// 0059e23a  d80d606e8200         fmul dword ptr [0x826e60]
// 0059e240  eb02                 jmp 0x59e244
// 0059e242  ddd9                 fstp st(1)
// 0059e244  d9c9                 fxch st(1)
// 0059e246  8d4c2434             lea ecx, [esp + 0x34]
// 0059e24a  d8442418             fadd dword ptr [esp + 0x18]
// 0059e24e  51                   push ecx
// 0059e24f  8d542410             lea edx, [esp + 0x10]
// 0059e253  52                   push edx
// 0059e254  d95c243c             fstp dword ptr [esp + 0x3c]
// 0059e258  8bce                 mov ecx, esi
// 0059e25a  dec1                 faddp st(1)
// 0059e25c  d95c2440             fstp dword ptr [esp + 0x40]
// 0059e260  d8442428             fadd dword ptr [esp + 0x28]
// 0059e264  d95c2444             fstp dword ptr [esp + 0x44]
// 0059e268  e843bcffff           call 0x599eb0
// 0059e26d  d944240c             fld dword ptr [esp + 0xc]
// 0059e271  8d442428             lea eax, [esp + 0x28]
// 0059e275  d8642418             fsub dword ptr [esp + 0x18]
// 0059e279  50                   push eax
// 0059e27a  8d4c2410             lea ecx, [esp + 0x10]
// 0059e27e  51                   push ecx
// 0059e27f  d95c2430             fstp dword ptr [esp + 0x30]
// 0059e283  8d4c2448             lea ecx, [esp + 0x48]
// 0059e287  d9442418             fld dword ptr [esp + 0x18]
// 0059e28b  d8642424             fsub dword ptr [esp + 0x24]
// 0059e28f  d95c2434             fstp dword ptr [esp + 0x34]
// 0059e293  d944241c             fld dword ptr [esp + 0x1c]
// 0059e297  d8642428             fsub dword ptr [esp + 0x28]
// 0059e29b  d95c2438             fstp dword ptr [esp + 0x38]
// 0059e29f  e8dc82edff           call 0x476580
// 0059e2a4  d944240c             fld dword ptr [esp + 0xc]
// 0059e2a8  8d542440             lea edx, [esp + 0x40]
// 0059e2ac  d905ac9b8100         fld dword ptr [0x819bac]
// 0059e2b2  52                   push edx
// 0059e2b3  dcc9                 fmul st(1), st(0)
// 0059e2b5  8d4c2474             lea ecx, [esp + 0x74]
// 0059e2b9  d9442414             fld dword ptr [esp + 0x14]
// 0059e2bd  d8c9                 fmul st(1)
// 0059e2bf  d9442418             fld dword ptr [esp + 0x18]
// 0059e2c3  deca                 fmulp st(2)
// 0059e2c5  d9442428             fld dword ptr [esp + 0x28]
// 0059e2c9  dccb                 fmul st(3), st(0)
// 0059e2cb  dcc9                 fmul st(1), st(0)
// 0059e2cd  deca                 fmulp st(2)
// 0059e2cf  d9ca                 fxch st(2)
// 0059e2d1  d8442468             fadd dword ptr [esp + 0x68]
// 0059e2d5  d95c2410             fstp dword ptr [esp + 0x10]
// 0059e2d9  d944246c             fld dword ptr [esp + 0x6c]
// 0059e2dd  dec2                 faddp st(2)
// 0059e2df  d9c9                 fxch st(1)
// 0059e2e1  d95c2414             fstp dword ptr [esp + 0x14]
// 0059e2e5  d8442470             fadd dword ptr [esp + 0x70]
// 0059e2e9  d95c2418             fstp dword ptr [esp + 0x18]
// 0059e2ed  e82e4ff7ff           call 0x513220
// 0059e2f2  d944240c             fld dword ptr [esp + 0xc]
// 0059e2f6  8d442470             lea eax, [esp + 0x70]
// 0059e2fa  d99c2494000000       fstp dword ptr [esp + 0x94]
// 0059e301  50                   push eax
// 0059e302  d9442414             fld dword ptr [esp + 0x14]
// 0059e306  8bce                 mov ecx, esi
// 0059e308  d99c249c000000       fstp dword ptr [esp + 0x9c]
// 0059e30f  d9442418             fld dword ptr [esp + 0x18]
// 0059e313  d99c24a0000000       fstp dword ptr [esp + 0xa0]
// 0059e31a  e881f5ffff           call 0x59d8a0
// 0059e31f  8d4c2434             lea ecx, [esp + 0x34]
// 0059e323  51                   push ecx
// 0059e324  8d54242c             lea edx, [esp + 0x2c]
// 0059e328  52                   push edx
// 0059e329  8bce                 mov ecx, esi
// 0059e32b  e880bbffff           call 0x599eb0
// 0059e330  8d442428             lea eax, [esp + 0x28]
// 0059e334  50                   push eax
// 0059e335  8bce                 mov ecx, esi
// 0059e337  e854f8ffff           call 0x59db90
// 0059e33c  8bce                 mov ecx, esi
// 0059e33e  e8add1ffff           call 0x59b4f0
// 0059e343  8bcb                 mov ecx, ebx
// 0059e345  e8769f0400           call 0x5e82c0
// 0059e34a  d905b0b38200         fld dword ptr [0x82b3b0]
// 0059e350  83ec08               sub esp, 8
// 0059e353  d9542404             fst dword ptr [esp + 4]
// 0059e357  8d4c2478             lea ecx, [esp + 0x78]
// 0059e35b  d91c24               fstp dword ptr [esp]
// 0059e35e  51                   push ecx
// 0059e35f  50                   push eax
// 0059e360  e83bff0300           call 0x5de2a0
// 0059e365  83c410               add esp, 0x10
// 0059e368  5f                   pop edi
// 0059e369  5b                   pop ebx
// 0059e36a  84c0                 test al, al
// 0059e36c  740c                 je 0x59e37a
// 0059e36e  b001                 mov al, 1
// 0059e370  5e                   pop esi
// 0059e371  81c494000000         add esp, 0x94
// 0059e377  c20800               ret 8
// 0059e37a  8d542438             lea edx, [esp + 0x38]
// 0059e37e  52                   push edx
// 0059e37f  8bce                 mov ecx, esi
// 0059e381  e81af5ffff           call 0x59d8a0
// 0059e386  8d442410             lea eax, [esp + 0x10]
// 0059e38a  50                   push eax
// 0059e38b  8bce                 mov ecx, esi
// 0059e38d  e8fef7ffff           call 0x59db90
// 0059e392  32c0                 xor al, al
// 0059e394  5e                   pop esi
// 0059e395  81c494000000         add esp, 0x94
// 0059e39b  c20800               ret 8

// from server: 84% by king_originala_sol_native
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-cl: 21022

struct Vector3 {
 float x,y,z;
 Vector3():x(0),y(0),z(0){}
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 Vector3& operator+=(const Vector3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}
 Vector3 operator+(const Vector3&v)const{Vector3 r=*this;r+=v;return r;}
 Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}
 Vector3 operator*(float s)const{return Vector3(x*s,y*s,z*s);}
 float&operator[](int i){return (&x)[i];}
};
struct Matrix3 {
 float cells[9];
 Matrix3(const Matrix3&v){*this=v;}
 Matrix3&operator=(const Matrix3&);
 Vector3 operator*(const Vector3&)const;
};
struct Frame {
 Matrix3 rotation;Vector3 translation;
 Frame(const Matrix3&r,const Vector3&t):rotation(r),translation(t){}
 Vector3 vectorToWorldSpace(const Vector3&v)const{return rotation*v;}
};
struct Geometry {void*vtable;Vector3 size;const Vector3&getSize()const{return size;}};
struct Primitive {char opaque[0x9c];Geometry*geometry;const Frame&getCoordinateFrame()const;const Vector3&getSize()const{return geometry->getSize();}};
struct PartInstance {
 char prefix[0x1dc];int partType,formFactor;char gap[0x228-0x1e4];Primitive primitive;
 const Vector3&getPartSizeXml()const{return primitive.getSize();}
 const Frame&getCoordinateFrame()const{return primitive.getCoordinateFrame();}
 Vector3 xmlToUiSize(const Vector3&v)const{Vector3 r=v;switch(formFactor){case 1:r.y*=5.0f/6.0f;break;case 2:r.y*=2.5f;break;}return r;}
 __declspec(noalias) Vector3 uiToXmlSize(const Vector3&)const;
 void setCoordinateFrame(const Frame&);void setPartSizeXml(const Vector3&);void join();
 bool resize(int normal,int amount);
};
bool __cdecl fuzzyEq(const Frame&,const Frame&,float,float);
bool PartInstance::resize(int normal,int amount){
 if(amount==0)return false;
 Vector3 oldSize=getPartSizeXml();
 const Frame&current=getCoordinateFrame();
 Frame oldFrame=current;
 Vector3 ui;
 Vector3 delta;
 float sign=normal<3?1.0f:-1.0f;
 if(partType==1)delta[normal%3]=static_cast<float>(amount);
 else delta=Vector3(static_cast<float>(amount),static_cast<float>(amount),static_cast<float>(amount));
 ui=xmlToUiSize(oldSize);
 Vector3 newUiSize=ui+delta;
 Vector3 convertedSize=uiToXmlSize(newUiSize);
 Vector3 t;
 {
 Vector3 xmlDelta=convertedSize-oldSize;
 t=oldFrame.vectorToWorldSpace(xmlDelta)*0.5f*sign;
 t+=oldFrame.translation;
 }
 Frame desired(oldFrame.rotation,t);
 setCoordinateFrame(desired);
 {
 Vector3 finalSize=uiToXmlSize(newUiSize);
 setPartSizeXml(finalSize);
 }
 join();
 if(fuzzyEq(getCoordinateFrame(),desired,0.00001f,0.00001f))return true;
 setCoordinateFrame(oldFrame);
 setPartSizeXml(oldSize);
 return false;
}
