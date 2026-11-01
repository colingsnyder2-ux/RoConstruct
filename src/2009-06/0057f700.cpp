// from server: 100% by auto
// roc 2009-06 0057f700  unit: G3D::_internal::DialogTemplate  size: 588 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0057f700
//
// 0057f700  56                   push esi
// 0057f701  8b742408             mov esi, dword ptr [esp + 8]
// 0057f705  85f6                 test esi, esi
// 0057f707  0f841f020000         je 0x57f92c
// 0057f70d  83bee400000000       cmp dword ptr [esi + 0xe4], 0
// 0057f714  7529                 jne 0x57f73f
// 0057f716  80be2401000000       cmp byte ptr [esi + 0x124], 0
// 0057f71d  7520                 jne 0x57f73f
// 0057f71f  f7466800040000       test dword ptr [esi + 0x68], 0x400
// 0057f726  750e                 jne 0x57f736
// 0057f728  68dcc28c00           push 0x8cc2dc
// 0057f72d  56                   push esi
// 0057f72e  e82dea0000           call 0x58e160
// 0057f733  83c408               add esp, 8
// 0057f736  56                   push esi
// 0057f737  e8a4be0000           call 0x58b5e0
// 0057f73c  83c404               add esp, 4
// 0057f73f  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0057f746  0f84d4000000         je 0x57f820
// 0057f74c  f6467002             test byte ptr [esi + 0x70], 2
// 0057f750  0f84ca000000         je 0x57f820
// 0057f756  0fb68624010000       movzx eax, byte ptr [esi + 0x124]
// 0057f75d  83f806               cmp eax, 6
// 0057f760  0f87ba000000         ja 0x57f820
// 0057f766  ff248530f95700       jmp dword ptr [eax*4 + 0x57f930]
// 0057f76d  f686e400000007       test byte ptr [esi + 0xe4], 7
// 0057f774  0f84a6000000         je 0x57f820
// 0057f77a  56                   push esi
// 0057f77b  e870d80000           call 0x58cff0
// 0057f780  83c404               add esp, 4
// 0057f783  5e                   pop esi
// 0057f784  c3                   ret 
// 0057f785  f686e400000007       test byte ptr [esi + 0xe4], 7
// 0057f78c  750d                 jne 0x57f79b
// 0057f78e  83bec800000005       cmp dword ptr [esi + 0xc8], 5
// 0057f795  0f8385000000         jae 0x57f820
// 0057f79b  56                   push esi
// 0057f79c  e84fd80000           call 0x58cff0
// 0057f7a1  83c404               add esp, 4
// 0057f7a4  5e                   pop esi
// 0057f7a5  c3                   ret 
// 0057f7a6  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 0057f7ac  2407                 and al, 7
// 0057f7ae  3c04                 cmp al, 4
// 0057f7b0  746e                 je 0x57f820
// 0057f7b2  56                   push esi
// 0057f7b3  e838d80000           call 0x58cff0
// 0057f7b8  83c404               add esp, 4
// 0057f7bb  5e                   pop esi
// 0057f7bc  c3                   ret 
// 0057f7bd  b803000000           mov eax, 3
// 0057f7c2  8486e4000000         test byte ptr [esi + 0xe4], al
// 0057f7c8  7508                 jne 0x57f7d2
// 0057f7ca  3986c8000000         cmp dword ptr [esi + 0xc8], eax
// 0057f7d0  734e                 jae 0x57f820
// 0057f7d2  56                   push esi
// 0057f7d3  e818d80000           call 0x58cff0
// 0057f7d8  83c404               add esp, 4
// 0057f7db  5e                   pop esi
// 0057f7dc  c3                   ret 
// 0057f7dd  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 0057f7e3  80e103               and cl, 3
// 0057f7e6  80f902               cmp cl, 2
// 0057f7e9  7435                 je 0x57f820
// 0057f7eb  56                   push esi
// 0057f7ec  e8ffd70000           call 0x58cff0
// 0057f7f1  83c404               add esp, 4
// 0057f7f4  5e                   pop esi
// 0057f7f5  c3                   ret 
// 0057f7f6  f686e400000001       test byte ptr [esi + 0xe4], 1
// 0057f7fd  7509                 jne 0x57f808
// 0057f7ff  83bec800000002       cmp dword ptr [esi + 0xc8], 2
// 0057f806  7318                 jae 0x57f820
// 0057f808  56                   push esi
// 0057f809  e8e2d70000           call 0x58cff0
// 0057f80e  83c404               add esp, 4
// 0057f811  5e                   pop esi
// 0057f812  c3                   ret 
// 0057f813  f686e400000001       test byte ptr [esi + 0xe4], 1
// 0057f81a  0f845affffff         je 0x57f77a
// 0057f820  0fb69626010000       movzx edx, byte ptr [esi + 0x126]
// 0057f827  8a8628010000         mov al, byte ptr [esi + 0x128]
// 0057f82d  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 0057f833  889608010000         mov byte ptr [esi + 0x108], dl
// 0057f839  8a962b010000         mov dl, byte ptr [esi + 0x12b]
// 0057f83f  888609010000         mov byte ptr [esi + 0x109], al
// 0057f845  f6ea                 imul dl
// 0057f847  57                   push edi
// 0057f848  8dbe00010000         lea edi, [esi + 0x100]
// 0057f84e  88860b010000         mov byte ptr [esi + 0x10b], al
// 0057f854  3c08                 cmp al, 8
// 0057f856  890f                 mov dword ptr [edi], ecx
// 0057f858  88960a010000         mov byte ptr [esi + 0x10a], dl
// 0057f85e  0fb6c0               movzx eax, al
// 0057f861  7208                 jb 0x57f86b
// 0057f863  c1e803               shr eax, 3
// 0057f866  0fafc1               imul eax, ecx
// 0057f869  eb09                 jmp 0x57f874
// 0057f86b  0fafc1               imul eax, ecx
// 0057f86e  83c007               add eax, 7
// 0057f871  c1e803               shr eax, 3
// 0057f874  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0057f87a  50                   push eax
// 0057f87b  898604010000         mov dword ptr [esi + 0x104], eax
// 0057f881  8b442414             mov eax, dword ptr [esp + 0x14]
// 0057f885  50                   push eax
// 0057f886  41                   inc ecx
// 0057f887  51                   push ecx
// 0057f888  56                   push esi
// 0057f889  e832f30000           call 0x58ebc0
// 0057f88e  83c410               add esp, 0x10
// 0057f891  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0057f898  7436                 je 0x57f8d0
// 0057f89a  8a8624010000         mov al, byte ptr [esi + 0x124]
// 0057f8a0  3c06                 cmp al, 6
// 0057f8a2  732c                 jae 0x57f8d0
// 0057f8a4  f6467002             test byte ptr [esi + 0x70], 2
// 0057f8a8  7426                 je 0x57f8d0
// 0057f8aa  0fb6d0               movzx edx, al
// 0057f8ad  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 0057f8b3  52                   push edx
// 0057f8b4  40                   inc eax
// 0057f8b5  50                   push eax
// 0057f8b6  57                   push edi
// 0057f8b7  e8b4be0000           call 0x58b770
// 0057f8bc  83c40c               add esp, 0xc
// 0057f8bf  833f00               cmp dword ptr [edi], 0
// 0057f8c2  750c                 jne 0x57f8d0
// 0057f8c4  56                   push esi
// 0057f8c5  e826d70000           call 0x58cff0
// 0057f8ca  83c404               add esp, 4
// 0057f8cd  5f                   pop edi
// 0057f8ce  5e                   pop esi
// 0057f8cf  c3                   ret 
// 0057f8d0  837e7000             cmp dword ptr [esi + 0x70], 0
// 0057f8d4  7409                 je 0x57f8df
// 0057f8d6  56                   push esi
// 0057f8d7  e8b4f00000           call 0x58e990
// 0057f8dc  83c404               add esp, 4
// 0057f8df  f6863002000004       test byte ptr [esi + 0x230], 4
// 0057f8e6  741a                 je 0x57f902
// 0057f8e8  80be3802000040       cmp byte ptr [esi + 0x238], 0x40
// 0057f8ef  7511                 jne 0x57f902
// 0057f8f1  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0057f8f7  41                   inc ecx
// 0057f8f8  51                   push ecx
// 0057f8f9  57                   push edi
// 0057f8fa  e8b1ef0000           call 0x58e8b0
// 0057f8ff  83c408               add esp, 8
// 0057f902  57                   push edi
// 0057f903  56                   push esi
// 0057f904  e837da0000           call 0x58d340
// 0057f909  8b869c010000         mov eax, dword ptr [esi + 0x19c]
// 0057f90f  83c408               add esp, 8
// 0057f912  85c0                 test eax, eax
// 0057f914  7415                 je 0x57f92b
// 0057f916  0fb69624010000       movzx edx, byte ptr [esi + 0x124]
// 0057f91d  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 0057f923  52                   push edx
// 0057f924  51                   push ecx
// 0057f925  56                   push esi
// 0057f926  ffd0                 call eax
// 0057f928  83c40c               add esp, 0xc
// 0057f92b  5f                   pop edi
// 0057f92c  5e                   pop esi
// 0057f92d  c3                   ret 
// 0057f92e  8bff                 mov edi, edi
// 0057f930  6d                   insd dword ptr es:[edi], dx
// 0057f931  f75700               not dword ptr [edi]
// 0057f934  85f7                 test edi, esi
// 0057f936  57                   push edi
// 0057f937  00a6f75700bd         add byte ptr [esi - 0x42ffa809], ah
// 0057f93d  f75700               not dword ptr [edi]
// library libpng-1.2.10/pngwrite.c (function _png_write_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
