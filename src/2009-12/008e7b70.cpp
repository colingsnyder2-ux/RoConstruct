// from server: 100% by auto
// roc 2009-12 008e7b70  unit: CXTPTabPaintManager::CColorSetVisualStudio  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e7b70
//
// 008e7b70  56                   push esi
// 008e7b71  8bf1                 mov esi, ecx
// 008e7b73  e8d8f5ffff           call 0x8e7150
// 008e7b78  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008e7b7e  e85dcdf7ff           call 0x8648e0
// 008e7b83  83f807               cmp eax, 7
// 008e7b86  7427                 je 0x8e7baf
// 008e7b88  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008e7b8e  e84dcdf7ff           call 0x8648e0
// 008e7b93  83f804               cmp eax, 4
// 008e7b96  7417                 je 0x8e7baf
// 008e7b98  e8337ef4ff           call 0x82f9d0
// 008e7b9d  6a30                 push 0x30
// 008e7b9f  8bc8                 mov ecx, eax
// 008e7ba1  e85a75f4ff           call 0x82f100
// 008e7ba6  50                   push eax
// 008e7ba7  8d4e04               lea ecx, [esi + 4]
// 008e7baa  e8717df4ff           call 0x82f920
// 008e7baf  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 008e7bb5  e826cdf7ff           call 0x8648e0
// 008e7bba  83f805               cmp eax, 5
// 008e7bbd  7528                 jne 0x8e7be7
// 008e7bbf  e80c7ef4ff           call 0x82f9d0
// 008e7bc4  6a31                 push 0x31
// 008e7bc6  8bc8                 mov ecx, eax
// 008e7bc8  e83375f4ff           call 0x82f100
// 008e7bcd  8986b4000000         mov dword ptr [esi + 0xb4], eax
// 008e7bd3  e8f87df4ff           call 0x82f9d0
// 008e7bd8  6a31                 push 0x31
// 008e7bda  8bc8                 mov ecx, eax
// 008e7bdc  e81f75f4ff           call 0x82f100
// 008e7be1  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 008e7be7  e8b456f6ff           call 0x84d2a0
// 008e7bec  6a00                 push 0
// 008e7bee  e89d2ef6ff           call 0x84aa90
// 008e7bf3  83c404               add esp, 4
// 008e7bf6  85c0                 test eax, eax
// 008e7bf8  7419                 je 0x8e7c13
// 008e7bfa  e8d17df4ff           call 0x82f9d0
// 008e7bff  6a0f                 push 0xf
// 008e7c01  8bc8                 mov ecx, eax
// 008e7c03  e8f874f4ff           call 0x82f100
// 008e7c08  50                   push eax
// 008e7c09  8d4e24               lea ecx, [esi + 0x24]
// 008e7c0c  e80f7df4ff           call 0x82f920
// 008e7c11  5e                   pop esi
// 008e7c12  c3                   ret 
// 008e7c13  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008e7c16  83f8ff               cmp eax, -1
// 008e7c19  7503                 jne 0x8e7c1e
// 008e7c1b  8b4618               mov eax, dword ptr [esi + 0x18]
// 008e7c1e  50                   push eax
// 008e7c1f  8d4e24               lea ecx, [esi + 0x24]
// 008e7c22  e8f97cf4ff           call 0x82f920
// 008e7c27  5e                   pop esi
// 008e7c28  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?RefreshMetrics@CColorSetVisualStudio2003@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
