// from server: 100% by auto
// roc 2011-06 0043d520  unit: VCFrameWnd::?$CXTPCommandBarsSiteBase  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0043d520
//
// 0043d520  53                   push ebx
// 0043d521  56                   push esi
// 0043d522  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0043d526  8b4604               mov eax, dword ptr [esi + 4]
// 0043d529  57                   push edi
// 0043d52a  8bd9                 mov ebx, ecx
// 0043d52c  3d00010000           cmp eax, 0x100
// 0043d531  723c                 jb 0x43d56f
// 0043d533  3d09010000           cmp eax, 0x109
// 0043d538  7735                 ja 0x43d56f
// 0043d53a  8b4608               mov eax, dword ptr [esi + 8]
// 0043d53d  83f80d               cmp eax, 0xd
// 0043d540  742d                 je 0x43d56f
// 0043d542  83f809               cmp eax, 9
// 0043d545  7428                 je 0x43d56f
// 0043d547  83f81b               cmp eax, 0x1b
// 0043d54a  7423                 je 0x43d56f
// 0043d54c  ff15f819a400         call dword ptr [0xa419f8]
// 0043d552  50                   push eax
// 0043d553  e8d0cd3c00           call 0x80a328
// 0043d558  8bf8                 mov edi, eax
// 0043d55a  85ff                 test edi, edi
// 0043d55c  7411                 je 0x43d56f
// 0043d55e  e8bd8b3d00           call 0x816120
// 0043d563  50                   push eax
// 0043d564  8bcf                 mov ecx, edi
// 0043d566  e87bd03c00           call 0x80a5e6
// 0043d56b  85c0                 test eax, eax
// 0043d56d  752b                 jne 0x43d59a
// 0043d56f  56                   push esi
// 0043d570  8bcb                 mov ecx, ebx
// 0043d572  e8d3d53c00           call 0x80ab4a
// 0043d577  85c0                 test eax, eax
// 0043d579  740b                 je 0x43d586
// 0043d57b  5f                   pop edi
// 0043d57c  5e                   pop esi
// 0043d57d  b801000000           mov eax, 1
// 0043d582  5b                   pop ebx
// 0043d583  c20400               ret 4
// 0043d586  8b8be8000000         mov ecx, dword ptr [ebx + 0xe8]
// 0043d58c  85c9                 test ecx, ecx
// 0043d58e  740a                 je 0x43d59a
// 0043d590  56                   push esi
// 0043d591  e85ae63e00           call 0x82bbf0
// 0043d596  85c0                 test eax, eax
// 0043d598  75e1                 jne 0x43d57b
// 0043d59a  5f                   pop edi
// 0043d59b  5e                   pop esi
// 0043d59c  33c0                 xor eax, eax
// 0043d59e  5b                   pop ebx
// 0043d59f  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPFrameWnd.cpp (function ?PreTranslateMessage@?$CXTPCommandBarsSiteBase@VCFrameWnd@@@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPFrameWnd.cpp
