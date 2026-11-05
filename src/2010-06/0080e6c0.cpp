// from server: 100% by auto
// roc 2010-06 0080e6c0  unit: CXTThemeManager  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e6c0
//
// 0080e6c0  33c0                 xor eax, eax
// 0080e6c2  56                   push esi
// 0080e6c3  8bf1                 mov esi, ecx
// 0080e6c5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0080e6c9  c7067814a600         mov dword ptr [esi], 0xa61478
// 0080e6cf  894604               mov dword ptr [esi + 4], eax
// 0080e6d2  894610               mov dword ptr [esi + 0x10], eax
// 0080e6d5  89460c               mov dword ptr [esi + 0xc], eax
// 0080e6d8  894614               mov dword ptr [esi + 0x14], eax
// 0080e6db  894608               mov dword ptr [esi + 8], eax
// 0080e6de  3bc8                 cmp ecx, eax
// 0080e6e0  7408                 je 0x80e6ea
// 0080e6e2  51                   push ecx
// 0080e6e3  8bce                 mov ecx, esi
// 0080e6e5  e806ffffff           call 0x80e5f0
// 0080e6ea  8bc6                 mov eax, esi
// 0080e6ec  5e                   pop esi
// 0080e6ed  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ??0CXTThemeManagerStyleHost@@IAE@PAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
