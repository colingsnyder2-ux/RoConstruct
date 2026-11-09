// roc 2012-06 005bc000  unit: RakNet::RakPeer  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bc000
//
// 005bc000  83ec14               sub esp, 0x14
// 005bc003  8b442418             mov eax, dword ptr [esp + 0x18]
// 005bc007  8b542420             mov edx, dword ptr [esp + 0x20]
// 005bc00b  56                   push esi
// 005bc00c  8bf1                 mov esi, ecx
// 005bc00e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005bc012  894c2408             mov dword ptr [esp + 8], ecx
// 005bc016  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005bc01a  89442404             mov dword ptr [esp + 4], eax
// 005bc01e  8b442428             mov eax, dword ptr [esp + 0x28]
// 005bc022  894c2414             mov dword ptr [esp + 0x14], ecx
// 005bc026  684c69e200           push 0xe2694c
// 005bc02b  8d4c2408             lea ecx, [esp + 8]
// 005bc02f  89542410             mov dword ptr [esp + 0x10], edx
// 005bc033  89442414             mov dword ptr [esp + 0x14], eax
// 005bc037  e86458faff           call 0x5618a0
// 005bc03c  84c0                 test al, al
// 005bc03e  7528                 jne 0x5bc068
// 005bc040  8d542404             lea edx, [esp + 4]
// 005bc044  52                   push edx
// 005bc045  8bce                 mov ecx, esi
// 005bc047  e854f3ffff           call 0x5bb3a0
// 005bc04c  83f8ff               cmp eax, -1
// 005bc04f  7417                 je 0x5bc068
// 005bc051  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bc057  69c008120000         imul eax, eax, 0x1208
// 005bc05d  03c8                 add ecx, eax
// 005bc05f  803901               cmp byte ptr [ecx], 1
// 005bc062  7504                 jne 0x5bc068
// 005bc064  85c9                 test ecx, ecx
// 005bc066  750b                 jne 0x5bc073
// 005bc068  33c0                 xor eax, eax
// 005bc06a  33d2                 xor edx, edx
// 005bc06c  5e                   pop esi
// 005bc06d  83c414               add esp, 0x14
// 005bc070  c21400               ret 0x14
// 005bc073  53                   push ebx
// 005bc074  55                   push ebp
// 005bc075  57                   push edi
// 005bc076  33c0                 xor eax, eax
// 005bc078  33d2                 xor edx, edx
// 005bc07a  33ff                 xor edi, edi
// 005bc07c  bbffff0000           mov ebx, 0xffff
// 005bc081  81c168110000         add ecx, 0x1168
// 005bc087  eb07                 jmp 0x5bc090
// 005bc089  8da42400000000       lea esp, [esp]
// 005bc090  0fb731               movzx esi, word ptr [ecx]
// 005bc093  bdffff0000           mov ebp, 0xffff
// 005bc098  663bf5               cmp si, bp
// 005bc09b  7418                 je 0x5bc0b5
// 005bc09d  0fb7f6               movzx esi, si
// 005bc0a0  3bf3                 cmp esi, ebx
// 005bc0a2  7d08                 jge 0x5bc0ac
// 005bc0a4  8b4108               mov eax, dword ptr [ecx + 8]
// 005bc0a7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005bc0aa  8bde                 mov ebx, esi
// 005bc0ac  47                   inc edi
// 005bc0ad  83c110               add ecx, 0x10
// 005bc0b0  83ff05               cmp edi, 5
// 005bc0b3  7cdb                 jl 0x5bc090
// 005bc0b5  5f                   pop edi
// 005bc0b6  5d                   pop ebp
// 005bc0b7  5b                   pop ebx
// 005bc0b8  5e                   pop esi
// 005bc0b9  83c414               add esp, 0x14
// 005bc0bc  c21400               ret 0x14
// copied from an identical function in another client (function ?GetBestClockDifferential@RakPeer@RakNet@@IBE_KUSystemAddress@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp