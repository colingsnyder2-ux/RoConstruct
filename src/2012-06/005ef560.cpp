// from server: 10% by intel
// roc 2012-06 005ef560  unit: seg_005e0000  size: 7848 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ef560
//
// 005ef560  55                   push ebp
// 005ef561  8bec                 mov ebp, esp
// 005ef563  83e4f8               and esp, 0xfffffff8
// 005ef566  81ecfc030000         sub esp, 0x3fc
// 005ef56c  53                   push ebx
// 005ef56d  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005ef570  56                   push esi
// 005ef571  57                   push edi
// 005ef572  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005ef575  8d44246c             lea eax, [esp + 0x6c]
// 005ef579  8bf1                 mov esi, ecx
// 005ef57b  53                   push ebx
// 005ef57c  c1ef06               shr edi, 6
// 005ef57f  50                   push eax
// 005ef580  89742464             mov dword ptr [esp + 0x64], esi
// 005ef584  83e707               and edi, 7
// 005ef587  e894802300           call 0x827620
// 005ef58c  d9442474             fld dword ptr [esp + 0x74]
// 005ef590  d9e1                 fabs 
// 005ef592  8d4c2474             lea ecx, [esp + 0x74]
// 005ef596  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005ef59d  53                   push ebx
// 005ef59e  d944247c             fld dword ptr [esp + 0x7c]
// 005ef5a2  51                   push ecx
// 005ef5a3  d9e1                 fabs 
// 005ef5a5  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005ef5ac  d9842484000000       fld dword ptr [esp + 0x84]
// 005ef5b3  d9e1                 fabs 
// 005ef5b5  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005ef5bc  e85f802300           call 0x827620
// 005ef5c1  d944247c             fld dword ptr [esp + 0x7c]
// 005ef5c5  8a4670               mov al, byte ptr [esi + 0x70]
// 005ef5c8  d9e1                 fabs 
// 005ef5ca  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005ef5d2  d9842480000000       fld dword ptr [esp + 0x80]
// 005ef5d9  83c410               add esp, 0x10
// 005ef5dc  d9e1                 fabs 
// 005ef5de  d9442474             fld dword ptr [esp + 0x74]
// 005ef5e2  d9e1                 fabs 
// 005ef5e4  d9450c               fld dword ptr [ebp + 0xc]
// 005ef5e7  dceb                 fsub st(3), st(0)
// 005ef5e9  d9cb                 fxch st(3)
// 005ef5eb  d95c241c             fstp dword ptr [esp + 0x1c]
// 005ef5ef  d9c9                 fxch st(1)
// 005ef5f1  dee2                 fsubrp st(2)
// 005ef5f3  d9c9                 fxch st(1)
// 005ef5f5  d95c2420             fstp dword ptr [esp + 0x20]
// 005ef5f9  d95c2424             fstp dword ptr [esp + 0x24]
// 005ef5fd  84c0                 test al, al
// 005ef5ff  741b                 je 0x5ef61c
// 005ef601  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005ef609  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005ef612  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005ef61a  eb11                 jmp 0x5ef62d
// 005ef61c  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005ef624  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005ef62d  0f57e4               xorps xmm4, xmm4
// 005ef630  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005ef639  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005ef63f  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005ef645  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005ef64b  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005ef651  83ff05               cmp edi, 5
// 005ef654  0f87a4010000         ja 0x5ef7fe
// 005ef65a  ff24bdf0135f00       jmp dword ptr [edi*4 + 0x5f13f0]
// 005ef661  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005ef669  8d542460             lea edx, [esp + 0x60]
// 005ef66d  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005ef673  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005ef67b  52                   push edx
// 005ef67c  8d4c2420             lea ecx, [esp + 0x20]
// 005ef680  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005ef686  e8b54b0400           call 0x634240
// 005ef68b  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005ef693  f30f1000             movss xmm0, dword ptr [eax]
// 005ef697  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005ef69c  0f57e4               xorps xmm4, xmm4
// 005ef69f  f30f59c5             mulss xmm0, xmm5
// 005ef6a3  f30f59cd             mulss xmm1, xmm5
// 005ef6a7  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005ef6ad  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005ef6b3  e946010000           jmp 0x5ef7fe
// 005ef6b8  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005ef6c0  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005ef6c6  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005ef6cc  84c0                 test al, al
// 005ef6ce  7413                 je 0x5ef6e3
// 005ef6d0  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005ef6d8  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ef6de  e91b010000           jmp 0x5ef7fe
// 005ef6e3  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005ef6eb  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ef6f1  e908010000           jmp 0x5ef7fe
// 005ef6f6  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005ef6fc  84c0                 test al, al
// 005ef6fe  7419                 je 0x5ef719
// 005ef700  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005ef708  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005ef70e  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ef714  e9e5000000           jmp 0x5ef7fe
// 005ef719  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005ef721  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005ef727  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005ef72f  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ef735  e9c4000000           jmp 0x5ef7fe
// 005ef73a  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005ef740  84c0                 test al, al
// 005ef742  7419                 je 0x5ef75d
// 005ef744  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005ef74c  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005ef752  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ef758  e9a1000000           jmp 0x5ef7fe
// 005ef75d  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005ef765  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005ef76b  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005ef773  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ef779  e980000000           jmp 0x5ef7fe
// 005ef77e  84c0                 test al, al
// 005ef780  745a                 je 0x5ef7dc
// 005ef782  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005ef789  7441                 je 0x5ef7cc
// 005ef78b  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005ef790  85c0                 test eax, eax
// 005ef792  7418                 je 0x5ef7ac
// 005ef794  68b7000000           push 0xb7
// 005ef799  688027b800           push 0xb82780
// 005ef79e  68cc60b400           push 0xb460cc
// 005ef7a3  ffd0                 call eax
// 005ef7a5  83c40c               add esp, 0xc
// 005ef7a8  84c0                 test al, al
// 005ef7aa  7515                 jne 0x5ef7c1
// 005ef7ac  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005ef7b3  680827b800           push 0xb82708
// 005ef7b8  50                   push eax
// 005ef7b9  e8d22a3800           call 0x972290
// 005ef7be  83c408               add esp, 8
// 005ef7c1  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005ef7c9  0f57e4               xorps xmm4, xmm4
// 005ef7cc  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005ef7d4  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005ef7da  eb1c                 jmp 0x5ef7f8
// 005ef7dc  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005ef7e4  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005ef7ea  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005ef7f2  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005ef7f8  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005ef7fe  807e7000             cmp byte ptr [esi + 0x70], 0
// 005ef802  7419                 je 0x5ef81d
// 005ef804  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005ef809  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005ef811  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005ef817  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005ef81d  85ff                 test edi, edi
// 005ef81f  0f85da080000         jne 0x5f00ff
// 005ef825  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005ef82d  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005ef832  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005ef83a  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005ef83f  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005ef845  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005ef84e  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005ef856  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005ef85c  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005ef865  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005ef86e  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005ef877  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005ef880  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005ef889  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005ef892  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005ef89b  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005ef8a4  f30f59c5             mulss xmm0, xmm5
// 005ef8a8  f30f59cd             mulss xmm1, xmm5
// 005ef8ac  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005ef8b5  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005ef8be  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005ef8c3  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005ef8cc  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005ef8d5  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005ef8dc  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005ef8e2  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005ef8eb  0f28e3               movaps xmm4, xmm3
// 005ef8ee  f30f5ce0             subss xmm4, xmm0
// 005ef8f2  0f28eb               movaps xmm5, xmm3
// 005ef8f5  f30f5ce9             subss xmm5, xmm1
// 005ef8f9  51                   push ecx
// 005ef8fa  8d542464             lea edx, [esp + 0x64]
// 005ef8fe  f30f5cc3             subss xmm0, xmm3
// 005ef902  0f28d3               movaps xmm2, xmm3
// 005ef905  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005ef90c  f30f5ccb             subss xmm1, xmm3
// 005ef910  52                   push edx
// 005ef911  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005ef91a  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005ef923  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005ef92c  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005ef935  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005ef93e  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005ef947  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005ef950  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005ef959  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005ef962  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005ef96b  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005ef974  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005ef97d  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005ef986  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005ef98f  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005ef998  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005ef9a1  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005ef9aa  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005ef9b3  e8687c2300           call 0x827620
// 005ef9b8  8d442474             lea eax, [esp + 0x74]
// 005ef9bc  50                   push eax
// 005ef9bd  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005ef9c4  51                   push ecx
// 005ef9c5  e8567c2300           call 0x827620
// 005ef9ca  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005ef9d2  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005ef9d8  0f57c8               xorps xmm1, xmm0
// 005ef9db  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005ef9e4  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005ef9ea  8d9424d0000000       lea edx, [esp + 0xd0]
// 005ef9f1  0f57c8               xorps xmm1, xmm0
// 005ef9f4  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005ef9fa  52                   push edx
// 005ef9fb  8d8424ec000000       lea eax, [esp + 0xec]
// 005efa02  50                   push eax
// 005efa03  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005efa0c  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005efa15  e8067c2300           call 0x827620
// 005efa1a  83c418               add esp, 0x18
// 005efa1d  8d4c2440             lea ecx, [esp + 0x40]
// 005efa21  51                   push ecx
// 005efa22  8d8c2480010000       lea ecx, [esp + 0x180]
// 005efa29  e812480400           call 0x634240
// 005efa2e  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005efa35  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005efa3b  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005efa42  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005efa49  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005efa4c  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005efa55  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005efa5b  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005efa64  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005efa6a  89542478             mov dword ptr [esp + 0x78], edx
// 005efa6e  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005efa75  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005efa7e  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005efa84  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005efa8b  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005efa92  89942484000000       mov dword ptr [esp + 0x84], edx
// 005efa99  8b542460             mov edx, dword ptr [esp + 0x60]
// 005efa9d  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005efaa6  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005efaab  8944247c             mov dword ptr [esp + 0x7c], eax
// 005efaaf  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005efab6  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005efabd  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005efac1  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005efaca  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005efad3  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005efadc  89942490000000       mov dword ptr [esp + 0x90], edx
// 005efae3  89842488000000       mov dword ptr [esp + 0x88], eax
// 005efaea  8b442464             mov eax, dword ptr [esp + 0x64]
// 005efaee  8d542478             lea edx, [esp + 0x78]
// 005efaf2  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005efaf9  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005efb02  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005efb0b  52                   push edx
// 005efb0c  8bce                 mov ecx, esi
// 005efb0e  89842498000000       mov dword ptr [esp + 0x98], eax
// 005efb15  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005efb1e  e89da7ffff           call 0x5ea2c0
// 005efb23  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005efb2c  8b7d24               mov edi, dword ptr [ebp + 0x24]
// 005efb2f  d907                 fld dword ptr [edi]
// 005efb31  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005efb37  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005efb40  d95e24               fstp dword ptr [esi + 0x24]
// 005efb43  d94704               fld dword ptr [edi + 4]
// 005efb46  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005efb4c  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005efb55  d95e28               fstp dword ptr [esi + 0x28]
// 005efb58  8d84248c010000       lea eax, [esp + 0x18c]
// 005efb5f  50                   push eax
// 005efb60  8d4c2464             lea ecx, [esp + 0x64]
// 005efb64  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005efb6a  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005efb73  51                   push ecx
// 005efb74  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005efb7a  e8a17a2300           call 0x827620
// 005efb7f  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005efb86  52                   push edx
// 005efb87  8d8424d8000000       lea eax, [esp + 0xd8]
// 005efb8e  50                   push eax
// 005efb8f  e88c7a2300           call 0x827620
// 005efb94  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005efb9a  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005efba3  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005efba9  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005efbb0  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005efbb7  51                   push ecx
// 005efbb8  8d9424ec000000       lea edx, [esp + 0xec]
// 005efbbf  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005efbc8  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005efbce  52                   push edx
// 005efbcf  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005efbd8  e8437a2300           call 0x827620
// 005efbdd  83c418               add esp, 0x18
// 005efbe0  8d442440             lea eax, [esp + 0x40]
// 005efbe4  50                   push eax
// 005efbe5  8d8c2410010000       lea ecx, [esp + 0x110]
// 005efbec  e84f460400           call 0x634240
// 005efbf1  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005efbf8  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005efbff  894c2478             mov dword ptr [esp + 0x78], ecx
// 005efc03  8954247c             mov dword ptr [esp + 0x7c], edx
// 005efc07  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005efc0d  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005efc14  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005efc1b  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005efc22  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005efc2b  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005efc31  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005efc3a  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005efc40  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005efc49  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005efc4f  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005efc58  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005efc5e  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005efc65  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005efc69  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005efc72  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005efc78  89842480000000       mov dword ptr [esp + 0x80], eax
// 005efc7f  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005efc86  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005efc8d  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005efc96  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005efc9c  8d4c2478             lea ecx, [esp + 0x78]
// 005efca0  89942488000000       mov dword ptr [esp + 0x88], edx
// 005efca7  8b542464             mov edx, dword ptr [esp + 0x64]
// 005efcab  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005efcb2  8b442468             mov eax, dword ptr [esp + 0x68]
// 005efcb6  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005efcbf  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005efcc5  8d5e44               lea ebx, [esi + 0x44]
// 005efcc8  51                   push ecx
// 005efcc9  8bcb                 mov ecx, ebx
// 005efccb  89942498000000       mov dword ptr [esp + 0x98], edx
// 005efcd2  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005efcd9  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005efce2  e8d9a5ffff           call 0x5ea2c0
// 005efce7  d94708               fld dword ptr [edi + 8]
// 005efcea  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005efcf3  d95e68               fstp dword ptr [esi + 0x68]
// 005efcf6  d9470c               fld dword ptr [edi + 0xc]
// 005efcf9  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005efcff  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005efd08  d95e6c               fstp dword ptr [esi + 0x6c]
// 005efd0b  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005efd11  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005efd1a  8d94248c010000       lea edx, [esp + 0x18c]
// 005efd21  52                   push edx
// 005efd22  8d442464             lea eax, [esp + 0x64]
// 005efd26  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005efd2c  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005efd35  50                   push eax
// 005efd36  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005efd3c  e8df782300           call 0x827620
// 005efd41  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005efd48  51                   push ecx
// 005efd49  8d9424d8000000       lea edx, [esp + 0xd8]
// 005efd50  52                   push edx
// 005efd51  e8ca782300           call 0x827620
// 005efd56  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005efd5c  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005efd65  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005efd6b  8d8424d0000000       lea eax, [esp + 0xd0]
// 005efd72  50                   push eax
// 005efd73  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005efd7a  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005efd83  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005efd89  51                   push ecx
// 005efd8a  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005efd93  e888782300           call 0x827620
// 005efd98  83c418               add esp, 0x18
// 005efd9b  8d542440             lea edx, [esp + 0x40]
// 005efd9f  52                   push edx
// 005efda0  8d8c2430010000       lea ecx, [esp + 0x130]
// 005efda7  e894440400           call 0x634240
// 005efdac  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005efdb3  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005efdba  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005efdc1  89442478             mov dword ptr [esp + 0x78], eax
// 005efdc5  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005efdcc  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005efdd0  89942480000000       mov dword ptr [esp + 0x80], edx
// 005efdd7  89842484000000       mov dword ptr [esp + 0x84], eax
// 005efdde  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005efde4  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005efdeb  8b442460             mov eax, dword ptr [esp + 0x60]
// 005efdef  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005efdf6  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005efdff  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005efe05  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005efe0e  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005efe14  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005efe1d  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005efe23  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005efe2c  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005efe32  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005efe3b  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005efe41  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005efe48  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005efe4c  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005efe55  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005efe5b  89842490000000       mov dword ptr [esp + 0x90], eax
// 005efe62  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005efe69  8b542468             mov edx, dword ptr [esp + 0x68]
// 005efe6d  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005efe74  8d442478             lea eax, [esp + 0x78]
// 005efe78  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005efe81  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005efe87  8d8e88000000         lea ecx, [esi + 0x88]
// 005efe8d  50                   push eax
// 005efe8e  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005efe95  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005efe9e  894c2460             mov dword ptr [esp + 0x60], ecx
// 005efea2  e819a4ffff           call 0x5ea2c0
// 005efea7  d94710               fld dword ptr [edi + 0x10]
// 005efeaa  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005efeb3  d99eac000000         fstp dword ptr [esi + 0xac]
// 005efeb9  d94714               fld dword ptr [edi + 0x14]
// 005efebc  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005efec2  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005efecb  d99eb0000000         fstp dword ptr [esi + 0xb0]
// 005efed1  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005efed7  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005efee0  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005efee7  51                   push ecx
// 005efee8  8d542464             lea edx, [esp + 0x64]
// 005efeec  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005efef2  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005efefb  52                   push edx
// 005efefc  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005eff02  e819772300           call 0x827620
// 005eff07  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005eff0e  50                   push eax
// 005eff0f  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005eff16  51                   push ecx
// 005eff17  e804772300           call 0x827620
// 005eff1c  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005eff22  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005eff29  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005eff32  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005eff38  8d9424d0000000       lea edx, [esp + 0xd0]
// 005eff3f  52                   push edx
// 005eff40  8d8424ec000000       lea eax, [esp + 0xec]
// 005eff47  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005eff50  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005eff56  50                   push eax
// 005eff57  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005eff60  e8bb762300           call 0x827620
// 005eff65  83c418               add esp, 0x18
// 005eff68  8d4c2440             lea ecx, [esp + 0x40]
// 005eff6c  51                   push ecx
// 005eff6d  8d8c2420010000       lea ecx, [esp + 0x120]
// 005eff74  e8c7420400           call 0x634240
// 005eff79  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005eff80  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005eff87  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005eff8e  89542478             mov dword ptr [esp + 0x78], edx
// 005eff92  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005eff99  8944247c             mov dword ptr [esp + 0x7c], eax
// 005eff9d  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005effa4  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005effab  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005effb2  89942484000000       mov dword ptr [esp + 0x84], edx
// 005effb9  89842488000000       mov dword ptr [esp + 0x88], eax
// 005effc0  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005effc6  8b542460             mov edx, dword ptr [esp + 0x60]
// 005effca  8b442464             mov eax, dword ptr [esp + 0x64]
// 005effce  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005effd7  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005effdd  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005effe6  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005effec  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005efff5  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005efffb  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f0004  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f000a  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f0013  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f0019  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f0020  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f0024  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f002d  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f0033  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f003a  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f0041  8d542478             lea edx, [esp + 0x78]
// 005f0045  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f004e  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f0054  8d8ecc000000         lea ecx, [esi + 0xcc]
// 005f005a  52                   push edx
// 005f005b  89842498000000       mov dword ptr [esp + 0x98], eax
// 005f0062  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f006b  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005f0072  e849a2ffff           call 0x5ea2c0
// 005f0077  d94718               fld dword ptr [edi + 0x18]
// 005f007a  d99ef0000000         fstp dword ptr [esi + 0xf0]
// 005f0080  56                   push esi
// 005f0081  d9471c               fld dword ptr [edi + 0x1c]
// 005f0084  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f0087  8b07                 mov eax, dword ptr [edi]
// 005f0089  d99ef4000000         fstp dword ptr [esi + 0xf4]
// 005f008f  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f0092  8bcf                 mov ecx, edi
// 005f0094  ffd2                 call edx
// 005f0096  8bf0                 mov esi, eax
// 005f0098  8b07                 mov eax, dword ptr [edi]
// 005f009a  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f009d  53                   push ebx
// 005f009e  8bcf                 mov ecx, edi
// 005f00a0  ffd2                 call edx
// 005f00a2  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f00a6  8bd8                 mov ebx, eax
// 005f00a8  8b07                 mov eax, dword ptr [edi]
// 005f00aa  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f00ad  51                   push ecx
// 005f00ae  8bcf                 mov ecx, edi
// 005f00b0  ffd2                 call edx
// 005f00b2  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005f00b9  8944243c             mov dword ptr [esp + 0x3c], eax
// 005f00bd  8b07                 mov eax, dword ptr [edi]
// 005f00bf  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f00c2  51                   push ecx
// 005f00c3  8bcf                 mov ecx, edi
// 005f00c5  ffd2                 call edx
// 005f00c7  8b17                 mov edx, dword ptr [edi]
// 005f00c9  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f00cc  50                   push eax
// 005f00cd  89442460             mov dword ptr [esp + 0x60], eax
// 005f00d1  8b442440             mov eax, dword ptr [esp + 0x40]
// 005f00d5  50                   push eax
// 005f00d6  53                   push ebx
// 005f00d7  56                   push esi
// 005f00d8  8bcf                 mov ecx, edi
// 005f00da  ffd2                 call edx
// 005f00dc  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005f00df  85c0                 test eax, eax
// 005f00e1  7413                 je 0x5f00f6
// 005f00e3  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f00e7  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005f00eb  8930                 mov dword ptr [eax], esi
// 005f00ed  895804               mov dword ptr [eax + 4], ebx
// 005f00f0  894808               mov dword ptr [eax + 8], ecx
// 005f00f3  89500c               mov dword ptr [eax + 0xc], edx
// 005f00f6  5f                   pop edi
// 005f00f7  5e                   pop esi
// 005f00f8  5b                   pop ebx
// 005f00f9  8be5                 mov esp, ebp
// 005f00fb  5d                   pop ebp
// 005f00fc  c22000               ret 0x20
// 005f00ff  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f0106  743c                 je 0x5f0144
// 005f0108  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005f010c  7536                 jne 0x5f0144
// 005f010e  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f0113  85c0                 test eax, eax
// 005f0115  7418                 je 0x5f012f
// 005f0117  6801010000           push 0x101
// 005f011c  688027b800           push 0xb82780
// 005f0121  680027b800           push 0xb82700
// 005f0126  ffd0                 call eax
// 005f0128  83c40c               add esp, 0xc
// 005f012b  84c0                 test al, al
// 005f012d  7515                 jne 0x5f0144
// 005f012f  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f0136  688826b800           push 0xb82688
// 005f013b  50                   push eax
// 005f013c  e84f213800           call 0x972290
// 005f0141  83c408               add esp, 8
// 005f0144  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005f014a  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f0151  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f0159  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005f0161  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005f0166  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005f016c  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005f0174  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005f0179  8d4c2460             lea ecx, [esp + 0x60]
// 005f017d  51                   push ecx
// 005f017e  f30f59c2             mulss xmm0, xmm2
// 005f0182  f30f59ca             mulss xmm1, xmm2
// 005f0186  8d4c2420             lea ecx, [esp + 0x20]
// 005f018a  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f0193  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f019c  e89f400400           call 0x634240
// 005f01a1  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f01aa  f30f5e00             divss xmm0, dword ptr [eax]
// 005f01ae  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005f01b3  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005f01b6  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f01b9  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f01be  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f01c6  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f01cc  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005f01d5  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f01de  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005f01e3  33d2                 xor edx, edx
// 005f01e5  33db                 xor ebx, ebx
// 005f01e7  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005f01f0  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f01f7  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005f01fe  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005f0204  0f2fd7               comiss xmm2, xmm7
// 005f0207  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005f020d  8954243c             mov dword ptr [esp + 0x3c], edx
// 005f0211  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005f021a  770a                 ja 0x5f0226
// 005f021c  85d2                 test edx, edx
// 005f021e  0f85d2feffff         jne 0x5f00f6
// 005f0224  eb04                 jmp 0x5f022a
// 005f0226  85d2                 test edx, edx
// 005f0228  7504                 jne 0x5f022e
// 005f022a  f30f5cc4             subss xmm0, xmm4
// 005f022e  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f0232  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f0236  7421                 je 0x5f0259
// 005f0238  f30f58c7             addss xmm0, xmm7
// 005f023c  0f2fc2               comiss xmm0, xmm2
// 005f023f  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f0248  8d44241c             lea eax, [esp + 0x1c]
// 005f024c  7707                 ja 0x5f0255
// 005f024e  8d84240c030000       lea eax, [esp + 0x30c]
// 005f0255  f30f1010             movss xmm2, dword ptr [eax]
// 005f0259  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005f0262  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f0268  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f026f  f30f58cb             addss xmm1, xmm3
// 005f0273  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005f0278  33c0                 xor eax, eax
// 005f027a  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005f0280  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005f0289  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f0290  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005f0296  0f2ff0               comiss xmm6, xmm0
// 005f0299  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005f02a2  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005f02a8  7708                 ja 0x5f02b2
// 005f02aa  85c0                 test eax, eax
// 005f02ac  0f852b110000         jne 0x5f13dd
// 005f02b2  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005f02b8  85c0                 test eax, eax
// 005f02ba  7504                 jne 0x5f02c0
// 005f02bc  f30f5ccc             subss xmm1, xmm4
// 005f02c0  0f28f1               movaps xmm6, xmm1
// 005f02c3  f30f58f0             addss xmm6, xmm0
// 005f02c7  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005f02cc  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005f02d5  8d442420             lea eax, [esp + 0x20]
// 005f02d9  7707                 ja 0x5f02e2
// 005f02db  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005f02e2  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f02e6  f30f1000             movss xmm0, dword ptr [eax]
// 005f02ea  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005f02f0  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005f02f9  f30f58c3             addss xmm0, xmm3
// 005f02fd  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005f0306  0f57c0               xorps xmm0, xmm0
// 005f0309  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005f030f  740f                 je 0x5f0320
// 005f0311  e87a9fffff           call 0x5ea290
// 005f0316  d80d94deb600         fmul dword ptr [0xb6de94]
// 005f031c  d95c2440             fstp dword ptr [esp + 0x40]
// 005f0320  0f28dd               movaps xmm3, xmm5
// 005f0323  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005f032c  0f28c3               movaps xmm0, xmm3
// 005f032f  f30f59c4             mulss xmm0, xmm4
// 005f0333  f30f5cd7             subss xmm2, xmm7
// 005f0337  f30f59d3             mulss xmm2, xmm3
// 005f033b  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005f0341  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005f0347  f30f58d3             addss xmm2, xmm3
// 005f034b  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005f0351  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005f0357  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005f035d  0f28c5               movaps xmm0, xmm5
// 005f0360  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005f0369  0f28e9               movaps xmm5, xmm1
// 005f036c  0f28f0               movaps xmm6, xmm0
// 005f036f  f30f59f4             mulss xmm6, xmm4
// 005f0373  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005f0379  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005f037f  f30f5ccb             subss xmm1, xmm3
// 005f0383  f30f59e8             mulss xmm5, xmm0
// 005f0387  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005f038d  f30f59c8             mulss xmm1, xmm0
// 005f0391  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005f0397  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005f03a0  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005f03a9  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005f03b2  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005f03bb  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005f03c4  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005f03cd  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005f03d6  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005f03df  85d2                 test edx, edx
// 005f03e1  753f                 jne 0x5f0422
// 005f03e3  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005f03e9  0f28c4               movaps xmm0, xmm4
// 005f03ec  f30f58c3             addss xmm0, xmm3
// 005f03f0  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005f03f9  0f28c3               movaps xmm0, xmm3
// 005f03fc  f30f58c2             addss xmm0, xmm2
// 005f0400  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005f0409  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005f0412  0f28c4               movaps xmm0, xmm4
// 005f0415  f30f58c3             addss xmm0, xmm3
// 005f0419  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005f0422  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f0428  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005f042d  772f                 ja 0x5f045e
// 005f042f  0f28c6               movaps xmm0, xmm6
// 005f0432  f30f58c5             addss xmm0, xmm5
// 005f0436  f30f58f1             addss xmm6, xmm1
// 005f043a  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005f0443  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005f044c  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005f0455  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005f045e  8d9424cc000000       lea edx, [esp + 0xcc]
// 005f0465  52                   push edx
// 005f0466  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f046d  e8ce3d0400           call 0x634240
// 005f0472  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f0477  f30f1008             movss xmm1, dword ptr [eax]
// 005f047b  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005f0481  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005f0487  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f048e  50                   push eax
// 005f048f  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f0496  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005f049f  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005f04a8  e8933d0400           call 0x634240
// 005f04ad  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f04b2  f30f1008             movss xmm1, dword ptr [eax]
// 005f04b6  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005f04bc  f30f584c244c         addss xmm1, dword ptr [esp + 0x4c]
// 005f04c2  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005f04c9  51                   push ecx
// 005f04ca  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f04d1  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005f04da  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005f04e3  e8583d0400           call 0x634240
// 005f04e8  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005f04ee  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f04f3  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005f04f9  f30f5c08             subss xmm1, dword ptr [eax]
// 005f04fd  8d94248c010000       lea edx, [esp + 0x18c]
// 005f0504  52                   push edx
// 005f0505  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f050c  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005f0515  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005f051e  e81d3d0400           call 0x634240
// 005f0523  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f0529  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f052e  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005f0534  f30f5c08             subss xmm1, dword ptr [eax]
// 005f0538  8d842498010000       lea eax, [esp + 0x198]
// 005f053f  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f0548  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f0550  50                   push eax
// 005f0551  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005f0558  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005f055e  0f57c0               xorps xmm0, xmm0
// 005f0561  51                   push ecx
// 005f0562  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005f0569  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f0572  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005f0578  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005f057e  e88d3c0400           call 0x634210
// 005f0583  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005f058c  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005f0595  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005f059e  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005f05a7  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f05b0  8d9424ec000000       lea edx, [esp + 0xec]
// 005f05b7  52                   push edx
// 005f05b8  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005f05bf  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005f05c8  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f05d1  50                   push eax
// 005f05d2  8d8c2484010000       lea ecx, [esp + 0x184]
// 005f05d9  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005f05e2  e8293c0400           call 0x634210
// 005f05e7  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f05f0  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f05f6  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005f05ff  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f0605  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005f060e  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005f0614  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f061d  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f0623  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005f062c  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005f0635  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005f063e  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f0647  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f0650  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005f0659  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f0662  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005f066b  8d4c246c             lea ecx, [esp + 0x6c]
// 005f066f  51                   push ecx
// 005f0670  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005f0677  52                   push edx
// 005f0678  e8a36f2300           call 0x827620
// 005f067d  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f0686  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005f068f  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f0698  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005f069f  50                   push eax
// 005f06a0  8d8c2484030000       lea ecx, [esp + 0x384]
// 005f06a7  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005f06b0  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f06b8  51                   push ecx
// 005f06b9  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005f06c2  e8596f2300           call 0x827620
// 005f06c7  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f06cd  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005f06d6  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f06dc  8d942470030000       lea edx, [esp + 0x370]
// 005f06e3  52                   push edx
// 005f06e4  8d842450030000       lea eax, [esp + 0x350]
// 005f06eb  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005f06f4  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f06fa  50                   push eax
// 005f06fb  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005f0704  e8176f2300           call 0x827620
// 005f0709  83c418               add esp, 0x18
// 005f070c  8d8c2430030000       lea ecx, [esp + 0x330]
// 005f0713  51                   push ecx
// 005f0714  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005f071b  e8203b0400           call 0x634240
// 005f0720  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f0729  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005f0730  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005f0737  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005f073e  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005f0747  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f0750  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005f0759  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005f0762  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005f076b  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005f0774  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005f077d  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005f0786  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005f078f  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005f0798  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005f07a1  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005f07aa  89942448020000       mov dword ptr [esp + 0x248], edx
// 005f07b1  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005f07b8  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005f07c1  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005f07ca  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005f07d1  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005f07d8  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005f07e1  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005f07ea  89942454020000       mov dword ptr [esp + 0x254], edx
// 005f07f1  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005f07f8  89842458020000       mov dword ptr [esp + 0x258], eax
// 005f07ff  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005f0806  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005f080f  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005f0818  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005f081f  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005f0826  89942460020000       mov dword ptr [esp + 0x260], edx
// 005f082d  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005f0836  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005f083f  8d54246c             lea edx, [esp + 0x6c]
// 005f0843  89842464020000       mov dword ptr [esp + 0x264], eax
// 005f084a  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005f0851  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005f0858  52                   push edx
// 005f0859  8d842470030000       lea eax, [esp + 0x370]
// 005f0860  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005f0869  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005f0872  50                   push eax
// 005f0873  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005f087a  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f0883  e8986d2300           call 0x827620
// 005f0888  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f0891  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005f089a  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f08a3  8d8c2498030000       lea ecx, [esp + 0x398]
// 005f08aa  51                   push ecx
// 005f08ab  8d942460030000       lea edx, [esp + 0x360]
// 005f08b2  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005f08bb  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f08c3  52                   push edx
// 005f08c4  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005f08cd  e84e6d2300           call 0x827620
// 005f08d2  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005f08d8  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005f08e1  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f08e7  8d842400040000       lea eax, [esp + 0x400]
// 005f08ee  50                   push eax
// 005f08ef  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005f08f6  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005f08ff  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f0905  51                   push ecx
// 005f0906  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005f090f  e80c6d2300           call 0x827620
// 005f0914  83c418               add esp, 0x18
// 005f0917  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005f091e  52                   push edx
// 005f091f  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005f0926  e815390400           call 0x634240
// 005f092b  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005f0934  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005f093b  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005f0942  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005f0949  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005f0952  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005f095b  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005f0964  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005f096d  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005f0976  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005f097f  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005f0988  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005f0991  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005f099a  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005f09a3  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005f09ac  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005f09b5  89842490020000       mov dword ptr [esp + 0x290], eax
// 005f09bc  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005f09c3  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005f09cc  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005f09d5  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005f09dc  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005f09e3  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005f09ec  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005f09f5  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005f09fc  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005f0a03  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005f0a0a  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005f0a11  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005f0a1a  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005f0a23  89942498020000       mov dword ptr [esp + 0x298], edx
// 005f0a2a  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005f0a31  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005f0a38  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005f0a41  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005f0a4a  8d44246c             lea eax, [esp + 0x6c]
// 005f0a4e  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005f0a55  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005f0a5c  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005f0a63  50                   push eax
// 005f0a64  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005f0a6b  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005f0a74  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005f0a7d  51                   push ecx
// 005f0a7e  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005f0a85  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005f0a8e  e88d6b2300           call 0x827620
// 005f0a93  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f0a9c  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005f0aa5  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f0aae  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005f0ab7  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f0abf  8d94248c030000       lea edx, [esp + 0x38c]
// 005f0ac6  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005f0acf  52                   push edx
// 005f0ad0  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005f0ad7  50                   push eax
// 005f0ad8  e8436b2300           call 0x827620
// 005f0add  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005f0ae3  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005f0aec  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005f0af2  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005f0af9  51                   push ecx
// 005f0afa  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005f0b01  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005f0b0a  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f0b10  52                   push edx
// 005f0b11  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005f0b1a  e8016b2300           call 0x827620
// 005f0b1f  83c418               add esp, 0x18
// 005f0b22  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005f0b29  50                   push eax
// 005f0b2a  8d8c2480010000       lea ecx, [esp + 0x180]
// 005f0b31  e80a370400           call 0x634240
// 005f0b36  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005f0b3f  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005f0b46  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005f0b4d  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005f0b54  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005f0b5d  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005f0b66  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005f0b6f  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005f0b78  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005f0b81  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005f0b8a  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005f0b93  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005f0b9c  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005f0ba5  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005f0bae  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005f0bb7  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 005f0bc0  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 005f0bc7  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 005f0bce  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 005f0bd7  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 005f0be0  89942404020000       mov dword ptr [esp + 0x204], edx
// 005f0be7  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 005f0bee  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 005f0bf7  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f0bfd  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 005f0c04  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 005f0c0b  89942410020000       mov dword ptr [esp + 0x210], edx
// 005f0c12  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 005f0c19  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 005f0c22  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f0c28  89842408020000       mov dword ptr [esp + 0x208], eax
// 005f0c2f  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 005f0c36  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 005f0c3d  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005f0c46  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f0c4c  8d4c246c             lea ecx, [esp + 0x6c]
// 005f0c50  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 005f0c57  89842414020000       mov dword ptr [esp + 0x214], eax
// 005f0c5e  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 005f0c65  51                   push ecx
// 005f0c66  8d942410010000       lea edx, [esp + 0x110]
// 005f0c6d  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 005f0c76  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f0c7c  52                   push edx
// 005f0c7d  89842428020000       mov dword ptr [esp + 0x228], eax
// 005f0c84  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f0c8d  e88e692300           call 0x827620
// 005f0c92  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f0c9b  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 005f0ca4  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f0cad  8d842404040000       lea eax, [esp + 0x404]
// 005f0cb4  50                   push eax
// 005f0cb5  8d8c2438010000       lea ecx, [esp + 0x138]
// 005f0cbc  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 005f0cc5  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f0ccd  51                   push ecx
// 005f0cce  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 005f0cd7  e844692300           call 0x827620
// 005f0cdc  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f0ce2  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 005f0ceb  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005f0cf1  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005f0cfa  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f0d00  8d9424b8030000       lea edx, [esp + 0x3b8]
// 005f0d07  52                   push edx
// 005f0d08  8d842430010000       lea eax, [esp + 0x130]
// 005f0d0f  50                   push eax
// 005f0d10  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 005f0d19  e802692300           call 0x827620
// 005f0d1e  83c418               add esp, 0x18
// 005f0d21  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 005f0d28  51                   push ecx
// 005f0d29  8d4c242c             lea ecx, [esp + 0x2c]
// 005f0d2d  e80e350400           call 0x634240
// 005f0d32  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 005f0d3b  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 005f0d42  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 005f0d49  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 005f0d50  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f0d59  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 005f0d62  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f0d6b  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 005f0d74  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f0d7d  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 005f0d86  89542478             mov dword ptr [esp + 0x78], edx
// 005f0d8a  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 005f0d91  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f0d95  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005f0d9c  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f0da5  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 005f0dae  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f0db5  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 005f0dbc  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f0dc3  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 005f0dca  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f0dd1  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 005f0dd8  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f0de1  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 005f0dea  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f0df1  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 005f0df8  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f0dff  8b17                 mov edx, dword ptr [edi]
// 005f0e01  8b5210               mov edx, dword ptr [edx + 0x10]
// 005f0e04  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f0e0d  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 005f0e16  89842494000000       mov dword ptr [esp + 0x94], eax
// 005f0e1d  8d842448020000       lea eax, [esp + 0x248]
// 005f0e24  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f0e2b  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f0e34  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 005f0e3d  50                   push eax
// 005f0e3e  8bcf                 mov ecx, edi
// 005f0e40  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f0e49  ffd2                 call edx
// 005f0e4b  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 005f0e52  8b07                 mov eax, dword ptr [edi]
// 005f0e54  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f0e57  8d8c2490020000       lea ecx, [esp + 0x290]
// 005f0e5e  51                   push ecx
// 005f0e5f  8bcf                 mov ecx, edi
// 005f0e61  ffd2                 call edx
// 005f0e63  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 005f0e6a  8b07                 mov eax, dword ptr [edi]
// 005f0e6c  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f0e6f  8d8c2400020000       lea ecx, [esp + 0x200]
// 005f0e76  51                   push ecx
// 005f0e77  8bcf                 mov ecx, edi
// 005f0e79  ffd2                 call edx
// 005f0e7b  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 005f0e82  8b07                 mov eax, dword ptr [edi]
// 005f0e84  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f0e87  8d4c2478             lea ecx, [esp + 0x78]
// 005f0e8b  51                   push ecx
// 005f0e8c  8bcf                 mov ecx, edi
// 005f0e8e  ffd2                 call edx
// 005f0e90  89842460010000       mov dword ptr [esp + 0x160], eax
// 005f0e97  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005f0e9e  40                   inc eax
// 005f0e9f  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f0ea6  3bc3                 cmp eax, ebx
// 005f0ea8  8d84246c010000       lea eax, [esp + 0x16c]
// 005f0eaf  7c07                 jl 0x5f0eb8
// 005f0eb1  8d8424e8000000       lea eax, [esp + 0xe8]
// 005f0eb8  8b18                 mov ebx, dword ptr [eax]
// 005f0eba  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 005f0ec1  8bc8                 mov ecx, eax
// 005f0ec3  40                   inc eax
// 005f0ec4  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f0ecb  85c9                 test ecx, ecx
// 005f0ecd  0f85f9000000         jne 0x5f0fcc
// 005f0ed3  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 005f0eda  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005f0edd  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 005f0ee6  8911                 mov dword ptr [ecx], edx
// 005f0ee8  f30f1106             movss dword ptr [esi], xmm0
// 005f0eec  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 005f0ef5  f30f114604           movss dword ptr [esi + 4], xmm0
// 005f0efa  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 005f0f03  f30f114608           movss dword ptr [esi + 8], xmm0
// 005f0f08  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 005f0f11  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 005f0f16  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 005f0f1f  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 005f0f24  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 005f0f2d  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 005f0f32  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 005f0f3b  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 005f0f40  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 005f0f49  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 005f0f4e  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 005f0f57  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 005f0f5c  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 005f0f65  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 005f0f6a  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 005f0f73  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 005f0f78  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 005f0f81  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 005f0f86  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 005f0f8f  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 005f0f94  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 005f0f9d  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 005f0fa2  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 005f0fab  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 005f0fb0  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 005f0fb9  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 005f0fbe  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 005f0fc7  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 005f0fcc  8bd3                 mov edx, ebx
// 005f0fce  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 005f0fd3  8d0c9501000000       lea ecx, [edx*4 + 1]
// 005f0fda  8bd0                 mov edx, eax
// 005f0fdc  40                   inc eax
// 005f0fdd  3bd1                 cmp edx, ecx
// 005f0fdf  0f8501010000         jne 0x5f10e6
// 005f0fe5  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005f0fec  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005f0fef  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 005f0ff8  894a04               mov dword ptr [edx + 4], ecx
// 005f0ffb  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 005f1000  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 005f1009  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 005f100e  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 005f1017  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 005f101c  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 005f1025  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 005f102a  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 005f1033  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 005f1038  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 005f1041  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 005f1046  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 005f104f  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 005f1054  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 005f105d  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 005f1062  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 005f106b  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 005f1070  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 005f1079  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 005f107e  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 005f1087  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 005f108c  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 005f1095  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 005f109a  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 005f10a3  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 005f10a8  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 005f10b1  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 005f10b6  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 005f10bf  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 005f10c4  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 005f10cd  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 005f10d5  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 005f10de  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 005f10e6  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f10ea  41                   inc ecx
// 005f10eb  0fafcb               imul ecx, ebx
// 005f10ee  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 005f10f5  8bc8                 mov ecx, eax
// 005f10f7  40                   inc eax
// 005f10f8  3bca                 cmp ecx, edx
// 005f10fa  0f852e010000         jne 0x5f122e
// 005f1100  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 005f1107  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005f110a  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005f1113  895108               mov dword ptr [ecx + 8], edx
// 005f1116  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 005f111e  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 005f1127  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 005f112f  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 005f1138  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 005f1140  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 005f1149  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 005f1151  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 005f115a  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 005f1162  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 005f116b  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 005f1173  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 005f117c  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 005f1184  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 005f118d  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 005f1195  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 005f119e  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 005f11a6  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 005f11af  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 005f11b7  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 005f11c0  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 005f11c8  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 005f11d1  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 005f11d9  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 005f11e2  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 005f11ea  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 005f11f3  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 005f11fb  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 005f1204  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 005f120c  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 005f1215  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 005f121d  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 005f1226  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 005f122e  8bc8                 mov ecx, eax
// 005f1230  8d149dffffffff       lea edx, [ebx*4 - 1]
// 005f1237  40                   inc eax
// 005f1238  89842478010000       mov dword ptr [esp + 0x178], eax
// 005f123f  3bca                 cmp ecx, edx
// 005f1241  0f8528010000         jne 0x5f136f
// 005f1247  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005f124a  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005f1251  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 005f1257  89420c               mov dword ptr [edx + 0xc], eax
// 005f125a  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 005f1262  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 005f1268  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 005f1270  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 005f1279  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 005f1281  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 005f128a  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 005f1292  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 005f129b  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 005f12a3  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 005f12ac  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 005f12b4  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 005f12bd  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 005f12c5  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 005f12ce  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 005f12d6  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 005f12df  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 005f12e7  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 005f12f0  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 005f12f8  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 005f1301  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 005f1309  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 005f1312  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 005f131a  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 005f1323  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 005f132b  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 005f1334  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 005f133c  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 005f1345  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 005f134d  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 005f1356  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 005f135e  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 005f1367  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 005f136f  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005f1376  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005f137d  8b17                 mov edx, dword ptr [edi]
// 005f137f  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f1382  50                   push eax
// 005f1383  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 005f138a  51                   push ecx
// 005f138b  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 005f1392  50                   push eax
// 005f1393  51                   push ecx
// 005f1394  8bcf                 mov ecx, edi
// 005f1396  ffd2                 call edx
// 005f1398  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f139e  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 005f13a7  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f13af  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 005f13b8  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 005f13be  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f13c4  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f13c9  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005f13d0  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f13d4  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005f13d8  e9b3eeffff           jmp 0x5f0290
// 005f13dd  0f28fa               movaps xmm7, xmm2
// 005f13e0  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 005f13e6  0f28d9               movaps xmm3, xmm1
// 005f13e9  42                   inc edx
// 005f13ea  e90feeffff           jmp 0x5f01fe
// 005f13ef  90                   nop 
// 005f13f0  61                   popal 
// 005f13f1  f65e00               neg byte ptr [esi]
// 005f13f4  cc                   int3 
// 005f13f5  f75e00               neg dword ptr [esi]
// 005f13f8  b8f65e007e           mov eax, 0x7e005ef6
// 005f13fd  f75e00               neg dword ptr [esi]
// 005f1400  f6f6                 div dh
// 005f1402  5e                   pop esi
// 005f1403  003a                 add byte ptr [edx], bh
// 005f1405  f75e00               neg dword ptr [esi]

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
