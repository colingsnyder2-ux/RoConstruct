// from server: 100% by auto
// roc 2009-12 00605990  unit: seg_00600000  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00605990
//
// 00605990  51                   push ecx
// 00605991  8b442408             mov eax, dword ptr [esp + 8]
// 00605995  53                   push ebx
// 00605996  57                   push edi
// 00605997  33ff                 xor edi, edi
// 00605999  33db                 xor ebx, ebx
// 0060599b  85c0                 test eax, eax
// 0060599d  0f84ac000000         je 0x605a4f
// 006059a3  56                   push esi
// 006059a4  8b30                 mov esi, dword ptr [eax]
// 006059a6  85f6                 test esi, esi
// 006059a8  0f84a0000000         je 0x605a4e
// 006059ae  8b8644020000         mov eax, dword ptr [esi + 0x244]
// 006059b4  8944240c             mov dword ptr [esp + 0xc], eax
// 006059b8  8b442418             mov eax, dword ptr [esp + 0x18]
// 006059bc  55                   push ebp
// 006059bd  8bae4c020000         mov ebp, dword ptr [esi + 0x24c]
// 006059c3  85c0                 test eax, eax
// 006059c5  7402                 je 0x6059c9
// 006059c7  8b38                 mov edi, dword ptr [eax]
// 006059c9  8b442420             mov eax, dword ptr [esp + 0x20]
// 006059cd  85c0                 test eax, eax
// 006059cf  7402                 je 0x6059d3
// 006059d1  8b18                 mov ebx, dword ptr [eax]
// 006059d3  53                   push ebx
// 006059d4  57                   push edi
// 006059d5  56                   push esi
// 006059d6  e8e5fcffff           call 0x6056c0
// 006059db  83c40c               add esp, 0xc
// 006059de  85ff                 test edi, edi
// 006059e0  7427                 je 0x605a09
// 006059e2  6aff                 push -1
// 006059e4  6800400000           push 0x4000
// 006059e9  57                   push edi
// 006059ea  56                   push esi
// 006059eb  e8d0dcffff           call 0x6036c0
// 006059f0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006059f4  51                   push ecx
// 006059f5  55                   push ebp
// 006059f6  57                   push edi
// 006059f7  e8a4b10000           call 0x610ba0
// 006059fc  8b542438             mov edx, dword ptr [esp + 0x38]
// 00605a00  83c41c               add esp, 0x1c
// 00605a03  c70200000000         mov dword ptr [edx], 0
// 00605a09  85db                 test ebx, ebx
// 00605a0b  7427                 je 0x605a34
// 00605a0d  6aff                 push -1
// 00605a0f  6800400000           push 0x4000
// 00605a14  53                   push ebx
// 00605a15  56                   push esi
// 00605a16  e8a5dcffff           call 0x6036c0
// 00605a1b  8b442420             mov eax, dword ptr [esp + 0x20]
// 00605a1f  50                   push eax
// 00605a20  55                   push ebp
// 00605a21  53                   push ebx
// 00605a22  e879b10000           call 0x610ba0
// 00605a27  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00605a2b  83c41c               add esp, 0x1c
// 00605a2e  c70100000000         mov dword ptr [ecx], 0
// 00605a34  8b542410             mov edx, dword ptr [esp + 0x10]
// 00605a38  52                   push edx
// 00605a39  55                   push ebp
// 00605a3a  56                   push esi
// 00605a3b  e860b10000           call 0x610ba0
// 00605a40  8b442424             mov eax, dword ptr [esp + 0x24]
// 00605a44  83c40c               add esp, 0xc
// 00605a47  c70000000000         mov dword ptr [eax], 0
// 00605a4d  5d                   pop ebp
// 00605a4e  5e                   pop esi
// 00605a4f  5f                   pop edi
// 00605a50  5b                   pop ebx
// 00605a51  59                   pop ecx
// 00605a52  c3                   ret 
// library libpng-1.2.29/pngread.c (function _png_destroy_read_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngread.c
