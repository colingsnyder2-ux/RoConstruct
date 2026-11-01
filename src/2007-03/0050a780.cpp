// from server: 100% by auto
// roc 2007-03 0050a780  unit: seg_00500000  size: 930 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050a780
//
// 0050a780  53                   push ebx
// 0050a781  57                   push edi
// 0050a782  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0050a786  33db                 xor ebx, ebx
// 0050a788  3bfb                 cmp edi, ebx
// 0050a78a  0f848f030000         je 0x50ab1f
// 0050a790  56                   push esi
// 0050a791  8b742414             mov esi, dword ptr [esp + 0x14]
// 0050a795  3bf3                 cmp esi, ebx
// 0050a797  0f8481030000         je 0x50ab1e
// 0050a79d  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0050a7a3  55                   push ebp
// 0050a7a4  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0050a7a8  23c5                 and eax, ebp
// 0050a7aa  a900400000           test eax, 0x4000
// 0050a7af  7463                 je 0x50a814
// 0050a7b1  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0050a7b5  83f9ff               cmp ecx, -1
// 0050a7b8  7424                 je 0x50a7de
// 0050a7ba  8b4638               mov eax, dword ptr [esi + 0x38]
// 0050a7bd  3bc3                 cmp eax, ebx
// 0050a7bf  7453                 je 0x50a814
// 0050a7c1  8be9                 mov ebp, ecx
// 0050a7c3  c1e504               shl ebp, 4
// 0050a7c6  8b442804             mov eax, dword ptr [eax + ebp + 4]
// 0050a7ca  3bc3                 cmp eax, ebx
// 0050a7cc  7442                 je 0x50a810
// 0050a7ce  50                   push eax
// 0050a7cf  57                   push edi
// 0050a7d0  e81be80000           call 0x518ff0
// 0050a7d5  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0050a7d8  895c2904             mov dword ptr [ecx + ebp + 4], ebx
// 0050a7dc  eb2f                 jmp 0x50a80d
// 0050a7de  33ed                 xor ebp, ebp
// 0050a7e0  395e30               cmp dword ptr [esi + 0x30], ebx
// 0050a7e3  7e18                 jle 0x50a7fd
// 0050a7e5  55                   push ebp
// 0050a7e6  6800400000           push 0x4000
// 0050a7eb  56                   push esi
// 0050a7ec  57                   push edi
// 0050a7ed  e88effffff           call 0x50a780
// 0050a7f2  83c501               add ebp, 1
// 0050a7f5  83c410               add esp, 0x10
// 0050a7f8  3b6e30               cmp ebp, dword ptr [esi + 0x30]
// 0050a7fb  7ce8                 jl 0x50a7e5
// 0050a7fd  8b5638               mov edx, dword ptr [esi + 0x38]
// 0050a800  52                   push edx
// 0050a801  57                   push edi
// 0050a802  e8e9e70000           call 0x518ff0
// 0050a807  895e38               mov dword ptr [esi + 0x38], ebx
// 0050a80a  895e30               mov dword ptr [esi + 0x30], ebx
// 0050a80d  83c408               add esp, 8
// 0050a810  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0050a814  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0050a81a  23c5                 and eax, ebp
// 0050a81c  a900200000           test eax, 0x2000
// 0050a821  7414                 je 0x50a837
// 0050a823  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0050a826  51                   push ecx
// 0050a827  57                   push edi
// 0050a828  e8c3e70000           call 0x518ff0
// 0050a82d  83c408               add esp, 8
// 0050a830  836608ef             and dword ptr [esi + 8], 0xffffffef
// 0050a834  895e4c               mov dword ptr [esi + 0x4c], ebx
// 0050a837  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0050a83d  23c5                 and eax, ebp
// 0050a83f  a900010000           test eax, 0x100
// 0050a844  7407                 je 0x50a84d
// 0050a846  816608ffbfffff       and dword ptr [esi + 8], 0xffffbfff
// 0050a84d  84c0                 test al, al
// 0050a84f  0f8986000000         jns 0x50a8db
// 0050a855  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 0050a85b  52                   push edx
// 0050a85c  57                   push edi
// 0050a85d  e88ee70000           call 0x518ff0
// 0050a862  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0050a868  50                   push eax
// 0050a869  57                   push edi
// 0050a86a  e881e70000           call 0x518ff0
// 0050a86f  83c410               add esp, 0x10
// 0050a872  399eb0000000         cmp dword ptr [esi + 0xb0], ebx
// 0050a878  899ea0000000         mov dword ptr [esi + 0xa0], ebx
// 0050a87e  899eac000000         mov dword ptr [esi + 0xac], ebx
// 0050a884  744e                 je 0x50a8d4
// 0050a886  33ed                 xor ebp, ebp
// 0050a888  389eb5000000         cmp byte ptr [esi + 0xb5], bl
// 0050a88e  762a                 jbe 0x50a8ba
// 0050a890  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0050a896  8b14a9               mov edx, dword ptr [ecx + ebp*4]
// 0050a899  52                   push edx
// 0050a89a  57                   push edi
// 0050a89b  e850e70000           call 0x518ff0
// 0050a8a0  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0050a8a6  891ca8               mov dword ptr [eax + ebp*4], ebx
// 0050a8a9  0fb68eb5000000       movzx ecx, byte ptr [esi + 0xb5]
// 0050a8b0  83c501               add ebp, 1
// 0050a8b3  83c408               add esp, 8
// 0050a8b6  3be9                 cmp ebp, ecx
// 0050a8b8  7cd6                 jl 0x50a890
// 0050a8ba  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 0050a8c0  52                   push edx
// 0050a8c1  57                   push edi
// 0050a8c2  e829e70000           call 0x518ff0
// 0050a8c7  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0050a8cb  83c408               add esp, 8
// 0050a8ce  899eb0000000         mov dword ptr [esi + 0xb0], ebx
// 0050a8d4  816608fffbffff       and dword ptr [esi + 8], 0xfffffbff
// 0050a8db  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0050a8e1  23c5                 and eax, ebp
// 0050a8e3  a810                 test al, 0x10
// 0050a8e5  7430                 je 0x50a917
// 0050a8e7  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0050a8ed  51                   push ecx
// 0050a8ee  57                   push edi
// 0050a8ef  e8fce60000           call 0x518ff0
// 0050a8f4  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 0050a8fa  52                   push edx
// 0050a8fb  57                   push edi
// 0050a8fc  e8efe60000           call 0x518ff0
// 0050a901  83c410               add esp, 0x10
// 0050a904  816608ffefffff       and dword ptr [esi + 8], 0xffffefff
// 0050a90b  899ec4000000         mov dword ptr [esi + 0xc4], ebx
// 0050a911  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 0050a917  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0050a91d  23c5                 and eax, ebp
// 0050a91f  a820                 test al, 0x20
// 0050a921  0f84a8000000         je 0x50a9cf
// 0050a927  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0050a92b  83f9ff               cmp ecx, -1
// 0050a92e  744a                 je 0x50a97a
// 0050a930  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 0050a936  3bc3                 cmp eax, ebx
// 0050a938  0f8491000000         je 0x50a9cf
// 0050a93e  8be9                 mov ebp, ecx
// 0050a940  c1e504               shl ebp, 4
// 0050a943  8b0c28               mov ecx, dword ptr [eax + ebp]
// 0050a946  51                   push ecx
// 0050a947  57                   push edi
// 0050a948  e8a3e60000           call 0x518ff0
// 0050a94d  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 0050a953  8b442a08             mov eax, dword ptr [edx + ebp + 8]
// 0050a957  50                   push eax
// 0050a958  57                   push edi
// 0050a959  e892e60000           call 0x518ff0
// 0050a95e  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 0050a964  891c29               mov dword ptr [ecx + ebp], ebx
// 0050a967  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 0050a96d  895c2a08             mov dword ptr [edx + ebp + 8], ebx
// 0050a971  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0050a975  83c410               add esp, 0x10
// 0050a978  eb55                 jmp 0x50a9cf
// 0050a97a  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 0050a980  3bc3                 cmp eax, ebx
// 0050a982  7444                 je 0x50a9c8
// 0050a984  33ed                 xor ebp, ebp
// 0050a986  3bc3                 cmp eax, ebx
// 0050a988  7e1e                 jle 0x50a9a8
// 0050a98a  8d9b00000000         lea ebx, [ebx]
// 0050a990  55                   push ebp
// 0050a991  6a20                 push 0x20
// 0050a993  56                   push esi
// 0050a994  57                   push edi
// 0050a995  e8e6fdffff           call 0x50a780
// 0050a99a  83c501               add ebp, 1
// 0050a99d  83c410               add esp, 0x10
// 0050a9a0  3baed8000000         cmp ebp, dword ptr [esi + 0xd8]
// 0050a9a6  7ce8                 jl 0x50a990
// 0050a9a8  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 0050a9ae  50                   push eax
// 0050a9af  57                   push edi
// 0050a9b0  e83be60000           call 0x518ff0
// 0050a9b5  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0050a9b9  83c408               add esp, 8
// 0050a9bc  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 0050a9c2  899ed8000000         mov dword ptr [esi + 0xd8], ebx
// 0050a9c8  816608ffdfffff       and dword ptr [esi + 8], 0xffffdfff
// 0050a9cf  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 0050a9d5  23cd                 and ecx, ebp
// 0050a9d7  f7c100020000         test ecx, 0x200
// 0050a9dd  0f847c000000         je 0x50aa5f
// 0050a9e3  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0050a9e7  83f9ff               cmp ecx, -1
// 0050a9ea  7428                 je 0x50aa14
// 0050a9ec  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 0050a9f2  3bc3                 cmp eax, ebx
// 0050a9f4  7469                 je 0x50aa5f
// 0050a9f6  8d2c89               lea ebp, [ecx + ecx*4]
// 0050a9f9  03ed                 add ebp, ebp
// 0050a9fb  03ed                 add ebp, ebp
// 0050a9fd  8b542808             mov edx, dword ptr [eax + ebp + 8]
// 0050aa01  52                   push edx
// 0050aa02  57                   push edi
// 0050aa03  e8e8e50000           call 0x518ff0
// 0050aa08  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 0050aa0e  895c2808             mov dword ptr [eax + ebp + 8], ebx
// 0050aa12  eb44                 jmp 0x50aa58
// 0050aa14  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0050aa1a  3bc3                 cmp eax, ebx
// 0050aa1c  7441                 je 0x50aa5f
// 0050aa1e  33ed                 xor ebp, ebp
// 0050aa20  3bc3                 cmp eax, ebx
// 0050aa22  7e1b                 jle 0x50aa3f
// 0050aa24  55                   push ebp
// 0050aa25  6800020000           push 0x200
// 0050aa2a  56                   push esi
// 0050aa2b  57                   push edi
// 0050aa2c  e84ffdffff           call 0x50a780
// 0050aa31  83c501               add ebp, 1
// 0050aa34  83c410               add esp, 0x10
// 0050aa37  3baec0000000         cmp ebp, dword ptr [esi + 0xc0]
// 0050aa3d  7ce5                 jl 0x50aa24
// 0050aa3f  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0050aa45  51                   push ecx
// 0050aa46  57                   push edi
// 0050aa47  e8a4e50000           call 0x518ff0
// 0050aa4c  899ebc000000         mov dword ptr [esi + 0xbc], ebx
// 0050aa52  899ec0000000         mov dword ptr [esi + 0xc0], ebx
// 0050aa58  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0050aa5c  83c408               add esp, 8
// 0050aa5f  8b96b8000000         mov edx, dword ptr [esi + 0xb8]
// 0050aa65  23d5                 and edx, ebp
// 0050aa67  f6c208               test dl, 8
// 0050aa6a  7414                 je 0x50aa80
// 0050aa6c  8b467c               mov eax, dword ptr [esi + 0x7c]
// 0050aa6f  50                   push eax
// 0050aa70  57                   push edi
// 0050aa71  e87ae50000           call 0x518ff0
// 0050aa76  83c408               add esp, 8
// 0050aa79  836608bf             and dword ptr [esi + 8], 0xffffffbf
// 0050aa7d  895e7c               mov dword ptr [esi + 0x7c], ebx
// 0050aa80  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 0050aa86  23cd                 and ecx, ebp
// 0050aa88  f7c100100000         test ecx, 0x1000
// 0050aa8e  7418                 je 0x50aaa8
// 0050aa90  8b5610               mov edx, dword ptr [esi + 0x10]
// 0050aa93  52                   push edx
// 0050aa94  57                   push edi
// 0050aa95  e826fcffff           call 0x50a6c0
// 0050aa9a  83c408               add esp, 8
// 0050aa9d  836608f7             and dword ptr [esi + 8], 0xfffffff7
// 0050aaa1  895e10               mov dword ptr [esi + 0x10], ebx
// 0050aaa4  66895e14             mov word ptr [esi + 0x14], bx
// 0050aaa8  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0050aaae  23c5                 and eax, ebp
// 0050aab0  a840                 test al, 0x40
// 0050aab2  7454                 je 0x50ab08
// 0050aab4  399ef8000000         cmp dword ptr [esi + 0xf8], ebx
// 0050aaba  7445                 je 0x50ab01
// 0050aabc  33ed                 xor ebp, ebp
// 0050aabe  395e04               cmp dword ptr [esi + 4], ebx
// 0050aac1  7e24                 jle 0x50aae7
// 0050aac3  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0050aac9  8b14a9               mov edx, dword ptr [ecx + ebp*4]
// 0050aacc  52                   push edx
// 0050aacd  57                   push edi
// 0050aace  e81de50000           call 0x518ff0
// 0050aad3  8b86f8000000         mov eax, dword ptr [esi + 0xf8]
// 0050aad9  891ca8               mov dword ptr [eax + ebp*4], ebx
// 0050aadc  83c501               add ebp, 1
// 0050aadf  83c408               add esp, 8
// 0050aae2  3b6e04               cmp ebp, dword ptr [esi + 4]
// 0050aae5  7cdc                 jl 0x50aac3
// 0050aae7  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0050aaed  51                   push ecx
// 0050aaee  57                   push edi
// 0050aaef  e8fce40000           call 0x518ff0
// 0050aaf4  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0050aaf8  83c408               add esp, 8
// 0050aafb  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 0050ab01  816608ff7fffff       and dword ptr [esi + 8], 0xffff7fff
// 0050ab08  837c2420ff           cmp dword ptr [esp + 0x20], -1
// 0050ab0d  7406                 je 0x50ab15
// 0050ab0f  81e5dfbdffff         and ebp, 0xffffbddf
// 0050ab15  f7d5                 not ebp
// 0050ab17  21aeb8000000         and dword ptr [esi + 0xb8], ebp
// 0050ab1d  5d                   pop ebp
// 0050ab1e  5e                   pop esi
// 0050ab1f  5f                   pop edi
// 0050ab20  5b                   pop ebx
// 0050ab21  c3                   ret 
// library libpng-1.2.7/png.c (function _png_free_data)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 png.c
