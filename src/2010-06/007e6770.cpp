// from server: 100% by auto
// roc 2010-06 007e6770  unit: CRobloxTreeCtrl  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e6770
//
// 007e6770  53                   push ebx
// 007e6771  8b1d54ba9e00         mov ebx, dword ptr [0x9eba54]
// 007e6777  56                   push esi
// 007e6778  57                   push edi
// 007e6779  8bf9                 mov edi, ecx
// 007e677b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007e677f  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e6782  8b5020               mov edx, dword ptr [eax + 0x20]
// 007e6785  51                   push ecx
// 007e6786  6a06                 push 6
// 007e6788  680a110000           push 0x110a
// 007e678d  52                   push edx
// 007e678e  ffd3                 call ebx
// 007e6790  8bf0                 mov esi, eax
// 007e6792  85f6                 test esi, esi
// 007e6794  7428                 je 0x7e67be
// 007e6796  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e6799  6a02                 push 2
// 007e679b  56                   push esi
// 007e679c  e8a1681900           call 0x97d042
// 007e67a1  a802                 test al, 2
// 007e67a3  7517                 jne 0x7e67bc
// 007e67a5  8b4734               mov eax, dword ptr [edi + 0x34]
// 007e67a8  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e67ab  56                   push esi
// 007e67ac  6a06                 push 6
// 007e67ae  680a110000           push 0x110a
// 007e67b3  50                   push eax
// 007e67b4  ffd3                 call ebx
// 007e67b6  8bf0                 mov esi, eax
// 007e67b8  85f6                 test esi, esi
// 007e67ba  75da                 jne 0x7e6796
// 007e67bc  8bc6                 mov eax, esi
// 007e67be  5f                   pop edi
// 007e67bf  5e                   pop esi
// 007e67c0  5b                   pop ebx
// 007e67c1  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetNextSelectedItem@CXTTreeBase@@QBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
