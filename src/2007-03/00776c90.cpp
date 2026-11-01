// from server: 100% by auto
// roc 2007-03 00776c90  unit: seg_00770000  size: 625 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00776c90
//
// 00776c90  56                   push esi
// 00776c91  8b35b4ed7700         mov esi, dword ptr [0x77edb4]
// 00776c97  6a3b                 push 0x3b
// 00776c99  6a5a                 push 0x5a
// 00776c9b  6a1d                 push 0x1d
// 00776c9d  6a3d                 push 0x3d
// 00776c9f  b81e000000           mov eax, 0x1e
// 00776ca4  33c9                 xor ecx, ecx
// 00776ca6  6858248c00           push 0x8c2458
// 00776cab  a350248c00           mov dword ptr [0x8c2450], eax
// 00776cb0  890d54248c00         mov dword ptr [0x8c2454], ecx
// 00776cb6  ffd6                 call esi
// 00776cb8  6a3b                 push 0x3b
// 00776cba  6a78                 push 0x78
// 00776cbc  b91e000000           mov ecx, 0x1e
// 00776cc1  51                   push ecx
// 00776cc2  6a5a                 push 0x5a
// 00776cc4  33c0                 xor eax, eax
// 00776cc6  6870248c00           push 0x8c2470
// 00776ccb  a368248c00           mov dword ptr [0x8c2468], eax
// 00776cd0  890d6c248c00         mov dword ptr [0x8c246c], ecx
// 00776cd6  ffd6                 call esi
// 00776cd8  b81e000000           mov eax, 0x1e
// 00776cdd  50                   push eax
// 00776cde  6a78                 push 0x78
// 00776ce0  6a00                 push 0
// 00776ce2  6a5b                 push 0x5b
// 00776ce4  b93b000000           mov ecx, 0x3b
// 00776ce9  6888248c00           push 0x8c2488
// 00776cee  a380248c00           mov dword ptr [0x8c2480], eax
// 00776cf3  890d84248c00         mov dword ptr [0x8c2484], ecx
// 00776cf9  ffd6                 call esi
// 00776cfb  6a1d                 push 0x1d
// 00776cfd  6a5c                 push 0x5c
// 00776cff  6a00                 push 0
// 00776d01  6a3e                 push 0x3e
// 00776d03  b83c000000           mov eax, 0x3c
// 00776d08  b91e000000           mov ecx, 0x1e
// 00776d0d  68a0248c00           push 0x8c24a0
// 00776d12  a398248c00           mov dword ptr [0x8c2498], eax
// 00776d17  890d9c248c00         mov dword ptr [0x8c249c], ecx
// 00776d1d  ffd6                 call esi
// 00776d1f  6a78                 push 0x78
// 00776d21  6a5a                 push 0x5a
// 00776d23  6a5a                 push 0x5a
// 00776d25  6a3d                 push 0x3d
// 00776d27  b81e000000           mov eax, 0x1e
// 00776d2c  33c9                 xor ecx, ecx
// 00776d2e  68b8248c00           push 0x8c24b8
// 00776d33  a3b0248c00           mov dword ptr [0x8c24b0], eax
// 00776d38  890db4248c00         mov dword ptr [0x8c24b4], ecx
// 00776d3e  ffd6                 call esi
// 00776d40  6a78                 push 0x78
// 00776d42  6a78                 push 0x78
// 00776d44  6a5b                 push 0x5b
// 00776d46  6a5a                 push 0x5a
// 00776d48  33c0                 xor eax, eax
// 00776d4a  b91e000000           mov ecx, 0x1e
// 00776d4f  68d0248c00           push 0x8c24d0
// 00776d54  a3c8248c00           mov dword ptr [0x8c24c8], eax
// 00776d59  890dcc248c00         mov dword ptr [0x8c24cc], ecx
// 00776d5f  ffd6                 call esi
// 00776d61  6a5b                 push 0x5b
// 00776d63  6a78                 push 0x78
// 00776d65  6a3d                 push 0x3d
// 00776d67  6a5b                 push 0x5b
// 00776d69  b81e000000           mov eax, 0x1e
// 00776d6e  b93b000000           mov ecx, 0x3b
// 00776d73  68e8248c00           push 0x8c24e8
// 00776d78  a3e0248c00           mov dword ptr [0x8c24e0], eax
// 00776d7d  890de4248c00         mov dword ptr [0x8c24e4], ecx
// 00776d83  ffd6                 call esi
// 00776d85  6a5a                 push 0x5a
// 00776d87  6a5c                 push 0x5c
// 00776d89  6a3d                 push 0x3d
// 00776d8b  b83c000000           mov eax, 0x3c
// 00776d90  b91e000000           mov ecx, 0x1e
// 00776d95  6a3e                 push 0x3e
// 00776d97  a3f8248c00           mov dword ptr [0x8c24f8], eax
// 00776d9c  890dfc248c00         mov dword ptr [0x8c24fc], ecx
// 00776da2  6800258c00           push 0x8c2500
// 00776da7  ffd6                 call esi
// 00776da9  6a6f                 push 0x6f
// 00776dab  6894000000           push 0x94
// 00776db0  6a52                 push 0x52
// 00776db2  b81e000000           mov eax, 0x1e
// 00776db7  6a78                 push 0x78
// 00776db9  8bc8                 mov ecx, eax
// 00776dbb  6818258c00           push 0x8c2518
// 00776dc0  a310258c00           mov dword ptr [0x8c2510], eax
// 00776dc5  890d14258c00         mov dword ptr [0x8c2514], ecx
// 00776dcb  ffd6                 call esi
// 00776dcd  6a52                 push 0x52
// 00776dcf  68a1000000           push 0xa1
// 00776dd4  6a29                 push 0x29
// 00776dd6  b818000000           mov eax, 0x18
// 00776ddb  6a78                 push 0x78
// 00776ddd  8bc8                 mov ecx, eax
// 00776ddf  6830258c00           push 0x8c2530
// 00776de4  a328258c00           mov dword ptr [0x8c2528], eax
// 00776de9  890d2c258c00         mov dword ptr [0x8c252c], ecx
// 00776def  ffd6                 call esi
// 00776df1  6a29                 push 0x29
// 00776df3  68a1000000           push 0xa1
// 00776df8  6a00                 push 0
// 00776dfa  b818000000           mov eax, 0x18
// 00776dff  6a78                 push 0x78
// 00776e01  8bc8                 mov ecx, eax
// 00776e03  6848258c00           push 0x8c2548
// 00776e08  a340258c00           mov dword ptr [0x8c2540], eax
// 00776e0d  890d44258c00         mov dword ptr [0x8c2544], ecx
// 00776e13  ffd6                 call esi
// 00776e15  6a3d                 push 0x3d
// 00776e17  6a1d                 push 0x1d
// 00776e19  33c9                 xor ecx, ecx
// 00776e1b  6a1d                 push 0x1d
// 00776e1d  51                   push ecx
// 00776e1e  33c0                 xor eax, eax
// 00776e20  6860258c00           push 0x8c2560
// 00776e25  a358258c00           mov dword ptr [0x8c2558], eax
// 00776e2a  890d5c258c00         mov dword ptr [0x8c255c], ecx
// 00776e30  ffd6                 call esi
// 00776e32  6a3d                 push 0x3d
// 00776e34  6a3d                 push 0x3d
// 00776e36  6a20                 push 0x20
// 00776e38  6a1d                 push 0x1d
// 00776e3a  33c0                 xor eax, eax
// 00776e3c  33c9                 xor ecx, ecx
// 00776e3e  6878258c00           push 0x8c2578
// 00776e43  a370258c00           mov dword ptr [0x8c2570], eax
// 00776e48  890d74258c00         mov dword ptr [0x8c2574], ecx
// 00776e4e  ffd6                 call esi
// 00776e50  6a20                 push 0x20
// 00776e52  6a3d                 push 0x3d
// 00776e54  33c9                 xor ecx, ecx
// 00776e56  51                   push ecx
// 00776e57  6a20                 push 0x20
// 00776e59  33c0                 xor eax, eax
// 00776e5b  6890258c00           push 0x8c2590
// 00776e60  a388258c00           mov dword ptr [0x8c2588], eax
// 00776e65  890d8c258c00         mov dword ptr [0x8c258c], ecx
// 00776e6b  ffd6                 call esi
// 00776e6d  6a1d                 push 0x1d
// 00776e6f  33c9                 xor ecx, ecx
// 00776e71  6a20                 push 0x20
// 00776e73  51                   push ecx
// 00776e74  51                   push ecx
// 00776e75  33c0                 xor eax, eax
// 00776e77  68a8258c00           push 0x8c25a8
// 00776e7c  a3a0258c00           mov dword ptr [0x8c25a0], eax
// 00776e81  890da4258c00         mov dword ptr [0x8c25a4], ecx
// 00776e87  ffd6                 call esi
// 00776e89  6a7a                 push 0x7a
// 00776e8b  6a1d                 push 0x1d
// 00776e8d  33c9                 xor ecx, ecx
// 00776e8f  6a5a                 push 0x5a
// 00776e91  51                   push ecx
// 00776e92  33c0                 xor eax, eax
// 00776e94  68c0258c00           push 0x8c25c0
// 00776e99  a3b8258c00           mov dword ptr [0x8c25b8], eax
// 00776e9e  890dbc258c00         mov dword ptr [0x8c25bc], ecx
// 00776ea4  ffd6                 call esi
// 00776ea6  6a7a                 push 0x7a
// 00776ea8  6a3d                 push 0x3d
// 00776eaa  6a5d                 push 0x5d
// 00776eac  6a1d                 push 0x1d
// 00776eae  33c0                 xor eax, eax
// 00776eb0  33c9                 xor ecx, ecx
// 00776eb2  68d8258c00           push 0x8c25d8
// 00776eb7  a3d0258c00           mov dword ptr [0x8c25d0], eax
// 00776ebc  890dd4258c00         mov dword ptr [0x8c25d4], ecx
// 00776ec2  ffd6                 call esi
// 00776ec4  6a5d                 push 0x5d
// 00776ec6  6a3d                 push 0x3d
// 00776ec8  6a3d                 push 0x3d
// 00776eca  6a20                 push 0x20
// 00776ecc  33c0                 xor eax, eax
// 00776ece  33c9                 xor ecx, ecx
// 00776ed0  68f0258c00           push 0x8c25f0
// 00776ed5  a3e8258c00           mov dword ptr [0x8c25e8], eax
// 00776eda  890dec258c00         mov dword ptr [0x8c25ec], ecx
// 00776ee0  ffd6                 call esi
// 00776ee2  6a5a                 push 0x5a
// 00776ee4  6a20                 push 0x20
// 00776ee6  33c9                 xor ecx, ecx
// 00776ee8  6a3d                 push 0x3d
// 00776eea  51                   push ecx
// 00776eeb  33c0                 xor eax, eax
// 00776eed  6808268c00           push 0x8c2608
// 00776ef2  a300268c00           mov dword ptr [0x8c2600], eax
// 00776ef7  890d04268c00         mov dword ptr [0x8c2604], ecx
// 00776efd  ffd6                 call esi
// 00776eff  5e                   pop esi
// 00776f00  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??__EarrSpritesStyckerVisualStudio2005@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
