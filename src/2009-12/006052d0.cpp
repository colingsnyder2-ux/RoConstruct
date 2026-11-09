// from server: 100% by auto
// roc 2009-12 006052d0  unit: seg_00600000  size: 1006 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006052d0
//
// 006052d0  81eca0000000         sub esp, 0xa0
// 006052d6  56                   push esi
// 006052d7  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 006052de  85f6                 test esi, esi
// 006052e0  0f84d0030000         je 0x6056b6
// 006052e6  53                   push ebx
// 006052e7  55                   push ebp
// 006052e8  57                   push edi
// 006052e9  6a00                 push 0
// 006052eb  56                   push esi
// 006052ec  e8ff180100           call 0x616bf0
// 006052f1  8bac24c0000000       mov ebp, dword ptr [esp + 0xc0]
// 006052f8  83c408               add esp, 8
// 006052fb  b373                 mov bl, 0x73
// 006052fd  8d4900               lea ecx, [ecx]
// 00605300  c644246049           mov byte ptr [esp + 0x60], 0x49
// 00605305  c644246148           mov byte ptr [esp + 0x61], 0x48
// 0060530a  c644246244           mov byte ptr [esp + 0x62], 0x44
// 0060530f  c644246352           mov byte ptr [esp + 0x63], 0x52
// 00605314  c644241049           mov byte ptr [esp + 0x10], 0x49
// 00605319  c644241144           mov byte ptr [esp + 0x11], 0x44
// 0060531e  c644241241           mov byte ptr [esp + 0x12], 0x41
// 00605323  c644241354           mov byte ptr [esp + 0x13], 0x54
// 00605328  c644243049           mov byte ptr [esp + 0x30], 0x49
// 0060532d  c644243145           mov byte ptr [esp + 0x31], 0x45
// 00605332  c64424324e           mov byte ptr [esp + 0x32], 0x4e
// 00605337  c644243344           mov byte ptr [esp + 0x33], 0x44
// 0060533c  c644241850           mov byte ptr [esp + 0x18], 0x50
// 00605341  c64424194c           mov byte ptr [esp + 0x19], 0x4c
// 00605346  c644241a54           mov byte ptr [esp + 0x1a], 0x54
// 0060534b  c644241b45           mov byte ptr [esp + 0x1b], 0x45
// 00605350  c644247062           mov byte ptr [esp + 0x70], 0x62
// 00605355  c64424714b           mov byte ptr [esp + 0x71], 0x4b
// 0060535a  c644247247           mov byte ptr [esp + 0x72], 0x47
// 0060535f  c644247344           mov byte ptr [esp + 0x73], 0x44
// 00605364  c644244063           mov byte ptr [esp + 0x40], 0x63
// 00605369  c644244148           mov byte ptr [esp + 0x41], 0x48
// 0060536e  c644244252           mov byte ptr [esp + 0x42], 0x52
// 00605373  c64424434d           mov byte ptr [esp + 0x43], 0x4d
// 00605378  c684249000000067     mov byte ptr [esp + 0x90], 0x67
// 00605380  c684249100000041     mov byte ptr [esp + 0x91], 0x41
// 00605388  c68424920000004d     mov byte ptr [esp + 0x92], 0x4d
// 00605390  c684249300000041     mov byte ptr [esp + 0x93], 0x41
// 00605398  c644245068           mov byte ptr [esp + 0x50], 0x68
// 0060539d  c644245149           mov byte ptr [esp + 0x51], 0x49
// 006053a2  c644245253           mov byte ptr [esp + 0x52], 0x53
// 006053a7  c644245354           mov byte ptr [esp + 0x53], 0x54
// 006053ac  c644245869           mov byte ptr [esp + 0x58], 0x69
// 006053b1  c644245943           mov byte ptr [esp + 0x59], 0x43
// 006053b6  c644245a43           mov byte ptr [esp + 0x5a], 0x43
// 006053bb  c644245b50           mov byte ptr [esp + 0x5b], 0x50
// 006053c0  c68424800000006f     mov byte ptr [esp + 0x80], 0x6f
// 006053c8  c684248100000046     mov byte ptr [esp + 0x81], 0x46
// 006053d0  c684248200000046     mov byte ptr [esp + 0x82], 0x46
// 006053d8  889c2483000000       mov byte ptr [esp + 0x83], bl
// 006053df  c644242070           mov byte ptr [esp + 0x20], 0x70
// 006053e4  c644242143           mov byte ptr [esp + 0x21], 0x43
// 006053e9  c644242241           mov byte ptr [esp + 0x22], 0x41
// 006053ee  c64424234c           mov byte ptr [esp + 0x23], 0x4c
// 006053f3  c644242870           mov byte ptr [esp + 0x28], 0x70
// 006053f8  c644242948           mov byte ptr [esp + 0x29], 0x48
// 006053fd  c644242a59           mov byte ptr [esp + 0x2a], 0x59
// 00605402  885c242b             mov byte ptr [esp + 0x2b], bl
// 00605406  885c2438             mov byte ptr [esp + 0x38], bl
// 0060540a  c644243942           mov byte ptr [esp + 0x39], 0x42
// 0060540f  c644243a49           mov byte ptr [esp + 0x3a], 0x49
// 00605414  c644243b54           mov byte ptr [esp + 0x3b], 0x54
// 00605419  889c24a0000000       mov byte ptr [esp + 0xa0], bl
// 00605420  c68424a100000043     mov byte ptr [esp + 0xa1], 0x43
// 00605428  c68424a200000041     mov byte ptr [esp + 0xa2], 0x41
// 00605430  c68424a30000004c     mov byte ptr [esp + 0xa3], 0x4c
// 00605438  885c2468             mov byte ptr [esp + 0x68], bl
// 0060543c  c644246950           mov byte ptr [esp + 0x69], 0x50
// 00605441  c644246a4c           mov byte ptr [esp + 0x6a], 0x4c
// 00605446  c644246b54           mov byte ptr [esp + 0x6b], 0x54
// 0060544b  885c2448             mov byte ptr [esp + 0x48], bl
// 0060544f  c644244952           mov byte ptr [esp + 0x49], 0x52
// 00605454  c644244a47           mov byte ptr [esp + 0x4a], 0x47
// 00605459  c644244b42           mov byte ptr [esp + 0x4b], 0x42
// 0060545e  c644247874           mov byte ptr [esp + 0x78], 0x74
// 00605463  c644247945           mov byte ptr [esp + 0x79], 0x45
// 00605468  c644247a58           mov byte ptr [esp + 0x7a], 0x58
// 0060546d  c644247b74           mov byte ptr [esp + 0x7b], 0x74
// 00605472  c684248800000074     mov byte ptr [esp + 0x88], 0x74
// 0060547a  c684248900000049     mov byte ptr [esp + 0x89], 0x49
// 00605482  c684248a0000004d     mov byte ptr [esp + 0x8a], 0x4d
// 0060548a  c684248b00000045     mov byte ptr [esp + 0x8b], 0x45
// 00605492  c684249800000074     mov byte ptr [esp + 0x98], 0x74
// 0060549a  c684249900000052     mov byte ptr [esp + 0x99], 0x52
// 006054a2  c684249a0000004e     mov byte ptr [esp + 0x9a], 0x4e
// 006054aa  c684249b00000053     mov byte ptr [esp + 0x9b], 0x53
// 006054b2  c68424a80000007a     mov byte ptr [esp + 0xa8], 0x7a
// 006054ba  c68424a900000054     mov byte ptr [esp + 0xa9], 0x54
// 006054c2  c68424aa00000058     mov byte ptr [esp + 0xaa], 0x58
// 006054ca  c68424ab00000074     mov byte ptr [esp + 0xab], 0x74
// 006054d2  56                   push esi
// 006054d3  e888160100           call 0x616b60
// 006054d8  8d8e1c010000         lea ecx, [esi + 0x11c]
// 006054de  8bf8                 mov edi, eax
// 006054e0  8b01                 mov eax, dword ptr [ecx]
// 006054e2  83c404               add esp, 4
// 006054e5  3b442460             cmp eax, dword ptr [esp + 0x60]
// 006054e9  750d                 jne 0x6054f8
// 006054eb  57                   push edi
// 006054ec  55                   push ebp
// 006054ed  56                   push esi
// 006054ee  e8cd170100           call 0x616cc0
// 006054f3  e9ae010000           jmp 0x6056a6
// 006054f8  3b442430             cmp eax, dword ptr [esp + 0x30]
// 006054fc  750d                 jne 0x60550b
// 006054fe  57                   push edi
// 006054ff  55                   push ebp
// 00605500  56                   push esi
// 00605501  e81a1b0100           call 0x617020
// 00605506  e99b010000           jmp 0x6056a6
// 0060550b  51                   push ecx
// 0060550c  56                   push esi
// 0060550d  e8cee5ffff           call 0x603ae0
// 00605512  83c408               add esp, 8
// 00605515  85c0                 test eax, eax
// 00605517  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0060551d  7445                 je 0x605564
// 0060551f  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00605523  751b                 jne 0x605540
// 00605525  85ff                 test edi, edi
// 00605527  7709                 ja 0x605532
// 00605529  f7466800200000       test dword ptr [esi + 0x68], 0x2000
// 00605530  740e                 je 0x605540
// 00605532  68b04e9c00           push 0x9c4eb0
// 00605537  56                   push esi
// 00605538  e853ac0000           call 0x610190
// 0060553d  83c408               add esp, 8
// 00605540  57                   push edi
// 00605541  55                   push ebp
// 00605542  56                   push esi
// 00605543  e8983a0100           call 0x618fe0
// 00605548  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 0060554e  83c40c               add esp, 0xc
// 00605551  3b4c2418             cmp ecx, dword ptr [esp + 0x18]
// 00605555  0f854e010000         jne 0x6056a9
// 0060555b  834e6802             or dword ptr [esi + 0x68], 2
// 0060555f  e945010000           jmp 0x6056a9
// 00605564  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00605568  752a                 jne 0x605594
// 0060556a  85ff                 test edi, edi
// 0060556c  7709                 ja 0x605577
// 0060556e  f7466800200000       test dword ptr [esi + 0x68], 0x2000
// 00605575  740e                 je 0x605585
// 00605577  68b04e9c00           push 0x9c4eb0
// 0060557c  56                   push esi
// 0060557d  e80eac0000           call 0x610190
// 00605582  83c408               add esp, 8
// 00605585  57                   push edi
// 00605586  56                   push esi
// 00605587  e864160100           call 0x616bf0
// 0060558c  83c408               add esp, 8
// 0060558f  e915010000           jmp 0x6056a9
// 00605594  57                   push edi
// 00605595  55                   push ebp
// 00605596  56                   push esi
// 00605597  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0060559b  750a                 jne 0x6055a7
// 0060559d  e8de180100           call 0x616e80
// 006055a2  e9ff000000           jmp 0x6056a6
// 006055a7  3b44247c             cmp eax, dword ptr [esp + 0x7c]
// 006055ab  750a                 jne 0x6055b7
// 006055ad  e84e2b0100           call 0x618100
// 006055b2  e9ef000000           jmp 0x6056a6
// 006055b7  3b44244c             cmp eax, dword ptr [esp + 0x4c]
// 006055bb  750a                 jne 0x6055c7
// 006055bd  e8be1d0100           call 0x617380
// 006055c2  e9df000000           jmp 0x6056a6
// 006055c7  3b84249c000000       cmp eax, dword ptr [esp + 0x9c]
// 006055ce  750a                 jne 0x6055da
// 006055d0  e89b1a0100           call 0x617070
// 006055d5  e9cc000000           jmp 0x6056a6
// 006055da  3b44245c             cmp eax, dword ptr [esp + 0x5c]
// 006055de  750a                 jne 0x6055ea
// 006055e0  e83b2d0100           call 0x618320
// 006055e5  e9bc000000           jmp 0x6056a6
// 006055ea  3b84248c000000       cmp eax, dword ptr [esp + 0x8c]
// 006055f1  750a                 jne 0x6055fd
// 006055f3  e8c82f0100           call 0x6185c0
// 006055f8  e9a9000000           jmp 0x6056a6
// 006055fd  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 00605601  750a                 jne 0x60560d
// 00605603  e8d8300100           call 0x6186e0
// 00605608  e999000000           jmp 0x6056a6
// 0060560d  3b8424ac000000       cmp eax, dword ptr [esp + 0xac]
// 00605614  750a                 jne 0x605620
// 00605616  e8c5330100           call 0x6189e0
// 0060561b  e986000000           jmp 0x6056a6
// 00605620  3b442434             cmp eax, dword ptr [esp + 0x34]
// 00605624  7507                 jne 0x60562d
// 00605626  e8752e0100           call 0x6184a0
// 0060562b  eb79                 jmp 0x6056a6
// 0060562d  3b442444             cmp eax, dword ptr [esp + 0x44]
// 00605631  7507                 jne 0x60563a
// 00605633  e8c81b0100           call 0x617200
// 00605638  eb6c                 jmp 0x6056a6
// 0060563a  3b442454             cmp eax, dword ptr [esp + 0x54]
// 0060563e  7507                 jne 0x605647
// 00605640  e89b210100           call 0x6177e0
// 00605645  eb5f                 jmp 0x6056a6
// 00605647  3b442464             cmp eax, dword ptr [esp + 0x64]
// 0060564b  7507                 jne 0x605654
// 0060564d  e89e230100           call 0x6179f0
// 00605652  eb52                 jmp 0x6056a6
// 00605654  3b442474             cmp eax, dword ptr [esp + 0x74]
// 00605658  7507                 jne 0x605661
// 0060565a  e891250100           call 0x617bf0
// 0060565f  eb45                 jmp 0x6056a6
// 00605661  3b842484000000       cmp eax, dword ptr [esp + 0x84]
// 00605668  7507                 jne 0x605671
// 0060566a  e891360100           call 0x618d00
// 0060566f  eb35                 jmp 0x6056a6
// 00605671  3b842494000000       cmp eax, dword ptr [esp + 0x94]
// 00605678  7507                 jne 0x605681
// 0060567a  e871350100           call 0x618bf0
// 0060567f  eb25                 jmp 0x6056a6
// 00605681  3b8424a4000000       cmp eax, dword ptr [esp + 0xa4]
// 00605688  7507                 jne 0x605691
// 0060568a  e801280100           call 0x617e90
// 0060568f  eb15                 jmp 0x6056a6
// 00605691  3b8424b4000000       cmp eax, dword ptr [esp + 0xb4]
// 00605698  7507                 jne 0x6056a1
// 0060569a  e881370100           call 0x618e20
// 0060569f  eb05                 jmp 0x6056a6
// 006056a1  e83a390100           call 0x618fe0
// 006056a6  83c40c               add esp, 0xc
// 006056a9  f6466810             test byte ptr [esi + 0x68], 0x10
// 006056ad  0f844dfcffff         je 0x605300
// 006056b3  5f                   pop edi
// 006056b4  5d                   pop ebp
// 006056b5  5b                   pop ebx
// 006056b6  5e                   pop esi
// 006056b7  81c4a0000000         add esp, 0xa0
// 006056bd  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
