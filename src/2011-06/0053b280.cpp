// from server: 100% by auto
// roc 2011-06 0053b280  unit: seg_00530000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053b280
//
// 0053b280  33d2                 xor edx, edx
// 0053b282  39542408             cmp dword ptr [esp + 8], edx
// 0053b286  763d                 jbe 0x53b2c5
// 0053b288  53                   push ebx
// 0053b289  0fb75904             movzx ebx, word ptr [ecx + 4]
// 0053b28d  55                   push ebp
// 0053b28e  56                   push esi
// 0053b28f  57                   push edi
// 0053b290  0fb77902             movzx edi, word ptr [ecx + 2]
// 0053b294  0fb731               movzx esi, word ptr [ecx]
// 0053b297  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0053b29b  8bc6                 mov eax, esi
// 0053b29d  c1e808               shr eax, 8
// 0053b2a0  32042a               xor al, byte ptr [edx + ebp]
// 0053b2a3  42                   inc edx
// 0053b2a4  660fb6e8             movzx bp, al
// 0053b2a8  6603ee               add bp, si
// 0053b2ab  660fafef             imul bp, di
// 0053b2af  0fb6c0               movzx eax, al
// 0053b2b2  014108               add dword ptr [ecx + 8], eax
// 0053b2b5  6603eb               add bp, bx
// 0053b2b8  668929               mov word ptr [ecx], bp
// 0053b2bb  3b542418             cmp edx, dword ptr [esp + 0x18]
// 0053b2bf  72d3                 jb 0x53b294
// 0053b2c1  5f                   pop edi
// 0053b2c2  5e                   pop esi
// 0053b2c3  5d                   pop ebp
// 0053b2c4  5b                   pop ebx
// 0053b2c5  c20800               ret 8
// library openrbx-raknet/CheckSum.cpp (function ?Add@CheckSum@@QAEXPAEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet CheckSum.cpp
