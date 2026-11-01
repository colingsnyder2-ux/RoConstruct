// from server: 100% by auto
// roc 2009-06 00793df0  unit: CXTPKeyboardManager  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00793df0
//
// 00793df0  56                   push esi
// 00793df1  8bf1                 mov esi, ecx
// 00793df3  8b4624               mov eax, dword ptr [esi + 0x24]
// 00793df6  57                   push edi
// 00793df7  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00793dfb  3bc7                 cmp eax, edi
// 00793dfd  7438                 je 0x793e37
// 00793dff  85c0                 test eax, eax
// 00793e01  741e                 je 0x793e21
// 00793e03  50                   push eax
// 00793e04  ff15e0ed8900         call dword ptr [0x89ede0]
// 00793e0a  85c0                 test eax, eax
// 00793e0c  7413                 je 0x793e21
// 00793e0e  8b4624               mov eax, dword ptr [esi + 0x24]
// 00793e11  6a00                 push 0
// 00793e13  6a00                 push 0
// 00793e15  68a3020000           push 0x2a3
// 00793e1a  50                   push eax
// 00793e1b  ff1590ee8900         call dword ptr [0x89ee90]
// 00793e21  68003d7900           push 0x793d00
// 00793e26  6a32                 push 0x32
// 00793e28  68bdba0100           push 0x1babd
// 00793e2d  57                   push edi
// 00793e2e  897e24               mov dword ptr [esi + 0x24], edi
// 00793e31  ff150cee8900         call dword ptr [0x89ee0c]
// 00793e37  5f                   pop edi
// 00793e38  5e                   pop esi
// 00793e39  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?TrackMouseLeave@CXTPMouseManager@@QAEXPAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMouseManager.cpp
