// from server: 100% by auto
// roc 2010-06 0042dc40  unit: VCFrameWnd::?$CXTPCommandBarsSiteBase  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042dc40
//
// 0042dc40  53                   push ebx
// 0042dc41  56                   push esi
// 0042dc42  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0042dc46  8b4604               mov eax, dword ptr [esi + 4]
// 0042dc49  57                   push edi
// 0042dc4a  8bd9                 mov ebx, ecx
// 0042dc4c  3d00010000           cmp eax, 0x100
// 0042dc51  723c                 jb 0x42dc8f
// 0042dc53  3d09010000           cmp eax, 0x109
// 0042dc58  7735                 ja 0x42dc8f
// 0042dc5a  8b4608               mov eax, dword ptr [esi + 8]
// 0042dc5d  83f80d               cmp eax, 0xd
// 0042dc60  742d                 je 0x42dc8f
// 0042dc62  83f809               cmp eax, 9
// 0042dc65  7428                 je 0x42dc8f
// 0042dc67  83f81b               cmp eax, 0x1b
// 0042dc6a  7423                 je 0x42dc8f
// 0042dc6c  ff1580ba9e00         call dword ptr [0x9eba80]
// 0042dc72  50                   push eax
// 0042dc73  e8f29f3700           call 0x7a7c6a
// 0042dc78  8bf8                 mov edi, eax
// 0042dc7a  85ff                 test edi, edi
// 0042dc7c  7411                 je 0x42dc8f
// 0042dc7e  e85d603800           call 0x7b3ce0
// 0042dc83  50                   push eax
// 0042dc84  8bcf                 mov ecx, edi
// 0042dc86  e89da23700           call 0x7a7f28
// 0042dc8b  85c0                 test eax, eax
// 0042dc8d  752b                 jne 0x42dcba
// 0042dc8f  56                   push esi
// 0042dc90  8bcb                 mov ecx, ebx
// 0042dc92  e8efa73700           call 0x7a8486
// 0042dc97  85c0                 test eax, eax
// 0042dc99  740b                 je 0x42dca6
// 0042dc9b  5f                   pop edi
// 0042dc9c  5e                   pop esi
// 0042dc9d  b801000000           mov eax, 1
// 0042dca2  5b                   pop ebx
// 0042dca3  c20400               ret 4
// 0042dca6  8b8be8000000         mov ecx, dword ptr [ebx + 0xe8]
// 0042dcac  85c9                 test ecx, ecx
// 0042dcae  740a                 je 0x42dcba
// 0042dcb0  56                   push esi
// 0042dcb1  e88ac43900           call 0x7ca140
// 0042dcb6  85c0                 test eax, eax
// 0042dcb8  75e1                 jne 0x42dc9b
// 0042dcba  5f                   pop edi
// 0042dcbb  5e                   pop esi
// 0042dcbc  33c0                 xor eax, eax
// 0042dcbe  5b                   pop ebx
// 0042dcbf  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPFrameWnd.cpp (function ?PreTranslateMessage@?$CXTPCommandBarsSiteBase@VCFrameWnd@@@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPFrameWnd.cpp
