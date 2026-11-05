// from server: 100% by auto
// roc 2011-06 00403530  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403530
//
// 00403530  56                   push esi
// 00403531  8b742408             mov esi, dword ptr [esp + 8]
// 00403535  85f6                 test esi, esi
// 00403537  742f                 je 0x403568
// 00403539  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040353d  85c0                 test eax, eax
// 0040353f  7427                 je 0x403568
// 00403541  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00403545  8b542414             mov edx, dword ptr [esp + 0x14]
// 00403549  6a00                 push 0
// 0040354b  6a00                 push 0
// 0040354d  51                   push ecx
// 0040354e  56                   push esi
// 0040354f  6aff                 push -1
// 00403551  50                   push eax
// 00403552  6a00                 push 0
// 00403554  52                   push edx
// 00403555  c60600               mov byte ptr [esi], 0
// 00403558  ff158c03a400         call dword ptr [0xa4038c]
// 0040355e  f7d8                 neg eax
// 00403560  1bc0                 sbb eax, eax
// 00403562  23c6                 and eax, esi
// 00403564  5e                   pop esi
// 00403565  c21000               ret 0x10
// 00403568  33c0                 xor eax, eax
// 0040356a  5e                   pop esi
// 0040356b  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\olemisc.cpp (function ?AtlW2AHelper@@YGPADPADPB_WHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olemisc.cpp
