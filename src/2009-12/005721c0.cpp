// from server: 100% by auto
// roc 2009-12 005721c0  unit: CSHA1  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005721c0
//
// 005721c0  33d2                 xor edx, edx
// 005721c2  39542408             cmp dword ptr [esp + 8], edx
// 005721c6  763d                 jbe 0x572205
// 005721c8  53                   push ebx
// 005721c9  0fb75904             movzx ebx, word ptr [ecx + 4]
// 005721cd  55                   push ebp
// 005721ce  56                   push esi
// 005721cf  57                   push edi
// 005721d0  0fb77902             movzx edi, word ptr [ecx + 2]
// 005721d4  0fb731               movzx esi, word ptr [ecx]
// 005721d7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005721db  8bc6                 mov eax, esi
// 005721dd  c1e808               shr eax, 8
// 005721e0  32042a               xor al, byte ptr [edx + ebp]
// 005721e3  42                   inc edx
// 005721e4  660fb6e8             movzx bp, al
// 005721e8  6603ee               add bp, si
// 005721eb  660fafef             imul bp, di
// 005721ef  0fb6c0               movzx eax, al
// 005721f2  014108               add dword ptr [ecx + 8], eax
// 005721f5  6603eb               add bp, bx
// 005721f8  668929               mov word ptr [ecx], bp
// 005721fb  3b542418             cmp edx, dword ptr [esp + 0x18]
// 005721ff  72d3                 jb 0x5721d4
// 00572201  5f                   pop edi
// 00572202  5e                   pop esi
// 00572203  5d                   pop ebp
// 00572204  5b                   pop ebx
// 00572205  c20800               ret 8
// library raknet-4.081/CheckSum.cpp (function ?Add@CheckSum@@QAEXPAEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CheckSum.cpp
