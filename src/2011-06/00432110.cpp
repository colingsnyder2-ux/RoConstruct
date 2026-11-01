// from server: 100% by auto
// roc 2011-06 00432110  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00432110
//
// 00432110  53                   push ebx
// 00432111  56                   push esi
// 00432112  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00432116  8b4604               mov eax, dword ptr [esi + 4]
// 00432119  57                   push edi
// 0043211a  8bd9                 mov ebx, ecx
// 0043211c  3d00010000           cmp eax, 0x100
// 00432121  723c                 jb 0x43215f
// 00432123  3d09010000           cmp eax, 0x109
// 00432128  7735                 ja 0x43215f
// 0043212a  8b4608               mov eax, dword ptr [esi + 8]
// 0043212d  83f80d               cmp eax, 0xd
// 00432130  742d                 je 0x43215f
// 00432132  83f809               cmp eax, 9
// 00432135  7428                 je 0x43215f
// 00432137  83f81b               cmp eax, 0x1b
// 0043213a  7423                 je 0x43215f
// 0043213c  ff15f819a400         call dword ptr [0xa419f8]
// 00432142  50                   push eax
// 00432143  e8e0813d00           call 0x80a328
// 00432148  8bf8                 mov edi, eax
// 0043214a  85ff                 test edi, edi
// 0043214c  7411                 je 0x43215f
// 0043214e  e8cd3f3e00           call 0x816120
// 00432153  50                   push eax
// 00432154  8bcf                 mov ecx, edi
// 00432156  e88b843d00           call 0x80a5e6
// 0043215b  85c0                 test eax, eax
// 0043215d  752b                 jne 0x43218a
// 0043215f  56                   push esi
// 00432160  8bcb                 mov ecx, ebx
// 00432162  e86b893d00           call 0x80aad2
// 00432167  85c0                 test eax, eax
// 00432169  740b                 je 0x432176
// 0043216b  5f                   pop edi
// 0043216c  5e                   pop esi
// 0043216d  b801000000           mov eax, 1
// 00432172  5b                   pop ebx
// 00432173  c20400               ret 4
// 00432176  8b8bec000000         mov ecx, dword ptr [ebx + 0xec]
// 0043217c  85c9                 test ecx, ecx
// 0043217e  740a                 je 0x43218a
// 00432180  56                   push esi
// 00432181  e86a9a3f00           call 0x82bbf0
// 00432186  85c0                 test eax, eax
// 00432188  75e1                 jne 0x43216b
// 0043218a  5f                   pop edi
// 0043218b  5e                   pop esi
// 0043218c  33c0                 xor eax, eax
// 0043218e  5b                   pop ebx
// 0043218f  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPFrameWnd.cpp (function ?PreTranslateMessage@?$CXTPCommandBarsSiteBase@VCMDIFrameWnd@@@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPFrameWnd.cpp
