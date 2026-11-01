// from server: 100% by auto
// roc 2009-12 007d2210  unit: seg_007d0000  size: 198 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d2210
//
// 007d2210  83ec34               sub esp, 0x34
// 007d2213  817b101d010000       cmp dword ptr [ebx + 0x10], 0x11d
// 007d221a  55                   push ebp
// 007d221b  8b6b30               mov ebp, dword ptr [ebx + 0x30]
// 007d221e  8b4524               mov eax, dword ptr [ebp + 0x24]
// 007d2221  56                   push esi
// 007d2222  57                   push edi
// 007d2223  8944240c             mov dword ptr [esp + 0xc], eax
// 007d2227  7527                 jne 0x7d2250
// 007d2229  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 007d222d  bafdffff7f           mov edx, 0x7ffffffd
// 007d2232  39511c               cmp dword ptr [ecx + 0x1c], edx
// 007d2235  7e0c                 jle 0x7d2243
// 007d2237  b9ccee9e00           mov ecx, 0x9eeecc
// 007d223c  8bf5                 mov esi, ebp
// 007d223e  e84df6ffff           call 0x7d1890
// 007d2243  8d7c2410             lea edi, [esp + 0x10]
// 007d2247  8bf3                 mov esi, ebx
// 007d2249  e822f7ffff           call 0x7d1970
// 007d224e  eb0b                 jmp 0x7d225b
// 007d2250  8d7c2410             lea edi, [esp + 0x10]
// 007d2254  8bf3                 mov esi, ebx
// 007d2256  e865ffffff           call 0x7d21c0
// 007d225b  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 007d225f  ff471c               inc dword ptr [edi + 0x1c]
// 007d2262  837b103d             cmp dword ptr [ebx + 0x10], 0x3d
// 007d2266  7421                 je 0x7d2289
// 007d2268  6a3d                 push 0x3d
// 007d226a  53                   push ebx
// 007d226b  e8d02f0000           call 0x7d5240
// 007d2270  8b5334               mov edx, dword ptr [ebx + 0x34]
// 007d2273  50                   push eax
// 007d2274  68d0ed9e00           push 0x9eedd0
// 007d2279  52                   push edx
// 007d227a  e80183fcff           call 0x79a580
// 007d227f  50                   push eax
// 007d2280  53                   push ebx
// 007d2281  e8ba300000           call 0x7d5340
// 007d2286  83c41c               add esp, 0x1c
// 007d2289  53                   push ebx
// 007d228a  e8a1440000           call 0x7d6730
// 007d228f  8d442414             lea eax, [esp + 0x14]
// 007d2293  50                   push eax
// 007d2294  55                   push ebp
// 007d2295  e866aa0000           call 0x7dcd00
// 007d229a  6a00                 push 0
// 007d229c  8d4c2438             lea ecx, [esp + 0x38]
// 007d22a0  51                   push ecx
// 007d22a1  53                   push ebx
// 007d22a2  8bf0                 mov esi, eax
// 007d22a4  e8070e0000           call 0x7d30b0
// 007d22a9  8d542440             lea edx, [esp + 0x40]
// 007d22ad  52                   push edx
// 007d22ae  55                   push ebp
// 007d22af  e84caa0000           call 0x7dcd00
// 007d22b4  50                   push eax
// 007d22b5  8b4718               mov eax, dword ptr [edi + 0x18]
// 007d22b8  8b4808               mov ecx, dword ptr [eax + 8]
// 007d22bb  56                   push esi
// 007d22bc  51                   push ecx
// 007d22bd  6a09                 push 9
// 007d22bf  55                   push ebp
// 007d22c0  e83ba30000           call 0x7dc600
// 007d22c5  8b542440             mov edx, dword ptr [esp + 0x40]
// 007d22c9  83c434               add esp, 0x34
// 007d22cc  5f                   pop edi
// 007d22cd  5e                   pop esi
// 007d22ce  895524               mov dword ptr [ebp + 0x24], edx
// 007d22d1  5d                   pop ebp
// 007d22d2  83c434               add esp, 0x34
// 007d22d5  c3                   ret 
// library lua-5.1.1/lparser.c (function _recfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
