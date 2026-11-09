// from server: 100% by auto
// roc 2010-06 009d9ec0  unit: seg_009d0000  size: 625 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009d9ec0
//
// 009d9ec0  56                   push esi
// 009d9ec1  8b35c0bb9e00         mov esi, dword ptr [0x9ebbc0]
// 009d9ec7  6a3b                 push 0x3b
// 009d9ec9  6a5a                 push 0x5a
// 009d9ecb  6a1d                 push 0x1d
// 009d9ecd  6a3d                 push 0x3d
// 009d9ecf  b81e000000           mov eax, 0x1e
// 009d9ed4  33c9                 xor ecx, ecx
// 009d9ed6  686863c200           push 0xc26368
// 009d9edb  a36063c200           mov dword ptr [0xc26360], eax
// 009d9ee0  890d6463c200         mov dword ptr [0xc26364], ecx
// 009d9ee6  ffd6                 call esi
// 009d9ee8  6a3b                 push 0x3b
// 009d9eea  6a78                 push 0x78
// 009d9eec  b91e000000           mov ecx, 0x1e
// 009d9ef1  51                   push ecx
// 009d9ef2  6a5a                 push 0x5a
// 009d9ef4  33c0                 xor eax, eax
// 009d9ef6  688063c200           push 0xc26380
// 009d9efb  a37863c200           mov dword ptr [0xc26378], eax
// 009d9f00  890d7c63c200         mov dword ptr [0xc2637c], ecx
// 009d9f06  ffd6                 call esi
// 009d9f08  b81e000000           mov eax, 0x1e
// 009d9f0d  50                   push eax
// 009d9f0e  6a78                 push 0x78
// 009d9f10  6a00                 push 0
// 009d9f12  6a5b                 push 0x5b
// 009d9f14  b93b000000           mov ecx, 0x3b
// 009d9f19  689863c200           push 0xc26398
// 009d9f1e  a39063c200           mov dword ptr [0xc26390], eax
// 009d9f23  890d9463c200         mov dword ptr [0xc26394], ecx
// 009d9f29  ffd6                 call esi
// 009d9f2b  6a1d                 push 0x1d
// 009d9f2d  6a5c                 push 0x5c
// 009d9f2f  6a00                 push 0
// 009d9f31  6a3e                 push 0x3e
// 009d9f33  b83c000000           mov eax, 0x3c
// 009d9f38  b91e000000           mov ecx, 0x1e
// 009d9f3d  68b063c200           push 0xc263b0
// 009d9f42  a3a863c200           mov dword ptr [0xc263a8], eax
// 009d9f47  890dac63c200         mov dword ptr [0xc263ac], ecx
// 009d9f4d  ffd6                 call esi
// 009d9f4f  6a78                 push 0x78
// 009d9f51  6a5a                 push 0x5a
// 009d9f53  6a5a                 push 0x5a
// 009d9f55  6a3d                 push 0x3d
// 009d9f57  b81e000000           mov eax, 0x1e
// 009d9f5c  33c9                 xor ecx, ecx
// 009d9f5e  68c863c200           push 0xc263c8
// 009d9f63  a3c063c200           mov dword ptr [0xc263c0], eax
// 009d9f68  890dc463c200         mov dword ptr [0xc263c4], ecx
// 009d9f6e  ffd6                 call esi
// 009d9f70  6a78                 push 0x78
// 009d9f72  6a78                 push 0x78
// 009d9f74  6a5b                 push 0x5b
// 009d9f76  6a5a                 push 0x5a
// 009d9f78  33c0                 xor eax, eax
// 009d9f7a  b91e000000           mov ecx, 0x1e
// 009d9f7f  68e063c200           push 0xc263e0
// 009d9f84  a3d863c200           mov dword ptr [0xc263d8], eax
// 009d9f89  890ddc63c200         mov dword ptr [0xc263dc], ecx
// 009d9f8f  ffd6                 call esi
// 009d9f91  6a5b                 push 0x5b
// 009d9f93  6a78                 push 0x78
// 009d9f95  6a3d                 push 0x3d
// 009d9f97  6a5b                 push 0x5b
// 009d9f99  b81e000000           mov eax, 0x1e
// 009d9f9e  b93b000000           mov ecx, 0x3b
// 009d9fa3  68f863c200           push 0xc263f8
// 009d9fa8  a3f063c200           mov dword ptr [0xc263f0], eax
// 009d9fad  890df463c200         mov dword ptr [0xc263f4], ecx
// 009d9fb3  ffd6                 call esi
// 009d9fb5  6a5a                 push 0x5a
// 009d9fb7  6a5c                 push 0x5c
// 009d9fb9  6a3d                 push 0x3d
// 009d9fbb  b83c000000           mov eax, 0x3c
// 009d9fc0  b91e000000           mov ecx, 0x1e
// 009d9fc5  6a3e                 push 0x3e
// 009d9fc7  a30864c200           mov dword ptr [0xc26408], eax
// 009d9fcc  890d0c64c200         mov dword ptr [0xc2640c], ecx
// 009d9fd2  681064c200           push 0xc26410
// 009d9fd7  ffd6                 call esi
// 009d9fd9  6a6f                 push 0x6f
// 009d9fdb  6894000000           push 0x94
// 009d9fe0  6a52                 push 0x52
// 009d9fe2  b81e000000           mov eax, 0x1e
// 009d9fe7  6a78                 push 0x78
// 009d9fe9  8bc8                 mov ecx, eax
// 009d9feb  682864c200           push 0xc26428
// 009d9ff0  a32064c200           mov dword ptr [0xc26420], eax
// 009d9ff5  890d2464c200         mov dword ptr [0xc26424], ecx
// 009d9ffb  ffd6                 call esi
// 009d9ffd  6a52                 push 0x52
// 009d9fff  68a1000000           push 0xa1
// 009da004  6a29                 push 0x29
// 009da006  b818000000           mov eax, 0x18
// 009da00b  6a78                 push 0x78
// 009da00d  8bc8                 mov ecx, eax
// 009da00f  684064c200           push 0xc26440
// 009da014  a33864c200           mov dword ptr [0xc26438], eax
// 009da019  890d3c64c200         mov dword ptr [0xc2643c], ecx
// 009da01f  ffd6                 call esi
// 009da021  6a29                 push 0x29
// 009da023  68a1000000           push 0xa1
// 009da028  6a00                 push 0
// 009da02a  b818000000           mov eax, 0x18
// 009da02f  6a78                 push 0x78
// 009da031  8bc8                 mov ecx, eax
// 009da033  685864c200           push 0xc26458
// 009da038  a35064c200           mov dword ptr [0xc26450], eax
// 009da03d  890d5464c200         mov dword ptr [0xc26454], ecx
// 009da043  ffd6                 call esi
// 009da045  6a3d                 push 0x3d
// 009da047  6a1d                 push 0x1d
// 009da049  33c9                 xor ecx, ecx
// 009da04b  6a1d                 push 0x1d
// 009da04d  51                   push ecx
// 009da04e  33c0                 xor eax, eax
// 009da050  687064c200           push 0xc26470
// 009da055  a36864c200           mov dword ptr [0xc26468], eax
// 009da05a  890d6c64c200         mov dword ptr [0xc2646c], ecx
// 009da060  ffd6                 call esi
// 009da062  6a3d                 push 0x3d
// 009da064  6a3d                 push 0x3d
// 009da066  6a20                 push 0x20
// 009da068  6a1d                 push 0x1d
// 009da06a  33c0                 xor eax, eax
// 009da06c  33c9                 xor ecx, ecx
// 009da06e  688864c200           push 0xc26488
// 009da073  a38064c200           mov dword ptr [0xc26480], eax
// 009da078  890d8464c200         mov dword ptr [0xc26484], ecx
// 009da07e  ffd6                 call esi
// 009da080  6a20                 push 0x20
// 009da082  6a3d                 push 0x3d
// 009da084  33c9                 xor ecx, ecx
// 009da086  51                   push ecx
// 009da087  6a20                 push 0x20
// 009da089  33c0                 xor eax, eax
// 009da08b  68a064c200           push 0xc264a0
// 009da090  a39864c200           mov dword ptr [0xc26498], eax
// 009da095  890d9c64c200         mov dword ptr [0xc2649c], ecx
// 009da09b  ffd6                 call esi
// 009da09d  6a1d                 push 0x1d
// 009da09f  33c9                 xor ecx, ecx
// 009da0a1  6a20                 push 0x20
// 009da0a3  51                   push ecx
// 009da0a4  51                   push ecx
// 009da0a5  33c0                 xor eax, eax
// 009da0a7  68b864c200           push 0xc264b8
// 009da0ac  a3b064c200           mov dword ptr [0xc264b0], eax
// 009da0b1  890db464c200         mov dword ptr [0xc264b4], ecx
// 009da0b7  ffd6                 call esi
// 009da0b9  6a7a                 push 0x7a
// 009da0bb  6a1d                 push 0x1d
// 009da0bd  33c9                 xor ecx, ecx
// 009da0bf  6a5a                 push 0x5a
// 009da0c1  51                   push ecx
// 009da0c2  33c0                 xor eax, eax
// 009da0c4  68d064c200           push 0xc264d0
// 009da0c9  a3c864c200           mov dword ptr [0xc264c8], eax
// 009da0ce  890dcc64c200         mov dword ptr [0xc264cc], ecx
// 009da0d4  ffd6                 call esi
// 009da0d6  6a7a                 push 0x7a
// 009da0d8  6a3d                 push 0x3d
// 009da0da  6a5d                 push 0x5d
// 009da0dc  6a1d                 push 0x1d
// 009da0de  33c0                 xor eax, eax
// 009da0e0  33c9                 xor ecx, ecx
// 009da0e2  68e864c200           push 0xc264e8
// 009da0e7  a3e064c200           mov dword ptr [0xc264e0], eax
// 009da0ec  890de464c200         mov dword ptr [0xc264e4], ecx
// 009da0f2  ffd6                 call esi
// 009da0f4  6a5d                 push 0x5d
// 009da0f6  6a3d                 push 0x3d
// 009da0f8  6a3d                 push 0x3d
// 009da0fa  6a20                 push 0x20
// 009da0fc  33c0                 xor eax, eax
// 009da0fe  33c9                 xor ecx, ecx
// 009da100  680065c200           push 0xc26500
// 009da105  a3f864c200           mov dword ptr [0xc264f8], eax
// 009da10a  890dfc64c200         mov dword ptr [0xc264fc], ecx
// 009da110  ffd6                 call esi
// 009da112  6a5a                 push 0x5a
// 009da114  6a20                 push 0x20
// 009da116  33c9                 xor ecx, ecx
// 009da118  6a3d                 push 0x3d
// 009da11a  51                   push ecx
// 009da11b  33c0                 xor eax, eax
// 009da11d  681865c200           push 0xc26518
// 009da122  a31065c200           mov dword ptr [0xc26510], eax
// 009da127  890d1465c200         mov dword ptr [0xc26514], ecx
// 009da12d  ffd6                 call esi
// 009da12f  5e                   pop esi
// 009da130  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??__EarrSpritesStyckerVisualStudio2005@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
