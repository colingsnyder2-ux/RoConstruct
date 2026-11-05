// from server: 100% by auto
// roc 2010-06 0042a8f0  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042a8f0
//
// 0042a8f0  53                   push ebx
// 0042a8f1  56                   push esi
// 0042a8f2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0042a8f6  8b4604               mov eax, dword ptr [esi + 4]
// 0042a8f9  57                   push edi
// 0042a8fa  8bd9                 mov ebx, ecx
// 0042a8fc  3d00010000           cmp eax, 0x100
// 0042a901  723c                 jb 0x42a93f
// 0042a903  3d09010000           cmp eax, 0x109
// 0042a908  7735                 ja 0x42a93f
// 0042a90a  8b4608               mov eax, dword ptr [esi + 8]
// 0042a90d  83f80d               cmp eax, 0xd
// 0042a910  742d                 je 0x42a93f
// 0042a912  83f809               cmp eax, 9
// 0042a915  7428                 je 0x42a93f
// 0042a917  83f81b               cmp eax, 0x1b
// 0042a91a  7423                 je 0x42a93f
// 0042a91c  ff1580ba9e00         call dword ptr [0x9eba80]
// 0042a922  50                   push eax
// 0042a923  e842d33700           call 0x7a7c6a
// 0042a928  8bf8                 mov edi, eax
// 0042a92a  85ff                 test edi, edi
// 0042a92c  7411                 je 0x42a93f
// 0042a92e  e8ad933800           call 0x7b3ce0
// 0042a933  50                   push eax
// 0042a934  8bcf                 mov ecx, edi
// 0042a936  e8edd53700           call 0x7a7f28
// 0042a93b  85c0                 test eax, eax
// 0042a93d  752b                 jne 0x42a96a
// 0042a93f  56                   push esi
// 0042a940  8bcb                 mov ecx, ebx
// 0042a942  e8c7da3700           call 0x7a840e
// 0042a947  85c0                 test eax, eax
// 0042a949  740b                 je 0x42a956
// 0042a94b  5f                   pop edi
// 0042a94c  5e                   pop esi
// 0042a94d  b801000000           mov eax, 1
// 0042a952  5b                   pop ebx
// 0042a953  c20400               ret 4
// 0042a956  8b8bec000000         mov ecx, dword ptr [ebx + 0xec]
// 0042a95c  85c9                 test ecx, ecx
// 0042a95e  740a                 je 0x42a96a
// 0042a960  56                   push esi
// 0042a961  e8daf73900           call 0x7ca140
// 0042a966  85c0                 test eax, eax
// 0042a968  75e1                 jne 0x42a94b
// 0042a96a  5f                   pop edi
// 0042a96b  5e                   pop esi
// 0042a96c  33c0                 xor eax, eax
// 0042a96e  5b                   pop ebx
// 0042a96f  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPFrameWnd.cpp (function ?PreTranslateMessage@?$CXTPCommandBarsSiteBase@VCMDIFrameWnd@@@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPFrameWnd.cpp
