// from server: 13% by intel
// roc 2012-06 005eb800  unit: G3D::Random  size: 7844 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005eb800
//
// 005eb800  55                   push ebp
// 005eb801  8bec                 mov ebp, esp
// 005eb803  83e4f8               and esp, 0xfffffff8
// 005eb806  81ecfc030000         sub esp, 0x3fc
// 005eb80c  53                   push ebx
// 005eb80d  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 005eb810  56                   push esi
// 005eb811  57                   push edi
// 005eb812  8b7d08               mov edi, dword ptr [ebp + 8]
// 005eb815  8d44246c             lea eax, [esp + 0x6c]
// 005eb819  8bf1                 mov esi, ecx
// 005eb81b  57                   push edi
// 005eb81c  50                   push eax
// 005eb81d  89742464             mov dword ptr [esp + 0x64], esi
// 005eb821  83e307               and ebx, 7
// 005eb824  e897bd2300           call 0x8275c0
// 005eb829  d9442474             fld dword ptr [esp + 0x74]
// 005eb82d  d9e1                 fabs 
// 005eb82f  8d4c2474             lea ecx, [esp + 0x74]
// 005eb833  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005eb83a  57                   push edi
// 005eb83b  d944247c             fld dword ptr [esp + 0x7c]
// 005eb83f  51                   push ecx
// 005eb840  d9e1                 fabs 
// 005eb842  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005eb849  d9842484000000       fld dword ptr [esp + 0x84]
// 005eb850  d9e1                 fabs 
// 005eb852  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005eb859  e862bd2300           call 0x8275c0
// 005eb85e  d944247c             fld dword ptr [esp + 0x7c]
// 005eb862  8a4670               mov al, byte ptr [esi + 0x70]
// 005eb865  d9e1                 fabs 
// 005eb867  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005eb86f  d9842480000000       fld dword ptr [esp + 0x80]
// 005eb876  83c410               add esp, 0x10
// 005eb879  d9e1                 fabs 
// 005eb87b  d9442474             fld dword ptr [esp + 0x74]
// 005eb87f  d9e1                 fabs 
// 005eb881  d9450c               fld dword ptr [ebp + 0xc]
// 005eb884  dceb                 fsub st(3), st(0)
// 005eb886  d9cb                 fxch st(3)
// 005eb888  d95c241c             fstp dword ptr [esp + 0x1c]
// 005eb88c  d9c9                 fxch st(1)
// 005eb88e  dee2                 fsubrp st(2)
// 005eb890  d9c9                 fxch st(1)
// 005eb892  d95c2420             fstp dword ptr [esp + 0x20]
// 005eb896  d95c2424             fstp dword ptr [esp + 0x24]
// 005eb89a  84c0                 test al, al
// 005eb89c  741b                 je 0x5eb8b9
// 005eb89e  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005eb8a6  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005eb8af  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005eb8b7  eb11                 jmp 0x5eb8ca
// 005eb8b9  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005eb8c1  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005eb8ca  0f57e4               xorps xmm4, xmm4
// 005eb8cd  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005eb8d6  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005eb8dc  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005eb8e2  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005eb8e8  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005eb8ee  83fb05               cmp ebx, 5
// 005eb8f1  0f87a4010000         ja 0x5eba9b
// 005eb8f7  ff249d8cd65e00       jmp dword ptr [ebx*4 + 0x5ed68c]
// 005eb8fe  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005eb906  8d542460             lea edx, [esp + 0x60]
// 005eb90a  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005eb910  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005eb918  52                   push edx
// 005eb919  8d4c2420             lea ecx, [esp + 0x20]
// 005eb91d  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005eb923  e818890400           call 0x634240
// 005eb928  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005eb930  f30f1000             movss xmm0, dword ptr [eax]
// 005eb934  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005eb939  0f57e4               xorps xmm4, xmm4
// 005eb93c  f30f59c5             mulss xmm0, xmm5
// 005eb940  f30f59cd             mulss xmm1, xmm5
// 005eb944  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005eb94a  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005eb950  e946010000           jmp 0x5eba9b
// 005eb955  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005eb95d  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005eb963  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005eb969  84c0                 test al, al
// 005eb96b  7413                 je 0x5eb980
// 005eb96d  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005eb975  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005eb97b  e91b010000           jmp 0x5eba9b
// 005eb980  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005eb988  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005eb98e  e908010000           jmp 0x5eba9b
// 005eb993  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005eb999  84c0                 test al, al
// 005eb99b  7419                 je 0x5eb9b6
// 005eb99d  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005eb9a5  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005eb9ab  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005eb9b1  e9e5000000           jmp 0x5eba9b
// 005eb9b6  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005eb9be  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005eb9c4  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005eb9cc  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005eb9d2  e9c4000000           jmp 0x5eba9b
// 005eb9d7  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005eb9dd  84c0                 test al, al
// 005eb9df  7419                 je 0x5eb9fa
// 005eb9e1  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005eb9e9  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005eb9ef  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005eb9f5  e9a1000000           jmp 0x5eba9b
// 005eb9fa  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005eba02  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005eba08  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005eba10  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005eba16  e980000000           jmp 0x5eba9b
// 005eba1b  84c0                 test al, al
// 005eba1d  745a                 je 0x5eba79
// 005eba1f  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005eba26  7441                 je 0x5eba69
// 005eba28  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005eba2d  85c0                 test eax, eax
// 005eba2f  7418                 je 0x5eba49
// 005eba31  68b7000000           push 0xb7
// 005eba36  688027b800           push 0xb82780
// 005eba3b  68cc60b400           push 0xb460cc
// 005eba40  ffd0                 call eax
// 005eba42  83c40c               add esp, 0xc
// 005eba45  84c0                 test al, al
// 005eba47  7515                 jne 0x5eba5e
// 005eba49  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005eba50  680827b800           push 0xb82708
// 005eba55  50                   push eax
// 005eba56  e835683800           call 0x972290
// 005eba5b  83c408               add esp, 8
// 005eba5e  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005eba66  0f57e4               xorps xmm4, xmm4
// 005eba69  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005eba71  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005eba77  eb1c                 jmp 0x5eba95
// 005eba79  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005eba81  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005eba87  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005eba8f  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005eba95  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005eba9b  807e7000             cmp byte ptr [esi + 0x70], 0
// 005eba9f  7419                 je 0x5ebaba
// 005ebaa1  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005ebaa6  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005ebaae  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005ebab4  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005ebaba  85db                 test ebx, ebx
// 005ebabc  0f85da080000         jne 0x5ec39c
// 005ebac2  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ebaca  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005ebacf  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005ebad7  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005ebadc  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005ebae2  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005ebaeb  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005ebaf3  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005ebaf9  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005ebb02  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005ebb0b  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005ebb14  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005ebb1d  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005ebb26  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005ebb2f  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005ebb38  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005ebb41  f30f59c5             mulss xmm0, xmm5
// 005ebb45  f30f59cd             mulss xmm1, xmm5
// 005ebb49  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005ebb52  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005ebb5b  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005ebb60  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005ebb69  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005ebb72  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005ebb79  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005ebb7f  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005ebb88  0f28e3               movaps xmm4, xmm3
// 005ebb8b  f30f5ce0             subss xmm4, xmm0
// 005ebb8f  0f28eb               movaps xmm5, xmm3
// 005ebb92  f30f5ce9             subss xmm5, xmm1
// 005ebb96  51                   push ecx
// 005ebb97  8d542464             lea edx, [esp + 0x64]
// 005ebb9b  f30f5cc3             subss xmm0, xmm3
// 005ebb9f  0f28d3               movaps xmm2, xmm3
// 005ebba2  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005ebba9  f30f5ccb             subss xmm1, xmm3
// 005ebbad  52                   push edx
// 005ebbae  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005ebbb7  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005ebbc0  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005ebbc9  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005ebbd2  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005ebbdb  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005ebbe4  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005ebbed  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005ebbf6  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005ebbff  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005ebc08  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005ebc11  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005ebc1a  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005ebc23  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005ebc2c  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005ebc35  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005ebc3e  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005ebc47  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005ebc50  e86bb92300           call 0x8275c0
// 005ebc55  8d442474             lea eax, [esp + 0x74]
// 005ebc59  50                   push eax
// 005ebc5a  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005ebc61  51                   push ecx
// 005ebc62  e859b92300           call 0x8275c0
// 005ebc67  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005ebc6f  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005ebc75  0f57c8               xorps xmm1, xmm0
// 005ebc78  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005ebc81  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005ebc87  8d9424d0000000       lea edx, [esp + 0xd0]
// 005ebc8e  0f57c8               xorps xmm1, xmm0
// 005ebc91  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ebc97  52                   push edx
// 005ebc98  8d8424ec000000       lea eax, [esp + 0xec]
// 005ebc9f  50                   push eax
// 005ebca0  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005ebca9  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005ebcb2  e809b92300           call 0x8275c0
// 005ebcb7  83c418               add esp, 0x18
// 005ebcba  8d4c2440             lea ecx, [esp + 0x40]
// 005ebcbe  51                   push ecx
// 005ebcbf  8d8c2480010000       lea ecx, [esp + 0x180]
// 005ebcc6  e875850400           call 0x634240
// 005ebccb  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005ebcd2  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005ebcd8  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005ebcdf  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005ebce6  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005ebce9  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005ebcf2  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005ebcf8  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005ebd01  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005ebd07  89542478             mov dword ptr [esp + 0x78], edx
// 005ebd0b  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005ebd12  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005ebd1b  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005ebd21  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005ebd28  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005ebd2f  89942484000000       mov dword ptr [esp + 0x84], edx
// 005ebd36  8b542460             mov edx, dword ptr [esp + 0x60]
// 005ebd3a  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005ebd43  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005ebd48  8944247c             mov dword ptr [esp + 0x7c], eax
// 005ebd4c  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005ebd53  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005ebd5a  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005ebd5e  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005ebd67  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005ebd70  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005ebd79  89942490000000       mov dword ptr [esp + 0x90], edx
// 005ebd80  89842488000000       mov dword ptr [esp + 0x88], eax
// 005ebd87  8b442464             mov eax, dword ptr [esp + 0x64]
// 005ebd8b  8d542478             lea edx, [esp + 0x78]
// 005ebd8f  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005ebd96  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005ebd9f  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005ebda8  52                   push edx
// 005ebda9  8bce                 mov ecx, esi
// 005ebdab  89842498000000       mov dword ptr [esp + 0x98], eax
// 005ebdb2  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005ebdbb  e800e5ffff           call 0x5ea2c0
// 005ebdc0  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005ebdc9  8b7d24               mov edi, dword ptr [ebp + 0x24]
// 005ebdcc  d907                 fld dword ptr [edi]
// 005ebdce  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005ebdd4  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005ebddd  d95e24               fstp dword ptr [esi + 0x24]
// 005ebde0  d94704               fld dword ptr [edi + 4]
// 005ebde3  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005ebde9  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005ebdf2  d95e28               fstp dword ptr [esi + 0x28]
// 005ebdf5  8d84248c010000       lea eax, [esp + 0x18c]
// 005ebdfc  50                   push eax
// 005ebdfd  8d4c2464             lea ecx, [esp + 0x64]
// 005ebe01  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005ebe07  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005ebe10  51                   push ecx
// 005ebe11  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005ebe17  e8a4b72300           call 0x8275c0
// 005ebe1c  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005ebe23  52                   push edx
// 005ebe24  8d8424d8000000       lea eax, [esp + 0xd8]
// 005ebe2b  50                   push eax
// 005ebe2c  e88fb72300           call 0x8275c0
// 005ebe31  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ebe37  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005ebe40  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ebe46  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ebe4d  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005ebe54  51                   push ecx
// 005ebe55  8d9424ec000000       lea edx, [esp + 0xec]
// 005ebe5c  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005ebe65  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ebe6b  52                   push edx
// 005ebe6c  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005ebe75  e846b72300           call 0x8275c0
// 005ebe7a  83c418               add esp, 0x18
// 005ebe7d  8d442440             lea eax, [esp + 0x40]
// 005ebe81  50                   push eax
// 005ebe82  8d8c2410010000       lea ecx, [esp + 0x110]
// 005ebe89  e8b2830400           call 0x634240
// 005ebe8e  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005ebe95  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005ebe9c  894c2478             mov dword ptr [esp + 0x78], ecx
// 005ebea0  8954247c             mov dword ptr [esp + 0x7c], edx
// 005ebea4  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005ebeaa  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005ebeb1  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005ebeb8  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005ebebf  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005ebec8  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005ebece  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005ebed7  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005ebedd  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005ebee6  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005ebeec  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005ebef5  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005ebefb  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005ebf02  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005ebf06  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005ebf0f  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ebf15  89842480000000       mov dword ptr [esp + 0x80], eax
// 005ebf1c  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005ebf23  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005ebf2a  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005ebf33  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ebf39  8d4c2478             lea ecx, [esp + 0x78]
// 005ebf3d  89942488000000       mov dword ptr [esp + 0x88], edx
// 005ebf44  8b542464             mov edx, dword ptr [esp + 0x64]
// 005ebf48  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005ebf4f  8b442468             mov eax, dword ptr [esp + 0x68]
// 005ebf53  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005ebf5c  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ebf62  8d5e44               lea ebx, [esi + 0x44]
// 005ebf65  51                   push ecx
// 005ebf66  8bcb                 mov ecx, ebx
// 005ebf68  89942498000000       mov dword ptr [esp + 0x98], edx
// 005ebf6f  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005ebf76  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005ebf7f  e83ce3ffff           call 0x5ea2c0
// 005ebf84  d94708               fld dword ptr [edi + 8]
// 005ebf87  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005ebf90  d95e68               fstp dword ptr [esi + 0x68]
// 005ebf93  d9470c               fld dword ptr [edi + 0xc]
// 005ebf96  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005ebf9c  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005ebfa5  d95e6c               fstp dword ptr [esi + 0x6c]
// 005ebfa8  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005ebfae  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005ebfb7  8d94248c010000       lea edx, [esp + 0x18c]
// 005ebfbe  52                   push edx
// 005ebfbf  8d442464             lea eax, [esp + 0x64]
// 005ebfc3  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005ebfc9  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005ebfd2  50                   push eax
// 005ebfd3  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005ebfd9  e8e2b52300           call 0x8275c0
// 005ebfde  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005ebfe5  51                   push ecx
// 005ebfe6  8d9424d8000000       lea edx, [esp + 0xd8]
// 005ebfed  52                   push edx
// 005ebfee  e8cdb52300           call 0x8275c0
// 005ebff3  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ebff9  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005ec002  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ec008  8d8424d0000000       lea eax, [esp + 0xd0]
// 005ec00f  50                   push eax
// 005ec010  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005ec017  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005ec020  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ec026  51                   push ecx
// 005ec027  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005ec030  e88bb52300           call 0x8275c0
// 005ec035  83c418               add esp, 0x18
// 005ec038  8d542440             lea edx, [esp + 0x40]
// 005ec03c  52                   push edx
// 005ec03d  8d8c2430010000       lea ecx, [esp + 0x130]
// 005ec044  e8f7810400           call 0x634240
// 005ec049  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005ec050  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005ec057  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005ec05e  89442478             mov dword ptr [esp + 0x78], eax
// 005ec062  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005ec069  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005ec06d  89942480000000       mov dword ptr [esp + 0x80], edx
// 005ec074  89842484000000       mov dword ptr [esp + 0x84], eax
// 005ec07b  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005ec081  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005ec088  8b442460             mov eax, dword ptr [esp + 0x60]
// 005ec08c  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005ec093  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005ec09c  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005ec0a2  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005ec0ab  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005ec0b1  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005ec0ba  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005ec0c0  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005ec0c9  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005ec0cf  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005ec0d8  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ec0de  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005ec0e5  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005ec0e9  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005ec0f2  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ec0f8  89842490000000       mov dword ptr [esp + 0x90], eax
// 005ec0ff  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005ec106  8b542468             mov edx, dword ptr [esp + 0x68]
// 005ec10a  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005ec111  8d442478             lea eax, [esp + 0x78]
// 005ec115  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005ec11e  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ec124  8d8e88000000         lea ecx, [esi + 0x88]
// 005ec12a  50                   push eax
// 005ec12b  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005ec132  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005ec13b  894c2460             mov dword ptr [esp + 0x60], ecx
// 005ec13f  e87ce1ffff           call 0x5ea2c0
// 005ec144  d94710               fld dword ptr [edi + 0x10]
// 005ec147  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005ec150  d99eac000000         fstp dword ptr [esi + 0xac]
// 005ec156  d94714               fld dword ptr [edi + 0x14]
// 005ec159  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005ec15f  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005ec168  d99eb0000000         fstp dword ptr [esi + 0xb0]
// 005ec16e  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005ec174  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005ec17d  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005ec184  51                   push ecx
// 005ec185  8d542464             lea edx, [esp + 0x64]
// 005ec189  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005ec18f  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005ec198  52                   push edx
// 005ec199  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005ec19f  e81cb42300           call 0x8275c0
// 005ec1a4  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005ec1ab  50                   push eax
// 005ec1ac  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005ec1b3  51                   push ecx
// 005ec1b4  e807b42300           call 0x8275c0
// 005ec1b9  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ec1bf  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ec1c6  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005ec1cf  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ec1d5  8d9424d0000000       lea edx, [esp + 0xd0]
// 005ec1dc  52                   push edx
// 005ec1dd  8d8424ec000000       lea eax, [esp + 0xec]
// 005ec1e4  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005ec1ed  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ec1f3  50                   push eax
// 005ec1f4  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005ec1fd  e8beb32300           call 0x8275c0
// 005ec202  83c418               add esp, 0x18
// 005ec205  8d4c2440             lea ecx, [esp + 0x40]
// 005ec209  51                   push ecx
// 005ec20a  8d8c2420010000       lea ecx, [esp + 0x120]
// 005ec211  e82a800400           call 0x634240
// 005ec216  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005ec21d  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005ec224  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005ec22b  89542478             mov dword ptr [esp + 0x78], edx
// 005ec22f  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005ec236  8944247c             mov dword ptr [esp + 0x7c], eax
// 005ec23a  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005ec241  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005ec248  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005ec24f  89942484000000       mov dword ptr [esp + 0x84], edx
// 005ec256  89842488000000       mov dword ptr [esp + 0x88], eax
// 005ec25d  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005ec263  8b542460             mov edx, dword ptr [esp + 0x60]
// 005ec267  8b442464             mov eax, dword ptr [esp + 0x64]
// 005ec26b  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005ec274  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005ec27a  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005ec283  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005ec289  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005ec292  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005ec298  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005ec2a1  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005ec2a7  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005ec2b0  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ec2b6  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005ec2bd  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005ec2c1  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005ec2ca  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ec2d0  89942490000000       mov dword ptr [esp + 0x90], edx
// 005ec2d7  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005ec2de  8d542478             lea edx, [esp + 0x78]
// 005ec2e2  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005ec2eb  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ec2f1  8d8ecc000000         lea ecx, [esi + 0xcc]
// 005ec2f7  52                   push edx
// 005ec2f8  89842498000000       mov dword ptr [esp + 0x98], eax
// 005ec2ff  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005ec308  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005ec30f  e8acdfffff           call 0x5ea2c0
// 005ec314  d94718               fld dword ptr [edi + 0x18]
// 005ec317  d99ef0000000         fstp dword ptr [esi + 0xf0]
// 005ec31d  56                   push esi
// 005ec31e  d9471c               fld dword ptr [edi + 0x1c]
// 005ec321  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005ec324  8b07                 mov eax, dword ptr [edi]
// 005ec326  d99ef4000000         fstp dword ptr [esi + 0xf4]
// 005ec32c  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ec32f  8bcf                 mov ecx, edi
// 005ec331  ffd2                 call edx
// 005ec333  8bf0                 mov esi, eax
// 005ec335  8b07                 mov eax, dword ptr [edi]
// 005ec337  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ec33a  53                   push ebx
// 005ec33b  8bcf                 mov ecx, edi
// 005ec33d  ffd2                 call edx
// 005ec33f  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005ec343  8bd8                 mov ebx, eax
// 005ec345  8b07                 mov eax, dword ptr [edi]
// 005ec347  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ec34a  51                   push ecx
// 005ec34b  8bcf                 mov ecx, edi
// 005ec34d  ffd2                 call edx
// 005ec34f  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005ec356  8944243c             mov dword ptr [esp + 0x3c], eax
// 005ec35a  8b07                 mov eax, dword ptr [edi]
// 005ec35c  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ec35f  51                   push ecx
// 005ec360  8bcf                 mov ecx, edi
// 005ec362  ffd2                 call edx
// 005ec364  8b17                 mov edx, dword ptr [edi]
// 005ec366  8b5218               mov edx, dword ptr [edx + 0x18]
// 005ec369  50                   push eax
// 005ec36a  89442460             mov dword ptr [esp + 0x60], eax
// 005ec36e  8b442440             mov eax, dword ptr [esp + 0x40]
// 005ec372  50                   push eax
// 005ec373  53                   push ebx
// 005ec374  56                   push esi
// 005ec375  8bcf                 mov ecx, edi
// 005ec377  ffd2                 call edx
// 005ec379  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005ec37c  85c0                 test eax, eax
// 005ec37e  7413                 je 0x5ec393
// 005ec380  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005ec384  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005ec388  8930                 mov dword ptr [eax], esi
// 005ec38a  895804               mov dword ptr [eax + 4], ebx
// 005ec38d  894808               mov dword ptr [eax + 8], ecx
// 005ec390  89500c               mov dword ptr [eax + 0xc], edx
// 005ec393  5f                   pop edi
// 005ec394  5e                   pop esi
// 005ec395  5b                   pop ebx
// 005ec396  8be5                 mov esp, ebp
// 005ec398  5d                   pop ebp
// 005ec399  c22000               ret 0x20
// 005ec39c  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005ec3a3  743c                 je 0x5ec3e1
// 005ec3a5  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005ec3a9  7536                 jne 0x5ec3e1
// 005ec3ab  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005ec3b0  85c0                 test eax, eax
// 005ec3b2  7418                 je 0x5ec3cc
// 005ec3b4  6801010000           push 0x101
// 005ec3b9  688027b800           push 0xb82780
// 005ec3be  680027b800           push 0xb82700
// 005ec3c3  ffd0                 call eax
// 005ec3c5  83c40c               add esp, 0xc
// 005ec3c8  84c0                 test al, al
// 005ec3ca  7515                 jne 0x5ec3e1
// 005ec3cc  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005ec3d3  688826b800           push 0xb82688
// 005ec3d8  50                   push eax
// 005ec3d9  e8b25e3800           call 0x972290
// 005ec3de  83c408               add esp, 8
// 005ec3e1  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005ec3e7  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ec3ee  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005ec3f6  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005ec3fe  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005ec403  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005ec409  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005ec411  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005ec416  8d4c2460             lea ecx, [esp + 0x60]
// 005ec41a  51                   push ecx
// 005ec41b  f30f59c2             mulss xmm0, xmm2
// 005ec41f  f30f59ca             mulss xmm1, xmm2
// 005ec423  8d4c2420             lea ecx, [esp + 0x20]
// 005ec427  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005ec430  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005ec439  e8027e0400           call 0x634240
// 005ec43e  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005ec447  f30f5e00             divss xmm0, dword ptr [eax]
// 005ec44b  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005ec450  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005ec453  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005ec456  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005ec45b  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005ec463  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005ec469  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005ec472  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005ec47b  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005ec480  33d2                 xor edx, edx
// 005ec482  33db                 xor ebx, ebx
// 005ec484  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005ec48d  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005ec494  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005ec49b  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005ec4a1  0f2fd7               comiss xmm2, xmm7
// 005ec4a4  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005ec4aa  8954243c             mov dword ptr [esp + 0x3c], edx
// 005ec4ae  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005ec4b7  770a                 ja 0x5ec4c3
// 005ec4b9  85d2                 test edx, edx
// 005ec4bb  0f85d2feffff         jne 0x5ec393
// 005ec4c1  eb04                 jmp 0x5ec4c7
// 005ec4c3  85d2                 test edx, edx
// 005ec4c5  7504                 jne 0x5ec4cb
// 005ec4c7  f30f5cc4             subss xmm0, xmm4
// 005ec4cb  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005ec4cf  80797000             cmp byte ptr [ecx + 0x70], 0
// 005ec4d3  7421                 je 0x5ec4f6
// 005ec4d5  f30f58c7             addss xmm0, xmm7
// 005ec4d9  0f2fc2               comiss xmm0, xmm2
// 005ec4dc  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005ec4e5  8d44241c             lea eax, [esp + 0x1c]
// 005ec4e9  7707                 ja 0x5ec4f2
// 005ec4eb  8d84240c030000       lea eax, [esp + 0x30c]
// 005ec4f2  f30f1010             movss xmm2, dword ptr [eax]
// 005ec4f6  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005ec4ff  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005ec505  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ec50c  f30f58cb             addss xmm1, xmm3
// 005ec510  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005ec515  33c0                 xor eax, eax
// 005ec517  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005ec51d  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005ec526  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005ec52d  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005ec533  0f2ff0               comiss xmm6, xmm0
// 005ec536  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005ec53f  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005ec545  7708                 ja 0x5ec54f
// 005ec547  85c0                 test eax, eax
// 005ec549  0f852b110000         jne 0x5ed67a
// 005ec54f  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005ec555  85c0                 test eax, eax
// 005ec557  7504                 jne 0x5ec55d
// 005ec559  f30f5ccc             subss xmm1, xmm4
// 005ec55d  0f28f1               movaps xmm6, xmm1
// 005ec560  f30f58f0             addss xmm6, xmm0
// 005ec564  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005ec569  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005ec572  8d442420             lea eax, [esp + 0x20]
// 005ec576  7707                 ja 0x5ec57f
// 005ec578  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005ec57f  80797000             cmp byte ptr [ecx + 0x70], 0
// 005ec583  f30f1000             movss xmm0, dword ptr [eax]
// 005ec587  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005ec58d  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005ec596  f30f58c3             addss xmm0, xmm3
// 005ec59a  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005ec5a3  0f57c0               xorps xmm0, xmm0
// 005ec5a6  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005ec5ac  740f                 je 0x5ec5bd
// 005ec5ae  e8dddcffff           call 0x5ea290
// 005ec5b3  d80d94deb600         fmul dword ptr [0xb6de94]
// 005ec5b9  d95c2440             fstp dword ptr [esp + 0x40]
// 005ec5bd  0f28dd               movaps xmm3, xmm5
// 005ec5c0  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005ec5c9  0f28c3               movaps xmm0, xmm3
// 005ec5cc  f30f59c4             mulss xmm0, xmm4
// 005ec5d0  f30f5cd7             subss xmm2, xmm7
// 005ec5d4  f30f59d3             mulss xmm2, xmm3
// 005ec5d8  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005ec5de  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005ec5e4  f30f58d3             addss xmm2, xmm3
// 005ec5e8  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005ec5ee  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005ec5f4  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005ec5fa  0f28c5               movaps xmm0, xmm5
// 005ec5fd  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005ec606  0f28e9               movaps xmm5, xmm1
// 005ec609  0f28f0               movaps xmm6, xmm0
// 005ec60c  f30f59f4             mulss xmm6, xmm4
// 005ec610  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005ec616  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005ec61c  f30f5ccb             subss xmm1, xmm3
// 005ec620  f30f59e8             mulss xmm5, xmm0
// 005ec624  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005ec62a  f30f59c8             mulss xmm1, xmm0
// 005ec62e  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005ec634  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005ec63d  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005ec646  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005ec64f  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005ec658  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005ec661  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005ec66a  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005ec673  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005ec67c  85d2                 test edx, edx
// 005ec67e  753f                 jne 0x5ec6bf
// 005ec680  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005ec686  0f28c4               movaps xmm0, xmm4
// 005ec689  f30f58c3             addss xmm0, xmm3
// 005ec68d  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005ec696  0f28c3               movaps xmm0, xmm3
// 005ec699  f30f58c2             addss xmm0, xmm2
// 005ec69d  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005ec6a6  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005ec6af  0f28c4               movaps xmm0, xmm4
// 005ec6b2  f30f58c3             addss xmm0, xmm3
// 005ec6b6  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005ec6bf  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005ec6c5  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005ec6ca  772f                 ja 0x5ec6fb
// 005ec6cc  0f28c6               movaps xmm0, xmm6
// 005ec6cf  f30f58c5             addss xmm0, xmm5
// 005ec6d3  f30f58f1             addss xmm6, xmm1
// 005ec6d7  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005ec6e0  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005ec6e9  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005ec6f2  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005ec6fb  8d9424cc000000       lea edx, [esp + 0xcc]
// 005ec702  52                   push edx
// 005ec703  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ec70a  e8317b0400           call 0x634240
// 005ec70f  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005ec714  f30f1008             movss xmm1, dword ptr [eax]
// 005ec718  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005ec71e  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005ec724  8d8424d8000000       lea eax, [esp + 0xd8]
// 005ec72b  50                   push eax
// 005ec72c  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ec733  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005ec73c  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005ec745  e8f67a0400           call 0x634240
// 005ec74a  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005ec74f  f30f1008             movss xmm1, dword ptr [eax]
// 005ec753  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005ec759  f30f584c244c         addss xmm1, dword ptr [esp + 0x4c]
// 005ec75f  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005ec766  51                   push ecx
// 005ec767  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ec76e  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005ec777  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005ec780  e8bb7a0400           call 0x634240
// 005ec785  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005ec78b  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005ec790  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005ec796  f30f5c08             subss xmm1, dword ptr [eax]
// 005ec79a  8d94248c010000       lea edx, [esp + 0x18c]
// 005ec7a1  52                   push edx
// 005ec7a2  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ec7a9  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005ec7b2  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005ec7bb  e8807a0400           call 0x634240
// 005ec7c0  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005ec7c6  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005ec7cb  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005ec7d1  f30f5c08             subss xmm1, dword ptr [eax]
// 005ec7d5  8d842498010000       lea eax, [esp + 0x198]
// 005ec7dc  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005ec7e5  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ec7ed  50                   push eax
// 005ec7ee  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005ec7f5  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005ec7fb  0f57c0               xorps xmm0, xmm0
// 005ec7fe  51                   push ecx
// 005ec7ff  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005ec806  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005ec80f  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005ec815  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005ec81b  e8f0790400           call 0x634210
// 005ec820  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005ec829  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005ec832  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005ec83b  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005ec844  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005ec84d  8d9424ec000000       lea edx, [esp + 0xec]
// 005ec854  52                   push edx
// 005ec855  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005ec85c  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005ec865  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005ec86e  50                   push eax
// 005ec86f  8d8c2484010000       lea ecx, [esp + 0x184]
// 005ec876  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005ec87f  e88c790400           call 0x634210
// 005ec884  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005ec88d  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005ec893  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005ec89c  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005ec8a2  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005ec8ab  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005ec8b1  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005ec8ba  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005ec8c0  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005ec8c9  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005ec8d2  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005ec8db  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005ec8e4  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005ec8ed  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005ec8f6  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005ec8ff  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005ec908  8d4c246c             lea ecx, [esp + 0x6c]
// 005ec90c  51                   push ecx
// 005ec90d  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005ec914  52                   push edx
// 005ec915  e8a6ac2300           call 0x8275c0
// 005ec91a  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005ec923  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005ec92c  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005ec935  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005ec93c  50                   push eax
// 005ec93d  8d8c2484030000       lea ecx, [esp + 0x384]
// 005ec944  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005ec94d  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ec955  51                   push ecx
// 005ec956  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005ec95f  e85cac2300           call 0x8275c0
// 005ec964  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005ec96a  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005ec973  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005ec979  8d942470030000       lea edx, [esp + 0x370]
// 005ec980  52                   push edx
// 005ec981  8d842450030000       lea eax, [esp + 0x350]
// 005ec988  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005ec991  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ec997  50                   push eax
// 005ec998  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005ec9a1  e81aac2300           call 0x8275c0
// 005ec9a6  83c418               add esp, 0x18
// 005ec9a9  8d8c2430030000       lea ecx, [esp + 0x330]
// 005ec9b0  51                   push ecx
// 005ec9b1  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005ec9b8  e883780400           call 0x634240
// 005ec9bd  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005ec9c6  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005ec9cd  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005ec9d4  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005ec9db  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005ec9e4  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005ec9ed  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005ec9f6  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005ec9ff  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005eca08  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005eca11  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005eca1a  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005eca23  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005eca2c  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005eca35  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005eca3e  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005eca47  89942448020000       mov dword ptr [esp + 0x248], edx
// 005eca4e  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005eca55  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005eca5e  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005eca67  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005eca6e  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005eca75  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005eca7e  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005eca87  89942454020000       mov dword ptr [esp + 0x254], edx
// 005eca8e  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005eca95  89842458020000       mov dword ptr [esp + 0x258], eax
// 005eca9c  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005ecaa3  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005ecaac  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005ecab5  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005ecabc  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005ecac3  89942460020000       mov dword ptr [esp + 0x260], edx
// 005ecaca  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005ecad3  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005ecadc  8d54246c             lea edx, [esp + 0x6c]
// 005ecae0  89842464020000       mov dword ptr [esp + 0x264], eax
// 005ecae7  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005ecaee  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005ecaf5  52                   push edx
// 005ecaf6  8d842470030000       lea eax, [esp + 0x370]
// 005ecafd  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005ecb06  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005ecb0f  50                   push eax
// 005ecb10  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005ecb17  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005ecb20  e89baa2300           call 0x8275c0
// 005ecb25  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005ecb2e  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005ecb37  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005ecb40  8d8c2498030000       lea ecx, [esp + 0x398]
// 005ecb47  51                   push ecx
// 005ecb48  8d942460030000       lea edx, [esp + 0x360]
// 005ecb4f  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005ecb58  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ecb60  52                   push edx
// 005ecb61  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005ecb6a  e851aa2300           call 0x8275c0
// 005ecb6f  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005ecb75  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005ecb7e  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005ecb84  8d842400040000       lea eax, [esp + 0x400]
// 005ecb8b  50                   push eax
// 005ecb8c  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005ecb93  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005ecb9c  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ecba2  51                   push ecx
// 005ecba3  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005ecbac  e80faa2300           call 0x8275c0
// 005ecbb1  83c418               add esp, 0x18
// 005ecbb4  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005ecbbb  52                   push edx
// 005ecbbc  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005ecbc3  e878760400           call 0x634240
// 005ecbc8  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005ecbd1  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005ecbd8  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005ecbdf  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005ecbe6  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005ecbef  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005ecbf8  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005ecc01  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005ecc0a  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005ecc13  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005ecc1c  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005ecc25  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005ecc2e  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005ecc37  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005ecc40  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005ecc49  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005ecc52  89842490020000       mov dword ptr [esp + 0x290], eax
// 005ecc59  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005ecc60  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005ecc69  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005ecc72  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005ecc79  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005ecc80  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005ecc89  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005ecc92  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005ecc99  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005ecca0  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005ecca7  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005eccae  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005eccb7  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005eccc0  89942498020000       mov dword ptr [esp + 0x298], edx
// 005eccc7  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005eccce  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005eccd5  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005eccde  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005ecce7  8d44246c             lea eax, [esp + 0x6c]
// 005ecceb  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005eccf2  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005eccf9  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005ecd00  50                   push eax
// 005ecd01  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005ecd08  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005ecd11  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005ecd1a  51                   push ecx
// 005ecd1b  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005ecd22  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005ecd2b  e890a82300           call 0x8275c0
// 005ecd30  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005ecd39  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005ecd42  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005ecd4b  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005ecd54  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ecd5c  8d94248c030000       lea edx, [esp + 0x38c]
// 005ecd63  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005ecd6c  52                   push edx
// 005ecd6d  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005ecd74  50                   push eax
// 005ecd75  e846a82300           call 0x8275c0
// 005ecd7a  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005ecd80  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005ecd89  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005ecd8f  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005ecd96  51                   push ecx
// 005ecd97  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005ecd9e  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005ecda7  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ecdad  52                   push edx
// 005ecdae  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005ecdb7  e804a82300           call 0x8275c0
// 005ecdbc  83c418               add esp, 0x18
// 005ecdbf  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005ecdc6  50                   push eax
// 005ecdc7  8d8c2480010000       lea ecx, [esp + 0x180]
// 005ecdce  e86d740400           call 0x634240
// 005ecdd3  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005ecddc  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005ecde3  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005ecdea  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005ecdf1  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005ecdfa  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005ece03  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005ece0c  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005ece15  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005ece1e  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005ece27  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005ece30  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005ece39  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005ece42  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005ece4b  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005ece54  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 005ece5d  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 005ece64  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 005ece6b  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 005ece74  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 005ece7d  89942404020000       mov dword ptr [esp + 0x204], edx
// 005ece84  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 005ece8b  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 005ece94  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005ece9a  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 005ecea1  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 005ecea8  89942410020000       mov dword ptr [esp + 0x210], edx
// 005eceaf  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 005eceb6  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 005ecebf  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ecec5  89842408020000       mov dword ptr [esp + 0x208], eax
// 005ececc  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 005eced3  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 005eceda  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005ecee3  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ecee9  8d4c246c             lea ecx, [esp + 0x6c]
// 005eceed  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 005ecef4  89842414020000       mov dword ptr [esp + 0x214], eax
// 005ecefb  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 005ecf02  51                   push ecx
// 005ecf03  8d942410010000       lea edx, [esp + 0x110]
// 005ecf0a  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 005ecf13  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ecf19  52                   push edx
// 005ecf1a  89842428020000       mov dword ptr [esp + 0x228], eax
// 005ecf21  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005ecf2a  e891a62300           call 0x8275c0
// 005ecf2f  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005ecf38  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 005ecf41  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005ecf4a  8d842404040000       lea eax, [esp + 0x404]
// 005ecf51  50                   push eax
// 005ecf52  8d8c2438010000       lea ecx, [esp + 0x138]
// 005ecf59  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 005ecf62  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ecf6a  51                   push ecx
// 005ecf6b  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 005ecf74  e847a62300           call 0x8275c0
// 005ecf79  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005ecf7f  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 005ecf88  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005ecf8e  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005ecf97  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ecf9d  8d9424b8030000       lea edx, [esp + 0x3b8]
// 005ecfa4  52                   push edx
// 005ecfa5  8d842430010000       lea eax, [esp + 0x130]
// 005ecfac  50                   push eax
// 005ecfad  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 005ecfb6  e805a62300           call 0x8275c0
// 005ecfbb  83c418               add esp, 0x18
// 005ecfbe  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 005ecfc5  51                   push ecx
// 005ecfc6  8d4c242c             lea ecx, [esp + 0x2c]
// 005ecfca  e871720400           call 0x634240
// 005ecfcf  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 005ecfd8  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 005ecfdf  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 005ecfe6  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 005ecfed  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005ecff6  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 005ecfff  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005ed008  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 005ed011  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005ed01a  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 005ed023  89542478             mov dword ptr [esp + 0x78], edx
// 005ed027  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 005ed02e  8944247c             mov dword ptr [esp + 0x7c], eax
// 005ed032  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005ed039  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005ed042  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 005ed04b  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005ed052  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 005ed059  89942484000000       mov dword ptr [esp + 0x84], edx
// 005ed060  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 005ed067  89842488000000       mov dword ptr [esp + 0x88], eax
// 005ed06e  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 005ed075  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005ed07e  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 005ed087  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005ed08e  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 005ed095  89942490000000       mov dword ptr [esp + 0x90], edx
// 005ed09c  8b17                 mov edx, dword ptr [edi]
// 005ed09e  8b5210               mov edx, dword ptr [edx + 0x10]
// 005ed0a1  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005ed0aa  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 005ed0b3  89842494000000       mov dword ptr [esp + 0x94], eax
// 005ed0ba  8d842448020000       lea eax, [esp + 0x248]
// 005ed0c1  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005ed0c8  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005ed0d1  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 005ed0da  50                   push eax
// 005ed0db  8bcf                 mov ecx, edi
// 005ed0dd  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005ed0e6  ffd2                 call edx
// 005ed0e8  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 005ed0ef  8b07                 mov eax, dword ptr [edi]
// 005ed0f1  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ed0f4  8d8c2490020000       lea ecx, [esp + 0x290]
// 005ed0fb  51                   push ecx
// 005ed0fc  8bcf                 mov ecx, edi
// 005ed0fe  ffd2                 call edx
// 005ed100  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 005ed107  8b07                 mov eax, dword ptr [edi]
// 005ed109  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ed10c  8d8c2400020000       lea ecx, [esp + 0x200]
// 005ed113  51                   push ecx
// 005ed114  8bcf                 mov ecx, edi
// 005ed116  ffd2                 call edx
// 005ed118  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 005ed11f  8b07                 mov eax, dword ptr [edi]
// 005ed121  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ed124  8d4c2478             lea ecx, [esp + 0x78]
// 005ed128  51                   push ecx
// 005ed129  8bcf                 mov ecx, edi
// 005ed12b  ffd2                 call edx
// 005ed12d  89842460010000       mov dword ptr [esp + 0x160], eax
// 005ed134  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005ed13b  40                   inc eax
// 005ed13c  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005ed143  3bc3                 cmp eax, ebx
// 005ed145  8d84246c010000       lea eax, [esp + 0x16c]
// 005ed14c  7c07                 jl 0x5ed155
// 005ed14e  8d8424e8000000       lea eax, [esp + 0xe8]
// 005ed155  8b18                 mov ebx, dword ptr [eax]
// 005ed157  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 005ed15e  8bc8                 mov ecx, eax
// 005ed160  40                   inc eax
// 005ed161  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005ed168  85c9                 test ecx, ecx
// 005ed16a  0f85f9000000         jne 0x5ed269
// 005ed170  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 005ed177  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005ed17a  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 005ed183  8911                 mov dword ptr [ecx], edx
// 005ed185  f30f1106             movss dword ptr [esi], xmm0
// 005ed189  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 005ed192  f30f114604           movss dword ptr [esi + 4], xmm0
// 005ed197  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 005ed1a0  f30f114608           movss dword ptr [esi + 8], xmm0
// 005ed1a5  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 005ed1ae  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 005ed1b3  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 005ed1bc  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 005ed1c1  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 005ed1ca  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 005ed1cf  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 005ed1d8  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 005ed1dd  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 005ed1e6  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 005ed1eb  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 005ed1f4  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 005ed1f9  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 005ed202  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 005ed207  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 005ed210  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 005ed215  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 005ed21e  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 005ed223  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 005ed22c  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 005ed231  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 005ed23a  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 005ed23f  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 005ed248  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 005ed24d  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 005ed256  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 005ed25b  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 005ed264  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 005ed269  8bd3                 mov edx, ebx
// 005ed26b  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 005ed270  8d0c9501000000       lea ecx, [edx*4 + 1]
// 005ed277  8bd0                 mov edx, eax
// 005ed279  40                   inc eax
// 005ed27a  3bd1                 cmp edx, ecx
// 005ed27c  0f8501010000         jne 0x5ed383
// 005ed282  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005ed289  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005ed28c  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 005ed295  894a04               mov dword ptr [edx + 4], ecx
// 005ed298  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 005ed29d  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 005ed2a6  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 005ed2ab  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 005ed2b4  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 005ed2b9  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 005ed2c2  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 005ed2c7  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 005ed2d0  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 005ed2d5  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 005ed2de  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 005ed2e3  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 005ed2ec  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 005ed2f1  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 005ed2fa  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 005ed2ff  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 005ed308  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 005ed30d  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 005ed316  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 005ed31b  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 005ed324  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 005ed329  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 005ed332  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 005ed337  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 005ed340  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 005ed345  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 005ed34e  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 005ed353  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 005ed35c  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 005ed361  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 005ed36a  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 005ed372  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 005ed37b  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 005ed383  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005ed387  41                   inc ecx
// 005ed388  0fafcb               imul ecx, ebx
// 005ed38b  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 005ed392  8bc8                 mov ecx, eax
// 005ed394  40                   inc eax
// 005ed395  3bca                 cmp ecx, edx
// 005ed397  0f852e010000         jne 0x5ed4cb
// 005ed39d  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 005ed3a4  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005ed3a7  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005ed3b0  895108               mov dword ptr [ecx + 8], edx
// 005ed3b3  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 005ed3bb  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 005ed3c4  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 005ed3cc  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 005ed3d5  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 005ed3dd  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 005ed3e6  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 005ed3ee  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 005ed3f7  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 005ed3ff  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 005ed408  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 005ed410  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 005ed419  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 005ed421  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 005ed42a  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 005ed432  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 005ed43b  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 005ed443  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 005ed44c  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 005ed454  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 005ed45d  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 005ed465  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 005ed46e  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 005ed476  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 005ed47f  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 005ed487  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 005ed490  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 005ed498  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 005ed4a1  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 005ed4a9  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 005ed4b2  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 005ed4ba  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 005ed4c3  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 005ed4cb  8bc8                 mov ecx, eax
// 005ed4cd  8d149dffffffff       lea edx, [ebx*4 - 1]
// 005ed4d4  40                   inc eax
// 005ed4d5  89842478010000       mov dword ptr [esp + 0x178], eax
// 005ed4dc  3bca                 cmp ecx, edx
// 005ed4de  0f8528010000         jne 0x5ed60c
// 005ed4e4  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005ed4e7  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005ed4ee  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 005ed4f4  89420c               mov dword ptr [edx + 0xc], eax
// 005ed4f7  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 005ed4ff  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 005ed505  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 005ed50d  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 005ed516  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 005ed51e  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 005ed527  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 005ed52f  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 005ed538  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 005ed540  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 005ed549  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 005ed551  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 005ed55a  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 005ed562  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 005ed56b  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 005ed573  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 005ed57c  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 005ed584  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 005ed58d  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 005ed595  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 005ed59e  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 005ed5a6  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 005ed5af  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 005ed5b7  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 005ed5c0  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 005ed5c8  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 005ed5d1  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 005ed5d9  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 005ed5e2  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 005ed5ea  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 005ed5f3  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 005ed5fb  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 005ed604  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 005ed60c  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005ed613  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005ed61a  8b17                 mov edx, dword ptr [edi]
// 005ed61c  8b5218               mov edx, dword ptr [edx + 0x18]
// 005ed61f  50                   push eax
// 005ed620  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 005ed627  51                   push ecx
// 005ed628  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 005ed62f  50                   push eax
// 005ed630  51                   push ecx
// 005ed631  8bcf                 mov ecx, edi
// 005ed633  ffd2                 call edx
// 005ed635  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005ed63b  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 005ed644  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005ed64c  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 005ed655  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 005ed65b  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005ed661  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005ed666  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005ed66d  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005ed671  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005ed675  e9b3eeffff           jmp 0x5ec52d
// 005ed67a  0f28fa               movaps xmm7, xmm2
// 005ed67d  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 005ed683  0f28d9               movaps xmm3, xmm1
// 005ed686  42                   inc edx
// 005ed687  e90feeffff           jmp 0x5ec49b

// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE

#include <math.h>

struct Vector2 { float x, y; Vector2() {} Vector2(float a, float b) : x(a), y(b) {} };

struct Vector3 { float x, y, z; Vector3() {} Vector3(float a, float b, float c) : x(a), y(b), z(c) {} Vector2 xy() const; };

struct Vector4 { float x, y, z, w; Vector4() {} Vector4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} Vector2 xy() const; };

extern Vector3 permute(const Vector3& v);

struct UVBlock;

struct BrickMeshBuilder
{
    char pad0[0x70];
    unsigned char smooth;        // +0x70
    char pad1[7];
    float u0;                    // +0x78
    float v0;                    // +0x7c
    float u1;                    // +0x80
    float v1;                    // +0x84
    float smoothScale() const;   // 005ea290
    void buildSurface(const Vector3* size, float inset, unsigned int packed, float bevel,
                      struct Writer* writer, int* outIndices, UVBlock* outUVs, Vector2* srcUVs);
};

struct Writer
{
    virtual void vv0();
    virtual void vv1();
    virtual void vv2();
    virtual void vv3();
    virtual int corner(const void* p);              // vtable +0x10
    virtual void vv5();
    virtual void addQuad(int a, int b, int c, int d); // vtable +0x18
};

struct UVBlock
{
    Vector3 v0;        // +0x00
    Vector3 v1;        // +0x0c
    Vector3 v2;        // +0x18
    float ox, oy;      // +0x24, +0x28
    Vector2 uv;        // +0x2c
    float p, q;        // +0x34, +0x38
    Vector2 r;         // +0x3c
    UVBlock& operator=(const UVBlock& other);      // 005ea2c0
};

extern bool g_assertEnabled;                                        // 0xe580b3
extern bool (*g_assertHandler)(const char*, const char*, int);       // 0xe5809c
extern void func_00972290(unsigned char, const char*);

static const char kFile[] = "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Rendering\\GfxAdapters\\BrickMeshBuilder.cpp";

void BrickMeshBuilder::buildSurface(const Vector3* size, float inset, unsigned int packed, float bevel,
                                    Writer* writer, int* outIndices, UVBlock* outUVs, Vector2* srcUVs)
{
    int id = (packed >> 3) & 7;

    Vector3 t1 = permute(*size);
    Vector3 absT1(fabsf(t1.x), fabsf(t1.y), fabsf(t1.z));

    Vector3 t2 = permute(*size);
    Vector3 extents(fabsf(t2.x) - inset, fabsf(t2.y) - inset, fabsf(t2.z));

    Vector4 offset(0.0f, 0.0f, 0.0f, 0.0f);

    if (smooth) {
        offset.x = 64.0f;
        offset.y = 12.0f;
    } else {
        offset.x = 2.0f;
        offset.y = 20.0f;
    }

    switch (id) {
    case 0: {
        offset.x = 1.0f / 64.0f;
        offset.y = 8.0f / 9.0f;
        Vector2 tmp = extents.xy();
        offset.z = tmp.x * 2.0f;
        offset.w = tmp.y * 2.0f;
        break;
    }
    case 2:
        offset.z = 2.0f;
        offset.w = 4.0f;
        offset.y = smooth ? (1.0f / 3.0f) : 0.2f;
        break;
    case 4:
        offset.z = 2.0f;
        if (smooth) { offset.w = 2.0f; offset.y = 2.0f / 3.0f; }
        else { offset.w = 4.0f; offset.y = 0.4f; }
        break;
    case 5:
        offset.z = 2.0f;
        if (smooth) { offset.w = 2.0f; offset.y = 5.0f / 6.0f; }
        else { offset.w = 4.0f; offset.y = 0.6f; }
        break;
    case 3:
        if (smooth) {
            if (g_assertEnabled) {
                if (!g_assertHandler || !g_assertHandler("0", kFile, 183))
                    func_00972290(g_assertEnabled, "0 file: " "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Rendering\\GfxAdapters\\BrickMeshBuilder.cpp" " line: 183");
            }
        } else {
            offset.y = 0.8f;
        }
        /* fallthrough */
    case 1:
        offset.w = 4.0f;
        offset.z = 2.0f;
        break;
    default:
        break;
    }

    if (smooth) {
        offset.x = offset.x + bevel * (1.0f / 32.0f);
    }

    if (id == 0) {

    Vector3 n(1.0f, 0.0f, 0.0f);
    Vector3 normal = permute(n);

    Vector3 c0(u0, v0, 1.0f);
    Vector3 tangent = permute(c0);

    Vector3 bsrc(-extents.x, -extents.y, extents.z);
    Vector3 binormal = permute(bsrc);

    Vector3 c1(u1, v0, 1.0f);
    Vector3 c2(u1, v1, 1.0f);
    Vector3 c3(u0, v1, 1.0f);

    Vector4 q0(2.0f * absT1.x - inset, inset, -inset, inset - 2.0f * absT1.y);
    Vector4 q1(inset, 2.0f * absT1.y - inset, inset - 2.0f * absT1.x, -inset);
    Vector4 q2(2.0f * absT1.x - inset, 2.0f * absT1.y - inset, -inset, -inset);
    Vector4 q3(inset, inset, inset - 2.0f * absT1.x, inset - 2.0f * absT1.y);
    Vector2 ones(1.0f, 1.0f);

    __declspec(align(8)) UVBlock blk;
    UVBlock* fourth;

    for (int i = 0; i < 4; ++i) {
        Vector2 t = (i == 0) ? q3.xy() : ((i == 1) ? q0.xy() : ((i == 2) ? q2.xy() : q1.xy()));
        blk.v0 = binormal;
        blk.v1 = tangent;
        blk.v2 = normal;
        blk.ox = offset.x;
        blk.oy = offset.y;
        blk.uv = t;
        blk.p = inset;
        blk.q = inset;
        blk.r = ones;
        outUVs[i] = blk;
        outUVs[i].ox = srcUVs[i].x;
        outUVs[i].oy = srcUVs[i].y;
    }

    int h1 = writer->corner(outUVs);
    int h2 = writer->corner(outUVs + 1);
    int h3 = writer->corner((const void*)this);
    int h4 = writer->corner(fourth);
    writer->addQuad(h1, h2, h3, h4);

    if (outIndices != 0) {
        outIndices[0] = h1;
        outIndices[1] = h2;
        outIndices[2] = h3;
        outIndices[3] = h4;
    }

    } else {
        if (g_assertEnabled) {
            if (outIndices == 0) {
                if (!g_assertHandler || !g_assertHandler("indices", kFile, 257))
                    func_00972290(g_assertEnabled, "indices file: " "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Rendering\\GfxAdapters\\BrickMeshBuilder.cpp" " line: 257");
            }
        }
        // TODO: shared stud/inlet mesh path
    }
}
