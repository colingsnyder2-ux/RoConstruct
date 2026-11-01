// from server: 100% by auto
// roc 2009-06 006c8870  unit: seg_006c0000  size: 334 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c8870
//
// 006c8870  51                   push ecx
// 006c8871  53                   push ebx
// 006c8872  55                   push ebp
// 006c8873  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 006c8877  57                   push edi
// 006c8878  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006c887c  33db                 xor ebx, ebx
// 006c887e  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 006c8886  3bfb                 cmp edi, ebx
// 006c8888  7543                 jne 0x6c88cd
// 006c888a  b816d28a00           mov eax, 0x8ad216
// 006c888f  894608               mov dword ptr [esi + 8], eax
// 006c8892  894604               mov dword ptr [esi + 4], eax
// 006c8895  83c8ff               or eax, 0xffffffff
// 006c8898  6a3c                 push 0x3c
// 006c889a  894614               mov dword ptr [esi + 0x14], eax
// 006c889d  89461c               mov dword ptr [esi + 0x1c], eax
// 006c88a0  894620               mov dword ptr [esi + 0x20], eax
// 006c88a3  8d4624               lea eax, [esi + 0x24]
// 006c88a6  6894c28e00           push 0x8ec294
// 006c88ab  50                   push eax
// 006c88ac  c7460c8cc28e00       mov dword ptr [esi + 0xc], 0x8ec28c
// 006c88b3  c7461094c28e00       mov dword ptr [esi + 0x10], 0x8ec294
// 006c88ba  e801080000           call 0x6c90c0
// 006c88bf  83c40c               add esp, 0xc
// 006c88c2  5f                   pop edi
// 006c88c3  5d                   pop ebp
// 006c88c4  895e18               mov dword ptr [esi + 0x18], ebx
// 006c88c7  8d4301               lea eax, [ebx + 1]
// 006c88ca  5b                   pop ebx
// 006c88cb  59                   pop ecx
// 006c88cc  c3                   ret 
// 006c88cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006c88d1  8a01                 mov al, byte ptr [ecx]
// 006c88d3  3ac3                 cmp al, bl
// 006c88d5  0f8496000000         je 0x6c8971
// 006c88db  eb03                 jmp 0x6c88e0
// 006c88dd  8d4900               lea ecx, [ecx]
// 006c88e0  0fbec0               movsx eax, al
// 006c88e3  83c0b4               add eax, -0x4c
// 006c88e6  83f829               cmp eax, 0x29
// 006c88e9  776f                 ja 0x6c895a
// 006c88eb  0fb69094896c00       movzx edx, byte ptr [eax + 0x6c8994]
// 006c88f2  ff24957c896c00       jmp dword ptr [edx*4 + 0x6c897c]
// 006c88f9  8bcf                 mov ecx, edi
// 006c88fb  8bc6                 mov eax, esi
// 006c88fd  e82ef5ffff           call 0x6c7e30
// 006c8902  eb5a                 jmp 0x6c895e
// 006c8904  3beb                 cmp ebp, ebx
// 006c8906  7410                 je 0x6c8918
// 006c8908  8b542414             mov edx, dword ptr [esp + 0x14]
// 006c890c  8bc5                 mov eax, ebp
// 006c890e  e8ddf2ffff           call 0x6c7bf0
// 006c8913  894614               mov dword ptr [esi + 0x14], eax
// 006c8916  eb46                 jmp 0x6c895e
// 006c8918  83c8ff               or eax, 0xffffffff
// 006c891b  894614               mov dword ptr [esi + 0x14], eax
// 006c891e  eb3e                 jmp 0x6c895e
// 006c8920  0fb64707             movzx eax, byte ptr [edi + 7]
// 006c8924  894618               mov dword ptr [esi + 0x18], eax
// 006c8927  eb35                 jmp 0x6c895e
// 006c8929  3beb                 cmp ebp, ebx
// 006c892b  7418                 je 0x6c8945
// 006c892d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006c8931  8d4e04               lea ecx, [esi + 4]
// 006c8934  51                   push ecx
// 006c8935  8bcd                 mov ecx, ebp
// 006c8937  e864fdffff           call 0x6c86a0
// 006c893c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006c8940  83c404               add esp, 4
// 006c8943  eb02                 jmp 0x6c8947
// 006c8945  33c0                 xor eax, eax
// 006c8947  894608               mov dword ptr [esi + 8], eax
// 006c894a  3bc3                 cmp eax, ebx
// 006c894c  7510                 jne 0x6c895e
// 006c894e  c7460816d28a00       mov dword ptr [esi + 8], 0x8ad216
// 006c8955  895e04               mov dword ptr [esi + 4], ebx
// 006c8958  eb04                 jmp 0x6c895e
// 006c895a  895c240c             mov dword ptr [esp + 0xc], ebx
// 006c895e  8b442418             mov eax, dword ptr [esp + 0x18]
// 006c8962  40                   inc eax
// 006c8963  89442418             mov dword ptr [esp + 0x18], eax
// 006c8967  8a00                 mov al, byte ptr [eax]
// 006c8969  3ac3                 cmp al, bl
// 006c896b  0f856fffffff         jne 0x6c88e0
// 006c8971  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006c8975  5f                   pop edi
// 006c8976  5d                   pop ebp
// 006c8977  5b                   pop ebx
// 006c8978  59                   pop ecx
// 006c8979  c3                   ret 
// 006c897a  8bff                 mov edi, edi
// 006c897c  5e                   pop esi
// 006c897d  896c00f9             mov dword ptr [eax + eax - 7], ebp
// 006c8981  886c0004             mov byte ptr [eax + eax + 4], ch
// 006c8985  896c0029             mov dword ptr [eax + eax + 0x29], ebp
// 006c8989  896c0020             mov dword ptr [eax + eax + 0x20], ebp
// 006c898d  896c005a             mov dword ptr [eax + eax + 0x5a], ebp
// 006c8991  896c0000             mov dword ptr [eax + eax], ebp
// 006c8995  0505050505           add eax, 0x5050505
// 006c899a  0501050505           add eax, 0x5050501
// 006c899f  0505050505           add eax, 0x5050505
// 006c89a4  0505050505           add eax, 0x5050505
// 006c89a9  0505050505           add eax, 0x5050505
// 006c89ae  000505050505         add byte ptr [0x5050505], al
// 006c89b4  020503050505         add al, byte ptr [0x5050503]
// library lua-5.1/ldebug.c (function _auxgetinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
