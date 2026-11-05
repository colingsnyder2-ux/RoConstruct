// from server: 100% by auto
// roc 2012-06 00645670  unit: seg_00640000  size: 736 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00645670
//
// 00645670  55                   push ebp
// 00645671  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00645675  85ed                 test ebp, ebp
// 00645677  0f84d1020000         je 0x64594e
// 0064567d  56                   push esi
// 0064567e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00645682  85f6                 test esi, esi
// 00645684  0f84c3020000         je 0x64594d
// 0064568a  56                   push esi
// 0064568b  55                   push ebp
// 0064568c  e8effdffff           call 0x645480
// 00645691  83c408               add esp, 8
// 00645694  f6460808             test byte ptr [esi + 8], 8
// 00645698  7414                 je 0x6456ae
// 0064569a  0fb74614             movzx eax, word ptr [esi + 0x14]
// 0064569e  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006456a1  50                   push eax
// 006456a2  51                   push ecx
// 006456a3  55                   push ebp
// 006456a4  e8770e0100           call 0x656520
// 006456a9  83c40c               add esp, 0xc
// 006456ac  eb14                 jmp 0x6456c2
// 006456ae  807e1903             cmp byte ptr [esi + 0x19], 3
// 006456b2  750e                 jne 0x6456c2
// 006456b4  68685eb800           push 0xb85e68
// 006456b9  55                   push ebp
// 006456ba  e8f18a0000           call 0x64e1b0
// 006456bf  83c408               add esp, 8
// 006456c2  f6460810             test byte ptr [esi + 8], 0x10
// 006456c6  7449                 je 0x645711
// 006456c8  f7457000000800       test dword ptr [ebp + 0x70], 0x80000
// 006456cf  7425                 je 0x6456f6
// 006456d1  807e1903             cmp byte ptr [esi + 0x19], 3
// 006456d5  751f                 jne 0x6456f6
// 006456d7  33d2                 xor edx, edx
// 006456d9  33c0                 xor eax, eax
// 006456db  663b5616             cmp dx, word ptr [esi + 0x16]
// 006456df  7315                 jae 0x6456f6
// 006456e1  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 006456e4  03c8                 add ecx, eax
// 006456e6  80caff               or dl, 0xff
// 006456e9  2a11                 sub dl, byte ptr [ecx]
// 006456eb  40                   inc eax
// 006456ec  8811                 mov byte ptr [ecx], dl
// 006456ee  0fb74e16             movzx ecx, word ptr [esi + 0x16]
// 006456f2  3bc1                 cmp eax, ecx
// 006456f4  7ceb                 jl 0x6456e1
// 006456f6  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 006456fa  0fb74616             movzx eax, word ptr [esi + 0x16]
// 006456fe  52                   push edx
// 006456ff  8b564c               mov edx, dword ptr [esi + 0x4c]
// 00645702  50                   push eax
// 00645703  8d4e50               lea ecx, [esi + 0x50]
// 00645706  51                   push ecx
// 00645707  52                   push edx
// 00645708  55                   push ebp
// 00645709  e8922a0100           call 0x6581a0
// 0064570e  83c414               add esp, 0x14
// 00645711  f6460820             test byte ptr [esi + 8], 0x20
// 00645715  7412                 je 0x645729
// 00645717  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0064571b  50                   push eax
// 0064571c  8d4e5a               lea ecx, [esi + 0x5a]
// 0064571f  51                   push ecx
// 00645720  55                   push ebp
// 00645721  e8da2b0100           call 0x658300
// 00645726  83c40c               add esp, 0xc
// 00645729  f6460840             test byte ptr [esi + 8], 0x40
// 0064572d  7412                 je 0x645741
// 0064572f  0fb75614             movzx edx, word ptr [esi + 0x14]
// 00645733  8b467c               mov eax, dword ptr [esi + 0x7c]
// 00645736  52                   push edx
// 00645737  50                   push eax
// 00645738  55                   push ebp
// 00645739  e8f20e0100           call 0x656630
// 0064573e  83c40c               add esp, 0xc
// 00645741  f7460800010000       test dword ptr [esi + 8], 0x100
// 00645748  7416                 je 0x645760
// 0064574a  0fb64e6c             movzx ecx, byte ptr [esi + 0x6c]
// 0064574e  8b5668               mov edx, dword ptr [esi + 0x68]
// 00645751  8b4664               mov eax, dword ptr [esi + 0x64]
// 00645754  51                   push ecx
// 00645755  52                   push edx
// 00645756  50                   push eax
// 00645757  55                   push ebp
// 00645758  e8032d0100           call 0x658460
// 0064575d  83c410               add esp, 0x10
// 00645760  f7460800040000       test dword ptr [esi + 8], 0x400
// 00645767  743c                 je 0x6457a5
// 00645769  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0064576f  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 00645775  0fb686b5000000       movzx eax, byte ptr [esi + 0xb5]
// 0064577c  51                   push ecx
// 0064577d  0fb68eb4000000       movzx ecx, byte ptr [esi + 0xb4]
// 00645784  52                   push edx
// 00645785  8b96a8000000         mov edx, dword ptr [esi + 0xa8]
// 0064578b  50                   push eax
// 0064578c  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 00645792  51                   push ecx
// 00645793  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 00645799  52                   push edx
// 0064579a  50                   push eax
// 0064579b  51                   push ecx
// 0064579c  55                   push ebp
// 0064579d  e88e130100           call 0x656b30
// 006457a2  83c420               add esp, 0x20
// 006457a5  f7460800400000       test dword ptr [esi + 8], 0x4000
// 006457ac  7427                 je 0x6457d5
// 006457ae  dd86e8000000         fld qword ptr [esi + 0xe8]
// 006457b4  0fb696dc000000       movzx edx, byte ptr [esi + 0xdc]
// 006457bb  83ec10               sub esp, 0x10
// 006457be  dd5c2408             fstp qword ptr [esp + 8]
// 006457c2  dd86e0000000         fld qword ptr [esi + 0xe0]
// 006457c8  dd1c24               fstp qword ptr [esp]
// 006457cb  52                   push edx
// 006457cc  55                   push ebp
// 006457cd  e87e2d0100           call 0x658550
// 006457d2  83c418               add esp, 0x18
// 006457d5  f6460880             test byte ptr [esi + 8], 0x80
// 006457d9  7416                 je 0x6457f1
// 006457db  0fb64678             movzx eax, byte ptr [esi + 0x78]
// 006457df  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 006457e2  8b5670               mov edx, dword ptr [esi + 0x70]
// 006457e5  50                   push eax
// 006457e6  51                   push ecx
// 006457e7  52                   push edx
// 006457e8  55                   push ebp
// 006457e9  e8122e0100           call 0x658600
// 006457ee  83c410               add esp, 0x10
// 006457f1  57                   push edi
// 006457f2  bf00020000           mov edi, 0x200
// 006457f7  857e08               test dword ptr [esi + 8], edi
// 006457fa  7410                 je 0x64580c
// 006457fc  8d463c               lea eax, [esi + 0x3c]
// 006457ff  50                   push eax
// 00645800  55                   push ebp
// 00645801  e8ea2e0100           call 0x6586f0
// 00645806  83c408               add esp, 8
// 00645809  097d68               or dword ptr [ebp + 0x68], edi
// 0064580c  f7460800200000       test dword ptr [esi + 8], 0x2000
// 00645813  53                   push ebx
// 00645814  742a                 je 0x645840
// 00645816  33ff                 xor edi, edi
// 00645818  39bed8000000         cmp dword ptr [esi + 0xd8], edi
// 0064581e  7e20                 jle 0x645840
// 00645820  33db                 xor ebx, ebx
// 00645822  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00645828  03cb                 add ecx, ebx
// 0064582a  51                   push ecx
// 0064582b  55                   push ebp
// 0064582c  e85f230100           call 0x657b90
// 00645831  47                   inc edi
// 00645832  83c408               add esp, 8
// 00645835  83c310               add ebx, 0x10
// 00645838  3bbed8000000         cmp edi, dword ptr [esi + 0xd8]
// 0064583e  7ce2                 jl 0x645822
// 00645840  33db                 xor ebx, ebx
// 00645842  395e30               cmp dword ptr [esi + 0x30], ebx
// 00645845  0f8e84000000         jle 0x6458cf
// 0064584b  33ff                 xor edi, edi
// 0064584d  8d4900               lea ecx, [ecx]
// 00645850  8b5638               mov edx, dword ptr [esi + 0x38]
// 00645853  8b0417               mov eax, dword ptr [edi + edx]
// 00645856  85c0                 test eax, eax
// 00645858  7e1a                 jle 0x645874
// 0064585a  68445eb800           push 0xb85e44
// 0064585f  55                   push ebp
// 00645860  e8fb890000           call 0x64e260
// 00645865  8b4638               mov eax, dword ptr [esi + 0x38]
// 00645868  83c408               add esp, 8
// 0064586b  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 00645872  eb52                 jmp 0x6458c6
// 00645874  7528                 jne 0x64589e
// 00645876  8bca                 mov ecx, edx
// 00645878  8b140f               mov edx, dword ptr [edi + ecx]
// 0064587b  8d040f               lea eax, [edi + ecx]
// 0064587e  8b4808               mov ecx, dword ptr [eax + 8]
// 00645881  52                   push edx
// 00645882  8b5004               mov edx, dword ptr [eax + 4]
// 00645885  6a00                 push 0
// 00645887  51                   push ecx
// 00645888  52                   push edx
// 00645889  55                   push ebp
// 0064588a  e871110100           call 0x656a00
// 0064588f  8b4638               mov eax, dword ptr [esi + 0x38]
// 00645892  83c414               add esp, 0x14
// 00645895  c70407feffffff       mov dword ptr [edi + eax], 0xfffffffe
// 0064589c  eb28                 jmp 0x6458c6
// 0064589e  83f8ff               cmp eax, -1
// 006458a1  7523                 jne 0x6458c6
// 006458a3  8bca                 mov ecx, edx
// 006458a5  8b540f08             mov edx, dword ptr [edi + ecx + 8]
// 006458a9  8d040f               lea eax, [edi + ecx]
// 006458ac  8b4004               mov eax, dword ptr [eax + 4]
// 006458af  6a00                 push 0
// 006458b1  52                   push edx
// 006458b2  50                   push eax
// 006458b3  55                   push ebp
// 006458b4  e837100100           call 0x6568f0
// 006458b9  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 006458bc  83c410               add esp, 0x10
// 006458bf  c7040ffdffffff       mov dword ptr [edi + ecx], 0xfffffffd
// 006458c6  43                   inc ebx
// 006458c7  83c710               add edi, 0x10
// 006458ca  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 006458cd  7c81                 jl 0x645850
// 006458cf  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 006458d5  85c0                 test eax, eax
// 006458d7  7472                 je 0x64594b
// 006458d9  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 006458df  8d1480               lea edx, [eax + eax*4]
// 006458e2  8d0497               lea eax, [edi + edx*4]
// 006458e5  3bf8                 cmp edi, eax
// 006458e7  7362                 jae 0x64594b
// 006458e9  bb00000100           mov ebx, 0x10000
// 006458ee  8bff                 mov edi, edi
// 006458f0  57                   push edi
// 006458f1  55                   push ebp
// 006458f2  e8098affff           call 0x63e300
// 006458f7  83c408               add esp, 8
// 006458fa  83f801               cmp eax, 1
// 006458fd  7433                 je 0x645932
// 006458ff  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00645902  84c9                 test cl, cl
// 00645904  742c                 je 0x645932
// 00645906  f6c102               test cl, 2
// 00645909  7427                 je 0x645932
// 0064590b  f6c104               test cl, 4
// 0064590e  7522                 jne 0x645932
// 00645910  f6470320             test byte ptr [edi + 3], 0x20
// 00645914  750a                 jne 0x645920
// 00645916  83f803               cmp eax, 3
// 00645919  7405                 je 0x645920
// 0064591b  855d6c               test dword ptr [ebp + 0x6c], ebx
// 0064591e  7412                 je 0x645932
// 00645920  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00645923  8b5708               mov edx, dword ptr [edi + 8]
// 00645926  51                   push ecx
// 00645927  52                   push edx
// 00645928  57                   push edi
// 00645929  55                   push ebp
// 0064592a  e8f1180100           call 0x657220
// 0064592f  83c410               add esp, 0x10
// 00645932  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00645938  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0064593e  8d0480               lea eax, [eax + eax*4]
// 00645941  83c714               add edi, 0x14
// 00645944  8d1481               lea edx, [ecx + eax*4]
// 00645947  3bfa                 cmp edi, edx
// 00645949  72a5                 jb 0x6458f0
// 0064594b  5b                   pop ebx
// 0064594c  5f                   pop edi
// 0064594d  5e                   pop esi
// 0064594e  5d                   pop ebp
// 0064594f  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
