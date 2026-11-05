// from server: 100% by auto
// roc 2012-06 00647570  unit: seg_00640000  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00647570
//
// 00647570  51                   push ecx
// 00647571  53                   push ebx
// 00647572  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00647576  85db                 test ebx, ebx
// 00647578  0f843f010000         je 0x6476bd
// 0064757e  55                   push ebp
// 0064757f  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00647583  85ed                 test ebp, ebp
// 00647585  0f8431010000         je 0x6476bc
// 0064758b  57                   push edi
// 0064758c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00647590  85ff                 test edi, edi
// 00647592  0f8423010000         je 0x6476bb
// 00647598  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 0064759e  03c7                 add eax, edi
// 006475a0  8d0480               lea eax, [eax + eax*4]
// 006475a3  03c0                 add eax, eax
// 006475a5  56                   push esi
// 006475a6  03c0                 add eax, eax
// 006475a8  50                   push eax
// 006475a9  53                   push ebx
// 006475aa  e8a16f0000           call 0x64e550
// 006475af  8bf0                 mov esi, eax
// 006475b1  83c408               add esp, 8
// 006475b4  89742410             mov dword ptr [esp + 0x10], esi
// 006475b8  85f6                 test esi, esi
// 006475ba  7514                 jne 0x6475d0
// 006475bc  681064b800           push 0xb86410
// 006475c1  53                   push ebx
// 006475c2  e8996c0000           call 0x64e260
// 006475c7  83c408               add esp, 8
// 006475ca  5e                   pop esi
// 006475cb  5f                   pop edi
// 006475cc  5d                   pop ebp
// 006475cd  5b                   pop ebx
// 006475ce  59                   pop ecx
// 006475cf  c3                   ret 
// 006475d0  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 006475d6  8b95bc000000         mov edx, dword ptr [ebp + 0xbc]
// 006475dc  8d0c80               lea ecx, [eax + eax*4]
// 006475df  03c9                 add ecx, ecx
// 006475e1  03c9                 add ecx, ecx
// 006475e3  51                   push ecx
// 006475e4  52                   push edx
// 006475e5  56                   push esi
// 006475e6  e871c03300           call 0x98365c
// 006475eb  8b85bc000000         mov eax, dword ptr [ebp + 0xbc]
// 006475f1  50                   push eax
// 006475f2  53                   push ebx
// 006475f3  e8286f0000           call 0x64e520
// 006475f8  33c9                 xor ecx, ecx
// 006475fa  83c414               add esp, 0x14
// 006475fd  3bf9                 cmp edi, ecx
// 006475ff  898dbc000000         mov dword ptr [ebp + 0xbc], ecx
// 00647605  894c2418             mov dword ptr [esp + 0x18], ecx
// 00647609  0f8e95000000         jle 0x6476a4
// 0064760f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00647613  83c70c               add edi, 0xc
// 00647616  eb08                 jmp 0x647620
// 00647618  8da42400000000       lea esp, [esp]
// 0064761f  90                   nop 
// 00647620  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 00647626  8b57f4               mov edx, dword ptr [edi - 0xc]
// 00647629  03c1                 add eax, ecx
// 0064762b  8d0c80               lea ecx, [eax + eax*4]
// 0064762e  8d348e               lea esi, [esi + ecx*4]
// 00647631  8916                 mov dword ptr [esi], edx
// 00647633  c6460400             mov byte ptr [esi + 4], 0
// 00647637  8b0f                 mov ecx, dword ptr [edi]
// 00647639  894e0c               mov dword ptr [esi + 0xc], ecx
// 0064763c  8a5368               mov dl, byte ptr [ebx + 0x68]
// 0064763f  885610               mov byte ptr [esi + 0x10], dl
// 00647642  833f00               cmp dword ptr [edi], 0
// 00647645  7509                 jne 0x647650
// 00647647  c7460800000000       mov dword ptr [esi + 8], 0
// 0064764e  eb3a                 jmp 0x64768a
// 00647650  8b07                 mov eax, dword ptr [edi]
// 00647652  50                   push eax
// 00647653  53                   push ebx
// 00647654  e8f76e0000           call 0x64e550
// 00647659  83c408               add esp, 8
// 0064765c  894608               mov dword ptr [esi + 8], eax
// 0064765f  85c0                 test eax, eax
// 00647661  7517                 jne 0x64767a
// 00647663  681064b800           push 0xb86410
// 00647668  53                   push ebx
// 00647669  e8f26b0000           call 0x64e260
// 0064766e  83c408               add esp, 8
// 00647671  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00647678  eb10                 jmp 0x64768a
// 0064767a  8b0f                 mov ecx, dword ptr [edi]
// 0064767c  8b57fc               mov edx, dword ptr [edi - 4]
// 0064767f  51                   push ecx
// 00647680  52                   push edx
// 00647681  50                   push eax
// 00647682  e8d5bf3300           call 0x98365c
// 00647687  83c40c               add esp, 0xc
// 0064768a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0064768e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00647692  41                   inc ecx
// 00647693  83c714               add edi, 0x14
// 00647696  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 0064769a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0064769e  7c80                 jl 0x647620
// 006476a0  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006476a4  01bdc0000000         add dword ptr [ebp + 0xc0], edi
// 006476aa  818db800000000020000 or dword ptr [ebp + 0xb8], 0x200
// 006476b4  89b5bc000000         mov dword ptr [ebp + 0xbc], esi
// 006476ba  5e                   pop esi
// 006476bb  5f                   pop edi
// 006476bc  5d                   pop ebp
// 006476bd  5b                   pop ebx
// 006476be  59                   pop ecx
// 006476bf  c3                   ret 
// library libpng-1.2.29/pngset.c (function _png_set_unknown_chunks)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngset.c
