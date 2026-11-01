// from server: 100% by auto
// roc 2007-03 00776b10  unit: seg_00770000  size: 381 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00776b10
//
// 00776b10  56                   push esi
// 00776b11  8b35b4ed7700         mov esi, dword ptr [0x77edb4]
// 00776b17  6a1e                 push 0x1e
// 00776b19  33c9                 xor ecx, ecx
// 00776b1b  6a2b                 push 0x2b
// 00776b1d  51                   push ecx
// 00776b1e  51                   push ecx
// 00776b1f  b819000000           mov eax, 0x19
// 00776b24  6850238c00           push 0x8c2350
// 00776b29  a348238c00           mov dword ptr [0x8c2348], eax
// 00776b2e  890d4c238c00         mov dword ptr [0x8c234c], ecx
// 00776b34  ffd6                 call esi
// 00776b36  6a4c                 push 0x4c
// 00776b38  6a3c                 push 0x3c
// 00776b3a  6a21                 push 0x21
// 00776b3c  6a1e                 push 0x1e
// 00776b3e  33c0                 xor eax, eax
// 00776b40  b919000000           mov ecx, 0x19
// 00776b45  6868238c00           push 0x8c2368
// 00776b4a  a360238c00           mov dword ptr [0x8c2360], eax
// 00776b4f  890d64238c00         mov dword ptr [0x8c2364], ecx
// 00776b55  ffd6                 call esi
// 00776b57  6a1e                 push 0x1e
// 00776b59  6a56                 push 0x56
// 00776b5b  6a00                 push 0
// 00776b5d  6a2b                 push 0x2b
// 00776b5f  b819000000           mov eax, 0x19
// 00776b64  b93f000000           mov ecx, 0x3f
// 00776b69  6880238c00           push 0x8c2380
// 00776b6e  a378238c00           mov dword ptr [0x8c2378], eax
// 00776b73  890d7c238c00         mov dword ptr [0x8c237c], ecx
// 00776b79  ffd6                 call esi
// 00776b7b  6a4c                 push 0x4c
// 00776b7d  6a1e                 push 0x1e
// 00776b7f  6a21                 push 0x21
// 00776b81  6a00                 push 0
// 00776b83  b83f000000           mov eax, 0x3f
// 00776b88  b919000000           mov ecx, 0x19
// 00776b8d  6898238c00           push 0x8c2398
// 00776b92  a390238c00           mov dword ptr [0x8c2390], eax
// 00776b97  890d94238c00         mov dword ptr [0x8c2394], ecx
// 00776b9d  ffd6                 call esi
// 00776b9f  6a6a                 push 0x6a
// 00776ba1  6a2b                 push 0x2b
// 00776ba3  33c9                 xor ecx, ecx
// 00776ba5  6a4c                 push 0x4c
// 00776ba7  51                   push ecx
// 00776ba8  b819000000           mov eax, 0x19
// 00776bad  68b0238c00           push 0x8c23b0
// 00776bb2  a3a8238c00           mov dword ptr [0x8c23a8], eax
// 00776bb7  890dac238c00         mov dword ptr [0x8c23ac], ecx
// 00776bbd  ffd6                 call esi
// 00776bbf  6a4c                 push 0x4c
// 00776bc1  6a78                 push 0x78
// 00776bc3  6a21                 push 0x21
// 00776bc5  6a5a                 push 0x5a
// 00776bc7  33c0                 xor eax, eax
// 00776bc9  b919000000           mov ecx, 0x19
// 00776bce  68c8238c00           push 0x8c23c8
// 00776bd3  a3c0238c00           mov dword ptr [0x8c23c0], eax
// 00776bd8  890dc4238c00         mov dword ptr [0x8c23c4], ecx
// 00776bde  ffd6                 call esi
// 00776be0  6a6a                 push 0x6a
// 00776be2  6a56                 push 0x56
// 00776be4  6a4c                 push 0x4c
// 00776be6  6a2b                 push 0x2b
// 00776be8  b819000000           mov eax, 0x19
// 00776bed  b93f000000           mov ecx, 0x3f
// 00776bf2  68e0238c00           push 0x8c23e0
// 00776bf7  a3d8238c00           mov dword ptr [0x8c23d8], eax
// 00776bfc  890ddc238c00         mov dword ptr [0x8c23dc], ecx
// 00776c02  ffd6                 call esi
// 00776c04  6a4c                 push 0x4c
// 00776c06  6a5a                 push 0x5a
// 00776c08  6a21                 push 0x21
// 00776c0a  b83f000000           mov eax, 0x3f
// 00776c0f  b919000000           mov ecx, 0x19
// 00776c14  6a3c                 push 0x3c
// 00776c16  a3f0238c00           mov dword ptr [0x8c23f0], eax
// 00776c1b  890df4238c00         mov dword ptr [0x8c23f4], ecx
// 00776c21  68f8238c00           push 0x8c23f8
// 00776c26  ffd6                 call esi
// 00776c28  6a21                 push 0x21
// 00776c2a  6a77                 push 0x77
// 00776c2c  6a00                 push 0
// 00776c2e  b81e000000           mov eax, 0x1e
// 00776c33  6a56                 push 0x56
// 00776c35  8bc8                 mov ecx, eax
// 00776c37  6810248c00           push 0x8c2410
// 00776c3c  a308248c00           mov dword ptr [0x8c2408], eax
// 00776c41  890d0c248c00         mov dword ptr [0x8c240c], ecx
// 00776c47  ffd6                 call esi
// 00776c49  6a6d                 push 0x6d
// 00776c4b  6a77                 push 0x77
// 00776c4d  6a4c                 push 0x4c
// 00776c4f  b81e000000           mov eax, 0x1e
// 00776c54  6a56                 push 0x56
// 00776c56  8bc8                 mov ecx, eax
// 00776c58  6828248c00           push 0x8c2428
// 00776c5d  a320248c00           mov dword ptr [0x8c2420], eax
// 00776c62  890d24248c00         mov dword ptr [0x8c2424], ecx
// 00776c68  ffd6                 call esi
// 00776c6a  6a2b                 push 0x2b
// 00776c6c  6a2b                 push 0x2b
// 00776c6e  6a00                 push 0
// 00776c70  b819000000           mov eax, 0x19
// 00776c75  6a00                 push 0
// 00776c77  8bc8                 mov ecx, eax
// 00776c79  6840248c00           push 0x8c2440
// 00776c7e  a338248c00           mov dword ptr [0x8c2438], eax
// 00776c83  890d3c248c00         mov dword ptr [0x8c243c], ecx
// 00776c89  ffd6                 call esi
// 00776c8b  5e                   pop esi
// 00776c8c  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??__EarrSpritesStyckerWidbey@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
