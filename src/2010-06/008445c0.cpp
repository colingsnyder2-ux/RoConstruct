// from server: 100% by auto
// roc 2010-06 008445c0  unit: CXTPToolBar::CControlButtonHide  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008445c0
//
// 008445c0  8b442404             mov eax, dword ptr [esp + 4]
// 008445c4  56                   push esi
// 008445c5  8bf1                 mov esi, ecx
// 008445c7  57                   push edi
// 008445c8  8d4e18               lea ecx, [esi + 0x18]
// 008445cb  33ff                 xor edi, edi
// 008445cd  51                   push ecx
// 008445ce  c706e07ca600         mov dword ptr [esi], 0xa67ce0
// 008445d4  894604               mov dword ptr [esi + 4], eax
// 008445d7  897e14               mov dword ptr [esi + 0x14], edi
// 008445da  ff15e4ba9e00         call dword ptr [0x9ebae4]
// 008445e0  897e28               mov dword ptr [esi + 0x28], edi
// 008445e3  897e2c               mov dword ptr [esi + 0x2c], edi
// 008445e6  897e08               mov dword ptr [esi + 8], edi
// 008445e9  5f                   pop edi
// 008445ea  8bc6                 mov eax, esi
// 008445ec  5e                   pop esi
// 008445ed  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPDockContext.cpp (function ??0CXTPDockContext@@QAE@PAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockContext.cpp
