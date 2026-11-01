// from server: 100% by auto
// roc 2009-12 00604730  unit: seg_00600000  size: 1467 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00604730
//
// 00604730  81eca0000000         sub esp, 0xa0
// 00604736  56                   push esi
// 00604737  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 0060473e  85f6                 test esi, esi
// 00604740  0f849d050000         je 0x604ce3
// 00604746  55                   push ebp
// 00604747  8bac24b0000000       mov ebp, dword ptr [esp + 0xb0]
// 0060474e  85ed                 test ebp, ebp
// 00604750  0f848c050000         je 0x604ce2
// 00604756  8a862c010000         mov al, byte ptr [esi + 0x12c]
// 0060475c  53                   push ebx
// 0060475d  57                   push edi
// 0060475e  3c08                 cmp al, 8
// 00604760  7367                 jae 0x6047c9
// 00604762  0fb6d8               movzx ebx, al
// 00604765  bf08000000           mov edi, 8
// 0060476a  2bfb                 sub edi, ebx
// 0060476c  57                   push edi
// 0060476d  8d442b20             lea eax, [ebx + ebp + 0x20]
// 00604771  50                   push eax
// 00604772  56                   push esi
// 00604773  e818630000           call 0x60aa90
// 00604778  57                   push edi
// 00604779  83c520               add ebp, 0x20
// 0060477c  53                   push ebx
// 0060477d  55                   push ebp
// 0060477e  c6862c01000008       mov byte ptr [esi + 0x12c], 8
// 00604785  e856edffff           call 0x6034e0
// 0060478a  83c418               add esp, 0x18
// 0060478d  85c0                 test eax, eax
// 0060478f  742c                 je 0x6047bd
// 00604791  83fb04               cmp ebx, 4
// 00604794  7319                 jae 0x6047af
// 00604796  83c7fc               add edi, -4
// 00604799  57                   push edi
// 0060479a  53                   push ebx
// 0060479b  55                   push ebp
// 0060479c  e83fedffff           call 0x6034e0
// 006047a1  83c40c               add esp, 0xc
// 006047a4  85c0                 test eax, eax
// 006047a6  7407                 je 0x6047af
// 006047a8  68f04d9c00           push 0x9c4df0
// 006047ad  eb05                 jmp 0x6047b4
// 006047af  68c84d9c00           push 0x9c4dc8
// 006047b4  56                   push esi
// 006047b5  e8d6b90000           call 0x610190
// 006047ba  83c408               add esp, 8
// 006047bd  83fb03               cmp ebx, 3
// 006047c0  7307                 jae 0x6047c9
// 006047c2  814e6800100000       or dword ptr [esi + 0x68], 0x1000
// 006047c9  b373                 mov bl, 0x73
// 006047cb  eb03                 jmp 0x6047d0
// 006047cd  8d4900               lea ecx, [ecx]
// 006047d0  c68424a000000049     mov byte ptr [esp + 0xa0], 0x49
// 006047d8  c68424a100000048     mov byte ptr [esp + 0xa1], 0x48
// 006047e0  c68424a200000044     mov byte ptr [esp + 0xa2], 0x44
// 006047e8  c68424a300000052     mov byte ptr [esp + 0xa3], 0x52
// 006047f0  c644246049           mov byte ptr [esp + 0x60], 0x49
// 006047f5  c644246144           mov byte ptr [esp + 0x61], 0x44
// 006047fa  c644246241           mov byte ptr [esp + 0x62], 0x41
// 006047ff  c644246354           mov byte ptr [esp + 0x63], 0x54
// 00604804  c644243049           mov byte ptr [esp + 0x30], 0x49
// 00604809  c644243145           mov byte ptr [esp + 0x31], 0x45
// 0060480e  c64424324e           mov byte ptr [esp + 0x32], 0x4e
// 00604813  c644243344           mov byte ptr [esp + 0x33], 0x44
// 00604818  c644241050           mov byte ptr [esp + 0x10], 0x50
// 0060481d  c64424114c           mov byte ptr [esp + 0x11], 0x4c
// 00604822  c644241254           mov byte ptr [esp + 0x12], 0x54
// 00604827  c644241345           mov byte ptr [esp + 0x13], 0x45
// 0060482c  c644247062           mov byte ptr [esp + 0x70], 0x62
// 00604831  c64424714b           mov byte ptr [esp + 0x71], 0x4b
// 00604836  c644247247           mov byte ptr [esp + 0x72], 0x47
// 0060483b  c644247344           mov byte ptr [esp + 0x73], 0x44
// 00604840  c644244063           mov byte ptr [esp + 0x40], 0x63
// 00604845  c644244148           mov byte ptr [esp + 0x41], 0x48
// 0060484a  c644244252           mov byte ptr [esp + 0x42], 0x52
// 0060484f  c64424434d           mov byte ptr [esp + 0x43], 0x4d
// 00604854  c684249000000067     mov byte ptr [esp + 0x90], 0x67
// 0060485c  c684249100000041     mov byte ptr [esp + 0x91], 0x41
// 00604864  c68424920000004d     mov byte ptr [esp + 0x92], 0x4d
// 0060486c  c684249300000041     mov byte ptr [esp + 0x93], 0x41
// 00604874  c644245068           mov byte ptr [esp + 0x50], 0x68
// 00604879  c644245149           mov byte ptr [esp + 0x51], 0x49
// 0060487e  c644245253           mov byte ptr [esp + 0x52], 0x53
// 00604883  c644245354           mov byte ptr [esp + 0x53], 0x54
// 00604888  c644245869           mov byte ptr [esp + 0x58], 0x69
// 0060488d  c644245943           mov byte ptr [esp + 0x59], 0x43
// 00604892  c644245a43           mov byte ptr [esp + 0x5a], 0x43
// 00604897  c644245b50           mov byte ptr [esp + 0x5b], 0x50
// 0060489c  c68424800000006f     mov byte ptr [esp + 0x80], 0x6f
// 006048a4  c684248100000046     mov byte ptr [esp + 0x81], 0x46
// 006048ac  c684248200000046     mov byte ptr [esp + 0x82], 0x46
// 006048b4  889c2483000000       mov byte ptr [esp + 0x83], bl
// 006048bb  c644241870           mov byte ptr [esp + 0x18], 0x70
// 006048c0  c644241943           mov byte ptr [esp + 0x19], 0x43
// 006048c5  c644241a41           mov byte ptr [esp + 0x1a], 0x41
// 006048ca  c644241b4c           mov byte ptr [esp + 0x1b], 0x4c
// 006048cf  c644242870           mov byte ptr [esp + 0x28], 0x70
// 006048d4  c644242948           mov byte ptr [esp + 0x29], 0x48
// 006048d9  c644242a59           mov byte ptr [esp + 0x2a], 0x59
// 006048de  885c242b             mov byte ptr [esp + 0x2b], bl
// 006048e2  885c2438             mov byte ptr [esp + 0x38], bl
// 006048e6  c644243942           mov byte ptr [esp + 0x39], 0x42
// 006048eb  c644243a49           mov byte ptr [esp + 0x3a], 0x49
// 006048f0  c644243b54           mov byte ptr [esp + 0x3b], 0x54
// 006048f5  885c2420             mov byte ptr [esp + 0x20], bl
// 006048f9  c644242143           mov byte ptr [esp + 0x21], 0x43
// 006048fe  c644242241           mov byte ptr [esp + 0x22], 0x41
// 00604903  c64424234c           mov byte ptr [esp + 0x23], 0x4c
// 00604908  885c2468             mov byte ptr [esp + 0x68], bl
// 0060490c  c644246950           mov byte ptr [esp + 0x69], 0x50
// 00604911  c644246a4c           mov byte ptr [esp + 0x6a], 0x4c
// 00604916  c644246b54           mov byte ptr [esp + 0x6b], 0x54
// 0060491b  885c2448             mov byte ptr [esp + 0x48], bl
// 0060491f  c644244952           mov byte ptr [esp + 0x49], 0x52
// 00604924  c644244a47           mov byte ptr [esp + 0x4a], 0x47
// 00604929  c644244b42           mov byte ptr [esp + 0x4b], 0x42
// 0060492e  c644247874           mov byte ptr [esp + 0x78], 0x74
// 00604933  c644247945           mov byte ptr [esp + 0x79], 0x45
// 00604938  c644247a58           mov byte ptr [esp + 0x7a], 0x58
// 0060493d  c644247b74           mov byte ptr [esp + 0x7b], 0x74
// 00604942  c684248800000074     mov byte ptr [esp + 0x88], 0x74
// 0060494a  c684248900000049     mov byte ptr [esp + 0x89], 0x49
// 00604952  c684248a0000004d     mov byte ptr [esp + 0x8a], 0x4d
// 0060495a  c684248b00000045     mov byte ptr [esp + 0x8b], 0x45
// 00604962  c684249800000074     mov byte ptr [esp + 0x98], 0x74
// 0060496a  c684249900000052     mov byte ptr [esp + 0x99], 0x52
// 00604972  c684249a0000004e     mov byte ptr [esp + 0x9a], 0x4e
// 0060497a  c684249b00000053     mov byte ptr [esp + 0x9b], 0x53
// 00604982  c68424a80000007a     mov byte ptr [esp + 0xa8], 0x7a
// 0060498a  c68424a900000054     mov byte ptr [esp + 0xa9], 0x54
// 00604992  c68424aa00000058     mov byte ptr [esp + 0xaa], 0x58
// 0060499a  c68424ab00000074     mov byte ptr [esp + 0xab], 0x74
// 006049a2  56                   push esi
// 006049a3  e8b8210100           call 0x616b60
// 006049a8  8b6c2464             mov ebp, dword ptr [esp + 0x64]
// 006049ac  8d8e1c010000         lea ecx, [esi + 0x11c]
// 006049b2  83c404               add esp, 4
// 006049b5  8bf8                 mov edi, eax
// 006049b7  3929                 cmp dword ptr [ecx], ebp
// 006049b9  750f                 jne 0x6049ca
// 006049bb  8b4668               mov eax, dword ptr [esi + 0x68]
// 006049be  a808                 test al, 8
// 006049c0  7408                 je 0x6049ca
// 006049c2  0d00200000           or eax, 0x2000
// 006049c7  894668               mov dword ptr [esi + 0x68], eax
// 006049ca  8b01                 mov eax, dword ptr [ecx]
// 006049cc  3b8424a0000000       cmp eax, dword ptr [esp + 0xa0]
// 006049d3  7517                 jne 0x6049ec
// 006049d5  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 006049dc  57                   push edi
// 006049dd  51                   push ecx
// 006049de  56                   push esi
// 006049df  e8dc220100           call 0x616cc0
// 006049e4  83c40c               add esp, 0xc
// 006049e7  e9e4fdffff           jmp 0x6047d0
// 006049ec  3b442430             cmp eax, dword ptr [esp + 0x30]
// 006049f0  7517                 jne 0x604a09
// 006049f2  8b9424b8000000       mov edx, dword ptr [esp + 0xb8]
// 006049f9  57                   push edi
// 006049fa  52                   push edx
// 006049fb  56                   push esi
// 006049fc  e81f260100           call 0x617020
// 00604a01  83c40c               add esp, 0xc
// 00604a04  e9c7fdffff           jmp 0x6047d0
// 00604a09  51                   push ecx
// 00604a0a  56                   push esi
// 00604a0b  e8d0f0ffff           call 0x603ae0
// 00604a10  83c408               add esp, 8
// 00604a13  85c0                 test eax, eax
// 00604a15  745f                 je 0x604a76
// 00604a17  39ae1c010000         cmp dword ptr [esi + 0x11c], ebp
// 00604a1d  7504                 jne 0x604a23
// 00604a1f  834e6804             or dword ptr [esi + 0x68], 4
// 00604a23  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 00604a2a  57                   push edi
// 00604a2b  50                   push eax
// 00604a2c  56                   push esi
// 00604a2d  e8ae450100           call 0x618fe0
// 00604a32  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00604a38  83c40c               add esp, 0xc
// 00604a3b  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00604a3f  7509                 jne 0x604a4a
// 00604a41  834e6802             or dword ptr [esi + 0x68], 2
// 00604a45  e986fdffff           jmp 0x6047d0
// 00604a4a  3bc5                 cmp eax, ebp
// 00604a4c  0f857efdffff         jne 0x6047d0
// 00604a52  8b4668               mov eax, dword ptr [esi + 0x68]
// 00604a55  a801                 test al, 1
// 00604a57  0f852a020000         jne 0x604c87
// 00604a5d  68ac4d9c00           push 0x9c4dac
// 00604a62  56                   push esi
// 00604a63  e828b70000           call 0x610190
// 00604a68  83c408               add esp, 8
// 00604a6b  5f                   pop edi
// 00604a6c  5b                   pop ebx
// 00604a6d  5d                   pop ebp
// 00604a6e  5e                   pop esi
// 00604a6f  81c4a0000000         add esp, 0xa0
// 00604a75  c3                   ret 
// 00604a76  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00604a7c  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00604a80  7517                 jne 0x604a99
// 00604a82  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 00604a89  57                   push edi
// 00604a8a  51                   push ecx
// 00604a8b  56                   push esi
// 00604a8c  e8ef230100           call 0x616e80
// 00604a91  83c40c               add esp, 0xc
// 00604a94  e937fdffff           jmp 0x6047d0
// 00604a99  3bc5                 cmp eax, ebp
// 00604a9b  0f840c020000         je 0x604cad
// 00604aa1  57                   push edi
// 00604aa2  3b442474             cmp eax, dword ptr [esp + 0x74]
// 00604aa6  7516                 jne 0x604abe
// 00604aa8  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00604aaf  52                   push edx
// 00604ab0  56                   push esi
// 00604ab1  e84a360100           call 0x618100
// 00604ab6  83c40c               add esp, 0xc
// 00604ab9  e912fdffff           jmp 0x6047d0
// 00604abe  3b442444             cmp eax, dword ptr [esp + 0x44]
// 00604ac2  7516                 jne 0x604ada
// 00604ac4  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00604acb  50                   push eax
// 00604acc  56                   push esi
// 00604acd  e8ae280100           call 0x617380
// 00604ad2  83c40c               add esp, 0xc
// 00604ad5  e9f6fcffff           jmp 0x6047d0
// 00604ada  3b842494000000       cmp eax, dword ptr [esp + 0x94]
// 00604ae1  7516                 jne 0x604af9
// 00604ae3  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00604aea  51                   push ecx
// 00604aeb  56                   push esi
// 00604aec  e87f250100           call 0x617070
// 00604af1  83c40c               add esp, 0xc
// 00604af4  e9d7fcffff           jmp 0x6047d0
// 00604af9  3b442454             cmp eax, dword ptr [esp + 0x54]
// 00604afd  7516                 jne 0x604b15
// 00604aff  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00604b06  52                   push edx
// 00604b07  56                   push esi
// 00604b08  e813380100           call 0x618320
// 00604b0d  83c40c               add esp, 0xc
// 00604b10  e9bbfcffff           jmp 0x6047d0
// 00604b15  3b842484000000       cmp eax, dword ptr [esp + 0x84]
// 00604b1c  7516                 jne 0x604b34
// 00604b1e  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00604b25  50                   push eax
// 00604b26  56                   push esi
// 00604b27  e8943a0100           call 0x6185c0
// 00604b2c  83c40c               add esp, 0xc
// 00604b2f  e99cfcffff           jmp 0x6047d0
// 00604b34  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 00604b38  7516                 jne 0x604b50
// 00604b3a  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00604b41  51                   push ecx
// 00604b42  56                   push esi
// 00604b43  e8983b0100           call 0x6186e0
// 00604b48  83c40c               add esp, 0xc
// 00604b4b  e980fcffff           jmp 0x6047d0
// 00604b50  3b442424             cmp eax, dword ptr [esp + 0x24]
// 00604b54  7516                 jne 0x604b6c
// 00604b56  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00604b5d  52                   push edx
// 00604b5e  56                   push esi
// 00604b5f  e87c3e0100           call 0x6189e0
// 00604b64  83c40c               add esp, 0xc
// 00604b67  e964fcffff           jmp 0x6047d0
// 00604b6c  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 00604b70  7516                 jne 0x604b88
// 00604b72  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00604b79  50                   push eax
// 00604b7a  56                   push esi
// 00604b7b  e820390100           call 0x6184a0
// 00604b80  83c40c               add esp, 0xc
// 00604b83  e948fcffff           jmp 0x6047d0
// 00604b88  3b44243c             cmp eax, dword ptr [esp + 0x3c]
// 00604b8c  7516                 jne 0x604ba4
// 00604b8e  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00604b95  51                   push ecx
// 00604b96  56                   push esi
// 00604b97  e864260100           call 0x617200
// 00604b9c  83c40c               add esp, 0xc
// 00604b9f  e92cfcffff           jmp 0x6047d0
// 00604ba4  3b44244c             cmp eax, dword ptr [esp + 0x4c]
// 00604ba8  7516                 jne 0x604bc0
// 00604baa  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00604bb1  52                   push edx
// 00604bb2  56                   push esi
// 00604bb3  e8282c0100           call 0x6177e0
// 00604bb8  83c40c               add esp, 0xc
// 00604bbb  e910fcffff           jmp 0x6047d0
// 00604bc0  3b44245c             cmp eax, dword ptr [esp + 0x5c]
// 00604bc4  7516                 jne 0x604bdc
// 00604bc6  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00604bcd  50                   push eax
// 00604bce  56                   push esi
// 00604bcf  e81c2e0100           call 0x6179f0
// 00604bd4  83c40c               add esp, 0xc
// 00604bd7  e9f4fbffff           jmp 0x6047d0
// 00604bdc  3b44246c             cmp eax, dword ptr [esp + 0x6c]
// 00604be0  7516                 jne 0x604bf8
// 00604be2  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00604be9  51                   push ecx
// 00604bea  56                   push esi
// 00604beb  e800300100           call 0x617bf0
// 00604bf0  83c40c               add esp, 0xc
// 00604bf3  e9d8fbffff           jmp 0x6047d0
// 00604bf8  3b44247c             cmp eax, dword ptr [esp + 0x7c]
// 00604bfc  7516                 jne 0x604c14
// 00604bfe  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00604c05  52                   push edx
// 00604c06  56                   push esi
// 00604c07  e8f4400100           call 0x618d00
// 00604c0c  83c40c               add esp, 0xc
// 00604c0f  e9bcfbffff           jmp 0x6047d0
// 00604c14  3b84248c000000       cmp eax, dword ptr [esp + 0x8c]
// 00604c1b  7516                 jne 0x604c33
// 00604c1d  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00604c24  50                   push eax
// 00604c25  56                   push esi
// 00604c26  e8c53f0100           call 0x618bf0
// 00604c2b  83c40c               add esp, 0xc
// 00604c2e  e99dfbffff           jmp 0x6047d0
// 00604c33  3b84249c000000       cmp eax, dword ptr [esp + 0x9c]
// 00604c3a  7516                 jne 0x604c52
// 00604c3c  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00604c43  51                   push ecx
// 00604c44  56                   push esi
// 00604c45  e846320100           call 0x617e90
// 00604c4a  83c40c               add esp, 0xc
// 00604c4d  e97efbffff           jmp 0x6047d0
// 00604c52  3b8424ac000000       cmp eax, dword ptr [esp + 0xac]
// 00604c59  7516                 jne 0x604c71
// 00604c5b  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00604c62  52                   push edx
// 00604c63  56                   push esi
// 00604c64  e8b7410100           call 0x618e20
// 00604c69  83c40c               add esp, 0xc
// 00604c6c  e95ffbffff           jmp 0x6047d0
// 00604c71  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00604c78  50                   push eax
// 00604c79  56                   push esi
// 00604c7a  e861430100           call 0x618fe0
// 00604c7f  83c40c               add esp, 0xc
// 00604c82  e949fbffff           jmp 0x6047d0
// 00604c87  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00604c8e  7550                 jne 0x604ce0
// 00604c90  a802                 test al, 2
// 00604c92  754c                 jne 0x604ce0
// 00604c94  68904d9c00           push 0x9c4d90
// 00604c99  56                   push esi
// 00604c9a  e8f1b40000           call 0x610190
// 00604c9f  83c408               add esp, 8
// 00604ca2  5f                   pop edi
// 00604ca3  5b                   pop ebx
// 00604ca4  5d                   pop ebp
// 00604ca5  5e                   pop esi
// 00604ca6  81c4a0000000         add esp, 0xa0
// 00604cac  c3                   ret 
// 00604cad  8b4668               mov eax, dword ptr [esi + 0x68]
// 00604cb0  a801                 test al, 1
// 00604cb2  7507                 jne 0x604cbb
// 00604cb4  68ac4d9c00           push 0x9c4dac
// 00604cb9  eb12                 jmp 0x604ccd
// 00604cbb  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00604cc2  7512                 jne 0x604cd6
// 00604cc4  a802                 test al, 2
// 00604cc6  750e                 jne 0x604cd6
// 00604cc8  68904d9c00           push 0x9c4d90
// 00604ccd  56                   push esi
// 00604cce  e8bdb40000           call 0x610190
// 00604cd3  83c408               add esp, 8
// 00604cd6  834e6804             or dword ptr [esi + 0x68], 4
// 00604cda  89be0c010000         mov dword ptr [esi + 0x10c], edi
// 00604ce0  5f                   pop edi
// 00604ce1  5b                   pop ebx
// 00604ce2  5d                   pop ebp
// 00604ce3  5e                   pop esi
// 00604ce4  81c4a0000000         add esp, 0xa0
// 00604cea  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
