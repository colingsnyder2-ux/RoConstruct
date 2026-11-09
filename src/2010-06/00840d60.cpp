// from server: 100% by auto
// roc 2010-06 00840d60  unit: PAVCXTPHookManagerHookAble::?$CArray  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00840d60
//
// 00840d60  56                   push esi
// 00840d61  8bf1                 mov esi, ecx
// 00840d63  6a0a                 push 0xa
// 00840d65  8d4e14               lea ecx, [esi + 0x14]
// 00840d68  c7063874a600         mov dword ptr [esi], 0xa67438
// 00840d6e  e8adfdffff           call 0x840b20
// 00840d73  33c0                 xor eax, eax
// 00840d75  894604               mov dword ptr [esi + 4], eax
// 00840d78  894608               mov dword ptr [esi + 8], eax
// 00840d7b  89460c               mov dword ptr [esi + 0xc], eax
// 00840d7e  894610               mov dword ptr [esi + 0x10], eax
// 00840d81  8bc6                 mov eax, esi
// 00840d83  5e                   pop esi
// 00840d84  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPKeyboardManager.cpp (function ??0CXTPKeyboardManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPKeyboardManager.cpp
