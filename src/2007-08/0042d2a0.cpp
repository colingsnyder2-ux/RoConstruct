// from server: 100% by EspClaude
// from server: 96% by EspClaude
// roc 2007-08 0042d2a0  unit: CLuaHtmlView  size: 985 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042d2a0
//
// 0042d2a0  6aff                 push -1
// 0042d2a2  684ed57300           push 0x73d54e
// 0042d2a7  64a100000000         mov eax, dword ptr fs:[0]
// 0042d2ad  50                   push eax
// 0042d2ae  83ec68               sub esp, 0x68
// 0042d2b1  53                   push ebx
// 0042d2b2  55                   push ebp
// 0042d2b3  56                   push esi
// 0042d2b4  57                   push edi
// 0042d2b5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042d2ba  33c4                 xor eax, esp
// 0042d2bc  50                   push eax
// 0042d2bd  8d44247c             lea eax, [esp + 0x7c]
// 0042d2c1  64a300000000         mov dword ptr fs:[0], eax
// 0042d2c7  894c2424             mov dword ptr [esp + 0x24], ecx
// 0042d2cb  33f6                 xor esi, esi
// 0042d2cd  89b42484000000       mov dword ptr [esp + 0x84], esi
// 0042d2d4  e811322000           call 0x6304ea
// 0042d2d9  33c9                 xor ecx, ecx
// 0042d2db  3bc6                 cmp eax, esi
// 0042d2dd  894c2420             mov dword ptr [esp + 0x20], ecx
// 0042d2e1  7415                 je 0x42d2f8
// 0042d2e3  8b08                 mov ecx, dword ptr [eax]
// 0042d2e5  8d542420             lea edx, [esp + 0x20]
// 0042d2e9  52                   push edx
// 0042d2ea  6820707800           push 0x787020
// 0042d2ef  50                   push eax
// 0042d2f0  8b01                 mov eax, dword ptr [ecx]
// 0042d2f2  ffd0                 call eax
// 0042d2f4  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0042d2f8  3bce                 cmp ecx, esi
// 0042d2fa  c684248400000001     mov byte ptr [esp + 0x84], 1
// 0042d302  7534                 jne 0x42d338
// 0042d304  68e4a27800           push 0x78a2e4
// 0042d309  8d4c243c             lea ecx, [esp + 0x3c]
// 0042d30d  ff1598e67700         call dword ptr [0x77e698]
// 0042d313  8d4c2438             lea ecx, [esp + 0x38]
// 0042d317  51                   push ecx
// 0042d318  8d4c2458             lea ecx, [esp + 0x58]
// 0042d31c  c684248800000002     mov byte ptr [esp + 0x88], 2
// 0042d324  e8975afeff           call 0x412dc0
// 0042d329  68c0108400           push 0x8410c0
// 0042d32e  8d542458             lea edx, [esp + 0x58]
// 0042d332  52                   push edx
// 0042d333  e866382000           call 0x630b9e
// 0042d338  8974241c             mov dword ptr [esp + 0x1c], esi
// 0042d33c  8b01                 mov eax, dword ptr [ecx]
// 0042d33e  8b4020               mov eax, dword ptr [eax + 0x20]
// 0042d341  8d54241c             lea edx, [esp + 0x1c]
// 0042d345  52                   push edx
// 0042d346  51                   push ecx
// 0042d347  c684248c00000003     mov byte ptr [esp + 0x8c], 3
// 0042d34f  ffd0                 call eax
// 0042d351  89742418             mov dword ptr [esp + 0x18], esi
// 0042d355  8d4c2428             lea ecx, [esp + 0x28]
// 0042d359  51                   push ecx
// 0042d35a  ff1500ea7700         call dword ptr [0x77ea00]
// 0042d360  8b942498000000       mov edx, dword ptr [esp + 0x98]
// 0042d367  8b742428             mov esi, dword ptr [esp + 0x28]
// 0042d36b  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0042d36f  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 0042d373  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 0042d377  52                   push edx
// 0042d378  8d4c243c             lea ecx, [esp + 0x3c]
// 0042d37c  c684248800000005     mov byte ptr [esp + 0x88], 5
// 0042d384  66c744243c0000       mov word ptr [esp + 0x3c], 0
// 0042d38b  e8f044feff           call 0x411880
// 0042d390  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0042d394  8b11                 mov edx, dword ptr [ecx]
// 0042d396  8d442418             lea eax, [esp + 0x18]
// 0042d39a  50                   push eax
// 0042d39b  83ec10               sub esp, 0x10
// 0042d39e  8bc4                 mov eax, esp
// 0042d3a0  8930                 mov dword ptr [eax], esi
// 0042d3a2  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 0042d3a6  897804               mov dword ptr [eax + 4], edi
// 0042d3a9  896808               mov dword ptr [eax + 8], ebp
// 0042d3ac  89580c               mov dword ptr [eax + 0xc], ebx
// 0042d3af  83ec10               sub esp, 0x10
// 0042d3b2  8bc4                 mov eax, esp
// 0042d3b4  8930                 mov dword ptr [eax], esi
// 0042d3b6  8b742460             mov esi, dword ptr [esp + 0x60]
// 0042d3ba  897004               mov dword ptr [eax + 4], esi
// 0042d3bd  8b742464             mov esi, dword ptr [esp + 0x64]
// 0042d3c1  897008               mov dword ptr [eax + 8], esi
// 0042d3c4  8b742468             mov esi, dword ptr [esp + 0x68]
// 0042d3c8  51                   push ecx
// 0042d3c9  8b4a2c               mov ecx, dword ptr [edx + 0x2c]
// 0042d3cc  c68424ac00000006     mov byte ptr [esp + 0xac], 6
// 0042d3d4  89700c               mov dword ptr [eax + 0xc], esi
// 0042d3d7  ffd1                 call ecx
// 0042d3d9  8b35d8e97700         mov esi, dword ptr [0x77e9d8]
// 0042d3df  8d542438             lea edx, [esp + 0x38]
// 0042d3e3  52                   push edx
// 0042d3e4  ffd6                 call esi
// 0042d3e6  8d442428             lea eax, [esp + 0x28]
// 0042d3ea  50                   push eax
// 0042d3eb  c684248800000004     mov byte ptr [esp + 0x88], 4
// 0042d3f3  ffd6                 call esi
// 0042d3f5  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042d3f9  85c0                 test eax, eax
// 0042d3fb  753b                 jne 0x42d438
// 0042d3fd  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 0042d404  51                   push ecx
// 0042d405  8d54243c             lea edx, [esp + 0x3c]
// 0042d409  68b0a57800           push 0x78a5b0
// 0042d40e  52                   push edx
// 0042d40f  e8ac430d00           call 0x5017c0
// 0042d414  83c40c               add esp, 0xc
// 0042d417  50                   push eax
// 0042d418  8d4c2458             lea ecx, [esp + 0x58]
// 0042d41c  c684248800000007     mov byte ptr [esp + 0x88], 7
// 0042d424  e89759feff           call 0x412dc0
// 0042d429  68c0108400           push 0x8410c0
// 0042d42e  8d442458             lea eax, [esp + 0x58]
// 0042d432  50                   push eax
// 0042d433  e866372000           call 0x630b9e
// 0042d438  8d542414             lea edx, [esp + 0x14]
// 0042d43c  52                   push edx
// 0042d43d  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0042d445  8b08                 mov ecx, dword ptr [eax]
// 0042d447  6834a27800           push 0x78a234
// 0042d44c  50                   push eax
// 0042d44d  8b01                 mov eax, dword ptr [ecx]
// 0042d44f  ffd0                 call eax
// 0042d451  837c241400           cmp dword ptr [esp + 0x14], 0
// 0042d456  c684248400000008     mov byte ptr [esp + 0x84], 8
// 0042d45e  753b                 jne 0x42d49b
// 0042d460  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 0042d467  51                   push ecx
// 0042d468  8d54243c             lea edx, [esp + 0x3c]
// 0042d46c  6894a57800           push 0x78a594
// 0042d471  52                   push edx
// 0042d472  e849430d00           call 0x5017c0
// 0042d477  83c40c               add esp, 0xc
// 0042d47a  50                   push eax
// 0042d47b  8d4c2458             lea ecx, [esp + 0x58]
// 0042d47f  c684248800000009     mov byte ptr [esp + 0x88], 9
// 0042d487  e83459feff           call 0x412dc0
// 0042d48c  68c0108400           push 0x8410c0
// 0042d491  8d442458             lea eax, [esp + 0x58]
// 0042d495  50                   push eax
// 0042d496  e803372000           call 0x630b9e
// 0042d49b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0042d49f  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 0042d4a5  8b30                 mov esi, dword ptr [eax]
// 0042d4a7  8b1dd8e67700         mov ebx, dword ptr [0x77e6d8]
// 0042d4ad  81c70c010000         add edi, 0x10c
// 0042d4b3  8974242c             mov dword ptr [esp + 0x2c], esi
// 0042d4b7  897c2428             mov dword ptr [esp + 0x28], edi
// 0042d4bb  8be8                 mov ebp, eax
// 0042d4bd  8d4900               lea ecx, [ecx]
// 0042d4c0  3bff                 cmp edi, edi
// 0042d4c2  7402                 je 0x42d4c6
// 0042d4c4  ffd3                 call ebx
// 0042d4c6  3bf5                 cmp esi, ebp
// 0042d4c8  7442                 je 0x42d50c
// 0042d4ca  3b7704               cmp esi, dword ptr [edi + 4]
// 0042d4cd  7502                 jne 0x42d4d1
// 0042d4cf  ffd3                 call ebx
// 0042d4d1  8b4608               mov eax, dword ptr [esi + 8]
// 0042d4d4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042d4d8  8b5020               mov edx, dword ptr [eax + 0x20]
// 0042d4db  51                   push ecx
// 0042d4dc  52                   push edx
// 0042d4dd  e8ced6ffff           call 0x42abb0
// 0042d4e2  83c408               add esp, 8
// 0042d4e5  84c0                 test al, al
// 0042d4e7  750b                 jne 0x42d4f4
// 0042d4e9  3b7704               cmp esi, dword ptr [edi + 4]
// 0042d4ec  7502                 jne 0x42d4f0
// 0042d4ee  ffd3                 call ebx
// 0042d4f0  8b36                 mov esi, dword ptr [esi]
// 0042d4f2  ebcc                 jmp 0x42d4c0
// 0042d4f4  8d4c2428             lea ecx, [esp + 0x28]
// 0042d4f8  8974242c             mov dword ptr [esp + 0x2c], esi
// 0042d4fc  e8bfd5ffff           call 0x42aac0
// 0042d501  8b30                 mov esi, dword ptr [eax]
// 0042d503  85f6                 test esi, esi
// 0042d505  7409                 je 0x42d510
// 0042d507  e9a2000000           jmp 0x42d5ae
// 0042d50c  8974242c             mov dword ptr [esp + 0x2c], esi
// 0042d510  8b442424             mov eax, dword ptr [esp + 0x24]
// 0042d514  83ec08               sub esp, 8
// 0042d517  05fc000000           add eax, 0xfc
// 0042d51c  8bcc                 mov ecx, esp
// 0042d51e  89a424a0000000       mov dword ptr [esp + 0xa0], esp
// 0042d525  50                   push eax
// 0042d526  e835970700           call 0x4a6c60
// 0042d52b  8d4c2440             lea ecx, [esp + 0x40]
// 0042d52f  e81c00feff           call 0x40d550
// 0042d534  b30a                 mov bl, 0xa
// 0042d536  6a24                 push 0x24
// 0042d538  889c2488000000       mov byte ptr [esp + 0x88], bl
// 0042d53f  e8b2292000           call 0x62fef6
// 0042d544  83c404               add esp, 4
// 0042d547  89842498000000       mov dword ptr [esp + 0x98], eax
// 0042d54e  85c0                 test eax, eax
// 0042d550  c68424840000000b     mov byte ptr [esp + 0x84], 0xb
// 0042d558  740e                 je 0x42d568
// 0042d55a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042d55e  51                   push ecx
// 0042d55f  8bc8                 mov ecx, eax
// 0042d561  e86aefffff           call 0x42c4d0
// 0042d566  eb02                 jmp 0x42d56a
// 0042d568  33c0                 xor eax, eax
// 0042d56a  50                   push eax
// 0042d56b  8d4c242c             lea ecx, [esp + 0x2c]
// 0042d56f  889c2488000000       mov byte ptr [esp + 0x88], bl
// 0042d576  8bf0                 mov esi, eax
// 0042d578  e803d8ffff           call 0x42ad80
// 0042d57d  50                   push eax
// 0042d57e  8bcf                 mov ecx, edi
// 0042d580  c68424880000000c     mov byte ptr [esp + 0x88], 0xc
// 0042d588  e803e5ffff           call 0x42ba90
// 0042d58d  8d4c2428             lea ecx, [esp + 0x28]
// 0042d591  889c2484000000       mov byte ptr [esp + 0x84], bl
// 0042d598  e8c34d0600           call 0x492360
// 0042d59d  8d4c2438             lea ecx, [esp + 0x38]
// 0042d5a1  c684248400000008     mov byte ptr [esp + 0x84], 8
// 0042d5a9  e8f2bf1200           call 0x5595a0
// 0042d5ae  8b942494000000       mov edx, dword ptr [esp + 0x94]
// 0042d5b5  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 0042d5bc  52                   push edx
// 0042d5bd  83ec08               sub esp, 8
// 0042d5c0  8bc4                 mov eax, esp
// 0042d5c2  8908                 mov dword ptr [eax], ecx
// 0042d5c4  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 0042d5cb  85c9                 test ecx, ecx
// 0042d5cd  89a424a4000000       mov dword ptr [esp + 0xa4], esp
// 0042d5d4  894804               mov dword ptr [eax + 4], ecx
// 0042d5d7  740c                 je 0x42d5e5
// 0042d5d9  83c104               add ecx, 4
// 0042d5dc  ba01000000           mov edx, 1
// 0042d5e1  f00fc111             lock xadd dword ptr [ecx], edx
// 0042d5e5  8bce                 mov ecx, esi
// 0042d5e7  e854fbffff           call 0x42d140
// 0042d5ec  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042d5f0  85c0                 test eax, eax
// 0042d5f2  c684248400000004     mov byte ptr [esp + 0x84], 4
// 0042d5fa  7408                 je 0x42d604
// 0042d5fc  8b08                 mov ecx, dword ptr [eax]
// 0042d5fe  8b5108               mov edx, dword ptr [ecx + 8]
// 0042d601  50                   push eax
// 0042d602  ffd2                 call edx
// 0042d604  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042d608  85c0                 test eax, eax
// 0042d60a  c684248400000003     mov byte ptr [esp + 0x84], 3
// 0042d612  7408                 je 0x42d61c
// 0042d614  8b08                 mov ecx, dword ptr [eax]
// 0042d616  8b5108               mov edx, dword ptr [ecx + 8]
// 0042d619  50                   push eax
// 0042d61a  ffd2                 call edx
// 0042d61c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042d620  85c0                 test eax, eax
// 0042d622  c684248400000001     mov byte ptr [esp + 0x84], 1
// 0042d62a  7408                 je 0x42d634
// 0042d62c  8b08                 mov ecx, dword ptr [eax]
// 0042d62e  8b5108               mov edx, dword ptr [ecx + 8]
// 0042d631  50                   push eax
// 0042d632  ffd2                 call edx
// 0042d634  8b442420             mov eax, dword ptr [esp + 0x20]
// 0042d638  85c0                 test eax, eax
// 0042d63a  c684248400000000     mov byte ptr [esp + 0x84], 0
// 0042d642  7408                 je 0x42d64c
// 0042d644  8b08                 mov ecx, dword ptr [eax]
// 0042d646  8b5108               mov edx, dword ptr [ecx + 8]
// 0042d649  50                   push eax
// 0042d64a  ffd2                 call edx
// 0042d64c  8d8c248c000000       lea ecx, [esp + 0x8c]
// 0042d653  c7842484000000ffffffff mov dword ptr [esp + 0x84], 0xffffffff
// 0042d65e  e8fd4c0600           call 0x492360
// 0042d663  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 0042d667  64890d00000000       mov dword ptr fs:[0], ecx
// 0042d66e  59                   pop ecx
// 0042d66f  5f                   pop edi
// 0042d670  5e                   pop esi
// 0042d671  5d                   pop ebp
// 0042d672  5b                   pop ebx
// 0042d673  83c474               add esp, 0x74
// 0042d676  c21000               ret 0x10

// from server: 100% by EspClaude
// roc 2008-06 0042c8c0  unit: CLuaHtmlView::Binder  size: 1026 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042c8c0
//
// 0042c8c0  6aff                 push -1
// 0042c8c2  68bef77b00           push 0x7bf7be
// 0042c8c7  64a100000000         mov eax, dword ptr fs:[0]
// 0042c8cd  50                   push eax
// 0042c8ce  64892500000000       mov dword ptr fs:[0], esp
// 0042c8d5  83ec68               sub esp, 0x68
// 0042c8d8  53                   push ebx
// 0042c8d9  55                   push ebp
// 0042c8da  56                   push esi
// 0042c8db  57                   push edi
// 0042c8dc  894c2420             mov dword ptr [esp + 0x20], ecx
// 0042c8e0  33f6                 xor esi, esi
// 0042c8e2  89b42480000000       mov dword ptr [esp + 0x80], esi
// 0042c8e9  e892462700           call 0x6a0f80
// 0042c8ee  33c9                 xor ecx, ecx
// 0042c8f0  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0042c8f4  3bc6                 cmp eax, esi
// 0042c8f6  7415                 je 0x42c90d
// 0042c8f8  8b08                 mov ecx, dword ptr [eax]
// 0042c8fa  8d54241c             lea edx, [esp + 0x1c]
// 0042c8fe  52                   push edx
// 0042c8ff  686c058100           push 0x81056c
// 0042c904  50                   push eax
// 0042c905  8b01                 mov eax, dword ptr [ecx]
// 0042c907  ffd0                 call eax
// 0042c909  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0042c90d  c684248000000001     mov byte ptr [esp + 0x80], 1
// 0042c915  3bce                 cmp ecx, esi
// 0042c917  7534                 jne 0x42c94d
// 0042c919  68e0058100           push 0x8105e0
// 0042c91e  8d4c2438             lea ecx, [esp + 0x38]
// 0042c922  ff1558248000         call dword ptr [0x802458]
// 0042c928  8d4c2434             lea ecx, [esp + 0x34]
// 0042c92c  51                   push ecx
// 0042c92d  8d4c2454             lea ecx, [esp + 0x54]
// 0042c931  c684248400000002     mov byte ptr [esp + 0x84], 2
// 0042c939  e812d4fdff           call 0x409d50
// 0042c93e  68c81b8d00           push 0x8d1bc8
// 0042c943  8d542454             lea edx, [esp + 0x54]
// 0042c947  52                   push edx
// 0042c948  e83f4c2700           call 0x6a158c
// 0042c94d  89742418             mov dword ptr [esp + 0x18], esi
// 0042c951  8b01                 mov eax, dword ptr [ecx]
// 0042c953  8b4020               mov eax, dword ptr [eax + 0x20]
// 0042c956  8d542418             lea edx, [esp + 0x18]
// 0042c95a  52                   push edx
// 0042c95b  51                   push ecx
// 0042c95c  c684248800000003     mov byte ptr [esp + 0x88], 3
// 0042c964  ffd0                 call eax
// 0042c966  89742414             mov dword ptr [esp + 0x14], esi
// 0042c96a  8d4c2424             lea ecx, [esp + 0x24]
// 0042c96e  51                   push ecx
// 0042c96f  ff15f4288000         call dword ptr [0x8028f4]
// 0042c975  8b842494000000       mov eax, dword ptr [esp + 0x94]
// 0042c97c  8b742424             mov esi, dword ptr [esp + 0x24]
// 0042c980  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0042c984  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0042c988  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0042c98c  33d2                 xor edx, edx
// 0042c98e  50                   push eax
// 0042c98f  8d4c2438             lea ecx, [esp + 0x38]
// 0042c993  c684248400000005     mov byte ptr [esp + 0x84], 5
// 0042c99b  6689542438           mov word ptr [esp + 0x38], dx
// 0042c9a0  e8cb93feff           call 0x415d70
// 0042c9a5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042c9a9  8b11                 mov edx, dword ptr [ecx]
// 0042c9ab  8d442414             lea eax, [esp + 0x14]
// 0042c9af  50                   push eax
// 0042c9b0  83ec10               sub esp, 0x10
// 0042c9b3  8bc4                 mov eax, esp
// 0042c9b5  8930                 mov dword ptr [eax], esi
// 0042c9b7  8b742448             mov esi, dword ptr [esp + 0x48]
// 0042c9bb  897804               mov dword ptr [eax + 4], edi
// 0042c9be  896808               mov dword ptr [eax + 8], ebp
// 0042c9c1  89580c               mov dword ptr [eax + 0xc], ebx
// 0042c9c4  83ec10               sub esp, 0x10
// 0042c9c7  8bc4                 mov eax, esp
// 0042c9c9  8930                 mov dword ptr [eax], esi
// 0042c9cb  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 0042c9cf  897004               mov dword ptr [eax + 4], esi
// 0042c9d2  8b742460             mov esi, dword ptr [esp + 0x60]
// 0042c9d6  897008               mov dword ptr [eax + 8], esi
// 0042c9d9  8b742464             mov esi, dword ptr [esp + 0x64]
// 0042c9dd  51                   push ecx
// 0042c9de  8b4a2c               mov ecx, dword ptr [edx + 0x2c]
// 0042c9e1  c68424a800000006     mov byte ptr [esp + 0xa8], 6
// 0042c9e9  89700c               mov dword ptr [eax + 0xc], esi
// 0042c9ec  ffd1                 call ecx
// 0042c9ee  8b351c298000         mov esi, dword ptr [0x80291c]
// 0042c9f4  8d542434             lea edx, [esp + 0x34]
// 0042c9f8  52                   push edx
// 0042c9f9  ffd6                 call esi
// 0042c9fb  8d442424             lea eax, [esp + 0x24]
// 0042c9ff  50                   push eax
// 0042ca00  c684248400000004     mov byte ptr [esp + 0x84], 4
// 0042ca08  ffd6                 call esi
// 0042ca0a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042ca0e  85c0                 test eax, eax
// 0042ca10  753b                 jne 0x42ca4d
// 0042ca12  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 0042ca19  51                   push ecx
// 0042ca1a  8d542438             lea edx, [esp + 0x38]
// 0042ca1e  687c068100           push 0x81067c
// 0042ca23  52                   push edx
// 0042ca24  e8e7d00d00           call 0x509b10
// 0042ca29  83c40c               add esp, 0xc
// 0042ca2c  50                   push eax
// 0042ca2d  8d4c2454             lea ecx, [esp + 0x54]
// 0042ca31  c684248400000007     mov byte ptr [esp + 0x84], 7
// 0042ca39  e812d3fdff           call 0x409d50
// 0042ca3e  68c81b8d00           push 0x8d1bc8
// 0042ca43  8d442454             lea eax, [esp + 0x54]
// 0042ca47  50                   push eax
// 0042ca48  e83f4b2700           call 0x6a158c
// 0042ca4d  8d542410             lea edx, [esp + 0x10]
// 0042ca51  52                   push edx
// 0042ca52  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0042ca5a  8b08                 mov ecx, dword ptr [eax]
// 0042ca5c  687c058100           push 0x81057c
// 0042ca61  50                   push eax
// 0042ca62  8b01                 mov eax, dword ptr [ecx]
// 0042ca64  ffd0                 call eax
// 0042ca66  837c241000           cmp dword ptr [esp + 0x10], 0
// 0042ca6b  c684248000000008     mov byte ptr [esp + 0x80], 8
// 0042ca73  753b                 jne 0x42cab0
// 0042ca75  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 0042ca7c  51                   push ecx
// 0042ca7d  8d542438             lea edx, [esp + 0x38]
// 0042ca81  6860068100           push 0x810660
// 0042ca86  52                   push edx
// 0042ca87  e884d00d00           call 0x509b10
// 0042ca8c  83c40c               add esp, 0xc
// 0042ca8f  50                   push eax
// 0042ca90  8d4c2454             lea ecx, [esp + 0x54]
// 0042ca94  c684248400000009     mov byte ptr [esp + 0x84], 9
// 0042ca9c  e8afd2fdff           call 0x409d50
// 0042caa1  68c81b8d00           push 0x8d1bc8
// 0042caa6  8d442454             lea eax, [esp + 0x54]
// 0042caaa  50                   push eax
// 0042caab  e8dc4a2700           call 0x6a158c
// 0042cab0  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0042cab4  8b8524010000         mov eax, dword ptr [ebp + 0x124]
// 0042caba  8bbd10010000         mov edi, dword ptr [ebp + 0x110]
// 0042cac0  8b30                 mov esi, dword ptr [eax]
// 0042cac2  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0042cac8  81c510010000         add ebp, 0x110
// 0042cace  8bc8                 mov ecx, eax
// 0042cad0  8bd7                 mov edx, edi
// 0042cad2  89742428             mov dword ptr [esp + 0x28], esi
// 0042cad6  897c2424             mov dword ptr [esp + 0x24], edi
// 0042cada  894c2438             mov dword ptr [esp + 0x38], ecx
// 0042cade  89542434             mov dword ptr [esp + 0x34], edx
// 0042cae2  85ff                 test edi, edi
// 0042cae4  7406                 je 0x42caec
// 0042cae6  3b7c2434             cmp edi, dword ptr [esp + 0x34]
// 0042caea  7402                 je 0x42caee
// 0042caec  ffd3                 call ebx
// 0042caee  3b742438             cmp esi, dword ptr [esp + 0x38]
// 0042caf2  745b                 je 0x42cb4f
// 0042caf4  85ff                 test edi, edi
// 0042caf6  7536                 jne 0x42cb2e
// 0042caf8  ffd3                 call ebx
// 0042cafa  33c0                 xor eax, eax
// 0042cafc  3b7014               cmp esi, dword ptr [eax + 0x14]
// 0042caff  7502                 jne 0x42cb03
// 0042cb01  ffd3                 call ebx
// 0042cb03  8b4608               mov eax, dword ptr [esi + 8]
// 0042cb06  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042cb0a  8b5030               mov edx, dword ptr [eax + 0x30]
// 0042cb0d  51                   push ecx
// 0042cb0e  52                   push edx
// 0042cb0f  e81cdeffff           call 0x42a930
// 0042cb14  83c408               add esp, 8
// 0042cb17  84c0                 test al, al
// 0042cb19  751b                 jne 0x42cb36
// 0042cb1b  85ff                 test edi, edi
// 0042cb1d  7513                 jne 0x42cb32
// 0042cb1f  ffd3                 call ebx
// 0042cb21  33c0                 xor eax, eax
// 0042cb23  3b7014               cmp esi, dword ptr [eax + 0x14]
// 0042cb26  7502                 jne 0x42cb2a
// 0042cb28  ffd3                 call ebx
// 0042cb2a  8b36                 mov esi, dword ptr [esi]
// 0042cb2c  ebb4                 jmp 0x42cae2
// 0042cb2e  8b07                 mov eax, dword ptr [edi]
// 0042cb30  ebca                 jmp 0x42cafc
// 0042cb32  8b07                 mov eax, dword ptr [edi]
// 0042cb34  ebed                 jmp 0x42cb23
// 0042cb36  8d4c2424             lea ecx, [esp + 0x24]
// 0042cb3a  89742428             mov dword ptr [esp + 0x28], esi
// 0042cb3e  e8adddffff           call 0x42a8f0
// 0042cb43  8b30                 mov esi, dword ptr [eax]
// 0042cb45  85f6                 test esi, esi
// 0042cb47  0f85a4000000         jne 0x42cbf1
// 0042cb4d  eb04                 jmp 0x42cb53
// 0042cb4f  89742428             mov dword ptr [esp + 0x28], esi
// 0042cb53  8b442420             mov eax, dword ptr [esp + 0x20]
// 0042cb57  83ec08               sub esp, 8
// 0042cb5a  0500010000           add eax, 0x100
// 0042cb5f  8bcc                 mov ecx, esp
// 0042cb61  89a4249c000000       mov dword ptr [esp + 0x9c], esp
// 0042cb68  50                   push eax
// 0042cb69  e8824bfeff           call 0x4116f0
// 0042cb6e  8d4c242c             lea ecx, [esp + 0x2c]
// 0042cb72  e8c94ffeff           call 0x411b40
// 0042cb77  b30a                 mov bl, 0xa
// 0042cb79  6a34                 push 0x34
// 0042cb7b  889c2484000000       mov byte ptr [esp + 0x84], bl
// 0042cb82  e8993d2700           call 0x6a0920
// 0042cb87  83c404               add esp, 4
// 0042cb8a  89842494000000       mov dword ptr [esp + 0x94], eax
// 0042cb91  c68424800000000b     mov byte ptr [esp + 0x80], 0xb
// 0042cb99  85c0                 test eax, eax
// 0042cb9b  740e                 je 0x42cbab
// 0042cb9d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042cba1  51                   push ecx
// 0042cba2  8bc8                 mov ecx, eax
// 0042cba4  e827f5ffff           call 0x42c0d0
// 0042cba9  eb02                 jmp 0x42cbad
// 0042cbab  33c0                 xor eax, eax
// 0042cbad  50                   push eax
// 0042cbae  8d4c2438             lea ecx, [esp + 0x38]
// 0042cbb2  889c2484000000       mov byte ptr [esp + 0x84], bl
// 0042cbb9  8bf0                 mov esi, eax
// 0042cbbb  e830dfffff           call 0x42aaf0
// 0042cbc0  50                   push eax
// 0042cbc1  8bcd                 mov ecx, ebp
// 0042cbc3  c68424840000000c     mov byte ptr [esp + 0x84], 0xc
// 0042cbcb  e8b0240800           call 0x4af080
// 0042cbd0  8d4c2434             lea ecx, [esp + 0x34]
// 0042cbd4  889c2480000000       mov byte ptr [esp + 0x80], bl
// 0042cbdb  e8803a1d00           call 0x600660
// 0042cbe0  8d4c2424             lea ecx, [esp + 0x24]
// 0042cbe4  c684248000000008     mov byte ptr [esp + 0x80], 8
// 0042cbec  e8cfa71400           call 0x5773c0
// 0042cbf1  8b942490000000       mov edx, dword ptr [esp + 0x90]
// 0042cbf8  8b8c2488000000       mov ecx, dword ptr [esp + 0x88]
// 0042cbff  52                   push edx
// 0042cc00  83ec08               sub esp, 8
// 0042cc03  8bc4                 mov eax, esp
// 0042cc05  8908                 mov dword ptr [eax], ecx
// 0042cc07  8b942498000000       mov edx, dword ptr [esp + 0x98]
// 0042cc0e  895004               mov dword ptr [eax + 4], edx
// 0042cc11  8b842498000000       mov eax, dword ptr [esp + 0x98]
// 0042cc18  89a424a0000000       mov dword ptr [esp + 0xa0], esp
// 0042cc1f  85c0                 test eax, eax
// 0042cc21  740c                 je 0x42cc2f
// 0042cc23  83c004               add eax, 4
// 0042cc26  b901000000           mov ecx, 1
// 0042cc2b  f00fc108             lock xadd dword ptr [eax], ecx
// 0042cc2f  8bce                 mov ecx, esi
// 0042cc31  e82afbffff           call 0x42c760
// 0042cc36  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042cc3a  c684248000000004     mov byte ptr [esp + 0x80], 4
// 0042cc42  85c0                 test eax, eax
// 0042cc44  7408                 je 0x42cc4e
// 0042cc46  8b10                 mov edx, dword ptr [eax]
// 0042cc48  50                   push eax
// 0042cc49  8b4208               mov eax, dword ptr [edx + 8]
// 0042cc4c  ffd0                 call eax
// 0042cc4e  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042cc52  c684248000000003     mov byte ptr [esp + 0x80], 3
// 0042cc5a  85c0                 test eax, eax
// 0042cc5c  7408                 je 0x42cc66
// 0042cc5e  8b08                 mov ecx, dword ptr [eax]
// 0042cc60  8b5108               mov edx, dword ptr [ecx + 8]
// 0042cc63  50                   push eax
// 0042cc64  ffd2                 call edx
// 0042cc66  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042cc6a  c684248000000001     mov byte ptr [esp + 0x80], 1
// 0042cc72  85c0                 test eax, eax
// 0042cc74  7408                 je 0x42cc7e
// 0042cc76  8b08                 mov ecx, dword ptr [eax]
// 0042cc78  8b5108               mov edx, dword ptr [ecx + 8]
// 0042cc7b  50                   push eax
// 0042cc7c  ffd2                 call edx
// 0042cc7e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042cc82  c684248000000000     mov byte ptr [esp + 0x80], 0
// 0042cc8a  85c0                 test eax, eax
// 0042cc8c  7408                 je 0x42cc96
// 0042cc8e  8b08                 mov ecx, dword ptr [eax]
// 0042cc90  8b5108               mov edx, dword ptr [ecx + 8]
// 0042cc93  50                   push eax
// 0042cc94  ffd2                 call edx
// 0042cc96  8d8c2488000000       lea ecx, [esp + 0x88]
// 0042cc9d  c7842480000000ffffffff mov dword ptr [esp + 0x80], 0xffffffff
// 0042cca8  e8b3391d00           call 0x600660
// 0042ccad  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0042ccb1  5f                   pop edi
// 0042ccb2  5e                   pop esi
// 0042ccb3  5d                   pop ebp
// 0042ccb4  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ccbb  5b                   pop ebx
// 0042ccbc  83c474               add esp, 0x74
// 0042ccbf  c21000               ret 0x10

// from server: 88% by king_originala
// roc 2008-06 0042c8c0  unit: CLuaHtmlView::Binder  size: 1026 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042c8c0
//
// 0042c8c0  6aff                 push -1
// 0042c8c2  68bef77b00           push 0x7bf7be
// 0042c8c7  64a100000000         mov eax, dword ptr fs:[0]
// 0042c8cd  50                   push eax
// 0042c8ce  64892500000000       mov dword ptr fs:[0], esp
// 0042c8d5  83ec68               sub esp, 0x68
// 0042c8d8  53                   push ebx
// 0042c8d9  55                   push ebp
// 0042c8da  56                   push esi
// 0042c8db  57                   push edi
// 0042c8dc  894c2420             mov dword ptr [esp + 0x20], ecx
// 0042c8e0  33f6                 xor esi, esi
// 0042c8e2  89b42480000000       mov dword ptr [esp + 0x80], esi
// 0042c8e9  e892462700           call 0x6a0f80
// 0042c8ee  33c9                 xor ecx, ecx
// 0042c8f0  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0042c8f4  3bc6                 cmp eax, esi
// 0042c8f6  7415                 je 0x42c90d
// 0042c8f8  8b08                 mov ecx, dword ptr [eax]
// 0042c8fa  8d54241c             lea edx, [esp + 0x1c]
// 0042c8fe  52                   push edx
// 0042c8ff  686c058100           push 0x81056c
// 0042c904  50                   push eax
// 0042c905  8b01                 mov eax, dword ptr [ecx]
// 0042c907  ffd0                 call eax
// 0042c909  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0042c90d  c684248000000001     mov byte ptr [esp + 0x80], 1
// 0042c915  3bce                 cmp ecx, esi
// 0042c917  7534                 jne 0x42c94d
// 0042c919  68e0058100           push 0x8105e0
// 0042c91e  8d4c2438             lea ecx, [esp + 0x38]
// 0042c922  ff1558248000         call dword ptr [0x802458]
// 0042c928  8d4c2434             lea ecx, [esp + 0x34]
// 0042c92c  51                   push ecx
// 0042c92d  8d4c2454             lea ecx, [esp + 0x54]
// 0042c931  c684248400000002     mov byte ptr [esp + 0x84], 2
// 0042c939  e812d4fdff           call 0x409d50
// 0042c93e  68c81b8d00           push 0x8d1bc8
// 0042c943  8d542454             lea edx, [esp + 0x54]
// 0042c947  52                   push edx
// 0042c948  e83f4c2700           call 0x6a158c
// 0042c94d  89742418             mov dword ptr [esp + 0x18], esi
// 0042c951  8b01                 mov eax, dword ptr [ecx]
// 0042c953  8b4020               mov eax, dword ptr [eax + 0x20]
// 0042c956  8d542418             lea edx, [esp + 0x18]
// 0042c95a  52                   push edx
// 0042c95b  51                   push ecx
// 0042c95c  c684248800000003     mov byte ptr [esp + 0x88], 3
// 0042c964  ffd0                 call eax
// 0042c966  89742414             mov dword ptr [esp + 0x14], esi
// 0042c96a  8d4c2424             lea ecx, [esp + 0x24]
// 0042c96e  51                   push ecx
// 0042c96f  ff15f4288000         call dword ptr [0x8028f4]
// 0042c975  8b842494000000       mov eax, dword ptr [esp + 0x94]
// 0042c97c  8b742424             mov esi, dword ptr [esp + 0x24]
// 0042c980  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0042c984  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0042c988  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0042c98c  33d2                 xor edx, edx
// 0042c98e  50                   push eax
// 0042c98f  8d4c2438             lea ecx, [esp + 0x38]
// 0042c993  c684248400000005     mov byte ptr [esp + 0x84], 5
// 0042c99b  6689542438           mov word ptr [esp + 0x38], dx
// 0042c9a0  e8cb93feff           call 0x415d70
// 0042c9a5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042c9a9  8b11                 mov edx, dword ptr [ecx]
// 0042c9ab  8d442414             lea eax, [esp + 0x14]
// 0042c9af  50                   push eax
// 0042c9b0  83ec10               sub esp, 0x10
// 0042c9b3  8bc4                 mov eax, esp
// 0042c9b5  8930                 mov dword ptr [eax], esi
// 0042c9b7  8b742448             mov esi, dword ptr [esp + 0x48]
// 0042c9bb  897804               mov dword ptr [eax + 4], edi
// 0042c9be  896808               mov dword ptr [eax + 8], ebp
// 0042c9c1  89580c               mov dword ptr [eax + 0xc], ebx
// 0042c9c4  83ec10               sub esp, 0x10
// 0042c9c7  8bc4                 mov eax, esp
// 0042c9c9  8930                 mov dword ptr [eax], esi
// 0042c9cb  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 0042c9cf  897004               mov dword ptr [eax + 4], esi
// 0042c9d2  8b742460             mov esi, dword ptr [esp + 0x60]
// 0042c9d6  897008               mov dword ptr [eax + 8], esi
// 0042c9d9  8b742464             mov esi, dword ptr [esp + 0x64]
// 0042c9dd  51                   push ecx
// 0042c9de  8b4a2c               mov ecx, dword ptr [edx + 0x2c]
// 0042c9e1  c68424a800000006     mov byte ptr [esp + 0xa8], 6
// 0042c9e9  89700c               mov dword ptr [eax + 0xc], esi
// 0042c9ec  ffd1                 call ecx
// 0042c9ee  8b351c298000         mov esi, dword ptr [0x80291c]
// 0042c9f4  8d542434             lea edx, [esp + 0x34]
// 0042c9f8  52                   push edx
// 0042c9f9  ffd6                 call esi
// 0042c9fb  8d442424             lea eax, [esp + 0x24]
// 0042c9ff  50                   push eax
// 0042ca00  c684248400000004     mov byte ptr [esp + 0x84], 4
// 0042ca08  ffd6                 call esi
// 0042ca0a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042ca0e  85c0                 test eax, eax
// 0042ca10  753b                 jne 0x42ca4d
// 0042ca12  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 0042ca19  51                   push ecx
// 0042ca1a  8d542438             lea edx, [esp + 0x38]
// 0042ca1e  687c068100           push 0x81067c
// 0042ca23  52                   push edx
// 0042ca24  e8e7d00d00           call 0x509b10
// 0042ca29  83c40c               add esp, 0xc
// 0042ca2c  50                   push eax
// 0042ca2d  8d4c2454             lea ecx, [esp + 0x54]
// 0042ca31  c684248400000007     mov byte ptr [esp + 0x84], 7
// 0042ca39  e812d3fdff           call 0x409d50
// 0042ca3e  68c81b8d00           push 0x8d1bc8
// 0042ca43  8d442454             lea eax, [esp + 0x54]
// 0042ca47  50                   push eax
// 0042ca48  e83f4b2700           call 0x6a158c
// 0042ca4d  8d542410             lea edx, [esp + 0x10]
// 0042ca51  52                   push edx
// 0042ca52  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0042ca5a  8b08                 mov ecx, dword ptr [eax]
// 0042ca5c  687c058100           push 0x81057c
// 0042ca61  50                   push eax
// 0042ca62  8b01                 mov eax, dword ptr [ecx]
// 0042ca64  ffd0                 call eax
// 0042ca66  837c241000           cmp dword ptr [esp + 0x10], 0
// 0042ca6b  c684248000000008     mov byte ptr [esp + 0x80], 8
// 0042ca73  753b                 jne 0x42cab0
// 0042ca75  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 0042ca7c  51                   push ecx
// 0042ca7d  8d542438             lea edx, [esp + 0x38]
// 0042ca81  6860068100           push 0x810660
// 0042ca86  52                   push edx
// 0042ca87  e884d00d00           call 0x509b10
// 0042ca8c  83c40c               add esp, 0xc
// 0042ca8f  50                   push eax
// 0042ca90  8d4c2454             lea ecx, [esp + 0x54]
// 0042ca94  c684248400000009     mov byte ptr [esp + 0x84], 9
// 0042ca9c  e8afd2fdff           call 0x409d50
// 0042caa1  68c81b8d00           push 0x8d1bc8
// 0042caa6  8d442454             lea eax, [esp + 0x54]
// 0042caaa  50                   push eax
// 0042caab  e8dc4a2700           call 0x6a158c
// 0042cab0  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0042cab4  8b8524010000         mov eax, dword ptr [ebp + 0x124]
// 0042caba  8bbd10010000         mov edi, dword ptr [ebp + 0x110]
// 0042cac0  8b30                 mov esi, dword ptr [eax]
// 0042cac2  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0042cac8  81c510010000         add ebp, 0x110
// 0042cace  8bc8                 mov ecx, eax
// 0042cad0  8bd7                 mov edx, edi
// 0042cad2  89742428             mov dword ptr [esp + 0x28], esi
// 0042cad6  897c2424             mov dword ptr [esp + 0x24], edi
// 0042cada  894c2438             mov dword ptr [esp + 0x38], ecx
// 0042cade  89542434             mov dword ptr [esp + 0x34], edx
// 0042cae2  85ff                 test edi, edi
// 0042cae4  7406                 je 0x42caec
// 0042cae6  3b7c2434             cmp edi, dword ptr [esp + 0x34]
// 0042caea  7402                 je 0x42caee
// 0042caec  ffd3                 call ebx
// 0042caee  3b742438             cmp esi, dword ptr [esp + 0x38]
// 0042caf2  745b                 je 0x42cb4f
// 0042caf4  85ff                 test edi, edi
// 0042caf6  7536                 jne 0x42cb2e
// 0042caf8  ffd3                 call ebx
// 0042cafa  33c0                 xor eax, eax
// 0042cafc  3b7014               cmp esi, dword ptr [eax + 0x14]
// 0042caff  7502                 jne 0x42cb03
// 0042cb01  ffd3                 call ebx
// 0042cb03  8b4608               mov eax, dword ptr [esi + 8]
// 0042cb06  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042cb0a  8b5030               mov edx, dword ptr [eax + 0x30]
// 0042cb0d  51                   push ecx
// 0042cb0e  52                   push edx
// 0042cb0f  e81cdeffff           call 0x42a930
// 0042cb14  83c408               add esp, 8
// 0042cb17  84c0                 test al, al
// 0042cb19  751b                 jne 0x42cb36
// 0042cb1b  85ff                 test edi, edi
// 0042cb1d  7513                 jne 0x42cb32
// 0042cb1f  ffd3                 call ebx
// 0042cb21  33c0                 xor eax, eax
// 0042cb23  3b7014               cmp esi, dword ptr [eax + 0x14]
// 0042cb26  7502                 jne 0x42cb2a
// 0042cb28  ffd3                 call ebx
// 0042cb2a  8b36                 mov esi, dword ptr [esi]
// 0042cb2c  ebb4                 jmp 0x42cae2
// 0042cb2e  8b07                 mov eax, dword ptr [edi]
// 0042cb30  ebca                 jmp 0x42cafc
// 0042cb32  8b07                 mov eax, dword ptr [edi]
// 0042cb34  ebed                 jmp 0x42cb23
// 0042cb36  8d4c2424             lea ecx, [esp + 0x24]
// 0042cb3a  89742428             mov dword ptr [esp + 0x28], esi
// 0042cb3e  e8adddffff           call 0x42a8f0
// 0042cb43  8b30                 mov esi, dword ptr [eax]
// 0042cb45  85f6                 test esi, esi
// 0042cb47  0f85a4000000         jne 0x42cbf1
// 0042cb4d  eb04                 jmp 0x42cb53
// 0042cb4f  89742428             mov dword ptr [esp + 0x28], esi
// 0042cb53  8b442420             mov eax, dword ptr [esp + 0x20]
// 0042cb57  83ec08               sub esp, 8
// 0042cb5a  0500010000           add eax, 0x100
// 0042cb5f  8bcc                 mov ecx, esp
// 0042cb61  89a4249c000000       mov dword ptr [esp + 0x9c], esp
// 0042cb68  50                   push eax
// 0042cb69  e8824bfeff           call 0x4116f0
// 0042cb6e  8d4c242c             lea ecx, [esp + 0x2c]
// 0042cb72  e8c94ffeff           call 0x411b40
// 0042cb77  b30a                 mov bl, 0xa
// 0042cb79  6a34                 push 0x34
// 0042cb7b  889c2484000000       mov byte ptr [esp + 0x84], bl
// 0042cb82  e8993d2700           call 0x6a0920
// 0042cb87  83c404               add esp, 4
// 0042cb8a  89842494000000       mov dword ptr [esp + 0x94], eax
// 0042cb91  c68424800000000b     mov byte ptr [esp + 0x80], 0xb
// 0042cb99  85c0                 test eax, eax
// 0042cb9b  740e                 je 0x42cbab
// 0042cb9d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042cba1  51                   push ecx
// 0042cba2  8bc8                 mov ecx, eax
// 0042cba4  e827f5ffff           call 0x42c0d0
// 0042cba9  eb02                 jmp 0x42cbad
// 0042cbab  33c0                 xor eax, eax
// 0042cbad  50                   push eax
// 0042cbae  8d4c2438             lea ecx, [esp + 0x38]
// 0042cbb2  889c2484000000       mov byte ptr [esp + 0x84], bl
// 0042cbb9  8bf0                 mov esi, eax
// 0042cbbb  e830dfffff           call 0x42aaf0
// 0042cbc0  50                   push eax
// 0042cbc1  8bcd                 mov ecx, ebp
// 0042cbc3  c68424840000000c     mov byte ptr [esp + 0x84], 0xc
// 0042cbcb  e8b0240800           call 0x4af080
// 0042cbd0  8d4c2434             lea ecx, [esp + 0x34]
// 0042cbd4  889c2480000000       mov byte ptr [esp + 0x80], bl
// 0042cbdb  e8803a1d00           call 0x600660
// 0042cbe0  8d4c2424             lea ecx, [esp + 0x24]
// 0042cbe4  c684248000000008     mov byte ptr [esp + 0x80], 8
// 0042cbec  e8cfa71400           call 0x5773c0
// 0042cbf1  8b942490000000       mov edx, dword ptr [esp + 0x90]
// 0042cbf8  8b8c2488000000       mov ecx, dword ptr [esp + 0x88]
// 0042cbff  52                   push edx
// 0042cc00  83ec08               sub esp, 8
// 0042cc03  8bc4                 mov eax, esp
// 0042cc05  8908                 mov dword ptr [eax], ecx
// 0042cc07  8b942498000000       mov edx, dword ptr [esp + 0x98]
// 0042cc0e  895004               mov dword ptr [eax + 4], edx
// 0042cc11  8b842498000000       mov eax, dword ptr [esp + 0x98]
// 0042cc18  89a424a0000000       mov dword ptr [esp + 0xa0], esp
// 0042cc1f  85c0                 test eax, eax
// 0042cc21  740c                 je 0x42cc2f
// 0042cc23  83c004               add eax, 4
// 0042cc26  b901000000           mov ecx, 1
// 0042cc2b  f00fc108             lock xadd dword ptr [eax], ecx
// 0042cc2f  8bce                 mov ecx, esi
// 0042cc31  e82afbffff           call 0x42c760
// 0042cc36  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042cc3a  c684248000000004     mov byte ptr [esp + 0x80], 4
// 0042cc42  85c0                 test eax, eax
// 0042cc44  7408                 je 0x42cc4e
// 0042cc46  8b10                 mov edx, dword ptr [eax]
// 0042cc48  50                   push eax
// 0042cc49  8b4208               mov eax, dword ptr [edx + 8]
// 0042cc4c  ffd0                 call eax
// 0042cc4e  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042cc52  c684248000000003     mov byte ptr [esp + 0x80], 3
// 0042cc5a  85c0                 test eax, eax
// 0042cc5c  7408                 je 0x42cc66
// 0042cc5e  8b08                 mov ecx, dword ptr [eax]
// 0042cc60  8b5108               mov edx, dword ptr [ecx + 8]
// 0042cc63  50                   push eax
// 0042cc64  ffd2                 call edx
// 0042cc66  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042cc6a  c684248000000001     mov byte ptr [esp + 0x80], 1
// 0042cc72  85c0                 test eax, eax
// 0042cc74  7408                 je 0x42cc7e
// 0042cc76  8b08                 mov ecx, dword ptr [eax]
// 0042cc78  8b5108               mov edx, dword ptr [ecx + 8]
// 0042cc7b  50                   push eax
// 0042cc7c  ffd2                 call edx
// 0042cc7e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042cc82  c684248000000000     mov byte ptr [esp + 0x80], 0
// 0042cc8a  85c0                 test eax, eax
// 0042cc8c  7408                 je 0x42cc96
// 0042cc8e  8b08                 mov ecx, dword ptr [eax]
// 0042cc90  8b5108               mov edx, dword ptr [ecx + 8]
// 0042cc93  50                   push eax
// 0042cc94  ffd2                 call edx
// 0042cc96  8d8c2488000000       lea ecx, [esp + 0x88]
// 0042cc9d  c7842480000000ffffffff mov dword ptr [esp + 0x80], 0xffffffff
// 0042cca8  e8b3391d00           call 0x600660
// 0042ccad  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0042ccb1  5f                   pop edi
// 0042ccb2  5e                   pop esi
// 0042ccb3  5d                   pop ebp
// 0042ccb4  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ccbb  5b                   pop ebx
// 0042ccbc  83c474               add esp, 0x74
// 0042ccbf  c21000               ret 0x10

// from server: 87% by colin
// roc-cl: 50727
#include <intrin.h>
#include <string>
#include <stdexcept>
#include <list>

typedef long HRESULT;
typedef unsigned short VARTYPE;
typedef struct _GUID { unsigned long Data1; unsigned short Data2, Data3; unsigned char Data4[8]; } GUID;
typedef GUID IID;
struct tagVARIANT { VARTYPE vt; unsigned short r1, r2, r3; union { long lVal; void* p; double d; }; };
typedef tagVARIANT VARIANT;
extern "C" __declspec(dllimport) void __stdcall VariantInit(VARIANT*);
extern "C" __declspec(dllimport) HRESULT __stdcall VariantClear(VARIANT*);

struct __declspec(uuid("00000000-0000-0000-C000-000000000046")) IUnknown {
    virtual HRESULT __stdcall QueryInterface(const IID& riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct __declspec(uuid("00020400-0000-0000-C000-000000000046")) IDispatch : IUnknown {
    virtual HRESULT __stdcall GetTypeInfoCount(unsigned int*) = 0;
    virtual HRESULT __stdcall GetTypeInfo(unsigned int, unsigned long, void**) = 0;
    virtual HRESULT __stdcall GetIDsOfNames(const IID&, wchar_t**, unsigned int, unsigned long, long*) = 0;
    virtual HRESULT __stdcall Invoke(long, const IID&, unsigned long, unsigned short, void*, VARIANT*, void*, unsigned int*) = 0;
};
struct __declspec(uuid("3050f21f-98b5-11cf-bb82-00aa00bdce0b")) IHTMLElementCollection : IDispatch {
    virtual HRESULT __stdcall toString(void*) = 0;
    virtual HRESULT __stdcall put_length(long) = 0;
    virtual HRESULT __stdcall get_length(long*) = 0;
    virtual HRESULT __stdcall get__newEnum(IUnknown**) = 0;
    virtual HRESULT __stdcall item(VARIANT name, VARIANT index, IDispatch** pdisp) = 0;
};
struct __declspec(uuid("332c4425-26cb-11d0-b483-00c04fd90119")) IHTMLDocument2 : IDispatch {
    virtual HRESULT __stdcall get_Script(IDispatch**) = 0;
    virtual HRESULT __stdcall get_all(IHTMLElementCollection** p) = 0;
};
struct __declspec(uuid("3050f5d2-98b5-11cf-bb82-00aa00bdce0b")) IHTMLInputElement : IDispatch {};

template<class T> class CComPtr {
public:
    CComPtr() throw() { p = 0; }
    ~CComPtr() throw() { if (p) p->Release(); }
    operator T*() const throw() { return p; }
    T* operator->() const throw() { return p; }
    T** operator&() throw() { return &p; }
    bool operator!() const throw() { return p == 0; }
    T* p;
};
template<class T> class CComQIPtr : public CComPtr<T> {
public:
    CComQIPtr(IUnknown* lp) throw() { if (lp != 0) lp->QueryInterface(__uuidof(T), (void**)&this->p); }
};
class CComVariant : public tagVARIANT {
public:
    CComVariant() throw() { ::VariantInit(this); }
    CComVariant(const char* lpszSrc) { vt = 0; *this = lpszSrc; }
    ~CComVariant() throw() { Clear(); }
    CComVariant& operator=(const char* lpszSrc);
    HRESULT Clear() { return ::VariantClear(this); }
};

namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) { sp_counted_base* p = r.pi_; pi_ = p; if (p != 0) _InterlockedIncrement(&p->use_count_); }
    ~shared_count();
};
}
template<class T> class shared_ptr {
public:
    explicit shared_ptr(T* p);
    ~shared_ptr();
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
    T* get() const { return px; }
};
}
template<class T> class dm_ptr {
public:
    dm_ptr(const dm_ptr& r);
    ~dm_ptr();
    T* px; void* pn;
};

namespace G3D { std::string __cdecl format(const char* fmt, ...); }
namespace RBX {
class DataModel;
class ReadRequest {
public:
    ReadRequest(dm_ptr<DataModel> dm);
    ~ReadRequest();
    void* a; void* b; void* c;
};
class Instance;
}

class CHtmlView {
public:
    virtual ~CHtmlView();
    IDispatch* GetHtmlDocument() const;
};

bool __cdecl isSameElement(IHTMLInputElement* a, IHTMLInputElement* b);

class CLuaHtmlView : public CHtmlView {
public:
    class Binder {
    public:
        Binder(IHTMLInputElement* element);
        void bind(boost::shared_ptr<RBX::Instance> instance, int property);
        char pad[0x20];
        IHTMLInputElement* element;
    };
    char pad0[0xfc - 4];
    dm_ptr<RBX::DataModel> dataModel;
    char pad1[0x10c - 0x104];
    typedef std::list<boost::shared_ptr<Binder> > BaseList;
    struct BinderList : public BaseList {
        struct iterator : public BaseList::iterator {
            iterator(const BaseList::iterator& i) : BaseList::iterator(i) {}
            __declspec(noinline) boost::shared_ptr<Binder>& operator*() const { return BaseList::iterator::operator*(); }
        };
        __declspec(noinline) void push_back(const boost::shared_ptr<Binder>& v) { BaseList::push_back(v); }
    };
    BinderList binders;
    void bindElement(boost::shared_ptr<RBX::Instance> instance, int property, const char* elementName);
};

void CLuaHtmlView::bindElement(boost::shared_ptr<RBX::Instance> instance, int property, const char* elementName)
{
    CComQIPtr<IHTMLDocument2> doc(GetHtmlDocument());
    if (!doc)
        throw std::runtime_error("The HtmlDocument is not loaded");
    CComPtr<IHTMLElementCollection> all;
    doc->get_all(&all);
    CComPtr<IDispatch> item;
    {
        CComVariant index;
        all->item(CComVariant(elementName), index, &item);
    }
    if (!item)
        throw std::runtime_error(G3D::format("%s not found", elementName));
    CComQIPtr<IHTMLInputElement> input(item);
    if (!input)
        throw std::runtime_error(G3D::format("%s is not an input element", elementName));
    Binder* binder = 0;
    BaseList::iterator it = binders.begin();
    BaseList::iterator end = binders.end();
    for (; it != end; ++it)
        if (isSameElement((*it)->element, input.p)) {
            binder = (*static_cast<BinderList::iterator&>(it)).get();
            break;
        }
    if (!binder) {
        RBX::ReadRequest request(dataModel);
        binder = new Binder(input);
        binders.push_back(boost::shared_ptr<Binder>(binder));
    }
    binder->bind(instance, property);
}
