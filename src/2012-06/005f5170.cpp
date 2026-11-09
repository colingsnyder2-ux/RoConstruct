// from server: 10% by intel
// roc 2012-06 005f5170  unit: seg_005f0000  size: 7848 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005f5170
//
// 005f5170  55                   push ebp
// 005f5171  8bec                 mov ebp, esp
// 005f5173  83e4f8               and esp, 0xfffffff8
// 005f5176  81ecfc030000         sub esp, 0x3fc
// 005f517c  53                   push ebx
// 005f517d  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005f5180  56                   push esi
// 005f5181  57                   push edi
// 005f5182  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005f5185  8d44246c             lea eax, [esp + 0x6c]
// 005f5189  8bf1                 mov esi, ecx
// 005f518b  53                   push ebx
// 005f518c  c1ef0f               shr edi, 0xf
// 005f518f  50                   push eax
// 005f5190  89742464             mov dword ptr [esp + 0x64], esi
// 005f5194  83e707               and edi, 7
// 005f5197  e804252300           call 0x8276a0
// 005f519c  d9442474             fld dword ptr [esp + 0x74]
// 005f51a0  d9e1                 fabs 
// 005f51a2  8d4c2474             lea ecx, [esp + 0x74]
// 005f51a6  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005f51ad  53                   push ebx
// 005f51ae  d944247c             fld dword ptr [esp + 0x7c]
// 005f51b2  51                   push ecx
// 005f51b3  d9e1                 fabs 
// 005f51b5  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005f51bc  d9842484000000       fld dword ptr [esp + 0x84]
// 005f51c3  d9e1                 fabs 
// 005f51c5  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005f51cc  e8cf242300           call 0x8276a0
// 005f51d1  d944247c             fld dword ptr [esp + 0x7c]
// 005f51d5  8a4670               mov al, byte ptr [esi + 0x70]
// 005f51d8  d9e1                 fabs 
// 005f51da  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f51e2  d9842480000000       fld dword ptr [esp + 0x80]
// 005f51e9  83c410               add esp, 0x10
// 005f51ec  d9e1                 fabs 
// 005f51ee  d9442474             fld dword ptr [esp + 0x74]
// 005f51f2  d9e1                 fabs 
// 005f51f4  d9450c               fld dword ptr [ebp + 0xc]
// 005f51f7  dceb                 fsub st(3), st(0)
// 005f51f9  d9cb                 fxch st(3)
// 005f51fb  d95c241c             fstp dword ptr [esp + 0x1c]
// 005f51ff  d9c9                 fxch st(1)
// 005f5201  dee2                 fsubrp st(2)
// 005f5203  d9c9                 fxch st(1)
// 005f5205  d95c2420             fstp dword ptr [esp + 0x20]
// 005f5209  d95c2424             fstp dword ptr [esp + 0x24]
// 005f520d  84c0                 test al, al
// 005f520f  741b                 je 0x5f522c
// 005f5211  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005f5219  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005f5222  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005f522a  eb11                 jmp 0x5f523d
// 005f522c  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005f5234  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005f523d  0f57e4               xorps xmm4, xmm4
// 005f5240  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005f5249  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005f524f  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005f5255  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005f525b  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005f5261  83ff05               cmp edi, 5
// 005f5264  0f87a4010000         ja 0x5f540e
// 005f526a  ff24bd00705f00       jmp dword ptr [edi*4 + 0x5f7000]
// 005f5271  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005f5279  8d542460             lea edx, [esp + 0x60]
// 005f527d  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005f5283  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005f528b  52                   push edx
// 005f528c  8d4c2420             lea ecx, [esp + 0x20]
// 005f5290  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005f5296  e8a5ef0300           call 0x634240
// 005f529b  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f52a3  f30f1000             movss xmm0, dword ptr [eax]
// 005f52a7  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005f52ac  0f57e4               xorps xmm4, xmm4
// 005f52af  f30f59c5             mulss xmm0, xmm5
// 005f52b3  f30f59cd             mulss xmm1, xmm5
// 005f52b7  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005f52bd  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005f52c3  e946010000           jmp 0x5f540e
// 005f52c8  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f52d0  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f52d6  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f52dc  84c0                 test al, al
// 005f52de  7413                 je 0x5f52f3
// 005f52e0  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005f52e8  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f52ee  e91b010000           jmp 0x5f540e
// 005f52f3  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005f52fb  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f5301  e908010000           jmp 0x5f540e
// 005f5306  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f530c  84c0                 test al, al
// 005f530e  7419                 je 0x5f5329
// 005f5310  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005f5318  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005f531e  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f5324  e9e5000000           jmp 0x5f540e
// 005f5329  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f5331  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f5337  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005f533f  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f5345  e9c4000000           jmp 0x5f540e
// 005f534a  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f5350  84c0                 test al, al
// 005f5352  7419                 je 0x5f536d
// 005f5354  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005f535c  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005f5362  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f5368  e9a1000000           jmp 0x5f540e
// 005f536d  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f5375  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f537b  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005f5383  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f5389  e980000000           jmp 0x5f540e
// 005f538e  84c0                 test al, al
// 005f5390  745a                 je 0x5f53ec
// 005f5392  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f5399  7441                 je 0x5f53dc
// 005f539b  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f53a0  85c0                 test eax, eax
// 005f53a2  7418                 je 0x5f53bc
// 005f53a4  68b7000000           push 0xb7
// 005f53a9  688027b800           push 0xb82780
// 005f53ae  68cc60b400           push 0xb460cc
// 005f53b3  ffd0                 call eax
// 005f53b5  83c40c               add esp, 0xc
// 005f53b8  84c0                 test al, al
// 005f53ba  7515                 jne 0x5f53d1
// 005f53bc  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f53c3  680827b800           push 0xb82708
// 005f53c8  50                   push eax
// 005f53c9  e8c2ce3700           call 0x972290
// 005f53ce  83c408               add esp, 8
// 005f53d1  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f53d9  0f57e4               xorps xmm4, xmm4
// 005f53dc  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f53e4  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f53ea  eb1c                 jmp 0x5f5408
// 005f53ec  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f53f4  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f53fa  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005f5402  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f5408  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f540e  807e7000             cmp byte ptr [esi + 0x70], 0
// 005f5412  7419                 je 0x5f542d
// 005f5414  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005f5419  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005f5421  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005f5427  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005f542d  85ff                 test edi, edi
// 005f542f  0f85da080000         jne 0x5f5d0f
// 005f5435  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f543d  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005f5442  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005f544a  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005f544f  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005f5455  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005f545e  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f5466  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005f546c  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005f5475  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005f547e  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005f5487  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005f5490  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005f5499  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005f54a2  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005f54ab  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005f54b4  f30f59c5             mulss xmm0, xmm5
// 005f54b8  f30f59cd             mulss xmm1, xmm5
// 005f54bc  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005f54c5  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005f54ce  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005f54d3  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005f54dc  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005f54e5  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005f54ec  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005f54f2  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005f54fb  0f28e3               movaps xmm4, xmm3
// 005f54fe  f30f5ce0             subss xmm4, xmm0
// 005f5502  0f28eb               movaps xmm5, xmm3
// 005f5505  f30f5ce9             subss xmm5, xmm1
// 005f5509  51                   push ecx
// 005f550a  8d542464             lea edx, [esp + 0x64]
// 005f550e  f30f5cc3             subss xmm0, xmm3
// 005f5512  0f28d3               movaps xmm2, xmm3
// 005f5515  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005f551c  f30f5ccb             subss xmm1, xmm3
// 005f5520  52                   push edx
// 005f5521  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005f552a  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005f5533  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005f553c  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005f5545  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005f554e  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005f5557  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005f5560  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005f5569  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005f5572  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005f557b  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005f5584  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005f558d  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005f5596  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005f559f  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005f55a8  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005f55b1  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005f55ba  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005f55c3  e8d8202300           call 0x8276a0
// 005f55c8  8d442474             lea eax, [esp + 0x74]
// 005f55cc  50                   push eax
// 005f55cd  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005f55d4  51                   push ecx
// 005f55d5  e8c6202300           call 0x8276a0
// 005f55da  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005f55e2  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005f55e8  0f57c8               xorps xmm1, xmm0
// 005f55eb  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005f55f4  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005f55fa  8d9424d0000000       lea edx, [esp + 0xd0]
// 005f5601  0f57c8               xorps xmm1, xmm0
// 005f5604  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f560a  52                   push edx
// 005f560b  8d8424ec000000       lea eax, [esp + 0xec]
// 005f5612  50                   push eax
// 005f5613  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005f561c  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f5625  e876202300           call 0x8276a0
// 005f562a  83c418               add esp, 0x18
// 005f562d  8d4c2440             lea ecx, [esp + 0x40]
// 005f5631  51                   push ecx
// 005f5632  8d8c2480010000       lea ecx, [esp + 0x180]
// 005f5639  e802ec0300           call 0x634240
// 005f563e  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005f5645  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f564b  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005f5652  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005f5659  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005f565c  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f5665  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f566b  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f5674  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f567a  89542478             mov dword ptr [esp + 0x78], edx
// 005f567e  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005f5685  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f568e  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f5694  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f569b  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005f56a2  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f56a9  8b542460             mov edx, dword ptr [esp + 0x60]
// 005f56ad  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f56b6  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005f56bb  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f56bf  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005f56c6  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f56cd  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f56d1  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f56da  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f56e3  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f56ec  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f56f3  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f56fa  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f56fe  8d542478             lea edx, [esp + 0x78]
// 005f5702  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f5709  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f5712  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f571b  52                   push edx
// 005f571c  8bce                 mov ecx, esi
// 005f571e  89842498000000       mov dword ptr [esp + 0x98], eax
// 005f5725  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f572e  e88d4bffff           call 0x5ea2c0
// 005f5733  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005f573c  8b7d24               mov edi, dword ptr [ebp + 0x24]
// 005f573f  d907                 fld dword ptr [edi]
// 005f5741  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f5747  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005f5750  d95e24               fstp dword ptr [esi + 0x24]
// 005f5753  d94704               fld dword ptr [edi + 4]
// 005f5756  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f575c  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005f5765  d95e28               fstp dword ptr [esi + 0x28]
// 005f5768  8d84248c010000       lea eax, [esp + 0x18c]
// 005f576f  50                   push eax
// 005f5770  8d4c2464             lea ecx, [esp + 0x64]
// 005f5774  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f577a  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005f5783  51                   push ecx
// 005f5784  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f578a  e8111f2300           call 0x8276a0
// 005f578f  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005f5796  52                   push edx
// 005f5797  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f579e  50                   push eax
// 005f579f  e8fc1e2300           call 0x8276a0
// 005f57a4  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f57aa  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f57b3  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f57b9  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f57c0  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005f57c7  51                   push ecx
// 005f57c8  8d9424ec000000       lea edx, [esp + 0xec]
// 005f57cf  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f57d8  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f57de  52                   push edx
// 005f57df  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f57e8  e8b31e2300           call 0x8276a0
// 005f57ed  83c418               add esp, 0x18
// 005f57f0  8d442440             lea eax, [esp + 0x40]
// 005f57f4  50                   push eax
// 005f57f5  8d8c2410010000       lea ecx, [esp + 0x110]
// 005f57fc  e83fea0300           call 0x634240
// 005f5801  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005f5808  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005f580f  894c2478             mov dword ptr [esp + 0x78], ecx
// 005f5813  8954247c             mov dword ptr [esp + 0x7c], edx
// 005f5817  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f581d  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005f5824  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005f582b  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005f5832  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f583b  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f5841  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f584a  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f5850  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f5859  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f585f  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f5868  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f586e  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005f5875  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005f5879  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f5882  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f5888  89842480000000       mov dword ptr [esp + 0x80], eax
// 005f588f  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005f5896  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005f589d  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f58a6  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f58ac  8d4c2478             lea ecx, [esp + 0x78]
// 005f58b0  89942488000000       mov dword ptr [esp + 0x88], edx
// 005f58b7  8b542464             mov edx, dword ptr [esp + 0x64]
// 005f58bb  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005f58c2  8b442468             mov eax, dword ptr [esp + 0x68]
// 005f58c6  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f58cf  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f58d5  8d5e44               lea ebx, [esi + 0x44]
// 005f58d8  51                   push ecx
// 005f58d9  8bcb                 mov ecx, ebx
// 005f58db  89942498000000       mov dword ptr [esp + 0x98], edx
// 005f58e2  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005f58e9  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f58f2  e8c949ffff           call 0x5ea2c0
// 005f58f7  d94708               fld dword ptr [edi + 8]
// 005f58fa  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005f5903  d95e68               fstp dword ptr [esi + 0x68]
// 005f5906  d9470c               fld dword ptr [edi + 0xc]
// 005f5909  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f590f  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005f5918  d95e6c               fstp dword ptr [esi + 0x6c]
// 005f591b  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f5921  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005f592a  8d94248c010000       lea edx, [esp + 0x18c]
// 005f5931  52                   push edx
// 005f5932  8d442464             lea eax, [esp + 0x64]
// 005f5936  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f593c  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005f5945  50                   push eax
// 005f5946  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f594c  e84f1d2300           call 0x8276a0
// 005f5951  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005f5958  51                   push ecx
// 005f5959  8d9424d8000000       lea edx, [esp + 0xd8]
// 005f5960  52                   push edx
// 005f5961  e83a1d2300           call 0x8276a0
// 005f5966  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f596c  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f5975  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f597b  8d8424d0000000       lea eax, [esp + 0xd0]
// 005f5982  50                   push eax
// 005f5983  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005f598a  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f5993  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f5999  51                   push ecx
// 005f599a  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f59a3  e8f81c2300           call 0x8276a0
// 005f59a8  83c418               add esp, 0x18
// 005f59ab  8d542440             lea edx, [esp + 0x40]
// 005f59af  52                   push edx
// 005f59b0  8d8c2430010000       lea ecx, [esp + 0x130]
// 005f59b7  e884e80300           call 0x634240
// 005f59bc  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005f59c3  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005f59ca  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005f59d1  89442478             mov dword ptr [esp + 0x78], eax
// 005f59d5  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005f59dc  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005f59e0  89942480000000       mov dword ptr [esp + 0x80], edx
// 005f59e7  89842484000000       mov dword ptr [esp + 0x84], eax
// 005f59ee  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f59f4  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005f59fb  8b442460             mov eax, dword ptr [esp + 0x60]
// 005f59ff  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005f5a06  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f5a0f  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f5a15  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f5a1e  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f5a24  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f5a2d  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f5a33  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f5a3c  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f5a42  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f5a4b  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f5a51  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005f5a58  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005f5a5c  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f5a65  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f5a6b  89842490000000       mov dword ptr [esp + 0x90], eax
// 005f5a72  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005f5a79  8b542468             mov edx, dword ptr [esp + 0x68]
// 005f5a7d  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005f5a84  8d442478             lea eax, [esp + 0x78]
// 005f5a88  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f5a91  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f5a97  8d8e88000000         lea ecx, [esi + 0x88]
// 005f5a9d  50                   push eax
// 005f5a9e  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005f5aa5  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f5aae  894c2460             mov dword ptr [esp + 0x60], ecx
// 005f5ab2  e80948ffff           call 0x5ea2c0
// 005f5ab7  d94710               fld dword ptr [edi + 0x10]
// 005f5aba  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005f5ac3  d99eac000000         fstp dword ptr [esi + 0xac]
// 005f5ac9  d94714               fld dword ptr [edi + 0x14]
// 005f5acc  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f5ad2  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005f5adb  d99eb0000000         fstp dword ptr [esi + 0xb0]
// 005f5ae1  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f5ae7  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005f5af0  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005f5af7  51                   push ecx
// 005f5af8  8d542464             lea edx, [esp + 0x64]
// 005f5afc  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f5b02  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005f5b0b  52                   push edx
// 005f5b0c  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f5b12  e8891b2300           call 0x8276a0
// 005f5b17  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005f5b1e  50                   push eax
// 005f5b1f  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005f5b26  51                   push ecx
// 005f5b27  e8741b2300           call 0x8276a0
// 005f5b2c  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f5b32  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f5b39  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f5b42  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f5b48  8d9424d0000000       lea edx, [esp + 0xd0]
// 005f5b4f  52                   push edx
// 005f5b50  8d8424ec000000       lea eax, [esp + 0xec]
// 005f5b57  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f5b60  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f5b66  50                   push eax
// 005f5b67  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f5b70  e82b1b2300           call 0x8276a0
// 005f5b75  83c418               add esp, 0x18
// 005f5b78  8d4c2440             lea ecx, [esp + 0x40]
// 005f5b7c  51                   push ecx
// 005f5b7d  8d8c2420010000       lea ecx, [esp + 0x120]
// 005f5b84  e8b7e60300           call 0x634240
// 005f5b89  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005f5b90  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005f5b97  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005f5b9e  89542478             mov dword ptr [esp + 0x78], edx
// 005f5ba2  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005f5ba9  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f5bad  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005f5bb4  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f5bbb  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005f5bc2  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f5bc9  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f5bd0  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f5bd6  8b542460             mov edx, dword ptr [esp + 0x60]
// 005f5bda  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f5bde  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f5be7  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f5bed  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f5bf6  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f5bfc  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f5c05  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f5c0b  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f5c14  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f5c1a  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f5c23  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f5c29  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f5c30  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f5c34  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f5c3d  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f5c43  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f5c4a  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f5c51  8d542478             lea edx, [esp + 0x78]
// 005f5c55  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f5c5e  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f5c64  8d8ecc000000         lea ecx, [esi + 0xcc]
// 005f5c6a  52                   push edx
// 005f5c6b  89842498000000       mov dword ptr [esp + 0x98], eax
// 005f5c72  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f5c7b  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005f5c82  e83946ffff           call 0x5ea2c0
// 005f5c87  d94718               fld dword ptr [edi + 0x18]
// 005f5c8a  d99ef0000000         fstp dword ptr [esi + 0xf0]
// 005f5c90  56                   push esi
// 005f5c91  d9471c               fld dword ptr [edi + 0x1c]
// 005f5c94  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f5c97  8b07                 mov eax, dword ptr [edi]
// 005f5c99  d99ef4000000         fstp dword ptr [esi + 0xf4]
// 005f5c9f  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f5ca2  8bcf                 mov ecx, edi
// 005f5ca4  ffd2                 call edx
// 005f5ca6  8bf0                 mov esi, eax
// 005f5ca8  8b07                 mov eax, dword ptr [edi]
// 005f5caa  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f5cad  53                   push ebx
// 005f5cae  8bcf                 mov ecx, edi
// 005f5cb0  ffd2                 call edx
// 005f5cb2  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f5cb6  8bd8                 mov ebx, eax
// 005f5cb8  8b07                 mov eax, dword ptr [edi]
// 005f5cba  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f5cbd  51                   push ecx
// 005f5cbe  8bcf                 mov ecx, edi
// 005f5cc0  ffd2                 call edx
// 005f5cc2  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005f5cc9  8944243c             mov dword ptr [esp + 0x3c], eax
// 005f5ccd  8b07                 mov eax, dword ptr [edi]
// 005f5ccf  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f5cd2  51                   push ecx
// 005f5cd3  8bcf                 mov ecx, edi
// 005f5cd5  ffd2                 call edx
// 005f5cd7  8b17                 mov edx, dword ptr [edi]
// 005f5cd9  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f5cdc  50                   push eax
// 005f5cdd  89442460             mov dword ptr [esp + 0x60], eax
// 005f5ce1  8b442440             mov eax, dword ptr [esp + 0x40]
// 005f5ce5  50                   push eax
// 005f5ce6  53                   push ebx
// 005f5ce7  56                   push esi
// 005f5ce8  8bcf                 mov ecx, edi
// 005f5cea  ffd2                 call edx
// 005f5cec  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005f5cef  85c0                 test eax, eax
// 005f5cf1  7413                 je 0x5f5d06
// 005f5cf3  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f5cf7  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005f5cfb  8930                 mov dword ptr [eax], esi
// 005f5cfd  895804               mov dword ptr [eax + 4], ebx
// 005f5d00  894808               mov dword ptr [eax + 8], ecx
// 005f5d03  89500c               mov dword ptr [eax + 0xc], edx
// 005f5d06  5f                   pop edi
// 005f5d07  5e                   pop esi
// 005f5d08  5b                   pop ebx
// 005f5d09  8be5                 mov esp, ebp
// 005f5d0b  5d                   pop ebp
// 005f5d0c  c22000               ret 0x20
// 005f5d0f  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f5d16  743c                 je 0x5f5d54
// 005f5d18  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005f5d1c  7536                 jne 0x5f5d54
// 005f5d1e  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f5d23  85c0                 test eax, eax
// 005f5d25  7418                 je 0x5f5d3f
// 005f5d27  6801010000           push 0x101
// 005f5d2c  688027b800           push 0xb82780
// 005f5d31  680027b800           push 0xb82700
// 005f5d36  ffd0                 call eax
// 005f5d38  83c40c               add esp, 0xc
// 005f5d3b  84c0                 test al, al
// 005f5d3d  7515                 jne 0x5f5d54
// 005f5d3f  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f5d46  688826b800           push 0xb82688
// 005f5d4b  50                   push eax
// 005f5d4c  e83fc53700           call 0x972290
// 005f5d51  83c408               add esp, 8
// 005f5d54  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005f5d5a  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f5d61  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f5d69  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005f5d71  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005f5d76  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005f5d7c  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005f5d84  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005f5d89  8d4c2460             lea ecx, [esp + 0x60]
// 005f5d8d  51                   push ecx
// 005f5d8e  f30f59c2             mulss xmm0, xmm2
// 005f5d92  f30f59ca             mulss xmm1, xmm2
// 005f5d96  8d4c2420             lea ecx, [esp + 0x20]
// 005f5d9a  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f5da3  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f5dac  e88fe40300           call 0x634240
// 005f5db1  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f5dba  f30f5e00             divss xmm0, dword ptr [eax]
// 005f5dbe  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005f5dc3  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005f5dc6  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f5dc9  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f5dce  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f5dd6  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f5ddc  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005f5de5  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f5dee  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005f5df3  33d2                 xor edx, edx
// 005f5df5  33db                 xor ebx, ebx
// 005f5df7  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005f5e00  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f5e07  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005f5e0e  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005f5e14  0f2fd7               comiss xmm2, xmm7
// 005f5e17  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005f5e1d  8954243c             mov dword ptr [esp + 0x3c], edx
// 005f5e21  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005f5e2a  770a                 ja 0x5f5e36
// 005f5e2c  85d2                 test edx, edx
// 005f5e2e  0f85d2feffff         jne 0x5f5d06
// 005f5e34  eb04                 jmp 0x5f5e3a
// 005f5e36  85d2                 test edx, edx
// 005f5e38  7504                 jne 0x5f5e3e
// 005f5e3a  f30f5cc4             subss xmm0, xmm4
// 005f5e3e  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f5e42  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f5e46  7421                 je 0x5f5e69
// 005f5e48  f30f58c7             addss xmm0, xmm7
// 005f5e4c  0f2fc2               comiss xmm0, xmm2
// 005f5e4f  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f5e58  8d44241c             lea eax, [esp + 0x1c]
// 005f5e5c  7707                 ja 0x5f5e65
// 005f5e5e  8d84240c030000       lea eax, [esp + 0x30c]
// 005f5e65  f30f1010             movss xmm2, dword ptr [eax]
// 005f5e69  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005f5e72  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f5e78  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f5e7f  f30f58cb             addss xmm1, xmm3
// 005f5e83  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005f5e88  33c0                 xor eax, eax
// 005f5e8a  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005f5e90  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005f5e99  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f5ea0  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005f5ea6  0f2ff0               comiss xmm6, xmm0
// 005f5ea9  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005f5eb2  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005f5eb8  7708                 ja 0x5f5ec2
// 005f5eba  85c0                 test eax, eax
// 005f5ebc  0f852b110000         jne 0x5f6fed
// 005f5ec2  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005f5ec8  85c0                 test eax, eax
// 005f5eca  7504                 jne 0x5f5ed0
// 005f5ecc  f30f5ccc             subss xmm1, xmm4
// 005f5ed0  0f28f1               movaps xmm6, xmm1
// 005f5ed3  f30f58f0             addss xmm6, xmm0
// 005f5ed7  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005f5edc  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005f5ee5  8d442420             lea eax, [esp + 0x20]
// 005f5ee9  7707                 ja 0x5f5ef2
// 005f5eeb  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005f5ef2  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f5ef6  f30f1000             movss xmm0, dword ptr [eax]
// 005f5efa  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005f5f00  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005f5f09  f30f58c3             addss xmm0, xmm3
// 005f5f0d  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005f5f16  0f57c0               xorps xmm0, xmm0
// 005f5f19  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005f5f1f  740f                 je 0x5f5f30
// 005f5f21  e86a43ffff           call 0x5ea290
// 005f5f26  d80d94deb600         fmul dword ptr [0xb6de94]
// 005f5f2c  d95c2440             fstp dword ptr [esp + 0x40]
// 005f5f30  0f28dd               movaps xmm3, xmm5
// 005f5f33  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005f5f3c  0f28c3               movaps xmm0, xmm3
// 005f5f3f  f30f59c4             mulss xmm0, xmm4
// 005f5f43  f30f5cd7             subss xmm2, xmm7
// 005f5f47  f30f59d3             mulss xmm2, xmm3
// 005f5f4b  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005f5f51  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005f5f57  f30f58d3             addss xmm2, xmm3
// 005f5f5b  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005f5f61  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005f5f67  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005f5f6d  0f28c5               movaps xmm0, xmm5
// 005f5f70  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005f5f79  0f28e9               movaps xmm5, xmm1
// 005f5f7c  0f28f0               movaps xmm6, xmm0
// 005f5f7f  f30f59f4             mulss xmm6, xmm4
// 005f5f83  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005f5f89  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005f5f8f  f30f5ccb             subss xmm1, xmm3
// 005f5f93  f30f59e8             mulss xmm5, xmm0
// 005f5f97  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005f5f9d  f30f59c8             mulss xmm1, xmm0
// 005f5fa1  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005f5fa7  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005f5fb0  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005f5fb9  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005f5fc2  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005f5fcb  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005f5fd4  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005f5fdd  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005f5fe6  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005f5fef  85d2                 test edx, edx
// 005f5ff1  753f                 jne 0x5f6032
// 005f5ff3  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005f5ff9  0f28c4               movaps xmm0, xmm4
// 005f5ffc  f30f58c3             addss xmm0, xmm3
// 005f6000  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005f6009  0f28c3               movaps xmm0, xmm3
// 005f600c  f30f58c2             addss xmm0, xmm2
// 005f6010  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005f6019  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005f6022  0f28c4               movaps xmm0, xmm4
// 005f6025  f30f58c3             addss xmm0, xmm3
// 005f6029  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005f6032  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f6038  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005f603d  772f                 ja 0x5f606e
// 005f603f  0f28c6               movaps xmm0, xmm6
// 005f6042  f30f58c5             addss xmm0, xmm5
// 005f6046  f30f58f1             addss xmm6, xmm1
// 005f604a  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005f6053  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005f605c  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005f6065  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005f606e  8d9424cc000000       lea edx, [esp + 0xcc]
// 005f6075  52                   push edx
// 005f6076  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f607d  e8bee10300           call 0x634240
// 005f6082  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f6087  f30f1008             movss xmm1, dword ptr [eax]
// 005f608b  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005f6091  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005f6097  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f609e  50                   push eax
// 005f609f  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f60a6  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005f60af  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005f60b8  e883e10300           call 0x634240
// 005f60bd  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f60c2  f30f1008             movss xmm1, dword ptr [eax]
// 005f60c6  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005f60cc  f30f584c244c         addss xmm1, dword ptr [esp + 0x4c]
// 005f60d2  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005f60d9  51                   push ecx
// 005f60da  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f60e1  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005f60ea  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005f60f3  e848e10300           call 0x634240
// 005f60f8  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005f60fe  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f6103  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005f6109  f30f5c08             subss xmm1, dword ptr [eax]
// 005f610d  8d94248c010000       lea edx, [esp + 0x18c]
// 005f6114  52                   push edx
// 005f6115  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f611c  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005f6125  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005f612e  e80de10300           call 0x634240
// 005f6133  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f6139  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f613e  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005f6144  f30f5c08             subss xmm1, dword ptr [eax]
// 005f6148  8d842498010000       lea eax, [esp + 0x198]
// 005f614f  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f6158  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f6160  50                   push eax
// 005f6161  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005f6168  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005f616e  0f57c0               xorps xmm0, xmm0
// 005f6171  51                   push ecx
// 005f6172  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005f6179  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f6182  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005f6188  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005f618e  e87de00300           call 0x634210
// 005f6193  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005f619c  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005f61a5  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005f61ae  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005f61b7  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f61c0  8d9424ec000000       lea edx, [esp + 0xec]
// 005f61c7  52                   push edx
// 005f61c8  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005f61cf  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005f61d8  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f61e1  50                   push eax
// 005f61e2  8d8c2484010000       lea ecx, [esp + 0x184]
// 005f61e9  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005f61f2  e819e00300           call 0x634210
// 005f61f7  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f6200  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f6206  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005f620f  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f6215  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005f621e  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005f6224  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f622d  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f6233  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005f623c  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005f6245  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005f624e  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f6257  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f6260  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005f6269  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f6272  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005f627b  8d4c246c             lea ecx, [esp + 0x6c]
// 005f627f  51                   push ecx
// 005f6280  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005f6287  52                   push edx
// 005f6288  e813142300           call 0x8276a0
// 005f628d  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f6296  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005f629f  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f62a8  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005f62af  50                   push eax
// 005f62b0  8d8c2484030000       lea ecx, [esp + 0x384]
// 005f62b7  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005f62c0  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f62c8  51                   push ecx
// 005f62c9  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005f62d2  e8c9132300           call 0x8276a0
// 005f62d7  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f62dd  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005f62e6  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f62ec  8d942470030000       lea edx, [esp + 0x370]
// 005f62f3  52                   push edx
// 005f62f4  8d842450030000       lea eax, [esp + 0x350]
// 005f62fb  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005f6304  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f630a  50                   push eax
// 005f630b  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005f6314  e887132300           call 0x8276a0
// 005f6319  83c418               add esp, 0x18
// 005f631c  8d8c2430030000       lea ecx, [esp + 0x330]
// 005f6323  51                   push ecx
// 005f6324  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005f632b  e810df0300           call 0x634240
// 005f6330  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f6339  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005f6340  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005f6347  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005f634e  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005f6357  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f6360  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005f6369  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005f6372  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005f637b  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005f6384  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005f638d  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005f6396  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005f639f  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005f63a8  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005f63b1  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005f63ba  89942448020000       mov dword ptr [esp + 0x248], edx
// 005f63c1  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005f63c8  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005f63d1  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005f63da  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005f63e1  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005f63e8  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005f63f1  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005f63fa  89942454020000       mov dword ptr [esp + 0x254], edx
// 005f6401  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005f6408  89842458020000       mov dword ptr [esp + 0x258], eax
// 005f640f  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005f6416  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005f641f  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005f6428  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005f642f  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005f6436  89942460020000       mov dword ptr [esp + 0x260], edx
// 005f643d  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005f6446  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005f644f  8d54246c             lea edx, [esp + 0x6c]
// 005f6453  89842464020000       mov dword ptr [esp + 0x264], eax
// 005f645a  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005f6461  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005f6468  52                   push edx
// 005f6469  8d842470030000       lea eax, [esp + 0x370]
// 005f6470  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005f6479  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005f6482  50                   push eax
// 005f6483  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005f648a  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f6493  e808122300           call 0x8276a0
// 005f6498  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f64a1  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005f64aa  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f64b3  8d8c2498030000       lea ecx, [esp + 0x398]
// 005f64ba  51                   push ecx
// 005f64bb  8d942460030000       lea edx, [esp + 0x360]
// 005f64c2  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005f64cb  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f64d3  52                   push edx
// 005f64d4  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005f64dd  e8be112300           call 0x8276a0
// 005f64e2  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005f64e8  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005f64f1  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f64f7  8d842400040000       lea eax, [esp + 0x400]
// 005f64fe  50                   push eax
// 005f64ff  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005f6506  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005f650f  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f6515  51                   push ecx
// 005f6516  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005f651f  e87c112300           call 0x8276a0
// 005f6524  83c418               add esp, 0x18
// 005f6527  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005f652e  52                   push edx
// 005f652f  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005f6536  e805dd0300           call 0x634240
// 005f653b  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005f6544  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005f654b  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005f6552  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005f6559  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005f6562  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005f656b  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005f6574  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005f657d  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005f6586  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005f658f  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005f6598  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005f65a1  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005f65aa  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005f65b3  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005f65bc  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005f65c5  89842490020000       mov dword ptr [esp + 0x290], eax
// 005f65cc  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005f65d3  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005f65dc  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005f65e5  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005f65ec  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005f65f3  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005f65fc  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005f6605  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005f660c  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005f6613  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005f661a  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005f6621  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005f662a  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005f6633  89942498020000       mov dword ptr [esp + 0x298], edx
// 005f663a  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005f6641  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005f6648  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005f6651  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005f665a  8d44246c             lea eax, [esp + 0x6c]
// 005f665e  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005f6665  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005f666c  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005f6673  50                   push eax
// 005f6674  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005f667b  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005f6684  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005f668d  51                   push ecx
// 005f668e  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005f6695  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005f669e  e8fd0f2300           call 0x8276a0
// 005f66a3  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f66ac  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005f66b5  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f66be  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005f66c7  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f66cf  8d94248c030000       lea edx, [esp + 0x38c]
// 005f66d6  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005f66df  52                   push edx
// 005f66e0  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005f66e7  50                   push eax
// 005f66e8  e8b30f2300           call 0x8276a0
// 005f66ed  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005f66f3  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005f66fc  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005f6702  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005f6709  51                   push ecx
// 005f670a  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005f6711  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005f671a  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f6720  52                   push edx
// 005f6721  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005f672a  e8710f2300           call 0x8276a0
// 005f672f  83c418               add esp, 0x18
// 005f6732  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005f6739  50                   push eax
// 005f673a  8d8c2480010000       lea ecx, [esp + 0x180]
// 005f6741  e8fada0300           call 0x634240
// 005f6746  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005f674f  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005f6756  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005f675d  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005f6764  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005f676d  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005f6776  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005f677f  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005f6788  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005f6791  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005f679a  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005f67a3  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005f67ac  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005f67b5  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005f67be  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005f67c7  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 005f67d0  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 005f67d7  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 005f67de  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 005f67e7  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 005f67f0  89942404020000       mov dword ptr [esp + 0x204], edx
// 005f67f7  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 005f67fe  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 005f6807  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f680d  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 005f6814  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 005f681b  89942410020000       mov dword ptr [esp + 0x210], edx
// 005f6822  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 005f6829  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 005f6832  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f6838  89842408020000       mov dword ptr [esp + 0x208], eax
// 005f683f  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 005f6846  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 005f684d  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005f6856  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f685c  8d4c246c             lea ecx, [esp + 0x6c]
// 005f6860  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 005f6867  89842414020000       mov dword ptr [esp + 0x214], eax
// 005f686e  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 005f6875  51                   push ecx
// 005f6876  8d942410010000       lea edx, [esp + 0x110]
// 005f687d  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 005f6886  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f688c  52                   push edx
// 005f688d  89842428020000       mov dword ptr [esp + 0x228], eax
// 005f6894  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f689d  e8fe0d2300           call 0x8276a0
// 005f68a2  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f68ab  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 005f68b4  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f68bd  8d842404040000       lea eax, [esp + 0x404]
// 005f68c4  50                   push eax
// 005f68c5  8d8c2438010000       lea ecx, [esp + 0x138]
// 005f68cc  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 005f68d5  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f68dd  51                   push ecx
// 005f68de  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 005f68e7  e8b40d2300           call 0x8276a0
// 005f68ec  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f68f2  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 005f68fb  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005f6901  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005f690a  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f6910  8d9424b8030000       lea edx, [esp + 0x3b8]
// 005f6917  52                   push edx
// 005f6918  8d842430010000       lea eax, [esp + 0x130]
// 005f691f  50                   push eax
// 005f6920  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 005f6929  e8720d2300           call 0x8276a0
// 005f692e  83c418               add esp, 0x18
// 005f6931  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 005f6938  51                   push ecx
// 005f6939  8d4c242c             lea ecx, [esp + 0x2c]
// 005f693d  e8fed80300           call 0x634240
// 005f6942  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 005f694b  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 005f6952  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 005f6959  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 005f6960  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f6969  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 005f6972  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f697b  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 005f6984  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f698d  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 005f6996  89542478             mov dword ptr [esp + 0x78], edx
// 005f699a  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 005f69a1  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f69a5  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005f69ac  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f69b5  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 005f69be  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f69c5  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 005f69cc  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f69d3  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 005f69da  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f69e1  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 005f69e8  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f69f1  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 005f69fa  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f6a01  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 005f6a08  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f6a0f  8b17                 mov edx, dword ptr [edi]
// 005f6a11  8b5210               mov edx, dword ptr [edx + 0x10]
// 005f6a14  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f6a1d  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 005f6a26  89842494000000       mov dword ptr [esp + 0x94], eax
// 005f6a2d  8d842448020000       lea eax, [esp + 0x248]
// 005f6a34  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f6a3b  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f6a44  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 005f6a4d  50                   push eax
// 005f6a4e  8bcf                 mov ecx, edi
// 005f6a50  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f6a59  ffd2                 call edx
// 005f6a5b  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 005f6a62  8b07                 mov eax, dword ptr [edi]
// 005f6a64  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f6a67  8d8c2490020000       lea ecx, [esp + 0x290]
// 005f6a6e  51                   push ecx
// 005f6a6f  8bcf                 mov ecx, edi
// 005f6a71  ffd2                 call edx
// 005f6a73  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 005f6a7a  8b07                 mov eax, dword ptr [edi]
// 005f6a7c  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f6a7f  8d8c2400020000       lea ecx, [esp + 0x200]
// 005f6a86  51                   push ecx
// 005f6a87  8bcf                 mov ecx, edi
// 005f6a89  ffd2                 call edx
// 005f6a8b  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 005f6a92  8b07                 mov eax, dword ptr [edi]
// 005f6a94  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f6a97  8d4c2478             lea ecx, [esp + 0x78]
// 005f6a9b  51                   push ecx
// 005f6a9c  8bcf                 mov ecx, edi
// 005f6a9e  ffd2                 call edx
// 005f6aa0  89842460010000       mov dword ptr [esp + 0x160], eax
// 005f6aa7  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005f6aae  40                   inc eax
// 005f6aaf  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f6ab6  3bc3                 cmp eax, ebx
// 005f6ab8  8d84246c010000       lea eax, [esp + 0x16c]
// 005f6abf  7c07                 jl 0x5f6ac8
// 005f6ac1  8d8424e8000000       lea eax, [esp + 0xe8]
// 005f6ac8  8b18                 mov ebx, dword ptr [eax]
// 005f6aca  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 005f6ad1  8bc8                 mov ecx, eax
// 005f6ad3  40                   inc eax
// 005f6ad4  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f6adb  85c9                 test ecx, ecx
// 005f6add  0f85f9000000         jne 0x5f6bdc
// 005f6ae3  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 005f6aea  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005f6aed  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 005f6af6  8911                 mov dword ptr [ecx], edx
// 005f6af8  f30f1106             movss dword ptr [esi], xmm0
// 005f6afc  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 005f6b05  f30f114604           movss dword ptr [esi + 4], xmm0
// 005f6b0a  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 005f6b13  f30f114608           movss dword ptr [esi + 8], xmm0
// 005f6b18  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 005f6b21  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 005f6b26  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 005f6b2f  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 005f6b34  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 005f6b3d  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 005f6b42  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 005f6b4b  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 005f6b50  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 005f6b59  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 005f6b5e  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 005f6b67  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 005f6b6c  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 005f6b75  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 005f6b7a  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 005f6b83  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 005f6b88  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 005f6b91  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 005f6b96  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 005f6b9f  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 005f6ba4  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 005f6bad  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 005f6bb2  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 005f6bbb  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 005f6bc0  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 005f6bc9  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 005f6bce  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 005f6bd7  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 005f6bdc  8bd3                 mov edx, ebx
// 005f6bde  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 005f6be3  8d0c9501000000       lea ecx, [edx*4 + 1]
// 005f6bea  8bd0                 mov edx, eax
// 005f6bec  40                   inc eax
// 005f6bed  3bd1                 cmp edx, ecx
// 005f6bef  0f8501010000         jne 0x5f6cf6
// 005f6bf5  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005f6bfc  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005f6bff  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 005f6c08  894a04               mov dword ptr [edx + 4], ecx
// 005f6c0b  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 005f6c10  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 005f6c19  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 005f6c1e  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 005f6c27  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 005f6c2c  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 005f6c35  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 005f6c3a  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 005f6c43  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 005f6c48  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 005f6c51  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 005f6c56  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 005f6c5f  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 005f6c64  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 005f6c6d  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 005f6c72  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 005f6c7b  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 005f6c80  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 005f6c89  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 005f6c8e  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 005f6c97  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 005f6c9c  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 005f6ca5  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 005f6caa  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 005f6cb3  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 005f6cb8  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 005f6cc1  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 005f6cc6  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 005f6ccf  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 005f6cd4  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 005f6cdd  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 005f6ce5  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 005f6cee  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 005f6cf6  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f6cfa  41                   inc ecx
// 005f6cfb  0fafcb               imul ecx, ebx
// 005f6cfe  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 005f6d05  8bc8                 mov ecx, eax
// 005f6d07  40                   inc eax
// 005f6d08  3bca                 cmp ecx, edx
// 005f6d0a  0f852e010000         jne 0x5f6e3e
// 005f6d10  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 005f6d17  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005f6d1a  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005f6d23  895108               mov dword ptr [ecx + 8], edx
// 005f6d26  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 005f6d2e  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 005f6d37  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 005f6d3f  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 005f6d48  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 005f6d50  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 005f6d59  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 005f6d61  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 005f6d6a  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 005f6d72  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 005f6d7b  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 005f6d83  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 005f6d8c  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 005f6d94  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 005f6d9d  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 005f6da5  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 005f6dae  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 005f6db6  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 005f6dbf  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 005f6dc7  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 005f6dd0  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 005f6dd8  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 005f6de1  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 005f6de9  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 005f6df2  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 005f6dfa  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 005f6e03  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 005f6e0b  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 005f6e14  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 005f6e1c  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 005f6e25  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 005f6e2d  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 005f6e36  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 005f6e3e  8bc8                 mov ecx, eax
// 005f6e40  8d149dffffffff       lea edx, [ebx*4 - 1]
// 005f6e47  40                   inc eax
// 005f6e48  89842478010000       mov dword ptr [esp + 0x178], eax
// 005f6e4f  3bca                 cmp ecx, edx
// 005f6e51  0f8528010000         jne 0x5f6f7f
// 005f6e57  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005f6e5a  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005f6e61  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 005f6e67  89420c               mov dword ptr [edx + 0xc], eax
// 005f6e6a  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 005f6e72  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 005f6e78  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 005f6e80  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 005f6e89  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 005f6e91  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 005f6e9a  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 005f6ea2  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 005f6eab  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 005f6eb3  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 005f6ebc  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 005f6ec4  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 005f6ecd  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 005f6ed5  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 005f6ede  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 005f6ee6  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 005f6eef  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 005f6ef7  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 005f6f00  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 005f6f08  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 005f6f11  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 005f6f19  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 005f6f22  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 005f6f2a  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 005f6f33  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 005f6f3b  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 005f6f44  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 005f6f4c  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 005f6f55  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 005f6f5d  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 005f6f66  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 005f6f6e  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 005f6f77  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 005f6f7f  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005f6f86  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005f6f8d  8b17                 mov edx, dword ptr [edi]
// 005f6f8f  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f6f92  50                   push eax
// 005f6f93  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 005f6f9a  51                   push ecx
// 005f6f9b  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 005f6fa2  50                   push eax
// 005f6fa3  51                   push ecx
// 005f6fa4  8bcf                 mov ecx, edi
// 005f6fa6  ffd2                 call edx
// 005f6fa8  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f6fae  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 005f6fb7  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f6fbf  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 005f6fc8  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 005f6fce  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f6fd4  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f6fd9  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005f6fe0  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f6fe4  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005f6fe8  e9b3eeffff           jmp 0x5f5ea0
// 005f6fed  0f28fa               movaps xmm7, xmm2
// 005f6ff0  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 005f6ff6  0f28d9               movaps xmm3, xmm1
// 005f6ff9  42                   inc edx
// 005f6ffa  e90feeffff           jmp 0x5f5e0e
// 005f6fff  90                   nop 
// 005f7000  7152                 jno 0x5f7054
// 005f7002  5f                   pop edi
// 005f7003  00dc                 add ah, bl
// 005f7005  53                   push ebx
// 005f7006  5f                   pop edi
// 005f7007  00c8                 add al, cl
// 005f7009  52                   push edx
// 005f700a  5f                   pop edi
// 005f700b  008e535f0006         add byte ptr [esi + 0x6005f53], cl
// 005f7011  53                   push ebx
// 005f7012  5f                   pop edi
// 005f7013  004a53               add byte ptr [edx + 0x53], cl
// 005f7016  5f                   pop edi

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
