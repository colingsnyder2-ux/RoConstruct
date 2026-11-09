// from server: 100% by auto
// roc 2010-06 009d9d40  unit: seg_009d0000  size: 381 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009d9d40
//
// 009d9d40  56                   push esi
// 009d9d41  8b35c0bb9e00         mov esi, dword ptr [0x9ebbc0]
// 009d9d47  6a1e                 push 0x1e
// 009d9d49  33c9                 xor ecx, ecx
// 009d9d4b  6a2b                 push 0x2b
// 009d9d4d  51                   push ecx
// 009d9d4e  51                   push ecx
// 009d9d4f  b819000000           mov eax, 0x19
// 009d9d54  686062c200           push 0xc26260
// 009d9d59  a35862c200           mov dword ptr [0xc26258], eax
// 009d9d5e  890d5c62c200         mov dword ptr [0xc2625c], ecx
// 009d9d64  ffd6                 call esi
// 009d9d66  6a4c                 push 0x4c
// 009d9d68  6a3c                 push 0x3c
// 009d9d6a  6a21                 push 0x21
// 009d9d6c  6a1e                 push 0x1e
// 009d9d6e  33c0                 xor eax, eax
// 009d9d70  b919000000           mov ecx, 0x19
// 009d9d75  687862c200           push 0xc26278
// 009d9d7a  a37062c200           mov dword ptr [0xc26270], eax
// 009d9d7f  890d7462c200         mov dword ptr [0xc26274], ecx
// 009d9d85  ffd6                 call esi
// 009d9d87  6a1e                 push 0x1e
// 009d9d89  6a56                 push 0x56
// 009d9d8b  6a00                 push 0
// 009d9d8d  6a2b                 push 0x2b
// 009d9d8f  b819000000           mov eax, 0x19
// 009d9d94  b93f000000           mov ecx, 0x3f
// 009d9d99  689062c200           push 0xc26290
// 009d9d9e  a38862c200           mov dword ptr [0xc26288], eax
// 009d9da3  890d8c62c200         mov dword ptr [0xc2628c], ecx
// 009d9da9  ffd6                 call esi
// 009d9dab  6a4c                 push 0x4c
// 009d9dad  6a1e                 push 0x1e
// 009d9daf  6a21                 push 0x21
// 009d9db1  6a00                 push 0
// 009d9db3  b83f000000           mov eax, 0x3f
// 009d9db8  b919000000           mov ecx, 0x19
// 009d9dbd  68a862c200           push 0xc262a8
// 009d9dc2  a3a062c200           mov dword ptr [0xc262a0], eax
// 009d9dc7  890da462c200         mov dword ptr [0xc262a4], ecx
// 009d9dcd  ffd6                 call esi
// 009d9dcf  6a6a                 push 0x6a
// 009d9dd1  6a2b                 push 0x2b
// 009d9dd3  33c9                 xor ecx, ecx
// 009d9dd5  6a4c                 push 0x4c
// 009d9dd7  51                   push ecx
// 009d9dd8  b819000000           mov eax, 0x19
// 009d9ddd  68c062c200           push 0xc262c0
// 009d9de2  a3b862c200           mov dword ptr [0xc262b8], eax
// 009d9de7  890dbc62c200         mov dword ptr [0xc262bc], ecx
// 009d9ded  ffd6                 call esi
// 009d9def  6a4c                 push 0x4c
// 009d9df1  6a78                 push 0x78
// 009d9df3  6a21                 push 0x21
// 009d9df5  6a5a                 push 0x5a
// 009d9df7  33c0                 xor eax, eax
// 009d9df9  b919000000           mov ecx, 0x19
// 009d9dfe  68d862c200           push 0xc262d8
// 009d9e03  a3d062c200           mov dword ptr [0xc262d0], eax
// 009d9e08  890dd462c200         mov dword ptr [0xc262d4], ecx
// 009d9e0e  ffd6                 call esi
// 009d9e10  6a6a                 push 0x6a
// 009d9e12  6a56                 push 0x56
// 009d9e14  6a4c                 push 0x4c
// 009d9e16  6a2b                 push 0x2b
// 009d9e18  b819000000           mov eax, 0x19
// 009d9e1d  b93f000000           mov ecx, 0x3f
// 009d9e22  68f062c200           push 0xc262f0
// 009d9e27  a3e862c200           mov dword ptr [0xc262e8], eax
// 009d9e2c  890dec62c200         mov dword ptr [0xc262ec], ecx
// 009d9e32  ffd6                 call esi
// 009d9e34  6a4c                 push 0x4c
// 009d9e36  6a5a                 push 0x5a
// 009d9e38  6a21                 push 0x21
// 009d9e3a  b83f000000           mov eax, 0x3f
// 009d9e3f  b919000000           mov ecx, 0x19
// 009d9e44  6a3c                 push 0x3c
// 009d9e46  a30063c200           mov dword ptr [0xc26300], eax
// 009d9e4b  890d0463c200         mov dword ptr [0xc26304], ecx
// 009d9e51  680863c200           push 0xc26308
// 009d9e56  ffd6                 call esi
// 009d9e58  6a21                 push 0x21
// 009d9e5a  6a77                 push 0x77
// 009d9e5c  6a00                 push 0
// 009d9e5e  b81e000000           mov eax, 0x1e
// 009d9e63  6a56                 push 0x56
// 009d9e65  8bc8                 mov ecx, eax
// 009d9e67  682063c200           push 0xc26320
// 009d9e6c  a31863c200           mov dword ptr [0xc26318], eax
// 009d9e71  890d1c63c200         mov dword ptr [0xc2631c], ecx
// 009d9e77  ffd6                 call esi
// 009d9e79  6a6d                 push 0x6d
// 009d9e7b  6a77                 push 0x77
// 009d9e7d  6a4c                 push 0x4c
// 009d9e7f  b81e000000           mov eax, 0x1e
// 009d9e84  6a56                 push 0x56
// 009d9e86  8bc8                 mov ecx, eax
// 009d9e88  683863c200           push 0xc26338
// 009d9e8d  a33063c200           mov dword ptr [0xc26330], eax
// 009d9e92  890d3463c200         mov dword ptr [0xc26334], ecx
// 009d9e98  ffd6                 call esi
// 009d9e9a  6a2b                 push 0x2b
// 009d9e9c  6a2b                 push 0x2b
// 009d9e9e  6a00                 push 0
// 009d9ea0  b819000000           mov eax, 0x19
// 009d9ea5  6a00                 push 0
// 009d9ea7  8bc8                 mov ecx, eax
// 009d9ea9  685063c200           push 0xc26350
// 009d9eae  a34863c200           mov dword ptr [0xc26348], eax
// 009d9eb3  890d4c63c200         mov dword ptr [0xc2634c], ecx
// 009d9eb9  ffd6                 call esi
// 009d9ebb  5e                   pop esi
// 009d9ebc  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??__EarrSpritesStyckerWidbey@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
