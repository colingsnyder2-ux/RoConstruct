// from server: 100% by auto
// roc 2012-06 00404140  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404140
//
// 00404140  56                   push esi
// 00404141  8b742408             mov esi, dword ptr [esp + 8]
// 00404145  85f6                 test esi, esi
// 00404147  742f                 je 0x404178
// 00404149  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040414d  85c0                 test eax, eax
// 0040414f  7427                 je 0x404178
// 00404151  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00404155  8b542414             mov edx, dword ptr [esp + 0x14]
// 00404159  6a00                 push 0
// 0040415b  6a00                 push 0
// 0040415d  51                   push ecx
// 0040415e  56                   push esi
// 0040415f  6aff                 push -1
// 00404161  50                   push eax
// 00404162  6a00                 push 0
// 00404164  52                   push edx
// 00404165  c60600               mov byte ptr [esi], 0
// 00404168  ff15c821b200         call dword ptr [0xb221c8]
// 0040416e  f7d8                 neg eax
// 00404170  1bc0                 sbb eax, eax
// 00404172  23c6                 and eax, esi
// 00404174  5e                   pop esi
// 00404175  c21000               ret 0x10
// 00404178  33c0                 xor eax, eax
// 0040417a  5e                   pop esi
// 0040417b  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\olemisc.cpp (function ?AtlW2AHelper@@YGPADPADPB_WHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olemisc.cpp
