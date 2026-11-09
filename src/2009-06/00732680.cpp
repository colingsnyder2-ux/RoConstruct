// from server: 100% by auto
// roc 2009-06 00732680  unit: CXTPCommandBar  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732680
//
// 00732680  53                   push ebx
// 00732681  56                   push esi
// 00732682  8bf1                 mov esi, ecx
// 00732684  57                   push edi
// 00732685  8b7e04               mov edi, dword ptr [esi + 4]
// 00732688  33db                 xor ebx, ebx
// 0073268a  3bfb                 cmp edi, ebx
// 0073268c  7421                 je 0x7326af
// 0073268e  395e08               cmp dword ptr [esi + 8], ebx
// 00732691  761c                 jbe 0x7326af
// 00732693  8b5608               mov edx, dword ptr [esi + 8]
// 00732696  8bcf                 mov ecx, edi
// 00732698  8b01                 mov eax, dword ptr [ecx]
// 0073269a  3bc3                 cmp eax, ebx
// 0073269c  7409                 je 0x7326a7
// 0073269e  8bff                 mov edi, edi
// 007326a0  8b4008               mov eax, dword ptr [eax + 8]
// 007326a3  3bc3                 cmp eax, ebx
// 007326a5  75f9                 jne 0x7326a0
// 007326a7  83c104               add ecx, 4
// 007326aa  83ea01               sub edx, 1
// 007326ad  75e9                 jne 0x732698
// 007326af  57                   push edi
// 007326b0  e82966feff           call 0x718cde
// 007326b5  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007326b8  83c404               add esp, 4
// 007326bb  895e04               mov dword ptr [esi + 4], ebx
// 007326be  895e0c               mov dword ptr [esi + 0xc], ebx
// 007326c1  895e10               mov dword ptr [esi + 0x10], ebx
// 007326c4  e8cd6efeff           call 0x719596
// 007326c9  5f                   pop edi
// 007326ca  895e14               mov dword ptr [esi + 0x14], ebx
// 007326cd  5e                   pop esi
// 007326ce  5b                   pop ebx
// 007326cf  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?RemoveAll@?$CMap@PAUHICON__@@PAU1@HH@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
