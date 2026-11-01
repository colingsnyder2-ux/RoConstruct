// from server: 100% by auto
// roc 2007-03 005fc480  unit: seg_005f0000  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc480
//
// 005fc480  53                   push ebx
// 005fc481  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005fc485  55                   push ebp
// 005fc486  56                   push esi
// 005fc487  8b742418             mov esi, dword ptr [esp + 0x18]
// 005fc48b  57                   push edi
// 005fc48c  8bd6                 mov edx, esi
// 005fc48e  8bc3                 mov eax, ebx
// 005fc490  e89bf3ffff           call 0x5fb830
// 005fc495  8be8                 mov ebp, eax
// 005fc497  837d0800             cmp dword ptr [ebp + 8], 0
// 005fc49b  750c                 jne 0x5fc4a9
// 005fc49d  81fd70037c00         cmp ebp, 0x7c0370
// 005fc4a3  0f8587000000         jne 0x5fc530
// 005fc4a9  8b4b14               mov ecx, dword ptr [ebx + 0x14]
// 005fc4ac  3b4b10               cmp ecx, dword ptr [ebx + 0x10]
// 005fc4af  b8e0ffffff           mov eax, 0xffffffe0
// 005fc4b4  7613                 jbe 0x5fc4c9
// 005fc4b6  014314               add dword ptr [ebx + 0x14], eax
// 005fc4b9  8b7b14               mov edi, dword ptr [ebx + 0x14]
// 005fc4bc  837f1800             cmp dword ptr [edi + 0x18], 0
// 005fc4c0  740c                 je 0x5fc4ce
// 005fc4c2  8bd7                 mov edx, edi
// 005fc4c4  3b5310               cmp edx, dword ptr [ebx + 0x10]
// 005fc4c7  77ed                 ja 0x5fc4b6
// 005fc4c9  014314               add dword ptr [ebx + 0x14], eax
// 005fc4cc  eb04                 jmp 0x5fc4d2
// 005fc4ce  85ff                 test edi, edi
// 005fc4d0  751e                 jne 0x5fc4f0
// 005fc4d2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005fc4d6  55                   push ebp
// 005fc4d7  8bfe                 mov edi, esi
// 005fc4d9  8bc3                 mov eax, ebx
// 005fc4db  e880feffff           call 0x5fc360
// 005fc4e0  56                   push esi
// 005fc4e1  53                   push ebx
// 005fc4e2  55                   push ebp
// 005fc4e3  e888faffff           call 0x5fbf70
// 005fc4e8  83c410               add esp, 0x10
// 005fc4eb  5f                   pop edi
// 005fc4ec  5e                   pop esi
// 005fc4ed  5d                   pop ebp
// 005fc4ee  5b                   pop ebx
// 005fc4ef  c3                   ret 
// 005fc4f0  8d5510               lea edx, [ebp + 0x10]
// 005fc4f3  8bc3                 mov eax, ebx
// 005fc4f5  e836f3ffff           call 0x5fb830
// 005fc4fa  3bc5                 cmp eax, ebp
// 005fc4fc  7427                 je 0x5fc525
// 005fc4fe  39681c               cmp dword ptr [eax + 0x1c], ebp
// 005fc501  7408                 je 0x5fc50b
// 005fc503  8b401c               mov eax, dword ptr [eax + 0x1c]
// 005fc506  39681c               cmp dword ptr [eax + 0x1c], ebp
// 005fc509  75f8                 jne 0x5fc503
// 005fc50b  89781c               mov dword ptr [eax + 0x1c], edi
// 005fc50e  b908000000           mov ecx, 8
// 005fc513  8bf5                 mov esi, ebp
// 005fc515  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 005fc517  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005fc51b  33c0                 xor eax, eax
// 005fc51d  89451c               mov dword ptr [ebp + 0x1c], eax
// 005fc520  894508               mov dword ptr [ebp + 8], eax
// 005fc523  eb0b                 jmp 0x5fc530
// 005fc525  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 005fc528  89471c               mov dword ptr [edi + 0x1c], eax
// 005fc52b  897d1c               mov dword ptr [ebp + 0x1c], edi
// 005fc52e  8bef                 mov ebp, edi
// 005fc530  8b0e                 mov ecx, dword ptr [esi]
// 005fc532  894d10               mov dword ptr [ebp + 0x10], ecx
// 005fc535  8b5604               mov edx, dword ptr [esi + 4]
// 005fc538  895514               mov dword ptr [ebp + 0x14], edx
// 005fc53b  8b4608               mov eax, dword ptr [esi + 8]
// 005fc53e  894518               mov dword ptr [ebp + 0x18], eax
// 005fc541  b804000000           mov eax, 4
// 005fc546  394608               cmp dword ptr [esi + 8], eax
// 005fc549  7c1b                 jl 0x5fc566
// 005fc54b  8b0e                 mov ecx, dword ptr [esi]
// 005fc54d  f6410503             test byte ptr [ecx + 5], 3
// 005fc551  7413                 je 0x5fc566
// 005fc553  844305               test byte ptr [ebx + 5], al
// 005fc556  740e                 je 0x5fc566
// 005fc558  8b542414             mov edx, dword ptr [esp + 0x14]
// 005fc55c  53                   push ebx
// 005fc55d  52                   push edx
// 005fc55e  e87dd3ffff           call 0x5f98e0
// 005fc563  83c408               add esp, 8
// 005fc566  5f                   pop edi
// 005fc567  5e                   pop esi
// 005fc568  8bc5                 mov eax, ebp
// 005fc56a  5d                   pop ebp
// 005fc56b  5b                   pop ebx
// 005fc56c  c3                   ret 
// library lua-5.1.1/ltable.c (function _newkey)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
