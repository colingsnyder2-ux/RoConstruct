// from server: 100% by auto
// roc 2010-06 007e5910  unit: CXTTreeBase  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5910
//
// 007e5910  56                   push esi
// 007e5911  57                   push edi
// 007e5912  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e5916  817f08f7fdffff       cmp dword ptr [edi + 8], 0xfffffdf7
// 007e591d  8bf1                 mov esi, ecx
// 007e591f  752d                 jne 0x7e594e
// 007e5921  8b4634               mov eax, dword ptr [esi + 0x34]
// 007e5924  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007e5927  6a00                 push 0
// 007e5929  6a00                 push 0
// 007e592b  6819110000           push 0x1119
// 007e5930  51                   push ecx
// 007e5931  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e5937  85c0                 test eax, eax
// 007e5939  7413                 je 0x7e594e
// 007e593b  6a13                 push 0x13
// 007e593d  6a00                 push 0
// 007e593f  6a00                 push 0
// 007e5941  6a00                 push 0
// 007e5943  6a00                 push 0
// 007e5945  6a00                 push 0
// 007e5947  50                   push eax
// 007e5948  ff1544bb9e00         call dword ptr [0x9ebb44]
// 007e594e  8b542414             mov edx, dword ptr [esp + 0x14]
// 007e5952  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e5956  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e5959  52                   push edx
// 007e595a  57                   push edi
// 007e595b  50                   push eax
// 007e595c  e89b21fcff           call 0x7a7afc
// 007e5961  5f                   pop edi
// 007e5962  5e                   pop esi
// 007e5963  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnNotify@CXTTreeBase@@MAEHIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
