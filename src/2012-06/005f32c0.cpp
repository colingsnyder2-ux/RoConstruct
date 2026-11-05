// from server: 10% by intel
// roc 2012-06 005f32c0  unit: seg_005f0000  size: 7848 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005f32c0
//
// 005f32c0  55                   push ebp
// 005f32c1  8bec                 mov ebp, esp
// 005f32c3  83e4f8               and esp, 0xfffffff8
// 005f32c6  81ecfc030000         sub esp, 0x3fc
// 005f32cc  53                   push ebx
// 005f32cd  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005f32d0  56                   push esi
// 005f32d1  57                   push edi
// 005f32d2  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 005f32d5  8d44246c             lea eax, [esp + 0x6c]
// 005f32d9  8bf1                 mov esi, ecx
// 005f32db  53                   push ebx
// 005f32dc  c1ef0c               shr edi, 0xc
// 005f32df  50                   push eax
// 005f32e0  89742464             mov dword ptr [esp + 0x64], esi
// 005f32e4  83e707               and edi, 7
// 005f32e7  e884432300           call 0x827670
// 005f32ec  d9442474             fld dword ptr [esp + 0x74]
// 005f32f0  d9e1                 fabs 
// 005f32f2  8d4c2474             lea ecx, [esp + 0x74]
// 005f32f6  d99c2448010000       fstp dword ptr [esp + 0x148]
// 005f32fd  53                   push ebx
// 005f32fe  d944247c             fld dword ptr [esp + 0x7c]
// 005f3302  51                   push ecx
// 005f3303  d9e1                 fabs 
// 005f3305  d99c2454010000       fstp dword ptr [esp + 0x154]
// 005f330c  d9842484000000       fld dword ptr [esp + 0x84]
// 005f3313  d9e1                 fabs 
// 005f3315  d99c2458010000       fstp dword ptr [esp + 0x158]
// 005f331c  e84f432300           call 0x827670
// 005f3321  d944247c             fld dword ptr [esp + 0x7c]
// 005f3325  8a4670               mov al, byte ptr [esi + 0x70]
// 005f3328  d9e1                 fabs 
// 005f332a  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f3332  d9842480000000       fld dword ptr [esp + 0x80]
// 005f3339  83c410               add esp, 0x10
// 005f333c  d9e1                 fabs 
// 005f333e  d9442474             fld dword ptr [esp + 0x74]
// 005f3342  d9e1                 fabs 
// 005f3344  d9450c               fld dword ptr [ebp + 0xc]
// 005f3347  dceb                 fsub st(3), st(0)
// 005f3349  d9cb                 fxch st(3)
// 005f334b  d95c241c             fstp dword ptr [esp + 0x1c]
// 005f334f  d9c9                 fxch st(1)
// 005f3351  dee2                 fsubrp st(2)
// 005f3353  d9c9                 fxch st(1)
// 005f3355  d95c2420             fstp dword ptr [esp + 0x20]
// 005f3359  d95c2424             fstp dword ptr [esp + 0x24]
// 005f335d  84c0                 test al, al
// 005f335f  741b                 je 0x5f337c
// 005f3361  f30f100534deb600     movss xmm0, dword ptr [0xb6de34]
// 005f3369  f30f1184244c010000   movss dword ptr [esp + 0x14c], xmm0
// 005f3372  f30f1005e427b800     movss xmm0, dword ptr [0xb827e4]
// 005f337a  eb11                 jmp 0x5f338d
// 005f337c  f30f10051ce6b600     movss xmm0, dword ptr [0xb6e61c]
// 005f3384  f30f11ac244c010000   movss dword ptr [esp + 0x14c], xmm5
// 005f338d  0f57e4               xorps xmm4, xmm4
// 005f3390  f30f11842450010000   movss dword ptr [esp + 0x150], xmm0
// 005f3399  f30f11642414         movss dword ptr [esp + 0x14], xmm4
// 005f339f  f30f11642418         movss dword ptr [esp + 0x18], xmm4
// 005f33a5  f30f1164240c         movss dword ptr [esp + 0xc], xmm4
// 005f33ab  f30f11642410         movss dword ptr [esp + 0x10], xmm4
// 005f33b1  83ff05               cmp edi, 5
// 005f33b4  0f87a4010000         ja 0x5f355e
// 005f33ba  ff24bd50515f00       jmp dword ptr [edi*4 + 0x5f5150]
// 005f33c1  f30f1005e45fd900     movss xmm0, dword ptr [0xd95fe4]
// 005f33c9  8d542460             lea edx, [esp + 0x60]
// 005f33cd  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005f33d3  f30f1005e85fd900     movss xmm0, dword ptr [0xd95fe8]
// 005f33db  52                   push edx
// 005f33dc  8d4c2420             lea ecx, [esp + 0x20]
// 005f33e0  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005f33e6  e8550e0400           call 0x634240
// 005f33eb  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f33f3  f30f1000             movss xmm0, dword ptr [eax]
// 005f33f7  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005f33fc  0f57e4               xorps xmm4, xmm4
// 005f33ff  f30f59c5             mulss xmm0, xmm5
// 005f3403  f30f59cd             mulss xmm1, xmm5
// 005f3407  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 005f340d  f30f114c2418         movss dword ptr [esp + 0x18], xmm1
// 005f3413  e946010000           jmp 0x5f355e
// 005f3418  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f3420  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f3426  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f342c  84c0                 test al, al
// 005f342e  7413                 je 0x5f3443
// 005f3430  f30f1005acb5b600     movss xmm0, dword ptr [0xb6b5ac]
// 005f3438  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f343e  e91b010000           jmp 0x5f355e
// 005f3443  f30f1005c485b600     movss xmm0, dword ptr [0xb685c4]
// 005f344b  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f3451  e908010000           jmp 0x5f355e
// 005f3456  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f345c  84c0                 test al, al
// 005f345e  7419                 je 0x5f3479
// 005f3460  f30f10058426b800     movss xmm0, dword ptr [0xb82684]
// 005f3468  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005f346e  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f3474  e9e5000000           jmp 0x5f355e
// 005f3479  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f3481  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f3487  f30f10055c32b600     movss xmm0, dword ptr [0xb6325c]
// 005f348f  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f3495  e9c4000000           jmp 0x5f355e
// 005f349a  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f34a0  84c0                 test al, al
// 005f34a2  7419                 je 0x5f34bd
// 005f34a4  f30f1005e027b800     movss xmm0, dword ptr [0xb827e0]
// 005f34ac  f30f116c2418         movss dword ptr [esp + 0x18], xmm5
// 005f34b2  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f34b8  e9a1000000           jmp 0x5f355e
// 005f34bd  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f34c5  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f34cb  f30f1005a885b600     movss xmm0, dword ptr [0xb685a8]
// 005f34d3  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f34d9  e980000000           jmp 0x5f355e
// 005f34de  84c0                 test al, al
// 005f34e0  745a                 je 0x5f353c
// 005f34e2  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f34e9  7441                 je 0x5f352c
// 005f34eb  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f34f0  85c0                 test eax, eax
// 005f34f2  7418                 je 0x5f350c
// 005f34f4  68b7000000           push 0xb7
// 005f34f9  688027b800           push 0xb82780
// 005f34fe  68cc60b400           push 0xb460cc
// 005f3503  ffd0                 call eax
// 005f3505  83c40c               add esp, 0xc
// 005f3508  84c0                 test al, al
// 005f350a  7515                 jne 0x5f3521
// 005f350c  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f3513  680827b800           push 0xb82708
// 005f3518  50                   push eax
// 005f3519  e872ed3700           call 0x972290
// 005f351e  83c408               add esp, 8
// 005f3521  f30f102d6832b600     movss xmm5, dword ptr [0xb63268]
// 005f3529  0f57e4               xorps xmm4, xmm4
// 005f352c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f3534  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f353a  eb1c                 jmp 0x5f3558
// 005f353c  f30f1005049cb600     movss xmm0, dword ptr [0xb69c04]
// 005f3544  f30f11442418         movss dword ptr [esp + 0x18], xmm0
// 005f354a  f30f10058085b600     movss xmm0, dword ptr [0xb68580]
// 005f3552  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 005f3558  f30f116c2414         movss dword ptr [esp + 0x14], xmm5
// 005f355e  807e7000             cmp byte ptr [esi + 0x70], 0
// 005f3562  7419                 je 0x5f357d
// 005f3564  f30f104514           movss xmm0, dword ptr [ebp + 0x14]
// 005f3569  f30f590594deb600     mulss xmm0, dword ptr [0xb6de94]
// 005f3571  f30f5844240c         addss xmm0, dword ptr [esp + 0xc]
// 005f3577  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005f357d  85ff                 test edi, edi
// 005f357f  0f85da080000         jne 0x5f3e5f
// 005f3585  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f358d  f30f104e78           movss xmm1, dword ptr [esi + 0x78]
// 005f3592  f30f109e80000000     movss xmm3, dword ptr [esi + 0x80]
// 005f359a  f30f10567c           movss xmm2, dword ptr [esi + 0x7c]
// 005f359f  f30f114c246c         movss dword ptr [esp + 0x6c], xmm1
// 005f35a5  f30f118c24d0010000   movss dword ptr [esp + 0x1d0], xmm1
// 005f35ae  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f35b6  f30f11442474         movss dword ptr [esp + 0x74], xmm0
// 005f35bc  f30f118c24d4010000   movss dword ptr [esp + 0x1d4], xmm1
// 005f35c5  f30f118424d8010000   movss dword ptr [esp + 0x1d8], xmm0
// 005f35ce  f30f118424e8010000   movss dword ptr [esp + 0x1e8], xmm0
// 005f35d7  f30f118c24c4010000   movss dword ptr [esp + 0x1c4], xmm1
// 005f35e0  f30f108c2444010000   movss xmm1, dword ptr [esp + 0x144]
// 005f35e9  f30f118424c8010000   movss dword ptr [esp + 0x1c8], xmm0
// 005f35f2  f30f1184248c010000   movss dword ptr [esp + 0x18c], xmm0
// 005f35fb  f30f10842440010000   movss xmm0, dword ptr [esp + 0x140]
// 005f3604  f30f59c5             mulss xmm0, xmm5
// 005f3608  f30f59cd             mulss xmm1, xmm5
// 005f360c  f30f119c24e0010000   movss dword ptr [esp + 0x1e0], xmm3
// 005f3615  f30f119c24c0010000   movss dword ptr [esp + 0x1c0], xmm3
// 005f361e  f30f105d0c           movss xmm3, dword ptr [ebp + 0xc]
// 005f3623  f30f11a42490010000   movss dword ptr [esp + 0x190], xmm4
// 005f362c  f30f11a42494010000   movss dword ptr [esp + 0x194], xmm4
// 005f3635  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005f363c  f30f11542470         movss dword ptr [esp + 0x70], xmm2
// 005f3642  f30f119424e4010000   movss dword ptr [esp + 0x1e4], xmm2
// 005f364b  0f28e3               movaps xmm4, xmm3
// 005f364e  f30f5ce0             subss xmm4, xmm0
// 005f3652  0f28eb               movaps xmm5, xmm3
// 005f3655  f30f5ce9             subss xmm5, xmm1
// 005f3659  51                   push ecx
// 005f365a  8d542464             lea edx, [esp + 0x64]
// 005f365e  f30f5cc3             subss xmm0, xmm3
// 005f3662  0f28d3               movaps xmm2, xmm3
// 005f3665  0f57159031b600       xorps xmm2, xmmword ptr [0xb63190]
// 005f366c  f30f5ccb             subss xmm1, xmm3
// 005f3670  52                   push edx
// 005f3671  f30f119c2484010000   movss dword ptr [esp + 0x184], xmm3
// 005f367a  f30f119c2488010000   movss dword ptr [esp + 0x188], xmm3
// 005f3683  f30f11a4248c010000   movss dword ptr [esp + 0x18c], xmm4
// 005f368c  f30f11ac2490010000   movss dword ptr [esp + 0x190], xmm5
// 005f3695  f30f11842414010000   movss dword ptr [esp + 0x114], xmm0
// 005f369e  f30f119c2418010000   movss dword ptr [esp + 0x118], xmm3
// 005f36a7  f30f1194241c010000   movss dword ptr [esp + 0x11c], xmm2
// 005f36b0  f30f11ac2420010000   movss dword ptr [esp + 0x120], xmm5
// 005f36b9  f30f11842434010000   movss dword ptr [esp + 0x134], xmm0
// 005f36c2  f30f118c2438010000   movss dword ptr [esp + 0x138], xmm1
// 005f36cb  f30f1194243c010000   movss dword ptr [esp + 0x13c], xmm2
// 005f36d4  f30f11942440010000   movss dword ptr [esp + 0x140], xmm2
// 005f36dd  f30f119c2424010000   movss dword ptr [esp + 0x124], xmm3
// 005f36e6  f30f118c2428010000   movss dword ptr [esp + 0x128], xmm1
// 005f36ef  f30f11a4242c010000   movss dword ptr [esp + 0x12c], xmm4
// 005f36f8  f30f11942430010000   movss dword ptr [esp + 0x130], xmm2
// 005f3701  f30f11a424c0010000   movss dword ptr [esp + 0x1c0], xmm4
// 005f370a  f30f11ac24c4010000   movss dword ptr [esp + 0x1c4], xmm5
// 005f3713  e8583f2300           call 0x827670
// 005f3718  8d442474             lea eax, [esp + 0x74]
// 005f371c  50                   push eax
// 005f371d  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005f3724  51                   push ecx
// 005f3725  e8463f2300           call 0x827670
// 005f372a  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 005f3732  f30f104c242c         movss xmm1, dword ptr [esp + 0x2c]
// 005f3738  0f57c8               xorps xmm1, xmm0
// 005f373b  f30f118c24d0000000   movss dword ptr [esp + 0xd0], xmm1
// 005f3744  f30f104c2430         movss xmm1, dword ptr [esp + 0x30]
// 005f374a  8d9424d0000000       lea edx, [esp + 0xd0]
// 005f3751  0f57c8               xorps xmm1, xmm0
// 005f3754  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f375a  52                   push edx
// 005f375b  8d8424ec000000       lea eax, [esp + 0xec]
// 005f3762  50                   push eax
// 005f3763  f30f118c24dc000000   movss dword ptr [esp + 0xdc], xmm1
// 005f376c  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f3775  e8f63e2300           call 0x827670
// 005f377a  83c418               add esp, 0x18
// 005f377d  8d4c2440             lea ecx, [esp + 0x40]
// 005f3781  51                   push ecx
// 005f3782  8d8c2480010000       lea ecx, [esp + 0x180]
// 005f3789  e8b20a0400           call 0x634240
// 005f378e  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005f3795  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f379b  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005f37a2  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005f37a9  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005f37ac  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f37b5  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f37bb  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f37c4  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f37ca  89542478             mov dword ptr [esp + 0x78], edx
// 005f37ce  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005f37d5  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f37de  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f37e4  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f37eb  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005f37f2  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f37f9  8b542460             mov edx, dword ptr [esp + 0x60]
// 005f37fd  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f3806  f30f10450c           movss xmm0, dword ptr [ebp + 0xc]
// 005f380b  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f380f  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005f3816  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f381d  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f3821  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f382a  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f3833  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f383c  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f3843  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f384a  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f384e  8d542478             lea edx, [esp + 0x78]
// 005f3852  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f3859  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f3862  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f386b  52                   push edx
// 005f386c  8bce                 mov ecx, esi
// 005f386e  89842498000000       mov dword ptr [esp + 0x98], eax
// 005f3875  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f387e  e83d6affff           call 0x5ea2c0
// 005f3883  f30f1084240c010000   movss xmm0, dword ptr [esp + 0x10c]
// 005f388c  8b7d24               mov edi, dword ptr [ebp + 0x24]
// 005f388f  d907                 fld dword ptr [edi]
// 005f3891  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f3897  f30f10842410010000   movss xmm0, dword ptr [esp + 0x110]
// 005f38a0  d95e24               fstp dword ptr [esi + 0x24]
// 005f38a3  d94704               fld dword ptr [edi + 4]
// 005f38a6  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f38ac  f30f10842414010000   movss xmm0, dword ptr [esp + 0x114]
// 005f38b5  d95e28               fstp dword ptr [esi + 0x28]
// 005f38b8  8d84248c010000       lea eax, [esp + 0x18c]
// 005f38bf  50                   push eax
// 005f38c0  8d4c2464             lea ecx, [esp + 0x64]
// 005f38c4  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f38ca  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005f38d3  51                   push ecx
// 005f38d4  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f38da  e8913d2300           call 0x827670
// 005f38df  8d9424e8010000       lea edx, [esp + 0x1e8]
// 005f38e6  52                   push edx
// 005f38e7  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f38ee  50                   push eax
// 005f38ef  e87c3d2300           call 0x827670
// 005f38f4  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f38fa  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f3903  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f3909  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f3910  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 005f3917  51                   push ecx
// 005f3918  8d9424ec000000       lea edx, [esp + 0xec]
// 005f391f  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f3928  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f392e  52                   push edx
// 005f392f  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f3938  e8333d2300           call 0x827670
// 005f393d  83c418               add esp, 0x18
// 005f3940  8d442440             lea eax, [esp + 0x40]
// 005f3944  50                   push eax
// 005f3945  8d8c2410010000       lea ecx, [esp + 0x110]
// 005f394c  e8ef080400           call 0x634240
// 005f3951  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 005f3958  8b9424dc000000       mov edx, dword ptr [esp + 0xdc]
// 005f395f  894c2478             mov dword ptr [esp + 0x78], ecx
// 005f3963  8954247c             mov dword ptr [esp + 0x7c], edx
// 005f3967  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f396d  8b8c24cc000000       mov ecx, dword ptr [esp + 0xcc]
// 005f3974  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 005f397b  8b9424d0000000       mov edx, dword ptr [esp + 0xd0]
// 005f3982  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f398b  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f3991  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f399a  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f39a0  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f39a9  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f39af  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f39b8  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f39be  898c2484000000       mov dword ptr [esp + 0x84], ecx
// 005f39c5  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005f39c9  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f39d2  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f39d8  89842480000000       mov dword ptr [esp + 0x80], eax
// 005f39df  8b8424d4000000       mov eax, dword ptr [esp + 0xd4]
// 005f39e6  898c2490000000       mov dword ptr [esp + 0x90], ecx
// 005f39ed  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f39f6  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f39fc  8d4c2478             lea ecx, [esp + 0x78]
// 005f3a00  89942488000000       mov dword ptr [esp + 0x88], edx
// 005f3a07  8b542464             mov edx, dword ptr [esp + 0x64]
// 005f3a0b  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 005f3a12  8b442468             mov eax, dword ptr [esp + 0x68]
// 005f3a16  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f3a1f  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f3a25  8d5e44               lea ebx, [esi + 0x44]
// 005f3a28  51                   push ecx
// 005f3a29  8bcb                 mov ecx, ebx
// 005f3a2b  89942498000000       mov dword ptr [esp + 0x98], edx
// 005f3a32  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 005f3a39  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f3a42  e87968ffff           call 0x5ea2c0
// 005f3a47  d94708               fld dword ptr [edi + 8]
// 005f3a4a  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005f3a53  d95e68               fstp dword ptr [esi + 0x68]
// 005f3a56  d9470c               fld dword ptr [edi + 0xc]
// 005f3a59  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f3a5f  f30f10842430010000   movss xmm0, dword ptr [esp + 0x130]
// 005f3a68  d95e6c               fstp dword ptr [esi + 0x6c]
// 005f3a6b  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f3a71  f30f10842434010000   movss xmm0, dword ptr [esp + 0x134]
// 005f3a7a  8d94248c010000       lea edx, [esp + 0x18c]
// 005f3a81  52                   push edx
// 005f3a82  8d442464             lea eax, [esp + 0x64]
// 005f3a86  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f3a8c  f30f1084243c010000   movss xmm0, dword ptr [esp + 0x13c]
// 005f3a95  50                   push eax
// 005f3a96  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f3a9c  e8cf3b2300           call 0x827670
// 005f3aa1  8d8c24c8010000       lea ecx, [esp + 0x1c8]
// 005f3aa8  51                   push ecx
// 005f3aa9  8d9424d8000000       lea edx, [esp + 0xd8]
// 005f3ab0  52                   push edx
// 005f3ab1  e8ba3b2300           call 0x827670
// 005f3ab6  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f3abc  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f3ac5  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f3acb  8d8424d0000000       lea eax, [esp + 0xd0]
// 005f3ad2  50                   push eax
// 005f3ad3  8d8c24ec000000       lea ecx, [esp + 0xec]
// 005f3ada  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f3ae3  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f3ae9  51                   push ecx
// 005f3aea  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f3af3  e8783b2300           call 0x827670
// 005f3af8  83c418               add esp, 0x18
// 005f3afb  8d542440             lea edx, [esp + 0x40]
// 005f3aff  52                   push edx
// 005f3b00  8d8c2430010000       lea ecx, [esp + 0x130]
// 005f3b07  e834070400           call 0x634240
// 005f3b0c  8b8424d8000000       mov eax, dword ptr [esp + 0xd8]
// 005f3b13  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 005f3b1a  8b9424e0000000       mov edx, dword ptr [esp + 0xe0]
// 005f3b21  89442478             mov dword ptr [esp + 0x78], eax
// 005f3b25  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 005f3b2c  894c247c             mov dword ptr [esp + 0x7c], ecx
// 005f3b30  89942480000000       mov dword ptr [esp + 0x80], edx
// 005f3b37  89842484000000       mov dword ptr [esp + 0x84], eax
// 005f3b3e  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f3b44  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 005f3b4b  8b442460             mov eax, dword ptr [esp + 0x60]
// 005f3b4f  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 005f3b56  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f3b5f  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f3b65  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f3b6e  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f3b74  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f3b7d  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f3b83  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f3b8c  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f3b92  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f3b9b  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f3ba1  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 005f3ba8  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005f3bac  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f3bb5  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f3bbb  89842490000000       mov dword ptr [esp + 0x90], eax
// 005f3bc2  8994248c000000       mov dword ptr [esp + 0x8c], edx
// 005f3bc9  8b542468             mov edx, dword ptr [esp + 0x68]
// 005f3bcd  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 005f3bd4  8d442478             lea eax, [esp + 0x78]
// 005f3bd8  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f3be1  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f3be7  8d8e88000000         lea ecx, [esi + 0x88]
// 005f3bed  50                   push eax
// 005f3bee  8994249c000000       mov dword ptr [esp + 0x9c], edx
// 005f3bf5  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f3bfe  894c2460             mov dword ptr [esp + 0x60], ecx
// 005f3c02  e8b966ffff           call 0x5ea2c0
// 005f3c07  d94710               fld dword ptr [edi + 0x10]
// 005f3c0a  f30f1084241c010000   movss xmm0, dword ptr [esp + 0x11c]
// 005f3c13  d99eac000000         fstp dword ptr [esi + 0xac]
// 005f3c19  d94714               fld dword ptr [edi + 0x14]
// 005f3c1c  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f3c22  f30f10842420010000   movss xmm0, dword ptr [esp + 0x120]
// 005f3c2b  d99eb0000000         fstp dword ptr [esi + 0xb0]
// 005f3c31  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f3c37  f30f10842424010000   movss xmm0, dword ptr [esp + 0x124]
// 005f3c40  8d8c248c010000       lea ecx, [esp + 0x18c]
// 005f3c47  51                   push ecx
// 005f3c48  8d542464             lea edx, [esp + 0x64]
// 005f3c4c  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f3c52  f30f1084242c010000   movss xmm0, dword ptr [esp + 0x12c]
// 005f3c5b  52                   push edx
// 005f3c5c  f30f1144243c         movss dword ptr [esp + 0x3c], xmm0
// 005f3c62  e8093a2300           call 0x827670
// 005f3c67  8d8424d8010000       lea eax, [esp + 0x1d8]
// 005f3c6e  50                   push eax
// 005f3c6f  8d8c24d8000000       lea ecx, [esp + 0xd8]
// 005f3c76  51                   push ecx
// 005f3c77  e8f4392300           call 0x827670
// 005f3c7c  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f3c82  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f3c89  f30f118424d0000000   movss dword ptr [esp + 0xd0], xmm0
// 005f3c92  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f3c98  8d9424d0000000       lea edx, [esp + 0xd0]
// 005f3c9f  52                   push edx
// 005f3ca0  8d8424ec000000       lea eax, [esp + 0xec]
// 005f3ca7  f30f118424d8000000   movss dword ptr [esp + 0xd8], xmm0
// 005f3cb0  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f3cb6  50                   push eax
// 005f3cb7  f30f118424e0000000   movss dword ptr [esp + 0xe0], xmm0
// 005f3cc0  e8ab392300           call 0x827670
// 005f3cc5  83c418               add esp, 0x18
// 005f3cc8  8d4c2440             lea ecx, [esp + 0x40]
// 005f3ccc  51                   push ecx
// 005f3ccd  8d8c2420010000       lea ecx, [esp + 0x120]
// 005f3cd4  e867050400           call 0x634240
// 005f3cd9  8b9424d8000000       mov edx, dword ptr [esp + 0xd8]
// 005f3ce0  8b8424dc000000       mov eax, dword ptr [esp + 0xdc]
// 005f3ce7  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 005f3cee  89542478             mov dword ptr [esp + 0x78], edx
// 005f3cf2  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 005f3cf9  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f3cfd  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 005f3d04  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f3d0b  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 005f3d12  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f3d19  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f3d20  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005f3d26  8b542460             mov edx, dword ptr [esp + 0x60]
// 005f3d2a  8b442464             mov eax, dword ptr [esp + 0x64]
// 005f3d2e  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f3d37  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005f3d3d  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f3d46  f30f10442440         movss xmm0, dword ptr [esp + 0x40]
// 005f3d4c  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f3d55  f30f10442444         movss xmm0, dword ptr [esp + 0x44]
// 005f3d5b  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f3d64  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f3d6a  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f3d73  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f3d79  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f3d80  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f3d84  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f3d8d  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f3d93  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f3d9a  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f3da1  8d542478             lea edx, [esp + 0x78]
// 005f3da5  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f3dae  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f3db4  8d8ecc000000         lea ecx, [esi + 0xcc]
// 005f3dba  52                   push edx
// 005f3dbb  89842498000000       mov dword ptr [esp + 0x98], eax
// 005f3dc2  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f3dcb  898c24e8000000       mov dword ptr [esp + 0xe8], ecx
// 005f3dd2  e8e964ffff           call 0x5ea2c0
// 005f3dd7  d94718               fld dword ptr [edi + 0x18]
// 005f3dda  d99ef0000000         fstp dword ptr [esi + 0xf0]
// 005f3de0  56                   push esi
// 005f3de1  d9471c               fld dword ptr [edi + 0x1c]
// 005f3de4  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f3de7  8b07                 mov eax, dword ptr [edi]
// 005f3de9  d99ef4000000         fstp dword ptr [esi + 0xf4]
// 005f3def  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f3df2  8bcf                 mov ecx, edi
// 005f3df4  ffd2                 call edx
// 005f3df6  8bf0                 mov esi, eax
// 005f3df8  8b07                 mov eax, dword ptr [edi]
// 005f3dfa  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f3dfd  53                   push ebx
// 005f3dfe  8bcf                 mov ecx, edi
// 005f3e00  ffd2                 call edx
// 005f3e02  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f3e06  8bd8                 mov ebx, eax
// 005f3e08  8b07                 mov eax, dword ptr [edi]
// 005f3e0a  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f3e0d  51                   push ecx
// 005f3e0e  8bcf                 mov ecx, edi
// 005f3e10  ffd2                 call edx
// 005f3e12  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 005f3e19  8944243c             mov dword ptr [esp + 0x3c], eax
// 005f3e1d  8b07                 mov eax, dword ptr [edi]
// 005f3e1f  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f3e22  51                   push ecx
// 005f3e23  8bcf                 mov ecx, edi
// 005f3e25  ffd2                 call edx
// 005f3e27  8b17                 mov edx, dword ptr [edi]
// 005f3e29  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f3e2c  50                   push eax
// 005f3e2d  89442460             mov dword ptr [esp + 0x60], eax
// 005f3e31  8b442440             mov eax, dword ptr [esp + 0x40]
// 005f3e35  50                   push eax
// 005f3e36  53                   push ebx
// 005f3e37  56                   push esi
// 005f3e38  8bcf                 mov ecx, edi
// 005f3e3a  ffd2                 call edx
// 005f3e3c  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005f3e3f  85c0                 test eax, eax
// 005f3e41  7413                 je 0x5f3e56
// 005f3e43  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f3e47  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005f3e4b  8930                 mov dword ptr [eax], esi
// 005f3e4d  895804               mov dword ptr [eax + 4], ebx
// 005f3e50  894808               mov dword ptr [eax + 8], ecx
// 005f3e53  89500c               mov dword ptr [eax + 0xc], edx
// 005f3e56  5f                   pop edi
// 005f3e57  5e                   pop esi
// 005f3e58  5b                   pop ebx
// 005f3e59  8be5                 mov esp, ebp
// 005f3e5b  5d                   pop ebp
// 005f3e5c  c22000               ret 0x20
// 005f3e5f  803db380e50000       cmp byte ptr [0xe580b3], 0
// 005f3e66  743c                 je 0x5f3ea4
// 005f3e68  837d1c00             cmp dword ptr [ebp + 0x1c], 0
// 005f3e6c  7536                 jne 0x5f3ea4
// 005f3e6e  a19c80e500           mov eax, dword ptr [0xe5809c]
// 005f3e73  85c0                 test eax, eax
// 005f3e75  7418                 je 0x5f3e8f
// 005f3e77  6801010000           push 0x101
// 005f3e7c  688027b800           push 0xb82780
// 005f3e81  680027b800           push 0xb82700
// 005f3e86  ffd0                 call eax
// 005f3e88  83c40c               add esp, 0xc
// 005f3e8b  84c0                 test al, al
// 005f3e8d  7515                 jne 0x5f3ea4
// 005f3e8f  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 005f3e96  688826b800           push 0xb82688
// 005f3e9b  50                   push eax
// 005f3e9c  e8efe33700           call 0x972290
// 005f3ea1  83c408               add esp, 8
// 005f3ea4  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005f3eaa  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f3eb1  f30f108e84000000     movss xmm1, dword ptr [esi + 0x84]
// 005f3eb9  f30f10157027b600     movss xmm2, dword ptr [0xb62770]
// 005f3ec1  f30f5c4e7c           subss xmm1, dword ptr [esi + 0x7c]
// 005f3ec6  f30f11442454         movss dword ptr [esp + 0x54], xmm0
// 005f3ecc  f30f108680000000     movss xmm0, dword ptr [esi + 0x80]
// 005f3ed4  f30f5c4678           subss xmm0, dword ptr [esi + 0x78]
// 005f3ed9  8d4c2460             lea ecx, [esp + 0x60]
// 005f3edd  51                   push ecx
// 005f3ede  f30f59c2             mulss xmm0, xmm2
// 005f3ee2  f30f59ca             mulss xmm1, xmm2
// 005f3ee6  8d4c2420             lea ecx, [esp + 0x20]
// 005f3eea  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f3ef3  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f3efc  e83f030400           call 0x634240
// 005f3f01  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f3f0a  f30f5e00             divss xmm0, dword ptr [eax]
// 005f3f0e  f30f105e78           movss xmm3, dword ptr [esi + 0x78]
// 005f3f13  8b7520               mov esi, dword ptr [ebp + 0x20]
// 005f3f16  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f3f19  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f3f1e  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f3f26  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f3f2c  f30f118424e0020000   movss dword ptr [esp + 0x2e0], xmm0
// 005f3f35  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f3f3e  f30f5e4004           divss xmm0, dword ptr [eax + 4]
// 005f3f43  33d2                 xor edx, edx
// 005f3f45  33db                 xor ebx, ebx
// 005f3f47  f30f118424e4020000   movss dword ptr [esp + 0x2e4], xmm0
// 005f3f50  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f3f57  899c2478010000       mov dword ptr [esp + 0x178], ebx
// 005f3f5e  f30f1054241c         movss xmm2, dword ptr [esp + 0x1c]
// 005f3f64  0f2fd7               comiss xmm2, xmm7
// 005f3f67  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005f3f6d  8954243c             mov dword ptr [esp + 0x3c], edx
// 005f3f71  f30f119c24f4000000   movss dword ptr [esp + 0xf4], xmm3
// 005f3f7a  770a                 ja 0x5f3f86
// 005f3f7c  85d2                 test edx, edx
// 005f3f7e  0f85d2feffff         jne 0x5f3e56
// 005f3f84  eb04                 jmp 0x5f3f8a
// 005f3f86  85d2                 test edx, edx
// 005f3f88  7504                 jne 0x5f3f8e
// 005f3f8a  f30f5cc4             subss xmm0, xmm4
// 005f3f8e  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f3f92  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f3f96  7421                 je 0x5f3fb9
// 005f3f98  f30f58c7             addss xmm0, xmm7
// 005f3f9c  0f2fc2               comiss xmm0, xmm2
// 005f3f9f  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f3fa8  8d44241c             lea eax, [esp + 0x1c]
// 005f3fac  7707                 ja 0x5f3fb5
// 005f3fae  8d84240c030000       lea eax, [esp + 0x30c]
// 005f3fb5  f30f1010             movss xmm2, dword ptr [eax]
// 005f3fb9  f30f108c24e0020000   movss xmm1, dword ptr [esp + 0x2e0]
// 005f3fc2  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f3fc8  0f57059031b600       xorps xmm0, xmmword ptr [0xb63190]
// 005f3fcf  f30f58cb             addss xmm1, xmm3
// 005f3fd3  f30f10597c           movss xmm3, dword ptr [ecx + 0x7c]
// 005f3fd8  33c0                 xor eax, eax
// 005f3fda  f30f1154244c         movss dword ptr [esp + 0x4c], xmm2
// 005f3fe0  f30f118c24fc000000   movss dword ptr [esp + 0xfc], xmm1
// 005f3fe9  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f3ff0  f30f10742420         movss xmm6, dword ptr [esp + 0x20]
// 005f3ff6  0f2ff0               comiss xmm6, xmm0
// 005f3ff9  f30f119c24f8000000   movss dword ptr [esp + 0xf8], xmm3
// 005f4002  f30f11442458         movss dword ptr [esp + 0x58], xmm0
// 005f4008  7708                 ja 0x5f4012
// 005f400a  85c0                 test eax, eax
// 005f400c  0f852b110000         jne 0x5f513d
// 005f4012  f30f104c2418         movss xmm1, dword ptr [esp + 0x18]
// 005f4018  85c0                 test eax, eax
// 005f401a  7504                 jne 0x5f4020
// 005f401c  f30f5ccc             subss xmm1, xmm4
// 005f4020  0f28f1               movaps xmm6, xmm1
// 005f4023  f30f58f0             addss xmm6, xmm0
// 005f4027  0f2f742420           comiss xmm6, dword ptr [esp + 0x20]
// 005f402c  f30f11b424dc020000   movss dword ptr [esp + 0x2dc], xmm6
// 005f4035  8d442420             lea eax, [esp + 0x20]
// 005f4039  7707                 ja 0x5f4042
// 005f403b  8d8424dc020000       lea eax, [esp + 0x2dc]
// 005f4042  80797000             cmp byte ptr [ecx + 0x70], 0
// 005f4046  f30f1000             movss xmm0, dword ptr [eax]
// 005f404a  f30f11442450         movss dword ptr [esp + 0x50], xmm0
// 005f4050  f30f108424e4020000   movss xmm0, dword ptr [esp + 0x2e4]
// 005f4059  f30f58c3             addss xmm0, xmm3
// 005f405d  f30f11842400010000   movss dword ptr [esp + 0x100], xmm0
// 005f4066  0f57c0               xorps xmm0, xmm0
// 005f4069  f30f11442440         movss dword ptr [esp + 0x40], xmm0
// 005f406f  740f                 je 0x5f4080
// 005f4071  e81a62ffff           call 0x5ea290
// 005f4076  d80d94deb600         fmul dword ptr [0xb6de94]
// 005f407c  d95c2440             fstp dword ptr [esp + 0x40]
// 005f4080  0f28dd               movaps xmm3, xmm5
// 005f4083  f30f5e9c244c010000   divss xmm3, dword ptr [esp + 0x14c]
// 005f408c  0f28c3               movaps xmm0, xmm3
// 005f408f  f30f59c4             mulss xmm0, xmm4
// 005f4093  f30f5cd7             subss xmm2, xmm7
// 005f4097  f30f59d3             mulss xmm2, xmm3
// 005f409b  f30f105c240c         movss xmm3, dword ptr [esp + 0xc]
// 005f40a1  f30f5c5c2440         subss xmm3, dword ptr [esp + 0x40]
// 005f40a7  f30f58d3             addss xmm2, xmm3
// 005f40ab  f30f105c2450         movss xmm3, dword ptr [esp + 0x50]
// 005f40b1  f30f5c5c2458         subss xmm3, dword ptr [esp + 0x58]
// 005f40b7  f30f11442460         movss dword ptr [esp + 0x60], xmm0
// 005f40bd  0f28c5               movaps xmm0, xmm5
// 005f40c0  f30f5e842450010000   divss xmm0, dword ptr [esp + 0x150]
// 005f40c9  0f28e9               movaps xmm5, xmm1
// 005f40cc  0f28f0               movaps xmm6, xmm0
// 005f40cf  f30f59f4             mulss xmm6, xmm4
// 005f40d3  f30f10642440         movss xmm4, dword ptr [esp + 0x40]
// 005f40d9  f30f5864240c         addss xmm4, dword ptr [esp + 0xc]
// 005f40df  f30f5ccb             subss xmm1, xmm3
// 005f40e3  f30f59e8             mulss xmm5, xmm0
// 005f40e7  f30f586c2410         addss xmm5, dword ptr [esp + 0x10]
// 005f40ed  f30f59c8             mulss xmm1, xmm0
// 005f40f1  f30f584c2410         addss xmm1, dword ptr [esp + 0x10]
// 005f40f7  f30f11a42404010000   movss dword ptr [esp + 0x104], xmm4
// 005f4100  f30f11ac2408010000   movss dword ptr [esp + 0x108], xmm5
// 005f4109  f30f11942454010000   movss dword ptr [esp + 0x154], xmm2
// 005f4112  f30f11ac2458010000   movss dword ptr [esp + 0x158], xmm5
// 005f411b  f30f11942464010000   movss dword ptr [esp + 0x164], xmm2
// 005f4124  f30f118c2468010000   movss dword ptr [esp + 0x168], xmm1
// 005f412d  f30f11a42470010000   movss dword ptr [esp + 0x170], xmm4
// 005f4136  f30f118c2474010000   movss dword ptr [esp + 0x174], xmm1
// 005f413f  85d2                 test edx, edx
// 005f4141  753f                 jne 0x5f4182
// 005f4143  f30f105c2460         movss xmm3, dword ptr [esp + 0x60]
// 005f4149  0f28c4               movaps xmm0, xmm4
// 005f414c  f30f58c3             addss xmm0, xmm3
// 005f4150  f30f11842404010000   movss dword ptr [esp + 0x104], xmm0
// 005f4159  0f28c3               movaps xmm0, xmm3
// 005f415c  f30f58c2             addss xmm0, xmm2
// 005f4160  f30f11842454010000   movss dword ptr [esp + 0x154], xmm0
// 005f4169  f30f11842464010000   movss dword ptr [esp + 0x164], xmm0
// 005f4172  0f28c4               movaps xmm0, xmm4
// 005f4175  f30f58c3             addss xmm0, xmm3
// 005f4179  f30f11842470010000   movss dword ptr [esp + 0x170], xmm0
// 005f4182  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005f4188  0f2f442450           comiss xmm0, dword ptr [esp + 0x50]
// 005f418d  772f                 ja 0x5f41be
// 005f418f  0f28c6               movaps xmm0, xmm6
// 005f4192  f30f58c5             addss xmm0, xmm5
// 005f4196  f30f58f1             addss xmm6, xmm1
// 005f419a  f30f11842408010000   movss dword ptr [esp + 0x108], xmm0
// 005f41a3  f30f11842458010000   movss dword ptr [esp + 0x158], xmm0
// 005f41ac  f30f11b42468010000   movss dword ptr [esp + 0x168], xmm6
// 005f41b5  f30f11b42474010000   movss dword ptr [esp + 0x174], xmm6
// 005f41be  8d9424cc000000       lea edx, [esp + 0xcc]
// 005f41c5  52                   push edx
// 005f41c6  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f41cd  e86e000400           call 0x634240
// 005f41d2  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f41d7  f30f1008             movss xmm1, dword ptr [eax]
// 005f41db  f30f58442458         addss xmm0, dword ptr [esp + 0x58]
// 005f41e1  f30f584c2454         addss xmm1, dword ptr [esp + 0x54]
// 005f41e7  8d8424d8000000       lea eax, [esp + 0xd8]
// 005f41ee  50                   push eax
// 005f41ef  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f41f6  f30f118c24a4010000   movss dword ptr [esp + 0x1a4], xmm1
// 005f41ff  f30f118424a8010000   movss dword ptr [esp + 0x1a8], xmm0
// 005f4208  e833000400           call 0x634240
// 005f420d  f30f104004           movss xmm0, dword ptr [eax + 4]
// 005f4212  f30f1008             movss xmm1, dword ptr [eax]
// 005f4216  f30f58442450         addss xmm0, dword ptr [esp + 0x50]
// 005f421c  f30f584c244c         addss xmm1, dword ptr [esp + 0x4c]
// 005f4222  8d8c24c0000000       lea ecx, [esp + 0xc0]
// 005f4229  51                   push ecx
// 005f422a  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f4231  f30f118c24ac010000   movss dword ptr [esp + 0x1ac], xmm1
// 005f423a  f30f118424b0010000   movss dword ptr [esp + 0x1b0], xmm0
// 005f4243  e8f8ff0300           call 0x634240
// 005f4248  f30f10442458         movss xmm0, dword ptr [esp + 0x58]
// 005f424e  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f4253  f30f104c2454         movss xmm1, dword ptr [esp + 0x54]
// 005f4259  f30f5c08             subss xmm1, dword ptr [eax]
// 005f425d  8d94248c010000       lea edx, [esp + 0x18c]
// 005f4264  52                   push edx
// 005f4265  8d8c2444010000       lea ecx, [esp + 0x144]
// 005f426c  f30f118c249c010000   movss dword ptr [esp + 0x19c], xmm1
// 005f4275  f30f118424a0010000   movss dword ptr [esp + 0x1a0], xmm0
// 005f427e  e8bdff0300           call 0x634240
// 005f4283  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f4289  f30f5c4004           subss xmm0, dword ptr [eax + 4]
// 005f428e  f30f104c244c         movss xmm1, dword ptr [esp + 0x4c]
// 005f4294  f30f5c08             subss xmm1, dword ptr [eax]
// 005f4298  8d842498010000       lea eax, [esp + 0x198]
// 005f429f  f30f118424f0000000   movss dword ptr [esp + 0xf0], xmm0
// 005f42a8  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f42b0  50                   push eax
// 005f42b1  8d8c24a4010000       lea ecx, [esp + 0x1a4]
// 005f42b8  f30f11442470         movss dword ptr [esp + 0x70], xmm0
// 005f42be  0f57c0               xorps xmm0, xmm0
// 005f42c1  51                   push ecx
// 005f42c2  8d8c24b8010000       lea ecx, [esp + 0x1b8]
// 005f42c9  f30f118c24f4000000   movss dword ptr [esp + 0xf4], xmm1
// 005f42d2  f30f11442478         movss dword ptr [esp + 0x78], xmm0
// 005f42d8  f30f1144247c         movss dword ptr [esp + 0x7c], xmm0
// 005f42de  e82dff0300           call 0x634210
// 005f42e3  f30f108424a8010000   movss xmm0, dword ptr [esp + 0x1a8]
// 005f42ec  f30f118424f0010000   movss dword ptr [esp + 0x1f0], xmm0
// 005f42f5  f30f108424a4010000   movss xmm0, dword ptr [esp + 0x1a4]
// 005f42fe  f30f118424f4010000   movss dword ptr [esp + 0x1f4], xmm0
// 005f4307  f30f108424ec000000   movss xmm0, dword ptr [esp + 0xec]
// 005f4310  8d9424ec000000       lea edx, [esp + 0xec]
// 005f4317  52                   push edx
// 005f4318  8d8424ac010000       lea eax, [esp + 0x1ac]
// 005f431f  f30f118424fc010000   movss dword ptr [esp + 0x1fc], xmm0
// 005f4328  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f4331  50                   push eax
// 005f4332  8d8c2484010000       lea ecx, [esp + 0x184]
// 005f4339  f30f11842404020000   movss dword ptr [esp + 0x204], xmm0
// 005f4342  e8c9fe0300           call 0x634210
// 005f4347  f30f108424a0010000   movss xmm0, dword ptr [esp + 0x1a0]
// 005f4350  f30f11442428         movss dword ptr [esp + 0x28], xmm0
// 005f4356  f30f108424ac010000   movss xmm0, dword ptr [esp + 0x1ac]
// 005f435f  f30f1144242c         movss dword ptr [esp + 0x2c], xmm0
// 005f4365  f30f10842498010000   movss xmm0, dword ptr [esp + 0x198]
// 005f436e  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005f4374  f30f108424f0000000   movss xmm0, dword ptr [esp + 0xf0]
// 005f437d  f30f11442434         movss dword ptr [esp + 0x34], xmm0
// 005f4383  f30f108424b0010000   movss xmm0, dword ptr [esp + 0x1b0]
// 005f438c  f30f11842420030000   movss dword ptr [esp + 0x320], xmm0
// 005f4395  f30f108424b4010000   movss xmm0, dword ptr [esp + 0x1b4]
// 005f439e  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f43a7  f30f108424b8010000   movss xmm0, dword ptr [esp + 0x1b8]
// 005f43b0  f30f11842428030000   movss dword ptr [esp + 0x328], xmm0
// 005f43b9  f30f108424bc010000   movss xmm0, dword ptr [esp + 0x1bc]
// 005f43c2  f30f1184242c030000   movss dword ptr [esp + 0x32c], xmm0
// 005f43cb  8d4c246c             lea ecx, [esp + 0x6c]
// 005f43cf  51                   push ecx
// 005f43d0  8d9424c4030000       lea edx, [esp + 0x3c4]
// 005f43d7  52                   push edx
// 005f43d8  e893322300           call 0x827670
// 005f43dd  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f43e6  f30f118424e0030000   movss dword ptr [esp + 0x3e0], xmm0
// 005f43ef  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f43f8  8d8424e0030000       lea eax, [esp + 0x3e0]
// 005f43ff  50                   push eax
// 005f4400  8d8c2484030000       lea ecx, [esp + 0x384]
// 005f4407  f30f118424e8030000   movss dword ptr [esp + 0x3e8], xmm0
// 005f4410  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f4418  51                   push ecx
// 005f4419  f30f118424f0030000   movss dword ptr [esp + 0x3f0], xmm0
// 005f4422  e849322300           call 0x827670
// 005f4427  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f442d  f30f11842470030000   movss dword ptr [esp + 0x370], xmm0
// 005f4436  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f443c  8d942470030000       lea edx, [esp + 0x370]
// 005f4443  52                   push edx
// 005f4444  8d842450030000       lea eax, [esp + 0x350]
// 005f444b  f30f11842478030000   movss dword ptr [esp + 0x378], xmm0
// 005f4454  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f445a  50                   push eax
// 005f445b  f30f11842480030000   movss dword ptr [esp + 0x380], xmm0
// 005f4464  e807322300           call 0x827670
// 005f4469  83c418               add esp, 0x18
// 005f446c  8d8c2430030000       lea ecx, [esp + 0x330]
// 005f4473  51                   push ecx
// 005f4474  8d8c24b4010000       lea ecx, [esp + 0x1b4]
// 005f447b  e8c0fd0300           call 0x634240
// 005f4480  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f4489  8b94243c030000       mov edx, dword ptr [esp + 0x33c]
// 005f4490  8b842440030000       mov eax, dword ptr [esp + 0x340]
// 005f4497  8b8c2444030000       mov ecx, dword ptr [esp + 0x344]
// 005f449e  f30f1184246c020000   movss dword ptr [esp + 0x26c], xmm0
// 005f44a7  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f44b0  f30f11842470020000   movss dword ptr [esp + 0x270], xmm0
// 005f44b9  f30f10842430030000   movss xmm0, dword ptr [esp + 0x330]
// 005f44c2  f30f11842474020000   movss dword ptr [esp + 0x274], xmm0
// 005f44cb  f30f10842434030000   movss xmm0, dword ptr [esp + 0x334]
// 005f44d4  f30f11842478020000   movss dword ptr [esp + 0x278], xmm0
// 005f44dd  f30f10842420030000   movss xmm0, dword ptr [esp + 0x320]
// 005f44e6  f30f1184247c020000   movss dword ptr [esp + 0x27c], xmm0
// 005f44ef  f30f10842424030000   movss xmm0, dword ptr [esp + 0x324]
// 005f44f8  f30f11842480020000   movss dword ptr [esp + 0x280], xmm0
// 005f4501  f30f10842428030000   movss xmm0, dword ptr [esp + 0x328]
// 005f450a  89942448020000       mov dword ptr [esp + 0x248], edx
// 005f4511  8b942478030000       mov edx, dword ptr [esp + 0x378]
// 005f4518  f30f11842484020000   movss dword ptr [esp + 0x284], xmm0
// 005f4521  f30f1084242c030000   movss xmm0, dword ptr [esp + 0x32c]
// 005f452a  8984244c020000       mov dword ptr [esp + 0x24c], eax
// 005f4531  8b84247c030000       mov eax, dword ptr [esp + 0x37c]
// 005f4538  f30f11842488020000   movss dword ptr [esp + 0x288], xmm0
// 005f4541  f30f108424f0010000   movss xmm0, dword ptr [esp + 0x1f0]
// 005f454a  89942454020000       mov dword ptr [esp + 0x254], edx
// 005f4551  8b9424c0030000       mov edx, dword ptr [esp + 0x3c0]
// 005f4558  89842458020000       mov dword ptr [esp + 0x258], eax
// 005f455f  8b8424c4030000       mov eax, dword ptr [esp + 0x3c4]
// 005f4566  f30f11842410030000   movss dword ptr [esp + 0x310], xmm0
// 005f456f  f30f108424f4010000   movss xmm0, dword ptr [esp + 0x1f4]
// 005f4578  898c2450020000       mov dword ptr [esp + 0x250], ecx
// 005f457f  8b8c2480030000       mov ecx, dword ptr [esp + 0x380]
// 005f4586  89942460020000       mov dword ptr [esp + 0x260], edx
// 005f458d  f30f11842414030000   movss dword ptr [esp + 0x314], xmm0
// 005f4596  f30f108424f8010000   movss xmm0, dword ptr [esp + 0x1f8]
// 005f459f  8d54246c             lea edx, [esp + 0x6c]
// 005f45a3  89842464020000       mov dword ptr [esp + 0x264], eax
// 005f45aa  898c245c020000       mov dword ptr [esp + 0x25c], ecx
// 005f45b1  8b8c24c8030000       mov ecx, dword ptr [esp + 0x3c8]
// 005f45b8  52                   push edx
// 005f45b9  8d842470030000       lea eax, [esp + 0x370]
// 005f45c0  f30f1184241c030000   movss dword ptr [esp + 0x31c], xmm0
// 005f45c9  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005f45d2  50                   push eax
// 005f45d3  898c2470020000       mov dword ptr [esp + 0x270], ecx
// 005f45da  f30f11842424030000   movss dword ptr [esp + 0x324], xmm0
// 005f45e3  e888302300           call 0x827670
// 005f45e8  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f45f1  f30f11842498030000   movss dword ptr [esp + 0x398], xmm0
// 005f45fa  f30f10842400010000   movss xmm0, dword ptr [esp + 0x100]
// 005f4603  8d8c2498030000       lea ecx, [esp + 0x398]
// 005f460a  51                   push ecx
// 005f460b  8d942460030000       lea edx, [esp + 0x360]
// 005f4612  f30f118424a0030000   movss dword ptr [esp + 0x3a0], xmm0
// 005f461b  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f4623  52                   push edx
// 005f4624  f30f118424a8030000   movss dword ptr [esp + 0x3a8], xmm0
// 005f462d  e83e302300           call 0x827670
// 005f4632  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005f4638  f30f11842400040000   movss dword ptr [esp + 0x400], xmm0
// 005f4641  f30f10442468         movss xmm0, dword ptr [esp + 0x68]
// 005f4647  8d842400040000       lea eax, [esp + 0x400]
// 005f464e  50                   push eax
// 005f464f  8d8c245c030000       lea ecx, [esp + 0x35c]
// 005f4656  f30f11842408040000   movss dword ptr [esp + 0x408], xmm0
// 005f465f  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f4665  51                   push ecx
// 005f4666  f30f11842410040000   movss dword ptr [esp + 0x410], xmm0
// 005f466f  e8fc2f2300           call 0x827670
// 005f4674  83c418               add esp, 0x18
// 005f4677  8d9424d0010000       lea edx, [esp + 0x1d0]
// 005f467e  52                   push edx
// 005f467f  8d8c24f4010000       lea ecx, [esp + 0x1f4]
// 005f4686  e8b5fb0300           call 0x634240
// 005f468b  f30f10842454010000   movss xmm0, dword ptr [esp + 0x154]
// 005f4694  8b842448030000       mov eax, dword ptr [esp + 0x348]
// 005f469b  8b8c244c030000       mov ecx, dword ptr [esp + 0x34c]
// 005f46a2  8b942450030000       mov edx, dword ptr [esp + 0x350]
// 005f46a9  f30f118424b4020000   movss dword ptr [esp + 0x2b4], xmm0
// 005f46b2  f30f10842458010000   movss xmm0, dword ptr [esp + 0x158]
// 005f46bb  f30f118424b8020000   movss dword ptr [esp + 0x2b8], xmm0
// 005f46c4  f30f108424d0010000   movss xmm0, dword ptr [esp + 0x1d0]
// 005f46cd  f30f118424bc020000   movss dword ptr [esp + 0x2bc], xmm0
// 005f46d6  f30f108424d4010000   movss xmm0, dword ptr [esp + 0x1d4]
// 005f46df  f30f118424c0020000   movss dword ptr [esp + 0x2c0], xmm0
// 005f46e8  f30f10842410030000   movss xmm0, dword ptr [esp + 0x310]
// 005f46f1  f30f118424c4020000   movss dword ptr [esp + 0x2c4], xmm0
// 005f46fa  f30f10842414030000   movss xmm0, dword ptr [esp + 0x314]
// 005f4703  f30f118424c8020000   movss dword ptr [esp + 0x2c8], xmm0
// 005f470c  f30f10842418030000   movss xmm0, dword ptr [esp + 0x318]
// 005f4715  89842490020000       mov dword ptr [esp + 0x290], eax
// 005f471c  8b842454030000       mov eax, dword ptr [esp + 0x354]
// 005f4723  f30f118424cc020000   movss dword ptr [esp + 0x2cc], xmm0
// 005f472c  f30f1084241c030000   movss xmm0, dword ptr [esp + 0x31c]
// 005f4735  898c2494020000       mov dword ptr [esp + 0x294], ecx
// 005f473c  8b8c2458030000       mov ecx, dword ptr [esp + 0x358]
// 005f4743  f30f118424d0020000   movss dword ptr [esp + 0x2d0], xmm0
// 005f474c  f30f1084247c010000   movss xmm0, dword ptr [esp + 0x17c]
// 005f4755  8984249c020000       mov dword ptr [esp + 0x29c], eax
// 005f475c  8b84246c030000       mov eax, dword ptr [esp + 0x36c]
// 005f4763  898c24a0020000       mov dword ptr [esp + 0x2a0], ecx
// 005f476a  8b8c2470030000       mov ecx, dword ptr [esp + 0x370]
// 005f4771  f30f118424e8020000   movss dword ptr [esp + 0x2e8], xmm0
// 005f477a  f30f10842480010000   movss xmm0, dword ptr [esp + 0x180]
// 005f4783  89942498020000       mov dword ptr [esp + 0x298], edx
// 005f478a  8b94245c030000       mov edx, dword ptr [esp + 0x35c]
// 005f4791  898424a8020000       mov dword ptr [esp + 0x2a8], eax
// 005f4798  f30f118424ec020000   movss dword ptr [esp + 0x2ec], xmm0
// 005f47a1  f30f10842484010000   movss xmm0, dword ptr [esp + 0x184]
// 005f47aa  8d44246c             lea eax, [esp + 0x6c]
// 005f47ae  898c24ac020000       mov dword ptr [esp + 0x2ac], ecx
// 005f47b5  899424a4020000       mov dword ptr [esp + 0x2a4], edx
// 005f47bc  8b942474030000       mov edx, dword ptr [esp + 0x374]
// 005f47c3  50                   push eax
// 005f47c4  8d8c24e8030000       lea ecx, [esp + 0x3e8]
// 005f47cb  f30f118424f4020000   movss dword ptr [esp + 0x2f4], xmm0
// 005f47d4  f30f1084248c010000   movss xmm0, dword ptr [esp + 0x18c]
// 005f47dd  51                   push ecx
// 005f47de  899424b8020000       mov dword ptr [esp + 0x2b8], edx
// 005f47e5  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005f47ee  e87d2e2300           call 0x827670
// 005f47f3  f30f10842404010000   movss xmm0, dword ptr [esp + 0x104]
// 005f47fc  f30f1184248c030000   movss dword ptr [esp + 0x38c], xmm0
// 005f4805  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f480e  f30f11842490030000   movss dword ptr [esp + 0x390], xmm0
// 005f4817  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f481f  8d94248c030000       lea edx, [esp + 0x38c]
// 005f4826  f30f11842494030000   movss dword ptr [esp + 0x394], xmm0
// 005f482f  52                   push edx
// 005f4830  8d8424d8030000       lea eax, [esp + 0x3d8]
// 005f4837  50                   push eax
// 005f4838  e8332e2300           call 0x827670
// 005f483d  f30f1044245c         movss xmm0, dword ptr [esp + 0x5c]
// 005f4843  f30f118424ac030000   movss dword ptr [esp + 0x3ac], xmm0
// 005f484c  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005f4852  8d8c24ac030000       lea ecx, [esp + 0x3ac]
// 005f4859  51                   push ecx
// 005f485a  8d9424c8030000       lea edx, [esp + 0x3c8]
// 005f4861  f30f118424b4030000   movss dword ptr [esp + 0x3b4], xmm0
// 005f486a  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f4870  52                   push edx
// 005f4871  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005f487a  e8f12d2300           call 0x827670
// 005f487f  83c418               add esp, 0x18
// 005f4882  8d8424c0010000       lea eax, [esp + 0x1c0]
// 005f4889  50                   push eax
// 005f488a  8d8c2480010000       lea ecx, [esp + 0x180]
// 005f4891  e8aaf90300           call 0x634240
// 005f4896  f30f10842464010000   movss xmm0, dword ptr [esp + 0x164]
// 005f489f  8b8c24b4030000       mov ecx, dword ptr [esp + 0x3b4]
// 005f48a6  8b9424b8030000       mov edx, dword ptr [esp + 0x3b8]
// 005f48ad  8b8424bc030000       mov eax, dword ptr [esp + 0x3bc]
// 005f48b4  f30f11842424020000   movss dword ptr [esp + 0x224], xmm0
// 005f48bd  f30f10842468010000   movss xmm0, dword ptr [esp + 0x168]
// 005f48c6  f30f11842428020000   movss dword ptr [esp + 0x228], xmm0
// 005f48cf  f30f108424c0010000   movss xmm0, dword ptr [esp + 0x1c0]
// 005f48d8  f30f1184242c020000   movss dword ptr [esp + 0x22c], xmm0
// 005f48e1  f30f108424c4010000   movss xmm0, dword ptr [esp + 0x1c4]
// 005f48ea  f30f11842430020000   movss dword ptr [esp + 0x230], xmm0
// 005f48f3  f30f108424e8020000   movss xmm0, dword ptr [esp + 0x2e8]
// 005f48fc  f30f11842434020000   movss dword ptr [esp + 0x234], xmm0
// 005f4905  f30f108424ec020000   movss xmm0, dword ptr [esp + 0x2ec]
// 005f490e  f30f11842438020000   movss dword ptr [esp + 0x238], xmm0
// 005f4917  f30f108424f0020000   movss xmm0, dword ptr [esp + 0x2f0]
// 005f4920  898c2400020000       mov dword ptr [esp + 0x200], ecx
// 005f4927  8b8c24cc030000       mov ecx, dword ptr [esp + 0x3cc]
// 005f492e  f30f1184243c020000   movss dword ptr [esp + 0x23c], xmm0
// 005f4937  f30f108424f4020000   movss xmm0, dword ptr [esp + 0x2f4]
// 005f4940  89942404020000       mov dword ptr [esp + 0x204], edx
// 005f4947  8b9424d0030000       mov edx, dword ptr [esp + 0x3d0]
// 005f494e  f30f11842440020000   movss dword ptr [esp + 0x240], xmm0
// 005f4957  f30f10442428         movss xmm0, dword ptr [esp + 0x28]
// 005f495d  898c240c020000       mov dword ptr [esp + 0x20c], ecx
// 005f4964  8b8c24e4030000       mov ecx, dword ptr [esp + 0x3e4]
// 005f496b  89942410020000       mov dword ptr [esp + 0x210], edx
// 005f4972  8b9424e8030000       mov edx, dword ptr [esp + 0x3e8]
// 005f4979  f30f118424f8020000   movss dword ptr [esp + 0x2f8], xmm0
// 005f4982  f30f1044242c         movss xmm0, dword ptr [esp + 0x2c]
// 005f4988  89842408020000       mov dword ptr [esp + 0x208], eax
// 005f498f  8b8424d4030000       mov eax, dword ptr [esp + 0x3d4]
// 005f4996  898c2418020000       mov dword ptr [esp + 0x218], ecx
// 005f499d  f30f118424fc020000   movss dword ptr [esp + 0x2fc], xmm0
// 005f49a6  f30f10442430         movss xmm0, dword ptr [esp + 0x30]
// 005f49ac  8d4c246c             lea ecx, [esp + 0x6c]
// 005f49b0  8994241c020000       mov dword ptr [esp + 0x21c], edx
// 005f49b7  89842414020000       mov dword ptr [esp + 0x214], eax
// 005f49be  8b8424ec030000       mov eax, dword ptr [esp + 0x3ec]
// 005f49c5  51                   push ecx
// 005f49c6  8d942410010000       lea edx, [esp + 0x110]
// 005f49cd  f30f11842404030000   movss dword ptr [esp + 0x304], xmm0
// 005f49d6  f30f10442438         movss xmm0, dword ptr [esp + 0x38]
// 005f49dc  52                   push edx
// 005f49dd  89842428020000       mov dword ptr [esp + 0x228], eax
// 005f49e4  f30f1184240c030000   movss dword ptr [esp + 0x30c], xmm0
// 005f49ed  e87e2c2300           call 0x827670
// 005f49f2  f30f108424fc000000   movss xmm0, dword ptr [esp + 0xfc]
// 005f49fb  f30f11842404040000   movss dword ptr [esp + 0x404], xmm0
// 005f4a04  f30f10842408010000   movss xmm0, dword ptr [esp + 0x108]
// 005f4a0d  8d842404040000       lea eax, [esp + 0x404]
// 005f4a14  50                   push eax
// 005f4a15  8d8c2438010000       lea ecx, [esp + 0x138]
// 005f4a1c  f30f1184240c040000   movss dword ptr [esp + 0x40c], xmm0
// 005f4a25  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 005f4a2d  51                   push ecx
// 005f4a2e  f30f11842414040000   movss dword ptr [esp + 0x414], xmm0
// 005f4a37  e8342c2300           call 0x827670
// 005f4a3c  f30f10442464         movss xmm0, dword ptr [esp + 0x64]
// 005f4a42  f30f118424b8030000   movss dword ptr [esp + 0x3b8], xmm0
// 005f4a4b  f30f10442460         movss xmm0, dword ptr [esp + 0x60]
// 005f4a51  f30f118424bc030000   movss dword ptr [esp + 0x3bc], xmm0
// 005f4a5a  f30f10442434         movss xmm0, dword ptr [esp + 0x34]
// 005f4a60  8d9424b8030000       lea edx, [esp + 0x3b8]
// 005f4a67  52                   push edx
// 005f4a68  8d842430010000       lea eax, [esp + 0x130]
// 005f4a6f  50                   push eax
// 005f4a70  f30f118424c8030000   movss dword ptr [esp + 0x3c8], xmm0
// 005f4a79  e8f22b2300           call 0x827670
// 005f4a7e  83c418               add esp, 0x18
// 005f4a81  8d8c24e0010000       lea ecx, [esp + 0x1e0]
// 005f4a88  51                   push ecx
// 005f4a89  8d4c242c             lea ecx, [esp + 0x2c]
// 005f4a8d  e8aef70300           call 0x634240
// 005f4a92  f30f10842470010000   movss xmm0, dword ptr [esp + 0x170]
// 005f4a9b  8b94241c010000       mov edx, dword ptr [esp + 0x11c]
// 005f4aa2  8b842420010000       mov eax, dword ptr [esp + 0x120]
// 005f4aa9  8b8c2424010000       mov ecx, dword ptr [esp + 0x124]
// 005f4ab0  f30f1184249c000000   movss dword ptr [esp + 0x9c], xmm0
// 005f4ab9  f30f10842474010000   movss xmm0, dword ptr [esp + 0x174]
// 005f4ac2  f30f118424a0000000   movss dword ptr [esp + 0xa0], xmm0
// 005f4acb  f30f108424e0010000   movss xmm0, dword ptr [esp + 0x1e0]
// 005f4ad4  f30f118424a4000000   movss dword ptr [esp + 0xa4], xmm0
// 005f4add  f30f108424e4010000   movss xmm0, dword ptr [esp + 0x1e4]
// 005f4ae6  89542478             mov dword ptr [esp + 0x78], edx
// 005f4aea  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 005f4af1  8944247c             mov dword ptr [esp + 0x7c], eax
// 005f4af5  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 005f4afc  f30f118424a8000000   movss dword ptr [esp + 0xa8], xmm0
// 005f4b05  f30f108424f8020000   movss xmm0, dword ptr [esp + 0x2f8]
// 005f4b0e  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005f4b15  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 005f4b1c  89942484000000       mov dword ptr [esp + 0x84], edx
// 005f4b23  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 005f4b2a  89842488000000       mov dword ptr [esp + 0x88], eax
// 005f4b31  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 005f4b38  f30f118424ac000000   movss dword ptr [esp + 0xac], xmm0
// 005f4b41  f30f108424fc020000   movss xmm0, dword ptr [esp + 0x2fc]
// 005f4b4a  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 005f4b51  8b8c2414010000       mov ecx, dword ptr [esp + 0x114]
// 005f4b58  89942490000000       mov dword ptr [esp + 0x90], edx
// 005f4b5f  8b17                 mov edx, dword ptr [edi]
// 005f4b61  8b5210               mov edx, dword ptr [edx + 0x10]
// 005f4b64  f30f118424b0000000   movss dword ptr [esp + 0xb0], xmm0
// 005f4b6d  f30f10842400030000   movss xmm0, dword ptr [esp + 0x300]
// 005f4b76  89842494000000       mov dword ptr [esp + 0x94], eax
// 005f4b7d  8d842448020000       lea eax, [esp + 0x248]
// 005f4b84  898c2498000000       mov dword ptr [esp + 0x98], ecx
// 005f4b8b  f30f118424b4000000   movss dword ptr [esp + 0xb4], xmm0
// 005f4b94  f30f10842404030000   movss xmm0, dword ptr [esp + 0x304]
// 005f4b9d  50                   push eax
// 005f4b9e  8bcf                 mov ecx, edi
// 005f4ba0  f30f118424bc000000   movss dword ptr [esp + 0xbc], xmm0
// 005f4ba9  ffd2                 call edx
// 005f4bab  898424e4000000       mov dword ptr [esp + 0xe4], eax
// 005f4bb2  8b07                 mov eax, dword ptr [edi]
// 005f4bb4  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f4bb7  8d8c2490020000       lea ecx, [esp + 0x290]
// 005f4bbe  51                   push ecx
// 005f4bbf  8bcf                 mov ecx, edi
// 005f4bc1  ffd2                 call edx
// 005f4bc3  8984243c010000       mov dword ptr [esp + 0x13c], eax
// 005f4bca  8b07                 mov eax, dword ptr [edi]
// 005f4bcc  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f4bcf  8d8c2400020000       lea ecx, [esp + 0x200]
// 005f4bd6  51                   push ecx
// 005f4bd7  8bcf                 mov ecx, edi
// 005f4bd9  ffd2                 call edx
// 005f4bdb  8984245c010000       mov dword ptr [esp + 0x15c], eax
// 005f4be2  8b07                 mov eax, dword ptr [edi]
// 005f4be4  8b5010               mov edx, dword ptr [eax + 0x10]
// 005f4be7  8d4c2478             lea ecx, [esp + 0x78]
// 005f4beb  51                   push ecx
// 005f4bec  8bcf                 mov ecx, edi
// 005f4bee  ffd2                 call edx
// 005f4bf0  89842460010000       mov dword ptr [esp + 0x160], eax
// 005f4bf7  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005f4bfe  40                   inc eax
// 005f4bff  898424e8000000       mov dword ptr [esp + 0xe8], eax
// 005f4c06  3bc3                 cmp eax, ebx
// 005f4c08  8d84246c010000       lea eax, [esp + 0x16c]
// 005f4c0f  7c07                 jl 0x5f4c18
// 005f4c11  8d8424e8000000       lea eax, [esp + 0xe8]
// 005f4c18  8b18                 mov ebx, dword ptr [eax]
// 005f4c1a  8b842478010000       mov eax, dword ptr [esp + 0x178]
// 005f4c21  8bc8                 mov ecx, eax
// 005f4c23  40                   inc eax
// 005f4c24  899c246c010000       mov dword ptr [esp + 0x16c], ebx
// 005f4c2b  85c9                 test ecx, ecx
// 005f4c2d  0f85f9000000         jne 0x5f4d2c
// 005f4c33  8b9424e4000000       mov edx, dword ptr [esp + 0xe4]
// 005f4c3a  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005f4c3d  f30f10842448020000   movss xmm0, dword ptr [esp + 0x248]
// 005f4c46  8911                 mov dword ptr [ecx], edx
// 005f4c48  f30f1106             movss dword ptr [esi], xmm0
// 005f4c4c  f30f1084244c020000   movss xmm0, dword ptr [esp + 0x24c]
// 005f4c55  f30f114604           movss dword ptr [esi + 4], xmm0
// 005f4c5a  f30f10842450020000   movss xmm0, dword ptr [esp + 0x250]
// 005f4c63  f30f114608           movss dword ptr [esi + 8], xmm0
// 005f4c68  f30f10842454020000   movss xmm0, dword ptr [esp + 0x254]
// 005f4c71  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 005f4c76  f30f10842458020000   movss xmm0, dword ptr [esp + 0x258]
// 005f4c7f  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 005f4c84  f30f1084245c020000   movss xmm0, dword ptr [esp + 0x25c]
// 005f4c8d  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 005f4c92  f30f10842460020000   movss xmm0, dword ptr [esp + 0x260]
// 005f4c9b  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 005f4ca0  f30f10842464020000   movss xmm0, dword ptr [esp + 0x264]
// 005f4ca9  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 005f4cae  f30f10842468020000   movss xmm0, dword ptr [esp + 0x268]
// 005f4cb7  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 005f4cbc  f30f1084246c020000   movss xmm0, dword ptr [esp + 0x26c]
// 005f4cc5  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 005f4cca  f30f10842470020000   movss xmm0, dword ptr [esp + 0x270]
// 005f4cd3  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 005f4cd8  f30f10842474020000   movss xmm0, dword ptr [esp + 0x274]
// 005f4ce1  f30f11462c           movss dword ptr [esi + 0x2c], xmm0
// 005f4ce6  f30f10842478020000   movss xmm0, dword ptr [esp + 0x278]
// 005f4cef  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 005f4cf4  f30f1084247c020000   movss xmm0, dword ptr [esp + 0x27c]
// 005f4cfd  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 005f4d02  f30f10842480020000   movss xmm0, dword ptr [esp + 0x280]
// 005f4d0b  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 005f4d10  f30f10842484020000   movss xmm0, dword ptr [esp + 0x284]
// 005f4d19  f30f11463c           movss dword ptr [esi + 0x3c], xmm0
// 005f4d1e  f30f10842488020000   movss xmm0, dword ptr [esp + 0x288]
// 005f4d27  f30f114640           movss dword ptr [esi + 0x40], xmm0
// 005f4d2c  8bd3                 mov edx, ebx
// 005f4d2e  0faf54243c           imul edx, dword ptr [esp + 0x3c]
// 005f4d33  8d0c9501000000       lea ecx, [edx*4 + 1]
// 005f4d3a  8bd0                 mov edx, eax
// 005f4d3c  40                   inc eax
// 005f4d3d  3bd1                 cmp edx, ecx
// 005f4d3f  0f8501010000         jne 0x5f4e46
// 005f4d45  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005f4d4c  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005f4d4f  f30f10842490020000   movss xmm0, dword ptr [esp + 0x290]
// 005f4d58  894a04               mov dword ptr [edx + 4], ecx
// 005f4d5b  f30f114644           movss dword ptr [esi + 0x44], xmm0
// 005f4d60  f30f10842494020000   movss xmm0, dword ptr [esp + 0x294]
// 005f4d69  f30f114648           movss dword ptr [esi + 0x48], xmm0
// 005f4d6e  f30f10842498020000   movss xmm0, dword ptr [esp + 0x298]
// 005f4d77  f30f11464c           movss dword ptr [esi + 0x4c], xmm0
// 005f4d7c  f30f1084249c020000   movss xmm0, dword ptr [esp + 0x29c]
// 005f4d85  f30f114650           movss dword ptr [esi + 0x50], xmm0
// 005f4d8a  f30f108424a0020000   movss xmm0, dword ptr [esp + 0x2a0]
// 005f4d93  f30f114654           movss dword ptr [esi + 0x54], xmm0
// 005f4d98  f30f108424a4020000   movss xmm0, dword ptr [esp + 0x2a4]
// 005f4da1  f30f114658           movss dword ptr [esi + 0x58], xmm0
// 005f4da6  f30f108424a8020000   movss xmm0, dword ptr [esp + 0x2a8]
// 005f4daf  f30f11465c           movss dword ptr [esi + 0x5c], xmm0
// 005f4db4  f30f108424ac020000   movss xmm0, dword ptr [esp + 0x2ac]
// 005f4dbd  f30f114660           movss dword ptr [esi + 0x60], xmm0
// 005f4dc2  f30f108424b0020000   movss xmm0, dword ptr [esp + 0x2b0]
// 005f4dcb  f30f114664           movss dword ptr [esi + 0x64], xmm0
// 005f4dd0  f30f108424b4020000   movss xmm0, dword ptr [esp + 0x2b4]
// 005f4dd9  f30f114668           movss dword ptr [esi + 0x68], xmm0
// 005f4dde  f30f108424b8020000   movss xmm0, dword ptr [esp + 0x2b8]
// 005f4de7  f30f11466c           movss dword ptr [esi + 0x6c], xmm0
// 005f4dec  f30f108424bc020000   movss xmm0, dword ptr [esp + 0x2bc]
// 005f4df5  f30f114670           movss dword ptr [esi + 0x70], xmm0
// 005f4dfa  f30f108424c0020000   movss xmm0, dword ptr [esp + 0x2c0]
// 005f4e03  f30f114674           movss dword ptr [esi + 0x74], xmm0
// 005f4e08  f30f108424c4020000   movss xmm0, dword ptr [esp + 0x2c4]
// 005f4e11  f30f114678           movss dword ptr [esi + 0x78], xmm0
// 005f4e16  f30f108424c8020000   movss xmm0, dword ptr [esp + 0x2c8]
// 005f4e1f  f30f11467c           movss dword ptr [esi + 0x7c], xmm0
// 005f4e24  f30f108424cc020000   movss xmm0, dword ptr [esp + 0x2cc]
// 005f4e2d  f30f118680000000     movss dword ptr [esi + 0x80], xmm0
// 005f4e35  f30f108424d0020000   movss xmm0, dword ptr [esp + 0x2d0]
// 005f4e3e  f30f118684000000     movss dword ptr [esi + 0x84], xmm0
// 005f4e46  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005f4e4a  41                   inc ecx
// 005f4e4b  0fafcb               imul ecx, ebx
// 005f4e4e  8d148dfeffffff       lea edx, [ecx*4 - 2]
// 005f4e55  8bc8                 mov ecx, eax
// 005f4e57  40                   inc eax
// 005f4e58  3bca                 cmp ecx, edx
// 005f4e5a  0f852e010000         jne 0x5f4f8e
// 005f4e60  8b94245c010000       mov edx, dword ptr [esp + 0x15c]
// 005f4e67  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 005f4e6a  f30f10842400020000   movss xmm0, dword ptr [esp + 0x200]
// 005f4e73  895108               mov dword ptr [ecx + 8], edx
// 005f4e76  f30f118688000000     movss dword ptr [esi + 0x88], xmm0
// 005f4e7e  f30f10842404020000   movss xmm0, dword ptr [esp + 0x204]
// 005f4e87  f30f11868c000000     movss dword ptr [esi + 0x8c], xmm0
// 005f4e8f  f30f10842408020000   movss xmm0, dword ptr [esp + 0x208]
// 005f4e98  f30f118690000000     movss dword ptr [esi + 0x90], xmm0
// 005f4ea0  f30f1084240c020000   movss xmm0, dword ptr [esp + 0x20c]
// 005f4ea9  f30f118694000000     movss dword ptr [esi + 0x94], xmm0
// 005f4eb1  f30f10842410020000   movss xmm0, dword ptr [esp + 0x210]
// 005f4eba  f30f118698000000     movss dword ptr [esi + 0x98], xmm0
// 005f4ec2  f30f10842414020000   movss xmm0, dword ptr [esp + 0x214]
// 005f4ecb  f30f11869c000000     movss dword ptr [esi + 0x9c], xmm0
// 005f4ed3  f30f10842418020000   movss xmm0, dword ptr [esp + 0x218]
// 005f4edc  f30f1186a0000000     movss dword ptr [esi + 0xa0], xmm0
// 005f4ee4  f30f1084241c020000   movss xmm0, dword ptr [esp + 0x21c]
// 005f4eed  f30f1186a4000000     movss dword ptr [esi + 0xa4], xmm0
// 005f4ef5  f30f10842420020000   movss xmm0, dword ptr [esp + 0x220]
// 005f4efe  f30f1186a8000000     movss dword ptr [esi + 0xa8], xmm0
// 005f4f06  f30f10842424020000   movss xmm0, dword ptr [esp + 0x224]
// 005f4f0f  f30f1186ac000000     movss dword ptr [esi + 0xac], xmm0
// 005f4f17  f30f10842428020000   movss xmm0, dword ptr [esp + 0x228]
// 005f4f20  f30f1186b0000000     movss dword ptr [esi + 0xb0], xmm0
// 005f4f28  f30f1084242c020000   movss xmm0, dword ptr [esp + 0x22c]
// 005f4f31  f30f1186b4000000     movss dword ptr [esi + 0xb4], xmm0
// 005f4f39  f30f10842430020000   movss xmm0, dword ptr [esp + 0x230]
// 005f4f42  f30f1186b8000000     movss dword ptr [esi + 0xb8], xmm0
// 005f4f4a  f30f10842434020000   movss xmm0, dword ptr [esp + 0x234]
// 005f4f53  f30f1186bc000000     movss dword ptr [esi + 0xbc], xmm0
// 005f4f5b  f30f10842438020000   movss xmm0, dword ptr [esp + 0x238]
// 005f4f64  f30f1186c0000000     movss dword ptr [esi + 0xc0], xmm0
// 005f4f6c  f30f1084243c020000   movss xmm0, dword ptr [esp + 0x23c]
// 005f4f75  f30f1186c4000000     movss dword ptr [esi + 0xc4], xmm0
// 005f4f7d  f30f10842440020000   movss xmm0, dword ptr [esp + 0x240]
// 005f4f86  f30f1186c8000000     movss dword ptr [esi + 0xc8], xmm0
// 005f4f8e  8bc8                 mov ecx, eax
// 005f4f90  8d149dffffffff       lea edx, [ebx*4 - 1]
// 005f4f97  40                   inc eax
// 005f4f98  89842478010000       mov dword ptr [esp + 0x178], eax
// 005f4f9f  3bca                 cmp ecx, edx
// 005f4fa1  0f8528010000         jne 0x5f50cf
// 005f4fa7  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 005f4faa  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005f4fb1  f30f10442478         movss xmm0, dword ptr [esp + 0x78]
// 005f4fb7  89420c               mov dword ptr [edx + 0xc], eax
// 005f4fba  f30f1186cc000000     movss dword ptr [esi + 0xcc], xmm0
// 005f4fc2  f30f1044247c         movss xmm0, dword ptr [esp + 0x7c]
// 005f4fc8  f30f1186d0000000     movss dword ptr [esi + 0xd0], xmm0
// 005f4fd0  f30f10842480000000   movss xmm0, dword ptr [esp + 0x80]
// 005f4fd9  f30f1186d4000000     movss dword ptr [esi + 0xd4], xmm0
// 005f4fe1  f30f10842484000000   movss xmm0, dword ptr [esp + 0x84]
// 005f4fea  f30f1186d8000000     movss dword ptr [esi + 0xd8], xmm0
// 005f4ff2  f30f10842488000000   movss xmm0, dword ptr [esp + 0x88]
// 005f4ffb  f30f1186dc000000     movss dword ptr [esi + 0xdc], xmm0
// 005f5003  f30f1084248c000000   movss xmm0, dword ptr [esp + 0x8c]
// 005f500c  f30f1186e0000000     movss dword ptr [esi + 0xe0], xmm0
// 005f5014  f30f10842490000000   movss xmm0, dword ptr [esp + 0x90]
// 005f501d  f30f1186e4000000     movss dword ptr [esi + 0xe4], xmm0
// 005f5025  f30f10842494000000   movss xmm0, dword ptr [esp + 0x94]
// 005f502e  f30f1186e8000000     movss dword ptr [esi + 0xe8], xmm0
// 005f5036  f30f10842498000000   movss xmm0, dword ptr [esp + 0x98]
// 005f503f  f30f1186ec000000     movss dword ptr [esi + 0xec], xmm0
// 005f5047  f30f1084249c000000   movss xmm0, dword ptr [esp + 0x9c]
// 005f5050  f30f1186f0000000     movss dword ptr [esi + 0xf0], xmm0
// 005f5058  f30f108424a0000000   movss xmm0, dword ptr [esp + 0xa0]
// 005f5061  f30f1186f4000000     movss dword ptr [esi + 0xf4], xmm0
// 005f5069  f30f108424a4000000   movss xmm0, dword ptr [esp + 0xa4]
// 005f5072  f30f1186f8000000     movss dword ptr [esi + 0xf8], xmm0
// 005f507a  f30f108424a8000000   movss xmm0, dword ptr [esp + 0xa8]
// 005f5083  f30f1186fc000000     movss dword ptr [esi + 0xfc], xmm0
// 005f508b  f30f108424ac000000   movss xmm0, dword ptr [esp + 0xac]
// 005f5094  f30f118600010000     movss dword ptr [esi + 0x100], xmm0
// 005f509c  f30f108424b0000000   movss xmm0, dword ptr [esp + 0xb0]
// 005f50a5  f30f118604010000     movss dword ptr [esi + 0x104], xmm0
// 005f50ad  f30f108424b4000000   movss xmm0, dword ptr [esp + 0xb4]
// 005f50b6  f30f118608010000     movss dword ptr [esi + 0x108], xmm0
// 005f50be  f30f108424b8000000   movss xmm0, dword ptr [esp + 0xb8]
// 005f50c7  f30f11860c010000     movss dword ptr [esi + 0x10c], xmm0
// 005f50cf  8b842460010000       mov eax, dword ptr [esp + 0x160]
// 005f50d6  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005f50dd  8b17                 mov edx, dword ptr [edi]
// 005f50df  8b5218               mov edx, dword ptr [edx + 0x18]
// 005f50e2  50                   push eax
// 005f50e3  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 005f50ea  51                   push ecx
// 005f50eb  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 005f50f2  50                   push eax
// 005f50f3  51                   push ecx
// 005f50f4  8bcf                 mov ecx, edi
// 005f50f6  ffd2                 call edx
// 005f50f8  f30f10442450         movss xmm0, dword ptr [esp + 0x50]
// 005f50fe  f30f109c2400010000   movss xmm3, dword ptr [esp + 0x100]
// 005f5107  f30f102d40c4b400     movss xmm5, dword ptr [0xb4c440]
// 005f510f  f30f108c24fc000000   movss xmm1, dword ptr [esp + 0xfc]
// 005f5118  f30f1054244c         movss xmm2, dword ptr [esp + 0x4c]
// 005f511e  f30f107c2454         movss xmm7, dword ptr [esp + 0x54]
// 005f5124  f30f10650c           movss xmm4, dword ptr [ebp + 0xc]
// 005f5129  8b8424e8000000       mov eax, dword ptr [esp + 0xe8]
// 005f5130  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 005f5134  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005f5138  e9b3eeffff           jmp 0x5f3ff0
// 005f513d  0f28fa               movaps xmm7, xmm2
// 005f5140  f30f117c2454         movss dword ptr [esp + 0x54], xmm7
// 005f5146  0f28d9               movaps xmm3, xmm1
// 005f5149  42                   inc edx
// 005f514a  e90feeffff           jmp 0x5f3f5e
// 005f514f  90                   nop 
// 005f5150  c1335f               sal dword ptr [ebx], 0x5f
// 005f5153  002c355f001834       add byte ptr [esi + 0x3418005f], ch
// 005f515a  5f                   pop edi
// 005f515b  00de                 add dh, bl
// 005f515d  345f                 xor al, 0x5f
// 005f515f  005634               add byte ptr [esi + 0x34], dl
// 005f5162  5f                   pop edi

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
