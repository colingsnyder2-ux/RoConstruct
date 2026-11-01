// from server: 100% by auto
// roc 2011-06 008f4680  unit: CXTPTabPaintManager::CColorSetDefault  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f4680
//
// 008f4680  56                   push esi
// 008f4681  57                   push edi
// 008f4682  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008f4686  8bf1                 mov esi, ecx
// 008f4688  8bcf                 mov ecx, edi
// 008f468a  e861a2f4ff           call 0x83e8f0
// 008f468f  85c0                 test eax, eax
// 008f4691  7508                 jne 0x8f469b
// 008f4693  8d86d4000000         lea eax, [esi + 0xd4]
// 008f4699  eb2f                 jmp 0x8f46ca
// 008f469b  8b4760               mov eax, dword ptr [edi + 0x60]
// 008f469e  83781c00             cmp dword ptr [eax + 0x1c], 0
// 008f46a2  7508                 jne 0x8f46ac
// 008f46a4  8d86b0000000         lea eax, [esi + 0xb0]
// 008f46aa  eb1e                 jmp 0x8f46ca
// 008f46ac  397804               cmp dword ptr [eax + 4], edi
// 008f46af  7508                 jne 0x8f46b9
// 008f46b1  8d86bc000000         lea eax, [esi + 0xbc]
// 008f46b7  eb11                 jmp 0x8f46ca
// 008f46b9  397808               cmp dword ptr [eax + 8], edi
// 008f46bc  8d86c8000000         lea eax, [esi + 0xc8]
// 008f46c2  7406                 je 0x8f46ca
// 008f46c4  8d86a4000000         lea eax, [esi + 0xa4]
// 008f46ca  8b4808               mov ecx, dword ptr [eax + 8]
// 008f46cd  5f                   pop edi
// 008f46ce  5e                   pop esi
// 008f46cf  83f9ff               cmp ecx, -1
// 008f46d2  7512                 jne 0x8f46e6
// 008f46d4  8b4004               mov eax, dword ptr [eax + 4]
// 008f46d7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008f46db  8b11                 mov edx, dword ptr [ecx]
// 008f46dd  50                   push eax
// 008f46de  8b4238               mov eax, dword ptr [edx + 0x38]
// 008f46e1  ffd0                 call eax
// 008f46e3  c20800               ret 8
// 008f46e6  8bc1                 mov eax, ecx
// 008f46e8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008f46ec  8b11                 mov edx, dword ptr [ecx]
// 008f46ee  50                   push eax
// 008f46ef  8b4238               mov eax, dword ptr [edx + 0x38]
// 008f46f2  ffd0                 call eax
// 008f46f4  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?SetTextColor@CXTPTabPaintManagerColorSet@@UAEXPAVCDC@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/TabManager/XTPTabPaintManagerColors.cpp
