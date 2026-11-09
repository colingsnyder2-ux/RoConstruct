// from server: 100% by auto
// roc 2009-12 00891820  unit: CXTPDockBar::UDOCK_INFO::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00891820
//
// 00891820  56                   push esi
// 00891821  57                   push edi
// 00891822  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00891826  8b4718               mov eax, dword ptr [edi + 0x18]
// 00891829  f7d0                 not eax
// 0089182b  8bf1                 mov esi, ecx
// 0089182d  a801                 test al, 1
// 0089182f  741e                 je 0x89184f
// 00891831  8b4e08               mov ecx, dword ptr [esi + 8]
// 00891834  51                   push ecx
// 00891835  8bcf                 mov ecx, edi
// 00891837  e8b82bf6ff           call 0x7f43f4
// 0089183c  8b5608               mov edx, dword ptr [esi + 8]
// 0089183f  8b4604               mov eax, dword ptr [esi + 4]
// 00891842  52                   push edx
// 00891843  50                   push eax
// 00891844  57                   push edi
// 00891845  e846fcffff           call 0x891490
// 0089184a  5f                   pop edi
// 0089184b  5e                   pop esi
// 0089184c  c20400               ret 4
// 0089184f  8bcf                 mov ecx, edi
// 00891851  e8982bf6ff           call 0x7f43ee
// 00891856  6aff                 push -1
// 00891858  50                   push eax
// 00891859  8bce                 mov ecx, esi
// 0089185b  e860f9ffff           call 0x8911c0
// 00891860  8b5608               mov edx, dword ptr [esi + 8]
// 00891863  8b4604               mov eax, dword ptr [esi + 4]
// 00891866  52                   push edx
// 00891867  50                   push eax
// 00891868  57                   push edi
// 00891869  e822fcffff           call 0x891490
// 0089186e  5f                   pop edi
// 0089186f  5e                   pop esi
// 00891870  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
