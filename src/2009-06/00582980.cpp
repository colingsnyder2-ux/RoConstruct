// from server: 100% by auto
// roc 2009-06 00582980  unit: seg_00580000  size: 1467 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00582980
//
// 00582980  81eca0000000         sub esp, 0xa0
// 00582986  56                   push esi
// 00582987  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 0058298e  85f6                 test esi, esi
// 00582990  0f849d050000         je 0x582f33
// 00582996  55                   push ebp
// 00582997  8bac24b0000000       mov ebp, dword ptr [esp + 0xb0]
// 0058299e  85ed                 test ebp, ebp
// 005829a0  0f848c050000         je 0x582f32
// 005829a6  8a862c010000         mov al, byte ptr [esi + 0x12c]
// 005829ac  53                   push ebx
// 005829ad  57                   push edi
// 005829ae  3c08                 cmp al, 8
// 005829b0  7367                 jae 0x582a19
// 005829b2  0fb6d8               movzx ebx, al
// 005829b5  bf08000000           mov edi, 8
// 005829ba  2bfb                 sub edi, ebx
// 005829bc  57                   push edi
// 005829bd  8d442b20             lea eax, [ebx + ebp + 0x20]
// 005829c1  50                   push eax
// 005829c2  56                   push esi
// 005829c3  e838630000           call 0x588d00
// 005829c8  57                   push edi
// 005829c9  83c520               add ebp, 0x20
// 005829cc  53                   push ebx
// 005829cd  55                   push ebp
// 005829ce  c6862c01000008       mov byte ptr [esi + 0x12c], 8
// 005829d5  e856edffff           call 0x581730
// 005829da  83c418               add esp, 0x18
// 005829dd  85c0                 test eax, eax
// 005829df  742c                 je 0x582a0d
// 005829e1  83fb04               cmp ebx, 4
// 005829e4  7319                 jae 0x5829ff
// 005829e6  83c7fc               add edi, -4
// 005829e9  57                   push edi
// 005829ea  53                   push ebx
// 005829eb  55                   push ebp
// 005829ec  e83fedffff           call 0x581730
// 005829f1  83c40c               add esp, 0xc
// 005829f4  85c0                 test eax, eax
// 005829f6  7407                 je 0x5829ff
// 005829f8  6850df8c00           push 0x8cdf50
// 005829fd  eb05                 jmp 0x582a04
// 005829ff  6828df8c00           push 0x8cdf28
// 00582a04  56                   push esi
// 00582a05  e856b70000           call 0x58e160
// 00582a0a  83c408               add esp, 8
// 00582a0d  83fb03               cmp ebx, 3
// 00582a10  7307                 jae 0x582a19
// 00582a12  814e6800100000       or dword ptr [esi + 0x68], 0x1000
// 00582a19  b373                 mov bl, 0x73
// 00582a1b  eb03                 jmp 0x582a20
// 00582a1d  8d4900               lea ecx, [ecx]
// 00582a20  c68424a000000049     mov byte ptr [esp + 0xa0], 0x49
// 00582a28  c68424a100000048     mov byte ptr [esp + 0xa1], 0x48
// 00582a30  c68424a200000044     mov byte ptr [esp + 0xa2], 0x44
// 00582a38  c68424a300000052     mov byte ptr [esp + 0xa3], 0x52
// 00582a40  c644246049           mov byte ptr [esp + 0x60], 0x49
// 00582a45  c644246144           mov byte ptr [esp + 0x61], 0x44
// 00582a4a  c644246241           mov byte ptr [esp + 0x62], 0x41
// 00582a4f  c644246354           mov byte ptr [esp + 0x63], 0x54
// 00582a54  c644243049           mov byte ptr [esp + 0x30], 0x49
// 00582a59  c644243145           mov byte ptr [esp + 0x31], 0x45
// 00582a5e  c64424324e           mov byte ptr [esp + 0x32], 0x4e
// 00582a63  c644243344           mov byte ptr [esp + 0x33], 0x44
// 00582a68  c644241050           mov byte ptr [esp + 0x10], 0x50
// 00582a6d  c64424114c           mov byte ptr [esp + 0x11], 0x4c
// 00582a72  c644241254           mov byte ptr [esp + 0x12], 0x54
// 00582a77  c644241345           mov byte ptr [esp + 0x13], 0x45
// 00582a7c  c644247062           mov byte ptr [esp + 0x70], 0x62
// 00582a81  c64424714b           mov byte ptr [esp + 0x71], 0x4b
// 00582a86  c644247247           mov byte ptr [esp + 0x72], 0x47
// 00582a8b  c644247344           mov byte ptr [esp + 0x73], 0x44
// 00582a90  c644244063           mov byte ptr [esp + 0x40], 0x63
// 00582a95  c644244148           mov byte ptr [esp + 0x41], 0x48
// 00582a9a  c644244252           mov byte ptr [esp + 0x42], 0x52
// 00582a9f  c64424434d           mov byte ptr [esp + 0x43], 0x4d
// 00582aa4  c684249000000067     mov byte ptr [esp + 0x90], 0x67
// 00582aac  c684249100000041     mov byte ptr [esp + 0x91], 0x41
// 00582ab4  c68424920000004d     mov byte ptr [esp + 0x92], 0x4d
// 00582abc  c684249300000041     mov byte ptr [esp + 0x93], 0x41
// 00582ac4  c644245068           mov byte ptr [esp + 0x50], 0x68
// 00582ac9  c644245149           mov byte ptr [esp + 0x51], 0x49
// 00582ace  c644245253           mov byte ptr [esp + 0x52], 0x53
// 00582ad3  c644245354           mov byte ptr [esp + 0x53], 0x54
// 00582ad8  c644245869           mov byte ptr [esp + 0x58], 0x69
// 00582add  c644245943           mov byte ptr [esp + 0x59], 0x43
// 00582ae2  c644245a43           mov byte ptr [esp + 0x5a], 0x43
// 00582ae7  c644245b50           mov byte ptr [esp + 0x5b], 0x50
// 00582aec  c68424800000006f     mov byte ptr [esp + 0x80], 0x6f
// 00582af4  c684248100000046     mov byte ptr [esp + 0x81], 0x46
// 00582afc  c684248200000046     mov byte ptr [esp + 0x82], 0x46
// 00582b04  889c2483000000       mov byte ptr [esp + 0x83], bl
// 00582b0b  c644241870           mov byte ptr [esp + 0x18], 0x70
// 00582b10  c644241943           mov byte ptr [esp + 0x19], 0x43
// 00582b15  c644241a41           mov byte ptr [esp + 0x1a], 0x41
// 00582b1a  c644241b4c           mov byte ptr [esp + 0x1b], 0x4c
// 00582b1f  c644242870           mov byte ptr [esp + 0x28], 0x70
// 00582b24  c644242948           mov byte ptr [esp + 0x29], 0x48
// 00582b29  c644242a59           mov byte ptr [esp + 0x2a], 0x59
// 00582b2e  885c242b             mov byte ptr [esp + 0x2b], bl
// 00582b32  885c2438             mov byte ptr [esp + 0x38], bl
// 00582b36  c644243942           mov byte ptr [esp + 0x39], 0x42
// 00582b3b  c644243a49           mov byte ptr [esp + 0x3a], 0x49
// 00582b40  c644243b54           mov byte ptr [esp + 0x3b], 0x54
// 00582b45  885c2420             mov byte ptr [esp + 0x20], bl
// 00582b49  c644242143           mov byte ptr [esp + 0x21], 0x43
// 00582b4e  c644242241           mov byte ptr [esp + 0x22], 0x41
// 00582b53  c64424234c           mov byte ptr [esp + 0x23], 0x4c
// 00582b58  885c2468             mov byte ptr [esp + 0x68], bl
// 00582b5c  c644246950           mov byte ptr [esp + 0x69], 0x50
// 00582b61  c644246a4c           mov byte ptr [esp + 0x6a], 0x4c
// 00582b66  c644246b54           mov byte ptr [esp + 0x6b], 0x54
// 00582b6b  885c2448             mov byte ptr [esp + 0x48], bl
// 00582b6f  c644244952           mov byte ptr [esp + 0x49], 0x52
// 00582b74  c644244a47           mov byte ptr [esp + 0x4a], 0x47
// 00582b79  c644244b42           mov byte ptr [esp + 0x4b], 0x42
// 00582b7e  c644247874           mov byte ptr [esp + 0x78], 0x74
// 00582b83  c644247945           mov byte ptr [esp + 0x79], 0x45
// 00582b88  c644247a58           mov byte ptr [esp + 0x7a], 0x58
// 00582b8d  c644247b74           mov byte ptr [esp + 0x7b], 0x74
// 00582b92  c684248800000074     mov byte ptr [esp + 0x88], 0x74
// 00582b9a  c684248900000049     mov byte ptr [esp + 0x89], 0x49
// 00582ba2  c684248a0000004d     mov byte ptr [esp + 0x8a], 0x4d
// 00582baa  c684248b00000045     mov byte ptr [esp + 0x8b], 0x45
// 00582bb2  c684249800000074     mov byte ptr [esp + 0x98], 0x74
// 00582bba  c684249900000052     mov byte ptr [esp + 0x99], 0x52
// 00582bc2  c684249a0000004e     mov byte ptr [esp + 0x9a], 0x4e
// 00582bca  c684249b00000053     mov byte ptr [esp + 0x9b], 0x53
// 00582bd2  c68424a80000007a     mov byte ptr [esp + 0xa8], 0x7a
// 00582bda  c68424a900000054     mov byte ptr [esp + 0xa9], 0x54
// 00582be2  c68424aa00000058     mov byte ptr [esp + 0xaa], 0x58
// 00582bea  c68424ab00000074     mov byte ptr [esp + 0xab], 0x74
// 00582bf2  56                   push esi
// 00582bf3  e8581f0100           call 0x594b50
// 00582bf8  8b6c2464             mov ebp, dword ptr [esp + 0x64]
// 00582bfc  8d8e1c010000         lea ecx, [esi + 0x11c]
// 00582c02  83c404               add esp, 4
// 00582c05  8bf8                 mov edi, eax
// 00582c07  3929                 cmp dword ptr [ecx], ebp
// 00582c09  750f                 jne 0x582c1a
// 00582c0b  8b4668               mov eax, dword ptr [esi + 0x68]
// 00582c0e  a808                 test al, 8
// 00582c10  7408                 je 0x582c1a
// 00582c12  0d00200000           or eax, 0x2000
// 00582c17  894668               mov dword ptr [esi + 0x68], eax
// 00582c1a  8b01                 mov eax, dword ptr [ecx]
// 00582c1c  3b8424a0000000       cmp eax, dword ptr [esp + 0xa0]
// 00582c23  7517                 jne 0x582c3c
// 00582c25  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 00582c2c  57                   push edi
// 00582c2d  51                   push ecx
// 00582c2e  56                   push esi
// 00582c2f  e87c200100           call 0x594cb0
// 00582c34  83c40c               add esp, 0xc
// 00582c37  e9e4fdffff           jmp 0x582a20
// 00582c3c  3b442430             cmp eax, dword ptr [esp + 0x30]
// 00582c40  7517                 jne 0x582c59
// 00582c42  8b9424b8000000       mov edx, dword ptr [esp + 0xb8]
// 00582c49  57                   push edi
// 00582c4a  52                   push edx
// 00582c4b  56                   push esi
// 00582c4c  e8bf230100           call 0x595010
// 00582c51  83c40c               add esp, 0xc
// 00582c54  e9c7fdffff           jmp 0x582a20
// 00582c59  51                   push ecx
// 00582c5a  56                   push esi
// 00582c5b  e8d0f0ffff           call 0x581d30
// 00582c60  83c408               add esp, 8
// 00582c63  85c0                 test eax, eax
// 00582c65  745f                 je 0x582cc6
// 00582c67  39ae1c010000         cmp dword ptr [esi + 0x11c], ebp
// 00582c6d  7504                 jne 0x582c73
// 00582c6f  834e6804             or dword ptr [esi + 0x68], 4
// 00582c73  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 00582c7a  57                   push edi
// 00582c7b  50                   push eax
// 00582c7c  56                   push esi
// 00582c7d  e82e430100           call 0x596fb0
// 00582c82  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00582c88  83c40c               add esp, 0xc
// 00582c8b  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00582c8f  7509                 jne 0x582c9a
// 00582c91  834e6802             or dword ptr [esi + 0x68], 2
// 00582c95  e986fdffff           jmp 0x582a20
// 00582c9a  3bc5                 cmp eax, ebp
// 00582c9c  0f857efdffff         jne 0x582a20
// 00582ca2  8b4668               mov eax, dword ptr [esi + 0x68]
// 00582ca5  a801                 test al, 1
// 00582ca7  0f852a020000         jne 0x582ed7
// 00582cad  680cdf8c00           push 0x8cdf0c
// 00582cb2  56                   push esi
// 00582cb3  e8a8b40000           call 0x58e160
// 00582cb8  83c408               add esp, 8
// 00582cbb  5f                   pop edi
// 00582cbc  5b                   pop ebx
// 00582cbd  5d                   pop ebp
// 00582cbe  5e                   pop esi
// 00582cbf  81c4a0000000         add esp, 0xa0
// 00582cc5  c3                   ret 
// 00582cc6  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00582ccc  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00582cd0  7517                 jne 0x582ce9
// 00582cd2  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 00582cd9  57                   push edi
// 00582cda  51                   push ecx
// 00582cdb  56                   push esi
// 00582cdc  e88f210100           call 0x594e70
// 00582ce1  83c40c               add esp, 0xc
// 00582ce4  e937fdffff           jmp 0x582a20
// 00582ce9  3bc5                 cmp eax, ebp
// 00582ceb  0f840c020000         je 0x582efd
// 00582cf1  57                   push edi
// 00582cf2  3b442474             cmp eax, dword ptr [esp + 0x74]
// 00582cf6  7516                 jne 0x582d0e
// 00582cf8  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00582cff  52                   push edx
// 00582d00  56                   push esi
// 00582d01  e8ba330100           call 0x5960c0
// 00582d06  83c40c               add esp, 0xc
// 00582d09  e912fdffff           jmp 0x582a20
// 00582d0e  3b442444             cmp eax, dword ptr [esp + 0x44]
// 00582d12  7516                 jne 0x582d2a
// 00582d14  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00582d1b  50                   push eax
// 00582d1c  56                   push esi
// 00582d1d  e84e260100           call 0x595370
// 00582d22  83c40c               add esp, 0xc
// 00582d25  e9f6fcffff           jmp 0x582a20
// 00582d2a  3b842494000000       cmp eax, dword ptr [esp + 0x94]
// 00582d31  7516                 jne 0x582d49
// 00582d33  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00582d3a  51                   push ecx
// 00582d3b  56                   push esi
// 00582d3c  e81f230100           call 0x595060
// 00582d41  83c40c               add esp, 0xc
// 00582d44  e9d7fcffff           jmp 0x582a20
// 00582d49  3b442454             cmp eax, dword ptr [esp + 0x54]
// 00582d4d  7516                 jne 0x582d65
// 00582d4f  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00582d56  52                   push edx
// 00582d57  56                   push esi
// 00582d58  e883350100           call 0x5962e0
// 00582d5d  83c40c               add esp, 0xc
// 00582d60  e9bbfcffff           jmp 0x582a20
// 00582d65  3b842484000000       cmp eax, dword ptr [esp + 0x84]
// 00582d6c  7516                 jne 0x582d84
// 00582d6e  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00582d75  50                   push eax
// 00582d76  56                   push esi
// 00582d77  e804380100           call 0x596580
// 00582d7c  83c40c               add esp, 0xc
// 00582d7f  e99cfcffff           jmp 0x582a20
// 00582d84  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 00582d88  7516                 jne 0x582da0
// 00582d8a  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00582d91  51                   push ecx
// 00582d92  56                   push esi
// 00582d93  e808390100           call 0x5966a0
// 00582d98  83c40c               add esp, 0xc
// 00582d9b  e980fcffff           jmp 0x582a20
// 00582da0  3b442424             cmp eax, dword ptr [esp + 0x24]
// 00582da4  7516                 jne 0x582dbc
// 00582da6  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00582dad  52                   push edx
// 00582dae  56                   push esi
// 00582daf  e8ec3b0100           call 0x5969a0
// 00582db4  83c40c               add esp, 0xc
// 00582db7  e964fcffff           jmp 0x582a20
// 00582dbc  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 00582dc0  7516                 jne 0x582dd8
// 00582dc2  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00582dc9  50                   push eax
// 00582dca  56                   push esi
// 00582dcb  e890360100           call 0x596460
// 00582dd0  83c40c               add esp, 0xc
// 00582dd3  e948fcffff           jmp 0x582a20
// 00582dd8  3b44243c             cmp eax, dword ptr [esp + 0x3c]
// 00582ddc  7516                 jne 0x582df4
// 00582dde  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00582de5  51                   push ecx
// 00582de6  56                   push esi
// 00582de7  e804240100           call 0x5951f0
// 00582dec  83c40c               add esp, 0xc
// 00582def  e92cfcffff           jmp 0x582a20
// 00582df4  3b44244c             cmp eax, dword ptr [esp + 0x4c]
// 00582df8  7516                 jne 0x582e10
// 00582dfa  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00582e01  52                   push edx
// 00582e02  56                   push esi
// 00582e03  e898290100           call 0x5957a0
// 00582e08  83c40c               add esp, 0xc
// 00582e0b  e910fcffff           jmp 0x582a20
// 00582e10  3b44245c             cmp eax, dword ptr [esp + 0x5c]
// 00582e14  7516                 jne 0x582e2c
// 00582e16  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00582e1d  50                   push eax
// 00582e1e  56                   push esi
// 00582e1f  e88c2b0100           call 0x5959b0
// 00582e24  83c40c               add esp, 0xc
// 00582e27  e9f4fbffff           jmp 0x582a20
// 00582e2c  3b44246c             cmp eax, dword ptr [esp + 0x6c]
// 00582e30  7516                 jne 0x582e48
// 00582e32  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00582e39  51                   push ecx
// 00582e3a  56                   push esi
// 00582e3b  e8702d0100           call 0x595bb0
// 00582e40  83c40c               add esp, 0xc
// 00582e43  e9d8fbffff           jmp 0x582a20
// 00582e48  3b44247c             cmp eax, dword ptr [esp + 0x7c]
// 00582e4c  7516                 jne 0x582e64
// 00582e4e  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00582e55  52                   push edx
// 00582e56  56                   push esi
// 00582e57  e8743e0100           call 0x596cd0
// 00582e5c  83c40c               add esp, 0xc
// 00582e5f  e9bcfbffff           jmp 0x582a20
// 00582e64  3b84248c000000       cmp eax, dword ptr [esp + 0x8c]
// 00582e6b  7516                 jne 0x582e83
// 00582e6d  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00582e74  50                   push eax
// 00582e75  56                   push esi
// 00582e76  e8453d0100           call 0x596bc0
// 00582e7b  83c40c               add esp, 0xc
// 00582e7e  e99dfbffff           jmp 0x582a20
// 00582e83  3b84249c000000       cmp eax, dword ptr [esp + 0x9c]
// 00582e8a  7516                 jne 0x582ea2
// 00582e8c  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00582e93  51                   push ecx
// 00582e94  56                   push esi
// 00582e95  e8b62f0100           call 0x595e50
// 00582e9a  83c40c               add esp, 0xc
// 00582e9d  e97efbffff           jmp 0x582a20
// 00582ea2  3b8424ac000000       cmp eax, dword ptr [esp + 0xac]
// 00582ea9  7516                 jne 0x582ec1
// 00582eab  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00582eb2  52                   push edx
// 00582eb3  56                   push esi
// 00582eb4  e8373f0100           call 0x596df0
// 00582eb9  83c40c               add esp, 0xc
// 00582ebc  e95ffbffff           jmp 0x582a20
// 00582ec1  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00582ec8  50                   push eax
// 00582ec9  56                   push esi
// 00582eca  e8e1400100           call 0x596fb0
// 00582ecf  83c40c               add esp, 0xc
// 00582ed2  e949fbffff           jmp 0x582a20
// 00582ed7  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00582ede  7550                 jne 0x582f30
// 00582ee0  a802                 test al, 2
// 00582ee2  754c                 jne 0x582f30
// 00582ee4  68f0de8c00           push 0x8cdef0
// 00582ee9  56                   push esi
// 00582eea  e871b20000           call 0x58e160
// 00582eef  83c408               add esp, 8
// 00582ef2  5f                   pop edi
// 00582ef3  5b                   pop ebx
// 00582ef4  5d                   pop ebp
// 00582ef5  5e                   pop esi
// 00582ef6  81c4a0000000         add esp, 0xa0
// 00582efc  c3                   ret 
// 00582efd  8b4668               mov eax, dword ptr [esi + 0x68]
// 00582f00  a801                 test al, 1
// 00582f02  7507                 jne 0x582f0b
// 00582f04  680cdf8c00           push 0x8cdf0c
// 00582f09  eb12                 jmp 0x582f1d
// 00582f0b  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00582f12  7512                 jne 0x582f26
// 00582f14  a802                 test al, 2
// 00582f16  750e                 jne 0x582f26
// 00582f18  68f0de8c00           push 0x8cdef0
// 00582f1d  56                   push esi
// 00582f1e  e83db20000           call 0x58e160
// 00582f23  83c408               add esp, 8
// 00582f26  834e6804             or dword ptr [esi + 0x68], 4
// 00582f2a  89be0c010000         mov dword ptr [esi + 0x10c], edi
// 00582f30  5f                   pop edi
// 00582f31  5b                   pop ebx
// 00582f32  5d                   pop ebp
// 00582f33  5e                   pop esi
// 00582f34  81c4a0000000         add esp, 0xa0
// 00582f3a  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
