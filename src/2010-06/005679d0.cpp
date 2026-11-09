// from server: 100% by auto
// roc 2010-06 005679d0  unit: seg_00560000  size: 438 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005679d0
//
// 005679d0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005679d4  56                   push esi
// 005679d5  8b742408             mov esi, dword ptr [esp + 8]
// 005679d9  8b4670               mov eax, dword ptr [esi + 0x70]
// 005679dc  a900100000           test eax, 0x1000
// 005679e1  7460                 je 0x567a43
// 005679e3  8a5119               mov dl, byte ptr [ecx + 0x19]
// 005679e6  80fa03               cmp dl, 3
// 005679e9  7531                 jne 0x567a1c
// 005679eb  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 005679f3  7417                 je 0x567a0c
// 005679f5  a900000002           test eax, 0x2000000
// 005679fa  7410                 je 0x567a0c
// 005679fc  33c0                 xor eax, eax
// 005679fe  c6411906             mov byte ptr [ecx + 0x19], 6
// 00567a02  c6411808             mov byte ptr [ecx + 0x18], 8
// 00567a06  66894116             mov word ptr [ecx + 0x16], ax
// 00567a0a  eb37                 jmp 0x567a43
// 00567a0c  33c0                 xor eax, eax
// 00567a0e  c6411902             mov byte ptr [ecx + 0x19], 2
// 00567a12  c6411808             mov byte ptr [ecx + 0x18], 8
// 00567a16  66894116             mov word ptr [ecx + 0x16], ax
// 00567a1a  eb27                 jmp 0x567a43
// 00567a1c  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 00567a24  740d                 je 0x567a33
// 00567a26  a900000002           test eax, 0x2000000
// 00567a2b  7406                 je 0x567a33
// 00567a2d  80ca04               or dl, 4
// 00567a30  885119               mov byte ptr [ecx + 0x19], dl
// 00567a33  80791808             cmp byte ptr [ecx + 0x18], 8
// 00567a37  7304                 jae 0x567a3d
// 00567a39  c6411808             mov byte ptr [ecx + 0x18], 8
// 00567a3d  33d2                 xor edx, edx
// 00567a3f  66895116             mov word ptr [ecx + 0x16], dx
// 00567a43  f6467080             test byte ptr [esi + 0x70], 0x80
// 00567a47  7427                 je 0x567a70
// 00567a49  806119fb             and byte ptr [ecx + 0x19], 0xfb
// 00567a4d  33c0                 xor eax, eax
// 00567a4f  66894116             mov word ptr [ecx + 0x16], ax
// 00567a53  8b9638010000         mov edx, dword ptr [esi + 0x138]
// 00567a59  89515a               mov dword ptr [ecx + 0x5a], edx
// 00567a5c  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 00567a62  89415e               mov dword ptr [ecx + 0x5e], eax
// 00567a65  668b9640010000       mov dx, word ptr [esi + 0x140]
// 00567a6c  66895162             mov word ptr [ecx + 0x62], dx
// 00567a70  f7467000200000       test dword ptr [esi + 0x70], 0x2000
// 00567a77  7415                 je 0x567a8e
// 00567a79  d9865c010000         fld dword ptr [esi + 0x15c]
// 00567a7f  d95928               fstp dword ptr [ecx + 0x28]
// 00567a82  8b8634020000         mov eax, dword ptr [esi + 0x234]
// 00567a88  8981fc000000         mov dword ptr [ecx + 0xfc], eax
// 00567a8e  f7467000040000       test dword ptr [esi + 0x70], 0x400
// 00567a95  740a                 je 0x567aa1
// 00567a97  80791810             cmp byte ptr [ecx + 0x18], 0x10
// 00567a9b  7504                 jne 0x567aa1
// 00567a9d  c6411808             mov byte ptr [ecx + 0x18], 8
// 00567aa1  f7467000400000       test dword ptr [esi + 0x70], 0x4000
// 00567aa8  7404                 je 0x567aae
// 00567aaa  80491902             or byte ptr [ecx + 0x19], 2
// 00567aae  f7467000006000       test dword ptr [esi + 0x70], 0x600000
// 00567ab5  7404                 je 0x567abb
// 00567ab7  806119fd             and byte ptr [ecx + 0x19], 0xfd
// 00567abb  f6467040             test byte ptr [esi + 0x70], 0x40
// 00567abf  741e                 je 0x567adf
// 00567ac1  8a4119               mov al, byte ptr [ecx + 0x19]
// 00567ac4  3c02                 cmp al, 2
// 00567ac6  7404                 je 0x567acc
// 00567ac8  3c06                 cmp al, 6
// 00567aca  7513                 jne 0x567adf
// 00567acc  83beec01000000       cmp dword ptr [esi + 0x1ec], 0
// 00567ad3  740a                 je 0x567adf
// 00567ad5  80791808             cmp byte ptr [ecx + 0x18], 8
// 00567ad9  7504                 jne 0x567adf
// 00567adb  c6411903             mov byte ptr [ecx + 0x19], 3
// 00567adf  f6467004             test byte ptr [esi + 0x70], 4
// 00567ae3  740a                 je 0x567aef
// 00567ae5  80791808             cmp byte ptr [ecx + 0x18], 8
// 00567ae9  7304                 jae 0x567aef
// 00567aeb  c6411808             mov byte ptr [ecx + 0x18], 8
// 00567aef  8a4119               mov al, byte ptr [ecx + 0x19]
// 00567af2  b201                 mov dl, 1
// 00567af4  3c03                 cmp al, 3
// 00567af6  740a                 je 0x567b02
// 00567af8  a802                 test al, 2
// 00567afa  7406                 je 0x567b02
// 00567afc  c6411d03             mov byte ptr [ecx + 0x1d], 3
// 00567b00  eb03                 jmp 0x567b05
// 00567b02  88511d               mov byte ptr [ecx + 0x1d], dl
// 00567b05  f7466c00004000       test dword ptr [esi + 0x6c], 0x400000
// 00567b0c  7405                 je 0x567b13
// 00567b0e  24fb                 and al, 0xfb
// 00567b10  884119               mov byte ptr [ecx + 0x19], al
// 00567b13  8a4119               mov al, byte ptr [ecx + 0x19]
// 00567b16  a804                 test al, 4
// 00567b18  7403                 je 0x567b1d
// 00567b1a  00511d               add byte ptr [ecx + 0x1d], dl
// 00567b1d  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 00567b24  7419                 je 0x567b3f
// 00567b26  3c02                 cmp al, 2
// 00567b28  7404                 je 0x567b2e
// 00567b2a  84c0                 test al, al
// 00567b2c  7511                 jne 0x567b3f
// 00567b2e  00511d               add byte ptr [ecx + 0x1d], dl
// 00567b31  f7467000000001       test dword ptr [esi + 0x70], 0x1000000
// 00567b38  7405                 je 0x567b3f
// 00567b3a  0c04                 or al, 4
// 00567b3c  884119               mov byte ptr [ecx + 0x19], al
// 00567b3f  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 00567b46  7416                 je 0x567b5e
// 00567b48  8a4664               mov al, byte ptr [esi + 0x64]
// 00567b4b  384118               cmp byte ptr [ecx + 0x18], al
// 00567b4e  7303                 jae 0x567b53
// 00567b50  884118               mov byte ptr [ecx + 0x18], al
// 00567b53  8a4665               mov al, byte ptr [esi + 0x65]
// 00567b56  38411d               cmp byte ptr [ecx + 0x1d], al
// 00567b59  7303                 jae 0x567b5e
// 00567b5b  88411d               mov byte ptr [ecx + 0x1d], al
// 00567b5e  8a4118               mov al, byte ptr [ecx + 0x18]
// 00567b61  f6691d               imul byte ptr [ecx + 0x1d]
// 00567b64  88411e               mov byte ptr [ecx + 0x1e], al
// 00567b67  3c08                 cmp al, 8
// 00567b69  5e                   pop esi
// 00567b6a  0fb6c0               movzx eax, al
// 00567b6d  720a                 jb 0x567b79
// 00567b6f  c1e803               shr eax, 3
// 00567b72  0faf01               imul eax, dword ptr [ecx]
// 00567b75  89410c               mov dword ptr [ecx + 0xc], eax
// 00567b78  c3                   ret 
// 00567b79  0faf01               imul eax, dword ptr [ecx]
// 00567b7c  83c007               add eax, 7
// 00567b7f  c1e803               shr eax, 3
// 00567b82  89410c               mov dword ptr [ecx + 0xc], eax
// 00567b85  c3                   ret 
// library libpng-1.2.29/pngrtran.c (function _png_read_transform_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngrtran.c
