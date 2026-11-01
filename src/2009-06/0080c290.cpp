// from server: 100% by auto
// roc 2009-06 0080c290  unit: CXTPTabPaintManager::CColorSetDefault  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080c290
//
// 0080c290  8b8104020000         mov eax, dword ptr [ecx + 0x204]
// 0080c296  83783400             cmp dword ptr [eax + 0x34], 0
// 0080c29a  740c                 je 0x80c2a8
// 0080c29c  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0080c2a0  e8ab71feff           call 0x7f3450
// 0080c2a5  c20400               ret 4
// 0080c2a8  8b442404             mov eax, dword ptr [esp + 4]
// 0080c2ac  8b5060               mov edx, dword ptr [eax + 0x60]
// 0080c2af  394204               cmp dword ptr [edx + 4], eax
// 0080c2b2  8d4174               lea eax, [ecx + 0x74]
// 0080c2b5  7406                 je 0x80c2bd
// 0080c2b7  8d8198000000         lea eax, [ecx + 0x98]
// 0080c2bd  8b4808               mov ecx, dword ptr [eax + 8]
// 0080c2c0  83f9ff               cmp ecx, -1
// 0080c2c3  7506                 jne 0x80c2cb
// 0080c2c5  8b4004               mov eax, dword ptr [eax + 4]
// 0080c2c8  c20400               ret 4
// 0080c2cb  8bc1                 mov eax, ecx
// 0080c2cd  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?GetItemColor@CColorSet@CXTPTabPaintManager@@UAEKPAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
