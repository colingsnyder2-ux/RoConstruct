// from server: 100% by auto
// roc 2007-03 005c34b0  unit: seg_005c0000  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c34b0
//
// 005c34b0  53                   push ebx
// 005c34b1  56                   push esi
// 005c34b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005c34b6  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005c34b9  57                   push edi
// 005c34ba  8bfe                 mov edi, esi
// 005c34bc  e86fffffff           call 0x5c3430
// 005c34c1  6a02                 push 2
// 005c34c3  6a00                 push 0
// 005c34c5  56                   push esi
// 005c34c6  e865880300           call 0x5fbd30
// 005c34cb  6a02                 push 2
// 005c34cd  894648               mov dword ptr [esi + 0x48], eax
// 005c34d0  c7465005000000       mov dword ptr [esi + 0x50], 5
// 005c34d7  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005c34da  6a00                 push 0
// 005c34dc  56                   push esi
// 005c34dd  83c760               add edi, 0x60
// 005c34e0  e84b880300           call 0x5fbd30
// 005c34e5  6a20                 push 0x20
// 005c34e7  56                   push esi
// 005c34e8  8907                 mov dword ptr [edi], eax
// 005c34ea  c7470805000000       mov dword ptr [edi + 8], 5
// 005c34f1  e8ca900300           call 0x5fc5c0
// 005c34f6  56                   push esi
// 005c34f7  e894640300           call 0x5f9990
// 005c34fc  56                   push esi
// 005c34fd  e81ed90300           call 0x600e20
// 005c3502  6a11                 push 0x11
// 005c3504  68f4967b00           push 0x7b96f4
// 005c3509  56                   push esi
// 005c350a  e811920300           call 0x5fc720
// 005c350f  80480520             or byte ptr [eax + 5], 0x20
// 005c3513  83c005               add eax, 5
// 005c3516  8b4344               mov eax, dword ptr [ebx + 0x44]
// 005c3519  83c434               add esp, 0x34
// 005c351c  03c0                 add eax, eax
// 005c351e  5f                   pop edi
// 005c351f  03c0                 add eax, eax
// 005c3521  5e                   pop esi
// 005c3522  894340               mov dword ptr [ebx + 0x40], eax
// 005c3525  5b                   pop ebx
// 005c3526  c3                   ret 
// library lua-5.1.1/lstate.c (function _f_luaopen)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstate.c
