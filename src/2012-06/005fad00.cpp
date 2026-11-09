// from server: 11% by intel
// roc 2012-06 005fad00  unit: seg_005f0000  size: 7788 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005fad00
//
// 005fad00  55                   push ebp
// 005fad01  8bec                 mov ebp, esp
// 005fad03  83e4f8               and esp, 0xfffffff8
// 005fad06  81ecfc030000         sub esp, 0x3fc
// 005fad0c  53                   push ebx
// 005fad0d  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005fad10  56                   push esi
// 005fad11  57                   push edi
// 005fad12  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005fad15  8d44246c             lea eax, [esp + 0x6c]
// 005fad19  8bf1                 mov esi, ecx
// 005fad1b  53                   push ebx
// 005fad1c  c1ef06               shr edi, 6
// 005fad1f  50                   push eax
// 005fad20  89742464             mov dword ptr [esp + 0x64], esi
// 005fad24  83e707               and edi, 7
// 005fad27  e8f4c82200           call 0x827620
// 005fad2c  d9442474             fld dword ptr [esp + 0x74]
// 005fad30  d9e1                 fabs 
// 005fad32  8d4c2474             lea ecx, [esp + 0x74]
// 005fad36  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005fad3d  53                   push ebx
// 005fad3e  d944247c             fld dword ptr [esp + 0x7c]
// 005fad42  51                   push ecx
// 005fad43  d9e1                 fabs 
// 005fad45  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005fad4c  d9842484000000       fld dword ptr [esp + 0x84]
// 005fad53  d9e1                 fabs 
// 005fad55  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005fad5c  e8bfc82200           call 0x827620
// 005fad61  d944247c             fld dword ptr [esp + 0x7c]
// 005fad65  8a4670               mov al, byte ptr [esi + 0x70]
// 005fad68  d9e1                 fabs 
// 005fad6a  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005fad72  d9842480000000       fld dword ptr [esp + 0x80]
// 005fad79  83c410               add esp, 0x10
// 005fad7c  d9e1                 fabs 
// 005fad7e  d9442474             fld dword ptr [esp + 0x74]
// 005fad82  d9e1                 fabs 
// 005fad84  d9450c               fld dword ptr [ebp + 0xc]
// 005fad87  dceb                 fsub st(3), st(0)
// 005fad89  d9cb                 fxch st(3)
// 005fad8b  d95c241c             fstp dword ptr [esp + 0x1c]
// 005fad8f  d9c9                 fxch st(1)
// 005fad91  dee2                 fsubrp st(2)
// 005fad93  d9c9                 fxch st(1)
// 005fad95  d95c2420             fstp dword ptr [esp + 0x20]
// 005fad99  d95c2424             fstp dword ptr [esp + 0x24]
// 005fad9d  84c0                 test al, al
// 005fad9f  741b                 je 0x5fadbc
// 005fada1  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005fada9  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005fadb2  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005fadba  eb11                 jmp 0x5fadcd
// 005fadbc  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005fadc4  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005fadcd  0f57e4               xorps xmm4, xmm4
// 005fadd0  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005fadd9  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005faddf  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005fade5  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005fadeb  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005fadf1  83ff05               cmp edi, 5
// 005fadf4  0f87a4010000         ja 0x5faf9e
// 005fadfa  ff24bd54cb5f00       jmp dword ptr [edi*4 + 0x5fcb54]
// 005fae01  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005fae09  8d542460             lea edx, [esp + 0x60]
// 005fae0d  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005fae13  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005fae1b  52                   push edx
// 005fae1c  8d4c2420             lea ecx, [esp + 0x20]
// 005fae20  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005fae26  e815940300           call 0x634240
// 005fae2b  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005fae33  f30f1000             movss xmm0, dword ptr [eax]
// 005fae37  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005fae3c  0f57e4               xorps xmm4, xmm4
// 005fae3f  f30f59c5             mulss xmm0, xmm5
// 005fae43  f30f59cd             mulss xmm1, xmm5
// 005fae47  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005fae4d  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005fae53  e946010000           jmp 0x5faf9e
// 005fae58  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005fae60  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005fae66  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005fae6c  84c0                 test al, al
// 005fae6e  7413                 je 0x5fae83
// 005fae70  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005fae78  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005fae7e  e91b010000           jmp 0x5faf9e
// 005fae83  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005fae8b  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005fae91  e908010000           jmp 0x5faf9e
// 005fae96  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005fae9c  84c0                 test al, al
// 005fae9e  7419                 je 0x5faeb9
// 005faea0  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005faea8  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005faeae  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005faeb4  e9e5000000           jmp 0x5faf9e
// 005faeb9  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005faec1  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005faec7  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005faecf  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005faed5  e9c4000000           jmp 0x5faf9e
// 005faeda  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005faee0  84c0                 test al, al
// 005faee2  7419                 je 0x5faefd
// 005faee4  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005faeec  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005faef2  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005faef8  e9a1000000           jmp 0x5faf9e
// 005faefd  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005faf05  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005faf0b  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005faf13  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005faf19  e980000000           jmp 0x5faf9e
// 005faf1e  84c0                 test al, al
// 005faf20  745a                 je 0x5faf7c
// 005faf22  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005faf29  7441                 je 0x5faf6c
// 005faf2b  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005faf30  85c0                 test eax, eax
// 005faf32  7418                 je 0x5faf4c
// 005faf34  68b7000000           push 0xb7
// 005faf39  688027b800           push 0xb82780
// 005faf3e  68cc60b400           push 0xb460cc
// 005faf43  ffd0                 call eax
// 005faf45  83c40c               add esp, 0xc
// 005faf48  84c0                 test al, al
// 005faf4a  7515                 jne 0x5faf61
// 005faf4c  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005faf53  680827b800           push 0xb82708
// 005faf58  50                   push eax
// 005faf59  e832733700           call 0x972290
// 005faf5e  83c408               add esp, 8
// 005faf61  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005faf69  0f57e4               xorps xmm4, xmm4
// 005faf6c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005faf74  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005faf7a  eb1c                 jmp 0x5faf98
// 005faf7c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005faf84  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005faf8a  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005faf92  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005faf98  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005faf9e  807e7000             cmp byte ptr [esi + 0x70], 0
// 005fafa2  7419                 je 0x5fafbd
// 005fafa4  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005fafa9  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005fafb1  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005fafb7  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005fafbd  85ff                 test edi, edi
// 005fafbf  0f859c080000         jne 0x5fb861
// 005fafc5  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fafcd  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005fafd2  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005fafda  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005fafdf  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005fafe5  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005fafee  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005faff6  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005faffc  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005fb005  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005fb00e  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005fb017  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005fb020  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005fb029  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005fb032  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005fb03b  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005fb044  f30f59c5             mulss xmm0, xmm5
// 005fb048  f30f59cd             mulss xmm1, xmm5
// 005fb04c  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005fb055  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005fb05e  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005fb063  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005fb06c  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005fb075  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005fb07c  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005fb082  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005fb08b  0f28e3               movaps xmm4, xmm3
// 005fb08e  f30f5ce0             subss xmm4, xmm0
// 005fb092  0f28eb               movaps xmm5, xmm3
// 005fb095  f30f5ce9             subss xmm5, xmm1
// 005fb099  51                   push ecx
// 005fb09a  8d542464             lea edx, [esp + 0x64]
// 005fb09e  f30f5cc3             subss xmm0, xmm3
// 005fb0a2  0f28d3               movaps xmm2, xmm3
// 005fb0a5  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005fb0ac  f30f5ccb             subss xmm1, xmm3
// 005fb0b0  52                   push edx
// 005fb0b1  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005fb0ba  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005fb0c3  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005fb0cc  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005fb0d5  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005fb0de  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005fb0e7  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005fb0f0  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005fb0f9  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005fb102  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005fb10b  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005fb114  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005fb11d  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005fb126  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005fb12f  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005fb138  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005fb141  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005fb14a  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005fb153  e8c8c42200           call 0x827620
// 005fb158  8d442474             lea eax, [esp + 0x74]
// 005fb15c  50                   push eax
// 005fb15d  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005fb164  51                   push ecx
// 005fb165  e8b6c42200           call 0x827620
// 005fb16a  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005fb172  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005fb178  0f57c8               xorps xmm1, xmm0
// 005fb17b  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005fb184  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005fb18a  8d9424d0000000       lea edx, [esp + 0xd0]
// 005fb191  0f57c8               xorps xmm1, xmm0
// 005fb194  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fb19a  52                   push edx
// 005fb19b  8d8424ec000000       lea eax, [esp + 0xec]
// 005fb1a2  50                   push eax
// 005fb1a3  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005fb1ac  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005fb1b5  e866c42200           call 0x827620
// 005fb1ba  83c418               add esp, 0x18
// 005fb1bd  8d4c2440             lea ecx, [esp + 0x40]
// 005fb1c1  51                   push ecx
// 005fb1c2  8d8c2480010000       lea ecx, [esp + 0x180]
// 005fb1c9  e872900300           call 0x634240
// 005fb1ce  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005fb1d5  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005fb1db  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005fb1e2  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005fb1e9  8b7d20               mov edi, dword ptr [ebp + 0x20]
// 005fb1ec  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fb1f5  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005fb1fb  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fb204  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005fb20a  89542478             mov dword ptr [esp + 0x78], edx
// 005fb20e  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005fb215  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fb21e  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005fb224  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005fb22b  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005fb232  89942484000000       mov dword ptr [esp + 0x84], edx
// 005fb239  8b542460             mov edx, dword ptr [esp + 0x60]
// 005fb23d  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fb246  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005fb24b  8944247c             mov dword ptr [esp + 0x7c], eax
// 005fb24f  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005fb256  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005fb25d  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005fb261  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fb26a  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fb273  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005fb27c  89942490000000       mov dword ptr [esp + 0x90], edx
// 005fb283  89842488000000       mov dword ptr [esp + 0x88], eax
// 005fb28a  8b442464             mov eax, dword ptr [esp + 0x64]
// 005fb28e  8d542478             lea edx, [esp + 0x78]
// 005fb292  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005fb299  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fb2a2  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005fb2ab  52                   push edx
// 005fb2ac  8bcf                 mov ecx, edi
// 005fb2ae  89842498000000       mov dword ptr [esp + 0x98], eax
// 005fb2b5  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fb2be  e8fdeffeff           call 0x5ea2c0
// 005fb2c3  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005fb2cc  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005fb2d2  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005fb2db  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005fb2e1  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005fb2ea  8d84248c010000       lea eax, [esp + 0x18c]
// 005fb2f1  50                   push eax
// 005fb2f2  8d4c2464             lea ecx, [esp + 0x64]
// 005fb2f6  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005fb2fc  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005fb305  51                   push ecx
// 005fb306  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005fb30c  e80fc32200           call 0x827620
// 005fb311  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005fb318  52                   push edx
// 005fb319  8d8424d8000000       lea eax, [esp + 0xd8]
// 005fb320  50                   push eax
// 005fb321  e8fac22200           call 0x827620
// 005fb326  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fb32c  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005fb335  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fb33b  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005fb342  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005fb349  51                   push ecx
// 005fb34a  8d9424ec000000       lea edx, [esp + 0xec]
// 005fb351  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005fb35a  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fb360  52                   push edx
// 005fb361  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005fb36a  e8b1c22200           call 0x827620
// 005fb36f  83c418               add esp, 0x18
// 005fb372  8d442440             lea eax, [esp + 0x40]
// 005fb376  50                   push eax
// 005fb377  8d8c2410010000       lea ecx, [esp + 0x110]
// 005fb37e  e8bd8e0300           call 0x634240
// 005fb383  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005fb38a  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005fb391  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005fb398  894c2478             mov dword ptr [esp + 0x78], ecx
// 005fb39c  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005fb3a3  8954247c             mov dword ptr [esp + 0x7c], edx
// 005fb3a7  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005fb3ae  89842480000000       mov dword ptr [esp + 0x80], eax
// 005fb3b5  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005fb3bc  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005fb3c2  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005fb3c6  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005fb3cd  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fb3d6  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005fb3dc  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fb3e5  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005fb3eb  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fb3f4  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005fb3fa  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fb403  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005fb409  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fb412  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fb418  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005fb41f  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fb428  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fb42e  8d4c2478             lea ecx, [esp + 0x78]
// 005fb432  89942488000000       mov dword ptr [esp + 0x88], edx
// 005fb439  8b542464             mov edx, dword ptr [esp + 0x64]
// 005fb43d  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005fb444  8b442468             mov eax, dword ptr [esp + 0x68]
// 005fb448  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fb451  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fb457  8d5f44               lea ebx, [edi + 0x44]
// 005fb45a  51                   push ecx
// 005fb45b  8bcb                 mov ecx, ebx
// 005fb45d  89942498000000       mov dword ptr [esp + 0x98], edx
// 005fb464  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005fb46b  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fb474  e847eefeff           call 0x5ea2c0
// 005fb479  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005fb482  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005fb488  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005fb491  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005fb497  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005fb4a0  8d94248c010000       lea edx, [esp + 0x18c]
// 005fb4a7  52                   push edx
// 005fb4a8  8d442464             lea eax, [esp + 0x64]
// 005fb4ac  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005fb4b2  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005fb4bb  50                   push eax
// 005fb4bc  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005fb4c2  e859c12200           call 0x827620
// 005fb4c7  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005fb4ce  51                   push ecx
// 005fb4cf  8d9424d8000000       lea edx, [esp + 0xd8]
// 005fb4d6  52                   push edx
// 005fb4d7  e844c12200           call 0x827620
// 005fb4dc  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fb4e2  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005fb4eb  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fb4f1  8d8424d0000000       lea eax, [esp + 0xd0]
// 005fb4f8  50                   push eax
// 005fb4f9  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005fb500  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005fb509  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fb50f  51                   push ecx
// 005fb510  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005fb519  e802c12200           call 0x827620
// 005fb51e  83c418               add esp, 0x18
// 005fb521  8d542440             lea edx, [esp + 0x40]
// 005fb525  52                   push edx
// 005fb526  8d8c2430010000       lea ecx, [esp + 0x130]
// 005fb52d  e80e8d0300           call 0x634240
// 005fb532  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005fb539  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005fb540  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005fb547  89442478             mov dword ptr [esp + 0x78], eax
// 005fb54b  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005fb552  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005fb556  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005fb55d  89942480000000       mov dword ptr [esp + 0x80], edx
// 005fb564  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005fb56b  89842484000000       mov dword ptr [esp + 0x84], eax
// 005fb572  8b442460             mov eax, dword ptr [esp + 0x60]
// 005fb576  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005fb57d  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005fb581  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005fb588  8b542468             mov edx, dword ptr [esp + 0x68]
// 005fb58c  89842490000000       mov dword ptr [esp + 0x90], eax
// 005fb593  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005fb59a  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005fb5a0  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fb5a9  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005fb5af  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fb5b8  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005fb5be  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fb5c7  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005fb5cd  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fb5d6  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005fb5dc  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fb5e5  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fb5eb  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fb5f4  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fb5fa  8d442478             lea eax, [esp + 0x78]
// 005fb5fe  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fb607  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fb60d  8d8f88000000         lea ecx, [edi + 0x88]
// 005fb613  50                   push eax
// 005fb614  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005fb61b  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fb624  894c2460             mov dword ptr [esp + 0x60], ecx
// 005fb628  e893ecfeff           call 0x5ea2c0
// 005fb62d  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005fb636  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005fb63c  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005fb645  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005fb64b  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005fb654  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005fb65b  51                   push ecx
// 005fb65c  8d542464             lea edx, [esp + 0x64]
// 005fb660  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005fb666  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005fb66f  52                   push edx
// 005fb670  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005fb676  e8a5bf2200           call 0x827620
// 005fb67b  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005fb682  50                   push eax
// 005fb683  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005fb68a  51                   push ecx
// 005fb68b  e890bf2200           call 0x827620
// 005fb690  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fb696  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005fb69d  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005fb6a6  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fb6ac  8d9424d0000000       lea edx, [esp + 0xd0]
// 005fb6b3  52                   push edx
// 005fb6b4  8d8424ec000000       lea eax, [esp + 0xec]
// 005fb6bb  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005fb6c4  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fb6ca  50                   push eax
// 005fb6cb  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005fb6d4  e847bf2200           call 0x827620
// 005fb6d9  83c418               add esp, 0x18
// 005fb6dc  8d4c2440             lea ecx, [esp + 0x40]
// 005fb6e0  51                   push ecx
// 005fb6e1  8d8c2420010000       lea ecx, [esp + 0x120]
// 005fb6e8  e8538b0300           call 0x634240
// 005fb6ed  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005fb6f4  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005fb6fb  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005fb702  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005fb708  89542478             mov dword ptr [esp + 0x78], edx
// 005fb70c  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005fb713  8944247c             mov dword ptr [esp + 0x7c], eax
// 005fb717  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005fb71e  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005fb725  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005fb72c  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fb735  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005fb73b  89942484000000       mov dword ptr [esp + 0x84], edx
// 005fb742  8b542460             mov edx, dword ptr [esp + 0x60]
// 005fb746  89842488000000       mov dword ptr [esp + 0x88], eax
// 005fb74d  8b442464             mov eax, dword ptr [esp + 0x64]
// 005fb751  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005fb758  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005fb75c  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fb765  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005fb76b  89942490000000       mov dword ptr [esp + 0x90], edx
// 005fb772  89842494000000       mov dword ptr [esp + 0x94], eax
// 005fb779  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005fb780  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fb789  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005fb78f  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fb798  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005fb79e  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fb7a7  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fb7ad  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fb7b6  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fb7bc  8d542478             lea edx, [esp + 0x78]
// 005fb7c0  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fb7c9  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fb7cf  8d8fcc000000         lea ecx, [edi + 0xcc]
// 005fb7d5  52                   push edx
// 005fb7d6  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fb7df  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005fb7e6  e8d5eafeff           call 0x5ea2c0
// 005fb7eb  8b7518               mov esi, dword ptr [ebp + 0x18]
// 005fb7ee  8b06                 mov eax, dword ptr [esi]
// 005fb7f0  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fb7f3  57                   push edi
// 005fb7f4  8bce                 mov ecx, esi
// 005fb7f6  ffd2                 call edx
// 005fb7f8  8bf8                 mov edi, eax
// 005fb7fa  8b06                 mov eax, dword ptr [esi]
// 005fb7fc  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fb7ff  53                   push ebx
// 005fb800  8bce                 mov ecx, esi
// 005fb802  ffd2                 call edx
// 005fb804  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005fb808  8bd8                 mov ebx, eax
// 005fb80a  8b06                 mov eax, dword ptr [esi]
// 005fb80c  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fb80f  51                   push ecx
// 005fb810  8bce                 mov ecx, esi
// 005fb812  ffd2                 call edx
// 005fb814  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005fb81b  8944243c             mov dword ptr [esp + 0x3c], eax
// 005fb81f  8b06                 mov eax, dword ptr [esi]
// 005fb821  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fb824  51                   push ecx
// 005fb825  8bce                 mov ecx, esi
// 005fb827  ffd2                 call edx
// 005fb829  8b16                 mov edx, dword ptr [esi]
// 005fb82b  8b5218               mov edx, dword ptr [edx + 0x18]
// 005fb82e  50                   push eax
// 005fb82f  89442460             mov dword ptr [esp + 0x60], eax
// 005fb833  8b442440             mov eax, dword ptr [esp + 0x40]
// 005fb837  50                   push eax
// 005fb838  53                   push ebx
// 005fb839  57                   push edi
// 005fb83a  8bce                 mov ecx, esi
// 005fb83c  ffd2                 call edx
// 005fb83e  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005fb841  85c0                 test eax, eax
// 005fb843  7413                 je 0x5fb858
// 005fb845  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005fb849  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005fb84d  8938                 mov dword ptr [eax], edi
// 005fb84f  895804               mov dword ptr [eax + 4], ebx
// 005fb852  894808               mov dword ptr [eax + 8], ecx
// 005fb855  89500c               mov dword ptr [eax + 0xc], edx
// 005fb858  5f                   pop edi
// 005fb859  5e                   pop esi
// 005fb85a  5b                   pop ebx
// 005fb85b  8be5                 mov esp, ebp
// 005fb85d  5d                   pop ebp
// 005fb85e  c22000               ret 0x20
// 005fb861  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005fb868  743c                 je 0x5fb8a6
// 005fb86a  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005fb86e  7536                 jne 0x5fb8a6
// 005fb870  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005fb875  85c0                 test eax, eax
// 005fb877  7418                 je 0x5fb891
// 005fb879  6801010000           push 0x101
// 005fb87e  688027b800           push 0xb82780
// 005fb883  680027b800           push 0xb82700
// 005fb888  ffd0                 call eax
// 005fb88a  83c40c               add esp, 0xc
// 005fb88d  84c0                 test al, al
// 005fb88f  7515                 jne 0x5fb8a6
// 005fb891  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005fb898  688826b800           push 0xb82688
// 005fb89d  50                   push eax
// 005fb89e  e8ed693700           call 0x972290
// 005fb8a3  83c408               add esp, 8
// 005fb8a6  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005fb8ac  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005fb8b3  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005fb8bb  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005fb8c3  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005fb8c8  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005fb8ce  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005fb8d6  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005fb8db  8d4c2460             lea ecx, [esp + 0x60]
// 005fb8df  51                   push ecx
// 005fb8e0  f30f59c2             mulss xmm0, xmm2
// 005fb8e4  f30f59ca             mulss xmm1, xmm2
// 005fb8e8  8d4c2420             lea ecx, [esp + 0x20]
// 005fb8ec  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005fb8f5  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005fb8fe  e83d890300           call 0x634240
// 005fb903  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005fb90c  f30f5e00             divss xmm0, dword ptr [eax]
// 005fb910  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005fb915  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005fb918  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005fb91b  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005fb920  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005fb928  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005fb92e  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005fb937  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005fb940  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005fb945  33d2                 xor edx, edx
// 005fb947  33db                 xor ebx, ebx
// 005fb949  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005fb952  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005fb959  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005fb960  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005fb966  0f2fd7               comiss xmm2, xmm7
// 005fb969  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005fb96f  8954243c             mov dword ptr [esp + 0x3c], edx
// 005fb973  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005fb97c  770a                 ja 0x5fb988
// 005fb97e  85d2                 test edx, edx
// 005fb980  0f85d2feffff         jne 0x5fb858
// 005fb986  eb04                 jmp 0x5fb98c
// 005fb988  85d2                 test edx, edx
// 005fb98a  7504                 jne 0x5fb990
// 005fb98c  f30f5cc4             subss xmm0, xmm4
// 005fb990  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005fb994  80797000             cmp byte ptr [ecx + 0x70], 0
// 005fb998  7421                 je 0x5fb9bb
// 005fb99a  f30f58c7             addss xmm0, xmm7
// 005fb99e  0f2fc2               comiss xmm0, xmm2
// 005fb9a1  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005fb9aa  8d44241c             lea eax, [esp + 0x1c]
// 005fb9ae  7707                 ja 0x5fb9b7
// 005fb9b0  8d84240c030000       lea eax, [esp + 0x30c]
// 005fb9b7  f30f1010             movss xmm2, dword ptr [eax]
// 005fb9bb  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005fb9c4  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005fb9ca  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005fb9d1  f30f58cb             addss xmm1, xmm3
// 005fb9d5  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005fb9da  33c0                 xor eax, eax
// 005fb9dc  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005fb9e2  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005fb9eb  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005fb9f2  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005fb9f8  0f2ff0               comiss xmm6, xmm0
// 005fb9fb  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005fba04  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005fba0a  7708                 ja 0x5fba14
// 005fba0c  85c0                 test eax, eax
// 005fba0e  0f852b110000         jne 0x5fcb3f
// 005fba14  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005fba1a  85c0                 test eax, eax
// 005fba1c  7504                 jne 0x5fba22
// 005fba1e  f30f5ccc             subss xmm1, xmm4
// 005fba22  0f28f1               movaps xmm6, xmm1
// 005fba25  f30f58f0             addss xmm6, xmm0
// 005fba29  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005fba2e  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005fba37  8d442420             lea eax, [esp + 0x20]
// 005fba3b  7707                 ja 0x5fba44
// 005fba3d  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005fba44  80797000             cmp byte ptr [ecx + 0x70], 0
// 005fba48  f30f1000             movss xmm0, dword ptr [eax]
// 005fba4c  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005fba52  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005fba5b  f30f58c3             addss xmm0, xmm3
// 005fba5f  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005fba68  0f57c0               xorps xmm0, xmm0
// 005fba6b  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005fba71  740f                 je 0x5fba82
// 005fba73  e818e8feff           call 0x5ea290
// 005fba78  d80d94deb600         fmul dword ptr [0xb6de94]
// 005fba7e  d95c2440             fstp dword ptr [esp + 0x40]
// 005fba82  0f28dd               movaps xmm3, xmm5
// 005fba85  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005fba8e  0f28c3               movaps xmm0, xmm3
// 005fba91  f30f59c4             mulss xmm0, xmm4
// 005fba95  f30f5cd7             subss xmm2, xmm7
// 005fba99  f30f59d3             mulss xmm2, xmm3
// 005fba9d  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005fbaa3  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005fbaa9  f30f58d3             addss xmm2, xmm3
// 005fbaad  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005fbab3  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005fbab9  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005fbabf  0f28c5               movaps xmm0, xmm5
// 005fbac2  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005fbacb  0f28e9               movaps xmm5, xmm1
// 005fbace  0f28f0               movaps xmm6, xmm0
// 005fbad1  f30f59f4             mulss xmm6, xmm4
// 005fbad5  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005fbadb  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005fbae1  f30f5ccb             subss xmm1, xmm3
// 005fbae5  f30f59e8             mulss xmm5, xmm0
// 005fbae9  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005fbaef  f30f59c8             mulss xmm1, xmm0
// 005fbaf3  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005fbaf9  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005fbb02  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005fbb0b  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005fbb14  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005fbb1d  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005fbb26  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005fbb2f  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005fbb38  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005fbb41  85d2                 test edx, edx
// 005fbb43  753f                 jne 0x5fbb84
// 005fbb45  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005fbb4b  0f28c4               movaps xmm0, xmm4
// 005fbb4e  f30f58c3             addss xmm0, xmm3
// 005fbb52  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005fbb5b  0f28c3               movaps xmm0, xmm3
// 005fbb5e  f30f58c2             addss xmm0, xmm2
// 005fbb62  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005fbb6b  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005fbb74  0f28c4               movaps xmm0, xmm4
// 005fbb77  f30f58c3             addss xmm0, xmm3
// 005fbb7b  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005fbb84  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005fbb8a  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005fbb8f  772f                 ja 0x5fbbc0
// 005fbb91  0f28c6               movaps xmm0, xmm6
// 005fbb94  f30f58c5             addss xmm0, xmm5
// 005fbb98  f30f58f1             addss xmm6, xmm1
// 005fbb9c  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005fbba5  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005fbbae  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005fbbb7  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005fbbc0  8d9424cc000000       lea edx, [esp + 0xcc]
// 005fbbc7  52                   push edx
// 005fbbc8  8d8c2444010000       lea ecx, [esp + 0x144]
// 005fbbcf  e86c860300           call 0x634240
// 005fbbd4  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005fbbd9  f30f1008             movss xmm1, dword ptr [eax]
// 005fbbdd  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005fbbe3  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005fbbe9  8d8424d8000000       lea eax, [esp + 0xd8]
// 005fbbf0  50                   push eax
// 005fbbf1  8d8c2444010000       lea ecx, [esp + 0x144]
// 005fbbf8  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005fbc01  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005fbc0a  e831860300           call 0x634240
// 005fbc0f  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005fbc14  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005fbc1a  f30f5808             addss xmm1, dword ptr [eax]
// 005fbc1e  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005fbc24  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005fbc2b  51                   push ecx
// 005fbc2c  8d8c2444010000       lea ecx, [esp + 0x144]
// 005fbc33  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005fbc3c  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005fbc45  e8f6850300           call 0x634240
// 005fbc4a  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005fbc50  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005fbc55  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005fbc5b  f30f5c08             subss xmm1, dword ptr [eax]
// 005fbc5f  8d94248c010000       lea edx, [esp + 0x18c]
// 005fbc66  52                   push edx
// 005fbc67  8d8c2444010000       lea ecx, [esp + 0x144]
// 005fbc6e  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005fbc77  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005fbc80  e8bb850300           call 0x634240
// 005fbc85  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005fbc8b  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005fbc90  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005fbc96  f30f5c08             subss xmm1, dword ptr [eax]
// 005fbc9a  8d842498010000       lea eax, [esp + 0x198]
// 005fbca1  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005fbcaa  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fbcb2  50                   push eax
// 005fbcb3  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005fbcba  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005fbcc0  0f57c0               xorps xmm0, xmm0
// 005fbcc3  51                   push ecx
// 005fbcc4  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005fbccb  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005fbcd4  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005fbcda  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005fbce0  e82b850300           call 0x634210
// 005fbce5  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005fbcee  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005fbcf7  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005fbd00  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005fbd09  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005fbd12  8d9424ec000000       lea edx, [esp + 0xec]
// 005fbd19  52                   push edx
// 005fbd1a  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005fbd21  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005fbd2a  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005fbd33  50                   push eax
// 005fbd34  8d8c2484010000       lea ecx, [esp + 0x184]
// 005fbd3b  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005fbd44  e8c7840300           call 0x634210
// 005fbd49  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005fbd52  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005fbd58  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005fbd61  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005fbd67  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005fbd70  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005fbd76  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005fbd7f  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005fbd85  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005fbd8e  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005fbd97  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005fbda0  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005fbda9  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005fbdb2  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005fbdbb  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005fbdc4  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005fbdcd  8d4c246c             lea ecx, [esp + 0x6c]
// 005fbdd1  51                   push ecx
// 005fbdd2  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005fbdd9  52                   push edx
// 005fbdda  e841b82200           call 0x827620
// 005fbddf  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005fbde8  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005fbdf1  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005fbdfa  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005fbe01  50                   push eax
// 005fbe02  8d8c2484030000       lea ecx, [esp + 0x384]
// 005fbe09  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005fbe12  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fbe1a  51                   push ecx
// 005fbe1b  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005fbe24  e8f7b72200           call 0x827620
// 005fbe29  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005fbe2f  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005fbe38  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005fbe3e  8d942470030000       lea edx, [esp + 0x370]
// 005fbe45  52                   push edx
// 005fbe46  8d842450030000       lea eax, [esp + 0x350]
// 005fbe4d  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005fbe56  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fbe5c  50                   push eax
// 005fbe5d  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005fbe66  e8b5b72200           call 0x827620
// 005fbe6b  83c418               add esp, 0x18
// 005fbe6e  8d8c2430030000       lea ecx, [esp + 0x330]
// 005fbe75  51                   push ecx
// 005fbe76  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005fbe7d  e8be830300           call 0x634240
// 005fbe82  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005fbe8b  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005fbe92  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005fbe99  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005fbea0  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005fbea9  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005fbeb2  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005fbebb  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005fbec4  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005fbecd  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005fbed6  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005fbedf  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005fbee8  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005fbef1  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005fbefa  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005fbf03  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005fbf0c  89942448020000       mov dword ptr [esp + 0x248], edx
// 005fbf13  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005fbf1a  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005fbf23  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005fbf2c  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005fbf33  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005fbf3a  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005fbf43  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005fbf4c  89942454020000       mov dword ptr [esp + 0x254], edx
// 005fbf53  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005fbf5a  89842458020000       mov dword ptr [esp + 0x258], eax
// 005fbf61  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005fbf68  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005fbf71  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005fbf7a  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005fbf81  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005fbf88  89942460020000       mov dword ptr [esp + 0x260], edx
// 005fbf8f  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005fbf98  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005fbfa1  8d54246c             lea edx, [esp + 0x6c]
// 005fbfa5  89842464020000       mov dword ptr [esp + 0x264], eax
// 005fbfac  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005fbfb3  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005fbfba  52                   push edx
// 005fbfbb  8d842470030000       lea eax, [esp + 0x370]
// 005fbfc2  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005fbfcb  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005fbfd4  50                   push eax
// 005fbfd5  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005fbfdc  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005fbfe5  e836b62200           call 0x827620
// 005fbfea  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005fbff3  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005fbffc  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005fc005  8d8c2498030000       lea ecx, [esp + 0x398]
// 005fc00c  51                   push ecx
// 005fc00d  8d942460030000       lea edx, [esp + 0x360]
// 005fc014  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005fc01d  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fc025  52                   push edx
// 005fc026  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005fc02f  e8ecb52200           call 0x827620
// 005fc034  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005fc03a  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005fc043  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005fc049  8d842400040000       lea eax, [esp + 0x400]
// 005fc050  50                   push eax
// 005fc051  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005fc058  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005fc061  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fc067  51                   push ecx
// 005fc068  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005fc071  e8aab52200           call 0x827620
// 005fc076  83c418               add esp, 0x18
// 005fc079  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005fc080  52                   push edx
// 005fc081  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005fc088  e8b3810300           call 0x634240
// 005fc08d  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005fc096  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005fc09d  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005fc0a4  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005fc0ab  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005fc0b4  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005fc0bd  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005fc0c6  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005fc0cf  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005fc0d8  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005fc0e1  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005fc0ea  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005fc0f3  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005fc0fc  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005fc105  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005fc10e  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005fc117  89842490020000       mov dword ptr [esp + 0x290], eax
// 005fc11e  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005fc125  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005fc12e  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005fc137  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005fc13e  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005fc145  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005fc14e  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005fc157  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005fc15e  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005fc165  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005fc16c  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005fc173  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005fc17c  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005fc185  89942498020000       mov dword ptr [esp + 0x298], edx
// 005fc18c  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005fc193  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005fc19a  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005fc1a3  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005fc1ac  8d44246c             lea eax, [esp + 0x6c]
// 005fc1b0  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005fc1b7  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005fc1be  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005fc1c5  50                   push eax
// 005fc1c6  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005fc1cd  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005fc1d6  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005fc1df  51                   push ecx
// 005fc1e0  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005fc1e7  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005fc1f0  e82bb42200           call 0x827620
// 005fc1f5  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005fc1fe  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005fc207  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005fc210  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005fc219  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fc221  8d94248c030000       lea edx, [esp + 0x38c]
// 005fc228  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005fc231  52                   push edx
// 005fc232  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005fc239  50                   push eax
// 005fc23a  e8e1b32200           call 0x827620
// 005fc23f  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005fc245  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005fc24e  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005fc254  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005fc25b  51                   push ecx
// 005fc25c  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005fc263  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005fc26c  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fc272  52                   push edx
// 005fc273  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005fc27c  e89fb32200           call 0x827620
// 005fc281  83c418               add esp, 0x18
// 005fc284  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005fc28b  50                   push eax
// 005fc28c  8d8c2480010000       lea ecx, [esp + 0x180]
// 005fc293  e8a87f0300           call 0x634240
// 005fc298  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005fc2a1  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005fc2a8  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005fc2af  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005fc2b6  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005fc2bf  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005fc2c8  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005fc2d1  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005fc2da  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005fc2e3  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005fc2ec  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005fc2f5  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005fc2fe  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005fc307  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005fc310  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005fc319  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 005fc322  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 005fc329  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 005fc330  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 005fc339  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 005fc342  89942404020000       mov dword ptr [esp + 0x204], edx
// 005fc349  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 005fc350  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 005fc359  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005fc35f  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 005fc366  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 005fc36d  89942410020000       mov dword ptr [esp + 0x210], edx
// 005fc374  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 005fc37b  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 005fc384  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fc38a  89842408020000       mov dword ptr [esp + 0x208], eax
// 005fc391  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 005fc398  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 005fc39f  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005fc3a8  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fc3ae  8d4c246c             lea ecx, [esp + 0x6c]
// 005fc3b2  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 005fc3b9  89842414020000       mov dword ptr [esp + 0x214], eax
// 005fc3c0  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 005fc3c7  51                   push ecx
// 005fc3c8  8d942410010000       lea edx, [esp + 0x110]
// 005fc3cf  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 005fc3d8  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fc3de  52                   push edx
// 005fc3df  89842428020000       mov dword ptr [esp + 0x228], eax
// 005fc3e6  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005fc3ef  e82cb22200           call 0x827620
// 005fc3f4  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005fc3fd  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 005fc406  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005fc40f  8d842404040000       lea eax, [esp + 0x404]
// 005fc416  50                   push eax
// 005fc417  8d8c2438010000       lea ecx, [esp + 0x138]
// 005fc41e  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 005fc427  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fc42f  51                   push ecx
// 005fc430  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 005fc439  e8e2b12200           call 0x827620
// 005fc43e  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005fc444  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 005fc44d  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005fc453  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005fc45c  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fc462  8d9424b8030000       lea edx, [esp + 0x3b8]
// 005fc469  52                   push edx
// 005fc46a  8d842430010000       lea eax, [esp + 0x130]
// 005fc471  50                   push eax
// 005fc472  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 005fc47b  e8a0b12200           call 0x827620
// 005fc480  83c418               add esp, 0x18
// 005fc483  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 005fc48a  51                   push ecx
// 005fc48b  8d4c242c             lea ecx, [esp + 0x2c]
// 005fc48f  e8ac7d0300           call 0x634240
// 005fc494  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 005fc49d  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 005fc4a4  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 005fc4ab  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 005fc4b2  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fc4bb  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 005fc4c4  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fc4cd  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 005fc4d6  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fc4df  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 005fc4e8  89542478             mov dword ptr [esp + 0x78], edx
// 005fc4ec  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 005fc4f3  8944247c             mov dword ptr [esp + 0x7c], eax
// 005fc4f7  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005fc4fe  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fc507  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 005fc510  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005fc517  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 005fc51e  89942484000000       mov dword ptr [esp + 0x84], edx
// 005fc525  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 005fc52c  89842488000000       mov dword ptr [esp + 0x88], eax
// 005fc533  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 005fc53a  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fc543  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 005fc54c  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005fc553  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 005fc55a  89942490000000       mov dword ptr [esp + 0x90], edx
// 005fc561  8b17                 mov edx, dword ptr [edi]
// 005fc563  8b5210               mov edx, dword ptr [edx + 0x10]
// 005fc566  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fc56f  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 005fc578  89842494000000       mov dword ptr [esp + 0x94], eax
// 005fc57f  8d842448020000       lea eax, [esp + 0x248]
// 005fc586  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005fc58d  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fc596  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 005fc59f  50                   push eax
// 005fc5a0  8bcf                 mov ecx, edi
// 005fc5a2  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fc5ab  ffd2                 call edx
// 005fc5ad  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 005fc5b4  8b07                 mov eax, dword ptr [edi]
// 005fc5b6  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fc5b9  8d8c2490020000       lea ecx, [esp + 0x290]
// 005fc5c0  51                   push ecx
// 005fc5c1  8bcf                 mov ecx, edi
// 005fc5c3  ffd2                 call edx
// 005fc5c5  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 005fc5cc  8b07                 mov eax, dword ptr [edi]
// 005fc5ce  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fc5d1  8d8c2400020000       lea ecx, [esp + 0x200]
// 005fc5d8  51                   push ecx
// 005fc5d9  8bcf                 mov ecx, edi
// 005fc5db  ffd2                 call edx
// 005fc5dd  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 005fc5e4  8b07                 mov eax, dword ptr [edi]
// 005fc5e6  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fc5e9  8d4c2478             lea ecx, [esp + 0x78]
// 005fc5ed  51                   push ecx
// 005fc5ee  8bcf                 mov ecx, edi
// 005fc5f0  ffd2                 call edx
// 005fc5f2  89842460010000       mov dword ptr [esp + 0x160], eax
// 005fc5f9  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005fc600  40                   inc eax
// 005fc601  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005fc608  3bc3                 cmp eax, ebx
// 005fc60a  8d84246c010000       lea eax, [esp + 0x16c]
// 005fc611  7c07                 jl 0x5fc61a
// 005fc613  8d8424e8000000       lea eax, [esp + 0xe8]
// 005fc61a  8b18                 mov ebx, dword ptr [eax]
// 005fc61c  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 005fc623  8bc8                 mov ecx, eax
// 005fc625  40                   inc eax
// 005fc626  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005fc62d  85c9                 test ecx, ecx
// 005fc62f  0f85f9000000         jne 0x5fc72e
// 005fc635  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 005fc63c  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005fc63f  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 005fc648  8911                 mov dword ptr [ecx], edx
// 005fc64a  f30f1106             movss dword ptr [esi], xmm0
// 005fc64e  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 005fc657  f30f114604           movss dword ptr [esi + 4], xmm0
// 005fc65c  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 005fc665  f30f114608           movss dword ptr [esi + 8], xmm0
// 005fc66a  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 005fc673  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 005fc678  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 005fc681  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 005fc686  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 005fc68f  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 005fc694  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 005fc69d  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 005fc6a2  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 005fc6ab  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 005fc6b0  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 005fc6b9  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 005fc6be  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 005fc6c7  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 005fc6cc  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 005fc6d5  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 005fc6da  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 005fc6e3  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 005fc6e8  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 005fc6f1  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 005fc6f6  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 005fc6ff  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 005fc704  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 005fc70d  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 005fc712  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 005fc71b  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 005fc720  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 005fc729  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 005fc72e  8bd3                 mov edx, ebx
// 005fc730  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 005fc735  8d0c9501000000       lea ecx, [edx*4 + 1]
// 005fc73c  8bd0                 mov edx, eax
// 005fc73e  40                   inc eax
// 005fc73f  3bd1                 cmp edx, ecx
// 005fc741  0f8501010000         jne 0x5fc848
// 005fc747  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005fc74e  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005fc751  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 005fc75a  894a04               mov dword ptr [edx + 4], ecx
// 005fc75d  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 005fc762  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 005fc76b  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 005fc770  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 005fc779  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 005fc77e  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 005fc787  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 005fc78c  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 005fc795  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 005fc79a  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 005fc7a3  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 005fc7a8  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 005fc7b1  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 005fc7b6  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 005fc7bf  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 005fc7c4  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 005fc7cd  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 005fc7d2  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 005fc7db  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 005fc7e0  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 005fc7e9  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 005fc7ee  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 005fc7f7  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 005fc7fc  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 005fc805  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 005fc80a  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 005fc813  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 005fc818  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 005fc821  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 005fc826  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 005fc82f  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 005fc837  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 005fc840  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 005fc848  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005fc84c  41                   inc ecx
// 005fc84d  0fafcb               imul ecx, ebx
// 005fc850  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 005fc857  8bc8                 mov ecx, eax
// 005fc859  40                   inc eax
// 005fc85a  3bca                 cmp ecx, edx
// 005fc85c  0f852e010000         jne 0x5fc990
// 005fc862  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 005fc869  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005fc86c  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005fc875  895108               mov dword ptr [ecx + 8], edx
// 005fc878  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 005fc880  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 005fc889  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 005fc891  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 005fc89a  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 005fc8a2  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 005fc8ab  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 005fc8b3  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 005fc8bc  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 005fc8c4  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 005fc8cd  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 005fc8d5  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 005fc8de  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 005fc8e6  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 005fc8ef  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 005fc8f7  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 005fc900  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 005fc908  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 005fc911  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 005fc919  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 005fc922  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 005fc92a  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 005fc933  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 005fc93b  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 005fc944  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 005fc94c  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 005fc955  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 005fc95d  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 005fc966  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 005fc96e  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 005fc977  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 005fc97f  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 005fc988  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 005fc990  8bc8                 mov ecx, eax
// 005fc992  8d149dffffffff       lea edx, [ebx*4 - 1]
// 005fc999  40                   inc eax
// 005fc99a  89842478010000       mov dword ptr [esp + 0x178], eax
// 005fc9a1  3bca                 cmp ecx, edx
// 005fc9a3  0f8528010000         jne 0x5fcad1
// 005fc9a9  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005fc9ac  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005fc9b3  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 005fc9b9  89420c               mov dword ptr [edx + 0xc], eax
// 005fc9bc  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 005fc9c4  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 005fc9ca  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 005fc9d2  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 005fc9db  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 005fc9e3  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 005fc9ec  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 005fc9f4  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 005fc9fd  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 005fca05  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 005fca0e  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 005fca16  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 005fca1f  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 005fca27  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 005fca30  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 005fca38  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 005fca41  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 005fca49  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 005fca52  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 005fca5a  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 005fca63  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 005fca6b  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 005fca74  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 005fca7c  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 005fca85  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 005fca8d  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 005fca96  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 005fca9e  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 005fcaa7  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 005fcaaf  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 005fcab8  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 005fcac0  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 005fcac9  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 005fcad1  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005fcad8  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005fcadf  8b17                 mov edx, dword ptr [edi]
// 005fcae1  8b5218               mov edx, dword ptr [edx + 0x18]
// 005fcae4  50                   push eax
// 005fcae5  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 005fcaec  51                   push ecx
// 005fcaed  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 005fcaf4  50                   push eax
// 005fcaf5  51                   push ecx
// 005fcaf6  8bcf                 mov ecx, edi
// 005fcaf8  ffd2                 call edx
// 005fcafa  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005fcb00  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 005fcb09  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005fcb11  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 005fcb1a  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 005fcb20  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005fcb26  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005fcb2b  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005fcb32  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005fcb36  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005fcb3a  e9b3eeffff           jmp 0x5fb9f2
// 005fcb3f  0f28fa               movaps xmm7, xmm2
// 005fcb42  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 005fcb48  0f28d9               movaps xmm3, xmm1
// 005fcb4b  42                   inc edx
// 005fcb4c  e90feeffff           jmp 0x5fb960
// 005fcb51  8d4900               lea ecx, [ecx]
// 005fcb54  01ae5f006caf         add dword ptr [esi - 0x5093ffa1], ebp
// 005fcb5a  5f                   pop edi
// 005fcb5b  0058ae               add byte ptr [eax - 0x52], bl
// 005fcb5e  5f                   pop edi
// 005fcb5f  001e                 add byte ptr [esi], bl
// 005fcb61  af                   scasd eax, dword ptr es:[edi]
// 005fcb62  5f                   pop edi
// 005fcb63  0096ae5f00da         add byte ptr [esi - 0x25ffa052], dl
// 005fcb69  ae                   scasb al, byte ptr es:[edi]
// 005fcb6a  5f                   pop edi

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
