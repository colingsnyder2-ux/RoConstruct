// from server: 100% by auto
// roc 2009-06 00581910  unit: seg_00580000  size: 941 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00581910
//
// 00581910  53                   push ebx
// 00581911  57                   push edi
// 00581912  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00581916  33db                 xor ebx, ebx
// 00581918  3bfb                 cmp edi, ebx
// 0058191a  0f849a030000         je 0x581cba
// 00581920  56                   push esi
// 00581921  8b742414             mov esi, dword ptr [esp + 0x14]
// 00581925  3bf3                 cmp esi, ebx
// 00581927  0f848c030000         je 0x581cb9
// 0058192d  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 00581933  55                   push ebp
// 00581934  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00581938  23c5                 and eax, ebp
// 0058193a  a900400000           test eax, 0x4000
// 0058193f  7461                 je 0x5819a2
// 00581941  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00581945  83f9ff               cmp ecx, -1
// 00581948  7424                 je 0x58196e
// 0058194a  8b4638               mov eax, dword ptr [esi + 0x38]
// 0058194d  3bc3                 cmp eax, ebx
// 0058194f  7451                 je 0x5819a2
// 00581951  8be9                 mov ebp, ecx
// 00581953  c1e504               shl ebp, 4
// 00581956  8b442804             mov eax, dword ptr [eax + ebp + 4]
// 0058195a  3bc3                 cmp eax, ebx
// 0058195c  7440                 je 0x58199e
// 0058195e  50                   push eax
// 0058195f  57                   push edi
// 00581960  e84bd30000           call 0x58ecb0
// 00581965  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00581968  895c2904             mov dword ptr [ecx + ebp + 4], ebx
// 0058196c  eb2d                 jmp 0x58199b
// 0058196e  33ed                 xor ebp, ebp
// 00581970  395e30               cmp dword ptr [esi + 0x30], ebx
// 00581973  7e16                 jle 0x58198b
// 00581975  55                   push ebp
// 00581976  6800400000           push 0x4000
// 0058197b  56                   push esi
// 0058197c  57                   push edi
// 0058197d  e88effffff           call 0x581910
// 00581982  45                   inc ebp
// 00581983  83c410               add esp, 0x10
// 00581986  3b6e30               cmp ebp, dword ptr [esi + 0x30]
// 00581989  7cea                 jl 0x581975
// 0058198b  8b5638               mov edx, dword ptr [esi + 0x38]
// 0058198e  52                   push edx
// 0058198f  57                   push edi
// 00581990  e81bd30000           call 0x58ecb0
// 00581995  895e38               mov dword ptr [esi + 0x38], ebx
// 00581998  895e30               mov dword ptr [esi + 0x30], ebx
// 0058199b  83c408               add esp, 8
// 0058199e  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 005819a2  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 005819a8  23c5                 and eax, ebp
// 005819aa  a900200000           test eax, 0x2000
// 005819af  7414                 je 0x5819c5
// 005819b1  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 005819b4  51                   push ecx
// 005819b5  57                   push edi
// 005819b6  e8f5d20000           call 0x58ecb0
// 005819bb  83c408               add esp, 8
// 005819be  836608ef             and dword ptr [esi + 8], 0xffffffef
// 005819c2  895e4c               mov dword ptr [esi + 0x4c], ebx
// 005819c5  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 005819cb  23c5                 and eax, ebp
// 005819cd  a900010000           test eax, 0x100
// 005819d2  7407                 je 0x5819db
// 005819d4  816608ffbfffff       and dword ptr [esi + 8], 0xffffbfff
// 005819db  84c0                 test al, al
// 005819dd  0f8986000000         jns 0x581a69
// 005819e3  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 005819e9  52                   push edx
// 005819ea  57                   push edi
// 005819eb  e8c0d20000           call 0x58ecb0
// 005819f0  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 005819f6  50                   push eax
// 005819f7  57                   push edi
// 005819f8  e8b3d20000           call 0x58ecb0
// 005819fd  83c410               add esp, 0x10
// 00581a00  899ea0000000         mov dword ptr [esi + 0xa0], ebx
// 00581a06  899eac000000         mov dword ptr [esi + 0xac], ebx
// 00581a0c  399eb0000000         cmp dword ptr [esi + 0xb0], ebx
// 00581a12  744e                 je 0x581a62
// 00581a14  33ed                 xor ebp, ebp
// 00581a16  389eb5000000         cmp byte ptr [esi + 0xb5], bl
// 00581a1c  762a                 jbe 0x581a48
// 00581a1e  8bff                 mov edi, edi
// 00581a20  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 00581a26  8b14a9               mov edx, dword ptr [ecx + ebp*4]
// 00581a29  52                   push edx
// 00581a2a  57                   push edi
// 00581a2b  e880d20000           call 0x58ecb0
// 00581a30  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00581a36  891ca8               mov dword ptr [eax + ebp*4], ebx
// 00581a39  0fb68eb5000000       movzx ecx, byte ptr [esi + 0xb5]
// 00581a40  45                   inc ebp
// 00581a41  83c408               add esp, 8
// 00581a44  3be9                 cmp ebp, ecx
// 00581a46  7cd8                 jl 0x581a20
// 00581a48  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 00581a4e  52                   push edx
// 00581a4f  57                   push edi
// 00581a50  e85bd20000           call 0x58ecb0
// 00581a55  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00581a59  83c408               add esp, 8
// 00581a5c  899eb0000000         mov dword ptr [esi + 0xb0], ebx
// 00581a62  816608fffbffff       and dword ptr [esi + 8], 0xfffffbff
// 00581a69  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 00581a6f  23c5                 and eax, ebp
// 00581a71  a810                 test al, 0x10
// 00581a73  7430                 je 0x581aa5
// 00581a75  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 00581a7b  51                   push ecx
// 00581a7c  57                   push edi
// 00581a7d  e82ed20000           call 0x58ecb0
// 00581a82  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 00581a88  52                   push edx
// 00581a89  57                   push edi
// 00581a8a  e821d20000           call 0x58ecb0
// 00581a8f  83c410               add esp, 0x10
// 00581a92  816608ffefffff       and dword ptr [esi + 8], 0xffffefff
// 00581a99  899ec4000000         mov dword ptr [esi + 0xc4], ebx
// 00581a9f  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 00581aa5  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 00581aab  23c5                 and eax, ebp
// 00581aad  a820                 test al, 0x20
// 00581aaf  0f84a0000000         je 0x581b55
// 00581ab5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00581ab9  83f9ff               cmp ecx, -1
// 00581abc  744a                 je 0x581b08
// 00581abe  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 00581ac4  3bc3                 cmp eax, ebx
// 00581ac6  0f8489000000         je 0x581b55
// 00581acc  8be9                 mov ebp, ecx
// 00581ace  c1e504               shl ebp, 4
// 00581ad1  8b0c28               mov ecx, dword ptr [eax + ebp]
// 00581ad4  51                   push ecx
// 00581ad5  57                   push edi
// 00581ad6  e8d5d10000           call 0x58ecb0
// 00581adb  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 00581ae1  8b442a08             mov eax, dword ptr [edx + ebp + 8]
// 00581ae5  50                   push eax
// 00581ae6  57                   push edi
// 00581ae7  e8c4d10000           call 0x58ecb0
// 00581aec  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00581af2  891c29               mov dword ptr [ecx + ebp], ebx
// 00581af5  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 00581afb  895c2a08             mov dword ptr [edx + ebp + 8], ebx
// 00581aff  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00581b03  83c410               add esp, 0x10
// 00581b06  eb4d                 jmp 0x581b55
// 00581b08  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00581b0e  3bc3                 cmp eax, ebx
// 00581b10  743c                 je 0x581b4e
// 00581b12  33ed                 xor ebp, ebp
// 00581b14  3bc3                 cmp eax, ebx
// 00581b16  7e16                 jle 0x581b2e
// 00581b18  55                   push ebp
// 00581b19  6a20                 push 0x20
// 00581b1b  56                   push esi
// 00581b1c  57                   push edi
// 00581b1d  e8eefdffff           call 0x581910
// 00581b22  45                   inc ebp
// 00581b23  83c410               add esp, 0x10
// 00581b26  3baed8000000         cmp ebp, dword ptr [esi + 0xd8]
// 00581b2c  7cea                 jl 0x581b18
// 00581b2e  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 00581b34  50                   push eax
// 00581b35  57                   push edi
// 00581b36  e875d10000           call 0x58ecb0
// 00581b3b  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00581b3f  83c408               add esp, 8
// 00581b42  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 00581b48  899ed8000000         mov dword ptr [esi + 0xd8], ebx
// 00581b4e  816608ffdfffff       and dword ptr [esi + 8], 0xffffdfff
// 00581b55  8b8774020000         mov eax, dword ptr [edi + 0x274]
// 00581b5b  3bc3                 cmp eax, ebx
// 00581b5d  7410                 je 0x581b6f
// 00581b5f  50                   push eax
// 00581b60  57                   push edi
// 00581b61  e84ad10000           call 0x58ecb0
// 00581b66  83c408               add esp, 8
// 00581b69  899f74020000         mov dword ptr [edi + 0x274], ebx
// 00581b6f  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 00581b75  23cd                 and ecx, ebp
// 00581b77  f7c100020000         test ecx, 0x200
// 00581b7d  747a                 je 0x581bf9
// 00581b7f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00581b83  83f9ff               cmp ecx, -1
// 00581b86  7428                 je 0x581bb0
// 00581b88  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 00581b8e  3bc3                 cmp eax, ebx
// 00581b90  7467                 je 0x581bf9
// 00581b92  8d2c89               lea ebp, [ecx + ecx*4]
// 00581b95  03ed                 add ebp, ebp
// 00581b97  03ed                 add ebp, ebp
// 00581b99  8b542808             mov edx, dword ptr [eax + ebp + 8]
// 00581b9d  52                   push edx
// 00581b9e  57                   push edi
// 00581b9f  e80cd10000           call 0x58ecb0
// 00581ba4  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 00581baa  895c2808             mov dword ptr [eax + ebp + 8], ebx
// 00581bae  eb42                 jmp 0x581bf2
// 00581bb0  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00581bb6  3bc3                 cmp eax, ebx
// 00581bb8  743f                 je 0x581bf9
// 00581bba  33ed                 xor ebp, ebp
// 00581bbc  3bc3                 cmp eax, ebx
// 00581bbe  7e19                 jle 0x581bd9
// 00581bc0  55                   push ebp
// 00581bc1  6800020000           push 0x200
// 00581bc6  56                   push esi
// 00581bc7  57                   push edi
// 00581bc8  e843fdffff           call 0x581910
// 00581bcd  45                   inc ebp
// 00581bce  83c410               add esp, 0x10
// 00581bd1  3baec0000000         cmp ebp, dword ptr [esi + 0xc0]
// 00581bd7  7ce7                 jl 0x581bc0
// 00581bd9  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 00581bdf  51                   push ecx
// 00581be0  57                   push edi
// 00581be1  e8cad00000           call 0x58ecb0
// 00581be6  899ebc000000         mov dword ptr [esi + 0xbc], ebx
// 00581bec  899ec0000000         mov dword ptr [esi + 0xc0], ebx
// 00581bf2  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00581bf6  83c408               add esp, 8
// 00581bf9  8b96b8000000         mov edx, dword ptr [esi + 0xb8]
// 00581bff  23d5                 and edx, ebp
// 00581c01  f6c208               test dl, 8
// 00581c04  7414                 je 0x581c1a
// 00581c06  8b467c               mov eax, dword ptr [esi + 0x7c]
// 00581c09  50                   push eax
// 00581c0a  57                   push edi
// 00581c0b  e8a0d00000           call 0x58ecb0
// 00581c10  83c408               add esp, 8
// 00581c13  836608bf             and dword ptr [esi + 8], 0xffffffbf
// 00581c17  895e7c               mov dword ptr [esi + 0x7c], ebx
// 00581c1a  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 00581c20  23cd                 and ecx, ebp
// 00581c22  f7c100100000         test ecx, 0x1000
// 00581c28  741a                 je 0x581c44
// 00581c2a  8b5610               mov edx, dword ptr [esi + 0x10]
// 00581c2d  52                   push edx
// 00581c2e  57                   push edi
// 00581c2f  e87cd00000           call 0x58ecb0
// 00581c34  836608f7             and dword ptr [esi + 8], 0xfffffff7
// 00581c38  83c408               add esp, 8
// 00581c3b  33c0                 xor eax, eax
// 00581c3d  895e10               mov dword ptr [esi + 0x10], ebx
// 00581c40  66894614             mov word ptr [esi + 0x14], ax
// 00581c44  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 00581c4a  23cd                 and ecx, ebp
// 00581c4c  f6c140               test cl, 0x40
// 00581c4f  7452                 je 0x581ca3
// 00581c51  399ef8000000         cmp dword ptr [esi + 0xf8], ebx
// 00581c57  7443                 je 0x581c9c
// 00581c59  33ed                 xor ebp, ebp
// 00581c5b  395e04               cmp dword ptr [esi + 4], ebx
// 00581c5e  7e22                 jle 0x581c82
// 00581c60  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 00581c66  8b04aa               mov eax, dword ptr [edx + ebp*4]
// 00581c69  50                   push eax
// 00581c6a  57                   push edi
// 00581c6b  e840d00000           call 0x58ecb0
// 00581c70  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 00581c76  891ca9               mov dword ptr [ecx + ebp*4], ebx
// 00581c79  45                   inc ebp
// 00581c7a  83c408               add esp, 8
// 00581c7d  3b6e04               cmp ebp, dword ptr [esi + 4]
// 00581c80  7cde                 jl 0x581c60
// 00581c82  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 00581c88  52                   push edx
// 00581c89  57                   push edi
// 00581c8a  e821d00000           call 0x58ecb0
// 00581c8f  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00581c93  83c408               add esp, 8
// 00581c96  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 00581c9c  816608ff7fffff       and dword ptr [esi + 8], 0xffff7fff
// 00581ca3  837c2420ff           cmp dword ptr [esp + 0x20], -1
// 00581ca8  7406                 je 0x581cb0
// 00581caa  81e5dfbdffff         and ebp, 0xffffbddf
// 00581cb0  f7d5                 not ebp
// 00581cb2  21aeb8000000         and dword ptr [esi + 0xb8], ebp
// 00581cb8  5d                   pop ebp
// 00581cb9  5e                   pop esi
// 00581cba  5f                   pop edi
// 00581cbb  5b                   pop ebx
// 00581cbc  c3                   ret 
// library libpng-1.2.22/png.c (function _png_free_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 png.c
