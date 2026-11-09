// from server: 100% by auto
// roc 2011-06 0056c110  unit: seg_00560000  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056c110
//
// 0056c110  83ec08               sub esp, 8
// 0056c113  56                   push esi
// 0056c114  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056c118  c644240449           mov byte ptr [esp + 4], 0x49
// 0056c11d  c644240545           mov byte ptr [esp + 5], 0x45
// 0056c122  c64424064e           mov byte ptr [esp + 6], 0x4e
// 0056c127  c644240744           mov byte ptr [esp + 7], 0x44
// 0056c12c  c644240800           mov byte ptr [esp + 8], 0
// 0056c131  85f6                 test esi, esi
// 0056c133  7442                 je 0x56c177
// 0056c135  6a00                 push 0
// 0056c137  8d442408             lea eax, [esp + 8]
// 0056c13b  50                   push eax
// 0056c13c  56                   push esi
// 0056c13d  e86ee8ffff           call 0x56a9b0
// 0056c142  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056c148  8bd0                 mov edx, eax
// 0056c14a  8bc8                 mov ecx, eax
// 0056c14c  c1e918               shr ecx, 0x18
// 0056c14f  c1ea10               shr edx, 0x10
// 0056c152  884c241c             mov byte ptr [esp + 0x1c], cl
// 0056c156  8854241d             mov byte ptr [esp + 0x1d], dl
// 0056c15a  6a04                 push 4
// 0056c15c  8d542420             lea edx, [esp + 0x20]
// 0056c160  8bc8                 mov ecx, eax
// 0056c162  52                   push edx
// 0056c163  c1e908               shr ecx, 8
// 0056c166  56                   push esi
// 0056c167  884c242a             mov byte ptr [esp + 0x2a], cl
// 0056c16b  8844242b             mov byte ptr [esp + 0x2b], al
// 0056c16f  e8cce6feff           call 0x55a840
// 0056c174  83c418               add esp, 0x18
// 0056c177  834e6810             or dword ptr [esi + 0x68], 0x10
// 0056c17b  5e                   pop esi
// 0056c17c  83c408               add esp, 8
// 0056c17f  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_IEND)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
