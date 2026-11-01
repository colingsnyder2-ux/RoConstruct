// from server: 100% by auto
// roc 2010-06 00888110  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00888110
//
// 00888110  83ec10               sub esp, 0x10
// 00888113  56                   push esi
// 00888114  8bf1                 mov esi, ecx
// 00888116  57                   push edi
// 00888117  8d4c2408             lea ecx, [esp + 8]
// 0088811b  e85071f7ff           call 0x7ff270
// 00888120  8b38                 mov edi, dword ptr [eax]
// 00888122  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00888125  8b31                 mov esi, dword ptr [ecx]
// 00888127  6a00                 push 0
// 00888129  83ec10               sub esp, 0x10
// 0088812c  8bd4                 mov edx, esp
// 0088812e  893a                 mov dword ptr [edx], edi
// 00888130  8b7804               mov edi, dword ptr [eax + 4]
// 00888133  897a04               mov dword ptr [edx + 4], edi
// 00888136  8b7808               mov edi, dword ptr [eax + 8]
// 00888139  8b400c               mov eax, dword ptr [eax + 0xc]
// 0088813c  897a08               mov dword ptr [edx + 8], edi
// 0088813f  89420c               mov dword ptr [edx + 0xc], eax
// 00888142  8b542434             mov edx, dword ptr [esp + 0x34]
// 00888146  8b442430             mov eax, dword ptr [esp + 0x30]
// 0088814a  52                   push edx
// 0088814b  8b5668               mov edx, dword ptr [esi + 0x68]
// 0088814e  50                   push eax
// 0088814f  ffd2                 call edx
// 00888151  5f                   pop edi
// 00888152  5e                   pop esi
// 00888153  83c410               add esp, 0x10
// 00888156  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetButtonLength@CAppearanceSet@CXTPTabPaintManager@@UAEHPAVCDC@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/TabManager/XTPTabPaintManagerAppearance.cpp
