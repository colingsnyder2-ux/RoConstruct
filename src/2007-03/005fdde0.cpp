// from server: 100% by auto
// roc 2007-03 005fdde0  unit: seg_005f0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fdde0
//
// 005fdde0  56                   push esi
// 005fdde1  e8ba450000           call 0x6023a0
// 005fdde6  6a00                 push 0
// 005fdde8  57                   push edi
// 005fdde9  56                   push esi
// 005fddea  e8e10e0000           call 0x5fecd0
// 005fddef  8b4630               mov eax, dword ptr [esi + 0x30]
// 005fddf2  57                   push edi
// 005fddf3  50                   push eax
// 005fddf4  e897740100           call 0x615290
// 005fddf9  83c418               add esp, 0x18
// 005fddfc  837e105d             cmp dword ptr [esi + 0x10], 0x5d
// 005fde00  7421                 je 0x5fde23
// 005fde02  6a5d                 push 0x5d
// 005fde04  56                   push esi
// 005fde05  e866300000           call 0x600e70
// 005fde0a  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 005fde0d  50                   push eax
// 005fde0e  6828047c00           push 0x7c0428
// 005fde13  51                   push ecx
// 005fde14  e827aaffff           call 0x5f8840
// 005fde19  50                   push eax
// 005fde1a  56                   push esi
// 005fde1b  e850310000           call 0x600f70
// 005fde20  83c41c               add esp, 0x1c
// 005fde23  56                   push esi
// 005fde24  e877450000           call 0x6023a0
// 005fde29  59                   pop ecx
// 005fde2a  c3                   ret 
// library lua-5.1.1/lparser.c (function _yindex)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
