// from server: 100% by auto
// roc 2011-06 005508a0  unit: seg_00550000  size: 941 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005508a0
//
// 005508a0  53                   push ebx
// 005508a1  57                   push edi
// 005508a2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005508a6  33db                 xor ebx, ebx
// 005508a8  3bfb                 cmp edi, ebx
// 005508aa  0f849a030000         je 0x550c4a
// 005508b0  56                   push esi
// 005508b1  8b742414             mov esi, dword ptr [esp + 0x14]
// 005508b5  3bf3                 cmp esi, ebx
// 005508b7  0f848c030000         je 0x550c49
// 005508bd  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 005508c3  55                   push ebp
// 005508c4  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 005508c8  23c5                 and eax, ebp
// 005508ca  a900400000           test eax, 0x4000
// 005508cf  7461                 je 0x550932
// 005508d1  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005508d5  83f9ff               cmp ecx, -1
// 005508d8  7424                 je 0x5508fe
// 005508da  8b4638               mov eax, dword ptr [esi + 0x38]
// 005508dd  3bc3                 cmp eax, ebx
// 005508df  7451                 je 0x550932
// 005508e1  8be9                 mov ebp, ecx
// 005508e3  c1e504               shl ebp, 4
// 005508e6  8b442804             mov eax, dword ptr [eax + ebp + 4]
// 005508ea  3bc3                 cmp eax, ebx
// 005508ec  7440                 je 0x55092e
// 005508ee  50                   push eax
// 005508ef  57                   push edi
// 005508f0  e8ab0d0100           call 0x5616a0
// 005508f5  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 005508f8  895c2904             mov dword ptr [ecx + ebp + 4], ebx
// 005508fc  eb2d                 jmp 0x55092b
// 005508fe  33ed                 xor ebp, ebp
// 00550900  395e30               cmp dword ptr [esi + 0x30], ebx
// 00550903  7e16                 jle 0x55091b
// 00550905  55                   push ebp
// 00550906  6800400000           push 0x4000
// 0055090b  56                   push esi
// 0055090c  57                   push edi
// 0055090d  e88effffff           call 0x5508a0
// 00550912  45                   inc ebp
// 00550913  83c410               add esp, 0x10
// 00550916  3b6e30               cmp ebp, dword ptr [esi + 0x30]
// 00550919  7cea                 jl 0x550905
// 0055091b  8b5638               mov edx, dword ptr [esi + 0x38]
// 0055091e  52                   push edx
// 0055091f  57                   push edi
// 00550920  e87b0d0100           call 0x5616a0
// 00550925  895e38               mov dword ptr [esi + 0x38], ebx
// 00550928  895e30               mov dword ptr [esi + 0x30], ebx
// 0055092b  83c408               add esp, 8
// 0055092e  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00550932  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 00550938  23c5                 and eax, ebp
// 0055093a  a900200000           test eax, 0x2000
// 0055093f  7414                 je 0x550955
// 00550941  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 00550944  51                   push ecx
// 00550945  57                   push edi
// 00550946  e8550d0100           call 0x5616a0
// 0055094b  83c408               add esp, 8
// 0055094e  836608ef             and dword ptr [esi + 8], 0xffffffef
// 00550952  895e4c               mov dword ptr [esi + 0x4c], ebx
// 00550955  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0055095b  23c5                 and eax, ebp
// 0055095d  a900010000           test eax, 0x100
// 00550962  7407                 je 0x55096b
// 00550964  816608ffbfffff       and dword ptr [esi + 8], 0xffffbfff
// 0055096b  84c0                 test al, al
// 0055096d  0f8986000000         jns 0x5509f9
// 00550973  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 00550979  52                   push edx
// 0055097a  57                   push edi
// 0055097b  e8200d0100           call 0x5616a0
// 00550980  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 00550986  50                   push eax
// 00550987  57                   push edi
// 00550988  e8130d0100           call 0x5616a0
// 0055098d  83c410               add esp, 0x10
// 00550990  899ea0000000         mov dword ptr [esi + 0xa0], ebx
// 00550996  899eac000000         mov dword ptr [esi + 0xac], ebx
// 0055099c  399eb0000000         cmp dword ptr [esi + 0xb0], ebx
// 005509a2  744e                 je 0x5509f2
// 005509a4  33ed                 xor ebp, ebp
// 005509a6  389eb5000000         cmp byte ptr [esi + 0xb5], bl
// 005509ac  762a                 jbe 0x5509d8
// 005509ae  8bff                 mov edi, edi
// 005509b0  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 005509b6  8b14a9               mov edx, dword ptr [ecx + ebp*4]
// 005509b9  52                   push edx
// 005509ba  57                   push edi
// 005509bb  e8e00c0100           call 0x5616a0
// 005509c0  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 005509c6  891ca8               mov dword ptr [eax + ebp*4], ebx
// 005509c9  0fb68eb5000000       movzx ecx, byte ptr [esi + 0xb5]
// 005509d0  45                   inc ebp
// 005509d1  83c408               add esp, 8
// 005509d4  3be9                 cmp ebp, ecx
// 005509d6  7cd8                 jl 0x5509b0
// 005509d8  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 005509de  52                   push edx
// 005509df  57                   push edi
// 005509e0  e8bb0c0100           call 0x5616a0
// 005509e5  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 005509e9  83c408               add esp, 8
// 005509ec  899eb0000000         mov dword ptr [esi + 0xb0], ebx
// 005509f2  816608fffbffff       and dword ptr [esi + 8], 0xfffffbff
// 005509f9  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 005509ff  23c5                 and eax, ebp
// 00550a01  a810                 test al, 0x10
// 00550a03  7430                 je 0x550a35
// 00550a05  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 00550a0b  51                   push ecx
// 00550a0c  57                   push edi
// 00550a0d  e88e0c0100           call 0x5616a0
// 00550a12  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 00550a18  52                   push edx
// 00550a19  57                   push edi
// 00550a1a  e8810c0100           call 0x5616a0
// 00550a1f  83c410               add esp, 0x10
// 00550a22  816608ffefffff       and dword ptr [esi + 8], 0xffffefff
// 00550a29  899ec4000000         mov dword ptr [esi + 0xc4], ebx
// 00550a2f  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 00550a35  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 00550a3b  23c5                 and eax, ebp
// 00550a3d  a820                 test al, 0x20
// 00550a3f  0f84a0000000         je 0x550ae5
// 00550a45  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00550a49  83f9ff               cmp ecx, -1
// 00550a4c  744a                 je 0x550a98
// 00550a4e  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 00550a54  3bc3                 cmp eax, ebx
// 00550a56  0f8489000000         je 0x550ae5
// 00550a5c  8be9                 mov ebp, ecx
// 00550a5e  c1e504               shl ebp, 4
// 00550a61  8b0c28               mov ecx, dword ptr [eax + ebp]
// 00550a64  51                   push ecx
// 00550a65  57                   push edi
// 00550a66  e8350c0100           call 0x5616a0
// 00550a6b  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 00550a71  8b442a08             mov eax, dword ptr [edx + ebp + 8]
// 00550a75  50                   push eax
// 00550a76  57                   push edi
// 00550a77  e8240c0100           call 0x5616a0
// 00550a7c  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00550a82  891c29               mov dword ptr [ecx + ebp], ebx
// 00550a85  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 00550a8b  895c2a08             mov dword ptr [edx + ebp + 8], ebx
// 00550a8f  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00550a93  83c410               add esp, 0x10
// 00550a96  eb4d                 jmp 0x550ae5
// 00550a98  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00550a9e  3bc3                 cmp eax, ebx
// 00550aa0  743c                 je 0x550ade
// 00550aa2  33ed                 xor ebp, ebp
// 00550aa4  3bc3                 cmp eax, ebx
// 00550aa6  7e16                 jle 0x550abe
// 00550aa8  55                   push ebp
// 00550aa9  6a20                 push 0x20
// 00550aab  56                   push esi
// 00550aac  57                   push edi
// 00550aad  e8eefdffff           call 0x5508a0
// 00550ab2  45                   inc ebp
// 00550ab3  83c410               add esp, 0x10
// 00550ab6  3baed8000000         cmp ebp, dword ptr [esi + 0xd8]
// 00550abc  7cea                 jl 0x550aa8
// 00550abe  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 00550ac4  50                   push eax
// 00550ac5  57                   push edi
// 00550ac6  e8d50b0100           call 0x5616a0
// 00550acb  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00550acf  83c408               add esp, 8
// 00550ad2  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 00550ad8  899ed8000000         mov dword ptr [esi + 0xd8], ebx
// 00550ade  816608ffdfffff       and dword ptr [esi + 8], 0xffffdfff
// 00550ae5  8b8774020000         mov eax, dword ptr [edi + 0x274]
// 00550aeb  3bc3                 cmp eax, ebx
// 00550aed  7410                 je 0x550aff
// 00550aef  50                   push eax
// 00550af0  57                   push edi
// 00550af1  e8aa0b0100           call 0x5616a0
// 00550af6  83c408               add esp, 8
// 00550af9  899f74020000         mov dword ptr [edi + 0x274], ebx
// 00550aff  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 00550b05  23cd                 and ecx, ebp
// 00550b07  f7c100020000         test ecx, 0x200
// 00550b0d  747a                 je 0x550b89
// 00550b0f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00550b13  83f9ff               cmp ecx, -1
// 00550b16  7428                 je 0x550b40
// 00550b18  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 00550b1e  3bc3                 cmp eax, ebx
// 00550b20  7467                 je 0x550b89
// 00550b22  8d2c89               lea ebp, [ecx + ecx*4]
// 00550b25  03ed                 add ebp, ebp
// 00550b27  03ed                 add ebp, ebp
// 00550b29  8b542808             mov edx, dword ptr [eax + ebp + 8]
// 00550b2d  52                   push edx
// 00550b2e  57                   push edi
// 00550b2f  e86c0b0100           call 0x5616a0
// 00550b34  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 00550b3a  895c2808             mov dword ptr [eax + ebp + 8], ebx
// 00550b3e  eb42                 jmp 0x550b82
// 00550b40  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00550b46  3bc3                 cmp eax, ebx
// 00550b48  743f                 je 0x550b89
// 00550b4a  33ed                 xor ebp, ebp
// 00550b4c  3bc3                 cmp eax, ebx
// 00550b4e  7e19                 jle 0x550b69
// 00550b50  55                   push ebp
// 00550b51  6800020000           push 0x200
// 00550b56  56                   push esi
// 00550b57  57                   push edi
// 00550b58  e843fdffff           call 0x5508a0
// 00550b5d  45                   inc ebp
// 00550b5e  83c410               add esp, 0x10
// 00550b61  3baec0000000         cmp ebp, dword ptr [esi + 0xc0]
// 00550b67  7ce7                 jl 0x550b50
// 00550b69  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 00550b6f  51                   push ecx
// 00550b70  57                   push edi
// 00550b71  e82a0b0100           call 0x5616a0
// 00550b76  899ebc000000         mov dword ptr [esi + 0xbc], ebx
// 00550b7c  899ec0000000         mov dword ptr [esi + 0xc0], ebx
// 00550b82  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00550b86  83c408               add esp, 8
// 00550b89  8b96b8000000         mov edx, dword ptr [esi + 0xb8]
// 00550b8f  23d5                 and edx, ebp
// 00550b91  f6c208               test dl, 8
// 00550b94  7414                 je 0x550baa
// 00550b96  8b467c               mov eax, dword ptr [esi + 0x7c]
// 00550b99  50                   push eax
// 00550b9a  57                   push edi
// 00550b9b  e8000b0100           call 0x5616a0
// 00550ba0  83c408               add esp, 8
// 00550ba3  836608bf             and dword ptr [esi + 8], 0xffffffbf
// 00550ba7  895e7c               mov dword ptr [esi + 0x7c], ebx
// 00550baa  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 00550bb0  23cd                 and ecx, ebp
// 00550bb2  f7c100100000         test ecx, 0x1000
// 00550bb8  741a                 je 0x550bd4
// 00550bba  8b5610               mov edx, dword ptr [esi + 0x10]
// 00550bbd  52                   push edx
// 00550bbe  57                   push edi
// 00550bbf  e8dc0a0100           call 0x5616a0
// 00550bc4  836608f7             and dword ptr [esi + 8], 0xfffffff7
// 00550bc8  83c408               add esp, 8
// 00550bcb  33c0                 xor eax, eax
// 00550bcd  895e10               mov dword ptr [esi + 0x10], ebx
// 00550bd0  66894614             mov word ptr [esi + 0x14], ax
// 00550bd4  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 00550bda  23cd                 and ecx, ebp
// 00550bdc  f6c140               test cl, 0x40
// 00550bdf  7452                 je 0x550c33
// 00550be1  399ef8000000         cmp dword ptr [esi + 0xf8], ebx
// 00550be7  7443                 je 0x550c2c
// 00550be9  33ed                 xor ebp, ebp
// 00550beb  395e04               cmp dword ptr [esi + 4], ebx
// 00550bee  7e22                 jle 0x550c12
// 00550bf0  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 00550bf6  8b04aa               mov eax, dword ptr [edx + ebp*4]
// 00550bf9  50                   push eax
// 00550bfa  57                   push edi
// 00550bfb  e8a00a0100           call 0x5616a0
// 00550c00  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 00550c06  891ca9               mov dword ptr [ecx + ebp*4], ebx
// 00550c09  45                   inc ebp
// 00550c0a  83c408               add esp, 8
// 00550c0d  3b6e04               cmp ebp, dword ptr [esi + 4]
// 00550c10  7cde                 jl 0x550bf0
// 00550c12  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 00550c18  52                   push edx
// 00550c19  57                   push edi
// 00550c1a  e8810a0100           call 0x5616a0
// 00550c1f  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00550c23  83c408               add esp, 8
// 00550c26  899ef8000000         mov dword ptr [esi + 0xf8], ebx
// 00550c2c  816608ff7fffff       and dword ptr [esi + 8], 0xffff7fff
// 00550c33  837c2420ff           cmp dword ptr [esp + 0x20], -1
// 00550c38  7406                 je 0x550c40
// 00550c3a  81e5dfbdffff         and ebp, 0xffffbddf
// 00550c40  f7d5                 not ebp
// 00550c42  21aeb8000000         and dword ptr [esi + 0xb8], ebp
// 00550c48  5d                   pop ebp
// 00550c49  5e                   pop esi
// 00550c4a  5f                   pop edi
// 00550c4b  5b                   pop ebx
// 00550c4c  c3                   ret 
// library libpng-1.2.22/png.c (function _png_free_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 png.c
