// from server: 100% by auto
// roc 2009-12 0097cf90  unit: seg_00970000  size: 625 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097cf90
//
// 0097cf90  56                   push esi
// 0097cf91  8b3538ca9800         mov esi, dword ptr [0x98ca38]
// 0097cf97  6a3b                 push 0x3b
// 0097cf99  6a5a                 push 0x5a
// 0097cf9b  6a1d                 push 0x1d
// 0097cf9d  6a3d                 push 0x3d
// 0097cf9f  b81e000000           mov eax, 0x1e
// 0097cfa4  33c9                 xor ecx, ecx
// 0097cfa6  6838bcb900           push 0xb9bc38
// 0097cfab  a330bcb900           mov dword ptr [0xb9bc30], eax
// 0097cfb0  890d34bcb900         mov dword ptr [0xb9bc34], ecx
// 0097cfb6  ffd6                 call esi
// 0097cfb8  6a3b                 push 0x3b
// 0097cfba  6a78                 push 0x78
// 0097cfbc  b91e000000           mov ecx, 0x1e
// 0097cfc1  51                   push ecx
// 0097cfc2  6a5a                 push 0x5a
// 0097cfc4  33c0                 xor eax, eax
// 0097cfc6  6850bcb900           push 0xb9bc50
// 0097cfcb  a348bcb900           mov dword ptr [0xb9bc48], eax
// 0097cfd0  890d4cbcb900         mov dword ptr [0xb9bc4c], ecx
// 0097cfd6  ffd6                 call esi
// 0097cfd8  b81e000000           mov eax, 0x1e
// 0097cfdd  50                   push eax
// 0097cfde  6a78                 push 0x78
// 0097cfe0  6a00                 push 0
// 0097cfe2  6a5b                 push 0x5b
// 0097cfe4  b93b000000           mov ecx, 0x3b
// 0097cfe9  6868bcb900           push 0xb9bc68
// 0097cfee  a360bcb900           mov dword ptr [0xb9bc60], eax
// 0097cff3  890d64bcb900         mov dword ptr [0xb9bc64], ecx
// 0097cff9  ffd6                 call esi
// 0097cffb  6a1d                 push 0x1d
// 0097cffd  6a5c                 push 0x5c
// 0097cfff  6a00                 push 0
// 0097d001  6a3e                 push 0x3e
// 0097d003  b83c000000           mov eax, 0x3c
// 0097d008  b91e000000           mov ecx, 0x1e
// 0097d00d  6880bcb900           push 0xb9bc80
// 0097d012  a378bcb900           mov dword ptr [0xb9bc78], eax
// 0097d017  890d7cbcb900         mov dword ptr [0xb9bc7c], ecx
// 0097d01d  ffd6                 call esi
// 0097d01f  6a78                 push 0x78
// 0097d021  6a5a                 push 0x5a
// 0097d023  6a5a                 push 0x5a
// 0097d025  6a3d                 push 0x3d
// 0097d027  b81e000000           mov eax, 0x1e
// 0097d02c  33c9                 xor ecx, ecx
// 0097d02e  6898bcb900           push 0xb9bc98
// 0097d033  a390bcb900           mov dword ptr [0xb9bc90], eax
// 0097d038  890d94bcb900         mov dword ptr [0xb9bc94], ecx
// 0097d03e  ffd6                 call esi
// 0097d040  6a78                 push 0x78
// 0097d042  6a78                 push 0x78
// 0097d044  6a5b                 push 0x5b
// 0097d046  6a5a                 push 0x5a
// 0097d048  33c0                 xor eax, eax
// 0097d04a  b91e000000           mov ecx, 0x1e
// 0097d04f  68b0bcb900           push 0xb9bcb0
// 0097d054  a3a8bcb900           mov dword ptr [0xb9bca8], eax
// 0097d059  890dacbcb900         mov dword ptr [0xb9bcac], ecx
// 0097d05f  ffd6                 call esi
// 0097d061  6a5b                 push 0x5b
// 0097d063  6a78                 push 0x78
// 0097d065  6a3d                 push 0x3d
// 0097d067  6a5b                 push 0x5b
// 0097d069  b81e000000           mov eax, 0x1e
// 0097d06e  b93b000000           mov ecx, 0x3b
// 0097d073  68c8bcb900           push 0xb9bcc8
// 0097d078  a3c0bcb900           mov dword ptr [0xb9bcc0], eax
// 0097d07d  890dc4bcb900         mov dword ptr [0xb9bcc4], ecx
// 0097d083  ffd6                 call esi
// 0097d085  6a5a                 push 0x5a
// 0097d087  6a5c                 push 0x5c
// 0097d089  6a3d                 push 0x3d
// 0097d08b  b83c000000           mov eax, 0x3c
// 0097d090  b91e000000           mov ecx, 0x1e
// 0097d095  6a3e                 push 0x3e
// 0097d097  a3d8bcb900           mov dword ptr [0xb9bcd8], eax
// 0097d09c  890ddcbcb900         mov dword ptr [0xb9bcdc], ecx
// 0097d0a2  68e0bcb900           push 0xb9bce0
// 0097d0a7  ffd6                 call esi
// 0097d0a9  6a6f                 push 0x6f
// 0097d0ab  6894000000           push 0x94
// 0097d0b0  6a52                 push 0x52
// 0097d0b2  b81e000000           mov eax, 0x1e
// 0097d0b7  6a78                 push 0x78
// 0097d0b9  8bc8                 mov ecx, eax
// 0097d0bb  68f8bcb900           push 0xb9bcf8
// 0097d0c0  a3f0bcb900           mov dword ptr [0xb9bcf0], eax
// 0097d0c5  890df4bcb900         mov dword ptr [0xb9bcf4], ecx
// 0097d0cb  ffd6                 call esi
// 0097d0cd  6a52                 push 0x52
// 0097d0cf  68a1000000           push 0xa1
// 0097d0d4  6a29                 push 0x29
// 0097d0d6  b818000000           mov eax, 0x18
// 0097d0db  6a78                 push 0x78
// 0097d0dd  8bc8                 mov ecx, eax
// 0097d0df  6810bdb900           push 0xb9bd10
// 0097d0e4  a308bdb900           mov dword ptr [0xb9bd08], eax
// 0097d0e9  890d0cbdb900         mov dword ptr [0xb9bd0c], ecx
// 0097d0ef  ffd6                 call esi
// 0097d0f1  6a29                 push 0x29
// 0097d0f3  68a1000000           push 0xa1
// 0097d0f8  6a00                 push 0
// 0097d0fa  b818000000           mov eax, 0x18
// 0097d0ff  6a78                 push 0x78
// 0097d101  8bc8                 mov ecx, eax
// 0097d103  6828bdb900           push 0xb9bd28
// 0097d108  a320bdb900           mov dword ptr [0xb9bd20], eax
// 0097d10d  890d24bdb900         mov dword ptr [0xb9bd24], ecx
// 0097d113  ffd6                 call esi
// 0097d115  6a3d                 push 0x3d
// 0097d117  6a1d                 push 0x1d
// 0097d119  33c9                 xor ecx, ecx
// 0097d11b  6a1d                 push 0x1d
// 0097d11d  51                   push ecx
// 0097d11e  33c0                 xor eax, eax
// 0097d120  6840bdb900           push 0xb9bd40
// 0097d125  a338bdb900           mov dword ptr [0xb9bd38], eax
// 0097d12a  890d3cbdb900         mov dword ptr [0xb9bd3c], ecx
// 0097d130  ffd6                 call esi
// 0097d132  6a3d                 push 0x3d
// 0097d134  6a3d                 push 0x3d
// 0097d136  6a20                 push 0x20
// 0097d138  6a1d                 push 0x1d
// 0097d13a  33c0                 xor eax, eax
// 0097d13c  33c9                 xor ecx, ecx
// 0097d13e  6858bdb900           push 0xb9bd58
// 0097d143  a350bdb900           mov dword ptr [0xb9bd50], eax
// 0097d148  890d54bdb900         mov dword ptr [0xb9bd54], ecx
// 0097d14e  ffd6                 call esi
// 0097d150  6a20                 push 0x20
// 0097d152  6a3d                 push 0x3d
// 0097d154  33c9                 xor ecx, ecx
// 0097d156  51                   push ecx
// 0097d157  6a20                 push 0x20
// 0097d159  33c0                 xor eax, eax
// 0097d15b  6870bdb900           push 0xb9bd70
// 0097d160  a368bdb900           mov dword ptr [0xb9bd68], eax
// 0097d165  890d6cbdb900         mov dword ptr [0xb9bd6c], ecx
// 0097d16b  ffd6                 call esi
// 0097d16d  6a1d                 push 0x1d
// 0097d16f  33c9                 xor ecx, ecx
// 0097d171  6a20                 push 0x20
// 0097d173  51                   push ecx
// 0097d174  51                   push ecx
// 0097d175  33c0                 xor eax, eax
// 0097d177  6888bdb900           push 0xb9bd88
// 0097d17c  a380bdb900           mov dword ptr [0xb9bd80], eax
// 0097d181  890d84bdb900         mov dword ptr [0xb9bd84], ecx
// 0097d187  ffd6                 call esi
// 0097d189  6a7a                 push 0x7a
// 0097d18b  6a1d                 push 0x1d
// 0097d18d  33c9                 xor ecx, ecx
// 0097d18f  6a5a                 push 0x5a
// 0097d191  51                   push ecx
// 0097d192  33c0                 xor eax, eax
// 0097d194  68a0bdb900           push 0xb9bda0
// 0097d199  a398bdb900           mov dword ptr [0xb9bd98], eax
// 0097d19e  890d9cbdb900         mov dword ptr [0xb9bd9c], ecx
// 0097d1a4  ffd6                 call esi
// 0097d1a6  6a7a                 push 0x7a
// 0097d1a8  6a3d                 push 0x3d
// 0097d1aa  6a5d                 push 0x5d
// 0097d1ac  6a1d                 push 0x1d
// 0097d1ae  33c0                 xor eax, eax
// 0097d1b0  33c9                 xor ecx, ecx
// 0097d1b2  68b8bdb900           push 0xb9bdb8
// 0097d1b7  a3b0bdb900           mov dword ptr [0xb9bdb0], eax
// 0097d1bc  890db4bdb900         mov dword ptr [0xb9bdb4], ecx
// 0097d1c2  ffd6                 call esi
// 0097d1c4  6a5d                 push 0x5d
// 0097d1c6  6a3d                 push 0x3d
// 0097d1c8  6a3d                 push 0x3d
// 0097d1ca  6a20                 push 0x20
// 0097d1cc  33c0                 xor eax, eax
// 0097d1ce  33c9                 xor ecx, ecx
// 0097d1d0  68d0bdb900           push 0xb9bdd0
// 0097d1d5  a3c8bdb900           mov dword ptr [0xb9bdc8], eax
// 0097d1da  890dccbdb900         mov dword ptr [0xb9bdcc], ecx
// 0097d1e0  ffd6                 call esi
// 0097d1e2  6a5a                 push 0x5a
// 0097d1e4  6a20                 push 0x20
// 0097d1e6  33c9                 xor ecx, ecx
// 0097d1e8  6a3d                 push 0x3d
// 0097d1ea  51                   push ecx
// 0097d1eb  33c0                 xor eax, eax
// 0097d1ed  68e8bdb900           push 0xb9bde8
// 0097d1f2  a3e0bdb900           mov dword ptr [0xb9bde0], eax
// 0097d1f7  890de4bdb900         mov dword ptr [0xb9bde4], ecx
// 0097d1fd  ffd6                 call esi
// 0097d1ff  5e                   pop esi
// 0097d200  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??__EarrSpritesStyckerVisualStudio2005@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
