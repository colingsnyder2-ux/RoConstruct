// from server: 100% by auto
// roc 2009-12 006056c0  unit: seg_00600000  size: 662 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006056c0
//
// 006056c0  8b442408             mov eax, dword ptr [esp + 8]
// 006056c4  83ec40               sub esp, 0x40
// 006056c7  53                   push ebx
// 006056c8  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 006056cc  55                   push ebp
// 006056cd  56                   push esi
// 006056ce  57                   push edi
// 006056cf  85c0                 test eax, eax
// 006056d1  740a                 je 0x6056dd
// 006056d3  50                   push eax
// 006056d4  53                   push ebx
// 006056d5  e896e3ffff           call 0x603a70
// 006056da  83c408               add esp, 8
// 006056dd  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 006056e1  85c0                 test eax, eax
// 006056e3  740a                 je 0x6056ef
// 006056e5  50                   push eax
// 006056e6  53                   push ebx
// 006056e7  e884e3ffff           call 0x603a70
// 006056ec  83c408               add esp, 8
// 006056ef  8b83ac000000         mov eax, dword ptr [ebx + 0xac]
// 006056f5  50                   push eax
// 006056f6  53                   push ebx
// 006056f7  e8e4b50000           call 0x610ce0
// 006056fc  8b8b50020000         mov ecx, dword ptr [ebx + 0x250]
// 00605702  51                   push ecx
// 00605703  53                   push ebx
// 00605704  e8d7b50000           call 0x610ce0
// 00605709  8b93e8000000         mov edx, dword ptr [ebx + 0xe8]
// 0060570f  52                   push edx
// 00605710  53                   push ebx
// 00605711  e8cab50000           call 0x610ce0
// 00605716  8b8388020000         mov eax, dword ptr [ebx + 0x288]
// 0060571c  50                   push eax
// 0060571d  53                   push ebx
// 0060571e  e8bdb50000           call 0x610ce0
// 00605723  8b8bec010000         mov ecx, dword ptr [ebx + 0x1ec]
// 00605729  51                   push ecx
// 0060572a  53                   push ebx
// 0060572b  e8b0b50000           call 0x610ce0
// 00605730  8b93f0010000         mov edx, dword ptr [ebx + 0x1f0]
// 00605736  52                   push edx
// 00605737  53                   push ebx
// 00605738  e8a3b50000           call 0x610ce0
// 0060573d  8b8364010000         mov eax, dword ptr [ebx + 0x164]
// 00605743  50                   push eax
// 00605744  53                   push ebx
// 00605745  e896b50000           call 0x610ce0
// 0060574a  8b8b68010000         mov ecx, dword ptr [ebx + 0x168]
// 00605750  51                   push ecx
// 00605751  53                   push ebx
// 00605752  e889b50000           call 0x610ce0
// 00605757  8b936c010000         mov edx, dword ptr [ebx + 0x16c]
// 0060575d  83c440               add esp, 0x40
// 00605760  52                   push edx
// 00605761  53                   push ebx
// 00605762  e879b50000           call 0x610ce0
// 00605767  83c408               add esp, 8
// 0060576a  f7831402000000100000 test dword ptr [ebx + 0x214], 0x1000
// 00605774  7410                 je 0x605786
// 00605776  8b8314010000         mov eax, dword ptr [ebx + 0x114]
// 0060577c  50                   push eax
// 0060577d  53                   push ebx
// 0060577e  e8bddeffff           call 0x603640
// 00605783  83c408               add esp, 8
// 00605786  81a314020000ffefffff and dword ptr [ebx + 0x214], 0xffffefff
// 00605790  f7831402000000200000 test dword ptr [ebx + 0x214], 0x2000
// 0060579a  7410                 je 0x6057ac
// 0060579c  8b8b88010000         mov ecx, dword ptr [ebx + 0x188]
// 006057a2  51                   push ecx
// 006057a3  53                   push ebx
// 006057a4  e837b50000           call 0x610ce0
// 006057a9  83c408               add esp, 8
// 006057ac  81a314020000ffdfffff and dword ptr [ebx + 0x214], 0xffffdfff
// 006057b6  8b8314020000         mov eax, dword ptr [ebx + 0x214]
// 006057bc  a808                 test al, 8
// 006057be  7410                 je 0x6057d0
// 006057c0  8b93f4010000         mov edx, dword ptr [ebx + 0x1f4]
// 006057c6  52                   push edx
// 006057c7  53                   push ebx
// 006057c8  e813b50000           call 0x610ce0
// 006057cd  83c408               add esp, 8
// 006057d0  83a314020000f7       and dword ptr [ebx + 0x214], 0xfffffff7
// 006057d7  83bb7001000000       cmp dword ptr [ebx + 0x170], 0
// 006057de  7448                 je 0x605828
// 006057e0  b908000000           mov ecx, 8
// 006057e5  2b8b58010000         sub ecx, dword ptr [ebx + 0x158]
// 006057eb  be01000000           mov esi, 1
// 006057f0  d3e6                 shl esi, cl
// 006057f2  33ff                 xor edi, edi
// 006057f4  85f6                 test esi, esi
// 006057f6  7e20                 jle 0x605818
// 006057f8  eb06                 jmp 0x605800
// 006057fa  8d9b00000000         lea ebx, [ebx]
// 00605800  8b8370010000         mov eax, dword ptr [ebx + 0x170]
// 00605806  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 00605809  51                   push ecx
// 0060580a  53                   push ebx
// 0060580b  e8d0b40000           call 0x610ce0
// 00605810  47                   inc edi
// 00605811  83c408               add esp, 8
// 00605814  3bfe                 cmp edi, esi
// 00605816  7ce8                 jl 0x605800
// 00605818  8b9370010000         mov edx, dword ptr [ebx + 0x170]
// 0060581e  52                   push edx
// 0060581f  53                   push ebx
// 00605820  e8bbb40000           call 0x610ce0
// 00605825  83c408               add esp, 8
// 00605828  83bb7401000000       cmp dword ptr [ebx + 0x174], 0
// 0060582f  7447                 je 0x605878
// 00605831  b908000000           mov ecx, 8
// 00605836  2b8b58010000         sub ecx, dword ptr [ebx + 0x158]
// 0060583c  be01000000           mov esi, 1
// 00605841  d3e6                 shl esi, cl
// 00605843  33ff                 xor edi, edi
// 00605845  85f6                 test esi, esi
// 00605847  7e1f                 jle 0x605868
// 00605849  8da42400000000       lea esp, [esp]
// 00605850  8b8374010000         mov eax, dword ptr [ebx + 0x174]
// 00605856  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 00605859  51                   push ecx
// 0060585a  53                   push ebx
// 0060585b  e880b40000           call 0x610ce0
// 00605860  47                   inc edi
// 00605861  83c408               add esp, 8
// 00605864  3bfe                 cmp edi, esi
// 00605866  7ce8                 jl 0x605850
// 00605868  8b9374010000         mov edx, dword ptr [ebx + 0x174]
// 0060586e  52                   push edx
// 0060586f  53                   push ebx
// 00605870  e86bb40000           call 0x610ce0
// 00605875  83c408               add esp, 8
// 00605878  83bb7801000000       cmp dword ptr [ebx + 0x178], 0
// 0060587f  7447                 je 0x6058c8
// 00605881  b908000000           mov ecx, 8
// 00605886  2b8b58010000         sub ecx, dword ptr [ebx + 0x158]
// 0060588c  be01000000           mov esi, 1
// 00605891  d3e6                 shl esi, cl
// 00605893  33ff                 xor edi, edi
// 00605895  85f6                 test esi, esi
// 00605897  7e1f                 jle 0x6058b8
// 00605899  8da42400000000       lea esp, [esp]
// 006058a0  8b8378010000         mov eax, dword ptr [ebx + 0x178]
// 006058a6  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 006058a9  51                   push ecx
// 006058aa  53                   push ebx
// 006058ab  e830b40000           call 0x610ce0
// 006058b0  47                   inc edi
// 006058b1  83c408               add esp, 8
// 006058b4  3bfe                 cmp edi, esi
// 006058b6  7ce8                 jl 0x6058a0
// 006058b8  8b9378010000         mov edx, dword ptr [ebx + 0x178]
// 006058be  52                   push edx
// 006058bf  53                   push ebx
// 006058c0  e81bb40000           call 0x610ce0
// 006058c5  83c408               add esp, 8
// 006058c8  8b8310020000         mov eax, dword ptr [ebx + 0x210]
// 006058ce  50                   push eax
// 006058cf  53                   push ebx
// 006058d0  e80bb40000           call 0x610ce0
// 006058d5  8d4b74               lea ecx, [ebx + 0x74]
// 006058d8  51                   push ecx
// 006058d9  e822e80000           call 0x614100
// 006058de  8b93b0010000         mov edx, dword ptr [ebx + 0x1b0]
// 006058e4  52                   push edx
// 006058e5  53                   push ebx
// 006058e6  e8f5b30000           call 0x610ce0
// 006058eb  8b83e4010000         mov eax, dword ptr [ebx + 0x1e4]
// 006058f1  50                   push eax
// 006058f2  53                   push ebx
// 006058f3  e8e8b30000           call 0x610ce0
// 006058f8  8b6b48               mov ebp, dword ptr [ebx + 0x48]
// 006058fb  688c020000           push 0x28c
// 00605900  b910000000           mov ecx, 0x10
// 00605905  8bf3                 mov esi, ebx
// 00605907  8d7c2430             lea edi, [esp + 0x30]
// 0060590b  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0060590d  8b8b4c020000         mov ecx, dword ptr [ebx + 0x24c]
// 00605913  8b7340               mov esi, dword ptr [ebx + 0x40]
// 00605916  8b7b44               mov edi, dword ptr [ebx + 0x44]
// 00605919  6a00                 push 0
// 0060591b  53                   push ebx
// 0060591c  898c2480000000       mov dword ptr [esp + 0x80], ecx
// 00605923  e87cf11e00           call 0x7f4aa4
// 00605928  8b942480000000       mov edx, dword ptr [esp + 0x80]
// 0060592f  897340               mov dword ptr [ebx + 0x40], esi
// 00605932  897b44               mov dword ptr [ebx + 0x44], edi
// 00605935  83c428               add esp, 0x28
// 00605938  8bfb                 mov edi, ebx
// 0060593a  b910000000           mov ecx, 0x10
// 0060593f  8d742410             lea esi, [esp + 0x10]
// 00605943  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00605945  5f                   pop edi
// 00605946  5e                   pop esi
// 00605947  896b48               mov dword ptr [ebx + 0x48], ebp
// 0060594a  5d                   pop ebp
// 0060594b  89934c020000         mov dword ptr [ebx + 0x24c], edx
// 00605951  5b                   pop ebx
// 00605952  83c440               add esp, 0x40
// 00605955  c3                   ret 
// library libpng-1.2.32/pngread.c (function _png_read_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngread.c
