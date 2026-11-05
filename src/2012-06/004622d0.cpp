// from server: 100% by auto
// roc 2012-06 004622d0  unit: RBX::TextureProxyBase  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004622d0
//
// 004622d0  83ec54               sub esp, 0x54
// 004622d3  53                   push ebx
// 004622d4  56                   push esi
// 004622d5  8d442408             lea eax, [esp + 8]
// 004622d9  50                   push eax
// 004622da  8bf1                 mov esi, ecx
// 004622dc  8b4e04               mov ecx, dword ptr [esi + 4]
// 004622df  6a54                 push 0x54
// 004622e1  51                   push ecx
// 004622e2  ff155021b200         call dword ptr [0xb22150]
// 004622e8  33db                 xor ebx, ebx
// 004622ea  83f854               cmp eax, 0x54
// 004622ed  7579                 jne 0x462368
// 004622ef  55                   push ebp
// 004622f0  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 004622f4  8bc5                 mov eax, ebp
// 004622f6  99                   cdq 
// 004622f7  8bc8                 mov ecx, eax
// 004622f9  0fb7442432           movzx eax, word ptr [esp + 0x32]
// 004622fe  894618               mov dword ptr [esi + 0x18], eax
// 00462301  57                   push edi
// 00462302  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00462306  0fafc7               imul eax, edi
// 00462309  33ca                 xor ecx, edx
// 0046230b  83c01f               add eax, 0x1f
// 0046230e  2bca                 sub ecx, edx
// 00462310  99                   cdq 
// 00462311  83e21f               and edx, 0x1f
// 00462314  03c2                 add eax, edx
// 00462316  8b542468             mov edx, dword ptr [esp + 0x68]
// 0046231a  c1f805               sar eax, 5
// 0046231d  03c0                 add eax, eax
// 0046231f  897e0c               mov dword ptr [esi + 0xc], edi
// 00462322  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00462326  03c0                 add eax, eax
// 00462328  c6461c01             mov byte ptr [esi + 0x1c], 1
// 0046232c  894e10               mov dword ptr [esi + 0x10], ecx
// 0046232f  894614               mov dword ptr [esi + 0x14], eax
// 00462332  897e08               mov dword ptr [esi + 8], edi
// 00462335  3bd3                 cmp edx, ebx
// 00462337  7508                 jne 0x462341
// 00462339  33d2                 xor edx, edx
// 0046233b  3beb                 cmp ebp, ebx
// 0046233d  0f9fc2               setg dl
// 00462340  42                   inc edx
// 00462341  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 00462348  885e1d               mov byte ptr [esi + 0x1d], bl
// 0046234b  83fa02               cmp edx, 2
// 0046234e  750e                 jne 0x46235e
// 00462350  49                   dec ecx
// 00462351  0fafc8               imul ecx, eax
// 00462354  03cf                 add ecx, edi
// 00462356  f7d8                 neg eax
// 00462358  894e08               mov dword ptr [esi + 8], ecx
// 0046235b  894614               mov dword ptr [esi + 0x14], eax
// 0046235e  5f                   pop edi
// 0046235f  5d                   pop ebp
// 00462360  5e                   pop esi
// 00462361  5b                   pop ebx
// 00462362  83c454               add esp, 0x54
// 00462365  c20400               ret 4
// 00462368  0fb74c241a           movzx ecx, word ptr [esp + 0x1a]
// 0046236d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00462371  8b442410             mov eax, dword ptr [esp + 0x10]
// 00462375  885e1c               mov byte ptr [esi + 0x1c], bl
// 00462378  895e14               mov dword ptr [esi + 0x14], ebx
// 0046237b  895e08               mov dword ptr [esi + 8], ebx
// 0046237e  885e1d               mov byte ptr [esi + 0x1d], bl
// 00462381  89560c               mov dword ptr [esi + 0xc], edx
// 00462384  894610               mov dword ptr [esi + 0x10], eax
// 00462387  894e18               mov dword ptr [esi + 0x18], ecx
// 0046238a  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 00462391  5e                   pop esi
// 00462392  5b                   pop ebx
// 00462393  83c454               add esp, 0x54
// 00462396  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?UpdateBitmapInfo@CImage@ATL@@AAEXW4DIBOrientation@12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
