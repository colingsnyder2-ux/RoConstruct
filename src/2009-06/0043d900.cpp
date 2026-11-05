// from server: 100% by auto
// roc 2009-06 0043d900  unit: CSelectionPropGrid  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043d900
//
// 0043d900  83ec54               sub esp, 0x54
// 0043d903  53                   push ebx
// 0043d904  56                   push esi
// 0043d905  8d442408             lea eax, [esp + 8]
// 0043d909  50                   push eax
// 0043d90a  8bf1                 mov esi, ecx
// 0043d90c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043d90f  6a54                 push 0x54
// 0043d911  51                   push ecx
// 0043d912  ff1564e18900         call dword ptr [0x89e164]
// 0043d918  33db                 xor ebx, ebx
// 0043d91a  83f854               cmp eax, 0x54
// 0043d91d  7579                 jne 0x43d998
// 0043d91f  55                   push ebp
// 0043d920  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0043d924  8bc5                 mov eax, ebp
// 0043d926  99                   cdq 
// 0043d927  8bc8                 mov ecx, eax
// 0043d929  0fb7442432           movzx eax, word ptr [esp + 0x32]
// 0043d92e  894618               mov dword ptr [esi + 0x18], eax
// 0043d931  57                   push edi
// 0043d932  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0043d936  0fafc7               imul eax, edi
// 0043d939  33ca                 xor ecx, edx
// 0043d93b  83c01f               add eax, 0x1f
// 0043d93e  2bca                 sub ecx, edx
// 0043d940  99                   cdq 
// 0043d941  83e21f               and edx, 0x1f
// 0043d944  03c2                 add eax, edx
// 0043d946  8b542468             mov edx, dword ptr [esp + 0x68]
// 0043d94a  c1f805               sar eax, 5
// 0043d94d  03c0                 add eax, eax
// 0043d94f  897e0c               mov dword ptr [esi + 0xc], edi
// 0043d952  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0043d956  03c0                 add eax, eax
// 0043d958  c6461c01             mov byte ptr [esi + 0x1c], 1
// 0043d95c  894e10               mov dword ptr [esi + 0x10], ecx
// 0043d95f  894614               mov dword ptr [esi + 0x14], eax
// 0043d962  897e08               mov dword ptr [esi + 8], edi
// 0043d965  3bd3                 cmp edx, ebx
// 0043d967  7508                 jne 0x43d971
// 0043d969  33d2                 xor edx, edx
// 0043d96b  3beb                 cmp ebp, ebx
// 0043d96d  0f9fc2               setg dl
// 0043d970  42                   inc edx
// 0043d971  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 0043d978  885e1d               mov byte ptr [esi + 0x1d], bl
// 0043d97b  83fa02               cmp edx, 2
// 0043d97e  750e                 jne 0x43d98e
// 0043d980  49                   dec ecx
// 0043d981  0fafc8               imul ecx, eax
// 0043d984  03cf                 add ecx, edi
// 0043d986  f7d8                 neg eax
// 0043d988  894e08               mov dword ptr [esi + 8], ecx
// 0043d98b  894614               mov dword ptr [esi + 0x14], eax
// 0043d98e  5f                   pop edi
// 0043d98f  5d                   pop ebp
// 0043d990  5e                   pop esi
// 0043d991  5b                   pop ebx
// 0043d992  83c454               add esp, 0x54
// 0043d995  c20400               ret 4
// 0043d998  0fb74c241a           movzx ecx, word ptr [esp + 0x1a]
// 0043d99d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0043d9a1  8b442410             mov eax, dword ptr [esp + 0x10]
// 0043d9a5  885e1c               mov byte ptr [esi + 0x1c], bl
// 0043d9a8  895e14               mov dword ptr [esi + 0x14], ebx
// 0043d9ab  895e08               mov dword ptr [esi + 8], ebx
// 0043d9ae  885e1d               mov byte ptr [esi + 0x1d], bl
// 0043d9b1  89560c               mov dword ptr [esi + 0xc], edx
// 0043d9b4  894610               mov dword ptr [esi + 0x10], eax
// 0043d9b7  894e18               mov dword ptr [esi + 0x18], ecx
// 0043d9ba  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 0043d9c1  5e                   pop esi
// 0043d9c2  5b                   pop ebx
// 0043d9c3  83c454               add esp, 0x54
// 0043d9c6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?UpdateBitmapInfo@CImage@ATL@@AAEXW4DIBOrientation@12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
