// from server: 100% by auto
// roc 2010-06 00566c50  unit: seg_00560000  size: 1006 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00566c50
//
// 00566c50  81eca0000000         sub esp, 0xa0
// 00566c56  56                   push esi
// 00566c57  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 00566c5e  85f6                 test esi, esi
// 00566c60  0f84d0030000         je 0x567036
// 00566c66  53                   push ebx
// 00566c67  55                   push ebp
// 00566c68  57                   push edi
// 00566c69  6a00                 push 0
// 00566c6b  56                   push esi
// 00566c6c  e89f180100           call 0x578510
// 00566c71  8bac24c0000000       mov ebp, dword ptr [esp + 0xc0]
// 00566c78  83c408               add esp, 8
// 00566c7b  b373                 mov bl, 0x73
// 00566c7d  8d4900               lea ecx, [ecx]
// 00566c80  c644246049           mov byte ptr [esp + 0x60], 0x49
// 00566c85  c644246148           mov byte ptr [esp + 0x61], 0x48
// 00566c8a  c644246244           mov byte ptr [esp + 0x62], 0x44
// 00566c8f  c644246352           mov byte ptr [esp + 0x63], 0x52
// 00566c94  c644241049           mov byte ptr [esp + 0x10], 0x49
// 00566c99  c644241144           mov byte ptr [esp + 0x11], 0x44
// 00566c9e  c644241241           mov byte ptr [esp + 0x12], 0x41
// 00566ca3  c644241354           mov byte ptr [esp + 0x13], 0x54
// 00566ca8  c644243049           mov byte ptr [esp + 0x30], 0x49
// 00566cad  c644243145           mov byte ptr [esp + 0x31], 0x45
// 00566cb2  c64424324e           mov byte ptr [esp + 0x32], 0x4e
// 00566cb7  c644243344           mov byte ptr [esp + 0x33], 0x44
// 00566cbc  c644241850           mov byte ptr [esp + 0x18], 0x50
// 00566cc1  c64424194c           mov byte ptr [esp + 0x19], 0x4c
// 00566cc6  c644241a54           mov byte ptr [esp + 0x1a], 0x54
// 00566ccb  c644241b45           mov byte ptr [esp + 0x1b], 0x45
// 00566cd0  c644247062           mov byte ptr [esp + 0x70], 0x62
// 00566cd5  c64424714b           mov byte ptr [esp + 0x71], 0x4b
// 00566cda  c644247247           mov byte ptr [esp + 0x72], 0x47
// 00566cdf  c644247344           mov byte ptr [esp + 0x73], 0x44
// 00566ce4  c644244063           mov byte ptr [esp + 0x40], 0x63
// 00566ce9  c644244148           mov byte ptr [esp + 0x41], 0x48
// 00566cee  c644244252           mov byte ptr [esp + 0x42], 0x52
// 00566cf3  c64424434d           mov byte ptr [esp + 0x43], 0x4d
// 00566cf8  c684249000000067     mov byte ptr [esp + 0x90], 0x67
// 00566d00  c684249100000041     mov byte ptr [esp + 0x91], 0x41
// 00566d08  c68424920000004d     mov byte ptr [esp + 0x92], 0x4d
// 00566d10  c684249300000041     mov byte ptr [esp + 0x93], 0x41
// 00566d18  c644245068           mov byte ptr [esp + 0x50], 0x68
// 00566d1d  c644245149           mov byte ptr [esp + 0x51], 0x49
// 00566d22  c644245253           mov byte ptr [esp + 0x52], 0x53
// 00566d27  c644245354           mov byte ptr [esp + 0x53], 0x54
// 00566d2c  c644245869           mov byte ptr [esp + 0x58], 0x69
// 00566d31  c644245943           mov byte ptr [esp + 0x59], 0x43
// 00566d36  c644245a43           mov byte ptr [esp + 0x5a], 0x43
// 00566d3b  c644245b50           mov byte ptr [esp + 0x5b], 0x50
// 00566d40  c68424800000006f     mov byte ptr [esp + 0x80], 0x6f
// 00566d48  c684248100000046     mov byte ptr [esp + 0x81], 0x46
// 00566d50  c684248200000046     mov byte ptr [esp + 0x82], 0x46
// 00566d58  889c2483000000       mov byte ptr [esp + 0x83], bl
// 00566d5f  c644242070           mov byte ptr [esp + 0x20], 0x70
// 00566d64  c644242143           mov byte ptr [esp + 0x21], 0x43
// 00566d69  c644242241           mov byte ptr [esp + 0x22], 0x41
// 00566d6e  c64424234c           mov byte ptr [esp + 0x23], 0x4c
// 00566d73  c644242870           mov byte ptr [esp + 0x28], 0x70
// 00566d78  c644242948           mov byte ptr [esp + 0x29], 0x48
// 00566d7d  c644242a59           mov byte ptr [esp + 0x2a], 0x59
// 00566d82  885c242b             mov byte ptr [esp + 0x2b], bl
// 00566d86  885c2438             mov byte ptr [esp + 0x38], bl
// 00566d8a  c644243942           mov byte ptr [esp + 0x39], 0x42
// 00566d8f  c644243a49           mov byte ptr [esp + 0x3a], 0x49
// 00566d94  c644243b54           mov byte ptr [esp + 0x3b], 0x54
// 00566d99  889c24a0000000       mov byte ptr [esp + 0xa0], bl
// 00566da0  c68424a100000043     mov byte ptr [esp + 0xa1], 0x43
// 00566da8  c68424a200000041     mov byte ptr [esp + 0xa2], 0x41
// 00566db0  c68424a30000004c     mov byte ptr [esp + 0xa3], 0x4c
// 00566db8  885c2468             mov byte ptr [esp + 0x68], bl
// 00566dbc  c644246950           mov byte ptr [esp + 0x69], 0x50
// 00566dc1  c644246a4c           mov byte ptr [esp + 0x6a], 0x4c
// 00566dc6  c644246b54           mov byte ptr [esp + 0x6b], 0x54
// 00566dcb  885c2448             mov byte ptr [esp + 0x48], bl
// 00566dcf  c644244952           mov byte ptr [esp + 0x49], 0x52
// 00566dd4  c644244a47           mov byte ptr [esp + 0x4a], 0x47
// 00566dd9  c644244b42           mov byte ptr [esp + 0x4b], 0x42
// 00566dde  c644247874           mov byte ptr [esp + 0x78], 0x74
// 00566de3  c644247945           mov byte ptr [esp + 0x79], 0x45
// 00566de8  c644247a58           mov byte ptr [esp + 0x7a], 0x58
// 00566ded  c644247b74           mov byte ptr [esp + 0x7b], 0x74
// 00566df2  c684248800000074     mov byte ptr [esp + 0x88], 0x74
// 00566dfa  c684248900000049     mov byte ptr [esp + 0x89], 0x49
// 00566e02  c684248a0000004d     mov byte ptr [esp + 0x8a], 0x4d
// 00566e0a  c684248b00000045     mov byte ptr [esp + 0x8b], 0x45
// 00566e12  c684249800000074     mov byte ptr [esp + 0x98], 0x74
// 00566e1a  c684249900000052     mov byte ptr [esp + 0x99], 0x52
// 00566e22  c684249a0000004e     mov byte ptr [esp + 0x9a], 0x4e
// 00566e2a  c684249b00000053     mov byte ptr [esp + 0x9b], 0x53
// 00566e32  c68424a80000007a     mov byte ptr [esp + 0xa8], 0x7a
// 00566e3a  c68424a900000054     mov byte ptr [esp + 0xa9], 0x54
// 00566e42  c68424aa00000058     mov byte ptr [esp + 0xaa], 0x58
// 00566e4a  c68424ab00000074     mov byte ptr [esp + 0xab], 0x74
// 00566e52  56                   push esi
// 00566e53  e828160100           call 0x578480
// 00566e58  8d8e1c010000         lea ecx, [esi + 0x11c]
// 00566e5e  8bf8                 mov edi, eax
// 00566e60  8b01                 mov eax, dword ptr [ecx]
// 00566e62  83c404               add esp, 4
// 00566e65  3b442460             cmp eax, dword ptr [esp + 0x60]
// 00566e69  750d                 jne 0x566e78
// 00566e6b  57                   push edi
// 00566e6c  55                   push ebp
// 00566e6d  56                   push esi
// 00566e6e  e86d170100           call 0x5785e0
// 00566e73  e9ae010000           jmp 0x567026
// 00566e78  3b442430             cmp eax, dword ptr [esp + 0x30]
// 00566e7c  750d                 jne 0x566e8b
// 00566e7e  57                   push edi
// 00566e7f  55                   push ebp
// 00566e80  56                   push esi
// 00566e81  e8ba1a0100           call 0x578940
// 00566e86  e99b010000           jmp 0x567026
// 00566e8b  51                   push ecx
// 00566e8c  56                   push esi
// 00566e8d  e8bee5ffff           call 0x565450
// 00566e92  83c408               add esp, 8
// 00566e95  85c0                 test eax, eax
// 00566e97  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00566e9d  7445                 je 0x566ee4
// 00566e9f  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00566ea3  751b                 jne 0x566ec0
// 00566ea5  85ff                 test edi, edi
// 00566ea7  7709                 ja 0x566eb2
// 00566ea9  f7466800200000       test dword ptr [esi + 0x68], 0x2000
// 00566eb0  740e                 je 0x566ec0
// 00566eb2  68102ca200           push 0xa22c10
// 00566eb7  56                   push esi
// 00566eb8  e8f3ab0000           call 0x571ab0
// 00566ebd  83c408               add esp, 8
// 00566ec0  57                   push edi
// 00566ec1  55                   push ebp
// 00566ec2  56                   push esi
// 00566ec3  e8383a0100           call 0x57a900
// 00566ec8  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 00566ece  83c40c               add esp, 0xc
// 00566ed1  3b4c2418             cmp ecx, dword ptr [esp + 0x18]
// 00566ed5  0f854e010000         jne 0x567029
// 00566edb  834e6802             or dword ptr [esi + 0x68], 2
// 00566edf  e945010000           jmp 0x567029
// 00566ee4  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00566ee8  752a                 jne 0x566f14
// 00566eea  85ff                 test edi, edi
// 00566eec  7709                 ja 0x566ef7
// 00566eee  f7466800200000       test dword ptr [esi + 0x68], 0x2000
// 00566ef5  740e                 je 0x566f05
// 00566ef7  68102ca200           push 0xa22c10
// 00566efc  56                   push esi
// 00566efd  e8aeab0000           call 0x571ab0
// 00566f02  83c408               add esp, 8
// 00566f05  57                   push edi
// 00566f06  56                   push esi
// 00566f07  e804160100           call 0x578510
// 00566f0c  83c408               add esp, 8
// 00566f0f  e915010000           jmp 0x567029
// 00566f14  57                   push edi
// 00566f15  55                   push ebp
// 00566f16  56                   push esi
// 00566f17  3b442424             cmp eax, dword ptr [esp + 0x24]
// 00566f1b  750a                 jne 0x566f27
// 00566f1d  e87e180100           call 0x5787a0
// 00566f22  e9ff000000           jmp 0x567026
// 00566f27  3b44247c             cmp eax, dword ptr [esp + 0x7c]
// 00566f2b  750a                 jne 0x566f37
// 00566f2d  e8ee2a0100           call 0x579a20
// 00566f32  e9ef000000           jmp 0x567026
// 00566f37  3b44244c             cmp eax, dword ptr [esp + 0x4c]
// 00566f3b  750a                 jne 0x566f47
// 00566f3d  e85e1d0100           call 0x578ca0
// 00566f42  e9df000000           jmp 0x567026
// 00566f47  3b84249c000000       cmp eax, dword ptr [esp + 0x9c]
// 00566f4e  750a                 jne 0x566f5a
// 00566f50  e83b1a0100           call 0x578990
// 00566f55  e9cc000000           jmp 0x567026
// 00566f5a  3b44245c             cmp eax, dword ptr [esp + 0x5c]
// 00566f5e  750a                 jne 0x566f6a
// 00566f60  e8db2c0100           call 0x579c40
// 00566f65  e9bc000000           jmp 0x567026
// 00566f6a  3b84248c000000       cmp eax, dword ptr [esp + 0x8c]
// 00566f71  750a                 jne 0x566f7d
// 00566f73  e8682f0100           call 0x579ee0
// 00566f78  e9a9000000           jmp 0x567026
// 00566f7d  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 00566f81  750a                 jne 0x566f8d
// 00566f83  e878300100           call 0x57a000
// 00566f88  e999000000           jmp 0x567026
// 00566f8d  3b8424ac000000       cmp eax, dword ptr [esp + 0xac]
// 00566f94  750a                 jne 0x566fa0
// 00566f96  e865330100           call 0x57a300
// 00566f9b  e986000000           jmp 0x567026
// 00566fa0  3b442434             cmp eax, dword ptr [esp + 0x34]
// 00566fa4  7507                 jne 0x566fad
// 00566fa6  e8152e0100           call 0x579dc0
// 00566fab  eb79                 jmp 0x567026
// 00566fad  3b442444             cmp eax, dword ptr [esp + 0x44]
// 00566fb1  7507                 jne 0x566fba
// 00566fb3  e8681b0100           call 0x578b20
// 00566fb8  eb6c                 jmp 0x567026
// 00566fba  3b442454             cmp eax, dword ptr [esp + 0x54]
// 00566fbe  7507                 jne 0x566fc7
// 00566fc0  e83b210100           call 0x579100
// 00566fc5  eb5f                 jmp 0x567026
// 00566fc7  3b442464             cmp eax, dword ptr [esp + 0x64]
// 00566fcb  7507                 jne 0x566fd4
// 00566fcd  e83e230100           call 0x579310
// 00566fd2  eb52                 jmp 0x567026
// 00566fd4  3b442474             cmp eax, dword ptr [esp + 0x74]
// 00566fd8  7507                 jne 0x566fe1
// 00566fda  e831250100           call 0x579510
// 00566fdf  eb45                 jmp 0x567026
// 00566fe1  3b842484000000       cmp eax, dword ptr [esp + 0x84]
// 00566fe8  7507                 jne 0x566ff1
// 00566fea  e831360100           call 0x57a620
// 00566fef  eb35                 jmp 0x567026
// 00566ff1  3b842494000000       cmp eax, dword ptr [esp + 0x94]
// 00566ff8  7507                 jne 0x567001
// 00566ffa  e811350100           call 0x57a510
// 00566fff  eb25                 jmp 0x567026
// 00567001  3b8424a4000000       cmp eax, dword ptr [esp + 0xa4]
// 00567008  7507                 jne 0x567011
// 0056700a  e8a1270100           call 0x5797b0
// 0056700f  eb15                 jmp 0x567026
// 00567011  3b8424b4000000       cmp eax, dword ptr [esp + 0xb4]
// 00567018  7507                 jne 0x567021
// 0056701a  e821370100           call 0x57a740
// 0056701f  eb05                 jmp 0x567026
// 00567021  e8da380100           call 0x57a900
// 00567026  83c40c               add esp, 0xc
// 00567029  f6466810             test byte ptr [esi + 0x68], 0x10
// 0056702d  0f844dfcffff         je 0x566c80
// 00567033  5f                   pop edi
// 00567034  5d                   pop ebp
// 00567035  5b                   pop ebx
// 00567036  5e                   pop esi
// 00567037  81c4a0000000         add esp, 0xa0
// 0056703d  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
