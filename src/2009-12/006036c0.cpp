// from server: 100% by auto
// roc 2009-12 006036c0  unit: seg_00600000  size: 941 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006036c0
//
// 006036c0  53                   push ebx
// 006036c1  57                   push edi
// 006036c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006036c6  33db                 xor ebx, ebx
// 006036c8  3bfb                 cmp edi, ebx
// 006036ca  0f849a030000         je 0x603a6a
// 006036d0  56                   push esi
// 006036d1  8b742414             mov esi, dword ptr [esp + 0x14]
// 006036d5  3bf3                 cmp esi, ebx
// 006036d7  0f848c030000         je 0x603a69
// 006036dd  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 006036e3  55                   push ebp
// 006036e4  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 006036e8  23c5                 and eax, ebp
// 006036ea  a900400000           test eax, 0x4000
// 006036ef  7461                 je 0x603752
// 006036f1  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006036f5  83f9ff               cmp ecx, -1
// 006036f8  7424                 je 0x60371e
// 006036fa  8b4638               mov eax, dword ptr [esi + 0x38]
// 006036fd  3bc3                 cmp eax, ebx
// 006036ff  7451                 je 0x603752
// 00603701  8be9                 mov ebp, ecx
// 00603703  c1e504               shl ebp, 4
// 00603706  8b442804             mov eax, dword ptr [eax + ebp + 4]
// 0060370a  3bc3                 cmp eax, ebx
// 0060370c  7440                 je 0x60374e
// 0060370e  50                   push eax
// 0060370f  57                   push edi
// 00603710  e8cbd50000           call 0x610ce0
// 00603715  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00603718  895c2904             mov dword ptr [ecx + ebp + 4], ebx
// 0060371c  eb2d                 jmp 0x60374b
// 0060371e  33ed                 xor ebp, ebp
// 00603720  395e30               cmp dword ptr [esi + 0x30], ebx
// 00603723  7e16                 jle 0x60373b
// 00603725  55                   push ebp
// 00603726  6800400000           push 0x4000
// 0060372b  56                   push esi
// 0060372c  57                   push edi
// 0060372d  e88effffff           call 0x6036c0
// 00603732  45                   inc ebp
// 00603733  83c410               add esp, 0x10
// 00603736  3b6e30               cmp ebp, dword ptr [esi + 0x30]
// 00603739  7cea                 jl 0x603725
// 0060373b  8b5638               mov edx, dword ptr [esi + 0x38]
// 0060373e  52                   push edx
// 0060373f  57                   push edi
// 00603740  e89bd50000           call 0x610ce0
// 00603745  895e38               mov dword ptr [esi + 0x38], ebx
// 00603748  895e30               mov dword ptr [esi + 0x30], ebx
// 0060374b  83c408               add esp, 8
// 0060374e  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00603752  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 00603758  23c5                 and eax, ebp
// 0060375a  a900200000           test eax, 0x2000
// 0060375f  7414                 je 0x603775
// 00603761  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 00603764  51                   push ecx
// 00603765  57                   push edi
// 00603766  e875d50000           call 0x610ce0
// 0060376b  83c408               add esp, 8
// 0060376e  836608ef             and dword ptr [esi + 8], 0xffffffef
// 00603772  895e4c               mov dword ptr [esi + 0x4c], ebx
// 00603775  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0060377b  23c5                 and eax, ebp
// 0060377d  a900010000           test eax, 0x100
// 00603782  7407                 je 0x60378b
// 00603784  816608ffbfffff       and dword ptr [esi + 8], 0xffffbfff
// 0060378b  84c0                 test al, al
// 0060378d  0f8986000000         jns 0x603819
// 00603793  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 00603799  52                   push edx
// 0060379a  57                   push edi
// 0060379b  e840d50000           call 0x610ce0
// 006037a0  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 006037a6  50                   push eax
// 006037a7  57                   push edi
// 006037a8  e833d50000           call 0x610ce0
// 006037ad  83c410               add esp, 0x10
// 006037b0  899ea0000000         mov dword ptr [esi + 0xa0], ebx
// 006037b6  899eac000000         mov dword ptr [esi + 0xac], ebx
// 006037bc  399eb0000000         cmp dword ptr [esi + 0xb0], ebx
// 006037c2  744e                 je 0x603812
// 006037c4  33ed                 xor ebp, ebp
// 006037c6  389eb5000000         cmp byte ptr [esi + 0xb5], bl
// 006037cc  762a                 jbe 0x6037f8
// 006037ce  8bff                 mov edi, edi
// 006037d0  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 006037d6  8b14a9               mov edx, dword ptr [ecx + ebp*4]
// 006037d9  52                   push edx
// 006037da  57                   push edi
// 006037db  e800d50000           call 0x610ce0
// 006037e0  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 006037e6  891ca8               mov dword ptr [eax + ebp*4], ebx
// 006037e9  0fb68eb5000000       movzx ecx, byte ptr [esi + 0xb5]
// 006037f0  45                   inc ebp
// 006037f1  83c408               add esp, 8
// 006037f4  3be9                 cmp ebp, ecx
// 006037f6  7cd8                 jl 0x6037d0
// 006037f8  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 006037fe  52                   push edx
// 006037ff  57                   push edi
// 00603800  e8dbd40000           call 0x610ce0
// 00603805  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00603809  83c408               add esp, 8
// 0060380c  899eb0000000         mov dword ptr [esi + 0xb0], ebx
// 00603812  816608fffbffff       and dword ptr [esi + 8], 0xfffffbff
// 00603819  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0060381f  23c5                 and eax, ebp
// 00603821  a810                 test al, 0x10
// 00603823  7430                 je 0x603855
// 00603825  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0060382b  51                   push ecx
// 0060382c  57                   push edi
// 0060382d  e8aed40000           call 0x610ce0
// 00603832  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 00603838  52                   push edx
// 00603839  57                   push edi
// 0060383a  e8a1d40000           call 0x610ce0
// 0060383f  83c410               add esp, 0x10
// 00603842  816608ffefffff       and dword ptr [esi + 8], 0xffffefff
// 00603849  899ec4000000         mov dword ptr [esi + 0xc4], ebx
// 0060384f  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 00603855  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0060385b  23c5                 and eax, ebp
// 0060385d  a820                 test al, 0x20
// 0060385f  0f84a0000000         je 0x603905
// 00603865  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00603869  83f9ff               cmp ecx, -1
// 0060386c  744a                 je 0x6038b8
// 0060386e  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 00603874  3bc3                 cmp eax, ebx
// 00603876  0f8489000000         je 0x603905
// 0060387c  8be9                 mov ebp, ecx
// 0060387e  c1e504               shl ebp, 4
// 00603881  8b0c28               mov ecx, dword ptr [eax + ebp]
// 00603884  51                   push ecx
// 00603885  57                   push edi
// 00603886  e855d40000           call 0x610ce0
// 0060388b  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 00603891  8b442a08             mov eax, dword ptr [edx + ebp + 8]
// 00603895  50                   push eax
// 00603896  57                   push edi
// 00603897  e844d40000           call 0x610ce0
// 0060389c  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 006038a2  891c29               mov dword ptr [ecx + ebp], ebx
// 006038a5  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 006038ab  895c2a08             mov dword ptr [edx + ebp + 8], ebx
// 006038af  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 006038b3  83c410               add esp, 0x10
// 006038b6  eb4d                 jmp 0x603905
// 006038b8  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 006038be  3bc3                 cmp eax, ebx
// 006038c0  743c                 je 0x6038fe
// 006038c2  33ed                 xor ebp, ebp
// 006038c4  3bc3                 cmp eax, ebx
// 006038c6  7e16                 jle 0x6038de
// 006038c8  55                   push ebp
// 006038c9  6a20                 push 0x20
// 006038cb  56                   push esi
// 006038cc  57                   push edi
// 006038cd  e8eefdffff           call 0x6036c0
// 006038d2  45                   inc ebp
// 006038d3  83c410               add esp, 0x10
// 006038d6  3baed8000000         cmp ebp, dword ptr [esi + 0xd8]
// 006038dc  7cea                 jl 0x6038c8
// 006038de  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 006038e4  50                   push eax
// 006038e5  57                   push edi
// 006038e6  e8f5d30000           call 0x610ce0
// 006038eb  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 006038ef  83c408               add esp, 8
// 006038f2  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 006038f8  899ed8000000         mov dword ptr [esi + 0xd8], ebx
// 006038fe  816608ffdfffff       and dword ptr [esi + 8], 0xffffdfff
// 00603905  8b8774020000         mov eax, dword ptr [edi + 0x274]
// 0060390b  3bc3                 cmp eax, ebx
// 0060390d  7410                 je 0x60391f
// 0060390f  50                   push eax
// 00603910  57                   push edi
// 00603911  e8cad30000           call 0x610ce0
// 00603916  83c408               add esp, 8
// 00603919  899f74020000         mov dword ptr [edi + 0x274], ebx
// 0060391f  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 00603925  23cd                 and ecx, ebp
// 00603927  f7c100020000         test ecx, 0x200
// 0060392d  747a                 je 0x6039a9
// 0060392f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00603933  83f9ff               cmp ecx, -1
// 00603936  7428                 je 0x603960
// 00603938  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 0060393e  3bc3                 cmp eax, ebx
// 00603940  7467                 je 0x6039a9
// 00603942  8d2c89               lea ebp, [ecx + ecx*4]
// 00603945  03ed                 add ebp, ebp
// 00603947  03ed                 add ebp, ebp
// 00603949  8b542808             mov edx, dword ptr [eax + ebp + 8]
// 0060394d  52                   push edx
// 0060394e  57                   push edi
// 0060394f  e88cd30000           call 0x610ce0
// 00603954  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 0060395a  895c2808             mov dword ptr [eax + ebp + 8], ebx
// 0060395e  eb42                 jmp 0x6039a2
// 00603960  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00603966  3bc3                 cmp eax, ebx
// 00603968  743f                 je 0x6039a9
// 0060396a  33ed                 xor ebp, ebp
// 0060396c  3bc3                 cmp eax, ebx
// 0060396e  7e19                 jle 0x603989
// 00603970  55                   push ebp
// 00603971  6800020000           push 0x200
// 00603976  56                   push esi
// 00603977  57                   push edi
// 00603978  e843fdffff           call 0x6036c0
// 0060397d  45                   inc ebp
// 0060397e  83c410               add esp, 0x10
// 00603981  3baec0000000         cmp ebp, dword ptr [esi + 0xc0]
// 00603987  7ce7                 jl 0x603970
// 00603989  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0060398f  51                   push ecx
// 00603990  57                   push edi
// 00603991  e84ad30000           call 0x610ce0
// 00603996  899ebc000000         mov dword ptr [esi + 0xbc], ebx
// 0060399c  899ec0000000         mov dword ptr [esi + 0xc0], ebx
// 006039a2  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 006039a6  83c408               add esp, 8
// 006039a9  8b96b8000000         mov edx, dword ptr [esi + 0xb8]
// 006039af  23d5                 and edx, ebp
// 006039b1  f6c208               test dl, 8
// 006039b4  7414                 je 0x6039ca
// 006039b6  8b467c               mov eax, dword ptr [esi + 0x7c]
// 006039b9  50                   push eax
// 006039ba  57                   push edi
// 006039bb  e820d30000           call 0x610ce0
// 006039c0  83c408               add esp, 8
// 006039c3  836608bf             and dword ptr [esi + 8], 0xffffffbf
// 006039c7  895e7c               mov dword ptr [esi + 0x7c], ebx
// 006039ca  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 006039d0  23cd                 and ecx, ebp
// 006039d2  f7c100100000         test ecx, 0x1000
// 006039d8  741a                 je 0x6039f4
// 006039da  8b5610               mov edx, dword ptr [esi + 0x10]
// 006039dd  52                   push edx
// 006039de  57                   push edi
// 006039df  e8fcd20000           call 0x610ce0
// 006039e4  836608f7             and dword ptr [esi + 8], 0xfffffff7
// 006039e8  83c408               add esp, 8
// 006039eb  33c0                 xor eax, eax
// 006039ed  895e10               mov dword ptr [esi + 0x10], ebx
// 006039f0  66894614             mov word ptr [esi + 0x14], ax
// 006039f4  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 006039fa  23cd                 and ecx, ebp
// 006039fc  f6c140               test cl, 0x40
// 006039ff  7452                 je 0x603a53
// 00603a01  399ef8000000         cmp dword ptr [esi + 0xf8], ebx
// 00603a07  7443                 je 0x603a4c
// 00603a09  33ed                 xor ebp, ebp
// 00603a0b  395e04               cmp dword ptr [esi + 4], ebx
// 00603a0e  7e22                 jle 0x603a32
// 00603a10  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 00603a16  8b04aa               mov eax, dword ptr [edx + ebp*4]
// 00603a19  50                   push eax
// 00603a1a  57                   push edi
// 00603a1b  e8c0d20000           call 0x610ce0
// 00603a20  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 00603a26  891ca9               mov dword ptr [ecx + ebp*4], ebx
// 00603a29  45                   inc ebp
// 00603a2a  83c408               add esp, 8
// 00603a2d  3b6e04               cmp ebp, dword ptr [esi + 4]
// 00603a30  7cde                 jl 0x603a10
// 00603a32  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 00603a38  52                   push edx
// 00603a39  57                   push edi
// 00603a3a  e8a1d20000           call 0x610ce0
// 00603a3f  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00603a43  83c408               add esp, 8
// 00603a46  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 00603a4c  816608ff7fffff       and dword ptr [esi + 8], 0xffff7fff
// 00603a53  837c2420ff           cmp dword ptr [esp + 0x20], -1
// 00603a58  7406                 je 0x603a60
// 00603a5a  81e5dfbdffff         and ebp, 0xffffbddf
// 00603a60  f7d5                 not ebp
// 00603a62  21aeb8000000         and dword ptr [esi + 0xb8], ebp
// 00603a68  5d                   pop ebp
// 00603a69  5e                   pop esi
// 00603a6a  5f                   pop edi
// 00603a6b  5b                   pop ebx
// 00603a6c  c3                   ret 
// library libpng-1.2.22/png.c (function _png_free_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 png.c
