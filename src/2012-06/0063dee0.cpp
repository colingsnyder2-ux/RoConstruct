// from server: 100% by auto
// roc 2012-06 0063dee0  unit: seg_00630000  size: 941 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063dee0
//
// 0063dee0  53                   push ebx
// 0063dee1  57                   push edi
// 0063dee2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0063dee6  33db                 xor ebx, ebx
// 0063dee8  3bfb                 cmp edi, ebx
// 0063deea  0f849a030000         je 0x63e28a
// 0063def0  56                   push esi
// 0063def1  8b742414             mov esi, dword ptr [esp + 0x14]
// 0063def5  3bf3                 cmp esi, ebx
// 0063def7  0f848c030000         je 0x63e289
// 0063defd  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0063df03  55                   push ebp
// 0063df04  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0063df08  23c5                 and eax, ebp
// 0063df0a  a900400000           test eax, 0x4000
// 0063df0f  7461                 je 0x63df72
// 0063df11  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0063df15  83f9ff               cmp ecx, -1
// 0063df18  7424                 je 0x63df3e
// 0063df1a  8b4638               mov eax, dword ptr [esi + 0x38]
// 0063df1d  3bc3                 cmp eax, ebx
// 0063df1f  7451                 je 0x63df72
// 0063df21  8be9                 mov ebp, ecx
// 0063df23  c1e504               shl ebp, 4
// 0063df26  8b442804             mov eax, dword ptr [eax + ebp + 4]
// 0063df2a  3bc3                 cmp eax, ebx
// 0063df2c  7440                 je 0x63df6e
// 0063df2e  50                   push eax
// 0063df2f  57                   push edi
// 0063df30  e8eb050100           call 0x64e520
// 0063df35  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0063df38  895c2904             mov dword ptr [ecx + ebp + 4], ebx
// 0063df3c  eb2d                 jmp 0x63df6b
// 0063df3e  33ed                 xor ebp, ebp
// 0063df40  395e30               cmp dword ptr [esi + 0x30], ebx
// 0063df43  7e16                 jle 0x63df5b
// 0063df45  55                   push ebp
// 0063df46  6800400000           push 0x4000
// 0063df4b  56                   push esi
// 0063df4c  57                   push edi
// 0063df4d  e88effffff           call 0x63dee0
// 0063df52  45                   inc ebp
// 0063df53  83c410               add esp, 0x10
// 0063df56  3b6e30               cmp ebp, dword ptr [esi + 0x30]
// 0063df59  7cea                 jl 0x63df45
// 0063df5b  8b5638               mov edx, dword ptr [esi + 0x38]
// 0063df5e  52                   push edx
// 0063df5f  57                   push edi
// 0063df60  e8bb050100           call 0x64e520
// 0063df65  895e38               mov dword ptr [esi + 0x38], ebx
// 0063df68  895e30               mov dword ptr [esi + 0x30], ebx
// 0063df6b  83c408               add esp, 8
// 0063df6e  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0063df72  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0063df78  23c5                 and eax, ebp
// 0063df7a  a900200000           test eax, 0x2000
// 0063df7f  7414                 je 0x63df95
// 0063df81  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0063df84  51                   push ecx
// 0063df85  57                   push edi
// 0063df86  e895050100           call 0x64e520
// 0063df8b  83c408               add esp, 8
// 0063df8e  836608ef             and dword ptr [esi + 8], 0xffffffef
// 0063df92  895e4c               mov dword ptr [esi + 0x4c], ebx
// 0063df95  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0063df9b  23c5                 and eax, ebp
// 0063df9d  a900010000           test eax, 0x100
// 0063dfa2  7407                 je 0x63dfab
// 0063dfa4  816608ffbfffff       and dword ptr [esi + 8], 0xffffbfff
// 0063dfab  84c0                 test al, al
// 0063dfad  0f8986000000         jns 0x63e039
// 0063dfb3  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 0063dfb9  52                   push edx
// 0063dfba  57                   push edi
// 0063dfbb  e860050100           call 0x64e520
// 0063dfc0  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0063dfc6  50                   push eax
// 0063dfc7  57                   push edi
// 0063dfc8  e853050100           call 0x64e520
// 0063dfcd  83c410               add esp, 0x10
// 0063dfd0  899ea0000000         mov dword ptr [esi + 0xa0], ebx
// 0063dfd6  899eac000000         mov dword ptr [esi + 0xac], ebx
// 0063dfdc  399eb0000000         cmp dword ptr [esi + 0xb0], ebx
// 0063dfe2  744e                 je 0x63e032
// 0063dfe4  33ed                 xor ebp, ebp
// 0063dfe6  389eb5000000         cmp byte ptr [esi + 0xb5], bl
// 0063dfec  762a                 jbe 0x63e018
// 0063dfee  8bff                 mov edi, edi
// 0063dff0  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0063dff6  8b14a9               mov edx, dword ptr [ecx + ebp*4]
// 0063dff9  52                   push edx
// 0063dffa  57                   push edi
// 0063dffb  e820050100           call 0x64e520
// 0063e000  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0063e006  891ca8               mov dword ptr [eax + ebp*4], ebx
// 0063e009  0fb68eb5000000       movzx ecx, byte ptr [esi + 0xb5]
// 0063e010  45                   inc ebp
// 0063e011  83c408               add esp, 8
// 0063e014  3be9                 cmp ebp, ecx
// 0063e016  7cd8                 jl 0x63dff0
// 0063e018  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 0063e01e  52                   push edx
// 0063e01f  57                   push edi
// 0063e020  e8fb040100           call 0x64e520
// 0063e025  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0063e029  83c408               add esp, 8
// 0063e02c  899eb0000000         mov dword ptr [esi + 0xb0], ebx
// 0063e032  816608fffbffff       and dword ptr [esi + 8], 0xfffffbff
// 0063e039  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0063e03f  23c5                 and eax, ebp
// 0063e041  a810                 test al, 0x10
// 0063e043  7430                 je 0x63e075
// 0063e045  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0063e04b  51                   push ecx
// 0063e04c  57                   push edi
// 0063e04d  e8ce040100           call 0x64e520
// 0063e052  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 0063e058  52                   push edx
// 0063e059  57                   push edi
// 0063e05a  e8c1040100           call 0x64e520
// 0063e05f  83c410               add esp, 0x10
// 0063e062  816608ffefffff       and dword ptr [esi + 8], 0xffffefff
// 0063e069  899ec4000000         mov dword ptr [esi + 0xc4], ebx
// 0063e06f  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 0063e075  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0063e07b  23c5                 and eax, ebp
// 0063e07d  a820                 test al, 0x20
// 0063e07f  0f84a0000000         je 0x63e125
// 0063e085  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0063e089  83f9ff               cmp ecx, -1
// 0063e08c  744a                 je 0x63e0d8
// 0063e08e  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 0063e094  3bc3                 cmp eax, ebx
// 0063e096  0f8489000000         je 0x63e125
// 0063e09c  8be9                 mov ebp, ecx
// 0063e09e  c1e504               shl ebp, 4
// 0063e0a1  8b0c28               mov ecx, dword ptr [eax + ebp]
// 0063e0a4  51                   push ecx
// 0063e0a5  57                   push edi
// 0063e0a6  e875040100           call 0x64e520
// 0063e0ab  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 0063e0b1  8b442a08             mov eax, dword ptr [edx + ebp + 8]
// 0063e0b5  50                   push eax
// 0063e0b6  57                   push edi
// 0063e0b7  e864040100           call 0x64e520
// 0063e0bc  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 0063e0c2  891c29               mov dword ptr [ecx + ebp], ebx
// 0063e0c5  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 0063e0cb  895c2a08             mov dword ptr [edx + ebp + 8], ebx
// 0063e0cf  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0063e0d3  83c410               add esp, 0x10
// 0063e0d6  eb4d                 jmp 0x63e125
// 0063e0d8  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 0063e0de  3bc3                 cmp eax, ebx
// 0063e0e0  743c                 je 0x63e11e
// 0063e0e2  33ed                 xor ebp, ebp
// 0063e0e4  3bc3                 cmp eax, ebx
// 0063e0e6  7e16                 jle 0x63e0fe
// 0063e0e8  55                   push ebp
// 0063e0e9  6a20                 push 0x20
// 0063e0eb  56                   push esi
// 0063e0ec  57                   push edi
// 0063e0ed  e8eefdffff           call 0x63dee0
// 0063e0f2  45                   inc ebp
// 0063e0f3  83c410               add esp, 0x10
// 0063e0f6  3baed8000000         cmp ebp, dword ptr [esi + 0xd8]
// 0063e0fc  7cea                 jl 0x63e0e8
// 0063e0fe  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 0063e104  50                   push eax
// 0063e105  57                   push edi
// 0063e106  e815040100           call 0x64e520
// 0063e10b  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0063e10f  83c408               add esp, 8
// 0063e112  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 0063e118  899ed8000000         mov dword ptr [esi + 0xd8], ebx
// 0063e11e  816608ffdfffff       and dword ptr [esi + 8], 0xffffdfff
// 0063e125  8b8774020000         mov eax, dword ptr [edi + 0x274]
// 0063e12b  3bc3                 cmp eax, ebx
// 0063e12d  7410                 je 0x63e13f
// 0063e12f  50                   push eax
// 0063e130  57                   push edi
// 0063e131  e8ea030100           call 0x64e520
// 0063e136  83c408               add esp, 8
// 0063e139  899f74020000         mov dword ptr [edi + 0x274], ebx
// 0063e13f  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 0063e145  23cd                 and ecx, ebp
// 0063e147  f7c100020000         test ecx, 0x200
// 0063e14d  747a                 je 0x63e1c9
// 0063e14f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0063e153  83f9ff               cmp ecx, -1
// 0063e156  7428                 je 0x63e180
// 0063e158  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 0063e15e  3bc3                 cmp eax, ebx
// 0063e160  7467                 je 0x63e1c9
// 0063e162  8d2c89               lea ebp, [ecx + ecx*4]
// 0063e165  03ed                 add ebp, ebp
// 0063e167  03ed                 add ebp, ebp
// 0063e169  8b542808             mov edx, dword ptr [eax + ebp + 8]
// 0063e16d  52                   push edx
// 0063e16e  57                   push edi
// 0063e16f  e8ac030100           call 0x64e520
// 0063e174  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 0063e17a  895c2808             mov dword ptr [eax + ebp + 8], ebx
// 0063e17e  eb42                 jmp 0x63e1c2
// 0063e180  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0063e186  3bc3                 cmp eax, ebx
// 0063e188  743f                 je 0x63e1c9
// 0063e18a  33ed                 xor ebp, ebp
// 0063e18c  3bc3                 cmp eax, ebx
// 0063e18e  7e19                 jle 0x63e1a9
// 0063e190  55                   push ebp
// 0063e191  6800020000           push 0x200
// 0063e196  56                   push esi
// 0063e197  57                   push edi
// 0063e198  e843fdffff           call 0x63dee0
// 0063e19d  45                   inc ebp
// 0063e19e  83c410               add esp, 0x10
// 0063e1a1  3baec0000000         cmp ebp, dword ptr [esi + 0xc0]
// 0063e1a7  7ce7                 jl 0x63e190
// 0063e1a9  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0063e1af  51                   push ecx
// 0063e1b0  57                   push edi
// 0063e1b1  e86a030100           call 0x64e520
// 0063e1b6  899ebc000000         mov dword ptr [esi + 0xbc], ebx
// 0063e1bc  899ec0000000         mov dword ptr [esi + 0xc0], ebx
// 0063e1c2  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0063e1c6  83c408               add esp, 8
// 0063e1c9  8b96b8000000         mov edx, dword ptr [esi + 0xb8]
// 0063e1cf  23d5                 and edx, ebp
// 0063e1d1  f6c208               test dl, 8
// 0063e1d4  7414                 je 0x63e1ea
// 0063e1d6  8b467c               mov eax, dword ptr [esi + 0x7c]
// 0063e1d9  50                   push eax
// 0063e1da  57                   push edi
// 0063e1db  e840030100           call 0x64e520
// 0063e1e0  83c408               add esp, 8
// 0063e1e3  836608bf             and dword ptr [esi + 8], 0xffffffbf
// 0063e1e7  895e7c               mov dword ptr [esi + 0x7c], ebx
// 0063e1ea  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 0063e1f0  23cd                 and ecx, ebp
// 0063e1f2  f7c100100000         test ecx, 0x1000
// 0063e1f8  741a                 je 0x63e214
// 0063e1fa  8b5610               mov edx, dword ptr [esi + 0x10]
// 0063e1fd  52                   push edx
// 0063e1fe  57                   push edi
// 0063e1ff  e81c030100           call 0x64e520
// 0063e204  836608f7             and dword ptr [esi + 8], 0xfffffff7
// 0063e208  83c408               add esp, 8
// 0063e20b  33c0                 xor eax, eax
// 0063e20d  895e10               mov dword ptr [esi + 0x10], ebx
// 0063e210  66894614             mov word ptr [esi + 0x14], ax
// 0063e214  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 0063e21a  23cd                 and ecx, ebp
// 0063e21c  f6c140               test cl, 0x40
// 0063e21f  7452                 je 0x63e273
// 0063e221  399ef8000000         cmp dword ptr [esi + 0xf8], ebx
// 0063e227  7443                 je 0x63e26c
// 0063e229  33ed                 xor ebp, ebp
// 0063e22b  395e04               cmp dword ptr [esi + 4], ebx
// 0063e22e  7e22                 jle 0x63e252
// 0063e230  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 0063e236  8b04aa               mov eax, dword ptr [edx + ebp*4]
// 0063e239  50                   push eax
// 0063e23a  57                   push edi
// 0063e23b  e8e0020100           call 0x64e520
// 0063e240  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0063e246  891ca9               mov dword ptr [ecx + ebp*4], ebx
// 0063e249  45                   inc ebp
// 0063e24a  83c408               add esp, 8
// 0063e24d  3b6e04               cmp ebp, dword ptr [esi + 4]
// 0063e250  7cde                 jl 0x63e230
// 0063e252  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 0063e258  52                   push edx
// 0063e259  57                   push edi
// 0063e25a  e8c1020100           call 0x64e520
// 0063e25f  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0063e263  83c408               add esp, 8
// 0063e266  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 0063e26c  816608ff7fffff       and dword ptr [esi + 8], 0xffff7fff
// 0063e273  837c2420ff           cmp dword ptr [esp + 0x20], -1
// 0063e278  7406                 je 0x63e280
// 0063e27a  81e5dfbdffff         and ebp, 0xffffbddf
// 0063e280  f7d5                 not ebp
// 0063e282  21aeb8000000         and dword ptr [esi + 0xb8], ebp
// 0063e288  5d                   pop ebp
// 0063e289  5e                   pop esi
// 0063e28a  5f                   pop edi
// 0063e28b  5b                   pop ebx
// 0063e28c  c3                   ret 
// library libpng-1.2.22/png.c (function _png_free_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 png.c
