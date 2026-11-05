// from server: 100% by auto
// roc 2010-06 005660b0  unit: seg_00560000  size: 1467 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005660b0
//
// 005660b0  81eca0000000         sub esp, 0xa0
// 005660b6  56                   push esi
// 005660b7  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 005660be  85f6                 test esi, esi
// 005660c0  0f849d050000         je 0x566663
// 005660c6  55                   push ebp
// 005660c7  8bac24b0000000       mov ebp, dword ptr [esp + 0xb0]
// 005660ce  85ed                 test ebp, ebp
// 005660d0  0f848c050000         je 0x566662
// 005660d6  8a862c010000         mov al, byte ptr [esi + 0x12c]
// 005660dc  53                   push ebx
// 005660dd  57                   push edi
// 005660de  3c08                 cmp al, 8
// 005660e0  7367                 jae 0x566149
// 005660e2  0fb6d8               movzx ebx, al
// 005660e5  bf08000000           mov edi, 8
// 005660ea  2bfb                 sub edi, ebx
// 005660ec  57                   push edi
// 005660ed  8d442b20             lea eax, [ebx + ebp + 0x20]
// 005660f1  50                   push eax
// 005660f2  56                   push esi
// 005660f3  e818630000           call 0x56c410
// 005660f8  57                   push edi
// 005660f9  83c520               add ebp, 0x20
// 005660fc  53                   push ebx
// 005660fd  55                   push ebp
// 005660fe  c6862c01000008       mov byte ptr [esi + 0x12c], 8
// 00566105  e846edffff           call 0x564e50
// 0056610a  83c418               add esp, 0x18
// 0056610d  85c0                 test eax, eax
// 0056610f  742c                 je 0x56613d
// 00566111  83fb04               cmp ebx, 4
// 00566114  7319                 jae 0x56612f
// 00566116  83c7fc               add edi, -4
// 00566119  57                   push edi
// 0056611a  53                   push ebx
// 0056611b  55                   push ebp
// 0056611c  e82fedffff           call 0x564e50
// 00566121  83c40c               add esp, 0xc
// 00566124  85c0                 test eax, eax
// 00566126  7407                 je 0x56612f
// 00566128  68502ba200           push 0xa22b50
// 0056612d  eb05                 jmp 0x566134
// 0056612f  68282ba200           push 0xa22b28
// 00566134  56                   push esi
// 00566135  e876b90000           call 0x571ab0
// 0056613a  83c408               add esp, 8
// 0056613d  83fb03               cmp ebx, 3
// 00566140  7307                 jae 0x566149
// 00566142  814e6800100000       or dword ptr [esi + 0x68], 0x1000
// 00566149  b373                 mov bl, 0x73
// 0056614b  eb03                 jmp 0x566150
// 0056614d  8d4900               lea ecx, [ecx]
// 00566150  c68424a000000049     mov byte ptr [esp + 0xa0], 0x49
// 00566158  c68424a100000048     mov byte ptr [esp + 0xa1], 0x48
// 00566160  c68424a200000044     mov byte ptr [esp + 0xa2], 0x44
// 00566168  c68424a300000052     mov byte ptr [esp + 0xa3], 0x52
// 00566170  c644246049           mov byte ptr [esp + 0x60], 0x49
// 00566175  c644246144           mov byte ptr [esp + 0x61], 0x44
// 0056617a  c644246241           mov byte ptr [esp + 0x62], 0x41
// 0056617f  c644246354           mov byte ptr [esp + 0x63], 0x54
// 00566184  c644243049           mov byte ptr [esp + 0x30], 0x49
// 00566189  c644243145           mov byte ptr [esp + 0x31], 0x45
// 0056618e  c64424324e           mov byte ptr [esp + 0x32], 0x4e
// 00566193  c644243344           mov byte ptr [esp + 0x33], 0x44
// 00566198  c644241050           mov byte ptr [esp + 0x10], 0x50
// 0056619d  c64424114c           mov byte ptr [esp + 0x11], 0x4c
// 005661a2  c644241254           mov byte ptr [esp + 0x12], 0x54
// 005661a7  c644241345           mov byte ptr [esp + 0x13], 0x45
// 005661ac  c644247062           mov byte ptr [esp + 0x70], 0x62
// 005661b1  c64424714b           mov byte ptr [esp + 0x71], 0x4b
// 005661b6  c644247247           mov byte ptr [esp + 0x72], 0x47
// 005661bb  c644247344           mov byte ptr [esp + 0x73], 0x44
// 005661c0  c644244063           mov byte ptr [esp + 0x40], 0x63
// 005661c5  c644244148           mov byte ptr [esp + 0x41], 0x48
// 005661ca  c644244252           mov byte ptr [esp + 0x42], 0x52
// 005661cf  c64424434d           mov byte ptr [esp + 0x43], 0x4d
// 005661d4  c684249000000067     mov byte ptr [esp + 0x90], 0x67
// 005661dc  c684249100000041     mov byte ptr [esp + 0x91], 0x41
// 005661e4  c68424920000004d     mov byte ptr [esp + 0x92], 0x4d
// 005661ec  c684249300000041     mov byte ptr [esp + 0x93], 0x41
// 005661f4  c644245068           mov byte ptr [esp + 0x50], 0x68
// 005661f9  c644245149           mov byte ptr [esp + 0x51], 0x49
// 005661fe  c644245253           mov byte ptr [esp + 0x52], 0x53
// 00566203  c644245354           mov byte ptr [esp + 0x53], 0x54
// 00566208  c644245869           mov byte ptr [esp + 0x58], 0x69
// 0056620d  c644245943           mov byte ptr [esp + 0x59], 0x43
// 00566212  c644245a43           mov byte ptr [esp + 0x5a], 0x43
// 00566217  c644245b50           mov byte ptr [esp + 0x5b], 0x50
// 0056621c  c68424800000006f     mov byte ptr [esp + 0x80], 0x6f
// 00566224  c684248100000046     mov byte ptr [esp + 0x81], 0x46
// 0056622c  c684248200000046     mov byte ptr [esp + 0x82], 0x46
// 00566234  889c2483000000       mov byte ptr [esp + 0x83], bl
// 0056623b  c644241870           mov byte ptr [esp + 0x18], 0x70
// 00566240  c644241943           mov byte ptr [esp + 0x19], 0x43
// 00566245  c644241a41           mov byte ptr [esp + 0x1a], 0x41
// 0056624a  c644241b4c           mov byte ptr [esp + 0x1b], 0x4c
// 0056624f  c644242870           mov byte ptr [esp + 0x28], 0x70
// 00566254  c644242948           mov byte ptr [esp + 0x29], 0x48
// 00566259  c644242a59           mov byte ptr [esp + 0x2a], 0x59
// 0056625e  885c242b             mov byte ptr [esp + 0x2b], bl
// 00566262  885c2438             mov byte ptr [esp + 0x38], bl
// 00566266  c644243942           mov byte ptr [esp + 0x39], 0x42
// 0056626b  c644243a49           mov byte ptr [esp + 0x3a], 0x49
// 00566270  c644243b54           mov byte ptr [esp + 0x3b], 0x54
// 00566275  885c2420             mov byte ptr [esp + 0x20], bl
// 00566279  c644242143           mov byte ptr [esp + 0x21], 0x43
// 0056627e  c644242241           mov byte ptr [esp + 0x22], 0x41
// 00566283  c64424234c           mov byte ptr [esp + 0x23], 0x4c
// 00566288  885c2468             mov byte ptr [esp + 0x68], bl
// 0056628c  c644246950           mov byte ptr [esp + 0x69], 0x50
// 00566291  c644246a4c           mov byte ptr [esp + 0x6a], 0x4c
// 00566296  c644246b54           mov byte ptr [esp + 0x6b], 0x54
// 0056629b  885c2448             mov byte ptr [esp + 0x48], bl
// 0056629f  c644244952           mov byte ptr [esp + 0x49], 0x52
// 005662a4  c644244a47           mov byte ptr [esp + 0x4a], 0x47
// 005662a9  c644244b42           mov byte ptr [esp + 0x4b], 0x42
// 005662ae  c644247874           mov byte ptr [esp + 0x78], 0x74
// 005662b3  c644247945           mov byte ptr [esp + 0x79], 0x45
// 005662b8  c644247a58           mov byte ptr [esp + 0x7a], 0x58
// 005662bd  c644247b74           mov byte ptr [esp + 0x7b], 0x74
// 005662c2  c684248800000074     mov byte ptr [esp + 0x88], 0x74
// 005662ca  c684248900000049     mov byte ptr [esp + 0x89], 0x49
// 005662d2  c684248a0000004d     mov byte ptr [esp + 0x8a], 0x4d
// 005662da  c684248b00000045     mov byte ptr [esp + 0x8b], 0x45
// 005662e2  c684249800000074     mov byte ptr [esp + 0x98], 0x74
// 005662ea  c684249900000052     mov byte ptr [esp + 0x99], 0x52
// 005662f2  c684249a0000004e     mov byte ptr [esp + 0x9a], 0x4e
// 005662fa  c684249b00000053     mov byte ptr [esp + 0x9b], 0x53
// 00566302  c68424a80000007a     mov byte ptr [esp + 0xa8], 0x7a
// 0056630a  c68424a900000054     mov byte ptr [esp + 0xa9], 0x54
// 00566312  c68424aa00000058     mov byte ptr [esp + 0xaa], 0x58
// 0056631a  c68424ab00000074     mov byte ptr [esp + 0xab], 0x74
// 00566322  56                   push esi
// 00566323  e858210100           call 0x578480
// 00566328  8b6c2464             mov ebp, dword ptr [esp + 0x64]
// 0056632c  8d8e1c010000         lea ecx, [esi + 0x11c]
// 00566332  83c404               add esp, 4
// 00566335  8bf8                 mov edi, eax
// 00566337  3929                 cmp dword ptr [ecx], ebp
// 00566339  750f                 jne 0x56634a
// 0056633b  8b4668               mov eax, dword ptr [esi + 0x68]
// 0056633e  a808                 test al, 8
// 00566340  7408                 je 0x56634a
// 00566342  0d00200000           or eax, 0x2000
// 00566347  894668               mov dword ptr [esi + 0x68], eax
// 0056634a  8b01                 mov eax, dword ptr [ecx]
// 0056634c  3b8424a0000000       cmp eax, dword ptr [esp + 0xa0]
// 00566353  7517                 jne 0x56636c
// 00566355  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 0056635c  57                   push edi
// 0056635d  51                   push ecx
// 0056635e  56                   push esi
// 0056635f  e87c220100           call 0x5785e0
// 00566364  83c40c               add esp, 0xc
// 00566367  e9e4fdffff           jmp 0x566150
// 0056636c  3b442430             cmp eax, dword ptr [esp + 0x30]
// 00566370  7517                 jne 0x566389
// 00566372  8b9424b8000000       mov edx, dword ptr [esp + 0xb8]
// 00566379  57                   push edi
// 0056637a  52                   push edx
// 0056637b  56                   push esi
// 0056637c  e8bf250100           call 0x578940
// 00566381  83c40c               add esp, 0xc
// 00566384  e9c7fdffff           jmp 0x566150
// 00566389  51                   push ecx
// 0056638a  56                   push esi
// 0056638b  e8c0f0ffff           call 0x565450
// 00566390  83c408               add esp, 8
// 00566393  85c0                 test eax, eax
// 00566395  745f                 je 0x5663f6
// 00566397  39ae1c010000         cmp dword ptr [esi + 0x11c], ebp
// 0056639d  7504                 jne 0x5663a3
// 0056639f  834e6804             or dword ptr [esi + 0x68], 4
// 005663a3  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 005663aa  57                   push edi
// 005663ab  50                   push eax
// 005663ac  56                   push esi
// 005663ad  e84e450100           call 0x57a900
// 005663b2  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 005663b8  83c40c               add esp, 0xc
// 005663bb  3b442410             cmp eax, dword ptr [esp + 0x10]
// 005663bf  7509                 jne 0x5663ca
// 005663c1  834e6802             or dword ptr [esi + 0x68], 2
// 005663c5  e986fdffff           jmp 0x566150
// 005663ca  3bc5                 cmp eax, ebp
// 005663cc  0f857efdffff         jne 0x566150
// 005663d2  8b4668               mov eax, dword ptr [esi + 0x68]
// 005663d5  a801                 test al, 1
// 005663d7  0f852a020000         jne 0x566607
// 005663dd  680c2ba200           push 0xa22b0c
// 005663e2  56                   push esi
// 005663e3  e8c8b60000           call 0x571ab0
// 005663e8  83c408               add esp, 8
// 005663eb  5f                   pop edi
// 005663ec  5b                   pop ebx
// 005663ed  5d                   pop ebp
// 005663ee  5e                   pop esi
// 005663ef  81c4a0000000         add esp, 0xa0
// 005663f5  c3                   ret 
// 005663f6  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 005663fc  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00566400  7517                 jne 0x566419
// 00566402  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 00566409  57                   push edi
// 0056640a  51                   push ecx
// 0056640b  56                   push esi
// 0056640c  e88f230100           call 0x5787a0
// 00566411  83c40c               add esp, 0xc
// 00566414  e937fdffff           jmp 0x566150
// 00566419  3bc5                 cmp eax, ebp
// 0056641b  0f840c020000         je 0x56662d
// 00566421  57                   push edi
// 00566422  3b442474             cmp eax, dword ptr [esp + 0x74]
// 00566426  7516                 jne 0x56643e
// 00566428  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 0056642f  52                   push edx
// 00566430  56                   push esi
// 00566431  e8ea350100           call 0x579a20
// 00566436  83c40c               add esp, 0xc
// 00566439  e912fdffff           jmp 0x566150
// 0056643e  3b442444             cmp eax, dword ptr [esp + 0x44]
// 00566442  7516                 jne 0x56645a
// 00566444  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 0056644b  50                   push eax
// 0056644c  56                   push esi
// 0056644d  e84e280100           call 0x578ca0
// 00566452  83c40c               add esp, 0xc
// 00566455  e9f6fcffff           jmp 0x566150
// 0056645a  3b842494000000       cmp eax, dword ptr [esp + 0x94]
// 00566461  7516                 jne 0x566479
// 00566463  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 0056646a  51                   push ecx
// 0056646b  56                   push esi
// 0056646c  e81f250100           call 0x578990
// 00566471  83c40c               add esp, 0xc
// 00566474  e9d7fcffff           jmp 0x566150
// 00566479  3b442454             cmp eax, dword ptr [esp + 0x54]
// 0056647d  7516                 jne 0x566495
// 0056647f  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00566486  52                   push edx
// 00566487  56                   push esi
// 00566488  e8b3370100           call 0x579c40
// 0056648d  83c40c               add esp, 0xc
// 00566490  e9bbfcffff           jmp 0x566150
// 00566495  3b842484000000       cmp eax, dword ptr [esp + 0x84]
// 0056649c  7516                 jne 0x5664b4
// 0056649e  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 005664a5  50                   push eax
// 005664a6  56                   push esi
// 005664a7  e8343a0100           call 0x579ee0
// 005664ac  83c40c               add esp, 0xc
// 005664af  e99cfcffff           jmp 0x566150
// 005664b4  3b44241c             cmp eax, dword ptr [esp + 0x1c]
// 005664b8  7516                 jne 0x5664d0
// 005664ba  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 005664c1  51                   push ecx
// 005664c2  56                   push esi
// 005664c3  e8383b0100           call 0x57a000
// 005664c8  83c40c               add esp, 0xc
// 005664cb  e980fcffff           jmp 0x566150
// 005664d0  3b442424             cmp eax, dword ptr [esp + 0x24]
// 005664d4  7516                 jne 0x5664ec
// 005664d6  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 005664dd  52                   push edx
// 005664de  56                   push esi
// 005664df  e81c3e0100           call 0x57a300
// 005664e4  83c40c               add esp, 0xc
// 005664e7  e964fcffff           jmp 0x566150
// 005664ec  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 005664f0  7516                 jne 0x566508
// 005664f2  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 005664f9  50                   push eax
// 005664fa  56                   push esi
// 005664fb  e8c0380100           call 0x579dc0
// 00566500  83c40c               add esp, 0xc
// 00566503  e948fcffff           jmp 0x566150
// 00566508  3b44243c             cmp eax, dword ptr [esp + 0x3c]
// 0056650c  7516                 jne 0x566524
// 0056650e  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00566515  51                   push ecx
// 00566516  56                   push esi
// 00566517  e804260100           call 0x578b20
// 0056651c  83c40c               add esp, 0xc
// 0056651f  e92cfcffff           jmp 0x566150
// 00566524  3b44244c             cmp eax, dword ptr [esp + 0x4c]
// 00566528  7516                 jne 0x566540
// 0056652a  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00566531  52                   push edx
// 00566532  56                   push esi
// 00566533  e8c82b0100           call 0x579100
// 00566538  83c40c               add esp, 0xc
// 0056653b  e910fcffff           jmp 0x566150
// 00566540  3b44245c             cmp eax, dword ptr [esp + 0x5c]
// 00566544  7516                 jne 0x56655c
// 00566546  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 0056654d  50                   push eax
// 0056654e  56                   push esi
// 0056654f  e8bc2d0100           call 0x579310
// 00566554  83c40c               add esp, 0xc
// 00566557  e9f4fbffff           jmp 0x566150
// 0056655c  3b44246c             cmp eax, dword ptr [esp + 0x6c]
// 00566560  7516                 jne 0x566578
// 00566562  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 00566569  51                   push ecx
// 0056656a  56                   push esi
// 0056656b  e8a02f0100           call 0x579510
// 00566570  83c40c               add esp, 0xc
// 00566573  e9d8fbffff           jmp 0x566150
// 00566578  3b44247c             cmp eax, dword ptr [esp + 0x7c]
// 0056657c  7516                 jne 0x566594
// 0056657e  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 00566585  52                   push edx
// 00566586  56                   push esi
// 00566587  e894400100           call 0x57a620
// 0056658c  83c40c               add esp, 0xc
// 0056658f  e9bcfbffff           jmp 0x566150
// 00566594  3b84248c000000       cmp eax, dword ptr [esp + 0x8c]
// 0056659b  7516                 jne 0x5665b3
// 0056659d  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 005665a4  50                   push eax
// 005665a5  56                   push esi
// 005665a6  e8653f0100           call 0x57a510
// 005665ab  83c40c               add esp, 0xc
// 005665ae  e99dfbffff           jmp 0x566150
// 005665b3  3b84249c000000       cmp eax, dword ptr [esp + 0x9c]
// 005665ba  7516                 jne 0x5665d2
// 005665bc  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 005665c3  51                   push ecx
// 005665c4  56                   push esi
// 005665c5  e8e6310100           call 0x5797b0
// 005665ca  83c40c               add esp, 0xc
// 005665cd  e97efbffff           jmp 0x566150
// 005665d2  3b8424ac000000       cmp eax, dword ptr [esp + 0xac]
// 005665d9  7516                 jne 0x5665f1
// 005665db  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 005665e2  52                   push edx
// 005665e3  56                   push esi
// 005665e4  e857410100           call 0x57a740
// 005665e9  83c40c               add esp, 0xc
// 005665ec  e95ffbffff           jmp 0x566150
// 005665f1  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 005665f8  50                   push eax
// 005665f9  56                   push esi
// 005665fa  e801430100           call 0x57a900
// 005665ff  83c40c               add esp, 0xc
// 00566602  e949fbffff           jmp 0x566150
// 00566607  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 0056660e  7550                 jne 0x566660
// 00566610  a802                 test al, 2
// 00566612  754c                 jne 0x566660
// 00566614  68f02aa200           push 0xa22af0
// 00566619  56                   push esi
// 0056661a  e891b40000           call 0x571ab0
// 0056661f  83c408               add esp, 8
// 00566622  5f                   pop edi
// 00566623  5b                   pop ebx
// 00566624  5d                   pop ebp
// 00566625  5e                   pop esi
// 00566626  81c4a0000000         add esp, 0xa0
// 0056662c  c3                   ret 
// 0056662d  8b4668               mov eax, dword ptr [esi + 0x68]
// 00566630  a801                 test al, 1
// 00566632  7507                 jne 0x56663b
// 00566634  680c2ba200           push 0xa22b0c
// 00566639  eb12                 jmp 0x56664d
// 0056663b  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00566642  7512                 jne 0x566656
// 00566644  a802                 test al, 2
// 00566646  750e                 jne 0x566656
// 00566648  68f02aa200           push 0xa22af0
// 0056664d  56                   push esi
// 0056664e  e85db40000           call 0x571ab0
// 00566653  83c408               add esp, 8
// 00566656  834e6804             or dword ptr [esi + 0x68], 4
// 0056665a  89be0c010000         mov dword ptr [esi + 0x10c], edi
// 00566660  5f                   pop edi
// 00566661  5b                   pop ebx
// 00566662  5d                   pop ebp
// 00566663  5e                   pop esi
// 00566664  81c4a0000000         add esp, 0xa0
// 0056666a  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
