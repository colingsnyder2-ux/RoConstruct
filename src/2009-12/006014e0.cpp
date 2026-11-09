// roc 2009-12 006014e0  unit: G3D::_internal::DialogTemplate  size: 588 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006014e0
//
// 006014e0  56                   push esi
// 006014e1  8b742408             mov esi, dword ptr [esp + 8]
// 006014e5  85f6                 test esi, esi
// 006014e7  0f841f020000         je 0x60170c
// 006014ed  83bee400000000       cmp dword ptr [esi + 0xe4], 0
// 006014f4  7529                 jne 0x60151f
// 006014f6  80be2401000000       cmp byte ptr [esi + 0x124], 0
// 006014fd  7520                 jne 0x60151f
// 006014ff  f7466800040000       test dword ptr [esi + 0x68], 0x400
// 00601506  750e                 jne 0x601516
// 00601508  6884319c00           push 0x9c3184
// 0060150d  56                   push esi
// 0060150e  e87dec0000           call 0x610190
// 00601513  83c408               add esp, 8
// 00601516  56                   push esi
// 00601517  e814c10000           call 0x60d630
// 0060151c  83c404               add esp, 4
// 0060151f  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00601526  0f84d4000000         je 0x601600
// 0060152c  f6467002             test byte ptr [esi + 0x70], 2
// 00601530  0f84ca000000         je 0x601600
// 00601536  0fb68624010000       movzx eax, byte ptr [esi + 0x124]
// 0060153d  83f806               cmp eax, 6
// 00601540  0f87ba000000         ja 0x601600
// 00601546  ff248510176000       jmp dword ptr [eax*4 + 0x601710]
// 0060154d  f686e400000007       test byte ptr [esi + 0xe4], 7
// 00601554  0f84a6000000         je 0x601600
// 0060155a  56                   push esi
// 0060155b  e8c0da0000           call 0x60f020
// 00601560  83c404               add esp, 4
// 00601563  5e                   pop esi
// 00601564  c3                   ret 
// 00601565  f686e400000007       test byte ptr [esi + 0xe4], 7
// 0060156c  750d                 jne 0x60157b
// 0060156e  83bec800000005       cmp dword ptr [esi + 0xc8], 5
// 00601575  0f8385000000         jae 0x601600
// 0060157b  56                   push esi
// 0060157c  e89fda0000           call 0x60f020
// 00601581  83c404               add esp, 4
// 00601584  5e                   pop esi
// 00601585  c3                   ret 
// 00601586  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 0060158c  2407                 and al, 7
// 0060158e  3c04                 cmp al, 4
// 00601590  746e                 je 0x601600
// 00601592  56                   push esi
// 00601593  e888da0000           call 0x60f020
// 00601598  83c404               add esp, 4
// 0060159b  5e                   pop esi
// 0060159c  c3                   ret 
// 0060159d  b803000000           mov eax, 3
// 006015a2  8486e4000000         test byte ptr [esi + 0xe4], al
// 006015a8  7508                 jne 0x6015b2
// 006015aa  3986c8000000         cmp dword ptr [esi + 0xc8], eax
// 006015b0  734e                 jae 0x601600
// 006015b2  56                   push esi
// 006015b3  e868da0000           call 0x60f020
// 006015b8  83c404               add esp, 4
// 006015bb  5e                   pop esi
// 006015bc  c3                   ret 
// 006015bd  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 006015c3  80e103               and cl, 3
// 006015c6  80f902               cmp cl, 2
// 006015c9  7435                 je 0x601600
// 006015cb  56                   push esi
// 006015cc  e84fda0000           call 0x60f020
// 006015d1  83c404               add esp, 4
// 006015d4  5e                   pop esi
// 006015d5  c3                   ret 
// 006015d6  f686e400000001       test byte ptr [esi + 0xe4], 1
// 006015dd  7509                 jne 0x6015e8
// 006015df  83bec800000002       cmp dword ptr [esi + 0xc8], 2
// 006015e6  7318                 jae 0x601600
// 006015e8  56                   push esi
// 006015e9  e832da0000           call 0x60f020
// 006015ee  83c404               add esp, 4
// 006015f1  5e                   pop esi
// 006015f2  c3                   ret 
// 006015f3  f686e400000001       test byte ptr [esi + 0xe4], 1
// 006015fa  0f845affffff         je 0x60155a
// 00601600  0fb69626010000       movzx edx, byte ptr [esi + 0x126]
// 00601607  8a8628010000         mov al, byte ptr [esi + 0x128]
// 0060160d  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00601613  889608010000         mov byte ptr [esi + 0x108], dl
// 00601619  8a962b010000         mov dl, byte ptr [esi + 0x12b]
// 0060161f  888609010000         mov byte ptr [esi + 0x109], al
// 00601625  f6ea                 imul dl
// 00601627  57                   push edi
// 00601628  8dbe00010000         lea edi, [esi + 0x100]
// 0060162e  88860b010000         mov byte ptr [esi + 0x10b], al
// 00601634  3c08                 cmp al, 8
// 00601636  890f                 mov dword ptr [edi], ecx
// 00601638  88960a010000         mov byte ptr [esi + 0x10a], dl
// 0060163e  0fb6c0               movzx eax, al
// 00601641  7208                 jb 0x60164b
// 00601643  c1e803               shr eax, 3
// 00601646  0fafc1               imul eax, ecx
// 00601649  eb09                 jmp 0x601654
// 0060164b  0fafc1               imul eax, ecx
// 0060164e  83c007               add eax, 7
// 00601651  c1e803               shr eax, 3
// 00601654  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0060165a  50                   push eax
// 0060165b  898604010000         mov dword ptr [esi + 0x104], eax
// 00601661  8b442414             mov eax, dword ptr [esp + 0x14]
// 00601665  50                   push eax
// 00601666  41                   inc ecx
// 00601667  51                   push ecx
// 00601668  56                   push esi
// 00601669  e882f50000           call 0x610bf0
// 0060166e  83c410               add esp, 0x10
// 00601671  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00601678  7436                 je 0x6016b0
// 0060167a  8a8624010000         mov al, byte ptr [esi + 0x124]
// 00601680  3c06                 cmp al, 6
// 00601682  732c                 jae 0x6016b0
// 00601684  f6467002             test byte ptr [esi + 0x70], 2
// 00601688  7426                 je 0x6016b0
// 0060168a  0fb6d0               movzx edx, al
// 0060168d  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00601693  52                   push edx
// 00601694  40                   inc eax
// 00601695  50                   push eax
// 00601696  57                   push edi
// 00601697  e824c10000           call 0x60d7c0
// 0060169c  83c40c               add esp, 0xc
// 0060169f  833f00               cmp dword ptr [edi], 0
// 006016a2  750c                 jne 0x6016b0
// 006016a4  56                   push esi
// 006016a5  e876d90000           call 0x60f020
// 006016aa  83c404               add esp, 4
// 006016ad  5f                   pop edi
// 006016ae  5e                   pop esi
// 006016af  c3                   ret 
// 006016b0  837e7000             cmp dword ptr [esi + 0x70], 0
// 006016b4  7409                 je 0x6016bf
// 006016b6  56                   push esi
// 006016b7  e804f30000           call 0x6109c0
// 006016bc  83c404               add esp, 4
// 006016bf  f6863002000004       test byte ptr [esi + 0x230], 4
// 006016c6  741a                 je 0x6016e2
// 006016c8  80be3802000040       cmp byte ptr [esi + 0x238], 0x40
// 006016cf  7511                 jne 0x6016e2
// 006016d1  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 006016d7  41                   inc ecx
// 006016d8  51                   push ecx
// 006016d9  57                   push edi
// 006016da  e801f20000           call 0x6108e0
// 006016df  83c408               add esp, 8
// 006016e2  57                   push edi
// 006016e3  56                   push esi
// 006016e4  e887dc0000           call 0x60f370
// 006016e9  8b869c010000         mov eax, dword ptr [esi + 0x19c]
// 006016ef  83c408               add esp, 8
// 006016f2  85c0                 test eax, eax
// 006016f4  7415                 je 0x60170b
// 006016f6  0fb69624010000       movzx edx, byte ptr [esi + 0x124]
// 006016fd  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 00601703  52                   push edx
// 00601704  51                   push ecx
// 00601705  56                   push esi
// 00601706  ffd0                 call eax
// 00601708  83c40c               add esp, 0xc
// 0060170b  5f                   pop edi
// 0060170c  5e                   pop esi
// 0060170d  c3                   ret 
// 0060170e  8bff                 mov edi, edi
// 00601710  4d                   dec ebp
// 00601711  1560006515           adc eax, 0x15650060
// 00601716  60                   pushal 
// 00601717  00861560009d         add byte ptr [esi - 0x62ff9feb], al
// 0060171d  156000bd15           adc eax, 0x15bd0060
// 00601722  60                   pushal 
// 00601723  00d6                 add dh, dl
// 00601725  156000f315           adc eax, 0x15f30060
// 0060172a  60                   pushal 
// library libpng-1.2.10/pngwrite.c (function _png_write_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
