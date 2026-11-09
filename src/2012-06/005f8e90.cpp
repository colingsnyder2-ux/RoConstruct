// from server: 11% by intel
// roc 2012-06 005f8e90  unit: seg_005f0000  size: 7788 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005f8e90
//
// 005f8e90  55                   push ebp
// 005f8e91  8bec                 mov ebp, esp
// 005f8e93  83e4f8               and esp, 0xfffffff8
// 005f8e96  81ecfc030000         sub esp, 0x3fc
// 005f8e9c  53                   push ebx
// 005f8e9d  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005f8ea0  56                   push esi
// 005f8ea1  57                   push edi
// 005f8ea2  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005f8ea5  8d44246c             lea eax, [esp + 0x6c]
// 005f8ea9  8bf1                 mov esi, ecx
// 005f8eab  53                   push ebx
// 005f8eac  c1ef03               shr edi, 3
// 005f8eaf  50                   push eax
// 005f8eb0  89742464             mov dword ptr [esp + 0x64], esi
// 005f8eb4  83e707               and edi, 7
// 005f8eb7  e834e72200           call 0x8275f0
// 005f8ebc  d9442474             fld dword ptr [esp + 0x74]
// 005f8ec0  d9e1                 fabs 
// 005f8ec2  8d4c2474             lea ecx, [esp + 0x74]
// 005f8ec6  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005f8ecd  53                   push ebx
// 005f8ece  d944247c             fld dword ptr [esp + 0x7c]
// 005f8ed2  51                   push ecx
// 005f8ed3  d9e1                 fabs 
// 005f8ed5  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005f8edc  d9842484000000       fld dword ptr [esp + 0x84]
// 005f8ee3  d9e1                 fabs 
// 005f8ee5  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005f8eec  e8ffe62200           call 0x8275f0
// 005f8ef1  d944247c             fld dword ptr [esp + 0x7c]
// 005f8ef5  8a4670               mov al, byte ptr [esi + 0x70]
// 005f8ef8  d9e1                 fabs 
// 005f8efa  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f8f02  d9842480000000       fld dword ptr [esp + 0x80]
// 005f8f09  83c410               add esp, 0x10
// 005f8f0c  d9e1                 fabs 
// 005f8f0e  d9442474             fld dword ptr [esp + 0x74]
// 005f8f12  d9e1                 fabs 
// 005f8f14  d9450c               fld dword ptr [ebp + 0xc]
// 005f8f17  dceb                 fsub st(3), st(0)
// 005f8f19  d9cb                 fxch st(3)
// 005f8f1b  d95c241c             fstp dword ptr [esp + 0x1c]
// 005f8f1f  d9c9                 fxch st(1)
// 005f8f21  dee2                 fsubrp st(2)
// 005f8f23  d9c9                 fxch st(1)
// 005f8f25  d95c2420             fstp dword ptr [esp + 0x20]
// 005f8f29  d95c2424             fstp dword ptr [esp + 0x24]
// 005f8f2d  84c0                 test al, al
// 005f8f2f  741b                 je 0x5f8f4c
// 005f8f31  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005f8f39  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005f8f42  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005f8f4a  eb11                 jmp 0x5f8f5d
// 005f8f4c  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005f8f54  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005f8f5d  0f57e4               xorps xmm4, xmm4
// 005f8f60  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005f8f69  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005f8f6f  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005f8f75  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005f8f7b  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005f8f81  83ff05               cmp edi, 5
// 005f8f84  0f87a4010000         ja 0x5f912e
// 005f8f8a  ff24bde4ac5f00       jmp dword ptr [edi*4 + 0x5face4]
// 005f8f91  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005f8f99  8d542460             lea edx, [esp + 0x60]
// 005f8f9d  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005f8fa3  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005f8fab  52                   push edx
// 005f8fac  8d4c2420             lea ecx, [esp + 0x20]
// 005f8fb0  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005f8fb6  e885b20300           call 0x634240
// 005f8fbb  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f8fc3  f30f1000             movss xmm0, dword ptr [eax]
// 005f8fc7  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005f8fcc  0f57e4               xorps xmm4, xmm4
// 005f8fcf  f30f59c5             mulss xmm0, xmm5
// 005f8fd3  f30f59cd             mulss xmm1, xmm5
// 005f8fd7  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005f8fdd  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005f8fe3  e946010000           jmp 0x5f912e
// 005f8fe8  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f8ff0  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f8ff6  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f8ffc  84c0                 test al, al
// 005f8ffe  7413                 je 0x5f9013
// 005f9000  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005f9008  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f900e  e91b010000           jmp 0x5f912e
// 005f9013  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005f901b  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f9021  e908010000           jmp 0x5f912e
// 005f9026  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f902c  84c0                 test al, al
// 005f902e  7419                 je 0x5f9049
// 005f9030  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005f9038  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005f903e  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f9044  e9e5000000           jmp 0x5f912e
// 005f9049  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f9051  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f9057  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005f905f  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f9065  e9c4000000           jmp 0x5f912e
// 005f906a  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f9070  84c0                 test al, al
// 005f9072  7419                 je 0x5f908d
// 005f9074  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005f907c  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005f9082  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f9088  e9a1000000           jmp 0x5f912e
// 005f908d  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f9095  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f909b  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005f90a3  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f90a9  e980000000           jmp 0x5f912e
// 005f90ae  84c0                 test al, al
// 005f90b0  745a                 je 0x5f910c
// 005f90b2  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f90b9  7441                 je 0x5f90fc
// 005f90bb  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f90c0  85c0                 test eax, eax
// 005f90c2  7418                 je 0x5f90dc
// 005f90c4  68b7000000           push 0xb7
// 005f90c9  688027b800           push 0xb82780
// 005f90ce  68cc60b400           push 0xb460cc
// 005f90d3  ffd0                 call eax
// 005f90d5  83c40c               add esp, 0xc
// 005f90d8  84c0                 test al, al
// 005f90da  7515                 jne 0x5f90f1
// 005f90dc  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f90e3  680827b800           push 0xb82708
// 005f90e8  50                   push eax
// 005f90e9  e8a2913700           call 0x972290
// 005f90ee  83c408               add esp, 8
// 005f90f1  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f90f9  0f57e4               xorps xmm4, xmm4
// 005f90fc  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f9104  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f910a  eb1c                 jmp 0x5f9128
// 005f910c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f9114  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f911a  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005f9122  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f9128  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f912e  807e7000             cmp byte ptr [esi + 0x70], 0
// 005f9132  7419                 je 0x5f914d
// 005f9134  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005f9139  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005f9141  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005f9147  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005f914d  85ff                 test edi, edi
// 005f914f  0f859c080000         jne 0x5f99f1
// 005f9155  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f915d  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005f9162  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005f916a  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005f916f  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005f9175  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005f917e  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f9186  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005f918c  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005f9195  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005f919e  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005f91a7  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005f91b0  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005f91b9  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005f91c2  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005f91cb  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005f91d4  f30f59c5             mulss xmm0, xmm5
// 005f91d8  f30f59cd             mulss xmm1, xmm5
// 005f91dc  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005f91e5  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005f91ee  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005f91f3  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005f91fc  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005f9205  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005f920c  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005f9212  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005f921b  0f28e3               movaps xmm4, xmm3
// 005f921e  f30f5ce0             subss xmm4, xmm0
// 005f9222  0f28eb               movaps xmm5, xmm3
// 005f9225  f30f5ce9             subss xmm5, xmm1
// 005f9229  51                   push ecx
// 005f922a  8d542464             lea edx, [esp + 0x64]
// 005f922e  f30f5cc3             subss xmm0, xmm3
// 005f9232  0f28d3               movaps xmm2, xmm3
// 005f9235  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005f923c  f30f5ccb             subss xmm1, xmm3
// 005f9240  52                   push edx
// 005f9241  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005f924a  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005f9253  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005f925c  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005f9265  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005f926e  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005f9277  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005f9280  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005f9289  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005f9292  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005f929b  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005f92a4  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005f92ad  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005f92b6  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005f92bf  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005f92c8  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005f92d1  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005f92da  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005f92e3  e808e32200           call 0x8275f0
// 005f92e8  8d442474             lea eax, [esp + 0x74]
// 005f92ec  50                   push eax
// 005f92ed  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005f92f4  51                   push ecx
// 005f92f5  e8f6e22200           call 0x8275f0
// 005f92fa  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005f9302  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005f9308  0f57c8               xorps xmm1, xmm0
// 005f930b  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005f9314  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005f931a  8d9424d0000000       lea edx, [esp + 0xd0]
// 005f9321  0f57c8               xorps xmm1, xmm0
// 005f9324  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f932a  52                   push edx
// 005f932b  8d8424ec000000       lea eax, [esp + 0xec]
// 005f9332  50                   push eax
// 005f9333  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005f933c  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f9345  e8a6e22200           call 0x8275f0
// 005f934a  83c418               add esp, 0x18
// 005f934d  8d4c2440             lea ecx, [esp + 0x40]
// 005f9351  51                   push ecx
// 005f9352  8d8c2480010000       lea ecx, [esp + 0x180]
// 005f9359  e8e2ae0300           call 0x634240
// 005f935e  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005f9365  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f936b  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005f9372  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005f9379  8b7d20               mov edi, dword ptr [ebp + 0x20]
// 005f937c  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f9385  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f938b  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f9394  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f939a  89542478             mov dword ptr [esp + 0x78], edx
// 005f939e  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005f93a5  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f93ae  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f93b4  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f93bb  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005f93c2  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f93c9  8b542460             mov edx, dword ptr [esp + 0x60]
// 005f93cd  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f93d6  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005f93db  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f93df  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005f93e6  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f93ed  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f93f1  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f93fa  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f9403  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f940c  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f9413  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f941a  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f941e  8d542478             lea edx, [esp + 0x78]
// 005f9422  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f9429  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f9432  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f943b  52                   push edx
// 005f943c  8bcf                 mov ecx, edi
// 005f943e  89842498000000       mov dword ptr [esp + 0x98], eax
// 005f9445  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f944e  e86d0effff           call 0x5ea2c0
// 005f9453  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005f945c  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f9462  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005f946b  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f9471  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005f947a  8d84248c010000       lea eax, [esp + 0x18c]
// 005f9481  50                   push eax
// 005f9482  8d4c2464             lea ecx, [esp + 0x64]
// 005f9486  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f948c  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005f9495  51                   push ecx
// 005f9496  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f949c  e84fe12200           call 0x8275f0
// 005f94a1  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005f94a8  52                   push edx
// 005f94a9  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f94b0  50                   push eax
// 005f94b1  e83ae12200           call 0x8275f0
// 005f94b6  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f94bc  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f94c5  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f94cb  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f94d2  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005f94d9  51                   push ecx
// 005f94da  8d9424ec000000       lea edx, [esp + 0xec]
// 005f94e1  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f94ea  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f94f0  52                   push edx
// 005f94f1  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f94fa  e8f1e02200           call 0x8275f0
// 005f94ff  83c418               add esp, 0x18
// 005f9502  8d442440             lea eax, [esp + 0x40]
// 005f9506  50                   push eax
// 005f9507  8d8c2410010000       lea ecx, [esp + 0x110]
// 005f950e  e82dad0300           call 0x634240
// 005f9513  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005f951a  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005f9521  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005f9528  894c2478             mov dword ptr [esp + 0x78], ecx
// 005f952c  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005f9533  8954247c             mov dword ptr [esp + 0x7c], edx
// 005f9537  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005f953e  89842480000000       mov dword ptr [esp + 0x80], eax
// 005f9545  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005f954c  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f9552  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005f9556  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005f955d  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f9566  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f956c  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f9575  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f957b  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f9584  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f958a  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f9593  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f9599  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f95a2  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f95a8  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005f95af  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f95b8  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f95be  8d4c2478             lea ecx, [esp + 0x78]
// 005f95c2  89942488000000       mov dword ptr [esp + 0x88], edx
// 005f95c9  8b542464             mov edx, dword ptr [esp + 0x64]
// 005f95cd  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005f95d4  8b442468             mov eax, dword ptr [esp + 0x68]
// 005f95d8  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f95e1  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f95e7  8d5f44               lea ebx, [edi + 0x44]
// 005f95ea  51                   push ecx
// 005f95eb  8bcb                 mov ecx, ebx
// 005f95ed  89942498000000       mov dword ptr [esp + 0x98], edx
// 005f95f4  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005f95fb  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f9604  e8b70cffff           call 0x5ea2c0
// 005f9609  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005f9612  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f9618  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005f9621  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f9627  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005f9630  8d94248c010000       lea edx, [esp + 0x18c]
// 005f9637  52                   push edx
// 005f9638  8d442464             lea eax, [esp + 0x64]
// 005f963c  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f9642  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005f964b  50                   push eax
// 005f964c  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f9652  e899df2200           call 0x8275f0
// 005f9657  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005f965e  51                   push ecx
// 005f965f  8d9424d8000000       lea edx, [esp + 0xd8]
// 005f9666  52                   push edx
// 005f9667  e884df2200           call 0x8275f0
// 005f966c  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f9672  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f967b  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f9681  8d8424d0000000       lea eax, [esp + 0xd0]
// 005f9688  50                   push eax
// 005f9689  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005f9690  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f9699  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f969f  51                   push ecx
// 005f96a0  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f96a9  e842df2200           call 0x8275f0
// 005f96ae  83c418               add esp, 0x18
// 005f96b1  8d542440             lea edx, [esp + 0x40]
// 005f96b5  52                   push edx
// 005f96b6  8d8c2430010000       lea ecx, [esp + 0x130]
// 005f96bd  e87eab0300           call 0x634240
// 005f96c2  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005f96c9  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005f96d0  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005f96d7  89442478             mov dword ptr [esp + 0x78], eax
// 005f96db  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005f96e2  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005f96e6  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005f96ed  89942480000000       mov dword ptr [esp + 0x80], edx
// 005f96f4  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005f96fb  89842484000000       mov dword ptr [esp + 0x84], eax
// 005f9702  8b442460             mov eax, dword ptr [esp + 0x60]
// 005f9706  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005f970d  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005f9711  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005f9718  8b542468             mov edx, dword ptr [esp + 0x68]
// 005f971c  89842490000000       mov dword ptr [esp + 0x90], eax
// 005f9723  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005f972a  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f9730  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f9739  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f973f  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f9748  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f974e  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f9757  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f975d  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f9766  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f976c  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f9775  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f977b  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f9784  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f978a  8d442478             lea eax, [esp + 0x78]
// 005f978e  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f9797  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f979d  8d8f88000000         lea ecx, [edi + 0x88]
// 005f97a3  50                   push eax
// 005f97a4  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005f97ab  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f97b4  894c2460             mov dword ptr [esp + 0x60], ecx
// 005f97b8  e8030bffff           call 0x5ea2c0
// 005f97bd  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005f97c6  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f97cc  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005f97d5  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f97db  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005f97e4  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005f97eb  51                   push ecx
// 005f97ec  8d542464             lea edx, [esp + 0x64]
// 005f97f0  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f97f6  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005f97ff  52                   push edx
// 005f9800  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f9806  e8e5dd2200           call 0x8275f0
// 005f980b  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005f9812  50                   push eax
// 005f9813  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005f981a  51                   push ecx
// 005f981b  e8d0dd2200           call 0x8275f0
// 005f9820  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f9826  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f982d  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f9836  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f983c  8d9424d0000000       lea edx, [esp + 0xd0]
// 005f9843  52                   push edx
// 005f9844  8d8424ec000000       lea eax, [esp + 0xec]
// 005f984b  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f9854  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f985a  50                   push eax
// 005f985b  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f9864  e887dd2200           call 0x8275f0
// 005f9869  83c418               add esp, 0x18
// 005f986c  8d4c2440             lea ecx, [esp + 0x40]
// 005f9870  51                   push ecx
// 005f9871  8d8c2420010000       lea ecx, [esp + 0x120]
// 005f9878  e8c3a90300           call 0x634240
// 005f987d  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005f9884  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005f988b  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005f9892  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f9898  89542478             mov dword ptr [esp + 0x78], edx
// 005f989c  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005f98a3  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f98a7  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005f98ae  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f98b5  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005f98bc  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f98c5  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f98cb  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f98d2  8b542460             mov edx, dword ptr [esp + 0x60]
// 005f98d6  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f98dd  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f98e1  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f98e8  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f98ec  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f98f5  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f98fb  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f9902  89842494000000       mov dword ptr [esp + 0x94], eax
// 005f9909  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f9910  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f9919  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f991f  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f9928  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f992e  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f9937  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f993d  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f9946  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f994c  8d542478             lea edx, [esp + 0x78]
// 005f9950  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f9959  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f995f  8d8fcc000000         lea ecx, [edi + 0xcc]
// 005f9965  52                   push edx
// 005f9966  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f996f  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005f9976  e84509ffff           call 0x5ea2c0
// 005f997b  8b7518               mov esi, dword ptr [ebp + 0x18]
// 005f997e  8b06                 mov eax, dword ptr [esi]
// 005f9980  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f9983  57                   push edi
// 005f9984  8bce                 mov ecx, esi
// 005f9986  ffd2                 call edx
// 005f9988  8bf8                 mov edi, eax
// 005f998a  8b06                 mov eax, dword ptr [esi]
// 005f998c  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f998f  53                   push ebx
// 005f9990  8bce                 mov ecx, esi
// 005f9992  ffd2                 call edx
// 005f9994  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f9998  8bd8                 mov ebx, eax
// 005f999a  8b06                 mov eax, dword ptr [esi]
// 005f999c  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f999f  51                   push ecx
// 005f99a0  8bce                 mov ecx, esi
// 005f99a2  ffd2                 call edx
// 005f99a4  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005f99ab  8944243c             mov dword ptr [esp + 0x3c], eax
// 005f99af  8b06                 mov eax, dword ptr [esi]
// 005f99b1  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f99b4  51                   push ecx
// 005f99b5  8bce                 mov ecx, esi
// 005f99b7  ffd2                 call edx
// 005f99b9  8b16                 mov edx, dword ptr [esi]
// 005f99bb  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f99be  50                   push eax
// 005f99bf  89442460             mov dword ptr [esp + 0x60], eax
// 005f99c3  8b442440             mov eax, dword ptr [esp + 0x40]
// 005f99c7  50                   push eax
// 005f99c8  53                   push ebx
// 005f99c9  57                   push edi
// 005f99ca  8bce                 mov ecx, esi
// 005f99cc  ffd2                 call edx
// 005f99ce  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005f99d1  85c0                 test eax, eax
// 005f99d3  7413                 je 0x5f99e8
// 005f99d5  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f99d9  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005f99dd  8938                 mov dword ptr [eax], edi
// 005f99df  895804               mov dword ptr [eax + 4], ebx
// 005f99e2  894808               mov dword ptr [eax + 8], ecx
// 005f99e5  89500c               mov dword ptr [eax + 0xc], edx
// 005f99e8  5f                   pop edi
// 005f99e9  5e                   pop esi
// 005f99ea  5b                   pop ebx
// 005f99eb  8be5                 mov esp, ebp
// 005f99ed  5d                   pop ebp
// 005f99ee  c22000               ret 0x20
// 005f99f1  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f99f8  743c                 je 0x5f9a36
// 005f99fa  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005f99fe  7536                 jne 0x5f9a36
// 005f9a00  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f9a05  85c0                 test eax, eax
// 005f9a07  7418                 je 0x5f9a21
// 005f9a09  6801010000           push 0x101
// 005f9a0e  688027b800           push 0xb82780
// 005f9a13  680027b800           push 0xb82700
// 005f9a18  ffd0                 call eax
// 005f9a1a  83c40c               add esp, 0xc
// 005f9a1d  84c0                 test al, al
// 005f9a1f  7515                 jne 0x5f9a36
// 005f9a21  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f9a28  688826b800           push 0xb82688
// 005f9a2d  50                   push eax
// 005f9a2e  e85d883700           call 0x972290
// 005f9a33  83c408               add esp, 8
// 005f9a36  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005f9a3c  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f9a43  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f9a4b  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005f9a53  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005f9a58  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005f9a5e  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005f9a66  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005f9a6b  8d4c2460             lea ecx, [esp + 0x60]
// 005f9a6f  51                   push ecx
// 005f9a70  f30f59c2             mulss xmm0, xmm2
// 005f9a74  f30f59ca             mulss xmm1, xmm2
// 005f9a78  8d4c2420             lea ecx, [esp + 0x20]
// 005f9a7c  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f9a85  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f9a8e  e8ada70300           call 0x634240
// 005f9a93  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f9a9c  f30f5e00             divss xmm0, dword ptr [eax]
// 005f9aa0  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005f9aa5  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005f9aa8  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f9aab  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f9ab0  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f9ab8  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f9abe  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005f9ac7  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f9ad0  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005f9ad5  33d2                 xor edx, edx
// 005f9ad7  33db                 xor ebx, ebx
// 005f9ad9  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005f9ae2  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f9ae9  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005f9af0  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005f9af6  0f2fd7               comiss xmm2, xmm7
// 005f9af9  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005f9aff  8954243c             mov dword ptr [esp + 0x3c], edx
// 005f9b03  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005f9b0c  770a                 ja 0x5f9b18
// 005f9b0e  85d2                 test edx, edx
// 005f9b10  0f85d2feffff         jne 0x5f99e8
// 005f9b16  eb04                 jmp 0x5f9b1c
// 005f9b18  85d2                 test edx, edx
// 005f9b1a  7504                 jne 0x5f9b20
// 005f9b1c  f30f5cc4             subss xmm0, xmm4
// 005f9b20  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f9b24  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f9b28  7421                 je 0x5f9b4b
// 005f9b2a  f30f58c7             addss xmm0, xmm7
// 005f9b2e  0f2fc2               comiss xmm0, xmm2
// 005f9b31  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f9b3a  8d44241c             lea eax, [esp + 0x1c]
// 005f9b3e  7707                 ja 0x5f9b47
// 005f9b40  8d84240c030000       lea eax, [esp + 0x30c]
// 005f9b47  f30f1010             movss xmm2, dword ptr [eax]
// 005f9b4b  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005f9b54  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f9b5a  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f9b61  f30f58cb             addss xmm1, xmm3
// 005f9b65  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005f9b6a  33c0                 xor eax, eax
// 005f9b6c  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005f9b72  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005f9b7b  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f9b82  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005f9b88  0f2ff0               comiss xmm6, xmm0
// 005f9b8b  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005f9b94  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005f9b9a  7708                 ja 0x5f9ba4
// 005f9b9c  85c0                 test eax, eax
// 005f9b9e  0f852b110000         jne 0x5faccf
// 005f9ba4  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005f9baa  85c0                 test eax, eax
// 005f9bac  7504                 jne 0x5f9bb2
// 005f9bae  f30f5ccc             subss xmm1, xmm4
// 005f9bb2  0f28f1               movaps xmm6, xmm1
// 005f9bb5  f30f58f0             addss xmm6, xmm0
// 005f9bb9  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005f9bbe  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005f9bc7  8d442420             lea eax, [esp + 0x20]
// 005f9bcb  7707                 ja 0x5f9bd4
// 005f9bcd  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005f9bd4  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f9bd8  f30f1000             movss xmm0, dword ptr [eax]
// 005f9bdc  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005f9be2  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005f9beb  f30f58c3             addss xmm0, xmm3
// 005f9bef  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005f9bf8  0f57c0               xorps xmm0, xmm0
// 005f9bfb  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005f9c01  740f                 je 0x5f9c12
// 005f9c03  e88806ffff           call 0x5ea290
// 005f9c08  d80d94deb600         fmul dword ptr [0xb6de94]
// 005f9c0e  d95c2440             fstp dword ptr [esp + 0x40]
// 005f9c12  0f28dd               movaps xmm3, xmm5
// 005f9c15  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005f9c1e  0f28c3               movaps xmm0, xmm3
// 005f9c21  f30f59c4             mulss xmm0, xmm4
// 005f9c25  f30f5cd7             subss xmm2, xmm7
// 005f9c29  f30f59d3             mulss xmm2, xmm3
// 005f9c2d  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005f9c33  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005f9c39  f30f58d3             addss xmm2, xmm3
// 005f9c3d  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005f9c43  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005f9c49  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005f9c4f  0f28c5               movaps xmm0, xmm5
// 005f9c52  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005f9c5b  0f28e9               movaps xmm5, xmm1
// 005f9c5e  0f28f0               movaps xmm6, xmm0
// 005f9c61  f30f59f4             mulss xmm6, xmm4
// 005f9c65  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005f9c6b  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005f9c71  f30f5ccb             subss xmm1, xmm3
// 005f9c75  f30f59e8             mulss xmm5, xmm0
// 005f9c79  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005f9c7f  f30f59c8             mulss xmm1, xmm0
// 005f9c83  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005f9c89  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005f9c92  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005f9c9b  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005f9ca4  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005f9cad  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005f9cb6  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005f9cbf  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005f9cc8  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005f9cd1  85d2                 test edx, edx
// 005f9cd3  753f                 jne 0x5f9d14
// 005f9cd5  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005f9cdb  0f28c4               movaps xmm0, xmm4
// 005f9cde  f30f58c3             addss xmm0, xmm3
// 005f9ce2  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005f9ceb  0f28c3               movaps xmm0, xmm3
// 005f9cee  f30f58c2             addss xmm0, xmm2
// 005f9cf2  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005f9cfb  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005f9d04  0f28c4               movaps xmm0, xmm4
// 005f9d07  f30f58c3             addss xmm0, xmm3
// 005f9d0b  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005f9d14  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f9d1a  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005f9d1f  772f                 ja 0x5f9d50
// 005f9d21  0f28c6               movaps xmm0, xmm6
// 005f9d24  f30f58c5             addss xmm0, xmm5
// 005f9d28  f30f58f1             addss xmm6, xmm1
// 005f9d2c  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005f9d35  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005f9d3e  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005f9d47  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005f9d50  8d9424cc000000       lea edx, [esp + 0xcc]
// 005f9d57  52                   push edx
// 005f9d58  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f9d5f  e8dca40300           call 0x634240
// 005f9d64  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f9d69  f30f1008             movss xmm1, dword ptr [eax]
// 005f9d6d  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005f9d73  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005f9d79  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f9d80  50                   push eax
// 005f9d81  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f9d88  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005f9d91  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005f9d9a  e8a1a40300           call 0x634240
// 005f9d9f  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f9da4  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005f9daa  f30f5808             addss xmm1, dword ptr [eax]
// 005f9dae  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005f9db4  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005f9dbb  51                   push ecx
// 005f9dbc  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f9dc3  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005f9dcc  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005f9dd5  e866a40300           call 0x634240
// 005f9dda  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005f9de0  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f9de5  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005f9deb  f30f5c08             subss xmm1, dword ptr [eax]
// 005f9def  8d94248c010000       lea edx, [esp + 0x18c]
// 005f9df6  52                   push edx
// 005f9df7  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f9dfe  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005f9e07  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005f9e10  e82ba40300           call 0x634240
// 005f9e15  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f9e1b  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f9e20  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005f9e26  f30f5c08             subss xmm1, dword ptr [eax]
// 005f9e2a  8d842498010000       lea eax, [esp + 0x198]
// 005f9e31  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f9e3a  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f9e42  50                   push eax
// 005f9e43  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005f9e4a  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005f9e50  0f57c0               xorps xmm0, xmm0
// 005f9e53  51                   push ecx
// 005f9e54  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005f9e5b  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f9e64  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005f9e6a  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005f9e70  e89ba30300           call 0x634210
// 005f9e75  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005f9e7e  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005f9e87  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005f9e90  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005f9e99  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f9ea2  8d9424ec000000       lea edx, [esp + 0xec]
// 005f9ea9  52                   push edx
// 005f9eaa  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005f9eb1  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005f9eba  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f9ec3  50                   push eax
// 005f9ec4  8d8c2484010000       lea ecx, [esp + 0x184]
// 005f9ecb  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005f9ed4  e837a30300           call 0x634210
// 005f9ed9  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f9ee2  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f9ee8  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005f9ef1  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f9ef7  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005f9f00  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005f9f06  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f9f0f  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f9f15  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005f9f1e  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005f9f27  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005f9f30  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f9f39  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f9f42  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005f9f4b  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f9f54  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005f9f5d  8d4c246c             lea ecx, [esp + 0x6c]
// 005f9f61  51                   push ecx
// 005f9f62  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005f9f69  52                   push edx
// 005f9f6a  e881d62200           call 0x8275f0
// 005f9f6f  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f9f78  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005f9f81  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f9f8a  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005f9f91  50                   push eax
// 005f9f92  8d8c2484030000       lea ecx, [esp + 0x384]
// 005f9f99  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005f9fa2  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f9faa  51                   push ecx
// 005f9fab  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005f9fb4  e837d62200           call 0x8275f0
// 005f9fb9  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f9fbf  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005f9fc8  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f9fce  8d942470030000       lea edx, [esp + 0x370]
// 005f9fd5  52                   push edx
// 005f9fd6  8d842450030000       lea eax, [esp + 0x350]
// 005f9fdd  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005f9fe6  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f9fec  50                   push eax
// 005f9fed  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005f9ff6  e8f5d52200           call 0x8275f0
// 005f9ffb  83c418               add esp, 0x18
// 005f9ffe  8d8c2430030000       lea ecx, [esp + 0x330]
// 005fa005  51                   push ecx
// 005fa006  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005fa00d  e82ea20300           call 0x634240
// 005fa012  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005fa01b  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005fa022  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005fa029  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005fa030  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005fa039  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005fa042  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005fa04b  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005fa054  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005fa05d  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005fa066  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005fa06f  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005fa078  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005fa081  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005fa08a  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005fa093  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005fa09c  89942448020000       mov dword ptr [esp + 0x248], edx
// 005fa0a3  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005fa0aa  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005fa0b3  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005fa0bc  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005fa0c3  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005fa0ca  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005fa0d3  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005fa0dc  89942454020000       mov dword ptr [esp + 0x254], edx
// 005fa0e3  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005fa0ea  89842458020000       mov dword ptr [esp + 0x258], eax
// 005fa0f1  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005fa0f8  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005fa101  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005fa10a  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005fa111  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005fa118  89942460020000       mov dword ptr [esp + 0x260], edx
// 005fa11f  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005fa128  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005fa131  8d54246c             lea edx, [esp + 0x6c]
// 005fa135  89842464020000       mov dword ptr [esp + 0x264], eax
// 005fa13c  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005fa143  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005fa14a  52                   push edx
// 005fa14b  8d842470030000       lea eax, [esp + 0x370]
// 005fa152  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005fa15b  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005fa164  50                   push eax
// 005fa165  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005fa16c  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005fa175  e876d42200           call 0x8275f0
// 005fa17a  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005fa183  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005fa18c  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005fa195  8d8c2498030000       lea ecx, [esp + 0x398]
// 005fa19c  51                   push ecx
// 005fa19d  8d942460030000       lea edx, [esp + 0x360]
// 005fa1a4  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005fa1ad  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fa1b5  52                   push edx
// 005fa1b6  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005fa1bf  e82cd42200           call 0x8275f0
// 005fa1c4  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005fa1ca  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005fa1d3  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005fa1d9  8d842400040000       lea eax, [esp + 0x400]
// 005fa1e0  50                   push eax
// 005fa1e1  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005fa1e8  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005fa1f1  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fa1f7  51                   push ecx
// 005fa1f8  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005fa201  e8ead32200           call 0x8275f0
// 005fa206  83c418               add esp, 0x18
// 005fa209  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005fa210  52                   push edx
// 005fa211  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005fa218  e823a00300           call 0x634240
// 005fa21d  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005fa226  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005fa22d  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005fa234  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005fa23b  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005fa244  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005fa24d  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005fa256  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005fa25f  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005fa268  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005fa271  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005fa27a  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005fa283  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005fa28c  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005fa295  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005fa29e  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005fa2a7  89842490020000       mov dword ptr [esp + 0x290], eax
// 005fa2ae  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005fa2b5  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005fa2be  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005fa2c7  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005fa2ce  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005fa2d5  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005fa2de  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005fa2e7  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005fa2ee  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005fa2f5  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005fa2fc  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005fa303  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005fa30c  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005fa315  89942498020000       mov dword ptr [esp + 0x298], edx
// 005fa31c  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005fa323  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005fa32a  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005fa333  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005fa33c  8d44246c             lea eax, [esp + 0x6c]
// 005fa340  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005fa347  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005fa34e  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005fa355  50                   push eax
// 005fa356  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005fa35d  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005fa366  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005fa36f  51                   push ecx
// 005fa370  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005fa377  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005fa380  e86bd22200           call 0x8275f0
// 005fa385  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005fa38e  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005fa397  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005fa3a0  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005fa3a9  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fa3b1  8d94248c030000       lea edx, [esp + 0x38c]
// 005fa3b8  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005fa3c1  52                   push edx
// 005fa3c2  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005fa3c9  50                   push eax
// 005fa3ca  e821d22200           call 0x8275f0
// 005fa3cf  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005fa3d5  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005fa3de  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005fa3e4  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005fa3eb  51                   push ecx
// 005fa3ec  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005fa3f3  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005fa3fc  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fa402  52                   push edx
// 005fa403  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005fa40c  e8dfd12200           call 0x8275f0
// 005fa411  83c418               add esp, 0x18
// 005fa414  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005fa41b  50                   push eax
// 005fa41c  8d8c2480010000       lea ecx, [esp + 0x180]
// 005fa423  e8189e0300           call 0x634240
// 005fa428  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005fa431  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005fa438  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005fa43f  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005fa446  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005fa44f  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005fa458  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005fa461  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005fa46a  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005fa473  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005fa47c  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005fa485  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005fa48e  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005fa497  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005fa4a0  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005fa4a9  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 005fa4b2  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 005fa4b9  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 005fa4c0  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 005fa4c9  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 005fa4d2  89942404020000       mov dword ptr [esp + 0x204], edx
// 005fa4d9  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 005fa4e0  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 005fa4e9  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005fa4ef  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 005fa4f6  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 005fa4fd  89942410020000       mov dword ptr [esp + 0x210], edx
// 005fa504  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 005fa50b  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 005fa514  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005fa51a  89842408020000       mov dword ptr [esp + 0x208], eax
// 005fa521  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 005fa528  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 005fa52f  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005fa538  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005fa53e  8d4c246c             lea ecx, [esp + 0x6c]
// 005fa542  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 005fa549  89842414020000       mov dword ptr [esp + 0x214], eax
// 005fa550  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 005fa557  51                   push ecx
// 005fa558  8d942410010000       lea edx, [esp + 0x110]
// 005fa55f  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 005fa568  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005fa56e  52                   push edx
// 005fa56f  89842428020000       mov dword ptr [esp + 0x228], eax
// 005fa576  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005fa57f  e86cd02200           call 0x8275f0
// 005fa584  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005fa58d  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 005fa596  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005fa59f  8d842404040000       lea eax, [esp + 0x404]
// 005fa5a6  50                   push eax
// 005fa5a7  8d8c2438010000       lea ecx, [esp + 0x138]
// 005fa5ae  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 005fa5b7  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005fa5bf  51                   push ecx
// 005fa5c0  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 005fa5c9  e822d02200           call 0x8275f0
// 005fa5ce  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005fa5d4  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 005fa5dd  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005fa5e3  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005fa5ec  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005fa5f2  8d9424b8030000       lea edx, [esp + 0x3b8]
// 005fa5f9  52                   push edx
// 005fa5fa  8d842430010000       lea eax, [esp + 0x130]
// 005fa601  50                   push eax
// 005fa602  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 005fa60b  e8e0cf2200           call 0x8275f0
// 005fa610  83c418               add esp, 0x18
// 005fa613  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 005fa61a  51                   push ecx
// 005fa61b  8d4c242c             lea ecx, [esp + 0x2c]
// 005fa61f  e81c9c0300           call 0x634240
// 005fa624  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 005fa62d  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 005fa634  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 005fa63b  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 005fa642  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005fa64b  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 005fa654  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005fa65d  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 005fa666  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005fa66f  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 005fa678  89542478             mov dword ptr [esp + 0x78], edx
// 005fa67c  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 005fa683  8944247c             mov dword ptr [esp + 0x7c], eax
// 005fa687  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005fa68e  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005fa697  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 005fa6a0  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005fa6a7  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 005fa6ae  89942484000000       mov dword ptr [esp + 0x84], edx
// 005fa6b5  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 005fa6bc  89842488000000       mov dword ptr [esp + 0x88], eax
// 005fa6c3  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 005fa6ca  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005fa6d3  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 005fa6dc  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005fa6e3  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 005fa6ea  89942490000000       mov dword ptr [esp + 0x90], edx
// 005fa6f1  8b17                 mov edx, dword ptr [edi]
// 005fa6f3  8b5210               mov edx, dword ptr [edx + 0x10]
// 005fa6f6  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005fa6ff  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 005fa708  89842494000000       mov dword ptr [esp + 0x94], eax
// 005fa70f  8d842448020000       lea eax, [esp + 0x248]
// 005fa716  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005fa71d  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005fa726  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 005fa72f  50                   push eax
// 005fa730  8bcf                 mov ecx, edi
// 005fa732  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005fa73b  ffd2                 call edx
// 005fa73d  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 005fa744  8b07                 mov eax, dword ptr [edi]
// 005fa746  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fa749  8d8c2490020000       lea ecx, [esp + 0x290]
// 005fa750  51                   push ecx
// 005fa751  8bcf                 mov ecx, edi
// 005fa753  ffd2                 call edx
// 005fa755  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 005fa75c  8b07                 mov eax, dword ptr [edi]
// 005fa75e  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fa761  8d8c2400020000       lea ecx, [esp + 0x200]
// 005fa768  51                   push ecx
// 005fa769  8bcf                 mov ecx, edi
// 005fa76b  ffd2                 call edx
// 005fa76d  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 005fa774  8b07                 mov eax, dword ptr [edi]
// 005fa776  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fa779  8d4c2478             lea ecx, [esp + 0x78]
// 005fa77d  51                   push ecx
// 005fa77e  8bcf                 mov ecx, edi
// 005fa780  ffd2                 call edx
// 005fa782  89842460010000       mov dword ptr [esp + 0x160], eax
// 005fa789  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005fa790  40                   inc eax
// 005fa791  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005fa798  3bc3                 cmp eax, ebx
// 005fa79a  8d84246c010000       lea eax, [esp + 0x16c]
// 005fa7a1  7c07                 jl 0x5fa7aa
// 005fa7a3  8d8424e8000000       lea eax, [esp + 0xe8]
// 005fa7aa  8b18                 mov ebx, dword ptr [eax]
// 005fa7ac  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 005fa7b3  8bc8                 mov ecx, eax
// 005fa7b5  40                   inc eax
// 005fa7b6  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005fa7bd  85c9                 test ecx, ecx
// 005fa7bf  0f85f9000000         jne 0x5fa8be
// 005fa7c5  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 005fa7cc  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005fa7cf  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 005fa7d8  8911                 mov dword ptr [ecx], edx
// 005fa7da  f30f1106             movss dword ptr [esi], xmm0
// 005fa7de  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 005fa7e7  f30f114604           movss dword ptr [esi + 4], xmm0
// 005fa7ec  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 005fa7f5  f30f114608           movss dword ptr [esi + 8], xmm0
// 005fa7fa  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 005fa803  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 005fa808  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 005fa811  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 005fa816  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 005fa81f  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 005fa824  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 005fa82d  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 005fa832  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 005fa83b  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 005fa840  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 005fa849  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 005fa84e  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 005fa857  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 005fa85c  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 005fa865  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 005fa86a  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 005fa873  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 005fa878  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 005fa881  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 005fa886  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 005fa88f  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 005fa894  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 005fa89d  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 005fa8a2  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 005fa8ab  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 005fa8b0  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 005fa8b9  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 005fa8be  8bd3                 mov edx, ebx
// 005fa8c0  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 005fa8c5  8d0c9501000000       lea ecx, [edx*4 + 1]
// 005fa8cc  8bd0                 mov edx, eax
// 005fa8ce  40                   inc eax
// 005fa8cf  3bd1                 cmp edx, ecx
// 005fa8d1  0f8501010000         jne 0x5fa9d8
// 005fa8d7  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005fa8de  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005fa8e1  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 005fa8ea  894a04               mov dword ptr [edx + 4], ecx
// 005fa8ed  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 005fa8f2  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 005fa8fb  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 005fa900  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 005fa909  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 005fa90e  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 005fa917  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 005fa91c  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 005fa925  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 005fa92a  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 005fa933  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 005fa938  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 005fa941  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 005fa946  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 005fa94f  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 005fa954  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 005fa95d  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 005fa962  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 005fa96b  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 005fa970  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 005fa979  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 005fa97e  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 005fa987  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 005fa98c  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 005fa995  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 005fa99a  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 005fa9a3  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 005fa9a8  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 005fa9b1  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 005fa9b6  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 005fa9bf  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 005fa9c7  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 005fa9d0  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 005fa9d8  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005fa9dc  41                   inc ecx
// 005fa9dd  0fafcb               imul ecx, ebx
// 005fa9e0  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 005fa9e7  8bc8                 mov ecx, eax
// 005fa9e9  40                   inc eax
// 005fa9ea  3bca                 cmp ecx, edx
// 005fa9ec  0f852e010000         jne 0x5fab20
// 005fa9f2  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 005fa9f9  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005fa9fc  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005faa05  895108               mov dword ptr [ecx + 8], edx
// 005faa08  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 005faa10  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 005faa19  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 005faa21  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 005faa2a  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 005faa32  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 005faa3b  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 005faa43  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 005faa4c  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 005faa54  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 005faa5d  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 005faa65  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 005faa6e  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 005faa76  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 005faa7f  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 005faa87  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 005faa90  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 005faa98  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 005faaa1  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 005faaa9  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 005faab2  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 005faaba  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 005faac3  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 005faacb  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 005faad4  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 005faadc  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 005faae5  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 005faaed  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 005faaf6  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 005faafe  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 005fab07  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 005fab0f  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 005fab18  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 005fab20  8bc8                 mov ecx, eax
// 005fab22  8d149dffffffff       lea edx, [ebx*4 - 1]
// 005fab29  40                   inc eax
// 005fab2a  89842478010000       mov dword ptr [esp + 0x178], eax
// 005fab31  3bca                 cmp ecx, edx
// 005fab33  0f8528010000         jne 0x5fac61
// 005fab39  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005fab3c  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005fab43  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 005fab49  89420c               mov dword ptr [edx + 0xc], eax
// 005fab4c  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 005fab54  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 005fab5a  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 005fab62  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 005fab6b  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 005fab73  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 005fab7c  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 005fab84  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 005fab8d  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 005fab95  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 005fab9e  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 005faba6  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 005fabaf  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 005fabb7  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 005fabc0  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 005fabc8  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 005fabd1  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 005fabd9  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 005fabe2  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 005fabea  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 005fabf3  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 005fabfb  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 005fac04  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 005fac0c  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 005fac15  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 005fac1d  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 005fac26  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 005fac2e  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 005fac37  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 005fac3f  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 005fac48  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 005fac50  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 005fac59  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 005fac61  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005fac68  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005fac6f  8b17                 mov edx, dword ptr [edi]
// 005fac71  8b5218               mov edx, dword ptr [edx + 0x18]
// 005fac74  50                   push eax
// 005fac75  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 005fac7c  51                   push ecx
// 005fac7d  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 005fac84  50                   push eax
// 005fac85  51                   push ecx
// 005fac86  8bcf                 mov ecx, edi
// 005fac88  ffd2                 call edx
// 005fac8a  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005fac90  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 005fac99  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005faca1  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 005facaa  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 005facb0  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005facb6  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005facbb  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005facc2  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005facc6  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005facca  e9b3eeffff           jmp 0x5f9b82
// 005faccf  0f28fa               movaps xmm7, xmm2
// 005facd2  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 005facd8  0f28d9               movaps xmm3, xmm1
// 005facdb  42                   inc edx
// 005facdc  e90feeffff           jmp 0x5f9af0
// 005face1  8d4900               lea ecx, [ecx]
// 005face4  91                   xchg ecx, eax

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
