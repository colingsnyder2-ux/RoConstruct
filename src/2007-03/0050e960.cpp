// from server: 100% by auto
// roc 2007-03 0050e960  unit: seg_00500000  size: 467 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e960
//
// 0050e960  8b542404             mov edx, dword ptr [esp + 4]
// 0050e964  83ec10               sub esp, 0x10
// 0050e967  53                   push ebx
// 0050e968  8a5a08               mov bl, byte ptr [edx + 8]
// 0050e96b  80fb03               cmp bl, 3
// 0050e96e  0f8496010000         je 0x50eb0a
// 0050e974  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0050e978  55                   push ebp
// 0050e979  8b2a                 mov ebp, dword ptr [edx]
// 0050e97b  56                   push esi
// 0050e97c  33f6                 xor esi, esi
// 0050e97e  f6c302               test bl, 2
// 0050e981  57                   push edi
// 0050e982  89742424             mov dword ptr [esp + 0x24], esi
// 0050e986  7430                 je 0x50e9b8
// 0050e988  0fb64209             movzx eax, byte ptr [edx + 9]
// 0050e98c  0fb631               movzx esi, byte ptr [ecx]
// 0050e98f  8bf8                 mov edi, eax
// 0050e991  2bfe                 sub edi, esi
// 0050e993  0fb67101             movzx esi, byte ptr [ecx + 1]
// 0050e997  897c2410             mov dword ptr [esp + 0x10], edi
// 0050e99b  8bf8                 mov edi, eax
// 0050e99d  2bfe                 sub edi, esi
// 0050e99f  0fb67102             movzx esi, byte ptr [ecx + 2]
// 0050e9a3  2bc6                 sub eax, esi
// 0050e9a5  8b742424             mov esi, dword ptr [esp + 0x24]
// 0050e9a9  897c2414             mov dword ptr [esp + 0x14], edi
// 0050e9ad  89442418             mov dword ptr [esp + 0x18], eax
// 0050e9b1  bf03000000           mov edi, 3
// 0050e9b6  eb13                 jmp 0x50e9cb
// 0050e9b8  0fb64103             movzx eax, byte ptr [ecx + 3]
// 0050e9bc  0fb67a09             movzx edi, byte ptr [edx + 9]
// 0050e9c0  2bf8                 sub edi, eax
// 0050e9c2  897c2410             mov dword ptr [esp + 0x10], edi
// 0050e9c6  bf01000000           mov edi, 1
// 0050e9cb  f6c304               test bl, 4
// 0050e9ce  7411                 je 0x50e9e1
// 0050e9d0  0fb64904             movzx ecx, byte ptr [ecx + 4]
// 0050e9d4  0fb64209             movzx eax, byte ptr [edx + 9]
// 0050e9d8  2bc1                 sub eax, ecx
// 0050e9da  8944bc10             mov dword ptr [esp + edi*4 + 0x10], eax
// 0050e9de  83c701               add edi, 1
// 0050e9e1  33c9                 xor ecx, ecx
// 0050e9e3  33c0                 xor eax, eax
// 0050e9e5  3bf9                 cmp edi, ecx
// 0050e9e7  0f8e1a010000         jle 0x50eb07
// 0050e9ed  8d4900               lea ecx, [ecx]
// 0050e9f0  394c8410             cmp dword ptr [esp + eax*4 + 0x10], ecx
// 0050e9f4  7f06                 jg 0x50e9fc
// 0050e9f6  894c8410             mov dword ptr [esp + eax*4 + 0x10], ecx
// 0050e9fa  eb05                 jmp 0x50ea01
// 0050e9fc  be01000000           mov esi, 1
// 0050ea01  83c001               add eax, 1
// 0050ea04  3bc7                 cmp eax, edi
// 0050ea06  7ce8                 jl 0x50e9f0
// 0050ea08  663bf1               cmp si, cx
// 0050ea0b  0f84f6000000         je 0x50eb07
// 0050ea11  0fb64209             movzx eax, byte ptr [edx + 9]
// 0050ea15  83c0fe               add eax, -2
// 0050ea18  83f80e               cmp eax, 0xe
// 0050ea1b  0f87e6000000         ja 0x50eb07
// 0050ea21  0fb68024eb5000       movzx eax, byte ptr [eax + 0x50eb24]
// 0050ea28  ff248510eb5000       jmp dword ptr [eax*4 + 0x50eb10]
// 0050ea2f  8b5204               mov edx, dword ptr [edx + 4]
// 0050ea32  3bd1                 cmp edx, ecx
// 0050ea34  8b442428             mov eax, dword ptr [esp + 0x28]
// 0050ea38  0f86c9000000         jbe 0x50eb07
// 0050ea3e  8bff                 mov edi, edi
// 0050ea40  8a08                 mov cl, byte ptr [eax]
// 0050ea42  d0e9                 shr cl, 1
// 0050ea44  80e155               and cl, 0x55
// 0050ea47  8808                 mov byte ptr [eax], cl
// 0050ea49  83c001               add eax, 1
// 0050ea4c  83ea01               sub edx, 1
// 0050ea4f  75ef                 jne 0x50ea40
// 0050ea51  5f                   pop edi
// 0050ea52  5e                   pop esi
// 0050ea53  5d                   pop ebp
// 0050ea54  5b                   pop ebx
// 0050ea55  83c410               add esp, 0x10
// 0050ea58  c3                   ret 
// 0050ea59  8b7a04               mov edi, dword ptr [edx + 4]
// 0050ea5c  8b542410             mov edx, dword ptr [esp + 0x10]
// 0050ea60  8b742428             mov esi, dword ptr [esp + 0x28]
// 0050ea64  8bca                 mov ecx, edx
// 0050ea66  b8f0000000           mov eax, 0xf0
// 0050ea6b  d3f8                 sar eax, cl
// 0050ea6d  bb0f000000           mov ebx, 0xf
// 0050ea72  d3fb                 sar ebx, cl
// 0050ea74  24f0                 and al, 0xf0
// 0050ea76  0ac3                 or al, bl
// 0050ea78  85ff                 test edi, edi
// 0050ea7a  0f8687000000         jbe 0x50eb07
// 0050ea80  8a1e                 mov bl, byte ptr [esi]
// 0050ea82  8aca                 mov cl, dl
// 0050ea84  d2eb                 shr bl, cl
// 0050ea86  83c601               add esi, 1
// 0050ea89  22d8                 and bl, al
// 0050ea8b  83ef01               sub edi, 1
// 0050ea8e  885eff               mov byte ptr [esi - 1], bl
// 0050ea91  75ed                 jne 0x50ea80
// 0050ea93  5f                   pop edi
// 0050ea94  5e                   pop esi
// 0050ea95  5d                   pop ebp
// 0050ea96  5b                   pop ebx
// 0050ea97  83c410               add esp, 0x10
// 0050ea9a  c3                   ret 
// 0050ea9b  8b742428             mov esi, dword ptr [esp + 0x28]
// 0050ea9f  0fafef               imul ebp, edi
// 0050eaa2  33db                 xor ebx, ebx
// 0050eaa4  85ed                 test ebp, ebp
// 0050eaa6  765f                 jbe 0x50eb07
// 0050eaa8  8bc3                 mov eax, ebx
// 0050eaaa  33d2                 xor edx, edx
// 0050eaac  f7f7                 div edi
// 0050eaae  83c301               add ebx, 1
// 0050eab1  83c601               add esi, 1
// 0050eab4  8a4c9410             mov cl, byte ptr [esp + edx*4 + 0x10]
// 0050eab8  d26eff               shr byte ptr [esi - 1], cl
// 0050eabb  3bdd                 cmp ebx, ebp
// 0050eabd  72e9                 jb 0x50eaa8
// 0050eabf  5f                   pop edi
// 0050eac0  5e                   pop esi
// 0050eac1  5d                   pop ebp
// 0050eac2  5b                   pop ebx
// 0050eac3  83c410               add esp, 0x10
// 0050eac6  c3                   ret 
// 0050eac7  8b742428             mov esi, dword ptr [esp + 0x28]
// 0050eacb  0fafef               imul ebp, edi
// 0050eace  33db                 xor ebx, ebx
// 0050ead0  85ed                 test ebp, ebp
// 0050ead2  7633                 jbe 0x50eb07
// 0050ead4  8bc3                 mov eax, ebx
// 0050ead6  33d2                 xor edx, edx
// 0050ead8  f7f7                 div edi
// 0050eada  660fb606             movzx ax, byte ptr [esi]
// 0050eade  0fb64e01             movzx ecx, byte ptr [esi + 1]
// 0050eae2  66c1e008             shl ax, 8
// 0050eae6  6603c1               add ax, cx
// 0050eae9  83c601               add esi, 1
// 0050eaec  83c301               add ebx, 1
// 0050eaef  83c601               add esi, 1
// 0050eaf2  0fb74c9410           movzx ecx, word ptr [esp + edx*4 + 0x10]
// 0050eaf7  66d3e8               shr ax, cl
// 0050eafa  3bdd                 cmp ebx, ebp
// 0050eafc  0fb7c0               movzx eax, ax
// 0050eaff  8866fe               mov byte ptr [esi - 2], ah
// 0050eb02  8846ff               mov byte ptr [esi - 1], al
// 0050eb05  72cd                 jb 0x50ead4
// 0050eb07  5f                   pop edi
// 0050eb08  5e                   pop esi
// 0050eb09  5d                   pop ebp
// 0050eb0a  5b                   pop ebx
// 0050eb0b  83c410               add esp, 0x10
// 0050eb0e  c3                   ret 
// 0050eb0f  90                   nop 
// 0050eb10  2f                   das 
// 0050eb11  ea500059ea5000       ljmp 0x50:0xea590050
// 0050eb18  9b                   wait 
// 0050eb19  ea5000c7ea5000       ljmp 0x50:0xeac70050
// 0050eb20  07                   pop es
// 0050eb21  eb50                 jmp 0x50eb73
// 0050eb23  0000                 add byte ptr [eax], al
// 0050eb25  0401                 add al, 1
// 0050eb27  0404                 add al, 4
// 0050eb29  0402                 add al, 2
// 0050eb2b  0404                 add al, 4
// 0050eb2d  0404                 add al, 4
// 0050eb2f  0404                 add al, 4
// 0050eb31  0403                 add al, 3
// library libpng-1.2.7/pngrtran.c (function _png_do_unshift)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
