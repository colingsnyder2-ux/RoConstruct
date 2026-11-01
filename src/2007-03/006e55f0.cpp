// from server: 100% by auto
// roc 2007-03 006e55f0  unit: seg_006e0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e55f0
//
// 006e55f0  8b442404             mov eax, dword ptr [esp + 4]
// 006e55f4  394130               cmp dword ptr [ecx + 0x30], eax
// 006e55f7  7408                 je 0x6e5601
// 006e55f9  894130               mov dword ptr [ecx + 0x30], eax
// 006e55fc  e83fffffff           call 0x6e5540
// 006e5601  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetEnabled@CXTPTabManagerItem@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
