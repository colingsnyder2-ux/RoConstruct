// from server: 100% by auto
// roc 2007-08 004a42f0  unit: RBX::IdManager::UItem::?$TItem  size: 242 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a42f0
//
// 004a42f0  56                   push esi
// 004a42f1  8b742408             mov esi, dword ptr [esp + 8]
// 004a42f5  85f6                 test esi, esi
// 004a42f7  0f84e1000000         je 0x4a43de
// 004a42fd  803e00               cmp byte ptr [esi], 0
// 004a4300  0f84d8000000         je 0x4a43de
// 004a4306  8bc6                 mov eax, esi
// 004a4308  8d5001               lea edx, [eax + 1]
// 004a430b  eb03                 jmp 0x4a4310
// 004a430d  8d4900               lea ecx, [ecx]
// 004a4310  8a08                 mov cl, byte ptr [eax]
// 004a4312  83c001               add eax, 1
// 004a4315  84c9                 test cl, cl
// 004a4317  75f7                 jne 0x4a4310
// 004a4319  2bc2                 sub eax, edx
// 004a431b  83c001               add eax, 1
// 004a431e  57                   push edi
// 004a431f  50                   push eax
// 004a4320  e8d1bb1800           call 0x62fef6
// 004a4325  8bf8                 mov edi, eax
// 004a4327  8bd7                 mov edx, edi
// 004a4329  83c404               add esp, 4
// 004a432c  8bc6                 mov eax, esi
// 004a432e  2bd6                 sub edx, esi
// 004a4330  8a08                 mov cl, byte ptr [eax]
// 004a4332  880c02               mov byte ptr [edx + eax], cl
// 004a4335  83c001               add eax, 1
// 004a4338  84c9                 test cl, cl
// 004a433a  75f4                 jne 0x4a4330
// 004a433c  380f                 cmp byte ptr [edi], cl
// 004a433e  7424                 je 0x4a4364
// 004a4340  8bf7                 mov esi, edi
// 004a4342  8a06                 mov al, byte ptr [esi]
// 004a4344  3c2f                 cmp al, 0x2f
// 004a4346  7404                 je 0x4a434c
// 004a4348  3c5c                 cmp al, 0x5c
// 004a434a  7510                 jne 0x4a435c
// 004a434c  57                   push edi
// 004a434d  c60600               mov byte ptr [esi], 0
// 004a4350  ff15a0e87700         call dword ptr [0x77e8a0]
// 004a4356  83c404               add esp, 4
// 004a4359  c6062f               mov byte ptr [esi], 0x2f
// 004a435c  83c601               add esi, 1
// 004a435f  803e00               cmp byte ptr [esi], 0
// 004a4362  75de                 jne 0x4a4342
// 004a4364  53                   push ebx
// 004a4365  55                   push ebp
// 004a4366  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004a436a  85ed                 test ebp, ebp
// 004a436c  7456                 je 0x4a43c4
// 004a436e  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004a4372  85db                 test ebx, ebx
// 004a4374  744e                 je 0x4a43c4
// 004a4376  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a437a  68b0cc7900           push 0x79ccb0
// 004a437f  50                   push eax
// 004a4380  ff1510e97700         call dword ptr [0x77e910]
// 004a4386  8bf0                 mov esi, eax
// 004a4388  83c408               add esp, 8
// 004a438b  85f6                 test esi, esi
// 004a438d  7510                 jne 0x4a439f
// 004a438f  57                   push edi
// 004a4390  e8cdb81800           call 0x62fc62
// 004a4395  83c404               add esp, 4
// 004a4398  5d                   pop ebp
// 004a4399  5b                   pop ebx
// 004a439a  5f                   pop edi
// 004a439b  32c0                 xor al, al
// 004a439d  5e                   pop esi
// 004a439e  c3                   ret 
// 004a439f  56                   push esi
// 004a43a0  53                   push ebx
// 004a43a1  6a01                 push 1
// 004a43a3  55                   push ebp
// 004a43a4  ff1514e97700         call dword ptr [0x77e914]
// 004a43aa  56                   push esi
// 004a43ab  ff1518e97700         call dword ptr [0x77e918]
// 004a43b1  83c414               add esp, 0x14
// 004a43b4  57                   push edi
// 004a43b5  e8a8b81800           call 0x62fc62
// 004a43ba  83c404               add esp, 4
// 004a43bd  5d                   pop ebp
// 004a43be  5b                   pop ebx
// 004a43bf  5f                   pop edi
// 004a43c0  b001                 mov al, 1
// 004a43c2  5e                   pop esi
// 004a43c3  c3                   ret 
// 004a43c4  57                   push edi
// 004a43c5  ff15a0e87700         call dword ptr [0x77e8a0]
// 004a43cb  83c404               add esp, 4
// 004a43ce  57                   push edi
// 004a43cf  e88eb81800           call 0x62fc62
// 004a43d4  83c404               add esp, 4
// 004a43d7  5d                   pop ebp
// 004a43d8  5b                   pop ebx
// 004a43d9  5f                   pop edi
// 004a43da  b001                 mov al, 1
// 004a43dc  5e                   pop esi
// 004a43dd  c3                   ret 
// 004a43de  32c0                 xor al, al
// 004a43e0  5e                   pop esi
// 004a43e1  c3                   ret 
// library openrbx-raknet/FileOperations.cpp (function ?WriteFileWithDirectories@@YA_NPBDPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet FileOperations.cpp
