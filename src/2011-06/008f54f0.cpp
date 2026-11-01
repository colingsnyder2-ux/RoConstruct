// from server: 100% by auto
// roc 2011-06 008f54f0  unit: CXTPTabPaintManager::CColorSetVisualStudio  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f54f0
//
// 008f54f0  56                   push esi
// 008f54f1  8bf1                 mov esi, ecx
// 008f54f3  e8d8f5ffff           call 0x8f4ad0
// 008f54f8  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008f54fe  e8bd04feff           call 0x8d59c0
// 008f5503  83f807               cmp eax, 7
// 008f5506  7427                 je 0x8f552f
// 008f5508  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008f550e  e8ad04feff           call 0x8d59c0
// 008f5513  83f804               cmp eax, 4
// 008f5516  7417                 je 0x8f552f
// 008f5518  e8c3fef4ff           call 0x8453e0
// 008f551d  6a30                 push 0x30
// 008f551f  8bc8                 mov ecx, eax
// 008f5521  e88af6f4ff           call 0x844bb0
// 008f5526  50                   push eax
// 008f5527  8d4e04               lea ecx, [esi + 4]
// 008f552a  e801fef4ff           call 0x845330
// 008f552f  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008f5535  e88604feff           call 0x8d59c0
// 008f553a  83f805               cmp eax, 5
// 008f553d  7528                 jne 0x8f5567
// 008f553f  e89cfef4ff           call 0x8453e0
// 008f5544  6a31                 push 0x31
// 008f5546  8bc8                 mov ecx, eax
// 008f5548  e863f6f4ff           call 0x844bb0
// 008f554d  8986b4000000         mov dword ptr [esi + 0xb4], eax
// 008f5553  e888fef4ff           call 0x8453e0
// 008f5558  6a31                 push 0x31
// 008f555a  8bc8                 mov ecx, eax
// 008f555c  e84ff6f4ff           call 0x844bb0
// 008f5561  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 008f5567  e81498f6ff           call 0x85ed80
// 008f556c  6a00                 push 0
// 008f556e  e8cd6ff6ff           call 0x85c540
// 008f5573  83c404               add esp, 4
// 008f5576  85c0                 test eax, eax
// 008f5578  7419                 je 0x8f5593
// 008f557a  e861fef4ff           call 0x8453e0
// 008f557f  6a0f                 push 0xf
// 008f5581  8bc8                 mov ecx, eax
// 008f5583  e828f6f4ff           call 0x844bb0
// 008f5588  50                   push eax
// 008f5589  8d4e24               lea ecx, [esi + 0x24]
// 008f558c  e89ffdf4ff           call 0x845330
// 008f5591  5e                   pop esi
// 008f5592  c3                   ret 
// 008f5593  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008f5596  83f8ff               cmp eax, -1
// 008f5599  7503                 jne 0x8f559e
// 008f559b  8b4618               mov eax, dword ptr [esi + 0x18]
// 008f559e  50                   push eax
// 008f559f  8d4e24               lea ecx, [esi + 0x24]
// 008f55a2  e889fdf4ff           call 0x845330
// 008f55a7  5e                   pop esi
// 008f55a8  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?RefreshMetrics@CColorSetVisualStudio2003@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
