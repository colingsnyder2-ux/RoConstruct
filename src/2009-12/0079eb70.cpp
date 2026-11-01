// from server: 100% by auto
// roc 2009-12 0079eb70  unit: seg_00790000  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079eb70
//
// 0079eb70  83ec64               sub esp, 0x64
// 0079eb73  6a01                 push 1
// 0079eb75  56                   push esi
// 0079eb76  e8159efeff           call 0x788990
// 0079eb7b  83c408               add esp, 8
// 0079eb7e  83f806               cmp eax, 6
// 0079eb81  750f                 jne 0x79eb92
// 0079eb83  6a01                 push 1
// 0079eb85  56                   push esi
// 0079eb86  e8d59dfeff           call 0x788960
// 0079eb8b  83c408               add esp, 8
// 0079eb8e  83c464               add esp, 0x64
// 0079eb91  c3                   ret 
// 0079eb92  837c246800           cmp dword ptr [esp + 0x68], 0
// 0079eb97  57                   push edi
// 0079eb98  6a01                 push 1
// 0079eb9a  740d                 je 0x79eba9
// 0079eb9c  6a01                 push 1
// 0079eb9e  56                   push esi
// 0079eb9f  e87cbdfeff           call 0x78a920
// 0079eba4  83c40c               add esp, 0xc
// 0079eba7  eb09                 jmp 0x79ebb2
// 0079eba9  56                   push esi
// 0079ebaa  e801bdfeff           call 0x78a8b0
// 0079ebaf  83c408               add esp, 8
// 0079ebb2  8bf8                 mov edi, eax
// 0079ebb4  85ff                 test edi, edi
// 0079ebb6  7d10                 jge 0x79ebc8
// 0079ebb8  6844b59e00           push 0x9eb544
// 0079ebbd  6a01                 push 1
// 0079ebbf  56                   push esi
// 0079ebc0  e8bbb9feff           call 0x78a580
// 0079ebc5  83c40c               add esp, 0xc
// 0079ebc8  8d442404             lea eax, [esp + 4]
// 0079ebcc  50                   push eax
// 0079ebcd  57                   push edi
// 0079ebce  56                   push esi
// 0079ebcf  e8ccbbffff           call 0x79a7a0
// 0079ebd4  83c40c               add esp, 0xc
// 0079ebd7  85c0                 test eax, eax
// 0079ebd9  7510                 jne 0x79ebeb
// 0079ebdb  6834b59e00           push 0x9eb534
// 0079ebe0  6a01                 push 1
// 0079ebe2  56                   push esi
// 0079ebe3  e898b9feff           call 0x78a580
// 0079ebe8  83c40c               add esp, 0xc
// 0079ebeb  8d4c2404             lea ecx, [esp + 4]
// 0079ebef  51                   push ecx
// 0079ebf0  6830b59e00           push 0x9eb530
// 0079ebf5  56                   push esi
// 0079ebf6  e8c5c8ffff           call 0x79b4c0
// 0079ebfb  6aff                 push -1
// 0079ebfd  56                   push esi
// 0079ebfe  e88d9dfeff           call 0x788990
// 0079ec03  83c414               add esp, 0x14
// 0079ec06  85c0                 test eax, eax
// 0079ec08  750f                 jne 0x79ec19
// 0079ec0a  57                   push edi
// 0079ec0b  68fcb49e00           push 0x9eb4fc
// 0079ec10  56                   push esi
// 0079ec11  e8dab0feff           call 0x789cf0
// 0079ec16  83c40c               add esp, 0xc
// 0079ec19  5f                   pop edi
// 0079ec1a  83c464               add esp, 0x64
// 0079ec1d  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _getfunc)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
