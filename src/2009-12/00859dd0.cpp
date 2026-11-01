// from server: 100% by auto
// roc 2009-12 00859dd0  unit: CXTPTabClientWnd  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00859dd0
//
// 00859dd0  51                   push ecx
// 00859dd1  53                   push ebx
// 00859dd2  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00859dd6  56                   push esi
// 00859dd7  8d442408             lea eax, [esp + 8]
// 00859ddb  50                   push eax
// 00859ddc  53                   push ebx
// 00859ddd  8bf1                 mov esi, ecx
// 00859ddf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00859de7  e884f7ffff           call 0x859570
// 00859dec  85c0                 test eax, eax
// 00859dee  7473                 je 0x859e63
// 00859df0  57                   push edi
// 00859df1  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00859df5  85ff                 test edi, edi
// 00859df7  7469                 je 0x859e62
// 00859df9  8d833ddcffff         lea eax, [ebx - 0x23c3]
// 00859dff  83f803               cmp eax, 3
// 00859e02  775e                 ja 0x859e62
// 00859e04  ff24856c9e8500       jmp dword ptr [eax*4 + 0x859e6c]
// 00859e0b  8b4f60               mov ecx, dword ptr [edi + 0x60]
// 00859e0e  6a04                 push 4
// 00859e10  51                   push ecx
// 00859e11  57                   push edi
// 00859e12  8bce                 mov ecx, esi
// 00859e14  e837f8ffff           call 0x859650
// 00859e19  5f                   pop edi
// 00859e1a  5e                   pop esi
// 00859e1b  5b                   pop ebx
// 00859e1c  59                   pop ecx
// 00859e1d  c20400               ret 4
// 00859e20  8b5760               mov edx, dword ptr [edi + 0x60]
// 00859e23  6a03                 push 3
// 00859e25  52                   push edx
// 00859e26  57                   push edi
// 00859e27  8bce                 mov ecx, esi
// 00859e29  e822f8ffff           call 0x859650
// 00859e2e  5f                   pop edi
// 00859e2f  5e                   pop esi
// 00859e30  5b                   pop ebx
// 00859e31  59                   pop ecx
// 00859e32  c20400               ret 4
// 00859e35  8b4760               mov eax, dword ptr [edi + 0x60]
// 00859e38  50                   push eax
// 00859e39  8bce                 mov ecx, esi
// 00859e3b  e850e8ffff           call 0x858690
// 00859e40  48                   dec eax
// 00859e41  eb0c                 jmp 0x859e4f
// 00859e43  8b4760               mov eax, dword ptr [edi + 0x60]
// 00859e46  50                   push eax
// 00859e47  8bce                 mov ecx, esi
// 00859e49  e842e8ffff           call 0x858690
// 00859e4e  40                   inc eax
// 00859e4f  6a02                 push 2
// 00859e51  50                   push eax
// 00859e52  8bce                 mov ecx, esi
// 00859e54  e8e7d6ffff           call 0x857540
// 00859e59  50                   push eax
// 00859e5a  57                   push edi
// 00859e5b  8bce                 mov ecx, esi
// 00859e5d  e8eef7ffff           call 0x859650
// 00859e62  5f                   pop edi
// 00859e63  5e                   pop esi
// 00859e64  5b                   pop ebx
// 00859e65  59                   pop ecx
// 00859e66  c20400               ret 4
// 00859e69  8d4900               lea ecx, [ecx]
// 00859e6c  359e850043           xor eax, 0x4300859e
// 00859e71  9e                   sahf 
// 00859e72  8500                 test dword ptr [eax], eax
// 00859e74  209e85000b9e         and byte ptr [esi - 0x61f4ff7b], bl
// 00859e7a  8500                 test dword ptr [eax], eax
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnWorkspaceCommand@CXTPTabClientWnd@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
