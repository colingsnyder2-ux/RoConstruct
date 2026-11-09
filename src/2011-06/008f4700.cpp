// from server: 100% by auto
// roc 2011-06 008f4700  unit: CXTPTabPaintManager::CColorSetDefault  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f4700
//
// 008f4700  8b8104020000         mov eax, dword ptr [ecx + 0x204]
// 008f4706  83783400             cmp dword ptr [eax + 0x34], 0
// 008f470a  740c                 je 0x8f4718
// 008f470c  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008f4710  e8dbe9fdff           call 0x8d30f0
// 008f4715  c20400               ret 4
// 008f4718  8b442404             mov eax, dword ptr [esp + 4]
// 008f471c  8b5060               mov edx, dword ptr [eax + 0x60]
// 008f471f  394204               cmp dword ptr [edx + 4], eax
// 008f4722  8d4174               lea eax, [ecx + 0x74]
// 008f4725  7406                 je 0x8f472d
// 008f4727  8d8198000000         lea eax, [ecx + 0x98]
// 008f472d  8b4808               mov ecx, dword ptr [eax + 8]
// 008f4730  83f9ff               cmp ecx, -1
// 008f4733  7506                 jne 0x8f473b
// 008f4735  8b4004               mov eax, dword ptr [eax + 4]
// 008f4738  c20400               ret 4
// 008f473b  8bc1                 mov eax, ecx
// 008f473d  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?GetItemColor@CColorSet@CXTPTabPaintManager@@UAEKPAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
