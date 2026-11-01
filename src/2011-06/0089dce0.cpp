// from server: 100% by auto
// roc 2011-06 0089dce0  unit: PAVCXTPHookManagerHookAble::?$CArray  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089dce0
//
// 0089dce0  56                   push esi
// 0089dce1  8bf1                 mov esi, ecx
// 0089dce3  6a0a                 push 0xa
// 0089dce5  8d4e14               lea ecx, [esi + 0x14]
// 0089dce8  c706581ead00         mov dword ptr [esi], 0xad1e58
// 0089dcee  e8edfdffff           call 0x89dae0
// 0089dcf3  33c0                 xor eax, eax
// 0089dcf5  894604               mov dword ptr [esi + 4], eax
// 0089dcf8  894608               mov dword ptr [esi + 8], eax
// 0089dcfb  89460c               mov dword ptr [esi + 0xc], eax
// 0089dcfe  894610               mov dword ptr [esi + 0x10], eax
// 0089dd01  8bc6                 mov eax, esi
// 0089dd03  5e                   pop esi
// 0089dd04  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPKeyboardManager.cpp (function ??0CXTPKeyboardManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPKeyboardManager.cpp
