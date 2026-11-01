// from server: 100% by auto
// roc 2007-03 00614db0  unit: seg_00610000  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614db0
//
// 00614db0  c1e009               shl eax, 9
// 00614db3  0b44240c             or eax, dword ptr [esp + 0xc]
// 00614db7  56                   push esi
// 00614db8  c1e008               shl eax, 8
// 00614dbb  0b44240c             or eax, dword ptr [esp + 0xc]
// 00614dbf  8bf1                 mov esi, ecx
// 00614dc1  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00614dc4  8b5108               mov edx, dword ptr [ecx + 8]
// 00614dc7  c1e006               shl eax, 6
// 00614dca  0b442408             or eax, dword ptr [esp + 8]
// 00614dce  57                   push edi
// 00614dcf  52                   push edx
// 00614dd0  50                   push eax
// 00614dd1  e83afdffff           call 0x614b10
// 00614dd6  8b7e20               mov edi, dword ptr [esi + 0x20]
// 00614dd9  8b460c               mov eax, dword ptr [esi + 0xc]
// 00614ddc  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 00614de3  8b4808               mov ecx, dword ptr [eax + 8]
// 00614de6  51                   push ecx
// 00614de7  681680ff7f           push 0x7fff8016
// 00614dec  e81ffdffff           call 0x614b10
// 00614df1  57                   push edi
// 00614df2  8d542428             lea edx, [esp + 0x28]
// 00614df6  52                   push edx
// 00614df7  56                   push esi
// 00614df8  89442430             mov dword ptr [esp + 0x30], eax
// 00614dfc  e84ff8ffff           call 0x614650
// 00614e01  8b442430             mov eax, dword ptr [esp + 0x30]
// 00614e05  83c41c               add esp, 0x1c
// 00614e08  5f                   pop edi
// 00614e09  5e                   pop esi
// 00614e0a  c3                   ret 
// library lua-5.1.1/lcode.c (function _condjump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
