// from server: 100% by auto
// roc 2009-06 0058e990  unit: seg_00580000  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058e990
//
// 0058e990  56                   push esi
// 0058e991  8b742408             mov esi, dword ptr [esp + 8]
// 0058e995  85f6                 test esi, esi
// 0058e997  0f8449010000         je 0x58eae6
// 0058e99d  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 0058e9a4  741c                 je 0x58e9c2
// 0058e9a6  8b465c               mov eax, dword ptr [esi + 0x5c]
// 0058e9a9  85c0                 test eax, eax
// 0058e9ab  7415                 je 0x58e9c2
// 0058e9ad  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0058e9b3  41                   inc ecx
// 0058e9b4  51                   push ecx
// 0058e9b5  8d9600010000         lea edx, [esi + 0x100]
// 0058e9bb  52                   push edx
// 0058e9bc  56                   push esi
// 0058e9bd  ffd0                 call eax
// 0058e9bf  83c40c               add esp, 0xc
// 0058e9c2  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 0058e9c9  741b                 je 0x58e9e6
// 0058e9cb  8b466c               mov eax, dword ptr [esi + 0x6c]
// 0058e9ce  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0058e9d4  50                   push eax
// 0058e9d5  41                   inc ecx
// 0058e9d6  51                   push ecx
// 0058e9d7  8d9600010000         lea edx, [esi + 0x100]
// 0058e9dd  52                   push edx
// 0058e9de  e85d54ffff           call 0x583e40
// 0058e9e3  83c40c               add esp, 0xc
// 0058e9e6  f7467000000100       test dword ptr [esi + 0x70], 0x10000
// 0058e9ed  7417                 je 0x58ea06
// 0058e9ef  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 0058e9f5  40                   inc eax
// 0058e9f6  50                   push eax
// 0058e9f7  8d8e00010000         lea ecx, [esi + 0x100]
// 0058e9fd  51                   push ecx
// 0058e9fe  e8ed53ffff           call 0x583df0
// 0058ea03  83c408               add esp, 8
// 0058ea06  f6467004             test byte ptr [esi + 0x70], 4
// 0058ea0a  741f                 je 0x58ea2b
// 0058ea0c  0fb69627010000       movzx edx, byte ptr [esi + 0x127]
// 0058ea13  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 0058ea19  52                   push edx
// 0058ea1a  40                   inc eax
// 0058ea1b  50                   push eax
// 0058ea1c  8d8e00010000         lea ecx, [esi + 0x100]
// 0058ea22  51                   push ecx
// 0058ea23  e8e8f8ffff           call 0x58e310
// 0058ea28  83c40c               add esp, 0xc
// 0058ea2b  f6467010             test byte ptr [esi + 0x70], 0x10
// 0058ea2f  7417                 je 0x58ea48
// 0058ea31  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 0058ea37  42                   inc edx
// 0058ea38  52                   push edx
// 0058ea39  8d8600010000         lea eax, [esi + 0x100]
// 0058ea3f  50                   push eax
// 0058ea40  e86b53ffff           call 0x583db0
// 0058ea45  83c408               add esp, 8
// 0058ea48  f6467008             test byte ptr [esi + 0x70], 8
// 0058ea4c  741e                 je 0x58ea6c
// 0058ea4e  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 0058ea54  8d8e81010000         lea ecx, [esi + 0x181]
// 0058ea5a  51                   push ecx
// 0058ea5b  42                   inc edx
// 0058ea5c  52                   push edx
// 0058ea5d  8d8600010000         lea eax, [esi + 0x100]
// 0058ea63  50                   push eax
// 0058ea64  e8d7f9ffff           call 0x58e440
// 0058ea69  83c40c               add esp, 0xc
// 0058ea6c  f7467000000200       test dword ptr [esi + 0x70], 0x20000
// 0058ea73  7417                 je 0x58ea8c
// 0058ea75  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0058ea7b  41                   inc ecx
// 0058ea7c  51                   push ecx
// 0058ea7d  8d9600010000         lea edx, [esi + 0x100]
// 0058ea83  52                   push edx
// 0058ea84  e857fcffff           call 0x58e6e0
// 0058ea89  83c408               add esp, 8
// 0058ea8c  f7467000000800       test dword ptr [esi + 0x70], 0x80000
// 0058ea93  7417                 je 0x58eaac
// 0058ea95  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 0058ea9b  40                   inc eax
// 0058ea9c  50                   push eax
// 0058ea9d  8d8e00010000         lea ecx, [esi + 0x100]
// 0058eaa3  51                   push ecx
// 0058eaa4  e857fdffff           call 0x58e800
// 0058eaa9  83c408               add esp, 8
// 0058eaac  f6467001             test byte ptr [esi + 0x70], 1
// 0058eab0  7417                 je 0x58eac9
// 0058eab2  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 0058eab8  42                   inc edx
// 0058eab9  52                   push edx
// 0058eaba  8d8600010000         lea eax, [esi + 0x100]
// 0058eac0  50                   push eax
// 0058eac1  e8ca55ffff           call 0x584090
// 0058eac6  83c408               add esp, 8
// 0058eac9  f6467020             test byte ptr [esi + 0x70], 0x20
// 0058eacd  7417                 je 0x58eae6
// 0058eacf  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0058ead5  41                   inc ecx
// 0058ead6  51                   push ecx
// 0058ead7  81c600010000         add esi, 0x100
// 0058eadd  56                   push esi
// 0058eade  e83d52ffff           call 0x583d20
// 0058eae3  83c408               add esp, 8
// 0058eae6  5e                   pop esi
// 0058eae7  c3                   ret 
// library libpng-1.2.10/pngwtran.c (function _png_do_write_transformations)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwtran.c
