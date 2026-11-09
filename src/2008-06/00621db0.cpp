// from server: 100% by auto
// roc 2008-06 00621db0  unit: lua_exception  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00621db0
//
// 00621db0  8b442408             mov eax, dword ptr [esp + 8]
// 00621db4  53                   push ebx
// 00621db5  56                   push esi
// 00621db6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00621dba  f6463602             test byte ptr [esi + 0x36], 2
// 00621dbe  57                   push edi
// 00621dbf  7405                 je 0x621dc6
// 00621dc1  e89affffff           call 0x621d60
// 00621dc6  8b5614               mov edx, dword ptr [esi + 0x14]
// 00621dc9  8d7ae8               lea edi, [edx - 0x18]
// 00621dcc  897e14               mov dword ptr [esi + 0x14], edi
// 00621dcf  8b5a10               mov ebx, dword ptr [edx + 0x10]
// 00621dd2  8b4a04               mov ecx, dword ptr [edx + 4]
// 00621dd5  8b3f                 mov edi, dword ptr [edi]
// 00621dd7  897e0c               mov dword ptr [esi + 0xc], edi
// 00621dda  8b52f4               mov edx, dword ptr [edx - 0xc]
// 00621ddd  895c2410             mov dword ptr [esp + 0x10], ebx
// 00621de1  895618               mov dword ptr [esi + 0x18], edx
// 00621de4  85db                 test ebx, ebx
// 00621de6  742d                 je 0x621e15
// 00621de8  55                   push ebp
// 00621de9  8da42400000000       lea esp, [esp]
// 00621df0  3b4608               cmp eax, dword ptr [esi + 8]
// 00621df3  731f                 jae 0x621e14
// 00621df5  8bd0                 mov edx, eax
// 00621df7  8b2a                 mov ebp, dword ptr [edx]
// 00621df9  8bf9                 mov edi, ecx
// 00621dfb  892f                 mov dword ptr [edi], ebp
// 00621dfd  8b6a04               mov ebp, dword ptr [edx + 4]
// 00621e00  896f04               mov dword ptr [edi + 4], ebp
// 00621e03  8b5208               mov edx, dword ptr [edx + 8]
// 00621e06  83c010               add eax, 0x10
// 00621e09  83c110               add ecx, 0x10
// 00621e0c  83eb01               sub ebx, 1
// 00621e0f  895708               mov dword ptr [edi + 8], edx
// 00621e12  75dc                 jne 0x621df0
// 00621e14  5d                   pop ebp
// 00621e15  33c0                 xor eax, eax
// 00621e17  3bd8                 cmp ebx, eax
// 00621e19  7e10                 jle 0x621e2b
// 00621e1b  eb03                 jmp 0x621e20
// 00621e1d  8d4900               lea ecx, [ecx]
// 00621e20  4b                   dec ebx
// 00621e21  894108               mov dword ptr [ecx + 8], eax
// 00621e24  83c110               add ecx, 0x10
// 00621e27  3bd8                 cmp ebx, eax
// 00621e29  7ff5                 jg 0x621e20
// 00621e2b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00621e2f  5f                   pop edi
// 00621e30  894e08               mov dword ptr [esi + 8], ecx
// 00621e33  5e                   pop esi
// 00621e34  40                   inc eax
// 00621e35  5b                   pop ebx
// 00621e36  c3                   ret 
// library lua-5.1.2/ldo.c (function _luaD_poscall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
