// from server: 100% by auto
// roc 2011-06 0056e570  unit: seg_00560000  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056e570
//
// 0056e570  56                   push esi
// 0056e571  8b742408             mov esi, dword ptr [esp + 8]
// 0056e575  85f6                 test esi, esi
// 0056e577  0f8449010000         je 0x56e6c6
// 0056e57d  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 0056e584  741c                 je 0x56e5a2
// 0056e586  8b465c               mov eax, dword ptr [esi + 0x5c]
// 0056e589  85c0                 test eax, eax
// 0056e58b  7415                 je 0x56e5a2
// 0056e58d  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0056e593  41                   inc ecx
// 0056e594  51                   push ecx
// 0056e595  8d9600010000         lea edx, [esi + 0x100]
// 0056e59b  52                   push edx
// 0056e59c  56                   push esi
// 0056e59d  ffd0                 call eax
// 0056e59f  83c40c               add esp, 0xc
// 0056e5a2  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 0056e5a9  741b                 je 0x56e5c6
// 0056e5ab  8b466c               mov eax, dword ptr [esi + 0x6c]
// 0056e5ae  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0056e5b4  50                   push eax
// 0056e5b5  41                   inc ecx
// 0056e5b6  51                   push ecx
// 0056e5b7  8d9600010000         lea edx, [esi + 0x100]
// 0056e5bd  52                   push edx
// 0056e5be  e80ddbfeff           call 0x55c0d0
// 0056e5c3  83c40c               add esp, 0xc
// 0056e5c6  f7467000000100       test dword ptr [esi + 0x70], 0x10000
// 0056e5cd  7417                 je 0x56e5e6
// 0056e5cf  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 0056e5d5  40                   inc eax
// 0056e5d6  50                   push eax
// 0056e5d7  8d8e00010000         lea ecx, [esi + 0x100]
// 0056e5dd  51                   push ecx
// 0056e5de  e89ddafeff           call 0x55c080
// 0056e5e3  83c408               add esp, 8
// 0056e5e6  f6467004             test byte ptr [esi + 0x70], 4
// 0056e5ea  741f                 je 0x56e60b
// 0056e5ec  0fb69627010000       movzx edx, byte ptr [esi + 0x127]
// 0056e5f3  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 0056e5f9  52                   push edx
// 0056e5fa  40                   inc eax
// 0056e5fb  50                   push eax
// 0056e5fc  8d8e00010000         lea ecx, [esi + 0x100]
// 0056e602  51                   push ecx
// 0056e603  e8e8f8ffff           call 0x56def0
// 0056e608  83c40c               add esp, 0xc
// 0056e60b  f6467010             test byte ptr [esi + 0x70], 0x10
// 0056e60f  7417                 je 0x56e628
// 0056e611  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 0056e617  42                   inc edx
// 0056e618  52                   push edx
// 0056e619  8d8600010000         lea eax, [esi + 0x100]
// 0056e61f  50                   push eax
// 0056e620  e81bdafeff           call 0x55c040
// 0056e625  83c408               add esp, 8
// 0056e628  f6467008             test byte ptr [esi + 0x70], 8
// 0056e62c  741e                 je 0x56e64c
// 0056e62e  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 0056e634  8d8e81010000         lea ecx, [esi + 0x181]
// 0056e63a  51                   push ecx
// 0056e63b  42                   inc edx
// 0056e63c  52                   push edx
// 0056e63d  8d8600010000         lea eax, [esi + 0x100]
// 0056e643  50                   push eax
// 0056e644  e8d7f9ffff           call 0x56e020
// 0056e649  83c40c               add esp, 0xc
// 0056e64c  f7467000000200       test dword ptr [esi + 0x70], 0x20000
// 0056e653  7417                 je 0x56e66c
// 0056e655  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0056e65b  41                   inc ecx
// 0056e65c  51                   push ecx
// 0056e65d  8d9600010000         lea edx, [esi + 0x100]
// 0056e663  52                   push edx
// 0056e664  e857fcffff           call 0x56e2c0
// 0056e669  83c408               add esp, 8
// 0056e66c  f7467000000800       test dword ptr [esi + 0x70], 0x80000
// 0056e673  7417                 je 0x56e68c
// 0056e675  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 0056e67b  40                   inc eax
// 0056e67c  50                   push eax
// 0056e67d  8d8e00010000         lea ecx, [esi + 0x100]
// 0056e683  51                   push ecx
// 0056e684  e857fdffff           call 0x56e3e0
// 0056e689  83c408               add esp, 8
// 0056e68c  f6467001             test byte ptr [esi + 0x70], 1
// 0056e690  7417                 je 0x56e6a9
// 0056e692  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 0056e698  42                   inc edx
// 0056e699  52                   push edx
// 0056e69a  8d8600010000         lea eax, [esi + 0x100]
// 0056e6a0  50                   push eax
// 0056e6a1  e87adcfeff           call 0x55c320
// 0056e6a6  83c408               add esp, 8
// 0056e6a9  f6467020             test byte ptr [esi + 0x70], 0x20
// 0056e6ad  7417                 je 0x56e6c6
// 0056e6af  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0056e6b5  41                   inc ecx
// 0056e6b6  51                   push ecx
// 0056e6b7  81c600010000         add esi, 0x100
// 0056e6bd  56                   push esi
// 0056e6be  e8edd8feff           call 0x55bfb0
// 0056e6c3  83c408               add esp, 8
// 0056e6c6  5e                   pop esi
// 0056e6c7  c3                   ret 
// library libpng-1.2.10/pngwtran.c (function _png_do_write_transformations)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwtran.c
