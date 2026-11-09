// from server: 100% by tajop
// roc 2007-08 004d0f40  unit: RBX::View::Part  size: 258 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d0f40
//
// 004d0f40  6aff                 push -1
// 004d0f42  68e0c37400           push 0x74c3e0
// 004d0f47  64a100000000         mov eax, dword ptr fs:[0]
// 004d0f4d  50                   push eax
// 004d0f4e  64892500000000       mov dword ptr fs:[0], esp
// 004d0f55  51                   push ecx
// 004d0f56  56                   push esi
// 004d0f57  8bf1                 mov esi, ecx
// 004d0f59  8b86b0000000         mov eax, dword ptr [esi + 0xcc]
// 004d0f5f  50                   push eax
// 004d0f60  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004d0f68  e8b3c50a00           call 0x57d520
// 004d0f6d  83c404               add esp, 4
// 004d0f70  85c0                 test eax, eax
// 004d0f72  741e                 je 0x4d10a2
// 004d0f74  8b8eb0000000         mov ecx, dword ptr [esi + 0xcc]
// 004d0f7a  8b89bc000000         mov ecx, dword ptr [ecx + 0xbc]
// 004d0f80  3bc1                 cmp eax, ecx
// 004d0f82  7472                 je 0x4d1106
// 004d0f84  85c9                 test ecx, ecx
// 004d0f86  740a                 je 0x4d10a2
// 004d0f88  50                   push eax
// 004d0f89  e832f1f4ff           call 0x4200c0
// 004d0f8e  84c0                 test al, al
// 004d0f90  7564                 jne 0x4d1106
// 004d0f92  8d4604               lea eax, [esi + 4]
// 004d0f95  50                   push eax
// 004d0f96  89742408             mov dword ptr [esp + 8], esi
// 004d0f9a  ff15ecd27700         call dword ptr [0x77d2ec]
// 004d0fa0  8b86c4000000         mov eax, dword ptr [esi + 0xc4]
// 004d0fa6  8b4848               mov ecx, dword ptr [eax + 0x48]
// 004d0fa9  8b11                 mov edx, dword ptr [ecx]
// 004d0fab  8b5208               mov edx, dword ptr [edx + 8]
// 004d0fae  8d442404             lea eax, [esp + 4]
// 004d0fb2  50                   push eax
// 004d0fb3  c644241401           mov byte ptr [esp + 0x14], 1
// 004d0fb8  ffd2                 call edx
// 004d0fba  8b442404             mov eax, dword ptr [esp + 4]
// 004d0fbe  85c0                 test eax, eax
// 004d0fc0  c644241000           mov byte ptr [esp + 0x10], 0
// 004d0fc5  742f                 je 0x4d1106
// 004d0fc7  83c004               add eax, 4
// 004d0fca  50                   push eax
// 004d0fcb  ff15e8d27700         call dword ptr [0x77d2e8]
// 004d0fd1  85c0                 test eax, eax
// 004d0fd3  7519                 jne 0x4d10fe
// 004d0fd5  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004d0fd9  e8f26df8ff           call 0x457dd0
// 004d0fde  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004d0fe2  85c9                 test ecx, ecx
// 004d0fe4  7408                 je 0x4d10fe
// 004d0fe6  8b01                 mov eax, dword ptr [ecx]
// 004d0fe8  8b10                 mov edx, dword ptr [eax]
// 004d0fea  6a01                 push 1
// 004d0fec  ffd2                 call edx
// 004d0fee  c744240400000000     mov dword ptr [esp + 4], 0
// 004d0ff6  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004d0ffa  85f6                 test esi, esi
// 004d0ffc  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004d1004  742a                 je 0x4d1140
// 004d1006  8d4604               lea eax, [esi + 4]
// 004d1009  83c9ff               or ecx, 0xffffffff
// 004d100c  f00fc108             lock xadd dword ptr [eax], ecx
// 004d1010  751e                 jne 0x4d1140
// 004d1012  8b16                 mov edx, dword ptr [esi]
// 004d1014  8b4204               mov eax, dword ptr [edx + 4]
// 004d1017  8bce                 mov ecx, esi
// 004d1019  ffd0                 call eax
// 004d101b  8d4e08               lea ecx, [esi + 8]
// 004d101e  83caff               or edx, 0xffffffff
// 004d1021  f00fc111             lock xadd dword ptr [ecx], edx
// 004d1025  7509                 jne 0x4d1140
// 004d1027  8b06                 mov eax, dword ptr [esi]
// 004d1029  8b5008               mov edx, dword ptr [eax + 8]
// 004d102c  8bce                 mov ecx, esi
// 004d102e  ffd2                 call edx
// 004d1030  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004d1034  5e                   pop esi
// 004d1035  64890d00000000       mov dword ptr fs:[0], ecx
// 004d103c  83c410               add esp, 0x10
// 004d103f  c20800               ret 8
// library rbxgs-view/Part.cpp (function ?onAncestorChanged@PartChunk@View@RBX@@AAEXV?$shared_ptr@VInstance@RBX@@@boost@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-view roc_unit_9fa68c426bc2b6e0.cpp