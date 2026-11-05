// from server: 100% by auto
// roc 2009-06 0080d080  unit: CXTPTabPaintManager::CColorSetVisualStudio  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080d080
//
// 0080d080  56                   push esi
// 0080d081  8bf1                 mov esi, ecx
// 0080d083  e8d8f5ffff           call 0x80c660
// 0080d088  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0080d08e  e88d8cfeff           call 0x7f5d20
// 0080d093  83f807               cmp eax, 7
// 0080d096  7427                 je 0x80d0bf
// 0080d098  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0080d09e  e87d8cfeff           call 0x7f5d20
// 0080d0a3  83f804               cmp eax, 4
// 0080d0a6  7417                 je 0x80d0bf
// 0080d0a8  e8737af4ff           call 0x754b20
// 0080d0ad  6a30                 push 0x30
// 0080d0af  8bc8                 mov ecx, eax
// 0080d0b1  e8ea71f4ff           call 0x7542a0
// 0080d0b6  50                   push eax
// 0080d0b7  8d4e04               lea ecx, [esi + 4]
// 0080d0ba  e8b179f4ff           call 0x754a70
// 0080d0bf  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0080d0c5  e8568cfeff           call 0x7f5d20
// 0080d0ca  83f805               cmp eax, 5
// 0080d0cd  7528                 jne 0x80d0f7
// 0080d0cf  e84c7af4ff           call 0x754b20
// 0080d0d4  6a31                 push 0x31
// 0080d0d6  8bc8                 mov ecx, eax
// 0080d0d8  e8c371f4ff           call 0x7542a0
// 0080d0dd  8986b4000000         mov dword ptr [esi + 0xb4], eax
// 0080d0e3  e8387af4ff           call 0x754b20
// 0080d0e8  6a31                 push 0x31
// 0080d0ea  8bc8                 mov ecx, eax
// 0080d0ec  e8af71f4ff           call 0x7542a0
// 0080d0f1  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 0080d0f7  e87454f6ff           call 0x772570
// 0080d0fc  6a00                 push 0
// 0080d0fe  e88d2bf6ff           call 0x76fc90
// 0080d103  83c404               add esp, 4
// 0080d106  85c0                 test eax, eax
// 0080d108  7419                 je 0x80d123
// 0080d10a  e8117af4ff           call 0x754b20
// 0080d10f  6a0f                 push 0xf
// 0080d111  8bc8                 mov ecx, eax
// 0080d113  e88871f4ff           call 0x7542a0
// 0080d118  50                   push eax
// 0080d119  8d4e24               lea ecx, [esi + 0x24]
// 0080d11c  e84f79f4ff           call 0x754a70
// 0080d121  5e                   pop esi
// 0080d122  c3                   ret 
// 0080d123  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0080d126  83f8ff               cmp eax, -1
// 0080d129  7503                 jne 0x80d12e
// 0080d12b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0080d12e  50                   push eax
// 0080d12f  8d4e24               lea ecx, [esi + 0x24]
// 0080d132  e83979f4ff           call 0x754a70
// 0080d137  5e                   pop esi
// 0080d138  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?RefreshMetrics@CColorSetVisualStudio2003@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
