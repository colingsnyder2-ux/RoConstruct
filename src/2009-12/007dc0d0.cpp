// from server: 100% by auto
// roc 2009-12 007dc0d0  unit: RBX::GroupDragTool  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc0d0
//
// 007dc0d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dc0d4  83f8ff               cmp eax, -1
// 007dc0d7  743e                 je 0x7dc117
// 007dc0d9  8b542408             mov edx, dword ptr [esp + 8]
// 007dc0dd  8b0a                 mov ecx, dword ptr [edx]
// 007dc0df  83f9ff               cmp ecx, -1
// 007dc0e2  7503                 jne 0x7dc0e7
// 007dc0e4  8902                 mov dword ptr [edx], eax
// 007dc0e6  c3                   ret 
// 007dc0e7  53                   push ebx
// 007dc0e8  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007dc0ec  8b13                 mov edx, dword ptr [ebx]
// 007dc0ee  56                   push esi
// 007dc0ef  8b720c               mov esi, dword ptr [edx + 0xc]
// 007dc0f2  8b148e               mov edx, dword ptr [esi + ecx*4]
// 007dc0f5  c1ea0e               shr edx, 0xe
// 007dc0f8  81eaffff0100         sub edx, 0x1ffff
// 007dc0fe  83faff               cmp edx, -1
// 007dc101  740d                 je 0x7dc110
// 007dc103  8d540a01             lea edx, [edx + ecx + 1]
// 007dc107  83faff               cmp edx, -1
// 007dc10a  7404                 je 0x7dc110
// 007dc10c  8bca                 mov ecx, edx
// 007dc10e  ebe2                 jmp 0x7dc0f2
// 007dc110  e82bfdffff           call 0x7dbe40
// 007dc115  5e                   pop esi
// 007dc116  5b                   pop ebx
// 007dc117  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_concat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
