// from server: 11% by intel
// roc 2012-06 00600850  unit: seg_00600000  size: 7788 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00600850
//
// 00600850  55                   push ebp
// 00600851  8bec                 mov ebp, esp
// 00600853  83e4f8               and esp, 0xfffffff8
// 00600856  81ecfc030000         sub esp, 0x3fc
// 0060085c  53                   push ebx
// 0060085d  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00600860  56                   push esi
// 00600861  57                   push edi
// 00600862  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00600865  8d44246c             lea eax, [esp + 0x6c]
// 00600869  8bf1                 mov esi, ecx
// 0060086b  53                   push ebx
// 0060086c  c1ef0f               shr edi, 0xf
// 0060086f  50                   push eax
// 00600870  89742464             mov dword ptr [esp + 0x64], esi
// 00600874  83e707               and edi, 7
// 00600877  e8246e2200           call 0x8276a0
// 0060087c  d9442474             fld dword ptr [esp + 0x74]
// 00600880  d9e1                 fabs 
// 00600882  8d4c2474             lea ecx, [esp + 0x74]
// 00600886  d99c2448010000       fstp dword ptr [esp + 0x148]
// 0060088d  53                   push ebx
// 0060088e  d944247c             fld dword ptr [esp + 0x7c]
// 00600892  51                   push ecx
// 00600893  d9e1                 fabs 
// 00600895  d99c2454010000       fstp dword ptr [esp + 0x154]
// 0060089c  d9842484000000       fld dword ptr [esp + 0x84]
// 006008a3  d9e1                 fabs 
// 006008a5  d99c2458010000       fstp dword ptr [esp + 0x158]
// 006008ac  e8ef6d2200           call 0x8276a0
// 006008b1  d944247c             fld dword ptr [esp + 0x7c]
// 006008b5  8a4670               mov al, byte ptr [esi + 0x70]
// 006008b8  d9e1                 fabs 
// 006008ba  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 006008c2  d9842480000000       fld dword ptr [esp + 0x80]
// 006008c9  83c410               add esp, 0x10
// 006008cc  d9e1                 fabs 
// 006008ce  d9442474             fld dword ptr [esp + 0x74]
// 006008d2  d9e1                 fabs 
// 006008d4  d9450c               fld dword ptr [ebp + 0xc]
// 006008d7  dceb                 fsub st(3), st(0)
// 006008d9  d9cb                 fxch st(3)
// 006008db  d95c241c             fstp dword ptr [esp + 0x1c]
// 006008df  d9c9                 fxch st(1)
// 006008e1  dee2                 fsubrp st(2)
// 006008e3  d9c9                 fxch st(1)
// 006008e5  d95c2420             fstp dword ptr [esp + 0x20]
// 006008e9  d95c2424             fstp dword ptr [esp + 0x24]
// 006008ed  84c0                 test al, al
// 006008ef  741b                 je 0x60090c
// 006008f1  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 006008f9  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 00600902  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 0060090a  eb11                 jmp 0x60091d
// 0060090c  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 00600914  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 0060091d  0f57e4               xorps xmm4, xmm4
// 00600920  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 00600929  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 0060092f  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 00600935  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 0060093b  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 00600941  83ff05               cmp edi, 5
// 00600944  0f87a4010000         ja 0x600aee
// 0060094a  ff24bda4266000       jmp dword ptr [edi*4 + 0x6026a4]
// 00600951  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 00600959  8d542460             lea edx, [esp + 0x60]
// 0060095d  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 00600963  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 0060096b  52                   push edx
// 0060096c  8d4c2420             lea ecx, [esp + 0x20]
// 00600970  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 00600976  e8c5380300           call 0x634240
// 0060097b  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 00600983  f30f1000             movss xmm0, dword ptr [eax]
// 00600987  f30f104804           movss xmm1, dword ptr [eax + 4]
// 0060098c  0f57e4               xorps xmm4, xmm4
// 0060098f  f30f59c5             mulss xmm0, xmm5
// 00600993  f30f59cd             mulss xmm1, xmm5
// 00600997  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 0060099d  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 006009a3  e946010000           jmp 0x600aee
// 006009a8  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 006009b0  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 006009b6  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 006009bc  84c0                 test al, al
// 006009be  7413                 je 0x6009d3
// 006009c0  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 006009c8  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 006009ce  e91b010000           jmp 0x600aee
// 006009d3  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 006009db  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 006009e1  e908010000           jmp 0x600aee
// 006009e6  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 006009ec  84c0                 test al, al
// 006009ee  7419                 je 0x600a09
// 006009f0  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 006009f8  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 006009fe  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00600a04  e9e5000000           jmp 0x600aee
// 00600a09  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 00600a11  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 00600a17  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 00600a1f  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00600a25  e9c4000000           jmp 0x600aee
// 00600a2a  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 00600a30  84c0                 test al, al
// 00600a32  7419                 je 0x600a4d
// 00600a34  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 00600a3c  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 00600a42  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00600a48  e9a1000000           jmp 0x600aee
// 00600a4d  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 00600a55  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 00600a5b  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 00600a63  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00600a69  e980000000           jmp 0x600aee
// 00600a6e  84c0                 test al, al
// 00600a70  745a                 je 0x600acc
// 00600a72  803db380e50000       cmp byte ptr [0xe580b3], 0
// 00600a79  7441                 je 0x600abc
// 00600a7b  a19c80e500           mov eax, dword ptr [0xe5809c]
// 00600a80  85c0                 test eax, eax
// 00600a82  7418                 je 0x600a9c
// 00600a84  68b7000000           push 0xb7
// 00600a89  688027b800           push 0xb82780
// 00600a8e  68cc60b400           push 0xb460cc
// 00600a93  ffd0                 call eax
// 00600a95  83c40c               add esp, 0xc
// 00600a98  84c0                 test al, al
// 00600a9a  7515                 jne 0x600ab1
// 00600a9c  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 00600aa3  680827b800           push 0xb82708
// 00600aa8  50                   push eax
// 00600aa9  e8e2173700           call 0x972290
// 00600aae  83c408               add esp, 8
// 00600ab1  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 00600ab9  0f57e4               xorps xmm4, xmm4
// 00600abc  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 00600ac4  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 00600aca  eb1c                 jmp 0x600ae8
// 00600acc  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 00600ad4  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 00600ada  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 00600ae2  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 00600ae8  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 00600aee  807e7000             cmp byte ptr [esi + 0x70], 0
// 00600af2  7419                 je 0x600b0d
// 00600af4  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 00600af9  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 00600b01  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 00600b07  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 00600b0d  85ff                 test edi, edi
// 00600b0f  0f859c080000         jne 0x6013b1
// 00600b15  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 00600b1d  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 00600b22  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 00600b2a  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 00600b2f  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 00600b35  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 00600b3e  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 00600b46  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 00600b4c  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 00600b55  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 00600b5e  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 00600b67  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 00600b70  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 00600b79  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 00600b82  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 00600b8b  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 00600b94  f30f59c5             mulss xmm0, xmm5
// 00600b98  f30f59cd             mulss xmm1, xmm5
// 00600b9c  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 00600ba5  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 00600bae  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 00600bb3  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 00600bbc  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 00600bc5  8d8c248c010000       lea ecx, [esp + 0x18c]
// 00600bcc  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 00600bd2  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 00600bdb  0f28e3               movaps xmm4, xmm3
// 00600bde  f30f5ce0             subss xmm4, xmm0
// 00600be2  0f28eb               movaps xmm5, xmm3
// 00600be5  f30f5ce9             subss xmm5, xmm1
// 00600be9  51                   push ecx
// 00600bea  8d542464             lea edx, [esp + 0x64]
// 00600bee  f30f5cc3             subss xmm0, xmm3
// 00600bf2  0f28d3               movaps xmm2, xmm3
// 00600bf5  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 00600bfc  f30f5ccb             subss xmm1, xmm3
// 00600c00  52                   push edx
// 00600c01  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 00600c0a  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 00600c13  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 00600c1c  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 00600c25  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 00600c2e  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 00600c37  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 00600c40  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 00600c49  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 00600c52  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 00600c5b  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 00600c64  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 00600c6d  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 00600c76  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 00600c7f  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 00600c88  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 00600c91  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 00600c9a  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 00600ca3  e8f8692200           call 0x8276a0
// 00600ca8  8d442474             lea eax, [esp + 0x74]
// 00600cac  50                   push eax
// 00600cad  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 00600cb4  51                   push ecx
// 00600cb5  e8e6692200           call 0x8276a0
// 00600cba  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 00600cc2  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 00600cc8  0f57c8               xorps xmm1, xmm0
// 00600ccb  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 00600cd4  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 00600cda  8d9424d0000000       lea edx, [esp + 0xd0]
// 00600ce1  0f57c8               xorps xmm1, xmm0
// 00600ce4  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 00600cea  52                   push edx
// 00600ceb  8d8424ec000000       lea eax, [esp + 0xec]
// 00600cf2  50                   push eax
// 00600cf3  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 00600cfc  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 00600d05  e896692200           call 0x8276a0
// 00600d0a  83c418               add esp, 0x18
// 00600d0d  8d4c2440             lea ecx, [esp + 0x40]
// 00600d11  51                   push ecx
// 00600d12  8d8c2480010000       lea ecx, [esp + 0x180]
// 00600d19  e822350300           call 0x634240
// 00600d1e  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 00600d25  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 00600d2b  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 00600d32  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 00600d39  8b7d20               mov edi, dword ptr [ebp + 0x20]
// 00600d3c  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 00600d45  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 00600d4b  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 00600d54  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 00600d5a  89542478             mov dword ptr [esp + 0x78], edx
// 00600d5e  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 00600d65  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 00600d6e  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 00600d74  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 00600d7b  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 00600d82  89942484000000       mov dword ptr [esp + 0x84], edx
// 00600d89  8b542460             mov edx, dword ptr [esp + 0x60]
// 00600d8d  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 00600d96  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 00600d9b  8944247c             mov dword ptr [esp + 0x7c], eax
// 00600d9f  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 00600da6  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 00600dad  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 00600db1  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 00600dba  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 00600dc3  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 00600dcc  89942490000000       mov dword ptr [esp + 0x90], edx
// 00600dd3  89842488000000       mov dword ptr [esp + 0x88], eax
// 00600dda  8b442464             mov eax, dword ptr [esp + 0x64]
// 00600dde  8d542478             lea edx, [esp + 0x78]
// 00600de2  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 00600de9  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 00600df2  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 00600dfb  52                   push edx
// 00600dfc  8bcf                 mov ecx, edi
// 00600dfe  89842498000000       mov dword ptr [esp + 0x98], eax
// 00600e05  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 00600e0e  e8ad94feff           call 0x5ea2c0
// 00600e13  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 00600e1c  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 00600e22  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 00600e2b  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 00600e31  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 00600e3a  8d84248c010000       lea eax, [esp + 0x18c]
// 00600e41  50                   push eax
// 00600e42  8d4c2464             lea ecx, [esp + 0x64]
// 00600e46  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 00600e4c  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 00600e55  51                   push ecx
// 00600e56  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 00600e5c  e83f682200           call 0x8276a0
// 00600e61  8d9424e8010000       lea edx, [esp + 0x1e8]
// 00600e68  52                   push edx
// 00600e69  8d8424d8000000       lea eax, [esp + 0xd8]
// 00600e70  50                   push eax
// 00600e71  e82a682200           call 0x8276a0
// 00600e76  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 00600e7c  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 00600e85  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 00600e8b  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 00600e92  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 00600e99  51                   push ecx
// 00600e9a  8d9424ec000000       lea edx, [esp + 0xec]
// 00600ea1  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 00600eaa  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 00600eb0  52                   push edx
// 00600eb1  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 00600eba  e8e1672200           call 0x8276a0
// 00600ebf  83c418               add esp, 0x18
// 00600ec2  8d442440             lea eax, [esp + 0x40]
// 00600ec6  50                   push eax
// 00600ec7  8d8c2410010000       lea ecx, [esp + 0x110]
// 00600ece  e86d330300           call 0x634240
// 00600ed3  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 00600eda  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 00600ee1  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 00600ee8  894c2478             mov dword ptr [esp + 0x78], ecx
// 00600eec  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 00600ef3  8954247c             mov dword ptr [esp + 0x7c], edx
// 00600ef7  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 00600efe  89842480000000       mov dword ptr [esp + 0x80], eax
// 00600f05  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 00600f0c  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 00600f12  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00600f16  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 00600f1d  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 00600f26  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 00600f2c  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 00600f35  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 00600f3b  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 00600f44  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 00600f4a  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 00600f53  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 00600f59  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 00600f62  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 00600f68  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 00600f6f  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 00600f78  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 00600f7e  8d4c2478             lea ecx, [esp + 0x78]
// 00600f82  89942488000000       mov dword ptr [esp + 0x88], edx
// 00600f89  8b542464             mov edx, dword ptr [esp + 0x64]
// 00600f8d  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 00600f94  8b442468             mov eax, dword ptr [esp + 0x68]
// 00600f98  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 00600fa1  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 00600fa7  8d5f44               lea ebx, [edi + 0x44]
// 00600faa  51                   push ecx
// 00600fab  8bcb                 mov ecx, ebx
// 00600fad  89942498000000       mov dword ptr [esp + 0x98], edx
// 00600fb4  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 00600fbb  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 00600fc4  e8f792feff           call 0x5ea2c0
// 00600fc9  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 00600fd2  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 00600fd8  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 00600fe1  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 00600fe7  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 00600ff0  8d94248c010000       lea edx, [esp + 0x18c]
// 00600ff7  52                   push edx
// 00600ff8  8d442464             lea eax, [esp + 0x64]
// 00600ffc  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 00601002  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 0060100b  50                   push eax
// 0060100c  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 00601012  e889662200           call 0x8276a0
// 00601017  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 0060101e  51                   push ecx
// 0060101f  8d9424d8000000       lea edx, [esp + 0xd8]
// 00601026  52                   push edx
// 00601027  e874662200           call 0x8276a0
// 0060102c  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 00601032  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 0060103b  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 00601041  8d8424d0000000       lea eax, [esp + 0xd0]
// 00601048  50                   push eax
// 00601049  8d8c24ec000000       lea ecx, [esp + 0xec]
// 00601050  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 00601059  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 0060105f  51                   push ecx
// 00601060  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 00601069  e832662200           call 0x8276a0
// 0060106e  83c418               add esp, 0x18
// 00601071  8d542440             lea edx, [esp + 0x40]
// 00601075  52                   push edx
// 00601076  8d8c2430010000       lea ecx, [esp + 0x130]
// 0060107d  e8be310300           call 0x634240
// 00601082  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 00601089  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 00601090  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 00601097  89442478             mov dword ptr [esp + 0x78], eax
// 0060109b  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 006010a2  894c247c             mov dword ptr [esp + 0x7c], ecx
// 006010a6  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 006010ad  89942480000000       mov dword ptr [esp + 0x80], edx
// 006010b4  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 006010bb  89842484000000       mov dword ptr [esp + 0x84], eax
// 006010c2  8b442460             mov eax, dword ptr [esp + 0x60]
// 006010c6  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 006010cd  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 006010d1  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 006010d8  8b542468             mov edx, dword ptr [esp + 0x68]
// 006010dc  89842490000000       mov dword ptr [esp + 0x90], eax
// 006010e3  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 006010ea  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 006010f0  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 006010f9  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 006010ff  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 00601108  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 0060110e  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 00601117  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 0060111d  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 00601126  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 0060112c  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 00601135  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 0060113b  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 00601144  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 0060114a  8d442478             lea eax, [esp + 0x78]
// 0060114e  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 00601157  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 0060115d  8d8f88000000         lea ecx, [edi + 0x88]
// 00601163  50                   push eax
// 00601164  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 0060116b  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 00601174  894c2460             mov dword ptr [esp + 0x60], ecx
// 00601178  e84391feff           call 0x5ea2c0
// 0060117d  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 00601186  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 0060118c  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 00601195  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 0060119b  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 006011a4  8d8c248c010000       lea ecx, [esp + 0x18c]
// 006011ab  51                   push ecx
// 006011ac  8d542464             lea edx, [esp + 0x64]
// 006011b0  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 006011b6  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 006011bf  52                   push edx
// 006011c0  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 006011c6  e8d5642200           call 0x8276a0
// 006011cb  8d8424d8010000       lea eax, [esp + 0x1d8]
// 006011d2  50                   push eax
// 006011d3  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 006011da  51                   push ecx
// 006011db  e8c0642200           call 0x8276a0
// 006011e0  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 006011e6  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 006011ed  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 006011f6  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 006011fc  8d9424d0000000       lea edx, [esp + 0xd0]
// 00601203  52                   push edx
// 00601204  8d8424ec000000       lea eax, [esp + 0xec]
// 0060120b  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 00601214  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 0060121a  50                   push eax
// 0060121b  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 00601224  e877642200           call 0x8276a0
// 00601229  83c418               add esp, 0x18
// 0060122c  8d4c2440             lea ecx, [esp + 0x40]
// 00601230  51                   push ecx
// 00601231  8d8c2420010000       lea ecx, [esp + 0x120]
// 00601238  e803300300           call 0x634240
// 0060123d  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 00601244  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 0060124b  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 00601252  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 00601258  89542478             mov dword ptr [esp + 0x78], edx
// 0060125c  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 00601263  8944247c             mov dword ptr [esp + 0x7c], eax
// 00601267  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 0060126e  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 00601275  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 0060127c  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 00601285  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 0060128b  89942484000000       mov dword ptr [esp + 0x84], edx
// 00601292  8b542460             mov edx, dword ptr [esp + 0x60]
// 00601296  89842488000000       mov dword ptr [esp + 0x88], eax
// 0060129d  8b442464             mov eax, dword ptr [esp + 0x64]
// 006012a1  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 006012a8  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 006012ac  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 006012b5  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 006012bb  89942490000000       mov dword ptr [esp + 0x90], edx
// 006012c2  89842494000000       mov dword ptr [esp + 0x94], eax
// 006012c9  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 006012d0  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 006012d9  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 006012df  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 006012e8  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 006012ee  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 006012f7  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 006012fd  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 00601306  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 0060130c  8d542478             lea edx, [esp + 0x78]
// 00601310  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 00601319  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 0060131f  8d8fcc000000         lea ecx, [edi + 0xcc]
// 00601325  52                   push edx
// 00601326  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 0060132f  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 00601336  e8858ffeff           call 0x5ea2c0
// 0060133b  8b7518               mov esi, dword ptr [ebp + 0x18]
// 0060133e  8b06                 mov eax, dword ptr [esi]
// 00601340  8b5010               mov edx, dword ptr [eax + 0x10]
// 00601343  57                   push edi
// 00601344  8bce                 mov ecx, esi
// 00601346  ffd2                 call edx
// 00601348  8bf8                 mov edi, eax
// 0060134a  8b06                 mov eax, dword ptr [esi]
// 0060134c  8b5010               mov edx, dword ptr [eax + 0x10]
// 0060134f  53                   push ebx
// 00601350  8bce                 mov ecx, esi
// 00601352  ffd2                 call edx
// 00601354  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00601358  8bd8                 mov ebx, eax
// 0060135a  8b06                 mov eax, dword ptr [esi]
// 0060135c  8b5010               mov edx, dword ptr [eax + 0x10]
// 0060135f  51                   push ecx
// 00601360  8bce                 mov ecx, esi
// 00601362  ffd2                 call edx
// 00601364  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 0060136b  8944243c             mov dword ptr [esp + 0x3c], eax
// 0060136f  8b06                 mov eax, dword ptr [esi]
// 00601371  8b5010               mov edx, dword ptr [eax + 0x10]
// 00601374  51                   push ecx
// 00601375  8bce                 mov ecx, esi
// 00601377  ffd2                 call edx
// 00601379  8b16                 mov edx, dword ptr [esi]
// 0060137b  8b5218               mov edx, dword ptr [edx + 0x18]
// 0060137e  50                   push eax
// 0060137f  89442460             mov dword ptr [esp + 0x60], eax
// 00601383  8b442440             mov eax, dword ptr [esp + 0x40]
// 00601387  50                   push eax
// 00601388  53                   push ebx
// 00601389  57                   push edi
// 0060138a  8bce                 mov ecx, esi
// 0060138c  ffd2                 call edx
// 0060138e  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00601391  85c0                 test eax, eax
// 00601393  7413                 je 0x6013a8
// 00601395  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00601399  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0060139d  8938                 mov dword ptr [eax], edi
// 0060139f  895804               mov dword ptr [eax + 4], ebx
// 006013a2  894808               mov dword ptr [eax + 8], ecx
// 006013a5  89500c               mov dword ptr [eax + 0xc], edx
// 006013a8  5f                   pop edi
// 006013a9  5e                   pop esi
// 006013aa  5b                   pop ebx
// 006013ab  8be5                 mov esp, ebp
// 006013ad  5d                   pop ebp
// 006013ae  c22000               ret 0x20
// 006013b1  803db380e50000       cmp byte ptr [0xe580b3], 0
// 006013b8  743c                 je 0x6013f6
// 006013ba  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 006013be  7536                 jne 0x6013f6
// 006013c0  a19c80e500           mov eax, dword ptr [0xe5809c]
// 006013c5  85c0                 test eax, eax
// 006013c7  7418                 je 0x6013e1
// 006013c9  6801010000           push 0x101
// 006013ce  688027b800           push 0xb82780
// 006013d3  680027b800           push 0xb82700
// 006013d8  ffd0                 call eax
// 006013da  83c40c               add esp, 0xc
// 006013dd  84c0                 test al, al
// 006013df  7515                 jne 0x6013f6
// 006013e1  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 006013e8  688826b800           push 0xb82688
// 006013ed  50                   push eax
// 006013ee  e89d0e3700           call 0x972290
// 006013f3  83c408               add esp, 8
// 006013f6  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 006013fc  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 00601403  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 0060140b  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 00601413  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 00601418  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 0060141e  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 00601426  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 0060142b  8d4c2460             lea ecx, [esp + 0x60]
// 0060142f  51                   push ecx
// 00601430  f30f59c2             mulss xmm0, xmm2
// 00601434  f30f59ca             mulss xmm1, xmm2
// 00601438  8d4c2420             lea ecx, [esp + 0x20]
// 0060143c  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 00601445  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 0060144e  e8ed2d0300           call 0x634240
// 00601453  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 0060145c  f30f5e00             divss xmm0, dword ptr [eax]
// 00601460  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 00601465  8b7520               mov esi, dword ptr [ebp + 0x20]
// 00601468  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 0060146b  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 00601470  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 00601478  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 0060147e  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 00601487  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 00601490  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 00601495  33d2                 xor edx, edx
// 00601497  33db                 xor ebx, ebx
// 00601499  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 006014a2  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 006014a9  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 006014b0  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 006014b6  0f2fd7               comiss xmm2, xmm7
// 006014b9  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 006014bf  8954243c             mov dword ptr [esp + 0x3c], edx
// 006014c3  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 006014cc  770a                 ja 0x6014d8
// 006014ce  85d2                 test edx, edx
// 006014d0  0f85d2feffff         jne 0x6013a8
// 006014d6  eb04                 jmp 0x6014dc
// 006014d8  85d2                 test edx, edx
// 006014da  7504                 jne 0x6014e0
// 006014dc  f30f5cc4             subss xmm0, xmm4
// 006014e0  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 006014e4  80797000             cmp byte ptr [ecx + 0x70], 0
// 006014e8  7421                 je 0x60150b
// 006014ea  f30f58c7             addss xmm0, xmm7
// 006014ee  0f2fc2               comiss xmm0, xmm2
// 006014f1  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 006014fa  8d44241c             lea eax, [esp + 0x1c]
// 006014fe  7707                 ja 0x601507
// 00601500  8d84240c030000       lea eax, [esp + 0x30c]
// 00601507  f30f1010             movss xmm2, dword ptr [eax]
// 0060150b  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 00601514  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 0060151a  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 00601521  f30f58cb             addss xmm1, xmm3
// 00601525  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 0060152a  33c0                 xor eax, eax
// 0060152c  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 00601532  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 0060153b  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 00601542  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 00601548  0f2ff0               comiss xmm6, xmm0
// 0060154b  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 00601554  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 0060155a  7708                 ja 0x601564
// 0060155c  85c0                 test eax, eax
// 0060155e  0f852b110000         jne 0x60268f
// 00601564  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 0060156a  85c0                 test eax, eax
// 0060156c  7504                 jne 0x601572
// 0060156e  f30f5ccc             subss xmm1, xmm4
// 00601572  0f28f1               movaps xmm6, xmm1
// 00601575  f30f58f0             addss xmm6, xmm0
// 00601579  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 0060157e  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 00601587  8d442420             lea eax, [esp + 0x20]
// 0060158b  7707                 ja 0x601594
// 0060158d  8d8424dc020000       lea eax, [esp + 0x2dc]
// 00601594  80797000             cmp byte ptr [ecx + 0x70], 0
// 00601598  f30f1000             movss xmm0, dword ptr [eax]
// 0060159c  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 006015a2  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 006015ab  f30f58c3             addss xmm0, xmm3
// 006015af  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 006015b8  0f57c0               xorps xmm0, xmm0
// 006015bb  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 006015c1  740f                 je 0x6015d2
// 006015c3  e8c88cfeff           call 0x5ea290
// 006015c8  d80d94deb600         fmul dword ptr [0xb6de94]
// 006015ce  d95c2440             fstp dword ptr [esp + 0x40]
// 006015d2  0f28dd               movaps xmm3, xmm5
// 006015d5  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 006015de  0f28c3               movaps xmm0, xmm3
// 006015e1  f30f59c4             mulss xmm0, xmm4
// 006015e5  f30f5cd7             subss xmm2, xmm7
// 006015e9  f30f59d3             mulss xmm2, xmm3
// 006015ed  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 006015f3  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 006015f9  f30f58d3             addss xmm2, xmm3
// 006015fd  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 00601603  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 00601609  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 0060160f  0f28c5               movaps xmm0, xmm5
// 00601612  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 0060161b  0f28e9               movaps xmm5, xmm1
// 0060161e  0f28f0               movaps xmm6, xmm0
// 00601621  f30f59f4             mulss xmm6, xmm4
// 00601625  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 0060162b  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 00601631  f30f5ccb             subss xmm1, xmm3
// 00601635  f30f59e8             mulss xmm5, xmm0
// 00601639  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 0060163f  f30f59c8             mulss xmm1, xmm0
// 00601643  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 00601649  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 00601652  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 0060165b  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 00601664  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 0060166d  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 00601676  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 0060167f  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 00601688  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 00601691  85d2                 test edx, edx
// 00601693  753f                 jne 0x6016d4
// 00601695  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 0060169b  0f28c4               movaps xmm0, xmm4
// 0060169e  f30f58c3             addss xmm0, xmm3
// 006016a2  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 006016ab  0f28c3               movaps xmm0, xmm3
// 006016ae  f30f58c2             addss xmm0, xmm2
// 006016b2  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 006016bb  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 006016c4  0f28c4               movaps xmm0, xmm4
// 006016c7  f30f58c3             addss xmm0, xmm3
// 006016cb  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 006016d4  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 006016da  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 006016df  772f                 ja 0x601710
// 006016e1  0f28c6               movaps xmm0, xmm6
// 006016e4  f30f58c5             addss xmm0, xmm5
// 006016e8  f30f58f1             addss xmm6, xmm1
// 006016ec  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 006016f5  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 006016fe  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 00601707  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 00601710  8d9424cc000000       lea edx, [esp + 0xcc]
// 00601717  52                   push edx
// 00601718  8d8c2444010000       lea ecx, [esp + 0x144]
// 0060171f  e81c2b0300           call 0x634240
// 00601724  f30f104004           movss xmm0, dword ptr [eax + 4]
// 00601729  f30f1008             movss xmm1, dword ptr [eax]
// 0060172d  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 00601733  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 00601739  8d8424d8000000       lea eax, [esp + 0xd8]
// 00601740  50                   push eax
// 00601741  8d8c2444010000       lea ecx, [esp + 0x144]
// 00601748  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 00601751  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 0060175a  e8e12a0300           call 0x634240
// 0060175f  f30f104004           movss xmm0, dword ptr [eax + 4]
// 00601764  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 0060176a  f30f5808             addss xmm1, dword ptr [eax]
// 0060176e  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 00601774  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 0060177b  51                   push ecx
// 0060177c  8d8c2444010000       lea ecx, [esp + 0x144]
// 00601783  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 0060178c  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 00601795  e8a62a0300           call 0x634240
// 0060179a  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 006017a0  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 006017a5  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 006017ab  f30f5c08             subss xmm1, dword ptr [eax]
// 006017af  8d94248c010000       lea edx, [esp + 0x18c]
// 006017b6  52                   push edx
// 006017b7  8d8c2444010000       lea ecx, [esp + 0x144]
// 006017be  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 006017c7  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 006017d0  e86b2a0300           call 0x634240
// 006017d5  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 006017db  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 006017e0  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 006017e6  f30f5c08             subss xmm1, dword ptr [eax]
// 006017ea  8d842498010000       lea eax, [esp + 0x198]
// 006017f1  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 006017fa  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 00601802  50                   push eax
// 00601803  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 0060180a  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 00601810  0f57c0               xorps xmm0, xmm0
// 00601813  51                   push ecx
// 00601814  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 0060181b  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 00601824  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 0060182a  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 00601830  e8db290300           call 0x634210
// 00601835  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 0060183e  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 00601847  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 00601850  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 00601859  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 00601862  8d9424ec000000       lea edx, [esp + 0xec]
// 00601869  52                   push edx
// 0060186a  8d8424ac010000       lea eax, [esp + 0x1ac]
// 00601871  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 0060187a  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 00601883  50                   push eax
// 00601884  8d8c2484010000       lea ecx, [esp + 0x184]
// 0060188b  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 00601894  e877290300           call 0x634210
// 00601899  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 006018a2  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 006018a8  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 006018b1  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 006018b7  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 006018c0  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 006018c6  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 006018cf  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 006018d5  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 006018de  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 006018e7  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 006018f0  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 006018f9  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 00601902  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 0060190b  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 00601914  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 0060191d  8d4c246c             lea ecx, [esp + 0x6c]
// 00601921  51                   push ecx
// 00601922  8d9424c4030000       lea edx, [esp + 0x3c4]
// 00601929  52                   push edx
// 0060192a  e8715d2200           call 0x8276a0
// 0060192f  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 00601938  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 00601941  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 0060194a  8d8424e0030000       lea eax, [esp + 0x3e0]
// 00601951  50                   push eax
// 00601952  8d8c2484030000       lea ecx, [esp + 0x384]
// 00601959  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 00601962  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0060196a  51                   push ecx
// 0060196b  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 00601974  e8275d2200           call 0x8276a0
// 00601979  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 0060197f  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 00601988  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 0060198e  8d942470030000       lea edx, [esp + 0x370]
// 00601995  52                   push edx
// 00601996  8d842450030000       lea eax, [esp + 0x350]
// 0060199d  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 006019a6  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 006019ac  50                   push eax
// 006019ad  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 006019b6  e8e55c2200           call 0x8276a0
// 006019bb  83c418               add esp, 0x18
// 006019be  8d8c2430030000       lea ecx, [esp + 0x330]
// 006019c5  51                   push ecx
// 006019c6  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 006019cd  e86e280300           call 0x634240
// 006019d2  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 006019db  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 006019e2  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 006019e9  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 006019f0  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 006019f9  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 00601a02  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 00601a0b  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 00601a14  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 00601a1d  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 00601a26  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 00601a2f  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 00601a38  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 00601a41  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 00601a4a  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 00601a53  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 00601a5c  89942448020000       mov dword ptr [esp + 0x248], edx
// 00601a63  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 00601a6a  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 00601a73  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 00601a7c  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 00601a83  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 00601a8a  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 00601a93  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 00601a9c  89942454020000       mov dword ptr [esp + 0x254], edx
// 00601aa3  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 00601aaa  89842458020000       mov dword ptr [esp + 0x258], eax
// 00601ab1  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 00601ab8  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 00601ac1  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 00601aca  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 00601ad1  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 00601ad8  89942460020000       mov dword ptr [esp + 0x260], edx
// 00601adf  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 00601ae8  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 00601af1  8d54246c             lea edx, [esp + 0x6c]
// 00601af5  89842464020000       mov dword ptr [esp + 0x264], eax
// 00601afc  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 00601b03  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 00601b0a  52                   push edx
// 00601b0b  8d842470030000       lea eax, [esp + 0x370]
// 00601b12  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 00601b1b  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 00601b24  50                   push eax
// 00601b25  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 00601b2c  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 00601b35  e8665b2200           call 0x8276a0
// 00601b3a  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 00601b43  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 00601b4c  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 00601b55  8d8c2498030000       lea ecx, [esp + 0x398]
// 00601b5c  51                   push ecx
// 00601b5d  8d942460030000       lea edx, [esp + 0x360]
// 00601b64  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 00601b6d  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 00601b75  52                   push edx
// 00601b76  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 00601b7f  e81c5b2200           call 0x8276a0
// 00601b84  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 00601b8a  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 00601b93  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 00601b99  8d842400040000       lea eax, [esp + 0x400]
// 00601ba0  50                   push eax
// 00601ba1  8d8c245c030000       lea ecx, [esp + 0x35c]
// 00601ba8  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 00601bb1  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 00601bb7  51                   push ecx
// 00601bb8  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 00601bc1  e8da5a2200           call 0x8276a0
// 00601bc6  83c418               add esp, 0x18
// 00601bc9  8d9424d0010000       lea edx, [esp + 0x1d0]
// 00601bd0  52                   push edx
// 00601bd1  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 00601bd8  e863260300           call 0x634240
// 00601bdd  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 00601be6  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 00601bed  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 00601bf4  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 00601bfb  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 00601c04  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 00601c0d  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 00601c16  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 00601c1f  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 00601c28  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 00601c31  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 00601c3a  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 00601c43  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 00601c4c  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 00601c55  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 00601c5e  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 00601c67  89842490020000       mov dword ptr [esp + 0x290], eax
// 00601c6e  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 00601c75  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 00601c7e  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 00601c87  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 00601c8e  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 00601c95  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 00601c9e  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 00601ca7  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 00601cae  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 00601cb5  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 00601cbc  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 00601cc3  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 00601ccc  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 00601cd5  89942498020000       mov dword ptr [esp + 0x298], edx
// 00601cdc  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 00601ce3  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 00601cea  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 00601cf3  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 00601cfc  8d44246c             lea eax, [esp + 0x6c]
// 00601d00  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 00601d07  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 00601d0e  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 00601d15  50                   push eax
// 00601d16  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 00601d1d  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 00601d26  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 00601d2f  51                   push ecx
// 00601d30  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 00601d37  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 00601d40  e85b592200           call 0x8276a0
// 00601d45  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 00601d4e  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 00601d57  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 00601d60  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 00601d69  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 00601d71  8d94248c030000       lea edx, [esp + 0x38c]
// 00601d78  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 00601d81  52                   push edx
// 00601d82  8d8424d8030000       lea eax, [esp + 0x3d8]
// 00601d89  50                   push eax
// 00601d8a  e811592200           call 0x8276a0
// 00601d8f  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 00601d95  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 00601d9e  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 00601da4  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 00601dab  51                   push ecx
// 00601dac  8d9424c8030000       lea edx, [esp + 0x3c8]
// 00601db3  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 00601dbc  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 00601dc2  52                   push edx
// 00601dc3  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 00601dcc  e8cf582200           call 0x8276a0
// 00601dd1  83c418               add esp, 0x18
// 00601dd4  8d8424c0010000       lea eax, [esp + 0x1c0]
// 00601ddb  50                   push eax
// 00601ddc  8d8c2480010000       lea ecx, [esp + 0x180]
// 00601de3  e858240300           call 0x634240
// 00601de8  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 00601df1  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 00601df8  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 00601dff  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 00601e06  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 00601e0f  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 00601e18  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 00601e21  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 00601e2a  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 00601e33  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 00601e3c  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 00601e45  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 00601e4e  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 00601e57  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 00601e60  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 00601e69  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 00601e72  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 00601e79  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 00601e80  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 00601e89  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 00601e92  89942404020000       mov dword ptr [esp + 0x204], edx
// 00601e99  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 00601ea0  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 00601ea9  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 00601eaf  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 00601eb6  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 00601ebd  89942410020000       mov dword ptr [esp + 0x210], edx
// 00601ec4  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 00601ecb  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 00601ed4  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 00601eda  89842408020000       mov dword ptr [esp + 0x208], eax
// 00601ee1  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 00601ee8  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 00601eef  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 00601ef8  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 00601efe  8d4c246c             lea ecx, [esp + 0x6c]
// 00601f02  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 00601f09  89842414020000       mov dword ptr [esp + 0x214], eax
// 00601f10  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 00601f17  51                   push ecx
// 00601f18  8d942410010000       lea edx, [esp + 0x110]
// 00601f1f  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 00601f28  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 00601f2e  52                   push edx
// 00601f2f  89842428020000       mov dword ptr [esp + 0x228], eax
// 00601f36  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 00601f3f  e85c572200           call 0x8276a0
// 00601f44  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 00601f4d  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 00601f56  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 00601f5f  8d842404040000       lea eax, [esp + 0x404]
// 00601f66  50                   push eax
// 00601f67  8d8c2438010000       lea ecx, [esp + 0x138]
// 00601f6e  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 00601f77  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 00601f7f  51                   push ecx
// 00601f80  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 00601f89  e812572200           call 0x8276a0
// 00601f8e  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 00601f94  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 00601f9d  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 00601fa3  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 00601fac  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 00601fb2  8d9424b8030000       lea edx, [esp + 0x3b8]
// 00601fb9  52                   push edx
// 00601fba  8d842430010000       lea eax, [esp + 0x130]
// 00601fc1  50                   push eax
// 00601fc2  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 00601fcb  e8d0562200           call 0x8276a0
// 00601fd0  83c418               add esp, 0x18
// 00601fd3  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 00601fda  51                   push ecx
// 00601fdb  8d4c242c             lea ecx, [esp + 0x2c]
// 00601fdf  e85c220300           call 0x634240
// 00601fe4  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 00601fed  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 00601ff4  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 00601ffb  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 00602002  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 0060200b  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 00602014  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 0060201d  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 00602026  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 0060202f  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 00602038  89542478             mov dword ptr [esp + 0x78], edx
// 0060203c  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 00602043  8944247c             mov dword ptr [esp + 0x7c], eax
// 00602047  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 0060204e  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 00602057  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 00602060  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 00602067  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 0060206e  89942484000000       mov dword ptr [esp + 0x84], edx
// 00602075  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 0060207c  89842488000000       mov dword ptr [esp + 0x88], eax
// 00602083  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 0060208a  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 00602093  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 0060209c  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 006020a3  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 006020aa  89942490000000       mov dword ptr [esp + 0x90], edx
// 006020b1  8b17                 mov edx, dword ptr [edi]
// 006020b3  8b5210               mov edx, dword ptr [edx + 0x10]
// 006020b6  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 006020bf  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 006020c8  89842494000000       mov dword ptr [esp + 0x94], eax
// 006020cf  8d842448020000       lea eax, [esp + 0x248]
// 006020d6  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 006020dd  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 006020e6  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 006020ef  50                   push eax
// 006020f0  8bcf                 mov ecx, edi
// 006020f2  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 006020fb  ffd2                 call edx
// 006020fd  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 00602104  8b07                 mov eax, dword ptr [edi]
// 00602106  8b5010               mov edx, dword ptr [eax + 0x10]
// 00602109  8d8c2490020000       lea ecx, [esp + 0x290]
// 00602110  51                   push ecx
// 00602111  8bcf                 mov ecx, edi
// 00602113  ffd2                 call edx
// 00602115  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 0060211c  8b07                 mov eax, dword ptr [edi]
// 0060211e  8b5010               mov edx, dword ptr [eax + 0x10]
// 00602121  8d8c2400020000       lea ecx, [esp + 0x200]
// 00602128  51                   push ecx
// 00602129  8bcf                 mov ecx, edi
// 0060212b  ffd2                 call edx
// 0060212d  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 00602134  8b07                 mov eax, dword ptr [edi]
// 00602136  8b5010               mov edx, dword ptr [eax + 0x10]
// 00602139  8d4c2478             lea ecx, [esp + 0x78]
// 0060213d  51                   push ecx
// 0060213e  8bcf                 mov ecx, edi
// 00602140  ffd2                 call edx
// 00602142  89842460010000       mov dword ptr [esp + 0x160], eax
// 00602149  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 00602150  40                   inc eax
// 00602151  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 00602158  3bc3                 cmp eax, ebx
// 0060215a  8d84246c010000       lea eax, [esp + 0x16c]
// 00602161  7c07                 jl 0x60216a
// 00602163  8d8424e8000000       lea eax, [esp + 0xe8]
// 0060216a  8b18                 mov ebx, dword ptr [eax]
// 0060216c  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 00602173  8bc8                 mov ecx, eax
// 00602175  40                   inc eax
// 00602176  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 0060217d  85c9                 test ecx, ecx
// 0060217f  0f85f9000000         jne 0x60227e
// 00602185  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 0060218c  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 0060218f  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 00602198  8911                 mov dword ptr [ecx], edx
// 0060219a  f30f1106             movss dword ptr [esi], xmm0
// 0060219e  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 006021a7  f30f114604           movss dword ptr [esi + 4], xmm0
// 006021ac  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 006021b5  f30f114608           movss dword ptr [esi + 8], xmm0
// 006021ba  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 006021c3  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 006021c8  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 006021d1  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 006021d6  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 006021df  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 006021e4  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 006021ed  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 006021f2  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 006021fb  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 00602200  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 00602209  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 0060220e  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 00602217  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 0060221c  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 00602225  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 0060222a  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 00602233  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 00602238  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 00602241  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 00602246  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 0060224f  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 00602254  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 0060225d  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 00602262  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 0060226b  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 00602270  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 00602279  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 0060227e  8bd3                 mov edx, ebx
// 00602280  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 00602285  8d0c9501000000       lea ecx, [edx*4 + 1]
// 0060228c  8bd0                 mov edx, eax
// 0060228e  40                   inc eax
// 0060228f  3bd1                 cmp edx, ecx
// 00602291  0f8501010000         jne 0x602398
// 00602297  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 0060229e  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 006022a1  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 006022aa  894a04               mov dword ptr [edx + 4], ecx
// 006022ad  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 006022b2  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 006022bb  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 006022c0  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 006022c9  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 006022ce  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 006022d7  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 006022dc  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 006022e5  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 006022ea  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 006022f3  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 006022f8  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 00602301  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 00602306  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 0060230f  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 00602314  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 0060231d  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 00602322  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 0060232b  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 00602330  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 00602339  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 0060233e  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 00602347  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 0060234c  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 00602355  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 0060235a  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 00602363  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 00602368  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 00602371  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 00602376  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 0060237f  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 00602387  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 00602390  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 00602398  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0060239c  41                   inc ecx
// 0060239d  0fafcb               imul ecx, ebx
// 006023a0  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 006023a7  8bc8                 mov ecx, eax
// 006023a9  40                   inc eax
// 006023aa  3bca                 cmp ecx, edx
// 006023ac  0f852e010000         jne 0x6024e0
// 006023b2  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 006023b9  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 006023bc  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 006023c5  895108               mov dword ptr [ecx + 8], edx
// 006023c8  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 006023d0  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 006023d9  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 006023e1  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 006023ea  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 006023f2  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 006023fb  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 00602403  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 0060240c  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 00602414  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 0060241d  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 00602425  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 0060242e  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 00602436  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 0060243f  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 00602447  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 00602450  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 00602458  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 00602461  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 00602469  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 00602472  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 0060247a  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 00602483  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 0060248b  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 00602494  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 0060249c  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 006024a5  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 006024ad  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 006024b6  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 006024be  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 006024c7  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 006024cf  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 006024d8  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 006024e0  8bc8                 mov ecx, eax
// 006024e2  8d149dffffffff       lea edx, [ebx*4 - 1]
// 006024e9  40                   inc eax
// 006024ea  89842478010000       mov dword ptr [esp + 0x178], eax
// 006024f1  3bca                 cmp ecx, edx
// 006024f3  0f8528010000         jne 0x602621
// 006024f9  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 006024fc  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 00602503  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 00602509  89420c               mov dword ptr [edx + 0xc], eax
// 0060250c  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 00602514  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 0060251a  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 00602522  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 0060252b  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 00602533  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 0060253c  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 00602544  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 0060254d  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 00602555  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 0060255e  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 00602566  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 0060256f  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 00602577  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 00602580  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 00602588  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 00602591  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 00602599  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 006025a2  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 006025aa  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 006025b3  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 006025bb  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 006025c4  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 006025cc  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 006025d5  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 006025dd  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 006025e6  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 006025ee  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 006025f7  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 006025ff  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 00602608  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 00602610  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 00602619  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 00602621  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 00602628  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 0060262f  8b17                 mov edx, dword ptr [edi]
// 00602631  8b5218               mov edx, dword ptr [edx + 0x18]
// 00602634  50                   push eax
// 00602635  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 0060263c  51                   push ecx
// 0060263d  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 00602644  50                   push eax
// 00602645  51                   push ecx
// 00602646  8bcf                 mov ecx, edi
// 00602648  ffd2                 call edx
// 0060264a  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 00602650  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 00602659  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 00602661  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 0060266a  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 00602670  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 00602676  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 0060267b  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 00602682  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00602686  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0060268a  e9b3eeffff           jmp 0x601542
// 0060268f  0f28fa               movaps xmm7, xmm2
// 00602692  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 00602698  0f28d9               movaps xmm3, xmm1
// 0060269b  42                   inc edx
// 0060269c  e90feeffff           jmp 0x6014b0
// 006026a1  8d4900               lea ecx, [ecx]
// 006026a4  51                   push ecx
// 006026a5  096000               or dword ptr [eax], esp
// 006026a8  bc0a6000a8           mov esp, 0xa800600a
// 006026ad  096000               or dword ptr [eax], esp
// 006026b0  6e                   outsb dx, byte ptr [esi]
// 006026b1  0a6000               or ah, byte ptr [eax]
// 006026b4  e609                 out 9, al
// 006026b6  60                   pushal 
// 006026b7  002a                 add byte ptr [edx], ch
// 006026b9  0a6000               or ah, byte ptr [eax]

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
