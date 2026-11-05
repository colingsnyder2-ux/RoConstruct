// from server: 100% by auto
// roc 2010-06 0056eca0  unit: G3D::LineSegment  size: 678 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056eca0
//
// 0056eca0  83ec28               sub esp, 0x28
// 0056eca3  837c243c04           cmp dword ptr [esp + 0x3c], 4
// 0056eca8  56                   push esi
// 0056eca9  8b742430             mov esi, dword ptr [esp + 0x30]
// 0056ecad  c644241870           mov byte ptr [esp + 0x18], 0x70
// 0056ecb2  c644241943           mov byte ptr [esp + 0x19], 0x43
// 0056ecb7  c644241a41           mov byte ptr [esp + 0x1a], 0x41
// 0056ecbc  c644241b4c           mov byte ptr [esp + 0x1b], 0x4c
// 0056ecc1  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0056ecc6  7c0e                 jl 0x56ecd6
// 0056ecc8  681c39a200           push 0xa2391c
// 0056eccd  56                   push esi
// 0056ecce  e88d2e0000           call 0x571b60
// 0056ecd3  83c408               add esp, 8
// 0056ecd6  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0056ecda  53                   push ebx
// 0056ecdb  55                   push ebp
// 0056ecdc  57                   push edi
// 0056ecdd  8d442410             lea eax, [esp + 0x10]
// 0056ece1  50                   push eax
// 0056ece2  51                   push ecx
// 0056ece3  56                   push esi
// 0056ece4  e8a7fbffff           call 0x56e890
// 0056ece9  8be8                 mov ebp, eax
// 0056eceb  8b442460             mov eax, dword ptr [esp + 0x60]
// 0056ecef  83c40c               add esp, 0xc
// 0056ecf2  45                   inc ebp
// 0056ecf3  896c2418             mov dword ptr [esp + 0x18], ebp
// 0056ecf7  8d4801               lea ecx, [eax + 1]
// 0056ecfa  8d9b00000000         lea ebx, [ebx]
// 0056ed00  8a10                 mov dl, byte ptr [eax]
// 0056ed02  40                   inc eax
// 0056ed03  84d2                 test dl, dl
// 0056ed05  75f9                 jne 0x56ed00
// 0056ed07  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 0056ed0b  2bc1                 sub eax, ecx
// 0056ed0d  33d2                 xor edx, edx
// 0056ed0f  85db                 test ebx, ebx
// 0056ed11  0f95c2               setne dl
// 0056ed14  8d0c9d00000000       lea ecx, [ebx*4]
// 0056ed1b  51                   push ecx
// 0056ed1c  56                   push esi
// 0056ed1d  03d0                 add edx, eax
// 0056ed1f  8bfa                 mov edi, edx
// 0056ed21  8d442f0a             lea eax, [edi + ebp + 0xa]
// 0056ed25  897c2424             mov dword ptr [esp + 0x24], edi
// 0056ed29  89442444             mov dword ptr [esp + 0x44], eax
// 0056ed2d  e86e380000           call 0x5725a0
// 0056ed32  83c408               add esp, 8
// 0056ed35  33c9                 xor ecx, ecx
// 0056ed37  89442450             mov dword ptr [esp + 0x50], eax
// 0056ed3b  85db                 test ebx, ebx
// 0056ed3d  7e50                 jle 0x56ed8f
// 0056ed3f  8b542458             mov edx, dword ptr [esp + 0x58]
// 0056ed43  2bd0                 sub edx, eax
// 0056ed45  8bf8                 mov edi, eax
// 0056ed47  89542414             mov dword ptr [esp + 0x14], edx
// 0056ed4b  eb07                 jmp 0x56ed54
// 0056ed4d  8d4900               lea ecx, [ecx]
// 0056ed50  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056ed54  8b043a               mov eax, dword ptr [edx + edi]
// 0056ed57  8d6801               lea ebp, [eax + 1]
// 0056ed5a  8d9b00000000         lea ebx, [ebx]
// 0056ed60  8a10                 mov dl, byte ptr [eax]
// 0056ed62  40                   inc eax
// 0056ed63  84d2                 test dl, dl
// 0056ed65  75f9                 jne 0x56ed60
// 0056ed67  2bc5                 sub eax, ebp
// 0056ed69  8be8                 mov ebp, eax
// 0056ed6b  33d2                 xor edx, edx
// 0056ed6d  8d43ff               lea eax, [ebx - 1]
// 0056ed70  3bc8                 cmp ecx, eax
// 0056ed72  0f95c2               setne dl
// 0056ed75  41                   inc ecx
// 0056ed76  83c704               add edi, 4
// 0056ed79  8d042a               lea eax, [edx + ebp]
// 0056ed7c  0144243c             add dword ptr [esp + 0x3c], eax
// 0056ed80  3bcb                 cmp ecx, ebx
// 0056ed82  8947fc               mov dword ptr [edi - 4], eax
// 0056ed85  7cc9                 jl 0x56ed50
// 0056ed87  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056ed8b  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0056ed8f  85f6                 test esi, esi
// 0056ed91  747b                 je 0x56ee0e
// 0056ed93  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0056ed97  8bc8                 mov ecx, eax
// 0056ed99  c1e918               shr ecx, 0x18
// 0056ed9c  884c241c             mov byte ptr [esp + 0x1c], cl
// 0056eda0  8bd0                 mov edx, eax
// 0056eda2  8bc8                 mov ecx, eax
// 0056eda4  c1ea10               shr edx, 0x10
// 0056eda7  8844241f             mov byte ptr [esp + 0x1f], al
// 0056edab  6a08                 push 8
// 0056edad  8d442420             lea eax, [esp + 0x20]
// 0056edb1  88542421             mov byte ptr [esp + 0x21], dl
// 0056edb5  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056edb9  50                   push eax
// 0056edba  c1e908               shr ecx, 8
// 0056edbd  56                   push esi
// 0056edbe  884c242a             mov byte ptr [esp + 0x2a], cl
// 0056edc2  8954242c             mov dword ptr [esp + 0x2c], edx
// 0056edc6  e8355fffff           call 0x564d00
// 0056edcb  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0056edcf  56                   push esi
// 0056edd0  898e1c010000         mov dword ptr [esi + 0x11c], ecx
// 0056edd6  e8e561ffff           call 0x564fc0
// 0056eddb  6a04                 push 4
// 0056eddd  8d542438             lea edx, [esp + 0x38]
// 0056ede1  52                   push edx
// 0056ede2  56                   push esi
// 0056ede3  e8f861ffff           call 0x564fe0
// 0056ede8  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0056edec  83c41c               add esp, 0x1c
// 0056edef  85c0                 test eax, eax
// 0056edf1  741b                 je 0x56ee0e
// 0056edf3  85ed                 test ebp, ebp
// 0056edf5  7617                 jbe 0x56ee0e
// 0056edf7  55                   push ebp
// 0056edf8  50                   push eax
// 0056edf9  56                   push esi
// 0056edfa  e8015fffff           call 0x564d00
// 0056edff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056ee03  55                   push ebp
// 0056ee04  50                   push eax
// 0056ee05  56                   push esi
// 0056ee06  e8d561ffff           call 0x564fe0
// 0056ee0b  83c418               add esp, 0x18
// 0056ee0e  8b442444             mov eax, dword ptr [esp + 0x44]
// 0056ee12  8bc8                 mov ecx, eax
// 0056ee14  c1f918               sar ecx, 0x18
// 0056ee17  884c242c             mov byte ptr [esp + 0x2c], cl
// 0056ee1b  8bd0                 mov edx, eax
// 0056ee1d  c1fa10               sar edx, 0x10
// 0056ee20  8bc8                 mov ecx, eax
// 0056ee22  8854242d             mov byte ptr [esp + 0x2d], dl
// 0056ee26  8844242f             mov byte ptr [esp + 0x2f], al
// 0056ee2a  8b442448             mov eax, dword ptr [esp + 0x48]
// 0056ee2e  c1f908               sar ecx, 8
// 0056ee31  8bd0                 mov edx, eax
// 0056ee33  c1fa18               sar edx, 0x18
// 0056ee36  884c242e             mov byte ptr [esp + 0x2e], cl
// 0056ee3a  88542430             mov byte ptr [esp + 0x30], dl
// 0056ee3e  8bc8                 mov ecx, eax
// 0056ee40  8bd0                 mov edx, eax
// 0056ee42  c1f910               sar ecx, 0x10
// 0056ee45  c1fa08               sar edx, 8
// 0056ee48  88442433             mov byte ptr [esp + 0x33], al
// 0056ee4c  8a44244c             mov al, byte ptr [esp + 0x4c]
// 0056ee50  884c2431             mov byte ptr [esp + 0x31], cl
// 0056ee54  88542432             mov byte ptr [esp + 0x32], dl
// 0056ee58  88442434             mov byte ptr [esp + 0x34], al
// 0056ee5c  885c2435             mov byte ptr [esp + 0x35], bl
// 0056ee60  85f6                 test esi, esi
// 0056ee62  743c                 je 0x56eea0
// 0056ee64  6a0a                 push 0xa
// 0056ee66  8d4c2430             lea ecx, [esp + 0x30]
// 0056ee6a  51                   push ecx
// 0056ee6b  56                   push esi
// 0056ee6c  e88f5effff           call 0x564d00
// 0056ee71  6a0a                 push 0xa
// 0056ee73  8d54243c             lea edx, [esp + 0x3c]
// 0056ee77  52                   push edx
// 0056ee78  56                   push esi
// 0056ee79  e86261ffff           call 0x564fe0
// 0056ee7e  8b6c246c             mov ebp, dword ptr [esp + 0x6c]
// 0056ee82  83c418               add esp, 0x18
// 0056ee85  85ed                 test ebp, ebp
// 0056ee87  7417                 je 0x56eea0
// 0056ee89  85ff                 test edi, edi
// 0056ee8b  7613                 jbe 0x56eea0
// 0056ee8d  57                   push edi
// 0056ee8e  55                   push ebp
// 0056ee8f  56                   push esi
// 0056ee90  e86b5effff           call 0x564d00
// 0056ee95  57                   push edi
// 0056ee96  55                   push ebp
// 0056ee97  56                   push esi
// 0056ee98  e84361ffff           call 0x564fe0
// 0056ee9d  83c418               add esp, 0x18
// 0056eea0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056eea4  50                   push eax
// 0056eea5  56                   push esi
// 0056eea6  e855370000           call 0x572600
// 0056eeab  83c408               add esp, 8
// 0056eeae  85db                 test ebx, ebx
// 0056eeb0  7e45                 jle 0x56eef7
// 0056eeb2  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 0056eeb6  8b442450             mov eax, dword ptr [esp + 0x50]
// 0056eeba  2bc5                 sub eax, ebp
// 0056eebc  8944243c             mov dword ptr [esp + 0x3c], eax
// 0056eec0  895c244c             mov dword ptr [esp + 0x4c], ebx
// 0056eec4  8b1c28               mov ebx, dword ptr [eax + ebp]
// 0056eec7  8b7d00               mov edi, dword ptr [ebp]
// 0056eeca  85f6                 test esi, esi
// 0056eecc  741f                 je 0x56eeed
// 0056eece  85ff                 test edi, edi
// 0056eed0  741b                 je 0x56eeed
// 0056eed2  85db                 test ebx, ebx
// 0056eed4  7617                 jbe 0x56eeed
// 0056eed6  53                   push ebx
// 0056eed7  57                   push edi
// 0056eed8  56                   push esi
// 0056eed9  e8225effff           call 0x564d00
// 0056eede  53                   push ebx
// 0056eedf  57                   push edi
// 0056eee0  56                   push esi
// 0056eee1  e8fa60ffff           call 0x564fe0
// 0056eee6  8b442454             mov eax, dword ptr [esp + 0x54]
// 0056eeea  83c418               add esp, 0x18
// 0056eeed  83c504               add ebp, 4
// 0056eef0  836c244c01           sub dword ptr [esp + 0x4c], 1
// 0056eef5  75cd                 jne 0x56eec4
// 0056eef7  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0056eefb  51                   push ecx
// 0056eefc  56                   push esi
// 0056eefd  e8fe360000           call 0x572600
// 0056ef02  83c408               add esp, 8
// 0056ef05  5f                   pop edi
// 0056ef06  5d                   pop ebp
// 0056ef07  5b                   pop ebx
// 0056ef08  85f6                 test esi, esi
// 0056ef0a  7435                 je 0x56ef41
// 0056ef0c  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056ef12  8bd0                 mov edx, eax
// 0056ef14  c1ea18               shr edx, 0x18
// 0056ef17  88542440             mov byte ptr [esp + 0x40], dl
// 0056ef1b  8bc8                 mov ecx, eax
// 0056ef1d  8bd0                 mov edx, eax
// 0056ef1f  88442443             mov byte ptr [esp + 0x43], al
// 0056ef23  6a04                 push 4
// 0056ef25  8d442444             lea eax, [esp + 0x44]
// 0056ef29  50                   push eax
// 0056ef2a  c1e910               shr ecx, 0x10
// 0056ef2d  c1ea08               shr edx, 8
// 0056ef30  56                   push esi
// 0056ef31  884c244d             mov byte ptr [esp + 0x4d], cl
// 0056ef35  8854244e             mov byte ptr [esp + 0x4e], dl
// 0056ef39  e8c25dffff           call 0x564d00
// 0056ef3e  83c40c               add esp, 0xc
// 0056ef41  5e                   pop esi
// 0056ef42  83c428               add esp, 0x28
// 0056ef45  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
