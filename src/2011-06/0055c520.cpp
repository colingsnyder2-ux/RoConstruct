// from server: 100% by auto
// roc 2011-06 0055c520  unit: seg_00550000  size: 438 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055c520
//
// 0055c520  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0055c524  56                   push esi
// 0055c525  8b742408             mov esi, dword ptr [esp + 8]
// 0055c529  8b4670               mov eax, dword ptr [esi + 0x70]
// 0055c52c  a900100000           test eax, 0x1000
// 0055c531  7460                 je 0x55c593
// 0055c533  8a5119               mov dl, byte ptr [ecx + 0x19]
// 0055c536  80fa03               cmp dl, 3
// 0055c539  7531                 jne 0x55c56c
// 0055c53b  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 0055c543  7417                 je 0x55c55c
// 0055c545  a900000002           test eax, 0x2000000
// 0055c54a  7410                 je 0x55c55c
// 0055c54c  33c0                 xor eax, eax
// 0055c54e  c6411906             mov byte ptr [ecx + 0x19], 6
// 0055c552  c6411808             mov byte ptr [ecx + 0x18], 8
// 0055c556  66894116             mov word ptr [ecx + 0x16], ax
// 0055c55a  eb37                 jmp 0x55c593
// 0055c55c  33c0                 xor eax, eax
// 0055c55e  c6411902             mov byte ptr [ecx + 0x19], 2
// 0055c562  c6411808             mov byte ptr [ecx + 0x18], 8
// 0055c566  66894116             mov word ptr [ecx + 0x16], ax
// 0055c56a  eb27                 jmp 0x55c593
// 0055c56c  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 0055c574  740d                 je 0x55c583
// 0055c576  a900000002           test eax, 0x2000000
// 0055c57b  7406                 je 0x55c583
// 0055c57d  80ca04               or dl, 4
// 0055c580  885119               mov byte ptr [ecx + 0x19], dl
// 0055c583  80791808             cmp byte ptr [ecx + 0x18], 8
// 0055c587  7304                 jae 0x55c58d
// 0055c589  c6411808             mov byte ptr [ecx + 0x18], 8
// 0055c58d  33d2                 xor edx, edx
// 0055c58f  66895116             mov word ptr [ecx + 0x16], dx
// 0055c593  f6467080             test byte ptr [esi + 0x70], 0x80
// 0055c597  7427                 je 0x55c5c0
// 0055c599  806119fb             and byte ptr [ecx + 0x19], 0xfb
// 0055c59d  33c0                 xor eax, eax
// 0055c59f  66894116             mov word ptr [ecx + 0x16], ax
// 0055c5a3  8b9638010000         mov edx, dword ptr [esi + 0x138]
// 0055c5a9  89515a               mov dword ptr [ecx + 0x5a], edx
// 0055c5ac  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 0055c5b2  89415e               mov dword ptr [ecx + 0x5e], eax
// 0055c5b5  668b9640010000       mov dx, word ptr [esi + 0x140]
// 0055c5bc  66895162             mov word ptr [ecx + 0x62], dx
// 0055c5c0  f7467000200000       test dword ptr [esi + 0x70], 0x2000
// 0055c5c7  7415                 je 0x55c5de
// 0055c5c9  d9865c010000         fld dword ptr [esi + 0x15c]
// 0055c5cf  d95928               fstp dword ptr [ecx + 0x28]
// 0055c5d2  8b8634020000         mov eax, dword ptr [esi + 0x234]
// 0055c5d8  8981fc000000         mov dword ptr [ecx + 0xfc], eax
// 0055c5de  f7467000040000       test dword ptr [esi + 0x70], 0x400
// 0055c5e5  740a                 je 0x55c5f1
// 0055c5e7  80791810             cmp byte ptr [ecx + 0x18], 0x10
// 0055c5eb  7504                 jne 0x55c5f1
// 0055c5ed  c6411808             mov byte ptr [ecx + 0x18], 8
// 0055c5f1  f7467000400000       test dword ptr [esi + 0x70], 0x4000
// 0055c5f8  7404                 je 0x55c5fe
// 0055c5fa  80491902             or byte ptr [ecx + 0x19], 2
// 0055c5fe  f7467000006000       test dword ptr [esi + 0x70], 0x600000
// 0055c605  7404                 je 0x55c60b
// 0055c607  806119fd             and byte ptr [ecx + 0x19], 0xfd
// 0055c60b  f6467040             test byte ptr [esi + 0x70], 0x40
// 0055c60f  741e                 je 0x55c62f
// 0055c611  8a4119               mov al, byte ptr [ecx + 0x19]
// 0055c614  3c02                 cmp al, 2
// 0055c616  7404                 je 0x55c61c
// 0055c618  3c06                 cmp al, 6
// 0055c61a  7513                 jne 0x55c62f
// 0055c61c  83beec01000000       cmp dword ptr [esi + 0x1ec], 0
// 0055c623  740a                 je 0x55c62f
// 0055c625  80791808             cmp byte ptr [ecx + 0x18], 8
// 0055c629  7504                 jne 0x55c62f
// 0055c62b  c6411903             mov byte ptr [ecx + 0x19], 3
// 0055c62f  f6467004             test byte ptr [esi + 0x70], 4
// 0055c633  740a                 je 0x55c63f
// 0055c635  80791808             cmp byte ptr [ecx + 0x18], 8
// 0055c639  7304                 jae 0x55c63f
// 0055c63b  c6411808             mov byte ptr [ecx + 0x18], 8
// 0055c63f  8a4119               mov al, byte ptr [ecx + 0x19]
// 0055c642  b201                 mov dl, 1
// 0055c644  3c03                 cmp al, 3
// 0055c646  740a                 je 0x55c652
// 0055c648  a802                 test al, 2
// 0055c64a  7406                 je 0x55c652
// 0055c64c  c6411d03             mov byte ptr [ecx + 0x1d], 3
// 0055c650  eb03                 jmp 0x55c655
// 0055c652  88511d               mov byte ptr [ecx + 0x1d], dl
// 0055c655  f7466c00004000       test dword ptr [esi + 0x6c], 0x400000
// 0055c65c  7405                 je 0x55c663
// 0055c65e  24fb                 and al, 0xfb
// 0055c660  884119               mov byte ptr [ecx + 0x19], al
// 0055c663  8a4119               mov al, byte ptr [ecx + 0x19]
// 0055c666  a804                 test al, 4
// 0055c668  7403                 je 0x55c66d
// 0055c66a  00511d               add byte ptr [ecx + 0x1d], dl
// 0055c66d  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 0055c674  7419                 je 0x55c68f
// 0055c676  3c02                 cmp al, 2
// 0055c678  7404                 je 0x55c67e
// 0055c67a  84c0                 test al, al
// 0055c67c  7511                 jne 0x55c68f
// 0055c67e  00511d               add byte ptr [ecx + 0x1d], dl
// 0055c681  f7467000000001       test dword ptr [esi + 0x70], 0x1000000
// 0055c688  7405                 je 0x55c68f
// 0055c68a  0c04                 or al, 4
// 0055c68c  884119               mov byte ptr [ecx + 0x19], al
// 0055c68f  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 0055c696  7416                 je 0x55c6ae
// 0055c698  8a4664               mov al, byte ptr [esi + 0x64]
// 0055c69b  384118               cmp byte ptr [ecx + 0x18], al
// 0055c69e  7303                 jae 0x55c6a3
// 0055c6a0  884118               mov byte ptr [ecx + 0x18], al
// 0055c6a3  8a4665               mov al, byte ptr [esi + 0x65]
// 0055c6a6  38411d               cmp byte ptr [ecx + 0x1d], al
// 0055c6a9  7303                 jae 0x55c6ae
// 0055c6ab  88411d               mov byte ptr [ecx + 0x1d], al
// 0055c6ae  8a4118               mov al, byte ptr [ecx + 0x18]
// 0055c6b1  f6691d               imul byte ptr [ecx + 0x1d]
// 0055c6b4  88411e               mov byte ptr [ecx + 0x1e], al
// 0055c6b7  3c08                 cmp al, 8
// 0055c6b9  5e                   pop esi
// 0055c6ba  0fb6c0               movzx eax, al
// 0055c6bd  720a                 jb 0x55c6c9
// 0055c6bf  c1e803               shr eax, 3
// 0055c6c2  0faf01               imul eax, dword ptr [ecx]
// 0055c6c5  89410c               mov dword ptr [ecx + 0xc], eax
// 0055c6c8  c3                   ret 
// 0055c6c9  0faf01               imul eax, dword ptr [ecx]
// 0055c6cc  83c007               add eax, 7
// 0055c6cf  c1e803               shr eax, 3
// 0055c6d2  89410c               mov dword ptr [ecx + 0xc], eax
// 0055c6d5  c3                   ret 
// library libpng-1.2.29/pngrtran.c (function _png_read_transform_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngrtran.c
