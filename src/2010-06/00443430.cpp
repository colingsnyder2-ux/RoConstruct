// from server: 100% by auto
// roc 2010-06 00443430  unit: RBX::TextureProxyBase  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00443430
//
// 00443430  83ec54               sub esp, 0x54
// 00443433  53                   push ebx
// 00443434  56                   push esi
// 00443435  8d442408             lea eax, [esp + 8]
// 00443439  50                   push eax
// 0044343a  8bf1                 mov esi, ecx
// 0044343c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0044343f  6a54                 push 0x54
// 00443441  51                   push ecx
// 00443442  ff15bca09e00         call dword ptr [0x9ea0bc]
// 00443448  33db                 xor ebx, ebx
// 0044344a  83f854               cmp eax, 0x54
// 0044344d  7579                 jne 0x4434c8
// 0044344f  55                   push ebp
// 00443450  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00443454  8bc5                 mov eax, ebp
// 00443456  99                   cdq 
// 00443457  8bc8                 mov ecx, eax
// 00443459  0fb7442432           movzx eax, word ptr [esp + 0x32]
// 0044345e  894618               mov dword ptr [esi + 0x18], eax
// 00443461  57                   push edi
// 00443462  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00443466  0fafc7               imul eax, edi
// 00443469  33ca                 xor ecx, edx
// 0044346b  83c01f               add eax, 0x1f
// 0044346e  2bca                 sub ecx, edx
// 00443470  99                   cdq 
// 00443471  83e21f               and edx, 0x1f
// 00443474  03c2                 add eax, edx
// 00443476  8b542468             mov edx, dword ptr [esp + 0x68]
// 0044347a  c1f805               sar eax, 5
// 0044347d  03c0                 add eax, eax
// 0044347f  897e0c               mov dword ptr [esi + 0xc], edi
// 00443482  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00443486  03c0                 add eax, eax
// 00443488  c6461c01             mov byte ptr [esi + 0x1c], 1
// 0044348c  894e10               mov dword ptr [esi + 0x10], ecx
// 0044348f  894614               mov dword ptr [esi + 0x14], eax
// 00443492  897e08               mov dword ptr [esi + 8], edi
// 00443495  3bd3                 cmp edx, ebx
// 00443497  7508                 jne 0x4434a1
// 00443499  33d2                 xor edx, edx
// 0044349b  3beb                 cmp ebp, ebx
// 0044349d  0f9fc2               setg dl
// 004434a0  42                   inc edx
// 004434a1  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 004434a8  885e1d               mov byte ptr [esi + 0x1d], bl
// 004434ab  83fa02               cmp edx, 2
// 004434ae  750e                 jne 0x4434be
// 004434b0  49                   dec ecx
// 004434b1  0fafc8               imul ecx, eax
// 004434b4  03cf                 add ecx, edi
// 004434b6  f7d8                 neg eax
// 004434b8  894e08               mov dword ptr [esi + 8], ecx
// 004434bb  894614               mov dword ptr [esi + 0x14], eax
// 004434be  5f                   pop edi
// 004434bf  5d                   pop ebp
// 004434c0  5e                   pop esi
// 004434c1  5b                   pop ebx
// 004434c2  83c454               add esp, 0x54
// 004434c5  c20400               ret 4
// 004434c8  0fb74c241a           movzx ecx, word ptr [esp + 0x1a]
// 004434cd  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004434d1  8b442410             mov eax, dword ptr [esp + 0x10]
// 004434d5  885e1c               mov byte ptr [esi + 0x1c], bl
// 004434d8  895e14               mov dword ptr [esi + 0x14], ebx
// 004434db  895e08               mov dword ptr [esi + 8], ebx
// 004434de  885e1d               mov byte ptr [esi + 0x1d], bl
// 004434e1  89560c               mov dword ptr [esi + 0xc], edx
// 004434e4  894610               mov dword ptr [esi + 0x10], eax
// 004434e7  894e18               mov dword ptr [esi + 0x18], ecx
// 004434ea  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 004434f1  5e                   pop esi
// 004434f2  5b                   pop ebx
// 004434f3  83c454               add esp, 0x54
// 004434f6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?UpdateBitmapInfo@CImage@ATL@@AAEXW4DIBOrientation@12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
