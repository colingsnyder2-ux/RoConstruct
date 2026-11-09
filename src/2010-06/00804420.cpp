// from server: 100% by auto
// roc 2010-06 00804420  unit: CXTPPropExchange  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804420
//
// 00804420  837c240800           cmp dword ptr [esp + 8], 0
// 00804425  56                   push esi
// 00804426  8b742408             mov esi, dword ptr [esp + 8]
// 0080442a  8bce                 mov ecx, esi
// 0080442c  746f                 je 0x80449d
// 0080442e  6a00                 push 0
// 00804430  6a5c                 push 0x5c
// 00804432  ff1578c69e00         call dword ptr [0x9ec678]
// 00804438  83f8ff               cmp eax, -1
// 0080443b  0f84a2000000         je 0x8044e3
// 00804441  68e806a600           push 0xa606e8
// 00804446  68a008a200           push 0xa208a0
// 0080444b  8bce                 mov ecx, esi
// 0080444d  ff1514c89e00         call dword ptr [0x9ec814]
// 00804453  681ce7a000           push 0xa0e71c
// 00804458  68a808a200           push 0xa208a8
// 0080445d  8bce                 mov ecx, esi
// 0080445f  ff1514c89e00         call dword ptr [0x9ec814]
// 00804465  68e406a600           push 0xa606e4
// 0080446a  68ac08a200           push 0xa208ac
// 0080446f  8bce                 mov ecx, esi
// 00804471  ff1514c89e00         call dword ptr [0x9ec814]
// 00804477  68d8c5a000           push 0xa0c5d8
// 0080447c  68a408a200           push 0xa208a4
// 00804481  8bce                 mov ecx, esi
// 00804483  ff1514c89e00         call dword ptr [0x9ec814]
// 00804489  688446a000           push 0xa04684
// 0080448e  68e806a600           push 0xa606e8
// 00804493  8bce                 mov ecx, esi
// 00804495  ff1514c89e00         call dword ptr [0x9ec814]
// 0080449b  5e                   pop esi
// 0080449c  c3                   ret 
// 0080449d  68a008a200           push 0xa208a0
// 008044a2  688446a000           push 0xa04684
// 008044a7  ff1514c89e00         call dword ptr [0x9ec814]
// 008044ad  68a808a200           push 0xa208a8
// 008044b2  681ce7a000           push 0xa0e71c
// 008044b7  8bce                 mov ecx, esi
// 008044b9  ff1514c89e00         call dword ptr [0x9ec814]
// 008044bf  68ac08a200           push 0xa208ac
// 008044c4  68e406a600           push 0xa606e4
// 008044c9  8bce                 mov ecx, esi
// 008044cb  ff1514c89e00         call dword ptr [0x9ec814]
// 008044d1  68a408a200           push 0xa208a4
// 008044d6  68d8c5a000           push 0xa0c5d8
// 008044db  8bce                 mov ecx, esi
// 008044dd  ff1514c89e00         call dword ptr [0x9ec814]
// 008044e3  5e                   pop esi
// 008044e4  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PreformatString@CXTPPropExchange@@SAXAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
