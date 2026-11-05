// from server: 100% by auto
// roc 2012-06 00648630  unit: seg_00640000  size: 1006 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00648630
//
// 00648630  81eca0000000         sub esp, 0xa0
// 00648636  56                   push esi
// 00648637  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 0064863e  85f6                 test esi, esi
// 00648640  0f84d0030000         je 0x648a16
// 00648646  53                   push ebx
// 00648647  55                   push ebp
// 00648648  57                   push edi
// 00648649  6a00                 push 0
// 0064864b  56                   push esi
// 0064864c  e8ff280100           call 0x65af50
// 00648651  8bac24c0000000       mov ebp, dword ptr [esp + 0xc0]
// 00648658  83c408               add esp, 8
// 0064865b  b373                 mov bl, 0x73
// 0064865d  8d4900               lea ecx, [ecx]
// 00648660  c644246049           mov byte ptr [esp + 0x60], 0x49
// 00648665  c644246148           mov byte ptr [esp + 0x61], 0x48
// 0064866a  c644246244           mov byte ptr [esp + 0x62], 0x44
// 0064866f  c644246352           mov byte ptr [esp + 0x63], 0x52
// 00648674  c644241049           mov byte ptr [esp + 0x10], 0x49
// 00648679  c644241144           mov byte ptr [esp + 0x11], 0x44
// 0064867e  c644241241           mov byte ptr [esp + 0x12], 0x41
// 00648683  c644241354           mov byte ptr [esp + 0x13], 0x54
// 00648688  c644243049           mov byte ptr [esp + 0x30], 0x49
// 0064868d  c644243145           mov byte ptr [esp + 0x31], 0x45
// 00648692  c64424324e           mov byte ptr [esp + 0x32], 0x4e
// 00648697  c644243344           mov byte ptr [esp + 0x33], 0x44
// 0064869c  c644241850           mov byte ptr [esp + 0x18], 0x50
// 006486a1  c64424194c           mov byte ptr [esp + 0x19], 0x4c
// 006486a6  c644241a54           mov byte ptr [esp + 0x1a], 0x54
// 006486ab  c644241b45           mov byte ptr [esp + 0x1b], 0x45
// 006486b0  c644247062           mov byte ptr [esp + 0x70], 0x62
// 006486b5  c64424714b           mov byte ptr [esp + 0x71], 0x4b
// 006486ba  c644247247           mov byte ptr [esp + 0x72], 0x47
// 006486bf  c644247344           mov byte ptr [esp + 0x73], 0x44
// 006486c4  c644244063           mov byte ptr [esp + 0x40], 0x63
// 006486c9  c644244148           mov byte ptr [esp + 0x41], 0x48
// 006486ce  c644244252           mov byte ptr [esp + 0x42], 0x52
// 006486d3  c64424434d           mov byte ptr [esp + 0x43], 0x4d
// 006486d8  c684249000000067     mov byte ptr [esp + 0x90], 0x67
// 006486e0  c684249100000041     mov byte ptr [esp + 0x91], 0x41
// 006486e8  c68424920000004d     mov byte ptr [esp + 0x92], 0x4d
// 006486f0  c684249300000041     mov byte ptr [esp + 0x93], 0x41
// 006486f8  c644245068           mov byte ptr [esp + 0x50], 0x68
// 006486fd  c644245149           mov byte ptr [esp + 0x51], 0x49
// 00648702  c644245253           mov byte ptr [esp + 0x52], 0x53
// 00648707  c644245354           mov byte ptr [esp + 0x53], 0x54
// 0064870c  c644245869           mov byte ptr [esp + 0x58], 0x69
// 00648711  c644245943           mov byte ptr [esp + 0x59], 0x43
// 00648716  c644245a43           mov byte ptr [esp + 0x5a], 0x43
// 0064871b  c644245b50           mov byte ptr [esp + 0x5b], 0x50
// 00648720  c68424800000006f     mov byte ptr [esp + 0x80], 0x6f
// 00648728  c684248100000046     mov byte ptr [esp + 0x81], 0x46
// 00648730  c684248200000046     mov byte ptr [esp + 0x82], 0x46
// 00648738  889c2483000000       mov byte ptr [esp + 0x83], bl
// 0064873f  c644242070           mov byte ptr [esp + 0x20], 0x70
// 00648744  c644242143           mov byte ptr [esp + 0x21], 0x43
// 00648749  c644242241           mov byte ptr [esp + 0x22], 0x41
// 0064874e  c64424234c           mov byte ptr [esp + 0x23], 0x4c
// 00648753  c644242870           mov byte ptr [esp + 0x28], 0x70
// 00648758  c644242948           mov byte ptr [esp + 0x29], 0x48
// 0064875d  c644242a59           mov byte ptr [esp + 0x2a], 0x59
// 00648762  885c242b             mov byte ptr [esp + 0x2b], bl
// 00648766  885c2438             mov byte ptr [esp + 0x38], bl
// 0064876a  c644243942           mov byte ptr [esp + 0x39], 0x42
// 0064876f  c644243a49           mov byte ptr [esp + 0x3a], 0x49
// 00648774  c644243b54           mov byte ptr [esp + 0x3b], 0x54
// 00648779  889c24a0000000       mov byte ptr [esp + 0xa0], bl
// 00648780  c68424a100000043     mov byte ptr [esp + 0xa1], 0x43
// 00648788  c68424a200000041     mov byte ptr [esp + 0xa2], 0x41
// 00648790  c68424a30000004c     mov byte ptr [esp + 0xa3], 0x4c
// 00648798  885c2468             mov byte ptr [esp + 0x68], bl
// 0064879c  c644246950           mov byte ptr [esp + 0x69], 0x50
// 006487a1  c644246a4c           mov byte ptr [esp + 0x6a], 0x4c
// 006487a6  c644246b54           mov byte ptr [esp + 0x6b], 0x54
// 006487ab  885c2448             mov byte ptr [esp + 0x48], bl
// 006487af  c644244952           mov byte ptr [esp + 0x49], 0x52
// 006487b4  c644244a47           mov byte ptr [esp + 0x4a], 0x47
// 006487b9  c644244b42           mov byte ptr [esp + 0x4b], 0x42
// 006487be  c644247874           mov byte ptr [esp + 0x78], 0x74
// 006487c3  c644247945           mov byte ptr [esp + 0x79], 0x45
// 006487c8  c644247a58           mov byte ptr [esp + 0x7a], 0x58
// 006487cd  c644247b74           mov byte ptr [esp + 0x7b], 0x74
// 006487d2  c684248800000074     mov byte ptr [esp + 0x88], 0x74
// 006487da  c684248900000049     mov byte ptr [esp + 0x89], 0x49
// 006487e2  c684248a0000004d     mov byte ptr [esp + 0x8a], 0x4d
// 006487ea  c684248b00000045     mov byte ptr [esp + 0x8b], 0x45
// 006487f2  c684249800000074     mov byte ptr [esp + 0x98], 0x74
// 006487fa  c684249900000052     mov byte ptr [esp + 0x99], 0x52
// 00648802  c684249a0000004e     mov byte ptr [esp + 0x9a], 0x4e
// 0064880a  c684249b00000053     mov byte ptr [esp + 0x9b], 0x53
// 00648812  c68424a80000007a     mov byte ptr [esp + 0xa8], 0x7a
// 0064881a  c68424a900000054     mov byte ptr [esp + 0xa9], 0x54
// 00648822  c68424aa00000058     mov byte ptr [esp + 0xaa], 0x58
// 0064882a  c68424ab00000074     mov byte ptr [esp + 0xab], 0x74
// 00648832  56                   push esi
// 00648833  e888260100           call 0x65aec0
// 00648838  8d8e1c010000         lea ecx, [esi + 0x11c]
// 0064883e  8bf8                 mov edi, eax
// 00648840  8b01                 mov eax, dword ptr [ecx]
// 00648842  83c404               add esp, 4
// 00648845  3b442460             cmp eax, dword ptr [esp + 0x60]
// 00648849  750d                 jne 0x648858
// 0064884b  57                   push edi
// 0064884c  55                   push ebp
// 0064884d  56                   push esi
// 0064884e  e8cd270100           call 0x65b020
// 00648853  e9ae010000           jmp 0x648a06
// 00648858  3b442430             cmp eax, dword ptr [esp + 0x30]
// 0064885c  750d                 jne 0x64886b
// 0064885e  57                   push edi
// 0064885f  55                   push ebp
// 00648860  56                   push esi
// 00648861  e81a2b0100           call 0x65b380
// 00648866  e99b010000           jmp 0x648a06
// 0064886b  51                   push ecx
// 0064886c  56                   push esi
// 0064886d  e88e5affff           call 0x63e300
// 00648872  83c408               add esp, 8
// 00648875  85c0                 test eax, eax
// 00648877  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0064887d  7445                 je 0x6488c4
// 0064887f  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00648883  751b                 jne 0x6488a0
// 00648885  85ff                 test edi, edi
// 00648887  7709                 ja 0x648892
// 00648889  f7466800200000       test dword ptr [esi + 0x68], 0x2000
// 00648890  740e                 je 0x6488a0
// 00648892  683866b800           push 0xb86638
// 00648897  56                   push esi
// 00648898  e813590000           call 0x64e1b0
// 0064889d  83c408               add esp, 8
// 006488a0  57                   push edi
// 006488a1  55                   push ebp
// 006488a2  56                   push esi
// 006488a3  e8c84a0100           call 0x65d370
// 006488a8  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 006488ae  83c40c               add esp, 0xc
// 006488b1  3b4c2418             cmp ecx, dword ptr [esp + 0x18]
// 006488b5  0f854e010000         jne 0x648a09
// 006488bb  834e6802             or dword ptr [esi + 0x68], 2
// 006488bf  e945010000           jmp 0x648a09
// 006488c4  3b442410             cmp eax, dword ptr [esp + 0x10]
// 006488c8  752a                 jne 0x6488f4
// 006488ca  85ff                 test edi, edi
// 006488cc  7709                 ja 0x6488d7
// 006488ce  f7466800200000       test dword ptr [esi + 0x68], 0x2000
// 006488d5  740e                 je 0x6488e5
// 006488d7  683866b800           push 0xb86638
// 006488dc  56                   push esi
// 006488dd  e8ce580000           call 0x64e1b0
// 006488e2  83c408               add esp, 8
// 006488e5  57                   push edi
// 006488e6  56                   push esi
// 006488e7  e864260100           call 0x65af50
// 006488ec  83c408               add esp, 8
// 006488ef  e915010000           jmp 0x648a09
// 006488f4  57                   push edi
// 006488f5  55                   push ebp
// 006488f6  56                   push esi
// 006488f7  3b442424             cmp eax, dword ptr [esp + 0x24]
// 006488fb  750a                 jne 0x648907
// 006488fd  e8de280100           call 0x65b1e0
// 00648902  e9ff000000           jmp 0x648a06
// 00648907  3b44247c             cmp eax, dword ptr [esp + 0x7c]
// 0064890b  750a                 jne 0x648917
// 0064890d  e82e3b0100           call 0x65c440
// 00648912  e9ef000000           jmp 0x648a06
// 00648917  3b44244c             cmp eax, dword ptr [esp + 0x4c]
// 0064891b  750a                 jne 0x648927
// 0064891d  e8be2d0100           call 0x65b6e0
// 00648922  e9df000000           jmp 0x648a06
// 00648927  3b84249c000000       cmp eax, dword ptr [esp + 0x9c]
// 0064892e  750a                 jne 0x64893a
// 00648930  e89b2a0100           call 0x65b3d0
// 00648935  e9cc000000           jmp 0x648a06
// 0064893a  3b44245c             cmp eax, dword ptr [esp + 0x5c]
// 0064893e  750a                 jne 0x64894a
// 00648940  e81b3d0100           call 0x65c660
// 00648945  e9bc000000           jmp 0x648a06
// 0064894a  3b84248c000000       cmp eax, dword ptr [esp + 0x8c]
// 00648951  750a                 jne 0x64895d
// 00648953  e8a83f0100           call 0x65c900
// 00648958  e9a9000000           jmp 0x648a06
// 0064895d  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 00648961  750a                 jne 0x64896d
// 00648963  e8b8400100           call 0x65ca20
// 00648968  e999000000           jmp 0x648a06
// 0064896d  3b8424ac000000       cmp eax, dword ptr [esp + 0xac]
// 00648974  750a                 jne 0x648980
// 00648976  e8a5430100           call 0x65cd20
// 0064897b  e986000000           jmp 0x648a06
// 00648980  3b442434             cmp eax, dword ptr [esp + 0x34]
// 00648984  7507                 jne 0x64898d
// 00648986  e8553e0100           call 0x65c7e0
// 0064898b  eb79                 jmp 0x648a06
// 0064898d  3b442444             cmp eax, dword ptr [esp + 0x44]
// 00648991  7507                 jne 0x64899a
// 00648993  e8c82b0100           call 0x65b560
// 00648998  eb6c                 jmp 0x648a06
// 0064899a  3b442454             cmp eax, dword ptr [esp + 0x54]
// 0064899e  7507                 jne 0x6489a7
// 006489a0  e87b310100           call 0x65bb20
// 006489a5  eb5f                 jmp 0x648a06
// 006489a7  3b442464             cmp eax, dword ptr [esp + 0x64]
// 006489ab  7507                 jne 0x6489b4
// 006489ad  e87e330100           call 0x65bd30
// 006489b2  eb52                 jmp 0x648a06
// 006489b4  3b442474             cmp eax, dword ptr [esp + 0x74]
// 006489b8  7507                 jne 0x6489c1
// 006489ba  e871350100           call 0x65bf30
// 006489bf  eb45                 jmp 0x648a06
// 006489c1  3b842484000000       cmp eax, dword ptr [esp + 0x84]
// 006489c8  7507                 jne 0x6489d1
// 006489ca  e871460100           call 0x65d040
// 006489cf  eb35                 jmp 0x648a06
// 006489d1  3b842494000000       cmp eax, dword ptr [esp + 0x94]
// 006489d8  7507                 jne 0x6489e1
// 006489da  e851450100           call 0x65cf30
// 006489df  eb25                 jmp 0x648a06
// 006489e1  3b8424a4000000       cmp eax, dword ptr [esp + 0xa4]
// 006489e8  7507                 jne 0x6489f1
// 006489ea  e8e1370100           call 0x65c1d0
// 006489ef  eb15                 jmp 0x648a06
// 006489f1  3b8424b4000000       cmp eax, dword ptr [esp + 0xb4]
// 006489f8  7507                 jne 0x648a01
// 006489fa  e8b1470100           call 0x65d1b0
// 006489ff  eb05                 jmp 0x648a06
// 00648a01  e86a490100           call 0x65d370
// 00648a06  83c40c               add esp, 0xc
// 00648a09  f6466810             test byte ptr [esi + 0x68], 0x10
// 00648a0d  0f844dfcffff         je 0x648660
// 00648a13  5f                   pop edi
// 00648a14  5d                   pop ebp
// 00648a15  5b                   pop ebx
// 00648a16  5e                   pop esi
// 00648a17  81c4a0000000         add esp, 0xa0
// 00648a1d  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
