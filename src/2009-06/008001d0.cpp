// from server: 100% by auto
// roc 2009-06 008001d0  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008001d0
//
// 008001d0  53                   push ebx
// 008001d1  56                   push esi
// 008001d2  57                   push edi
// 008001d3  8bf1                 mov esi, ecx
// 008001d5  e82e8ef1ff           call 0x719008
// 008001da  ff1578ee8900         call dword ptr [0x89ee78]
// 008001e0  50                   push eax
// 008001e1  e81c8bf1ff           call 0x718d02
// 008001e6  3bc6                 cmp eax, esi
// 008001e8  7407                 je 0x8001f1
// 008001ea  8bce                 mov ecx, esi
// 008001ec  e8e98bf1ff           call 0x718dda
// 008001f1  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 008001f5  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 008001f9  57                   push edi
// 008001fa  53                   push ebx
// 008001fb  8bce                 mov ecx, esi
// 008001fd  e8befaffff           call 0x7ffcc0
// 00800202  83f8ff               cmp eax, -1
// 00800205  7437                 je 0x80023e
// 00800207  57                   push edi
// 00800208  53                   push ebx
// 00800209  8bce                 mov ecx, esi
// 0080020b  e860feffff           call 0x800070
// 00800210  8b4620               mov eax, dword ptr [esi + 0x20]
// 00800213  c7466001000000       mov dword ptr [esi + 0x60], 1
// 0080021a  8b3598ee8900         mov esi, dword ptr [0x89ee98]
// 00800220  50                   push eax
// 00800221  ffd6                 call esi
// 00800223  50                   push eax
// 00800224  e8d98af1ff           call 0x718d02
// 00800229  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0080022c  51                   push ecx
// 0080022d  ffd6                 call esi
// 0080022f  50                   push eax
// 00800230  e8cd8af1ff           call 0x718d02
// 00800235  6a01                 push 1
// 00800237  8bc8                 mov ecx, eax
// 00800239  e8f2c50400           call 0x84c830
// 0080023e  5f                   pop edi
// 0080023f  5e                   pop esi
// 00800240  5b                   pop ebx
// 00800241  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?OnLButtonDblClk@CXTColorHex@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
