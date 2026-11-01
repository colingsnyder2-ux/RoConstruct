// from server: 100% by auto
// roc 2007-03 00600760  unit: seg_00600000  size: 704 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600760
//
// 00600760  83ec08               sub esp, 8
// 00600763  53                   push ebx
// 00600764  55                   push ebp
// 00600765  56                   push esi
// 00600766  8bf0                 mov esi, eax
// 00600768  e8b3fbffff           call 0x600320
// 0060076d  8bd8                 mov ebx, eax
// 0060076f  8d4301               lea eax, [ebx + 1]
// 00600772  3dffffff3f           cmp eax, 0x3fffffff
// 00600777  7719                 ja 0x600792
// 00600779  8b16                 mov edx, dword ptr [esi]
// 0060077b  8d0c9d00000000       lea ecx, [ebx*4]
// 00600782  51                   push ecx
// 00600783  6a00                 push 0
// 00600785  6a00                 push 0
// 00600787  52                   push edx
// 00600788  e813ccffff           call 0x5fd3a0
// 0060078d  83c410               add esp, 0x10
// 00600790  eb0b                 jmp 0x60079d
// 00600792  8b06                 mov eax, dword ptr [esi]
// 00600794  50                   push eax
// 00600795  e8e6cbffff           call 0x5fd380
// 0060079a  83c404               add esp, 4
// 0060079d  8d0c9d00000000       lea ecx, [ebx*4]
// 006007a4  51                   push ecx
// 006007a5  894714               mov dword ptr [edi + 0x14], eax
// 006007a8  895f30               mov dword ptr [edi + 0x30], ebx
// 006007ab  8b5604               mov edx, dword ptr [esi + 4]
// 006007ae  50                   push eax
// 006007af  52                   push edx
// 006007b0  e8bbc5ffff           call 0x5fcd70
// 006007b5  83c40c               add esp, 0xc
// 006007b8  85c0                 test eax, eax
// 006007ba  7423                 je 0x6007df
// 006007bc  8b460c               mov eax, dword ptr [esi + 0xc]
// 006007bf  8b0e                 mov ecx, dword ptr [esi]
// 006007c1  6898067c00           push 0x7c0698
// 006007c6  50                   push eax
// 006007c7  687c067c00           push 0x7c067c
// 006007cc  51                   push ecx
// 006007cd  e86e80ffff           call 0x5f8840
// 006007d2  8b16                 mov edx, dword ptr [esi]
// 006007d4  6a03                 push 3
// 006007d6  52                   push edx
// 006007d7  e824fafbff           call 0x5c0200
// 006007dc  83c418               add esp, 0x18
// 006007df  e83cfbffff           call 0x600320
// 006007e4  8bd8                 mov ebx, eax
// 006007e6  8d4301               lea eax, [ebx + 1]
// 006007e9  3d55555515           cmp eax, 0x15555555
// 006007ee  7719                 ja 0x600809
// 006007f0  8b16                 mov edx, dword ptr [esi]
// 006007f2  8d0c5b               lea ecx, [ebx + ebx*2]
// 006007f5  03c9                 add ecx, ecx
// 006007f7  03c9                 add ecx, ecx
// 006007f9  51                   push ecx
// 006007fa  6a00                 push 0
// 006007fc  6a00                 push 0
// 006007fe  52                   push edx
// 006007ff  e89ccbffff           call 0x5fd3a0
// 00600804  83c410               add esp, 0x10
// 00600807  eb0b                 jmp 0x600814
// 00600809  8b06                 mov eax, dword ptr [esi]
// 0060080b  50                   push eax
// 0060080c  e86fcbffff           call 0x5fd380
// 00600811  83c404               add esp, 4
// 00600814  85db                 test ebx, ebx
// 00600816  894718               mov dword ptr [edi + 0x18], eax
// 00600819  895f38               mov dword ptr [edi + 0x38], ebx
// 0060081c  0f8e23010000         jle 0x600945
// 00600822  33c0                 xor eax, eax
// 00600824  8bcb                 mov ecx, ebx
// 00600826  eb08                 jmp 0x600830
// 00600828  8da42400000000       lea esp, [esp]
// 0060082f  90                   nop 
// 00600830  8b5718               mov edx, dword ptr [edi + 0x18]
// 00600833  c7041000000000       mov dword ptr [eax + edx], 0
// 0060083a  83c00c               add eax, 0xc
// 0060083d  83e901               sub ecx, 1
// 00600840  75ee                 jne 0x600830
// 00600842  85db                 test ebx, ebx
// 00600844  0f8efb000000         jle 0x600945
// 0060084a  33ed                 xor ebp, ebp
// 0060084c  8d642400             lea esp, [esp]
// 00600850  e83bfbffff           call 0x600390
// 00600855  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00600858  6a04                 push 4
// 0060085a  8d542410             lea edx, [esp + 0x10]
// 0060085e  890429               mov dword ptr [ecx + ebp], eax
// 00600861  8b4604               mov eax, dword ptr [esi + 4]
// 00600864  52                   push edx
// 00600865  50                   push eax
// 00600866  e805c5ffff           call 0x5fcd70
// 0060086b  83c40c               add esp, 0xc
// 0060086e  85c0                 test eax, eax
// 00600870  7423                 je 0x600895
// 00600872  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00600875  8b16                 mov edx, dword ptr [esi]
// 00600877  6898067c00           push 0x7c0698
// 0060087c  51                   push ecx
// 0060087d  687c067c00           push 0x7c067c
// 00600882  52                   push edx
// 00600883  e8b87fffff           call 0x5f8840
// 00600888  8b06                 mov eax, dword ptr [esi]
// 0060088a  6a03                 push 3
// 0060088c  50                   push eax
// 0060088d  e86ef9fbff           call 0x5c0200
// 00600892  83c418               add esp, 0x18
// 00600895  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0060089a  7d23                 jge 0x6008bf
// 0060089c  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0060089f  8b16                 mov edx, dword ptr [esi]
// 006008a1  68a8067c00           push 0x7c06a8
// 006008a6  51                   push ecx
// 006008a7  687c067c00           push 0x7c067c
// 006008ac  52                   push edx
// 006008ad  e88e7fffff           call 0x5f8840
// 006008b2  8b06                 mov eax, dword ptr [esi]
// 006008b4  6a03                 push 3
// 006008b6  50                   push eax
// 006008b7  e844f9fbff           call 0x5c0200
// 006008bc  83c418               add esp, 0x18
// 006008bf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006008c2  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006008c6  6a04                 push 4
// 006008c8  8d442414             lea eax, [esp + 0x14]
// 006008cc  89542904             mov dword ptr [ecx + ebp + 4], edx
// 006008d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006008d3  50                   push eax
// 006008d4  51                   push ecx
// 006008d5  e896c4ffff           call 0x5fcd70
// 006008da  83c40c               add esp, 0xc
// 006008dd  85c0                 test eax, eax
// 006008df  7423                 je 0x600904
// 006008e1  8b560c               mov edx, dword ptr [esi + 0xc]
// 006008e4  8b06                 mov eax, dword ptr [esi]
// 006008e6  6898067c00           push 0x7c0698
// 006008eb  52                   push edx
// 006008ec  687c067c00           push 0x7c067c
// 006008f1  50                   push eax
// 006008f2  e8497fffff           call 0x5f8840
// 006008f7  8b0e                 mov ecx, dword ptr [esi]
// 006008f9  6a03                 push 3
// 006008fb  51                   push ecx
// 006008fc  e8fff8fbff           call 0x5c0200
// 00600901  83c418               add esp, 0x18
// 00600904  837c241000           cmp dword ptr [esp + 0x10], 0
// 00600909  7d23                 jge 0x60092e
// 0060090b  8b560c               mov edx, dword ptr [esi + 0xc]
// 0060090e  8b06                 mov eax, dword ptr [esi]
// 00600910  68a8067c00           push 0x7c06a8
// 00600915  52                   push edx
// 00600916  687c067c00           push 0x7c067c
// 0060091b  50                   push eax
// 0060091c  e81f7fffff           call 0x5f8840
// 00600921  8b0e                 mov ecx, dword ptr [esi]
// 00600923  6a03                 push 3
// 00600925  51                   push ecx
// 00600926  e8d5f8fbff           call 0x5c0200
// 0060092b  83c418               add esp, 0x18
// 0060092e  8b5718               mov edx, dword ptr [edi + 0x18]
// 00600931  8b442410             mov eax, dword ptr [esp + 0x10]
// 00600935  89442a08             mov dword ptr [edx + ebp + 8], eax
// 00600939  83c50c               add ebp, 0xc
// 0060093c  83eb01               sub ebx, 1
// 0060093f  0f850bffffff         jne 0x600850
// 00600945  8b5604               mov edx, dword ptr [esi + 4]
// 00600948  6a04                 push 4
// 0060094a  8d4c2414             lea ecx, [esp + 0x14]
// 0060094e  51                   push ecx
// 0060094f  52                   push edx
// 00600950  e81bc4ffff           call 0x5fcd70
// 00600955  83c40c               add esp, 0xc
// 00600958  85c0                 test eax, eax
// 0060095a  7423                 je 0x60097f
// 0060095c  8b460c               mov eax, dword ptr [esi + 0xc]
// 0060095f  8b0e                 mov ecx, dword ptr [esi]
// 00600961  6898067c00           push 0x7c0698
// 00600966  50                   push eax
// 00600967  687c067c00           push 0x7c067c
// 0060096c  51                   push ecx
// 0060096d  e8ce7effff           call 0x5f8840
// 00600972  8b16                 mov edx, dword ptr [esi]
// 00600974  6a03                 push 3
// 00600976  52                   push edx
// 00600977  e884f8fbff           call 0x5c0200
// 0060097c  83c418               add esp, 0x18
// 0060097f  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00600983  85db                 test ebx, ebx
// 00600985  7d27                 jge 0x6009ae
// 00600987  8b460c               mov eax, dword ptr [esi + 0xc]
// 0060098a  8b0e                 mov ecx, dword ptr [esi]
// 0060098c  68a8067c00           push 0x7c06a8
// 00600991  50                   push eax
// 00600992  687c067c00           push 0x7c067c
// 00600997  51                   push ecx
// 00600998  e8a37effff           call 0x5f8840
// 0060099d  8b16                 mov edx, dword ptr [esi]
// 0060099f  6a03                 push 3
// 006009a1  52                   push edx
// 006009a2  e859f8fbff           call 0x5c0200
// 006009a7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 006009ab  83c418               add esp, 0x18
// 006009ae  8d4301               lea eax, [ebx + 1]
// 006009b1  3dffffff3f           cmp eax, 0x3fffffff
// 006009b6  7719                 ja 0x6009d1
// 006009b8  8b16                 mov edx, dword ptr [esi]
// 006009ba  8d0c9d00000000       lea ecx, [ebx*4]
// 006009c1  51                   push ecx
// 006009c2  6a00                 push 0
// 006009c4  6a00                 push 0
// 006009c6  52                   push edx
// 006009c7  e8d4c9ffff           call 0x5fd3a0
// 006009cc  83c410               add esp, 0x10
// 006009cf  eb0b                 jmp 0x6009dc
// 006009d1  8b06                 mov eax, dword ptr [esi]
// 006009d3  50                   push eax
// 006009d4  e8a7c9ffff           call 0x5fd380
// 006009d9  83c404               add esp, 4
// 006009dc  89471c               mov dword ptr [edi + 0x1c], eax
// 006009df  33c0                 xor eax, eax
// 006009e1  85db                 test ebx, ebx
// 006009e3  895f24               mov dword ptr [edi + 0x24], ebx
// 006009e6  7e19                 jle 0x600a01
// 006009e8  eb06                 jmp 0x6009f0
// 006009ea  8d9b00000000         lea ebx, [ebx]
// 006009f0  8b4f1c               mov ecx, dword ptr [edi + 0x1c]
// 006009f3  c7048100000000       mov dword ptr [ecx + eax*4], 0
// 006009fa  83c001               add eax, 1
// 006009fd  3bc3                 cmp eax, ebx
// 006009ff  7cef                 jl 0x6009f0
// 00600a01  33ed                 xor ebp, ebp
// 00600a03  85db                 test ebx, ebx
// 00600a05  7e12                 jle 0x600a19
// 00600a07  e884f9ffff           call 0x600390
// 00600a0c  8b571c               mov edx, dword ptr [edi + 0x1c]
// 00600a0f  8904aa               mov dword ptr [edx + ebp*4], eax
// 00600a12  83c501               add ebp, 1
// 00600a15  3beb                 cmp ebp, ebx
// 00600a17  7cee                 jl 0x600a07
// 00600a19  5e                   pop esi
// 00600a1a  5d                   pop ebp
// 00600a1b  5b                   pop ebx
// 00600a1c  83c408               add esp, 8
// 00600a1f  c3                   ret 
// library lua-5.1.1/lundump.c (function _LoadDebug)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lundump.c
