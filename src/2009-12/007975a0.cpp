// from server: 100% by auto
// roc 2009-12 007975a0  unit: lua_exception  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007975a0
//
// 007975a0  8b442408             mov eax, dword ptr [esp + 8]
// 007975a4  53                   push ebx
// 007975a5  56                   push esi
// 007975a6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007975aa  f6463802             test byte ptr [esi + 0x38], 2
// 007975ae  57                   push edi
// 007975af  7405                 je 0x7975b6
// 007975b1  e88affffff           call 0x797540
// 007975b6  8b5614               mov edx, dword ptr [esi + 0x14]
// 007975b9  8d7ae8               lea edi, [edx - 0x18]
// 007975bc  897e14               mov dword ptr [esi + 0x14], edi
// 007975bf  8b5a10               mov ebx, dword ptr [edx + 0x10]
// 007975c2  8b4a04               mov ecx, dword ptr [edx + 4]
// 007975c5  8b3f                 mov edi, dword ptr [edi]
// 007975c7  897e0c               mov dword ptr [esi + 0xc], edi
// 007975ca  8b52f4               mov edx, dword ptr [edx - 0xc]
// 007975cd  895c2410             mov dword ptr [esp + 0x10], ebx
// 007975d1  895618               mov dword ptr [esi + 0x18], edx
// 007975d4  85db                 test ebx, ebx
// 007975d6  742d                 je 0x797605
// 007975d8  55                   push ebp
// 007975d9  8da42400000000       lea esp, [esp]
// 007975e0  3b4608               cmp eax, dword ptr [esi + 8]
// 007975e3  731f                 jae 0x797604
// 007975e5  8bd0                 mov edx, eax
// 007975e7  8b2a                 mov ebp, dword ptr [edx]
// 007975e9  8bf9                 mov edi, ecx
// 007975eb  892f                 mov dword ptr [edi], ebp
// 007975ed  8b6a04               mov ebp, dword ptr [edx + 4]
// 007975f0  896f04               mov dword ptr [edi + 4], ebp
// 007975f3  8b5208               mov edx, dword ptr [edx + 8]
// 007975f6  83c010               add eax, 0x10
// 007975f9  83c110               add ecx, 0x10
// 007975fc  83eb01               sub ebx, 1
// 007975ff  895708               mov dword ptr [edi + 8], edx
// 00797602  75dc                 jne 0x7975e0
// 00797604  5d                   pop ebp
// 00797605  33c0                 xor eax, eax
// 00797607  3bd8                 cmp ebx, eax
// 00797609  7e10                 jle 0x79761b
// 0079760b  eb03                 jmp 0x797610
// 0079760d  8d4900               lea ecx, [ecx]
// 00797610  4b                   dec ebx
// 00797611  894108               mov dword ptr [ecx + 8], eax
// 00797614  83c110               add ecx, 0x10
// 00797617  3bd8                 cmp ebx, eax
// 00797619  7ff5                 jg 0x797610
// 0079761b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0079761f  5f                   pop edi
// 00797620  894e08               mov dword ptr [esi + 8], ecx
// 00797623  5e                   pop esi
// 00797624  40                   inc eax
// 00797625  5b                   pop ebx
// 00797626  c3                   ret 
// library lua-5.1.3/ldo.c (function _luaD_poscall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldo.c
