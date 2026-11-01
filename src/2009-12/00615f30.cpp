// from server: 100% by auto
// roc 2009-12 00615f30  unit: seg_00610000  size: 745 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00615f30
//
// 00615f30  83ec10               sub esp, 0x10
// 00615f33  817c241cff000000     cmp dword ptr [esp + 0x1c], 0xff
// 00615f3b  7544                 jne 0x615f81
// 00615f3d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00615f41  8a810b010000         mov al, byte ptr [ecx + 0x10b]
// 00615f47  3c08                 cmp al, 8
// 00615f49  0fb6c0               movzx eax, al
// 00615f4c  720c                 jb 0x615f5a
// 00615f4e  c1e803               shr eax, 3
// 00615f51  0faf81c8000000       imul eax, dword ptr [ecx + 0xc8]
// 00615f58  eb0d                 jmp 0x615f67
// 00615f5a  0faf81c8000000       imul eax, dword ptr [ecx + 0xc8]
// 00615f61  83c007               add eax, 7
// 00615f64  c1e803               shr eax, 3
// 00615f67  50                   push eax
// 00615f68  8b81ec000000         mov eax, dword ptr [ecx + 0xec]
// 00615f6e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00615f72  40                   inc eax
// 00615f73  50                   push eax
// 00615f74  51                   push ecx
// 00615f75  e86ced1d00           call 0x7f4ce6
// 00615f7a  83c40c               add esp, 0xc
// 00615f7d  83c410               add esp, 0x10
// 00615f80  c3                   ret 
// 00615f81  8b442414             mov eax, dword ptr [esp + 0x14]
// 00615f85  0fb6880b010000       movzx ecx, byte ptr [eax + 0x10b]
// 00615f8c  53                   push ebx
// 00615f8d  55                   push ebp
// 00615f8e  56                   push esi
// 00615f8f  8bb0ec000000         mov esi, dword ptr [eax + 0xec]
// 00615f95  8bd1                 mov edx, ecx
// 00615f97  46                   inc esi
// 00615f98  83ea01               sub edx, 1
// 00615f9b  57                   push edi
// 00615f9c  0f84c6010000         je 0x616168
// 00615fa2  83ea01               sub edx, 1
// 00615fa5  0f8408010000         je 0x6160b3
// 00615fab  83ea02               sub edx, 2
// 00615fae  7451                 je 0x616001
// 00615fb0  8b80c8000000         mov eax, dword ptr [eax + 0xc8]
// 00615fb6  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00615fba  c1e903               shr ecx, 3
// 00615fbd  8bf9                 mov edi, ecx
// 00615fbf  b380                 mov bl, 0x80
// 00615fc1  85c0                 test eax, eax
// 00615fc3  0f8648020000         jbe 0x616211
// 00615fc9  89442410             mov dword ptr [esp + 0x10], eax
// 00615fcd  8d4900               lea ecx, [ecx]
// 00615fd0  8a54242c             mov dl, byte ptr [esp + 0x2c]
// 00615fd4  84da                 test dl, bl
// 00615fd6  740b                 je 0x615fe3
// 00615fd8  57                   push edi
// 00615fd9  56                   push esi
// 00615fda  55                   push ebp
// 00615fdb  e806ed1d00           call 0x7f4ce6
// 00615fe0  83c40c               add esp, 0xc
// 00615fe3  03f7                 add esi, edi
// 00615fe5  03ef                 add ebp, edi
// 00615fe7  80fb01               cmp bl, 1
// 00615fea  7504                 jne 0x615ff0
// 00615fec  b380                 mov bl, 0x80
// 00615fee  eb02                 jmp 0x615ff2
// 00615ff0  d0eb                 shr bl, 1
// 00615ff2  836c241001           sub dword ptr [esp + 0x10], 1
// 00615ff7  75d7                 jne 0x615fd0
// 00615ff9  5f                   pop edi
// 00615ffa  5e                   pop esi
// 00615ffb  5d                   pop ebp
// 00615ffc  5b                   pop ebx
// 00615ffd  83c410               add esp, 0x10
// 00616000  c3                   ret 
// 00616001  f7407000000100       test dword ptr [eax + 0x70], 0x10000
// 00616008  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0061600c  8b88c8000000         mov ecx, dword ptr [eax + 0xc8]
// 00616012  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 0061601a  7411                 je 0x61602d
// 0061601c  b804000000           mov eax, 4
// 00616021  33ed                 xor ebp, ebp
// 00616023  89442414             mov dword ptr [esp + 0x14], eax
// 00616027  89442418             mov dword ptr [esp + 0x18], eax
// 0061602b  eb15                 jmp 0x616042
// 0061602d  bd04000000           mov ebp, 4
// 00616032  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0061603a  c7442418fcffffff     mov dword ptr [esp + 0x18], 0xfffffffc
// 00616042  8bd5                 mov edx, ebp
// 00616044  85c9                 test ecx, ecx
// 00616046  0f86c5010000         jbe 0x616211
// 0061604c  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00616050  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00616054  85442410             test dword ptr [esp + 0x10], eax
// 00616058  7422                 je 0x61607c
// 0061605a  0fb606               movzx eax, byte ptr [esi]
// 0061605d  8aca                 mov cl, dl
// 0061605f  d3e8                 shr eax, cl
// 00616061  b904000000           mov ecx, 4
// 00616066  2bca                 sub ecx, edx
// 00616068  bb0f0f0000           mov ebx, 0xf0f
// 0061606d  d3fb                 sar ebx, cl
// 0061606f  83e00f               and eax, 0xf
// 00616072  8bca                 mov ecx, edx
// 00616074  d2e0                 shl al, cl
// 00616076  221f                 and bl, byte ptr [edi]
// 00616078  0ad8                 or bl, al
// 0061607a  881f                 mov byte ptr [edi], bl
// 0061607c  3b542414             cmp edx, dword ptr [esp + 0x14]
// 00616080  7506                 jne 0x616088
// 00616082  46                   inc esi
// 00616083  8bd5                 mov edx, ebp
// 00616085  47                   inc edi
// 00616086  eb04                 jmp 0x61608c
// 00616088  03542418             add edx, dword ptr [esp + 0x18]
// 0061608c  b801000000           mov eax, 1
// 00616091  39442410             cmp dword ptr [esp + 0x10], eax
// 00616095  750a                 jne 0x6160a1
// 00616097  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 0061609f  eb04                 jmp 0x6160a5
// 006160a1  d17c2410             sar dword ptr [esp + 0x10], 1
// 006160a5  2944241c             sub dword ptr [esp + 0x1c], eax
// 006160a9  75a5                 jne 0x616050
// 006160ab  5f                   pop edi
// 006160ac  5e                   pop esi
// 006160ad  5d                   pop ebp
// 006160ae  5b                   pop ebx
// 006160af  83c410               add esp, 0x10
// 006160b2  c3                   ret 
// 006160b3  f7407000000100       test dword ptr [eax + 0x70], 0x10000
// 006160ba  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006160be  8b88c8000000         mov ecx, dword ptr [eax + 0xc8]
// 006160c4  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 006160cc  7414                 je 0x6160e2
// 006160ce  33ed                 xor ebp, ebp
// 006160d0  c744241c06000000     mov dword ptr [esp + 0x1c], 6
// 006160d8  c744241802000000     mov dword ptr [esp + 0x18], 2
// 006160e0  eb15                 jmp 0x6160f7
// 006160e2  bd06000000           mov ebp, 6
// 006160e7  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006160ef  c7442418feffffff     mov dword ptr [esp + 0x18], 0xfffffffe
// 006160f7  8bd5                 mov edx, ebp
// 006160f9  85c9                 test ecx, ecx
// 006160fb  0f8610010000         jbe 0x616211
// 00616101  894c2414             mov dword ptr [esp + 0x14], ecx
// 00616105  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00616109  854c2410             test dword ptr [esp + 0x10], ecx
// 0061610d  7422                 je 0x616131
// 0061610f  0fb606               movzx eax, byte ptr [esi]
// 00616112  8aca                 mov cl, dl
// 00616114  d3e8                 shr eax, cl
// 00616116  b906000000           mov ecx, 6
// 0061611b  2bca                 sub ecx, edx
// 0061611d  bb3f3f0000           mov ebx, 0x3f3f
// 00616122  d3fb                 sar ebx, cl
// 00616124  83e003               and eax, 3
// 00616127  8bca                 mov ecx, edx
// 00616129  d2e0                 shl al, cl
// 0061612b  221f                 and bl, byte ptr [edi]
// 0061612d  0ad8                 or bl, al
// 0061612f  881f                 mov byte ptr [edi], bl
// 00616131  3b54241c             cmp edx, dword ptr [esp + 0x1c]
// 00616135  7506                 jne 0x61613d
// 00616137  46                   inc esi
// 00616138  8bd5                 mov edx, ebp
// 0061613a  47                   inc edi
// 0061613b  eb04                 jmp 0x616141
// 0061613d  03542418             add edx, dword ptr [esp + 0x18]
// 00616141  b801000000           mov eax, 1
// 00616146  39442410             cmp dword ptr [esp + 0x10], eax
// 0061614a  750a                 jne 0x616156
// 0061614c  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 00616154  eb04                 jmp 0x61615a
// 00616156  d17c2410             sar dword ptr [esp + 0x10], 1
// 0061615a  29442414             sub dword ptr [esp + 0x14], eax
// 0061615e  75a5                 jne 0x616105
// 00616160  5f                   pop edi
// 00616161  5e                   pop esi
// 00616162  5d                   pop ebp
// 00616163  5b                   pop ebx
// 00616164  83c410               add esp, 0x10
// 00616167  c3                   ret 
// 00616168  f7407000000100       test dword ptr [eax + 0x70], 0x10000
// 0061616f  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00616173  8b88c8000000         mov ecx, dword ptr [eax + 0xc8]
// 00616179  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 00616181  7414                 je 0x616197
// 00616183  33ed                 xor ebp, ebp
// 00616185  c744241c07000000     mov dword ptr [esp + 0x1c], 7
// 0061618d  c744241801000000     mov dword ptr [esp + 0x18], 1
// 00616195  eb15                 jmp 0x6161ac
// 00616197  bd07000000           mov ebp, 7
// 0061619c  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006161a4  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 006161ac  8bd5                 mov edx, ebp
// 006161ae  85c9                 test ecx, ecx
// 006161b0  765f                 jbe 0x616211
// 006161b2  894c2414             mov dword ptr [esp + 0x14], ecx
// 006161b6  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006161ba  85442410             test dword ptr [esp + 0x10], eax
// 006161be  7422                 je 0x6161e2
// 006161c0  0fb606               movzx eax, byte ptr [esi]
// 006161c3  8aca                 mov cl, dl
// 006161c5  d3e8                 shr eax, cl
// 006161c7  b907000000           mov ecx, 7
// 006161cc  2bca                 sub ecx, edx
// 006161ce  bb7f7f0000           mov ebx, 0x7f7f
// 006161d3  d3fb                 sar ebx, cl
// 006161d5  83e001               and eax, 1
// 006161d8  8bca                 mov ecx, edx
// 006161da  d2e0                 shl al, cl
// 006161dc  221f                 and bl, byte ptr [edi]
// 006161de  0ad8                 or bl, al
// 006161e0  881f                 mov byte ptr [edi], bl
// 006161e2  3b54241c             cmp edx, dword ptr [esp + 0x1c]
// 006161e6  7506                 jne 0x6161ee
// 006161e8  46                   inc esi
// 006161e9  8bd5                 mov edx, ebp
// 006161eb  47                   inc edi
// 006161ec  eb04                 jmp 0x6161f2
// 006161ee  03542418             add edx, dword ptr [esp + 0x18]
// 006161f2  b801000000           mov eax, 1
// 006161f7  39442410             cmp dword ptr [esp + 0x10], eax
// 006161fb  750a                 jne 0x616207
// 006161fd  c744241080000000     mov dword ptr [esp + 0x10], 0x80
// 00616205  eb04                 jmp 0x61620b
// 00616207  d17c2410             sar dword ptr [esp + 0x10], 1
// 0061620b  29442414             sub dword ptr [esp + 0x14], eax
// 0061620f  75a5                 jne 0x6161b6
// 00616211  5f                   pop edi
// 00616212  5e                   pop esi
// 00616213  5d                   pop ebp
// 00616214  5b                   pop ebx
// 00616215  83c410               add esp, 0x10
// 00616218  c3                   ret 
// library libpng-1.2.6/pngrutil.c (function _png_combine_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngrutil.c
