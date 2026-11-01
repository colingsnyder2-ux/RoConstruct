// from server: 100% by auto
// roc 2007-03 005fcd70  unit: seg_005f0000  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fcd70
//
// 005fcd70  53                   push ebx
// 005fcd71  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005fcd75  85db                 test ebx, ebx
// 005fcd77  55                   push ebp
// 005fcd78  56                   push esi
// 005fcd79  57                   push edi
// 005fcd7a  7478                 je 0x5fcdf4
// 005fcd7c  8b742414             mov esi, dword ptr [esp + 0x14]
// 005fcd80  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005fcd84  833e00               cmp dword ptr [esi], 0
// 005fcd87  7542                 jne 0x5fcdcb
// 005fcd89  8b560c               mov edx, dword ptr [esi + 0xc]
// 005fcd8c  8b4610               mov eax, dword ptr [esi + 0x10]
// 005fcd8f  8d4c241c             lea ecx, [esp + 0x1c]
// 005fcd93  51                   push ecx
// 005fcd94  52                   push edx
// 005fcd95  50                   push eax
// 005fcd96  8b4608               mov eax, dword ptr [esi + 8]
// 005fcd99  ffd0                 call eax
// 005fcd9b  83c40c               add esp, 0xc
// 005fcd9e  85c0                 test eax, eax
// 005fcda0  7459                 je 0x5fcdfb
// 005fcda2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005fcda6  85c9                 test ecx, ecx
// 005fcda8  7451                 je 0x5fcdfb
// 005fcdaa  83c1ff               add ecx, -1
// 005fcdad  894604               mov dword ptr [esi + 4], eax
// 005fcdb0  890e                 mov dword ptr [esi], ecx
// 005fcdb2  0fb610               movzx edx, byte ptr [eax]
// 005fcdb5  83c001               add eax, 1
// 005fcdb8  83faff               cmp edx, -1
// 005fcdbb  894604               mov dword ptr [esi + 4], eax
// 005fcdbe  743b                 je 0x5fcdfb
// 005fcdc0  83c101               add ecx, 1
// 005fcdc3  83c0ff               add eax, -1
// 005fcdc6  890e                 mov dword ptr [esi], ecx
// 005fcdc8  894604               mov dword ptr [esi + 4], eax
// 005fcdcb  8b4604               mov eax, dword ptr [esi + 4]
// 005fcdce  0fb608               movzx ecx, byte ptr [eax]
// 005fcdd1  83f9ff               cmp ecx, -1
// 005fcdd4  7425                 je 0x5fcdfb
// 005fcdd6  8b3e                 mov edi, dword ptr [esi]
// 005fcdd8  3bdf                 cmp ebx, edi
// 005fcdda  7702                 ja 0x5fcdde
// 005fcddc  8bfb                 mov edi, ebx
// 005fcdde  57                   push edi
// 005fcddf  50                   push eax
// 005fcde0  55                   push ebp
// 005fcde1  e8fc230200           call 0x61f1e2
// 005fcde6  293e                 sub dword ptr [esi], edi
// 005fcde8  017e04               add dword ptr [esi + 4], edi
// 005fcdeb  83c40c               add esp, 0xc
// 005fcdee  03ef                 add ebp, edi
// 005fcdf0  2bdf                 sub ebx, edi
// 005fcdf2  7590                 jne 0x5fcd84
// 005fcdf4  5f                   pop edi
// 005fcdf5  5e                   pop esi
// 005fcdf6  5d                   pop ebp
// 005fcdf7  33c0                 xor eax, eax
// 005fcdf9  5b                   pop ebx
// 005fcdfa  c3                   ret 
// 005fcdfb  5f                   pop edi
// 005fcdfc  5e                   pop esi
// 005fcdfd  5d                   pop ebp
// 005fcdfe  8bc3                 mov eax, ebx
// 005fce00  5b                   pop ebx
// 005fce01  c3                   ret 
// library lua-5.1.1/lzio.c (function _luaZ_read)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lzio.c
