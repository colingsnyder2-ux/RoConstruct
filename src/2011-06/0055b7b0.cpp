// from server: 100% by auto
// roc 2011-06 0055b7b0  unit: seg_00550000  size: 1006 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055b7b0
//
// 0055b7b0  81eca0000000         sub esp, 0xa0
// 0055b7b6  56                   push esi
// 0055b7b7  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 0055b7be  85f6                 test esi, esi
// 0055b7c0  0f84d0030000         je 0x55bb96
// 0055b7c6  53                   push ebx
// 0055b7c7  55                   push ebp
// 0055b7c8  57                   push edi
// 0055b7c9  6a00                 push 0
// 0055b7cb  56                   push esi
// 0055b7cc  e86f400100           call 0x56f840
// 0055b7d1  8bac24c0000000       mov ebp, dword ptr [esp + 0xc0]
// 0055b7d8  83c408               add esp, 8
// 0055b7db  b373                 mov bl, 0x73
// 0055b7dd  8d4900               lea ecx, [ecx]
// 0055b7e0  c644246049           mov byte ptr [esp + 0x60], 0x49
// 0055b7e5  c644246148           mov byte ptr [esp + 0x61], 0x48
// 0055b7ea  c644246244           mov byte ptr [esp + 0x62], 0x44
// 0055b7ef  c644246352           mov byte ptr [esp + 0x63], 0x52
// 0055b7f4  c644241049           mov byte ptr [esp + 0x10], 0x49
// 0055b7f9  c644241144           mov byte ptr [esp + 0x11], 0x44
// 0055b7fe  c644241241           mov byte ptr [esp + 0x12], 0x41
// 0055b803  c644241354           mov byte ptr [esp + 0x13], 0x54
// 0055b808  c644243049           mov byte ptr [esp + 0x30], 0x49
// 0055b80d  c644243145           mov byte ptr [esp + 0x31], 0x45
// 0055b812  c64424324e           mov byte ptr [esp + 0x32], 0x4e
// 0055b817  c644243344           mov byte ptr [esp + 0x33], 0x44
// 0055b81c  c644241850           mov byte ptr [esp + 0x18], 0x50
// 0055b821  c64424194c           mov byte ptr [esp + 0x19], 0x4c
// 0055b826  c644241a54           mov byte ptr [esp + 0x1a], 0x54
// 0055b82b  c644241b45           mov byte ptr [esp + 0x1b], 0x45
// 0055b830  c644247062           mov byte ptr [esp + 0x70], 0x62
// 0055b835  c64424714b           mov byte ptr [esp + 0x71], 0x4b
// 0055b83a  c644247247           mov byte ptr [esp + 0x72], 0x47
// 0055b83f  c644247344           mov byte ptr [esp + 0x73], 0x44
// 0055b844  c644244063           mov byte ptr [esp + 0x40], 0x63
// 0055b849  c644244148           mov byte ptr [esp + 0x41], 0x48
// 0055b84e  c644244252           mov byte ptr [esp + 0x42], 0x52
// 0055b853  c64424434d           mov byte ptr [esp + 0x43], 0x4d
// 0055b858  c684249000000067     mov byte ptr [esp + 0x90], 0x67
// 0055b860  c684249100000041     mov byte ptr [esp + 0x91], 0x41
// 0055b868  c68424920000004d     mov byte ptr [esp + 0x92], 0x4d
// 0055b870  c684249300000041     mov byte ptr [esp + 0x93], 0x41
// 0055b878  c644245068           mov byte ptr [esp + 0x50], 0x68
// 0055b87d  c644245149           mov byte ptr [esp + 0x51], 0x49
// 0055b882  c644245253           mov byte ptr [esp + 0x52], 0x53
// 0055b887  c644245354           mov byte ptr [esp + 0x53], 0x54
// 0055b88c  c644245869           mov byte ptr [esp + 0x58], 0x69
// 0055b891  c644245943           mov byte ptr [esp + 0x59], 0x43
// 0055b896  c644245a43           mov byte ptr [esp + 0x5a], 0x43
// 0055b89b  c644245b50           mov byte ptr [esp + 0x5b], 0x50
// 0055b8a0  c68424800000006f     mov byte ptr [esp + 0x80], 0x6f
// 0055b8a8  c684248100000046     mov byte ptr [esp + 0x81], 0x46
// 0055b8b0  c684248200000046     mov byte ptr [esp + 0x82], 0x46
// 0055b8b8  889c2483000000       mov byte ptr [esp + 0x83], bl
// 0055b8bf  c644242070           mov byte ptr [esp + 0x20], 0x70
// 0055b8c4  c644242143           mov byte ptr [esp + 0x21], 0x43
// 0055b8c9  c644242241           mov byte ptr [esp + 0x22], 0x41
// 0055b8ce  c64424234c           mov byte ptr [esp + 0x23], 0x4c
// 0055b8d3  c644242870           mov byte ptr [esp + 0x28], 0x70
// 0055b8d8  c644242948           mov byte ptr [esp + 0x29], 0x48
// 0055b8dd  c644242a59           mov byte ptr [esp + 0x2a], 0x59
// 0055b8e2  885c242b             mov byte ptr [esp + 0x2b], bl
// 0055b8e6  885c2438             mov byte ptr [esp + 0x38], bl
// 0055b8ea  c644243942           mov byte ptr [esp + 0x39], 0x42
// 0055b8ef  c644243a49           mov byte ptr [esp + 0x3a], 0x49
// 0055b8f4  c644243b54           mov byte ptr [esp + 0x3b], 0x54
// 0055b8f9  889c24a0000000       mov byte ptr [esp + 0xa0], bl
// 0055b900  c68424a100000043     mov byte ptr [esp + 0xa1], 0x43
// 0055b908  c68424a200000041     mov byte ptr [esp + 0xa2], 0x41
// 0055b910  c68424a30000004c     mov byte ptr [esp + 0xa3], 0x4c
// 0055b918  885c2468             mov byte ptr [esp + 0x68], bl
// 0055b91c  c644246950           mov byte ptr [esp + 0x69], 0x50
// 0055b921  c644246a4c           mov byte ptr [esp + 0x6a], 0x4c
// 0055b926  c644246b54           mov byte ptr [esp + 0x6b], 0x54
// 0055b92b  885c2448             mov byte ptr [esp + 0x48], bl
// 0055b92f  c644244952           mov byte ptr [esp + 0x49], 0x52
// 0055b934  c644244a47           mov byte ptr [esp + 0x4a], 0x47
// 0055b939  c644244b42           mov byte ptr [esp + 0x4b], 0x42
// 0055b93e  c644247874           mov byte ptr [esp + 0x78], 0x74
// 0055b943  c644247945           mov byte ptr [esp + 0x79], 0x45
// 0055b948  c644247a58           mov byte ptr [esp + 0x7a], 0x58
// 0055b94d  c644247b74           mov byte ptr [esp + 0x7b], 0x74
// 0055b952  c684248800000074     mov byte ptr [esp + 0x88], 0x74
// 0055b95a  c684248900000049     mov byte ptr [esp + 0x89], 0x49
// 0055b962  c684248a0000004d     mov byte ptr [esp + 0x8a], 0x4d
// 0055b96a  c684248b00000045     mov byte ptr [esp + 0x8b], 0x45
// 0055b972  c684249800000074     mov byte ptr [esp + 0x98], 0x74
// 0055b97a  c684249900000052     mov byte ptr [esp + 0x99], 0x52
// 0055b982  c684249a0000004e     mov byte ptr [esp + 0x9a], 0x4e
// 0055b98a  c684249b00000053     mov byte ptr [esp + 0x9b], 0x53
// 0055b992  c68424a80000007a     mov byte ptr [esp + 0xa8], 0x7a
// 0055b99a  c68424a900000054     mov byte ptr [esp + 0xa9], 0x54
// 0055b9a2  c68424aa00000058     mov byte ptr [esp + 0xaa], 0x58
// 0055b9aa  c68424ab00000074     mov byte ptr [esp + 0xab], 0x74
// 0055b9b2  56                   push esi
// 0055b9b3  e8f83d0100           call 0x56f7b0
// 0055b9b8  8d8e1c010000         lea ecx, [esi + 0x11c]
// 0055b9be  8bf8                 mov edi, eax
// 0055b9c0  8b01                 mov eax, dword ptr [ecx]
// 0055b9c2  83c404               add esp, 4
// 0055b9c5  3b442460             cmp eax, dword ptr [esp + 0x60]
// 0055b9c9  750d                 jne 0x55b9d8
// 0055b9cb  57                   push edi
// 0055b9cc  55                   push ebp
// 0055b9cd  56                   push esi
// 0055b9ce  e83d3f0100           call 0x56f910
// 0055b9d3  e9ae010000           jmp 0x55bb86
// 0055b9d8  3b442430             cmp eax, dword ptr [esp + 0x30]
// 0055b9dc  750d                 jne 0x55b9eb
// 0055b9de  57                   push edi
// 0055b9df  55                   push ebp
// 0055b9e0  56                   push esi
// 0055b9e1  e88a420100           call 0x56fc70
// 0055b9e6  e99b010000           jmp 0x55bb86
// 0055b9eb  51                   push ecx
// 0055b9ec  56                   push esi
// 0055b9ed  e8ce52ffff           call 0x550cc0
// 0055b9f2  83c408               add esp, 8
// 0055b9f5  85c0                 test eax, eax
// 0055b9f7  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0055b9fd  7445                 je 0x55ba44
// 0055b9ff  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0055ba03  751b                 jne 0x55ba20
// 0055ba05  85ff                 test edi, edi
// 0055ba07  7709                 ja 0x55ba12
// 0055ba09  f7466800200000       test dword ptr [esi + 0x68], 0x2000
// 0055ba10  740e                 je 0x55ba20
// 0055ba12  688827a800           push 0xa82788
// 0055ba17  56                   push esi
// 0055ba18  e813590000           call 0x561330
// 0055ba1d  83c408               add esp, 8
// 0055ba20  57                   push edi
// 0055ba21  55                   push ebp
// 0055ba22  56                   push esi
// 0055ba23  e838620100           call 0x571c60
// 0055ba28  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 0055ba2e  83c40c               add esp, 0xc
// 0055ba31  3b4c2418             cmp ecx, dword ptr [esp + 0x18]
// 0055ba35  0f854e010000         jne 0x55bb89
// 0055ba3b  834e6802             or dword ptr [esi + 0x68], 2
// 0055ba3f  e945010000           jmp 0x55bb89
// 0055ba44  3b442410             cmp eax, dword ptr [esp + 0x10]
// 0055ba48  752a                 jne 0x55ba74
// 0055ba4a  85ff                 test edi, edi
// 0055ba4c  7709                 ja 0x55ba57
// 0055ba4e  f7466800200000       test dword ptr [esi + 0x68], 0x2000
// 0055ba55  740e                 je 0x55ba65
// 0055ba57  688827a800           push 0xa82788
// 0055ba5c  56                   push esi
// 0055ba5d  e8ce580000           call 0x561330
// 0055ba62  83c408               add esp, 8
// 0055ba65  57                   push edi
// 0055ba66  56                   push esi
// 0055ba67  e8d43d0100           call 0x56f840
// 0055ba6c  83c408               add esp, 8
// 0055ba6f  e915010000           jmp 0x55bb89
// 0055ba74  57                   push edi
// 0055ba75  55                   push ebp
// 0055ba76  56                   push esi
// 0055ba77  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0055ba7b  750a                 jne 0x55ba87
// 0055ba7d  e84e400100           call 0x56fad0
// 0055ba82  e9ff000000           jmp 0x55bb86
// 0055ba87  3b44247c             cmp eax, dword ptr [esp + 0x7c]
// 0055ba8b  750a                 jne 0x55ba97
// 0055ba8d  e89e520100           call 0x570d30
// 0055ba92  e9ef000000           jmp 0x55bb86
// 0055ba97  3b44244c             cmp eax, dword ptr [esp + 0x4c]
// 0055ba9b  750a                 jne 0x55baa7
// 0055ba9d  e82e450100           call 0x56ffd0
// 0055baa2  e9df000000           jmp 0x55bb86
// 0055baa7  3b84249c000000       cmp eax, dword ptr [esp + 0x9c]
// 0055baae  750a                 jne 0x55baba
// 0055bab0  e80b420100           call 0x56fcc0
// 0055bab5  e9cc000000           jmp 0x55bb86
// 0055baba  3b44245c             cmp eax, dword ptr [esp + 0x5c]
// 0055babe  750a                 jne 0x55baca
// 0055bac0  e88b540100           call 0x570f50
// 0055bac5  e9bc000000           jmp 0x55bb86
// 0055baca  3b84248c000000       cmp eax, dword ptr [esp + 0x8c]
// 0055bad1  750a                 jne 0x55badd
// 0055bad3  e818570100           call 0x5711f0
// 0055bad8  e9a9000000           jmp 0x55bb86
// 0055badd  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 0055bae1  750a                 jne 0x55baed
// 0055bae3  e828580100           call 0x571310
// 0055bae8  e999000000           jmp 0x55bb86
// 0055baed  3b8424ac000000       cmp eax, dword ptr [esp + 0xac]
// 0055baf4  750a                 jne 0x55bb00
// 0055baf6  e8155b0100           call 0x571610
// 0055bafb  e986000000           jmp 0x55bb86
// 0055bb00  3b442434             cmp eax, dword ptr [esp + 0x34]
// 0055bb04  7507                 jne 0x55bb0d
// 0055bb06  e8c5550100           call 0x5710d0
// 0055bb0b  eb79                 jmp 0x55bb86
// 0055bb0d  3b442444             cmp eax, dword ptr [esp + 0x44]
// 0055bb11  7507                 jne 0x55bb1a
// 0055bb13  e838430100           call 0x56fe50
// 0055bb18  eb6c                 jmp 0x55bb86
// 0055bb1a  3b442454             cmp eax, dword ptr [esp + 0x54]
// 0055bb1e  7507                 jne 0x55bb27
// 0055bb20  e8eb480100           call 0x570410
// 0055bb25  eb5f                 jmp 0x55bb86
// 0055bb27  3b442464             cmp eax, dword ptr [esp + 0x64]
// 0055bb2b  7507                 jne 0x55bb34
// 0055bb2d  e8ee4a0100           call 0x570620
// 0055bb32  eb52                 jmp 0x55bb86
// 0055bb34  3b442474             cmp eax, dword ptr [esp + 0x74]
// 0055bb38  7507                 jne 0x55bb41
// 0055bb3a  e8e14c0100           call 0x570820
// 0055bb3f  eb45                 jmp 0x55bb86
// 0055bb41  3b842484000000       cmp eax, dword ptr [esp + 0x84]
// 0055bb48  7507                 jne 0x55bb51
// 0055bb4a  e8e15d0100           call 0x571930
// 0055bb4f  eb35                 jmp 0x55bb86
// 0055bb51  3b842494000000       cmp eax, dword ptr [esp + 0x94]
// 0055bb58  7507                 jne 0x55bb61
// 0055bb5a  e8c15c0100           call 0x571820
// 0055bb5f  eb25                 jmp 0x55bb86
// 0055bb61  3b8424a4000000       cmp eax, dword ptr [esp + 0xa4]
// 0055bb68  7507                 jne 0x55bb71
// 0055bb6a  e8514f0100           call 0x570ac0
// 0055bb6f  eb15                 jmp 0x55bb86
// 0055bb71  3b8424b4000000       cmp eax, dword ptr [esp + 0xb4]
// 0055bb78  7507                 jne 0x55bb81
// 0055bb7a  e8215f0100           call 0x571aa0
// 0055bb7f  eb05                 jmp 0x55bb86
// 0055bb81  e8da600100           call 0x571c60
// 0055bb86  83c40c               add esp, 0xc
// 0055bb89  f6466810             test byte ptr [esi + 0x68], 0x10
// 0055bb8d  0f844dfcffff         je 0x55b7e0
// 0055bb93  5f                   pop edi
// 0055bb94  5d                   pop ebp
// 0055bb95  5b                   pop ebx
// 0055bb96  5e                   pop esi
// 0055bb97  81c4a0000000         add esp, 0xa0
// 0055bb9d  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
