// from server: 100% by auto
// roc 2012-06 00647a90  unit: seg_00640000  size: 1467 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00647a90
//
// 00647a90  81eca0000000         sub esp, 0xa0
// 00647a96  56                   push esi
// 00647a97  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 00647a9e  85f6                 test esi, esi
// 00647aa0  0f849d050000         je 0x648043
// 00647aa6  55                   push ebp
// 00647aa7  8bac24b0000000       mov ebp, dword ptr [esp + 0xb0]
// 00647aae  85ed                 test ebp, ebp
// 00647ab0  0f848c050000         je 0x648042
// 00647ab6  8a862c010000         mov al, byte ptr [esi + 0x12c]
// 00647abc  53                   push ebx
// 00647abd  57                   push edi
// 00647abe  3c08                 cmp al, 8
// 00647ac0  7367                 jae 0x647b29
// 00647ac2  0fb6d8               movzx ebx, al
// 00647ac5  bf08000000           mov edi, 8
// 00647aca  2bfb                 sub edi, ebx
// 00647acc  57                   push edi
// 00647acd  8d442b20             lea eax, [ebx + ebp + 0x20]
// 00647ad1  50                   push eax
// 00647ad2  56                   push esi
// 00647ad3  e818630000           call 0x64ddf0
// 00647ad8  57                   push edi
// 00647ad9  83c520               add ebp, 0x20
// 00647adc  53                   push ebx
// 00647add  55                   push ebp
// 00647ade  c6862c01000008       mov byte ptr [esi + 0x12c], 8
// 00647ae5  e81662ffff           call 0x63dd00
// 00647aea  83c418               add esp, 0x18
// 00647aed  85c0                 test eax, eax
// 00647aef  742c                 je 0x647b1d
// 00647af1  83fb04               cmp ebx, 4
// 00647af4  7319                 jae 0x647b0f
// 00647af6  83c7fc               add edi, -4
// 00647af9  57                   push edi
// 00647afa  53                   push ebx
// 00647afb  55                   push ebp
// 00647afc  e8ff61ffff           call 0x63dd00
// 00647b01  83c40c               add esp, 0xc
// 00647b04  85c0                 test eax, eax
// 00647b06  7407                 je 0x647b0f
// 00647b08  687465b800           push 0xb86574
// 00647b0d  eb05                 jmp 0x647b14
// 00647b0f  684c65b800           push 0xb8654c
// 00647b14  56                   push esi
// 00647b15  e896660000           call 0x64e1b0
// 00647b1a  83c408               add esp, 8
// 00647b1d  83fb03               cmp ebx, 3
// 00647b20  7307                 jae 0x647b29
// 00647b22  814e6800100000       or dword ptr [esi + 0x68], 0x1000
// 00647b29  b373                 mov bl, 0x73
// 00647b2b  eb03                 jmp 0x647b30
// 00647b2d  8d4900               lea ecx, [ecx]
// 00647b30  c68424a000000049     mov byte ptr [esp + 0xa0], 0x49
// 00647b38  c68424a100000048     mov byte ptr [esp + 0xa1], 0x48
// 00647b40  c68424a200000044     mov byte ptr [esp + 0xa2], 0x44
// 00647b48  c68424a300000052     mov byte ptr [esp + 0xa3], 0x52
// 00647b50  c644246049           mov byte ptr [esp + 0x60], 0x49
// 00647b55  c644246144           mov byte ptr [esp + 0x61], 0x44
// 00647b5a  c644246241           mov byte ptr [esp + 0x62], 0x41
// 00647b5f  c644246354           mov byte ptr [esp + 0x63], 0x54
// 00647b64  c644243049           mov byte ptr [esp + 0x30], 0x49
// 00647b69  c644243145           mov byte ptr [esp + 0x31], 0x45
// 00647b6e  c64424324e           mov byte ptr [esp + 0x32], 0x4e
// 00647b73  c644243344           mov byte ptr [esp + 0x33], 0x44
// 00647b78  c644241050           mov byte ptr [esp + 0x10], 0x50
// 00647b7d  c64424114c           mov byte ptr [esp + 0x11], 0x4c
// 00647b82  c644241254           mov byte ptr [esp + 0x12], 0x54
// 00647b87  c644241345           mov byte ptr [esp + 0x13], 0x45
// 00647b8c  c644247062           mov byte ptr [esp + 0x70], 0x62
// 00647b91  c64424714b           mov byte ptr [esp + 0x71], 0x4b
// 00647b96  c644247247           mov byte ptr [esp + 0x72], 0x47
// 00647b9b  c644247344           mov byte ptr [esp + 0x73], 0x44
// 00647ba0  c644244063           mov byte ptr [esp + 0x40], 0x63
// 00647ba5  c644244148           mov byte ptr [esp + 0x41], 0x48
// 00647baa  c644244252           mov byte ptr [esp + 0x42], 0x52
// 00647baf  c64424434d           mov byte ptr [esp + 0x43], 0x4d
// 00647bb4  c684249000000067     mov byte ptr [esp + 0x90], 0x67
// 00647bbc  c684249100000041     mov byte ptr [esp + 0x91], 0x41
// 00647bc4  c68424920000004d     mov byte ptr [esp + 0x92], 0x4d
// 00647bcc  c684249300000041     mov byte ptr [esp + 0x93], 0x41
// 00647bd4  c644245068           mov byte ptr [esp + 0x50], 0x68
// 00647bd9  c644245149           mov byte ptr [esp + 0x51], 0x49
// 00647bde  c644245253           mov byte ptr [esp + 0x52], 0x53
// 00647be3  c644245354           mov byte ptr [esp + 0x53], 0x54
// 00647be8  c644245869           mov byte ptr [esp + 0x58], 0x69
// 00647bed  c644245943           mov byte ptr [esp + 0x59], 0x43
// 00647bf2  c644245a43           mov byte ptr [esp + 0x5a], 0x43
// 00647bf7  c644245b50           mov byte ptr [esp + 0x5b], 0x50
// 00647bfc  c68424800000006f     mov byte ptr [esp + 0x80], 0x6f
// 00647c04  c684248100000046     mov byte ptr [esp + 0x81], 0x46
// 00647c0c  c684248200000046     mov byte ptr [esp + 0x82], 0x46
// 00647c14  889c2483000000       mov byte ptr [esp + 0x83], bl
// 00647c1b  c644241870           mov byte ptr [esp + 0x18], 0x70
// 00647c20  c644241943           mov byte ptr [esp + 0x19], 0x43
// 00647c25  c644241a41           mov byte ptr [esp + 0x1a], 0x41
// 00647c2a  c644241b4c           mov byte ptr [esp + 0x1b], 0x4c
// 00647c2f  c644242870           mov byte ptr [esp + 0x28], 0x70
// 00647c34  c644242948           mov byte ptr [esp + 0x29], 0x48
// 00647c39  c644242a59           mov byte ptr [esp + 0x2a], 0x59
// 00647c3e  885c242b             mov byte ptr [esp + 0x2b], bl
// 00647c42  885c2438             mov byte ptr [esp + 0x38], bl
// 00647c46  c644243942           mov byte ptr [esp + 0x39], 0x42
// 00647c4b  c644243a49           mov byte ptr [esp + 0x3a], 0x49
// 00647c50  c644243b54           mov byte ptr [esp + 0x3b], 0x54
// 00647c55  885c2420             mov byte ptr [esp + 0x20], bl
// 00647c59  c644242143           mov byte ptr [esp + 0x21], 0x43
// 00647c5e  c644242241           mov byte ptr [esp + 0x22], 0x41
// 00647c63  c64424234c           mov byte ptr [esp + 0x23], 0x4c
// 00647c68  885c2468             mov byte ptr [esp + 0x68], bl
// 00647c6c  c644246950           mov byte ptr [esp + 0x69], 0x50
// 00647c71  c644246a4c           mov byte ptr [esp + 0x6a], 0x4c
// 00647c76  c644246b54           mov byte ptr [esp + 0x6b], 0x54
// 00647c7b  885c2448             mov byte ptr [esp + 0x48], bl
// 00647c7f  c644244952           mov byte ptr [esp + 0x49], 0x52
// 00647c84  c644244a47           mov byte ptr [esp + 0x4a], 0x47
// 00647c89  c644244b42           mov byte ptr [esp + 0x4b], 0x42
// 00647c8e  c644247874           mov byte ptr [esp + 0x78], 0x74
// 00647c93  c644247945           mov byte ptr [esp + 0x79], 0x45
// 00647c98  c644247a58           mov byte ptr [esp + 0x7a], 0x58
// 00647c9d  c644247b74           mov byte ptr [esp + 0x7b], 0x74
// 00647ca2  c684248800000074     mov byte ptr [esp + 0x88], 0x74
// 00647caa  c684248900000049     mov byte ptr [esp + 0x89], 0x49
// 00647cb2  c684248a0000004d     mov byte ptr [esp + 0x8a], 0x4d
// 00647cba  c684248b00000045     mov byte ptr [esp + 0x8b], 0x45
// 00647cc2  c684249800000074     mov byte ptr [esp + 0x98], 0x74
// 00647cca  c684249900000052     mov byte ptr [esp + 0x99], 0x52
// 00647cd2  c684249a0000004e     mov byte ptr [esp + 0x9a], 0x4e
// 00647cda  c684249b00000053     mov byte ptr [esp + 0x9b], 0x53
// 00647ce2  c68424a80000007a     mov byte ptr [esp + 0xa8], 0x7a
// 00647cea  c68424a900000054     mov byte ptr [esp + 0xa9], 0x54
// 00647cf2  c68424aa00000058     mov byte ptr [esp + 0xaa], 0x58
// 00647cfa  c68424ab00000074     mov byte ptr [esp + 0xab], 0x74
// 00647d02  56                   push esi
// 00647d03  e8b8310100           call 0x65aec0
// 00647d08  8b6c2464             mov ebp, dword ptr [esp + 0x64]
// 00647d0c  8d8e1c010000         lea ecx, [esi + 0x11c]
// 00647d12  83c404               add esp, 4
// 00647d15  8bf8                 mov edi, eax
// 00647d17  3929                 cmp dword ptr [ecx], ebp
// 00647d19  750f                 jne 0x647d2a
// 00647d1b  8b4668               mov eax, dword ptr [esi + 0x68]
// 00647d1e  a808                 test al, 8
// 00647d20  7408                 je 0x647d2a
// 00647d22  0d00200000           or eax, 0x2000
// 00647d27  894668               mov dword ptr [esi + 0x68], eax
// 00647d2a  8b01                 mov eax, dword ptr [ecx]
// 00647d2c  3b8424a0000000       cmp eax, dword ptr [esp + 0xa0]
// 00647d33  7517                 jne 0x647d4c
// 00647d35  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 00647d3c  57                   push edi
// 00647d3d  51                   push ecx
// 00647d3e  56                   push esi
// 00647d3f  e8dc320100           call 0x65b020
// 00647d44  83c40c               add esp, 0xc
// 00647d47  e9e4fdffff           jmp 0x647b30
// 00647d4c  3b442430             cmp eax, dword ptr [esp + 0x30]
// 00647d50  7517                 jne 0x647d69
// 00647d52  8b9424b8000000       mov edx, dword ptr [esp + 0xb8]
// 00647d59  57                   push edi
// 00647d5a  52                   push edx
// 00647d5b  56                   push esi
// 00647d5c  e81f360100           call 0x65b380
// 00647d61  83c40c               add esp, 0xc
// 00647d64  e9c7fdffff           jmp 0x647b30
// 00647d69  51                   push ecx
// 00647d6a  56                   push esi
// 00647d6b  e89065ffff           call 0x63e300
// 00647d70  83c408               add esp, 8
// 00647d73  85c0                 test eax, eax
// 00647d75  745f                 je 0x647dd6
// 00647d77  39ae1c010000         cmp dword ptr [esi + 0x11c], ebp
// 00647d7d  7504                 jne 0x647d83
// 00647d7f  834e6804             or dword ptr [esi + 0x68], 4
// 00647d83  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 00647d8a  57                   push edi
// 00647d8b  50                   push eax
// 00647d8c  56                   push esi
// 00647d8d  e8de550100           call 0x65d370
// 00647d92  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00647d98  83c40c               add esp, 0xc
// 00647d9b  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00647d9f  7509                 jne 0x647daa
// 00647da1  834e6802             or dword ptr [esi + 0x68], 2
// 00647da5  e986fdffff           jmp 0x647b30
// 00647daa  3bc5                 cmp eax, ebp
// 00647dac  0f857efdffff         jne 0x647b30
// 00647db2  8b4668               mov eax, dword ptr [esi + 0x68]
// 00647db5  a801                 test al, 1
// 00647db7  0f852a020000         jne 0x647fe7
// 00647dbd  683065b800           push 0xb86530
// 00647dc2  56                   push esi
// 00647dc3  e8e8630000           call 0x64e1b0
// 00647dc8  83c408               add esp, 8
// 00647dcb  5f                   pop edi
// 00647dcc  5b                   pop ebx
// 00647dcd  5d                   pop ebp
// 00647dce  5e                   pop esi
// 00647dcf  81c4a0000000         add esp, 0xa0
// 00647dd5  c3                   ret 
// 00647dd6  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00647ddc  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00647de0  7517                 jne 0x647df9
// 00647de2  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 00647de9  57                   push edi
// 00647dea  51                   push ecx
// 00647deb  56                   push esi
// 00647dec  e8ef330100           call 0x65b1e0
// 00647df1  83c40c               add esp, 0xc
// 00647df4  e937fdffff           jmp 0x647b30
// 00647df9  3bc5                 cmp eax, ebp
// 00647dfb  0f840c020000         je 0x64800d
// 00647e01  57                   push edi
// 00647e02  3b442474             cmp eax, dword ptr [esp + 0x74]
// 00647e06  7516                 jne 0x647e1e
// 00647e08  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00647e0f  52                   push edx
// 00647e10  56                   push esi
// 00647e11  e82a460100           call 0x65c440
// 00647e16  83c40c               add esp, 0xc
// 00647e19  e912fdffff           jmp 0x647b30
// 00647e1e  3b442444             cmp eax, dword ptr [esp + 0x44]
// 00647e22  7516                 jne 0x647e3a
// 00647e24  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00647e2b  50                   push eax
// 00647e2c  56                   push esi
// 00647e2d  e8ae380100           call 0x65b6e0
// 00647e32  83c40c               add esp, 0xc
// 00647e35  e9f6fcffff           jmp 0x647b30
// 00647e3a  3b842494000000       cmp eax, dword ptr [esp + 0x94]
// 00647e41  7516                 jne 0x647e59
// 00647e43  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00647e4a  51                   push ecx
// 00647e4b  56                   push esi
// 00647e4c  e87f350100           call 0x65b3d0
// 00647e51  83c40c               add esp, 0xc
// 00647e54  e9d7fcffff           jmp 0x647b30
// 00647e59  3b442454             cmp eax, dword ptr [esp + 0x54]
// 00647e5d  7516                 jne 0x647e75
// 00647e5f  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00647e66  52                   push edx
// 00647e67  56                   push esi
// 00647e68  e8f3470100           call 0x65c660
// 00647e6d  83c40c               add esp, 0xc
// 00647e70  e9bbfcffff           jmp 0x647b30
// 00647e75  3b842484000000       cmp eax, dword ptr [esp + 0x84]
// 00647e7c  7516                 jne 0x647e94
// 00647e7e  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00647e85  50                   push eax
// 00647e86  56                   push esi
// 00647e87  e8744a0100           call 0x65c900
// 00647e8c  83c40c               add esp, 0xc
// 00647e8f  e99cfcffff           jmp 0x647b30
// 00647e94  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 00647e98  7516                 jne 0x647eb0
// 00647e9a  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00647ea1  51                   push ecx
// 00647ea2  56                   push esi
// 00647ea3  e8784b0100           call 0x65ca20
// 00647ea8  83c40c               add esp, 0xc
// 00647eab  e980fcffff           jmp 0x647b30
// 00647eb0  3b442424             cmp eax, dword ptr [esp + 0x24]
// 00647eb4  7516                 jne 0x647ecc
// 00647eb6  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00647ebd  52                   push edx
// 00647ebe  56                   push esi
// 00647ebf  e85c4e0100           call 0x65cd20
// 00647ec4  83c40c               add esp, 0xc
// 00647ec7  e964fcffff           jmp 0x647b30
// 00647ecc  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 00647ed0  7516                 jne 0x647ee8
// 00647ed2  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00647ed9  50                   push eax
// 00647eda  56                   push esi
// 00647edb  e800490100           call 0x65c7e0
// 00647ee0  83c40c               add esp, 0xc
// 00647ee3  e948fcffff           jmp 0x647b30
// 00647ee8  3b44243c             cmp eax, dword ptr [esp + 0x3c]
// 00647eec  7516                 jne 0x647f04
// 00647eee  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00647ef5  51                   push ecx
// 00647ef6  56                   push esi
// 00647ef7  e864360100           call 0x65b560
// 00647efc  83c40c               add esp, 0xc
// 00647eff  e92cfcffff           jmp 0x647b30
// 00647f04  3b44244c             cmp eax, dword ptr [esp + 0x4c]
// 00647f08  7516                 jne 0x647f20
// 00647f0a  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00647f11  52                   push edx
// 00647f12  56                   push esi
// 00647f13  e8083c0100           call 0x65bb20
// 00647f18  83c40c               add esp, 0xc
// 00647f1b  e910fcffff           jmp 0x647b30
// 00647f20  3b44245c             cmp eax, dword ptr [esp + 0x5c]
// 00647f24  7516                 jne 0x647f3c
// 00647f26  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00647f2d  50                   push eax
// 00647f2e  56                   push esi
// 00647f2f  e8fc3d0100           call 0x65bd30
// 00647f34  83c40c               add esp, 0xc
// 00647f37  e9f4fbffff           jmp 0x647b30
// 00647f3c  3b44246c             cmp eax, dword ptr [esp + 0x6c]
// 00647f40  7516                 jne 0x647f58
// 00647f42  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00647f49  51                   push ecx
// 00647f4a  56                   push esi
// 00647f4b  e8e03f0100           call 0x65bf30
// 00647f50  83c40c               add esp, 0xc
// 00647f53  e9d8fbffff           jmp 0x647b30
// 00647f58  3b44247c             cmp eax, dword ptr [esp + 0x7c]
// 00647f5c  7516                 jne 0x647f74
// 00647f5e  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00647f65  52                   push edx
// 00647f66  56                   push esi
// 00647f67  e8d4500100           call 0x65d040
// 00647f6c  83c40c               add esp, 0xc
// 00647f6f  e9bcfbffff           jmp 0x647b30
// 00647f74  3b84248c000000       cmp eax, dword ptr [esp + 0x8c]
// 00647f7b  7516                 jne 0x647f93
// 00647f7d  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00647f84  50                   push eax
// 00647f85  56                   push esi
// 00647f86  e8a54f0100           call 0x65cf30
// 00647f8b  83c40c               add esp, 0xc
// 00647f8e  e99dfbffff           jmp 0x647b30
// 00647f93  3b84249c000000       cmp eax, dword ptr [esp + 0x9c]
// 00647f9a  7516                 jne 0x647fb2
// 00647f9c  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00647fa3  51                   push ecx
// 00647fa4  56                   push esi
// 00647fa5  e826420100           call 0x65c1d0
// 00647faa  83c40c               add esp, 0xc
// 00647fad  e97efbffff           jmp 0x647b30
// 00647fb2  3b8424ac000000       cmp eax, dword ptr [esp + 0xac]
// 00647fb9  7516                 jne 0x647fd1
// 00647fbb  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00647fc2  52                   push edx
// 00647fc3  56                   push esi
// 00647fc4  e8e7510100           call 0x65d1b0
// 00647fc9  83c40c               add esp, 0xc
// 00647fcc  e95ffbffff           jmp 0x647b30
// 00647fd1  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00647fd8  50                   push eax
// 00647fd9  56                   push esi
// 00647fda  e891530100           call 0x65d370
// 00647fdf  83c40c               add esp, 0xc
// 00647fe2  e949fbffff           jmp 0x647b30
// 00647fe7  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00647fee  7550                 jne 0x648040
// 00647ff0  a802                 test al, 2
// 00647ff2  754c                 jne 0x648040
// 00647ff4  681465b800           push 0xb86514
// 00647ff9  56                   push esi
// 00647ffa  e8b1610000           call 0x64e1b0
// 00647fff  83c408               add esp, 8
// 00648002  5f                   pop edi
// 00648003  5b                   pop ebx
// 00648004  5d                   pop ebp
// 00648005  5e                   pop esi
// 00648006  81c4a0000000         add esp, 0xa0
// 0064800c  c3                   ret 
// 0064800d  8b4668               mov eax, dword ptr [esi + 0x68]
// 00648010  a801                 test al, 1
// 00648012  7507                 jne 0x64801b
// 00648014  683065b800           push 0xb86530
// 00648019  eb12                 jmp 0x64802d
// 0064801b  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00648022  7512                 jne 0x648036
// 00648024  a802                 test al, 2
// 00648026  750e                 jne 0x648036
// 00648028  681465b800           push 0xb86514
// 0064802d  56                   push esi
// 0064802e  e87d610000           call 0x64e1b0
// 00648033  83c408               add esp, 8
// 00648036  834e6804             or dword ptr [esi + 0x68], 4
// 0064803a  89be0c010000         mov dword ptr [esi + 0x10c], edi
// 00648040  5f                   pop edi
// 00648041  5b                   pop ebx
// 00648042  5d                   pop ebp
// 00648043  5e                   pop esi
// 00648044  81c4a0000000         add esp, 0xa0
// 0064804a  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
