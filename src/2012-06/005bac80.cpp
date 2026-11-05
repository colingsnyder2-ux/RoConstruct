// roc 2012-06 005bac80  unit: RakNet::RakPeer  size: 187 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bac80
//
// 005bac80  56                   push esi
// 005bac81  8bf1                 mov esi, ecx
// 005bac83  68f815d900           push 0xd915f8
// 005bac88  8d4c240c             lea ecx, [esp + 0xc]
// 005bac8c  e87f70faff           call 0x561d10
// 005bac91  84c0                 test al, al
// 005bac93  7407                 je 0x5bac9c
// 005bac95  83c8ff               or eax, 0xffffffff
// 005bac98  5e                   pop esi
// 005bac99  c21000               ret 0x10
// 005bac9c  8d8658040000         lea eax, [esi + 0x458]
// 005baca2  50                   push eax
// 005baca3  8d4c240c             lea ecx, [esp + 0xc]
// 005baca7  e86470faff           call 0x561d10
// 005bacac  84c0                 test al, al
// 005bacae  75e5                 jne 0x5bac95
// 005bacb0  668b442410           mov ax, word ptr [esp + 0x10]
// 005bacb5  b9ffff0000           mov ecx, 0xffff
// 005bacba  663bc1               cmp ax, cx
// 005bacbd  7433                 je 0x5bacf2
// 005bacbf  663b460e             cmp ax, word ptr [esi + 0xe]
// 005bacc3  732d                 jae 0x5bacf2
// 005bacc5  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005baccb  0fb7c0               movzx eax, ax
// 005bacce  69c008120000         imul eax, eax, 0x1208
// 005bacd4  8d542408             lea edx, [esp + 8]
// 005bacd8  52                   push edx
// 005bacd9  8d8c08e0110000       lea ecx, [eax + ecx + 0x11e0]
// 005bace0  e82b70faff           call 0x561d10
// 005bace5  84c0                 test al, al
// 005bace7  7409                 je 0x5bacf2
// 005bace9  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 005bacee  5e                   pop esi
// 005bacef  c21000               ret 0x10
// 005bacf2  53                   push ebx
// 005bacf3  57                   push edi
// 005bacf4  33d2                 xor edx, edx
// 005bacf6  33ff                 xor edi, edi
// 005bacf8  663b560e             cmp dx, word ptr [esi + 0xe]
// 005bacfc  732c                 jae 0x5bad2a
// 005bacfe  33db                 xor ebx, ebx
// 005bad00  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bad06  8d442410             lea eax, [esp + 0x10]
// 005bad0a  50                   push eax
// 005bad0b  8d8c19e0110000       lea ecx, [ecx + ebx + 0x11e0]
// 005bad12  e8f96ffaff           call 0x561d10
// 005bad17  84c0                 test al, al
// 005bad19  7518                 jne 0x5bad33
// 005bad1b  0fb7560e             movzx edx, word ptr [esi + 0xe]
// 005bad1f  47                   inc edi
// 005bad20  81c308120000         add ebx, 0x1208
// 005bad26  3bfa                 cmp edi, edx
// 005bad28  72d6                 jb 0x5bad00
// 005bad2a  5f                   pop edi
// 005bad2b  5b                   pop ebx
// 005bad2c  83c8ff               or eax, 0xffffffff
// 005bad2f  5e                   pop esi
// 005bad30  c21000               ret 0x10
// 005bad33  8bc7                 mov eax, edi
// 005bad35  5f                   pop edi
// 005bad36  5b                   pop ebx
// 005bad37  5e                   pop esi
// 005bad38  c21000               ret 0x10
// copied from an identical function in another client (function ?GetSystemIndexFromGuid@RakPeer@RakNet@@IBEIURakNetGUID@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp