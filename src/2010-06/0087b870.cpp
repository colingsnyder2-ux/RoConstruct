// from server: 100% by auto
// roc 2010-06 0087b870  unit: VCEdit::?$CXTMaskEditT  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087b870
//
// 0087b870  56                   push esi
// 0087b871  8bf1                 mov esi, ecx
// 0087b873  8d8e84000000         lea ecx, [esi + 0x84]
// 0087b879  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0087b87f  8d8e80000000         lea ecx, [esi + 0x80]
// 0087b885  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0087b88b  8d4e7c               lea ecx, [esi + 0x7c]
// 0087b88e  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0087b894  8d4e78               lea ecx, [esi + 0x78]
// 0087b897  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0087b89d  8d4e74               lea ecx, [esi + 0x74]
// 0087b8a0  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0087b8a6  8d4e70               lea ecx, [esi + 0x70]
// 0087b8a9  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0087b8af  8bce                 mov ecx, esi
// 0087b8b1  e80a151000           call 0x97cdc0
// 0087b8b6  f644240801           test byte ptr [esp + 8], 1
// 0087b8bb  7409                 je 0x87b8c6
// 0087b8bd  56                   push esi
// 0087b8be  e8d7c0f2ff           call 0x7a799a
// 0087b8c3  83c404               add esp, 4
// 0087b8c6  8bc6                 mov eax, esi
// 0087b8c8  5e                   pop esi
// 0087b8c9  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTPEdit.cpp (function ??_G?$CXTMaskEditT@VCEdit@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTPEdit.cpp
