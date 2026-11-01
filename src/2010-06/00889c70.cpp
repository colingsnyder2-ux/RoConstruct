// from server: 100% by auto
// roc 2010-06 00889c70  unit: CXTPTabPaintManager::CAppearanceSetPropertyPageSelected  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00889c70
//
// 00889c70  8b542408             mov edx, dword ptr [esp + 8]
// 00889c74  8b4260               mov eax, dword ptr [edx + 0x60]
// 00889c77  56                   push esi
// 00889c78  57                   push edi
// 00889c79  395004               cmp dword ptr [eax + 4], edx
// 00889c7c  7438                 je 0x889cb6
// 00889c7e  395008               cmp dword ptr [eax + 8], edx
// 00889c81  7433                 je 0x889cb6
// 00889c83  8b7a44               mov edi, dword ptr [edx + 0x44]
// 00889c86  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 00889c89  8b31                 mov esi, dword ptr [ecx]
// 00889c8b  6a01                 push 1
// 00889c8d  83ec10               sub esp, 0x10
// 00889c90  8bc4                 mov eax, esp
// 00889c92  8938                 mov dword ptr [eax], edi
// 00889c94  8b7a48               mov edi, dword ptr [edx + 0x48]
// 00889c97  897804               mov dword ptr [eax + 4], edi
// 00889c9a  8b7a4c               mov edi, dword ptr [edx + 0x4c]
// 00889c9d  897808               mov dword ptr [eax + 8], edi
// 00889ca0  8b7a50               mov edi, dword ptr [edx + 0x50]
// 00889ca3  89780c               mov dword ptr [eax + 0xc], edi
// 00889ca6  8b442420             mov eax, dword ptr [esp + 0x20]
// 00889caa  52                   push edx
// 00889cab  8b5668               mov edx, dword ptr [esi + 0x68]
// 00889cae  50                   push eax
// 00889caf  ffd2                 call edx
// 00889cb1  5f                   pop edi
// 00889cb2  5e                   pop esi
// 00889cb3  c20800               ret 8
// 00889cb6  5f                   pop edi
// 00889cb7  5e                   pop esi
// 00889cb8  89542408             mov dword ptr [esp + 8], edx
// 00889cbc  e98ff8ffff           jmp 0x889550
// library xtp-13.2.1-shared-mfc/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?DrawSingleButton@CAppearanceSetPropertyPageSelected@CXTPTabPaintManager@@UAEXPAVCDC@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/TabManager/XTPTabPaintManagerAppearance.cpp
