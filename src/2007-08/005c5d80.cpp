// from server: 100% by auto
// roc 2007-08 005c5d80  unit: lua_exception  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c5d80
//
// 005c5d80  8b442408             mov eax, dword ptr [esp + 8]
// 005c5d84  53                   push ebx
// 005c5d85  56                   push esi
// 005c5d86  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005c5d8a  f6463602             test byte ptr [esi + 0x36], 2
// 005c5d8e  57                   push edi
// 005c5d8f  7405                 je 0x5c5d96
// 005c5d91  e88affffff           call 0x5c5d20
// 005c5d96  8b5614               mov edx, dword ptr [esi + 0x14]
// 005c5d99  8d7ae8               lea edi, [edx - 0x18]
// 005c5d9c  897e14               mov dword ptr [esi + 0x14], edi
// 005c5d9f  8b5a10               mov ebx, dword ptr [edx + 0x10]
// 005c5da2  85db                 test ebx, ebx
// 005c5da4  8b4a04               mov ecx, dword ptr [edx + 4]
// 005c5da7  8b3f                 mov edi, dword ptr [edi]
// 005c5da9  897e0c               mov dword ptr [esi + 0xc], edi
// 005c5dac  8b52f4               mov edx, dword ptr [edx - 0xc]
// 005c5daf  895c2410             mov dword ptr [esp + 0x10], ebx
// 005c5db3  895618               mov dword ptr [esi + 0x18], edx
// 005c5db6  742d                 je 0x5c5de5
// 005c5db8  55                   push ebp
// 005c5db9  8da42400000000       lea esp, [esp]
// 005c5dc0  3b4608               cmp eax, dword ptr [esi + 8]
// 005c5dc3  731f                 jae 0x5c5de4
// 005c5dc5  8bd0                 mov edx, eax
// 005c5dc7  8b2a                 mov ebp, dword ptr [edx]
// 005c5dc9  8bf9                 mov edi, ecx
// 005c5dcb  892f                 mov dword ptr [edi], ebp
// 005c5dcd  8b6a04               mov ebp, dword ptr [edx + 4]
// 005c5dd0  896f04               mov dword ptr [edi + 4], ebp
// 005c5dd3  8b5208               mov edx, dword ptr [edx + 8]
// 005c5dd6  83c010               add eax, 0x10
// 005c5dd9  83c110               add ecx, 0x10
// 005c5ddc  83eb01               sub ebx, 1
// 005c5ddf  895708               mov dword ptr [edi + 8], edx
// 005c5de2  75dc                 jne 0x5c5dc0
// 005c5de4  5d                   pop ebp
// 005c5de5  33c0                 xor eax, eax
// 005c5de7  3bd8                 cmp ebx, eax
// 005c5de9  7e12                 jle 0x5c5dfd
// 005c5deb  eb03                 jmp 0x5c5df0
// 005c5ded  8d4900               lea ecx, [ecx]
// 005c5df0  83eb01               sub ebx, 1
// 005c5df3  894108               mov dword ptr [ecx + 8], eax
// 005c5df6  83c110               add ecx, 0x10
// 005c5df9  3bd8                 cmp ebx, eax
// 005c5dfb  7ff3                 jg 0x5c5df0
// 005c5dfd  8b442410             mov eax, dword ptr [esp + 0x10]
// 005c5e01  5f                   pop edi
// 005c5e02  894e08               mov dword ptr [esi + 8], ecx
// 005c5e05  5e                   pop esi
// 005c5e06  83c001               add eax, 1
// 005c5e09  5b                   pop ebx
// 005c5e0a  c3                   ret 
// library lua-5.1.2/ldo.c (function _luaD_poscall)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
