// from server: 11% by intel
// roc 2012-06 005fcb70  unit: seg_005f0000  size: 7788 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005fcb70
//
// 005fcb70  55                   push ebp
// 005fcb71  8bec                 mov ebp, esp
// 005fcb73  83e4f8               and esp, 0xfffffff8
// 005fcb76  81ecfc030000         sub esp, 0x3fc
// 005fcb7c  53                   push ebx
// 005fcb7d  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005fcb80  56                   push esi
// 005fcb81  57                   push edi
// 005fcb82  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005fcb85  8d44246c             lea eax, [esp + 0x6c]
// 005fcb89  8bf1                 mov esi, ecx
// 005fcb8b  53                   push ebx
// 005fcb8c  c1ef09               shr edi, 9
// 005fcb8f  50                   push eax
// 005fcb90  89742464             mov dword ptr [esp + 0x64], esi
// 005fcb94  83e707               and edi, 7
// 005fcb97  e8a4aa2200           call 0x827640
// 005fcb9c  d9442474             fld dword ptr [esp + 0x74]
// 005fcba0  d9e1                 fabs 
// 005fcba2  8d4c2474             lea ecx, [esp + 0x74]
// 005fcba6  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005fcbad  53                   push ebx
// 005fcbae  d944247c             fld dword ptr [esp + 0x7c]
// 005fcbb2  51                   push ecx
// 005fcbb3  d9e1                 fabs 
// 005fcbb5  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005fcbbc  d9842484000000       fld dword ptr [esp + 0x84]
// 005fcbc3  d9e1                 fabs 
// 005fcbc5  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005fcbcc  e86faa2200           call 0x827640
// 005fcbd1  d944247c             fld dword ptr [esp + 0x7c]
// 005fcbd5  8a4670               mov al, byte ptr [esi + 0x70]
// 005fcbd8  d9e1                 fabs 
// 005fcbda  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005fcbe2  d9842480000000       fld dword ptr [esp + 0x80]
// 005fcbe9  83c410               add esp, 0x10
// 005fcbec  d9e1                 fabs 
// 005fcbee  d9442474             fld dword ptr [esp + 0x74]
// 005fcbf2  d9e1                 fabs 
// 005fcbf4  d9450c               fld dword ptr [ebp + 0xc]
// 005fcbf7  dceb                 fsub st(3), st(0)
// 005fcbf9  d9cb                 fxch st(3)
// 005fcbfb  d95c241c             fstp dword ptr [esp + 0x1c]
// 005fcbff  d9c9                 fxch st(1)
// 005fcc01  dee2                 fsubrp st(2)
// 005fcc03  d9c9                 fxch st(1)
// 005fcc05  d95c2420             fstp dword ptr [esp + 0x20]
// 005fcc09  d95c2424             fstp dword ptr [esp + 0x24]
// 005fcc0d  84c0                 test al, al
// 005fcc0f  741b                 je 0x5fcc2c
// 005fcc11  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005fcc19  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005fcc22  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005fcc2a  eb11                 jmp 0x5fcc3d
// 005fcc2c  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005fcc34  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005fcc3d  0f57e4               xorps xmm4, xmm4
// 005fcc40  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005fcc49  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005fcc4f  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005fcc55  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005fcc5b  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005fcc61  83ff05               cmp edi, 5
// 005fcc64  0f87a4010000         ja 0x5fce0e
// 005fcc6a  ff24bdc4e95f00       jmp dword ptr [edi*4 + 0x5fe9c4]
// 005fcc71  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005fcc79  8d542460             lea edx, [esp + 0x60]
// 005fcc7d  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005fcc83  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005fcc8b  52                   push edx
// 005fcc8c  8d4c2420             lea ecx, [esp + 0x20]
// 005fcc90  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005fcc96  e8a5750300           call 0x634240
// 005fcc9b  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005fcca3  f30f1000             movss xmm0, dword ptr [eax]
// 005fcca7  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005fccac  0f57e4               xorps xmm4, xmm4
// 005fccaf  f30f59c5             mulss xmm0, xmm5
// 005fccb3  f30f59cd             mulss xmm1, xmm5
// 005fccb7  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005fccbd  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005fccc3  e946010000           jmp 0x5fce0e
// 005fccc8  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005fccd0  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005fccd6  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005fccdc  84c0                 test al, al
// 005fccde  7413                 je 0x5fccf3
// 005fcce0  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005fcce8  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005fccee  e91b010000           jmp 0x5fce0e
// 005fccf3  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005fccfb  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005fcd01  e908010000           jmp 0x5fce0e
// 005fcd06  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005fcd0c  84c0                 test al, al
// 005fcd0e  7419                 je 0x5fcd29
// 005fcd10  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005fcd18  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005fcd1e  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005fcd24  e9e5000000           jmp 0x5fce0e
// 005fcd29  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005fcd31  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005fcd37  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005fcd3f  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005fcd45  e9c4000000           jmp 0x5fce0e
// 005fcd4a  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005fcd50  84c0                 test al, al
// 005fcd52  7419                 je 0x5fcd6d
// 005fcd54  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005fcd5c  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005fcd62  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005fcd68  e9a1000000           jmp 0x5fce0e
// 005fcd6d  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005fcd75  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005fcd7b  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005fcd83  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005fcd89  e980000000           jmp 0x5fce0e
// 005fcd8e  84c0                 test al, al
// 005fcd90  745a                 je 0x5fcdec
// 005fcd92  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005fcd99  7441                 je 0x5fcddc
// 005fcd9b  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005fcda0  85c0                 test eax, eax
// 005fcda2  7418                 je 0x5fcdbc
// 005fcda4  68b7000000           push 0xb7
// 005fcda9  688027b800           push 0xb82780
// 005fcdae  68cc60b400           push 0xb460cc
// 005fcdb3  ffd0                 call eax
// 005fcdb5  83c40c               add esp, 0xc
// 005fcdb8  84c0                 test al, al
// 005fcdba  7515                 jne 0x5fcdd1
// 005fcdbc  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005fcdc3  680827b800           push 0xb82708
// 005fcdc8  50                   push eax
// 005fcdc9  e8c2543700           call 0x972290
// 005fcdce  83c408               add esp, 8
// 005fcdd1  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005fcdd9  0f57e4               xorps xmm4, xmm4
// 005fcddc  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005fcde4  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005fcdea  eb1c                 jmp 0x5fce08
// 005fcdec  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005fcdf4  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005fcdfa  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005fce02  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005fce08  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005fce0e  807e7000             cmp byte ptr [esi + 0x70], 0
// 005fce12  7419                 je 0x5fce2d
// 005fce14  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005fce19  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005fce21  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005fce27  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005fce2d  85ff                 test edi, edi
// 005fce2f  0f859c080000         jne 0x5fd6d1
// 005fce35  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fce3d  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005fce42  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005fce4a  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005fce4f  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005fce55  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005fce5e  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005fce66  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005fce6c  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005fce75  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005fce7e  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005fce87  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005fce90  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005fce99  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005fcea2  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005fceab  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005fceb4  f30f59c5             mulss xmm0, xmm5
// 005fceb8  f30f59cd             mulss xmm1, xmm5
// 005fcebc  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005fcec5  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005fcece  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005fced3  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005fcedc  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005fcee5  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005fceec  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005fcef2  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005fcefb  0f28e3               movaps xmm4, xmm3
// 005fcefe  f30f5ce0             subss xmm4, xmm0
// 005fcf02  0f28eb               movaps xmm5, xmm3
// 005fcf05  f30f5ce9             subss xmm5, xmm1
// 005fcf09  51                   push ecx
// 005fcf0a  8d542464             lea edx, [esp + 0x64]
// 005fcf0e  f30f5cc3             subss xmm0, xmm3
// 005fcf12  0f28d3               movaps xmm2, xmm3
// 005fcf15  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005fcf1c  f30f5ccb             subss xmm1, xmm3
// 005fcf20  52                   push edx
// 005fcf21  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005fcf2a  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005fcf33  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005fcf3c  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005fcf45  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005fcf4e  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005fcf57  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005fcf60  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005fcf69  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005fcf72  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005fcf7b  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005fcf84  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005fcf8d  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005fcf96  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005fcf9f  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005fcfa8  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005fcfb1  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005fcfba  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005fcfc3  e878a62200           call 0x827640
// 005fcfc8  8d442474             lea eax, [esp + 0x74]
// 005fcfcc  50                   push eax
// 005fcfcd  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005fcfd4  51                   push ecx
// 005fcfd5  e866a62200           call 0x827640
// 005fcfda  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005fcfe2  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005fcfe8  0f57c8               xorps xmm1, xmm0
// 005fcfeb  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005fcff4  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005fcffa  8d9424d0000000       lea edx, [esp + 0xd0]
// 005fd001  0f57c8               xorps xmm1, xmm0
// 005fd004  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fd00a  52                   push edx
// 005fd00b  8d8424ec000000       lea eax, [esp + 0xec]
// 005fd012  50                   push eax
// 005fd013  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005fd01c  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005fd025  e816a62200           call 0x827640
// 005fd02a  83c418               add esp, 0x18
// 005fd02d  8d4c2440             lea ecx, [esp + 0x40]
// 005fd031  51                   push ecx
// 005fd032  8d8c2480010000       lea ecx, [esp + 0x180]
// 005fd039  e802720300           call 0x634240
// 005fd03e  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005fd045  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005fd04b  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005fd052  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005fd059  8b7d20               mov edi, dword ptr [ebp + 0x20]
// 005fd05c  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fd065  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005fd06b  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fd074  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005fd07a  89542478             mov dword ptr [esp + 0x78], edx
// 005fd07e  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005fd085  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fd08e  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005fd094  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005fd09b  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005fd0a2  89942484000000       mov dword ptr [esp + 0x84], edx
// 005fd0a9  8b542460             mov edx, dword ptr [esp + 0x60]
// 005fd0ad  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fd0b6  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005fd0bb  8944247c             mov dword ptr [esp + 0x7c], eax
// 005fd0bf  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005fd0c6  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005fd0cd  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005fd0d1  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fd0da  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fd0e3  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005fd0ec  89942490000000       mov dword ptr [esp + 0x90], edx
// 005fd0f3  89842488000000       mov dword ptr [esp + 0x88], eax
// 005fd0fa  8b442464             mov eax, dword ptr [esp + 0x64]
// 005fd0fe  8d542478             lea edx, [esp + 0x78]
// 005fd102  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005fd109  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fd112  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005fd11b  52                   push edx
// 005fd11c  8bcf                 mov ecx, edi
// 005fd11e  89842498000000       mov dword ptr [esp + 0x98], eax
// 005fd125  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fd12e  e88dd1feff           call 0x5ea2c0
// 005fd133  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005fd13c  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005fd142  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005fd14b  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005fd151  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005fd15a  8d84248c010000       lea eax, [esp + 0x18c]
// 005fd161  50                   push eax
// 005fd162  8d4c2464             lea ecx, [esp + 0x64]
// 005fd166  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005fd16c  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005fd175  51                   push ecx
// 005fd176  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005fd17c  e8bfa42200           call 0x827640
// 005fd181  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005fd188  52                   push edx
// 005fd189  8d8424d8000000       lea eax, [esp + 0xd8]
// 005fd190  50                   push eax
// 005fd191  e8aaa42200           call 0x827640
// 005fd196  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fd19c  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005fd1a5  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fd1ab  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005fd1b2  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005fd1b9  51                   push ecx
// 005fd1ba  8d9424ec000000       lea edx, [esp + 0xec]
// 005fd1c1  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005fd1ca  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fd1d0  52                   push edx
// 005fd1d1  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005fd1da  e861a42200           call 0x827640
// 005fd1df  83c418               add esp, 0x18
// 005fd1e2  8d442440             lea eax, [esp + 0x40]
// 005fd1e6  50                   push eax
// 005fd1e7  8d8c2410010000       lea ecx, [esp + 0x110]
// 005fd1ee  e84d700300           call 0x634240
// 005fd1f3  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005fd1fa  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005fd201  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005fd208  894c2478             mov dword ptr [esp + 0x78], ecx
// 005fd20c  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005fd213  8954247c             mov dword ptr [esp + 0x7c], edx
// 005fd217  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005fd21e  89842480000000       mov dword ptr [esp + 0x80], eax
// 005fd225  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005fd22c  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005fd232  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005fd236  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005fd23d  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fd246  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005fd24c  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fd255  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005fd25b  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fd264  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005fd26a  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fd273  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005fd279  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fd282  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fd288  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005fd28f  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fd298  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fd29e  8d4c2478             lea ecx, [esp + 0x78]
// 005fd2a2  89942488000000       mov dword ptr [esp + 0x88], edx
// 005fd2a9  8b542464             mov edx, dword ptr [esp + 0x64]
// 005fd2ad  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005fd2b4  8b442468             mov eax, dword ptr [esp + 0x68]
// 005fd2b8  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fd2c1  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fd2c7  8d5f44               lea ebx, [edi + 0x44]
// 005fd2ca  51                   push ecx
// 005fd2cb  8bcb                 mov ecx, ebx
// 005fd2cd  89942498000000       mov dword ptr [esp + 0x98], edx
// 005fd2d4  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005fd2db  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fd2e4  e8d7cffeff           call 0x5ea2c0
// 005fd2e9  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005fd2f2  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005fd2f8  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005fd301  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005fd307  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005fd310  8d94248c010000       lea edx, [esp + 0x18c]
// 005fd317  52                   push edx
// 005fd318  8d442464             lea eax, [esp + 0x64]
// 005fd31c  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005fd322  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005fd32b  50                   push eax
// 005fd32c  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005fd332  e809a32200           call 0x827640
// 005fd337  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005fd33e  51                   push ecx
// 005fd33f  8d9424d8000000       lea edx, [esp + 0xd8]
// 005fd346  52                   push edx
// 005fd347  e8f4a22200           call 0x827640
// 005fd34c  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fd352  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005fd35b  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fd361  8d8424d0000000       lea eax, [esp + 0xd0]
// 005fd368  50                   push eax
// 005fd369  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005fd370  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005fd379  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fd37f  51                   push ecx
// 005fd380  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005fd389  e8b2a22200           call 0x827640
// 005fd38e  83c418               add esp, 0x18
// 005fd391  8d542440             lea edx, [esp + 0x40]
// 005fd395  52                   push edx
// 005fd396  8d8c2430010000       lea ecx, [esp + 0x130]
// 005fd39d  e89e6e0300           call 0x634240
// 005fd3a2  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005fd3a9  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005fd3b0  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005fd3b7  89442478             mov dword ptr [esp + 0x78], eax
// 005fd3bb  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005fd3c2  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005fd3c6  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005fd3cd  89942480000000       mov dword ptr [esp + 0x80], edx
// 005fd3d4  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005fd3db  89842484000000       mov dword ptr [esp + 0x84], eax
// 005fd3e2  8b442460             mov eax, dword ptr [esp + 0x60]
// 005fd3e6  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005fd3ed  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005fd3f1  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005fd3f8  8b542468             mov edx, dword ptr [esp + 0x68]
// 005fd3fc  89842490000000       mov dword ptr [esp + 0x90], eax
// 005fd403  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005fd40a  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005fd410  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fd419  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005fd41f  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fd428  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005fd42e  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fd437  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005fd43d  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fd446  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005fd44c  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fd455  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fd45b  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fd464  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fd46a  8d442478             lea eax, [esp + 0x78]
// 005fd46e  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fd477  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fd47d  8d8f88000000         lea ecx, [edi + 0x88]
// 005fd483  50                   push eax
// 005fd484  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005fd48b  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fd494  894c2460             mov dword ptr [esp + 0x60], ecx
// 005fd498  e823cefeff           call 0x5ea2c0
// 005fd49d  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005fd4a6  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005fd4ac  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005fd4b5  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005fd4bb  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005fd4c4  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005fd4cb  51                   push ecx
// 005fd4cc  8d542464             lea edx, [esp + 0x64]
// 005fd4d0  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005fd4d6  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005fd4df  52                   push edx
// 005fd4e0  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005fd4e6  e855a12200           call 0x827640
// 005fd4eb  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005fd4f2  50                   push eax
// 005fd4f3  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005fd4fa  51                   push ecx
// 005fd4fb  e840a12200           call 0x827640
// 005fd500  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fd506  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005fd50d  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005fd516  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fd51c  8d9424d0000000       lea edx, [esp + 0xd0]
// 005fd523  52                   push edx
// 005fd524  8d8424ec000000       lea eax, [esp + 0xec]
// 005fd52b  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005fd534  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fd53a  50                   push eax
// 005fd53b  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005fd544  e8f7a02200           call 0x827640
// 005fd549  83c418               add esp, 0x18
// 005fd54c  8d4c2440             lea ecx, [esp + 0x40]
// 005fd550  51                   push ecx
// 005fd551  8d8c2420010000       lea ecx, [esp + 0x120]
// 005fd558  e8e36c0300           call 0x634240
// 005fd55d  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005fd564  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005fd56b  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005fd572  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005fd578  89542478             mov dword ptr [esp + 0x78], edx
// 005fd57c  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005fd583  8944247c             mov dword ptr [esp + 0x7c], eax
// 005fd587  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005fd58e  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005fd595  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005fd59c  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fd5a5  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005fd5ab  89942484000000       mov dword ptr [esp + 0x84], edx
// 005fd5b2  8b542460             mov edx, dword ptr [esp + 0x60]
// 005fd5b6  89842488000000       mov dword ptr [esp + 0x88], eax
// 005fd5bd  8b442464             mov eax, dword ptr [esp + 0x64]
// 005fd5c1  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005fd5c8  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005fd5cc  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fd5d5  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005fd5db  89942490000000       mov dword ptr [esp + 0x90], edx
// 005fd5e2  89842494000000       mov dword ptr [esp + 0x94], eax
// 005fd5e9  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005fd5f0  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fd5f9  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005fd5ff  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fd608  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005fd60e  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fd617  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fd61d  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fd626  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fd62c  8d542478             lea edx, [esp + 0x78]
// 005fd630  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fd639  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fd63f  8d8fcc000000         lea ecx, [edi + 0xcc]
// 005fd645  52                   push edx
// 005fd646  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fd64f  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005fd656  e865ccfeff           call 0x5ea2c0
// 005fd65b  8b7518               mov esi, dword ptr [ebp + 0x18]
// 005fd65e  8b06                 mov eax, dword ptr [esi]
// 005fd660  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fd663  57                   push edi
// 005fd664  8bce                 mov ecx, esi
// 005fd666  ffd2                 call edx
// 005fd668  8bf8                 mov edi, eax
// 005fd66a  8b06                 mov eax, dword ptr [esi]
// 005fd66c  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fd66f  53                   push ebx
// 005fd670  8bce                 mov ecx, esi
// 005fd672  ffd2                 call edx
// 005fd674  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005fd678  8bd8                 mov ebx, eax
// 005fd67a  8b06                 mov eax, dword ptr [esi]
// 005fd67c  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fd67f  51                   push ecx
// 005fd680  8bce                 mov ecx, esi
// 005fd682  ffd2                 call edx
// 005fd684  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005fd68b  8944243c             mov dword ptr [esp + 0x3c], eax
// 005fd68f  8b06                 mov eax, dword ptr [esi]
// 005fd691  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fd694  51                   push ecx
// 005fd695  8bce                 mov ecx, esi
// 005fd697  ffd2                 call edx
// 005fd699  8b16                 mov edx, dword ptr [esi]
// 005fd69b  8b5218               mov edx, dword ptr [edx + 0x18]
// 005fd69e  50                   push eax
// 005fd69f  89442460             mov dword ptr [esp + 0x60], eax
// 005fd6a3  8b442440             mov eax, dword ptr [esp + 0x40]
// 005fd6a7  50                   push eax
// 005fd6a8  53                   push ebx
// 005fd6a9  57                   push edi
// 005fd6aa  8bce                 mov ecx, esi
// 005fd6ac  ffd2                 call edx
// 005fd6ae  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005fd6b1  85c0                 test eax, eax
// 005fd6b3  7413                 je 0x5fd6c8
// 005fd6b5  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005fd6b9  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005fd6bd  8938                 mov dword ptr [eax], edi
// 005fd6bf  895804               mov dword ptr [eax + 4], ebx
// 005fd6c2  894808               mov dword ptr [eax + 8], ecx
// 005fd6c5  89500c               mov dword ptr [eax + 0xc], edx
// 005fd6c8  5f                   pop edi
// 005fd6c9  5e                   pop esi
// 005fd6ca  5b                   pop ebx
// 005fd6cb  8be5                 mov esp, ebp
// 005fd6cd  5d                   pop ebp
// 005fd6ce  c22000               ret 0x20
// 005fd6d1  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005fd6d8  743c                 je 0x5fd716
// 005fd6da  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005fd6de  7536                 jne 0x5fd716
// 005fd6e0  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005fd6e5  85c0                 test eax, eax
// 005fd6e7  7418                 je 0x5fd701
// 005fd6e9  6801010000           push 0x101
// 005fd6ee  688027b800           push 0xb82780
// 005fd6f3  680027b800           push 0xb82700
// 005fd6f8  ffd0                 call eax
// 005fd6fa  83c40c               add esp, 0xc
// 005fd6fd  84c0                 test al, al
// 005fd6ff  7515                 jne 0x5fd716
// 005fd701  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005fd708  688826b800           push 0xb82688
// 005fd70d  50                   push eax
// 005fd70e  e87d4b3700           call 0x972290
// 005fd713  83c408               add esp, 8
// 005fd716  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005fd71c  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005fd723  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005fd72b  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005fd733  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005fd738  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005fd73e  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005fd746  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005fd74b  8d4c2460             lea ecx, [esp + 0x60]
// 005fd74f  51                   push ecx
// 005fd750  f30f59c2             mulss xmm0, xmm2
// 005fd754  f30f59ca             mulss xmm1, xmm2
// 005fd758  8d4c2420             lea ecx, [esp + 0x20]
// 005fd75c  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005fd765  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005fd76e  e8cd6a0300           call 0x634240
// 005fd773  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005fd77c  f30f5e00             divss xmm0, dword ptr [eax]
// 005fd780  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005fd785  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005fd788  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005fd78b  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005fd790  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005fd798  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005fd79e  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005fd7a7  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005fd7b0  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005fd7b5  33d2                 xor edx, edx
// 005fd7b7  33db                 xor ebx, ebx
// 005fd7b9  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005fd7c2  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005fd7c9  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005fd7d0  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005fd7d6  0f2fd7               comiss xmm2, xmm7
// 005fd7d9  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005fd7df  8954243c             mov dword ptr [esp + 0x3c], edx
// 005fd7e3  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005fd7ec  770a                 ja 0x5fd7f8
// 005fd7ee  85d2                 test edx, edx
// 005fd7f0  0f85d2feffff         jne 0x5fd6c8
// 005fd7f6  eb04                 jmp 0x5fd7fc
// 005fd7f8  85d2                 test edx, edx
// 005fd7fa  7504                 jne 0x5fd800
// 005fd7fc  f30f5cc4             subss xmm0, xmm4
// 005fd800  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005fd804  80797000             cmp byte ptr [ecx + 0x70], 0
// 005fd808  7421                 je 0x5fd82b
// 005fd80a  f30f58c7             addss xmm0, xmm7
// 005fd80e  0f2fc2               comiss xmm0, xmm2
// 005fd811  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005fd81a  8d44241c             lea eax, [esp + 0x1c]
// 005fd81e  7707                 ja 0x5fd827
// 005fd820  8d84240c030000       lea eax, [esp + 0x30c]
// 005fd827  f30f1010             movss xmm2, dword ptr [eax]
// 005fd82b  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005fd834  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005fd83a  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005fd841  f30f58cb             addss xmm1, xmm3
// 005fd845  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005fd84a  33c0                 xor eax, eax
// 005fd84c  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005fd852  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005fd85b  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005fd862  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005fd868  0f2ff0               comiss xmm6, xmm0
// 005fd86b  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005fd874  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005fd87a  7708                 ja 0x5fd884
// 005fd87c  85c0                 test eax, eax
// 005fd87e  0f852b110000         jne 0x5fe9af
// 005fd884  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005fd88a  85c0                 test eax, eax
// 005fd88c  7504                 jne 0x5fd892
// 005fd88e  f30f5ccc             subss xmm1, xmm4
// 005fd892  0f28f1               movaps xmm6, xmm1
// 005fd895  f30f58f0             addss xmm6, xmm0
// 005fd899  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005fd89e  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005fd8a7  8d442420             lea eax, [esp + 0x20]
// 005fd8ab  7707                 ja 0x5fd8b4
// 005fd8ad  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005fd8b4  80797000             cmp byte ptr [ecx + 0x70], 0
// 005fd8b8  f30f1000             movss xmm0, dword ptr [eax]
// 005fd8bc  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005fd8c2  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005fd8cb  f30f58c3             addss xmm0, xmm3
// 005fd8cf  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005fd8d8  0f57c0               xorps xmm0, xmm0
// 005fd8db  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005fd8e1  740f                 je 0x5fd8f2
// 005fd8e3  e8a8c9feff           call 0x5ea290
// 005fd8e8  d80d94deb600         fmul dword ptr [0xb6de94]
// 005fd8ee  d95c2440             fstp dword ptr [esp + 0x40]
// 005fd8f2  0f28dd               movaps xmm3, xmm5
// 005fd8f5  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005fd8fe  0f28c3               movaps xmm0, xmm3
// 005fd901  f30f59c4             mulss xmm0, xmm4
// 005fd905  f30f5cd7             subss xmm2, xmm7
// 005fd909  f30f59d3             mulss xmm2, xmm3
// 005fd90d  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005fd913  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005fd919  f30f58d3             addss xmm2, xmm3
// 005fd91d  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005fd923  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005fd929  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005fd92f  0f28c5               movaps xmm0, xmm5
// 005fd932  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005fd93b  0f28e9               movaps xmm5, xmm1
// 005fd93e  0f28f0               movaps xmm6, xmm0
// 005fd941  f30f59f4             mulss xmm6, xmm4
// 005fd945  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005fd94b  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005fd951  f30f5ccb             subss xmm1, xmm3
// 005fd955  f30f59e8             mulss xmm5, xmm0
// 005fd959  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005fd95f  f30f59c8             mulss xmm1, xmm0
// 005fd963  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005fd969  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005fd972  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005fd97b  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005fd984  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005fd98d  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005fd996  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005fd99f  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005fd9a8  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005fd9b1  85d2                 test edx, edx
// 005fd9b3  753f                 jne 0x5fd9f4
// 005fd9b5  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005fd9bb  0f28c4               movaps xmm0, xmm4
// 005fd9be  f30f58c3             addss xmm0, xmm3
// 005fd9c2  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005fd9cb  0f28c3               movaps xmm0, xmm3
// 005fd9ce  f30f58c2             addss xmm0, xmm2
// 005fd9d2  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005fd9db  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005fd9e4  0f28c4               movaps xmm0, xmm4
// 005fd9e7  f30f58c3             addss xmm0, xmm3
// 005fd9eb  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005fd9f4  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005fd9fa  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005fd9ff  772f                 ja 0x5fda30
// 005fda01  0f28c6               movaps xmm0, xmm6
// 005fda04  f30f58c5             addss xmm0, xmm5
// 005fda08  f30f58f1             addss xmm6, xmm1
// 005fda0c  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005fda15  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005fda1e  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005fda27  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005fda30  8d9424cc000000       lea edx, [esp + 0xcc]
// 005fda37  52                   push edx
// 005fda38  8d8c2444010000       lea ecx, [esp + 0x144]
// 005fda3f  e8fc670300           call 0x634240
// 005fda44  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005fda49  f30f1008             movss xmm1, dword ptr [eax]
// 005fda4d  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005fda53  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005fda59  8d8424d8000000       lea eax, [esp + 0xd8]
// 005fda60  50                   push eax
// 005fda61  8d8c2444010000       lea ecx, [esp + 0x144]
// 005fda68  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005fda71  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005fda7a  e8c1670300           call 0x634240
// 005fda7f  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005fda84  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005fda8a  f30f5808             addss xmm1, dword ptr [eax]
// 005fda8e  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005fda94  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005fda9b  51                   push ecx
// 005fda9c  8d8c2444010000       lea ecx, [esp + 0x144]
// 005fdaa3  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005fdaac  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005fdab5  e886670300           call 0x634240
// 005fdaba  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005fdac0  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005fdac5  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005fdacb  f30f5c08             subss xmm1, dword ptr [eax]
// 005fdacf  8d94248c010000       lea edx, [esp + 0x18c]
// 005fdad6  52                   push edx
// 005fdad7  8d8c2444010000       lea ecx, [esp + 0x144]
// 005fdade  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005fdae7  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005fdaf0  e84b670300           call 0x634240
// 005fdaf5  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005fdafb  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005fdb00  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005fdb06  f30f5c08             subss xmm1, dword ptr [eax]
// 005fdb0a  8d842498010000       lea eax, [esp + 0x198]
// 005fdb11  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005fdb1a  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fdb22  50                   push eax
// 005fdb23  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005fdb2a  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005fdb30  0f57c0               xorps xmm0, xmm0
// 005fdb33  51                   push ecx
// 005fdb34  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005fdb3b  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005fdb44  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005fdb4a  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005fdb50  e8bb660300           call 0x634210
// 005fdb55  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005fdb5e  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005fdb67  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005fdb70  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005fdb79  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005fdb82  8d9424ec000000       lea edx, [esp + 0xec]
// 005fdb89  52                   push edx
// 005fdb8a  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005fdb91  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005fdb9a  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005fdba3  50                   push eax
// 005fdba4  8d8c2484010000       lea ecx, [esp + 0x184]
// 005fdbab  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005fdbb4  e857660300           call 0x634210
// 005fdbb9  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005fdbc2  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005fdbc8  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005fdbd1  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005fdbd7  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005fdbe0  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005fdbe6  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005fdbef  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005fdbf5  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005fdbfe  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005fdc07  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005fdc10  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005fdc19  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005fdc22  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005fdc2b  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005fdc34  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005fdc3d  8d4c246c             lea ecx, [esp + 0x6c]
// 005fdc41  51                   push ecx
// 005fdc42  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005fdc49  52                   push edx
// 005fdc4a  e8f1992200           call 0x827640
// 005fdc4f  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005fdc58  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005fdc61  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005fdc6a  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005fdc71  50                   push eax
// 005fdc72  8d8c2484030000       lea ecx, [esp + 0x384]
// 005fdc79  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005fdc82  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fdc8a  51                   push ecx
// 005fdc8b  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005fdc94  e8a7992200           call 0x827640
// 005fdc99  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005fdc9f  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005fdca8  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005fdcae  8d942470030000       lea edx, [esp + 0x370]
// 005fdcb5  52                   push edx
// 005fdcb6  8d842450030000       lea eax, [esp + 0x350]
// 005fdcbd  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005fdcc6  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fdccc  50                   push eax
// 005fdccd  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005fdcd6  e865992200           call 0x827640
// 005fdcdb  83c418               add esp, 0x18
// 005fdcde  8d8c2430030000       lea ecx, [esp + 0x330]
// 005fdce5  51                   push ecx
// 005fdce6  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005fdced  e84e650300           call 0x634240
// 005fdcf2  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005fdcfb  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005fdd02  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005fdd09  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005fdd10  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005fdd19  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005fdd22  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005fdd2b  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005fdd34  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005fdd3d  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005fdd46  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005fdd4f  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005fdd58  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005fdd61  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005fdd6a  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005fdd73  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005fdd7c  89942448020000       mov dword ptr [esp + 0x248], edx
// 005fdd83  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005fdd8a  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005fdd93  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005fdd9c  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005fdda3  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005fddaa  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005fddb3  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005fddbc  89942454020000       mov dword ptr [esp + 0x254], edx
// 005fddc3  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005fddca  89842458020000       mov dword ptr [esp + 0x258], eax
// 005fddd1  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005fddd8  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005fdde1  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005fddea  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005fddf1  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005fddf8  89942460020000       mov dword ptr [esp + 0x260], edx
// 005fddff  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005fde08  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005fde11  8d54246c             lea edx, [esp + 0x6c]
// 005fde15  89842464020000       mov dword ptr [esp + 0x264], eax
// 005fde1c  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005fde23  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005fde2a  52                   push edx
// 005fde2b  8d842470030000       lea eax, [esp + 0x370]
// 005fde32  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005fde3b  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005fde44  50                   push eax
// 005fde45  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005fde4c  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005fde55  e8e6972200           call 0x827640
// 005fde5a  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005fde63  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005fde6c  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005fde75  8d8c2498030000       lea ecx, [esp + 0x398]
// 005fde7c  51                   push ecx
// 005fde7d  8d942460030000       lea edx, [esp + 0x360]
// 005fde84  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005fde8d  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fde95  52                   push edx
// 005fde96  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005fde9f  e89c972200           call 0x827640
// 005fdea4  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005fdeaa  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005fdeb3  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005fdeb9  8d842400040000       lea eax, [esp + 0x400]
// 005fdec0  50                   push eax
// 005fdec1  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005fdec8  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005fded1  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fded7  51                   push ecx
// 005fded8  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005fdee1  e85a972200           call 0x827640
// 005fdee6  83c418               add esp, 0x18
// 005fdee9  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005fdef0  52                   push edx
// 005fdef1  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005fdef8  e843630300           call 0x634240
// 005fdefd  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005fdf06  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005fdf0d  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005fdf14  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005fdf1b  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005fdf24  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005fdf2d  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005fdf36  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005fdf3f  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005fdf48  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005fdf51  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005fdf5a  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005fdf63  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005fdf6c  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005fdf75  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005fdf7e  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005fdf87  89842490020000       mov dword ptr [esp + 0x290], eax
// 005fdf8e  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005fdf95  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005fdf9e  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005fdfa7  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005fdfae  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005fdfb5  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005fdfbe  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005fdfc7  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005fdfce  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005fdfd5  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005fdfdc  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005fdfe3  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005fdfec  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005fdff5  89942498020000       mov dword ptr [esp + 0x298], edx
// 005fdffc  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005fe003  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005fe00a  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005fe013  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005fe01c  8d44246c             lea eax, [esp + 0x6c]
// 005fe020  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005fe027  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005fe02e  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005fe035  50                   push eax
// 005fe036  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005fe03d  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005fe046  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005fe04f  51                   push ecx
// 005fe050  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005fe057  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005fe060  e8db952200           call 0x827640
// 005fe065  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005fe06e  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005fe077  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005fe080  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005fe089  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fe091  8d94248c030000       lea edx, [esp + 0x38c]
// 005fe098  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005fe0a1  52                   push edx
// 005fe0a2  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005fe0a9  50                   push eax
// 005fe0aa  e891952200           call 0x827640
// 005fe0af  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005fe0b5  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005fe0be  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005fe0c4  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005fe0cb  51                   push ecx
// 005fe0cc  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005fe0d3  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005fe0dc  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fe0e2  52                   push edx
// 005fe0e3  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005fe0ec  e84f952200           call 0x827640
// 005fe0f1  83c418               add esp, 0x18
// 005fe0f4  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005fe0fb  50                   push eax
// 005fe0fc  8d8c2480010000       lea ecx, [esp + 0x180]
// 005fe103  e838610300           call 0x634240
// 005fe108  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005fe111  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005fe118  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005fe11f  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005fe126  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005fe12f  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005fe138  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005fe141  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005fe14a  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005fe153  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005fe15c  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005fe165  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005fe16e  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005fe177  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005fe180  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005fe189  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 005fe192  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 005fe199  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 005fe1a0  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 005fe1a9  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 005fe1b2  89942404020000       mov dword ptr [esp + 0x204], edx
// 005fe1b9  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 005fe1c0  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 005fe1c9  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005fe1cf  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 005fe1d6  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 005fe1dd  89942410020000       mov dword ptr [esp + 0x210], edx
// 005fe1e4  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 005fe1eb  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 005fe1f4  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fe1fa  89842408020000       mov dword ptr [esp + 0x208], eax
// 005fe201  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 005fe208  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 005fe20f  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005fe218  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fe21e  8d4c246c             lea ecx, [esp + 0x6c]
// 005fe222  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 005fe229  89842414020000       mov dword ptr [esp + 0x214], eax
// 005fe230  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 005fe237  51                   push ecx
// 005fe238  8d942410010000       lea edx, [esp + 0x110]
// 005fe23f  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 005fe248  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fe24e  52                   push edx
// 005fe24f  89842428020000       mov dword ptr [esp + 0x228], eax
// 005fe256  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005fe25f  e8dc932200           call 0x827640
// 005fe264  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005fe26d  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 005fe276  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005fe27f  8d842404040000       lea eax, [esp + 0x404]
// 005fe286  50                   push eax
// 005fe287  8d8c2438010000       lea ecx, [esp + 0x138]
// 005fe28e  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 005fe297  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fe29f  51                   push ecx
// 005fe2a0  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 005fe2a9  e892932200           call 0x827640
// 005fe2ae  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005fe2b4  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 005fe2bd  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005fe2c3  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005fe2cc  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fe2d2  8d9424b8030000       lea edx, [esp + 0x3b8]
// 005fe2d9  52                   push edx
// 005fe2da  8d842430010000       lea eax, [esp + 0x130]
// 005fe2e1  50                   push eax
// 005fe2e2  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 005fe2eb  e850932200           call 0x827640
// 005fe2f0  83c418               add esp, 0x18
// 005fe2f3  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 005fe2fa  51                   push ecx
// 005fe2fb  8d4c242c             lea ecx, [esp + 0x2c]
// 005fe2ff  e83c5f0300           call 0x634240
// 005fe304  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 005fe30d  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 005fe314  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 005fe31b  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 005fe322  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fe32b  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 005fe334  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fe33d  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 005fe346  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fe34f  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 005fe358  89542478             mov dword ptr [esp + 0x78], edx
// 005fe35c  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 005fe363  8944247c             mov dword ptr [esp + 0x7c], eax
// 005fe367  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005fe36e  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fe377  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 005fe380  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005fe387  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 005fe38e  89942484000000       mov dword ptr [esp + 0x84], edx
// 005fe395  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 005fe39c  89842488000000       mov dword ptr [esp + 0x88], eax
// 005fe3a3  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 005fe3aa  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fe3b3  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 005fe3bc  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005fe3c3  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 005fe3ca  89942490000000       mov dword ptr [esp + 0x90], edx
// 005fe3d1  8b17                 mov edx, dword ptr [edi]
// 005fe3d3  8b5210               mov edx, dword ptr [edx + 0x10]
// 005fe3d6  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fe3df  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 005fe3e8  89842494000000       mov dword ptr [esp + 0x94], eax
// 005fe3ef  8d842448020000       lea eax, [esp + 0x248]
// 005fe3f6  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005fe3fd  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fe406  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 005fe40f  50                   push eax
// 005fe410  8bcf                 mov ecx, edi
// 005fe412  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fe41b  ffd2                 call edx
// 005fe41d  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 005fe424  8b07                 mov eax, dword ptr [edi]
// 005fe426  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fe429  8d8c2490020000       lea ecx, [esp + 0x290]
// 005fe430  51                   push ecx
// 005fe431  8bcf                 mov ecx, edi
// 005fe433  ffd2                 call edx
// 005fe435  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 005fe43c  8b07                 mov eax, dword ptr [edi]
// 005fe43e  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fe441  8d8c2400020000       lea ecx, [esp + 0x200]
// 005fe448  51                   push ecx
// 005fe449  8bcf                 mov ecx, edi
// 005fe44b  ffd2                 call edx
// 005fe44d  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 005fe454  8b07                 mov eax, dword ptr [edi]
// 005fe456  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fe459  8d4c2478             lea ecx, [esp + 0x78]
// 005fe45d  51                   push ecx
// 005fe45e  8bcf                 mov ecx, edi
// 005fe460  ffd2                 call edx
// 005fe462  89842460010000       mov dword ptr [esp + 0x160], eax
// 005fe469  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005fe470  40                   inc eax
// 005fe471  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005fe478  3bc3                 cmp eax, ebx
// 005fe47a  8d84246c010000       lea eax, [esp + 0x16c]
// 005fe481  7c07                 jl 0x5fe48a
// 005fe483  8d8424e8000000       lea eax, [esp + 0xe8]
// 005fe48a  8b18                 mov ebx, dword ptr [eax]
// 005fe48c  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 005fe493  8bc8                 mov ecx, eax
// 005fe495  40                   inc eax
// 005fe496  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005fe49d  85c9                 test ecx, ecx
// 005fe49f  0f85f9000000         jne 0x5fe59e
// 005fe4a5  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 005fe4ac  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005fe4af  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 005fe4b8  8911                 mov dword ptr [ecx], edx
// 005fe4ba  f30f1106             movss dword ptr [esi], xmm0
// 005fe4be  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 005fe4c7  f30f114604           movss dword ptr [esi + 4], xmm0
// 005fe4cc  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 005fe4d5  f30f114608           movss dword ptr [esi + 8], xmm0
// 005fe4da  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 005fe4e3  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 005fe4e8  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 005fe4f1  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 005fe4f6  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 005fe4ff  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 005fe504  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 005fe50d  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 005fe512  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 005fe51b  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 005fe520  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 005fe529  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 005fe52e  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 005fe537  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 005fe53c  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 005fe545  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 005fe54a  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 005fe553  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 005fe558  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 005fe561  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 005fe566  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 005fe56f  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 005fe574  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 005fe57d  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 005fe582  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 005fe58b  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 005fe590  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 005fe599  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 005fe59e  8bd3                 mov edx, ebx
// 005fe5a0  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 005fe5a5  8d0c9501000000       lea ecx, [edx*4 + 1]
// 005fe5ac  8bd0                 mov edx, eax
// 005fe5ae  40                   inc eax
// 005fe5af  3bd1                 cmp edx, ecx
// 005fe5b1  0f8501010000         jne 0x5fe6b8
// 005fe5b7  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005fe5be  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005fe5c1  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 005fe5ca  894a04               mov dword ptr [edx + 4], ecx
// 005fe5cd  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 005fe5d2  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 005fe5db  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 005fe5e0  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 005fe5e9  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 005fe5ee  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 005fe5f7  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 005fe5fc  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 005fe605  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 005fe60a  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 005fe613  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 005fe618  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 005fe621  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 005fe626  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 005fe62f  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 005fe634  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 005fe63d  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 005fe642  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 005fe64b  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 005fe650  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 005fe659  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 005fe65e  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 005fe667  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 005fe66c  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 005fe675  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 005fe67a  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 005fe683  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 005fe688  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 005fe691  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 005fe696  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 005fe69f  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 005fe6a7  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 005fe6b0  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 005fe6b8  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005fe6bc  41                   inc ecx
// 005fe6bd  0fafcb               imul ecx, ebx
// 005fe6c0  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 005fe6c7  8bc8                 mov ecx, eax
// 005fe6c9  40                   inc eax
// 005fe6ca  3bca                 cmp ecx, edx
// 005fe6cc  0f852e010000         jne 0x5fe800
// 005fe6d2  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 005fe6d9  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005fe6dc  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005fe6e5  895108               mov dword ptr [ecx + 8], edx
// 005fe6e8  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 005fe6f0  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 005fe6f9  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 005fe701  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 005fe70a  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 005fe712  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 005fe71b  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 005fe723  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 005fe72c  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 005fe734  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 005fe73d  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 005fe745  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 005fe74e  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 005fe756  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 005fe75f  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 005fe767  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 005fe770  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 005fe778  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 005fe781  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 005fe789  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 005fe792  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 005fe79a  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 005fe7a3  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 005fe7ab  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 005fe7b4  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 005fe7bc  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 005fe7c5  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 005fe7cd  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 005fe7d6  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 005fe7de  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 005fe7e7  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 005fe7ef  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 005fe7f8  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 005fe800  8bc8                 mov ecx, eax
// 005fe802  8d149dffffffff       lea edx, [ebx*4 - 1]
// 005fe809  40                   inc eax
// 005fe80a  89842478010000       mov dword ptr [esp + 0x178], eax
// 005fe811  3bca                 cmp ecx, edx
// 005fe813  0f8528010000         jne 0x5fe941
// 005fe819  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005fe81c  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005fe823  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 005fe829  89420c               mov dword ptr [edx + 0xc], eax
// 005fe82c  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 005fe834  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 005fe83a  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 005fe842  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 005fe84b  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 005fe853  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 005fe85c  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 005fe864  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 005fe86d  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 005fe875  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 005fe87e  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 005fe886  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 005fe88f  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 005fe897  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 005fe8a0  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 005fe8a8  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 005fe8b1  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 005fe8b9  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 005fe8c2  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 005fe8ca  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 005fe8d3  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 005fe8db  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 005fe8e4  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 005fe8ec  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 005fe8f5  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 005fe8fd  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 005fe906  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 005fe90e  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 005fe917  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 005fe91f  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 005fe928  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 005fe930  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 005fe939  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 005fe941  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005fe948  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005fe94f  8b17                 mov edx, dword ptr [edi]
// 005fe951  8b5218               mov edx, dword ptr [edx + 0x18]
// 005fe954  50                   push eax
// 005fe955  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 005fe95c  51                   push ecx
// 005fe95d  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 005fe964  50                   push eax
// 005fe965  51                   push ecx
// 005fe966  8bcf                 mov ecx, edi
// 005fe968  ffd2                 call edx
// 005fe96a  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005fe970  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 005fe979  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005fe981  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 005fe98a  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 005fe990  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005fe996  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005fe99b  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005fe9a2  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005fe9a6  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005fe9aa  e9b3eeffff           jmp 0x5fd862
// 005fe9af  0f28fa               movaps xmm7, xmm2
// 005fe9b2  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 005fe9b8  0f28d9               movaps xmm3, xmm1
// 005fe9bb  42                   inc edx
// 005fe9bc  e90feeffff           jmp 0x5fd7d0
// 005fe9c1  8d4900               lea ecx, [ecx]
// 005fe9c4  71cc                 jno 0x5fe992
// 005fe9c6  5f                   pop edi
// 005fe9c7  00dc                 add ah, bl
// 005fe9c9  cd5f                 int 0x5f
// 005fe9cb  00c8                 add al, cl
// 005fe9cd  cc                   int3 
// 005fe9ce  5f                   pop edi
// 005fe9cf  008ecd5f0006         add byte ptr [esi + 0x6005fcd], cl
// 005fe9d5  cd5f                 int 0x5f
// 005fe9d7  004acd               add byte ptr [edx - 0x33], cl
// 005fe9da  5f                   pop edi

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
