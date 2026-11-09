// from server: 100% by auto
// roc 2008-06 0065f060  unit: seg_00650000  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065f060
//
// 0065f060  53                   push ebx
// 0065f061  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0065f065  55                   push ebp
// 0065f066  56                   push esi
// 0065f067  8b742418             mov esi, dword ptr [esp + 0x18]
// 0065f06b  57                   push edi
// 0065f06c  8bd6                 mov edx, esi
// 0065f06e  8bc3                 mov eax, ebx
// 0065f070  e8abf3ffff           call 0x65e420
// 0065f075  8be8                 mov ebp, eax
// 0065f077  837d0800             cmp dword ptr [ebp + 8], 0
// 0065f07b  750c                 jne 0x65f089
// 0065f07d  81fdd0c38400         cmp ebp, 0x84c3d0
// 0065f083  0f8587000000         jne 0x65f110
// 0065f089  8b4b14               mov ecx, dword ptr [ebx + 0x14]
// 0065f08c  b8e0ffffff           mov eax, 0xffffffe0
// 0065f091  3b4b10               cmp ecx, dword ptr [ebx + 0x10]
// 0065f094  7613                 jbe 0x65f0a9
// 0065f096  014314               add dword ptr [ebx + 0x14], eax
// 0065f099  8b7b14               mov edi, dword ptr [ebx + 0x14]
// 0065f09c  837f1800             cmp dword ptr [edi + 0x18], 0
// 0065f0a0  740c                 je 0x65f0ae
// 0065f0a2  8bd7                 mov edx, edi
// 0065f0a4  3b5310               cmp edx, dword ptr [ebx + 0x10]
// 0065f0a7  77ed                 ja 0x65f096
// 0065f0a9  014314               add dword ptr [ebx + 0x14], eax
// 0065f0ac  eb04                 jmp 0x65f0b2
// 0065f0ae  85ff                 test edi, edi
// 0065f0b0  751e                 jne 0x65f0d0
// 0065f0b2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0065f0b6  55                   push ebp
// 0065f0b7  8bfe                 mov edi, esi
// 0065f0b9  8bc3                 mov eax, ebx
// 0065f0bb  e880feffff           call 0x65ef40
// 0065f0c0  56                   push esi
// 0065f0c1  53                   push ebx
// 0065f0c2  55                   push ebp
// 0065f0c3  e888faffff           call 0x65eb50
// 0065f0c8  83c410               add esp, 0x10
// 0065f0cb  5f                   pop edi
// 0065f0cc  5e                   pop esi
// 0065f0cd  5d                   pop ebp
// 0065f0ce  5b                   pop ebx
// 0065f0cf  c3                   ret 
// 0065f0d0  8d5510               lea edx, [ebp + 0x10]
// 0065f0d3  8bc3                 mov eax, ebx
// 0065f0d5  e846f3ffff           call 0x65e420
// 0065f0da  3bc5                 cmp eax, ebp
// 0065f0dc  7427                 je 0x65f105
// 0065f0de  39681c               cmp dword ptr [eax + 0x1c], ebp
// 0065f0e1  7408                 je 0x65f0eb
// 0065f0e3  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0065f0e6  39681c               cmp dword ptr [eax + 0x1c], ebp
// 0065f0e9  75f8                 jne 0x65f0e3
// 0065f0eb  89781c               mov dword ptr [eax + 0x1c], edi
// 0065f0ee  b908000000           mov ecx, 8
// 0065f0f3  8bf5                 mov esi, ebp
// 0065f0f5  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0065f0f7  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0065f0fb  33c0                 xor eax, eax
// 0065f0fd  89451c               mov dword ptr [ebp + 0x1c], eax
// 0065f100  894508               mov dword ptr [ebp + 8], eax
// 0065f103  eb0b                 jmp 0x65f110
// 0065f105  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 0065f108  89471c               mov dword ptr [edi + 0x1c], eax
// 0065f10b  897d1c               mov dword ptr [ebp + 0x1c], edi
// 0065f10e  8bef                 mov ebp, edi
// 0065f110  8b0e                 mov ecx, dword ptr [esi]
// 0065f112  894d10               mov dword ptr [ebp + 0x10], ecx
// 0065f115  8b5604               mov edx, dword ptr [esi + 4]
// 0065f118  895514               mov dword ptr [ebp + 0x14], edx
// 0065f11b  8b4608               mov eax, dword ptr [esi + 8]
// 0065f11e  894518               mov dword ptr [ebp + 0x18], eax
// 0065f121  b804000000           mov eax, 4
// 0065f126  394608               cmp dword ptr [esi + 8], eax
// 0065f129  7c1b                 jl 0x65f146
// 0065f12b  8b0e                 mov ecx, dword ptr [esi]
// 0065f12d  f6410503             test byte ptr [ecx + 5], 3
// 0065f131  7413                 je 0x65f146
// 0065f133  844305               test byte ptr [ebx + 5], al
// 0065f136  740e                 je 0x65f146
// 0065f138  8b542414             mov edx, dword ptr [esp + 0x14]
// 0065f13c  53                   push ebx
// 0065f13d  52                   push edx
// 0065f13e  e87dd3ffff           call 0x65c4c0
// 0065f143  83c408               add esp, 8
// 0065f146  5f                   pop edi
// 0065f147  5e                   pop esi
// 0065f148  8bc5                 mov eax, ebp
// 0065f14a  5d                   pop ebp
// 0065f14b  5b                   pop ebx
// 0065f14c  c3                   ret 
// library lua-5.1/ltable.c (function _newkey)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
