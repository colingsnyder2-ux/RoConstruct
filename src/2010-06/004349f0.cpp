// from server: 100% by auto
// roc 2010-06 004349f0  unit: CPropertyGridItemBrickColor  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004349f0
//
// 004349f0  8b442404             mov eax, dword ptr [esp + 4]
// 004349f4  56                   push esi
// 004349f5  8bf1                 mov esi, ecx
// 004349f7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004349fa  8908                 mov dword ptr [eax], ecx
// 004349fc  83460cff             add dword ptr [esi + 0xc], -1
// 00434a00  894610               mov dword ptr [esi + 0x10], eax
// 00434a03  7529                 jne 0x434a2e
// 00434a05  8b4604               mov eax, dword ptr [esi + 4]
// 00434a08  57                   push edi
// 00434a09  33ff                 xor edi, edi
// 00434a0b  3bc7                 cmp eax, edi
// 00434a0d  7407                 je 0x434a16
// 00434a0f  90                   nop 
// 00434a10  8b00                 mov eax, dword ptr [eax]
// 00434a12  3bc7                 cmp eax, edi
// 00434a14  75fa                 jne 0x434a10
// 00434a16  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00434a19  897e0c               mov dword ptr [esi + 0xc], edi
// 00434a1c  897e10               mov dword ptr [esi + 0x10], edi
// 00434a1f  897e08               mov dword ptr [esi + 8], edi
// 00434a22  897e04               mov dword ptr [esi + 4], edi
// 00434a25  e8da3a3700           call 0x7a8504
// 00434a2a  897e14               mov dword ptr [esi + 0x14], edi
// 00434a2d  5f                   pop edi
// 00434a2e  5e                   pop esi
// 00434a2f  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeNode@?$CList@II@@IAEXPAUCNode@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
