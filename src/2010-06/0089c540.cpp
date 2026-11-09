// from server: 100% by auto
// roc 2010-06 0089c540  unit: CXTPTabPaintManager::CColorSetDefault  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089c540
//
// 0089c540  8b442418             mov eax, dword ptr [esp + 0x18]
// 0089c544  8b4004               mov eax, dword ptr [eax + 4]
// 0089c547  56                   push esi
// 0089c548  85c0                 test eax, eax
// 0089c54a  741f                 je 0x89c56b
// 0089c54c  8b11                 mov edx, dword ptr [ecx]
// 0089c54e  50                   push eax
// 0089c54f  8b4224               mov eax, dword ptr [edx + 0x24]
// 0089c552  ffd0                 call eax
// 0089c554  8bf0                 mov esi, eax
// 0089c556  56                   push esi
// 0089c557  8d4c2410             lea ecx, [esp + 0x10]
// 0089c55b  51                   push ecx
// 0089c55c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089c560  e8d9c1f0ff           call 0x7a873e
// 0089c565  8bc6                 mov eax, esi
// 0089c567  5e                   pop esi
// 0089c568  c21800               ret 0x18
// 0089c56b  8b717c               mov esi, dword ptr [ecx + 0x7c]
// 0089c56e  83feff               cmp esi, -1
// 0089c571  7503                 jne 0x89c576
// 0089c573  8b7178               mov esi, dword ptr [ecx + 0x78]
// 0089c576  56                   push esi
// 0089c577  8d4c2410             lea ecx, [esp + 0x10]
// 0089c57b  51                   push ecx
// 0089c57c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089c580  e8b9c1f0ff           call 0x7a873e
// 0089c585  8bc6                 mov eax, esi
// 0089c587  5e                   pop esi
// 0089c588  c21800               ret 0x18
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillClient@CColorSet@CXTPTabPaintManager@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
