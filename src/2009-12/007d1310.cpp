// from server: 100% by auto
// roc 2009-12 007d1310  unit: seg_007d0000  size: 309 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1310
//
// 007d1310  55                   push ebp
// 007d1311  8bec                 mov ebp, esp
// 007d1313  83e4f8               and esp, 0xfffffff8
// 007d1316  83ec14               sub esp, 0x14
// 007d1319  53                   push ebx
// 007d131a  56                   push esi
// 007d131b  8bf0                 mov esi, eax
// 007d131d  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d1321  8b4508               mov eax, dword ptr [ebp + 8]
// 007d1324  57                   push edi
// 007d1325  8b7828               mov edi, dword ptr [eax + 0x28]
// 007d1328  897c2414             mov dword ptr [esp + 0x14], edi
// 007d132c  7519                 jne 0x7d1347
// 007d132e  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d1331  8b06                 mov eax, dword ptr [esi]
// 007d1333  51                   push ecx
// 007d1334  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d1337  6a04                 push 4
// 007d1339  8d54241c             lea edx, [esp + 0x1c]
// 007d133d  52                   push edx
// 007d133e  50                   push eax
// 007d133f  ffd1                 call ecx
// 007d1341  83c410               add esp, 0x10
// 007d1344  894610               mov dword ptr [esi + 0x10], eax
// 007d1347  85ff                 test edi, edi
// 007d1349  0f8ea4000000         jle 0x7d13f3
// 007d134f  33db                 xor ebx, ebx
// 007d1351  897c2414             mov dword ptr [esp + 0x14], edi
// 007d1355  8b5508               mov edx, dword ptr [ebp + 8]
// 007d1358  8b7a08               mov edi, dword ptr [edx + 8]
// 007d135b  8a441f08             mov al, byte ptr [edi + ebx + 8]
// 007d135f  03fb                 add edi, ebx
// 007d1361  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d1365  88442413             mov byte ptr [esp + 0x13], al
// 007d1369  7519                 jne 0x7d1384
// 007d136b  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d136e  8b06                 mov eax, dword ptr [esi]
// 007d1370  51                   push ecx
// 007d1371  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d1374  6a01                 push 1
// 007d1376  8d54241b             lea edx, [esp + 0x1b]
// 007d137a  52                   push edx
// 007d137b  50                   push eax
// 007d137c  ffd1                 call ecx
// 007d137e  83c410               add esp, 0x10
// 007d1381  894610               mov dword ptr [esi + 0x10], eax
// 007d1384  8b4708               mov eax, dword ptr [edi + 8]
// 007d1387  83e801               sub eax, 1
// 007d138a  7434                 je 0x7d13c0
// 007d138c  83e802               sub eax, 2
// 007d138f  740e                 je 0x7d139f
// 007d1391  83e801               sub eax, 1
// 007d1394  754f                 jne 0x7d13e5
// 007d1396  8b07                 mov eax, dword ptr [edi]
// 007d1398  e8f3feffff           call 0x7d1290
// 007d139d  eb46                 jmp 0x7d13e5
// 007d139f  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d13a3  dd07                 fld qword ptr [edi]
// 007d13a5  dd5c2418             fstp qword ptr [esp + 0x18]
// 007d13a9  753a                 jne 0x7d13e5
// 007d13ab  8b5608               mov edx, dword ptr [esi + 8]
// 007d13ae  8b0e                 mov ecx, dword ptr [esi]
// 007d13b0  52                   push edx
// 007d13b1  8b5604               mov edx, dword ptr [esi + 4]
// 007d13b4  6a08                 push 8
// 007d13b6  8d442420             lea eax, [esp + 0x20]
// 007d13ba  50                   push eax
// 007d13bb  51                   push ecx
// 007d13bc  ffd2                 call edx
// 007d13be  eb1f                 jmp 0x7d13df
// 007d13c0  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d13c4  8a07                 mov al, byte ptr [edi]
// 007d13c6  88442413             mov byte ptr [esp + 0x13], al
// 007d13ca  7519                 jne 0x7d13e5
// 007d13cc  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d13cf  8b06                 mov eax, dword ptr [esi]
// 007d13d1  51                   push ecx
// 007d13d2  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d13d5  6a01                 push 1
// 007d13d7  8d54241b             lea edx, [esp + 0x1b]
// 007d13db  52                   push edx
// 007d13dc  50                   push eax
// 007d13dd  ffd1                 call ecx
// 007d13df  894610               mov dword ptr [esi + 0x10], eax
// 007d13e2  83c410               add esp, 0x10
// 007d13e5  83c310               add ebx, 0x10
// 007d13e8  836c241401           sub dword ptr [esp + 0x14], 1
// 007d13ed  0f8562ffffff         jne 0x7d1355
// 007d13f3  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d13f7  8b5508               mov edx, dword ptr [ebp + 8]
// 007d13fa  8b5a34               mov ebx, dword ptr [edx + 0x34]
// 007d13fd  895c2414             mov dword ptr [esp + 0x14], ebx
// 007d1401  7519                 jne 0x7d141c
// 007d1403  8b4608               mov eax, dword ptr [esi + 8]
// 007d1406  8b16                 mov edx, dword ptr [esi]
// 007d1408  50                   push eax
// 007d1409  8b4604               mov eax, dword ptr [esi + 4]
// 007d140c  6a04                 push 4
// 007d140e  8d4c241c             lea ecx, [esp + 0x1c]
// 007d1412  51                   push ecx
// 007d1413  52                   push edx
// 007d1414  ffd0                 call eax
// 007d1416  83c410               add esp, 0x10
// 007d1419  894610               mov dword ptr [esi + 0x10], eax
// 007d141c  33ff                 xor edi, edi
// 007d141e  85db                 test ebx, ebx
// 007d1420  7e1c                 jle 0x7d143e
// 007d1422  8b4508               mov eax, dword ptr [ebp + 8]
// 007d1425  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007d1428  8b5010               mov edx, dword ptr [eax + 0x10]
// 007d142b  8b04ba               mov eax, dword ptr [edx + edi*4]
// 007d142e  56                   push esi
// 007d142f  51                   push ecx
// 007d1430  50                   push eax
// 007d1431  e86a010000           call 0x7d15a0
// 007d1436  47                   inc edi
// 007d1437  83c40c               add esp, 0xc
// 007d143a  3bfb                 cmp edi, ebx
// 007d143c  7ce4                 jl 0x7d1422
// 007d143e  5f                   pop edi
// 007d143f  5e                   pop esi
// 007d1440  5b                   pop ebx
// 007d1441  8be5                 mov esp, ebp
// 007d1443  5d                   pop ebp
// 007d1444  c3                   ret 
// library lua-5.1/ldump.c (function _DumpConstants)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldump.c
