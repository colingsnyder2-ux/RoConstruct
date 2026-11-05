// from server: 100% by auto
// roc 2012-06 0065ca20  unit: seg_00650000  size: 767 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065ca20
//
// 0065ca20  83ec10               sub esp, 0x10
// 0065ca23  56                   push esi
// 0065ca24  8b742418             mov esi, dword ptr [esp + 0x18]
// 0065ca28  8b4668               mov eax, dword ptr [esi + 0x68]
// 0065ca2b  57                   push edi
// 0065ca2c  a801                 test al, 1
// 0065ca2e  7552                 jne 0x65ca82
// 0065ca30  68c8abb800           push 0xb8abc8
// 0065ca35  56                   push esi
// 0065ca36  e87517ffff           call 0x64e1b0
// 0065ca3b  83c408               add esp, 8
// 0065ca3e  33ff                 xor edi, edi
// 0065ca40  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065ca46  53                   push ebx
// 0065ca47  55                   push ebp
// 0065ca48  52                   push edx
// 0065ca49  56                   push esi
// 0065ca4a  e8d11affff           call 0x64e520
// 0065ca4f  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0065ca53  8d4501               lea eax, [ebp + 1]
// 0065ca56  50                   push eax
// 0065ca57  56                   push esi
// 0065ca58  e8f31affff           call 0x64e550
// 0065ca5d  8bd8                 mov ebx, eax
// 0065ca5f  83c410               add esp, 0x10
// 0065ca62  899e88020000         mov dword ptr [esi + 0x288], ebx
// 0065ca68  3bdf                 cmp ebx, edi
// 0065ca6a  756b                 jne 0x65cad7
// 0065ca6c  68acabb800           push 0xb8abac
// 0065ca71  56                   push esi
// 0065ca72  e8e917ffff           call 0x64e260
// 0065ca77  83c408               add esp, 8
// 0065ca7a  5d                   pop ebp
// 0065ca7b  5b                   pop ebx
// 0065ca7c  5f                   pop edi
// 0065ca7d  5e                   pop esi
// 0065ca7e  83c410               add esp, 0x10
// 0065ca81  c3                   ret 
// 0065ca82  a804                 test al, 4
// 0065ca84  741f                 je 0x65caa5
// 0065ca86  6894abb800           push 0xb8ab94
// 0065ca8b  56                   push esi
// 0065ca8c  e8cf17ffff           call 0x64e260
// 0065ca91  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0065ca95  50                   push eax
// 0065ca96  56                   push esi
// 0065ca97  e8b4e4ffff           call 0x65af50
// 0065ca9c  83c410               add esp, 0x10
// 0065ca9f  5f                   pop edi
// 0065caa0  5e                   pop esi
// 0065caa1  83c410               add esp, 0x10
// 0065caa4  c3                   ret 
// 0065caa5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065caa9  33ff                 xor edi, edi
// 0065caab  3bc7                 cmp eax, edi
// 0065caad  7491                 je 0x65ca40
// 0065caaf  f7400800040000       test dword ptr [eax + 8], 0x400
// 0065cab6  7488                 je 0x65ca40
// 0065cab8  687cabb800           push 0xb8ab7c
// 0065cabd  56                   push esi
// 0065cabe  e89d17ffff           call 0x64e260
// 0065cac3  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0065cac7  51                   push ecx
// 0065cac8  56                   push esi
// 0065cac9  e882e4ffff           call 0x65af50
// 0065cace  83c410               add esp, 0x10
// 0065cad1  5f                   pop edi
// 0065cad2  5e                   pop esi
// 0065cad3  83c410               add esp, 0x10
// 0065cad6  c3                   ret 
// 0065cad7  55                   push ebp
// 0065cad8  53                   push ebx
// 0065cad9  56                   push esi
// 0065cada  e81113ffff           call 0x64ddf0
// 0065cadf  55                   push ebp
// 0065cae0  53                   push ebx
// 0065cae1  56                   push esi
// 0065cae2  e8a913feff           call 0x63de90
// 0065cae7  57                   push edi
// 0065cae8  56                   push esi
// 0065cae9  e862e4ffff           call 0x65af50
// 0065caee  83c420               add esp, 0x20
// 0065caf1  85c0                 test eax, eax
// 0065caf3  741e                 je 0x65cb13
// 0065caf5  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0065cafb  51                   push ecx
// 0065cafc  56                   push esi
// 0065cafd  e81e1affff           call 0x64e520
// 0065cb02  83c408               add esp, 8
// 0065cb05  5d                   pop ebp
// 0065cb06  5b                   pop ebx
// 0065cb07  89be88020000         mov dword ptr [esi + 0x288], edi
// 0065cb0d  5f                   pop edi
// 0065cb0e  5e                   pop esi
// 0065cb0f  83c410               add esp, 0x10
// 0065cb12  c3                   ret 
// 0065cb13  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065cb19  c6042a00             mov byte ptr [edx + ebp], 0
// 0065cb1d  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0065cb23  8bc1                 mov eax, ecx
// 0065cb25  803800               cmp byte ptr [eax], 0
// 0065cb28  740c                 je 0x65cb36
// 0065cb2a  8d9b00000000         lea ebx, [ebx]
// 0065cb30  40                   inc eax
// 0065cb31  803800               cmp byte ptr [eax], 0
// 0065cb34  75fa                 jne 0x65cb30
// 0065cb36  03cd                 add ecx, ebp
// 0065cb38  8d500c               lea edx, [eax + 0xc]
// 0065cb3b  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0065cb3f  3bca                 cmp ecx, edx
// 0065cb41  770a                 ja 0x65cb4d
// 0065cb43  6868abb800           push 0xb8ab68
// 0065cb48  e985000000           jmp 0x65cbd2
// 0065cb4d  0fb66801             movzx ebp, byte ptr [eax + 1]
// 0065cb51  0fb64802             movzx ecx, byte ptr [eax + 2]
// 0065cb55  0fb65003             movzx edx, byte ptr [eax + 3]
// 0065cb59  0fb65805             movzx ebx, byte ptr [eax + 5]
// 0065cb5d  c1e508               shl ebp, 8
// 0065cb60  03e9                 add ebp, ecx
// 0065cb62  0fb64804             movzx ecx, byte ptr [eax + 4]
// 0065cb66  c1e508               shl ebp, 8
// 0065cb69  03ea                 add ebp, edx
// 0065cb6b  0fb65006             movzx edx, byte ptr [eax + 6]
// 0065cb6f  c1e308               shl ebx, 8
// 0065cb72  03da                 add ebx, edx
// 0065cb74  0fb65008             movzx edx, byte ptr [eax + 8]
// 0065cb78  c1e508               shl ebp, 8
// 0065cb7b  03e9                 add ebp, ecx
// 0065cb7d  0fb64807             movzx ecx, byte ptr [eax + 7]
// 0065cb81  c1e308               shl ebx, 8
// 0065cb84  03d9                 add ebx, ecx
// 0065cb86  8a4809               mov cl, byte ptr [eax + 9]
// 0065cb89  c1e308               shl ebx, 8
// 0065cb8c  03da                 add ebx, edx
// 0065cb8e  8a500a               mov dl, byte ptr [eax + 0xa]
// 0065cb91  83c00b               add eax, 0xb
// 0065cb94  884c2413             mov byte ptr [esp + 0x13], cl
// 0065cb98  88542424             mov byte ptr [esp + 0x24], dl
// 0065cb9c  89442414             mov dword ptr [esp + 0x14], eax
// 0065cba0  84c9                 test cl, cl
// 0065cba2  7507                 jne 0x65cbab
// 0065cba4  80fa02               cmp dl, 2
// 0065cba7  7524                 jne 0x65cbcd
// 0065cba9  eb66                 jmp 0x65cc11
// 0065cbab  80f901               cmp cl, 1
// 0065cbae  7507                 jne 0x65cbb7
// 0065cbb0  80fa03               cmp dl, 3
// 0065cbb3  7518                 jne 0x65cbcd
// 0065cbb5  eb5a                 jmp 0x65cc11
// 0065cbb7  80f902               cmp cl, 2
// 0065cbba  7507                 jne 0x65cbc3
// 0065cbbc  80fa03               cmp dl, 3
// 0065cbbf  750c                 jne 0x65cbcd
// 0065cbc1  eb4e                 jmp 0x65cc11
// 0065cbc3  80f903               cmp cl, 3
// 0065cbc6  752e                 jne 0x65cbf6
// 0065cbc8  80fa04               cmp dl, 4
// 0065cbcb  7444                 je 0x65cc11
// 0065cbcd  683cabb800           push 0xb8ab3c
// 0065cbd2  56                   push esi
// 0065cbd3  e88816ffff           call 0x64e260
// 0065cbd8  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0065cbde  50                   push eax
// 0065cbdf  56                   push esi
// 0065cbe0  e83b19ffff           call 0x64e520
// 0065cbe5  83c410               add esp, 0x10
// 0065cbe8  5d                   pop ebp
// 0065cbe9  5b                   pop ebx
// 0065cbea  89be88020000         mov dword ptr [esi + 0x288], edi
// 0065cbf0  5f                   pop edi
// 0065cbf1  5e                   pop esi
// 0065cbf2  83c410               add esp, 0x10
// 0065cbf5  c3                   ret 
// 0065cbf6  80f904               cmp cl, 4
// 0065cbf9  7216                 jb 0x65cc11
// 0065cbfb  68f09ab800           push 0xb89af0
// 0065cc00  56                   push esi
// 0065cc01  e85a16ffff           call 0x64e260
// 0065cc06  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065cc0a  8a54242c             mov dl, byte ptr [esp + 0x2c]
// 0065cc0e  83c408               add esp, 8
// 0065cc11  803800               cmp byte ptr [eax], 0
// 0065cc14  8bf8                 mov edi, eax
// 0065cc16  7406                 je 0x65cc1e
// 0065cc18  47                   inc edi
// 0065cc19  803f00               cmp byte ptr [edi], 0
// 0065cc1c  75fa                 jne 0x65cc18
// 0065cc1e  0fb6c2               movzx eax, dl
// 0065cc21  8d0c8500000000       lea ecx, [eax*4]
// 0065cc28  51                   push ecx
// 0065cc29  56                   push esi
// 0065cc2a  8944242c             mov dword ptr [esp + 0x2c], eax
// 0065cc2e  e81d19ffff           call 0x64e550
// 0065cc33  83c408               add esp, 8
// 0065cc36  89442418             mov dword ptr [esp + 0x18], eax
// 0065cc3a  85c0                 test eax, eax
// 0065cc3c  752d                 jne 0x65cc6b
// 0065cc3e  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065cc44  52                   push edx
// 0065cc45  56                   push esi
// 0065cc46  e8d518ffff           call 0x64e520
// 0065cc4b  6820abb800           push 0xb8ab20
// 0065cc50  56                   push esi
// 0065cc51  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0065cc5b  e80016ffff           call 0x64e260
// 0065cc60  83c410               add esp, 0x10
// 0065cc63  5d                   pop ebp
// 0065cc64  5b                   pop ebx
// 0065cc65  5f                   pop edi
// 0065cc66  5e                   pop esi
// 0065cc67  83c410               add esp, 0x10
// 0065cc6a  c3                   ret 
// 0065cc6b  33d2                 xor edx, edx
// 0065cc6d  39542424             cmp dword ptr [esp + 0x24], edx
// 0065cc71  7e5a                 jle 0x65cccd
// 0065cc73  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065cc77  47                   inc edi
// 0065cc78  893c90               mov dword ptr [eax + edx*4], edi
// 0065cc7b  3bf9                 cmp edi, ecx
// 0065cc7d  770b                 ja 0x65cc8a
// 0065cc7f  90                   nop 
// 0065cc80  803f00               cmp byte ptr [edi], 0
// 0065cc83  743d                 je 0x65ccc2
// 0065cc85  47                   inc edi
// 0065cc86  3bf9                 cmp edi, ecx
// 0065cc88  76f6                 jbe 0x65cc80
// 0065cc8a  6868abb800           push 0xb8ab68
// 0065cc8f  56                   push esi
// 0065cc90  e8cb15ffff           call 0x64e260
// 0065cc95  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0065cc9b  50                   push eax
// 0065cc9c  56                   push esi
// 0065cc9d  e87e18ffff           call 0x64e520
// 0065cca2  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0065cca6  51                   push ecx
// 0065cca7  56                   push esi
// 0065cca8  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0065ccb2  e86918ffff           call 0x64e520
// 0065ccb7  83c418               add esp, 0x18
// 0065ccba  5d                   pop ebp
// 0065ccbb  5b                   pop ebx
// 0065ccbc  5f                   pop edi
// 0065ccbd  5e                   pop esi
// 0065ccbe  83c410               add esp, 0x10
// 0065ccc1  c3                   ret 
// 0065ccc2  3bf9                 cmp edi, ecx
// 0065ccc4  77c4                 ja 0x65cc8a
// 0065ccc6  42                   inc edx
// 0065ccc7  3b542424             cmp edx, dword ptr [esp + 0x24]
// 0065cccb  7ca6                 jl 0x65cc73
// 0065cccd  8b542414             mov edx, dword ptr [esp + 0x14]
// 0065ccd1  0fb64c2413           movzx ecx, byte ptr [esp + 0x13]
// 0065ccd6  50                   push eax
// 0065ccd7  8b442428             mov eax, dword ptr [esp + 0x28]
// 0065ccdb  52                   push edx
// 0065ccdc  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 0065cce2  50                   push eax
// 0065cce3  8b442434             mov eax, dword ptr [esp + 0x34]
// 0065cce7  51                   push ecx
// 0065cce8  53                   push ebx
// 0065cce9  55                   push ebp
// 0065ccea  52                   push edx
// 0065cceb  50                   push eax
// 0065ccec  56                   push esi
// 0065cced  e8fe9efeff           call 0x646bf0
// 0065ccf2  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0065ccf8  51                   push ecx
// 0065ccf9  56                   push esi
// 0065ccfa  e82118ffff           call 0x64e520
// 0065ccff  8b542444             mov edx, dword ptr [esp + 0x44]
// 0065cd03  52                   push edx
// 0065cd04  56                   push esi
// 0065cd05  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0065cd0f  e80c18ffff           call 0x64e520
// 0065cd14  83c434               add esp, 0x34
// 0065cd17  5d                   pop ebp
// 0065cd18  5b                   pop ebx
// 0065cd19  5f                   pop edi
// 0065cd1a  5e                   pop esi
// 0065cd1b  83c410               add esp, 0x10
// 0065cd1e  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
