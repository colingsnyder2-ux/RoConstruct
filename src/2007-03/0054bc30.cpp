// from server: 100% by colin
// roc 2007-03 0054bc30  unit: seg_00540000  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0054bc30
//
// 0054bc30  55                   push ebp
// 0054bc31  8bec                 mov ebp, esp
// 0054bc33  6aff                 push -1
// 0054bc35  68c0327500           push 0x7532c0
// 0054bc3a  64a100000000         mov eax, dword ptr fs:[0]
// 0054bc40  50                   push eax
// 0054bc41  64892500000000       mov dword ptr fs:[0], esp
// 0054bc48  83ec08               sub esp, 8
// 0054bc4b  53                   push ebx
// 0054bc4c  56                   push esi
// 0054bc4d  8bf1                 mov esi, ecx
// 0054bc4f  8b06                 mov eax, dword ptr [esi]
// 0054bc51  8b503c               mov edx, dword ptr [eax + 0x3c]
// 0054bc54  57                   push edi
// 0054bc55  8965f0               mov dword ptr [ebp - 0x10], esp
// 0054bc58  33db                 xor ebx, ebx
// 0054bc5a  6a01                 push 1
// 0054bc5c  8975ec               mov dword ptr [ebp - 0x14], esi
// 0054bc5f  895dfc               mov dword ptr [ebp - 4], ebx
// 0054bc62  ffd2                 call edx
// 0054bc64  eb0b                 jmp 0x54bc71
// 0054bc66  b86cbc5400           mov eax, 0x54bc6c
// 0054bc6b  c3                   ret 
// 0054bc6c  8b75ec               mov esi, dword ptr [ebp - 0x14]
// 0054bc6f  33db                 xor ebx, ebx
// 0054bc71  8b06                 mov eax, dword ptr [esi]
// 0054bc73  8b503c               mov edx, dword ptr [eax + 0x3c]
// 0054bc76  6a02                 push 2
// 0054bc78  8bce                 mov ecx, esi
// 0054bc7a  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0054bc81  ffd2                 call edx
// 0054bc83  eb0b                 jmp 0x54bc90
// 0054bc85  b88bbc5400           mov eax, 0x54bc8b
// 0054bc8a  c3                   ret 
// 0054bc8b  8b75ec               mov esi, dword ptr [ebp - 0x14]
// 0054bc8e  33db                 xor ebx, ebx
// 0054bc90  385e44               cmp byte ptr [esi + 0x44], bl
// 0054bc93  7403                 je 0x54bc98
// 0054bc95  885e44               mov byte ptr [esi + 0x44], bl
// 0054bc98  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0054bc9b  895e58               mov dword ptr [esi + 0x58], ebx
// 0054bc9e  5f                   pop edi
// 0054bc9f  5e                   pop esi
// 0054bca0  64890d00000000       mov dword ptr fs:[0], ecx
// 0054bca7  5b                   pop ebx
// 0054bca8  8be5                 mov esp, ebp
// 0054bcaa  5d                   pop ebp
// 0054bcab  c3                   ret 
// copied from an identical function in another client (function ?close@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@QAEXXZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp