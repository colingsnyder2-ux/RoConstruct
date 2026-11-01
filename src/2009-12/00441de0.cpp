// from server: 100% by auto
// roc 2009-12 00441de0  unit: Ogre::RbxCluster  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00441de0
//
// 00441de0  83ec54               sub esp, 0x54
// 00441de3  53                   push ebx
// 00441de4  56                   push esi
// 00441de5  8d442408             lea eax, [esp + 8]
// 00441de9  50                   push eax
// 00441dea  8bf1                 mov esi, ecx
// 00441dec  8b4e04               mov ecx, dword ptr [esi + 4]
// 00441def  6a54                 push 0x54
// 00441df1  51                   push ecx
// 00441df2  ff155cb19800         call dword ptr [0x98b15c]
// 00441df8  33db                 xor ebx, ebx
// 00441dfa  83f854               cmp eax, 0x54
// 00441dfd  7579                 jne 0x441e78
// 00441dff  55                   push ebp
// 00441e00  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00441e04  8bc5                 mov eax, ebp
// 00441e06  99                   cdq 
// 00441e07  8bc8                 mov ecx, eax
// 00441e09  0fb7442432           movzx eax, word ptr [esp + 0x32]
// 00441e0e  894618               mov dword ptr [esi + 0x18], eax
// 00441e11  57                   push edi
// 00441e12  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00441e16  0fafc7               imul eax, edi
// 00441e19  33ca                 xor ecx, edx
// 00441e1b  83c01f               add eax, 0x1f
// 00441e1e  2bca                 sub ecx, edx
// 00441e20  99                   cdq 
// 00441e21  83e21f               and edx, 0x1f
// 00441e24  03c2                 add eax, edx
// 00441e26  8b542468             mov edx, dword ptr [esp + 0x68]
// 00441e2a  c1f805               sar eax, 5
// 00441e2d  03c0                 add eax, eax
// 00441e2f  897e0c               mov dword ptr [esi + 0xc], edi
// 00441e32  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00441e36  03c0                 add eax, eax
// 00441e38  c6461c01             mov byte ptr [esi + 0x1c], 1
// 00441e3c  894e10               mov dword ptr [esi + 0x10], ecx
// 00441e3f  894614               mov dword ptr [esi + 0x14], eax
// 00441e42  897e08               mov dword ptr [esi + 8], edi
// 00441e45  3bd3                 cmp edx, ebx
// 00441e47  7508                 jne 0x441e51
// 00441e49  33d2                 xor edx, edx
// 00441e4b  3beb                 cmp ebp, ebx
// 00441e4d  0f9fc2               setg dl
// 00441e50  42                   inc edx
// 00441e51  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 00441e58  885e1d               mov byte ptr [esi + 0x1d], bl
// 00441e5b  83fa02               cmp edx, 2
// 00441e5e  750e                 jne 0x441e6e
// 00441e60  49                   dec ecx
// 00441e61  0fafc8               imul ecx, eax
// 00441e64  03cf                 add ecx, edi
// 00441e66  f7d8                 neg eax
// 00441e68  894e08               mov dword ptr [esi + 8], ecx
// 00441e6b  894614               mov dword ptr [esi + 0x14], eax
// 00441e6e  5f                   pop edi
// 00441e6f  5d                   pop ebp
// 00441e70  5e                   pop esi
// 00441e71  5b                   pop ebx
// 00441e72  83c454               add esp, 0x54
// 00441e75  c20400               ret 4
// 00441e78  0fb74c241a           movzx ecx, word ptr [esp + 0x1a]
// 00441e7d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00441e81  8b442410             mov eax, dword ptr [esp + 0x10]
// 00441e85  885e1c               mov byte ptr [esi + 0x1c], bl
// 00441e88  895e14               mov dword ptr [esi + 0x14], ebx
// 00441e8b  895e08               mov dword ptr [esi + 8], ebx
// 00441e8e  885e1d               mov byte ptr [esi + 0x1d], bl
// 00441e91  89560c               mov dword ptr [esi + 0xc], edx
// 00441e94  894610               mov dword ptr [esi + 0x10], eax
// 00441e97  894e18               mov dword ptr [esi + 0x18], ecx
// 00441e9a  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 00441ea1  5e                   pop esi
// 00441ea2  5b                   pop ebx
// 00441ea3  83c454               add esp, 0x54
// 00441ea6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?UpdateBitmapInfo@CImage@ATL@@AAEXW4DIBOrientation@12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
