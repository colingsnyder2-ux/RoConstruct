// from server: 100% by auto
// roc 2009-06 007b43f0  unit: CXTPShortcutManager  size: 341 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b43f0
//
// 007b43f0  53                   push ebx
// 007b43f1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007b43f5  56                   push esi
// 007b43f6  57                   push edi
// 007b43f7  33ff                 xor edi, edi
// 007b43f9  3bdf                 cmp ebx, edi
// 007b43fb  8bf1                 mov esi, ecx
// 007b43fd  7d05                 jge 0x7b4404
// 007b43ff  e8e048f6ff           call 0x718ce4
// 007b4404  8b442414             mov eax, dword ptr [esp + 0x14]
// 007b4408  3bc7                 cmp eax, edi
// 007b440a  7c03                 jl 0x7b440f
// 007b440c  894610               mov dword ptr [esi + 0x10], eax
// 007b440f  3bdf                 cmp ebx, edi
// 007b4411  751f                 jne 0x7b4432
// 007b4413  8b4604               mov eax, dword ptr [esi + 4]
// 007b4416  3bc7                 cmp eax, edi
// 007b4418  740c                 je 0x7b4426
// 007b441a  50                   push eax
// 007b441b  e8be48f6ff           call 0x718cde
// 007b4420  83c404               add esp, 4
// 007b4423  897e04               mov dword ptr [esi + 4], edi
// 007b4426  897e0c               mov dword ptr [esi + 0xc], edi
// 007b4429  897e08               mov dword ptr [esi + 8], edi
// 007b442c  5f                   pop edi
// 007b442d  5e                   pop esi
// 007b442e  5b                   pop ebx
// 007b442f  c20800               ret 8
// 007b4432  8b5604               mov edx, dword ptr [esi + 4]
// 007b4435  55                   push ebp
// 007b4436  3bd7                 cmp edx, edi
// 007b4438  7531                 jne 0x7b446b
// 007b443a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 007b443d  3bdd                 cmp ebx, ebp
// 007b443f  7e02                 jle 0x7b4443
// 007b4441  8beb                 mov ebp, ebx
// 007b4443  8d7c6d00             lea edi, [ebp + ebp*2]
// 007b4447  03ff                 add edi, edi
// 007b4449  57                   push edi
// 007b444a  e8cb48f6ff           call 0x718d1a
// 007b444f  57                   push edi
// 007b4450  6a00                 push 0
// 007b4452  50                   push eax
// 007b4453  894604               mov dword ptr [esi + 4], eax
// 007b4456  e81958f6ff           call 0x719c74
// 007b445b  83c410               add esp, 0x10
// 007b445e  896e0c               mov dword ptr [esi + 0xc], ebp
// 007b4461  5d                   pop ebp
// 007b4462  5f                   pop edi
// 007b4463  895e08               mov dword ptr [esi + 8], ebx
// 007b4466  5e                   pop esi
// 007b4467  5b                   pop ebx
// 007b4468  c20800               ret 8
// 007b446b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007b446e  3bd9                 cmp ebx, ecx
// 007b4470  7f2f                 jg 0x7b44a1
// 007b4472  8b4e08               mov ecx, dword ptr [esi + 8]
// 007b4475  3bd9                 cmp ebx, ecx
// 007b4477  0f8ebe000000         jle 0x7b453b
// 007b447d  8bc3                 mov eax, ebx
// 007b447f  2bc1                 sub eax, ecx
// 007b4481  8d0440               lea eax, [eax + eax*2]
// 007b4484  03c0                 add eax, eax
// 007b4486  50                   push eax
// 007b4487  8d0c49               lea ecx, [ecx + ecx*2]
// 007b448a  8d144a               lea edx, [edx + ecx*2]
// 007b448d  57                   push edi
// 007b448e  52                   push edx
// 007b448f  e8e057f6ff           call 0x719c74
// 007b4494  83c40c               add esp, 0xc
// 007b4497  5d                   pop ebp
// 007b4498  5f                   pop edi
// 007b4499  895e08               mov dword ptr [esi + 8], ebx
// 007b449c  5e                   pop esi
// 007b449d  5b                   pop ebx
// 007b449e  c20800               ret 8
// 007b44a1  8b4610               mov eax, dword ptr [esi + 0x10]
// 007b44a4  3bc7                 cmp eax, edi
// 007b44a6  7524                 jne 0x7b44cc
// 007b44a8  8b4608               mov eax, dword ptr [esi + 8]
// 007b44ab  99                   cdq 
// 007b44ac  83e207               and edx, 7
// 007b44af  03c2                 add eax, edx
// 007b44b1  c1f803               sar eax, 3
// 007b44b4  83f804               cmp eax, 4
// 007b44b7  7d07                 jge 0x7b44c0
// 007b44b9  b804000000           mov eax, 4
// 007b44be  eb0c                 jmp 0x7b44cc
// 007b44c0  3d00040000           cmp eax, 0x400
// 007b44c5  7e05                 jle 0x7b44cc
// 007b44c7  b800040000           mov eax, 0x400
// 007b44cc  8d3c01               lea edi, [ecx + eax]
// 007b44cf  3bdf                 cmp ebx, edi
// 007b44d1  7d06                 jge 0x7b44d9
// 007b44d3  897c2414             mov dword ptr [esp + 0x14], edi
// 007b44d7  eb06                 jmp 0x7b44df
// 007b44d9  895c2414             mov dword ptr [esp + 0x14], ebx
// 007b44dd  8bfb                 mov edi, ebx
// 007b44df  3bf9                 cmp edi, ecx
// 007b44e1  7d05                 jge 0x7b44e8
// 007b44e3  e8fc47f6ff           call 0x718ce4
// 007b44e8  8d3c7f               lea edi, [edi + edi*2]
// 007b44eb  03ff                 add edi, edi
// 007b44ed  57                   push edi
// 007b44ee  e82748f6ff           call 0x718d1a
// 007b44f3  8b4e04               mov ecx, dword ptr [esi + 4]
// 007b44f6  8be8                 mov ebp, eax
// 007b44f8  8b4608               mov eax, dword ptr [esi + 8]
// 007b44fb  8d0440               lea eax, [eax + eax*2]
// 007b44fe  03c0                 add eax, eax
// 007b4500  50                   push eax
// 007b4501  51                   push ecx
// 007b4502  57                   push edi
// 007b4503  55                   push ebp
// 007b4504  e8c7e9c4ff           call 0x402ed0
// 007b4509  8b4e08               mov ecx, dword ptr [esi + 8]
// 007b450c  8bc3                 mov eax, ebx
// 007b450e  2bc1                 sub eax, ecx
// 007b4510  8d1440               lea edx, [eax + eax*2]
// 007b4513  03d2                 add edx, edx
// 007b4515  52                   push edx
// 007b4516  8d0449               lea eax, [ecx + ecx*2]
// 007b4519  8d4c4500             lea ecx, [ebp + eax*2]
// 007b451d  6a00                 push 0
// 007b451f  51                   push ecx
// 007b4520  e84f57f6ff           call 0x719c74
// 007b4525  8b5604               mov edx, dword ptr [esi + 4]
// 007b4528  52                   push edx
// 007b4529  e8b047f6ff           call 0x718cde
// 007b452e  8b442438             mov eax, dword ptr [esp + 0x38]
// 007b4532  83c424               add esp, 0x24
// 007b4535  896e04               mov dword ptr [esi + 4], ebp
// 007b4538  89460c               mov dword ptr [esi + 0xc], eax
// 007b453b  5d                   pop ebp
// 007b453c  5f                   pop edi
// 007b453d  895e08               mov dword ptr [esi + 8], ebx
// 007b4540  5e                   pop esi
// 007b4541  5b                   pop ebx
// 007b4542  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPShortcutManager.cpp (function ?SetSize@?$CArray@UtagACCEL@@AAU1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPShortcutManager.cpp
