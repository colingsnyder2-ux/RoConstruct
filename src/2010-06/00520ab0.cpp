// from server: 100% by auto
// roc 2010-06 00520ab0  unit: CSHA1  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00520ab0
//
// 00520ab0  33d2                 xor edx, edx
// 00520ab2  39542408             cmp dword ptr [esp + 8], edx
// 00520ab6  763d                 jbe 0x520af5
// 00520ab8  53                   push ebx
// 00520ab9  0fb75904             movzx ebx, word ptr [ecx + 4]
// 00520abd  55                   push ebp
// 00520abe  56                   push esi
// 00520abf  57                   push edi
// 00520ac0  0fb77902             movzx edi, word ptr [ecx + 2]
// 00520ac4  0fb731               movzx esi, word ptr [ecx]
// 00520ac7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00520acb  8bc6                 mov eax, esi
// 00520acd  c1e808               shr eax, 8
// 00520ad0  32042a               xor al, byte ptr [edx + ebp]
// 00520ad3  42                   inc edx
// 00520ad4  660fb6e8             movzx bp, al
// 00520ad8  6603ee               add bp, si
// 00520adb  660fafef             imul bp, di
// 00520adf  0fb6c0               movzx eax, al
// 00520ae2  014108               add dword ptr [ecx + 8], eax
// 00520ae5  6603eb               add bp, bx
// 00520ae8  668929               mov word ptr [ecx], bp
// 00520aeb  3b542418             cmp edx, dword ptr [esp + 0x18]
// 00520aef  72d3                 jb 0x520ac4
// 00520af1  5f                   pop edi
// 00520af2  5e                   pop esi
// 00520af3  5d                   pop ebp
// 00520af4  5b                   pop ebx
// 00520af5  c20800               ret 8
// library openrbx-raknet/CheckSum.cpp (function ?Add@CheckSum@@QAEXPAEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet CheckSum.cpp
