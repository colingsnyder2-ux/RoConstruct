// from server: 11% by intel
// roc 2012-06 005fe9e0  unit: seg_005f0000  size: 7788 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005fe9e0
//
// 005fe9e0  55                   push ebp
// 005fe9e1  8bec                 mov ebp, esp
// 005fe9e3  83e4f8               and esp, 0xfffffff8
// 005fe9e6  81ecfc030000         sub esp, 0x3fc
// 005fe9ec  53                   push ebx
// 005fe9ed  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005fe9f0  56                   push esi
// 005fe9f1  57                   push edi
// 005fe9f2  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005fe9f5  8d44246c             lea eax, [esp + 0x6c]
// 005fe9f9  8bf1                 mov esi, ecx
// 005fe9fb  53                   push ebx
// 005fe9fc  c1ef0c               shr edi, 0xc
// 005fe9ff  50                   push eax
// 005fea00  89742464             mov dword ptr [esp + 0x64], esi
// 005fea04  83e707               and edi, 7
// 005fea07  e8648c2200           call 0x827670
// 005fea0c  d9442474             fld dword ptr [esp + 0x74]
// 005fea10  d9e1                 fabs 
// 005fea12  8d4c2474             lea ecx, [esp + 0x74]
// 005fea16  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005fea1d  53                   push ebx
// 005fea1e  d944247c             fld dword ptr [esp + 0x7c]
// 005fea22  51                   push ecx
// 005fea23  d9e1                 fabs 
// 005fea25  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005fea2c  d9842484000000       fld dword ptr [esp + 0x84]
// 005fea33  d9e1                 fabs 
// 005fea35  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005fea3c  e82f8c2200           call 0x827670
// 005fea41  d944247c             fld dword ptr [esp + 0x7c]
// 005fea45  8a4670               mov al, byte ptr [esi + 0x70]
// 005fea48  d9e1                 fabs 
// 005fea4a  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005fea52  d9842480000000       fld dword ptr [esp + 0x80]
// 005fea59  83c410               add esp, 0x10
// 005fea5c  d9e1                 fabs 
// 005fea5e  d9442474             fld dword ptr [esp + 0x74]
// 005fea62  d9e1                 fabs 
// 005fea64  d9450c               fld dword ptr [ebp + 0xc]
// 005fea67  dceb                 fsub st(3), st(0)
// 005fea69  d9cb                 fxch st(3)
// 005fea6b  d95c241c             fstp dword ptr [esp + 0x1c]
// 005fea6f  d9c9                 fxch st(1)
// 005fea71  dee2                 fsubrp st(2)
// 005fea73  d9c9                 fxch st(1)
// 005fea75  d95c2420             fstp dword ptr [esp + 0x20]
// 005fea79  d95c2424             fstp dword ptr [esp + 0x24]
// 005fea7d  84c0                 test al, al
// 005fea7f  741b                 je 0x5fea9c
// 005fea81  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005fea89  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005fea92  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005fea9a  eb11                 jmp 0x5feaad
// 005fea9c  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005feaa4  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005feaad  0f57e4               xorps xmm4, xmm4
// 005feab0  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005feab9  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005feabf  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005feac5  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005feacb  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005fead1  83ff05               cmp edi, 5
// 005fead4  0f87a4010000         ja 0x5fec7e
// 005feada  ff24bd34086000       jmp dword ptr [edi*4 + 0x600834]
// 005feae1  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005feae9  8d542460             lea edx, [esp + 0x60]
// 005feaed  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005feaf3  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005feafb  52                   push edx
// 005feafc  8d4c2420             lea ecx, [esp + 0x20]
// 005feb00  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005feb06  e835570300           call 0x634240
// 005feb0b  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005feb13  f30f1000             movss xmm0, dword ptr [eax]
// 005feb17  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005feb1c  0f57e4               xorps xmm4, xmm4
// 005feb1f  f30f59c5             mulss xmm0, xmm5
// 005feb23  f30f59cd             mulss xmm1, xmm5
// 005feb27  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005feb2d  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005feb33  e946010000           jmp 0x5fec7e
// 005feb38  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005feb40  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005feb46  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005feb4c  84c0                 test al, al
// 005feb4e  7413                 je 0x5feb63
// 005feb50  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005feb58  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005feb5e  e91b010000           jmp 0x5fec7e
// 005feb63  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005feb6b  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005feb71  e908010000           jmp 0x5fec7e
// 005feb76  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005feb7c  84c0                 test al, al
// 005feb7e  7419                 je 0x5feb99
// 005feb80  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005feb88  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005feb8e  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005feb94  e9e5000000           jmp 0x5fec7e
// 005feb99  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005feba1  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005feba7  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005febaf  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005febb5  e9c4000000           jmp 0x5fec7e
// 005febba  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005febc0  84c0                 test al, al
// 005febc2  7419                 je 0x5febdd
// 005febc4  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005febcc  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005febd2  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005febd8  e9a1000000           jmp 0x5fec7e
// 005febdd  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005febe5  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005febeb  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005febf3  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005febf9  e980000000           jmp 0x5fec7e
// 005febfe  84c0                 test al, al
// 005fec00  745a                 je 0x5fec5c
// 005fec02  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005fec09  7441                 je 0x5fec4c
// 005fec0b  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005fec10  85c0                 test eax, eax
// 005fec12  7418                 je 0x5fec2c
// 005fec14  68b7000000           push 0xb7
// 005fec19  688027b800           push 0xb82780
// 005fec1e  68cc60b400           push 0xb460cc
// 005fec23  ffd0                 call eax
// 005fec25  83c40c               add esp, 0xc
// 005fec28  84c0                 test al, al
// 005fec2a  7515                 jne 0x5fec41
// 005fec2c  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005fec33  680827b800           push 0xb82708
// 005fec38  50                   push eax
// 005fec39  e852363700           call 0x972290
// 005fec3e  83c408               add esp, 8
// 005fec41  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005fec49  0f57e4               xorps xmm4, xmm4
// 005fec4c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005fec54  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005fec5a  eb1c                 jmp 0x5fec78
// 005fec5c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005fec64  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005fec6a  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005fec72  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005fec78  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005fec7e  807e7000             cmp byte ptr [esi + 0x70], 0
// 005fec82  7419                 je 0x5fec9d
// 005fec84  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005fec89  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005fec91  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005fec97  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005fec9d  85ff                 test edi, edi
// 005fec9f  0f859c080000         jne 0x5ff541
// 005feca5  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fecad  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005fecb2  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005fecba  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005fecbf  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005fecc5  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005fecce  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005fecd6  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005fecdc  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005fece5  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005fecee  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005fecf7  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005fed00  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005fed09  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005fed12  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005fed1b  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005fed24  f30f59c5             mulss xmm0, xmm5
// 005fed28  f30f59cd             mulss xmm1, xmm5
// 005fed2c  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005fed35  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005fed3e  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005fed43  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005fed4c  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005fed55  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005fed5c  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005fed62  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005fed6b  0f28e3               movaps xmm4, xmm3
// 005fed6e  f30f5ce0             subss xmm4, xmm0
// 005fed72  0f28eb               movaps xmm5, xmm3
// 005fed75  f30f5ce9             subss xmm5, xmm1
// 005fed79  51                   push ecx
// 005fed7a  8d542464             lea edx, [esp + 0x64]
// 005fed7e  f30f5cc3             subss xmm0, xmm3
// 005fed82  0f28d3               movaps xmm2, xmm3
// 005fed85  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005fed8c  f30f5ccb             subss xmm1, xmm3
// 005fed90  52                   push edx
// 005fed91  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005fed9a  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005feda3  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005fedac  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005fedb5  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005fedbe  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005fedc7  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005fedd0  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005fedd9  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005fede2  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005fedeb  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005fedf4  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005fedfd  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005fee06  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005fee0f  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005fee18  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005fee21  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005fee2a  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005fee33  e838882200           call 0x827670
// 005fee38  8d442474             lea eax, [esp + 0x74]
// 005fee3c  50                   push eax
// 005fee3d  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005fee44  51                   push ecx
// 005fee45  e826882200           call 0x827670
// 005fee4a  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005fee52  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005fee58  0f57c8               xorps xmm1, xmm0
// 005fee5b  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005fee64  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005fee6a  8d9424d0000000       lea edx, [esp + 0xd0]
// 005fee71  0f57c8               xorps xmm1, xmm0
// 005fee74  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fee7a  52                   push edx
// 005fee7b  8d8424ec000000       lea eax, [esp + 0xec]
// 005fee82  50                   push eax
// 005fee83  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005fee8c  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005fee95  e8d6872200           call 0x827670
// 005fee9a  83c418               add esp, 0x18
// 005fee9d  8d4c2440             lea ecx, [esp + 0x40]
// 005feea1  51                   push ecx
// 005feea2  8d8c2480010000       lea ecx, [esp + 0x180]
// 005feea9  e892530300           call 0x634240
// 005feeae  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005feeb5  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005feebb  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005feec2  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005feec9  8b7d20               mov edi, dword ptr [ebp + 0x20]
// 005feecc  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005feed5  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005feedb  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005feee4  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005feeea  89542478             mov dword ptr [esp + 0x78], edx
// 005feeee  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005feef5  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005feefe  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005fef04  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005fef0b  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005fef12  89942484000000       mov dword ptr [esp + 0x84], edx
// 005fef19  8b542460             mov edx, dword ptr [esp + 0x60]
// 005fef1d  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fef26  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005fef2b  8944247c             mov dword ptr [esp + 0x7c], eax
// 005fef2f  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005fef36  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005fef3d  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005fef41  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fef4a  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fef53  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005fef5c  89942490000000       mov dword ptr [esp + 0x90], edx
// 005fef63  89842488000000       mov dword ptr [esp + 0x88], eax
// 005fef6a  8b442464             mov eax, dword ptr [esp + 0x64]
// 005fef6e  8d542478             lea edx, [esp + 0x78]
// 005fef72  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005fef79  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fef82  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005fef8b  52                   push edx
// 005fef8c  8bcf                 mov ecx, edi
// 005fef8e  89842498000000       mov dword ptr [esp + 0x98], eax
// 005fef95  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fef9e  e81db3feff           call 0x5ea2c0
// 005fefa3  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005fefac  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005fefb2  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005fefbb  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005fefc1  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005fefca  8d84248c010000       lea eax, [esp + 0x18c]
// 005fefd1  50                   push eax
// 005fefd2  8d4c2464             lea ecx, [esp + 0x64]
// 005fefd6  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005fefdc  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005fefe5  51                   push ecx
// 005fefe6  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005fefec  e87f862200           call 0x827670
// 005feff1  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005feff8  52                   push edx
// 005feff9  8d8424d8000000       lea eax, [esp + 0xd8]
// 005ff000  50                   push eax
// 005ff001  e86a862200           call 0x827670
// 005ff006  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ff00c  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005ff015  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ff01b  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ff022  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005ff029  51                   push ecx
// 005ff02a  8d9424ec000000       lea edx, [esp + 0xec]
// 005ff031  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005ff03a  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ff040  52                   push edx
// 005ff041  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005ff04a  e821862200           call 0x827670
// 005ff04f  83c418               add esp, 0x18
// 005ff052  8d442440             lea eax, [esp + 0x40]
// 005ff056  50                   push eax
// 005ff057  8d8c2410010000       lea ecx, [esp + 0x110]
// 005ff05e  e8dd510300           call 0x634240
// 005ff063  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005ff06a  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005ff071  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005ff078  894c2478             mov dword ptr [esp + 0x78], ecx
// 005ff07c  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005ff083  8954247c             mov dword ptr [esp + 0x7c], edx
// 005ff087  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005ff08e  89842480000000       mov dword ptr [esp + 0x80], eax
// 005ff095  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005ff09c  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005ff0a2  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005ff0a6  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005ff0ad  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005ff0b6  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005ff0bc  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005ff0c5  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005ff0cb  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005ff0d4  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005ff0da  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005ff0e3  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005ff0e9  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005ff0f2  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ff0f8  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005ff0ff  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005ff108  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ff10e  8d4c2478             lea ecx, [esp + 0x78]
// 005ff112  89942488000000       mov dword ptr [esp + 0x88], edx
// 005ff119  8b542464             mov edx, dword ptr [esp + 0x64]
// 005ff11d  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005ff124  8b442468             mov eax, dword ptr [esp + 0x68]
// 005ff128  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005ff131  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ff137  8d5f44               lea ebx, [edi + 0x44]
// 005ff13a  51                   push ecx
// 005ff13b  8bcb                 mov ecx, ebx
// 005ff13d  89942498000000       mov dword ptr [esp + 0x98], edx
// 005ff144  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005ff14b  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005ff154  e867b1feff           call 0x5ea2c0
// 005ff159  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005ff162  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005ff168  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005ff171  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005ff177  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005ff180  8d94248c010000       lea edx, [esp + 0x18c]
// 005ff187  52                   push edx
// 005ff188  8d442464             lea eax, [esp + 0x64]
// 005ff18c  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005ff192  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005ff19b  50                   push eax
// 005ff19c  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005ff1a2  e8c9842200           call 0x827670
// 005ff1a7  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005ff1ae  51                   push ecx
// 005ff1af  8d9424d8000000       lea edx, [esp + 0xd8]
// 005ff1b6  52                   push edx
// 005ff1b7  e8b4842200           call 0x827670
// 005ff1bc  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ff1c2  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005ff1cb  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ff1d1  8d8424d0000000       lea eax, [esp + 0xd0]
// 005ff1d8  50                   push eax
// 005ff1d9  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005ff1e0  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005ff1e9  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ff1ef  51                   push ecx
// 005ff1f0  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005ff1f9  e872842200           call 0x827670
// 005ff1fe  83c418               add esp, 0x18
// 005ff201  8d542440             lea edx, [esp + 0x40]
// 005ff205  52                   push edx
// 005ff206  8d8c2430010000       lea ecx, [esp + 0x130]
// 005ff20d  e82e500300           call 0x634240
// 005ff212  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005ff219  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005ff220  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005ff227  89442478             mov dword ptr [esp + 0x78], eax
// 005ff22b  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005ff232  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005ff236  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005ff23d  89942480000000       mov dword ptr [esp + 0x80], edx
// 005ff244  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005ff24b  89842484000000       mov dword ptr [esp + 0x84], eax
// 005ff252  8b442460             mov eax, dword ptr [esp + 0x60]
// 005ff256  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005ff25d  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005ff261  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005ff268  8b542468             mov edx, dword ptr [esp + 0x68]
// 005ff26c  89842490000000       mov dword ptr [esp + 0x90], eax
// 005ff273  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005ff27a  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005ff280  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005ff289  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005ff28f  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005ff298  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005ff29e  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005ff2a7  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005ff2ad  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005ff2b6  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005ff2bc  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005ff2c5  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ff2cb  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005ff2d4  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ff2da  8d442478             lea eax, [esp + 0x78]
// 005ff2de  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005ff2e7  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ff2ed  8d8f88000000         lea ecx, [edi + 0x88]
// 005ff2f3  50                   push eax
// 005ff2f4  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005ff2fb  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005ff304  894c2460             mov dword ptr [esp + 0x60], ecx
// 005ff308  e8b3affeff           call 0x5ea2c0
// 005ff30d  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005ff316  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005ff31c  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005ff325  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005ff32b  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005ff334  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005ff33b  51                   push ecx
// 005ff33c  8d542464             lea edx, [esp + 0x64]
// 005ff340  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005ff346  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005ff34f  52                   push edx
// 005ff350  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005ff356  e815832200           call 0x827670
// 005ff35b  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005ff362  50                   push eax
// 005ff363  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005ff36a  51                   push ecx
// 005ff36b  e800832200           call 0x827670
// 005ff370  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ff376  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ff37d  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005ff386  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ff38c  8d9424d0000000       lea edx, [esp + 0xd0]
// 005ff393  52                   push edx
// 005ff394  8d8424ec000000       lea eax, [esp + 0xec]
// 005ff39b  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005ff3a4  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ff3aa  50                   push eax
// 005ff3ab  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005ff3b4  e8b7822200           call 0x827670
// 005ff3b9  83c418               add esp, 0x18
// 005ff3bc  8d4c2440             lea ecx, [esp + 0x40]
// 005ff3c0  51                   push ecx
// 005ff3c1  8d8c2420010000       lea ecx, [esp + 0x120]
// 005ff3c8  e8734e0300           call 0x634240
// 005ff3cd  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005ff3d4  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005ff3db  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005ff3e2  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005ff3e8  89542478             mov dword ptr [esp + 0x78], edx
// 005ff3ec  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005ff3f3  8944247c             mov dword ptr [esp + 0x7c], eax
// 005ff3f7  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005ff3fe  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005ff405  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005ff40c  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005ff415  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005ff41b  89942484000000       mov dword ptr [esp + 0x84], edx
// 005ff422  8b542460             mov edx, dword ptr [esp + 0x60]
// 005ff426  89842488000000       mov dword ptr [esp + 0x88], eax
// 005ff42d  8b442464             mov eax, dword ptr [esp + 0x64]
// 005ff431  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005ff438  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005ff43c  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005ff445  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005ff44b  89942490000000       mov dword ptr [esp + 0x90], edx
// 005ff452  89842494000000       mov dword ptr [esp + 0x94], eax
// 005ff459  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005ff460  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005ff469  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005ff46f  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005ff478  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005ff47e  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005ff487  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ff48d  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005ff496  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ff49c  8d542478             lea edx, [esp + 0x78]
// 005ff4a0  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005ff4a9  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ff4af  8d8fcc000000         lea ecx, [edi + 0xcc]
// 005ff4b5  52                   push edx
// 005ff4b6  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005ff4bf  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005ff4c6  e8f5adfeff           call 0x5ea2c0
// 005ff4cb  8b7518               mov esi, dword ptr [ebp + 0x18]
// 005ff4ce  8b06                 mov eax, dword ptr [esi]
// 005ff4d0  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ff4d3  57                   push edi
// 005ff4d4  8bce                 mov ecx, esi
// 005ff4d6  ffd2                 call edx
// 005ff4d8  8bf8                 mov edi, eax
// 005ff4da  8b06                 mov eax, dword ptr [esi]
// 005ff4dc  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ff4df  53                   push ebx
// 005ff4e0  8bce                 mov ecx, esi
// 005ff4e2  ffd2                 call edx
// 005ff4e4  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005ff4e8  8bd8                 mov ebx, eax
// 005ff4ea  8b06                 mov eax, dword ptr [esi]
// 005ff4ec  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ff4ef  51                   push ecx
// 005ff4f0  8bce                 mov ecx, esi
// 005ff4f2  ffd2                 call edx
// 005ff4f4  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005ff4fb  8944243c             mov dword ptr [esp + 0x3c], eax
// 005ff4ff  8b06                 mov eax, dword ptr [esi]
// 005ff501  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ff504  51                   push ecx
// 005ff505  8bce                 mov ecx, esi
// 005ff507  ffd2                 call edx
// 005ff509  8b16                 mov edx, dword ptr [esi]
// 005ff50b  8b5218               mov edx, dword ptr [edx + 0x18]
// 005ff50e  50                   push eax
// 005ff50f  89442460             mov dword ptr [esp + 0x60], eax
// 005ff513  8b442440             mov eax, dword ptr [esp + 0x40]
// 005ff517  50                   push eax
// 005ff518  53                   push ebx
// 005ff519  57                   push edi
// 005ff51a  8bce                 mov ecx, esi
// 005ff51c  ffd2                 call edx
// 005ff51e  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005ff521  85c0                 test eax, eax
// 005ff523  7413                 je 0x5ff538
// 005ff525  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005ff529  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005ff52d  8938                 mov dword ptr [eax], edi
// 005ff52f  895804               mov dword ptr [eax + 4], ebx
// 005ff532  894808               mov dword ptr [eax + 8], ecx
// 005ff535  89500c               mov dword ptr [eax + 0xc], edx
// 005ff538  5f                   pop edi
// 005ff539  5e                   pop esi
// 005ff53a  5b                   pop ebx
// 005ff53b  8be5                 mov esp, ebp
// 005ff53d  5d                   pop ebp
// 005ff53e  c22000               ret 0x20
// 005ff541  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005ff548  743c                 je 0x5ff586
// 005ff54a  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005ff54e  7536                 jne 0x5ff586
// 005ff550  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005ff555  85c0                 test eax, eax
// 005ff557  7418                 je 0x5ff571
// 005ff559  6801010000           push 0x101
// 005ff55e  688027b800           push 0xb82780
// 005ff563  680027b800           push 0xb82700
// 005ff568  ffd0                 call eax
// 005ff56a  83c40c               add esp, 0xc
// 005ff56d  84c0                 test al, al
// 005ff56f  7515                 jne 0x5ff586
// 005ff571  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005ff578  688826b800           push 0xb82688
// 005ff57d  50                   push eax
// 005ff57e  e80d2d3700           call 0x972290
// 005ff583  83c408               add esp, 8
// 005ff586  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005ff58c  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ff593  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005ff59b  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005ff5a3  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005ff5a8  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005ff5ae  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005ff5b6  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005ff5bb  8d4c2460             lea ecx, [esp + 0x60]
// 005ff5bf  51                   push ecx
// 005ff5c0  f30f59c2             mulss xmm0, xmm2
// 005ff5c4  f30f59ca             mulss xmm1, xmm2
// 005ff5c8  8d4c2420             lea ecx, [esp + 0x20]
// 005ff5cc  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005ff5d5  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005ff5de  e85d4c0300           call 0x634240
// 005ff5e3  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005ff5ec  f30f5e00             divss xmm0, dword ptr [eax]
// 005ff5f0  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005ff5f5  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005ff5f8  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005ff5fb  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005ff600  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005ff608  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005ff60e  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005ff617  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005ff620  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005ff625  33d2                 xor edx, edx
// 005ff627  33db                 xor ebx, ebx
// 005ff629  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005ff632  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005ff639  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005ff640  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005ff646  0f2fd7               comiss xmm2, xmm7
// 005ff649  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005ff64f  8954243c             mov dword ptr [esp + 0x3c], edx
// 005ff653  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005ff65c  770a                 ja 0x5ff668
// 005ff65e  85d2                 test edx, edx
// 005ff660  0f85d2feffff         jne 0x5ff538
// 005ff666  eb04                 jmp 0x5ff66c
// 005ff668  85d2                 test edx, edx
// 005ff66a  7504                 jne 0x5ff670
// 005ff66c  f30f5cc4             subss xmm0, xmm4
// 005ff670  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005ff674  80797000             cmp byte ptr [ecx + 0x70], 0
// 005ff678  7421                 je 0x5ff69b
// 005ff67a  f30f58c7             addss xmm0, xmm7
// 005ff67e  0f2fc2               comiss xmm0, xmm2
// 005ff681  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005ff68a  8d44241c             lea eax, [esp + 0x1c]
// 005ff68e  7707                 ja 0x5ff697
// 005ff690  8d84240c030000       lea eax, [esp + 0x30c]
// 005ff697  f30f1010             movss xmm2, dword ptr [eax]
// 005ff69b  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005ff6a4  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005ff6aa  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ff6b1  f30f58cb             addss xmm1, xmm3
// 005ff6b5  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005ff6ba  33c0                 xor eax, eax
// 005ff6bc  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005ff6c2  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005ff6cb  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005ff6d2  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005ff6d8  0f2ff0               comiss xmm6, xmm0
// 005ff6db  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005ff6e4  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005ff6ea  7708                 ja 0x5ff6f4
// 005ff6ec  85c0                 test eax, eax
// 005ff6ee  0f852b110000         jne 0x60081f
// 005ff6f4  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005ff6fa  85c0                 test eax, eax
// 005ff6fc  7504                 jne 0x5ff702
// 005ff6fe  f30f5ccc             subss xmm1, xmm4
// 005ff702  0f28f1               movaps xmm6, xmm1
// 005ff705  f30f58f0             addss xmm6, xmm0
// 005ff709  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005ff70e  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005ff717  8d442420             lea eax, [esp + 0x20]
// 005ff71b  7707                 ja 0x5ff724
// 005ff71d  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005ff724  80797000             cmp byte ptr [ecx + 0x70], 0
// 005ff728  f30f1000             movss xmm0, dword ptr [eax]
// 005ff72c  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005ff732  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005ff73b  f30f58c3             addss xmm0, xmm3
// 005ff73f  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005ff748  0f57c0               xorps xmm0, xmm0
// 005ff74b  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005ff751  740f                 je 0x5ff762
// 005ff753  e838abfeff           call 0x5ea290
// 005ff758  d80d94deb600         fmul dword ptr [0xb6de94]
// 005ff75e  d95c2440             fstp dword ptr [esp + 0x40]
// 005ff762  0f28dd               movaps xmm3, xmm5
// 005ff765  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005ff76e  0f28c3               movaps xmm0, xmm3
// 005ff771  f30f59c4             mulss xmm0, xmm4
// 005ff775  f30f5cd7             subss xmm2, xmm7
// 005ff779  f30f59d3             mulss xmm2, xmm3
// 005ff77d  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005ff783  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005ff789  f30f58d3             addss xmm2, xmm3
// 005ff78d  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005ff793  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005ff799  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005ff79f  0f28c5               movaps xmm0, xmm5
// 005ff7a2  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005ff7ab  0f28e9               movaps xmm5, xmm1
// 005ff7ae  0f28f0               movaps xmm6, xmm0
// 005ff7b1  f30f59f4             mulss xmm6, xmm4
// 005ff7b5  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005ff7bb  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005ff7c1  f30f5ccb             subss xmm1, xmm3
// 005ff7c5  f30f59e8             mulss xmm5, xmm0
// 005ff7c9  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005ff7cf  f30f59c8             mulss xmm1, xmm0
// 005ff7d3  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005ff7d9  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005ff7e2  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005ff7eb  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005ff7f4  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005ff7fd  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005ff806  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005ff80f  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005ff818  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005ff821  85d2                 test edx, edx
// 005ff823  753f                 jne 0x5ff864
// 005ff825  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005ff82b  0f28c4               movaps xmm0, xmm4
// 005ff82e  f30f58c3             addss xmm0, xmm3
// 005ff832  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005ff83b  0f28c3               movaps xmm0, xmm3
// 005ff83e  f30f58c2             addss xmm0, xmm2
// 005ff842  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005ff84b  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005ff854  0f28c4               movaps xmm0, xmm4
// 005ff857  f30f58c3             addss xmm0, xmm3
// 005ff85b  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005ff864  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005ff86a  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005ff86f  772f                 ja 0x5ff8a0
// 005ff871  0f28c6               movaps xmm0, xmm6
// 005ff874  f30f58c5             addss xmm0, xmm5
// 005ff878  f30f58f1             addss xmm6, xmm1
// 005ff87c  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005ff885  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005ff88e  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005ff897  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005ff8a0  8d9424cc000000       lea edx, [esp + 0xcc]
// 005ff8a7  52                   push edx
// 005ff8a8  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ff8af  e88c490300           call 0x634240
// 005ff8b4  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005ff8b9  f30f1008             movss xmm1, dword ptr [eax]
// 005ff8bd  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005ff8c3  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005ff8c9  8d8424d8000000       lea eax, [esp + 0xd8]
// 005ff8d0  50                   push eax
// 005ff8d1  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ff8d8  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005ff8e1  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005ff8ea  e851490300           call 0x634240
// 005ff8ef  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005ff8f4  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005ff8fa  f30f5808             addss xmm1, dword ptr [eax]
// 005ff8fe  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005ff904  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005ff90b  51                   push ecx
// 005ff90c  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ff913  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005ff91c  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005ff925  e816490300           call 0x634240
// 005ff92a  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005ff930  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005ff935  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005ff93b  f30f5c08             subss xmm1, dword ptr [eax]
// 005ff93f  8d94248c010000       lea edx, [esp + 0x18c]
// 005ff946  52                   push edx
// 005ff947  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ff94e  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005ff957  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005ff960  e8db480300           call 0x634240
// 005ff965  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005ff96b  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005ff970  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005ff976  f30f5c08             subss xmm1, dword ptr [eax]
// 005ff97a  8d842498010000       lea eax, [esp + 0x198]
// 005ff981  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005ff98a  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ff992  50                   push eax
// 005ff993  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005ff99a  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005ff9a0  0f57c0               xorps xmm0, xmm0
// 005ff9a3  51                   push ecx
// 005ff9a4  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005ff9ab  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005ff9b4  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005ff9ba  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005ff9c0  e84b480300           call 0x634210
// 005ff9c5  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005ff9ce  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005ff9d7  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005ff9e0  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005ff9e9  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005ff9f2  8d9424ec000000       lea edx, [esp + 0xec]
// 005ff9f9  52                   push edx
// 005ff9fa  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005ffa01  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005ffa0a  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005ffa13  50                   push eax
// 005ffa14  8d8c2484010000       lea ecx, [esp + 0x184]
// 005ffa1b  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005ffa24  e8e7470300           call 0x634210
// 005ffa29  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005ffa32  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005ffa38  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005ffa41  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005ffa47  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005ffa50  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005ffa56  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005ffa5f  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005ffa65  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005ffa6e  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005ffa77  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005ffa80  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005ffa89  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005ffa92  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005ffa9b  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005ffaa4  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005ffaad  8d4c246c             lea ecx, [esp + 0x6c]
// 005ffab1  51                   push ecx
// 005ffab2  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005ffab9  52                   push edx
// 005ffaba  e8b17b2200           call 0x827670
// 005ffabf  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005ffac8  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005ffad1  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005ffada  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005ffae1  50                   push eax
// 005ffae2  8d8c2484030000       lea ecx, [esp + 0x384]
// 005ffae9  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005ffaf2  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ffafa  51                   push ecx
// 005ffafb  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005ffb04  e8677b2200           call 0x827670
// 005ffb09  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005ffb0f  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005ffb18  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005ffb1e  8d942470030000       lea edx, [esp + 0x370]
// 005ffb25  52                   push edx
// 005ffb26  8d842450030000       lea eax, [esp + 0x350]
// 005ffb2d  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005ffb36  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ffb3c  50                   push eax
// 005ffb3d  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005ffb46  e8257b2200           call 0x827670
// 005ffb4b  83c418               add esp, 0x18
// 005ffb4e  8d8c2430030000       lea ecx, [esp + 0x330]
// 005ffb55  51                   push ecx
// 005ffb56  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005ffb5d  e8de460300           call 0x634240
// 005ffb62  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005ffb6b  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005ffb72  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005ffb79  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005ffb80  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005ffb89  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005ffb92  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005ffb9b  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005ffba4  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005ffbad  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005ffbb6  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005ffbbf  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005ffbc8  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005ffbd1  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005ffbda  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005ffbe3  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005ffbec  89942448020000       mov dword ptr [esp + 0x248], edx
// 005ffbf3  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005ffbfa  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005ffc03  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005ffc0c  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005ffc13  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005ffc1a  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005ffc23  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005ffc2c  89942454020000       mov dword ptr [esp + 0x254], edx
// 005ffc33  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005ffc3a  89842458020000       mov dword ptr [esp + 0x258], eax
// 005ffc41  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005ffc48  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005ffc51  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005ffc5a  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005ffc61  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005ffc68  89942460020000       mov dword ptr [esp + 0x260], edx
// 005ffc6f  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005ffc78  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005ffc81  8d54246c             lea edx, [esp + 0x6c]
// 005ffc85  89842464020000       mov dword ptr [esp + 0x264], eax
// 005ffc8c  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005ffc93  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005ffc9a  52                   push edx
// 005ffc9b  8d842470030000       lea eax, [esp + 0x370]
// 005ffca2  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005ffcab  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005ffcb4  50                   push eax
// 005ffcb5  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005ffcbc  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005ffcc5  e8a6792200           call 0x827670
// 005ffcca  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005ffcd3  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005ffcdc  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005ffce5  8d8c2498030000       lea ecx, [esp + 0x398]
// 005ffcec  51                   push ecx
// 005ffced  8d942460030000       lea edx, [esp + 0x360]
// 005ffcf4  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005ffcfd  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ffd05  52                   push edx
// 005ffd06  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005ffd0f  e85c792200           call 0x827670
// 005ffd14  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005ffd1a  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005ffd23  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005ffd29  8d842400040000       lea eax, [esp + 0x400]
// 005ffd30  50                   push eax
// 005ffd31  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005ffd38  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005ffd41  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ffd47  51                   push ecx
// 005ffd48  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005ffd51  e81a792200           call 0x827670
// 005ffd56  83c418               add esp, 0x18
// 005ffd59  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005ffd60  52                   push edx
// 005ffd61  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005ffd68  e8d3440300           call 0x634240
// 005ffd6d  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005ffd76  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005ffd7d  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005ffd84  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005ffd8b  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005ffd94  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005ffd9d  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005ffda6  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005ffdaf  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005ffdb8  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005ffdc1  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005ffdca  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005ffdd3  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005ffddc  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005ffde5  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005ffdee  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005ffdf7  89842490020000       mov dword ptr [esp + 0x290], eax
// 005ffdfe  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005ffe05  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005ffe0e  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005ffe17  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005ffe1e  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005ffe25  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005ffe2e  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005ffe37  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005ffe3e  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005ffe45  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005ffe4c  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005ffe53  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005ffe5c  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005ffe65  89942498020000       mov dword ptr [esp + 0x298], edx
// 005ffe6c  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005ffe73  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005ffe7a  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005ffe83  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005ffe8c  8d44246c             lea eax, [esp + 0x6c]
// 005ffe90  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005ffe97  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005ffe9e  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005ffea5  50                   push eax
// 005ffea6  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005ffead  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005ffeb6  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005ffebf  51                   push ecx
// 005ffec0  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005ffec7  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005ffed0  e89b772200           call 0x827670
// 005ffed5  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005ffede  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005ffee7  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005ffef0  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005ffef9  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fff01  8d94248c030000       lea edx, [esp + 0x38c]
// 005fff08  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005fff11  52                   push edx
// 005fff12  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005fff19  50                   push eax
// 005fff1a  e851772200           call 0x827670
// 005fff1f  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005fff25  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005fff2e  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005fff34  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005fff3b  51                   push ecx
// 005fff3c  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005fff43  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005fff4c  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fff52  52                   push edx
// 005fff53  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005fff5c  e80f772200           call 0x827670
// 005fff61  83c418               add esp, 0x18
// 005fff64  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005fff6b  50                   push eax
// 005fff6c  8d8c2480010000       lea ecx, [esp + 0x180]
// 005fff73  e8c8420300           call 0x634240
// 005fff78  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005fff81  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005fff88  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005fff8f  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005fff96  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005fff9f  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005fffa8  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005fffb1  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005fffba  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005fffc3  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005fffcc  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005fffd5  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005fffde  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005fffe7  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005ffff0  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005ffff9  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 00600002  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 00600009  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 00600010  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 00600019  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 00600022  89942404020000       mov dword ptr [esp + 0x204], edx
// 00600029  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 00600030  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 00600039  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 0060003f  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 00600046  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 0060004d  89942410020000       mov dword ptr [esp + 0x210], edx
// 00600054  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 0060005b  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 00600064  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 0060006a  89842408020000       mov dword ptr [esp + 0x208], eax
// 00600071  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 00600078  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 0060007f  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 00600088  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 0060008e  8d4c246c             lea ecx, [esp + 0x6c]
// 00600092  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 00600099  89842414020000       mov dword ptr [esp + 0x214], eax
// 006000a0  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 006000a7  51                   push ecx
// 006000a8  8d942410010000       lea edx, [esp + 0x110]
// 006000af  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 006000b8  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 006000be  52                   push edx
// 006000bf  89842428020000       mov dword ptr [esp + 0x228], eax
// 006000c6  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 006000cf  e89c752200           call 0x827670
// 006000d4  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 006000dd  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 006000e6  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 006000ef  8d842404040000       lea eax, [esp + 0x404]
// 006000f6  50                   push eax
// 006000f7  8d8c2438010000       lea ecx, [esp + 0x138]
// 006000fe  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 00600107  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0060010f  51                   push ecx
// 00600110  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 00600119  e852752200           call 0x827670
// 0060011e  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 00600124  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 0060012d  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 00600133  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 0060013c  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 00600142  8d9424b8030000       lea edx, [esp + 0x3b8]
// 00600149  52                   push edx
// 0060014a  8d842430010000       lea eax, [esp + 0x130]
// 00600151  50                   push eax
// 00600152  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 0060015b  e810752200           call 0x827670
// 00600160  83c418               add esp, 0x18
// 00600163  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 0060016a  51                   push ecx
// 0060016b  8d4c242c             lea ecx, [esp + 0x2c]
// 0060016f  e8cc400300           call 0x634240
// 00600174  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 0060017d  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 00600184  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 0060018b  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 00600192  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 0060019b  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 006001a4  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 006001ad  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 006001b6  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 006001bf  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 006001c8  89542478             mov dword ptr [esp + 0x78], edx
// 006001cc  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 006001d3  8944247c             mov dword ptr [esp + 0x7c], eax
// 006001d7  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 006001de  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 006001e7  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 006001f0  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 006001f7  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 006001fe  89942484000000       mov dword ptr [esp + 0x84], edx
// 00600205  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 0060020c  89842488000000       mov dword ptr [esp + 0x88], eax
// 00600213  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 0060021a  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 00600223  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 0060022c  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 00600233  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 0060023a  89942490000000       mov dword ptr [esp + 0x90], edx
// 00600241  8b17                 mov edx, dword ptr [edi]
// 00600243  8b5210               mov edx, dword ptr [edx + 0x10]
// 00600246  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 0060024f  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 00600258  89842494000000       mov dword ptr [esp + 0x94], eax
// 0060025f  8d842448020000       lea eax, [esp + 0x248]
// 00600266  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 0060026d  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 00600276  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 0060027f  50                   push eax
// 00600280  8bcf                 mov ecx, edi
// 00600282  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 0060028b  ffd2                 call edx
// 0060028d  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 00600294  8b07                 mov eax, dword ptr [edi]
// 00600296  8b5010               mov edx, dword ptr [eax + 0x10]
// 00600299  8d8c2490020000       lea ecx, [esp + 0x290]
// 006002a0  51                   push ecx
// 006002a1  8bcf                 mov ecx, edi
// 006002a3  ffd2                 call edx
// 006002a5  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 006002ac  8b07                 mov eax, dword ptr [edi]
// 006002ae  8b5010               mov edx, dword ptr [eax + 0x10]
// 006002b1  8d8c2400020000       lea ecx, [esp + 0x200]
// 006002b8  51                   push ecx
// 006002b9  8bcf                 mov ecx, edi
// 006002bb  ffd2                 call edx
// 006002bd  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 006002c4  8b07                 mov eax, dword ptr [edi]
// 006002c6  8b5010               mov edx, dword ptr [eax + 0x10]
// 006002c9  8d4c2478             lea ecx, [esp + 0x78]
// 006002cd  51                   push ecx
// 006002ce  8bcf                 mov ecx, edi
// 006002d0  ffd2                 call edx
// 006002d2  89842460010000       mov dword ptr [esp + 0x160], eax
// 006002d9  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 006002e0  40                   inc eax
// 006002e1  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 006002e8  3bc3                 cmp eax, ebx
// 006002ea  8d84246c010000       lea eax, [esp + 0x16c]
// 006002f1  7c07                 jl 0x6002fa
// 006002f3  8d8424e8000000       lea eax, [esp + 0xe8]
// 006002fa  8b18                 mov ebx, dword ptr [eax]
// 006002fc  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 00600303  8bc8                 mov ecx, eax
// 00600305  40                   inc eax
// 00600306  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 0060030d  85c9                 test ecx, ecx
// 0060030f  0f85f9000000         jne 0x60040e
// 00600315  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 0060031c  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 0060031f  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 00600328  8911                 mov dword ptr [ecx], edx
// 0060032a  f30f1106             movss dword ptr [esi], xmm0
// 0060032e  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 00600337  f30f114604           movss dword ptr [esi + 4], xmm0
// 0060033c  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 00600345  f30f114608           movss dword ptr [esi + 8], xmm0
// 0060034a  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 00600353  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 00600358  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 00600361  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 00600366  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 0060036f  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 00600374  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 0060037d  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 00600382  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 0060038b  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 00600390  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 00600399  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 0060039e  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 006003a7  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 006003ac  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 006003b5  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 006003ba  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 006003c3  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 006003c8  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 006003d1  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 006003d6  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 006003df  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 006003e4  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 006003ed  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 006003f2  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 006003fb  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 00600400  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 00600409  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 0060040e  8bd3                 mov edx, ebx
// 00600410  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 00600415  8d0c9501000000       lea ecx, [edx*4 + 1]
// 0060041c  8bd0                 mov edx, eax
// 0060041e  40                   inc eax
// 0060041f  3bd1                 cmp edx, ecx
// 00600421  0f8501010000         jne 0x600528
// 00600427  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 0060042e  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 00600431  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 0060043a  894a04               mov dword ptr [edx + 4], ecx
// 0060043d  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 00600442  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 0060044b  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 00600450  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 00600459  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 0060045e  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 00600467  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 0060046c  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 00600475  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 0060047a  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 00600483  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 00600488  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 00600491  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 00600496  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 0060049f  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 006004a4  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 006004ad  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 006004b2  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 006004bb  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 006004c0  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 006004c9  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 006004ce  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 006004d7  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 006004dc  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 006004e5  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 006004ea  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 006004f3  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 006004f8  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 00600501  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 00600506  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 0060050f  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 00600517  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 00600520  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 00600528  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0060052c  41                   inc ecx
// 0060052d  0fafcb               imul ecx, ebx
// 00600530  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 00600537  8bc8                 mov ecx, eax
// 00600539  40                   inc eax
// 0060053a  3bca                 cmp ecx, edx
// 0060053c  0f852e010000         jne 0x600670
// 00600542  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 00600549  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 0060054c  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 00600555  895108               mov dword ptr [ecx + 8], edx
// 00600558  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 00600560  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 00600569  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 00600571  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 0060057a  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 00600582  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 0060058b  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 00600593  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 0060059c  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 006005a4  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 006005ad  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 006005b5  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 006005be  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 006005c6  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 006005cf  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 006005d7  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 006005e0  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 006005e8  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 006005f1  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 006005f9  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 00600602  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 0060060a  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 00600613  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 0060061b  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 00600624  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 0060062c  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 00600635  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 0060063d  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 00600646  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 0060064e  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 00600657  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 0060065f  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 00600668  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 00600670  8bc8                 mov ecx, eax
// 00600672  8d149dffffffff       lea edx, [ebx*4 - 1]
// 00600679  40                   inc eax
// 0060067a  89842478010000       mov dword ptr [esp + 0x178], eax
// 00600681  3bca                 cmp ecx, edx
// 00600683  0f8528010000         jne 0x6007b1
// 00600689  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 0060068c  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 00600693  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 00600699  89420c               mov dword ptr [edx + 0xc], eax
// 0060069c  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 006006a4  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 006006aa  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 006006b2  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 006006bb  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 006006c3  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 006006cc  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 006006d4  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 006006dd  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 006006e5  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 006006ee  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 006006f6  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 006006ff  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 00600707  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 00600710  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 00600718  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 00600721  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 00600729  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 00600732  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 0060073a  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 00600743  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 0060074b  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 00600754  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 0060075c  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 00600765  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 0060076d  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 00600776  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 0060077e  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 00600787  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 0060078f  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 00600798  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 006007a0  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 006007a9  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 006007b1  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 006007b8  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 006007bf  8b17                 mov edx, dword ptr [edi]
// 006007c1  8b5218               mov edx, dword ptr [edx + 0x18]
// 006007c4  50                   push eax
// 006007c5  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 006007cc  51                   push ecx
// 006007cd  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 006007d4  50                   push eax
// 006007d5  51                   push ecx
// 006007d6  8bcf                 mov ecx, edi
// 006007d8  ffd2                 call edx
// 006007da  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 006007e0  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 006007e9  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 006007f1  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 006007fa  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 00600800  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 00600806  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 0060080b  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 00600812  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00600816  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0060081a  e9b3eeffff           jmp 0x5ff6d2
// 0060081f  0f28fa               movaps xmm7, xmm2
// 00600822  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 00600828  0f28d9               movaps xmm3, xmm1
// 0060082b  42                   inc edx
// 0060082c  e90feeffff           jmp 0x5ff640
// 00600831  8d4900               lea ecx, [ecx]
// 00600834  e1ea                 loope 0x600820
// 00600836  5f                   pop edi
// 00600837  004cec5f             add byte ptr [esp + ebp*8 + 0x5f], cl
// 0060083b  0038                 add byte ptr [eax], bh
// 0060083d  eb5f                 jmp 0x60089e
// 0060083f  00fe                 add dh, bh
// 00600841  eb5f                 jmp 0x6008a2
// 00600843  0076eb               add byte ptr [esi - 0x15], dh
// 00600846  5f                   pop edi

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
