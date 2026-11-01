// from server: 100% by auto
// roc 2009-12 008903c0  unit: CXTPToolBar::CControlButtonHide  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008903c0
//
// 008903c0  8b442404             mov eax, dword ptr [esp + 4]
// 008903c4  56                   push esi
// 008903c5  8bf1                 mov esi, ecx
// 008903c7  57                   push edi
// 008903c8  8d4e18               lea ecx, [esi + 0x18]
// 008903cb  33ff                 xor edi, edi
// 008903cd  51                   push ecx
// 008903ce  c706003aa000         mov dword ptr [esi], 0xa03a00
// 008903d4  894604               mov dword ptr [esi + 4], eax
// 008903d7  897e14               mov dword ptr [esi + 0x14], edi
// 008903da  ff159cca9800         call dword ptr [0x98ca9c]
// 008903e0  897e28               mov dword ptr [esi + 0x28], edi
// 008903e3  897e2c               mov dword ptr [esi + 0x2c], edi
// 008903e6  897e08               mov dword ptr [esi + 8], edi
// 008903e9  5f                   pop edi
// 008903ea  8bc6                 mov eax, esi
// 008903ec  5e                   pop esi
// 008903ed  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockContext.cpp (function ??0CXTPDockContext@@QAE@PAVCXTPToolBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockContext.cpp
