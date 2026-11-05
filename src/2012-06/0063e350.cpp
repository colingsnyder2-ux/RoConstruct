// from server: 100% by auto
// roc 2012-06 0063e350  unit: seg_00630000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063e350
//
// 0063e350  8b442404             mov eax, dword ptr [esp + 4]
// 0063e354  53                   push ebx
// 0063e355  56                   push esi
// 0063e356  8b742410             mov esi, dword ptr [esp + 0x10]
// 0063e35a  8bce                 mov ecx, esi
// 0063e35c  8bd0                 mov edx, eax
// 0063e35e  25ffff0000           and eax, 0xffff
// 0063e363  8bd8                 mov ebx, eax
// 0063e365  c1fa10               sar edx, 0x10
// 0063e368  c1f910               sar ecx, 0x10
// 0063e36b  81e2ffff0000         and edx, 0xffff
// 0063e371  81e6ffff0000         and esi, 0xffff
// 0063e377  81e1ffff0000         and ecx, 0xffff
// 0063e37d  57                   push edi
// 0063e37e  8bfe                 mov edi, esi
// 0063e380  0faff2               imul esi, edx
// 0063e383  8bc1                 mov eax, ecx
// 0063e385  0faffb               imul edi, ebx
// 0063e388  0fafca               imul ecx, edx
// 0063e38b  0fafc3               imul eax, ebx
// 0063e38e  03c6                 add eax, esi
// 0063e390  8bf7                 mov esi, edi
// 0063e392  c1fe10               sar esi, 0x10
// 0063e395  81e6ffff0000         and esi, 0xffff
// 0063e39b  03c6                 add eax, esi
// 0063e39d  8bd0                 mov edx, eax
// 0063e39f  c1fa10               sar edx, 0x10
// 0063e3a2  81e2ffff0000         and edx, 0xffff
// 0063e3a8  03ca                 add ecx, edx
// 0063e3aa  8b542418             mov edx, dword ptr [esp + 0x18]
// 0063e3ae  890a                 mov dword ptr [edx], ecx
// 0063e3b0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0063e3b4  0fb7cf               movzx ecx, di
// 0063e3b7  5f                   pop edi
// 0063e3b8  c1e010               shl eax, 0x10
// 0063e3bb  0bc1                 or eax, ecx
// 0063e3bd  5e                   pop esi
// 0063e3be  8902                 mov dword ptr [edx], eax
// 0063e3c0  5b                   pop ebx
// 0063e3c1  c3                   ret 
// library libpng-1.2.35/png.c (function _png_64bit_product)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 png.c
