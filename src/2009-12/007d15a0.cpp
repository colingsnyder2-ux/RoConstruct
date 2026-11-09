// from server: 100% by auto
// roc 2009-12 007d15a0  unit: seg_007d0000  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d15a0
//
// 007d15a0  53                   push ebx
// 007d15a1  55                   push ebp
// 007d15a2  56                   push esi
// 007d15a3  8b742418             mov esi, dword ptr [esp + 0x18]
// 007d15a7  57                   push edi
// 007d15a8  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007d15ac  8b4720               mov eax, dword ptr [edi + 0x20]
// 007d15af  3b442418             cmp eax, dword ptr [esp + 0x18]
// 007d15b3  7406                 je 0x7d15bb
// 007d15b5  837e0c00             cmp dword ptr [esi + 0xc], 0
// 007d15b9  7402                 je 0x7d15bd
// 007d15bb  33c0                 xor eax, eax
// 007d15bd  e8cefcffff           call 0x7d1290
// 007d15c2  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d15c6  8b473c               mov eax, dword ptr [edi + 0x3c]
// 007d15c9  89442414             mov dword ptr [esp + 0x14], eax
// 007d15cd  7519                 jne 0x7d15e8
// 007d15cf  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d15d2  8b06                 mov eax, dword ptr [esi]
// 007d15d4  51                   push ecx
// 007d15d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d15d8  6a04                 push 4
// 007d15da  8d54241c             lea edx, [esp + 0x1c]
// 007d15de  52                   push edx
// 007d15df  50                   push eax
// 007d15e0  ffd1                 call ecx
// 007d15e2  83c410               add esp, 0x10
// 007d15e5  894610               mov dword ptr [esi + 0x10], eax
// 007d15e8  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d15ec  8b5740               mov edx, dword ptr [edi + 0x40]
// 007d15ef  89542414             mov dword ptr [esp + 0x14], edx
// 007d15f3  7519                 jne 0x7d160e
// 007d15f5  8b4608               mov eax, dword ptr [esi + 8]
// 007d15f8  8b16                 mov edx, dword ptr [esi]
// 007d15fa  50                   push eax
// 007d15fb  8b4604               mov eax, dword ptr [esi + 4]
// 007d15fe  6a04                 push 4
// 007d1600  8d4c241c             lea ecx, [esp + 0x1c]
// 007d1604  51                   push ecx
// 007d1605  52                   push edx
// 007d1606  ffd0                 call eax
// 007d1608  83c410               add esp, 0x10
// 007d160b  894610               mov dword ptr [esi + 0x10], eax
// 007d160e  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d1612  8a4f48               mov cl, byte ptr [edi + 0x48]
// 007d1615  884c2414             mov byte ptr [esp + 0x14], cl
// 007d1619  7519                 jne 0x7d1634
// 007d161b  8b5608               mov edx, dword ptr [esi + 8]
// 007d161e  8b0e                 mov ecx, dword ptr [esi]
// 007d1620  52                   push edx
// 007d1621  8b5604               mov edx, dword ptr [esi + 4]
// 007d1624  6a01                 push 1
// 007d1626  8d44241c             lea eax, [esp + 0x1c]
// 007d162a  50                   push eax
// 007d162b  51                   push ecx
// 007d162c  ffd2                 call edx
// 007d162e  83c410               add esp, 0x10
// 007d1631  894610               mov dword ptr [esi + 0x10], eax
// 007d1634  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d1638  8a4749               mov al, byte ptr [edi + 0x49]
// 007d163b  88442414             mov byte ptr [esp + 0x14], al
// 007d163f  7519                 jne 0x7d165a
// 007d1641  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d1644  8b06                 mov eax, dword ptr [esi]
// 007d1646  51                   push ecx
// 007d1647  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d164a  6a01                 push 1
// 007d164c  8d54241c             lea edx, [esp + 0x1c]
// 007d1650  52                   push edx
// 007d1651  50                   push eax
// 007d1652  ffd1                 call ecx
// 007d1654  83c410               add esp, 0x10
// 007d1657  894610               mov dword ptr [esi + 0x10], eax
// 007d165a  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d165e  8a574a               mov dl, byte ptr [edi + 0x4a]
// 007d1661  88542414             mov byte ptr [esp + 0x14], dl
// 007d1665  7519                 jne 0x7d1680
// 007d1667  8b4608               mov eax, dword ptr [esi + 8]
// 007d166a  8b16                 mov edx, dword ptr [esi]
// 007d166c  50                   push eax
// 007d166d  8b4604               mov eax, dword ptr [esi + 4]
// 007d1670  6a01                 push 1
// 007d1672  8d4c241c             lea ecx, [esp + 0x1c]
// 007d1676  51                   push ecx
// 007d1677  52                   push edx
// 007d1678  ffd0                 call eax
// 007d167a  83c410               add esp, 0x10
// 007d167d  894610               mov dword ptr [esi + 0x10], eax
// 007d1680  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d1684  8a4f4b               mov cl, byte ptr [edi + 0x4b]
// 007d1687  884c2414             mov byte ptr [esp + 0x14], cl
// 007d168b  7519                 jne 0x7d16a6
// 007d168d  8b5608               mov edx, dword ptr [esi + 8]
// 007d1690  8b0e                 mov ecx, dword ptr [esi]
// 007d1692  52                   push edx
// 007d1693  8b5604               mov edx, dword ptr [esi + 4]
// 007d1696  6a01                 push 1
// 007d1698  8d44241c             lea eax, [esp + 0x1c]
// 007d169c  50                   push eax
// 007d169d  51                   push ecx
// 007d169e  ffd2                 call edx
// 007d16a0  83c410               add esp, 0x10
// 007d16a3  894610               mov dword ptr [esi + 0x10], eax
// 007d16a6  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d16aa  8b5f2c               mov ebx, dword ptr [edi + 0x2c]
// 007d16ad  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 007d16b0  895c2414             mov dword ptr [esp + 0x14], ebx
// 007d16b4  7538                 jne 0x7d16ee
// 007d16b6  8b4608               mov eax, dword ptr [esi + 8]
// 007d16b9  8b16                 mov edx, dword ptr [esi]
// 007d16bb  50                   push eax
// 007d16bc  8b4604               mov eax, dword ptr [esi + 4]
// 007d16bf  6a04                 push 4
// 007d16c1  8d4c241c             lea ecx, [esp + 0x1c]
// 007d16c5  51                   push ecx
// 007d16c6  52                   push edx
// 007d16c7  ffd0                 call eax
// 007d16c9  83c410               add esp, 0x10
// 007d16cc  894610               mov dword ptr [esi + 0x10], eax
// 007d16cf  85c0                 test eax, eax
// 007d16d1  751b                 jne 0x7d16ee
// 007d16d3  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d16d6  8b06                 mov eax, dword ptr [esi]
// 007d16d8  51                   push ecx
// 007d16d9  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d16dc  8d149d00000000       lea edx, [ebx*4]
// 007d16e3  52                   push edx
// 007d16e4  55                   push ebp
// 007d16e5  50                   push eax
// 007d16e6  ffd1                 call ecx
// 007d16e8  83c410               add esp, 0x10
// 007d16eb  894610               mov dword ptr [esi + 0x10], eax
// 007d16ee  57                   push edi
// 007d16ef  8bc6                 mov eax, esi
// 007d16f1  e81afcffff           call 0x7d1310
// 007d16f6  57                   push edi
// 007d16f7  8bc6                 mov eax, esi
// 007d16f9  e852fdffff           call 0x7d1450
// 007d16fe  83c408               add esp, 8
// 007d1701  5f                   pop edi
// 007d1702  5e                   pop esi
// 007d1703  5d                   pop ebp
// 007d1704  5b                   pop ebx
// 007d1705  c3                   ret 
// library lua-5.1/ldump.c (function _DumpFunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldump.c
