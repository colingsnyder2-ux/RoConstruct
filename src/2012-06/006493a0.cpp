// from server: 100% by auto
// roc 2012-06 006493a0  unit: seg_00640000  size: 438 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006493a0
//
// 006493a0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006493a4  56                   push esi
// 006493a5  8b742408             mov esi, dword ptr [esp + 8]
// 006493a9  8b4670               mov eax, dword ptr [esi + 0x70]
// 006493ac  a900100000           test eax, 0x1000
// 006493b1  7460                 je 0x649413
// 006493b3  8a5119               mov dl, byte ptr [ecx + 0x19]
// 006493b6  80fa03               cmp dl, 3
// 006493b9  7531                 jne 0x6493ec
// 006493bb  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 006493c3  7417                 je 0x6493dc
// 006493c5  a900000002           test eax, 0x2000000
// 006493ca  7410                 je 0x6493dc
// 006493cc  33c0                 xor eax, eax
// 006493ce  c6411906             mov byte ptr [ecx + 0x19], 6
// 006493d2  c6411808             mov byte ptr [ecx + 0x18], 8
// 006493d6  66894116             mov word ptr [ecx + 0x16], ax
// 006493da  eb37                 jmp 0x649413
// 006493dc  33c0                 xor eax, eax
// 006493de  c6411902             mov byte ptr [ecx + 0x19], 2
// 006493e2  c6411808             mov byte ptr [ecx + 0x18], 8
// 006493e6  66894116             mov word ptr [ecx + 0x16], ax
// 006493ea  eb27                 jmp 0x649413
// 006493ec  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 006493f4  740d                 je 0x649403
// 006493f6  a900000002           test eax, 0x2000000
// 006493fb  7406                 je 0x649403
// 006493fd  80ca04               or dl, 4
// 00649400  885119               mov byte ptr [ecx + 0x19], dl
// 00649403  80791808             cmp byte ptr [ecx + 0x18], 8
// 00649407  7304                 jae 0x64940d
// 00649409  c6411808             mov byte ptr [ecx + 0x18], 8
// 0064940d  33d2                 xor edx, edx
// 0064940f  66895116             mov word ptr [ecx + 0x16], dx
// 00649413  f6467080             test byte ptr [esi + 0x70], 0x80
// 00649417  7427                 je 0x649440
// 00649419  806119fb             and byte ptr [ecx + 0x19], 0xfb
// 0064941d  33c0                 xor eax, eax
// 0064941f  66894116             mov word ptr [ecx + 0x16], ax
// 00649423  8b9638010000         mov edx, dword ptr [esi + 0x138]
// 00649429  89515a               mov dword ptr [ecx + 0x5a], edx
// 0064942c  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 00649432  89415e               mov dword ptr [ecx + 0x5e], eax
// 00649435  668b9640010000       mov dx, word ptr [esi + 0x140]
// 0064943c  66895162             mov word ptr [ecx + 0x62], dx
// 00649440  f7467000200000       test dword ptr [esi + 0x70], 0x2000
// 00649447  7415                 je 0x64945e
// 00649449  d9865c010000         fld dword ptr [esi + 0x15c]
// 0064944f  d95928               fstp dword ptr [ecx + 0x28]
// 00649452  8b8634020000         mov eax, dword ptr [esi + 0x234]
// 00649458  8981fc000000         mov dword ptr [ecx + 0xfc], eax
// 0064945e  f7467000040000       test dword ptr [esi + 0x70], 0x400
// 00649465  740a                 je 0x649471
// 00649467  80791810             cmp byte ptr [ecx + 0x18], 0x10
// 0064946b  7504                 jne 0x649471
// 0064946d  c6411808             mov byte ptr [ecx + 0x18], 8
// 00649471  f7467000400000       test dword ptr [esi + 0x70], 0x4000
// 00649478  7404                 je 0x64947e
// 0064947a  80491902             or byte ptr [ecx + 0x19], 2
// 0064947e  f7467000006000       test dword ptr [esi + 0x70], 0x600000
// 00649485  7404                 je 0x64948b
// 00649487  806119fd             and byte ptr [ecx + 0x19], 0xfd
// 0064948b  f6467040             test byte ptr [esi + 0x70], 0x40
// 0064948f  741e                 je 0x6494af
// 00649491  8a4119               mov al, byte ptr [ecx + 0x19]
// 00649494  3c02                 cmp al, 2
// 00649496  7404                 je 0x64949c
// 00649498  3c06                 cmp al, 6
// 0064949a  7513                 jne 0x6494af
// 0064949c  83beec01000000       cmp dword ptr [esi + 0x1ec], 0
// 006494a3  740a                 je 0x6494af
// 006494a5  80791808             cmp byte ptr [ecx + 0x18], 8
// 006494a9  7504                 jne 0x6494af
// 006494ab  c6411903             mov byte ptr [ecx + 0x19], 3
// 006494af  f6467004             test byte ptr [esi + 0x70], 4
// 006494b3  740a                 je 0x6494bf
// 006494b5  80791808             cmp byte ptr [ecx + 0x18], 8
// 006494b9  7304                 jae 0x6494bf
// 006494bb  c6411808             mov byte ptr [ecx + 0x18], 8
// 006494bf  8a4119               mov al, byte ptr [ecx + 0x19]
// 006494c2  b201                 mov dl, 1
// 006494c4  3c03                 cmp al, 3
// 006494c6  740a                 je 0x6494d2
// 006494c8  a802                 test al, 2
// 006494ca  7406                 je 0x6494d2
// 006494cc  c6411d03             mov byte ptr [ecx + 0x1d], 3
// 006494d0  eb03                 jmp 0x6494d5
// 006494d2  88511d               mov byte ptr [ecx + 0x1d], dl
// 006494d5  f7466c00004000       test dword ptr [esi + 0x6c], 0x400000
// 006494dc  7405                 je 0x6494e3
// 006494de  24fb                 and al, 0xfb
// 006494e0  884119               mov byte ptr [ecx + 0x19], al
// 006494e3  8a4119               mov al, byte ptr [ecx + 0x19]
// 006494e6  a804                 test al, 4
// 006494e8  7403                 je 0x6494ed
// 006494ea  00511d               add byte ptr [ecx + 0x1d], dl
// 006494ed  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 006494f4  7419                 je 0x64950f
// 006494f6  3c02                 cmp al, 2
// 006494f8  7404                 je 0x6494fe
// 006494fa  84c0                 test al, al
// 006494fc  7511                 jne 0x64950f
// 006494fe  00511d               add byte ptr [ecx + 0x1d], dl
// 00649501  f7467000000001       test dword ptr [esi + 0x70], 0x1000000
// 00649508  7405                 je 0x64950f
// 0064950a  0c04                 or al, 4
// 0064950c  884119               mov byte ptr [ecx + 0x19], al
// 0064950f  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 00649516  7416                 je 0x64952e
// 00649518  8a4664               mov al, byte ptr [esi + 0x64]
// 0064951b  384118               cmp byte ptr [ecx + 0x18], al
// 0064951e  7303                 jae 0x649523
// 00649520  884118               mov byte ptr [ecx + 0x18], al
// 00649523  8a4665               mov al, byte ptr [esi + 0x65]
// 00649526  38411d               cmp byte ptr [ecx + 0x1d], al
// 00649529  7303                 jae 0x64952e
// 0064952b  88411d               mov byte ptr [ecx + 0x1d], al
// 0064952e  8a4118               mov al, byte ptr [ecx + 0x18]
// 00649531  f6691d               imul byte ptr [ecx + 0x1d]
// 00649534  88411e               mov byte ptr [ecx + 0x1e], al
// 00649537  3c08                 cmp al, 8
// 00649539  5e                   pop esi
// 0064953a  0fb6c0               movzx eax, al
// 0064953d  720a                 jb 0x649549
// 0064953f  c1e803               shr eax, 3
// 00649542  0faf01               imul eax, dword ptr [ecx]
// 00649545  89410c               mov dword ptr [ecx + 0xc], eax
// 00649548  c3                   ret 
// 00649549  0faf01               imul eax, dword ptr [ecx]
// 0064954c  83c007               add eax, 7
// 0064954f  c1e803               shr eax, 3
// 00649552  89410c               mov dword ptr [ecx + 0xc], eax
// 00649555  c3                   ret 
// library libpng-1.2.29/pngrtran.c (function _png_read_transform_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngrtran.c
