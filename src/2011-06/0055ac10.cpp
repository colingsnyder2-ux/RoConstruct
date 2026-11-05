// from server: 100% by auto
// roc 2011-06 0055ac10  unit: seg_00550000  size: 1467 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055ac10
//
// 0055ac10  81eca0000000         sub esp, 0xa0
// 0055ac16  56                   push esi
// 0055ac17  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 0055ac1e  85f6                 test esi, esi
// 0055ac20  0f849d050000         je 0x55b1c3
// 0055ac26  55                   push ebp
// 0055ac27  8bac24b0000000       mov ebp, dword ptr [esp + 0xb0]
// 0055ac2e  85ed                 test ebp, ebp
// 0055ac30  0f848c050000         je 0x55b1c2
// 0055ac36  8a862c010000         mov al, byte ptr [esi + 0x12c]
// 0055ac3c  53                   push ebx
// 0055ac3d  57                   push edi
// 0055ac3e  3c08                 cmp al, 8
// 0055ac40  7367                 jae 0x55aca9
// 0055ac42  0fb6d8               movzx ebx, al
// 0055ac45  bf08000000           mov edi, 8
// 0055ac4a  2bfb                 sub edi, ebx
// 0055ac4c  57                   push edi
// 0055ac4d  8d442b20             lea eax, [ebx + ebp + 0x20]
// 0055ac51  50                   push eax
// 0055ac52  56                   push esi
// 0055ac53  e818630000           call 0x560f70
// 0055ac58  57                   push edi
// 0055ac59  83c520               add ebp, 0x20
// 0055ac5c  53                   push ebx
// 0055ac5d  55                   push ebp
// 0055ac5e  c6862c01000008       mov byte ptr [esi + 0x12c], 8
// 0055ac65  e8565affff           call 0x5506c0
// 0055ac6a  83c418               add esp, 0x18
// 0055ac6d  85c0                 test eax, eax
// 0055ac6f  742c                 je 0x55ac9d
// 0055ac71  83fb04               cmp ebx, 4
// 0055ac74  7319                 jae 0x55ac8f
// 0055ac76  83c7fc               add edi, -4
// 0055ac79  57                   push edi
// 0055ac7a  53                   push ebx
// 0055ac7b  55                   push ebp
// 0055ac7c  e83f5affff           call 0x5506c0
// 0055ac81  83c40c               add esp, 0xc
// 0055ac84  85c0                 test eax, eax
// 0055ac86  7407                 je 0x55ac8f
// 0055ac88  68c426a800           push 0xa826c4
// 0055ac8d  eb05                 jmp 0x55ac94
// 0055ac8f  689c26a800           push 0xa8269c
// 0055ac94  56                   push esi
// 0055ac95  e896660000           call 0x561330
// 0055ac9a  83c408               add esp, 8
// 0055ac9d  83fb03               cmp ebx, 3
// 0055aca0  7307                 jae 0x55aca9
// 0055aca2  814e6800100000       or dword ptr [esi + 0x68], 0x1000
// 0055aca9  b373                 mov bl, 0x73
// 0055acab  eb03                 jmp 0x55acb0
// 0055acad  8d4900               lea ecx, [ecx]
// 0055acb0  c68424a000000049     mov byte ptr [esp + 0xa0], 0x49
// 0055acb8  c68424a100000048     mov byte ptr [esp + 0xa1], 0x48
// 0055acc0  c68424a200000044     mov byte ptr [esp + 0xa2], 0x44
// 0055acc8  c68424a300000052     mov byte ptr [esp + 0xa3], 0x52
// 0055acd0  c644246049           mov byte ptr [esp + 0x60], 0x49
// 0055acd5  c644246144           mov byte ptr [esp + 0x61], 0x44
// 0055acda  c644246241           mov byte ptr [esp + 0x62], 0x41
// 0055acdf  c644246354           mov byte ptr [esp + 0x63], 0x54
// 0055ace4  c644243049           mov byte ptr [esp + 0x30], 0x49
// 0055ace9  c644243145           mov byte ptr [esp + 0x31], 0x45
// 0055acee  c64424324e           mov byte ptr [esp + 0x32], 0x4e
// 0055acf3  c644243344           mov byte ptr [esp + 0x33], 0x44
// 0055acf8  c644241050           mov byte ptr [esp + 0x10], 0x50
// 0055acfd  c64424114c           mov byte ptr [esp + 0x11], 0x4c
// 0055ad02  c644241254           mov byte ptr [esp + 0x12], 0x54
// 0055ad07  c644241345           mov byte ptr [esp + 0x13], 0x45
// 0055ad0c  c644247062           mov byte ptr [esp + 0x70], 0x62
// 0055ad11  c64424714b           mov byte ptr [esp + 0x71], 0x4b
// 0055ad16  c644247247           mov byte ptr [esp + 0x72], 0x47
// 0055ad1b  c644247344           mov byte ptr [esp + 0x73], 0x44
// 0055ad20  c644244063           mov byte ptr [esp + 0x40], 0x63
// 0055ad25  c644244148           mov byte ptr [esp + 0x41], 0x48
// 0055ad2a  c644244252           mov byte ptr [esp + 0x42], 0x52
// 0055ad2f  c64424434d           mov byte ptr [esp + 0x43], 0x4d
// 0055ad34  c684249000000067     mov byte ptr [esp + 0x90], 0x67
// 0055ad3c  c684249100000041     mov byte ptr [esp + 0x91], 0x41
// 0055ad44  c68424920000004d     mov byte ptr [esp + 0x92], 0x4d
// 0055ad4c  c684249300000041     mov byte ptr [esp + 0x93], 0x41
// 0055ad54  c644245068           mov byte ptr [esp + 0x50], 0x68
// 0055ad59  c644245149           mov byte ptr [esp + 0x51], 0x49
// 0055ad5e  c644245253           mov byte ptr [esp + 0x52], 0x53
// 0055ad63  c644245354           mov byte ptr [esp + 0x53], 0x54
// 0055ad68  c644245869           mov byte ptr [esp + 0x58], 0x69
// 0055ad6d  c644245943           mov byte ptr [esp + 0x59], 0x43
// 0055ad72  c644245a43           mov byte ptr [esp + 0x5a], 0x43
// 0055ad77  c644245b50           mov byte ptr [esp + 0x5b], 0x50
// 0055ad7c  c68424800000006f     mov byte ptr [esp + 0x80], 0x6f
// 0055ad84  c684248100000046     mov byte ptr [esp + 0x81], 0x46
// 0055ad8c  c684248200000046     mov byte ptr [esp + 0x82], 0x46
// 0055ad94  889c2483000000       mov byte ptr [esp + 0x83], bl
// 0055ad9b  c644241870           mov byte ptr [esp + 0x18], 0x70
// 0055ada0  c644241943           mov byte ptr [esp + 0x19], 0x43
// 0055ada5  c644241a41           mov byte ptr [esp + 0x1a], 0x41
// 0055adaa  c644241b4c           mov byte ptr [esp + 0x1b], 0x4c
// 0055adaf  c644242870           mov byte ptr [esp + 0x28], 0x70
// 0055adb4  c644242948           mov byte ptr [esp + 0x29], 0x48
// 0055adb9  c644242a59           mov byte ptr [esp + 0x2a], 0x59
// 0055adbe  885c242b             mov byte ptr [esp + 0x2b], bl
// 0055adc2  885c2438             mov byte ptr [esp + 0x38], bl
// 0055adc6  c644243942           mov byte ptr [esp + 0x39], 0x42
// 0055adcb  c644243a49           mov byte ptr [esp + 0x3a], 0x49
// 0055add0  c644243b54           mov byte ptr [esp + 0x3b], 0x54
// 0055add5  885c2420             mov byte ptr [esp + 0x20], bl
// 0055add9  c644242143           mov byte ptr [esp + 0x21], 0x43
// 0055adde  c644242241           mov byte ptr [esp + 0x22], 0x41
// 0055ade3  c64424234c           mov byte ptr [esp + 0x23], 0x4c
// 0055ade8  885c2468             mov byte ptr [esp + 0x68], bl
// 0055adec  c644246950           mov byte ptr [esp + 0x69], 0x50
// 0055adf1  c644246a4c           mov byte ptr [esp + 0x6a], 0x4c
// 0055adf6  c644246b54           mov byte ptr [esp + 0x6b], 0x54
// 0055adfb  885c2448             mov byte ptr [esp + 0x48], bl
// 0055adff  c644244952           mov byte ptr [esp + 0x49], 0x52
// 0055ae04  c644244a47           mov byte ptr [esp + 0x4a], 0x47
// 0055ae09  c644244b42           mov byte ptr [esp + 0x4b], 0x42
// 0055ae0e  c644247874           mov byte ptr [esp + 0x78], 0x74
// 0055ae13  c644247945           mov byte ptr [esp + 0x79], 0x45
// 0055ae18  c644247a58           mov byte ptr [esp + 0x7a], 0x58
// 0055ae1d  c644247b74           mov byte ptr [esp + 0x7b], 0x74
// 0055ae22  c684248800000074     mov byte ptr [esp + 0x88], 0x74
// 0055ae2a  c684248900000049     mov byte ptr [esp + 0x89], 0x49
// 0055ae32  c684248a0000004d     mov byte ptr [esp + 0x8a], 0x4d
// 0055ae3a  c684248b00000045     mov byte ptr [esp + 0x8b], 0x45
// 0055ae42  c684249800000074     mov byte ptr [esp + 0x98], 0x74
// 0055ae4a  c684249900000052     mov byte ptr [esp + 0x99], 0x52
// 0055ae52  c684249a0000004e     mov byte ptr [esp + 0x9a], 0x4e
// 0055ae5a  c684249b00000053     mov byte ptr [esp + 0x9b], 0x53
// 0055ae62  c68424a80000007a     mov byte ptr [esp + 0xa8], 0x7a
// 0055ae6a  c68424a900000054     mov byte ptr [esp + 0xa9], 0x54
// 0055ae72  c68424aa00000058     mov byte ptr [esp + 0xaa], 0x58
// 0055ae7a  c68424ab00000074     mov byte ptr [esp + 0xab], 0x74
// 0055ae82  56                   push esi
// 0055ae83  e828490100           call 0x56f7b0
// 0055ae88  8b6c2464             mov ebp, dword ptr [esp + 0x64]
// 0055ae8c  8d8e1c010000         lea ecx, [esi + 0x11c]
// 0055ae92  83c404               add esp, 4
// 0055ae95  8bf8                 mov edi, eax
// 0055ae97  3929                 cmp dword ptr [ecx], ebp
// 0055ae99  750f                 jne 0x55aeaa
// 0055ae9b  8b4668               mov eax, dword ptr [esi + 0x68]
// 0055ae9e  a808                 test al, 8
// 0055aea0  7408                 je 0x55aeaa
// 0055aea2  0d00200000           or eax, 0x2000
// 0055aea7  894668               mov dword ptr [esi + 0x68], eax
// 0055aeaa  8b01                 mov eax, dword ptr [ecx]
// 0055aeac  3b8424a0000000       cmp eax, dword ptr [esp + 0xa0]
// 0055aeb3  7517                 jne 0x55aecc
// 0055aeb5  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 0055aebc  57                   push edi
// 0055aebd  51                   push ecx
// 0055aebe  56                   push esi
// 0055aebf  e84c4a0100           call 0x56f910
// 0055aec4  83c40c               add esp, 0xc
// 0055aec7  e9e4fdffff           jmp 0x55acb0
// 0055aecc  3b442430             cmp eax, dword ptr [esp + 0x30]
// 0055aed0  7517                 jne 0x55aee9
// 0055aed2  8b9424b8000000       mov edx, dword ptr [esp + 0xb8]
// 0055aed9  57                   push edi
// 0055aeda  52                   push edx
// 0055aedb  56                   push esi
// 0055aedc  e88f4d0100           call 0x56fc70
// 0055aee1  83c40c               add esp, 0xc
// 0055aee4  e9c7fdffff           jmp 0x55acb0
// 0055aee9  51                   push ecx
// 0055aeea  56                   push esi
// 0055aeeb  e8d05dffff           call 0x550cc0
// 0055aef0  83c408               add esp, 8
// 0055aef3  85c0                 test eax, eax
// 0055aef5  745f                 je 0x55af56
// 0055aef7  39ae1c010000         cmp dword ptr [esi + 0x11c], ebp
// 0055aefd  7504                 jne 0x55af03
// 0055aeff  834e6804             or dword ptr [esi + 0x68], 4
// 0055af03  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 0055af0a  57                   push edi
// 0055af0b  50                   push eax
// 0055af0c  56                   push esi
// 0055af0d  e84e6d0100           call 0x571c60
// 0055af12  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0055af18  83c40c               add esp, 0xc
// 0055af1b  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0055af1f  7509                 jne 0x55af2a
// 0055af21  834e6802             or dword ptr [esi + 0x68], 2
// 0055af25  e986fdffff           jmp 0x55acb0
// 0055af2a  3bc5                 cmp eax, ebp
// 0055af2c  0f857efdffff         jne 0x55acb0
// 0055af32  8b4668               mov eax, dword ptr [esi + 0x68]
// 0055af35  a801                 test al, 1
// 0055af37  0f852a020000         jne 0x55b167
// 0055af3d  688026a800           push 0xa82680
// 0055af42  56                   push esi
// 0055af43  e8e8630000           call 0x561330
// 0055af48  83c408               add esp, 8
// 0055af4b  5f                   pop edi
// 0055af4c  5b                   pop ebx
// 0055af4d  5d                   pop ebp
// 0055af4e  5e                   pop esi
// 0055af4f  81c4a0000000         add esp, 0xa0
// 0055af55  c3                   ret 
// 0055af56  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0055af5c  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0055af60  7517                 jne 0x55af79
// 0055af62  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 0055af69  57                   push edi
// 0055af6a  51                   push ecx
// 0055af6b  56                   push esi
// 0055af6c  e85f4b0100           call 0x56fad0
// 0055af71  83c40c               add esp, 0xc
// 0055af74  e937fdffff           jmp 0x55acb0
// 0055af79  3bc5                 cmp eax, ebp
// 0055af7b  0f840c020000         je 0x55b18d
// 0055af81  57                   push edi
// 0055af82  3b442474             cmp eax, dword ptr [esp + 0x74]
// 0055af86  7516                 jne 0x55af9e
// 0055af88  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 0055af8f  52                   push edx
// 0055af90  56                   push esi
// 0055af91  e89a5d0100           call 0x570d30
// 0055af96  83c40c               add esp, 0xc
// 0055af99  e912fdffff           jmp 0x55acb0
// 0055af9e  3b442444             cmp eax, dword ptr [esp + 0x44]
// 0055afa2  7516                 jne 0x55afba
// 0055afa4  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 0055afab  50                   push eax
// 0055afac  56                   push esi
// 0055afad  e81e500100           call 0x56ffd0
// 0055afb2  83c40c               add esp, 0xc
// 0055afb5  e9f6fcffff           jmp 0x55acb0
// 0055afba  3b842494000000       cmp eax, dword ptr [esp + 0x94]
// 0055afc1  7516                 jne 0x55afd9
// 0055afc3  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 0055afca  51                   push ecx
// 0055afcb  56                   push esi
// 0055afcc  e8ef4c0100           call 0x56fcc0
// 0055afd1  83c40c               add esp, 0xc
// 0055afd4  e9d7fcffff           jmp 0x55acb0
// 0055afd9  3b442454             cmp eax, dword ptr [esp + 0x54]
// 0055afdd  7516                 jne 0x55aff5
// 0055afdf  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 0055afe6  52                   push edx
// 0055afe7  56                   push esi
// 0055afe8  e8635f0100           call 0x570f50
// 0055afed  83c40c               add esp, 0xc
// 0055aff0  e9bbfcffff           jmp 0x55acb0
// 0055aff5  3b842484000000       cmp eax, dword ptr [esp + 0x84]
// 0055affc  7516                 jne 0x55b014
// 0055affe  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 0055b005  50                   push eax
// 0055b006  56                   push esi
// 0055b007  e8e4610100           call 0x5711f0
// 0055b00c  83c40c               add esp, 0xc
// 0055b00f  e99cfcffff           jmp 0x55acb0
// 0055b014  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 0055b018  7516                 jne 0x55b030
// 0055b01a  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 0055b021  51                   push ecx
// 0055b022  56                   push esi
// 0055b023  e8e8620100           call 0x571310
// 0055b028  83c40c               add esp, 0xc
// 0055b02b  e980fcffff           jmp 0x55acb0
// 0055b030  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0055b034  7516                 jne 0x55b04c
// 0055b036  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 0055b03d  52                   push edx
// 0055b03e  56                   push esi
// 0055b03f  e8cc650100           call 0x571610
// 0055b044  83c40c               add esp, 0xc
// 0055b047  e964fcffff           jmp 0x55acb0
// 0055b04c  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 0055b050  7516                 jne 0x55b068
// 0055b052  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 0055b059  50                   push eax
// 0055b05a  56                   push esi
// 0055b05b  e870600100           call 0x5710d0
// 0055b060  83c40c               add esp, 0xc
// 0055b063  e948fcffff           jmp 0x55acb0
// 0055b068  3b44243c             cmp eax, dword ptr [esp + 0x3c]
// 0055b06c  7516                 jne 0x55b084
// 0055b06e  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 0055b075  51                   push ecx
// 0055b076  56                   push esi
// 0055b077  e8d44d0100           call 0x56fe50
// 0055b07c  83c40c               add esp, 0xc
// 0055b07f  e92cfcffff           jmp 0x55acb0
// 0055b084  3b44244c             cmp eax, dword ptr [esp + 0x4c]
// 0055b088  7516                 jne 0x55b0a0
// 0055b08a  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 0055b091  52                   push edx
// 0055b092  56                   push esi
// 0055b093  e878530100           call 0x570410
// 0055b098  83c40c               add esp, 0xc
// 0055b09b  e910fcffff           jmp 0x55acb0
// 0055b0a0  3b44245c             cmp eax, dword ptr [esp + 0x5c]
// 0055b0a4  7516                 jne 0x55b0bc
// 0055b0a6  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 0055b0ad  50                   push eax
// 0055b0ae  56                   push esi
// 0055b0af  e86c550100           call 0x570620
// 0055b0b4  83c40c               add esp, 0xc
// 0055b0b7  e9f4fbffff           jmp 0x55acb0
// 0055b0bc  3b44246c             cmp eax, dword ptr [esp + 0x6c]
// 0055b0c0  7516                 jne 0x55b0d8
// 0055b0c2  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 0055b0c9  51                   push ecx
// 0055b0ca  56                   push esi
// 0055b0cb  e850570100           call 0x570820
// 0055b0d0  83c40c               add esp, 0xc
// 0055b0d3  e9d8fbffff           jmp 0x55acb0
// 0055b0d8  3b44247c             cmp eax, dword ptr [esp + 0x7c]
// 0055b0dc  7516                 jne 0x55b0f4
// 0055b0de  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 0055b0e5  52                   push edx
// 0055b0e6  56                   push esi
// 0055b0e7  e844680100           call 0x571930
// 0055b0ec  83c40c               add esp, 0xc
// 0055b0ef  e9bcfbffff           jmp 0x55acb0
// 0055b0f4  3b84248c000000       cmp eax, dword ptr [esp + 0x8c]
// 0055b0fb  7516                 jne 0x55b113
// 0055b0fd  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 0055b104  50                   push eax
// 0055b105  56                   push esi
// 0055b106  e815670100           call 0x571820
// 0055b10b  83c40c               add esp, 0xc
// 0055b10e  e99dfbffff           jmp 0x55acb0
// 0055b113  3b84249c000000       cmp eax, dword ptr [esp + 0x9c]
// 0055b11a  7516                 jne 0x55b132
// 0055b11c  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 0055b123  51                   push ecx
// 0055b124  56                   push esi
// 0055b125  e896590100           call 0x570ac0
// 0055b12a  83c40c               add esp, 0xc
// 0055b12d  e97efbffff           jmp 0x55acb0
// 0055b132  3b8424ac000000       cmp eax, dword ptr [esp + 0xac]
// 0055b139  7516                 jne 0x55b151
// 0055b13b  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 0055b142  52                   push edx
// 0055b143  56                   push esi
// 0055b144  e857690100           call 0x571aa0
// 0055b149  83c40c               add esp, 0xc
// 0055b14c  e95ffbffff           jmp 0x55acb0
// 0055b151  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 0055b158  50                   push eax
// 0055b159  56                   push esi
// 0055b15a  e8016b0100           call 0x571c60
// 0055b15f  83c40c               add esp, 0xc
// 0055b162  e949fbffff           jmp 0x55acb0
// 0055b167  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 0055b16e  7550                 jne 0x55b1c0
// 0055b170  a802                 test al, 2
// 0055b172  754c                 jne 0x55b1c0
// 0055b174  686426a800           push 0xa82664
// 0055b179  56                   push esi
// 0055b17a  e8b1610000           call 0x561330
// 0055b17f  83c408               add esp, 8
// 0055b182  5f                   pop edi
// 0055b183  5b                   pop ebx
// 0055b184  5d                   pop ebp
// 0055b185  5e                   pop esi
// 0055b186  81c4a0000000         add esp, 0xa0
// 0055b18c  c3                   ret 
// 0055b18d  8b4668               mov eax, dword ptr [esi + 0x68]
// 0055b190  a801                 test al, 1
// 0055b192  7507                 jne 0x55b19b
// 0055b194  688026a800           push 0xa82680
// 0055b199  eb12                 jmp 0x55b1ad
// 0055b19b  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 0055b1a2  7512                 jne 0x55b1b6
// 0055b1a4  a802                 test al, 2
// 0055b1a6  750e                 jne 0x55b1b6
// 0055b1a8  686426a800           push 0xa82664
// 0055b1ad  56                   push esi
// 0055b1ae  e87d610000           call 0x561330
// 0055b1b3  83c408               add esp, 8
// 0055b1b6  834e6804             or dword ptr [esi + 0x68], 4
// 0055b1ba  89be0c010000         mov dword ptr [esi + 0x10c], edi
// 0055b1c0  5f                   pop edi
// 0055b1c1  5b                   pop ebx
// 0055b1c2  5d                   pop ebp
// 0055b1c3  5e                   pop esi
// 0055b1c4  81c4a0000000         add esp, 0xa0
// 0055b1ca  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
