// from server: 27% by Intel
// roc 2012-06 005ed6b0  unit: G3D::Random  size: 7848 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ed6b0
//
// 005ed6b0  55                   push ebp
// 005ed6b1  8bec                 mov ebp, esp
// 005ed6b3  83e4f8               and esp, 0xfffffff8
// 005ed6b6  81ecfc030000         sub esp, 0x3fc
// 005ed6bc  53                   push ebx
// 005ed6bd  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005ed6c0  56                   push esi
// 005ed6c1  57                   push edi
// 005ed6c2  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005ed6c5  8d44246c             lea eax, [esp + 0x6c]
// 005ed6c9  8bf1                 mov esi, ecx
// 005ed6cb  53                   push ebx
// 005ed6cc  c1ef03               shr edi, 3
// 005ed6cf  50                   push eax
// 005ed6d0  89742464             mov dword ptr [esp + 0x64], esi
// 005ed6d4  83e707               and edi, 7
// 005ed6d7  e8149f2300           call 0x8275f0
// 005ed6dc  d9442474             fld dword ptr [esp + 0x74]
// 005ed6e0  d9e1                 fabs 
// 005ed6e2  8d4c2474             lea ecx, [esp + 0x74]
// 005ed6e6  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005ed6ed  53                   push ebx
// 005ed6ee  d944247c             fld dword ptr [esp + 0x7c]
// 005ed6f2  51                   push ecx
// 005ed6f3  d9e1                 fabs 
// 005ed6f5  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005ed6fc  d9842484000000       fld dword ptr [esp + 0x84]
// 005ed703  d9e1                 fabs 
// 005ed705  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005ed70c  e8df9e2300           call 0x8275f0
// 005ed711  d944247c             fld dword ptr [esp + 0x7c]
// 005ed715  8a4670               mov al, byte ptr [esi + 0x70]
// 005ed718  d9e1                 fabs 
// 005ed71a  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005ed722  d9842480000000       fld dword ptr [esp + 0x80]
// 005ed729  83c410               add esp, 0x10
// 005ed72c  d9e1                 fabs 
// 005ed72e  d9442474             fld dword ptr [esp + 0x74]
// 005ed732  d9e1                 fabs 
// 005ed734  d9450c               fld dword ptr [ebp + 0xc]
// 005ed737  dceb                 fsub st(3), st(0)
// 005ed739  d9cb                 fxch st(3)
// 005ed73b  d95c241c             fstp dword ptr [esp + 0x1c]
// 005ed73f  d9c9                 fxch st(1)
// 005ed741  dee2                 fsubrp st(2)
// 005ed743  d9c9                 fxch st(1)
// 005ed745  d95c2420             fstp dword ptr [esp + 0x20]
// 005ed749  d95c2424             fstp dword ptr [esp + 0x24]
// 005ed74d  84c0                 test al, al
// 005ed74f  741b                 je 0x5ed76c
// 005ed751  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005ed759  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005ed762  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005ed76a  eb11                 jmp 0x5ed77d
// 005ed76c  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005ed774  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005ed77d  0f57e4               xorps xmm4, xmm4
// 005ed780  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005ed789  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005ed78f  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005ed795  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005ed79b  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005ed7a1  83ff05               cmp edi, 5
// 005ed7a4  0f87a4010000         ja 0x5ed94e
// 005ed7aa  ff24bd40f55e00       jmp dword ptr [edi*4 + 0x5ef540]
// 005ed7b1  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005ed7b9  8d542460             lea edx, [esp + 0x60]
// 005ed7bd  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005ed7c3  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005ed7cb  52                   push edx
// 005ed7cc  8d4c2420             lea ecx, [esp + 0x20]
// 005ed7d0  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005ed7d6  e8656a0400           call 0x634240
// 005ed7db  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005ed7e3  f30f1000             movss xmm0, dword ptr [eax]
// 005ed7e7  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005ed7ec  0f57e4               xorps xmm4, xmm4
// 005ed7ef  f30f59c5             mulss xmm0, xmm5
// 005ed7f3  f30f59cd             mulss xmm1, xmm5
// 005ed7f7  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005ed7fd  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005ed803  e946010000           jmp 0x5ed94e
// 005ed808  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005ed810  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005ed816  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005ed81c  84c0                 test al, al
// 005ed81e  7413                 je 0x5ed833
// 005ed820  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005ed828  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ed82e  e91b010000           jmp 0x5ed94e
// 005ed833  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005ed83b  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ed841  e908010000           jmp 0x5ed94e
// 005ed846  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005ed84c  84c0                 test al, al
// 005ed84e  7419                 je 0x5ed869
// 005ed850  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005ed858  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005ed85e  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ed864  e9e5000000           jmp 0x5ed94e
// 005ed869  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005ed871  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005ed877  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005ed87f  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ed885  e9c4000000           jmp 0x5ed94e
// 005ed88a  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005ed890  84c0                 test al, al
// 005ed892  7419                 je 0x5ed8ad
// 005ed894  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005ed89c  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005ed8a2  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ed8a8  e9a1000000           jmp 0x5ed94e
// 005ed8ad  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005ed8b5  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005ed8bb  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005ed8c3  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ed8c9  e980000000           jmp 0x5ed94e
// 005ed8ce  84c0                 test al, al
// 005ed8d0  745a                 je 0x5ed92c
// 005ed8d2  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005ed8d9  7441                 je 0x5ed91c
// 005ed8db  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005ed8e0  85c0                 test eax, eax
// 005ed8e2  7418                 je 0x5ed8fc
// 005ed8e4  68b7000000           push 0xb7
// 005ed8e9  688027b800           push 0xb82780
// 005ed8ee  68cc60b400           push 0xb460cc
// 005ed8f3  ffd0                 call eax
// 005ed8f5  83c40c               add esp, 0xc
// 005ed8f8  84c0                 test al, al
// 005ed8fa  7515                 jne 0x5ed911
// 005ed8fc  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005ed903  680827b800           push 0xb82708
// 005ed908  50                   push eax
// 005ed909  e882493800           call 0x972290
// 005ed90e  83c408               add esp, 8
// 005ed911  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005ed919  0f57e4               xorps xmm4, xmm4
// 005ed91c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005ed924  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005ed92a  eb1c                 jmp 0x5ed948
// 005ed92c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005ed934  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005ed93a  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005ed942  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ed948  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005ed94e  807e7000             cmp byte ptr [esi + 0x70], 0
// 005ed952  7419                 je 0x5ed96d
// 005ed954  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005ed959  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005ed961  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005ed967  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005ed96d  85ff                 test edi, edi
// 005ed96f  0f85da080000         jne 0x5ee24f
// 005ed975  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ed97d  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005ed982  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005ed98a  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005ed98f  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005ed995  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005ed99e  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005ed9a6  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005ed9ac  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005ed9b5  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005ed9be  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005ed9c7  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005ed9d0  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005ed9d9  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005ed9e2  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005ed9eb  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005ed9f4  f30f59c5             mulss xmm0, xmm5
// 005ed9f8  f30f59cd             mulss xmm1, xmm5
// 005ed9fc  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005eda05  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005eda0e  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005eda13  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005eda1c  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005eda25  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005eda2c  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005eda32  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005eda3b  0f28e3               movaps xmm4, xmm3
// 005eda3e  f30f5ce0             subss xmm4, xmm0
// 005eda42  0f28eb               movaps xmm5, xmm3
// 005eda45  f30f5ce9             subss xmm5, xmm1
// 005eda49  51                   push ecx
// 005eda4a  8d542464             lea edx, [esp + 0x64]
// 005eda4e  f30f5cc3             subss xmm0, xmm3
// 005eda52  0f28d3               movaps xmm2, xmm3
// 005eda55  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005eda5c  f30f5ccb             subss xmm1, xmm3
// 005eda60  52                   push edx
// 005eda61  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005eda6a  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005eda73  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005eda7c  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005eda85  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005eda8e  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005eda97  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005edaa0  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005edaa9  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005edab2  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005edabb  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005edac4  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005edacd  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005edad6  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005edadf  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005edae8  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005edaf1  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005edafa  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005edb03  e8e89a2300           call 0x8275f0
// 005edb08  8d442474             lea eax, [esp + 0x74]
// 005edb0c  50                   push eax
// 005edb0d  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005edb14  51                   push ecx
// 005edb15  e8d69a2300           call 0x8275f0
// 005edb1a  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005edb22  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005edb28  0f57c8               xorps xmm1, xmm0
// 005edb2b  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005edb34  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005edb3a  8d9424d0000000       lea edx, [esp + 0xd0]
// 005edb41  0f57c8               xorps xmm1, xmm0
// 005edb44  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005edb4a  52                   push edx
// 005edb4b  8d8424ec000000       lea eax, [esp + 0xec]
// 005edb52  50                   push eax
// 005edb53  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005edb5c  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005edb65  e8869a2300           call 0x8275f0
// 005edb6a  83c418               add esp, 0x18
// 005edb6d  8d4c2440             lea ecx, [esp + 0x40]
// 005edb71  51                   push ecx
// 005edb72  8d8c2480010000       lea ecx, [esp + 0x180]
// 005edb79  e8c2660400           call 0x634240
// 005edb7e  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005edb85  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005edb8b  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005edb92  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005edb99  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005edb9c  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005edba5  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005edbab  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005edbb4  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005edbba  89542478             mov dword ptr [esp + 0x78], edx
// 005edbbe  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005edbc5  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005edbce  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005edbd4  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005edbdb  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005edbe2  89942484000000       mov dword ptr [esp + 0x84], edx
// 005edbe9  8b542460             mov edx, dword ptr [esp + 0x60]
// 005edbed  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005edbf6  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005edbfb  8944247c             mov dword ptr [esp + 0x7c], eax
// 005edbff  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005edc06  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005edc0d  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005edc11  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005edc1a  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005edc23  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005edc2c  89942490000000       mov dword ptr [esp + 0x90], edx
// 005edc33  89842488000000       mov dword ptr [esp + 0x88], eax
// 005edc3a  8b442464             mov eax, dword ptr [esp + 0x64]
// 005edc3e  8d542478             lea edx, [esp + 0x78]
// 005edc42  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005edc49  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005edc52  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005edc5b  52                   push edx
// 005edc5c  8bce                 mov ecx, esi
// 005edc5e  89842498000000       mov dword ptr [esp + 0x98], eax
// 005edc65  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005edc6e  e84dc6ffff           call 0x5ea2c0
// 005edc73  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005edc7c  8b7d24               mov edi, dword ptr [ebp + 0x24]
// 005edc7f  d907                 fld dword ptr [edi]
// 005edc81  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005edc87  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005edc90  d95e24               fstp dword ptr [esi + 0x24]
// 005edc93  d94704               fld dword ptr [edi + 4]
// 005edc96  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005edc9c  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005edca5  d95e28               fstp dword ptr [esi + 0x28]
// 005edca8  8d84248c010000       lea eax, [esp + 0x18c]
// 005edcaf  50                   push eax
// 005edcb0  8d4c2464             lea ecx, [esp + 0x64]
// 005edcb4  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005edcba  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005edcc3  51                   push ecx
// 005edcc4  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005edcca  e821992300           call 0x8275f0
// 005edccf  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005edcd6  52                   push edx
// 005edcd7  8d8424d8000000       lea eax, [esp + 0xd8]
// 005edcde  50                   push eax
// 005edcdf  e80c992300           call 0x8275f0
// 005edce4  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005edcea  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005edcf3  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005edcf9  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005edd00  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005edd07  51                   push ecx
// 005edd08  8d9424ec000000       lea edx, [esp + 0xec]
// 005edd0f  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005edd18  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005edd1e  52                   push edx
// 005edd1f  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005edd28  e8c3982300           call 0x8275f0
// 005edd2d  83c418               add esp, 0x18
// 005edd30  8d442440             lea eax, [esp + 0x40]
// 005edd34  50                   push eax
// 005edd35  8d8c2410010000       lea ecx, [esp + 0x110]
// 005edd3c  e8ff640400           call 0x634240
// 005edd41  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005edd48  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005edd4f  894c2478             mov dword ptr [esp + 0x78], ecx
// 005edd53  8954247c             mov dword ptr [esp + 0x7c], edx
// 005edd57  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005edd5d  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005edd64  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005edd6b  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005edd72  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005edd7b  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005edd81  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005edd8a  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005edd90  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005edd99  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005edd9f  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005edda8  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005eddae  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005eddb5  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005eddb9  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005eddc2  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005eddc8  89842480000000       mov dword ptr [esp + 0x80], eax
// 005eddcf  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005eddd6  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005edddd  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005edde6  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005eddec  8d4c2478             lea ecx, [esp + 0x78]
// 005eddf0  89942488000000       mov dword ptr [esp + 0x88], edx
// 005eddf7  8b542464             mov edx, dword ptr [esp + 0x64]
// 005eddfb  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005ede02  8b442468             mov eax, dword ptr [esp + 0x68]
// 005ede06  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005ede0f  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ede15  8d5e44               lea ebx, [esi + 0x44]
// 005ede18  51                   push ecx
// 005ede19  8bcb                 mov ecx, ebx
// 005ede1b  89942498000000       mov dword ptr [esp + 0x98], edx
// 005ede22  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005ede29  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005ede32  e889c4ffff           call 0x5ea2c0
// 005ede37  d94708               fld dword ptr [edi + 8]
// 005ede3a  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005ede43  d95e68               fstp dword ptr [esi + 0x68]
// 005ede46  d9470c               fld dword ptr [edi + 0xc]
// 005ede49  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005ede4f  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005ede58  d95e6c               fstp dword ptr [esi + 0x6c]
// 005ede5b  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005ede61  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005ede6a  8d94248c010000       lea edx, [esp + 0x18c]
// 005ede71  52                   push edx
// 005ede72  8d442464             lea eax, [esp + 0x64]
// 005ede76  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005ede7c  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005ede85  50                   push eax
// 005ede86  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005ede8c  e85f972300           call 0x8275f0
// 005ede91  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005ede98  51                   push ecx
// 005ede99  8d9424d8000000       lea edx, [esp + 0xd8]
// 005edea0  52                   push edx
// 005edea1  e84a972300           call 0x8275f0
// 005edea6  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005edeac  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005edeb5  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005edebb  8d8424d0000000       lea eax, [esp + 0xd0]
// 005edec2  50                   push eax
// 005edec3  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005edeca  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005eded3  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005eded9  51                   push ecx
// 005ededa  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005edee3  e808972300           call 0x8275f0
// 005edee8  83c418               add esp, 0x18
// 005edeeb  8d542440             lea edx, [esp + 0x40]
// 005edeef  52                   push edx
// 005edef0  8d8c2430010000       lea ecx, [esp + 0x130]
// 005edef7  e844630400           call 0x634240
// 005edefc  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005edf03  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005edf0a  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005edf11  89442478             mov dword ptr [esp + 0x78], eax
// 005edf15  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005edf1c  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005edf20  89942480000000       mov dword ptr [esp + 0x80], edx
// 005edf27  89842484000000       mov dword ptr [esp + 0x84], eax
// 005edf2e  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005edf34  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005edf3b  8b442460             mov eax, dword ptr [esp + 0x60]
// 005edf3f  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005edf46  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005edf4f  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005edf55  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005edf5e  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005edf64  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005edf6d  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005edf73  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005edf7c  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005edf82  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005edf8b  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005edf91  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005edf98  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005edf9c  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005edfa5  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005edfab  89842490000000       mov dword ptr [esp + 0x90], eax
// 005edfb2  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005edfb9  8b542468             mov edx, dword ptr [esp + 0x68]
// 005edfbd  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005edfc4  8d442478             lea eax, [esp + 0x78]
// 005edfc8  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005edfd1  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005edfd7  8d8e88000000         lea ecx, [esi + 0x88]
// 005edfdd  50                   push eax
// 005edfde  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005edfe5  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005edfee  894c2460             mov dword ptr [esp + 0x60], ecx
// 005edff2  e8c9c2ffff           call 0x5ea2c0
// 005edff7  d94710               fld dword ptr [edi + 0x10]
// 005edffa  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005ee003  d99eac000000         fstp dword ptr [esi + 0xac]
// 005ee009  d94714               fld dword ptr [edi + 0x14]
// 005ee00c  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005ee012  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005ee01b  d99eb0000000         fstp dword ptr [esi + 0xb0]
// 005ee021  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005ee027  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005ee030  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005ee037  51                   push ecx
// 005ee038  8d542464             lea edx, [esp + 0x64]
// 005ee03c  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005ee042  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005ee04b  52                   push edx
// 005ee04c  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005ee052  e899952300           call 0x8275f0
// 005ee057  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005ee05e  50                   push eax
// 005ee05f  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005ee066  51                   push ecx
// 005ee067  e884952300           call 0x8275f0
// 005ee06c  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ee072  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ee079  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005ee082  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ee088  8d9424d0000000       lea edx, [esp + 0xd0]
// 005ee08f  52                   push edx
// 005ee090  8d8424ec000000       lea eax, [esp + 0xec]
// 005ee097  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005ee0a0  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ee0a6  50                   push eax
// 005ee0a7  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005ee0b0  e83b952300           call 0x8275f0
// 005ee0b5  83c418               add esp, 0x18
// 005ee0b8  8d4c2440             lea ecx, [esp + 0x40]
// 005ee0bc  51                   push ecx
// 005ee0bd  8d8c2420010000       lea ecx, [esp + 0x120]
// 005ee0c4  e877610400           call 0x634240
// 005ee0c9  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005ee0d0  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005ee0d7  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005ee0de  89542478             mov dword ptr [esp + 0x78], edx
// 005ee0e2  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005ee0e9  8944247c             mov dword ptr [esp + 0x7c], eax
// 005ee0ed  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005ee0f4  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005ee0fb  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005ee102  89942484000000       mov dword ptr [esp + 0x84], edx
// 005ee109  89842488000000       mov dword ptr [esp + 0x88], eax
// 005ee110  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005ee116  8b542460             mov edx, dword ptr [esp + 0x60]
// 005ee11a  8b442464             mov eax, dword ptr [esp + 0x64]
// 005ee11e  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005ee127  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005ee12d  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005ee136  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005ee13c  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005ee145  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005ee14b  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005ee154  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005ee15a  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005ee163  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005ee169  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005ee170  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005ee174  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005ee17d  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005ee183  89942490000000       mov dword ptr [esp + 0x90], edx
// 005ee18a  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005ee191  8d542478             lea edx, [esp + 0x78]
// 005ee195  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005ee19e  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ee1a4  8d8ecc000000         lea ecx, [esi + 0xcc]
// 005ee1aa  52                   push edx
// 005ee1ab  89842498000000       mov dword ptr [esp + 0x98], eax
// 005ee1b2  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005ee1bb  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005ee1c2  e8f9c0ffff           call 0x5ea2c0
// 005ee1c7  d94718               fld dword ptr [edi + 0x18]
// 005ee1ca  d99ef0000000         fstp dword ptr [esi + 0xf0]
// 005ee1d0  56                   push esi
// 005ee1d1  d9471c               fld dword ptr [edi + 0x1c]
// 005ee1d4  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005ee1d7  8b07                 mov eax, dword ptr [edi]
// 005ee1d9  d99ef4000000         fstp dword ptr [esi + 0xf4]
// 005ee1df  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ee1e2  8bcf                 mov ecx, edi
// 005ee1e4  ffd2                 call edx
// 005ee1e6  8bf0                 mov esi, eax
// 005ee1e8  8b07                 mov eax, dword ptr [edi]
// 005ee1ea  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ee1ed  53                   push ebx
// 005ee1ee  8bcf                 mov ecx, edi
// 005ee1f0  ffd2                 call edx
// 005ee1f2  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005ee1f6  8bd8                 mov ebx, eax
// 005ee1f8  8b07                 mov eax, dword ptr [edi]
// 005ee1fa  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ee1fd  51                   push ecx
// 005ee1fe  8bcf                 mov ecx, edi
// 005ee200  ffd2                 call edx
// 005ee202  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005ee209  8944243c             mov dword ptr [esp + 0x3c], eax
// 005ee20d  8b07                 mov eax, dword ptr [edi]
// 005ee20f  8b5010               mov edx, dword ptr [eax + 0x10]
// 005ee212  51                   push ecx
// 005ee213  8bcf                 mov ecx, edi
// 005ee215  ffd2                 call edx
// 005ee217  8b17                 mov edx, dword ptr [edi]
// 005ee219  8b5218               mov edx, dword ptr [edx + 0x18]
// 005ee21c  50                   push eax
// 005ee21d  89442460             mov dword ptr [esp + 0x60], eax
// 005ee221  8b442440             mov eax, dword ptr [esp + 0x40]
// 005ee225  50                   push eax
// 005ee226  53                   push ebx
// 005ee227  56                   push esi
// 005ee228  8bcf                 mov ecx, edi
// 005ee22a  ffd2                 call edx
// 005ee22c  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005ee22f  85c0                 test eax, eax
// 005ee231  7413                 je 0x5ee246
// 005ee233  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005ee237  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005ee23b  8930                 mov dword ptr [eax], esi
// 005ee23d  895804               mov dword ptr [eax + 4], ebx
// 005ee240  894808               mov dword ptr [eax + 8], ecx
// 005ee243  89500c               mov dword ptr [eax + 0xc], edx
// 005ee246  5f                   pop edi
// 005ee247  5e                   pop esi
// 005ee248  5b                   pop ebx
// 005ee249  8be5                 mov esp, ebp
// 005ee24b  5d                   pop ebp
// 005ee24c  c22000               ret 0x20
// 005ee24f  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005ee256  743c                 je 0x5ee294
// 005ee258  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005ee25c  7536                 jne 0x5ee294
// 005ee25e  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005ee263  85c0                 test eax, eax
// 005ee265  7418                 je 0x5ee27f
// 005ee267  6801010000           push 0x101
// 005ee26c  688027b800           push 0xb82780
// 005ee271  680027b800           push 0xb82700
// 005ee276  ffd0                 call eax
// 005ee278  83c40c               add esp, 0xc
// 005ee27b  84c0                 test al, al
// 005ee27d  7515                 jne 0x5ee294
// 005ee27f  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005ee286  688826b800           push 0xb82688
// 005ee28b  50                   push eax
// 005ee28c  e8ff3f3800           call 0x972290
// 005ee291  83c408               add esp, 8
// 005ee294  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005ee29a  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ee2a1  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005ee2a9  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005ee2b1  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005ee2b6  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005ee2bc  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005ee2c4  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005ee2c9  8d4c2460             lea ecx, [esp + 0x60]
// 005ee2cd  51                   push ecx
// 005ee2ce  f30f59c2             mulss xmm0, xmm2
// 005ee2d2  f30f59ca             mulss xmm1, xmm2
// 005ee2d6  8d4c2420             lea ecx, [esp + 0x20]
// 005ee2da  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005ee2e3  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005ee2ec  e84f5f0400           call 0x634240
// 005ee2f1  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005ee2fa  f30f5e00             divss xmm0, dword ptr [eax]
// 005ee2fe  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005ee303  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005ee306  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005ee309  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005ee30e  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005ee316  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005ee31c  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005ee325  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005ee32e  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005ee333  33d2                 xor edx, edx
// 005ee335  33db                 xor ebx, ebx
// 005ee337  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005ee340  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005ee347  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005ee34e  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005ee354  0f2fd7               comiss xmm2, xmm7
// 005ee357  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005ee35d  8954243c             mov dword ptr [esp + 0x3c], edx
// 005ee361  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005ee36a  770a                 ja 0x5ee376
// 005ee36c  85d2                 test edx, edx
// 005ee36e  0f85d2feffff         jne 0x5ee246
// 005ee374  eb04                 jmp 0x5ee37a
// 005ee376  85d2                 test edx, edx
// 005ee378  7504                 jne 0x5ee37e
// 005ee37a  f30f5cc4             subss xmm0, xmm4
// 005ee37e  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005ee382  80797000             cmp byte ptr [ecx + 0x70], 0
// 005ee386  7421                 je 0x5ee3a9
// 005ee388  f30f58c7             addss xmm0, xmm7
// 005ee38c  0f2fc2               comiss xmm0, xmm2
// 005ee38f  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005ee398  8d44241c             lea eax, [esp + 0x1c]
// 005ee39c  7707                 ja 0x5ee3a5
// 005ee39e  8d84240c030000       lea eax, [esp + 0x30c]
// 005ee3a5  f30f1010             movss xmm2, dword ptr [eax]
// 005ee3a9  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005ee3b2  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005ee3b8  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005ee3bf  f30f58cb             addss xmm1, xmm3
// 005ee3c3  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005ee3c8  33c0                 xor eax, eax
// 005ee3ca  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005ee3d0  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005ee3d9  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005ee3e0  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005ee3e6  0f2ff0               comiss xmm6, xmm0
// 005ee3e9  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005ee3f2  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005ee3f8  7708                 ja 0x5ee402
// 005ee3fa  85c0                 test eax, eax
// 005ee3fc  0f852b110000         jne 0x5ef52d
// 005ee402  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005ee408  85c0                 test eax, eax
// 005ee40a  7504                 jne 0x5ee410
// 005ee40c  f30f5ccc             subss xmm1, xmm4
// 005ee410  0f28f1               movaps xmm6, xmm1
// 005ee413  f30f58f0             addss xmm6, xmm0
// 005ee417  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005ee41c  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005ee425  8d442420             lea eax, [esp + 0x20]
// 005ee429  7707                 ja 0x5ee432
// 005ee42b  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005ee432  80797000             cmp byte ptr [ecx + 0x70], 0
// 005ee436  f30f1000             movss xmm0, dword ptr [eax]
// 005ee43a  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005ee440  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005ee449  f30f58c3             addss xmm0, xmm3
// 005ee44d  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005ee456  0f57c0               xorps xmm0, xmm0
// 005ee459  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005ee45f  740f                 je 0x5ee470
// 005ee461  e82abeffff           call 0x5ea290
// 005ee466  d80d94deb600         fmul dword ptr [0xb6de94]
// 005ee46c  d95c2440             fstp dword ptr [esp + 0x40]
// 005ee470  0f28dd               movaps xmm3, xmm5
// 005ee473  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005ee47c  0f28c3               movaps xmm0, xmm3
// 005ee47f  f30f59c4             mulss xmm0, xmm4
// 005ee483  f30f5cd7             subss xmm2, xmm7
// 005ee487  f30f59d3             mulss xmm2, xmm3
// 005ee48b  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005ee491  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005ee497  f30f58d3             addss xmm2, xmm3
// 005ee49b  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005ee4a1  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005ee4a7  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005ee4ad  0f28c5               movaps xmm0, xmm5
// 005ee4b0  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005ee4b9  0f28e9               movaps xmm5, xmm1
// 005ee4bc  0f28f0               movaps xmm6, xmm0
// 005ee4bf  f30f59f4             mulss xmm6, xmm4
// 005ee4c3  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005ee4c9  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005ee4cf  f30f5ccb             subss xmm1, xmm3
// 005ee4d3  f30f59e8             mulss xmm5, xmm0
// 005ee4d7  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005ee4dd  f30f59c8             mulss xmm1, xmm0
// 005ee4e1  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005ee4e7  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005ee4f0  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005ee4f9  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005ee502  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005ee50b  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005ee514  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005ee51d  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005ee526  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005ee52f  85d2                 test edx, edx
// 005ee531  753f                 jne 0x5ee572
// 005ee533  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005ee539  0f28c4               movaps xmm0, xmm4
// 005ee53c  f30f58c3             addss xmm0, xmm3
// 005ee540  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005ee549  0f28c3               movaps xmm0, xmm3
// 005ee54c  f30f58c2             addss xmm0, xmm2
// 005ee550  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005ee559  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005ee562  0f28c4               movaps xmm0, xmm4
// 005ee565  f30f58c3             addss xmm0, xmm3
// 005ee569  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005ee572  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005ee578  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005ee57d  772f                 ja 0x5ee5ae
// 005ee57f  0f28c6               movaps xmm0, xmm6
// 005ee582  f30f58c5             addss xmm0, xmm5
// 005ee586  f30f58f1             addss xmm6, xmm1
// 005ee58a  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005ee593  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005ee59c  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005ee5a5  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005ee5ae  8d9424cc000000       lea edx, [esp + 0xcc]
// 005ee5b5  52                   push edx
// 005ee5b6  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ee5bd  e87e5c0400           call 0x634240
// 005ee5c2  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005ee5c7  f30f1008             movss xmm1, dword ptr [eax]
// 005ee5cb  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005ee5d1  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005ee5d7  8d8424d8000000       lea eax, [esp + 0xd8]
// 005ee5de  50                   push eax
// 005ee5df  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ee5e6  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005ee5ef  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005ee5f8  e8435c0400           call 0x634240
// 005ee5fd  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005ee602  f30f1008             movss xmm1, dword ptr [eax]
// 005ee606  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005ee60c  f30f584c244c         addss xmm1, dword ptr [esp + 0x4c]
// 005ee612  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005ee619  51                   push ecx
// 005ee61a  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ee621  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005ee62a  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005ee633  e8085c0400           call 0x634240
// 005ee638  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005ee63e  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005ee643  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005ee649  f30f5c08             subss xmm1, dword ptr [eax]
// 005ee64d  8d94248c010000       lea edx, [esp + 0x18c]
// 005ee654  52                   push edx
// 005ee655  8d8c2444010000       lea ecx, [esp + 0x144]
// 005ee65c  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005ee665  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005ee66e  e8cd5b0400           call 0x634240
// 005ee673  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005ee679  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005ee67e  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005ee684  f30f5c08             subss xmm1, dword ptr [eax]
// 005ee688  8d842498010000       lea eax, [esp + 0x198]
// 005ee68f  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005ee698  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ee6a0  50                   push eax
// 005ee6a1  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005ee6a8  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005ee6ae  0f57c0               xorps xmm0, xmm0
// 005ee6b1  51                   push ecx
// 005ee6b2  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005ee6b9  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005ee6c2  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005ee6c8  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005ee6ce  e83d5b0400           call 0x634210
// 005ee6d3  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005ee6dc  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005ee6e5  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005ee6ee  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005ee6f7  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005ee700  8d9424ec000000       lea edx, [esp + 0xec]
// 005ee707  52                   push edx
// 005ee708  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005ee70f  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005ee718  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005ee721  50                   push eax
// 005ee722  8d8c2484010000       lea ecx, [esp + 0x184]
// 005ee729  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005ee732  e8d95a0400           call 0x634210
// 005ee737  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005ee740  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005ee746  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005ee74f  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005ee755  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005ee75e  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005ee764  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005ee76d  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005ee773  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005ee77c  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005ee785  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005ee78e  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005ee797  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005ee7a0  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005ee7a9  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005ee7b2  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005ee7bb  8d4c246c             lea ecx, [esp + 0x6c]
// 005ee7bf  51                   push ecx
// 005ee7c0  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005ee7c7  52                   push edx
// 005ee7c8  e8238e2300           call 0x8275f0
// 005ee7cd  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005ee7d6  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005ee7df  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005ee7e8  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005ee7ef  50                   push eax
// 005ee7f0  8d8c2484030000       lea ecx, [esp + 0x384]
// 005ee7f7  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005ee800  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ee808  51                   push ecx
// 005ee809  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005ee812  e8d98d2300           call 0x8275f0
// 005ee817  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005ee81d  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005ee826  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005ee82c  8d942470030000       lea edx, [esp + 0x370]
// 005ee833  52                   push edx
// 005ee834  8d842450030000       lea eax, [esp + 0x350]
// 005ee83b  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005ee844  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005ee84a  50                   push eax
// 005ee84b  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005ee854  e8978d2300           call 0x8275f0
// 005ee859  83c418               add esp, 0x18
// 005ee85c  8d8c2430030000       lea ecx, [esp + 0x330]
// 005ee863  51                   push ecx
// 005ee864  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005ee86b  e8d0590400           call 0x634240
// 005ee870  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005ee879  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005ee880  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005ee887  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005ee88e  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005ee897  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005ee8a0  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005ee8a9  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005ee8b2  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005ee8bb  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005ee8c4  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005ee8cd  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005ee8d6  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005ee8df  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005ee8e8  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005ee8f1  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005ee8fa  89942448020000       mov dword ptr [esp + 0x248], edx
// 005ee901  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005ee908  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005ee911  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005ee91a  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005ee921  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005ee928  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005ee931  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005ee93a  89942454020000       mov dword ptr [esp + 0x254], edx
// 005ee941  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005ee948  89842458020000       mov dword ptr [esp + 0x258], eax
// 005ee94f  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005ee956  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005ee95f  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005ee968  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005ee96f  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005ee976  89942460020000       mov dword ptr [esp + 0x260], edx
// 005ee97d  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005ee986  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005ee98f  8d54246c             lea edx, [esp + 0x6c]
// 005ee993  89842464020000       mov dword ptr [esp + 0x264], eax
// 005ee99a  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005ee9a1  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005ee9a8  52                   push edx
// 005ee9a9  8d842470030000       lea eax, [esp + 0x370]
// 005ee9b0  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005ee9b9  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005ee9c2  50                   push eax
// 005ee9c3  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005ee9ca  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005ee9d3  e8188c2300           call 0x8275f0
// 005ee9d8  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005ee9e1  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005ee9ea  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005ee9f3  8d8c2498030000       lea ecx, [esp + 0x398]
// 005ee9fa  51                   push ecx
// 005ee9fb  8d942460030000       lea edx, [esp + 0x360]
// 005eea02  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005eea0b  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005eea13  52                   push edx
// 005eea14  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005eea1d  e8ce8b2300           call 0x8275f0
// 005eea22  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005eea28  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005eea31  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005eea37  8d842400040000       lea eax, [esp + 0x400]
// 005eea3e  50                   push eax
// 005eea3f  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005eea46  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005eea4f  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005eea55  51                   push ecx
// 005eea56  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005eea5f  e88c8b2300           call 0x8275f0
// 005eea64  83c418               add esp, 0x18
// 005eea67  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005eea6e  52                   push edx
// 005eea6f  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005eea76  e8c5570400           call 0x634240
// 005eea7b  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005eea84  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005eea8b  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005eea92  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005eea99  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005eeaa2  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005eeaab  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005eeab4  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005eeabd  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005eeac6  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005eeacf  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005eead8  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005eeae1  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005eeaea  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005eeaf3  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005eeafc  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005eeb05  89842490020000       mov dword ptr [esp + 0x290], eax
// 005eeb0c  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005eeb13  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005eeb1c  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005eeb25  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005eeb2c  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005eeb33  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005eeb3c  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005eeb45  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005eeb4c  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005eeb53  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005eeb5a  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005eeb61  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005eeb6a  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005eeb73  89942498020000       mov dword ptr [esp + 0x298], edx
// 005eeb7a  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005eeb81  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005eeb88  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005eeb91  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005eeb9a  8d44246c             lea eax, [esp + 0x6c]
// 005eeb9e  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005eeba5  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005eebac  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005eebb3  50                   push eax
// 005eebb4  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005eebbb  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005eebc4  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005eebcd  51                   push ecx
// 005eebce  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005eebd5  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005eebde  e80d8a2300           call 0x8275f0
// 005eebe3  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005eebec  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005eebf5  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005eebfe  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005eec07  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005eec0f  8d94248c030000       lea edx, [esp + 0x38c]
// 005eec16  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005eec1f  52                   push edx
// 005eec20  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005eec27  50                   push eax
// 005eec28  e8c3892300           call 0x8275f0
// 005eec2d  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005eec33  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005eec3c  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005eec42  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005eec49  51                   push ecx
// 005eec4a  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005eec51  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005eec5a  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005eec60  52                   push edx
// 005eec61  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005eec6a  e881892300           call 0x8275f0
// 005eec6f  83c418               add esp, 0x18
// 005eec72  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005eec79  50                   push eax
// 005eec7a  8d8c2480010000       lea ecx, [esp + 0x180]
// 005eec81  e8ba550400           call 0x634240
// 005eec86  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005eec8f  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005eec96  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005eec9d  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005eeca4  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005eecad  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005eecb6  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005eecbf  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005eecc8  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005eecd1  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005eecda  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005eece3  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005eecec  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005eecf5  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005eecfe  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005eed07  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 005eed10  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 005eed17  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 005eed1e  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 005eed27  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 005eed30  89942404020000       mov dword ptr [esp + 0x204], edx
// 005eed37  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 005eed3e  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 005eed47  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005eed4d  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 005eed54  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 005eed5b  89942410020000       mov dword ptr [esp + 0x210], edx
// 005eed62  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 005eed69  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 005eed72  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005eed78  89842408020000       mov dword ptr [esp + 0x208], eax
// 005eed7f  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 005eed86  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 005eed8d  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005eed96  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005eed9c  8d4c246c             lea ecx, [esp + 0x6c]
// 005eeda0  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 005eeda7  89842414020000       mov dword ptr [esp + 0x214], eax
// 005eedae  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 005eedb5  51                   push ecx
// 005eedb6  8d942410010000       lea edx, [esp + 0x110]
// 005eedbd  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 005eedc6  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005eedcc  52                   push edx
// 005eedcd  89842428020000       mov dword ptr [esp + 0x228], eax
// 005eedd4  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005eeddd  e80e882300           call 0x8275f0
// 005eede2  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005eedeb  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 005eedf4  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005eedfd  8d842404040000       lea eax, [esp + 0x404]
// 005eee04  50                   push eax
// 005eee05  8d8c2438010000       lea ecx, [esp + 0x138]
// 005eee0c  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 005eee15  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005eee1d  51                   push ecx
// 005eee1e  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 005eee27  e8c4872300           call 0x8275f0
// 005eee2c  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005eee32  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 005eee3b  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005eee41  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005eee4a  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005eee50  8d9424b8030000       lea edx, [esp + 0x3b8]
// 005eee57  52                   push edx
// 005eee58  8d842430010000       lea eax, [esp + 0x130]
// 005eee5f  50                   push eax
// 005eee60  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 005eee69  e882872300           call 0x8275f0
// 005eee6e  83c418               add esp, 0x18
// 005eee71  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 005eee78  51                   push ecx
// 005eee79  8d4c242c             lea ecx, [esp + 0x2c]
// 005eee7d  e8be530400           call 0x634240
// 005eee82  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 005eee8b  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 005eee92  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 005eee99  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 005eeea0  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005eeea9  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 005eeeb2  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005eeebb  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 005eeec4  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005eeecd  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 005eeed6  89542478             mov dword ptr [esp + 0x78], edx
// 005eeeda  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 005eeee1  8944247c             mov dword ptr [esp + 0x7c], eax
// 005eeee5  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005eeeec  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005eeef5  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 005eeefe  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005eef05  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 005eef0c  89942484000000       mov dword ptr [esp + 0x84], edx
// 005eef13  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 005eef1a  89842488000000       mov dword ptr [esp + 0x88], eax
// 005eef21  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 005eef28  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005eef31  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 005eef3a  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005eef41  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 005eef48  89942490000000       mov dword ptr [esp + 0x90], edx
// 005eef4f  8b17                 mov edx, dword ptr [edi]
// 005eef51  8b5210               mov edx, dword ptr [edx + 0x10]
// 005eef54  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005eef5d  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 005eef66  89842494000000       mov dword ptr [esp + 0x94], eax
// 005eef6d  8d842448020000       lea eax, [esp + 0x248]
// 005eef74  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005eef7b  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005eef84  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 005eef8d  50                   push eax
// 005eef8e  8bcf                 mov ecx, edi
// 005eef90  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005eef99  ffd2                 call edx
// 005eef9b  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 005eefa2  8b07                 mov eax, dword ptr [edi]
// 005eefa4  8b5010               mov edx, dword ptr [eax + 0x10]
// 005eefa7  8d8c2490020000       lea ecx, [esp + 0x290]
// 005eefae  51                   push ecx
// 005eefaf  8bcf                 mov ecx, edi
// 005eefb1  ffd2                 call edx
// 005eefb3  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 005eefba  8b07                 mov eax, dword ptr [edi]
// 005eefbc  8b5010               mov edx, dword ptr [eax + 0x10]
// 005eefbf  8d8c2400020000       lea ecx, [esp + 0x200]
// 005eefc6  51                   push ecx
// 005eefc7  8bcf                 mov ecx, edi
// 005eefc9  ffd2                 call edx
// 005eefcb  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 005eefd2  8b07                 mov eax, dword ptr [edi]
// 005eefd4  8b5010               mov edx, dword ptr [eax + 0x10]
// 005eefd7  8d4c2478             lea ecx, [esp + 0x78]
// 005eefdb  51                   push ecx
// 005eefdc  8bcf                 mov ecx, edi
// 005eefde  ffd2                 call edx
// 005eefe0  89842460010000       mov dword ptr [esp + 0x160], eax
// 005eefe7  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005eefee  40                   inc eax
// 005eefef  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005eeff6  3bc3                 cmp eax, ebx
// 005eeff8  8d84246c010000       lea eax, [esp + 0x16c]
// 005eefff  7c07                 jl 0x5ef008
// 005ef001  8d8424e8000000       lea eax, [esp + 0xe8]
// 005ef008  8b18                 mov ebx, dword ptr [eax]
// 005ef00a  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 005ef011  8bc8                 mov ecx, eax
// 005ef013  40                   inc eax
// 005ef014  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005ef01b  85c9                 test ecx, ecx
// 005ef01d  0f85f9000000         jne 0x5ef11c
// 005ef023  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 005ef02a  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005ef02d  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 005ef036  8911                 mov dword ptr [ecx], edx
// 005ef038  f30f1106             movss dword ptr [esi], xmm0
// 005ef03c  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 005ef045  f30f114604           movss dword ptr [esi + 4], xmm0
// 005ef04a  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 005ef053  f30f114608           movss dword ptr [esi + 8], xmm0
// 005ef058  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 005ef061  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 005ef066  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 005ef06f  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 005ef074  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 005ef07d  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 005ef082  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 005ef08b  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 005ef090  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 005ef099  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 005ef09e  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 005ef0a7  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 005ef0ac  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 005ef0b5  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 005ef0ba  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 005ef0c3  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 005ef0c8  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 005ef0d1  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 005ef0d6  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 005ef0df  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 005ef0e4  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 005ef0ed  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 005ef0f2  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 005ef0fb  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 005ef100  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 005ef109  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 005ef10e  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 005ef117  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 005ef11c  8bd3                 mov edx, ebx
// 005ef11e  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 005ef123  8d0c9501000000       lea ecx, [edx*4 + 1]
// 005ef12a  8bd0                 mov edx, eax
// 005ef12c  40                   inc eax
// 005ef12d  3bd1                 cmp edx, ecx
// 005ef12f  0f8501010000         jne 0x5ef236
// 005ef135  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005ef13c  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005ef13f  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 005ef148  894a04               mov dword ptr [edx + 4], ecx
// 005ef14b  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 005ef150  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 005ef159  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 005ef15e  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 005ef167  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 005ef16c  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 005ef175  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 005ef17a  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 005ef183  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 005ef188  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 005ef191  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 005ef196  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 005ef19f  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 005ef1a4  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 005ef1ad  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 005ef1b2  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 005ef1bb  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 005ef1c0  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 005ef1c9  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 005ef1ce  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 005ef1d7  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 005ef1dc  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 005ef1e5  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 005ef1ea  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 005ef1f3  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 005ef1f8  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 005ef201  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 005ef206  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 005ef20f  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 005ef214  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 005ef21d  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 005ef225  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 005ef22e  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 005ef236  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005ef23a  41                   inc ecx
// 005ef23b  0fafcb               imul ecx, ebx
// 005ef23e  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 005ef245  8bc8                 mov ecx, eax
// 005ef247  40                   inc eax
// 005ef248  3bca                 cmp ecx, edx
// 005ef24a  0f852e010000         jne 0x5ef37e
// 005ef250  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 005ef257  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005ef25a  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005ef263  895108               mov dword ptr [ecx + 8], edx
// 005ef266  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 005ef26e  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 005ef277  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 005ef27f  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 005ef288  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 005ef290  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 005ef299  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 005ef2a1  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 005ef2aa  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 005ef2b2  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 005ef2bb  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 005ef2c3  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 005ef2cc  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 005ef2d4  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 005ef2dd  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 005ef2e5  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 005ef2ee  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 005ef2f6  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 005ef2ff  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 005ef307  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 005ef310  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 005ef318  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 005ef321  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 005ef329  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 005ef332  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 005ef33a  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 005ef343  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 005ef34b  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 005ef354  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 005ef35c  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 005ef365  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 005ef36d  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 005ef376  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 005ef37e  8bc8                 mov ecx, eax
// 005ef380  8d149dffffffff       lea edx, [ebx*4 - 1]
// 005ef387  40                   inc eax
// 005ef388  89842478010000       mov dword ptr [esp + 0x178], eax
// 005ef38f  3bca                 cmp ecx, edx
// 005ef391  0f8528010000         jne 0x5ef4bf
// 005ef397  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005ef39a  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005ef3a1  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 005ef3a7  89420c               mov dword ptr [edx + 0xc], eax
// 005ef3aa  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 005ef3b2  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 005ef3b8  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 005ef3c0  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 005ef3c9  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 005ef3d1  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 005ef3da  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 005ef3e2  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 005ef3eb  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 005ef3f3  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 005ef3fc  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 005ef404  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 005ef40d  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 005ef415  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 005ef41e  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 005ef426  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 005ef42f  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 005ef437  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 005ef440  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 005ef448  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 005ef451  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 005ef459  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 005ef462  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 005ef46a  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 005ef473  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 005ef47b  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 005ef484  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 005ef48c  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 005ef495  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 005ef49d  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 005ef4a6  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 005ef4ae  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 005ef4b7  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 005ef4bf  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005ef4c6  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005ef4cd  8b17                 mov edx, dword ptr [edi]
// 005ef4cf  8b5218               mov edx, dword ptr [edx + 0x18]
// 005ef4d2  50                   push eax
// 005ef4d3  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 005ef4da  51                   push ecx
// 005ef4db  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 005ef4e2  50                   push eax
// 005ef4e3  51                   push ecx
// 005ef4e4  8bcf                 mov ecx, edi
// 005ef4e6  ffd2                 call edx
// 005ef4e8  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005ef4ee  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 005ef4f7  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005ef4ff  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 005ef508  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 005ef50e  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005ef514  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005ef519  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005ef520  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005ef524  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005ef528  e9b3eeffff           jmp 0x5ee3e0
// 005ef52d  0f28fa               movaps xmm7, xmm2
// 005ef530  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 005ef536  0f28d9               movaps xmm3, xmm1
// 005ef539  42                   inc edx
// 005ef53a  e90feeffff           jmp 0x5ee34e
// 005ef53f  90                   nop 
// 005ef540  b1d7                 mov cl, 0xd7
// 005ef542  5e                   pop esi
// 005ef543  001cd9               add byte ptr [ecx + ebx*8], bl
// 005ef546  5e                   pop esi
// 005ef547  0008                 add byte ptr [eax], cl
// 005ef549  d85e00               fcomp dword ptr [esi]
// 005ef54c  ce                   into 
// 005ef54d  d85e00               fcomp dword ptr [esi]
// 005ef550  46                   inc esi
// 005ef551  d85e00               fcomp dword ptr [esi]
// 005ef554  8ad8                 mov bl, al
// 005ef556  5e                   pop esi

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
