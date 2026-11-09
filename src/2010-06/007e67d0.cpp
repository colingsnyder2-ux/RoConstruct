// from server: 100% by auto
// roc 2010-06 007e67d0  unit: CRobloxTreeCtrl  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e67d0
//
// 007e67d0  33c0                 xor eax, eax
// 007e67d2  39442404             cmp dword ptr [esp + 4], eax
// 007e67d6  53                   push ebx
// 007e67d7  0f95c0               setne al
// 007e67da  55                   push ebp
// 007e67db  56                   push esi
// 007e67dc  8b742414             mov esi, dword ptr [esp + 0x14]
// 007e67e0  57                   push edi
// 007e67e1  8bf9                 mov edi, ecx
// 007e67e3  8be8                 mov ebp, eax
// 007e67e5  8bdd                 mov ebx, ebp
// 007e67e7  f7db                 neg ebx
// 007e67e9  1bdb                 sbb ebx, ebx
// 007e67eb  83e302               and ebx, 2
// 007e67ee  85f6                 test esi, esi
// 007e67f0  751e                 jne 0x7e6810
// 007e67f2  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e67f5  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007e67f8  56                   push esi
// 007e67f9  56                   push esi
// 007e67fa  680a110000           push 0x110a
// 007e67ff  51                   push ecx
// 007e6800  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e6806  8bf0                 mov esi, eax
// 007e6808  85f6                 test esi, esi
// 007e680a  743e                 je 0x7e684a
// 007e680c  8d642400             lea esp, [esp]
// 007e6810  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e6813  6a02                 push 2
// 007e6815  56                   push esi
// 007e6816  e827681900           call 0x97d042
// 007e681b  d1e8                 shr eax, 1
// 007e681d  83e001               and eax, 1
// 007e6820  3bc5                 cmp eax, ebp
// 007e6822  740b                 je 0x7e682f
// 007e6824  6a02                 push 2
// 007e6826  53                   push ebx
// 007e6827  56                   push esi
// 007e6828  8bcf                 mov ecx, edi
// 007e682a  e8e1faffff           call 0x7e6310
// 007e682f  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e6832  8b5020               mov edx, dword ptr [eax + 0x20]
// 007e6835  56                   push esi
// 007e6836  6a06                 push 6
// 007e6838  680a110000           push 0x110a
// 007e683d  52                   push edx
// 007e683e  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e6844  8bf0                 mov esi, eax
// 007e6846  85f6                 test esi, esi
// 007e6848  75c6                 jne 0x7e6810
// 007e684a  5f                   pop edi
// 007e684b  5e                   pop esi
// 007e684c  5d                   pop ebp
// 007e684d  5b                   pop ebx
// 007e684e  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?SelectAll@CXTTreeBase@@QAEXHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
