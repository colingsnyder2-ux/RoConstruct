// from server: 100% by auto
// roc 2009-12 007d1110  unit: seg_007d0000  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1110
//
// 007d1110  56                   push esi
// 007d1111  8b742408             mov esi, dword ptr [esp + 8]
// 007d1115  833e00               cmp dword ptr [esi], 0
// 007d1118  753f                 jne 0x7d1159
// 007d111a  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d111d  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d1120  8d4c2408             lea ecx, [esp + 8]
// 007d1124  51                   push ecx
// 007d1125  52                   push edx
// 007d1126  50                   push eax
// 007d1127  8b4608               mov eax, dword ptr [esi + 8]
// 007d112a  ffd0                 call eax
// 007d112c  83c40c               add esp, 0xc
// 007d112f  85c0                 test eax, eax
// 007d1131  741a                 je 0x7d114d
// 007d1133  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007d1137  85c9                 test ecx, ecx
// 007d1139  7412                 je 0x7d114d
// 007d113b  49                   dec ecx
// 007d113c  894604               mov dword ptr [esi + 4], eax
// 007d113f  890e                 mov dword ptr [esi], ecx
// 007d1141  0fb610               movzx edx, byte ptr [eax]
// 007d1144  40                   inc eax
// 007d1145  894604               mov dword ptr [esi + 4], eax
// 007d1148  83faff               cmp edx, -1
// 007d114b  7505                 jne 0x7d1152
// 007d114d  83c8ff               or eax, 0xffffffff
// 007d1150  5e                   pop esi
// 007d1151  c3                   ret 
// 007d1152  41                   inc ecx
// 007d1153  48                   dec eax
// 007d1154  890e                 mov dword ptr [esi], ecx
// 007d1156  894604               mov dword ptr [esi + 4], eax
// 007d1159  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d115c  0fb601               movzx eax, byte ptr [ecx]
// 007d115f  5e                   pop esi
// 007d1160  c3                   ret 
// library lua-5.1/lzio.c (function _luaZ_lookahead)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lzio.c
