// from server: 100% by Intel
﻿// from server: 98% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 00440e30  unit: CSelectionPropGrid  size: 1321 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00440e30
//
// 00440e30  64a100000000         mov eax, dword ptr fs:[0]
// 00440e36  6aff                 push -1
// 00440e38  68c80a7c00           push 0x7c0ac8
// 00440e3d  50                   push eax
// 00440e3e  64892500000000       mov dword ptr fs:[0], esp
// 00440e45  8b442410             mov eax, dword ptr [esp + 0x10]
// 00440e49  53                   push ebx
// 00440e4a  55                   push ebp
// 00440e4b  56                   push esi
// 00440e4c  8b742420             mov esi, dword ptr [esp + 0x20]
// 00440e50  57                   push edi
// 00440e51  8bf9                 mov edi, ecx
// 00440e53  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00440e56  50                   push eax
// 00440e57  e8c4ef1200           call 0x56fe20
// 00440e5c  84c0                 test al, al
// 00440e5e  0f85e0040000         jne 0x441344
// 00440e64  bb01000000           mov ebx, 1
// 00440e69  845e10               test byte ptr [esi + 0x10], bl
// 00440e6c  0f84d2040000         je 0x441344
// 00440e72  6a00                 push 0
// 00440e74  6878959200           push 0x929578
// 00440e79  68b4959200           push 0x9295b4
// 00440e7e  6a00                 push 0
// 00440e80  56                   push esi
// 00440e81  e840092600           call 0x6a17c6
// 00440e86  8be8                 mov ebp, eax
// 00440e88  83c414               add esp, 0x14
// 00440e8b  85ed                 test ebp, ebp
// 00440e8d  744f                 je 0x440ede
// 00440e8f  6844010000           push 0x144
// 00440e94  e887fa2500           call 0x6a0920
// 00440e99  83c404               add esp, 4
// 00440e9c  89442420             mov dword ptr [esp + 0x20], eax
// 00440ea0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00440ea8  85c0                 test eax, eax
// 00440eaa  740b                 je 0x440eb7
// 00440eac  57                   push edi
// 00440ead  55                   push ebp
// 00440eae  8bc8                 mov ecx, eax
// 00440eb0  e87bc4ffff           call 0x43d330
// 00440eb5  eb02                 jmp 0x440eb9
// 00440eb7  33c0                 xor eax, eax
// 00440eb9  50                   push eax
// 00440eba  8bcf                 mov ecx, edi
// 00440ebc  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00440ec4  e84789ffff           call 0x439810
// 00440ec9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00440ecd  64890d00000000       mov dword ptr fs:[0], ecx
// 00440ed4  5f                   pop edi
// 00440ed5  5e                   pop esi
// 00440ed6  5d                   pop ebp
// 00440ed7  5b                   pop ebx
// 00440ed8  83c40c               add esp, 0xc
// 00440edb  c20800               ret 8
// 00440ede  6a00                 push 0
// 00440ee0  68f4ff9200           push 0x92fff4
// 00440ee5  68b4959200           push 0x9295b4
// 00440eea  6a00                 push 0
// 00440eec  56                   push esi
// 00440eed  e8d4082600           call 0x6a17c6
// 00440ef2  8be8                 mov ebp, eax
// 00440ef4  83c414               add esp, 0x14
// 00440ef7  85ed                 test ebp, ebp
// 00440ef9  744b                 je 0x440f46
// 00440efb  6830010000           push 0x130
// 00440f00  e81bfa2500           call 0x6a0920
// 00440f05  83c404               add esp, 4
// 00440f08  89442420             mov dword ptr [esp + 0x20], eax
// 00440f0c  895c2418             mov dword ptr [esp + 0x18], ebx
// 00440f10  85c0                 test eax, eax
// 00440f12  740b                 je 0x440f1f
// 00440f14  57                   push edi
// 00440f15  55                   push ebp
// 00440f16  8bc8                 mov ecx, eax
// 00440f18  e83397ffff           call 0x43a650
// 00440f1d  eb02                 jmp 0x440f21
// 00440f1f  33c0                 xor eax, eax
// 00440f21  50                   push eax
// 00440f22  8bcf                 mov ecx, edi
// 00440f24  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00440f2c  e86f8cffff           call 0x439ba0
// 00440f31  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00440f35  64890d00000000       mov dword ptr fs:[0], ecx
// 00440f3c  5f                   pop edi
// 00440f3d  5e                   pop esi
// 00440f3e  5d                   pop ebp
// 00440f3f  5b                   pop ebx
// 00440f40  83c40c               add esp, 0xc
// 00440f43  c20800               ret 8
// 00440f46  6a00                 push 0
// 00440f48  68b8ff9200           push 0x92ffb8
// 00440f4d  68b4959200           push 0x9295b4
// 00440f52  6a00                 push 0
// 00440f54  56                   push esi
// 00440f55  e86c082600           call 0x6a17c6
// 00440f5a  8bd8                 mov ebx, eax
// 00440f5c  83c414               add esp, 0x14
// 00440f5f  85db                 test ebx, ebx
// 00440f61  744f                 je 0x440fb2
// 00440f63  6830010000           push 0x130
// 00440f68  e8b3f92500           call 0x6a0920
// 00440f6d  83c404               add esp, 4
// 00440f70  89442420             mov dword ptr [esp + 0x20], eax
// 00440f74  c744241802000000     mov dword ptr [esp + 0x18], 2
// 00440f7c  85c0                 test eax, eax
// 00440f7e  740b                 je 0x440f8b
// 00440f80  57                   push edi
// 00440f81  53                   push ebx
// 00440f82  8bc8                 mov ecx, eax
// 00440f84  e8879bffff           call 0x43ab10
// 00440f89  eb02                 jmp 0x440f8d
// 00440f8b  33c0                 xor eax, eax
// 00440f8d  50                   push eax
// 00440f8e  8bcf                 mov ecx, edi
// 00440f90  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00440f98  e8038cffff           call 0x439ba0
// 00440f9d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00440fa1  64890d00000000       mov dword ptr fs:[0], ecx
// 00440fa8  5f                   pop edi
// 00440fa9  5e                   pop esi
// 00440faa  5d                   pop ebp
// 00440fab  5b                   pop ebx
// 00440fac  83c40c               add esp, 0xc
// 00440faf  c20800               ret 8
// 00440fb2  6a00                 push 0
// 00440fb4  6870ff9200           push 0x92ff70
// 00440fb9  68b4959200           push 0x9295b4
// 00440fbe  6a00                 push 0
// 00440fc0  56                   push esi
// 00440fc1  e800082600           call 0x6a17c6
// 00440fc6  8bd8                 mov ebx, eax
// 00440fc8  83c414               add esp, 0x14
// 00440fcb  85db                 test ebx, ebx
// 00440fcd  744f                 je 0x44101e
// 00440fcf  683c010000           push 0x13c
// 00440fd4  e847f92500           call 0x6a0920
// 00440fd9  83c404               add esp, 4
// 00440fdc  89442420             mov dword ptr [esp + 0x20], eax
// 00440fe0  c744241803000000     mov dword ptr [esp + 0x18], 3
// 00440fe8  85c0                 test eax, eax
// 00440fea  740b                 je 0x440ff7
// 00440fec  57                   push edi
// 00440fed  53                   push ebx
// 00440fee  8bc8                 mov ecx, eax
// 00440ff0  e80b9fffff           call 0x43af00
// 00440ff5  eb02                 jmp 0x440ff9
// 00440ff7  33c0                 xor eax, eax
// 00440ff9  50                   push eax
// 00440ffa  8bcf                 mov ecx, edi
// 00440ffc  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00441004  e83789ffff           call 0x439940
// 00441009  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044100d  64890d00000000       mov dword ptr fs:[0], ecx
// 00441014  5f                   pop edi
// 00441015  5e                   pop esi
// 00441016  5d                   pop ebp
// 00441017  5b                   pop ebx
// 00441018  83c40c               add esp, 0xc
// 0044101b  c20800               ret 8
// 0044101e  6a00                 push 0
// 00441020  6820ff9200           push 0x92ff20
// 00441025  68b4959200           push 0x9295b4
// 0044102a  6a00                 push 0
// 0044102c  56                   push esi
// 0044102d  e894072600           call 0x6a17c6
// 00441032  8bd8                 mov ebx, eax
// 00441034  83c414               add esp, 0x14
// 00441037  85db                 test ebx, ebx
// 00441039  744f                 je 0x44108a
// 0044103b  683c010000           push 0x13c
// 00441040  e8dbf82500           call 0x6a0920
// 00441045  83c404               add esp, 4
// 00441048  89442420             mov dword ptr [esp + 0x20], eax
// 0044104c  c744241804000000     mov dword ptr [esp + 0x18], 4
// 00441054  85c0                 test eax, eax
// 00441056  740b                 je 0x441063
// 00441058  57                   push edi
// 00441059  53                   push ebx
// 0044105a  8bc8                 mov ecx, eax
// 0044105c  e8ffc4ffff           call 0x43d560
// 00441061  eb02                 jmp 0x441065
// 00441063  33c0                 xor eax, eax
// 00441065  50                   push eax
// 00441066  8bcf                 mov ecx, edi
// 00441068  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00441070  e8cb88ffff           call 0x439940
// 00441075  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00441079  64890d00000000       mov dword ptr fs:[0], ecx
// 00441080  5f                   pop edi
// 00441081  5e                   pop esi
// 00441082  5d                   pop ebp
// 00441083  5b                   pop ebx
// 00441084  83c40c               add esp, 0xc
// 00441087  c20800               ret 8
// 0044108a  6a00                 push 0
// 0044108c  68d8fe9200           push 0x92fed8
// 00441091  68b4959200           push 0x9295b4
// 00441096  6a00                 push 0
// 00441098  56                   push esi
// 00441099  e828072600           call 0x6a17c6
// 0044109e  8bd8                 mov ebx, eax
// 004410a0  83c414               add esp, 0x14
// 004410a3  85db                 test ebx, ebx
// 004410a5  744f                 je 0x4410f6
// 004410a7  683c010000           push 0x13c
// 004410ac  e86ff82500           call 0x6a0920
// 004410b1  83c404               add esp, 4
// 004410b4  89442420             mov dword ptr [esp + 0x20], eax
// 004410b8  c744241805000000     mov dword ptr [esp + 0x18], 5
// 004410c0  85c0                 test eax, eax
// 004410c2  740b                 je 0x4410cf
// 004410c4  57                   push edi
// 004410c5  53                   push ebx
// 004410c6  8bc8                 mov ecx, eax
// 004410c8  e8f3c5ffff           call 0x43d6c0
// 004410cd  eb02                 jmp 0x4410d1
// 004410cf  33c0                 xor eax, eax
// 004410d1  50                   push eax
// 004410d2  8bcf                 mov ecx, edi
// 004410d4  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004410dc  e8bf8affff           call 0x439ba0
// 004410e1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004410e5  64890d00000000       mov dword ptr fs:[0], ecx
// 004410ec  5f                   pop edi
// 004410ed  5e                   pop esi
// 004410ee  5d                   pop ebp
// 004410ef  5b                   pop ebx
// 004410f0  83c40c               add esp, 0xc
// 004410f3  c20800               ret 8
// 004410f6  6a00                 push 0
// 004410f8  68a4fe9200           push 0x92fea4
// 004410fd  68b4959200           push 0x9295b4
// 00441102  6a00                 push 0
// 00441104  56                   push esi
// 00441105  e8bc062600           call 0x6a17c6
// 0044110a  8bd8                 mov ebx, eax
// 0044110c  83c414               add esp, 0x14
// 0044110f  85db                 test ebx, ebx
// 00441111  744f                 je 0x441162
// 00441113  6838010000           push 0x138
// 00441118  e803f82500           call 0x6a0920
// 0044111d  83c404               add esp, 4
// 00441120  89442420             mov dword ptr [esp + 0x20], eax
// 00441124  c744241806000000     mov dword ptr [esp + 0x18], 6
// 0044112c  85c0                 test eax, eax
// 0044112e  740b                 je 0x44113b
// 00441130  57                   push edi
// 00441131  53                   push ebx
// 00441132  8bc8                 mov ecx, eax
// 00441134  e867d2ffff           call 0x43e3a0
// 00441139  eb02                 jmp 0x44113d
// 0044113b  33c0                 xor eax, eax
// 0044113d  50                   push eax
// 0044113e  8bcf                 mov ecx, edi
// 00441140  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00441148  e82389ffff           call 0x439a70
// 0044114d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00441151  64890d00000000       mov dword ptr fs:[0], ecx
// 00441158  5f                   pop edi
// 00441159  5e                   pop esi
// 0044115a  5d                   pop ebp
// 0044115b  5b                   pop ebx
// 0044115c  83c40c               add esp, 0xc
// 0044115f  c20800               ret 8
// 00441162  6a00                 push 0
// 00441164  6870fe9200           push 0x92fe70
// 00441169  68b4959200           push 0x9295b4
// 0044116e  6a00                 push 0
// 00441170  56                   push esi
// 00441171  e850062600           call 0x6a17c6
// 00441176  8bd8                 mov ebx, eax
// 00441178  83c414               add esp, 0x14
// 0044117b  85db                 test ebx, ebx
// 0044117d  744f                 je 0x4411ce
// 0044117f  6834010000           push 0x134
// 00441184  e897f72500           call 0x6a0920
// 00441189  83c404               add esp, 4
// 0044118c  89442420             mov dword ptr [esp + 0x20], eax
// 00441190  c744241807000000     mov dword ptr [esp + 0x18], 7
// 00441198  85c0                 test eax, eax
// 0044119a  740b                 je 0x4411a7
// 0044119c  57                   push edi
// 0044119d  53                   push ebx
// 0044119e  8bc8                 mov ecx, eax
// 004411a0  e8dbc9ffff           call 0x43db80
// 004411a5  eb02                 jmp 0x4411a9
// 004411a7  33c0                 xor eax, eax
// 004411a9  50                   push eax
// 004411aa  8bcf                 mov ecx, edi
// 004411ac  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004411b4  e8e789ffff           call 0x439ba0
// 004411b9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004411bd  64890d00000000       mov dword ptr fs:[0], ecx
// 004411c4  5f                   pop edi
// 004411c5  5e                   pop esi
// 004411c6  5d                   pop ebp
// 004411c7  5b                   pop ebx
// 004411c8  83c40c               add esp, 0xc
// 004411cb  c20800               ret 8
// 004411ce  81fe70579700         cmp esi, 0x975770
// 004411d4  754f                 jne 0x441225
// 004411d6  6830010000           push 0x130
// 004411db  e840f72500           call 0x6a0920
// 004411e0  83c404               add esp, 4
// 004411e3  89442420             mov dword ptr [esp + 0x20], eax
// 004411e7  c744241808000000     mov dword ptr [esp + 0x18], 8
// 004411ef  85c0                 test eax, eax
// 004411f1  740b                 je 0x4411fe
// 004411f3  57                   push edi
// 004411f4  56                   push esi
// 004411f5  8bc8                 mov ecx, eax
// 004411f7  e854cdffff           call 0x43df50
// 004411fc  eb02                 jmp 0x441200
// 004411fe  33c0                 xor eax, eax
// 00441200  50                   push eax
// 00441201  8bcf                 mov ecx, edi
// 00441203  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0044120b  e89089ffff           call 0x439ba0
// 00441210  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00441214  64890d00000000       mov dword ptr fs:[0], ecx
// 0044121b  5f                   pop edi
// 0044121c  5e                   pop esi
// 0044121d  5d                   pop ebp
// 0044121e  5b                   pop ebx
// 0044121f  83c40c               add esp, 0xc
// 00441222  c20800               ret 8
// 00441225  6a00                 push 0
// 00441227  6828fe9200           push 0x92fe28
// 0044122c  68b4959200           push 0x9295b4
// 00441231  6a00                 push 0
// 00441233  56                   push esi
// 00441234  e88d052600           call 0x6a17c6
// 00441239  8bd8                 mov ebx, eax
// 0044123b  83c414               add esp, 0x14
// 0044123e  85db                 test ebx, ebx
// 00441240  744f                 je 0x441291
// 00441242  6830010000           push 0x130
// 00441247  e8d4f62500           call 0x6a0920
// 0044124c  83c404               add esp, 4
// 0044124f  89442420             mov dword ptr [esp + 0x20], eax
// 00441253  c744241809000000     mov dword ptr [esp + 0x18], 9
// 0044125b  85c0                 test eax, eax
// 0044125d  740b                 je 0x44126a
// 0044125f  57                   push edi
// 00441260  53                   push ebx
// 00441261  8bc8                 mov ecx, eax
// 00441263  e848fbffff           call 0x440db0
// 00441268  eb02                 jmp 0x44126c
// 0044126a  33c0                 xor eax, eax
// 0044126c  50                   push eax
// 0044126d  8bcf                 mov ecx, edi
// 0044126f  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00441277  e82489ffff           call 0x439ba0
// 0044127c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00441280  64890d00000000       mov dword ptr fs:[0], ecx
// 00441287  5f                   pop edi
// 00441288  5e                   pop esi
// 00441289  5d                   pop ebp
// 0044128a  5b                   pop ebx
// 0044128b  83c40c               add esp, 0xc
// 0044128e  c20800               ret 8
// 00441291  6a00                 push 0
// 00441293  68d0fd9200           push 0x92fdd0
// 00441298  68b4959200           push 0x9295b4
// 0044129d  6a00                 push 0
// 0044129f  56                   push esi
// 004412a0  e821052600           call 0x6a17c6
// 004412a5  8bd8                 mov ebx, eax
// 004412a7  83c414               add esp, 0x14
// 004412aa  85db                 test ebx, ebx
// 004412ac  744f                 je 0x4412fd
// 004412ae  6830010000           push 0x130
// 004412b3  e868f62500           call 0x6a0920
// 004412b8  83c404               add esp, 4
// 004412bb  89442420             mov dword ptr [esp + 0x20], eax
// 004412bf  c74424180a000000     mov dword ptr [esp + 0x18], 0xa
// 004412c7  85c0                 test eax, eax
// 004412c9  740b                 je 0x4412d6
// 004412cb  57                   push edi
// 004412cc  53                   push ebx
// 004412cd  8bc8                 mov ecx, eax
// 004412cf  e85cfaffff           call 0x440d30
// 004412d4  eb02                 jmp 0x4412d8
// 004412d6  33c0                 xor eax, eax
// 004412d8  50                   push eax
// 004412d9  8bcf                 mov ecx, edi
// 004412db  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004412e3  e8b888ffff           call 0x439ba0
// 004412e8  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004412ec  64890d00000000       mov dword ptr fs:[0], ecx
// 004412f3  5f                   pop edi
// 004412f4  5e                   pop esi
// 004412f5  5d                   pop ebp
// 004412f6  5b                   pop ebx
// 004412f7  83c40c               add esp, 0xc
// 004412fa  c20800               ret 8
// 004412fd  8b16                 mov edx, dword ptr [esi]
// 004412ff  8b4218               mov eax, dword ptr [edx + 0x18]
// 00441302  8bce                 mov ecx, esi
// 00441304  ffd0                 call eax
// 00441306  84c0                 test al, al
// 00441308  743a                 je 0x441344
// 0044130a  6830010000           push 0x130
// 0044130f  e80cf62500           call 0x6a0920
// 00441314  83c404               add esp, 4
// 00441317  89442420             mov dword ptr [esp + 0x20], eax
// 0044131b  c74424180b000000     mov dword ptr [esp + 0x18], 0xb
// 00441323  85c0                 test eax, eax
// 00441325  740b                 je 0x441332
// 00441327  57                   push edi
// 00441328  56                   push esi
// 00441329  8bc8                 mov ecx, eax
// 0044132b  e830a5ffff           call 0x43b860
// 00441330  eb02                 jmp 0x441334
// 00441332  33c0                 xor eax, eax
// 00441334  50                   push eax
// 00441335  8bcf                 mov ecx, edi
// 00441337  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0044133f  e85c88ffff           call 0x439ba0
// 00441344  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00441348  5f                   pop edi
// 00441349  5e                   pop esi
// 0044134a  5d                   pop ebp
// 0044134b  64890d00000000       mov dword ptr fs:[0], ecx
// 00441352  5b                   pop ebx
// 00441353  83c40c               add esp, 0xc
// 00441356  c20800               ret 8

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern "C" void* __cdecl runtime_cast(void*, int, const void*, const void*, int);

extern char descriptorBase;
extern char descriptor0;
extern char descriptor1;
extern char descriptor2;
extern char descriptor3;
extern char descriptor4;
extern char descriptor5;
extern char descriptor6;
extern char descriptor7;
extern char descriptor9;
extern char descriptor10;

struct Grid;
struct Owner {
    bool check(void*);
};

struct Property {
    typedef bool (__thiscall *Query)(Property*);
    void** table;
    char padding[8];
    Owner* owner;
    unsigned char flags;
};
extern Property specialProperty;

struct Editor0 {
    char storage[0x130];
    Editor0(void*, Grid*);
};
struct Editor1 {
    char storage[0x11c];
    Editor1(void*, Grid*);
};
struct Editor2 {
    char storage[0x11c];
    Editor2(void*, Grid*);
};
struct Editor3 {
    char storage[0x128];
    Editor3(void*, Grid*);
};
struct Editor4 {
    char storage[0x128];
    Editor4(void*, Grid*);
};
struct Editor5 {
    char storage[0x128];
    Editor5(void*, Grid*);
};
struct Editor6 {
    char storage[0x124];
    Editor6(void*, Grid*);
};
struct Editor7 {
    char storage[0x120];
    Editor7(void*, Grid*);
};
struct Editor8 {
    char storage[0x11c];
    Editor8(void*, Grid*);
};
struct Editor9 {
    char storage[0x11c];
    Editor9(void*, Grid*);
};
struct Editor10 {
    char storage[0x11c];
    Editor10(void*, Grid*);
};
struct Editor11 {
    char storage[0x11c];
    Editor11(void*, Grid*);
};

struct Grid {
    void add0(Editor0*);
    void add3(Editor3*);
    void add3(Editor4*);
    void add6(Editor6*);
    void addOther(Editor1*);
    void addOther(Editor2*);
    void addOther(Editor5*);
    void addOther(Editor7*);
    void addOther(Editor8*);
    void addOther(Editor9*);
    void addOther(Editor10*);
    void addOther(Editor11*);
    void f(void*, Property*);
};

void Grid::f(void* object, Property* property)
{
    if (property->owner->check(object))
        return;
    if (!(property->flags & 1))
        return;

    void* typed = runtime_cast(property, 0, &descriptorBase, &descriptor0, 0);
    if (typed) {
        add0(new Editor0(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor1, 0);
    if (typed) {
        addOther(new Editor1(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor2, 0);
    if (typed) {
        addOther(new Editor2(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor3, 0);
    if (typed) {
        add3(new Editor3(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor4, 0);
    if (typed) {
        add3(new Editor4(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor5, 0);
    if (typed) {
        addOther(new Editor5(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor6, 0);
    if (typed) {
        add6(new Editor6(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor7, 0);
    if (typed) {
        addOther(new Editor7(typed, this));
        return;
    }

    if (property == &specialProperty) {
        addOther(new Editor8(property, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor9, 0);
    if (typed) {
        addOther(new Editor9(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor10, 0);
    if (typed) {
        addOther(new Editor10(typed, this));
        return;
    }

    if (((Property::Query)property->table[3])(property))
        addOther(new Editor11(property, this));
}
