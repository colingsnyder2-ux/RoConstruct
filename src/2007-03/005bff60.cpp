// from server: 100% by auto
// roc 2007-03 005bff60  unit: seg_005b0000  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005bff60
//
// 005bff60  8b442408             mov eax, dword ptr [esp + 8]
// 005bff64  53                   push ebx
// 005bff65  56                   push esi
// 005bff66  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005bff6a  f6463602             test byte ptr [esi + 0x36], 2
// 005bff6e  57                   push edi
// 005bff6f  7405                 je 0x5bff76
// 005bff71  e88affffff           call 0x5bff00
// 005bff76  8b5614               mov edx, dword ptr [esi + 0x14]
// 005bff79  8d7ae8               lea edi, [edx - 0x18]
// 005bff7c  897e14               mov dword ptr [esi + 0x14], edi
// 005bff7f  8b5a10               mov ebx, dword ptr [edx + 0x10]
// 005bff82  85db                 test ebx, ebx
// 005bff84  8b4a04               mov ecx, dword ptr [edx + 4]
// 005bff87  8b3f                 mov edi, dword ptr [edi]
// 005bff89  897e0c               mov dword ptr [esi + 0xc], edi
// 005bff8c  8b52f4               mov edx, dword ptr [edx - 0xc]
// 005bff8f  895c2410             mov dword ptr [esp + 0x10], ebx
// 005bff93  895618               mov dword ptr [esi + 0x18], edx
// 005bff96  742d                 je 0x5bffc5
// 005bff98  55                   push ebp
// 005bff99  8da42400000000       lea esp, [esp]
// 005bffa0  3b4608               cmp eax, dword ptr [esi + 8]
// 005bffa3  731f                 jae 0x5bffc4
// 005bffa5  8bd0                 mov edx, eax
// 005bffa7  8b2a                 mov ebp, dword ptr [edx]
// 005bffa9  8bf9                 mov edi, ecx
// 005bffab  892f                 mov dword ptr [edi], ebp
// 005bffad  8b6a04               mov ebp, dword ptr [edx + 4]
// 005bffb0  896f04               mov dword ptr [edi + 4], ebp
// 005bffb3  8b5208               mov edx, dword ptr [edx + 8]
// 005bffb6  83c010               add eax, 0x10
// 005bffb9  83c110               add ecx, 0x10
// 005bffbc  83eb01               sub ebx, 1
// 005bffbf  895708               mov dword ptr [edi + 8], edx
// 005bffc2  75dc                 jne 0x5bffa0
// 005bffc4  5d                   pop ebp
// 005bffc5  33c0                 xor eax, eax
// 005bffc7  3bd8                 cmp ebx, eax
// 005bffc9  7e12                 jle 0x5bffdd
// 005bffcb  eb03                 jmp 0x5bffd0
// 005bffcd  8d4900               lea ecx, [ecx]
// 005bffd0  83eb01               sub ebx, 1
// 005bffd3  894108               mov dword ptr [ecx + 8], eax
// 005bffd6  83c110               add ecx, 0x10
// 005bffd9  3bd8                 cmp ebx, eax
// 005bffdb  7ff3                 jg 0x5bffd0
// 005bffdd  8b442410             mov eax, dword ptr [esp + 0x10]
// 005bffe1  5f                   pop edi
// 005bffe2  894e08               mov dword ptr [esi + 8], ecx
// 005bffe5  5e                   pop esi
// 005bffe6  83c001               add eax, 1
// 005bffe9  5b                   pop ebx
// 005bffea  c3                   ret 
// library lua-5.1.1/ldo.c (function _luaD_poscall)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
