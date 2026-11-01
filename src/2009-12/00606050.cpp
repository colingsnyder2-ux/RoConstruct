// from server: 100% by auto
// roc 2009-12 00606050  unit: seg_00600000  size: 438 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00606050
//
// 00606050  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00606054  56                   push esi
// 00606055  8b742408             mov esi, dword ptr [esp + 8]
// 00606059  8b4670               mov eax, dword ptr [esi + 0x70]
// 0060605c  a900100000           test eax, 0x1000
// 00606061  7460                 je 0x6060c3
// 00606063  8a5119               mov dl, byte ptr [ecx + 0x19]
// 00606066  80fa03               cmp dl, 3
// 00606069  7531                 jne 0x60609c
// 0060606b  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 00606073  7417                 je 0x60608c
// 00606075  a900000002           test eax, 0x2000000
// 0060607a  7410                 je 0x60608c
// 0060607c  33c0                 xor eax, eax
// 0060607e  c6411906             mov byte ptr [ecx + 0x19], 6
// 00606082  c6411808             mov byte ptr [ecx + 0x18], 8
// 00606086  66894116             mov word ptr [ecx + 0x16], ax
// 0060608a  eb37                 jmp 0x6060c3
// 0060608c  33c0                 xor eax, eax
// 0060608e  c6411902             mov byte ptr [ecx + 0x19], 2
// 00606092  c6411808             mov byte ptr [ecx + 0x18], 8
// 00606096  66894116             mov word ptr [ecx + 0x16], ax
// 0060609a  eb27                 jmp 0x6060c3
// 0060609c  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 006060a4  740d                 je 0x6060b3
// 006060a6  a900000002           test eax, 0x2000000
// 006060ab  7406                 je 0x6060b3
// 006060ad  80ca04               or dl, 4
// 006060b0  885119               mov byte ptr [ecx + 0x19], dl
// 006060b3  80791808             cmp byte ptr [ecx + 0x18], 8
// 006060b7  7304                 jae 0x6060bd
// 006060b9  c6411808             mov byte ptr [ecx + 0x18], 8
// 006060bd  33d2                 xor edx, edx
// 006060bf  66895116             mov word ptr [ecx + 0x16], dx
// 006060c3  f6467080             test byte ptr [esi + 0x70], 0x80
// 006060c7  7427                 je 0x6060f0
// 006060c9  806119fb             and byte ptr [ecx + 0x19], 0xfb
// 006060cd  33c0                 xor eax, eax
// 006060cf  66894116             mov word ptr [ecx + 0x16], ax
// 006060d3  8b9638010000         mov edx, dword ptr [esi + 0x138]
// 006060d9  89515a               mov dword ptr [ecx + 0x5a], edx
// 006060dc  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 006060e2  89415e               mov dword ptr [ecx + 0x5e], eax
// 006060e5  668b9640010000       mov dx, word ptr [esi + 0x140]
// 006060ec  66895162             mov word ptr [ecx + 0x62], dx
// 006060f0  f7467000200000       test dword ptr [esi + 0x70], 0x2000
// 006060f7  7415                 je 0x60610e
// 006060f9  d9865c010000         fld dword ptr [esi + 0x15c]
// 006060ff  d95928               fstp dword ptr [ecx + 0x28]
// 00606102  8b8634020000         mov eax, dword ptr [esi + 0x234]
// 00606108  8981fc000000         mov dword ptr [ecx + 0xfc], eax
// 0060610e  f7467000040000       test dword ptr [esi + 0x70], 0x400
// 00606115  740a                 je 0x606121
// 00606117  80791810             cmp byte ptr [ecx + 0x18], 0x10
// 0060611b  7504                 jne 0x606121
// 0060611d  c6411808             mov byte ptr [ecx + 0x18], 8
// 00606121  f7467000400000       test dword ptr [esi + 0x70], 0x4000
// 00606128  7404                 je 0x60612e
// 0060612a  80491902             or byte ptr [ecx + 0x19], 2
// 0060612e  f7467000006000       test dword ptr [esi + 0x70], 0x600000
// 00606135  7404                 je 0x60613b
// 00606137  806119fd             and byte ptr [ecx + 0x19], 0xfd
// 0060613b  f6467040             test byte ptr [esi + 0x70], 0x40
// 0060613f  741e                 je 0x60615f
// 00606141  8a4119               mov al, byte ptr [ecx + 0x19]
// 00606144  3c02                 cmp al, 2
// 00606146  7404                 je 0x60614c
// 00606148  3c06                 cmp al, 6
// 0060614a  7513                 jne 0x60615f
// 0060614c  83beec01000000       cmp dword ptr [esi + 0x1ec], 0
// 00606153  740a                 je 0x60615f
// 00606155  80791808             cmp byte ptr [ecx + 0x18], 8
// 00606159  7504                 jne 0x60615f
// 0060615b  c6411903             mov byte ptr [ecx + 0x19], 3
// 0060615f  f6467004             test byte ptr [esi + 0x70], 4
// 00606163  740a                 je 0x60616f
// 00606165  80791808             cmp byte ptr [ecx + 0x18], 8
// 00606169  7304                 jae 0x60616f
// 0060616b  c6411808             mov byte ptr [ecx + 0x18], 8
// 0060616f  8a4119               mov al, byte ptr [ecx + 0x19]
// 00606172  b201                 mov dl, 1
// 00606174  3c03                 cmp al, 3
// 00606176  740a                 je 0x606182
// 00606178  a802                 test al, 2
// 0060617a  7406                 je 0x606182
// 0060617c  c6411d03             mov byte ptr [ecx + 0x1d], 3
// 00606180  eb03                 jmp 0x606185
// 00606182  88511d               mov byte ptr [ecx + 0x1d], dl
// 00606185  f7466c00004000       test dword ptr [esi + 0x6c], 0x400000
// 0060618c  7405                 je 0x606193
// 0060618e  24fb                 and al, 0xfb
// 00606190  884119               mov byte ptr [ecx + 0x19], al
// 00606193  8a4119               mov al, byte ptr [ecx + 0x19]
// 00606196  a804                 test al, 4
// 00606198  7403                 je 0x60619d
// 0060619a  00511d               add byte ptr [ecx + 0x1d], dl
// 0060619d  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 006061a4  7419                 je 0x6061bf
// 006061a6  3c02                 cmp al, 2
// 006061a8  7404                 je 0x6061ae
// 006061aa  84c0                 test al, al
// 006061ac  7511                 jne 0x6061bf
// 006061ae  00511d               add byte ptr [ecx + 0x1d], dl
// 006061b1  f7467000000001       test dword ptr [esi + 0x70], 0x1000000
// 006061b8  7405                 je 0x6061bf
// 006061ba  0c04                 or al, 4
// 006061bc  884119               mov byte ptr [ecx + 0x19], al
// 006061bf  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 006061c6  7416                 je 0x6061de
// 006061c8  8a4664               mov al, byte ptr [esi + 0x64]
// 006061cb  384118               cmp byte ptr [ecx + 0x18], al
// 006061ce  7303                 jae 0x6061d3
// 006061d0  884118               mov byte ptr [ecx + 0x18], al
// 006061d3  8a4665               mov al, byte ptr [esi + 0x65]
// 006061d6  38411d               cmp byte ptr [ecx + 0x1d], al
// 006061d9  7303                 jae 0x6061de
// 006061db  88411d               mov byte ptr [ecx + 0x1d], al
// 006061de  8a4118               mov al, byte ptr [ecx + 0x18]
// 006061e1  f6691d               imul byte ptr [ecx + 0x1d]
// 006061e4  88411e               mov byte ptr [ecx + 0x1e], al
// 006061e7  3c08                 cmp al, 8
// 006061e9  5e                   pop esi
// 006061ea  0fb6c0               movzx eax, al
// 006061ed  720a                 jb 0x6061f9
// 006061ef  c1e803               shr eax, 3
// 006061f2  0faf01               imul eax, dword ptr [ecx]
// 006061f5  89410c               mov dword ptr [ecx + 0xc], eax
// 006061f8  c3                   ret 
// 006061f9  0faf01               imul eax, dword ptr [ecx]
// 006061fc  83c007               add eax, 7
// 006061ff  c1e803               shr eax, 3
// 00606202  89410c               mov dword ptr [ecx + 0xc], eax
// 00606205  c3                   ret 
// library libpng-1.2.29/pngrtran.c (function _png_read_transform_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngrtran.c
