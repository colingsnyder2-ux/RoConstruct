// from server: 100% by auto
// roc 2007-03 005fdb50  unit: seg_005f0000  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fdb50
//
// 005fdb50  55                   push ebp
// 005fdb51  56                   push esi
// 005fdb52  57                   push edi
// 005fdb53  8b7b34               mov edi, dword ptr [ebx + 0x34]
// 005fdb56  57                   push edi
// 005fdb57  8bf0                 mov esi, eax
// 005fdb59  e8b2efffff           call 0x5fcb10
// 005fdb5e  8be8                 mov ebp, eax
// 005fdb60  892e                 mov dword ptr [esi], ebp
// 005fdb62  8b4330               mov eax, dword ptr [ebx + 0x30]
// 005fdb65  894608               mov dword ptr [esi + 8], eax
// 005fdb68  33c0                 xor eax, eax
// 005fdb6a  895e0c               mov dword ptr [esi + 0xc], ebx
// 005fdb6d  897e10               mov dword ptr [esi + 0x10], edi
// 005fdb70  897330               mov dword ptr [ebx + 0x30], esi
// 005fdb73  83c9ff               or ecx, 0xffffffff
// 005fdb76  50                   push eax
// 005fdb77  894618               mov dword ptr [esi + 0x18], eax
// 005fdb7a  894e1c               mov dword ptr [esi + 0x1c], ecx
// 005fdb7d  894e20               mov dword ptr [esi + 0x20], ecx
// 005fdb80  894624               mov dword ptr [esi + 0x24], eax
// 005fdb83  894628               mov dword ptr [esi + 0x28], eax
// 005fdb86  89462c               mov dword ptr [esi + 0x2c], eax
// 005fdb89  66894630             mov word ptr [esi + 0x30], ax
// 005fdb8d  884632               mov byte ptr [esi + 0x32], al
// 005fdb90  894614               mov dword ptr [esi + 0x14], eax
// 005fdb93  8b4b40               mov ecx, dword ptr [ebx + 0x40]
// 005fdb96  50                   push eax
// 005fdb97  57                   push edi
// 005fdb98  894d20               mov dword ptr [ebp + 0x20], ecx
// 005fdb9b  c6454b02             mov byte ptr [ebp + 0x4b], 2
// 005fdb9f  e88ce1ffff           call 0x5fbd30
// 005fdba4  894604               mov dword ptr [esi + 4], eax
// 005fdba7  8b4f08               mov ecx, dword ptr [edi + 8]
// 005fdbaa  8901                 mov dword ptr [ecx], eax
// 005fdbac  c7410805000000       mov dword ptr [ecx + 8], 5
// 005fdbb3  8b571c               mov edx, dword ptr [edi + 0x1c]
// 005fdbb6  2b5708               sub edx, dword ptr [edi + 8]
// 005fdbb9  be10000000           mov esi, 0x10
// 005fdbbe  83c410               add esp, 0x10
// 005fdbc1  3bd6                 cmp edx, esi
// 005fdbc3  7f0b                 jg 0x5fdbd0
// 005fdbc5  6a01                 push 1
// 005fdbc7  57                   push edi
// 005fdbc8  e82321fcff           call 0x5bfcf0
// 005fdbcd  83c408               add esp, 8
// 005fdbd0  017708               add dword ptr [edi + 8], esi
// 005fdbd3  8b4708               mov eax, dword ptr [edi + 8]
// 005fdbd6  8928                 mov dword ptr [eax], ebp
// 005fdbd8  c7400809000000       mov dword ptr [eax + 8], 9
// 005fdbdf  8b471c               mov eax, dword ptr [edi + 0x1c]
// 005fdbe2  2b4708               sub eax, dword ptr [edi + 8]
// 005fdbe5  3bc6                 cmp eax, esi
// 005fdbe7  7f0b                 jg 0x5fdbf4
// 005fdbe9  6a01                 push 1
// 005fdbeb  57                   push edi
// 005fdbec  e8ff20fcff           call 0x5bfcf0
// 005fdbf1  83c408               add esp, 8
// 005fdbf4  017708               add dword ptr [edi + 8], esi
// 005fdbf7  5f                   pop edi
// 005fdbf8  5e                   pop esi
// 005fdbf9  5d                   pop ebp
// 005fdbfa  c3                   ret 
// library lua-5.1.1/lparser.c (function _open_func)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
