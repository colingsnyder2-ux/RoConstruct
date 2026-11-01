// from server: 100% by auto
// roc 2009-12 00615ed0  unit: seg_00610000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00615ed0
//
// 00615ed0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00615ed4  8a01                 mov al, byte ptr [ecx]
// 00615ed6  3c41                 cmp al, 0x41
// 00615ed8  7245                 jb 0x615f1f
// 00615eda  3c7a                 cmp al, 0x7a
// 00615edc  7741                 ja 0x615f1f
// 00615ede  3c5a                 cmp al, 0x5a
// 00615ee0  7604                 jbe 0x615ee6
// 00615ee2  3c61                 cmp al, 0x61
// 00615ee4  7239                 jb 0x615f1f
// 00615ee6  8a4101               mov al, byte ptr [ecx + 1]
// 00615ee9  3c41                 cmp al, 0x41
// 00615eeb  7232                 jb 0x615f1f
// 00615eed  3c7a                 cmp al, 0x7a
// 00615eef  772e                 ja 0x615f1f
// 00615ef1  3c5a                 cmp al, 0x5a
// 00615ef3  7604                 jbe 0x615ef9
// 00615ef5  3c61                 cmp al, 0x61
// 00615ef7  7226                 jb 0x615f1f
// 00615ef9  8a4102               mov al, byte ptr [ecx + 2]
// 00615efc  3c41                 cmp al, 0x41
// 00615efe  721f                 jb 0x615f1f
// 00615f00  3c7a                 cmp al, 0x7a
// 00615f02  771b                 ja 0x615f1f
// 00615f04  3c5a                 cmp al, 0x5a
// 00615f06  7604                 jbe 0x615f0c
// 00615f08  3c61                 cmp al, 0x61
// 00615f0a  7213                 jb 0x615f1f
// 00615f0c  8a4103               mov al, byte ptr [ecx + 3]
// 00615f0f  3c41                 cmp al, 0x41
// 00615f11  720c                 jb 0x615f1f
// 00615f13  3c7a                 cmp al, 0x7a
// 00615f15  7708                 ja 0x615f1f
// 00615f17  3c5a                 cmp al, 0x5a
// 00615f19  7611                 jbe 0x615f2c
// 00615f1b  3c61                 cmp al, 0x61
// 00615f1d  730d                 jae 0x615f2c
// 00615f1f  c7442408488f9c00     mov dword ptr [esp + 8], 0x9c8f48
// 00615f27  e974a3ffff           jmp 0x6102a0
// 00615f2c  c3                   ret 
// library libpng-1.2.6/pngrutil.c (function _png_check_chunk_name)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngrutil.c
