// from server: 10% by intel
// roc 2012-06 005f1410  unit: seg_005f0000  size: 7848 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005f1410
//
// 005f1410  55                   push ebp
// 005f1411  8bec                 mov ebp, esp
// 005f1413  83e4f8               and esp, 0xfffffff8
// 005f1416  81ecfc030000         sub esp, 0x3fc
// 005f141c  53                   push ebx
// 005f141d  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005f1420  56                   push esi
// 005f1421  57                   push edi
// 005f1422  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005f1425  8d44246c             lea eax, [esp + 0x6c]
// 005f1429  8bf1                 mov esi, ecx
// 005f142b  53                   push ebx
// 005f142c  c1ef09               shr edi, 9
// 005f142f  50                   push eax
// 005f1430  89742464             mov dword ptr [esp + 0x64], esi
// 005f1434  83e707               and edi, 7
// 005f1437  e804622300           call 0x827640
// 005f143c  d9442474             fld dword ptr [esp + 0x74]
// 005f1440  d9e1                 fabs 
// 005f1442  8d4c2474             lea ecx, [esp + 0x74]
// 005f1446  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005f144d  53                   push ebx
// 005f144e  d944247c             fld dword ptr [esp + 0x7c]
// 005f1452  51                   push ecx
// 005f1453  d9e1                 fabs 
// 005f1455  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005f145c  d9842484000000       fld dword ptr [esp + 0x84]
// 005f1463  d9e1                 fabs 
// 005f1465  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005f146c  e8cf612300           call 0x827640
// 005f1471  d944247c             fld dword ptr [esp + 0x7c]
// 005f1475  8a4670               mov al, byte ptr [esi + 0x70]
// 005f1478  d9e1                 fabs 
// 005f147a  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f1482  d9842480000000       fld dword ptr [esp + 0x80]
// 005f1489  83c410               add esp, 0x10
// 005f148c  d9e1                 fabs 
// 005f148e  d9442474             fld dword ptr [esp + 0x74]
// 005f1492  d9e1                 fabs 
// 005f1494  d9450c               fld dword ptr [ebp + 0xc]
// 005f1497  dceb                 fsub st(3), st(0)
// 005f1499  d9cb                 fxch st(3)
// 005f149b  d95c241c             fstp dword ptr [esp + 0x1c]
// 005f149f  d9c9                 fxch st(1)
// 005f14a1  dee2                 fsubrp st(2)
// 005f14a3  d9c9                 fxch st(1)
// 005f14a5  d95c2420             fstp dword ptr [esp + 0x20]
// 005f14a9  d95c2424             fstp dword ptr [esp + 0x24]
// 005f14ad  84c0                 test al, al
// 005f14af  741b                 je 0x5f14cc
// 005f14b1  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005f14b9  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005f14c2  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005f14ca  eb11                 jmp 0x5f14dd
// 005f14cc  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005f14d4  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005f14dd  0f57e4               xorps xmm4, xmm4
// 005f14e0  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005f14e9  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005f14ef  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005f14f5  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005f14fb  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005f1501  83ff05               cmp edi, 5
// 005f1504  0f87a4010000         ja 0x5f16ae
// 005f150a  ff24bda0325f00       jmp dword ptr [edi*4 + 0x5f32a0]
// 005f1511  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005f1519  8d542460             lea edx, [esp + 0x60]
// 005f151d  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005f1523  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005f152b  52                   push edx
// 005f152c  8d4c2420             lea ecx, [esp + 0x20]
// 005f1530  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005f1536  e8052d0400           call 0x634240
// 005f153b  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f1543  f30f1000             movss xmm0, dword ptr [eax]
// 005f1547  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005f154c  0f57e4               xorps xmm4, xmm4
// 005f154f  f30f59c5             mulss xmm0, xmm5
// 005f1553  f30f59cd             mulss xmm1, xmm5
// 005f1557  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005f155d  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005f1563  e946010000           jmp 0x5f16ae
// 005f1568  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f1570  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f1576  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f157c  84c0                 test al, al
// 005f157e  7413                 je 0x5f1593
// 005f1580  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005f1588  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f158e  e91b010000           jmp 0x5f16ae
// 005f1593  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005f159b  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f15a1  e908010000           jmp 0x5f16ae
// 005f15a6  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f15ac  84c0                 test al, al
// 005f15ae  7419                 je 0x5f15c9
// 005f15b0  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005f15b8  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005f15be  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f15c4  e9e5000000           jmp 0x5f16ae
// 005f15c9  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f15d1  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f15d7  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005f15df  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f15e5  e9c4000000           jmp 0x5f16ae
// 005f15ea  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f15f0  84c0                 test al, al
// 005f15f2  7419                 je 0x5f160d
// 005f15f4  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005f15fc  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005f1602  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f1608  e9a1000000           jmp 0x5f16ae
// 005f160d  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f1615  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f161b  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005f1623  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f1629  e980000000           jmp 0x5f16ae
// 005f162e  84c0                 test al, al
// 005f1630  745a                 je 0x5f168c
// 005f1632  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f1639  7441                 je 0x5f167c
// 005f163b  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f1640  85c0                 test eax, eax
// 005f1642  7418                 je 0x5f165c
// 005f1644  68b7000000           push 0xb7
// 005f1649  688027b800           push 0xb82780
// 005f164e  68cc60b400           push 0xb460cc
// 005f1653  ffd0                 call eax
// 005f1655  83c40c               add esp, 0xc
// 005f1658  84c0                 test al, al
// 005f165a  7515                 jne 0x5f1671
// 005f165c  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f1663  680827b800           push 0xb82708
// 005f1668  50                   push eax
// 005f1669  e8220c3800           call 0x972290
// 005f166e  83c408               add esp, 8
// 005f1671  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f1679  0f57e4               xorps xmm4, xmm4
// 005f167c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f1684  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f168a  eb1c                 jmp 0x5f16a8
// 005f168c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f1694  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f169a  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005f16a2  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f16a8  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f16ae  807e7000             cmp byte ptr [esi + 0x70], 0
// 005f16b2  7419                 je 0x5f16cd
// 005f16b4  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005f16b9  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005f16c1  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005f16c7  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005f16cd  85ff                 test edi, edi
// 005f16cf  0f85da080000         jne 0x5f1faf
// 005f16d5  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f16dd  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005f16e2  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005f16ea  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005f16ef  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005f16f5  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005f16fe  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f1706  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005f170c  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005f1715  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005f171e  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005f1727  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005f1730  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005f1739  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005f1742  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005f174b  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005f1754  f30f59c5             mulss xmm0, xmm5
// 005f1758  f30f59cd             mulss xmm1, xmm5
// 005f175c  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005f1765  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005f176e  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005f1773  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005f177c  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005f1785  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005f178c  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005f1792  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005f179b  0f28e3               movaps xmm4, xmm3
// 005f179e  f30f5ce0             subss xmm4, xmm0
// 005f17a2  0f28eb               movaps xmm5, xmm3
// 005f17a5  f30f5ce9             subss xmm5, xmm1
// 005f17a9  51                   push ecx
// 005f17aa  8d542464             lea edx, [esp + 0x64]
// 005f17ae  f30f5cc3             subss xmm0, xmm3
// 005f17b2  0f28d3               movaps xmm2, xmm3
// 005f17b5  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005f17bc  f30f5ccb             subss xmm1, xmm3
// 005f17c0  52                   push edx
// 005f17c1  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005f17ca  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005f17d3  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005f17dc  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005f17e5  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005f17ee  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005f17f7  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005f1800  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005f1809  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005f1812  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005f181b  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005f1824  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005f182d  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005f1836  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005f183f  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005f1848  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005f1851  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005f185a  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005f1863  e8d85d2300           call 0x827640
// 005f1868  8d442474             lea eax, [esp + 0x74]
// 005f186c  50                   push eax
// 005f186d  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005f1874  51                   push ecx
// 005f1875  e8c65d2300           call 0x827640
// 005f187a  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005f1882  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005f1888  0f57c8               xorps xmm1, xmm0
// 005f188b  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005f1894  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005f189a  8d9424d0000000       lea edx, [esp + 0xd0]
// 005f18a1  0f57c8               xorps xmm1, xmm0
// 005f18a4  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f18aa  52                   push edx
// 005f18ab  8d8424ec000000       lea eax, [esp + 0xec]
// 005f18b2  50                   push eax
// 005f18b3  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005f18bc  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f18c5  e8765d2300           call 0x827640
// 005f18ca  83c418               add esp, 0x18
// 005f18cd  8d4c2440             lea ecx, [esp + 0x40]
// 005f18d1  51                   push ecx
// 005f18d2  8d8c2480010000       lea ecx, [esp + 0x180]
// 005f18d9  e862290400           call 0x634240
// 005f18de  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005f18e5  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f18eb  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005f18f2  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005f18f9  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005f18fc  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f1905  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f190b  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f1914  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f191a  89542478             mov dword ptr [esp + 0x78], edx
// 005f191e  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005f1925  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f192e  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f1934  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f193b  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005f1942  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f1949  8b542460             mov edx, dword ptr [esp + 0x60]
// 005f194d  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f1956  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005f195b  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f195f  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005f1966  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f196d  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f1971  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f197a  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f1983  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f198c  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f1993  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f199a  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f199e  8d542478             lea edx, [esp + 0x78]
// 005f19a2  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f19a9  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f19b2  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f19bb  52                   push edx
// 005f19bc  8bce                 mov ecx, esi
// 005f19be  89842498000000       mov dword ptr [esp + 0x98], eax
// 005f19c5  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f19ce  e8ed88ffff           call 0x5ea2c0
// 005f19d3  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005f19dc  8b7d24               mov edi, dword ptr [ebp + 0x24]
// 005f19df  d907                 fld dword ptr [edi]
// 005f19e1  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f19e7  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005f19f0  d95e24               fstp dword ptr [esi + 0x24]
// 005f19f3  d94704               fld dword ptr [edi + 4]
// 005f19f6  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f19fc  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005f1a05  d95e28               fstp dword ptr [esi + 0x28]
// 005f1a08  8d84248c010000       lea eax, [esp + 0x18c]
// 005f1a0f  50                   push eax
// 005f1a10  8d4c2464             lea ecx, [esp + 0x64]
// 005f1a14  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f1a1a  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005f1a23  51                   push ecx
// 005f1a24  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f1a2a  e8115c2300           call 0x827640
// 005f1a2f  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005f1a36  52                   push edx
// 005f1a37  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f1a3e  50                   push eax
// 005f1a3f  e8fc5b2300           call 0x827640
// 005f1a44  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f1a4a  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f1a53  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f1a59  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f1a60  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005f1a67  51                   push ecx
// 005f1a68  8d9424ec000000       lea edx, [esp + 0xec]
// 005f1a6f  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f1a78  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f1a7e  52                   push edx
// 005f1a7f  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f1a88  e8b35b2300           call 0x827640
// 005f1a8d  83c418               add esp, 0x18
// 005f1a90  8d442440             lea eax, [esp + 0x40]
// 005f1a94  50                   push eax
// 005f1a95  8d8c2410010000       lea ecx, [esp + 0x110]
// 005f1a9c  e89f270400           call 0x634240
// 005f1aa1  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005f1aa8  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005f1aaf  894c2478             mov dword ptr [esp + 0x78], ecx
// 005f1ab3  8954247c             mov dword ptr [esp + 0x7c], edx
// 005f1ab7  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f1abd  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005f1ac4  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005f1acb  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005f1ad2  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f1adb  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f1ae1  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f1aea  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f1af0  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f1af9  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f1aff  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f1b08  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f1b0e  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005f1b15  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005f1b19  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f1b22  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f1b28  89842480000000       mov dword ptr [esp + 0x80], eax
// 005f1b2f  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005f1b36  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005f1b3d  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f1b46  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f1b4c  8d4c2478             lea ecx, [esp + 0x78]
// 005f1b50  89942488000000       mov dword ptr [esp + 0x88], edx
// 005f1b57  8b542464             mov edx, dword ptr [esp + 0x64]
// 005f1b5b  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005f1b62  8b442468             mov eax, dword ptr [esp + 0x68]
// 005f1b66  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f1b6f  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f1b75  8d5e44               lea ebx, [esi + 0x44]
// 005f1b78  51                   push ecx
// 005f1b79  8bcb                 mov ecx, ebx
// 005f1b7b  89942498000000       mov dword ptr [esp + 0x98], edx
// 005f1b82  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005f1b89  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f1b92  e82987ffff           call 0x5ea2c0
// 005f1b97  d94708               fld dword ptr [edi + 8]
// 005f1b9a  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005f1ba3  d95e68               fstp dword ptr [esi + 0x68]
// 005f1ba6  d9470c               fld dword ptr [edi + 0xc]
// 005f1ba9  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f1baf  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005f1bb8  d95e6c               fstp dword ptr [esi + 0x6c]
// 005f1bbb  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f1bc1  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005f1bca  8d94248c010000       lea edx, [esp + 0x18c]
// 005f1bd1  52                   push edx
// 005f1bd2  8d442464             lea eax, [esp + 0x64]
// 005f1bd6  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f1bdc  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005f1be5  50                   push eax
// 005f1be6  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f1bec  e84f5a2300           call 0x827640
// 005f1bf1  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005f1bf8  51                   push ecx
// 005f1bf9  8d9424d8000000       lea edx, [esp + 0xd8]
// 005f1c00  52                   push edx
// 005f1c01  e83a5a2300           call 0x827640
// 005f1c06  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f1c0c  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f1c15  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f1c1b  8d8424d0000000       lea eax, [esp + 0xd0]
// 005f1c22  50                   push eax
// 005f1c23  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005f1c2a  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f1c33  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f1c39  51                   push ecx
// 005f1c3a  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f1c43  e8f8592300           call 0x827640
// 005f1c48  83c418               add esp, 0x18
// 005f1c4b  8d542440             lea edx, [esp + 0x40]
// 005f1c4f  52                   push edx
// 005f1c50  8d8c2430010000       lea ecx, [esp + 0x130]
// 005f1c57  e8e4250400           call 0x634240
// 005f1c5c  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005f1c63  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005f1c6a  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005f1c71  89442478             mov dword ptr [esp + 0x78], eax
// 005f1c75  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005f1c7c  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005f1c80  89942480000000       mov dword ptr [esp + 0x80], edx
// 005f1c87  89842484000000       mov dword ptr [esp + 0x84], eax
// 005f1c8e  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f1c94  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005f1c9b  8b442460             mov eax, dword ptr [esp + 0x60]
// 005f1c9f  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005f1ca6  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f1caf  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f1cb5  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f1cbe  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f1cc4  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f1ccd  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f1cd3  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f1cdc  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f1ce2  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f1ceb  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f1cf1  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005f1cf8  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005f1cfc  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f1d05  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f1d0b  89842490000000       mov dword ptr [esp + 0x90], eax
// 005f1d12  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005f1d19  8b542468             mov edx, dword ptr [esp + 0x68]
// 005f1d1d  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005f1d24  8d442478             lea eax, [esp + 0x78]
// 005f1d28  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f1d31  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f1d37  8d8e88000000         lea ecx, [esi + 0x88]
// 005f1d3d  50                   push eax
// 005f1d3e  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005f1d45  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f1d4e  894c2460             mov dword ptr [esp + 0x60], ecx
// 005f1d52  e86985ffff           call 0x5ea2c0
// 005f1d57  d94710               fld dword ptr [edi + 0x10]
// 005f1d5a  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005f1d63  d99eac000000         fstp dword ptr [esi + 0xac]
// 005f1d69  d94714               fld dword ptr [edi + 0x14]
// 005f1d6c  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f1d72  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005f1d7b  d99eb0000000         fstp dword ptr [esi + 0xb0]
// 005f1d81  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f1d87  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005f1d90  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005f1d97  51                   push ecx
// 005f1d98  8d542464             lea edx, [esp + 0x64]
// 005f1d9c  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f1da2  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005f1dab  52                   push edx
// 005f1dac  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f1db2  e889582300           call 0x827640
// 005f1db7  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005f1dbe  50                   push eax
// 005f1dbf  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005f1dc6  51                   push ecx
// 005f1dc7  e874582300           call 0x827640
// 005f1dcc  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f1dd2  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f1dd9  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f1de2  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f1de8  8d9424d0000000       lea edx, [esp + 0xd0]
// 005f1def  52                   push edx
// 005f1df0  8d8424ec000000       lea eax, [esp + 0xec]
// 005f1df7  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f1e00  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f1e06  50                   push eax
// 005f1e07  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f1e10  e82b582300           call 0x827640
// 005f1e15  83c418               add esp, 0x18
// 005f1e18  8d4c2440             lea ecx, [esp + 0x40]
// 005f1e1c  51                   push ecx
// 005f1e1d  8d8c2420010000       lea ecx, [esp + 0x120]
// 005f1e24  e817240400           call 0x634240
// 005f1e29  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005f1e30  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005f1e37  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005f1e3e  89542478             mov dword ptr [esp + 0x78], edx
// 005f1e42  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005f1e49  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f1e4d  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005f1e54  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f1e5b  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005f1e62  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f1e69  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f1e70  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f1e76  8b542460             mov edx, dword ptr [esp + 0x60]
// 005f1e7a  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f1e7e  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f1e87  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f1e8d  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f1e96  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f1e9c  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f1ea5  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f1eab  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f1eb4  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f1eba  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f1ec3  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f1ec9  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f1ed0  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f1ed4  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f1edd  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f1ee3  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f1eea  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f1ef1  8d542478             lea edx, [esp + 0x78]
// 005f1ef5  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f1efe  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f1f04  8d8ecc000000         lea ecx, [esi + 0xcc]
// 005f1f0a  52                   push edx
// 005f1f0b  89842498000000       mov dword ptr [esp + 0x98], eax
// 005f1f12  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f1f1b  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005f1f22  e89983ffff           call 0x5ea2c0
// 005f1f27  d94718               fld dword ptr [edi + 0x18]
// 005f1f2a  d99ef0000000         fstp dword ptr [esi + 0xf0]
// 005f1f30  56                   push esi
// 005f1f31  d9471c               fld dword ptr [edi + 0x1c]
// 005f1f34  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f1f37  8b07                 mov eax, dword ptr [edi]
// 005f1f39  d99ef4000000         fstp dword ptr [esi + 0xf4]
// 005f1f3f  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f1f42  8bcf                 mov ecx, edi
// 005f1f44  ffd2                 call edx
// 005f1f46  8bf0                 mov esi, eax
// 005f1f48  8b07                 mov eax, dword ptr [edi]
// 005f1f4a  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f1f4d  53                   push ebx
// 005f1f4e  8bcf                 mov ecx, edi
// 005f1f50  ffd2                 call edx
// 005f1f52  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f1f56  8bd8                 mov ebx, eax
// 005f1f58  8b07                 mov eax, dword ptr [edi]
// 005f1f5a  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f1f5d  51                   push ecx
// 005f1f5e  8bcf                 mov ecx, edi
// 005f1f60  ffd2                 call edx
// 005f1f62  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005f1f69  8944243c             mov dword ptr [esp + 0x3c], eax
// 005f1f6d  8b07                 mov eax, dword ptr [edi]
// 005f1f6f  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f1f72  51                   push ecx
// 005f1f73  8bcf                 mov ecx, edi
// 005f1f75  ffd2                 call edx
// 005f1f77  8b17                 mov edx, dword ptr [edi]
// 005f1f79  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f1f7c  50                   push eax
// 005f1f7d  89442460             mov dword ptr [esp + 0x60], eax
// 005f1f81  8b442440             mov eax, dword ptr [esp + 0x40]
// 005f1f85  50                   push eax
// 005f1f86  53                   push ebx
// 005f1f87  56                   push esi
// 005f1f88  8bcf                 mov ecx, edi
// 005f1f8a  ffd2                 call edx
// 005f1f8c  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005f1f8f  85c0                 test eax, eax
// 005f1f91  7413                 je 0x5f1fa6
// 005f1f93  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f1f97  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005f1f9b  8930                 mov dword ptr [eax], esi
// 005f1f9d  895804               mov dword ptr [eax + 4], ebx
// 005f1fa0  894808               mov dword ptr [eax + 8], ecx
// 005f1fa3  89500c               mov dword ptr [eax + 0xc], edx
// 005f1fa6  5f                   pop edi
// 005f1fa7  5e                   pop esi
// 005f1fa8  5b                   pop ebx
// 005f1fa9  8be5                 mov esp, ebp
// 005f1fab  5d                   pop ebp
// 005f1fac  c22000               ret 0x20
// 005f1faf  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f1fb6  743c                 je 0x5f1ff4
// 005f1fb8  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005f1fbc  7536                 jne 0x5f1ff4
// 005f1fbe  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f1fc3  85c0                 test eax, eax
// 005f1fc5  7418                 je 0x5f1fdf
// 005f1fc7  6801010000           push 0x101
// 005f1fcc  688027b800           push 0xb82780
// 005f1fd1  680027b800           push 0xb82700
// 005f1fd6  ffd0                 call eax
// 005f1fd8  83c40c               add esp, 0xc
// 005f1fdb  84c0                 test al, al
// 005f1fdd  7515                 jne 0x5f1ff4
// 005f1fdf  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f1fe6  688826b800           push 0xb82688
// 005f1feb  50                   push eax
// 005f1fec  e89f023800           call 0x972290
// 005f1ff1  83c408               add esp, 8
// 005f1ff4  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005f1ffa  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f2001  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f2009  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005f2011  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005f2016  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005f201c  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005f2024  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005f2029  8d4c2460             lea ecx, [esp + 0x60]
// 005f202d  51                   push ecx
// 005f202e  f30f59c2             mulss xmm0, xmm2
// 005f2032  f30f59ca             mulss xmm1, xmm2
// 005f2036  8d4c2420             lea ecx, [esp + 0x20]
// 005f203a  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f2043  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f204c  e8ef210400           call 0x634240
// 005f2051  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f205a  f30f5e00             divss xmm0, dword ptr [eax]
// 005f205e  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005f2063  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005f2066  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f2069  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f206e  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f2076  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f207c  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005f2085  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f208e  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005f2093  33d2                 xor edx, edx
// 005f2095  33db                 xor ebx, ebx
// 005f2097  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005f20a0  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f20a7  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005f20ae  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005f20b4  0f2fd7               comiss xmm2, xmm7
// 005f20b7  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005f20bd  8954243c             mov dword ptr [esp + 0x3c], edx
// 005f20c1  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005f20ca  770a                 ja 0x5f20d6
// 005f20cc  85d2                 test edx, edx
// 005f20ce  0f85d2feffff         jne 0x5f1fa6
// 005f20d4  eb04                 jmp 0x5f20da
// 005f20d6  85d2                 test edx, edx
// 005f20d8  7504                 jne 0x5f20de
// 005f20da  f30f5cc4             subss xmm0, xmm4
// 005f20de  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f20e2  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f20e6  7421                 je 0x5f2109
// 005f20e8  f30f58c7             addss xmm0, xmm7
// 005f20ec  0f2fc2               comiss xmm0, xmm2
// 005f20ef  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f20f8  8d44241c             lea eax, [esp + 0x1c]
// 005f20fc  7707                 ja 0x5f2105
// 005f20fe  8d84240c030000       lea eax, [esp + 0x30c]
// 005f2105  f30f1010             movss xmm2, dword ptr [eax]
// 005f2109  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005f2112  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f2118  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f211f  f30f58cb             addss xmm1, xmm3
// 005f2123  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005f2128  33c0                 xor eax, eax
// 005f212a  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005f2130  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005f2139  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f2140  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005f2146  0f2ff0               comiss xmm6, xmm0
// 005f2149  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005f2152  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005f2158  7708                 ja 0x5f2162
// 005f215a  85c0                 test eax, eax
// 005f215c  0f852b110000         jne 0x5f328d
// 005f2162  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005f2168  85c0                 test eax, eax
// 005f216a  7504                 jne 0x5f2170
// 005f216c  f30f5ccc             subss xmm1, xmm4
// 005f2170  0f28f1               movaps xmm6, xmm1
// 005f2173  f30f58f0             addss xmm6, xmm0
// 005f2177  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005f217c  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005f2185  8d442420             lea eax, [esp + 0x20]
// 005f2189  7707                 ja 0x5f2192
// 005f218b  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005f2192  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f2196  f30f1000             movss xmm0, dword ptr [eax]
// 005f219a  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005f21a0  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005f21a9  f30f58c3             addss xmm0, xmm3
// 005f21ad  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005f21b6  0f57c0               xorps xmm0, xmm0
// 005f21b9  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005f21bf  740f                 je 0x5f21d0
// 005f21c1  e8ca80ffff           call 0x5ea290
// 005f21c6  d80d94deb600         fmul dword ptr [0xb6de94]
// 005f21cc  d95c2440             fstp dword ptr [esp + 0x40]
// 005f21d0  0f28dd               movaps xmm3, xmm5
// 005f21d3  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005f21dc  0f28c3               movaps xmm0, xmm3
// 005f21df  f30f59c4             mulss xmm0, xmm4
// 005f21e3  f30f5cd7             subss xmm2, xmm7
// 005f21e7  f30f59d3             mulss xmm2, xmm3
// 005f21eb  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005f21f1  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005f21f7  f30f58d3             addss xmm2, xmm3
// 005f21fb  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005f2201  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005f2207  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005f220d  0f28c5               movaps xmm0, xmm5
// 005f2210  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005f2219  0f28e9               movaps xmm5, xmm1
// 005f221c  0f28f0               movaps xmm6, xmm0
// 005f221f  f30f59f4             mulss xmm6, xmm4
// 005f2223  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005f2229  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005f222f  f30f5ccb             subss xmm1, xmm3
// 005f2233  f30f59e8             mulss xmm5, xmm0
// 005f2237  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005f223d  f30f59c8             mulss xmm1, xmm0
// 005f2241  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005f2247  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005f2250  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005f2259  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005f2262  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005f226b  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005f2274  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005f227d  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005f2286  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005f228f  85d2                 test edx, edx
// 005f2291  753f                 jne 0x5f22d2
// 005f2293  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005f2299  0f28c4               movaps xmm0, xmm4
// 005f229c  f30f58c3             addss xmm0, xmm3
// 005f22a0  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005f22a9  0f28c3               movaps xmm0, xmm3
// 005f22ac  f30f58c2             addss xmm0, xmm2
// 005f22b0  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005f22b9  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005f22c2  0f28c4               movaps xmm0, xmm4
// 005f22c5  f30f58c3             addss xmm0, xmm3
// 005f22c9  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005f22d2  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f22d8  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005f22dd  772f                 ja 0x5f230e
// 005f22df  0f28c6               movaps xmm0, xmm6
// 005f22e2  f30f58c5             addss xmm0, xmm5
// 005f22e6  f30f58f1             addss xmm6, xmm1
// 005f22ea  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005f22f3  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005f22fc  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005f2305  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005f230e  8d9424cc000000       lea edx, [esp + 0xcc]
// 005f2315  52                   push edx
// 005f2316  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f231d  e81e1f0400           call 0x634240
// 005f2322  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f2327  f30f1008             movss xmm1, dword ptr [eax]
// 005f232b  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005f2331  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005f2337  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f233e  50                   push eax
// 005f233f  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f2346  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005f234f  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005f2358  e8e31e0400           call 0x634240
// 005f235d  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f2362  f30f1008             movss xmm1, dword ptr [eax]
// 005f2366  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005f236c  f30f584c244c         addss xmm1, dword ptr [esp + 0x4c]
// 005f2372  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005f2379  51                   push ecx
// 005f237a  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f2381  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005f238a  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005f2393  e8a81e0400           call 0x634240
// 005f2398  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005f239e  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f23a3  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005f23a9  f30f5c08             subss xmm1, dword ptr [eax]
// 005f23ad  8d94248c010000       lea edx, [esp + 0x18c]
// 005f23b4  52                   push edx
// 005f23b5  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f23bc  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005f23c5  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005f23ce  e86d1e0400           call 0x634240
// 005f23d3  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f23d9  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f23de  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005f23e4  f30f5c08             subss xmm1, dword ptr [eax]
// 005f23e8  8d842498010000       lea eax, [esp + 0x198]
// 005f23ef  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f23f8  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f2400  50                   push eax
// 005f2401  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005f2408  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005f240e  0f57c0               xorps xmm0, xmm0
// 005f2411  51                   push ecx
// 005f2412  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005f2419  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f2422  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005f2428  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005f242e  e8dd1d0400           call 0x634210
// 005f2433  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005f243c  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005f2445  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005f244e  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005f2457  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f2460  8d9424ec000000       lea edx, [esp + 0xec]
// 005f2467  52                   push edx
// 005f2468  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005f246f  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005f2478  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f2481  50                   push eax
// 005f2482  8d8c2484010000       lea ecx, [esp + 0x184]
// 005f2489  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005f2492  e8791d0400           call 0x634210
// 005f2497  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f24a0  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f24a6  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005f24af  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f24b5  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005f24be  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005f24c4  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f24cd  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f24d3  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005f24dc  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005f24e5  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005f24ee  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f24f7  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f2500  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005f2509  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f2512  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005f251b  8d4c246c             lea ecx, [esp + 0x6c]
// 005f251f  51                   push ecx
// 005f2520  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005f2527  52                   push edx
// 005f2528  e813512300           call 0x827640
// 005f252d  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f2536  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005f253f  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f2548  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005f254f  50                   push eax
// 005f2550  8d8c2484030000       lea ecx, [esp + 0x384]
// 005f2557  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005f2560  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f2568  51                   push ecx
// 005f2569  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005f2572  e8c9502300           call 0x827640
// 005f2577  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f257d  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005f2586  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f258c  8d942470030000       lea edx, [esp + 0x370]
// 005f2593  52                   push edx
// 005f2594  8d842450030000       lea eax, [esp + 0x350]
// 005f259b  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005f25a4  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f25aa  50                   push eax
// 005f25ab  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005f25b4  e887502300           call 0x827640
// 005f25b9  83c418               add esp, 0x18
// 005f25bc  8d8c2430030000       lea ecx, [esp + 0x330]
// 005f25c3  51                   push ecx
// 005f25c4  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005f25cb  e8701c0400           call 0x634240
// 005f25d0  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f25d9  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005f25e0  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005f25e7  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005f25ee  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005f25f7  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f2600  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005f2609  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005f2612  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005f261b  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005f2624  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005f262d  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005f2636  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005f263f  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005f2648  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005f2651  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005f265a  89942448020000       mov dword ptr [esp + 0x248], edx
// 005f2661  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005f2668  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005f2671  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005f267a  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005f2681  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005f2688  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005f2691  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005f269a  89942454020000       mov dword ptr [esp + 0x254], edx
// 005f26a1  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005f26a8  89842458020000       mov dword ptr [esp + 0x258], eax
// 005f26af  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005f26b6  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005f26bf  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005f26c8  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005f26cf  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005f26d6  89942460020000       mov dword ptr [esp + 0x260], edx
// 005f26dd  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005f26e6  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005f26ef  8d54246c             lea edx, [esp + 0x6c]
// 005f26f3  89842464020000       mov dword ptr [esp + 0x264], eax
// 005f26fa  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005f2701  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005f2708  52                   push edx
// 005f2709  8d842470030000       lea eax, [esp + 0x370]
// 005f2710  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005f2719  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005f2722  50                   push eax
// 005f2723  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005f272a  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f2733  e8084f2300           call 0x827640
// 005f2738  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f2741  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005f274a  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f2753  8d8c2498030000       lea ecx, [esp + 0x398]
// 005f275a  51                   push ecx
// 005f275b  8d942460030000       lea edx, [esp + 0x360]
// 005f2762  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005f276b  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f2773  52                   push edx
// 005f2774  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005f277d  e8be4e2300           call 0x827640
// 005f2782  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005f2788  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005f2791  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f2797  8d842400040000       lea eax, [esp + 0x400]
// 005f279e  50                   push eax
// 005f279f  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005f27a6  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005f27af  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f27b5  51                   push ecx
// 005f27b6  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005f27bf  e87c4e2300           call 0x827640
// 005f27c4  83c418               add esp, 0x18
// 005f27c7  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005f27ce  52                   push edx
// 005f27cf  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005f27d6  e8651a0400           call 0x634240
// 005f27db  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005f27e4  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005f27eb  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005f27f2  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005f27f9  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005f2802  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005f280b  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005f2814  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005f281d  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005f2826  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005f282f  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005f2838  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005f2841  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005f284a  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005f2853  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005f285c  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005f2865  89842490020000       mov dword ptr [esp + 0x290], eax
// 005f286c  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005f2873  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005f287c  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005f2885  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005f288c  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005f2893  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005f289c  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005f28a5  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005f28ac  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005f28b3  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005f28ba  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005f28c1  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005f28ca  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005f28d3  89942498020000       mov dword ptr [esp + 0x298], edx
// 005f28da  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005f28e1  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005f28e8  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005f28f1  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005f28fa  8d44246c             lea eax, [esp + 0x6c]
// 005f28fe  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005f2905  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005f290c  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005f2913  50                   push eax
// 005f2914  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005f291b  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005f2924  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005f292d  51                   push ecx
// 005f292e  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005f2935  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005f293e  e8fd4c2300           call 0x827640
// 005f2943  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f294c  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005f2955  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f295e  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005f2967  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f296f  8d94248c030000       lea edx, [esp + 0x38c]
// 005f2976  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005f297f  52                   push edx
// 005f2980  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005f2987  50                   push eax
// 005f2988  e8b34c2300           call 0x827640
// 005f298d  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005f2993  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005f299c  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005f29a2  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005f29a9  51                   push ecx
// 005f29aa  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005f29b1  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005f29ba  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f29c0  52                   push edx
// 005f29c1  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005f29ca  e8714c2300           call 0x827640
// 005f29cf  83c418               add esp, 0x18
// 005f29d2  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005f29d9  50                   push eax
// 005f29da  8d8c2480010000       lea ecx, [esp + 0x180]
// 005f29e1  e85a180400           call 0x634240
// 005f29e6  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005f29ef  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005f29f6  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005f29fd  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005f2a04  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005f2a0d  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005f2a16  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005f2a1f  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005f2a28  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005f2a31  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005f2a3a  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005f2a43  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005f2a4c  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005f2a55  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005f2a5e  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005f2a67  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 005f2a70  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 005f2a77  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 005f2a7e  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 005f2a87  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 005f2a90  89942404020000       mov dword ptr [esp + 0x204], edx
// 005f2a97  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 005f2a9e  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 005f2aa7  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f2aad  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 005f2ab4  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 005f2abb  89942410020000       mov dword ptr [esp + 0x210], edx
// 005f2ac2  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 005f2ac9  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 005f2ad2  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f2ad8  89842408020000       mov dword ptr [esp + 0x208], eax
// 005f2adf  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 005f2ae6  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 005f2aed  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005f2af6  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f2afc  8d4c246c             lea ecx, [esp + 0x6c]
// 005f2b00  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 005f2b07  89842414020000       mov dword ptr [esp + 0x214], eax
// 005f2b0e  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 005f2b15  51                   push ecx
// 005f2b16  8d942410010000       lea edx, [esp + 0x110]
// 005f2b1d  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 005f2b26  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f2b2c  52                   push edx
// 005f2b2d  89842428020000       mov dword ptr [esp + 0x228], eax
// 005f2b34  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f2b3d  e8fe4a2300           call 0x827640
// 005f2b42  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f2b4b  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 005f2b54  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f2b5d  8d842404040000       lea eax, [esp + 0x404]
// 005f2b64  50                   push eax
// 005f2b65  8d8c2438010000       lea ecx, [esp + 0x138]
// 005f2b6c  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 005f2b75  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f2b7d  51                   push ecx
// 005f2b7e  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 005f2b87  e8b44a2300           call 0x827640
// 005f2b8c  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f2b92  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 005f2b9b  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005f2ba1  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005f2baa  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f2bb0  8d9424b8030000       lea edx, [esp + 0x3b8]
// 005f2bb7  52                   push edx
// 005f2bb8  8d842430010000       lea eax, [esp + 0x130]
// 005f2bbf  50                   push eax
// 005f2bc0  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 005f2bc9  e8724a2300           call 0x827640
// 005f2bce  83c418               add esp, 0x18
// 005f2bd1  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 005f2bd8  51                   push ecx
// 005f2bd9  8d4c242c             lea ecx, [esp + 0x2c]
// 005f2bdd  e85e160400           call 0x634240
// 005f2be2  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 005f2beb  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 005f2bf2  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 005f2bf9  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 005f2c00  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f2c09  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 005f2c12  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f2c1b  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 005f2c24  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f2c2d  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 005f2c36  89542478             mov dword ptr [esp + 0x78], edx
// 005f2c3a  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 005f2c41  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f2c45  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005f2c4c  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f2c55  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 005f2c5e  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f2c65  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 005f2c6c  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f2c73  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 005f2c7a  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f2c81  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 005f2c88  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f2c91  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 005f2c9a  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f2ca1  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 005f2ca8  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f2caf  8b17                 mov edx, dword ptr [edi]
// 005f2cb1  8b5210               mov edx, dword ptr [edx + 0x10]
// 005f2cb4  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f2cbd  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 005f2cc6  89842494000000       mov dword ptr [esp + 0x94], eax
// 005f2ccd  8d842448020000       lea eax, [esp + 0x248]
// 005f2cd4  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f2cdb  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f2ce4  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 005f2ced  50                   push eax
// 005f2cee  8bcf                 mov ecx, edi
// 005f2cf0  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f2cf9  ffd2                 call edx
// 005f2cfb  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 005f2d02  8b07                 mov eax, dword ptr [edi]
// 005f2d04  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f2d07  8d8c2490020000       lea ecx, [esp + 0x290]
// 005f2d0e  51                   push ecx
// 005f2d0f  8bcf                 mov ecx, edi
// 005f2d11  ffd2                 call edx
// 005f2d13  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 005f2d1a  8b07                 mov eax, dword ptr [edi]
// 005f2d1c  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f2d1f  8d8c2400020000       lea ecx, [esp + 0x200]
// 005f2d26  51                   push ecx
// 005f2d27  8bcf                 mov ecx, edi
// 005f2d29  ffd2                 call edx
// 005f2d2b  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 005f2d32  8b07                 mov eax, dword ptr [edi]
// 005f2d34  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f2d37  8d4c2478             lea ecx, [esp + 0x78]
// 005f2d3b  51                   push ecx
// 005f2d3c  8bcf                 mov ecx, edi
// 005f2d3e  ffd2                 call edx
// 005f2d40  89842460010000       mov dword ptr [esp + 0x160], eax
// 005f2d47  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005f2d4e  40                   inc eax
// 005f2d4f  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f2d56  3bc3                 cmp eax, ebx
// 005f2d58  8d84246c010000       lea eax, [esp + 0x16c]
// 005f2d5f  7c07                 jl 0x5f2d68
// 005f2d61  8d8424e8000000       lea eax, [esp + 0xe8]
// 005f2d68  8b18                 mov ebx, dword ptr [eax]
// 005f2d6a  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 005f2d71  8bc8                 mov ecx, eax
// 005f2d73  40                   inc eax
// 005f2d74  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f2d7b  85c9                 test ecx, ecx
// 005f2d7d  0f85f9000000         jne 0x5f2e7c
// 005f2d83  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 005f2d8a  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005f2d8d  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 005f2d96  8911                 mov dword ptr [ecx], edx
// 005f2d98  f30f1106             movss dword ptr [esi], xmm0
// 005f2d9c  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 005f2da5  f30f114604           movss dword ptr [esi + 4], xmm0
// 005f2daa  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 005f2db3  f30f114608           movss dword ptr [esi + 8], xmm0
// 005f2db8  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 005f2dc1  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 005f2dc6  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 005f2dcf  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 005f2dd4  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 005f2ddd  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 005f2de2  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 005f2deb  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 005f2df0  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 005f2df9  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 005f2dfe  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 005f2e07  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 005f2e0c  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 005f2e15  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 005f2e1a  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 005f2e23  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 005f2e28  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 005f2e31  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 005f2e36  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 005f2e3f  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 005f2e44  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 005f2e4d  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 005f2e52  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 005f2e5b  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 005f2e60  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 005f2e69  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 005f2e6e  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 005f2e77  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 005f2e7c  8bd3                 mov edx, ebx
// 005f2e7e  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 005f2e83  8d0c9501000000       lea ecx, [edx*4 + 1]
// 005f2e8a  8bd0                 mov edx, eax
// 005f2e8c  40                   inc eax
// 005f2e8d  3bd1                 cmp edx, ecx
// 005f2e8f  0f8501010000         jne 0x5f2f96
// 005f2e95  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005f2e9c  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005f2e9f  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 005f2ea8  894a04               mov dword ptr [edx + 4], ecx
// 005f2eab  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 005f2eb0  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 005f2eb9  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 005f2ebe  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 005f2ec7  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 005f2ecc  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 005f2ed5  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 005f2eda  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 005f2ee3  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 005f2ee8  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 005f2ef1  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 005f2ef6  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 005f2eff  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 005f2f04  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 005f2f0d  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 005f2f12  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 005f2f1b  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 005f2f20  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 005f2f29  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 005f2f2e  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 005f2f37  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 005f2f3c  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 005f2f45  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 005f2f4a  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 005f2f53  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 005f2f58  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 005f2f61  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 005f2f66  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 005f2f6f  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 005f2f74  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 005f2f7d  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 005f2f85  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 005f2f8e  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 005f2f96  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f2f9a  41                   inc ecx
// 005f2f9b  0fafcb               imul ecx, ebx
// 005f2f9e  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 005f2fa5  8bc8                 mov ecx, eax
// 005f2fa7  40                   inc eax
// 005f2fa8  3bca                 cmp ecx, edx
// 005f2faa  0f852e010000         jne 0x5f30de
// 005f2fb0  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 005f2fb7  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005f2fba  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005f2fc3  895108               mov dword ptr [ecx + 8], edx
// 005f2fc6  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 005f2fce  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 005f2fd7  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 005f2fdf  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 005f2fe8  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 005f2ff0  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 005f2ff9  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 005f3001  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 005f300a  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 005f3012  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 005f301b  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 005f3023  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 005f302c  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 005f3034  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 005f303d  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 005f3045  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 005f304e  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 005f3056  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 005f305f  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 005f3067  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 005f3070  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 005f3078  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 005f3081  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 005f3089  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 005f3092  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 005f309a  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 005f30a3  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 005f30ab  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 005f30b4  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 005f30bc  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 005f30c5  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 005f30cd  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 005f30d6  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 005f30de  8bc8                 mov ecx, eax
// 005f30e0  8d149dffffffff       lea edx, [ebx*4 - 1]
// 005f30e7  40                   inc eax
// 005f30e8  89842478010000       mov dword ptr [esp + 0x178], eax
// 005f30ef  3bca                 cmp ecx, edx
// 005f30f1  0f8528010000         jne 0x5f321f
// 005f30f7  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005f30fa  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005f3101  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 005f3107  89420c               mov dword ptr [edx + 0xc], eax
// 005f310a  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 005f3112  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 005f3118  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 005f3120  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 005f3129  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 005f3131  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 005f313a  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 005f3142  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 005f314b  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 005f3153  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 005f315c  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 005f3164  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 005f316d  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 005f3175  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 005f317e  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 005f3186  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 005f318f  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 005f3197  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 005f31a0  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 005f31a8  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 005f31b1  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 005f31b9  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 005f31c2  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 005f31ca  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 005f31d3  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 005f31db  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 005f31e4  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 005f31ec  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 005f31f5  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 005f31fd  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 005f3206  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 005f320e  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 005f3217  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 005f321f  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005f3226  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005f322d  8b17                 mov edx, dword ptr [edi]
// 005f322f  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f3232  50                   push eax
// 005f3233  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 005f323a  51                   push ecx
// 005f323b  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 005f3242  50                   push eax
// 005f3243  51                   push ecx
// 005f3244  8bcf                 mov ecx, edi
// 005f3246  ffd2                 call edx
// 005f3248  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f324e  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 005f3257  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f325f  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 005f3268  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 005f326e  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f3274  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f3279  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005f3280  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f3284  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005f3288  e9b3eeffff           jmp 0x5f2140
// 005f328d  0f28fa               movaps xmm7, xmm2
// 005f3290  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 005f3296  0f28d9               movaps xmm3, xmm1
// 005f3299  42                   inc edx
// 005f329a  e90feeffff           jmp 0x5f20ae
// 005f329f  90                   nop 
// 005f32a0  11155f007c16         adc dword ptr [0x167c005f], edx
// 005f32a6  5f                   pop edi
// 005f32a7  006815               add byte ptr [eax + 0x15], ch
// 005f32aa  5f                   pop edi
// 005f32ab  002e                 add byte ptr [esi], ch
// 005f32ad  16                   push ss
// 005f32ae  5f                   pop edi
// 005f32af  00a6155f00ea         add byte ptr [esi - 0x15ffa0eb], ah

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
