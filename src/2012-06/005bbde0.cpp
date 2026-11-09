// roc 2012-06 005bbde0  unit: RakNet::RakPeer  size: 280 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bbde0
//
// 005bbde0  56                   push esi
// 005bbde1  8bf1                 mov esi, ecx
// 005bbde3  684c69e200           push 0xe2694c
// 005bbde8  8d4c240c             lea ecx, [esp + 0xc]
// 005bbdec  e8af5afaff           call 0x5618a0
// 005bbdf1  84c0                 test al, al
// 005bbdf3  7407                 je 0x5bbdfc
// 005bbdf5  83c8ff               or eax, 0xffffffff
// 005bbdf8  5e                   pop esi
// 005bbdf9  c21800               ret 0x18
// 005bbdfc  668b44241a           mov ax, word ptr [esp + 0x1a]
// 005bbe01  b9ffff0000           mov ecx, 0xffff
// 005bbe06  663bc1               cmp ax, cx
// 005bbe09  7444                 je 0x5bbe4f
// 005bbe0b  663b460e             cmp ax, word ptr [esi + 0xe]
// 005bbe0f  733e                 jae 0x5bbe4f
// 005bbe11  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bbe17  0fb7c0               movzx eax, ax
// 005bbe1a  69c008120000         imul eax, eax, 0x1208
// 005bbe20  8d542408             lea edx, [esp + 8]
// 005bbe24  52                   push edx
// 005bbe25  8d4c0804             lea ecx, [eax + ecx + 4]
// 005bbe29  e8725afaff           call 0x5618a0
// 005bbe2e  84c0                 test al, al
// 005bbe30  741d                 je 0x5bbe4f
// 005bbe32  0fb744241a           movzx eax, word ptr [esp + 0x1a]
// 005bbe37  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bbe3d  8bd0                 mov edx, eax
// 005bbe3f  69d208120000         imul edx, edx, 0x1208
// 005bbe45  803c0a00             cmp byte ptr [edx + ecx], 0
// 005bbe49  0f859d000000         jne 0x5bbeec
// 005bbe4f  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 005bbe54  7410                 je 0x5bbe66
// 005bbe56  8d542408             lea edx, [esp + 8]
// 005bbe5a  52                   push edx
// 005bbe5b  8bce                 mov ecx, esi
// 005bbe5d  e83ef5ffff           call 0x5bb3a0
// 005bbe62  5e                   pop esi
// 005bbe63  c21800               ret 0x18
// 005bbe66  53                   push ebx
// 005bbe67  57                   push edi
// 005bbe68  33c0                 xor eax, eax
// 005bbe6a  33ff                 xor edi, edi
// 005bbe6c  663b460e             cmp ax, word ptr [esi + 0xe]
// 005bbe70  733d                 jae 0x5bbeaf
// 005bbe72  33db                 xor ebx, ebx
// 005bbe74  eb0a                 jmp 0x5bbe80
// 005bbe76  8da42400000000       lea esp, [esp]
// 005bbe7d  8d4900               lea ecx, [ecx]
// 005bbe80  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bbe86  803c0b00             cmp byte ptr [ebx + ecx], 0
// 005bbe8a  8d040b               lea eax, [ebx + ecx]
// 005bbe8d  7411                 je 0x5bbea0
// 005bbe8f  8d542410             lea edx, [esp + 0x10]
// 005bbe93  52                   push edx
// 005bbe94  8d4804               lea ecx, [eax + 4]
// 005bbe97  e8045afaff           call 0x5618a0
// 005bbe9c  84c0                 test al, al
// 005bbe9e  7550                 jne 0x5bbef0
// 005bbea0  0fb7460e             movzx eax, word ptr [esi + 0xe]
// 005bbea4  47                   inc edi
// 005bbea5  81c308120000         add ebx, 0x1208
// 005bbeab  3bf8                 cmp edi, eax
// 005bbead  72d1                 jb 0x5bbe80
// 005bbeaf  33c9                 xor ecx, ecx
// 005bbeb1  33ff                 xor edi, edi
// 005bbeb3  663b4e0e             cmp cx, word ptr [esi + 0xe]
// 005bbeb7  732e                 jae 0x5bbee7
// 005bbeb9  33db                 xor ebx, ebx
// 005bbebb  eb03                 jmp 0x5bbec0
// 005bbebd  8d4900               lea ecx, [ecx]
// 005bbec0  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 005bbec6  8d542410             lea edx, [esp + 0x10]
// 005bbeca  52                   push edx
// 005bbecb  8d4c0304             lea ecx, [ebx + eax + 4]
// 005bbecf  e8cc59faff           call 0x5618a0
// 005bbed4  84c0                 test al, al
// 005bbed6  7518                 jne 0x5bbef0
// 005bbed8  0fb74e0e             movzx ecx, word ptr [esi + 0xe]
// 005bbedc  47                   inc edi
// 005bbedd  81c308120000         add ebx, 0x1208
// 005bbee3  3bf9                 cmp edi, ecx
// 005bbee5  72d9                 jb 0x5bbec0
// 005bbee7  5f                   pop edi
// 005bbee8  83c8ff               or eax, 0xffffffff
// 005bbeeb  5b                   pop ebx
// 005bbeec  5e                   pop esi
// 005bbeed  c21800               ret 0x18
// 005bbef0  8bc7                 mov eax, edi
// 005bbef2  5f                   pop edi
// 005bbef3  5b                   pop ebx
// 005bbef4  5e                   pop esi
// 005bbef5  c21800               ret 0x18
// copied from an identical function in another client (function ?GetIndexFromSystemAddress@RakPeer@RakNet@@IBEHUSystemAddress@2@_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp