// from server: 100% by auto
// roc 2012-06 00448f30  unit: VCFrameWnd::?$CXTPCommandBarsSiteBase  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00448f30
//
// 00448f30  53                   push ebx
// 00448f31  56                   push esi
// 00448f32  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00448f36  8b4604               mov eax, dword ptr [esi + 4]
// 00448f39  57                   push edi
// 00448f3a  8bd9                 mov ebx, ecx
// 00448f3c  3d00010000           cmp eax, 0x100
// 00448f41  723c                 jb 0x448f7f
// 00448f43  3d09010000           cmp eax, 0x109
// 00448f48  7735                 ja 0x448f7f
// 00448f4a  8b4608               mov eax, dword ptr [esi + 8]
// 00448f4d  83f80d               cmp eax, 0xd
// 00448f50  742d                 je 0x448f7f
// 00448f52  83f809               cmp eax, 9
// 00448f55  7428                 je 0x448f7f
// 00448f57  83f81b               cmp eax, 0x1b
// 00448f5a  7423                 je 0x448f7f
// 00448f5c  ff15e83bb200         call dword ptr [0xb23be8]
// 00448f62  50                   push eax
// 00448f63  e8fe965300           call 0x982666
// 00448f68  8bf8                 mov edi, eax
// 00448f6a  85ff                 test edi, edi
// 00448f6c  7411                 je 0x448f7f
// 00448f6e  e82d545400           call 0x98e3a0
// 00448f73  50                   push eax
// 00448f74  8bcf                 mov ecx, edi
// 00448f76  e81b975300           call 0x982696
// 00448f7b  85c0                 test eax, eax
// 00448f7d  752b                 jne 0x448faa
// 00448f7f  56                   push esi
// 00448f80  8bcb                 mov ecx, ebx
// 00448f82  e8499c5300           call 0x982bd0
// 00448f87  85c0                 test eax, eax
// 00448f89  740b                 je 0x448f96
// 00448f8b  5f                   pop edi
// 00448f8c  5e                   pop esi
// 00448f8d  b801000000           mov eax, 1
// 00448f92  5b                   pop ebx
// 00448f93  c20400               ret 4
// 00448f96  8b8be8000000         mov ecx, dword ptr [ebx + 0xe8]
// 00448f9c  85c9                 test ecx, ecx
// 00448f9e  740a                 je 0x448faa
// 00448fa0  56                   push esi
// 00448fa1  e81ab25500           call 0x9a41c0
// 00448fa6  85c0                 test eax, eax
// 00448fa8  75e1                 jne 0x448f8b
// 00448faa  5f                   pop edi
// 00448fab  5e                   pop esi
// 00448fac  33c0                 xor eax, eax
// 00448fae  5b                   pop ebx
// 00448faf  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPFrameWnd.cpp (function ?PreTranslateMessage@?$CXTPCommandBarsSiteBase@VCFrameWnd@@@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPFrameWnd.cpp
