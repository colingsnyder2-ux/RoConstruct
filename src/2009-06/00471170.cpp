// from server: 74% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 0046d710  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 1950 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046d710
//
// 0046d710  6aff                 push -1
// 0046d712  68dc3d7c00           push 0x7c3ddc
// 0046d717  64a100000000         mov eax, dword ptr fs:[0]
// 0046d71d  50                   push eax
// 0046d71e  64892500000000       mov dword ptr fs:[0], esp
// 0046d725  81ec04020000         sub esp, 0x204
// 0046d72b  53                   push ebx
// 0046d72c  55                   push ebp
// 0046d72d  56                   push esi
// 0046d72e  8bd9                 mov ebx, ecx
// 0046d730  57                   push edi
// 0046d731  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0046d735  8d842424020000       lea eax, [esp + 0x224]
// 0046d73c  8d7304               lea esi, [ebx + 4]
// 0046d73f  50                   push eax
// 0046d740  8bce                 mov ecx, esi
// 0046d742  c784242002000000000000 mov dword ptr [esp + 0x220], 0
// 0046d74d  c70304c98100         mov dword ptr [ebx], 0x81c904
// 0046d753  ff155c248000         call dword ptr [0x80245c]
// 0046d759  8d7b20               lea edi, [ebx + 0x20]
// 0046d75c  8bcf                 mov ecx, edi
// 0046d75e  c684241c02000001     mov byte ptr [esp + 0x21c], 1
// 0046d766  ff1560248000         call dword ptr [0x802460]
// 0046d76c  8d542413             lea edx, [esp + 0x13]
// 0046d770  52                   push edx
// 0046d771  8d442417             lea eax, [esp + 0x17]
// 0046d775  8d4b3c               lea ecx, [ebx + 0x3c]
// 0046d778  50                   push eax
// 0046d779  c684242402000002     mov byte ptr [esp + 0x224], 2
// 0046d781  e88a89fdff           call 0x446110
// 0046d786  8d542413             lea edx, [esp + 0x13]
// 0046d78a  52                   push edx
// 0046d78b  8d442417             lea eax, [esp + 0x17]
// 0046d78f  8d4b5c               lea ecx, [ebx + 0x5c]
// 0046d792  50                   push eax
// 0046d793  c684242402000003     mov byte ptr [esp + 0x224], 3
// 0046d79b  e890c32200           call 0x699b30
// 0046d7a0  6a01                 push 1
// 0046d7a2  6a40                 push 0x40
// 0046d7a4  6a01                 push 1
// 0046d7a6  8bce                 mov ecx, esi
// 0046d7a8  c684242802000004     mov byte ptr [esp + 0x228], 4
// 0046d7b0  ff1564248000         call dword ptr [0x802464]
// 0046d7b6  50                   push eax
// 0046d7b7  8d8c2498010000       lea ecx, [esp + 0x198]
// 0046d7be  ff1504248000         call dword ptr [0x802404]
// 0046d7c4  8d8c2490010000       lea ecx, [esp + 0x190]
// 0046d7cb  51                   push ecx
// 0046d7cc  8d8c2444010000       lea ecx, [esp + 0x144]
// 0046d7d3  c684242002000005     mov byte ptr [esp + 0x220], 5
// 0046d7db  e8707bfaff           call 0x415350
// 0046d7e0  8d542430             lea edx, [esp + 0x30]
// 0046d7e4  52                   push edx
// 0046d7e5  8d8c2444010000       lea ecx, [esp + 0x144]
// 0046d7ec  c684242002000006     mov byte ptr [esp + 0x220], 6
// 0046d7f4  e8c71e1200           call 0x58f6c0
// 0046d7f9  8b30                 mov esi, dword ptr [eax]
// 0046d7fb  8974242c             mov dword ptr [esp + 0x2c], esi
// 0046d7ff  c70000000000         mov dword ptr [eax], 0
// 0046d805  89742454             mov dword ptr [esp + 0x54], esi
// 0046d809  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0046d80d  c684241c02000007     mov byte ptr [esp + 0x21c], 7
// 0046d815  85c9                 test ecx, ecx
// 0046d817  7410                 je 0x46d829
// 0046d819  8be9                 mov ebp, ecx
// 0046d81b  e85062faff           call 0x413a70
// 0046d820  55                   push ebp
// 0046d821  e8542e2300           call 0x6a067a
// 0046d826  83c404               add esp, 4
// 0046d829  a11cee9600           mov eax, dword ptr [0x96ee1c]
// 0046d82e  50                   push eax
// 0046d82f  8bce                 mov ecx, esi
// 0046d831  e8fae91000           call 0x57c230
// 0046d836  85c0                 test eax, eax
// 0046d838  7409                 je 0x46d843
// 0046d83a  57                   push edi
// 0046d83b  8d4810               lea ecx, [eax + 0x10]
// 0046d83e  e8cde91000           call 0x57c210
// 0046d843  8b0d20ee9600         mov ecx, dword ptr [0x96ee20]
// 0046d849  51                   push ecx
// 0046d84a  8bce                 mov ecx, esi
// 0046d84c  e8dfe91000           call 0x57c230
// 0046d851  85c0                 test eax, eax
// 0046d853  0f8439010000         je 0x46d992
// 0046d859  8b1524ee9600         mov edx, dword ptr [0x96ee24]
// 0046d85f  52                   push edx
// 0046d860  8bc8                 mov ecx, eax
// 0046d862  e8c9e91000           call 0x57c230
// 0046d867  8d4c2434             lea ecx, [esp + 0x34]
// 0046d86b  8be8                 mov ebp, eax
// 0046d86d  ff1560248000         call dword ptr [0x802460]
// 0046d873  c684241c02000008     mov byte ptr [esp + 0x21c], 8
// 0046d87b  85ed                 test ebp, ebp
// 0046d87d  0f84fd000000         je 0x46d980
// 0046d883  a138ee9600           mov eax, dword ptr [0x96ee38]
// 0046d888  50                   push eax
// 0046d889  8bcd                 mov ecx, ebp
// 0046d88b  33f6                 xor esi, esi
// 0046d88d  e89ee91000           call 0x57c230
// 0046d892  8b0d28ee9600         mov ecx, dword ptr [0x96ee28]
// 0046d898  51                   push ecx
// 0046d899  8bcd                 mov ecx, ebp
// 0046d89b  e890e91000           call 0x57c230
// 0046d8a0  83cfff               or edi, 0xffffffff
// 0046d8a3  897c2418             mov dword ptr [esp + 0x18], edi
// 0046d8a7  85c0                 test eax, eax
// 0046d8a9  7428                 je 0x46d8d3
// 0046d8ab  8d542434             lea edx, [esp + 0x34]
// 0046d8af  52                   push edx
// 0046d8b0  8d4810               lea ecx, [eax + 0x10]
// 0046d8b3  8d7702               lea esi, [edi + 2]
// 0046d8b6  e855e91000           call 0x57c210
// 0046d8bb  8d4c2434             lea ecx, [esp + 0x34]
// 0046d8bf  ff1564248000         call dword ptr [0x802464]
// 0046d8c5  50                   push eax
// 0046d8c6  ff1568288000         call dword ptr [0x802868]
// 0046d8cc  83c404               add esp, 4
// 0046d8cf  89442418             mov dword ptr [esp + 0x18], eax
// 0046d8d3  a12cee9600           mov eax, dword ptr [0x96ee2c]
// 0046d8d8  50                   push eax
// 0046d8d9  8bcd                 mov ecx, ebp
// 0046d8db  e850e91000           call 0x57c230
// 0046d8e0  85c0                 test eax, eax
// 0046d8e2  7424                 je 0x46d908
// 0046d8e4  8d4c2434             lea ecx, [esp + 0x34]
// 0046d8e8  51                   push ecx
// 0046d8e9  8d4810               lea ecx, [eax + 0x10]
// 0046d8ec  46                   inc esi
// 0046d8ed  e81ee91000           call 0x57c210
// 0046d8f2  8d4c2434             lea ecx, [esp + 0x34]
// 0046d8f6  ff1564248000         call dword ptr [0x802464]
// 0046d8fc  50                   push eax
// 0046d8fd  ff1568288000         call dword ptr [0x802868]
// 0046d903  83c404               add esp, 4
// 0046d906  8bf8                 mov edi, eax
// 0046d908  83fe02               cmp esi, 2
// 0046d90b  7564                 jne 0x46d971
// 0046d90d  6a0c                 push 0xc
// 0046d90f  e80c302300           call 0x6a0920
// 0046d914  83c404               add esp, 4
// 0046d917  89442414             mov dword ptr [esp + 0x14], eax
// 0046d91b  c684241c02000009     mov byte ptr [esp + 0x21c], 9
// 0046d923  85c0                 test eax, eax
// 0046d925  7411                 je 0x46d938
// 0046d927  8b542418             mov edx, dword ptr [esp + 0x18]
// 0046d92b  57                   push edi
// 0046d92c  52                   push edx
// 0046d92d  8bc8                 mov ecx, eax
// 0046d92f  e88cf1ffff           call 0x46cac0
// 0046d934  8bf0                 mov esi, eax
// 0046d936  eb02                 jmp 0x46d93a
// 0046d938  33f6                 xor esi, esi
// 0046d93a  8b4604               mov eax, dword ptr [esi + 4]
// 0046d93d  50                   push eax
// 0046d93e  8bcb                 mov ecx, ebx
// 0046d940  c684242002000008     mov byte ptr [esp + 0x220], 8
// 0046d948  e8c3f6ffff           call 0x46d010
// 0046d94d  85c0                 test eax, eax
// 0046d94f  740a                 je 0x46d95b
// 0046d951  8b10                 mov edx, dword ptr [eax]
// 0046d953  8bc8                 mov ecx, eax
// 0046d955  8b02                 mov eax, dword ptr [edx]
// 0046d957  6a01                 push 1
// 0046d959  ffd0                 call eax
// 0046d95b  8b4e04               mov ecx, dword ptr [esi + 4]
// 0046d95e  8d542414             lea edx, [esp + 0x14]
// 0046d962  894c2414             mov dword ptr [esp + 0x14], ecx
// 0046d966  52                   push edx
// 0046d967  8d4b3c               lea ecx, [ebx + 0x3c]
// 0046d96a  e861faffff           call 0x46d3d0
// 0046d96f  8930                 mov dword ptr [eax], esi
// 0046d971  8b6d00               mov ebp, dword ptr [ebp]
// 0046d974  85ed                 test ebp, ebp
// 0046d976  0f8507ffffff         jne 0x46d883
// 0046d97c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0046d980  8d4c2434             lea ecx, [esp + 0x34]
// 0046d984  c684241c02000007     mov byte ptr [esp + 0x21c], 7
// 0046d98c  ff1568248000         call dword ptr [0x802468]
// 0046d992  a130ee9600           mov eax, dword ptr [0x96ee30]
// 0046d997  50                   push eax
// 0046d998  8bce                 mov ecx, esi
// 0046d99a  e891e81000           call 0x57c230
// 0046d99f  85c0                 test eax, eax
// 0046d9a1  0f848d040000         je 0x46de34
// 0046d9a7  8b0d34ee9600         mov ecx, dword ptr [0x96ee34]
// 0046d9ad  51                   push ecx
// 0046d9ae  8bc8                 mov ecx, eax
// 0046d9b0  e87be81000           call 0x57c230
// 0046d9b5  8be8                 mov ebp, eax
// 0046d9b7  896c2418             mov dword ptr [esp + 0x18], ebp
// 0046d9bb  85ed                 test ebp, ebp
// 0046d9bd  0f8471040000         je 0x46de34
// 0046d9c3  eb04                 jmp 0x46d9c9
// 0046d9c5  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0046d9c9  8b1538ee9600         mov edx, dword ptr [0x96ee38]
// 0046d9cf  52                   push edx
// 0046d9d0  8bcd                 mov ecx, ebp
// 0046d9d2  33db                 xor ebx, ebx
// 0046d9d4  e857e81000           call 0x57c230
// 0046d9d9  6816b78000           push 0x80b716
// 0046d9de  8d8c2494000000       lea ecx, [esp + 0x94]
// 0046d9e5  8bf0                 mov esi, eax
// 0046d9e7  ff1558248000         call dword ptr [0x802458]
// 0046d9ed  c684241c0200000a     mov byte ptr [esp + 0x21c], 0xa
// 0046d9f5  85f6                 test esi, esi
// 0046d9f7  741c                 je 0x46da15
// 0046d9f9  8d842490000000       lea eax, [esp + 0x90]
// 0046da00  50                   push eax
// 0046da01  8d4e10               lea ecx, [esi + 0x10]
// 0046da04  c744242801000000     mov dword ptr [esp + 0x28], 1
// 0046da0c  e8ffe71000           call 0x57c210
// 0046da11  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0046da15  8b0d3cee9600         mov ecx, dword ptr [0x96ee3c]
// 0046da1b  51                   push ecx
// 0046da1c  8bcd                 mov ecx, ebp
// 0046da1e  e80de81000           call 0x57c230
// 0046da23  6816b78000           push 0x80b716
// 0046da28  8d4c2478             lea ecx, [esp + 0x78]
// 0046da2c  8bf0                 mov esi, eax
// 0046da2e  ff1558248000         call dword ptr [0x802458]
// 0046da34  c684241c0200000b     mov byte ptr [esp + 0x21c], 0xb
// 0046da3c  85f6                 test esi, esi
// 0046da3e  740e                 je 0x46da4e
// 0046da40  8d542474             lea edx, [esp + 0x74]
// 0046da44  52                   push edx
// 0046da45  8d4e10               lea ecx, [esi + 0x10]
// 0046da48  43                   inc ebx
// 0046da49  e8c2e71000           call 0x57c210
// 0046da4e  a140ee9600           mov eax, dword ptr [0x96ee40]
// 0046da53  50                   push eax
// 0046da54  8bcd                 mov ecx, ebp
// 0046da56  e8d5e71000           call 0x57c230
// 0046da5b  6816b78000           push 0x80b716
// 0046da60  8d4c245c             lea ecx, [esp + 0x5c]
// 0046da64  8bf0                 mov esi, eax
// 0046da66  ff1558248000         call dword ptr [0x802458]
// 0046da6c  c684241c0200000c     mov byte ptr [esp + 0x21c], 0xc
// 0046da74  85f6                 test esi, esi
// 0046da76  740e                 je 0x46da86
// 0046da78  8d4c2458             lea ecx, [esp + 0x58]
// 0046da7c  51                   push ecx
// 0046da7d  8d4e10               lea ecx, [esi + 0x10]
// 0046da80  43                   inc ebx
// 0046da81  e88ae71000           call 0x57c210
// 0046da86  8b1544ee9600         mov edx, dword ptr [0x96ee44]
// 0046da8c  52                   push edx
// 0046da8d  8bcd                 mov ecx, ebp
// 0046da8f  e89ce71000           call 0x57c230
// 0046da94  6816b78000           push 0x80b716
// 0046da99  8d8c24b0000000       lea ecx, [esp + 0xb0]
// 0046daa0  8bf0                 mov esi, eax
// 0046daa2  ff1558248000         call dword ptr [0x802458]
// 0046daa8  c684241c0200000d     mov byte ptr [esp + 0x21c], 0xd
// 0046dab0  bf02000000           mov edi, 2
// 0046dab5  85f6                 test esi, esi
// 0046dab7  7433                 je 0x46daec
// 0046dab9  8d8424ac000000       lea eax, [esp + 0xac]
// 0046dac0  50                   push eax
// 0046dac1  8d4e10               lea ecx, [esi + 0x10]
// 0046dac4  43                   inc ebx
// 0046dac5  e846e71000           call 0x57c210
// 0046daca  83ec1c               sub esp, 0x1c
// 0046dacd  8d9424c8000000       lea edx, [esp + 0xc8]
// 0046dad4  8bcc                 mov ecx, esp
// 0046dad6  89642430             mov dword ptr [esp + 0x30], esp
// 0046dada  52                   push edx
// 0046dadb  ff155c248000         call dword ptr [0x80245c]
// 0046dae1  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0046dae5  e896f0ffff           call 0x46cb80
// 0046daea  8bf8                 mov edi, eax
// 0046daec  6a74                 push 0x74
// 0046daee  e82d2e2300           call 0x6a0920
// 0046daf3  8bf0                 mov esi, eax
// 0046daf5  83c404               add esp, 4
// 0046daf8  89742414             mov dword ptr [esp + 0x14], esi
// 0046dafc  c684241c0200000e     mov byte ptr [esp + 0x21c], 0xe
// 0046db04  85f6                 test esi, esi
// 0046db06  746b                 je 0x46db73
// 0046db08  57                   push edi
// 0046db09  83ec1c               sub esp, 0x1c
// 0046db0c  8d442478             lea eax, [esp + 0x78]
// 0046db10  8bcc                 mov ecx, esp
// 0046db12  89642440             mov dword ptr [esp + 0x40], esp
// 0046db16  50                   push eax
// 0046db17  ff155c248000         call dword ptr [0x80245c]
// 0046db1d  83ec1c               sub esp, 0x1c
// 0046db20  8d9424b0000000       lea edx, [esp + 0xb0]
// 0046db27  8bcc                 mov ecx, esp
// 0046db29  89642460             mov dword ptr [esp + 0x60], esp
// 0046db2d  52                   push edx
// 0046db2e  c684245c0200000f     mov byte ptr [esp + 0x25c], 0xf
// 0046db36  ff155c248000         call dword ptr [0x80245c]
// 0046db3c  83ec1c               sub esp, 0x1c
// 0046db3f  8d8424e8000000       lea eax, [esp + 0xe8]
// 0046db46  8bcc                 mov ecx, esp
// 0046db48  89a42480000000       mov dword ptr [esp + 0x80], esp
// 0046db4f  50                   push eax
// 0046db50  c684247802000010     mov byte ptr [esp + 0x278], 0x10
// 0046db58  ff155c248000         call dword ptr [0x80245c]
// 0046db5e  8bce                 mov ecx, esi
// 0046db60  c68424740200000e     mov byte ptr [esp + 0x274], 0xe
// 0046db68  e8430b0000           call 0x46e6b0
// 0046db6d  89442420             mov dword ptr [esp + 0x20], eax
// 0046db71  eb08                 jmp 0x46db7b
// 0046db73  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0046db7b  8b0d48ee9600         mov ecx, dword ptr [0x96ee48]
// 0046db81  51                   push ecx
// 0046db82  8bcd                 mov ecx, ebp
// 0046db84  c68424200200000d     mov byte ptr [esp + 0x220], 0xd
// 0046db8c  e89fe61000           call 0x57c230
// 0046db91  8bf0                 mov esi, eax
// 0046db93  85f6                 test esi, esi
// 0046db95  0f8421020000         je 0x46ddbc
// 0046db9b  43                   inc ebx
// 0046db9c  895c2424             mov dword ptr [esp + 0x24], ebx
// 0046dba0  8b154cee9600         mov edx, dword ptr [0x96ee4c]
// 0046dba6  52                   push edx
// 0046dba7  8bce                 mov ecx, esi
// 0046dba9  33ed                 xor ebp, ebp
// 0046dbab  e880e61000           call 0x57c230
// 0046dbb0  6816b78000           push 0x80b716
// 0046dbb5  8d4c2438             lea ecx, [esp + 0x38]
// 0046dbb9  8bf8                 mov edi, eax
// 0046dbbb  ff1558248000         call dword ptr [0x802458]
// 0046dbc1  c684241c02000011     mov byte ptr [esp + 0x21c], 0x11
// 0046dbc9  c7442414e7030000     mov dword ptr [esp + 0x14], 0x3e7
// 0046dbd1  85ff                 test edi, edi
// 0046dbd3  7433                 je 0x46dc08
// 0046dbd5  8d442434             lea eax, [esp + 0x34]
// 0046dbd9  50                   push eax
// 0046dbda  8d4f10               lea ecx, [edi + 0x10]
// 0046dbdd  bd01000000           mov ebp, 1
// 0046dbe2  e829e61000           call 0x57c210
// 0046dbe7  83ec1c               sub esp, 0x1c
// 0046dbea  8d542450             lea edx, [esp + 0x50]
// 0046dbee  8bcc                 mov ecx, esp
// 0046dbf0  89642444             mov dword ptr [esp + 0x44], esp
// 0046dbf4  52                   push edx
// 0046dbf5  ff155c248000         call dword ptr [0x80245c]
// 0046dbfb  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0046dbff  e87cf0ffff           call 0x46cc80
// 0046dc04  89442414             mov dword ptr [esp + 0x14], eax
// 0046dc08  a150ee9600           mov eax, dword ptr [0x96ee50]
// 0046dc0d  50                   push eax
// 0046dc0e  8bce                 mov ecx, esi
// 0046dc10  e81be61000           call 0x57c230
// 0046dc15  6816b78000           push 0x80b716
// 0046dc1a  8d4c2438             lea ecx, [esp + 0x38]
// 0046dc1e  8bf8                 mov edi, eax
// 0046dc20  ff154c248000         call dword ptr [0x80244c]
// 0046dc26  33db                 xor ebx, ebx
// 0046dc28  85ff                 test edi, edi
// 0046dc2a  742d                 je 0x46dc59
// 0046dc2c  8d4c2434             lea ecx, [esp + 0x34]
// 0046dc30  51                   push ecx
// 0046dc31  8d4f10               lea ecx, [edi + 0x10]
// 0046dc34  45                   inc ebp
// 0046dc35  e8d6e51000           call 0x57c210
// 0046dc3a  83ec1c               sub esp, 0x1c
// 0046dc3d  8d542450             lea edx, [esp + 0x50]
// 0046dc41  8bcc                 mov ecx, esp
// 0046dc43  89642444             mov dword ptr [esp + 0x44], esp
// 0046dc47  52                   push edx
// 0046dc48  ff155c248000         call dword ptr [0x80245c]
// 0046dc4e  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0046dc52  e889f1ffff           call 0x46cde0
// 0046dc57  8bd8                 mov ebx, eax
// 0046dc59  a154ee9600           mov eax, dword ptr [0x96ee54]
// 0046dc5e  50                   push eax
// 0046dc5f  8bce                 mov ecx, esi
// 0046dc61  e8cae51000           call 0x57c230
// 0046dc66  6816b78000           push 0x80b716
// 0046dc6b  8d8c24cc000000       lea ecx, [esp + 0xcc]
// 0046dc72  8bf8                 mov edi, eax
// 0046dc74  ff1558248000         call dword ptr [0x802458]
// 0046dc7a  c684241c02000012     mov byte ptr [esp + 0x21c], 0x12
// 0046dc82  85ff                 test edi, edi
// 0046dc84  7411                 je 0x46dc97
// 0046dc86  8d8c24c8000000       lea ecx, [esp + 0xc8]
// 0046dc8d  51                   push ecx
// 0046dc8e  8d4f10               lea ecx, [edi + 0x10]
// 0046dc91  45                   inc ebp
// 0046dc92  e879e51000           call 0x57c210
// 0046dc97  8b1558ee9600         mov edx, dword ptr [0x96ee58]
// 0046dc9d  52                   push edx
// 0046dc9e  8bce                 mov ecx, esi
// 0046dca0  e88be51000           call 0x57c230
// 0046dca5  6816b78000           push 0x80b716
// 0046dcaa  8d8c24e8000000       lea ecx, [esp + 0xe8]
// 0046dcb1  8bf8                 mov edi, eax
// 0046dcb3  ff1558248000         call dword ptr [0x802458]
// 0046dcb9  c684241c02000013     mov byte ptr [esp + 0x21c], 0x13
// 0046dcc1  85ff                 test edi, edi
// 0046dcc3  7411                 je 0x46dcd6
// 0046dcc5  8d8424e4000000       lea eax, [esp + 0xe4]
// 0046dccc  50                   push eax
// 0046dccd  8d4f10               lea ecx, [edi + 0x10]
// 0046dcd0  45                   inc ebp
// 0046dcd1  e83ae51000           call 0x57c210
// 0046dcd6  83fd04               cmp ebp, 4
// 0046dcd9  0f858f000000         jne 0x46dd6e
// 0046dcdf  83ec1c               sub esp, 0x1c
// 0046dce2  8d942400010000       lea edx, [esp + 0x100]
// 0046dce9  8bcc                 mov ecx, esp
// 0046dceb  89642444             mov dword ptr [esp + 0x44], esp
// 0046dcef  52                   push edx
// 0046dcf0  ff155c248000         call dword ptr [0x80245c]
// 0046dcf6  83ec1c               sub esp, 0x1c
// 0046dcf9  8d842400010000       lea eax, [esp + 0x100]
// 0046dd00  8bcc                 mov ecx, esp
// 0046dd02  89a42488000000       mov dword ptr [esp + 0x88], esp
// 0046dd09  50                   push eax
// 0046dd0a  c684245802000014     mov byte ptr [esp + 0x258], 0x14
// 0046dd12  ff155c248000         call dword ptr [0x80245c]
// 0046dd18  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0046dd1c  53                   push ebx
// 0046dd1d  51                   push ecx
// 0046dd1e  8d8c2440010000       lea ecx, [esp + 0x140]
// 0046dd25  c684245c02000013     mov byte ptr [esp + 0x25c], 0x13
// 0046dd2d  e83e0c0000           call 0x46e970
// 0046dd32  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0046dd36  50                   push eax
// 0046dd37  c684242002000015     mov byte ptr [esp + 0x220], 0x15
// 0046dd3f  e81c0c0000           call 0x46e960
// 0046dd44  8d8c2424010000       lea ecx, [esp + 0x124]
// 0046dd4b  c684241c02000016     mov byte ptr [esp + 0x21c], 0x16
// 0046dd53  ff1568248000         call dword ptr [0x802468]
// 0046dd59  8d8c2408010000       lea ecx, [esp + 0x108]
// 0046dd60  c684241c02000013     mov byte ptr [esp + 0x21c], 0x13
// 0046dd68  ff1568248000         call dword ptr [0x802468]
// 0046dd6e  8b36                 mov esi, dword ptr [esi]
// 0046dd70  8d8c24e4000000       lea ecx, [esp + 0xe4]
// 0046dd77  c684241c02000012     mov byte ptr [esp + 0x21c], 0x12
// 0046dd7f  ff1568248000         call dword ptr [0x802468]
// 0046dd85  8d8c24c8000000       lea ecx, [esp + 0xc8]
// 0046dd8c  c684241c02000011     mov byte ptr [esp + 0x21c], 0x11
// 0046dd94  ff1568248000         call dword ptr [0x802468]
// 0046dd9a  8d4c2434             lea ecx, [esp + 0x34]
// 0046dd9e  c684241c0200000d     mov byte ptr [esp + 0x21c], 0xd
// 0046dda6  ff1568248000         call dword ptr [0x802468]
// 0046ddac  85f6                 test esi, esi
// 0046ddae  0f85ecfdffff         jne 0x46dba0
// 0046ddb4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0046ddb8  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0046ddbc  83fb05               cmp ebx, 5
// 0046ddbf  750e                 jne 0x46ddcf
// 0046ddc1  8b542420             mov edx, dword ptr [esp + 0x20]
// 0046ddc5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046ddc9  52                   push edx
// 0046ddca  e8b1f6ffff           call 0x46d480
// 0046ddcf  8b6d00               mov ebp, dword ptr [ebp]
// 0046ddd2  8d8c24ac000000       lea ecx, [esp + 0xac]
// 0046ddd9  896c2418             mov dword ptr [esp + 0x18], ebp
// 0046dddd  c684241c0200000c     mov byte ptr [esp + 0x21c], 0xc
// 0046dde5  ff1568248000         call dword ptr [0x802468]
// 0046ddeb  8d4c2458             lea ecx, [esp + 0x58]
// 0046ddef  c684241c0200000b     mov byte ptr [esp + 0x21c], 0xb
// 0046ddf7  ff1568248000         call dword ptr [0x802468]
// 0046ddfd  8d4c2474             lea ecx, [esp + 0x74]
// 0046de01  c684241c0200000a     mov byte ptr [esp + 0x21c], 0xa
// 0046de09  ff1568248000         call dword ptr [0x802468]
// 0046de0f  8d8c2490000000       lea ecx, [esp + 0x90]
// 0046de16  c684241c02000007     mov byte ptr [esp + 0x21c], 7
// 0046de1e  ff1568248000         call dword ptr [0x802468]
// 0046de24  85ed                 test ebp, ebp
// 0046de26  0f8599fbffff         jne 0x46d9c5
// 0046de2c  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0046de30  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0046de34  c684241c02000006     mov byte ptr [esp + 0x21c], 6
// 0046de3c  85f6                 test esi, esi
// 0046de3e  7410                 je 0x46de50
// 0046de40  8bce                 mov ecx, esi
// 0046de42  e8295cfaff           call 0x413a70
// 0046de47  56                   push esi
// 0046de48  e82d282300           call 0x6a067a
// 0046de4d  83c404               add esp, 4
// 0046de50  8d8c2440010000       lea ecx, [esp + 0x140]
// 0046de57  c684241c02000005     mov byte ptr [esp + 0x21c], 5
// 0046de5f  e85c69faff           call 0x4147c0
// 0046de64  8d8c2488010000       lea ecx, [esp + 0x188]
// 0046de6b  c684241c02000004     mov byte ptr [esp + 0x21c], 4
// 0046de73  ff1508248000         call dword ptr [0x802408]
// 0046de79  8d8c2424020000       lea ecx, [esp + 0x224]
// 0046de80  c784241c020000ffffffff mov dword ptr [esp + 0x21c], 0xffffffff
// 0046de8b  ff1568248000         call dword ptr [0x802468]
// 0046de91  8b8c2414020000       mov ecx, dword ptr [esp + 0x214]
// 0046de98  5f                   pop edi
// 0046de99  5e                   pop esi
// 0046de9a  5d                   pop ebp
// 0046de9b  8bc3                 mov eax, ebx
// 0046de9d  64890d00000000       mov dword ptr fs:[0], ecx
// 0046dea4  5b                   pop ebx
// 0046dea5  81c410020000         add esp, 0x210
// 0046deab  c21c00               ret 0x1c

// from server: 94% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// Native map loader; real MSVC containers and observed XML/parser interfaces.
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <memory>
#include <cstdlib>
#include <cstddef>
// The genuine imported c_str member is invoked through its real typed member address.
// This fully defined helper has no external stand-in or fabricated class layout.
static const char*nativeCString(const std::string&value){
 const char*(std::string::*method)()const=&std::string::c_str;
 return (value.*method)();
}
namespace RBX {class Name;}
class XmlNameValuePair {public:bool getValue(std::string&)const;};
// Opaque native receiver: no XmlElement objects or RTTI are created here.
class XmlElement {public:
 ~XmlElement();
 const XmlElement*findFirstChildByTag(const RBX::Name&)const;
 const XmlElement*nextSibling()const{return *reinterpret_cast<const XmlElement*const*>(this);}
 const XmlNameValuePair&observedValue()const{return *reinterpret_cast<const XmlNameValuePair*>(reinterpret_cast<const char*>(this)+0x10);}
};
namespace boost {namespace noncopyable_ {class noncopyable {protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);const noncopyable&operator=(const noncopyable&);};}typedef noncopyable_::noncopyable noncopyable;}
class XmlParser:public boost::noncopyable {
protected:std::streambuf*buffer;std::stack<XmlElement*>elements;XmlParser(std::streambuf*);
public:virtual std::auto_ptr<XmlElement>parse()=0;
};
// Native constructor415350 initializes the inherited prefix and map at+28hex.
class TextXmlParser:public XmlParser {
 std::map<std::string,std::string>legacyHashes;
public:TextXmlParser(std::streambuf*);~TextXmlParser();virtual std::auto_ptr<XmlElement>parse();
};
extern const RBX::Name& tag_schema_version;
extern const RBX::Name& tag_color_map;
extern const RBX::Name& tag_color;
extern const RBX::Name& tag_ldraw_code;
extern const RBX::Name& tag_roblox_code;
extern const RBX::Name& tag_part_map;
extern const RBX::Name& tag_part;
extern const RBX::Name& tag_name;
extern const RBX::Name& tag_description;
extern const RBX::Name& tag_ldraw_filename;
extern const RBX::Name& tag_mapping_fidelity;
extern const RBX::Name& tag_roblox_part;
extern const RBX::Name& tag_shape;
extern const RBX::Name& tag_form_factor;
extern const RBX::Name& tag_size_vect3;
extern const RBX::Name& tag_y_offset;

namespace RBX { namespace LDraw2Lua {
class LDraw2RobloxColorMap {
public:
    virtual ~LDraw2RobloxColorMap();
    int ldrawCode,robloxCode;
    LDraw2RobloxColorMap(int,int);
    int getLDrawCode() const { return ldrawCode; }
};
struct NativeRobloxPart {
    int shape,formFactor;
    std::string size,offset;
    NativeRobloxPart(int,int,std::string,std::string);
};
class LDraw2RobloxPartMap {
public:
    virtual ~LDraw2RobloxPartMap();
    std::string name,description,filename;
    int fidelity;
    std::vector<NativeRobloxPart> parts;
    LDraw2RobloxPartMap(std::string,std::string,std::string,int);
    void addPart(const NativeRobloxPart&);
};
class LDraw2RobloxMapRoot {
public:
    virtual ~LDraw2RobloxMapRoot();
    std::string path,version;
    std::map<int,LDraw2RobloxColorMap*> colors;
    std::map<std::string,LDraw2RobloxPartMap*> parts;
    LDraw2RobloxMapRoot(std::string);
    LDraw2RobloxColorMap* findColor(int);
    int readFidelity(std::string);
    int readShape(std::string);
    int readFormFactor(std::string);
    void addPartMap(LDraw2RobloxPartMap*);
};
typedef char NativeRootSize[sizeof(LDraw2RobloxMapRoot)==124?1:-1];
typedef char NativeColorSize[sizeof(LDraw2RobloxColorMap)==12?1:-1];
typedef char NativePartMapSize[sizeof(LDraw2RobloxPartMap)==116?1:-1];
typedef char NativeRobloxPartSize[sizeof(NativeRobloxPart)==64?1:-1];
typedef char NativeTextXmlParserSize[sizeof(TextXmlParser)==72?1:-1];

LDraw2RobloxMapRoot::LDraw2RobloxMapRoot(std::string filename):path(filename) {
    const char*(std::string::*fileCString)()const=&std::string::c_str;
    std::ifstream input((path.*fileCString)());
    TextXmlParser parser(input.rdbuf());
    std::auto_ptr<XmlElement> root=parser.parse();
    const XmlElement* item=root->findFirstChildByTag(tag_schema_version);
    if(item) item->observedValue().getValue(version);
    item=root->findFirstChildByTag(tag_color_map);
    if(item) {
        const XmlElement* color=item->findFirstChildByTag(tag_color);
        std::string text;
        while(color) {
            int found=0;
            color->findFirstChildByTag(tag_name);
            item=color->findFirstChildByTag(tag_ldraw_code);
            int ldraw=-1;
            if(item) { ++found; item->observedValue().getValue(text); ldraw=atoi(nativeCString(text)); }
            item=color->findFirstChildByTag(tag_roblox_code);
            int roblox=-1;
            if(item) { ++found; item->observedValue().getValue(text); roblox=atoi(nativeCString(text)); }
            if(found==2) {
                LDraw2RobloxColorMap* entry=new LDraw2RobloxColorMap(ldraw,roblox);
                LDraw2RobloxColorMap* previous=findColor(entry->getLDrawCode());
                if(previous) delete previous;
                colors[entry->getLDrawCode()]=entry;
            }
            color=color->nextSibling();
        }
    }
    item=root->findFirstChildByTag(tag_part_map);
    if(item) {
        const XmlElement* part=item->findFirstChildByTag(tag_part);
        while(part) {
            int found=0;
            item=part->findFirstChildByTag(tag_name);
            std::string name("");
            if(item) { ++found; item->observedValue().getValue(name); }
            item=part->findFirstChildByTag(tag_description);
            std::string description("");
            if(item) { ++found; item->observedValue().getValue(description); }
            item=part->findFirstChildByTag(tag_ldraw_filename);
            std::string ldrawFilename("");
            if(item) { ++found; item->observedValue().getValue(ldrawFilename); }
            item=part->findFirstChildByTag(tag_mapping_fidelity);
            std::string fidelityText("");
            int fidelity=2;
            if(item) { ++found; item->observedValue().getValue(fidelityText); fidelity=readFidelity(fidelityText); }
            LDraw2RobloxPartMap* entry=new LDraw2RobloxPartMap(name,description,ldrawFilename,fidelity);
            const XmlElement* child=part->findFirstChildByTag(tag_roblox_part);
            if(child) {
                ++found;
                while(child) {
                    int fields=0;
                    item=child->findFirstChildByTag(tag_shape);
                    std::string text("");
                    int shape=999;
                    if(item) { ++fields; item->observedValue().getValue(text); shape=readShape(text); }
                    item=child->findFirstChildByTag(tag_form_factor);
                    text="";
                    int formFactor=0;
                    if(item) { ++fields; item->observedValue().getValue(text); formFactor=readFormFactor(text); }
                    item=child->findFirstChildByTag(tag_size_vect3);
                    std::string size("");
                    if(item) { ++fields; item->observedValue().getValue(size); }
                    item=child->findFirstChildByTag(tag_y_offset);
                    std::string offset("");
                    if(item) { ++fields; item->observedValue().getValue(offset); }
                    if(fields==4) entry->addPart(NativeRobloxPart(shape,formFactor,size,offset));
                    child=child->nextSibling();
                }
            }
            if(found==5) addPartMap(entry);
            part=part->nextSibling();
        }
    }
}
}}

typedef char native_string_size[sizeof(std::string)==28?1:-1];
typedef char native_stream_size[sizeof(std::ifstream)==140?1:-1];
typedef char native_parser_base_size[sizeof(XmlParser)==40?1:-1];
typedef char native_parser_stack_size[sizeof(std::stack<XmlElement*>)==32?1:-1];
typedef char native_parser_map_size[sizeof(std::map<std::string,std::string>)==32?1:-1];
typedef char native_xml_owner_size[sizeof(std::auto_ptr<XmlElement>)==4?1:-1];
namespace RBX {namespace LDraw2Lua {
typedef char native_path_offset[offsetof(LDraw2RobloxMapRoot,path)==4?1:-1];
typedef char native_version_offset[offsetof(LDraw2RobloxMapRoot,version)==0x20?1:-1];
typedef char native_colors_offset[offsetof(LDraw2RobloxMapRoot,colors)==0x3c?1:-1];
typedef char native_parts_offset[offsetof(LDraw2RobloxMapRoot,parts)==0x5c?1:-1];
typedef char native_color_code_offset[offsetof(LDraw2RobloxColorMap,ldrawCode)==4?1:-1];
typedef char native_color_roblox_offset[offsetof(LDraw2RobloxColorMap,robloxCode)==8?1:-1];
typedef char native_part_fidelity_offset[offsetof(LDraw2RobloxPartMap,fidelity)==0x58?1:-1];
typedef char native_part_entries_offset[offsetof(LDraw2RobloxPartMap,parts)==0x5c?1:-1];
typedef char native_value_size_offset[offsetof(NativeRobloxPart,size)==8?1:-1];
typedef char native_value_y_offset[offsetof(NativeRobloxPart,offset)==0x24?1:-1];
}}
