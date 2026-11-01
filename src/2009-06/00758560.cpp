// from server: 100% by auto
// roc 2009-06 00758560  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758560
//
// 00758560  51                   push ecx
// 00758561  56                   push esi
// 00758562  8bf1                 mov esi, ecx
// 00758564  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00758567  e870390f00           call 0x84bedc
// 0075856c  a900040000           test eax, 0x400
// 00758571  740d                 je 0x758580
// 00758573  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00758576  e88d0afcff           call 0x719008
// 0075857b  5e                   pop esi
// 0075857c  59                   pop ecx
// 0075857d  c20c00               ret 0xc
// 00758580  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00758584  8b542410             mov edx, dword ptr [esp + 0x10]
// 00758588  57                   push edi
// 00758589  8d442408             lea eax, [esp + 8]
// 0075858d  50                   push eax
// 0075858e  51                   push ecx
// 0075858f  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00758592  52                   push edx
// 00758593  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0075859b  e84c0efcff           call 0x7193ec
// 007585a0  8bf8                 mov edi, eax
// 007585a2  85ff                 test edi, edi
// 007585a4  7437                 je 0x7585dd
// 007585a6  f644240846           test byte ptr [esp + 8], 0x46
// 007585ab  7430                 je 0x7585dd
// 007585ad  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007585b0  6a02                 push 2
// 007585b2  57                   push edi
// 007585b3  e8e23b0f00           call 0x84c19a
// 007585b8  a802                 test al, 2
// 007585ba  752c                 jne 0x7585e8
// 007585bc  6a00                 push 0
// 007585be  6a00                 push 0
// 007585c0  8bce                 mov ecx, esi
// 007585c2  e8c9f1ffff           call 0x757790
// 007585c7  57                   push edi
// 007585c8  8bce                 mov ecx, esi
// 007585ca  e881f0ffff           call 0x757650
// 007585cf  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007585d2  e8310afcff           call 0x719008
// 007585d7  5f                   pop edi
// 007585d8  5e                   pop esi
// 007585d9  59                   pop ecx
// 007585da  c20c00               ret 0xc
// 007585dd  6a00                 push 0
// 007585df  6a00                 push 0
// 007585e1  8bce                 mov ecx, esi
// 007585e3  e8a8f1ffff           call 0x757790
// 007585e8  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007585eb  e8180afcff           call 0x719008
// 007585f0  5f                   pop edi
// 007585f1  5e                   pop esi
// 007585f2  59                   pop ecx
// 007585f3  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnRButtonDown@CXTPTreeBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
