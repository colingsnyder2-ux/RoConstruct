// from server: 100% by auto
// roc 2009-12 0086ef50  unit: CXTPResourceManager  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086ef50
//
// 0086ef50  56                   push esi
// 0086ef51  8bf1                 mov esi, ecx
// 0086ef53  8b4624               mov eax, dword ptr [esi + 0x24]
// 0086ef56  57                   push edi
// 0086ef57  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0086ef5b  3bc7                 cmp eax, edi
// 0086ef5d  7438                 je 0x86ef97
// 0086ef5f  85c0                 test eax, eax
// 0086ef61  741e                 je 0x86ef81
// 0086ef63  50                   push eax
// 0086ef64  ff1584cc9800         call dword ptr [0x98cc84]
// 0086ef6a  85c0                 test eax, eax
// 0086ef6c  7413                 je 0x86ef81
// 0086ef6e  8b4624               mov eax, dword ptr [esi + 0x24]
// 0086ef71  6a00                 push 0
// 0086ef73  6a00                 push 0
// 0086ef75  68a3020000           push 0x2a3
// 0086ef7a  50                   push eax
// 0086ef7b  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0086ef81  6860ee8600           push 0x86ee60
// 0086ef86  6a32                 push 0x32
// 0086ef88  68bdba0100           push 0x1babd
// 0086ef8d  57                   push edi
// 0086ef8e  897e24               mov dword ptr [esi + 0x24], edi
// 0086ef91  ff1558cc9800         call dword ptr [0x98cc58]
// 0086ef97  5f                   pop edi
// 0086ef98  5e                   pop esi
// 0086ef99  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?TrackMouseLeave@CXTPMouseManager@@QAEXPAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMouseManager.cpp
