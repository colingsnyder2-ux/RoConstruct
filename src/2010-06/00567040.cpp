// from server: 100% by auto
// roc 2010-06 00567040  unit: seg_00560000  size: 662 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00567040
//
// 00567040  8b442408             mov eax, dword ptr [esp + 8]
// 00567044  83ec40               sub esp, 0x40
// 00567047  53                   push ebx
// 00567048  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 0056704c  55                   push ebp
// 0056704d  56                   push esi
// 0056704e  57                   push edi
// 0056704f  85c0                 test eax, eax
// 00567051  740a                 je 0x56705d
// 00567053  50                   push eax
// 00567054  53                   push ebx
// 00567055  e886e3ffff           call 0x5653e0
// 0056705a  83c408               add esp, 8
// 0056705d  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00567061  85c0                 test eax, eax
// 00567063  740a                 je 0x56706f
// 00567065  50                   push eax
// 00567066  53                   push ebx
// 00567067  e874e3ffff           call 0x5653e0
// 0056706c  83c408               add esp, 8
// 0056706f  8b83ac000000         mov eax, dword ptr [ebx + 0xac]
// 00567075  50                   push eax
// 00567076  53                   push ebx
// 00567077  e884b50000           call 0x572600
// 0056707c  8b8b50020000         mov ecx, dword ptr [ebx + 0x250]
// 00567082  51                   push ecx
// 00567083  53                   push ebx
// 00567084  e877b50000           call 0x572600
// 00567089  8b93e8000000         mov edx, dword ptr [ebx + 0xe8]
// 0056708f  52                   push edx
// 00567090  53                   push ebx
// 00567091  e86ab50000           call 0x572600
// 00567096  8b8388020000         mov eax, dword ptr [ebx + 0x288]
// 0056709c  50                   push eax
// 0056709d  53                   push ebx
// 0056709e  e85db50000           call 0x572600
// 005670a3  8b8bec010000         mov ecx, dword ptr [ebx + 0x1ec]
// 005670a9  51                   push ecx
// 005670aa  53                   push ebx
// 005670ab  e850b50000           call 0x572600
// 005670b0  8b93f0010000         mov edx, dword ptr [ebx + 0x1f0]
// 005670b6  52                   push edx
// 005670b7  53                   push ebx
// 005670b8  e843b50000           call 0x572600
// 005670bd  8b8364010000         mov eax, dword ptr [ebx + 0x164]
// 005670c3  50                   push eax
// 005670c4  53                   push ebx
// 005670c5  e836b50000           call 0x572600
// 005670ca  8b8b68010000         mov ecx, dword ptr [ebx + 0x168]
// 005670d0  51                   push ecx
// 005670d1  53                   push ebx
// 005670d2  e829b50000           call 0x572600
// 005670d7  8b936c010000         mov edx, dword ptr [ebx + 0x16c]
// 005670dd  83c440               add esp, 0x40
// 005670e0  52                   push edx
// 005670e1  53                   push ebx
// 005670e2  e819b50000           call 0x572600
// 005670e7  83c408               add esp, 8
// 005670ea  f7831402000000100000 test dword ptr [ebx + 0x214], 0x1000
// 005670f4  7410                 je 0x567106
// 005670f6  8b8314010000         mov eax, dword ptr [ebx + 0x114]
// 005670fc  50                   push eax
// 005670fd  53                   push ebx
// 005670fe  e8addeffff           call 0x564fb0
// 00567103  83c408               add esp, 8
// 00567106  81a314020000ffefffff and dword ptr [ebx + 0x214], 0xffffefff
// 00567110  f7831402000000200000 test dword ptr [ebx + 0x214], 0x2000
// 0056711a  7410                 je 0x56712c
// 0056711c  8b8b88010000         mov ecx, dword ptr [ebx + 0x188]
// 00567122  51                   push ecx
// 00567123  53                   push ebx
// 00567124  e8d7b40000           call 0x572600
// 00567129  83c408               add esp, 8
// 0056712c  81a314020000ffdfffff and dword ptr [ebx + 0x214], 0xffffdfff
// 00567136  8b8314020000         mov eax, dword ptr [ebx + 0x214]
// 0056713c  a808                 test al, 8
// 0056713e  7410                 je 0x567150
// 00567140  8b93f4010000         mov edx, dword ptr [ebx + 0x1f4]
// 00567146  52                   push edx
// 00567147  53                   push ebx
// 00567148  e8b3b40000           call 0x572600
// 0056714d  83c408               add esp, 8
// 00567150  83a314020000f7       and dword ptr [ebx + 0x214], 0xfffffff7
// 00567157  83bb7001000000       cmp dword ptr [ebx + 0x170], 0
// 0056715e  7448                 je 0x5671a8
// 00567160  b908000000           mov ecx, 8
// 00567165  2b8b58010000         sub ecx, dword ptr [ebx + 0x158]
// 0056716b  be01000000           mov esi, 1
// 00567170  d3e6                 shl esi, cl
// 00567172  33ff                 xor edi, edi
// 00567174  85f6                 test esi, esi
// 00567176  7e20                 jle 0x567198
// 00567178  eb06                 jmp 0x567180
// 0056717a  8d9b00000000         lea ebx, [ebx]
// 00567180  8b8370010000         mov eax, dword ptr [ebx + 0x170]
// 00567186  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 00567189  51                   push ecx
// 0056718a  53                   push ebx
// 0056718b  e870b40000           call 0x572600
// 00567190  47                   inc edi
// 00567191  83c408               add esp, 8
// 00567194  3bfe                 cmp edi, esi
// 00567196  7ce8                 jl 0x567180
// 00567198  8b9370010000         mov edx, dword ptr [ebx + 0x170]
// 0056719e  52                   push edx
// 0056719f  53                   push ebx
// 005671a0  e85bb40000           call 0x572600
// 005671a5  83c408               add esp, 8
// 005671a8  83bb7401000000       cmp dword ptr [ebx + 0x174], 0
// 005671af  7447                 je 0x5671f8
// 005671b1  b908000000           mov ecx, 8
// 005671b6  2b8b58010000         sub ecx, dword ptr [ebx + 0x158]
// 005671bc  be01000000           mov esi, 1
// 005671c1  d3e6                 shl esi, cl
// 005671c3  33ff                 xor edi, edi
// 005671c5  85f6                 test esi, esi
// 005671c7  7e1f                 jle 0x5671e8
// 005671c9  8da42400000000       lea esp, [esp]
// 005671d0  8b8374010000         mov eax, dword ptr [ebx + 0x174]
// 005671d6  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 005671d9  51                   push ecx
// 005671da  53                   push ebx
// 005671db  e820b40000           call 0x572600
// 005671e0  47                   inc edi
// 005671e1  83c408               add esp, 8
// 005671e4  3bfe                 cmp edi, esi
// 005671e6  7ce8                 jl 0x5671d0
// 005671e8  8b9374010000         mov edx, dword ptr [ebx + 0x174]
// 005671ee  52                   push edx
// 005671ef  53                   push ebx
// 005671f0  e80bb40000           call 0x572600
// 005671f5  83c408               add esp, 8
// 005671f8  83bb7801000000       cmp dword ptr [ebx + 0x178], 0
// 005671ff  7447                 je 0x567248
// 00567201  b908000000           mov ecx, 8
// 00567206  2b8b58010000         sub ecx, dword ptr [ebx + 0x158]
// 0056720c  be01000000           mov esi, 1
// 00567211  d3e6                 shl esi, cl
// 00567213  33ff                 xor edi, edi
// 00567215  85f6                 test esi, esi
// 00567217  7e1f                 jle 0x567238
// 00567219  8da42400000000       lea esp, [esp]
// 00567220  8b8378010000         mov eax, dword ptr [ebx + 0x178]
// 00567226  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 00567229  51                   push ecx
// 0056722a  53                   push ebx
// 0056722b  e8d0b30000           call 0x572600
// 00567230  47                   inc edi
// 00567231  83c408               add esp, 8
// 00567234  3bfe                 cmp edi, esi
// 00567236  7ce8                 jl 0x567220
// 00567238  8b9378010000         mov edx, dword ptr [ebx + 0x178]
// 0056723e  52                   push edx
// 0056723f  53                   push ebx
// 00567240  e8bbb30000           call 0x572600
// 00567245  83c408               add esp, 8
// 00567248  8b8310020000         mov eax, dword ptr [ebx + 0x210]
// 0056724e  50                   push eax
// 0056724f  53                   push ebx
// 00567250  e8abb30000           call 0x572600
// 00567255  8d4b74               lea ecx, [ebx + 0x74]
// 00567258  51                   push ecx
// 00567259  e8c2e70000           call 0x575a20
// 0056725e  8b93b0010000         mov edx, dword ptr [ebx + 0x1b0]
// 00567264  52                   push edx
// 00567265  53                   push ebx
// 00567266  e895b30000           call 0x572600
// 0056726b  8b83e4010000         mov eax, dword ptr [ebx + 0x1e4]
// 00567271  50                   push eax
// 00567272  53                   push ebx
// 00567273  e888b30000           call 0x572600
// 00567278  8b6b48               mov ebp, dword ptr [ebx + 0x48]
// 0056727b  688c020000           push 0x28c
// 00567280  b910000000           mov ecx, 0x10
// 00567285  8bf3                 mov esi, ebx
// 00567287  8d7c2430             lea edi, [esp + 0x30]
// 0056728b  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0056728d  8b8b4c020000         mov ecx, dword ptr [ebx + 0x24c]
// 00567293  8b7340               mov esi, dword ptr [ebx + 0x40]
// 00567296  8b7b44               mov edi, dword ptr [ebx + 0x44]
// 00567299  6a00                 push 0
// 0056729b  53                   push ebx
// 0056729c  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 005672a3  e83c192400           call 0x7a8be4
// 005672a8  8b942480000000       mov edx, dword ptr [esp + 0x80]
// 005672af  897340               mov dword ptr [ebx + 0x40], esi
// 005672b2  897b44               mov dword ptr [ebx + 0x44], edi
// 005672b5  83c428               add esp, 0x28
// 005672b8  8bfb                 mov edi, ebx
// 005672ba  b910000000           mov ecx, 0x10
// 005672bf  8d742410             lea esi, [esp + 0x10]
// 005672c3  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 005672c5  5f                   pop edi
// 005672c6  5e                   pop esi
// 005672c7  896b48               mov dword ptr [ebx + 0x48], ebp
// 005672ca  5d                   pop ebp
// 005672cb  89934c020000         mov dword ptr [ebx + 0x24c], edx
// 005672d1  5b                   pop ebx
// 005672d2  83c440               add esp, 0x40
// 005672d5  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
