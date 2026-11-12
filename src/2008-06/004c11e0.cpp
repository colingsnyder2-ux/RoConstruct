// from server: 100% by auto
// roc 2008-06 004c11e0  unit: ProfiledRakPeer  size: 408 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c11e0
//
// 004c11e0  81ec80000000         sub esp, 0x80
// 004c11e6  53                   push ebx
// 004c11e7  55                   push ebp
// 004c11e8  56                   push esi
// 004c11e9  57                   push edi
// 004c11ea  8b842494000000       mov eax, dword ptr [esp + 0x94]
// 004c11f1  8b08                 mov ecx, dword ptr [eax]
// 004c11f3  8b5004               mov edx, dword ptr [eax + 4]
// 004c11f6  894c2430             mov dword ptr [esp + 0x30], ecx
// 004c11fa  8b4808               mov ecx, dword ptr [eax + 8]
// 004c11fd  89542434             mov dword ptr [esp + 0x34], edx
// 004c1201  8b500c               mov edx, dword ptr [eax + 0xc]
// 004c1204  33c0                 xor eax, eax
// 004c1206  89442440             mov dword ptr [esp + 0x40], eax
// 004c120a  89442444             mov dword ptr [esp + 0x44], eax
// 004c120e  89442448             mov dword ptr [esp + 0x48], eax
// 004c1212  8944244c             mov dword ptr [esp + 0x4c], eax
// 004c1216  8b842498000000       mov eax, dword ptr [esp + 0x98]
// 004c121d  894c2438             mov dword ptr [esp + 0x38], ecx
// 004c1221  8b08                 mov ecx, dword ptr [eax]
// 004c1223  8954243c             mov dword ptr [esp + 0x3c], edx
// 004c1227  8b5004               mov edx, dword ptr [eax + 4]
// 004c122a  894c2470             mov dword ptr [esp + 0x70], ecx
// 004c122e  8b4808               mov ecx, dword ptr [eax + 8]
// 004c1231  89542474             mov dword ptr [esp + 0x74], edx
// 004c1235  8b500c               mov edx, dword ptr [eax + 0xc]
// 004c1238  33c0                 xor eax, eax
// 004c123a  89842480000000       mov dword ptr [esp + 0x80], eax
// 004c1241  89842484000000       mov dword ptr [esp + 0x84], eax
// 004c1248  89842488000000       mov dword ptr [esp + 0x88], eax
// 004c124f  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 004c1256  8b84249c000000       mov eax, dword ptr [esp + 0x9c]
// 004c125d  894c2478             mov dword ptr [esp + 0x78], ecx
// 004c1261  8b08                 mov ecx, dword ptr [eax]
// 004c1263  8954247c             mov dword ptr [esp + 0x7c], edx
// 004c1267  8b5004               mov edx, dword ptr [eax + 4]
// 004c126a  894c2450             mov dword ptr [esp + 0x50], ecx
// 004c126e  8b4808               mov ecx, dword ptr [eax + 8]
// 004c1271  89542454             mov dword ptr [esp + 0x54], edx
// 004c1275  8b500c               mov edx, dword ptr [eax + 0xc]
// 004c1278  33c0                 xor eax, eax
// 004c127a  89442460             mov dword ptr [esp + 0x60], eax
// 004c127e  89442464             mov dword ptr [esp + 0x64], eax
// 004c1282  89442468             mov dword ptr [esp + 0x68], eax
// 004c1286  8944246c             mov dword ptr [esp + 0x6c], eax
// 004c128a  89442414             mov dword ptr [esp + 0x14], eax
// 004c128e  89442418             mov dword ptr [esp + 0x18], eax
// 004c1292  8944241c             mov dword ptr [esp + 0x1c], eax
// 004c1296  89442420             mov dword ptr [esp + 0x20], eax
// 004c129a  89442424             mov dword ptr [esp + 0x24], eax
// 004c129e  89442428             mov dword ptr [esp + 0x28], eax
// 004c12a2  8944242c             mov dword ptr [esp + 0x2c], eax
// 004c12a6  8d442430             lea eax, [esp + 0x30]
// 004c12aa  894c2458             mov dword ptr [esp + 0x58], ecx
// 004c12ae  50                   push eax
// 004c12af  8d4c2454             lea ecx, [esp + 0x54]
// 004c12b3  89542460             mov dword ptr [esp + 0x60], edx
// 004c12b7  51                   push ecx
// 004c12b8  8bd0                 mov edx, eax
// 004c12ba  52                   push edx
// 004c12bb  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 004c12c3  e8d8ceffff           call 0x4be1a0
// 004c12c8  83c40c               add esp, 0xc
// 004c12cb  33f6                 xor esi, esi
// 004c12cd  33ed                 xor ebp, ebp
// 004c12cf  90                   nop 
// 004c12d0  8b5cac70             mov ebx, dword ptr [esp + ebp*4 + 0x70]
// 004c12d4  bf20000000           mov edi, 0x20
// 004c12d9  85db                 test ebx, ebx
// 004c12db  7466                 je 0x4c1343
// 004c12dd  8d4900               lea ecx, [ecx]
// 004c12e0  f6c301               test bl, 1
// 004c12e3  7456                 je 0x4c133b
// 004c12e5  85f6                 test esi, esi
// 004c12e7  742b                 je 0x4c1314
// 004c12e9  8da42400000000       lea esp, [esp]
// 004c12f0  8d442430             lea eax, [esp + 0x30]
// 004c12f4  50                   push eax
// 004c12f5  e8e6b7ffff           call 0x4bcae0
// 004c12fa  8d4c2434             lea ecx, [esp + 0x34]
// 004c12fe  51                   push ecx
// 004c12ff  8d542458             lea edx, [esp + 0x58]
// 004c1303  52                   push edx
// 004c1304  8bc1                 mov eax, ecx
// 004c1306  50                   push eax
// 004c1307  e894ceffff           call 0x4be1a0
// 004c130c  83c410               add esp, 0x10
// 004c130f  83ee01               sub esi, 1
// 004c1312  75dc                 jne 0x4c12f0
// 004c1314  8d4c2410             lea ecx, [esp + 0x10]
// 004c1318  51                   push ecx
// 004c1319  8d542434             lea edx, [esp + 0x34]
// 004c131d  52                   push edx
// 004c131e  8bc1                 mov eax, ecx
// 004c1320  50                   push eax
// 004c1321  e8dae0ffff           call 0x4bf400
// 004c1326  8d4c241c             lea ecx, [esp + 0x1c]
// 004c132a  51                   push ecx
// 004c132b  8d542460             lea edx, [esp + 0x60]
// 004c132f  52                   push edx
// 004c1330  8bc1                 mov eax, ecx
// 004c1332  50                   push eax
// 004c1333  e868ceffff           call 0x4be1a0
// 004c1338  83c418               add esp, 0x18
// 004c133b  d1eb                 shr ebx, 1
// 004c133d  46                   inc esi
// 004c133e  4f                   dec edi
// 004c133f  85db                 test ebx, ebx
// 004c1341  759d                 jne 0x4c12e0
// 004c1343  45                   inc ebp
// 004c1344  03f7                 add esi, edi
// 004c1346  83fd04               cmp ebp, 4
// 004c1349  7285                 jb 0x4c12d0
// 004c134b  8b8424a0000000       mov eax, dword ptr [esp + 0xa0]
// 004c1352  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c1356  8b542414             mov edx, dword ptr [esp + 0x14]
// 004c135a  5f                   pop edi
// 004c135b  8908                 mov dword ptr [eax], ecx
// 004c135d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c1361  895004               mov dword ptr [eax + 4], edx
// 004c1364  8b542418             mov edx, dword ptr [esp + 0x18]
// 004c1368  5e                   pop esi
// 004c1369  5d                   pop ebp
// 004c136a  894808               mov dword ptr [eax + 8], ecx
// 004c136d  89500c               mov dword ptr [eax + 0xc], edx
// 004c1370  5b                   pop ebx
// 004c1371  81c480000000         add esp, 0x80
// 004c1377  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$simpleModExp@$$BY03I@big@@YAXAAY03I000@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
