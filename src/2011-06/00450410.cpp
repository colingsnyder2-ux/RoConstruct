// from server: 100% by auto
// roc 2011-06 00450410  unit: Ogre::RbxCluster  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00450410
//
// 00450410  83ec54               sub esp, 0x54
// 00450413  53                   push ebx
// 00450414  56                   push esi
// 00450415  8d442408             lea eax, [esp + 8]
// 00450419  50                   push eax
// 0045041a  8bf1                 mov esi, ecx
// 0045041c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0045041f  6a54                 push 0x54
// 00450421  51                   push ecx
// 00450422  ff157c01a400         call dword ptr [0xa4017c]
// 00450428  33db                 xor ebx, ebx
// 0045042a  83f854               cmp eax, 0x54
// 0045042d  7579                 jne 0x4504a8
// 0045042f  55                   push ebp
// 00450430  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00450434  8bc5                 mov eax, ebp
// 00450436  99                   cdq 
// 00450437  8bc8                 mov ecx, eax
// 00450439  0fb7442432           movzx eax, word ptr [esp + 0x32]
// 0045043e  894618               mov dword ptr [esi + 0x18], eax
// 00450441  57                   push edi
// 00450442  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00450446  0fafc7               imul eax, edi
// 00450449  33ca                 xor ecx, edx
// 0045044b  83c01f               add eax, 0x1f
// 0045044e  2bca                 sub ecx, edx
// 00450450  99                   cdq 
// 00450451  83e21f               and edx, 0x1f
// 00450454  03c2                 add eax, edx
// 00450456  8b542468             mov edx, dword ptr [esp + 0x68]
// 0045045a  c1f805               sar eax, 5
// 0045045d  03c0                 add eax, eax
// 0045045f  897e0c               mov dword ptr [esi + 0xc], edi
// 00450462  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00450466  03c0                 add eax, eax
// 00450468  c6461c01             mov byte ptr [esi + 0x1c], 1
// 0045046c  894e10               mov dword ptr [esi + 0x10], ecx
// 0045046f  894614               mov dword ptr [esi + 0x14], eax
// 00450472  897e08               mov dword ptr [esi + 8], edi
// 00450475  3bd3                 cmp edx, ebx
// 00450477  7508                 jne 0x450481
// 00450479  33d2                 xor edx, edx
// 0045047b  3beb                 cmp ebp, ebx
// 0045047d  0f9fc2               setg dl
// 00450480  42                   inc edx
// 00450481  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 00450488  885e1d               mov byte ptr [esi + 0x1d], bl
// 0045048b  83fa02               cmp edx, 2
// 0045048e  750e                 jne 0x45049e
// 00450490  49                   dec ecx
// 00450491  0fafc8               imul ecx, eax
// 00450494  03cf                 add ecx, edi
// 00450496  f7d8                 neg eax
// 00450498  894e08               mov dword ptr [esi + 8], ecx
// 0045049b  894614               mov dword ptr [esi + 0x14], eax
// 0045049e  5f                   pop edi
// 0045049f  5d                   pop ebp
// 004504a0  5e                   pop esi
// 004504a1  5b                   pop ebx
// 004504a2  83c454               add esp, 0x54
// 004504a5  c20400               ret 4
// 004504a8  0fb74c241a           movzx ecx, word ptr [esp + 0x1a]
// 004504ad  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004504b1  8b442410             mov eax, dword ptr [esp + 0x10]
// 004504b5  885e1c               mov byte ptr [esi + 0x1c], bl
// 004504b8  895e14               mov dword ptr [esi + 0x14], ebx
// 004504bb  895e08               mov dword ptr [esi + 8], ebx
// 004504be  885e1d               mov byte ptr [esi + 0x1d], bl
// 004504c1  89560c               mov dword ptr [esi + 0xc], edx
// 004504c4  894610               mov dword ptr [esi + 0x10], eax
// 004504c7  894e18               mov dword ptr [esi + 0x18], ecx
// 004504ca  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 004504d1  5e                   pop esi
// 004504d2  5b                   pop ebx
// 004504d3  83c454               add esp, 0x54
// 004504d6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?UpdateBitmapInfo@CImage@ATL@@AAEXW4DIBOrientation@12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
