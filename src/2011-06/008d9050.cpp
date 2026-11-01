// from server: 100% by auto
// roc 2011-06 008d9050  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d9050
//
// 008d9050  83ec10               sub esp, 0x10
// 008d9053  56                   push esi
// 008d9054  8bf1                 mov esi, ecx
// 008d9056  57                   push edi
// 008d9057  8d4c2408             lea ecx, [esp + 8]
// 008d905b  e8903cf8ff           call 0x85ccf0
// 008d9060  8b38                 mov edi, dword ptr [eax]
// 008d9062  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 008d9065  8b31                 mov esi, dword ptr [ecx]
// 008d9067  6a00                 push 0
// 008d9069  83ec10               sub esp, 0x10
// 008d906c  8bd4                 mov edx, esp
// 008d906e  893a                 mov dword ptr [edx], edi
// 008d9070  8b7804               mov edi, dword ptr [eax + 4]
// 008d9073  897a04               mov dword ptr [edx + 4], edi
// 008d9076  8b7808               mov edi, dword ptr [eax + 8]
// 008d9079  8b400c               mov eax, dword ptr [eax + 0xc]
// 008d907c  897a08               mov dword ptr [edx + 8], edi
// 008d907f  89420c               mov dword ptr [edx + 0xc], eax
// 008d9082  8b542434             mov edx, dword ptr [esp + 0x34]
// 008d9086  8b442430             mov eax, dword ptr [esp + 0x30]
// 008d908a  52                   push edx
// 008d908b  8b5668               mov edx, dword ptr [esi + 0x68]
// 008d908e  50                   push eax
// 008d908f  ffd2                 call edx
// 008d9091  5f                   pop edi
// 008d9092  5e                   pop esi
// 008d9093  83c410               add esp, 0x10
// 008d9096  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetButtonLength@CXTPTabPaintManagerAppearanceSet@@UAEHPAVCDC@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/TabManager/XTPTabPaintManagerAppearance.cpp
