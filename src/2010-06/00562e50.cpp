// from server: 100% by auto
// roc 2010-06 00562e50  unit: G3D::_internal::DialogTemplate  size: 588 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00562e50
//
// 00562e50  56                   push esi
// 00562e51  8b742408             mov esi, dword ptr [esp + 8]
// 00562e55  85f6                 test esi, esi
// 00562e57  0f841f020000         je 0x56307c
// 00562e5d  83bee400000000       cmp dword ptr [esi + 0xe4], 0
// 00562e64  7529                 jne 0x562e8f
// 00562e66  80be2401000000       cmp byte ptr [esi + 0x124], 0
// 00562e6d  7520                 jne 0x562e8f
// 00562e6f  f7466800040000       test dword ptr [esi + 0x68], 0x400
// 00562e76  750e                 jne 0x562e86
// 00562e78  68dc0ea200           push 0xa20edc
// 00562e7d  56                   push esi
// 00562e7e  e82dec0000           call 0x571ab0
// 00562e83  83c408               add esp, 8
// 00562e86  56                   push esi
// 00562e87  e8c4c00000           call 0x56ef50
// 00562e8c  83c404               add esp, 4
// 00562e8f  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00562e96  0f84d4000000         je 0x562f70
// 00562e9c  f6467002             test byte ptr [esi + 0x70], 2
// 00562ea0  0f84ca000000         je 0x562f70
// 00562ea6  0fb68624010000       movzx eax, byte ptr [esi + 0x124]
// 00562ead  83f806               cmp eax, 6
// 00562eb0  0f87ba000000         ja 0x562f70
// 00562eb6  ff248580305600       jmp dword ptr [eax*4 + 0x563080]
// 00562ebd  f686e400000007       test byte ptr [esi + 0xe4], 7
// 00562ec4  0f84a6000000         je 0x562f70
// 00562eca  56                   push esi
// 00562ecb  e870da0000           call 0x570940
// 00562ed0  83c404               add esp, 4
// 00562ed3  5e                   pop esi
// 00562ed4  c3                   ret 
// 00562ed5  f686e400000007       test byte ptr [esi + 0xe4], 7
// 00562edc  750d                 jne 0x562eeb
// 00562ede  83bec800000005       cmp dword ptr [esi + 0xc8], 5
// 00562ee5  0f8385000000         jae 0x562f70
// 00562eeb  56                   push esi
// 00562eec  e84fda0000           call 0x570940
// 00562ef1  83c404               add esp, 4
// 00562ef4  5e                   pop esi
// 00562ef5  c3                   ret 
// 00562ef6  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 00562efc  2407                 and al, 7
// 00562efe  3c04                 cmp al, 4
// 00562f00  746e                 je 0x562f70
// 00562f02  56                   push esi
// 00562f03  e838da0000           call 0x570940
// 00562f08  83c404               add esp, 4
// 00562f0b  5e                   pop esi
// 00562f0c  c3                   ret 
// 00562f0d  b803000000           mov eax, 3
// 00562f12  8486e4000000         test byte ptr [esi + 0xe4], al
// 00562f18  7508                 jne 0x562f22
// 00562f1a  3986c8000000         cmp dword ptr [esi + 0xc8], eax
// 00562f20  734e                 jae 0x562f70
// 00562f22  56                   push esi
// 00562f23  e818da0000           call 0x570940
// 00562f28  83c404               add esp, 4
// 00562f2b  5e                   pop esi
// 00562f2c  c3                   ret 
// 00562f2d  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 00562f33  80e103               and cl, 3
// 00562f36  80f902               cmp cl, 2
// 00562f39  7435                 je 0x562f70
// 00562f3b  56                   push esi
// 00562f3c  e8ffd90000           call 0x570940
// 00562f41  83c404               add esp, 4
// 00562f44  5e                   pop esi
// 00562f45  c3                   ret 
// 00562f46  f686e400000001       test byte ptr [esi + 0xe4], 1
// 00562f4d  7509                 jne 0x562f58
// 00562f4f  83bec800000002       cmp dword ptr [esi + 0xc8], 2
// 00562f56  7318                 jae 0x562f70
// 00562f58  56                   push esi
// 00562f59  e8e2d90000           call 0x570940
// 00562f5e  83c404               add esp, 4
// 00562f61  5e                   pop esi
// 00562f62  c3                   ret 
// 00562f63  f686e400000001       test byte ptr [esi + 0xe4], 1
// 00562f6a  0f845affffff         je 0x562eca
// 00562f70  0fb69626010000       movzx edx, byte ptr [esi + 0x126]
// 00562f77  8a8628010000         mov al, byte ptr [esi + 0x128]
// 00562f7d  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00562f83  889608010000         mov byte ptr [esi + 0x108], dl
// 00562f89  8a962b010000         mov dl, byte ptr [esi + 0x12b]
// 00562f8f  888609010000         mov byte ptr [esi + 0x109], al
// 00562f95  f6ea                 imul dl
// 00562f97  57                   push edi
// 00562f98  8dbe00010000         lea edi, [esi + 0x100]
// 00562f9e  88860b010000         mov byte ptr [esi + 0x10b], al
// 00562fa4  3c08                 cmp al, 8
// 00562fa6  890f                 mov dword ptr [edi], ecx
// 00562fa8  88960a010000         mov byte ptr [esi + 0x10a], dl
// 00562fae  0fb6c0               movzx eax, al
// 00562fb1  7208                 jb 0x562fbb
// 00562fb3  c1e803               shr eax, 3
// 00562fb6  0fafc1               imul eax, ecx
// 00562fb9  eb09                 jmp 0x562fc4
// 00562fbb  0fafc1               imul eax, ecx
// 00562fbe  83c007               add eax, 7
// 00562fc1  c1e803               shr eax, 3
// 00562fc4  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00562fca  50                   push eax
// 00562fcb  898604010000         mov dword ptr [esi + 0x104], eax
// 00562fd1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00562fd5  50                   push eax
// 00562fd6  41                   inc ecx
// 00562fd7  51                   push ecx
// 00562fd8  56                   push esi
// 00562fd9  e832f50000           call 0x572510
// 00562fde  83c410               add esp, 0x10
// 00562fe1  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00562fe8  7436                 je 0x563020
// 00562fea  8a8624010000         mov al, byte ptr [esi + 0x124]
// 00562ff0  3c06                 cmp al, 6
// 00562ff2  732c                 jae 0x563020
// 00562ff4  f6467002             test byte ptr [esi + 0x70], 2
// 00562ff8  7426                 je 0x563020
// 00562ffa  0fb6d0               movzx edx, al
// 00562ffd  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00563003  52                   push edx
// 00563004  40                   inc eax
// 00563005  50                   push eax
// 00563006  57                   push edi
// 00563007  e8d4c00000           call 0x56f0e0
// 0056300c  83c40c               add esp, 0xc
// 0056300f  833f00               cmp dword ptr [edi], 0
// 00563012  750c                 jne 0x563020
// 00563014  56                   push esi
// 00563015  e826d90000           call 0x570940
// 0056301a  83c404               add esp, 4
// 0056301d  5f                   pop edi
// 0056301e  5e                   pop esi
// 0056301f  c3                   ret 
// 00563020  837e7000             cmp dword ptr [esi + 0x70], 0
// 00563024  7409                 je 0x56302f
// 00563026  56                   push esi
// 00563027  e8b4f20000           call 0x5722e0
// 0056302c  83c404               add esp, 4
// 0056302f  f6863002000004       test byte ptr [esi + 0x230], 4
// 00563036  741a                 je 0x563052
// 00563038  80be3802000040       cmp byte ptr [esi + 0x238], 0x40
// 0056303f  7511                 jne 0x563052
// 00563041  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00563047  41                   inc ecx
// 00563048  51                   push ecx
// 00563049  57                   push edi
// 0056304a  e8b1f10000           call 0x572200
// 0056304f  83c408               add esp, 8
// 00563052  57                   push edi
// 00563053  56                   push esi
// 00563054  e837dc0000           call 0x570c90
// 00563059  8b869c010000         mov eax, dword ptr [esi + 0x19c]
// 0056305f  83c408               add esp, 8
// 00563062  85c0                 test eax, eax
// 00563064  7415                 je 0x56307b
// 00563066  0fb69624010000       movzx edx, byte ptr [esi + 0x124]
// 0056306d  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 00563073  52                   push edx
// 00563074  51                   push ecx
// 00563075  56                   push esi
// 00563076  ffd0                 call eax
// 00563078  83c40c               add esp, 0xc
// 0056307b  5f                   pop edi
// 0056307c  5e                   pop esi
// 0056307d  c3                   ret 
// 0056307e  8bff                 mov edi, edi
// 00563080  bd2e5600d5           mov ebp, 0xd500562e
// 00563085  2e56                 push esi
// 00563087  00f6                 add dh, dh
// 00563089  2e56                 push esi
// 0056308b  000d2f56002d         add byte ptr [0x2d00562f], cl
// 00563091  2f                   das 
// 00563092  56                   push esi
// 00563093  00462f               add byte ptr [esi + 0x2f], al
// 00563096  56                   push esi
// 00563097  00632f               add byte ptr [ebx + 0x2f], ah
// 0056309a  56                   push esi
// library libpng-1.2.10/pngwrite.c (function _png_write_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
