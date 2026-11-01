// from server: 100% by auto
// roc 2007-03 0068d230  unit: seg_00680000  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068d230
//
// 0068d230  56                   push esi
// 0068d231  8bf1                 mov esi, ecx
// 0068d233  8b4624               mov eax, dword ptr [esi + 0x24]
// 0068d236  57                   push edi
// 0068d237  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0068d23b  3bc7                 cmp eax, edi
// 0068d23d  7438                 je 0x68d277
// 0068d23f  85c0                 test eax, eax
// 0068d241  741e                 je 0x68d261
// 0068d243  50                   push eax
// 0068d244  ff1574ed7700         call dword ptr [0x77ed74]
// 0068d24a  85c0                 test eax, eax
// 0068d24c  7413                 je 0x68d261
// 0068d24e  8b4624               mov eax, dword ptr [esi + 0x24]
// 0068d251  6a00                 push 0
// 0068d253  6a00                 push 0
// 0068d255  68a3020000           push 0x2a3
// 0068d25a  50                   push eax
// 0068d25b  ff1550ee7700         call dword ptr [0x77ee50]
// 0068d261  6840d16800           push 0x68d140
// 0068d266  6a32                 push 0x32
// 0068d268  68bdba0100           push 0x1babd
// 0068d26d  57                   push edi
// 0068d26e  897e24               mov dword ptr [esi + 0x24], edi
// 0068d271  ff1544ed7700         call dword ptr [0x77ed44]
// 0068d277  5f                   pop edi
// 0068d278  5e                   pop esi
// 0068d279  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?TrackMouseLeave@CXTPMouseManager@@QAEXPAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMouseManager.cpp
