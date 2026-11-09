// from server: 100% by auto
// roc 2010-06 0089bba0  unit: CXTPTabPaintManager::CColorSetDefault  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089bba0
//
// 0089bba0  8b8104020000         mov eax, dword ptr [ecx + 0x204]
// 0089bba6  83783400             cmp dword ptr [eax + 0x34], 0
// 0089bbaa  740c                 je 0x89bbb8
// 0089bbac  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089bbb0  e81b66feff           call 0x8821d0
// 0089bbb5  c20400               ret 4
// 0089bbb8  8b442404             mov eax, dword ptr [esp + 4]
// 0089bbbc  8b5060               mov edx, dword ptr [eax + 0x60]
// 0089bbbf  394204               cmp dword ptr [edx + 4], eax
// 0089bbc2  8d4174               lea eax, [ecx + 0x74]
// 0089bbc5  7406                 je 0x89bbcd
// 0089bbc7  8d8198000000         lea eax, [ecx + 0x98]
// 0089bbcd  8b4808               mov ecx, dword ptr [eax + 8]
// 0089bbd0  83f9ff               cmp ecx, -1
// 0089bbd3  7506                 jne 0x89bbdb
// 0089bbd5  8b4004               mov eax, dword ptr [eax + 4]
// 0089bbd8  c20400               ret 4
// 0089bbdb  8bc1                 mov eax, ecx
// 0089bbdd  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?GetItemColor@CColorSet@CXTPTabPaintManager@@UAEKPAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
