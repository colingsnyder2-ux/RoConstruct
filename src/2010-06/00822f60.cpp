// from server: 100% by auto
// roc 2010-06 00822f60  unit: CXTPResourceManager  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822f60
//
// 00822f60  56                   push esi
// 00822f61  8bf1                 mov esi, ecx
// 00822f63  8b4624               mov eax, dword ptr [esi + 0x24]
// 00822f66  57                   push edi
// 00822f67  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00822f6b  3bc7                 cmp eax, edi
// 00822f6d  7438                 je 0x822fa7
// 00822f6f  85c0                 test eax, eax
// 00822f71  741e                 je 0x822f91
// 00822f73  50                   push eax
// 00822f74  ff1528bc9e00         call dword ptr [0x9ebc28]
// 00822f7a  85c0                 test eax, eax
// 00822f7c  7413                 je 0x822f91
// 00822f7e  8b4624               mov eax, dword ptr [esi + 0x24]
// 00822f81  6a00                 push 0
// 00822f83  6a00                 push 0
// 00822f85  68a3020000           push 0x2a3
// 00822f8a  50                   push eax
// 00822f8b  ff1554ba9e00         call dword ptr [0x9eba54]
// 00822f91  68702e8200           push 0x822e70
// 00822f96  6a32                 push 0x32
// 00822f98  68bdba0100           push 0x1babd
// 00822f9d  57                   push edi
// 00822f9e  897e24               mov dword ptr [esi + 0x24], edi
// 00822fa1  ff1554bc9e00         call dword ptr [0x9ebc54]
// 00822fa7  5f                   pop edi
// 00822fa8  5e                   pop esi
// 00822fa9  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?TrackMouseLeave@CXTPMouseManager@@QAEXPAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMouseManager.cpp
