// from server: 100% by auto
// roc 2008-06 004d6f00  unit: CSHA1  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d6f00
//
// 004d6f00  33d2                 xor edx, edx
// 004d6f02  39542408             cmp dword ptr [esp + 8], edx
// 004d6f06  763d                 jbe 0x4d6f45
// 004d6f08  53                   push ebx
// 004d6f09  0fb75904             movzx ebx, word ptr [ecx + 4]
// 004d6f0d  55                   push ebp
// 004d6f0e  56                   push esi
// 004d6f0f  57                   push edi
// 004d6f10  0fb77902             movzx edi, word ptr [ecx + 2]
// 004d6f14  0fb731               movzx esi, word ptr [ecx]
// 004d6f17  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004d6f1b  8bc6                 mov eax, esi
// 004d6f1d  c1e808               shr eax, 8
// 004d6f20  32042a               xor al, byte ptr [edx + ebp]
// 004d6f23  42                   inc edx
// 004d6f24  660fb6e8             movzx bp, al
// 004d6f28  6603ee               add bp, si
// 004d6f2b  660fafef             imul bp, di
// 004d6f2f  0fb6c0               movzx eax, al
// 004d6f32  014108               add dword ptr [ecx + 8], eax
// 004d6f35  6603eb               add bp, bx
// 004d6f38  668929               mov word ptr [ecx], bp
// 004d6f3b  3b542418             cmp edx, dword ptr [esp + 0x18]
// 004d6f3f  72d3                 jb 0x4d6f14
// 004d6f41  5f                   pop edi
// 004d6f42  5e                   pop esi
// 004d6f43  5d                   pop ebp
// 004d6f44  5b                   pop ebx
// 004d6f45  c20800               ret 8
// library openrbx-raknet/CheckSum.cpp (function ?Add@CheckSum@@QAEXPAEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet CheckSum.cpp
