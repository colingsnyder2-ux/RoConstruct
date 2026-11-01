// from server: 100% by auto
// roc 2011-06 008a12d0  unit: CXTPShortcutManager  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a12d0
//
// 008a12d0  83ec10               sub esp, 0x10
// 008a12d3  56                   push esi
// 008a12d4  57                   push edi
// 008a12d5  8bf1                 mov esi, ecx
// 008a12d7  33ff                 xor edi, edi
// 008a12d9  897e08               mov dword ptr [esi + 8], edi
// 008a12dc  e83b93f6ff           call 0x80a61c
// 008a12e1  b07f                 mov al, 0x7f
// 008a12e3  88442408             mov byte ptr [esp + 8], al
// 008a12e7  88442409             mov byte ptr [esp + 9], al
// 008a12eb  8844240a             mov byte ptr [esp + 0xa], al
// 008a12ef  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008a12f3  897c240c             mov dword ptr [esp + 0xc], edi
// 008a12f7  3bc7                 cmp eax, edi
// 008a12f9  750a                 jne 0x8a1305
// 008a12fb  5f                   pop edi
// 008a12fc  33c0                 xor eax, eax
// 008a12fe  5e                   pop esi
// 008a12ff  83c410               add esp, 0x10
// 008a1302  c20400               ret 4
// 008a1305  53                   push ebx
// 008a1306  8d4c240c             lea ecx, [esp + 0xc]
// 008a130a  51                   push ecx
// 008a130b  8d542424             lea edx, [esp + 0x24]
// 008a130f  52                   push edx
// 008a1310  8d4c2420             lea ecx, [esp + 0x20]
// 008a1314  51                   push ecx
// 008a1315  8d542420             lea edx, [esp + 0x20]
// 008a1319  52                   push edx
// 008a131a  8d4c2420             lea ecx, [esp + 0x20]
// 008a131e  51                   push ecx
// 008a131f  50                   push eax
// 008a1320  e83bfcffff           call 0x8a0f60
// 008a1325  83c418               add esp, 0x18
// 008a1328  85c0                 test eax, eax
// 008a132a  751d                 jne 0x8a1349
// 008a132c  8b442410             mov eax, dword ptr [esp + 0x10]
// 008a1330  3bc7                 cmp eax, edi
// 008a1332  740a                 je 0x8a133e
// 008a1334  50                   push eax
// 008a1335  ff15740aa400         call dword ptr [0xa40a74]
// 008a133b  83c404               add esp, 4
// 008a133e  5b                   pop ebx
// 008a133f  5f                   pop edi
// 008a1340  33c0                 xor eax, eax
// 008a1342  5e                   pop esi
// 008a1343  83c410               add esp, 0x10
// 008a1346  c20400               ret 4
// 008a1349  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008a134d  3bdf                 cmp ebx, edi
// 008a134f  74ed                 je 0x8a133e
// 008a1351  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008a1355  8b442414             mov eax, dword ptr [esp + 0x14]
// 008a1359  55                   push ebp
// 008a135a  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 008a135e  55                   push ebp
// 008a135f  51                   push ecx
// 008a1360  50                   push eax
// 008a1361  53                   push ebx
// 008a1362  8bce                 mov ecx, esi
// 008a1364  e8b7faffff           call 0x8a0e20
// 008a1369  53                   push ebx
// 008a136a  8bf8                 mov edi, eax
// 008a136c  ff15740aa400         call dword ptr [0xa40a74]
// 008a1372  83c404               add esp, 4
// 008a1375  85ff                 test edi, edi
// 008a1377  750c                 jne 0x8a1385
// 008a1379  5d                   pop ebp
// 008a137a  5b                   pop ebx
// 008a137b  5f                   pop edi
// 008a137c  33c0                 xor eax, eax
// 008a137e  5e                   pop esi
// 008a137f  83c410               add esp, 0x10
// 008a1382  c20400               ret 4
// 008a1385  33d2                 xor edx, edx
// 008a1387  83fd04               cmp ebp, 4
// 008a138a  0f94c2               sete dl
// 008a138d  57                   push edi
// 008a138e  8bce                 mov ecx, esi
// 008a1390  895608               mov dword ptr [esi + 8], edx
// 008a1393  e89092f6ff           call 0x80a628
// 008a1398  5d                   pop ebp
// 008a1399  5b                   pop ebx
// 008a139a  5f                   pop edi
// 008a139b  b801000000           mov eax, 1
// 008a13a0  5e                   pop esi
// 008a13a1  83c410               add esp, 0x10
// 008a13a4  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ?LoadFromFile@CXTPGraphicBitmapPng@@QAEHPAVCFile@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
