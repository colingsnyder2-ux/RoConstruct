// from server: 100% by auto
// roc 2007-03 0050e680  unit: seg_00500000  size: 412 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e680
//
// 0050e680  8b442404             mov eax, dword ptr [esp + 4]
// 0050e684  f7407000100000       test dword ptr [eax + 0x70], 0x1000
// 0050e68b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0050e68f  743f                 je 0x50e6d0
// 0050e691  8a5119               mov dl, byte ptr [ecx + 0x19]
// 0050e694  80fa03               cmp dl, 3
// 0050e697  7517                 jne 0x50e6b0
// 0050e699  6683b81a01000000     cmp word ptr [eax + 0x11a], 0
// 0050e6a1  0f95c2               setne dl
// 0050e6a4  8d149502000000       lea edx, [edx*4 + 2]
// 0050e6ab  885119               mov byte ptr [ecx + 0x19], dl
// 0050e6ae  eb16                 jmp 0x50e6c6
// 0050e6b0  6683b81a01000000     cmp word ptr [eax + 0x11a], 0
// 0050e6b8  7406                 je 0x50e6c0
// 0050e6ba  80ca04               or dl, 4
// 0050e6bd  885119               mov byte ptr [ecx + 0x19], dl
// 0050e6c0  80791808             cmp byte ptr [ecx + 0x18], 8
// 0050e6c4  7304                 jae 0x50e6ca
// 0050e6c6  c6411808             mov byte ptr [ecx + 0x18], 8
// 0050e6ca  66c741160000         mov word ptr [ecx + 0x16], 0
// 0050e6d0  f6407080             test byte ptr [eax + 0x70], 0x80
// 0050e6d4  7427                 je 0x50e6fd
// 0050e6d6  806119fb             and byte ptr [ecx + 0x19], 0xfb
// 0050e6da  66c741160000         mov word ptr [ecx + 0x16], 0
// 0050e6e0  8b9038010000         mov edx, dword ptr [eax + 0x138]
// 0050e6e6  89515a               mov dword ptr [ecx + 0x5a], edx
// 0050e6e9  8b903c010000         mov edx, dword ptr [eax + 0x13c]
// 0050e6ef  89515e               mov dword ptr [ecx + 0x5e], edx
// 0050e6f2  668b9040010000       mov dx, word ptr [eax + 0x140]
// 0050e6f9  66895162             mov word ptr [ecx + 0x62], dx
// 0050e6fd  f7407000200000       test dword ptr [eax + 0x70], 0x2000
// 0050e704  7415                 je 0x50e71b
// 0050e706  d9805c010000         fld dword ptr [eax + 0x15c]
// 0050e70c  d95928               fstp dword ptr [ecx + 0x28]
// 0050e70f  8b9034020000         mov edx, dword ptr [eax + 0x234]
// 0050e715  8991fc000000         mov dword ptr [ecx + 0xfc], edx
// 0050e71b  f7407000040000       test dword ptr [eax + 0x70], 0x400
// 0050e722  740a                 je 0x50e72e
// 0050e724  80791810             cmp byte ptr [ecx + 0x18], 0x10
// 0050e728  7504                 jne 0x50e72e
// 0050e72a  c6411808             mov byte ptr [ecx + 0x18], 8
// 0050e72e  f6407040             test byte ptr [eax + 0x70], 0x40
// 0050e732  7420                 je 0x50e754
// 0050e734  8a5119               mov dl, byte ptr [ecx + 0x19]
// 0050e737  80fa02               cmp dl, 2
// 0050e73a  7405                 je 0x50e741
// 0050e73c  80fa06               cmp dl, 6
// 0050e73f  7513                 jne 0x50e754
// 0050e741  83b8ec01000000       cmp dword ptr [eax + 0x1ec], 0
// 0050e748  740a                 je 0x50e754
// 0050e74a  80791808             cmp byte ptr [ecx + 0x18], 8
// 0050e74e  7504                 jne 0x50e754
// 0050e750  c6411903             mov byte ptr [ecx + 0x19], 3
// 0050e754  f6407004             test byte ptr [eax + 0x70], 4
// 0050e758  740a                 je 0x50e764
// 0050e75a  80791808             cmp byte ptr [ecx + 0x18], 8
// 0050e75e  7304                 jae 0x50e764
// 0050e760  c6411808             mov byte ptr [ecx + 0x18], 8
// 0050e764  f7407000400000       test dword ptr [eax + 0x70], 0x4000
// 0050e76b  7404                 je 0x50e771
// 0050e76d  80491902             or byte ptr [ecx + 0x19], 2
// 0050e771  f7407000006000       test dword ptr [eax + 0x70], 0x600000
// 0050e778  7404                 je 0x50e77e
// 0050e77a  806119fd             and byte ptr [ecx + 0x19], 0xfd
// 0050e77e  8a5119               mov dl, byte ptr [ecx + 0x19]
// 0050e781  80fa03               cmp dl, 3
// 0050e784  53                   push ebx
// 0050e785  b301                 mov bl, 1
// 0050e787  740b                 je 0x50e794
// 0050e789  f6c202               test dl, 2
// 0050e78c  7406                 je 0x50e794
// 0050e78e  c6411d03             mov byte ptr [ecx + 0x1d], 3
// 0050e792  eb03                 jmp 0x50e797
// 0050e794  88591d               mov byte ptr [ecx + 0x1d], bl
// 0050e797  f7407000000400       test dword ptr [eax + 0x70], 0x40000
// 0050e79e  7406                 je 0x50e7a6
// 0050e7a0  80e2fb               and dl, 0xfb
// 0050e7a3  885119               mov byte ptr [ecx + 0x19], dl
// 0050e7a6  8a5119               mov dl, byte ptr [ecx + 0x19]
// 0050e7a9  f6c204               test dl, 4
// 0050e7ac  7403                 je 0x50e7b1
// 0050e7ae  00591d               add byte ptr [ecx + 0x1d], bl
// 0050e7b1  f7407000800000       test dword ptr [eax + 0x70], 0x8000
// 0050e7b8  741b                 je 0x50e7d5
// 0050e7ba  80fa02               cmp dl, 2
// 0050e7bd  7404                 je 0x50e7c3
// 0050e7bf  84d2                 test dl, dl
// 0050e7c1  7512                 jne 0x50e7d5
// 0050e7c3  00591d               add byte ptr [ecx + 0x1d], bl
// 0050e7c6  f7407000000001       test dword ptr [eax + 0x70], 0x1000000
// 0050e7cd  7406                 je 0x50e7d5
// 0050e7cf  80ca04               or dl, 4
// 0050e7d2  885119               mov byte ptr [ecx + 0x19], dl
// 0050e7d5  f7407000001000       test dword ptr [eax + 0x70], 0x100000
// 0050e7dc  5b                   pop ebx
// 0050e7dd  7416                 je 0x50e7f5
// 0050e7df  8a5064               mov dl, byte ptr [eax + 0x64]
// 0050e7e2  385118               cmp byte ptr [ecx + 0x18], dl
// 0050e7e5  7303                 jae 0x50e7ea
// 0050e7e7  885118               mov byte ptr [ecx + 0x18], dl
// 0050e7ea  8a4065               mov al, byte ptr [eax + 0x65]
// 0050e7ed  38411d               cmp byte ptr [ecx + 0x1d], al
// 0050e7f0  7303                 jae 0x50e7f5
// 0050e7f2  88411d               mov byte ptr [ecx + 0x1d], al
// 0050e7f5  8a4118               mov al, byte ptr [ecx + 0x18]
// 0050e7f8  f6691d               imul byte ptr [ecx + 0x1d]
// 0050e7fb  88411e               mov byte ptr [ecx + 0x1e], al
// 0050e7fe  3c08                 cmp al, 8
// 0050e800  0fb6c0               movzx eax, al
// 0050e803  720a                 jb 0x50e80f
// 0050e805  c1e803               shr eax, 3
// 0050e808  0faf01               imul eax, dword ptr [ecx]
// 0050e80b  89410c               mov dword ptr [ecx + 0xc], eax
// 0050e80e  c3                   ret 
// 0050e80f  0faf01               imul eax, dword ptr [ecx]
// 0050e812  83c007               add eax, 7
// 0050e815  c1e803               shr eax, 3
// 0050e818  89410c               mov dword ptr [ecx + 0xc], eax
// 0050e81b  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_read_transform_info)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
