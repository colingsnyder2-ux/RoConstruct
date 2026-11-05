// from server: 100% by auto
// roc 2010-06 0089bb20  unit: CXTPTabPaintManager::CColorSetDefault  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089bb20
//
// 0089bb20  56                   push esi
// 0089bb21  57                   push edi
// 0089bb22  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0089bb26  8bf1                 mov esi, ecx
// 0089bb28  8bcf                 mov ecx, edi
// 0089bb2a  e8e17ffaff           call 0x843b10
// 0089bb2f  85c0                 test eax, eax
// 0089bb31  7508                 jne 0x89bb3b
// 0089bb33  8d86d4000000         lea eax, [esi + 0xd4]
// 0089bb39  eb2f                 jmp 0x89bb6a
// 0089bb3b  8b4760               mov eax, dword ptr [edi + 0x60]
// 0089bb3e  83781c00             cmp dword ptr [eax + 0x1c], 0
// 0089bb42  7508                 jne 0x89bb4c
// 0089bb44  8d86b0000000         lea eax, [esi + 0xb0]
// 0089bb4a  eb1e                 jmp 0x89bb6a
// 0089bb4c  397804               cmp dword ptr [eax + 4], edi
// 0089bb4f  7508                 jne 0x89bb59
// 0089bb51  8d86bc000000         lea eax, [esi + 0xbc]
// 0089bb57  eb11                 jmp 0x89bb6a
// 0089bb59  397808               cmp dword ptr [eax + 8], edi
// 0089bb5c  8d86c8000000         lea eax, [esi + 0xc8]
// 0089bb62  7406                 je 0x89bb6a
// 0089bb64  8d86a4000000         lea eax, [esi + 0xa4]
// 0089bb6a  8b4808               mov ecx, dword ptr [eax + 8]
// 0089bb6d  5f                   pop edi
// 0089bb6e  5e                   pop esi
// 0089bb6f  83f9ff               cmp ecx, -1
// 0089bb72  7512                 jne 0x89bb86
// 0089bb74  8b4004               mov eax, dword ptr [eax + 4]
// 0089bb77  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089bb7b  8b11                 mov edx, dword ptr [ecx]
// 0089bb7d  50                   push eax
// 0089bb7e  8b4238               mov eax, dword ptr [edx + 0x38]
// 0089bb81  ffd0                 call eax
// 0089bb83  c20800               ret 8
// 0089bb86  8bc1                 mov eax, ecx
// 0089bb88  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089bb8c  8b11                 mov edx, dword ptr [ecx]
// 0089bb8e  50                   push eax
// 0089bb8f  8b4238               mov eax, dword ptr [edx + 0x38]
// 0089bb92  ffd0                 call eax
// 0089bb94  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?SetTextColor@CColorSet@CXTPTabPaintManager@@UAEXPAVCDC@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/TabManager/XTPTabPaintManagerColors.cpp
