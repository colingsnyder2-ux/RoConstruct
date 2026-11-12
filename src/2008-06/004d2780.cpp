// from server: 100% by auto
// roc 2008-06 004d2780  unit: seg_004d0000  size: 1254 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d2780
//
// 004d2780  6aff                 push -1
// 004d2782  64a100000000         mov eax, dword ptr fs:[0]
// 004d2788  68a89a7c00           push 0x7c9aa8
// 004d278d  50                   push eax
// 004d278e  64892500000000       mov dword ptr fs:[0], esp
// 004d2795  83ec08               sub esp, 8
// 004d2798  53                   push ebx
// 004d2799  55                   push ebp
// 004d279a  56                   push esi
// 004d279b  8bf1                 mov esi, ecx
// 004d279d  8b86a8000000         mov eax, dword ptr [esi + 0xa8]
// 004d27a3  57                   push edi
// 004d27a4  33ed                 xor ebp, ebp
// 004d27a6  33ff                 xor edi, edi
// 004d27a8  3bc5                 cmp eax, ebp
// 004d27aa  7665                 jbe 0x4d2811
// 004d27ac  8d642400             lea esp, [esp]
// 004d27b0  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 004d27b6  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 004d27b9  33db                 xor ebx, ebx
// 004d27bb  39690c               cmp dword ptr [ecx + 0xc], ebp
// 004d27be  762a                 jbe 0x4d27ea
// 004d27c0  8b96a4000000         mov edx, dword ptr [esi + 0xa4]
// 004d27c6  8b04ba               mov eax, dword ptr [edx + edi*4]
// 004d27c9  8b4808               mov ecx, dword ptr [eax + 8]
// 004d27cc  8b1499               mov edx, dword ptr [ecx + ebx*4]
// 004d27cf  8b423c               mov eax, dword ptr [edx + 0x3c]
// 004d27d2  50                   push eax
// 004d27d3  e8a2de1c00           call 0x6a067a
// 004d27d8  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 004d27de  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 004d27e1  43                   inc ebx
// 004d27e2  83c404               add esp, 4
// 004d27e5  3b590c               cmp ebx, dword ptr [ecx + 0xc]
// 004d27e8  72d6                 jb 0x4d27c0
// 004d27ea  8b96a4000000         mov edx, dword ptr [esi + 0xa4]
// 004d27f0  8b1cba               mov ebx, dword ptr [edx + edi*4]
// 004d27f3  3bdd                 cmp ebx, ebp
// 004d27f5  7411                 je 0x4d2808
// 004d27f7  8d4b08               lea ecx, [ebx + 8]
// 004d27fa  e8017cfeff           call 0x4ba400
// 004d27ff  53                   push ebx
// 004d2800  e875de1c00           call 0x6a067a
// 004d2805  83c404               add esp, 4
// 004d2808  47                   inc edi
// 004d2809  3bbea8000000         cmp edi, dword ptr [esi + 0xa8]
// 004d280f  729f                 jb 0x4d27b0
// 004d2811  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 004d2817  3bc5                 cmp eax, ebp
// 004d2819  7428                 je 0x4d2843
// 004d281b  3d00020000           cmp eax, 0x200
// 004d2820  761b                 jbe 0x4d283d
// 004d2822  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 004d2828  50                   push eax
// 004d2829  e84cde1c00           call 0x6a067a
// 004d282e  83c404               add esp, 4
// 004d2831  89aeac000000         mov dword ptr [esi + 0xac], ebp
// 004d2837  89aea4000000         mov dword ptr [esi + 0xa4], ebp
// 004d283d  89aea8000000         mov dword ptr [esi + 0xa8], ebp
// 004d2843  8b5610               mov edx, dword ptr [esi + 0x10]
// 004d2846  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004d2849  3bd1                 cmp edx, ecx
// 004d284b  7706                 ja 0x4d2853
// 004d284d  2bca                 sub ecx, edx
// 004d284f  8bc1                 mov eax, ecx
// 004d2851  eb07                 jmp 0x4d285a
// 004d2853  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d2856  2bc2                 sub eax, edx
// 004d2858  03c1                 add eax, ecx
// 004d285a  3bc5                 cmp eax, ebp
// 004d285c  7641                 jbe 0x4d289f
// 004d285e  ff4610               inc dword ptr [esi + 0x10]
// 004d2861  8b4610               mov eax, dword ptr [esi + 0x10]
// 004d2864  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004d2867  3bc1                 cmp eax, ecx
// 004d2869  7503                 jne 0x4d286e
// 004d286b  896e10               mov dword ptr [esi + 0x10], ebp
// 004d286e  8b4610               mov eax, dword ptr [esi + 0x10]
// 004d2871  3bc5                 cmp eax, ebp
// 004d2873  7515                 jne 0x4d288a
// 004d2875  8b460c               mov eax, dword ptr [esi + 0xc]
// 004d2878  8b4488fc             mov eax, dword ptr [eax + ecx*4 - 4]
// 004d287c  8b503c               mov edx, dword ptr [eax + 0x3c]
// 004d287f  52                   push edx
// 004d2880  e8f5dd1c00           call 0x6a067a
// 004d2885  83c404               add esp, 4
// 004d2888  ebb9                 jmp 0x4d2843
// 004d288a  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004d288d  8b4481fc             mov eax, dword ptr [ecx + eax*4 - 4]
// 004d2891  8b503c               mov edx, dword ptr [eax + 0x3c]
// 004d2894  52                   push edx
// 004d2895  e8e0dd1c00           call 0x6a067a
// 004d289a  83c404               add esp, 4
// 004d289d  eba4                 jmp 0x4d2843
// 004d289f  8b460c               mov eax, dword ptr [esi + 0xc]
// 004d28a2  50                   push eax
// 004d28a3  e8d2dd1c00           call 0x6a067a
// 004d28a8  33c9                 xor ecx, ecx
// 004d28aa  b820000000           mov eax, 0x20
// 004d28af  ba04000000           mov edx, 4
// 004d28b4  f7e2                 mul edx
// 004d28b6  0f90c1               seto cl
// 004d28b9  f7d9                 neg ecx
// 004d28bb  0bc8                 or ecx, eax
// 004d28bd  51                   push ecx
// 004d28be  e85de01c00           call 0x6a0920
// 004d28c3  33ff                 xor edi, edi
// 004d28c5  33ed                 xor ebp, ebp
// 004d28c7  83c408               add esp, 8
// 004d28ca  89460c               mov dword ptr [esi + 0xc], eax
// 004d28cd  c7461820000000       mov dword ptr [esi + 0x18], 0x20
// 004d28d4  897e10               mov dword ptr [esi + 0x10], edi
// 004d28d7  897e14               mov dword ptr [esi + 0x14], edi
// 004d28da  896c2410             mov dword ptr [esp + 0x10], ebp
// 004d28de  397e04               cmp dword ptr [esi + 4], edi
// 004d28e1  0f8650010000         jbe 0x4d2a37
// 004d28e7  8b06                 mov eax, dword ptr [esi]
// 004d28e9  393ca8               cmp dword ptr [eax + ebp*4], edi
// 004d28ec  8d04a8               lea eax, [eax + ebp*4]
// 004d28ef  0f8434010000         je 0x4d2a29
// 004d28f5  8b18                 mov ebx, dword ptr [eax]
// 004d28f7  3bdf                 cmp ebx, edi
// 004d28f9  0f842a010000         je 0x4d2a29
// 004d28ff  393b                 cmp dword ptr [ebx], edi
// 004d2901  0f8491000000         je 0x4d2998
// 004d2907  eb07                 jmp 0x4d2910
// 004d2909  8da42400000000       lea esp, [esp]
// 004d2910  8b06                 mov eax, dword ptr [esi]
// 004d2912  8d0cad00000000       lea ecx, [ebp*4]
// 004d2919  8b3c08               mov edi, dword ptr [eax + ecx]
// 004d291c  03c1                 add eax, ecx
// 004d291e  8b4708               mov eax, dword ptr [edi + 8]
// 004d2921  8b08                 mov ecx, dword ptr [eax]
// 004d2923  894c2414             mov dword ptr [esp + 0x14], ecx
// 004d2927  8b0f                 mov ecx, dword ptr [edi]
// 004d2929  85c9                 test ecx, ecx
// 004d292b  7452                 je 0x4d297f
// 004d292d  83f901               cmp ecx, 1
// 004d2930  7518                 jne 0x4d294a
// 004d2932  8b4704               mov eax, dword ptr [edi + 4]
// 004d2935  50                   push eax
// 004d2936  e83fdd1c00           call 0x6a067a
// 004d293b  83c404               add esp, 4
// 004d293e  33c0                 xor eax, eax
// 004d2940  894708               mov dword ptr [edi + 8], eax
// 004d2943  894704               mov dword ptr [edi + 4], eax
// 004d2946  8907                 mov dword ptr [edi], eax
// 004d2948  eb35                 jmp 0x4d297f
// 004d294a  8b5004               mov edx, dword ptr [eax + 4]
// 004d294d  8b4008               mov eax, dword ptr [eax + 8]
// 004d2950  894208               mov dword ptr [edx + 8], eax
// 004d2953  8b4708               mov eax, dword ptr [edi + 8]
// 004d2956  8b4808               mov ecx, dword ptr [eax + 8]
// 004d2959  8b5004               mov edx, dword ptr [eax + 4]
// 004d295c  895104               mov dword ptr [ecx + 4], edx
// 004d295f  8b4708               mov eax, dword ptr [edi + 8]
// 004d2962  8b6808               mov ebp, dword ptr [eax + 8]
// 004d2965  3b4704               cmp eax, dword ptr [edi + 4]
// 004d2968  7503                 jne 0x4d296d
// 004d296a  896f04               mov dword ptr [edi + 4], ebp
// 004d296d  50                   push eax
// 004d296e  e807dd1c00           call 0x6a067a
// 004d2973  83c404               add esp, 4
// 004d2976  ff0f                 dec dword ptr [edi]
// 004d2978  896f08               mov dword ptr [edi + 8], ebp
// 004d297b  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 004d297f  8b442414             mov eax, dword ptr [esp + 0x14]
// 004d2983  8b403c               mov eax, dword ptr [eax + 0x3c]
// 004d2986  50                   push eax
// 004d2987  e8eedc1c00           call 0x6a067a
// 004d298c  83c404               add esp, 4
// 004d298f  833b00               cmp dword ptr [ebx], 0
// 004d2992  0f8578ffffff         jne 0x4d2910
// 004d2998  895c2414             mov dword ptr [esp + 0x14], ebx
// 004d299c  8b03                 mov eax, dword ptr [ebx]
// 004d299e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004d29a6  85c0                 test eax, eax
// 004d29a8  7433                 je 0x4d29dd
// 004d29aa  83f801               cmp eax, 1
// 004d29ad  750e                 jne 0x4d29bd
// 004d29af  8b4304               mov eax, dword ptr [ebx + 4]
// 004d29b2  50                   push eax
// 004d29b3  e8c2dc1c00           call 0x6a067a
// 004d29b8  83c404               add esp, 4
// 004d29bb  eb16                 jmp 0x4d29d3
// 004d29bd  8b7b04               mov edi, dword ptr [ebx + 4]
// 004d29c0  8bc7                 mov eax, edi
// 004d29c2  8b7f08               mov edi, dword ptr [edi + 8]
// 004d29c5  50                   push eax
// 004d29c6  e8afdc1c00           call 0x6a067a
// 004d29cb  83c404               add esp, 4
// 004d29ce  3b7b04               cmp edi, dword ptr [ebx + 4]
// 004d29d1  75ed                 jne 0x4d29c0
// 004d29d3  33c0                 xor eax, eax
// 004d29d5  8903                 mov dword ptr [ebx], eax
// 004d29d7  894304               mov dword ptr [ebx + 4], eax
// 004d29da  894308               mov dword ptr [ebx + 8], eax
// 004d29dd  8b03                 mov eax, dword ptr [ebx]
// 004d29df  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004d29e7  85c0                 test eax, eax
// 004d29e9  7433                 je 0x4d2a1e
// 004d29eb  83f801               cmp eax, 1
// 004d29ee  750e                 jne 0x4d29fe
// 004d29f0  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004d29f3  51                   push ecx
// 004d29f4  e881dc1c00           call 0x6a067a
// 004d29f9  83c404               add esp, 4
// 004d29fc  eb16                 jmp 0x4d2a14
// 004d29fe  8b7b04               mov edi, dword ptr [ebx + 4]
// 004d2a01  8bc7                 mov eax, edi
// 004d2a03  8b7f08               mov edi, dword ptr [edi + 8]
// 004d2a06  50                   push eax
// 004d2a07  e86edc1c00           call 0x6a067a
// 004d2a0c  83c404               add esp, 4
// 004d2a0f  3b7b04               cmp edi, dword ptr [ebx + 4]
// 004d2a12  75ed                 jne 0x4d2a01
// 004d2a14  33c0                 xor eax, eax
// 004d2a16  8903                 mov dword ptr [ebx], eax
// 004d2a18  894304               mov dword ptr [ebx + 4], eax
// 004d2a1b  894308               mov dword ptr [ebx + 8], eax
// 004d2a1e  53                   push ebx
// 004d2a1f  e856dc1c00           call 0x6a067a
// 004d2a24  83c404               add esp, 4
// 004d2a27  33ff                 xor edi, edi
// 004d2a29  45                   inc ebp
// 004d2a2a  896c2410             mov dword ptr [esp + 0x10], ebp
// 004d2a2e  3b6e04               cmp ebp, dword ptr [esi + 4]
// 004d2a31  0f82b0feffff         jb 0x4d28e7
// 004d2a37  8b4608               mov eax, dword ptr [esi + 8]
// 004d2a3a  3bc7                 cmp eax, edi
// 004d2a3c  741a                 je 0x4d2a58
// 004d2a3e  3d00020000           cmp eax, 0x200
// 004d2a43  7610                 jbe 0x4d2a55
// 004d2a45  8b16                 mov edx, dword ptr [esi]
// 004d2a47  52                   push edx
// 004d2a48  e82ddc1c00           call 0x6a067a
// 004d2a4d  83c404               add esp, 4
// 004d2a50  897e08               mov dword ptr [esi + 8], edi
// 004d2a53  893e                 mov dword ptr [esi], edi
// 004d2a55  897e04               mov dword ptr [esi + 4], edi
// 004d2a58  8d7e38               lea edi, [esi + 0x38]
// 004d2a5b  33ed                 xor ebp, ebp
// 004d2a5d  396f14               cmp dword ptr [edi + 0x14], ebp
// 004d2a60  740d                 je 0x4d2a6f
// 004d2a62  8bcf                 mov ecx, edi
// 004d2a64  e8c7e1ffff           call 0x4d0c30
// 004d2a69  896f18               mov dword ptr [edi + 0x18], ebp
// 004d2a6c  896f14               mov dword ptr [edi + 0x14], ebp
// 004d2a6f  8bcf                 mov ecx, edi
// 004d2a71  e86ac8ffff           call 0x4cf2e0
// 004d2a76  bf01000000           mov edi, 1
// 004d2a7b  eb03                 jmp 0x4d2a80
// 004d2a7d  8d4900               lea ecx, [ecx]
// 004d2a80  8b5658               mov edx, dword ptr [esi + 0x58]
// 004d2a83  8b4e5c               mov ecx, dword ptr [esi + 0x5c]
// 004d2a86  3bd1                 cmp edx, ecx
// 004d2a88  7706                 ja 0x4d2a90
// 004d2a8a  2bca                 sub ecx, edx
// 004d2a8c  8bc1                 mov eax, ecx
// 004d2a8e  eb07                 jmp 0x4d2a97
// 004d2a90  8b4660               mov eax, dword ptr [esi + 0x60]
// 004d2a93  2bc2                 sub eax, edx
// 004d2a95  03c1                 add eax, ecx
// 004d2a97  3bc5                 cmp eax, ebp
// 004d2a99  7439                 je 0x4d2ad4
// 004d2a9b  017e58               add dword ptr [esi + 0x58], edi
// 004d2a9e  8b4658               mov eax, dword ptr [esi + 0x58]
// 004d2aa1  8b4e60               mov ecx, dword ptr [esi + 0x60]
// 004d2aa4  3bc1                 cmp eax, ecx
// 004d2aa6  7503                 jne 0x4d2aab
// 004d2aa8  896e58               mov dword ptr [esi + 0x58], ebp
// 004d2aab  8b4658               mov eax, dword ptr [esi + 0x58]
// 004d2aae  3bc5                 cmp eax, ebp
// 004d2ab0  7509                 jne 0x4d2abb
// 004d2ab2  8b4654               mov eax, dword ptr [esi + 0x54]
// 004d2ab5  8b4488fc             mov eax, dword ptr [eax + ecx*4 - 4]
// 004d2ab9  eb07                 jmp 0x4d2ac2
// 004d2abb  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004d2abe  8b4481fc             mov eax, dword ptr [ecx + eax*4 - 4]
// 004d2ac2  3bc5                 cmp eax, ebp
// 004d2ac4  74ba                 je 0x4d2a80
// 004d2ac6  8b503c               mov edx, dword ptr [eax + 0x3c]
// 004d2ac9  52                   push edx
// 004d2aca  e8abdb1c00           call 0x6a067a
// 004d2acf  83c404               add esp, 4
// 004d2ad2  ebac                 jmp 0x4d2a80
// 004d2ad4  8b4654               mov eax, dword ptr [esi + 0x54]
// 004d2ad7  50                   push eax
// 004d2ad8  e89ddb1c00           call 0x6a067a
// 004d2add  33c9                 xor ecx, ecx
// 004d2adf  b800020000           mov eax, 0x200
// 004d2ae4  ba04000000           mov edx, 4
// 004d2ae9  f7e2                 mul edx
// 004d2aeb  0f90c1               seto cl
// 004d2aee  f7d9                 neg ecx
// 004d2af0  0bc8                 or ecx, eax
// 004d2af2  51                   push ecx
// 004d2af3  e828de1c00           call 0x6a0920
// 004d2af8  896e58               mov dword ptr [esi + 0x58], ebp
// 004d2afb  896e5c               mov dword ptr [esi + 0x5c], ebp
// 004d2afe  83c408               add esp, 8
// 004d2b01  894654               mov dword ptr [esi + 0x54], eax
// 004d2b04  c7466000020000       mov dword ptr [esi + 0x60], 0x200
// 004d2b0b  8d7e64               lea edi, [esi + 0x64]
// 004d2b0e  bd04000000           mov ebp, 4
// 004d2b13  33db                 xor ebx, ebx
// 004d2b15  8b4704               mov eax, dword ptr [edi + 4]
// 004d2b18  8b5708               mov edx, dword ptr [edi + 8]
// 004d2b1b  3bc2                 cmp eax, edx
// 004d2b1d  7706                 ja 0x4d2b25
// 004d2b1f  2bd0                 sub edx, eax
// 004d2b21  8bca                 mov ecx, edx
// 004d2b23  eb07                 jmp 0x4d2b2c
// 004d2b25  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004d2b28  2bc8                 sub ecx, eax
// 004d2b2a  03ca                 add ecx, edx
// 004d2b2c  3bd9                 cmp ebx, ecx
// 004d2b2e  733b                 jae 0x4d2b6b
// 004d2b30  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004d2b33  8d1418               lea edx, [eax + ebx]
// 004d2b36  3bd1                 cmp edx, ecx
// 004d2b38  721a                 jb 0x4d2b54
// 004d2b3a  2bc1                 sub eax, ecx
// 004d2b3c  8b0f                 mov ecx, dword ptr [edi]
// 004d2b3e  03c3                 add eax, ebx
// 004d2b40  8d0481               lea eax, [ecx + eax*4]
// 004d2b43  8b08                 mov ecx, dword ptr [eax]
// 004d2b45  8b513c               mov edx, dword ptr [ecx + 0x3c]
// 004d2b48  52                   push edx
// 004d2b49  e82cdb1c00           call 0x6a067a
// 004d2b4e  83c404               add esp, 4
// 004d2b51  43                   inc ebx
// 004d2b52  ebc1                 jmp 0x4d2b15
// 004d2b54  8b07                 mov eax, dword ptr [edi]
// 004d2b56  8b0c90               mov ecx, dword ptr [eax + edx*4]
// 004d2b59  8d0490               lea eax, [eax + edx*4]
// 004d2b5c  8b513c               mov edx, dword ptr [ecx + 0x3c]
// 004d2b5f  52                   push edx
// 004d2b60  e815db1c00           call 0x6a067a
// 004d2b65  83c404               add esp, 4
// 004d2b68  43                   inc ebx
// 004d2b69  ebaa                 jmp 0x4d2b15
// 004d2b6b  8b07                 mov eax, dword ptr [edi]
// 004d2b6d  50                   push eax
// 004d2b6e  e807db1c00           call 0x6a067a
// 004d2b73  33c9                 xor ecx, ecx
// 004d2b75  b820000000           mov eax, 0x20
// 004d2b7a  ba04000000           mov edx, 4
// 004d2b7f  f7e2                 mul edx
// 004d2b81  0f90c1               seto cl
// 004d2b84  f7d9                 neg ecx
// 004d2b86  0bc8                 or ecx, eax
// 004d2b88  51                   push ecx
// 004d2b89  e892dd1c00           call 0x6a0920
// 004d2b8e  33db                 xor ebx, ebx
// 004d2b90  8907                 mov dword ptr [edi], eax
// 004d2b92  c7470c20000000       mov dword ptr [edi + 0xc], 0x20
// 004d2b99  895f04               mov dword ptr [edi + 4], ebx
// 004d2b9c  895f08               mov dword ptr [edi + 8], ebx
// 004d2b9f  83c408               add esp, 8
// 004d2ba2  83c710               add edi, 0x10
// 004d2ba5  83ed01               sub ebp, 1
// 004d2ba8  0f8565ffffff         jne 0x4d2b13
// 004d2bae  33ff                 xor edi, edi
// 004d2bb0  399e94070000         cmp dword ptr [esi + 0x794], ebx
// 004d2bb6  7623                 jbe 0x4d2bdb
// 004d2bb8  eb06                 jmp 0x4d2bc0
// 004d2bba  8d9b00000000         lea ebx, [ebx]
// 004d2bc0  8b8690070000         mov eax, dword ptr [esi + 0x790]
// 004d2bc6  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 004d2bc9  51                   push ecx
// 004d2bca  e8abda1c00           call 0x6a067a
// 004d2bcf  47                   inc edi
// 004d2bd0  83c404               add esp, 4
// 004d2bd3  3bbe94070000         cmp edi, dword ptr [esi + 0x794]
// 004d2bd9  72e5                 jb 0x4d2bc0
// 004d2bdb  8b8698070000         mov eax, dword ptr [esi + 0x798]
// 004d2be1  3bc3                 cmp eax, ebx
// 004d2be3  7428                 je 0x4d2c0d
// 004d2be5  3d00020000           cmp eax, 0x200
// 004d2bea  761b                 jbe 0x4d2c07
// 004d2bec  8b9690070000         mov edx, dword ptr [esi + 0x790]
// 004d2bf2  52                   push edx
// 004d2bf3  e882da1c00           call 0x6a067a
// 004d2bf8  83c404               add esp, 4
// 004d2bfb  899e98070000         mov dword ptr [esi + 0x798], ebx
// 004d2c01  899e90070000         mov dword ptr [esi + 0x790], ebx
// 004d2c07  899e94070000         mov dword ptr [esi + 0x794], ebx
// 004d2c0d  8d8eb0070000         lea ecx, [esi + 0x7b0]
// 004d2c13  e8c8c6ffff           call 0x4cf2e0
// 004d2c18  8b4624               mov eax, dword ptr [esi + 0x24]
// 004d2c1b  3bc3                 cmp eax, ebx
// 004d2c1d  7434                 je 0x4d2c53
// 004d2c1f  3d00020000           cmp eax, 0x200
// 004d2c24  762a                 jbe 0x4d2c50
// 004d2c26  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004d2c29  3bc3                 cmp eax, ebx
// 004d2c2b  741d                 je 0x4d2c4a
// 004d2c2d  8b48fc               mov ecx, dword ptr [eax - 4]
// 004d2c30  8d78fc               lea edi, [eax - 4]
// 004d2c33  6810d44700           push 0x47d410
// 004d2c38  51                   push ecx
// 004d2c39  6a08                 push 8
// 004d2c3b  50                   push eax
// 004d2c3c  e81aea1c00           call 0x6a165b
// 004d2c41  57                   push edi
// 004d2c42  e833da1c00           call 0x6a067a
// 004d2c47  83c404               add esp, 4
// 004d2c4a  895e24               mov dword ptr [esi + 0x24], ebx
// 004d2c4d  895e1c               mov dword ptr [esi + 0x1c], ebx
// 004d2c50  895e20               mov dword ptr [esi + 0x20], ebx
// 004d2c53  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004d2c57  5f                   pop edi
// 004d2c58  5e                   pop esi
// 004d2c59  5d                   pop ebp
// 004d2c5a  5b                   pop ebx
// 004d2c5b  64890d00000000       mov dword ptr fs:[0], ecx
// 004d2c62  83c414               add esp, 0x14
// 004d2c65  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ?FreeThreadSafeMemory@ReliabilityLayer@@AAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
