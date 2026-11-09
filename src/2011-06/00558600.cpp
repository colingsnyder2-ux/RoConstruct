// from server: 100% by auto
// roc 2011-06 00558600  unit: seg_00550000  size: 489 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00558600
//
// 00558600  55                   push ebp
// 00558601  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00558605  85ed                 test ebp, ebp
// 00558607  0f84da010000         je 0x5587e7
// 0055860d  56                   push esi
// 0055860e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00558612  85f6                 test esi, esi
// 00558614  0f84cc010000         je 0x5587e6
// 0055861a  f7456800040000       test dword ptr [ebp + 0x68], 0x400
// 00558621  0f85bf010000         jne 0x5587e6
// 00558627  57                   push edi
// 00558628  55                   push ebp
// 00558629  e812230100           call 0x56a940
// 0055862e  bf00100000           mov edi, 0x1000
// 00558633  83c404               add esp, 4
// 00558636  857d68               test dword ptr [ebp + 0x68], edi
// 00558639  7421                 je 0x55865c
// 0055863b  83bd3002000000       cmp dword ptr [ebp + 0x230], 0
// 00558642  7418                 je 0x55865c
// 00558644  68681fa800           push 0xa81f68
// 00558649  55                   push ebp
// 0055864a  e8918d0000           call 0x5613e0
// 0055864f  83c408               add esp, 8
// 00558652  c7853002000000000000 mov dword ptr [ebp + 0x230], 0
// 0055865c  0fb6461c             movzx eax, byte ptr [esi + 0x1c]
// 00558660  0fb64e1b             movzx ecx, byte ptr [esi + 0x1b]
// 00558664  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 00558668  50                   push eax
// 00558669  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0055866d  51                   push ecx
// 0055866e  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 00558672  52                   push edx
// 00558673  8b5604               mov edx, dword ptr [esi + 4]
// 00558676  50                   push eax
// 00558677  8b06                 mov eax, dword ptr [esi]
// 00558679  51                   push ecx
// 0055867a  52                   push edx
// 0055867b  50                   push eax
// 0055867c  55                   push ebp
// 0055867d  e80e350100           call 0x56bb90
// 00558682  83c420               add esp, 0x20
// 00558685  f6460801             test byte ptr [esi + 8], 1
// 00558689  7412                 je 0x55869d
// 0055868b  d94628               fld dword ptr [esi + 0x28]
// 0055868e  83ec08               sub esp, 8
// 00558691  dd1c24               fstp qword ptr [esp]
// 00558694  55                   push ebp
// 00558695  e8e63a0100           call 0x56c180
// 0055869a  83c40c               add esp, 0xc
// 0055869d  f7460800080000       test dword ptr [esi + 8], 0x800
// 005586a4  740e                 je 0x5586b4
// 005586a6  0fb64e2c             movzx ecx, byte ptr [esi + 0x2c]
// 005586aa  51                   push ecx
// 005586ab  55                   push ebp
// 005586ac  e8af3b0100           call 0x56c260
// 005586b1  83c408               add esp, 8
// 005586b4  857e08               test dword ptr [esi + 8], edi
// 005586b7  7420                 je 0x5586d9
// 005586b9  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 005586bf  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 005586c5  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 005586cb  52                   push edx
// 005586cc  50                   push eax
// 005586cd  6a00                 push 0
// 005586cf  51                   push ecx
// 005586d0  55                   push ebp
// 005586d1  e83a3c0100           call 0x56c310
// 005586d6  83c414               add esp, 0x14
// 005586d9  f6460802             test byte ptr [esi + 8], 2
// 005586dd  7412                 je 0x5586f1
// 005586df  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 005586e3  52                   push edx
// 005586e4  8d4644               lea eax, [esi + 0x44]
// 005586e7  50                   push eax
// 005586e8  55                   push ebp
// 005586e9  e8823f0100           call 0x56c670
// 005586ee  83c40c               add esp, 0xc
// 005586f1  f6460804             test byte ptr [esi + 8], 4
// 005586f5  745b                 je 0x558752
// 005586f7  d9869c000000         fld dword ptr [esi + 0x9c]
// 005586fd  83ec40               sub esp, 0x40
// 00558700  dd5c2438             fstp qword ptr [esp + 0x38]
// 00558704  d98698000000         fld dword ptr [esi + 0x98]
// 0055870a  dd5c2430             fstp qword ptr [esp + 0x30]
// 0055870e  d98694000000         fld dword ptr [esi + 0x94]
// 00558714  dd5c2428             fstp qword ptr [esp + 0x28]
// 00558718  d98690000000         fld dword ptr [esi + 0x90]
// 0055871e  dd5c2420             fstp qword ptr [esp + 0x20]
// 00558722  d9868c000000         fld dword ptr [esi + 0x8c]
// 00558728  dd5c2418             fstp qword ptr [esp + 0x18]
// 0055872c  d98688000000         fld dword ptr [esi + 0x88]
// 00558732  dd5c2410             fstp qword ptr [esp + 0x10]
// 00558736  d98684000000         fld dword ptr [esi + 0x84]
// 0055873c  dd5c2408             fstp qword ptr [esp + 8]
// 00558740  d98680000000         fld dword ptr [esi + 0x80]
// 00558746  dd1c24               fstp qword ptr [esp]
// 00558749  55                   push ebp
// 0055874a  e801400100           call 0x56c750
// 0055874f  83c444               add esp, 0x44
// 00558752  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00558758  85c0                 test eax, eax
// 0055875a  0f847e000000         je 0x5587de
// 00558760  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00558766  8d0c80               lea ecx, [eax + eax*4]
// 00558769  8d148f               lea edx, [edi + ecx*4]
// 0055876c  3bfa                 cmp edi, edx
// 0055876e  736e                 jae 0x5587de
// 00558770  57                   push edi
// 00558771  55                   push ebp
// 00558772  e84985ffff           call 0x550cc0
// 00558777  83c408               add esp, 8
// 0055877a  83f801               cmp eax, 1
// 0055877d  7446                 je 0x5587c5
// 0055877f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00558782  84c9                 test cl, cl
// 00558784  743f                 je 0x5587c5
// 00558786  f6c106               test cl, 6
// 00558789  753a                 jne 0x5587c5
// 0055878b  f6470320             test byte ptr [edi + 3], 0x20
// 0055878f  750e                 jne 0x55879f
// 00558791  83f803               cmp eax, 3
// 00558794  7409                 je 0x55879f
// 00558796  f7456c00000100       test dword ptr [ebp + 0x6c], 0x10000
// 0055879d  7426                 je 0x5587c5
// 0055879f  837f0c00             cmp dword ptr [edi + 0xc], 0
// 005587a3  750e                 jne 0x5587b3
// 005587a5  68441fa800           push 0xa81f44
// 005587aa  55                   push ebp
// 005587ab  e8308c0000           call 0x5613e0
// 005587b0  83c408               add esp, 8
// 005587b3  8b470c               mov eax, dword ptr [edi + 0xc]
// 005587b6  8b4f08               mov ecx, dword ptr [edi + 8]
// 005587b9  50                   push eax
// 005587ba  51                   push ecx
// 005587bb  57                   push edi
// 005587bc  55                   push ebp
// 005587bd  e84e330100           call 0x56bb10
// 005587c2  83c410               add esp, 0x10
// 005587c5  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 005587cb  8d1480               lea edx, [eax + eax*4]
// 005587ce  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 005587d4  83c714               add edi, 0x14
// 005587d7  8d0c90               lea ecx, [eax + edx*4]
// 005587da  3bf9                 cmp edi, ecx
// 005587dc  7292                 jb 0x558770
// 005587de  814d6800040000       or dword ptr [ebp + 0x68], 0x400
// 005587e5  5f                   pop edi
// 005587e6  5e                   pop esi
// 005587e7  5d                   pop ebp
// 005587e8  c3                   ret 
// library libpng-1.2.29/pngwrite.c (function _png_write_info_before_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngwrite.c
