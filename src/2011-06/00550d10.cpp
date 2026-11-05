// from server: 100% by auto
// roc 2011-06 00550d10  unit: seg_00550000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00550d10
//
// 00550d10  8b442404             mov eax, dword ptr [esp + 4]
// 00550d14  53                   push ebx
// 00550d15  56                   push esi
// 00550d16  8b742410             mov esi, dword ptr [esp + 0x10]
// 00550d1a  8bce                 mov ecx, esi
// 00550d1c  8bd0                 mov edx, eax
// 00550d1e  25ffff0000           and eax, 0xffff
// 00550d23  8bd8                 mov ebx, eax
// 00550d25  c1fa10               sar edx, 0x10
// 00550d28  c1f910               sar ecx, 0x10
// 00550d2b  81e2ffff0000         and edx, 0xffff
// 00550d31  81e6ffff0000         and esi, 0xffff
// 00550d37  81e1ffff0000         and ecx, 0xffff
// 00550d3d  57                   push edi
// 00550d3e  8bfe                 mov edi, esi
// 00550d40  0faff2               imul esi, edx
// 00550d43  8bc1                 mov eax, ecx
// 00550d45  0faffb               imul edi, ebx
// 00550d48  0fafca               imul ecx, edx
// 00550d4b  0fafc3               imul eax, ebx
// 00550d4e  03c6                 add eax, esi
// 00550d50  8bf7                 mov esi, edi
// 00550d52  c1fe10               sar esi, 0x10
// 00550d55  81e6ffff0000         and esi, 0xffff
// 00550d5b  03c6                 add eax, esi
// 00550d5d  8bd0                 mov edx, eax
// 00550d5f  c1fa10               sar edx, 0x10
// 00550d62  81e2ffff0000         and edx, 0xffff
// 00550d68  03ca                 add ecx, edx
// 00550d6a  8b542418             mov edx, dword ptr [esp + 0x18]
// 00550d6e  890a                 mov dword ptr [edx], ecx
// 00550d70  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00550d74  0fb7cf               movzx ecx, di
// 00550d77  5f                   pop edi
// 00550d78  c1e010               shl eax, 0x10
// 00550d7b  0bc1                 or eax, ecx
// 00550d7d  5e                   pop esi
// 00550d7e  8902                 mov dword ptr [edx], eax
// 00550d80  5b                   pop ebx
// 00550d81  c3                   ret 
// library libpng-1.2.35/png.c (function _png_64bit_product)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 png.c
