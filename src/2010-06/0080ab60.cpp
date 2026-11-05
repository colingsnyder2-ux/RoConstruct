// from server: 100% by auto
// roc 2010-06 0080ab60  unit: CXTPTabClientWnd  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080ab60
//
// 0080ab60  56                   push esi
// 0080ab61  8bf1                 mov esi, ecx
// 0080ab63  83beb400000000       cmp dword ptr [esi + 0xb4], 0
// 0080ab6a  57                   push edi
// 0080ab6b  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0080ab6f  7455                 je 0x80abc6
// 0080ab71  8b4704               mov eax, dword ptr [edi + 4]
// 0080ab74  3d01020000           cmp eax, 0x201
// 0080ab79  741c                 je 0x80ab97
// 0080ab7b  3d04020000           cmp eax, 0x204
// 0080ab80  7415                 je 0x80ab97
// 0080ab82  3d07020000           cmp eax, 0x207
// 0080ab87  740e                 je 0x80ab97
// 0080ab89  3d03020000           cmp eax, 0x203
// 0080ab8e  7407                 je 0x80ab97
// 0080ab90  3d06020000           cmp eax, 0x206
// 0080ab95  752f                 jne 0x80abc6
// 0080ab97  8b0f                 mov ecx, dword ptr [edi]
// 0080ab99  3b4e20               cmp ecx, dword ptr [esi + 0x20]
// 0080ab9c  7528                 jne 0x80abc6
// 0080ab9e  8b570c               mov edx, dword ptr [edi + 0xc]
// 0080aba1  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 0080aba7  52                   push edx
// 0080aba8  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0080abab  50                   push eax
// 0080abac  6868280000           push 0x2868
// 0080abb1  52                   push edx
// 0080abb2  ff1554ba9e00         call dword ptr [0x9eba54]
// 0080abb8  85c0                 test eax, eax
// 0080abba  740a                 je 0x80abc6
// 0080abbc  5f                   pop edi
// 0080abbd  b801000000           mov eax, 1
// 0080abc2  5e                   pop esi
// 0080abc3  c20400               ret 4
// 0080abc6  57                   push edi
// 0080abc7  8bce                 mov ecx, esi
// 0080abc9  e8d2d3f9ff           call 0x7a7fa0
// 0080abce  5f                   pop edi
// 0080abcf  5e                   pop esi
// 0080abd0  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?PreTranslateMessage@CXTPTabClientWnd@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
