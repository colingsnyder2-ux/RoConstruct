// from server: 100% by auto
// roc 2009-06 007bec00  unit: CXTPToolBar::CControlButtonHide  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bec00
//
// 007bec00  8b442404             mov eax, dword ptr [esp + 4]
// 007bec04  56                   push esi
// 007bec05  8bf1                 mov esi, ecx
// 007bec07  57                   push edi
// 007bec08  8d4e18               lea ecx, [esi + 0x18]
// 007bec0b  33ff                 xor edi, edi
// 007bec0d  51                   push ecx
// 007bec0e  c706984d9000         mov dword ptr [esi], 0x904d98
// 007bec14  894604               mov dword ptr [esi + 4], eax
// 007bec17  897e14               mov dword ptr [esi + 0x14], edi
// 007bec1a  ff15c8ee8900         call dword ptr [0x89eec8]
// 007bec20  897e28               mov dword ptr [esi + 0x28], edi
// 007bec23  897e2c               mov dword ptr [esi + 0x2c], edi
// 007bec26  897e08               mov dword ptr [esi + 8], edi
// 007bec29  5f                   pop edi
// 007bec2a  8bc6                 mov eax, esi
// 007bec2c  5e                   pop esi
// 007bec2d  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockContext.cpp (function ??0CXTPDockContext@@QAE@PAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockContext.cpp
