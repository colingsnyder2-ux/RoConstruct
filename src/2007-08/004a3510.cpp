// from server: 100% by auto
// roc 2007-08 004a3510  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a3510
//
// 004a3510  56                   push esi
// 004a3511  8bf1                 mov esi, ecx
// 004a3513  8b06                 mov eax, dword ptr [esi]
// 004a3515  50                   push eax
// 004a3516  ff152cef7700         call dword ptr [0x77ef2c]
// 004a351c  ba10e78b00           mov edx, 0x8be710
// 004a3521  8a08                 mov cl, byte ptr [eax]
// 004a3523  880a                 mov byte ptr [edx], cl
// 004a3525  83c001               add eax, 1
// 004a3528  83c201               add edx, 1
// 004a352b  84c9                 test cl, cl
// 004a352d  75f2                 jne 0x4a3521
// 004a352f  384c2408             cmp byte ptr [esp + 8], cl
// 004a3533  744d                 je 0x4a3582
// 004a3535  57                   push edi
// 004a3536  bf10e78b00           mov edi, 0x8be710
// 004a353b  83c7ff               add edi, -1
// 004a353e  8bff                 mov edi, edi
// 004a3540  8a4701               mov al, byte ptr [edi + 1]
// 004a3543  83c701               add edi, 1
// 004a3546  84c0                 test al, al
// 004a3548  75f6                 jne 0x4a3540
// 004a354a  66a1a0ab7900         mov ax, word ptr [0x79aba0]
// 004a3550  668907               mov word ptr [edi], ax
// 004a3553  b810e78b00           mov eax, 0x8be710
// 004a3558  8d5001               lea edx, [eax + 1]
// 004a355b  5f                   pop edi
// 004a355c  8d642400             lea esp, [esp]
// 004a3560  8a08                 mov cl, byte ptr [eax]
// 004a3562  83c001               add eax, 1
// 004a3565  84c9                 test cl, cl
// 004a3567  75f7                 jne 0x4a3560
// 004a3569  2bc2                 sub eax, edx
// 004a356b  0fb75604             movzx edx, word ptr [esi + 4]
// 004a356f  6a0a                 push 0xa
// 004a3571  8d8810e78b00         lea ecx, [eax + 0x8be710]
// 004a3577  51                   push ecx
// 004a3578  52                   push edx
// 004a3579  ff151ce97700         call dword ptr [0x77e91c]
// 004a357f  83c40c               add esp, 0xc
// 004a3582  b810e78b00           mov eax, 0x8be710
// 004a3587  5e                   pop esi
// 004a3588  c20400               ret 4
// library openrbx-raknet/RakNetTypes.cpp (function ?ToString@SystemAddress@@QBEPAD_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakNetTypes.cpp
