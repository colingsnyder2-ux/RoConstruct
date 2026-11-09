// from server: 100% by auto
// roc 2011-06 008f14c0  unit: CXTCaptionTheme  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f14c0
//
// 008f14c0  83ec10               sub esp, 0x10
// 008f14c3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f14c7  8b5004               mov edx, dword ptr [eax + 4]
// 008f14ca  53                   push ebx
// 008f14cb  55                   push ebp
// 008f14cc  56                   push esi
// 008f14cd  8bf1                 mov esi, ecx
// 008f14cf  8b08                 mov ecx, dword ptr [eax]
// 008f14d1  894c240c             mov dword ptr [esp + 0xc], ecx
// 008f14d5  8b4808               mov ecx, dword ptr [eax + 8]
// 008f14d8  57                   push edi
// 008f14d9  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 008f14dd  89542414             mov dword ptr [esp + 0x14], edx
// 008f14e1  8b500c               mov edx, dword ptr [eax + 0xc]
// 008f14e4  894c2418             mov dword ptr [esp + 0x18], ecx
// 008f14e8  6a01                 push 1
// 008f14ea  8bcf                 mov ecx, edi
// 008f14ec  89542420             mov dword ptr [esp + 0x20], edx
// 008f14f0  e8f9b00d00           call 0x9cc5ee
// 008f14f5  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 008f14f9  8b4370               mov eax, dword ptr [ebx + 0x70]
// 008f14fc  50                   push eax
// 008f14fd  8d4c2414             lea ecx, [esp + 0x14]
// 008f1501  51                   push ecx
// 008f1502  8bcf                 mov ecx, edi
// 008f1504  e81799f1ff           call 0x80ae20
// 008f1509  8b83c8000000         mov eax, dword ptr [ebx + 0xc8]
// 008f150f  8b2de41ba400         mov ebp, dword ptr [0xa41be4]
// 008f1515  a801                 test al, 1
// 008f1517  746c                 je 0x8f1585
// 008f1519  8b4628               mov eax, dword ptr [esi + 0x28]
// 008f151c  83f8ff               cmp eax, -1
// 008f151f  7505                 jne 0x8f1526
// 008f1521  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 008f1524  eb02                 jmp 0x8f1528
// 008f1526  8bc8                 mov ecx, eax
// 008f1528  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008f152b  83f8ff               cmp eax, -1
// 008f152e  7503                 jne 0x8f1533
// 008f1530  8b4618               mov eax, dword ptr [esi + 0x18]
// 008f1533  51                   push ecx
// 008f1534  50                   push eax
// 008f1535  8d542418             lea edx, [esp + 0x18]
// 008f1539  52                   push edx
// 008f153a  8bcf                 mov ecx, edi
// 008f153c  e8d998f1ff           call 0x80ae1a
// 008f1541  6aff                 push -1
// 008f1543  6aff                 push -1
// 008f1545  8d442418             lea eax, [esp + 0x18]
// 008f1549  50                   push eax
// 008f154a  ffd5                 call ebp
// 008f154c  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008f154f  83f8ff               cmp eax, -1
// 008f1552  7503                 jne 0x8f1557
// 008f1554  8b4618               mov eax, dword ptr [esi + 0x18]
// 008f1557  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 008f155a  83f9ff               cmp ecx, -1
// 008f155d  7505                 jne 0x8f1564
// 008f155f  8b7624               mov esi, dword ptr [esi + 0x24]
// 008f1562  eb02                 jmp 0x8f1566
// 008f1564  8bf1                 mov esi, ecx
// 008f1566  50                   push eax
// 008f1567  56                   push esi
// 008f1568  8d4c2418             lea ecx, [esp + 0x18]
// 008f156c  51                   push ecx
// 008f156d  8bcf                 mov ecx, edi
// 008f156f  e8a698f1ff           call 0x80ae1a
// 008f1574  837b6c00             cmp dword ptr [ebx + 0x6c], 0
// 008f1578  754c                 jne 0x8f15c6
// 008f157a  6aff                 push -1
// 008f157c  6aff                 push -1
// 008f157e  8d542418             lea edx, [esp + 0x18]
// 008f1582  52                   push edx
// 008f1583  eb3f                 jmp 0x8f15c4
// 008f1585  a802                 test al, 2
// 008f1587  743d                 je 0x8f15c6
// 008f1589  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008f158c  83f8ff               cmp eax, -1
// 008f158f  7505                 jne 0x8f1596
// 008f1591  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008f1594  eb02                 jmp 0x8f1598
// 008f1596  8bc8                 mov ecx, eax
// 008f1598  8b4628               mov eax, dword ptr [esi + 0x28]
// 008f159b  83f8ff               cmp eax, -1
// 008f159e  7505                 jne 0x8f15a5
// 008f15a0  8b7624               mov esi, dword ptr [esi + 0x24]
// 008f15a3  eb02                 jmp 0x8f15a7
// 008f15a5  8bf0                 mov esi, eax
// 008f15a7  51                   push ecx
// 008f15a8  56                   push esi
// 008f15a9  8d442418             lea eax, [esp + 0x18]
// 008f15ad  50                   push eax
// 008f15ae  8bcf                 mov ecx, edi
// 008f15b0  e86598f1ff           call 0x80ae1a
// 008f15b5  837b6c00             cmp dword ptr [ebx + 0x6c], 0
// 008f15b9  750b                 jne 0x8f15c6
// 008f15bb  6aff                 push -1
// 008f15bd  6aff                 push -1
// 008f15bf  8d4c2418             lea ecx, [esp + 0x18]
// 008f15c3  51                   push ecx
// 008f15c4  ffd5                 call ebp
// 008f15c6  8b436c               mov eax, dword ptr [ebx + 0x6c]
// 008f15c9  f7d8                 neg eax
// 008f15cb  50                   push eax
// 008f15cc  50                   push eax
// 008f15cd  8d542418             lea edx, [esp + 0x18]
// 008f15d1  52                   push edx
// 008f15d2  ffd5                 call ebp
// 008f15d4  8b4374               mov eax, dword ptr [ebx + 0x74]
// 008f15d7  50                   push eax
// 008f15d8  8d4c2414             lea ecx, [esp + 0x14]
// 008f15dc  51                   push ecx
// 008f15dd  8bcf                 mov ecx, edi
// 008f15df  e83c98f1ff           call 0x80ae20
// 008f15e4  5f                   pop edi
// 008f15e5  5e                   pop esi
// 008f15e6  5d                   pop ebp
// 008f15e7  5b                   pop ebx
// 008f15e8  83c410               add esp, 0x10
// 008f15eb  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionTheme@@UAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
