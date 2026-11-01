// from server: 100% by auto
// roc 2007-08 00721220  unit: CXTCaptionButtonTheme  size: 367 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00721220
//
// 00721220  83ec20               sub esp, 0x20
// 00721223  53                   push ebx
// 00721224  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00721228  8b03                 mov eax, dword ptr [ebx]
// 0072122a  8b5308               mov edx, dword ptr [ebx + 8]
// 0072122d  55                   push ebp
// 0072122e  56                   push esi
// 0072122f  57                   push edi
// 00721230  8be9                 mov ebp, ecx
// 00721232  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00721235  6a00                 push 0
// 00721237  894c2428             mov dword ptr [esp + 0x28], ecx
// 0072123b  89442424             mov dword ptr [esp + 0x24], eax
// 0072123f  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00721242  6afe                 push -2
// 00721244  8d4c2428             lea ecx, [esp + 0x28]
// 00721248  51                   push ecx
// 00721249  89542434             mov dword ptr [esp + 0x34], edx
// 0072124d  89442438             mov dword ptr [esp + 0x38], eax
// 00721251  ff1590ed7700         call dword ptr [0x77ed90]
// 00721257  8b742434             mov esi, dword ptr [esp + 0x34]
// 0072125b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0072125f  8b442424             mov eax, dword ptr [esp + 0x24]
// 00721263  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 00721267  8916                 mov dword ptr [esi], edx
// 00721269  894604               mov dword ptr [esi + 4], eax
// 0072126c  837f7800             cmp dword ptr [edi + 0x78], 0
// 00721270  7422                 je 0x721294
// 00721272  8d4c2410             lea ecx, [esp + 0x10]
// 00721276  51                   push ecx
// 00721277  8bcf                 mov ecx, edi
// 00721279  e81241ffff           call 0x715390
// 0072127e  8b10                 mov edx, dword ptr [eax]
// 00721280  8916                 mov dword ptr [esi], edx
// 00721282  8b4004               mov eax, dword ptr [eax + 4]
// 00721285  5f                   pop edi
// 00721286  894604               mov dword ptr [esi + 4], eax
// 00721289  8bc6                 mov eax, esi
// 0072128b  5e                   pop esi
// 0072128c  5d                   pop ebp
// 0072128d  5b                   pop ebx
// 0072128e  83c420               add esp, 0x20
// 00721291  c21400               ret 0x14
// 00721294  8b442440             mov eax, dword ptr [esp + 0x40]
// 00721298  8b4804               mov ecx, dword ptr [eax + 4]
// 0072129b  8b00                 mov eax, dword ptr [eax]
// 0072129d  8b5500               mov edx, dword ptr [ebp]
// 007212a0  8b5240               mov edx, dword ptr [edx + 0x40]
// 007212a3  57                   push edi
// 007212a4  51                   push ecx
// 007212a5  50                   push eax
// 007212a6  56                   push esi
// 007212a7  8bcd                 mov ecx, ebp
// 007212a9  ffd2                 call edx
// 007212ab  8b476c               mov eax, dword ptr [edi + 0x6c]
// 007212ae  8906                 mov dword ptr [esi], eax
// 007212b0  8b17                 mov edx, dword ptr [edi]
// 007212b2  8b8260010000         mov eax, dword ptr [edx + 0x160]
// 007212b8  8bcf                 mov ecx, edi
// 007212ba  ffd0                 call eax
// 007212bc  a804                 test al, 4
// 007212be  7425                 je 0x7212e5
// 007212c0  8b6f70               mov ebp, dword ptr [edi + 0x70]
// 007212c3  8d4c2410             lea ecx, [esp + 0x10]
// 007212c7  51                   push ecx
// 007212c8  8bcf                 mov ecx, edi
// 007212ca  e84140ffff           call 0x715310
// 007212cf  8b4004               mov eax, dword ptr [eax + 4]
// 007212d2  99                   cdq 
// 007212d3  2bc2                 sub eax, edx
// 007212d5  8bc8                 mov ecx, eax
// 007212d7  8bc5                 mov eax, ebp
// 007212d9  99                   cdq 
// 007212da  2bc2                 sub eax, edx
// 007212dc  d1f9                 sar ecx, 1
// 007212de  d1f8                 sar eax, 1
// 007212e0  03c8                 add ecx, eax
// 007212e2  014e04               add dword ptr [esi + 4], ecx
// 007212e5  8bcf                 mov ecx, edi
// 007212e7  e826710100           call 0x738412
// 007212ec  2500030000           and eax, 0x300
// 007212f1  3d00010000           cmp eax, 0x100
// 007212f6  7466                 je 0x72135e
// 007212f8  3d00020000           cmp eax, 0x200
// 007212fd  7445                 je 0x721344
// 007212ff  8b17                 mov edx, dword ptr [edi]
// 00721301  8b8260010000         mov eax, dword ptr [edx + 0x160]
// 00721307  8bcf                 mov ecx, edi
// 00721309  ffd0                 call eax
// 0072130b  a804                 test al, 4
// 0072130d  7510                 jne 0x72131f
// 0072130f  8d4c2410             lea ecx, [esp + 0x10]
// 00721313  51                   push ecx
// 00721314  8bcf                 mov ecx, edi
// 00721316  e8f53fffff           call 0x715310
// 0072131b  8b10                 mov edx, dword ptr [eax]
// 0072131d  0116                 add dword ptr [esi], edx
// 0072131f  8b4308               mov eax, dword ptr [ebx + 8]
// 00721322  2b476c               sub eax, dword ptr [edi + 0x6c]
// 00721325  8b542440             mov edx, dword ptr [esp + 0x40]
// 00721329  2b02                 sub eax, dword ptr [edx]
// 0072132b  8b0e                 mov ecx, dword ptr [esi]
// 0072132d  2bc1                 sub eax, ecx
// 0072132f  99                   cdq 
// 00721330  2bc2                 sub eax, edx
// 00721332  d1f8                 sar eax, 1
// 00721334  03c1                 add eax, ecx
// 00721336  5f                   pop edi
// 00721337  8906                 mov dword ptr [esi], eax
// 00721339  8bc6                 mov eax, esi
// 0072133b  5e                   pop esi
// 0072133c  5d                   pop ebp
// 0072133d  5b                   pop ebx
// 0072133e  83c420               add esp, 0x20
// 00721341  c21400               ret 0x14
// 00721344  8b4308               mov eax, dword ptr [ebx + 8]
// 00721347  2b476c               sub eax, dword ptr [edi + 0x6c]
// 0072134a  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0072134e  2b01                 sub eax, dword ptr [ecx]
// 00721350  5f                   pop edi
// 00721351  8906                 mov dword ptr [esi], eax
// 00721353  8bc6                 mov eax, esi
// 00721355  5e                   pop esi
// 00721356  5d                   pop ebp
// 00721357  5b                   pop ebx
// 00721358  83c420               add esp, 0x20
// 0072135b  c21400               ret 0x14
// 0072135e  8b17                 mov edx, dword ptr [edi]
// 00721360  8b8260010000         mov eax, dword ptr [edx + 0x160]
// 00721366  8bcf                 mov ecx, edi
// 00721368  ffd0                 call eax
// 0072136a  a804                 test al, 4
// 0072136c  7515                 jne 0x721383
// 0072136e  8b5f70               mov ebx, dword ptr [edi + 0x70]
// 00721371  8d4c2418             lea ecx, [esp + 0x18]
// 00721375  51                   push ecx
// 00721376  8bcf                 mov ecx, edi
// 00721378  e8933fffff           call 0x715310
// 0072137d  8b10                 mov edx, dword ptr [eax]
// 0072137f  03d3                 add edx, ebx
// 00721381  0116                 add dword ptr [esi], edx
// 00721383  5f                   pop edi
// 00721384  8bc6                 mov eax, esi
// 00721386  5e                   pop esi
// 00721387  5d                   pop ebp
// 00721388  5b                   pop ebx
// 00721389  83c420               add esp, 0x20
// 0072138c  c21400               ret 0x14
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?GetTextPosition@CXTButtonTheme@@MAE?AVCPoint@@IAAVCRect@@AAVCSize@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
