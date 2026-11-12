// from server: 100% by auto
// roc 2009-06 00513470  unit: CSHA1  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00513470
//
// 00513470  33d2                 xor edx, edx
// 00513472  39542408             cmp dword ptr [esp + 8], edx
// 00513476  763d                 jbe 0x5134b5
// 00513478  53                   push ebx
// 00513479  0fb75904             movzx ebx, word ptr [ecx + 4]
// 0051347d  55                   push ebp
// 0051347e  56                   push esi
// 0051347f  57                   push edi
// 00513480  0fb77902             movzx edi, word ptr [ecx + 2]
// 00513484  0fb731               movzx esi, word ptr [ecx]
// 00513487  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0051348b  8bc6                 mov eax, esi
// 0051348d  c1e808               shr eax, 8
// 00513490  32042a               xor al, byte ptr [edx + ebp]
// 00513493  42                   inc edx
// 00513494  660fb6e8             movzx bp, al
// 00513498  6603ee               add bp, si
// 0051349b  660fafef             imul bp, di
// 0051349f  0fb6c0               movzx eax, al
// 005134a2  014108               add dword ptr [ecx + 8], eax
// 005134a5  6603eb               add bp, bx
// 005134a8  668929               mov word ptr [ecx], bp
// 005134ab  3b542418             cmp edx, dword ptr [esp + 0x18]
// 005134af  72d3                 jb 0x513484
// 005134b1  5f                   pop edi
// 005134b2  5e                   pop esi
// 005134b3  5d                   pop ebp
// 005134b4  5b                   pop ebx
// 005134b5  c20800               ret 8
// library openrbx-raknet/CheckSum.cpp (function ?Add@CheckSum@@QAEXPAEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet CheckSum.cpp
