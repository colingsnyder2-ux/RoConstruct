// roc 2012-06 005bb2c0  unit: RakNet::RakPeer  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb2c0
//
// 005bb2c0  56                   push esi
// 005bb2c1  8bf1                 mov esi, ecx
// 005bb2c3  68f815d900           push 0xd915f8
// 005bb2c8  8d4c240c             lea ecx, [esp + 0xc]
// 005bb2cc  e83f6afaff           call 0x561d10
// 005bb2d1  84c0                 test al, al
// 005bb2d3  7406                 je 0x5bb2db
// 005bb2d5  33c0                 xor eax, eax
// 005bb2d7  5e                   pop esi
// 005bb2d8  c21400               ret 0x14
// 005bb2db  53                   push ebx
// 005bb2dc  55                   push ebp
// 005bb2dd  33c0                 xor eax, eax
// 005bb2df  33ed                 xor ebp, ebp
// 005bb2e1  57                   push edi
// 005bb2e2  663b460e             cmp ax, word ptr [esi + 0xe]
// 005bb2e6  7342                 jae 0x5bb32a
// 005bb2e8  8a5c2424             mov bl, byte ptr [esp + 0x24]
// 005bb2ec  33ff                 xor edi, edi
// 005bb2ee  8bff                 mov edi, edi
// 005bb2f0  8b962c020000         mov edx, dword ptr [esi + 0x22c]
// 005bb2f6  8d4c2414             lea ecx, [esp + 0x14]
// 005bb2fa  51                   push ecx
// 005bb2fb  8d8c3ae0110000       lea ecx, [edx + edi + 0x11e0]
// 005bb302  e8096afaff           call 0x561d10
// 005bb307  84c0                 test al, al
// 005bb309  7410                 je 0x5bb31b
// 005bb30b  84db                 test bl, bl
// 005bb30d  7424                 je 0x5bb333
// 005bb30f  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 005bb315  803c0700             cmp byte ptr [edi + eax], 0
// 005bb319  7518                 jne 0x5bb333
// 005bb31b  0fb74e0e             movzx ecx, word ptr [esi + 0xe]
// 005bb31f  45                   inc ebp
// 005bb320  81c708120000         add edi, 0x1208
// 005bb326  3be9                 cmp ebp, ecx
// 005bb328  72c6                 jb 0x5bb2f0
// 005bb32a  5f                   pop edi
// 005bb32b  5d                   pop ebp
// 005bb32c  5b                   pop ebx
// 005bb32d  33c0                 xor eax, eax
// 005bb32f  5e                   pop esi
// 005bb330  c21400               ret 0x14
// 005bb333  8bc5                 mov eax, ebp
// 005bb335  69c008120000         imul eax, eax, 0x1208
// 005bb33b  03862c020000         add eax, dword ptr [esi + 0x22c]
// 005bb341  5f                   pop edi
// 005bb342  5d                   pop ebp
// 005bb343  5b                   pop ebx
// 005bb344  5e                   pop esi
// 005bb345  c21400               ret 0x14
// copied from an identical function in another client (function ?GetRemoteSystemFromGUID@RakPeer@RakNet@@IBEPAURemoteSystemStruct@12@URakNetGUID@2@_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp