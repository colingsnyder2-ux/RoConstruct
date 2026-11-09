// from server: 100% by auto
// roc 2010-06 005f1210  unit: TextXmlWriter  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005f1210
//
// 005f1210  83ec14               sub esp, 0x14
// 005f1213  56                   push esi
// 005f1214  8bf1                 mov esi, ecx
// 005f1216  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 005f121a  57                   push edi
// 005f121b  7521                 jne 0x5f123e
// 005f121d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005f1221  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005f1224  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005f1228  50                   push eax
// 005f1229  51                   push ecx
// 005f122a  6a01                 push 1
// 005f122c  57                   push edi
// 005f122d  8bce                 mov ecx, esi
// 005f122f  e81cf8ffff           call 0x5f0a50
// 005f1234  8bc7                 mov eax, edi
// 005f1236  5f                   pop edi
// 005f1237  5e                   pop esi
// 005f1238  83c414               add esp, 0x14
// 005f123b  c21000               ret 0x10
// 005f123e  8b442424             mov eax, dword ptr [esp + 0x24]
// 005f1242  8b5618               mov edx, dword ptr [esi + 0x18]
// 005f1245  8b3a                 mov edi, dword ptr [edx]
// 005f1247  8b0e                 mov ecx, dword ptr [esi]
// 005f1249  53                   push ebx
// 005f124a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 005f1250  85c0                 test eax, eax
// 005f1252  7404                 je 0x5f1258
// 005f1254  3bc1                 cmp eax, ecx
// 005f1256  7406                 je 0x5f125e
// 005f1258  ffd3                 call ebx
// 005f125a  8b442428             mov eax, dword ptr [esp + 0x28]
// 005f125e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005f1262  55                   push ebp
// 005f1263  3bd7                 cmp edx, edi
// 005f1265  753a                 jne 0x5f12a1
// 005f1267  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005f126b  83c20c               add edx, 0xc
// 005f126e  52                   push edx
// 005f126f  57                   push edi
// 005f1270  ff151ca59e00         call dword ptr [0x9ea51c]
// 005f1276  83c408               add esp, 8
// 005f1279  84c0                 test al, al
// 005f127b  0f849a010000         je 0x5f141b
// 005f1281  8b442430             mov eax, dword ptr [esp + 0x30]
// 005f1285  57                   push edi
// 005f1286  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005f128a  50                   push eax
// 005f128b  6a01                 push 1
// 005f128d  57                   push edi
// 005f128e  8bce                 mov ecx, esi
// 005f1290  e8bbf7ffff           call 0x5f0a50
// 005f1295  5d                   pop ebp
// 005f1296  5b                   pop ebx
// 005f1297  8bc7                 mov eax, edi
// 005f1299  5f                   pop edi
// 005f129a  5e                   pop esi
// 005f129b  83c414               add esp, 0x14
// 005f129e  c21000               ret 0x10
// 005f12a1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005f12a4  8b0e                 mov ecx, dword ptr [esi]
// 005f12a6  85c0                 test eax, eax
// 005f12a8  7404                 je 0x5f12ae
// 005f12aa  3bc1                 cmp eax, ecx
// 005f12ac  7406                 je 0x5f12b4
// 005f12ae  ffd3                 call ebx
// 005f12b0  8b542430             mov edx, dword ptr [esp + 0x30]
// 005f12b4  3bd7                 cmp edx, edi
// 005f12b6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005f12ba  753e                 jne 0x5f12fa
// 005f12bc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005f12bf  8b4108               mov eax, dword ptr [ecx + 8]
// 005f12c2  83c00c               add eax, 0xc
// 005f12c5  57                   push edi
// 005f12c6  50                   push eax
// 005f12c7  ff151ca59e00         call dword ptr [0x9ea51c]
// 005f12cd  83c408               add esp, 8
// 005f12d0  84c0                 test al, al
// 005f12d2  0f8443010000         je 0x5f141b
// 005f12d8  8b5618               mov edx, dword ptr [esi + 0x18]
// 005f12db  8b4208               mov eax, dword ptr [edx + 8]
// 005f12de  57                   push edi
// 005f12df  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005f12e3  50                   push eax
// 005f12e4  6a00                 push 0
// 005f12e6  57                   push edi
// 005f12e7  8bce                 mov ecx, esi
// 005f12e9  e862f7ffff           call 0x5f0a50
// 005f12ee  5d                   pop ebp
// 005f12ef  5b                   pop ebx
// 005f12f0  8bc7                 mov eax, edi
// 005f12f2  5f                   pop edi
// 005f12f3  5e                   pop esi
// 005f12f4  83c414               add esp, 0x14
// 005f12f7  c21000               ret 0x10
// 005f12fa  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 005f1300  83c20c               add edx, 0xc
// 005f1303  52                   push edx
// 005f1304  57                   push edi
// 005f1305  ffd5                 call ebp
// 005f1307  83c408               add esp, 8
// 005f130a  84c0                 test al, al
// 005f130c  746c                 je 0x5f137a
// 005f130e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005f1312  8b542430             mov edx, dword ptr [esp + 0x30]
// 005f1316  894c2410             mov dword ptr [esp + 0x10], ecx
// 005f131a  8d4c2410             lea ecx, [esp + 0x10]
// 005f131e  89542414             mov dword ptr [esp + 0x14], edx
// 005f1322  e879e8ffff           call 0x5efba0
// 005f1327  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005f132b  57                   push edi
// 005f132c  8d430c               lea eax, [ebx + 0xc]
// 005f132f  50                   push eax
// 005f1330  8d4e08               lea ecx, [esi + 8]
// 005f1333  e8181fe8ff           call 0x473250
// 005f1338  84c0                 test al, al
// 005f133a  743e                 je 0x5f137a
// 005f133c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005f133f  80794500             cmp byte ptr [ecx + 0x45], 0
// 005f1343  57                   push edi
// 005f1344  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005f1348  8bce                 mov ecx, esi
// 005f134a  7415                 je 0x5f1361
// 005f134c  53                   push ebx
// 005f134d  6a00                 push 0
// 005f134f  57                   push edi
// 005f1350  e8fbf6ffff           call 0x5f0a50
// 005f1355  5d                   pop ebp
// 005f1356  5b                   pop ebx
// 005f1357  8bc7                 mov eax, edi
// 005f1359  5f                   pop edi
// 005f135a  5e                   pop esi
// 005f135b  83c414               add esp, 0x14
// 005f135e  c21000               ret 0x10
// 005f1361  8b542434             mov edx, dword ptr [esp + 0x34]
// 005f1365  52                   push edx
// 005f1366  6a01                 push 1
// 005f1368  57                   push edi
// 005f1369  e8e2f6ffff           call 0x5f0a50
// 005f136e  5d                   pop ebp
// 005f136f  5b                   pop ebx
// 005f1370  8bc7                 mov eax, edi
// 005f1372  5f                   pop edi
// 005f1373  5e                   pop esi
// 005f1374  83c414               add esp, 0x14
// 005f1377  c21000               ret 0x10
// 005f137a  8b442430             mov eax, dword ptr [esp + 0x30]
// 005f137e  83c00c               add eax, 0xc
// 005f1381  57                   push edi
// 005f1382  50                   push eax
// 005f1383  ffd5                 call ebp
// 005f1385  83c408               add esp, 8
// 005f1388  84c0                 test al, al
// 005f138a  0f848b000000         je 0x5f141b
// 005f1390  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005f1394  8b542430             mov edx, dword ptr [esp + 0x30]
// 005f1398  8b4618               mov eax, dword ptr [esi + 0x18]
// 005f139b  894c2410             mov dword ptr [esp + 0x10], ecx
// 005f139f  8b0e                 mov ecx, dword ptr [esi]
// 005f13a1  894c2418             mov dword ptr [esp + 0x18], ecx
// 005f13a5  8d4c2410             lea ecx, [esp + 0x10]
// 005f13a9  89542414             mov dword ptr [esp + 0x14], edx
// 005f13ad  8944241c             mov dword ptr [esp + 0x1c], eax
// 005f13b1  e88a28e2ff           call 0x413c40
// 005f13b6  8d542418             lea edx, [esp + 0x18]
// 005f13ba  52                   push edx
// 005f13bb  8d4c2414             lea ecx, [esp + 0x14]
// 005f13bf  e8bc5be7ff           call 0x466f80
// 005f13c4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005f13c8  84c0                 test al, al
// 005f13ca  7511                 jne 0x5f13dd
// 005f13cc  8d430c               lea eax, [ebx + 0xc]
// 005f13cf  50                   push eax
// 005f13d0  57                   push edi
// 005f13d1  8d4e08               lea ecx, [esi + 8]
// 005f13d4  e8771ee8ff           call 0x473250
// 005f13d9  84c0                 test al, al
// 005f13db  743e                 je 0x5f141b
// 005f13dd  8b442430             mov eax, dword ptr [esp + 0x30]
// 005f13e1  8b4808               mov ecx, dword ptr [eax + 8]
// 005f13e4  80794500             cmp byte ptr [ecx + 0x45], 0
// 005f13e8  57                   push edi
// 005f13e9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005f13ed  8bce                 mov ecx, esi
// 005f13ef  7415                 je 0x5f1406
// 005f13f1  50                   push eax
// 005f13f2  6a00                 push 0
// 005f13f4  57                   push edi
// 005f13f5  e856f6ffff           call 0x5f0a50
// 005f13fa  5d                   pop ebp
// 005f13fb  5b                   pop ebx
// 005f13fc  8bc7                 mov eax, edi
// 005f13fe  5f                   pop edi
// 005f13ff  5e                   pop esi
// 005f1400  83c414               add esp, 0x14
// 005f1403  c21000               ret 0x10
// 005f1406  53                   push ebx
// 005f1407  6a01                 push 1
// 005f1409  57                   push edi
// 005f140a  e841f6ffff           call 0x5f0a50
// 005f140f  5d                   pop ebp
// 005f1410  5b                   pop ebx
// 005f1411  8bc7                 mov eax, edi
// 005f1413  5f                   pop edi
// 005f1414  5e                   pop esi
// 005f1415  83c414               add esp, 0x14
// 005f1418  c21000               ret 0x10
// 005f141b  57                   push edi
// 005f141c  8d54241c             lea edx, [esp + 0x1c]
// 005f1420  52                   push edx
// 005f1421  8bce                 mov ecx, esi
// 005f1423  e828f8ffff           call 0x5f0c50
// 005f1428  8b10                 mov edx, dword ptr [eax]
// 005f142a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005f142e  5d                   pop ebp
// 005f142f  5b                   pop ebx
// 005f1430  8911                 mov dword ptr [ecx], edx
// 005f1432  8b4004               mov eax, dword ptr [eax + 4]
// 005f1435  5f                   pop edi
// 005f1436  894104               mov dword ptr [ecx + 4], eax
// 005f1439  8bc1                 mov eax, ecx
// 005f143b  5e                   pop esi
// 005f143c  83c414               add esp, 0x14
// 005f143f  c21000               ret 0x10
// standard library map_str<string> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
