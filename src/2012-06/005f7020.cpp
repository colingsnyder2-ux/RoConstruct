// from server: 11% by intel
// roc 2012-06 005f7020  unit: seg_005f0000  size: 7784 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005f7020
//
// 005f7020  55                   push ebp
// 005f7021  8bec                 mov ebp, esp
// 005f7023  83e4f8               and esp, 0xfffffff8
// 005f7026  81ecfc030000         sub esp, 0x3fc
// 005f702c  53                   push ebx
// 005f702d  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 005f7030  56                   push esi
// 005f7031  57                   push edi
// 005f7032  8b7d08               mov edi, dword ptr [ebp + 8]
// 005f7035  8d44246c             lea eax, [esp + 0x6c]
// 005f7039  8bf1                 mov esi, ecx
// 005f703b  57                   push edi
// 005f703c  50                   push eax
// 005f703d  89742464             mov dword ptr [esp + 0x64], esi
// 005f7041  83e307               and ebx, 7
// 005f7044  e877052300           call 0x8275c0
// 005f7049  d9442474             fld dword ptr [esp + 0x74]
// 005f704d  d9e1                 fabs 
// 005f704f  8d4c2474             lea ecx, [esp + 0x74]
// 005f7053  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005f705a  57                   push edi
// 005f705b  d944247c             fld dword ptr [esp + 0x7c]
// 005f705f  51                   push ecx
// 005f7060  d9e1                 fabs 
// 005f7062  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005f7069  d9842484000000       fld dword ptr [esp + 0x84]
// 005f7070  d9e1                 fabs 
// 005f7072  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005f7079  e842052300           call 0x8275c0
// 005f707e  d944247c             fld dword ptr [esp + 0x7c]
// 005f7082  8a4670               mov al, byte ptr [esi + 0x70]
// 005f7085  d9e1                 fabs 
// 005f7087  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f708f  d9842480000000       fld dword ptr [esp + 0x80]
// 005f7096  83c410               add esp, 0x10
// 005f7099  d9e1                 fabs 
// 005f709b  d9442474             fld dword ptr [esp + 0x74]
// 005f709f  d9e1                 fabs 
// 005f70a1  d9450c               fld dword ptr [ebp + 0xc]
// 005f70a4  dceb                 fsub st(3), st(0)
// 005f70a6  d9cb                 fxch st(3)
// 005f70a8  d95c241c             fstp dword ptr [esp + 0x1c]
// 005f70ac  d9c9                 fxch st(1)
// 005f70ae  dee2                 fsubrp st(2)
// 005f70b0  d9c9                 fxch st(1)
// 005f70b2  d95c2420             fstp dword ptr [esp + 0x20]
// 005f70b6  d95c2424             fstp dword ptr [esp + 0x24]
// 005f70ba  84c0                 test al, al
// 005f70bc  741b                 je 0x5f70d9
// 005f70be  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005f70c6  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005f70cf  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005f70d7  eb11                 jmp 0x5f70ea
// 005f70d9  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005f70e1  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005f70ea  0f57e4               xorps xmm4, xmm4
// 005f70ed  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005f70f6  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005f70fc  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005f7102  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005f7108  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005f710e  83fb05               cmp ebx, 5
// 005f7111  0f87a4010000         ja 0x5f72bb
// 005f7117  ff249d708e5f00       jmp dword ptr [ebx*4 + 0x5f8e70]
// 005f711e  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005f7126  8d542460             lea edx, [esp + 0x60]
// 005f712a  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005f7130  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005f7138  52                   push edx
// 005f7139  8d4c2420             lea ecx, [esp + 0x20]
// 005f713d  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005f7143  e8f8d00300           call 0x634240
// 005f7148  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f7150  f30f1000             movss xmm0, dword ptr [eax]
// 005f7154  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005f7159  0f57e4               xorps xmm4, xmm4
// 005f715c  f30f59c5             mulss xmm0, xmm5
// 005f7160  f30f59cd             mulss xmm1, xmm5
// 005f7164  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005f716a  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005f7170  e946010000           jmp 0x5f72bb
// 005f7175  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f717d  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f7183  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f7189  84c0                 test al, al
// 005f718b  7413                 je 0x5f71a0
// 005f718d  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005f7195  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f719b  e91b010000           jmp 0x5f72bb
// 005f71a0  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005f71a8  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f71ae  e908010000           jmp 0x5f72bb
// 005f71b3  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f71b9  84c0                 test al, al
// 005f71bb  7419                 je 0x5f71d6
// 005f71bd  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005f71c5  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005f71cb  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f71d1  e9e5000000           jmp 0x5f72bb
// 005f71d6  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f71de  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f71e4  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005f71ec  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f71f2  e9c4000000           jmp 0x5f72bb
// 005f71f7  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f71fd  84c0                 test al, al
// 005f71ff  7419                 je 0x5f721a
// 005f7201  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005f7209  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005f720f  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f7215  e9a1000000           jmp 0x5f72bb
// 005f721a  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f7222  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f7228  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005f7230  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f7236  e980000000           jmp 0x5f72bb
// 005f723b  84c0                 test al, al
// 005f723d  745a                 je 0x5f7299
// 005f723f  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f7246  7441                 je 0x5f7289
// 005f7248  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f724d  85c0                 test eax, eax
// 005f724f  7418                 je 0x5f7269
// 005f7251  68b7000000           push 0xb7
// 005f7256  688027b800           push 0xb82780
// 005f725b  68cc60b400           push 0xb460cc
// 005f7260  ffd0                 call eax
// 005f7262  83c40c               add esp, 0xc
// 005f7265  84c0                 test al, al
// 005f7267  7515                 jne 0x5f727e
// 005f7269  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f7270  680827b800           push 0xb82708
// 005f7275  50                   push eax
// 005f7276  e815b03700           call 0x972290
// 005f727b  83c408               add esp, 8
// 005f727e  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f7286  0f57e4               xorps xmm4, xmm4
// 005f7289  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f7291  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f7297  eb1c                 jmp 0x5f72b5
// 005f7299  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f72a1  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f72a7  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005f72af  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f72b5  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f72bb  807e7000             cmp byte ptr [esi + 0x70], 0
// 005f72bf  7419                 je 0x5f72da
// 005f72c1  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005f72c6  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005f72ce  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005f72d4  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005f72da  85db                 test ebx, ebx
// 005f72dc  0f859c080000         jne 0x5f7b7e
// 005f72e2  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f72ea  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005f72ef  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005f72f7  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005f72fc  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005f7302  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005f730b  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f7313  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005f7319  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005f7322  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005f732b  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005f7334  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005f733d  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005f7346  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005f734f  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005f7358  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005f7361  f30f59c5             mulss xmm0, xmm5
// 005f7365  f30f59cd             mulss xmm1, xmm5
// 005f7369  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005f7372  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005f737b  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005f7380  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005f7389  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005f7392  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005f7399  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005f739f  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005f73a8  0f28e3               movaps xmm4, xmm3
// 005f73ab  f30f5ce0             subss xmm4, xmm0
// 005f73af  0f28eb               movaps xmm5, xmm3
// 005f73b2  f30f5ce9             subss xmm5, xmm1
// 005f73b6  51                   push ecx
// 005f73b7  8d542464             lea edx, [esp + 0x64]
// 005f73bb  f30f5cc3             subss xmm0, xmm3
// 005f73bf  0f28d3               movaps xmm2, xmm3
// 005f73c2  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005f73c9  f30f5ccb             subss xmm1, xmm3
// 005f73cd  52                   push edx
// 005f73ce  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005f73d7  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005f73e0  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005f73e9  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005f73f2  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005f73fb  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005f7404  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005f740d  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005f7416  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005f741f  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005f7428  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005f7431  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005f743a  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005f7443  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005f744c  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005f7455  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005f745e  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005f7467  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005f7470  e84b012300           call 0x8275c0
// 005f7475  8d442474             lea eax, [esp + 0x74]
// 005f7479  50                   push eax
// 005f747a  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005f7481  51                   push ecx
// 005f7482  e839012300           call 0x8275c0
// 005f7487  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005f748f  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005f7495  0f57c8               xorps xmm1, xmm0
// 005f7498  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005f74a1  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005f74a7  8d9424d0000000       lea edx, [esp + 0xd0]
// 005f74ae  0f57c8               xorps xmm1, xmm0
// 005f74b1  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f74b7  52                   push edx
// 005f74b8  8d8424ec000000       lea eax, [esp + 0xec]
// 005f74bf  50                   push eax
// 005f74c0  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005f74c9  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f74d2  e8e9002300           call 0x8275c0
// 005f74d7  83c418               add esp, 0x18
// 005f74da  8d4c2440             lea ecx, [esp + 0x40]
// 005f74de  51                   push ecx
// 005f74df  8d8c2480010000       lea ecx, [esp + 0x180]
// 005f74e6  e855cd0300           call 0x634240
// 005f74eb  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005f74f2  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f74f8  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005f74ff  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005f7506  8b7d20               mov edi, dword ptr [ebp + 0x20]
// 005f7509  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f7512  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f7518  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f7521  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f7527  89542478             mov dword ptr [esp + 0x78], edx
// 005f752b  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005f7532  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f753b  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f7541  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f7548  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005f754f  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f7556  8b542460             mov edx, dword ptr [esp + 0x60]
// 005f755a  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f7563  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005f7568  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f756c  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005f7573  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f757a  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f757e  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f7587  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f7590  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f7599  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f75a0  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f75a7  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f75ab  8d542478             lea edx, [esp + 0x78]
// 005f75af  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f75b6  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f75bf  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f75c8  52                   push edx
// 005f75c9  8bcf                 mov ecx, edi
// 005f75cb  89842498000000       mov dword ptr [esp + 0x98], eax
// 005f75d2  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f75db  e8e02cffff           call 0x5ea2c0
// 005f75e0  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005f75e9  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f75ef  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005f75f8  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f75fe  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005f7607  8d84248c010000       lea eax, [esp + 0x18c]
// 005f760e  50                   push eax
// 005f760f  8d4c2464             lea ecx, [esp + 0x64]
// 005f7613  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f7619  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005f7622  51                   push ecx
// 005f7623  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f7629  e892ff2200           call 0x8275c0
// 005f762e  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005f7635  52                   push edx
// 005f7636  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f763d  50                   push eax
// 005f763e  e87dff2200           call 0x8275c0
// 005f7643  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f7649  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f7652  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f7658  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f765f  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005f7666  51                   push ecx
// 005f7667  8d9424ec000000       lea edx, [esp + 0xec]
// 005f766e  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f7677  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f767d  52                   push edx
// 005f767e  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f7687  e834ff2200           call 0x8275c0
// 005f768c  83c418               add esp, 0x18
// 005f768f  8d442440             lea eax, [esp + 0x40]
// 005f7693  50                   push eax
// 005f7694  8d8c2410010000       lea ecx, [esp + 0x110]
// 005f769b  e8a0cb0300           call 0x634240
// 005f76a0  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005f76a7  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005f76ae  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005f76b5  894c2478             mov dword ptr [esp + 0x78], ecx
// 005f76b9  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005f76c0  8954247c             mov dword ptr [esp + 0x7c], edx
// 005f76c4  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005f76cb  89842480000000       mov dword ptr [esp + 0x80], eax
// 005f76d2  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005f76d9  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f76df  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005f76e3  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005f76ea  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f76f3  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f76f9  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f7702  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f7708  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f7711  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f7717  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f7720  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f7726  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f772f  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f7735  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005f773c  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f7745  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f774b  8d4c2478             lea ecx, [esp + 0x78]
// 005f774f  89942488000000       mov dword ptr [esp + 0x88], edx
// 005f7756  8b542464             mov edx, dword ptr [esp + 0x64]
// 005f775a  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005f7761  8b442468             mov eax, dword ptr [esp + 0x68]
// 005f7765  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f776e  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f7774  8d5f44               lea ebx, [edi + 0x44]
// 005f7777  51                   push ecx
// 005f7778  8bcb                 mov ecx, ebx
// 005f777a  89942498000000       mov dword ptr [esp + 0x98], edx
// 005f7781  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005f7788  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f7791  e82a2bffff           call 0x5ea2c0
// 005f7796  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005f779f  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f77a5  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005f77ae  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f77b4  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005f77bd  8d94248c010000       lea edx, [esp + 0x18c]
// 005f77c4  52                   push edx
// 005f77c5  8d442464             lea eax, [esp + 0x64]
// 005f77c9  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f77cf  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005f77d8  50                   push eax
// 005f77d9  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f77df  e8dcfd2200           call 0x8275c0
// 005f77e4  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005f77eb  51                   push ecx
// 005f77ec  8d9424d8000000       lea edx, [esp + 0xd8]
// 005f77f3  52                   push edx
// 005f77f4  e8c7fd2200           call 0x8275c0
// 005f77f9  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f77ff  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f7808  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f780e  8d8424d0000000       lea eax, [esp + 0xd0]
// 005f7815  50                   push eax
// 005f7816  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005f781d  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f7826  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f782c  51                   push ecx
// 005f782d  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f7836  e885fd2200           call 0x8275c0
// 005f783b  83c418               add esp, 0x18
// 005f783e  8d542440             lea edx, [esp + 0x40]
// 005f7842  52                   push edx
// 005f7843  8d8c2430010000       lea ecx, [esp + 0x130]
// 005f784a  e8f1c90300           call 0x634240
// 005f784f  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005f7856  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005f785d  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005f7864  89442478             mov dword ptr [esp + 0x78], eax
// 005f7868  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005f786f  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005f7873  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005f787a  89942480000000       mov dword ptr [esp + 0x80], edx
// 005f7881  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005f7888  89842484000000       mov dword ptr [esp + 0x84], eax
// 005f788f  8b442460             mov eax, dword ptr [esp + 0x60]
// 005f7893  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005f789a  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005f789e  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005f78a5  8b542468             mov edx, dword ptr [esp + 0x68]
// 005f78a9  89842490000000       mov dword ptr [esp + 0x90], eax
// 005f78b0  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005f78b7  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f78bd  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f78c6  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f78cc  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f78d5  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f78db  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f78e4  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f78ea  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f78f3  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f78f9  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f7902  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f7908  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f7911  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f7917  8d442478             lea eax, [esp + 0x78]
// 005f791b  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f7924  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f792a  8d8f88000000         lea ecx, [edi + 0x88]
// 005f7930  50                   push eax
// 005f7931  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005f7938  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f7941  894c2460             mov dword ptr [esp + 0x60], ecx
// 005f7945  e87629ffff           call 0x5ea2c0
// 005f794a  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005f7953  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f7959  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005f7962  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f7968  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005f7971  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005f7978  51                   push ecx
// 005f7979  8d542464             lea edx, [esp + 0x64]
// 005f797d  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f7983  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005f798c  52                   push edx
// 005f798d  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f7993  e828fc2200           call 0x8275c0
// 005f7998  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005f799f  50                   push eax
// 005f79a0  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005f79a7  51                   push ecx
// 005f79a8  e813fc2200           call 0x8275c0
// 005f79ad  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f79b3  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f79ba  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f79c3  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f79c9  8d9424d0000000       lea edx, [esp + 0xd0]
// 005f79d0  52                   push edx
// 005f79d1  8d8424ec000000       lea eax, [esp + 0xec]
// 005f79d8  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f79e1  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f79e7  50                   push eax
// 005f79e8  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f79f1  e8cafb2200           call 0x8275c0
// 005f79f6  83c418               add esp, 0x18
// 005f79f9  8d4c2440             lea ecx, [esp + 0x40]
// 005f79fd  51                   push ecx
// 005f79fe  8d8c2420010000       lea ecx, [esp + 0x120]
// 005f7a05  e836c80300           call 0x634240
// 005f7a0a  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005f7a11  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005f7a18  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005f7a1f  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f7a25  89542478             mov dword ptr [esp + 0x78], edx
// 005f7a29  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005f7a30  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f7a34  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005f7a3b  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f7a42  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005f7a49  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f7a52  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f7a58  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f7a5f  8b542460             mov edx, dword ptr [esp + 0x60]
// 005f7a63  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f7a6a  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f7a6e  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f7a75  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f7a79  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f7a82  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f7a88  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f7a8f  89842494000000       mov dword ptr [esp + 0x94], eax
// 005f7a96  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f7a9d  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f7aa6  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f7aac  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f7ab5  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f7abb  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f7ac4  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f7aca  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f7ad3  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f7ad9  8d542478             lea edx, [esp + 0x78]
// 005f7add  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f7ae6  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f7aec  8d8fcc000000         lea ecx, [edi + 0xcc]
// 005f7af2  52                   push edx
// 005f7af3  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f7afc  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005f7b03  e8b827ffff           call 0x5ea2c0
// 005f7b08  8b7518               mov esi, dword ptr [ebp + 0x18]
// 005f7b0b  8b06                 mov eax, dword ptr [esi]
// 005f7b0d  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f7b10  57                   push edi
// 005f7b11  8bce                 mov ecx, esi
// 005f7b13  ffd2                 call edx
// 005f7b15  8bf8                 mov edi, eax
// 005f7b17  8b06                 mov eax, dword ptr [esi]
// 005f7b19  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f7b1c  53                   push ebx
// 005f7b1d  8bce                 mov ecx, esi
// 005f7b1f  ffd2                 call edx
// 005f7b21  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f7b25  8bd8                 mov ebx, eax
// 005f7b27  8b06                 mov eax, dword ptr [esi]
// 005f7b29  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f7b2c  51                   push ecx
// 005f7b2d  8bce                 mov ecx, esi
// 005f7b2f  ffd2                 call edx
// 005f7b31  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005f7b38  8944243c             mov dword ptr [esp + 0x3c], eax
// 005f7b3c  8b06                 mov eax, dword ptr [esi]
// 005f7b3e  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f7b41  51                   push ecx
// 005f7b42  8bce                 mov ecx, esi
// 005f7b44  ffd2                 call edx
// 005f7b46  8b16                 mov edx, dword ptr [esi]
// 005f7b48  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f7b4b  50                   push eax
// 005f7b4c  89442460             mov dword ptr [esp + 0x60], eax
// 005f7b50  8b442440             mov eax, dword ptr [esp + 0x40]
// 005f7b54  50                   push eax
// 005f7b55  53                   push ebx
// 005f7b56  57                   push edi
// 005f7b57  8bce                 mov ecx, esi
// 005f7b59  ffd2                 call edx
// 005f7b5b  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005f7b5e  85c0                 test eax, eax
// 005f7b60  7413                 je 0x5f7b75
// 005f7b62  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f7b66  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005f7b6a  8938                 mov dword ptr [eax], edi
// 005f7b6c  895804               mov dword ptr [eax + 4], ebx
// 005f7b6f  894808               mov dword ptr [eax + 8], ecx
// 005f7b72  89500c               mov dword ptr [eax + 0xc], edx
// 005f7b75  5f                   pop edi
// 005f7b76  5e                   pop esi
// 005f7b77  5b                   pop ebx
// 005f7b78  8be5                 mov esp, ebp
// 005f7b7a  5d                   pop ebp
// 005f7b7b  c22000               ret 0x20
// 005f7b7e  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f7b85  743c                 je 0x5f7bc3
// 005f7b87  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005f7b8b  7536                 jne 0x5f7bc3
// 005f7b8d  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f7b92  85c0                 test eax, eax
// 005f7b94  7418                 je 0x5f7bae
// 005f7b96  6801010000           push 0x101
// 005f7b9b  688027b800           push 0xb82780
// 005f7ba0  680027b800           push 0xb82700
// 005f7ba5  ffd0                 call eax
// 005f7ba7  83c40c               add esp, 0xc
// 005f7baa  84c0                 test al, al
// 005f7bac  7515                 jne 0x5f7bc3
// 005f7bae  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f7bb5  688826b800           push 0xb82688
// 005f7bba  50                   push eax
// 005f7bbb  e8d0a63700           call 0x972290
// 005f7bc0  83c408               add esp, 8
// 005f7bc3  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005f7bc9  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f7bd0  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f7bd8  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005f7be0  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005f7be5  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005f7beb  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005f7bf3  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005f7bf8  8d4c2460             lea ecx, [esp + 0x60]
// 005f7bfc  51                   push ecx
// 005f7bfd  f30f59c2             mulss xmm0, xmm2
// 005f7c01  f30f59ca             mulss xmm1, xmm2
// 005f7c05  8d4c2420             lea ecx, [esp + 0x20]
// 005f7c09  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f7c12  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f7c1b  e820c60300           call 0x634240
// 005f7c20  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f7c29  f30f5e00             divss xmm0, dword ptr [eax]
// 005f7c2d  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005f7c32  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005f7c35  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f7c38  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f7c3d  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f7c45  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f7c4b  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005f7c54  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f7c5d  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005f7c62  33d2                 xor edx, edx
// 005f7c64  33db                 xor ebx, ebx
// 005f7c66  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005f7c6f  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f7c76  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005f7c7d  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005f7c83  0f2fd7               comiss xmm2, xmm7
// 005f7c86  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005f7c8c  8954243c             mov dword ptr [esp + 0x3c], edx
// 005f7c90  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005f7c99  770a                 ja 0x5f7ca5
// 005f7c9b  85d2                 test edx, edx
// 005f7c9d  0f85d2feffff         jne 0x5f7b75
// 005f7ca3  eb04                 jmp 0x5f7ca9
// 005f7ca5  85d2                 test edx, edx
// 005f7ca7  7504                 jne 0x5f7cad
// 005f7ca9  f30f5cc4             subss xmm0, xmm4
// 005f7cad  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f7cb1  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f7cb5  7421                 je 0x5f7cd8
// 005f7cb7  f30f58c7             addss xmm0, xmm7
// 005f7cbb  0f2fc2               comiss xmm0, xmm2
// 005f7cbe  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f7cc7  8d44241c             lea eax, [esp + 0x1c]
// 005f7ccb  7707                 ja 0x5f7cd4
// 005f7ccd  8d84240c030000       lea eax, [esp + 0x30c]
// 005f7cd4  f30f1010             movss xmm2, dword ptr [eax]
// 005f7cd8  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005f7ce1  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f7ce7  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f7cee  f30f58cb             addss xmm1, xmm3
// 005f7cf2  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005f7cf7  33c0                 xor eax, eax
// 005f7cf9  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005f7cff  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005f7d08  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f7d0f  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005f7d15  0f2ff0               comiss xmm6, xmm0
// 005f7d18  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005f7d21  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005f7d27  7708                 ja 0x5f7d31
// 005f7d29  85c0                 test eax, eax
// 005f7d2b  0f852b110000         jne 0x5f8e5c
// 005f7d31  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005f7d37  85c0                 test eax, eax
// 005f7d39  7504                 jne 0x5f7d3f
// 005f7d3b  f30f5ccc             subss xmm1, xmm4
// 005f7d3f  0f28f1               movaps xmm6, xmm1
// 005f7d42  f30f58f0             addss xmm6, xmm0
// 005f7d46  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005f7d4b  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005f7d54  8d442420             lea eax, [esp + 0x20]
// 005f7d58  7707                 ja 0x5f7d61
// 005f7d5a  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005f7d61  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f7d65  f30f1000             movss xmm0, dword ptr [eax]
// 005f7d69  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005f7d6f  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005f7d78  f30f58c3             addss xmm0, xmm3
// 005f7d7c  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005f7d85  0f57c0               xorps xmm0, xmm0
// 005f7d88  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005f7d8e  740f                 je 0x5f7d9f
// 005f7d90  e8fb24ffff           call 0x5ea290
// 005f7d95  d80d94deb600         fmul dword ptr [0xb6de94]
// 005f7d9b  d95c2440             fstp dword ptr [esp + 0x40]
// 005f7d9f  0f28dd               movaps xmm3, xmm5
// 005f7da2  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005f7dab  0f28c3               movaps xmm0, xmm3
// 005f7dae  f30f59c4             mulss xmm0, xmm4
// 005f7db2  f30f5cd7             subss xmm2, xmm7
// 005f7db6  f30f59d3             mulss xmm2, xmm3
// 005f7dba  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005f7dc0  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005f7dc6  f30f58d3             addss xmm2, xmm3
// 005f7dca  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005f7dd0  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005f7dd6  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005f7ddc  0f28c5               movaps xmm0, xmm5
// 005f7ddf  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005f7de8  0f28e9               movaps xmm5, xmm1
// 005f7deb  0f28f0               movaps xmm6, xmm0
// 005f7dee  f30f59f4             mulss xmm6, xmm4
// 005f7df2  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005f7df8  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005f7dfe  f30f5ccb             subss xmm1, xmm3
// 005f7e02  f30f59e8             mulss xmm5, xmm0
// 005f7e06  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005f7e0c  f30f59c8             mulss xmm1, xmm0
// 005f7e10  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005f7e16  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005f7e1f  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005f7e28  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005f7e31  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005f7e3a  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005f7e43  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005f7e4c  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005f7e55  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005f7e5e  85d2                 test edx, edx
// 005f7e60  753f                 jne 0x5f7ea1
// 005f7e62  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005f7e68  0f28c4               movaps xmm0, xmm4
// 005f7e6b  f30f58c3             addss xmm0, xmm3
// 005f7e6f  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005f7e78  0f28c3               movaps xmm0, xmm3
// 005f7e7b  f30f58c2             addss xmm0, xmm2
// 005f7e7f  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005f7e88  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005f7e91  0f28c4               movaps xmm0, xmm4
// 005f7e94  f30f58c3             addss xmm0, xmm3
// 005f7e98  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005f7ea1  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f7ea7  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005f7eac  772f                 ja 0x5f7edd
// 005f7eae  0f28c6               movaps xmm0, xmm6
// 005f7eb1  f30f58c5             addss xmm0, xmm5
// 005f7eb5  f30f58f1             addss xmm6, xmm1
// 005f7eb9  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005f7ec2  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005f7ecb  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005f7ed4  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005f7edd  8d9424cc000000       lea edx, [esp + 0xcc]
// 005f7ee4  52                   push edx
// 005f7ee5  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f7eec  e84fc30300           call 0x634240
// 005f7ef1  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f7ef6  f30f1008             movss xmm1, dword ptr [eax]
// 005f7efa  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005f7f00  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005f7f06  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f7f0d  50                   push eax
// 005f7f0e  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f7f15  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005f7f1e  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005f7f27  e814c30300           call 0x634240
// 005f7f2c  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f7f31  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005f7f37  f30f5808             addss xmm1, dword ptr [eax]
// 005f7f3b  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005f7f41  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005f7f48  51                   push ecx
// 005f7f49  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f7f50  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005f7f59  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005f7f62  e8d9c20300           call 0x634240
// 005f7f67  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005f7f6d  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f7f72  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005f7f78  f30f5c08             subss xmm1, dword ptr [eax]
// 005f7f7c  8d94248c010000       lea edx, [esp + 0x18c]
// 005f7f83  52                   push edx
// 005f7f84  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f7f8b  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005f7f94  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005f7f9d  e89ec20300           call 0x634240
// 005f7fa2  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f7fa8  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f7fad  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005f7fb3  f30f5c08             subss xmm1, dword ptr [eax]
// 005f7fb7  8d842498010000       lea eax, [esp + 0x198]
// 005f7fbe  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f7fc7  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f7fcf  50                   push eax
// 005f7fd0  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005f7fd7  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005f7fdd  0f57c0               xorps xmm0, xmm0
// 005f7fe0  51                   push ecx
// 005f7fe1  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005f7fe8  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f7ff1  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005f7ff7  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005f7ffd  e80ec20300           call 0x634210
// 005f8002  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005f800b  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005f8014  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005f801d  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005f8026  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f802f  8d9424ec000000       lea edx, [esp + 0xec]
// 005f8036  52                   push edx
// 005f8037  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005f803e  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005f8047  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f8050  50                   push eax
// 005f8051  8d8c2484010000       lea ecx, [esp + 0x184]
// 005f8058  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005f8061  e8aac10300           call 0x634210
// 005f8066  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f806f  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f8075  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005f807e  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f8084  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005f808d  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005f8093  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f809c  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f80a2  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005f80ab  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005f80b4  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005f80bd  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f80c6  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f80cf  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005f80d8  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f80e1  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005f80ea  8d4c246c             lea ecx, [esp + 0x6c]
// 005f80ee  51                   push ecx
// 005f80ef  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005f80f6  52                   push edx
// 005f80f7  e8c4f42200           call 0x8275c0
// 005f80fc  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f8105  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005f810e  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f8117  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005f811e  50                   push eax
// 005f811f  8d8c2484030000       lea ecx, [esp + 0x384]
// 005f8126  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005f812f  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f8137  51                   push ecx
// 005f8138  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005f8141  e87af42200           call 0x8275c0
// 005f8146  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f814c  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005f8155  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f815b  8d942470030000       lea edx, [esp + 0x370]
// 005f8162  52                   push edx
// 005f8163  8d842450030000       lea eax, [esp + 0x350]
// 005f816a  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005f8173  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f8179  50                   push eax
// 005f817a  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005f8183  e838f42200           call 0x8275c0
// 005f8188  83c418               add esp, 0x18
// 005f818b  8d8c2430030000       lea ecx, [esp + 0x330]
// 005f8192  51                   push ecx
// 005f8193  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005f819a  e8a1c00300           call 0x634240
// 005f819f  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f81a8  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005f81af  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005f81b6  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005f81bd  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005f81c6  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f81cf  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005f81d8  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005f81e1  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005f81ea  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005f81f3  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005f81fc  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005f8205  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005f820e  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005f8217  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005f8220  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005f8229  89942448020000       mov dword ptr [esp + 0x248], edx
// 005f8230  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005f8237  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005f8240  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005f8249  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005f8250  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005f8257  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005f8260  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005f8269  89942454020000       mov dword ptr [esp + 0x254], edx
// 005f8270  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005f8277  89842458020000       mov dword ptr [esp + 0x258], eax
// 005f827e  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005f8285  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005f828e  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005f8297  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005f829e  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005f82a5  89942460020000       mov dword ptr [esp + 0x260], edx
// 005f82ac  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005f82b5  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005f82be  8d54246c             lea edx, [esp + 0x6c]
// 005f82c2  89842464020000       mov dword ptr [esp + 0x264], eax
// 005f82c9  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005f82d0  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005f82d7  52                   push edx
// 005f82d8  8d842470030000       lea eax, [esp + 0x370]
// 005f82df  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005f82e8  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005f82f1  50                   push eax
// 005f82f2  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005f82f9  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f8302  e8b9f22200           call 0x8275c0
// 005f8307  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f8310  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005f8319  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f8322  8d8c2498030000       lea ecx, [esp + 0x398]
// 005f8329  51                   push ecx
// 005f832a  8d942460030000       lea edx, [esp + 0x360]
// 005f8331  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005f833a  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f8342  52                   push edx
// 005f8343  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005f834c  e86ff22200           call 0x8275c0
// 005f8351  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005f8357  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005f8360  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f8366  8d842400040000       lea eax, [esp + 0x400]
// 005f836d  50                   push eax
// 005f836e  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005f8375  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005f837e  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f8384  51                   push ecx
// 005f8385  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005f838e  e82df22200           call 0x8275c0
// 005f8393  83c418               add esp, 0x18
// 005f8396  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005f839d  52                   push edx
// 005f839e  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005f83a5  e896be0300           call 0x634240
// 005f83aa  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005f83b3  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005f83ba  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005f83c1  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005f83c8  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005f83d1  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005f83da  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005f83e3  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005f83ec  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005f83f5  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005f83fe  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005f8407  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005f8410  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005f8419  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005f8422  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005f842b  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005f8434  89842490020000       mov dword ptr [esp + 0x290], eax
// 005f843b  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005f8442  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005f844b  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005f8454  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005f845b  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005f8462  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005f846b  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005f8474  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005f847b  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005f8482  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005f8489  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005f8490  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005f8499  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005f84a2  89942498020000       mov dword ptr [esp + 0x298], edx
// 005f84a9  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005f84b0  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005f84b7  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005f84c0  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005f84c9  8d44246c             lea eax, [esp + 0x6c]
// 005f84cd  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005f84d4  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005f84db  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005f84e2  50                   push eax
// 005f84e3  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005f84ea  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005f84f3  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005f84fc  51                   push ecx
// 005f84fd  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005f8504  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005f850d  e8aef02200           call 0x8275c0
// 005f8512  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f851b  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005f8524  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f852d  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005f8536  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f853e  8d94248c030000       lea edx, [esp + 0x38c]
// 005f8545  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005f854e  52                   push edx
// 005f854f  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005f8556  50                   push eax
// 005f8557  e864f02200           call 0x8275c0
// 005f855c  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005f8562  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005f856b  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005f8571  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005f8578  51                   push ecx
// 005f8579  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005f8580  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005f8589  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f858f  52                   push edx
// 005f8590  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005f8599  e822f02200           call 0x8275c0
// 005f859e  83c418               add esp, 0x18
// 005f85a1  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005f85a8  50                   push eax
// 005f85a9  8d8c2480010000       lea ecx, [esp + 0x180]
// 005f85b0  e88bbc0300           call 0x634240
// 005f85b5  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005f85be  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005f85c5  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005f85cc  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005f85d3  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005f85dc  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005f85e5  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005f85ee  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005f85f7  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005f8600  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005f8609  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005f8612  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005f861b  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005f8624  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005f862d  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005f8636  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 005f863f  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 005f8646  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 005f864d  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 005f8656  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 005f865f  89942404020000       mov dword ptr [esp + 0x204], edx
// 005f8666  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 005f866d  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 005f8676  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f867c  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 005f8683  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 005f868a  89942410020000       mov dword ptr [esp + 0x210], edx
// 005f8691  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 005f8698  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 005f86a1  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f86a7  89842408020000       mov dword ptr [esp + 0x208], eax
// 005f86ae  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 005f86b5  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 005f86bc  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005f86c5  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f86cb  8d4c246c             lea ecx, [esp + 0x6c]
// 005f86cf  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 005f86d6  89842414020000       mov dword ptr [esp + 0x214], eax
// 005f86dd  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 005f86e4  51                   push ecx
// 005f86e5  8d942410010000       lea edx, [esp + 0x110]
// 005f86ec  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 005f86f5  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f86fb  52                   push edx
// 005f86fc  89842428020000       mov dword ptr [esp + 0x228], eax
// 005f8703  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f870c  e8afee2200           call 0x8275c0
// 005f8711  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f871a  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 005f8723  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f872c  8d842404040000       lea eax, [esp + 0x404]
// 005f8733  50                   push eax
// 005f8734  8d8c2438010000       lea ecx, [esp + 0x138]
// 005f873b  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 005f8744  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f874c  51                   push ecx
// 005f874d  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 005f8756  e865ee2200           call 0x8275c0
// 005f875b  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f8761  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 005f876a  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005f8770  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005f8779  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f877f  8d9424b8030000       lea edx, [esp + 0x3b8]
// 005f8786  52                   push edx
// 005f8787  8d842430010000       lea eax, [esp + 0x130]
// 005f878e  50                   push eax
// 005f878f  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 005f8798  e823ee2200           call 0x8275c0
// 005f879d  83c418               add esp, 0x18
// 005f87a0  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 005f87a7  51                   push ecx
// 005f87a8  8d4c242c             lea ecx, [esp + 0x2c]
// 005f87ac  e88fba0300           call 0x634240
// 005f87b1  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 005f87ba  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 005f87c1  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 005f87c8  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 005f87cf  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f87d8  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 005f87e1  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f87ea  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 005f87f3  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f87fc  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 005f8805  89542478             mov dword ptr [esp + 0x78], edx
// 005f8809  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 005f8810  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f8814  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005f881b  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f8824  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 005f882d  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f8834  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 005f883b  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f8842  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 005f8849  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f8850  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 005f8857  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f8860  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 005f8869  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f8870  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 005f8877  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f887e  8b17                 mov edx, dword ptr [edi]
// 005f8880  8b5210               mov edx, dword ptr [edx + 0x10]
// 005f8883  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f888c  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 005f8895  89842494000000       mov dword ptr [esp + 0x94], eax
// 005f889c  8d842448020000       lea eax, [esp + 0x248]
// 005f88a3  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f88aa  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f88b3  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 005f88bc  50                   push eax
// 005f88bd  8bcf                 mov ecx, edi
// 005f88bf  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f88c8  ffd2                 call edx
// 005f88ca  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 005f88d1  8b07                 mov eax, dword ptr [edi]
// 005f88d3  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f88d6  8d8c2490020000       lea ecx, [esp + 0x290]
// 005f88dd  51                   push ecx
// 005f88de  8bcf                 mov ecx, edi
// 005f88e0  ffd2                 call edx
// 005f88e2  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 005f88e9  8b07                 mov eax, dword ptr [edi]
// 005f88eb  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f88ee  8d8c2400020000       lea ecx, [esp + 0x200]
// 005f88f5  51                   push ecx
// 005f88f6  8bcf                 mov ecx, edi
// 005f88f8  ffd2                 call edx
// 005f88fa  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 005f8901  8b07                 mov eax, dword ptr [edi]
// 005f8903  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f8906  8d4c2478             lea ecx, [esp + 0x78]
// 005f890a  51                   push ecx
// 005f890b  8bcf                 mov ecx, edi
// 005f890d  ffd2                 call edx
// 005f890f  89842460010000       mov dword ptr [esp + 0x160], eax
// 005f8916  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005f891d  40                   inc eax
// 005f891e  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f8925  3bc3                 cmp eax, ebx
// 005f8927  8d84246c010000       lea eax, [esp + 0x16c]
// 005f892e  7c07                 jl 0x5f8937
// 005f8930  8d8424e8000000       lea eax, [esp + 0xe8]
// 005f8937  8b18                 mov ebx, dword ptr [eax]
// 005f8939  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 005f8940  8bc8                 mov ecx, eax
// 005f8942  40                   inc eax
// 005f8943  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f894a  85c9                 test ecx, ecx
// 005f894c  0f85f9000000         jne 0x5f8a4b
// 005f8952  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 005f8959  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005f895c  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 005f8965  8911                 mov dword ptr [ecx], edx
// 005f8967  f30f1106             movss dword ptr [esi], xmm0
// 005f896b  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 005f8974  f30f114604           movss dword ptr [esi + 4], xmm0
// 005f8979  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 005f8982  f30f114608           movss dword ptr [esi + 8], xmm0
// 005f8987  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 005f8990  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 005f8995  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 005f899e  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 005f89a3  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 005f89ac  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 005f89b1  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 005f89ba  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 005f89bf  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 005f89c8  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 005f89cd  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 005f89d6  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 005f89db  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 005f89e4  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 005f89e9  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 005f89f2  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 005f89f7  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 005f8a00  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 005f8a05  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 005f8a0e  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 005f8a13  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 005f8a1c  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 005f8a21  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 005f8a2a  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 005f8a2f  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 005f8a38  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 005f8a3d  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 005f8a46  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 005f8a4b  8bd3                 mov edx, ebx
// 005f8a4d  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 005f8a52  8d0c9501000000       lea ecx, [edx*4 + 1]
// 005f8a59  8bd0                 mov edx, eax
// 005f8a5b  40                   inc eax
// 005f8a5c  3bd1                 cmp edx, ecx
// 005f8a5e  0f8501010000         jne 0x5f8b65
// 005f8a64  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005f8a6b  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005f8a6e  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 005f8a77  894a04               mov dword ptr [edx + 4], ecx
// 005f8a7a  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 005f8a7f  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 005f8a88  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 005f8a8d  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 005f8a96  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 005f8a9b  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 005f8aa4  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 005f8aa9  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 005f8ab2  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 005f8ab7  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 005f8ac0  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 005f8ac5  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 005f8ace  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 005f8ad3  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 005f8adc  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 005f8ae1  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 005f8aea  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 005f8aef  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 005f8af8  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 005f8afd  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 005f8b06  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 005f8b0b  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 005f8b14  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 005f8b19  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 005f8b22  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 005f8b27  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 005f8b30  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 005f8b35  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 005f8b3e  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 005f8b43  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 005f8b4c  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 005f8b54  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 005f8b5d  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 005f8b65  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f8b69  41                   inc ecx
// 005f8b6a  0fafcb               imul ecx, ebx
// 005f8b6d  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 005f8b74  8bc8                 mov ecx, eax
// 005f8b76  40                   inc eax
// 005f8b77  3bca                 cmp ecx, edx
// 005f8b79  0f852e010000         jne 0x5f8cad
// 005f8b7f  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 005f8b86  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005f8b89  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005f8b92  895108               mov dword ptr [ecx + 8], edx
// 005f8b95  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 005f8b9d  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 005f8ba6  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 005f8bae  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 005f8bb7  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 005f8bbf  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 005f8bc8  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 005f8bd0  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 005f8bd9  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 005f8be1  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 005f8bea  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 005f8bf2  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 005f8bfb  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 005f8c03  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 005f8c0c  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 005f8c14  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 005f8c1d  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 005f8c25  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 005f8c2e  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 005f8c36  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 005f8c3f  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 005f8c47  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 005f8c50  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 005f8c58  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 005f8c61  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 005f8c69  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 005f8c72  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 005f8c7a  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 005f8c83  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 005f8c8b  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 005f8c94  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 005f8c9c  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 005f8ca5  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 005f8cad  8bc8                 mov ecx, eax
// 005f8caf  8d149dffffffff       lea edx, [ebx*4 - 1]
// 005f8cb6  40                   inc eax
// 005f8cb7  89842478010000       mov dword ptr [esp + 0x178], eax
// 005f8cbe  3bca                 cmp ecx, edx
// 005f8cc0  0f8528010000         jne 0x5f8dee
// 005f8cc6  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005f8cc9  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005f8cd0  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 005f8cd6  89420c               mov dword ptr [edx + 0xc], eax
// 005f8cd9  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 005f8ce1  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 005f8ce7  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 005f8cef  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 005f8cf8  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 005f8d00  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 005f8d09  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 005f8d11  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 005f8d1a  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 005f8d22  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 005f8d2b  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 005f8d33  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 005f8d3c  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 005f8d44  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 005f8d4d  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 005f8d55  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 005f8d5e  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 005f8d66  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 005f8d6f  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 005f8d77  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 005f8d80  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 005f8d88  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 005f8d91  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 005f8d99  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 005f8da2  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 005f8daa  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 005f8db3  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 005f8dbb  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 005f8dc4  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 005f8dcc  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 005f8dd5  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 005f8ddd  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 005f8de6  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 005f8dee  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005f8df5  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005f8dfc  8b17                 mov edx, dword ptr [edi]
// 005f8dfe  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f8e01  50                   push eax
// 005f8e02  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 005f8e09  51                   push ecx
// 005f8e0a  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 005f8e11  50                   push eax
// 005f8e12  51                   push ecx
// 005f8e13  8bcf                 mov ecx, edi
// 005f8e15  ffd2                 call edx
// 005f8e17  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f8e1d  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 005f8e26  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f8e2e  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 005f8e37  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 005f8e3d  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f8e43  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f8e48  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005f8e4f  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f8e53  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005f8e57  e9b3eeffff           jmp 0x5f7d0f
// 005f8e5c  0f28fa               movaps xmm7, xmm2
// 005f8e5f  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 005f8e65  0f28d9               movaps xmm3, xmm1
// 005f8e68  42                   inc edx
// 005f8e69  e90feeffff           jmp 0x5f7c7d
// 005f8e6e  8bff                 mov edi, edi
// 005f8e70  1e                   push ds
// 005f8e71  715f                 jno 0x5f8ed2
// 005f8e73  0089725f0075         add byte ptr [ecx + 0x75005f72], cl
// 005f8e79  715f                 jno 0x5f8eda
// 005f8e7b  003b                 add byte ptr [ebx], bh
// 005f8e7d  725f                 jb 0x5f8ede
// 005f8e7f  00b3715f00f7         add byte ptr [ebx - 0x8ffa08f], dh
// 005f8e85  715f                 jno 0x5f8ee6

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
