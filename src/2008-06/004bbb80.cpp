// from server: 100% by auto
// roc 2008-06 004bbb80  unit: ProfiledRakPeer  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbb80
//
// 004bbb80  8b442404             mov eax, dword ptr [esp + 4]
// 004bbb84  56                   push esi
// 004bbb85  8bf1                 mov esi, ecx
// 004bbb87  57                   push edi
// 004bbb88  33c9                 xor ecx, ecx
// 004bbb8a  33ff                 xor edi, edi
// 004bbb8c  8986d0080000         mov dword ptr [esi + 0x8d0], eax
// 004bbb92  663b4e08             cmp cx, word ptr [esi + 8]
// 004bbb96  732e                 jae 0x4bbbc6
// 004bbb98  eb06                 jmp 0x4bbba0
// 004bbb9a  8d9b00000000         lea ebx, [ebx]
// 004bbba0  8b96d0080000         mov edx, dword ptr [esi + 0x8d0]
// 004bbba6  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 004bbbac  0fb7c7               movzx eax, di
// 004bbbaf  69c050080000         imul eax, eax, 0x850
// 004bbbb5  52                   push edx
// 004bbbb6  8d4c0818             lea ecx, [eax + ecx + 0x18]
// 004bbbba  e8115d2e00           call 0x7a18d0
// 004bbbbf  47                   inc edi
// 004bbbc0  663b7e08             cmp di, word ptr [esi + 8]
// 004bbbc4  72da                 jb 0x4bbba0
// 004bbbc6  5f                   pop edi
// 004bbbc7  5e                   pop esi
// 004bbbc8  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?SetSplitMessageProgressInterval@RakPeer@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
