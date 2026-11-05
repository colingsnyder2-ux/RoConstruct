// from server: 100% by auto
// roc 2012-06 00659c80  unit: seg_00650000  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00659c80
//
// 00659c80  56                   push esi
// 00659c81  8b742408             mov esi, dword ptr [esp + 8]
// 00659c85  85f6                 test esi, esi
// 00659c87  0f8449010000         je 0x659dd6
// 00659c8d  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 00659c94  741c                 je 0x659cb2
// 00659c96  8b465c               mov eax, dword ptr [esi + 0x5c]
// 00659c99  85c0                 test eax, eax
// 00659c9b  7415                 je 0x659cb2
// 00659c9d  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00659ca3  41                   inc ecx
// 00659ca4  51                   push ecx
// 00659ca5  8d9600010000         lea edx, [esi + 0x100]
// 00659cab  52                   push edx
// 00659cac  56                   push esi
// 00659cad  ffd0                 call eax
// 00659caf  83c40c               add esp, 0xc
// 00659cb2  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 00659cb9  741b                 je 0x659cd6
// 00659cbb  8b466c               mov eax, dword ptr [esi + 0x6c]
// 00659cbe  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00659cc4  50                   push eax
// 00659cc5  41                   inc ecx
// 00659cc6  51                   push ecx
// 00659cc7  8d9600010000         lea edx, [esi + 0x100]
// 00659ccd  52                   push edx
// 00659cce  e87df2feff           call 0x648f50
// 00659cd3  83c40c               add esp, 0xc
// 00659cd6  f7467000000100       test dword ptr [esi + 0x70], 0x10000
// 00659cdd  7417                 je 0x659cf6
// 00659cdf  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00659ce5  40                   inc eax
// 00659ce6  50                   push eax
// 00659ce7  8d8e00010000         lea ecx, [esi + 0x100]
// 00659ced  51                   push ecx
// 00659cee  e80df2feff           call 0x648f00
// 00659cf3  83c408               add esp, 8
// 00659cf6  f6467004             test byte ptr [esi + 0x70], 4
// 00659cfa  741f                 je 0x659d1b
// 00659cfc  0fb69627010000       movzx edx, byte ptr [esi + 0x127]
// 00659d03  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00659d09  52                   push edx
// 00659d0a  40                   inc eax
// 00659d0b  50                   push eax
// 00659d0c  8d8e00010000         lea ecx, [esi + 0x100]
// 00659d12  51                   push ecx
// 00659d13  e8e8f8ffff           call 0x659600
// 00659d18  83c40c               add esp, 0xc
// 00659d1b  f6467010             test byte ptr [esi + 0x70], 0x10
// 00659d1f  7417                 je 0x659d38
// 00659d21  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00659d27  42                   inc edx
// 00659d28  52                   push edx
// 00659d29  8d8600010000         lea eax, [esi + 0x100]
// 00659d2f  50                   push eax
// 00659d30  e88bf1feff           call 0x648ec0
// 00659d35  83c408               add esp, 8
// 00659d38  f6467008             test byte ptr [esi + 0x70], 8
// 00659d3c  741e                 je 0x659d5c
// 00659d3e  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00659d44  8d8e81010000         lea ecx, [esi + 0x181]
// 00659d4a  51                   push ecx
// 00659d4b  42                   inc edx
// 00659d4c  52                   push edx
// 00659d4d  8d8600010000         lea eax, [esi + 0x100]
// 00659d53  50                   push eax
// 00659d54  e8d7f9ffff           call 0x659730
// 00659d59  83c40c               add esp, 0xc
// 00659d5c  f7467000000200       test dword ptr [esi + 0x70], 0x20000
// 00659d63  7417                 je 0x659d7c
// 00659d65  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00659d6b  41                   inc ecx
// 00659d6c  51                   push ecx
// 00659d6d  8d9600010000         lea edx, [esi + 0x100]
// 00659d73  52                   push edx
// 00659d74  e857fcffff           call 0x6599d0
// 00659d79  83c408               add esp, 8
// 00659d7c  f7467000000800       test dword ptr [esi + 0x70], 0x80000
// 00659d83  7417                 je 0x659d9c
// 00659d85  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00659d8b  40                   inc eax
// 00659d8c  50                   push eax
// 00659d8d  8d8e00010000         lea ecx, [esi + 0x100]
// 00659d93  51                   push ecx
// 00659d94  e857fdffff           call 0x659af0
// 00659d99  83c408               add esp, 8
// 00659d9c  f6467001             test byte ptr [esi + 0x70], 1
// 00659da0  7417                 je 0x659db9
// 00659da2  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00659da8  42                   inc edx
// 00659da9  52                   push edx
// 00659daa  8d8600010000         lea eax, [esi + 0x100]
// 00659db0  50                   push eax
// 00659db1  e8eaf3feff           call 0x6491a0
// 00659db6  83c408               add esp, 8
// 00659db9  f6467020             test byte ptr [esi + 0x70], 0x20
// 00659dbd  7417                 je 0x659dd6
// 00659dbf  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00659dc5  41                   inc ecx
// 00659dc6  51                   push ecx
// 00659dc7  81c600010000         add esi, 0x100
// 00659dcd  56                   push esi
// 00659dce  e85df0feff           call 0x648e30
// 00659dd3  83c408               add esp, 8
// 00659dd6  5e                   pop esi
// 00659dd7  c3                   ret 
// library libpng-1.2.10/pngwtran.c (function _png_do_write_transformations)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwtran.c
