// from server: 100% by auto
// roc 2011-06 0056b1e0  unit: seg_00560000  size: 265 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056b1e0
//
// 0056b1e0  83ec0c               sub esp, 0xc
// 0056b1e3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056b1e7  53                   push ebx
// 0056b1e8  b074                 mov al, 0x74
// 0056b1ea  56                   push esi
// 0056b1eb  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056b1ef  8844240c             mov byte ptr [esp + 0xc], al
// 0056b1f3  8844240f             mov byte ptr [esp + 0xf], al
// 0056b1f7  8d442408             lea eax, [esp + 8]
// 0056b1fb  50                   push eax
// 0056b1fc  51                   push ecx
// 0056b1fd  56                   push esi
// 0056b1fe  c644241945           mov byte ptr [esp + 0x19], 0x45
// 0056b203  c644241a58           mov byte ptr [esp + 0x1a], 0x58
// 0056b208  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0056b20d  e8eefdffff           call 0x56b000
// 0056b212  8bd8                 mov ebx, eax
// 0056b214  83c40c               add esp, 0xc
// 0056b217  85db                 test ebx, ebx
// 0056b219  0f84c4000000         je 0x56b2e3
// 0056b21f  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056b223  55                   push ebp
// 0056b224  57                   push edi
// 0056b225  85c0                 test eax, eax
// 0056b227  7415                 je 0x56b23e
// 0056b229  803800               cmp byte ptr [eax], 0
// 0056b22c  7410                 je 0x56b23e
// 0056b22e  8d5001               lea edx, [eax + 1]
// 0056b231  8a08                 mov cl, byte ptr [eax]
// 0056b233  40                   inc eax
// 0056b234  84c9                 test cl, cl
// 0056b236  75f9                 jne 0x56b231
// 0056b238  2bc2                 sub eax, edx
// 0056b23a  8bf8                 mov edi, eax
// 0056b23c  eb02                 jmp 0x56b240
// 0056b23e  33ff                 xor edi, edi
// 0056b240  8d543b01             lea edx, [ebx + edi + 1]
// 0056b244  52                   push edx
// 0056b245  8d442418             lea eax, [esp + 0x18]
// 0056b249  50                   push eax
// 0056b24a  56                   push esi
// 0056b24b  e860f7ffff           call 0x56a9b0
// 0056b250  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0056b254  83c40c               add esp, 0xc
// 0056b257  43                   inc ebx
// 0056b258  85f6                 test esi, esi
// 0056b25a  741b                 je 0x56b277
// 0056b25c  85ed                 test ebp, ebp
// 0056b25e  7417                 je 0x56b277
// 0056b260  85db                 test ebx, ebx
// 0056b262  7613                 jbe 0x56b277
// 0056b264  53                   push ebx
// 0056b265  55                   push ebp
// 0056b266  56                   push esi
// 0056b267  e8d4f5feff           call 0x55a840
// 0056b26c  53                   push ebx
// 0056b26d  55                   push ebp
// 0056b26e  56                   push esi
// 0056b26f  e8dc55feff           call 0x550850
// 0056b274  83c418               add esp, 0x18
// 0056b277  85ff                 test edi, edi
// 0056b279  7423                 je 0x56b29e
// 0056b27b  85f6                 test esi, esi
// 0056b27d  7458                 je 0x56b2d7
// 0056b27f  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0056b283  85db                 test ebx, ebx
// 0056b285  7417                 je 0x56b29e
// 0056b287  85ff                 test edi, edi
// 0056b289  7613                 jbe 0x56b29e
// 0056b28b  57                   push edi
// 0056b28c  53                   push ebx
// 0056b28d  56                   push esi
// 0056b28e  e8adf5feff           call 0x55a840
// 0056b293  57                   push edi
// 0056b294  53                   push ebx
// 0056b295  56                   push esi
// 0056b296  e8b555feff           call 0x550850
// 0056b29b  83c418               add esp, 0x18
// 0056b29e  85f6                 test esi, esi
// 0056b2a0  7435                 je 0x56b2d7
// 0056b2a2  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056b2a8  8bd0                 mov edx, eax
// 0056b2aa  8bc8                 mov ecx, eax
// 0056b2ac  c1e918               shr ecx, 0x18
// 0056b2af  c1ea10               shr edx, 0x10
// 0056b2b2  884c2410             mov byte ptr [esp + 0x10], cl
// 0056b2b6  88542411             mov byte ptr [esp + 0x11], dl
// 0056b2ba  6a04                 push 4
// 0056b2bc  8d542414             lea edx, [esp + 0x14]
// 0056b2c0  8bc8                 mov ecx, eax
// 0056b2c2  52                   push edx
// 0056b2c3  c1e908               shr ecx, 8
// 0056b2c6  56                   push esi
// 0056b2c7  884c241e             mov byte ptr [esp + 0x1e], cl
// 0056b2cb  8844241f             mov byte ptr [esp + 0x1f], al
// 0056b2cf  e86cf5feff           call 0x55a840
// 0056b2d4  83c40c               add esp, 0xc
// 0056b2d7  55                   push ebp
// 0056b2d8  56                   push esi
// 0056b2d9  e8c263ffff           call 0x5616a0
// 0056b2de  83c408               add esp, 8
// 0056b2e1  5f                   pop edi
// 0056b2e2  5d                   pop ebp
// 0056b2e3  5e                   pop esi
// 0056b2e4  5b                   pop ebx
// 0056b2e5  83c40c               add esp, 0xc
// 0056b2e8  c3                   ret 
// library libpng-1.2.35/pngwutil.c (function _png_write_tEXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngwutil.c
