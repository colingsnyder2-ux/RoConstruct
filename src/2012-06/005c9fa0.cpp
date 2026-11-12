// roc 2012-06 005c9fa0  unit: RBX::AdornRbxGfx  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c9fa0
//
// 005c9fa0  33d2                 xor edx, edx
// 005c9fa2  39542408             cmp dword ptr [esp + 8], edx
// 005c9fa6  763d                 jbe 0x5c9fe5
// 005c9fa8  53                   push ebx
// 005c9fa9  0fb75904             movzx ebx, word ptr [ecx + 4]
// 005c9fad  55                   push ebp
// 005c9fae  56                   push esi
// 005c9faf  57                   push edi
// 005c9fb0  0fb77902             movzx edi, word ptr [ecx + 2]
// 005c9fb4  0fb731               movzx esi, word ptr [ecx]
// 005c9fb7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005c9fbb  8bc6                 mov eax, esi
// 005c9fbd  c1e808               shr eax, 8
// 005c9fc0  32042a               xor al, byte ptr [edx + ebp]
// 005c9fc3  42                   inc edx
// 005c9fc4  660fb6e8             movzx bp, al
// 005c9fc8  6603ee               add bp, si
// 005c9fcb  660fafef             imul bp, di
// 005c9fcf  0fb6c0               movzx eax, al
// 005c9fd2  014108               add dword ptr [ecx + 8], eax
// 005c9fd5  6603eb               add bp, bx
// 005c9fd8  668929               mov word ptr [ecx], bp
// 005c9fdb  3b542418             cmp edx, dword ptr [esp + 0x18]
// 005c9fdf  72d3                 jb 0x5c9fb4
// 005c9fe1  5f                   pop edi
// 005c9fe2  5e                   pop esi
// 005c9fe3  5d                   pop ebp
// 005c9fe4  5b                   pop ebx
// 005c9fe5  c20800               ret 8
// library openrbx-raknet/CheckSum.cpp (function ?Add@CheckSum@@QAEXPAEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet CheckSum.cpp
