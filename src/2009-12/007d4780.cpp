// from server: 100% by auto
// roc 2009-12 007d4780  unit: seg_007d0000  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d4780
//
// 007d4780  51                   push ecx
// 007d4781  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d4784  6a04                 push 4
// 007d4786  8d442404             lea eax, [esp + 4]
// 007d478a  50                   push eax
// 007d478b  51                   push ecx
// 007d478c  e80fcaffff           call 0x7d11a0
// 007d4791  83c40c               add esp, 0xc
// 007d4794  85c0                 test eax, eax
// 007d4796  7423                 je 0x7d47bb
// 007d4798  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d479b  8b06                 mov eax, dword ptr [esi]
// 007d479d  6858f09e00           push 0x9ef058
// 007d47a2  52                   push edx
// 007d47a3  683cf09e00           push 0x9ef03c
// 007d47a8  50                   push eax
// 007d47a9  e8d25dfcff           call 0x79a580
// 007d47ae  8b0e                 mov ecx, dword ptr [esi]
// 007d47b0  6a03                 push 3
// 007d47b2  51                   push ecx
// 007d47b3  e89830fcff           call 0x797850
// 007d47b8  83c418               add esp, 0x18
// 007d47bb  8b0424               mov eax, dword ptr [esp]
// 007d47be  85c0                 test eax, eax
// 007d47c0  7502                 jne 0x7d47c4
// 007d47c2  59                   pop ecx
// 007d47c3  c3                   ret 
// 007d47c4  8b5608               mov edx, dword ptr [esi + 8]
// 007d47c7  57                   push edi
// 007d47c8  50                   push eax
// 007d47c9  8b06                 mov eax, dword ptr [esi]
// 007d47cb  52                   push edx
// 007d47cc  50                   push eax
// 007d47cd  e85ecaffff           call 0x7d1230
// 007d47d2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007d47d6  8b5604               mov edx, dword ptr [esi + 4]
// 007d47d9  51                   push ecx
// 007d47da  8bf8                 mov edi, eax
// 007d47dc  57                   push edi
// 007d47dd  52                   push edx
// 007d47de  e8bdc9ffff           call 0x7d11a0
// 007d47e3  83c418               add esp, 0x18
// 007d47e6  85c0                 test eax, eax
// 007d47e8  7423                 je 0x7d480d
// 007d47ea  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d47ed  8b0e                 mov ecx, dword ptr [esi]
// 007d47ef  6858f09e00           push 0x9ef058
// 007d47f4  50                   push eax
// 007d47f5  683cf09e00           push 0x9ef03c
// 007d47fa  51                   push ecx
// 007d47fb  e8805dfcff           call 0x79a580
// 007d4800  8b16                 mov edx, dword ptr [esi]
// 007d4802  6a03                 push 3
// 007d4804  52                   push edx
// 007d4805  e84630fcff           call 0x797850
// 007d480a  83c418               add esp, 0x18
// 007d480d  8b442404             mov eax, dword ptr [esp + 4]
// 007d4811  8b0e                 mov ecx, dword ptr [esi]
// 007d4813  48                   dec eax
// 007d4814  50                   push eax
// 007d4815  57                   push edi
// 007d4816  51                   push ecx
// 007d4817  e874c3ffff           call 0x7d0b90
// 007d481c  83c40c               add esp, 0xc
// 007d481f  5f                   pop edi
// 007d4820  59                   pop ecx
// 007d4821  c3                   ret 
// library lua-5.1/lundump.c (function _LoadString)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lundump.c
