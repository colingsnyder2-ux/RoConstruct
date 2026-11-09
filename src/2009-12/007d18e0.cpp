// from server: 100% by auto
// roc 2009-12 007d18e0  unit: seg_007d0000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d18e0
//
// 007d18e0  397e10               cmp dword ptr [esi + 0x10], edi
// 007d18e3  7509                 jne 0x7d18ee
// 007d18e5  89742404             mov dword ptr [esp + 4], esi
// 007d18e9  e9424e0000           jmp 0x7d6730
// 007d18ee  3b4604               cmp eax, dword ptr [esi + 4]
// 007d18f1  7521                 jne 0x7d1914
// 007d18f3  57                   push edi
// 007d18f4  56                   push esi
// 007d18f5  e846390000           call 0x7d5240
// 007d18fa  50                   push eax
// 007d18fb  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d18fe  68d0ed9e00           push 0x9eedd0
// 007d1903  50                   push eax
// 007d1904  e8778cfcff           call 0x79a580
// 007d1909  50                   push eax
// 007d190a  56                   push esi
// 007d190b  e8303a0000           call 0x7d5340
// 007d1910  83c41c               add esp, 0x1c
// 007d1913  c3                   ret 
// 007d1914  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d1918  50                   push eax
// 007d1919  51                   push ecx
// 007d191a  56                   push esi
// 007d191b  e820390000           call 0x7d5240
// 007d1920  83c408               add esp, 8
// 007d1923  50                   push eax
// 007d1924  57                   push edi
// 007d1925  56                   push esi
// 007d1926  e815390000           call 0x7d5240
// 007d192b  8b5634               mov edx, dword ptr [esi + 0x34]
// 007d192e  83c408               add esp, 8
// 007d1931  50                   push eax
// 007d1932  682cee9e00           push 0x9eee2c
// 007d1937  52                   push edx
// 007d1938  e8438cfcff           call 0x79a580
// 007d193d  50                   push eax
// 007d193e  56                   push esi
// 007d193f  e8fc390000           call 0x7d5340
// 007d1944  83c41c               add esp, 0x1c
// 007d1947  c3                   ret 
// library lua-5.1/lparser.c (function _check_match)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
