// from server: 100% by auto
// roc 2008-06 006e34d0  unit: HH::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006e34d0
//
// 006e34d0  56                   push esi
// 006e34d1  57                   push edi
// 006e34d2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006e34d6  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e34d9  f7d0                 not eax
// 006e34db  8bf1                 mov esi, ecx
// 006e34dd  a801                 test al, 1
// 006e34df  741e                 je 0x6e34ff
// 006e34e1  8b4e08               mov ecx, dword ptr [esi + 8]
// 006e34e4  51                   push ecx
// 006e34e5  8bcf                 mov ecx, edi
// 006e34e7  e85cdcfbff           call 0x6a1148
// 006e34ec  8b5608               mov edx, dword ptr [esi + 8]
// 006e34ef  8b4604               mov eax, dword ptr [esi + 4]
// 006e34f2  52                   push edx
// 006e34f3  50                   push eax
// 006e34f4  57                   push edi
// 006e34f5  e856400a00           call 0x787550
// 006e34fa  5f                   pop edi
// 006e34fb  5e                   pop esi
// 006e34fc  c20400               ret 4
// 006e34ff  8bcf                 mov ecx, edi
// 006e3501  e83cdcfbff           call 0x6a1142
// 006e3506  6aff                 push -1
// 006e3508  50                   push eax
// 006e3509  8bce                 mov ecx, esi
// 006e350b  e8c0ac0200           call 0x70e1d0
// 006e3510  8b5608               mov edx, dword ptr [esi + 8]
// 006e3513  8b4604               mov eax, dword ptr [esi + 4]
// 006e3516  52                   push edx
// 006e3517  50                   push eax
// 006e3518  57                   push edi
// 006e3519  e832400a00           call 0x787550
// 006e351e  5f                   pop edi
// 006e351f  5e                   pop esi
// 006e3520  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
