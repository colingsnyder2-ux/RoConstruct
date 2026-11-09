// from server: 100% by auto
// roc 2009-06 005842a0  unit: seg_00580000  size: 438 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005842a0
//
// 005842a0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005842a4  56                   push esi
// 005842a5  8b742408             mov esi, dword ptr [esp + 8]
// 005842a9  8b4670               mov eax, dword ptr [esi + 0x70]
// 005842ac  a900100000           test eax, 0x1000
// 005842b1  7460                 je 0x584313
// 005842b3  8a5119               mov dl, byte ptr [ecx + 0x19]
// 005842b6  80fa03               cmp dl, 3
// 005842b9  7531                 jne 0x5842ec
// 005842bb  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 005842c3  7417                 je 0x5842dc
// 005842c5  a900000002           test eax, 0x2000000
// 005842ca  7410                 je 0x5842dc
// 005842cc  33c0                 xor eax, eax
// 005842ce  c6411906             mov byte ptr [ecx + 0x19], 6
// 005842d2  c6411808             mov byte ptr [ecx + 0x18], 8
// 005842d6  66894116             mov word ptr [ecx + 0x16], ax
// 005842da  eb37                 jmp 0x584313
// 005842dc  33c0                 xor eax, eax
// 005842de  c6411902             mov byte ptr [ecx + 0x19], 2
// 005842e2  c6411808             mov byte ptr [ecx + 0x18], 8
// 005842e6  66894116             mov word ptr [ecx + 0x16], ax
// 005842ea  eb27                 jmp 0x584313
// 005842ec  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 005842f4  740d                 je 0x584303
// 005842f6  a900000002           test eax, 0x2000000
// 005842fb  7406                 je 0x584303
// 005842fd  80ca04               or dl, 4
// 00584300  885119               mov byte ptr [ecx + 0x19], dl
// 00584303  80791808             cmp byte ptr [ecx + 0x18], 8
// 00584307  7304                 jae 0x58430d
// 00584309  c6411808             mov byte ptr [ecx + 0x18], 8
// 0058430d  33d2                 xor edx, edx
// 0058430f  66895116             mov word ptr [ecx + 0x16], dx
// 00584313  f6467080             test byte ptr [esi + 0x70], 0x80
// 00584317  7427                 je 0x584340
// 00584319  806119fb             and byte ptr [ecx + 0x19], 0xfb
// 0058431d  33c0                 xor eax, eax
// 0058431f  66894116             mov word ptr [ecx + 0x16], ax
// 00584323  8b9638010000         mov edx, dword ptr [esi + 0x138]
// 00584329  89515a               mov dword ptr [ecx + 0x5a], edx
// 0058432c  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 00584332  89415e               mov dword ptr [ecx + 0x5e], eax
// 00584335  668b9640010000       mov dx, word ptr [esi + 0x140]
// 0058433c  66895162             mov word ptr [ecx + 0x62], dx
// 00584340  f7467000200000       test dword ptr [esi + 0x70], 0x2000
// 00584347  7415                 je 0x58435e
// 00584349  d9865c010000         fld dword ptr [esi + 0x15c]
// 0058434f  d95928               fstp dword ptr [ecx + 0x28]
// 00584352  8b8634020000         mov eax, dword ptr [esi + 0x234]
// 00584358  8981fc000000         mov dword ptr [ecx + 0xfc], eax
// 0058435e  f7467000040000       test dword ptr [esi + 0x70], 0x400
// 00584365  740a                 je 0x584371
// 00584367  80791810             cmp byte ptr [ecx + 0x18], 0x10
// 0058436b  7504                 jne 0x584371
// 0058436d  c6411808             mov byte ptr [ecx + 0x18], 8
// 00584371  f7467000400000       test dword ptr [esi + 0x70], 0x4000
// 00584378  7404                 je 0x58437e
// 0058437a  80491902             or byte ptr [ecx + 0x19], 2
// 0058437e  f7467000006000       test dword ptr [esi + 0x70], 0x600000
// 00584385  7404                 je 0x58438b
// 00584387  806119fd             and byte ptr [ecx + 0x19], 0xfd
// 0058438b  f6467040             test byte ptr [esi + 0x70], 0x40
// 0058438f  741e                 je 0x5843af
// 00584391  8a4119               mov al, byte ptr [ecx + 0x19]
// 00584394  3c02                 cmp al, 2
// 00584396  7404                 je 0x58439c
// 00584398  3c06                 cmp al, 6
// 0058439a  7513                 jne 0x5843af
// 0058439c  83beec01000000       cmp dword ptr [esi + 0x1ec], 0
// 005843a3  740a                 je 0x5843af
// 005843a5  80791808             cmp byte ptr [ecx + 0x18], 8
// 005843a9  7504                 jne 0x5843af
// 005843ab  c6411903             mov byte ptr [ecx + 0x19], 3
// 005843af  f6467004             test byte ptr [esi + 0x70], 4
// 005843b3  740a                 je 0x5843bf
// 005843b5  80791808             cmp byte ptr [ecx + 0x18], 8
// 005843b9  7304                 jae 0x5843bf
// 005843bb  c6411808             mov byte ptr [ecx + 0x18], 8
// 005843bf  8a4119               mov al, byte ptr [ecx + 0x19]
// 005843c2  b201                 mov dl, 1
// 005843c4  3c03                 cmp al, 3
// 005843c6  740a                 je 0x5843d2
// 005843c8  a802                 test al, 2
// 005843ca  7406                 je 0x5843d2
// 005843cc  c6411d03             mov byte ptr [ecx + 0x1d], 3
// 005843d0  eb03                 jmp 0x5843d5
// 005843d2  88511d               mov byte ptr [ecx + 0x1d], dl
// 005843d5  f7466c00004000       test dword ptr [esi + 0x6c], 0x400000
// 005843dc  7405                 je 0x5843e3
// 005843de  24fb                 and al, 0xfb
// 005843e0  884119               mov byte ptr [ecx + 0x19], al
// 005843e3  8a4119               mov al, byte ptr [ecx + 0x19]
// 005843e6  a804                 test al, 4
// 005843e8  7403                 je 0x5843ed
// 005843ea  00511d               add byte ptr [ecx + 0x1d], dl
// 005843ed  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 005843f4  7419                 je 0x58440f
// 005843f6  3c02                 cmp al, 2
// 005843f8  7404                 je 0x5843fe
// 005843fa  84c0                 test al, al
// 005843fc  7511                 jne 0x58440f
// 005843fe  00511d               add byte ptr [ecx + 0x1d], dl
// 00584401  f7467000000001       test dword ptr [esi + 0x70], 0x1000000
// 00584408  7405                 je 0x58440f
// 0058440a  0c04                 or al, 4
// 0058440c  884119               mov byte ptr [ecx + 0x19], al
// 0058440f  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 00584416  7416                 je 0x58442e
// 00584418  8a4664               mov al, byte ptr [esi + 0x64]
// 0058441b  384118               cmp byte ptr [ecx + 0x18], al
// 0058441e  7303                 jae 0x584423
// 00584420  884118               mov byte ptr [ecx + 0x18], al
// 00584423  8a4665               mov al, byte ptr [esi + 0x65]
// 00584426  38411d               cmp byte ptr [ecx + 0x1d], al
// 00584429  7303                 jae 0x58442e
// 0058442b  88411d               mov byte ptr [ecx + 0x1d], al
// 0058442e  8a4118               mov al, byte ptr [ecx + 0x18]
// 00584431  f6691d               imul byte ptr [ecx + 0x1d]
// 00584434  88411e               mov byte ptr [ecx + 0x1e], al
// 00584437  3c08                 cmp al, 8
// 00584439  5e                   pop esi
// 0058443a  0fb6c0               movzx eax, al
// 0058443d  720a                 jb 0x584449
// 0058443f  c1e803               shr eax, 3
// 00584442  0faf01               imul eax, dword ptr [ecx]
// 00584445  89410c               mov dword ptr [ecx + 0xc], eax
// 00584448  c3                   ret 
// 00584449  0faf01               imul eax, dword ptr [ecx]
// 0058444c  83c007               add eax, 7
// 0058444f  c1e803               shr eax, 3
// 00584452  89410c               mov dword ptr [ecx + 0xc], eax
// 00584455  c3                   ret 
// library libpng-1.2.29/pngrtran.c (function _png_read_transform_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngrtran.c
