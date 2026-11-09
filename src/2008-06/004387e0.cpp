// from server: 100% by auto
// roc 2008-06 004387e0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004387e0
//
// 004387e0  8b442404             mov eax, dword ptr [esp + 4]
// 004387e4  56                   push esi
// 004387e5  8bf1                 mov esi, ecx
// 004387e7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004387ea  8908                 mov dword ptr [eax], ecx
// 004387ec  83460cff             add dword ptr [esi + 0xc], -1
// 004387f0  894610               mov dword ptr [esi + 0x10], eax
// 004387f3  7529                 jne 0x43881e
// 004387f5  8b4604               mov eax, dword ptr [esi + 4]
// 004387f8  57                   push edi
// 004387f9  33ff                 xor edi, edi
// 004387fb  3bc7                 cmp eax, edi
// 004387fd  7407                 je 0x438806
// 004387ff  90                   nop 
// 00438800  8b00                 mov eax, dword ptr [eax]
// 00438802  3bc7                 cmp eax, edi
// 00438804  75fa                 jne 0x438800
// 00438806  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00438809  897e0c               mov dword ptr [esi + 0xc], edi
// 0043880c  897e10               mov dword ptr [esi + 0x10], edi
// 0043880f  897e08               mov dword ptr [esi + 8], edi
// 00438812  897e04               mov dword ptr [esi + 4], edi
// 00438815  e8fe882600           call 0x6a1118
// 0043881a  897e14               mov dword ptr [esi + 0x14], edi
// 0043881d  5f                   pop edi
// 0043881e  5e                   pop esi
// 0043881f  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeNode@?$CList@II@@IAEXPAUCNode@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
