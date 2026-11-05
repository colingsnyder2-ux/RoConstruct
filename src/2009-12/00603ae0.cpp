// from server: 100% by auto
// roc 2009-12 00603ae0  unit: seg_00600000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00603ae0
//
// 00603ae0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00603ae4  85c9                 test ecx, ecx
// 00603ae6  7438                 je 0x603b20
// 00603ae8  8b542408             mov edx, dword ptr [esp + 8]
// 00603aec  85d2                 test edx, edx
// 00603aee  7430                 je 0x603b20
// 00603af0  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 00603af7  7e27                 jle 0x603b20
// 00603af9  8b8120020000         mov eax, dword ptr [ecx + 0x220]
// 00603aff  8b8924020000         mov ecx, dword ptr [ecx + 0x224]
// 00603b05  56                   push esi
// 00603b06  8d3480               lea esi, [eax + eax*4]
// 00603b09  8d4c0efb             lea ecx, [esi + ecx - 5]
// 00603b0d  5e                   pop esi
// 00603b0e  85c0                 test eax, eax
// 00603b10  740e                 je 0x603b20
// 00603b12  8b12                 mov edx, dword ptr [edx]
// 00603b14  3b11                 cmp edx, dword ptr [ecx]
// 00603b16  740b                 je 0x603b23
// 00603b18  48                   dec eax
// 00603b19  83e905               sub ecx, 5
// 00603b1c  85c0                 test eax, eax
// 00603b1e  75f4                 jne 0x603b14
// 00603b20  33c0                 xor eax, eax
// 00603b22  c3                   ret 
// 00603b23  0fb64104             movzx eax, byte ptr [ecx + 4]
// 00603b27  c3                   ret 
// library libpng-1.2.22/png.c (function _png_handle_as_unknown)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 png.c
