// from server: 100% by auto
// roc 2009-06 0077ed10  unit: CXTPTabClientWnd  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077ed10
//
// 0077ed10  51                   push ecx
// 0077ed11  53                   push ebx
// 0077ed12  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0077ed16  56                   push esi
// 0077ed17  8d442408             lea eax, [esp + 8]
// 0077ed1b  50                   push eax
// 0077ed1c  53                   push ebx
// 0077ed1d  8bf1                 mov esi, ecx
// 0077ed1f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0077ed27  e884f7ffff           call 0x77e4b0
// 0077ed2c  85c0                 test eax, eax
// 0077ed2e  7473                 je 0x77eda3
// 0077ed30  57                   push edi
// 0077ed31  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0077ed35  85ff                 test edi, edi
// 0077ed37  7469                 je 0x77eda2
// 0077ed39  8d833ddcffff         lea eax, [ebx - 0x23c3]
// 0077ed3f  83f803               cmp eax, 3
// 0077ed42  775e                 ja 0x77eda2
// 0077ed44  ff2485aced7700       jmp dword ptr [eax*4 + 0x77edac]
// 0077ed4b  8b4f60               mov ecx, dword ptr [edi + 0x60]
// 0077ed4e  6a04                 push 4
// 0077ed50  51                   push ecx
// 0077ed51  57                   push edi
// 0077ed52  8bce                 mov ecx, esi
// 0077ed54  e837f8ffff           call 0x77e590
// 0077ed59  5f                   pop edi
// 0077ed5a  5e                   pop esi
// 0077ed5b  5b                   pop ebx
// 0077ed5c  59                   pop ecx
// 0077ed5d  c20400               ret 4
// 0077ed60  8b5760               mov edx, dword ptr [edi + 0x60]
// 0077ed63  6a03                 push 3
// 0077ed65  52                   push edx
// 0077ed66  57                   push edi
// 0077ed67  8bce                 mov ecx, esi
// 0077ed69  e822f8ffff           call 0x77e590
// 0077ed6e  5f                   pop edi
// 0077ed6f  5e                   pop esi
// 0077ed70  5b                   pop ebx
// 0077ed71  59                   pop ecx
// 0077ed72  c20400               ret 4
// 0077ed75  8b4760               mov eax, dword ptr [edi + 0x60]
// 0077ed78  50                   push eax
// 0077ed79  8bce                 mov ecx, esi
// 0077ed7b  e850e8ffff           call 0x77d5d0
// 0077ed80  48                   dec eax
// 0077ed81  eb0c                 jmp 0x77ed8f
// 0077ed83  8b4760               mov eax, dword ptr [edi + 0x60]
// 0077ed86  50                   push eax
// 0077ed87  8bce                 mov ecx, esi
// 0077ed89  e842e8ffff           call 0x77d5d0
// 0077ed8e  40                   inc eax
// 0077ed8f  6a02                 push 2
// 0077ed91  50                   push eax
// 0077ed92  8bce                 mov ecx, esi
// 0077ed94  e8e7d6ffff           call 0x77c480
// 0077ed99  50                   push eax
// 0077ed9a  57                   push edi
// 0077ed9b  8bce                 mov ecx, esi
// 0077ed9d  e8eef7ffff           call 0x77e590
// 0077eda2  5f                   pop edi
// 0077eda3  5e                   pop esi
// 0077eda4  5b                   pop ebx
// 0077eda5  59                   pop ecx
// 0077eda6  c20400               ret 4
// 0077eda9  8d4900               lea ecx, [ecx]
// 0077edac  75ed                 jne 0x77ed9b
// 0077edae  7700                 ja 0x77edb0
// 0077edb0  83ed77               sub ebp, 0x77
// 0077edb3  0060ed               add byte ptr [eax - 0x13], ah
// 0077edb6  7700                 ja 0x77edb8
// 0077edb8  4b                   dec ebx
// 0077edb9  ed                   in eax, dx
// 0077edba  7700                 ja 0x77edbc
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnWorkspaceCommand@CXTPTabClientWnd@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
