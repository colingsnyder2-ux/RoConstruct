// from server: 100% by auto
// roc 2009-06 00583520  unit: seg_00580000  size: 1006 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00583520
//
// 00583520  81eca0000000         sub esp, 0xa0
// 00583526  56                   push esi
// 00583527  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 0058352e  85f6                 test esi, esi
// 00583530  0f84d0030000         je 0x583906
// 00583536  53                   push ebx
// 00583537  55                   push ebp
// 00583538  57                   push edi
// 00583539  6a00                 push 0
// 0058353b  56                   push esi
// 0058353c  e89f160100           call 0x594be0
// 00583541  8bac24c0000000       mov ebp, dword ptr [esp + 0xc0]
// 00583548  83c408               add esp, 8
// 0058354b  b373                 mov bl, 0x73
// 0058354d  8d4900               lea ecx, [ecx]
// 00583550  c644246049           mov byte ptr [esp + 0x60], 0x49
// 00583555  c644246148           mov byte ptr [esp + 0x61], 0x48
// 0058355a  c644246244           mov byte ptr [esp + 0x62], 0x44
// 0058355f  c644246352           mov byte ptr [esp + 0x63], 0x52
// 00583564  c644241049           mov byte ptr [esp + 0x10], 0x49
// 00583569  c644241144           mov byte ptr [esp + 0x11], 0x44
// 0058356e  c644241241           mov byte ptr [esp + 0x12], 0x41
// 00583573  c644241354           mov byte ptr [esp + 0x13], 0x54
// 00583578  c644243049           mov byte ptr [esp + 0x30], 0x49
// 0058357d  c644243145           mov byte ptr [esp + 0x31], 0x45
// 00583582  c64424324e           mov byte ptr [esp + 0x32], 0x4e
// 00583587  c644243344           mov byte ptr [esp + 0x33], 0x44
// 0058358c  c644241850           mov byte ptr [esp + 0x18], 0x50
// 00583591  c64424194c           mov byte ptr [esp + 0x19], 0x4c
// 00583596  c644241a54           mov byte ptr [esp + 0x1a], 0x54
// 0058359b  c644241b45           mov byte ptr [esp + 0x1b], 0x45
// 005835a0  c644247062           mov byte ptr [esp + 0x70], 0x62
// 005835a5  c64424714b           mov byte ptr [esp + 0x71], 0x4b
// 005835aa  c644247247           mov byte ptr [esp + 0x72], 0x47
// 005835af  c644247344           mov byte ptr [esp + 0x73], 0x44
// 005835b4  c644244063           mov byte ptr [esp + 0x40], 0x63
// 005835b9  c644244148           mov byte ptr [esp + 0x41], 0x48
// 005835be  c644244252           mov byte ptr [esp + 0x42], 0x52
// 005835c3  c64424434d           mov byte ptr [esp + 0x43], 0x4d
// 005835c8  c684249000000067     mov byte ptr [esp + 0x90], 0x67
// 005835d0  c684249100000041     mov byte ptr [esp + 0x91], 0x41
// 005835d8  c68424920000004d     mov byte ptr [esp + 0x92], 0x4d
// 005835e0  c684249300000041     mov byte ptr [esp + 0x93], 0x41
// 005835e8  c644245068           mov byte ptr [esp + 0x50], 0x68
// 005835ed  c644245149           mov byte ptr [esp + 0x51], 0x49
// 005835f2  c644245253           mov byte ptr [esp + 0x52], 0x53
// 005835f7  c644245354           mov byte ptr [esp + 0x53], 0x54
// 005835fc  c644245869           mov byte ptr [esp + 0x58], 0x69
// 00583601  c644245943           mov byte ptr [esp + 0x59], 0x43
// 00583606  c644245a43           mov byte ptr [esp + 0x5a], 0x43
// 0058360b  c644245b50           mov byte ptr [esp + 0x5b], 0x50
// 00583610  c68424800000006f     mov byte ptr [esp + 0x80], 0x6f
// 00583618  c684248100000046     mov byte ptr [esp + 0x81], 0x46
// 00583620  c684248200000046     mov byte ptr [esp + 0x82], 0x46
// 00583628  889c2483000000       mov byte ptr [esp + 0x83], bl
// 0058362f  c644242070           mov byte ptr [esp + 0x20], 0x70
// 00583634  c644242143           mov byte ptr [esp + 0x21], 0x43
// 00583639  c644242241           mov byte ptr [esp + 0x22], 0x41
// 0058363e  c64424234c           mov byte ptr [esp + 0x23], 0x4c
// 00583643  c644242870           mov byte ptr [esp + 0x28], 0x70
// 00583648  c644242948           mov byte ptr [esp + 0x29], 0x48
// 0058364d  c644242a59           mov byte ptr [esp + 0x2a], 0x59
// 00583652  885c242b             mov byte ptr [esp + 0x2b], bl
// 00583656  885c2438             mov byte ptr [esp + 0x38], bl
// 0058365a  c644243942           mov byte ptr [esp + 0x39], 0x42
// 0058365f  c644243a49           mov byte ptr [esp + 0x3a], 0x49
// 00583664  c644243b54           mov byte ptr [esp + 0x3b], 0x54
// 00583669  889c24a0000000       mov byte ptr [esp + 0xa0], bl
// 00583670  c68424a100000043     mov byte ptr [esp + 0xa1], 0x43
// 00583678  c68424a200000041     mov byte ptr [esp + 0xa2], 0x41
// 00583680  c68424a30000004c     mov byte ptr [esp + 0xa3], 0x4c
// 00583688  885c2468             mov byte ptr [esp + 0x68], bl
// 0058368c  c644246950           mov byte ptr [esp + 0x69], 0x50
// 00583691  c644246a4c           mov byte ptr [esp + 0x6a], 0x4c
// 00583696  c644246b54           mov byte ptr [esp + 0x6b], 0x54
// 0058369b  885c2448             mov byte ptr [esp + 0x48], bl
// 0058369f  c644244952           mov byte ptr [esp + 0x49], 0x52
// 005836a4  c644244a47           mov byte ptr [esp + 0x4a], 0x47
// 005836a9  c644244b42           mov byte ptr [esp + 0x4b], 0x42
// 005836ae  c644247874           mov byte ptr [esp + 0x78], 0x74
// 005836b3  c644247945           mov byte ptr [esp + 0x79], 0x45
// 005836b8  c644247a58           mov byte ptr [esp + 0x7a], 0x58
// 005836bd  c644247b74           mov byte ptr [esp + 0x7b], 0x74
// 005836c2  c684248800000074     mov byte ptr [esp + 0x88], 0x74
// 005836ca  c684248900000049     mov byte ptr [esp + 0x89], 0x49
// 005836d2  c684248a0000004d     mov byte ptr [esp + 0x8a], 0x4d
// 005836da  c684248b00000045     mov byte ptr [esp + 0x8b], 0x45
// 005836e2  c684249800000074     mov byte ptr [esp + 0x98], 0x74
// 005836ea  c684249900000052     mov byte ptr [esp + 0x99], 0x52
// 005836f2  c684249a0000004e     mov byte ptr [esp + 0x9a], 0x4e
// 005836fa  c684249b00000053     mov byte ptr [esp + 0x9b], 0x53
// 00583702  c68424a80000007a     mov byte ptr [esp + 0xa8], 0x7a
// 0058370a  c68424a900000054     mov byte ptr [esp + 0xa9], 0x54
// 00583712  c68424aa00000058     mov byte ptr [esp + 0xaa], 0x58
// 0058371a  c68424ab00000074     mov byte ptr [esp + 0xab], 0x74
// 00583722  56                   push esi
// 00583723  e828140100           call 0x594b50
// 00583728  8d8e1c010000         lea ecx, [esi + 0x11c]
// 0058372e  8bf8                 mov edi, eax
// 00583730  8b01                 mov eax, dword ptr [ecx]
// 00583732  83c404               add esp, 4
// 00583735  3b442460             cmp eax, dword ptr [esp + 0x60]
// 00583739  750d                 jne 0x583748
// 0058373b  57                   push edi
// 0058373c  55                   push ebp
// 0058373d  56                   push esi
// 0058373e  e86d150100           call 0x594cb0
// 00583743  e9ae010000           jmp 0x5838f6
// 00583748  3b442430             cmp eax, dword ptr [esp + 0x30]
// 0058374c  750d                 jne 0x58375b
// 0058374e  57                   push edi
// 0058374f  55                   push ebp
// 00583750  56                   push esi
// 00583751  e8ba180100           call 0x595010
// 00583756  e99b010000           jmp 0x5838f6
// 0058375b  51                   push ecx
// 0058375c  56                   push esi
// 0058375d  e8cee5ffff           call 0x581d30
// 00583762  83c408               add esp, 8
// 00583765  85c0                 test eax, eax
// 00583767  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0058376d  7445                 je 0x5837b4
// 0058376f  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00583773  751b                 jne 0x583790
// 00583775  85ff                 test edi, edi
// 00583777  7709                 ja 0x583782
// 00583779  f7466800200000       test dword ptr [esi + 0x68], 0x2000
// 00583780  740e                 je 0x583790
// 00583782  6810e08c00           push 0x8ce010
// 00583787  56                   push esi
// 00583788  e8d3a90000           call 0x58e160
// 0058378d  83c408               add esp, 8
// 00583790  57                   push edi
// 00583791  55                   push ebp
// 00583792  56                   push esi
// 00583793  e818380100           call 0x596fb0
// 00583798  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 0058379e  83c40c               add esp, 0xc
// 005837a1  3b4c2418             cmp ecx, dword ptr [esp + 0x18]
// 005837a5  0f854e010000         jne 0x5838f9
// 005837ab  834e6802             or dword ptr [esi + 0x68], 2
// 005837af  e945010000           jmp 0x5838f9
// 005837b4  3b442410             cmp eax, dword ptr [esp + 0x10]
// 005837b8  752a                 jne 0x5837e4
// 005837ba  85ff                 test edi, edi
// 005837bc  7709                 ja 0x5837c7
// 005837be  f7466800200000       test dword ptr [esi + 0x68], 0x2000
// 005837c5  740e                 je 0x5837d5
// 005837c7  6810e08c00           push 0x8ce010
// 005837cc  56                   push esi
// 005837cd  e88ea90000           call 0x58e160
// 005837d2  83c408               add esp, 8
// 005837d5  57                   push edi
// 005837d6  56                   push esi
// 005837d7  e804140100           call 0x594be0
// 005837dc  83c408               add esp, 8
// 005837df  e915010000           jmp 0x5838f9
// 005837e4  57                   push edi
// 005837e5  55                   push ebp
// 005837e6  56                   push esi
// 005837e7  3b442424             cmp eax, dword ptr [esp + 0x24]
// 005837eb  750a                 jne 0x5837f7
// 005837ed  e87e160100           call 0x594e70
// 005837f2  e9ff000000           jmp 0x5838f6
// 005837f7  3b44247c             cmp eax, dword ptr [esp + 0x7c]
// 005837fb  750a                 jne 0x583807
// 005837fd  e8be280100           call 0x5960c0
// 00583802  e9ef000000           jmp 0x5838f6
// 00583807  3b44244c             cmp eax, dword ptr [esp + 0x4c]
// 0058380b  750a                 jne 0x583817
// 0058380d  e85e1b0100           call 0x595370
// 00583812  e9df000000           jmp 0x5838f6
// 00583817  3b84249c000000       cmp eax, dword ptr [esp + 0x9c]
// 0058381e  750a                 jne 0x58382a
// 00583820  e83b180100           call 0x595060
// 00583825  e9cc000000           jmp 0x5838f6
// 0058382a  3b44245c             cmp eax, dword ptr [esp + 0x5c]
// 0058382e  750a                 jne 0x58383a
// 00583830  e8ab2a0100           call 0x5962e0
// 00583835  e9bc000000           jmp 0x5838f6
// 0058383a  3b84248c000000       cmp eax, dword ptr [esp + 0x8c]
// 00583841  750a                 jne 0x58384d
// 00583843  e8382d0100           call 0x596580
// 00583848  e9a9000000           jmp 0x5838f6
// 0058384d  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 00583851  750a                 jne 0x58385d
// 00583853  e8482e0100           call 0x5966a0
// 00583858  e999000000           jmp 0x5838f6
// 0058385d  3b8424ac000000       cmp eax, dword ptr [esp + 0xac]
// 00583864  750a                 jne 0x583870
// 00583866  e835310100           call 0x5969a0
// 0058386b  e986000000           jmp 0x5838f6
// 00583870  3b442434             cmp eax, dword ptr [esp + 0x34]
// 00583874  7507                 jne 0x58387d
// 00583876  e8e52b0100           call 0x596460
// 0058387b  eb79                 jmp 0x5838f6
// 0058387d  3b442444             cmp eax, dword ptr [esp + 0x44]
// 00583881  7507                 jne 0x58388a
// 00583883  e868190100           call 0x5951f0
// 00583888  eb6c                 jmp 0x5838f6
// 0058388a  3b442454             cmp eax, dword ptr [esp + 0x54]
// 0058388e  7507                 jne 0x583897
// 00583890  e80b1f0100           call 0x5957a0
// 00583895  eb5f                 jmp 0x5838f6
// 00583897  3b442464             cmp eax, dword ptr [esp + 0x64]
// 0058389b  7507                 jne 0x5838a4
// 0058389d  e80e210100           call 0x5959b0
// 005838a2  eb52                 jmp 0x5838f6
// 005838a4  3b442474             cmp eax, dword ptr [esp + 0x74]
// 005838a8  7507                 jne 0x5838b1
// 005838aa  e801230100           call 0x595bb0
// 005838af  eb45                 jmp 0x5838f6
// 005838b1  3b842484000000       cmp eax, dword ptr [esp + 0x84]
// 005838b8  7507                 jne 0x5838c1
// 005838ba  e811340100           call 0x596cd0
// 005838bf  eb35                 jmp 0x5838f6
// 005838c1  3b842494000000       cmp eax, dword ptr [esp + 0x94]
// 005838c8  7507                 jne 0x5838d1
// 005838ca  e8f1320100           call 0x596bc0
// 005838cf  eb25                 jmp 0x5838f6
// 005838d1  3b8424a4000000       cmp eax, dword ptr [esp + 0xa4]
// 005838d8  7507                 jne 0x5838e1
// 005838da  e871250100           call 0x595e50
// 005838df  eb15                 jmp 0x5838f6
// 005838e1  3b8424b4000000       cmp eax, dword ptr [esp + 0xb4]
// 005838e8  7507                 jne 0x5838f1
// 005838ea  e801350100           call 0x596df0
// 005838ef  eb05                 jmp 0x5838f6
// 005838f1  e8ba360100           call 0x596fb0
// 005838f6  83c40c               add esp, 0xc
// 005838f9  f6466810             test byte ptr [esi + 0x68], 0x10
// 005838fd  0f844dfcffff         je 0x583550
// 00583903  5f                   pop edi
// 00583904  5d                   pop ebp
// 00583905  5b                   pop ebx
// 00583906  5e                   pop esi
// 00583907  81c4a0000000         add esp, 0xa0
// 0058390d  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
