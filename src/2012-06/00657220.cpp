// from server: 100% by auto
// roc 2012-06 00657220  unit: seg_00650000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00657220
//
// 00657220  56                   push esi
// 00657221  8b742408             mov esi, dword ptr [esp + 8]
// 00657225  85f6                 test esi, esi
// 00657227  746b                 je 0x657294
// 00657229  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0065722d  53                   push ebx
// 0065722e  57                   push edi
// 0065722f  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00657233  57                   push edi
// 00657234  50                   push eax
// 00657235  56                   push esi
// 00657236  e885eeffff           call 0x6560c0
// 0065723b  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0065723f  83c40c               add esp, 0xc
// 00657242  85db                 test ebx, ebx
// 00657244  7417                 je 0x65725d
// 00657246  85ff                 test edi, edi
// 00657248  7613                 jbe 0x65725d
// 0065724a  57                   push edi
// 0065724b  53                   push ebx
// 0065724c  56                   push esi
// 0065724d  e86e04ffff           call 0x6476c0
// 00657252  57                   push edi
// 00657253  53                   push ebx
// 00657254  56                   push esi
// 00657255  e8366cfeff           call 0x63de90
// 0065725a  83c418               add esp, 0x18
// 0065725d  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 00657263  8bd0                 mov edx, eax
// 00657265  8bc8                 mov ecx, eax
// 00657267  c1e918               shr ecx, 0x18
// 0065726a  c1ea10               shr edx, 0x10
// 0065726d  884c2410             mov byte ptr [esp + 0x10], cl
// 00657271  88542411             mov byte ptr [esp + 0x11], dl
// 00657275  6a04                 push 4
// 00657277  8d542414             lea edx, [esp + 0x14]
// 0065727b  8bc8                 mov ecx, eax
// 0065727d  52                   push edx
// 0065727e  c1e908               shr ecx, 8
// 00657281  56                   push esi
// 00657282  884c241e             mov byte ptr [esp + 0x1e], cl
// 00657286  8844241f             mov byte ptr [esp + 0x1f], al
// 0065728a  e83104ffff           call 0x6476c0
// 0065728f  83c40c               add esp, 0xc
// 00657292  5f                   pop edi
// 00657293  5b                   pop ebx
// 00657294  5e                   pop esi
// 00657295  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
