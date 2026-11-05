// from server: 100% by auto
// roc 2009-06 00583910  unit: seg_00580000  size: 662 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00583910
//
// 00583910  8b442408             mov eax, dword ptr [esp + 8]
// 00583914  83ec40               sub esp, 0x40
// 00583917  53                   push ebx
// 00583918  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 0058391c  55                   push ebp
// 0058391d  56                   push esi
// 0058391e  57                   push edi
// 0058391f  85c0                 test eax, eax
// 00583921  740a                 je 0x58392d
// 00583923  50                   push eax
// 00583924  53                   push ebx
// 00583925  e896e3ffff           call 0x581cc0
// 0058392a  83c408               add esp, 8
// 0058392d  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00583931  85c0                 test eax, eax
// 00583933  740a                 je 0x58393f
// 00583935  50                   push eax
// 00583936  53                   push ebx
// 00583937  e884e3ffff           call 0x581cc0
// 0058393c  83c408               add esp, 8
// 0058393f  8b83ac000000         mov eax, dword ptr [ebx + 0xac]
// 00583945  50                   push eax
// 00583946  53                   push ebx
// 00583947  e864b30000           call 0x58ecb0
// 0058394c  8b8b50020000         mov ecx, dword ptr [ebx + 0x250]
// 00583952  51                   push ecx
// 00583953  53                   push ebx
// 00583954  e857b30000           call 0x58ecb0
// 00583959  8b93e8000000         mov edx, dword ptr [ebx + 0xe8]
// 0058395f  52                   push edx
// 00583960  53                   push ebx
// 00583961  e84ab30000           call 0x58ecb0
// 00583966  8b8388020000         mov eax, dword ptr [ebx + 0x288]
// 0058396c  50                   push eax
// 0058396d  53                   push ebx
// 0058396e  e83db30000           call 0x58ecb0
// 00583973  8b8bec010000         mov ecx, dword ptr [ebx + 0x1ec]
// 00583979  51                   push ecx
// 0058397a  53                   push ebx
// 0058397b  e830b30000           call 0x58ecb0
// 00583980  8b93f0010000         mov edx, dword ptr [ebx + 0x1f0]
// 00583986  52                   push edx
// 00583987  53                   push ebx
// 00583988  e823b30000           call 0x58ecb0
// 0058398d  8b8364010000         mov eax, dword ptr [ebx + 0x164]
// 00583993  50                   push eax
// 00583994  53                   push ebx
// 00583995  e816b30000           call 0x58ecb0
// 0058399a  8b8b68010000         mov ecx, dword ptr [ebx + 0x168]
// 005839a0  51                   push ecx
// 005839a1  53                   push ebx
// 005839a2  e809b30000           call 0x58ecb0
// 005839a7  8b936c010000         mov edx, dword ptr [ebx + 0x16c]
// 005839ad  83c440               add esp, 0x40
// 005839b0  52                   push edx
// 005839b1  53                   push ebx
// 005839b2  e8f9b20000           call 0x58ecb0
// 005839b7  83c408               add esp, 8
// 005839ba  f7831402000000100000 test dword ptr [ebx + 0x214], 0x1000
// 005839c4  7410                 je 0x5839d6
// 005839c6  8b8314010000         mov eax, dword ptr [ebx + 0x114]
// 005839cc  50                   push eax
// 005839cd  53                   push ebx
// 005839ce  e8bddeffff           call 0x581890
// 005839d3  83c408               add esp, 8
// 005839d6  81a314020000ffefffff and dword ptr [ebx + 0x214], 0xffffefff
// 005839e0  f7831402000000200000 test dword ptr [ebx + 0x214], 0x2000
// 005839ea  7410                 je 0x5839fc
// 005839ec  8b8b88010000         mov ecx, dword ptr [ebx + 0x188]
// 005839f2  51                   push ecx
// 005839f3  53                   push ebx
// 005839f4  e8b7b20000           call 0x58ecb0
// 005839f9  83c408               add esp, 8
// 005839fc  81a314020000ffdfffff and dword ptr [ebx + 0x214], 0xffffdfff
// 00583a06  8b8314020000         mov eax, dword ptr [ebx + 0x214]
// 00583a0c  a808                 test al, 8
// 00583a0e  7410                 je 0x583a20
// 00583a10  8b93f4010000         mov edx, dword ptr [ebx + 0x1f4]
// 00583a16  52                   push edx
// 00583a17  53                   push ebx
// 00583a18  e893b20000           call 0x58ecb0
// 00583a1d  83c408               add esp, 8
// 00583a20  83a314020000f7       and dword ptr [ebx + 0x214], 0xfffffff7
// 00583a27  83bb7001000000       cmp dword ptr [ebx + 0x170], 0
// 00583a2e  7448                 je 0x583a78
// 00583a30  b908000000           mov ecx, 8
// 00583a35  2b8b58010000         sub ecx, dword ptr [ebx + 0x158]
// 00583a3b  be01000000           mov esi, 1
// 00583a40  d3e6                 shl esi, cl
// 00583a42  33ff                 xor edi, edi
// 00583a44  85f6                 test esi, esi
// 00583a46  7e20                 jle 0x583a68
// 00583a48  eb06                 jmp 0x583a50
// 00583a4a  8d9b00000000         lea ebx, [ebx]
// 00583a50  8b8370010000         mov eax, dword ptr [ebx + 0x170]
// 00583a56  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 00583a59  51                   push ecx
// 00583a5a  53                   push ebx
// 00583a5b  e850b20000           call 0x58ecb0
// 00583a60  47                   inc edi
// 00583a61  83c408               add esp, 8
// 00583a64  3bfe                 cmp edi, esi
// 00583a66  7ce8                 jl 0x583a50
// 00583a68  8b9370010000         mov edx, dword ptr [ebx + 0x170]
// 00583a6e  52                   push edx
// 00583a6f  53                   push ebx
// 00583a70  e83bb20000           call 0x58ecb0
// 00583a75  83c408               add esp, 8
// 00583a78  83bb7401000000       cmp dword ptr [ebx + 0x174], 0
// 00583a7f  7447                 je 0x583ac8
// 00583a81  b908000000           mov ecx, 8
// 00583a86  2b8b58010000         sub ecx, dword ptr [ebx + 0x158]
// 00583a8c  be01000000           mov esi, 1
// 00583a91  d3e6                 shl esi, cl
// 00583a93  33ff                 xor edi, edi
// 00583a95  85f6                 test esi, esi
// 00583a97  7e1f                 jle 0x583ab8
// 00583a99  8da42400000000       lea esp, [esp]
// 00583aa0  8b8374010000         mov eax, dword ptr [ebx + 0x174]
// 00583aa6  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 00583aa9  51                   push ecx
// 00583aaa  53                   push ebx
// 00583aab  e800b20000           call 0x58ecb0
// 00583ab0  47                   inc edi
// 00583ab1  83c408               add esp, 8
// 00583ab4  3bfe                 cmp edi, esi
// 00583ab6  7ce8                 jl 0x583aa0
// 00583ab8  8b9374010000         mov edx, dword ptr [ebx + 0x174]
// 00583abe  52                   push edx
// 00583abf  53                   push ebx
// 00583ac0  e8ebb10000           call 0x58ecb0
// 00583ac5  83c408               add esp, 8
// 00583ac8  83bb7801000000       cmp dword ptr [ebx + 0x178], 0
// 00583acf  7447                 je 0x583b18
// 00583ad1  b908000000           mov ecx, 8
// 00583ad6  2b8b58010000         sub ecx, dword ptr [ebx + 0x158]
// 00583adc  be01000000           mov esi, 1
// 00583ae1  d3e6                 shl esi, cl
// 00583ae3  33ff                 xor edi, edi
// 00583ae5  85f6                 test esi, esi
// 00583ae7  7e1f                 jle 0x583b08
// 00583ae9  8da42400000000       lea esp, [esp]
// 00583af0  8b8378010000         mov eax, dword ptr [ebx + 0x178]
// 00583af6  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 00583af9  51                   push ecx
// 00583afa  53                   push ebx
// 00583afb  e8b0b10000           call 0x58ecb0
// 00583b00  47                   inc edi
// 00583b01  83c408               add esp, 8
// 00583b04  3bfe                 cmp edi, esi
// 00583b06  7ce8                 jl 0x583af0
// 00583b08  8b9378010000         mov edx, dword ptr [ebx + 0x178]
// 00583b0e  52                   push edx
// 00583b0f  53                   push ebx
// 00583b10  e89bb10000           call 0x58ecb0
// 00583b15  83c408               add esp, 8
// 00583b18  8b8310020000         mov eax, dword ptr [ebx + 0x210]
// 00583b1e  50                   push eax
// 00583b1f  53                   push ebx
// 00583b20  e88bb10000           call 0x58ecb0
// 00583b25  8d4b74               lea ecx, [ebx + 0x74]
// 00583b28  51                   push ecx
// 00583b29  e8c2e50000           call 0x5920f0
// 00583b2e  8b93b0010000         mov edx, dword ptr [ebx + 0x1b0]
// 00583b34  52                   push edx
// 00583b35  53                   push ebx
// 00583b36  e875b10000           call 0x58ecb0
// 00583b3b  8b83e4010000         mov eax, dword ptr [ebx + 0x1e4]
// 00583b41  50                   push eax
// 00583b42  53                   push ebx
// 00583b43  e868b10000           call 0x58ecb0
// 00583b48  8b6b48               mov ebp, dword ptr [ebx + 0x48]
// 00583b4b  688c020000           push 0x28c
// 00583b50  b910000000           mov ecx, 0x10
// 00583b55  8bf3                 mov esi, ebx
// 00583b57  8d7c2430             lea edi, [esp + 0x30]
// 00583b5b  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00583b5d  8b8b4c020000         mov ecx, dword ptr [ebx + 0x24c]
// 00583b63  8b7340               mov esi, dword ptr [ebx + 0x40]
// 00583b66  8b7b44               mov edi, dword ptr [ebx + 0x44]
// 00583b69  6a00                 push 0
// 00583b6b  53                   push ebx
// 00583b6c  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 00583b73  e8fc601900           call 0x719c74
// 00583b78  8b942480000000       mov edx, dword ptr [esp + 0x80]
// 00583b7f  897340               mov dword ptr [ebx + 0x40], esi
// 00583b82  897b44               mov dword ptr [ebx + 0x44], edi
// 00583b85  83c428               add esp, 0x28
// 00583b88  8bfb                 mov edi, ebx
// 00583b8a  b910000000           mov ecx, 0x10
// 00583b8f  8d742410             lea esi, [esp + 0x10]
// 00583b93  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00583b95  5f                   pop edi
// 00583b96  5e                   pop esi
// 00583b97  896b48               mov dword ptr [ebx + 0x48], ebp
// 00583b9a  5d                   pop ebp
// 00583b9b  89934c020000         mov dword ptr [ebx + 0x24c], edx
// 00583ba1  5b                   pop ebx
// 00583ba2  83c440               add esp, 0x40
// 00583ba5  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
