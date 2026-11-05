// from server: 100% by auto
// roc 2009-06 0058ba20  unit: seg_00580000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058ba20
//
// 0058ba20  56                   push esi
// 0058ba21  8b742408             mov esi, dword ptr [esp + 8]
// 0058ba25  85f6                 test esi, esi
// 0058ba27  746b                 je 0x58ba94
// 0058ba29  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0058ba2d  53                   push ebx
// 0058ba2e  57                   push edi
// 0058ba2f  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0058ba33  57                   push edi
// 0058ba34  50                   push eax
// 0058ba35  56                   push esi
// 0058ba36  e885eeffff           call 0x58a8c0
// 0058ba3b  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0058ba3f  83c40c               add esp, 0xc
// 0058ba42  85db                 test ebx, ebx
// 0058ba44  7417                 je 0x58ba5d
// 0058ba46  85ff                 test edi, edi
// 0058ba48  7613                 jbe 0x58ba5d
// 0058ba4a  57                   push edi
// 0058ba4b  53                   push ebx
// 0058ba4c  56                   push esi
// 0058ba4d  e88e5bffff           call 0x5815e0
// 0058ba52  57                   push edi
// 0058ba53  53                   push ebx
// 0058ba54  56                   push esi
// 0058ba55  e8665effff           call 0x5818c0
// 0058ba5a  83c418               add esp, 0x18
// 0058ba5d  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0058ba63  8bd0                 mov edx, eax
// 0058ba65  8bc8                 mov ecx, eax
// 0058ba67  c1e918               shr ecx, 0x18
// 0058ba6a  c1ea10               shr edx, 0x10
// 0058ba6d  884c2410             mov byte ptr [esp + 0x10], cl
// 0058ba71  88542411             mov byte ptr [esp + 0x11], dl
// 0058ba75  6a04                 push 4
// 0058ba77  8d542414             lea edx, [esp + 0x14]
// 0058ba7b  8bc8                 mov ecx, eax
// 0058ba7d  52                   push edx
// 0058ba7e  c1e908               shr ecx, 8
// 0058ba81  56                   push esi
// 0058ba82  884c241e             mov byte ptr [esp + 0x1e], cl
// 0058ba86  8844241f             mov byte ptr [esp + 0x1f], al
// 0058ba8a  e8515bffff           call 0x5815e0
// 0058ba8f  83c40c               add esp, 0xc
// 0058ba92  5f                   pop edi
// 0058ba93  5b                   pop ebx
// 0058ba94  5e                   pop esi
// 0058ba95  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
