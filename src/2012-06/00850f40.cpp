// roc 2012-06 00850f40  unit: RBX::Reflection::PAUTuple::?$sp_counted_impl_pd  size: 334 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00850f40
//
// 00850f40  51                   push ecx
// 00850f41  53                   push ebx
// 00850f42  55                   push ebp
// 00850f43  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00850f47  57                   push edi
// 00850f48  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00850f4c  33db                 xor ebx, ebx
// 00850f4e  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00850f56  3bfb                 cmp edi, ebx
// 00850f58  7543                 jne 0x850f9d
// 00850f5a  b8e83bb400           mov eax, 0xb43be8
// 00850f5f  894608               mov dword ptr [esi + 8], eax
// 00850f62  894604               mov dword ptr [esi + 4], eax
// 00850f65  83c8ff               or eax, 0xffffffff
// 00850f68  6a3c                 push 0x3c
// 00850f6a  894614               mov dword ptr [esi + 0x14], eax
// 00850f6d  89461c               mov dword ptr [esi + 0x1c], eax
// 00850f70  894620               mov dword ptr [esi + 0x20], eax
// 00850f73  8d4624               lea eax, [esi + 0x24]
// 00850f76  68802ebd00           push 0xbd2e80
// 00850f7b  50                   push eax
// 00850f7c  c7460c782ebd00       mov dword ptr [esi + 0xc], 0xbd2e78
// 00850f83  c74610802ebd00       mov dword ptr [esi + 0x10], 0xbd2e80
// 00850f8a  e8d1f1ffff           call 0x850160
// 00850f8f  83c40c               add esp, 0xc
// 00850f92  5f                   pop edi
// 00850f93  5d                   pop ebp
// 00850f94  895e18               mov dword ptr [esi + 0x18], ebx
// 00850f97  8d4301               lea eax, [ebx + 1]
// 00850f9a  5b                   pop ebx
// 00850f9b  59                   pop ecx
// 00850f9c  c3                   ret 
// 00850f9d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00850fa1  8a01                 mov al, byte ptr [ecx]
// 00850fa3  3ac3                 cmp al, bl
// 00850fa5  0f8496000000         je 0x851041
// 00850fab  eb03                 jmp 0x850fb0
// 00850fad  8d4900               lea ecx, [ecx]
// 00850fb0  0fbec0               movsx eax, al
// 00850fb3  83c0b4               add eax, -0x4c
// 00850fb6  83f829               cmp eax, 0x29
// 00850fb9  776f                 ja 0x85102a
// 00850fbb  0fb69064108500       movzx edx, byte ptr [eax + 0x851064]
// 00850fc2  ff24954c108500       jmp dword ptr [edx*4 + 0x85104c]
// 00850fc9  8bcf                 mov ecx, edi
// 00850fcb  8bc6                 mov eax, esi
// 00850fcd  e81ef5ffff           call 0x8504f0
// 00850fd2  eb5a                 jmp 0x85102e
// 00850fd4  3beb                 cmp ebp, ebx
// 00850fd6  7410                 je 0x850fe8
// 00850fd8  8b542414             mov edx, dword ptr [esp + 0x14]
// 00850fdc  8bc5                 mov eax, ebp
// 00850fde  e8cdf2ffff           call 0x8502b0
// 00850fe3  894614               mov dword ptr [esi + 0x14], eax
// 00850fe6  eb46                 jmp 0x85102e
// 00850fe8  83c8ff               or eax, 0xffffffff
// 00850feb  894614               mov dword ptr [esi + 0x14], eax
// 00850fee  eb3e                 jmp 0x85102e
// 00850ff0  0fb64707             movzx eax, byte ptr [edi + 7]
// 00850ff4  894618               mov dword ptr [esi + 0x18], eax
// 00850ff7  eb35                 jmp 0x85102e
// 00850ff9  3beb                 cmp ebp, ebx
// 00850ffb  7418                 je 0x851015
// 00850ffd  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00851001  8d4e04               lea ecx, [esi + 4]
// 00851004  51                   push ecx
// 00851005  8bcd                 mov ecx, ebp
// 00851007  e864fdffff           call 0x850d70
// 0085100c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00851010  83c404               add esp, 4
// 00851013  eb02                 jmp 0x851017
// 00851015  33c0                 xor eax, eax
// 00851017  894608               mov dword ptr [esi + 8], eax
// 0085101a  3bc3                 cmp eax, ebx
// 0085101c  7510                 jne 0x85102e
// 0085101e  c74608e83bb400       mov dword ptr [esi + 8], 0xb43be8
// 00851025  895e04               mov dword ptr [esi + 4], ebx
// 00851028  eb04                 jmp 0x85102e
// 0085102a  895c240c             mov dword ptr [esp + 0xc], ebx
// 0085102e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00851032  40                   inc eax
// 00851033  89442418             mov dword ptr [esp + 0x18], eax
// 00851037  8a00                 mov al, byte ptr [eax]
// 00851039  3ac3                 cmp al, bl
// 0085103b  0f856fffffff         jne 0x850fb0
// 00851041  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00851045  5f                   pop edi
// 00851046  5d                   pop ebp
// 00851047  5b                   pop ebx
// 00851048  59                   pop ecx
// 00851049  c3                   ret 
// 0085104a  8bff                 mov edi, edi
// 0085104c  2e108500c90f85       adc byte ptr cs:[ebp - 0x7af03700], al
// 00851053  00d4                 add ah, dl
// 00851055  0f8500f90f85         jne 0x8595095b
// 0085105b  00f0                 add al, dh
// 0085105d  0f85002a1085         jne 0x85953a63
// 00851063  0000                 add byte ptr [eax], al
// 00851065  0505050505           add eax, 0x5050505
// 0085106a  0501050505           add eax, 0x5050501
// 0085106f  0505050505           add eax, 0x5050505
// 00851074  0505050505           add eax, 0x5050505
// 00851079  0505050505           add eax, 0x5050505
// 0085107e  000505050505         add byte ptr [0x5050505], al
// 00851084  020503050505         add al, byte ptr [0x5050503]
// library lua-5.1/ldebug.c (function _auxgetinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
