// from server: 100% by auto
// roc 2011-06 008dabb0  unit: CXTPTabPaintManager::CAppearanceSetPropertyPageSelected  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008dabb0
//
// 008dabb0  8b542408             mov edx, dword ptr [esp + 8]
// 008dabb4  8b4260               mov eax, dword ptr [edx + 0x60]
// 008dabb7  56                   push esi
// 008dabb8  57                   push edi
// 008dabb9  395004               cmp dword ptr [eax + 4], edx
// 008dabbc  7438                 je 0x8dabf6
// 008dabbe  395008               cmp dword ptr [eax + 8], edx
// 008dabc1  7433                 je 0x8dabf6
// 008dabc3  8b7a44               mov edi, dword ptr [edx + 0x44]
// 008dabc6  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 008dabc9  8b31                 mov esi, dword ptr [ecx]
// 008dabcb  6a01                 push 1
// 008dabcd  83ec10               sub esp, 0x10
// 008dabd0  8bc4                 mov eax, esp
// 008dabd2  8938                 mov dword ptr [eax], edi
// 008dabd4  8b7a48               mov edi, dword ptr [edx + 0x48]
// 008dabd7  897804               mov dword ptr [eax + 4], edi
// 008dabda  8b7a4c               mov edi, dword ptr [edx + 0x4c]
// 008dabdd  897808               mov dword ptr [eax + 8], edi
// 008dabe0  8b7a50               mov edi, dword ptr [edx + 0x50]
// 008dabe3  89780c               mov dword ptr [eax + 0xc], edi
// 008dabe6  8b442420             mov eax, dword ptr [esp + 0x20]
// 008dabea  52                   push edx
// 008dabeb  8b5668               mov edx, dword ptr [esi + 0x68]
// 008dabee  50                   push eax
// 008dabef  ffd2                 call edx
// 008dabf1  5f                   pop edi
// 008dabf2  5e                   pop esi
// 008dabf3  c20800               ret 8
// 008dabf6  5f                   pop edi
// 008dabf7  5e                   pop esi
// 008dabf8  89542408             mov dword ptr [esp + 8], edx
// 008dabfc  e98ff8ffff           jmp 0x8da490
// library xtp-15.2.1-shared-mfc/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?DrawSingleButton@CAppearanceSetPropertyPageSelected@CXTPTabPaintManager@@UAEXPAVCDC@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/TabManager/XTPTabPaintManagerAppearance.cpp
