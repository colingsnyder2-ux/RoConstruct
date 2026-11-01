// from server: 100% by auto
// roc 2007-03 0071c7f0  unit: seg_00710000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071c7f0
//
// 0071c7f0  8b442404             mov eax, dword ptr [esp + 4]
// 0071c7f4  56                   push esi
// 0071c7f5  50                   push eax
// 0071c7f6  8bf1                 mov esi, ecx
// 0071c7f8  e863390000           call 0x720160
// 0071c7fd  83f8ff               cmp eax, -1
// 0071c800  7506                 jne 0x71c808
// 0071c802  0bc0                 or eax, eax
// 0071c804  5e                   pop esi
// 0071c805  c20400               ret 4
// 0071c808  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0071c80b  6a00                 push 0
// 0071c80d  6a00                 push 0
// 0071c80f  51                   push ecx
// 0071c810  ff1554ee7700         call dword ptr [0x77ee54]
// 0071c816  33c0                 xor eax, eax
// 0071c818  5e                   pop esi
// 0071c819  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectButton.cpp (function ?OnCreate@CXTPSkinObjectButton@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectButton.cpp
