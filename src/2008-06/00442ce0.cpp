// from server: 100% by auto
// roc 2008-06 00442ce0  unit: CPropGrid  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00442ce0
//
// 00442ce0  83ec54               sub esp, 0x54
// 00442ce3  53                   push ebx
// 00442ce4  56                   push esi
// 00442ce5  8d442408             lea eax, [esp + 8]
// 00442ce9  50                   push eax
// 00442cea  8bf1                 mov esi, ecx
// 00442cec  8b4e04               mov ecx, dword ptr [esi + 4]
// 00442cef  6a54                 push 0x54
// 00442cf1  51                   push ecx
// 00442cf2  ff1554218000         call dword ptr [0x802154]
// 00442cf8  33db                 xor ebx, ebx
// 00442cfa  83f854               cmp eax, 0x54
// 00442cfd  7579                 jne 0x442d78
// 00442cff  55                   push ebp
// 00442d00  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00442d04  8bc5                 mov eax, ebp
// 00442d06  99                   cdq 
// 00442d07  8bc8                 mov ecx, eax
// 00442d09  0fb7442432           movzx eax, word ptr [esp + 0x32]
// 00442d0e  894618               mov dword ptr [esi + 0x18], eax
// 00442d11  57                   push edi
// 00442d12  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00442d16  0fafc7               imul eax, edi
// 00442d19  33ca                 xor ecx, edx
// 00442d1b  83c01f               add eax, 0x1f
// 00442d1e  2bca                 sub ecx, edx
// 00442d20  99                   cdq 
// 00442d21  83e21f               and edx, 0x1f
// 00442d24  03c2                 add eax, edx
// 00442d26  8b542468             mov edx, dword ptr [esp + 0x68]
// 00442d2a  c1f805               sar eax, 5
// 00442d2d  03c0                 add eax, eax
// 00442d2f  897e0c               mov dword ptr [esi + 0xc], edi
// 00442d32  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00442d36  03c0                 add eax, eax
// 00442d38  c6461c01             mov byte ptr [esi + 0x1c], 1
// 00442d3c  894e10               mov dword ptr [esi + 0x10], ecx
// 00442d3f  894614               mov dword ptr [esi + 0x14], eax
// 00442d42  897e08               mov dword ptr [esi + 8], edi
// 00442d45  3bd3                 cmp edx, ebx
// 00442d47  7508                 jne 0x442d51
// 00442d49  33d2                 xor edx, edx
// 00442d4b  3beb                 cmp ebp, ebx
// 00442d4d  0f9fc2               setg dl
// 00442d50  42                   inc edx
// 00442d51  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 00442d58  885e1d               mov byte ptr [esi + 0x1d], bl
// 00442d5b  83fa02               cmp edx, 2
// 00442d5e  750e                 jne 0x442d6e
// 00442d60  49                   dec ecx
// 00442d61  0fafc8               imul ecx, eax
// 00442d64  03cf                 add ecx, edi
// 00442d66  f7d8                 neg eax
// 00442d68  894e08               mov dword ptr [esi + 8], ecx
// 00442d6b  894614               mov dword ptr [esi + 0x14], eax
// 00442d6e  5f                   pop edi
// 00442d6f  5d                   pop ebp
// 00442d70  5e                   pop esi
// 00442d71  5b                   pop ebx
// 00442d72  83c454               add esp, 0x54
// 00442d75  c20400               ret 4
// 00442d78  0fb74c241a           movzx ecx, word ptr [esp + 0x1a]
// 00442d7d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00442d81  8b442410             mov eax, dword ptr [esp + 0x10]
// 00442d85  885e1c               mov byte ptr [esi + 0x1c], bl
// 00442d88  895e14               mov dword ptr [esi + 0x14], ebx
// 00442d8b  895e08               mov dword ptr [esi + 8], ebx
// 00442d8e  885e1d               mov byte ptr [esi + 0x1d], bl
// 00442d91  89560c               mov dword ptr [esi + 0xc], edx
// 00442d94  894610               mov dword ptr [esi + 0x10], eax
// 00442d97  894e18               mov dword ptr [esi + 0x18], ecx
// 00442d9a  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 00442da1  5e                   pop esi
// 00442da2  5b                   pop ebx
// 00442da3  83c454               add esp, 0x54
// 00442da6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?UpdateBitmapInfo@CImage@ATL@@AAEXW4DIBOrientation@12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
