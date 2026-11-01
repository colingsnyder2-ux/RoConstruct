// from server: 100% by auto
// roc 2007-03 0051adf0  unit: seg_00510000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0051adf0
//
// 0051adf0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0051adf4  8a01                 mov al, byte ptr [ecx]
// 0051adf6  3c41                 cmp al, 0x41
// 0051adf8  7245                 jb 0x51ae3f
// 0051adfa  3c7a                 cmp al, 0x7a
// 0051adfc  7741                 ja 0x51ae3f
// 0051adfe  3c5a                 cmp al, 0x5a
// 0051ae00  7604                 jbe 0x51ae06
// 0051ae02  3c61                 cmp al, 0x61
// 0051ae04  7239                 jb 0x51ae3f
// 0051ae06  8a4101               mov al, byte ptr [ecx + 1]
// 0051ae09  3c41                 cmp al, 0x41
// 0051ae0b  7232                 jb 0x51ae3f
// 0051ae0d  3c7a                 cmp al, 0x7a
// 0051ae0f  772e                 ja 0x51ae3f
// 0051ae11  3c5a                 cmp al, 0x5a
// 0051ae13  7604                 jbe 0x51ae19
// 0051ae15  3c61                 cmp al, 0x61
// 0051ae17  7226                 jb 0x51ae3f
// 0051ae19  8a4102               mov al, byte ptr [ecx + 2]
// 0051ae1c  3c41                 cmp al, 0x41
// 0051ae1e  721f                 jb 0x51ae3f
// 0051ae20  3c7a                 cmp al, 0x7a
// 0051ae22  771b                 ja 0x51ae3f
// 0051ae24  3c5a                 cmp al, 0x5a
// 0051ae26  7604                 jbe 0x51ae2c
// 0051ae28  3c61                 cmp al, 0x61
// 0051ae2a  7213                 jb 0x51ae3f
// 0051ae2c  8a4103               mov al, byte ptr [ecx + 3]
// 0051ae2f  3c41                 cmp al, 0x41
// 0051ae31  720c                 jb 0x51ae3f
// 0051ae33  3c7a                 cmp al, 0x7a
// 0051ae35  7708                 ja 0x51ae3f
// 0051ae37  3c5a                 cmp al, 0x5a
// 0051ae39  7611                 jbe 0x51ae4c
// 0051ae3b  3c61                 cmp al, 0x61
// 0051ae3d  730d                 jae 0x51ae4c
// 0051ae3f  c7442408e0367a00     mov dword ptr [esp + 8], 0x7a36e0
// 0051ae47  e9e4d5ffff           jmp 0x518430
// 0051ae4c  c3                   ret 
// library libpng-1.2.7/pngrutil.c (function _png_check_chunk_name)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrutil.c
