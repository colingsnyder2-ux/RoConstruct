// from server: 100% by auto
// roc 2009-12 008e6d80  unit: CXTPTabPaintManager::CColorSetDefault  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6d80
//
// 008e6d80  8b8104020000         mov eax, dword ptr [ecx + 0x204]
// 008e6d86  83783400             cmp dword ptr [eax + 0x34], 0
// 008e6d8a  740c                 je 0x8e6d98
// 008e6d8c  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008e6d90  e86b72feff           call 0x8ce000
// 008e6d95  c20400               ret 4
// 008e6d98  8b442404             mov eax, dword ptr [esp + 4]
// 008e6d9c  8b5060               mov edx, dword ptr [eax + 0x60]
// 008e6d9f  394204               cmp dword ptr [edx + 4], eax
// 008e6da2  8d4174               lea eax, [ecx + 0x74]
// 008e6da5  7406                 je 0x8e6dad
// 008e6da7  8d8198000000         lea eax, [ecx + 0x98]
// 008e6dad  8b4808               mov ecx, dword ptr [eax + 8]
// 008e6db0  83f9ff               cmp ecx, -1
// 008e6db3  7506                 jne 0x8e6dbb
// 008e6db5  8b4004               mov eax, dword ptr [eax + 4]
// 008e6db8  c20400               ret 4
// 008e6dbb  8bc1                 mov eax, ecx
// 008e6dbd  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?GetItemColor@CColorSet@CXTPTabPaintManager@@UAEKPAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
