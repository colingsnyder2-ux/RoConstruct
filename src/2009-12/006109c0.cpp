// from server: 100% by auto
// roc 2009-12 006109c0  unit: seg_00610000  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006109c0
//
// 006109c0  56                   push esi
// 006109c1  8b742408             mov esi, dword ptr [esp + 8]
// 006109c5  85f6                 test esi, esi
// 006109c7  0f8449010000         je 0x610b16
// 006109cd  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 006109d4  741c                 je 0x6109f2
// 006109d6  8b465c               mov eax, dword ptr [esi + 0x5c]
// 006109d9  85c0                 test eax, eax
// 006109db  7415                 je 0x6109f2
// 006109dd  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 006109e3  41                   inc ecx
// 006109e4  51                   push ecx
// 006109e5  8d9600010000         lea edx, [esi + 0x100]
// 006109eb  52                   push edx
// 006109ec  56                   push esi
// 006109ed  ffd0                 call eax
// 006109ef  83c40c               add esp, 0xc
// 006109f2  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 006109f9  741b                 je 0x610a16
// 006109fb  8b466c               mov eax, dword ptr [esi + 0x6c]
// 006109fe  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00610a04  50                   push eax
// 00610a05  41                   inc ecx
// 00610a06  51                   push ecx
// 00610a07  8d9600010000         lea edx, [esi + 0x100]
// 00610a0d  52                   push edx
// 00610a0e  e8dd51ffff           call 0x605bf0
// 00610a13  83c40c               add esp, 0xc
// 00610a16  f7467000000100       test dword ptr [esi + 0x70], 0x10000
// 00610a1d  7417                 je 0x610a36
// 00610a1f  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00610a25  40                   inc eax
// 00610a26  50                   push eax
// 00610a27  8d8e00010000         lea ecx, [esi + 0x100]
// 00610a2d  51                   push ecx
// 00610a2e  e86d51ffff           call 0x605ba0
// 00610a33  83c408               add esp, 8
// 00610a36  f6467004             test byte ptr [esi + 0x70], 4
// 00610a3a  741f                 je 0x610a5b
// 00610a3c  0fb69627010000       movzx edx, byte ptr [esi + 0x127]
// 00610a43  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00610a49  52                   push edx
// 00610a4a  40                   inc eax
// 00610a4b  50                   push eax
// 00610a4c  8d8e00010000         lea ecx, [esi + 0x100]
// 00610a52  51                   push ecx
// 00610a53  e8e8f8ffff           call 0x610340
// 00610a58  83c40c               add esp, 0xc
// 00610a5b  f6467010             test byte ptr [esi + 0x70], 0x10
// 00610a5f  7417                 je 0x610a78
// 00610a61  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00610a67  42                   inc edx
// 00610a68  52                   push edx
// 00610a69  8d8600010000         lea eax, [esi + 0x100]
// 00610a6f  50                   push eax
// 00610a70  e8eb50ffff           call 0x605b60
// 00610a75  83c408               add esp, 8
// 00610a78  f6467008             test byte ptr [esi + 0x70], 8
// 00610a7c  741e                 je 0x610a9c
// 00610a7e  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00610a84  8d8e81010000         lea ecx, [esi + 0x181]
// 00610a8a  51                   push ecx
// 00610a8b  42                   inc edx
// 00610a8c  52                   push edx
// 00610a8d  8d8600010000         lea eax, [esi + 0x100]
// 00610a93  50                   push eax
// 00610a94  e8d7f9ffff           call 0x610470
// 00610a99  83c40c               add esp, 0xc
// 00610a9c  f7467000000200       test dword ptr [esi + 0x70], 0x20000
// 00610aa3  7417                 je 0x610abc
// 00610aa5  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00610aab  41                   inc ecx
// 00610aac  51                   push ecx
// 00610aad  8d9600010000         lea edx, [esi + 0x100]
// 00610ab3  52                   push edx
// 00610ab4  e857fcffff           call 0x610710
// 00610ab9  83c408               add esp, 8
// 00610abc  f7467000000800       test dword ptr [esi + 0x70], 0x80000
// 00610ac3  7417                 je 0x610adc
// 00610ac5  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00610acb  40                   inc eax
// 00610acc  50                   push eax
// 00610acd  8d8e00010000         lea ecx, [esi + 0x100]
// 00610ad3  51                   push ecx
// 00610ad4  e857fdffff           call 0x610830
// 00610ad9  83c408               add esp, 8
// 00610adc  f6467001             test byte ptr [esi + 0x70], 1
// 00610ae0  7417                 je 0x610af9
// 00610ae2  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00610ae8  42                   inc edx
// 00610ae9  52                   push edx
// 00610aea  8d8600010000         lea eax, [esi + 0x100]
// 00610af0  50                   push eax
// 00610af1  e84a53ffff           call 0x605e40
// 00610af6  83c408               add esp, 8
// 00610af9  f6467020             test byte ptr [esi + 0x70], 0x20
// 00610afd  7417                 je 0x610b16
// 00610aff  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00610b05  41                   inc ecx
// 00610b06  51                   push ecx
// 00610b07  81c600010000         add esi, 0x100
// 00610b0d  56                   push esi
// 00610b0e  e8bd4fffff           call 0x605ad0
// 00610b13  83c408               add esp, 8
// 00610b16  5e                   pop esi
// 00610b17  c3                   ret 
// library libpng-1.2.10/pngwtran.c (function _png_do_write_transformations)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwtran.c
