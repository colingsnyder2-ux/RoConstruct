// from server: 100% by auto
// roc 2008-06 00623800  unit: lua_exception  size: 334 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00623800
//
// 00623800  51                   push ecx
// 00623801  53                   push ebx
// 00623802  55                   push ebp
// 00623803  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00623807  57                   push edi
// 00623808  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0062380c  33db                 xor ebx, ebx
// 0062380e  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00623816  3bfb                 cmp edi, ebx
// 00623818  7543                 jne 0x62385d
// 0062381a  b816b78000           mov eax, 0x80b716
// 0062381f  894608               mov dword ptr [esi + 8], eax
// 00623822  894604               mov dword ptr [esi + 4], eax
// 00623825  83c8ff               or eax, 0xffffffff
// 00623828  6a3c                 push 0x3c
// 0062382a  894614               mov dword ptr [esi + 0x14], eax
// 0062382d  89461c               mov dword ptr [esi + 0x1c], eax
// 00623830  894620               mov dword ptr [esi + 0x20], eax
// 00623833  8d4624               lea eax, [esi + 0x24]
// 00623836  68e0498400           push 0x8449e0
// 0062383b  50                   push eax
// 0062383c  c7460cd8498400       mov dword ptr [esi + 0xc], 0x8449d8
// 00623843  c74610e0498400       mov dword ptr [esi + 0x10], 0x8449e0
// 0062384a  e891f2ffff           call 0x622ae0
// 0062384f  83c40c               add esp, 0xc
// 00623852  5f                   pop edi
// 00623853  5d                   pop ebp
// 00623854  895e18               mov dword ptr [esi + 0x18], ebx
// 00623857  8d4301               lea eax, [ebx + 1]
// 0062385a  5b                   pop ebx
// 0062385b  59                   pop ecx
// 0062385c  c3                   ret 
// 0062385d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00623861  8a01                 mov al, byte ptr [ecx]
// 00623863  3ac3                 cmp al, bl
// 00623865  0f8496000000         je 0x623901
// 0062386b  eb03                 jmp 0x623870
// 0062386d  8d4900               lea ecx, [ecx]
// 00623870  0fbec0               movsx eax, al
// 00623873  83c0b4               add eax, -0x4c
// 00623876  83f829               cmp eax, 0x29
// 00623879  776f                 ja 0x6238ea
// 0062387b  0fb69024396200       movzx edx, byte ptr [eax + 0x623924]
// 00623882  ff24950c396200       jmp dword ptr [edx*4 + 0x62390c]
// 00623889  8bcf                 mov ecx, edi
// 0062388b  8bc6                 mov eax, esi
// 0062388d  e8def5ffff           call 0x622e70
// 00623892  eb5a                 jmp 0x6238ee
// 00623894  3beb                 cmp ebp, ebx
// 00623896  7410                 je 0x6238a8
// 00623898  8b542414             mov edx, dword ptr [esp + 0x14]
// 0062389c  8bc5                 mov eax, ebp
// 0062389e  e88df3ffff           call 0x622c30
// 006238a3  894614               mov dword ptr [esi + 0x14], eax
// 006238a6  eb46                 jmp 0x6238ee
// 006238a8  83c8ff               or eax, 0xffffffff
// 006238ab  894614               mov dword ptr [esi + 0x14], eax
// 006238ae  eb3e                 jmp 0x6238ee
// 006238b0  0fb64707             movzx eax, byte ptr [edi + 7]
// 006238b4  894618               mov dword ptr [esi + 0x18], eax
// 006238b7  eb35                 jmp 0x6238ee
// 006238b9  3beb                 cmp ebp, ebx
// 006238bb  7418                 je 0x6238d5
// 006238bd  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006238c1  8d4e04               lea ecx, [esi + 4]
// 006238c4  51                   push ecx
// 006238c5  8bcd                 mov ecx, ebp
// 006238c7  e864fdffff           call 0x623630
// 006238cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006238d0  83c404               add esp, 4
// 006238d3  eb02                 jmp 0x6238d7
// 006238d5  33c0                 xor eax, eax
// 006238d7  894608               mov dword ptr [esi + 8], eax
// 006238da  3bc3                 cmp eax, ebx
// 006238dc  7510                 jne 0x6238ee
// 006238de  c7460816b78000       mov dword ptr [esi + 8], 0x80b716
// 006238e5  895e04               mov dword ptr [esi + 4], ebx
// 006238e8  eb04                 jmp 0x6238ee
// 006238ea  895c240c             mov dword ptr [esp + 0xc], ebx
// 006238ee  8b442418             mov eax, dword ptr [esp + 0x18]
// 006238f2  40                   inc eax
// 006238f3  89442418             mov dword ptr [esp + 0x18], eax
// 006238f7  8a00                 mov al, byte ptr [eax]
// 006238f9  3ac3                 cmp al, bl
// 006238fb  0f856fffffff         jne 0x623870
// 00623901  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00623905  5f                   pop edi
// 00623906  5d                   pop ebp
// 00623907  5b                   pop ebx
// 00623908  59                   pop ecx
// 00623909  c3                   ret 
// 0062390a  8bff                 mov edi, edi
// 0062390c  ee                   out dx, al
// 0062390d  386200               cmp byte ptr [edx], ah
// 00623910  8938                 mov dword ptr [eax], edi
// 00623912  6200                 bound eax, qword ptr [eax]
// 00623914  94                   xchg esp, eax
// 00623915  386200               cmp byte ptr [edx], ah
// 00623918  b9386200b0           mov ecx, 0xb0006238
// 0062391d  386200               cmp byte ptr [edx], ah
// 00623920  ea386200000505       ljmp 0x505:0x6238
// 00623927  0505050501           add eax, 0x1050505
// 0062392c  0505050505           add eax, 0x5050505
// 00623931  0505050505           add eax, 0x5050505
// 00623936  0505050505           add eax, 0x5050505
// 0062393b  0505050005           add eax, 0x5000505
// 00623940  0505050502           add eax, 0x2050505
// 00623945  0503050505           add eax, 0x5050503
// library lua-5.1/ldebug.c (function _auxgetinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
