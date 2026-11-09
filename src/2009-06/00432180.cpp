// from server: 100% by auto
// roc 2009-06 00432180  unit: RBX::Soundscape::VSoundId::?$XItem  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00432180
//
// 00432180  8b442404             mov eax, dword ptr [esp + 4]
// 00432184  56                   push esi
// 00432185  8bf1                 mov esi, ecx
// 00432187  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0043218a  8908                 mov dword ptr [eax], ecx
// 0043218c  83460cff             add dword ptr [esi + 0xc], -1
// 00432190  894610               mov dword ptr [esi + 0x10], eax
// 00432193  7529                 jne 0x4321be
// 00432195  8b4604               mov eax, dword ptr [esi + 4]
// 00432198  57                   push edi
// 00432199  33ff                 xor edi, edi
// 0043219b  3bc7                 cmp eax, edi
// 0043219d  7407                 je 0x4321a6
// 0043219f  90                   nop 
// 004321a0  8b00                 mov eax, dword ptr [eax]
// 004321a2  3bc7                 cmp eax, edi
// 004321a4  75fa                 jne 0x4321a0
// 004321a6  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004321a9  897e0c               mov dword ptr [esi + 0xc], edi
// 004321ac  897e10               mov dword ptr [esi + 0x10], edi
// 004321af  897e08               mov dword ptr [esi + 8], edi
// 004321b2  897e04               mov dword ptr [esi + 4], edi
// 004321b5  e8dc732e00           call 0x719596
// 004321ba  897e14               mov dword ptr [esi + 0x14], edi
// 004321bd  5f                   pop edi
// 004321be  5e                   pop esi
// 004321bf  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeNode@?$CList@II@@IAEXPAUCNode@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
